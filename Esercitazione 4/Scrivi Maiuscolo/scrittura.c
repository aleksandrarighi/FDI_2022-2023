#include "scrittura.h"

int scrivimaiuscolo(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return 0;
	}

	int c;
	while ((c = fgetc(f)) != EOF) {
		if (islower(c)) {
			c = toupper(c);
		}
		putchar(c);
	}

	fclose(f);
	return 1;
}
