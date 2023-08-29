#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern void plotter(const char* p) {
    int currentIndex = 0;
    int value = p[currentIndex];

    while (value != 0) {
        if (value < 0) {
            char nextChar = p[currentIndex + 1];

            for (int i = 0; i < abs(value); i++) {
                printf("%c", nextChar);
            }

            currentIndex += 2; // Avanza di due posizioni
        }
        else if (value > 0) {
            printf("%c", value);
            currentIndex++; // Avanza di una posizione
        }

        value = p[currentIndex]; // Aggiorna il valore corrente

        if (value == 0) {
            break; // Termina se il valore corrente è zero
        }
    }
}