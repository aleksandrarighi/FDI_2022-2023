#ifndef MATRIX_H
#define MATRIX_H

struct matrix {
    size_t rows, cols;
    double* data;
};

extern struct matrix* mat_rowmul(const struct matrix* m1, const struct matrix* m2);

#endif