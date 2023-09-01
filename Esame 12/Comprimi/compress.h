#ifndef COMPRESS_H
#define COMPRESS_H
#include <stdio.h>

struct dati {
    size_t len;
    int* vals;
};

extern int dati_read(const char* filename, struct dati* d);

#endif
