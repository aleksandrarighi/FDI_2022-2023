#include <stdio.h>

void stampa_onde(FILE* f, int n) {
    if (n == 0) {
        putc('\n', f);
        putc('\n', f);
        putc('\n', f);
    }

    // Prima riga
    for (int i = 0; i < 1; i++) {
        putc(' ', f);
    }
    putc('-', f);
    for (int i = 2; i <= n; i++) {
        for (int j = i; j < 7; j++) {
            putc(' ', f);
        }
        putc('-', f);
        putc(' ', f);
        putc(' ', f);
        putc(' ', f);
        putc(' ', f);
    }
    putc('\n', f);

    // Seconda riga
    for (int i = 0; i < n; i++) {
        putc('/', f);
        putc(' ', f);
        putc('\\', f);
        putc(' ', f);
        putc(' ', f);
        putc(' ', f);
    }
    putc('\n', f);

    // Ultima riga
    for (int i = 0; i < n; i++) {
        putc(' ', f);
        putc(' ', f);
        putc(' ', f);
        putc('\\', f);
        putc('_', f);
        putc(' ', f);
        putc('/', f);
    }
    putc('\n', f);
}