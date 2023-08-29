#include "lettura.h"

double* leggidouble(const char* filename, size_t* size) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        return NULL; 
    }

    double tmp;
    size_t count = 0;

    while (fscanf(f, "%lf", &tmp) == 1) {
        count++;
    }

    // Alloca la memoria per i double
    double* numeri = malloc(count * sizeof(double));
    if (numeri == NULL) {
        fclose(f);
        return NULL;  // Errore nell'allocazione di memoria
    }

    // Riapri il file per la lettura dei double
    rewind(f);

    // Legge i double dal file e li salva nell'array numeri
    for (size_t i = 0; i < count; i++) {
        if (fscanf(f, "%lf", &numeri[i]) != 1) {
            fclose(f);
            free(numeri);
            return NULL;  // Errore nella lettura dei double
        }
    }

    fclose(f);
    *size = count;
    return numeri;
}


/*
#define _CRT_SECURE_NO_WARNINGS_
#include "lettura.h"
#include <stdio.h>

double* leggidouble(const char* filename, size_t* size) {
    if (filename == NULL) {
        return NULL;
    }

    double* x = NULL;
    FILE* f = fopen(filename, "r");
    if (f != NULL) {
        size_t n = 0;
        while (1) {
            double d;
            int res = fscanf(f, "%lf", &d);
            if (res != 1) {
                break;
            }
            x = realloc(x, (n + 1) * sizeof(double));
            x[n] = d;
            ++n;
        }
        *size = n;
        fclose(f);
    }
    return x;
}*/