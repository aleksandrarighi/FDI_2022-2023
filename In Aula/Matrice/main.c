#define _CRT_SECURE_NO_WARNINGS_
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct mat {
	size_t rows, cols;
	double* data;
};

struct mat* mat_create(struct mat* A, size_t rows, size_t cols) {
	A->rows = rows;
	A->cols = cols;
	A->data = malloc(rows * cols * sizeof(double));
}

void mat_destroy(struct mat* A) {
		free(A->data);
}

void mat_print(struct mat* A)
{
	for (size_t r = 0; r < A->rows; ++r) {			/*stampa matrice*/
		for (size_t c = 0; A->cols; ++c) {
			printf("%f ", A->data[r * A->cols + c]);
		}
		printf("\n");
	}
}

#define E(M, r, c) (M)->data[(r)*((M)->cols) + c]

bool mat_add(struct mat* A, const struct mat* B) {
	if (A->cols != B->cols || A->rows != B->rows) {
		return false;
	}
	size_t rows = A->rows;
	size_t cols = A->cols;
	for (size_t r = 0; r < rows; ++r) {
		for (size_t c = 0; c < cols; ++c) {
			E(A, r, c) += E(B, r, c);
		}
	}
	return true;
}


int main(void) {

	struct mat* A = mat_create(&A, 3, 2);

	/*struct mat* A= malloc(sizeof(struct mat)); //A è un puntatore a una matrice
											   //ho allocato per rows e cols ma non per matrice
	A->rows = 3;
	A->cols = 2;
	A->data = malloc(A->rows * A->cols * sizeof(double)); //rows * cols: (A->rows * A->cols...)*/

	A->data[0 * A->cols + 0] = 1;
	A->data[0 * A->cols + 1] = 2;
	A->data[1 * A->cols + 0] = 3;
	A->data[1 * A->cols + 1] = 4;
	A->data[2 * A->cols + 0] = 5;
	A->data[2 * A->cols + 1] = 6;

	mat_print(&A, stdout);

	mat_destroy(&A);
	return 0;
}