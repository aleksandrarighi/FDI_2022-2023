#include <string.h>

extern char* codifica_morse(const char* testo);

int main(void) {
	char * ris= codifica_morse("CIAO MAMMA");
	if (strcmp(ris, "_._. .. ._ ___ / __ ._ __ __ ._") == 0) {
		printf("OK/n");
	}
	else {
		printf("Fail/n");
	}
	free(ris);
	return 0;
}