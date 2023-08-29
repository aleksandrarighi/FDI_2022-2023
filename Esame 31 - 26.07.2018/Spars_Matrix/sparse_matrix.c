#include "sparse_matrix.h"

double sm_get(struct sparse_matrix* m, uint32_t row, uint32_t col) {
	if (m == NULL || row >= m->rows || col >= m->cols) {
		return 0.0;
	}

	for (uint32_t i = 0; i < m->nnz; i++) {
		if (m->rowidxs[i] == row && m->colidxs[i] == col) {
			return m->data[i];
		}
	}
	return 0.0; 
}