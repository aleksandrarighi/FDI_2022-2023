#include "stringhe.h"
#include <stdio.h>
#include <stdlib.h>

struct stringa* read_stringhe_bin(const char* filename, unsigned int* pn) {
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		*pn = 0;
		return NULL;
	}

	*pn = 0;
	struct stringa* arr = NULL;

	unsigned char length;
	while (fread(&length, sizeof(unsigned char), 1, f) == 1 && length != 0) {
		(*pn)++;

		struct stringa* new_arr = realloc(arr, *pn * sizeof(struct stringa));
		if (new_arr == NULL) {
			fclose(f);
			free(arr);
			return NULL;
		}
		
		arr = new_arr;

		arr[*pn - 1].length = length;
		arr[*pn - 1].s = malloc(length + 1); //1 per il terminatore NULL
		if (arr[*pn - 1].s == NULL) {
			fclose(f);
			free(arr);
			return NULL;
		}

		fread(arr[*pn - 1].s, sizeof(char), length, f);
		arr[*pn - 1].s[length] = '\0';
	}
	fclose(f);
	return arr;
}