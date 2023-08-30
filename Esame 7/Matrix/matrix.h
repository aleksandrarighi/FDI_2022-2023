#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
struct matrix {
    size_t N, M;
    double* data;
};

extern int matrix_read(struct matrix* matr, FILE* f);

#endif
