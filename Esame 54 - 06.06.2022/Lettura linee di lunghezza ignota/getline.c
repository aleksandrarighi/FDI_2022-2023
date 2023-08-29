#include "getline.h"
#include <stdlib.h>

size_t getline(char** lineptr, size_t* n, FILE* stream) {
	if (*lineptr == NULL || *n < 16) {
		*n = 16;
		*lineptr = malloc(*n);
		if (*lineptr == NULL) {
			return 0; //errore di allocazione in memoria
		}
	}

	//dichiaro una variabile count per tenere il conto del numero di caratteri letti
	//dichiaro una variabile c per memorizzare il carattere corrente
	int count = 0; 
	int c;
	//faccio un ciclo while che inizializzi i caratteri uno alla volta fino a quando non si raggiunge la fine dello stream
	while ((c = fgetc(stream)) != EOF) {
		if (count >= *n - 1) { //il buffer è pieno e devo riallocare memoria
			*n *= 2;
			char* new_lineptr = realloc(*lineptr, *n);
			if (new_lineptr == NULL) {
				return count;
			}
			*lineptr = new_lineptr;
		}
		//assegno il carattere letto al buffer e incremento il contatore count.
		//se il carattere letto è un newline('\n'), interrompo il ciclo
		(*lineptr)[count++] = c;
		if (c == '\n') {
			break;
		}
	}
	//aggiungo il terminatore di stringa '\0'
	(*lineptr)[count++] = '\0';
	//restituisco il numero di caratteri letti
	return count;
}