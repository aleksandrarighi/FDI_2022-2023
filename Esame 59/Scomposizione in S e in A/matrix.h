#ifndef MATRIX_H
#define MATRIX_H

struct matrix {
    size_t rows, cols;
    double* data;
};

extern void mat_symdecomp(const struct matrix* m, struct matrix* S, struct matrix* A);

#endif
