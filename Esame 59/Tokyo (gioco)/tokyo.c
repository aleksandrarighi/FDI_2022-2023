#include <stdlib.h>

int tokyo_confronta(char a[2], char b[2]) {
	if (a == NULL || b == NULL || a[0] < 1 || b[0] < 1 || a[0] > 6 || b[0] > 6 || a[1] < 1 || b[1] < 1 || a[1] > 6 || b[1] > 6) {
		return 0;
	}

	char a_value;
	char b_value;

	if (a[0] < a[1]) {
		a[1] *= 10;
		a_value = a[0] + a[1];
	}
	else if (a[0] > a[1]) {
		a[0] *= 10;
		a_value = a[0] + a[1];
	}

	if (b[0] < b[1]) {
		b[1] *= 10;
		b_value = b[0] + b[1];
	}
	else if (b[0] > b[1]) {
		b[0] *= 10;
		b_value = b[0] + b[1];
	}

	if (a_value > b_value) {
		return 1;
	}
	else if (a_value == b_value) {
		return 0;
	}
	else if (a_value < b_value) {
		return -1;
	}
}