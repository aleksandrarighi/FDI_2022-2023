#include "matrix.h"

void matrix_write(const struct matrix* matr, FILE* f) {
	if (matr == NULL || f == NULL) {
		return;
	}

	fprintf(f, "%lu\n%lu\n", matr->N, matr->M);

	for (size_t i = 0; i < matr->N; i++) {
		for (size_t j = 0; j < matr->M; j++) {
			fprintf(f, ".6%lf", matr->data[i * matr->M + j]);

			if (j != matr->M - 1) {
				fprintf(f, "\t");
			}
		}
		fprintf(f, "\n");
	}
}