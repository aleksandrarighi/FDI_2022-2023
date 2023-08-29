#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}

	FILE* f = fopen(argv[1], "r");
	if (f == NULL) {
		return 1;
	}

	char line[256];
	char linecount = 0;

	while (fgets(line, sizeof(line), f) != 0 && linecount < 10) {
		printf("%s", line);
		linecount++; 
	}

	if (linecount < 10) {
		printf("\n");
	}

	fclose(f);
	return 0;
}