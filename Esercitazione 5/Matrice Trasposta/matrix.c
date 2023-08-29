#include "matrix.h"

struct matrix* mat_transpose(const struct matrix* mat) {
	if (mat == NULL) {
		return NULL;
	}
    // Alloca memoria per la matrice trasposta
    struct matrix* transpose = malloc(sizeof(struct matrix));
    transpose->rows = mat->cols; // Numero di righe della matrice trasposta
    transpose->cols = mat->rows; // Numero di colonne della matrice trasposta
    transpose->data = malloc(transpose->rows * transpose->cols * sizeof(double));

    // Copia i valori dalla matrice originale alla matrice trasposta
    for (size_t i = 0; i < mat->rows; i++) {
        for (size_t j = 0; j < mat->cols; j++) {
            // Copia l'elemento dalla posizione (i, j) nella matrice originale
            // nella posizione (j, i) nella matrice trasposta
            transpose->data[j * transpose->cols + i] = mat->data[i * mat->cols + j];
        }
    }

}