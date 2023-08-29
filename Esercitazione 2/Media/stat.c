#include "stat.h"
#include <stdlib.h>

double media(double* x, unsigned int n) {
	if (n == 0) {
		return 0;
	}

	if (x == NULL) {
		return;
	}

	double average = 0;
	for (unsigned int i = 0; i < n; i++) {
		average = (average + x[i])/n;
	}
	return average;
}

int main(void) {

	unsigned int n = 5;
	double* v = malloc(n * sizeof(double));
	if (v == NULL)
		return 0;
	v[0] = 4;
	v[1] = 6;
	v[2] = 5;
	v[3] = 2;
	v[4] = 3;
	double average = media(v, n);
	free(v);
	return 0;