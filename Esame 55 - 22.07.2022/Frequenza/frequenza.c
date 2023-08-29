#include "frequenza.h"
#include <stdlib.h>
#include <string.h>

struct oggetto* piu_frequente(const struct carta* c) {
	size_t* frequenze = calloc(c->n, sizeof(size_t));

	//conto la frequenza degli oggetti;
	for (size_t i = 0; i < c->n; i++) {
		for (size_t j = 0; j < c->n; j++) {
			if (strcmp(c->disegni[i].forma, c->disegni[j].forma) == 0 && strcmp(c->disegni[i].colorenumero, c->disegni[j].colorenumero) == 0) {
				frequenze[i]++;
			}
		}
	}

	//trovo l'oggetto pi� presente
	size_t oggettopi�frequente = 0;
	for (size_t i = 1; i < c->n; i++) {
		if (frequenze[i] > frequenze[oggettopi�frequente]) {
			oggettopi�frequente = i;
		}
	}

	struct oggetto* oggetto = malloc(sizeof(struct oggetto));
	if (oggetto == NULL) {
		free(frequenze);
		return NULL;
	}

	//alloco l'oggetto pi� frequente
	size_t lenform = strlen(c->disegni[oggettopi�frequente].forma) + 1;
	size_t lencolornum = strlen(c->disegni[oggettopi�frequente].colorenumero) + 1;
	oggetto->forma = malloc(lenform);
	oggetto->colorenumero = malloc(lencolornum);
	if (oggetto->forma == NULL || oggetto->colorenumero == NULL) {
		free(frequenze);
		free(oggetto->forma);
		free(oggetto->colorenumero);
		free(oggetto);
		return NULL;
	}

	//copio l'oggetto pi� frequente
	strcpy(oggetto->forma, c->disegni[oggettopi�frequente].forma);
	strcpy(oggetto->colorenumero, c->disegni[oggettopi�frequente].colorenumero);

	free(frequenze);
	return oggetto;

}