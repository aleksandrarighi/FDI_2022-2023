#include <stdlib.h>

int MCD(int a, int b) {
	a = abs(a);
	b = abs(b);

	if (b > a) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	while (b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}


int ammette_soluzioni(int a, int b, int c) {
	if (a == 0 && b == 0) {
		if (c == 0) {
			return 1;
		}
		else return 0;
	}
	else {
		int MCD_ab = MCD(a, b);
		if (c % MCD_ab == 0) {
			return 1;
		}
		else return 0;
	}
}
