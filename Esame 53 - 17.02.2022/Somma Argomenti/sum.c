#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int sum = 0;
	for (int i = 1; i < argc; i++) {
		int value = atoi(argv[i]);
		for (int j = 0; argv[i][j] != '\0'; j++) {
			if (isdigit(argv[i][j])) {
				sum += value;
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}