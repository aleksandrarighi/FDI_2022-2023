#include <stdbool.h>
#include <stdint.h>

bool primo(uint32_t x) {
	if (x < 2) {
		return false;
	}

	for (uint32_t i = 2; i < x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

bool primigemelli(uint32_t start, uint32_t* x, uint32_t* y) {
	if (start > UINT32_MAX - 1) {
		return false;
	}

	uint32_t current = start;
	while (true) {
		if (primo(current) && primo(current + 2)) {
			*x = current;
			*y = current + 2;
			return true;
		}
		current++;
	}
}