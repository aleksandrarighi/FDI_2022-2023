#include <stdio.h>
#include <stdint.h>

void scrivi_v(FILE* f, uint8_t n) {
	if (n == 0) {
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			fprintf(f, " ");
		}
		fprintf(f, "\\");

		for (int j = 0; j < (n - i - 1) * 2; j++) {
			fprintf(f, " ");
		}
		fprintf(f, "/");
		fprintf(f, "\n");
	}
}