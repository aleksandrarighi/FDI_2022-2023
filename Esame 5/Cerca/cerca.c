#include <string.h>

char* cerca_primo(char* s, const char* list) {
	int s_len = strlen(s);
	int list_len = strlen(list);

	for (int i = 0; i < s_len; i++) {
		for (int j = 0; i < list_len; j++) {
			if (list[j] == s[i]) {
				return &s[i];
			}
		}
	}
	return NULL;
}