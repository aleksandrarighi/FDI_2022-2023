#include "dati.h"
#include <stdio.h>

struct dato* read_dati(const char* filename, unsigned int* pn) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	unsigned int num_dati = 0;
	double valore;
	unsigned int classe;

	// Conta il numero di dati nel file
	while (fscanf(f, "%lf %u", &valore, &classe) == 2) {
		num_dati++;
	}

	// Torna all'inizio del file
	rewind(f);

	struct dato* dati = malloc(num_dati * sizeof(struct dato));
	if (dati == NULL) {
		fclose(f);
		return NULL;
	}

	for (unsigned int i = 0; i < num_dati; i++) {
		if (fscanf(f, "%lf %u", &valore, &classe) == 2) {
			dati[i].valore = valore;
			dati[i].classe = classe;
		}
		else {
			free(dati);
			fclose(f);
			return NULL;
		}
	}
	fclose(f);
	*pn = num_dati;
	return dati;
}