#include "strip_comments.h"
#include <stdio.h>

void strip_comments(const char* in_filename, const char* out_filename) {
	FILE* f_in = fopen(in_filename, "r");
	if (f_in == NULL) {
		return;
	}

	FILE* f_out = fopen(out_filename, "w");
	if (f_out == NULL) {
		fclose(f_in);
		return;
	}

	char line[2048];
	while (fgets(line, sizeof(line), f_in) != NULL) {
		if (line[0] != '#') {
			fprintf(f_out, "%s", line);
		}
	}
	fclose(f_in);
	fclose(f_out);
}