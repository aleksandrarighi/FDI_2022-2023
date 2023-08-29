#include <stdio.h>
#include <string.h>

void stampa_cornicetta(const char* s) {
    int length = strlen(s) + 4; // Calcola la lunghezza totale della cornicetta
    int i;

    // Stampa l'angolo superiore sinistro della cornicetta
    printf("/");

    // Stampa la riga superiore della cornicetta
    for (i = 0; i < length; i++) {
        printf("-");
    }

    // Stampa l'angolo superiore destro della cornicetta
    printf("\\\n");

    // Stampa la riga centrale della cornicetta con la stringa
    printf("| %s |\n", s);

    // Stampa l'angolo inferiore sinistro della cornicetta
    printf("\\");

    // Stampa la riga inferiore della cornicetta
    for (i = 0; i < length; i++) {
        printf("-");
    }

    // Stampa l'angolo inferiore destro della cornicetta
    printf("/\n");
}
