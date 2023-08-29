#include <stdbool.h>

bool is_terna_pitagorica(unsigned int a, unsigned int b, unsigned int c) {
	if ((a * a) + (b * b) == (c * c) || (a * a) + (c * c) == (b * b) || (b * b) + (c * c) == (a * a)) {
		return true;
	}
	else return false;
}

/*int main(void) {

	unsigned int a = 3;
	unsigned int b = 4;
	unsigned int c = 5;

	bool x = is_terna_pitagorica(a, b, c);
	return 0;
}*/