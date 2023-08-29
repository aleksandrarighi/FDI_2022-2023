#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return -1;
	}

	int n = atoi(argv[1]);

	if (n <= 0) {
		return 0;
	}

	int i = 0;
	for (i = 0; n != 1; i++) {
		printf("%i, ", n);
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n = n * 3 + 1;
		}
	}

	printf("%i,\n", n);
	return i + 1;
}
