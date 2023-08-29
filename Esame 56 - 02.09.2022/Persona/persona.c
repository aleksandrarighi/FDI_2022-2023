#include "persona.h"
#include <stdlib.h>
#include <stdio.h>

struct persona* leggi_persone(const char* filename, size_t* size) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		*size = 0;
		fclose(f);
		return NULL;
	}

	size_t total_people;
	if (fscanf(f, "%lu", &total_people) != 1) {
		*size = 0;
		fclose(f);
		return NULL;
	}

	struct persona* people = malloc(total_people * sizeof(struct persona));
	if (people == NULL) {
		*size = 0;
		fclose(f);
		return NULL;
	}
	for (size_t i = 0; i < total_people; i++) {
		if (fscanf(f, "%i %*c %[^\n]", &people[i].anni, people[i].nome) != 2) {
			*size = 0;
			free(people);
			fclose(f);
			return NULL;
		}
	}
	fclose(f);
	return people;
}

/*%i indica che verrà letto un intero e assegnato alla variabile corrispondente (people[i].anni). L'intero può essere specificato in formato decimale, ottale o esadecimale.
%*c indica che verrà letto un carattere e ignorato. Il carattere letto sarà un carattere virgola, ma poiché viene preceduto dal modificatore *, non verrà assegnato a nessuna variabile. In pratica, viene semplicemente ignorato.
%[^\n] La specifica %[^\n] è un formato di scansione che indica a fscanf di leggere una sequenza di caratteri fino a quando non viene raggiunto un carattere di nuova riga ('\n'). In pratica, questa specifica permette di leggere una stringa che può contenere spazi e tabulazioni, ma si interrompe quando viene trovato il carattere di nuova riga.*/