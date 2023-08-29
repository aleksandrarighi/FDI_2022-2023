#include "lettura.h"

int* leggiinteri(const char* filename, size_t* size) {
    FILE* f = fopen(filename, "rb");

    if (f == NULL) {
        return NULL;
    }

    int n;
    if (fread(&n, sizeof(int), 1, f) != 1) {
        fclose(f);
        return NULL;
    }

    int* numeri = malloc(n * sizeof(int));
    if (numeri == NULL) {
        fclose(f);
        return NULL;
    }

    if (fread(numeri, sizeof(int), n, f) != n) {
        free(numeri);
        fclose(f);
        return NULL;
    }

    fclose(f);

    *size = (size_t)n;
    return numeri;
}
