#ifndef MATRIX_H
#define MATRIX_H

struct matrix {
    size_t rows, cols;
    double* data;
};

extern struct matrix* matrix_quadruplica(const struct matrix* m);

#endif