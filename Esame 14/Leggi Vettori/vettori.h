#ifndef VETTORI_H
#define VETTORI_H
#include <stdio.h>

struct vettore {
    size_t len;
    int* data;
};

extern struct vettore* vettori_leggi(FILE* f, size_t* n);

#endif
