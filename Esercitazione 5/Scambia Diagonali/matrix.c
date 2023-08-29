#include "matrix.h"

struct matrix* scambia_diagonali(const struct matrix* m) {
	if (m->rows != m->cols) {
		return NULL;
	}

	struct matrix* swap = malloc(sizeof(struct matrix));
	swap->rows = m->rows;
	swap->cols = m->cols;
	swap->data = malloc(swap->rows * swap->cols * sizeof(double));

	for (size_t i = 0; i < m->rows; i++) {
		for (size_t j = 0; j < m->cols; j++) {
			if (i == j) {
				swap->data[i * m->cols + j] = m->data[(m->rows - 1 - i) * m->cols + (m->cols - 1 - j)];
			}
			else if (i + j == m->rows - 1) {
				swap->data[i * m->cols + j] = m->data[j * m->cols + i];
			}
			else {
				swap->data[i * m->cols + j] = m->data[i * m->cols + j];
			}
		}
	}

	return swap;
}
