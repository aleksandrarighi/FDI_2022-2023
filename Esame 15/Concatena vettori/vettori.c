#include "vettori.h"
#include <stdlib.h>

struct vettore* mergeVettori(const struct vettore* a, const struct vettore* b) {
	struct vettore* concatena = malloc(sizeof(struct vettore));
	if (concatena == NULL) {
		return NULL;
	}

	concatena->n = a->n + b->n;
	concatena->data = malloc(concatena->n * sizeof(double));
	if (concatena->data == NULL) {
		free(concatena);
		return NULL;
	}

	for (size_t i = 0; i < a->n; i++) {
		concatena->data[i] = a->data[i];
	}

	for (size_t i = 0; i < b->n; i++) {
		concatena->data[a->n + i] = b->data[i];
	}

	return concatena;
}