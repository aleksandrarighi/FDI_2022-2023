#include "quadrati.h"
#include <stdio.h>

void stampa_quadrato(unsigned int lato) {
	for (unsigned int i = 0; i < lato; i++) {
		for (unsigned j = 0; j < lato; j++) {
			if (i == 0 || i == lato - 1 || j == 0 || j == lato - 1) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

