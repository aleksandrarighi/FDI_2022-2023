#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	int somma = 0;
	for (int i = 1; i < argc; ++i) {
		char* endptr;
		int val = strtol(argv[1], &endptr, 10);
		if (*endptr == 0) {
			somma += val;
		}
	}
	printf("%d/n", somma);
	return 0;
}