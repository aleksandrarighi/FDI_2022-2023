#include "matrix.h"
#include <stdlib.h>

void mat_symdecomp(const struct matrix* m, struct matrix* S, struct matrix* A) {
	if (m == NULL || S == NULL || A == NULL) {
		return;
	}

	if (m->rows != m->cols) {
		return;
	}

	//alloco i dati per S e per A
	S->rows = m->rows;
	S->cols = m->cols;
	A->rows = m->rows;
	A->cols = m->cols;
	S->data = malloc(S->rows * S->cols * sizeof(double));
	A->data = malloc(A->rows * A->cols * sizeof(double));

	if (S == NULL || A == NULL) {
		free(S->data);
		free(A->data);
		return;
	}

	for (size_t i = 0; i < S->rows; i++) {
		for (size_t j = 0; j < S->cols; j++) {
			S->data[i * S->cols + j] = (m->data[i * m->cols + j] + m->data[j * m->cols + i]) / 2;
			A->data[i * A->cols + j] = (m->data[i * m->cols + j] - m->data[j * m->cols + i]) / 2;
		}
	}
}