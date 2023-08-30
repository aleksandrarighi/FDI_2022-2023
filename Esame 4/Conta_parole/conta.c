#include <stdlib.h>

size_t conta_parole(const char* s) {
	if (s[0] == 0) {
		return 0;
	}

	size_t count = 0;

	if (s[0] == ' ') {
		count = 0;
	}
	else {
		count = 1;
	}

	for (size_t i = 0; s[i + 1] != 0; i++) {
		if (s[i] == ' ' && s[i + 1] != ' ') {
			count++;
		}
	}
	
	return count;
}