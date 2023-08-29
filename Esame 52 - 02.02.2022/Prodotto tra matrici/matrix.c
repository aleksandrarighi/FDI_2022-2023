#include "matrix.h"
#include <stdlib.h>

struct matrix* mat_mul(const struct matrix* m1, const struct matrix* m2) {
	if (m1 == NULL || m2 == NULL || m1->cols != m2->rows) {
		return NULL;
	}

	struct matrix* prodotto = malloc(sizeof(struct matrix));
	prodotto->rows = m1->rows;
	prodotto->cols = m2->cols;
	prodotto->data = malloc(prodotto->rows * prodotto->cols * sizeof(double));

		for (size_t i = 0; i < prodotto->rows; i++) {
		for (size_t j = 0; j < prodotto->cols; j++) {
			double somma = 0.0;
			for (size_t k = 0; k < m1->cols; k++) {
				somma += m1->data[i * m1->cols + k] * m2->data[k * m2->cols + j];
			}
			prodotto->data[i * prodotto->cols + j] = somma;
		}
	}
		return prodotto;

}