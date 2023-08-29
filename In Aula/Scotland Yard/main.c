#include "map.h"

int main(void) {
	struct connections * ris = load_connections("example.txt");
	for (size_t r = 0; r < ris->n; ++r) {
		for (size_t c = 0; r < ris->n; ++c) {
			printf("%i", ris->data[r * n + c]);
		}			
		printf("/n");
	}

	free(ris->data);
	free(ris);
	return 0;
	}