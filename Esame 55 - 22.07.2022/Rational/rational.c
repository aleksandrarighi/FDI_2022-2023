#include "rational.h"
#include <stdio.h>

struct rational* rational_read(const char* filename, size_t* size) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		*size = 0;
		return NULL;
	}

	//conto il numero di frazioni nel file
	*size = 0;
	int num;
	int den;
	while (fscanf(f, "%i / %i", &num, &den) == 2) {
			(*size)++;
	}
	rewind(f);

	//alloco memoria
	struct rational* razionali = malloc(*size * sizeof(struct rational));
	if (razionali == NULL) {
		fclose(f);
		*size = 0;
		return NULL;
	}

	//leggo le frazioni dal file
	for (size_t i = 0; i < *size; i++) {
		if (fscanf(f, "%i / %u", &razionali[i].num, &razionali[i].den) != 2) {
			fclose(f);
			free(razionali);
			*size = 0;
			return NULL;
		}
	}
	fclose(f);
	return razionali;
}