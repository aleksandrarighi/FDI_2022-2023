#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
struct matrix {
    size_t N, M;
    double* data;
};

extern int mat_isupper(const struct matrix* matr);

#endif
