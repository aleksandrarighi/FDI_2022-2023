#include "matrix.h"
#include <stdlib.h>

struct matrix* matrix_quadruplica(const struct matrix* m) {
	if (m == NULL) {
		return NULL;
	}

	struct matrix* quadruplica = malloc(sizeof(struct matrix));
	quadruplica->rows = 4 * (m->rows);
	quadruplica->cols = 4 * (m->cols);
	quadruplica->data = malloc(quadruplica->rows * quadruplica->cols * sizeof(double));

	for (size_t i = 0; i < m->rows; i++) {
		for (size_t j = 0; j < m->cols; j++) {
			quadruplica->data[i * quadruplica->cols + j] = m->data[i * m->cols + j]; //Questa assegnazione copia il valore corrispondente dalla matrice originale m nella posizione corrispondente della matrice quadruplicata quadruplica nel primo angolo.
			quadruplica->data[i * quadruplica->cols + (j + m->cols)] = m->data[i * m->cols + j]; //Questa assegnazione copia lo stesso valore nella posizione corrispondente della matrice quadruplicata quadruplica nel secondo angolo. L'indice j + m->cols viene utilizzato per spostarsi di una colonna a destra nella matrice quadruplicata.
			quadruplica->data[(i + m->rows) * quadruplica->cols + j] = m->data[i * m->cols + j]; //Questa assegnazione copia ancora una volta lo stesso valore nella posizione corrispondente della matrice quadruplicata quadruplica nel terzo angolo. L'indice (i + m->rows) viene utilizzato per spostarsi di una riga in basso nella matrice quadruplicata.
			quadruplica->data[(i * m->rows) * quadruplica->cols + (j + m->cols)] = m->data[i * m->cols + j]; //Questa assegnazione copia ancora una volta lo stesso valore nella posizione corrispondente della matrice quadruplicata quadruplica nel quarto angolo. L'indice (i + m->rows) viene utilizzato per spostarsi di una riga in basso, e l'indice (j + m->cols) viene utilizzato per spostarsi di una colonna a destra nella matrice quadruplicata.
		}
	}
	return quadruplica;
}