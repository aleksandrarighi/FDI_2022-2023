#include <stdlib.h>
#include "image.h"

struct image* aggiungi_cornice(const struct image* img) {
    if (img == NULL) {
        return NULL;
    }

    struct image* immagine = malloc(sizeof(struct image));
    immagine->rows = img->rows + 2;
    immagine->cols = img->cols + 2;
    immagine->data = malloc(immagine->rows * immagine->cols * sizeof(uint8_t));

    for (size_t i = 0; i < immagine->rows * immagine->cols; i++) {
        immagine->data[i] = 0;
    }

    for (size_t i = 0; i < img->rows; i++) {
        for (size_t j = 0; j < img->cols; j++) {
            immagine->data[(i + 1) * immagine->cols + (j + 1)] = img->data[i * img->cols + j];
        }
    }

    return immagine;
}