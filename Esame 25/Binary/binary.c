#include "binary.h"
#include <stdio.h>

void stampa_binario(const char* filename_in, const char* filename_out) {
	FILE* f_in = fopen(filename_in, "rb");
	if (f_in == NULL) {
		return;
	}

	FILE* f_out = fopen(filename_out, "w");
	if (f_out == NULL) {
		fclose(f_in);
		return;
	}

	int byte_count = 0;
	int bit_count = 0;
	unsigned char byte;
	while (fread(&byte, sizeof(unsigned char), 1, f_in) == 1) {
		for (int i = 7; i >= 0; i--) {
			unsigned char bit = (byte >> i) & 1;
			fprintf(f_out, "%d", bit);
			bit_count++;

			if (bit_count % 8 == 0) {
				fprintf(f_out, " ");
				byte_count++;
			}
		}
		if (byte_count % 8 == 0) {
			fprintf(f_out, "\n");
		}
	}
	fclose(f_in);
	fclose(f_out);
}