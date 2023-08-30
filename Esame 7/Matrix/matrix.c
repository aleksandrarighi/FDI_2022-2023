#include "matrix.h"
#include <stdlib.h>

int matrix_read(struct matrix* matr, FILE* f) {
	if (matr == NULL || f == NULL) {
		return 0;
	}

	if (fscanf(f, "%lu\n%lu\n", &matr->N, &matr->M) != 2) {
		return 0;
	}

	matr->data = malloc(matr->N * matr->M * sizeof(double));
	if (matr->data == NULL) {
		return 0;
	}

	for (size_t i = 0; i < matr->N; i++) {
		for (size_t j = 0; j < matr->M; j++) {
			if (fscanf(f, ".6%lf", &matr->data[i * matr->M + j]) != 1) {
				free(matr->data);
				return 0;
			}
			if (j < matr->M - 1) {
				fscanf(f, "\t");
			}
		}
		fscanf(f, "\n");
	}
	return 1;
}