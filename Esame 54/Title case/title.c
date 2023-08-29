#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
	if (argc < 3) {
		printf("\n");
		return 0;
	}

	for (int i = 1; i < argc; i++) {
		size_t len = strlen(argv[i]);
		if (len > 0) {
			char ultimocarattere = argv[i][len - 1];
			char ultimocaratteremaiuscolo = toupper(ultimocarattere);
			argv[i][len - 1] = ultimocaratteremaiuscolo;
		}
		printf("%s ", argv[i]);
	}
	printf("\n");
	return 0;
}