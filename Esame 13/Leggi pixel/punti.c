#include "punti.h"
#include <stdlib.h>

struct pixel* read_pixels(FILE* f, size_t* n) {
    if (f == NULL || n == NULL) {
        return NULL;
    }

    *n = 0;
    size_t capacity = 1;
    struct pixel* pixels = malloc(capacity * sizeof(struct pixel));
    if (pixels == NULL) {
        return NULL; 
    }

    while (1) {
        if (*n >= capacity) {
            capacity *= 2;
            struct pixel* temp = realloc(pixels, capacity * sizeof(struct pixel));
            if (temp == NULL) {
                free(pixels);
                return NULL; 
            }
            pixels = temp;
        }

        if (fread(&(pixels[*n].x), sizeof(short), 1, f) != 1) {
            break; 
        }

        fread(&(pixels[*n].y), sizeof(short), 1, f);
        fread(pixels[*n].rgb, sizeof(unsigned char), 3, f);
        (*n)++;
    }

    return pixels;
}