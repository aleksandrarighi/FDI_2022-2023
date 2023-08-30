#include "vettori.h"

double prodotto_scalare(const double* x, const double* y, size_t n) {
	if (n == 0 || x == NULL || y == NULL) {
		return 0; 
	}

	double sum = 0; 
	for (size_t i = 0; i < n; i++) {
		double prodotto = x[i] * y[i];
		sum += prodotto;
	}
	return sum;
}