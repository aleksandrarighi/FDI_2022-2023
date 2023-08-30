#include "matrix.h"

int mat_isupper(const struct matrix* matr) {
	if (matr == NULL) {
		return 0;
	}

	if (matr->N != matr->M) {
		return 0;
	}

	for (size_t i = 1; i < matr->N; i++) {
		for (size_t j = 0; j < i; j++) {
			if (matr->data[i * matr->N + j] != 0) {
				return 0;
			}
		}
	}
	return 1;
}