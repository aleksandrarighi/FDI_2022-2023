#include <stdio.h>

void ripeti(FILE* f, char c, unsigned char n) {
	while (n > 0) {
		putc(c, f);
		n--;
	}
}

void capsula(FILE* f, unsigned char n) {
	//prima riga
	ripeti(f, ' ', n);
	ripeti(f, '-', n);
	putc('\n', f);

	//alto
	for (size_t i = 0; i < n; i++) {
		ripeti(f, ' ', n - 1 - i);
		putc('/', f);
		ripeti(f, ' ', n + 2 * i);
		putc('\\', f);
		putc('\n', f);
	}

	//centro
	for (size_t i = 0; i < n; i++) {
		putc('|', f);
		ripeti(f, ' ', 3 * n - 2);
		putc('|', f);
		putc('\n', f);
	}

	//basso
	for (size_t i = n - 1; i > 0; i--) {
		ripeti(f, ' ', n - 1 - i);
		putc('\\', f);
		ripeti(f, ' ', n + 2 * i);
		putc('/', f);
		putc('\n', f);
	}
	
	//ultima riga
	ripeti(f, ' ', n - 1);
	putc('\\', f);
	ripeti(f, '_', n);
	putc('/', f);
	putc('\n', f);
}