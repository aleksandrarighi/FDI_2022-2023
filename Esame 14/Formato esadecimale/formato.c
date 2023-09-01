#include <stdlib.h>
#include <string.h>

int is_hex(const char* s) {
	if (s == NULL) {
		return 0;
	}

	size_t len = strlen(s);

	if (len < 3 || len > 10 || (s[0] != '0' && (s[1] != 'x' && s[1] != 'X'))) {
		return 0;
	}

	for (size_t i = 2; i < len; i++) {
		if ((s[i] < '0' || (s[i] > '9' && s[i] < 'A') || (s[i] > 'F' && s[i] < 'a') || s[i] > 'f')) {
			return 0;
		}
	}

	return 1;
}