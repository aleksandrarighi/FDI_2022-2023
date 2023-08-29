#include "matrix.h"

struct matrix* mat_normalize_rows(const struct matrix* m) {
	if (m == 0) {
		return NULL;
	}

	struct matrix* result = malloc(sizeof(struct matrix));
	result->rows = m->rows;
	result->cols = m->cols;
	result->data = malloc(m->rows * m->cols * sizeof(double));

	for (size_t i = 0; i < m->rows; i++) {
		double norma = 0;

		for (size_t j = 0; j < m->cols; j++) {
			double element = m->data[i * m->cols + j];
			norma += element * element;
		}
		norma = sqrt(norma);

		if (norma != 0) {
			for (size_t j = 0; j < m->cols; j++) {
				result->data[i*m->cols+j]= m->data[i * m->cols + j] / norma;
			}
		}
		else {
			for (size_t j = 0; j < m->cols; j++) {
				result->data[i * m->cols + j] = m->data[i * m->cols + j];
			}
		}
	}
	return result;
}