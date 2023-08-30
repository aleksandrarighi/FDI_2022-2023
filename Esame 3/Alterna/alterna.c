#include "alterna.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* alterna(const char* s1, const char* s2) {
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);
	size_t tot_len = len1 + len2 + 1;
	
	char* new_str = malloc(tot_len * sizeof(char));
	if (new_str == NULL) {
		return NULL;
	}

	size_t i, j, k;
	for (i = 0, j = 0, k = 0; i < len1 && j < len2; i++, j++) {
		new_str[k++] = s1[i];
		new_str[k++] = s2[j];
	}

	while (i < len1) {
		new_str[k++] = s1[i++];
	}

	while (j < len2) {
		new_str[k++] = s2[j++];
	}

	new_str[tot_len - 1] = '\0';
	return new_str;
}