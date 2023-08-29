#include "map.h"
#include <stdio.h>

struct connections* load_connections(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	size_t n;
	if (fscanf(f, "%lu", &n) != 1) {
		fclose(f);
		return NULL;
	}

	struct connections* connessioni = malloc(sizeof(struct connections));
	if (connessioni == NULL) {
		fclose(f);
		return NULL;
	}

	connessioni->n;
	connessioni->data = malloc(n * n * sizeof(bool));
	if (connessioni->data == NULL) {
		fclose(f);
		return NULL;
	}

	for (size_t i = 0; i < n * n; i++) {
		connessioni->data[i] = false;
	}

	size_t rows = 0;
	size_t cols = 0;
	int value;

	while (fscanf(f, "%d", &value) == 1) {
		if (value == -1) {
			rows++;
			cols = 0;
		}
		else {
			connessioni->data[rows * n + cols] = true;
			connessioni->data[cols * n + rows] = true;
			cols++;
		}
	}
	fclose(f);
	return connessioni;
}