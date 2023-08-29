#include <stdlib.h>
#include <string.h>

void translate(char* str, const char* from, const char* to) {
	if (str == NULL) {
		return;
	}
	if (from == NULL) {
		return;
	}
	if (to == NULL) {
		return;
	}

	size_t lenfrom = strlen(from);
	size_t lento = strlen(to);
	if (lenfrom != lento) {
		return;
	}

	for (int i = 0; str[i]!='\0'; i++) {
		char* pos = (strchr(from, str[i]));
		if (pos != NULL) {
			size_t index = pos - from;
			str[i] = to[index];
		}
	}
}