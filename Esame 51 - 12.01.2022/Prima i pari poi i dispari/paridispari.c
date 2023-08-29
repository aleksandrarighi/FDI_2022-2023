#include "paridispari.h"
#include <string.h>

void paridispari(int* v, size_t n) {
	if (v == NULL || n == 0) {
		return;
	}

	int i = 0; 
	int j = n - 1;
	
	while (i < j) {
		while (v[i] % 2 == 0 && i < j) {
			i++;
		}

		while (v[j] % 2 != 0 && i < j) {
			j--;
		}

		if (i < j) {
			int tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
		}
	}
}