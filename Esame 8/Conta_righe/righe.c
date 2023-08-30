#include "righe.h"

unsigned int conta_righe(FILE* f) {
	if (f == NULL) {
		return 1;
	}

	char prev_c = '\n'; // Carattere precedente (inizializzato a '\n' per gestire il caso di un file vuoto)
	int count = 0;
	
	while (1) {
		int c = fgetc(f);

		if (c == EOF) {
			break;
		}

		if (c == '\n') {
			count++;
		}

		prev_c = c;
	}

	if (prev_c != '\n') {
		count++;
	}

	return count;
 }