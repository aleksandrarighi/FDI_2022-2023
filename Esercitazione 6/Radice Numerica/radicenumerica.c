#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}

	int n = atoi(argv[1]);

	if (n < 0) {
		return 1;
	}

	int radicenumerica = 0;
	while (n / 10 != 0) {
		radicenumerica = 0;
		while (n != 0) {
			radicenumerica += n % 10;
			n /= 10;
		}
		n = radicenumerica;
	}
	printf("%i\n", radicenumerica);
	return 0; 
}