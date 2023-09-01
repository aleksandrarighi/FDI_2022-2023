#include "matrix.h"
#include <stdlib.h>

void mat_swapcols(struct matrix* mat, size_t c1, size_t c2) {
	double* temp = malloc(mat->N * sizeof(double));
	if (temp == NULL) {
		return;
	}

	for (size_t i = 0; i < mat->N; i++) {
		temp[i] = mat->data[i * mat->M + c1];
	}

	for (size_t i = 0; i < mat->N; i++) {
		mat->data[i * mat->M + c1] = mat->data[i * mat->M + c2];
	}

	for (size_t i = 0; i < mat->N; i++) {
		mat->data[i * mat->M + c2] = temp[i];
	}

	free(temp);
}