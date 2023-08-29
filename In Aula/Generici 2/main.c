#include <stdlib.h>

void swap(void* x, void* y, size_t n) {
	char* xc = x, * yc = y; //char ci permette di accedere byte per byte
	for (size_t i = 0; i < n; ++i) {
		char tmp = xc[i]; //scambio byte per byte il loro contenuto
		xc[i] = yc[i];
		yc[i] = tmp;
	}
}
struct persona {
	char nome[50], cognome[50];
	int eta;
};

int main(void) {
	struct persona uno = { "Costantino", "Grana", "46" };
	struct persona due = { "Aleksandra", "Righi", "20" };
	swap(&uno, &due, sizeof(struct persona));
	return 0;
}