#include "matrici.h"

double det3x3(double* matr) {
	double a = matr[0];
	double b = matr[1];
	double c = matr[2];
	double d = matr[3];
	double e = matr[4];
	double f = matr[5];
	double g = matr[6];
	double h = matr[7];
	double i = matr[8];

	return a * e * i + b * f * g + c * d * h - g * e * c - h * f * a - i * d * b;
}