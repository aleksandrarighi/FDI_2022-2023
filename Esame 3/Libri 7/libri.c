#include "libri.h"
#include <string.h>
#include <stdlib.h>

struct libro* filtra_libri(struct libro* plibri, unsigned int* pn, const char* cerca) {
	unsigned int count = 0; 

	for (unsigned int i = 0; i < *pn; i++) {
		if (strstr(plibri[i].titolo, cerca) != NULL) {
			count++;
		}
	}

	if (count == 0) {
		*pn = 0; 
		return NULL;
	}

	struct libro* filtered_libri = malloc(count * sizeof(struct libro));
	if (filtered_libri == NULL) {
		return NULL;
	}

	unsigned int index = 0;
	for (unsigned i = 0; i < *pn; i++) {
		if (strstr(plibri[i].titolo, cerca) != NULL) {
			filtered_libri[index] = plibri[i];
			index++;
		}
	}

	*pn = count;
	return filtered_libri;

}