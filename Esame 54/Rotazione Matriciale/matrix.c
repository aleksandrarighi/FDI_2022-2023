#include "matrix.h"
#include <stdlib.h>

struct matrix* mat_rotate180(const struct matrix* m) {
	if (m == NULL) {
		return NULL;
	}

	struct matrix* rotazione = malloc(sizeof(struct matrix));
	rotazione->rows = m->rows;
	rotazione->cols = m->cols;
	rotazione->data = malloc(rotazione->rows * rotazione->cols * sizeof(double));

	for (size_t i = 0; i < rotazione->rows; i++) {
		for (size_t j = 0; j < rotazione->cols; j++) {
			rotazione->data[(m->rows - i - 1) * m->cols + (m->cols - j - 1)] = m->data[i * m->cols + j];
		}
	}
	return rotazione;
}