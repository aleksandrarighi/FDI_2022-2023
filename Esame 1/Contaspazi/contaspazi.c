#include <stdlib.h>
#include <string.h>
#include <stdio.h>

unsigned int conta_spazi(const char* s) {
	unsigned int count = 0; 
	
	while (*s != '\0') {
		if (*s == ' ') {
			count++;
		}
		s++;
	}
	return count;
}

/*int main(void) {
		const char* frase = "prova stringa in cui contare gli spazi";
		unsigned int numero_spazi = conta_spazi(frase);

		printf("La frase: \"%s\"\n", frase);
		printf("Numero di spazi: %u\n", numero_spazi);

		return 0;
}
*/