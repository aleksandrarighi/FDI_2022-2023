#include "unico.h"
#include <stdlib.h>
#include <string.h>

const struct oggetto* unico(const struct carta* c) {
	for (size_t i = 0; i < c->n; i++) {
		int unica_forma = 1;
		int unico_colore = 1;

		for (size_t j = 0; j < c->n; j++) {
			if (i != j) {
				if (strcmp(c->disegni[i].forma, c->disegni[j].forma) == 0) {
					unica_forma = 0;
				}
				if (strcmp(c->disegni[i].colore, c->disegni[j].colore) == 0) {
					unico_colore = 0;
				}
			}
		}
		if (unica_forma || unico_colore) {
			return &(c->disegni[i]);
		}
	}
	return NULL;
}