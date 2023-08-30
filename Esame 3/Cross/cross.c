#include <stdio.h>

void stampa_cross(unsigned int n) {
	for (unsigned int i = 0; i <= 2 * n + 1; i++) {
		for (unsigned int j = 0; j <= 2 * n + 1; j++) {
			if (i == n && j == n) {
				putchar('x');
			}
			else if (i == j) {
				putchar('\\');
			}
			else if (i == 2 * n - j) {
				putchar('/');
			}
			else {
				putchar(' ');
			}
		}
		putchar('\n');
	}
}