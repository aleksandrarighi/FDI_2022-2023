#include "matrix.h"
#include<stdlib.h>

void mat_swaprows(struct matrix* mat, size_t r1, size_t r2) {
	double* temp = malloc(mat->M * sizeof(double));
	if (temp == NULL) {
		return;
	}

	for (size_t i = 0; i < mat->M; i++) {
		temp[i] = mat->data[r1 * mat->M + i];
	}

	for (size_t i = 0; i < mat->M; i++) {
		mat->data[r1 * mat->M + i] = mat->data[r2 * mat->M + i];
	}

	for (size_t i = 0; i < mat->M; i++) {
		mat->data[r2 * mat->M + i] = temp[i];
	}

	free(temp);
}