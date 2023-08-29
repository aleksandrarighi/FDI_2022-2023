#define _CRT_SECURE_NO_WARNINGS_
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* codifica_morse(const char* testo) {
	if (testo == NULL) {
		return NULL;
	}
	char* ris = calloc(strlen(testo) * 5 + 1, 1); //i cartteri possibili sono 4 + spazio, con calloc c'è sempre uno zero in fondo
	char* str[] = {
		"•—",	"—•••", "—•—•", "—••", "•" "••—•", "——•", "••••", "••", "•———", "—•—", "•—••", "——",
		"—•", "———", "•——•", "——•—", "•—•", "•••", "—", "••—","•••—", "•——", "—••—", "—•——", "——••"
	};
	for (size_t i = 0; testo[i] != 0; ++i) {
		if (testo[i] == ' ') {
			strcat(ris, "/");
		}
		else {
			strcat(ris, str[testo[i] - 'A']);
		}
		
	}
	if (strlen(ris) > 0) {
		ris[strlen(ris) - 1] = 0;
	}
	return NULL;
 }