#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>

struct matrix {
    size_t N, M;
    double* data;
};

extern struct matrix* mat_transpose(const struct matrix* mat);

#endif
