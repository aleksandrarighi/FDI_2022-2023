#include <stdint.h>
int* rotate(const int* vec, size_t len, size_t r) {
	if (vec == 0) {
		return NULL;
	}
	
	int* res = malloc(sizeof(int) * len);

	for (int i = 0; i < len; ++i) {
		 res[(r + i) % len] = vec[i];
	}
	return res;
}