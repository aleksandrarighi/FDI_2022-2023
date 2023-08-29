#include "unici.h"

int* unici(const int* vec, size_t size, size_t* newsize) {

	int* tmp = malloc(size * sizeof(int));

	*newsize = 0;
	for (size_t i = 0; i < size; i++) {
		int valore = vec[i];
		int duplicato = 0; 

		for (size_t j = 0; j < *newsize; j++) {
			if (tmp[j] == valore) {
				duplicato = 1;
				break;
			}
		}
		if (!duplicato) {
			tmp[*newsize] = valore;
			(*newsize)++;
		}
	}
	int* valoriunici = malloc(*newsize * sizeof(int));
	for (size_t i = 0; i < *newsize; i++) {
		valoriunici[i] = tmp[i];
	}
	free(tmp);
	return valoriunici;
}