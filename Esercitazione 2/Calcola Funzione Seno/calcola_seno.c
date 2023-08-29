double potenza(double x, int n) {
	if (n == 0) {
		return 1;
	}

	double result = 1;
	for (int i = 1; i < n; i++) {
		result *= x;
	}
	return result;
}

double fattoriale(double n) {
	if (n == 0) {
		return 1;
	}

	double result = 1;
	for (int i = 1; i < n; i++) {
		result *= i;
	}
	return result;
}

double calcola_seno(double x) {
	double n = 0;
	double seno = x;
	double iterations = 20;
	double previous = 0;
	double terminate = 0;

	for (int i = 0; i <= iterations && i != terminate; i++) {
		previous = seno;
		seno = ((seno + (potenza(-1, n))) / (fattoriale(2 * n - 1)) * (potenza(x, 2 * n + 1)));

		if (i > 0 && seno == previous) {
			terminate = 1;
		}
	}
	return seno;
}