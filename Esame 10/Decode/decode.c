#include "decode.h"

extern void decode(FILE* f) {
	if (f == NULL) {
		return;
	}

	int c; 
	while ((c = fgetc(f)) != EOF) {
		if (c >= '1' && c <= '9') {
			int repeat = c - '0';
			c = fgetc(f); //leggo il carattere successivo
			for (int i = 0; i < repeat; i++) {
				putchar(c);
			}
		}
		else {
			putchar(c);
		}
	}
}