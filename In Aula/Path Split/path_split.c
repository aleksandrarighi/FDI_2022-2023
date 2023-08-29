#define _CRT_SECURE_NO_WARNINGS_
#include "path_split.h"
#include <stdlib.h>
#include <string.h>

void path_split(const char* str, char** path, char** filename) {
	if (str == NULL) {
		*path = NULL;
		*filename = NULL;
	}

	if (str == NULL) {
		return;
	}

	char* p = strrchr(str, '\\');
	if (p == NULL) {
		return NULL;
	}

	*path = calloc(p - str + 2, 1);
	*filename = calloc(strlen(p + 1) + 1, 1);

	strncpy(*path, str, p - str + 1);
	strcpy(*filename, p + 1);
}