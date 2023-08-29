#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		return 1;
	}

	int max = atoi(argv[1]);
	
	for (int i = 2; i < argc; i++) {
		int n = atoi(argv[i]);
		if (n == 0 && argv[i] != '0') {
			return 1;
		}
		if (n > max) {
			n = max;
		}
	}
	printf("%d\n", max);
	return 0;
}