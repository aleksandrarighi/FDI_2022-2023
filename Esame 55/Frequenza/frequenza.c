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

	//trovo l'oggetto più presente
	size_t oggettopiùfrequente = 0;
	for (size_t i = 1; i < c->n; i++) {
		if (frequenze[i] > frequenze[oggettopiùfrequente]) {
			oggettopiùfrequente = i;
		}
	}

	struct oggetto* oggetto = malloc(sizeof(struct oggetto));
	if (oggetto == NULL) {
		free(frequenze);
		return NULL;
	}

	//alloco l'oggetto più frequente
	size_t lenform = strlen(c->disegni[oggettopiùfrequente].forma) + 1;
	size_t lencolornum = strlen(c->disegni[oggettopiùfrequente].colorenumero) + 1;
	oggetto->forma = malloc(lenform);
	oggetto->colorenumero = malloc(lencolornum);
	if (oggetto->forma == NULL || oggetto->colorenumero == NULL) {
		free(frequenze);
		free(oggetto->forma);
		free(oggetto->colorenumero);
		free(oggetto);
		return NULL;
	}

	//copio l'oggetto più frequente
	strcpy(oggetto->forma, c->disegni[oggettopiùfrequente].forma);
	strcpy(oggetto->colorenumero, c->disegni[oggettopiùfrequente].colorenumero);

	free(frequenze);
	return oggetto;

}