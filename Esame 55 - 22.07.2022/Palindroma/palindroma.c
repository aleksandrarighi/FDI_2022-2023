#include "palindroma.h"
#include <stdlib.h>
#include <string.h>

bool palindroma(const char* str) {
	if (str == NULL || *str == '\0') {
		return false;
	}
	size_t len = strlen(str);
	if (len == 1) {
		return true;
	}

	for (size_t i = 0; i < len; i++) {
		if (str[i] != (str[len -1-i])) {
			return false;
		}
	}
	return true;
}