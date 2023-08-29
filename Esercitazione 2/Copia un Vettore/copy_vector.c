/*Creare un file “copy_vector.c”. Nel file, si realizzi in linguaggio C la funzione corrispondente alla seguente dichiarazione:

extern void copy_vector(uint32_t *dst, uint32_t *src, size_t n);
La funzione riceve come parametri:

dst un puntatore destinazione ad una zona di memoria in grado di contenere n interi senza segno a 32 bit
src un puntatore sorgente ad una zona di memoria in grado di contenere n interi senza segno a 32 bit
n il numero di interi che descrive la dimensione delle due zone di memoria.
Il suo scopo è quello di copiare gli n interi puntati da src in dst.*/

#include <stdint.h>
#include <stdlib.h>

void copy_vector(uint32_t* dst, uint32_t* src, size_t n) {
	if (dst == NULL || src == NULL) {
		return;
	}

	for (size_t i = 0; i < n; i++) {
		dst[i] = src[i];
	}
}

/*int main(void) {
	size_t n = 8;
	uint32_t dst[8];
	uint32_t src[8] = { 2, 5, 8, 13, 6, 9, 10, 7 };

	copy_vector(&dst, &src, n);
	return 0;
}*/