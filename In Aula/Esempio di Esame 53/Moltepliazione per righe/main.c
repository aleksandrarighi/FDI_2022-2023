#include "matrix.h"

int main(void) {
	double Adata[] = { 1, 2, 3, 4, 5, 6 };
	struct matrix A = { 2, 3, Adata };

	double Bdata[] = { 7, 8 };
	struct matrix B = { 2, 1, Bdata };

	struct matrix* x = mat_rowmul(&A, &B);

	if (x != NULL) {
		free(x->data);
		free(x);
	}

	return 0;
}