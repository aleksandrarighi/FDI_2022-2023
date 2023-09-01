#include "matrix.h"
#include<stdlib.h>

struct matrix* mat_copy(const struct matrix* mat) {
	if (mat == NULL) {
		return;
	}

	struct matrix* copia = malloc(sizeof(struct matrix));
	copia->N = mat->N;
	copia->M = mat->M;
	copia->data = malloc(copia->N * copia->M * sizeof(double));

	for (size_t i = 0; i < copia->N; i++) {
		for (size_t j = 0; j < copia->M; j++) {
			copia->data[i * mat->M + j] = mat->data[i * mat->M + j];
		}
	}

	return copia;
}