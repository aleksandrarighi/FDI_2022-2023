#include <stdbool.h>

bool crescente(unsigned int x) {
    unsigned int precedente = x % 10;
    x /= 10;

    while (x != 0) {
        unsigned int cifra = x % 10;
        x /= 10;
        if (cifra >= precedente) {
            return false;
        }
        precedente = cifra; //per mantenere correttamente il valore della cifra precedente per il confronto nella prossima iterazione del ciclo
    }

    return true;
}

/*#include <stdbool.h>

bool crescente(unsigned int x) {

    while (x > 10) {
        unsigned int next = x % 10;
        x /= 10;
        if (x % 10 + 1 != next) {
            return false;
        }
    }
    return true;
}*/
