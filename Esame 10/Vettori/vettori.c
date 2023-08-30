#include "vettori.h"
#include <stdlib.h>

int vettore_leggi(FILE* f, struct vettore* v) {
	if (f == NULL || v == NULL) {
		return 0;
	}

	unsigned char num_ele;
	if (fread(&num_ele, sizeof(unsigned char), 1, f) != 1) {
		return 0;
	}

	v->size = num_ele;
	v->data = malloc(num_ele * sizeof(double));
	if (v->data == NULL) {
		free(v->data);
		return 0;
	}

	for (unsigned int i = 0; i < num_ele; i++) {
		if (fread(&(v->data[i]), sizeof(double), 1, f) != 1) {
			free(v->data);
			return 0;
		}
	}
	return 1;
}