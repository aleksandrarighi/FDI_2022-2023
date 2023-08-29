#include "lettura.h"

int* leggiinteri2(const char* filename, size_t* size) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        return NULL;  // Fallita l'apertura del file
    }

    // Determina la dimensione del file
    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    rewind(f);

    // Controlla se il file ha una dimensione valida per contenere almeno un intero
    if (file_size < sizeof(int)) {
        fclose(f);
        return NULL;  // File troppo piccolo
    }

    // Calcola il numero di interi nel file
    *size = file_size / sizeof(int);

    // Alloca la memoria per gli interi
    int* numeri = malloc(file_size * sizeof(int));
    if (numeri == NULL) {
        fclose(f);
        return NULL;  // Errore nell'allocazione di memoria
    }

    // Legge gli interi dal file
    size_t num_read = fread(numeri, sizeof(int), *size, f);
    fclose(f);

    if (num_read != *size) {
        free(numeri);
        return NULL;  // Errore nella lettura degli interi
    }

    return numeri;
}


