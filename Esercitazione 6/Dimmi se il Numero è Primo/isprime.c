#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}

	int n = atoi(argv[1]);

	if (n < 0) {
		return 1;
	}

	bool isprime = true;

	if (n <= 1) {
		isprime = false;
	}
	else {
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				isprime = false;
				break;
			}
		}
	}

	if (isprime) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}

	return 0;
}
