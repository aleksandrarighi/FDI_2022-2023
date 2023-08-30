#include "array.h"
#include <stdlib.h>

double* array_remove(const double* arr, size_t n, size_t pos) {
	if (pos >= n || arr == NULL) {
		return NULL;
	}

	size_t new_size = n - 1;

	double* new_arr = malloc(new_size * sizeof(double));
	if (new_arr == NULL) {
		return NULL;
	}

	for (size_t i = 0; i < pos; i++) {
		new_arr[i] = arr[i];
	}

	for (size_t i = pos; i < n - 1; i++) {
		new_arr[i - 1] = arr[i];
	}

	return new_arr;
}