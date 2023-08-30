#include <stdlib.h>

double media(double* arr, size_t n) {
	if (n == 0) {
		return 0.0;
	}

	double sum = 0.0;
	for (size_t i = 0; i < n; i++) {
		sum += arr[i];
	}

	return sum / n;
}