#include <stdlib.h>
#include <stdint.h>

char* trim(const char* s)
{
	if (s == NULL) {
		return NULL;
	}
	size_t start = SIZE_MAX, stop = SIZE_MAX;
	for (size_t i = 0; s[i] != 0; ++i) {
		if (start == SIZE_MAX && s[i] != ' ') {
			start = i;
		}
		if (s[i] != ' ') {
			stop = i;
		}

	}
	if (start == stop) {
		return calloc(1, 1);
	}
	char* out = malloc(stop - start + 2);
	out[stop - start + 1] = 0;
	for (size_t i = start; i <= stop; ++i) {
		out[i - start] = s[i];
	}
	return out;
}