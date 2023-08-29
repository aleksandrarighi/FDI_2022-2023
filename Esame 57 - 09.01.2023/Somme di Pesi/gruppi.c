#include <stdlib.h>
#include <stdio.h>

extern int* read_gruppi(const char* filename, size_t* ngruppi) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	int value;
	int sum = 0; // variabile per tenere traccia della somma dei valori di ogni gruppo
	int* sums = NULL; // array delle somme dei gruppi
	size_t numGroups = 0; // numero di gruppi letti

	for (; fscanf(f, "%i", &value) == 1; fscanf(f, "%*[^\n]"), fgetc(f)) {
		sum += value;

		char c = fgetc(f);
		if (c == '\n' || c == EOF) {
			// letto riga vuota o raggiunto la fine del file, quindi completato un gruppo
			int* newSums = realloc(sums, (numGroups + 1) * sizeof(int));
			if (newSums == NULL) {
				// gestisci l'errore se l'allocazione fallisce
				free(sums);
				fclose(f);
				return NULL;
			}
			sums = newSums;
			sums[numGroups] = sum;
			sum = 0; // azzero la somma per il prossimo gruppo
			numGroups++;
		}
	}

	fclose(f);

	*ngruppi = numGroups;
	return sums;
}

