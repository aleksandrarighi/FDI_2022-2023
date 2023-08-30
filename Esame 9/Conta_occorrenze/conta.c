#include <stdio.h>
#include <string.h>

unsigned int conta_occorrenze(const char* testo, const char* stringa) {
	if (testo == NULL || stringa == NULL || *testo == '\0' || *stringa == '\0') {
		return 0; 
	}
	unsigned int count = 0;
	size_t len = strlen(stringa);

	for (const char *i = testo; (i = strstr(i, stringa)) != NULL; i++) {
		count++;
		i = i + len - 1; //avanza il puntatore dopo l'ultima occorrenza trovata
	}
	return count;
}