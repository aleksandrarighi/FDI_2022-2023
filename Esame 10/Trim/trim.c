#include <stdlib.h>
#include <string.h>

char* trim(const char* s) {
	if (s == NULL) {
		return NULL;
	}

	int len = strlen(s);
	int start = 0; 
	int end = len - 1;

	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n') {
		start++;
	}

	while (end > start && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')) {
		end--;
	}

	int len_trim = end - start + 1;


	char* new_str = malloc((len_trim + 1) * sizeof(char));
	if (new_str == NULL) {
		free(new_str);
		return NULL;
	}

	for (int i = 0; i < len_trim; i++) {
		new_str[i] = s[start + i];
	}
	new_str[len_trim] = '\0';

	return new_str;
}