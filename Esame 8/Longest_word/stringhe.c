#include <stdlib.h>
#include <string.h>

char* parola_piu_lunga(const char* sz) {
	if (sz == NULL || *sz == '\0') {
		return NULL;
	}
	
	//puntatore all'inizio della parola più lunga
	const char* start = 0; 
	//lunghezza della parola più lunga
	size_t max_len = 0;

	while (*sz != '\0') {
		while (*sz != ' ') {
			sz++; //ignoriamo gli spazi
		}

		//inizo di una nuova parola
		const char* word_start = sz;
		//lunghezza della parola corrente
		size_t word_len = 0; 

		while (*sz != ' ' && *sz != '\0') {
			sz++;
			word_len++;
		}

		if (word_len > max_len) {
			start = word_start;
			max_len = word_len;
		}
	}

	if (max_len == 0) {
		return NULL;
	}

	char* longest_word = malloc(max_len + 1);
	if (longest_word == NULL) {
		return NULL;
	}

	strncpy(longest_word, start, max_len);
	longest_word[max_len] = '\0';

	return longest_word;
}