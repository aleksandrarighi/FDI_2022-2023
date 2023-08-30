
double fattoriale(int x) {
	if (x == 0 || x == 1) {
		return 1;
	}

	double fact = 1.0;
	for (int i = 2; i < x; i++) {
		fact *= i;
	}
	return fact;
}

double potenza(int base, int esponente) {
	if (esponente == 0) {
		return 1.0;
	}
	if (esponente == 1) {
		return base;
	}

	double pot = 1.0;
	for (int i = 0; i < esponente; i++) {
		pot *= base;
	}
	return pot;
}

double coseno(double x) {
	double cos = 0;
	for (int i = 0; i <= 1000; i++) {
		double term = (potenza(-1, x) * potenza(x, 2 * x)) / fattoriale(2 * x);
		cos += term;
	}
	return cos;
}