#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <math.h>
struct matrix {
    size_t rows, cols;
    double* data;
};

extern void mat_normalize_rows(struct matrix* m);

#endif
