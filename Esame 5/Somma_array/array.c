#include "array.h"
#include <stdlib.h>

double* array_somma(const double* arr1, const double* arr2, size_t n) {
	double* new_array = malloc(n * sizeof(double));
	for (size_t i = 0; i < n; i++) {
		new_array[i] = arr1[i] + arr2[i];
	}
	return new_array;
}
