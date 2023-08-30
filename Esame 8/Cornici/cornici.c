#include <stdio.h>

void cornici(unsigned int n) {
	if (n == 0) {
		putchar('+');
		putchar('\n');
		return;
	}

	//prima riga
	putchar('+');
	for (unsigned int i = 0; i < n; i++) {
		putchar('-');
	}
	putchar('+');
	putchar('\n');

	//righe interne
	for (unsigned int i = 0; i < n; i++) {
		putchar('|');
		for (unsigned int j = 0; j < n; j++) {
			if (i == j) {
				putchar('+');
			}
			else {
				putchar('-');
			}
		}
		putchar('+');
		putchar('|');
		putchar('\n');
	}	

	//stampo l'ultima riga
	putchar('+');
	for (unsigned int i = 0; i < n; i++) {
		putchar('-');
	}
	putchar('+');
	putchar('\n');
}