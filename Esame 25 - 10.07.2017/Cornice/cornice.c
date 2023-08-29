#include <stdlib.h>
#include <stdio.h>

void stampa_cornice(size_t n) {
	for (size_t i = 0; i < n; i++) {
		printf(".--.      ");
	}
	printf("\n");
	for (size_t i = 0; i < n; i++) {
		printf("::::.\\::::");
	}
	printf("\n");
	for (size_t i = 0; i < n; i++) {
		printf("      `--'");
	}
	printf("\n");
}