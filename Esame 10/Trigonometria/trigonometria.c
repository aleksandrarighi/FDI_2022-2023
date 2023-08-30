double fattoriale(double n) {
	if (n == 0 || n == 1) {
		return 1.0;
	}

	double fact = 1.0;
	for (int i = 2; i <= n; i++) {
		fact *= i;
	}
	return fact;
}

double potenza(double base, double esponente) {
	if (esponente == 0) {
		return 1.0;
	}
	if (esponente == 1) {
		return base;
	}

	double pot = 1.0;
	for (int i = 1; i < esponente; i++) {
		pot *= base; 
	}
	return pot;
}

double seno_iperbolico(double x) {
	double sinh = 0.0;
	double term;
	for (int i = 0; i < 20; i++) {
		term = potenza(x, 2 * i + 1) / fattoriale(2 * i + 1);
		sinh += term;
	}
	return sinh;
}