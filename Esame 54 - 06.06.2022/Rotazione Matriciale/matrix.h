#ifndef MATRIX_H
#define MATRIX_H

struct matrix {
    size_t rows, cols;
    double* data;
};

extern struct matrix* mat_rotate180(const struct matrix* m);

#endif
