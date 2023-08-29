#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h> // Per avere uint8_t
struct image {
    size_t rows, cols;
    uint8_t* data;
};

extern struct image* aggiungi_cornice(const struct image* img);

#endif
