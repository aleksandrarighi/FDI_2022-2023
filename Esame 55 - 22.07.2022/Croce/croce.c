#include <stdio.h>

void stampa_croce(FILE* f, size_t dim) {
	if (dim == 0) {
		return;
	}

	for (size_t i = 0; i < dim; i++) {
		for (size_t j = 0; j < dim; j++) {
			if (i == j) {
				fprintf(f, "\\");
			}
			else if (i == dim - j - 1) {
				fprintf(f, "/");
			}
			else {
				fprintf(f, " ");
			}
		}
		fprintf(f, "\n");
	}
}