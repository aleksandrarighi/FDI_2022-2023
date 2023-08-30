

double fattoriale(unsigned int x) { 
	if (x == 0 || x == 1) {
		return 1;
	}

	double fact = 1;
	for (unsigned int i = 2; i < x; i++) {
		fact *= i;
	}
	 
	return fact;
}

double binomiale(unsigned int n, unsigned int k) {
	if (n == 0 || k > n) {
		return -1;
	}

	return fattoriale(n) / (fattoriale(k) * fattoriale(n - k));

}

