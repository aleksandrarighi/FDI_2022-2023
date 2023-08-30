#include <stdio.h>
#include <string.h>

void stampa_cornicetta(const char* s) {
	int len = strlen(s);

	putchar('/');
	for (int i = 0; i < len + 2; i++) {
		putchar('-');
	}
	putchar('\\');
	putchar('\n');

	putchar('|');
	putchar(' ');
	printf("%s", s);
	putchar(' ');
	putchar('|');
	putchar('\n');

	putchar('\\');
	for (int i = 0; i < len + 2; i++) {
		putchar('-');
	}
	putchar('/');
	putchar('\n');
}