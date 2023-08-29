#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool scrivi_intero(const char* filename, int i) {
	if (filename == NULL) {
		return false;
	}

	FILE* f = fopen(filename, "w");

	if (f == NULL) {
		return false;
	}

	fprintf(f, "%i", i);
	fclose(f);

	return true;
}