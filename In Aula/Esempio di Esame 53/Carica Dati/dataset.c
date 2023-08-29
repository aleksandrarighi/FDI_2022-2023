#define _CRT_SECURE_NO_WARNINGS_
#include "dataset.h"
#include <string.h>

struct dataset* dataset_load(const char* filename) {
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		return NULL;
	}

	struct dataset* d = malloc(sizeof(struct dataset));
	d->data = NULL;
	d->nrows = 0;

	while (1) {
		char fname[256];
		char prognosis[7];
		int res =fscanf(f, "%255[^,], %6sn", fname, prognosis);
		if (res != 2) {
			break;
		}
		struct row tmp;
		tmp.filename = malloc(strlen(fname) + 1);
		strcpy(tmp.filename, fname);
		tmp.prognosis = prognosis[0];

		d->data = realloc(d->data, (d->nrows + 1) * sizeof(struct row));
		d->data[d->nrows] = tmp; 
		d->nrows += 1;
	}
	fclose(f);
	return d;
}