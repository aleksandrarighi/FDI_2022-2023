#include "read_file.h"
#include <stdlib.h>

byte* read_file(const char* szFileName, size_t* cb) {
	FILE* f = fopen(szFileName, "rb");
	if (f == NULL) {
		return NULL;
	}

	fseek(f, 0, SEEK_END);
	*cb = ftell(f);
	fseek(f, 0, SEEK_SET);

	byte* new_ptr = malloc(*cb);
	fread(new_ptr, 1, *cb, f);

	fclose(f);
	return new_ptr;
}