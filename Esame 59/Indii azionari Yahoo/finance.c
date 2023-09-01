#include "finance.h"
#include <stdlib.h>

struct value* read_historical_series(const char* filename, size_t* n) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	//salto la prima linea, errore nella lettura dell'intestazione
	char temp[256];
	if (fgets(temp, sizeof(temp), f) == NULL) {
		fclose(f);
		return NULL;
	}

	//conto quante righe ci sono nel file
	*n = 0;
	while (fgets(temp, sizeof(temp), f) != NULL) {
		(*n)++;
	}

	//alloco memoria per conservare le righe
	struct value* dati = malloc(*n * sizeof(struct value));
	if (dati == NULL) {
		fclose(f);
		return NULL;
	}

	//torno all'inizio del file per rileggere le righe
	fseek(f, 0, SEEK_SET);
	fgets(temp, sizeof(temp), f); //salto la prima riga

	//leggo le righe dal file e riempio la struct 
	for (size_t i = 0; i < *n; i++) {
		if (fscanf(f, "%10s,%lf,%lf,%lf,%lf,%lf,%lld\n", dati[i].Date, &dati[i].Open, &dati[i].High, &dati[i].Low, &dati[i].Close, &dati[i].AdjClose, &dati[i].Volume) != 7) {
			fclose(f);
			free(dati);
			return NULL;
		} 
	}
	fclose(f);
	return dati;
}