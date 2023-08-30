#include <stdlib.h>

int* crea_inizializza(unsigned int n, int val) {
	int* new_vec = malloc(n * sizeof(int));

	for (unsigned int i = 0; i < n; i++) {
		new_vec[i] = val - i;
	}

	return new_vec;
}