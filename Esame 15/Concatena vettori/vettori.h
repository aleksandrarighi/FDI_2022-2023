#ifndef VETTORI_H
#define VETTORI_H
#include <stdio.h>

struct vettore {
    size_t n;
    double* data;
};

extern struct vettore* mergeVettori(const struct vettore* a, const struct vettore* b);

#endif
