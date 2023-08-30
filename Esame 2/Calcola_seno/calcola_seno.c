#include <math.h>

unsigned int fattoriale(unsigned int n) {
	if (n == 0 || n == 1) {
		return 1;
	}

	unsigned int mul = 1;
	for (unsigned int i = 2; i < n; i++) {
		mul *= i;
	}
	return mul;
}

double calcola_seno(double x) {
	double res = 0.0;
	double term = x;

	for (int n = 1; n <= 20; n++) {
		term = (pow(-1, n) * pow(x, (2 * n) + 1)) / fattoriale((2 * n) + 1);
		res = res + term;
	}
	return res;
}