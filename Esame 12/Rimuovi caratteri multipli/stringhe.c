#include <stdlib.h>
#include <string.h>

char* rimuovimultipli(const char* str) {
	if (str == NULL) {
		return NULL;
	}

	size_t len = strlen(str);
	if (len == 0) {
		char* new_str = malloc(1);
		if (new_str != NULL) {
			*new_str = '\0';
		}
		return new_str;
	}

	char* new_str = malloc(len + 1);
	if (new_str == NULL) {
		return NULL;
	}

	size_t new_len = 1;
	new_str[0] = str[0];

	for (size_t i = 1; i < len; i++) {
		if (str[i] != str[i - 1]) {
			new_str[new_len++] = str[i];
		}
	}

	new_str[new_len] = '\0';

	return new_str;
}