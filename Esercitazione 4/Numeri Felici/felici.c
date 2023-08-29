
int felice(unsigned int num) {
	if (num == 0) {
		return 0;
	}

	unsigned int sum = 0;
	while (num != 1 && num != 4) {
		sum = 0;
		while (num > 0) {
			unsigned int digit = num % 10;
			sum += digit * digit;
			num /= 10;
		}
		num = sum;
	}
	if (num == 1) {
		return 1;
	}
	else {
		return 0;
	}

}