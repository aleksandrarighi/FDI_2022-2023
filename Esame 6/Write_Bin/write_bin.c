#include <stdio.h>

extern void write_bin(const double* values, size_t n, FILE* f) {
	if (*values == 0 || n == 0) {
		return;
	}

	fwrite(values, sizeof(double), n, f);
}