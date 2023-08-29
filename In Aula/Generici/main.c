#include <stdlib.h>

void swap(void* x, void* y, size_t n) {
	char* xc = x, * yc = y; //char ci permette di accedere byte per byte
	for (size_t i = 0; i < n; ++i) {
		char tmp = xc[i]; //scambio byte per byte il loro contenuto
		xc[i] = yc[i];
		yc[i] = tmp;
	}
}

int main(void) {
	int a = 5, b = -7;
	swap(&a, &b, sizeof(int));
	return 0;
}