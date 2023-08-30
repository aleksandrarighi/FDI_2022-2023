#include "dati.h"
#include <stdio.h>
#include <stdlib.h>

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

int salva_conteggio_bin(const char* filename, struct dato* pdati, unsigned int n) {
	//Qui viene dichiarato un array conteggio_classi di lunghezza 11, inizializzato con zeri. 
	//Questo array verrà utilizzato per tenere traccia del numero di dati per ogni classe da 0 a 10.
	unsigned int conteggio_classi[11] = { 0 };

	/*Questo ciclo for scorre attraverso l'array dei dati pdati di lunghezza n.
	Per ogni dato, estrae la classe (classe) associata a quel dato.
	Se la classe è compresa tra 0 e 10 (inclusi), incrementa il conteggio della classe corrispondente
	nell'array conteggio_classi.*/
	for (unsigned int i = 0; i < n; i++) {
		unsigned int classe = pdati[i].classe;
		if (classe <= 10) {
			conteggio_classi[classe]++;
		}
	}
	
	FILE* f = fopen(filename, "wb");
	if (f == NULL) {
		return 0;
	}
	
	/*Questo secondo ciclo for scorre attraverso l'array conteggio_classi da 0 a 10 (inclusi). 
	Per ogni classe, estrae il conteggio associato (conteggio) e utilizza la funzione fwrite 
	per scrivere il conteggio nel file binario f. 
	L'uso di &conteggio passa l'indirizzo di memoria della variabile conteggio a fwrite.*/
	for (unsigned int i = 0; i <= 10; i++) {
		unsigned int conteggio = conteggio_classi[i];
		fwrite(&conteggio, sizeof(unsigned int), 1, f);
	}

	fclose(f);
	return 1;
}