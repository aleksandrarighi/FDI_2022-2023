#include <stdlib.h>
#include <string.h>

char* sostituisci(const char* str, const char* vecchia, const char* nuova) {
	if (str == NULL || vecchia == NULL || nuova == NULL) {
		return NULL;
	}

	size_t str_len = strlen(str);
	size_t vecchia_len = strlen(vecchia);
	size_t nuova_len = strlen(nuova);

	if (str_len == 0 || vecchia_len == 0) {
		char* copia = malloc(str_len * sizeof(char));
		if (copia == NULL) {
			return NULL;
		}
		strcpy(copia, str);
		return copia;
	}

	size_t count = 0;
	const char* temp = str;

	//conto quante occorrenze di vecchia ci sono in str
	while ((temp = strstr(temp, vecchia)) != NULL) {
		count++;
		temp += vecchia_len;
	}

	//lunghezza della nuova stringa
	size_t new_len = str_len + count * (vecchia_len - nuova_len) + 1;

	char* new_str = malloc(new_len);
	if (new_str == NULL) {
		return NULL;
	}

	char* new_temp = new_str;
	temp = str;

	//copio str in new_str e sostituisco vecchia con nuova
	while (*temp != 0) {
		if (strncmp(temp, vecchia, vecchia_len) == 0) {
			strcpy(temp, nuova);
			new_temp += nuova_len;
			temp += vecchia_len;
		}
		else {
			*new_temp = *temp;
			new_temp++;
			temp++;
		}
	}
	*new_temp = '\0';

	return new_str;
}