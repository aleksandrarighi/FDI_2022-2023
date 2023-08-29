#include "is_tga.h"
#include <stdio.h>
#include <string.h>

bool is_tga(const char* filename) {
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		return false;
	}

	fseek(f, 0, SEEK_END);
	long f_size = ftell(f);
	if (f_size < 18) {
		fclose(f);
		return false;
	}

	fseek(f, -18, SEEK_END);
	char s[19];
	fread(s, sizeof(s), 18, f);
	s[18] = '\0';

	const char* caratteri = "TRUEVISION-XFILE.";
	bool is_tga = strcmp(caratteri, s);
	if (is_tga != 0) {
		fclose(f);
		return false;
	}

	fclose(f);
	return true;
}