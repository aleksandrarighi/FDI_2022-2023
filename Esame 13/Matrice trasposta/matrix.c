#include "matrix.h"
#include <stdlib.h>

extern struct matrix* mat_transpose(const struct matrix* mat) {
	if (mat == NULL) {
		return NULL;
	}

	struct matrix* transpose = malloc(sizeof(struct matrix));
	transpose->N = mat->M;
	transpose->M = mat->N;
	transpose->data = malloc(transpose->N * transpose->M * sizeof(double));

	for (size_t i = 0; i < transpose->N; i++) {
		for (size_t j = 0; j < transpose->M; j++) {
			transpose->data[j * transpose->M + i] = mat->data[i * mat->M + j];
		}
	}
	return transpose;
}