#include <string.h>
#include <stdlib.h>

char* concatena(const char* s1, const char* s2) {
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);
	size_t tot_len = len1 + len2 + 1; //terminatore null

	char* new_str = malloc(tot_len * sizeof(char));
	if (new_str == NULL) {
		return NULL;
	}

	for (size_t i = 0; i < len1; i++) {
		new_str[i] = s1[i];
	}
	for (size_t i = 0; i < len2; i++) {
		new_str[len1 + i] = s2[i];
	}

	new_str[tot_len - 1] = '\0';
	return new_str;
}