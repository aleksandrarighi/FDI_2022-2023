

double semifattoriale(char n) {
	if (n == 0 || n == 1) {
		return 1;
	}

	if (n < 0) {
		return -1;
	}

	double semi_fact = n;
	for (int i = n - 2; i > 0; i -= 2) {
			semi_fact *= (i);
	}
	return semi_fact;
}