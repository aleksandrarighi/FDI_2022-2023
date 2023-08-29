#include "matrix.h"

struct matrix* mat_rowmul(const struct matrix* m1, const struct matrix* m2) {
	if (m1 == NULL || m2 == NULL) {
		return NULL;
	}
	if (m1->rows != m2->rows || m2->cols != 1) {
		return NULL;
	}

	struct matrix* out = malloc(sizeof(struct matrix));
	out->rows = m1->rows;
	out->cols = m1->cols;
	out->data = malloc (out->rows * out->cols*sizeof(double));

	for (size_t r = 0; r < out->rows; ++r) {
		for (size_t c = 0; c < out->cols; ++c) {
			out->data[r * out->cols + c] =
				m1->data[r * m1->cols + c] *
				m2->data[r * m2->cols + 0]; //m2->data[r];
		}
	}
	return out;
}
