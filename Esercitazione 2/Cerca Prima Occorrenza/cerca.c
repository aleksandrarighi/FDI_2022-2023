#include "cerca.h"

int cerca_primo(const char* s, char c) {
	for (int i = 0; s[i] != 0; i++) {
		if (s[i] == c) {
			return i;
		}
	}
	return -1;
}