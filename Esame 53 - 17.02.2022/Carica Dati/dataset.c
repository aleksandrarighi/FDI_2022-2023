#include "dataset.h"
#include <stdio.h>
#include <string.h>

struct dataset* dataset_load(const char* filename) {
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		return NULL;
	}

	struct dataset* dataset = malloc(sizeof(struct dataset)); //la funzione restituisce il dataset allocato dinamicamente e riempito con le righe lette da file
	if (dataset == NULL) {
		fclose(f);
		return NULL;
	}
	//inizializziamo il dataset
	dataset->data = NULL;
	dataset->nrows = 0;
	
	char line[256];//buffer per leggere una riga da file
	size_t line_length;

	while (fgets(line, sizeof(line), f) != NULL) {
		line_length = strlen(line);

		if (line[line_length - 1] == '\n') {
			line[line_length - 1] = '\0'; //rimuovo il carattere a capo
			line_length--;
		}

		char* commaposition = strchr(line, ','); //prendo la posizione della virgola

		size_t f_length = commaposition - line;

		struct row* row = malloc(sizeof(struct row));
		if (row == NULL) {
			fclose(f);
			free(dataset);
			return NULL;
		}

		row->filename = malloc((f_length + 1) * sizeof(char)); //Nelle righe bisogna inserire un puntatore al nome del file (allocato dinamicamente)
		if (row->filename == NULL) {
			fclose(f);
			free(row);
			free(dataset);
			return NULL;
		}

		strcpy(row->filename, line);
		row->filename[f_length] = '\0';
		row->prognosis = commaposition[1];

		struct row* new_data = realloc(dataset->data, (dataset->nrows + 1) * sizeof(struct row));
		if (new_data == NULL) {
			fclose(f);
			free(row->filename);
			free(row);
			return NULL;
		}

		dataset->data = new_data;
		dataset->data[dataset->nrows] = *row;
		dataset->nrows++;
	}

	fclose(f);
	return dataset;
}