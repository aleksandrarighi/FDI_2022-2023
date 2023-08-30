#include "matrici.h" 

double* diag(double* matr, size_t n) {
	double* diagonale = malloc(n * sizeof(double));
	if (diagonale == NULL) {
		return NULL;
	}
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			if (i == j) {
				diagonale[i] = matr[i * n + j];
			}
		}
	}
	return diagonale;
}