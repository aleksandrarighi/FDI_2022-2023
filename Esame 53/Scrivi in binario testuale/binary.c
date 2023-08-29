#include "binary.h"
#include <stdio.h>

void stampa_binario(const char* filename_in, const char* filename_out) {
	FILE* input_file = fopen(filename_in, "rb");
	if (input_file == NULL) {
		return;
	}

	FILE* output_file = fopen(filename_out, "w");
	if (output_file == NULL) {
		fclose(input_file);
		return;
	}

	int byte_count = 0;
	unsigned char byte;

	while (fread(&byte, sizeof(unsigned char), 1, input_file) == 1) {
		for (int i = 7; i >= 0; i--) {
			unsigned char bit = (byte >> i) & 1;
			fprintf(output_file, "%d", bit);
		}
		fprintf(output_file, " ");
		byte_count++;

		if (byte_count % 8 == 0) {
			fprintf(output_file, "\n");
		}
	}

	fclose(input_file);
	fclose(output_file);
}