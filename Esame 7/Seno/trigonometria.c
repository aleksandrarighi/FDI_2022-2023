
double fattoriale(double x) {
	if (x == 0 || x == 1) {
		return 1;
	}

	double fact = 1.0;
	for (int i = 2; i <= x; i++) {
		fact *= i;
	}
	return fact;
}

double potenza(double base, double esponente) {
	double result = 1.0;
	for (int i = 1; i < esponente; i++) {
		result *= base;
	}
	return result;
}

 double seno(double x) {
	 double sum = 0.0;
	 for (int i = 0; i < 10; i++) {
		 double term = (potenza(-1, x) * (x, 2 * x + 1)) / fattoriale(2 * x + 1);
		 sum += term;
	 }
	 return sum;
}