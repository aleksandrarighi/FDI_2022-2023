#include <stdlib.h>
#include <string.h>

void swap(void* x, void* y, size_t n) {
	char* xc = x, * yc = y; //char ci permette di accedere byte per byte
	for (size_t i = 0; i < n; ++i) {
		char tmp = xc[i]; //scambio byte per byte il loro contenuto
		xc[i] = yc[i];
		yc[i] = tmp;
	}
}

typedef int (*cmpfn) (void* va, void* vb); 

void sort(int* arr, size_t n, size_t size, int cmp (void *va, void*vb)) { 
	char* p = arr;
	for (size_t i = 0; i < n; ++i) {
		size_t posmin = i;
		for (size_t j = i + 1; j < n; ++j) {
			if (cmp(p + j * size, p + posmin * size) < 0) {
				posmin = j;
			}
		}
		if (posmin != i) {
			swap(p + i*size, p + posmin*size, size); //arr[i] = arr + i
		}
	}
}

int doublecmp(void * va, void* vb) {   //non è una funzione generica se chiede 2 int
	double* a = va, * b = vb;
	if (*a == *b) {
		return 0;
	}
	else if (*a < *b) {
		return -1;
	}
	else {
		return 1;
	}

	/*return (*a>*b) - (*a < *b);*/
}

int mystrcmp(const void* va, const void* vb) {
	char* const* a = va;
	char* const* b = vb;

}

int main(void) {
	char* arr[7] = {
		"hi", "stupid", "hoe", "aleksandra", "is" "a" "bitch"
	};
	size_t n = 7;
	qsort(arr, n, sizeof(*arr), mystrcmp); //ordina dati generici
	char val[] = "aleksandra";
	char p[] = val;
	char** res = bsearch(&p, arr, n, sizeof(*arr), mystrcmp);

	/*
	{ 7, 9, 2, -5, 3, -1, 2}
	{-5, 9, 2, 7, 3, -1, 2}
	{-5, -1, 2, 7, 3, 9, 2}
	{-5, -1, 2, 7, 3, 9, 2}
	{-5, -1, 2, 2, 7, 3, 9}
	{-5, -1, 2, 2, 7, 3, 9}
	{-5, -1, 2, 2, 3, 7, 9}
	*/

	/*int (*fn)(void* va, void* vb); //puntatore a funzione che accetta 2 void pointer e restituisce int
	fn = intcmp;
	int res = fn(&arr[0], &arr[1]); //res vale -1 */
	//i puntatori a funzione ci permettono in tempo reale a decidere quale funzione viene utilizzata

	return 0;
}