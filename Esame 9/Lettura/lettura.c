#include "lettura.h"
#include <stdlib.h>

char* fgets_malloc(FILE* f) {
	if (f == NULL) {
		return NULL;
	}

	char* temp = NULL; 
	int c; //carattere letto dal file
	size_t size = 0; //dimensione della variabile temporanea temp
	size_t len = 0; //lunghezza della riga letta

	//leggo i caratteri dal file finché non raggiungo EOF o a capo
	while ((c = fgetc(f)) != EOF && c != '\n') {
		//se la variabile temporanea temp è piena la rialoco con il doppio della sua dimensione
		if (len + 1 >= size) {
			if (size == 0) {
				size = 128;
			}
			else {
				size *= 2;
			}
			char* new_temp = realloc(temp, size);
			if (new_temp == NULL) {
				free(temp);
				return NULL;
			}
			temp = new_temp;
		}
		temp[len++] = c; //assegno il carattere alla variabile temporanea e incremento la lunghezza
	}
	//se la lettura è fallita perché non ha letto nulla e ho raggiunto EOF
	if (len == 0 && c == EOF) {
		return NULL;
	}

	//alloco la memoria per la riga letta
	char* new_newtemp = realloc(temp, len + 1);
	if (new_newtemp == NULL) {
		free(new_newtemp);
		return NULL;
	}

	temp = new_newtemp;

	temp[len] = '\0'; //aggiungo il terminatore NULL
	return temp;
}