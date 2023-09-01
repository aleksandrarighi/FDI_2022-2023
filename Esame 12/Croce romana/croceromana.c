#include <stdio.h>

void croceromana(FILE* f, unsigned char n) {
	//prima riga
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n*2; j++) {
			putc(' ', f);
		}
		putc('|', f);
		putc('\n', f);
	}

	//centro
	for (int i = 0; i < n * 2; i++) {
		putc('-', f);
	}
	putc('+', f);
	for (int i = 0; i < n * 2; i++) {
		putc('-', f);
	}
	putc('\n', f);

	//ultime righe
	for (int i = 0; i < n * 2; i++) {
		for (int j = 0; j < n * 2; j++) {
			putc(' ', f);
		}
		putc('|', f);
		putc('\n', f);
	}
	putc('\n', f);
}