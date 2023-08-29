#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}

	size_t len = strlen(argv[1]);
	for (size_t i = 0; i < len; i++) {
		if (argv[1][i] != '-' && argv[1][i] != '0' && argv[1][i] != '+') {
			return 1;
		}
	}

	int decimal = 0;
	for (size_t i = 0; i < len; i++) {
		if (argv[1][i] == '-') {
			decimal = decimal * 3 - 1; 
		}
		else if (argv[1][i] == '0') {
			decimal *= 3;
		}
		else if (argv[1][i] == '+') {
			decimal = decimal * 3 + 1;
		}
	}
	printf("%i\n", decimal);
	return 0;
}