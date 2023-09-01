#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>

struct matrix {
    size_t N, M;
    double* data;
};

extern struct matrix* mat_copy(const struct matrix* mat);

#endif
