double fattoriale(double n) {
	if (n == 0 || n == 1) {
		return 1;
	}

	double fact = 1;
	for (int i = 2; i <= n; i++) {
		fact *= i;
	}
	return fact;
}

double binomialesimmetrico(unsigned int n, unsigned int h, unsigned int k) {
	return fattoriale(n) / (fattoriale(h) * fattoriale(k));
}