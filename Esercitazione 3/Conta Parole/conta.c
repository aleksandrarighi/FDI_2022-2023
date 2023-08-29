#include <stdlib.h>

size_t conta_parole(const char* s) {
    size_t count = 0;
    int stato = 0; // 0 = all'esterno di una parola, 1 = all'interno di una parola

    // Scorri la stringa carattere per carattere utilizzando un ciclo for
    for (size_t i = 0; s[i] != '\0'; i++) {
        // Controlla se il carattere corrente è uno spazio
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r') {
            stato = 0; // Se il carattere è uno spazio, siamo all'esterno di una parola
        }
        else if (stato == 0) {
            stato = 1; // Se il carattere non è uno spazio e eravamo all'esterno di una parola, incrementa il conteggio
            count++;
        }
    }

    return count;
}
