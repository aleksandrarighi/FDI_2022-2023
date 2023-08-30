#include <stdio.h>

struct person {
    char name[256];
    unsigned int age;
};

unsigned int count_teenagers(FILE* f) {
    unsigned int numero_teenagers = 0; 
    unsigned int numero_persone;

    if (fscanf(f, "%u", &numero_persone) != 1) {
        fprintf(stderr, "Errore nella lettura del numero di persone.\n");
        return 0;
    }

    for (unsigned int i = 0; i < numero_persone; i++) {
        struct person p;
        if (fscanf(f, "%255s %u", p.name, &p.age) != 2) {
            fprintf(stderr, "Errore nella lettura dei dati di una persona.\n");
            return 0;
        }
        if (p.age >= 13 && p.age <= 19) {
            numero_teenagers++;
        }
    }
    return numero_teenagers;
}