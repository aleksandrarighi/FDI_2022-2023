/*Creare un file "iota.c". Nel file, si realizzi in linguaggio C la funzione corrispondente alla seguente dichiarazione:

extern void iota(uint32_t *x, size_t n);
La funzione deve riempire il vettore x di n interi senza segno a 32 bit con il relativo indice. Ad esempio: il primo dovrà essere inizializzato a 0, il secondo a 1, il terzo a 2 e così via.

Se x vale NULL la funzione non fa nulla.*/

#include <stdint.h>
#include <stdlib.h>

void iota(uint32_t* x, size_t n) {
	if (x == NULL) {
		return;
	}
	for (size_t i = 0; i < n; i++) {
		x[i] = i;
	}
}