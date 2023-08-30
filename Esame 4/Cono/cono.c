#include <stdio.h>

void stampa_cono(unsigned int h) {
    for (unsigned int i = 0; i < h; i++) {
        for (unsigned int j = 0; j < h - i; j++) {
            putchar(' ');
        }

        putchar('/');

        for (unsigned int j = 0; j < 2 * i; j++) {
            if (i == h - 1) {
                putchar('_');
            }
            else {
                putchar(' ');
            }
        }

        putchar('\\');

        putchar('\n');
    }

    for (unsigned int i = 0; i < h - 1; i++) {
        putchar(' ');
    }
    putchar('_');
    putchar('\n');
}

/*int main(void) {
    for (unsigned int i = 0; i < 10; i++) {
        stampa_cono(i);
    }
    return 0;
}*/
