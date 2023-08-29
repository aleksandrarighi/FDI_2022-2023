#include "matrix.h"

void mat_normalize_rows(struct matrix* m) {
	if (m == NULL) {
		return;
	}

	for (size_t i = 0; i < m->rows; i++) {
		double norm = 0;

		// Calcola la norma euclidea della riga corrente
		for (size_t j = 0; j < m->cols; j++) {
			double element = m->data[i * m->cols + j];
			norm += element * element;
		}

		norm = sqrt(norm);

		// Normalizza la riga corrente se la norma è diversa da zero
		if (norm != 0) {
			for (size_t j = 0; j < m->cols; j++) {
				m->data[i * m->cols + j] /= norm;
			}
		}
	}
}
