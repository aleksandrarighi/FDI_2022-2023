#include <stdlib.h>

size_t shorten(int* v, size_t n, int max) {
	if (v == NULL) {
		return 0;
	}

	size_t new_size = 0;
	for (size_t i = 0; i < n; i++) {
		if (v[i] <= max) {
			v[new_size] = v[i];
			new_size++;
		}
	}
	return new_size;
}