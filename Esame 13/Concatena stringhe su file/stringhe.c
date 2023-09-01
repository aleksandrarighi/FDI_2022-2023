#include "stringhe.h"
#include <string.h>

void stringhe_scrivi(const char* filename, const char** vs, size_t n) {
	FILE* f = fopen(filename, "wb");
	if (f == NULL) {
		return;
	}

	for (size_t i = 0; i < n; i++) {
		const char* current = vs[i];
		size_t len = strlen(current);
		fwrite(current, sizeof(char), len + 1, f);
	}

	fclose(f);
}