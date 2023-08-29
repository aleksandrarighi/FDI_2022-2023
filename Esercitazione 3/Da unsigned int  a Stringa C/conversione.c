/*Creare il file "conversione.c" in cui deve essere definita la funzione corrispondente alla seguente dichiarazione:

extern char *converti(unsigned int n);
La funzione accetta come parametro un numero naturale o nullo n e deve restituire un puntatore ad un array di caratteri zero terminato allocato dinamicamente, contenente la rappresentazione in base 10 del numero intero, con le singole cifre rappresentate in ASCII. Ad esempio: il numero 4355 genererà l'array di caratteri: "4355", ovvero { 52, 51, 53, 53, 0 }, o anche { 0x34, 0x33, 0x35, 0x35, 0x00 }.

Provate a fare questo esercizio prima senza funzioni di libreria, e poi utilizzando la reference del C per trovare una funzione utile.

In questo esercizio non create un file "conversione.h", e nel vostro file "main.c" di test mettete la funzione main che utilizza la funzione converti(). Il main non deve generare warning.*/

#include <stdlib.h>

char* converti(unsigned int n) {
	unsigned int tmp = n;
	int c = 0;

	while (tmp > 0) {
		tmp /= 10;
		c++;
	}

	char* s = malloc((c + 1) * sizeof(char));
	if (s == NULL) {
		return NULL;
	}

	for (int i = c - 1; i >= 0; i--) {
		s[i] = '0' + (n % 10);
	}

	s[c] = '\0';

	return s;
}