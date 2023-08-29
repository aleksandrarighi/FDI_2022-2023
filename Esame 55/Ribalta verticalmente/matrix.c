#include "matrix.h"
#include <stdlib.h>

struct matrix* matrix_flip_v(const struct matrix* m) {
	if (m == NULL) {
		return NULL;
	}

	struct matrix* ribaltata = malloc(sizeof(struct matrix));
	ribaltata->rows = m->rows;
	ribaltata->cols = m->cols;
	ribaltata->data = malloc(ribaltata->rows * ribaltata->cols * sizeof(double));

	for (size_t i = 0; i < m->rows; i++) {
		for (size_t j = 0; j < m->cols; j++) {
			ribaltata->data[(m->rows - i - 1) * m->cols + j] = m->data[i * m->cols + j];
			//(m->rows - i - 1) indica l'ultima riga della nostra matrice, *(*m->cols + j) indica il primo elemento da sostituire;
			//i * m->cols + j indica la posizione della matrice iniziale in cui andare a mettere l'elemento;
		}
	}
	return ribaltata;
}