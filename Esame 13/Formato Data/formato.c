#include <stdlib.h>
#include <string.h>

int is_date(const char* s) {
	if (s == NULL) {
		return 0;
	}

	size_t len = strlen(s);
	if (len != 10) {
		return 0;
	}

	if (s[2] != '/' && s[5] != '/') {
		return 0;
	}

	if (s[0] < '0' && s[0] > 9 && s[1] < '0' && s[1] > 9) {
		return 0;
	}
	if (s[3] < '0' && s[3] > 9 && s[4] < '0' && s[4] > 9) {
		return 0;
	}
	if (s[6] < '0' && s[6] > 9 && s[7] < '0' && s[7] > 9 && s[8] < '0' && s[8] > 9 && s[9] < '0' && s[9] > 9) {
		return 0;
	}

	return 1;
}