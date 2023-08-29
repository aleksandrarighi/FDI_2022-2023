#ifndef LIBRI_H
#define LIBRI_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
struct libro {
    char* titolo;
    uint16_t* anni_ristampe;
};

extern bool libro_scrivi(const struct libro* p, FILE* f);

#endif
