#include <stdlib.h>

void reverse(int* vec, size_t len, size_t from, size_t to) {
	if (vec == NULL || from >= len || to > len || from >= to) {
		return;
	}

	while (from < to) {
		int tmp = vec[from];
		vec[from] = vec[to - 1];
		vec[to - 1] = tmp;
		from++;
		to--;
	}
}