#include "risiko.h"

void confronta_lanci(const struct lancio* attacco, const struct lancio* difesa, char* perse_attacco, char* perse_difesa) {
	*perse_attacco = 0;
	*perse_difesa = 0;

	int num_confronti = attacco->n_dadi;
	if (difesa->n_dadi < num_confronti) {
		num_confronti = difesa->n_dadi;
	}

	for (int i = 0; i < num_confronti; i++) {
		if (attacco->valori[i] > difesa->valori[i]) {
			(*perse_difesa)++;
		}
		else {
			(*perse_attacco)++;
		}
	}
}