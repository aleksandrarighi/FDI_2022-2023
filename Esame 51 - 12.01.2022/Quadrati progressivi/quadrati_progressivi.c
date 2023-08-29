#include <stdio.h>

void quadrati_progressivi(FILE* f, int n) {
	if (n <= 0) {
		return;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			int value; 
			if (i < j) {
				value = j;
			}
			else {
				value = i;
			}
			fprintf(f, "%d", value % 10);
		}
		fprintf(f, "\n");
	}
}