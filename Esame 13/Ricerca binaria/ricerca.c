#include <stdio.h>

int ricerca_binaria(const int* v, size_t n, int x) {
	if (v == NULL) {
		return -1;
	}

	size_t primo = 0;
	size_t ultimo = n - 1;

	while (primo <= ultimo) {
		size_t m = (primo + ultimo) / 2;

		if (v[m] == x) {
			return m;
		}

		else if (v[m] > x) {
			ultimo = m - 1;
		}

		else {
			primo = m + 1;
		}
	}
	return -1;
}