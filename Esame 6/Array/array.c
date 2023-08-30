#include "array.h"
#include <string.h>

void array_remove(double* arr, size_t* pn, size_t pos) {
	if (pos >= *pn) {
		return;
	}

	for (size_t i = pos; i < (*pn) - 1; i++) {
		arr[i] = arr[i + 1];
	}

	(*pn)--;
}