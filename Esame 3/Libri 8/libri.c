#include "libri.h"
#include <stdio.h>
#include <stdlib.h>

struct libro* read_libri(const char* filename, unsigned int* pn) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	unsigned int count = 0;
	char line[512];
	while (fgets(line, sizeof(line), f) != NULL) {
		count++;
	}

	struct libro* libri = malloc(count * sizeof(struct libro));
	if (libri == NULL) {
		fclose(f);
		return NULL;
	}

	rewind(f);
	for (unsigned int i = 0; i < count; i++) {
		if (fgets(line, sizeof(line), f) != NULL) {
			sscanf(line, "%u; %[^;]; %u", &libri[i].codice, libri[i].titolo, &libri[i].pagine);
		}
	}
	fclose(f);
	*pn = count;
	return libri;
}