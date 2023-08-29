#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}

	FILE* f = fopen(argv[1], "r");
	if (f == NULL) {
		return 1;
	}

	int c;
	while ((c = fgetc(f)) != 0) {
		if (isupper(c)) {
			c = tolower(c);
		}
		fputc(c, f);
	}
	fclose(f);
	return 0;
}