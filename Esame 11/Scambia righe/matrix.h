#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>

struct matrix {
    size_t N, M;
    double* data;
};

extern void mat_swaprows(struct matrix* mat, size_t r1, size_t r2);

#endif 
