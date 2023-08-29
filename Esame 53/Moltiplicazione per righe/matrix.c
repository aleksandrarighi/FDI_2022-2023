#include "matrix.h"
#include <stdlib.h>

struct matrix* mat_rowmul(const struct matrix* m1, const struct matrix* m2) {
	if (m1 == NULL || m2 == NULL) {
		return NULL;
	}
	if (m1->rows != m2->rows || m2->cols != 1) {
		return NULL;
	}

	struct matrix* moltiplicazione = malloc(sizeof(struct matrix));
	if (moltiplicazione == NULL) {
		return NULL;
	}
	moltiplicazione->rows = m1->rows;
	moltiplicazione->cols = m1->cols;
	moltiplicazione->data = malloc(moltiplicazione->rows * moltiplicazione->cols * sizeof(double));
	if (moltiplicazione->data == NULL) {
		free(moltiplicazione);
		return NULL;
	}

	for (size_t i = 0; i < moltiplicazione->rows; i++) {
		for (size_t j = 0; j < moltiplicazione->rows; j++) {
			moltiplicazione->data[i * moltiplicazione->cols + j] = m1->data[i * m1->cols + j] * m2->data[j];
			//i * m1->cols + j accedo all'elemento nella riga i e nella colonna j della matrice m1;
			//j accedo all'elemento nella colonna j della matrice m2.
		}
	}
	return moltiplicazione;
}
