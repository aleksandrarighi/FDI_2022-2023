#include <stdio.h>

void histogram(const char* values, size_t n) {
	if (values == NULL || n == 0) {
		return;
	}

	for (size_t i = 0; i < n; i++) {
		for (int j = 0; j < values[i]; j++) {
			printf("*");
		}
		printf("\n");
	}
}