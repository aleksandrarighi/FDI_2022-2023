#include <stdio.h>
#include <limits.h>

int cercaMassimo(const char* filename) {
	FILE* f = fopen(filename, "r");

	int max = INT_MIN;
	int num;

	while (fscanf(f, "%d", &num) != EOF) {
		if (num > max) {
			max = num;;
		}
	}

	fclose(f);
	return max;
}