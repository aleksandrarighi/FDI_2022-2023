#include "compress.h"
#include <stdint.h>
#include <stdlib.h>

int dati_read(const char* filename, struct dati* d) {
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		return 0;
	}

	d->len = 0;
	d->vals = NULL;

	while (f != EOF) {
		unsigned char type;
		if (fread(&type, sizeof(unsigned char), 1, f) != 1) {
			break;
		}

		int val = 0;
		size_t size;

		if (type == 1) {
			int8_t value;
			if (fread(&value, sizeof(int8_t), 1, f) != 1) {
				fclose(f);
				free(d->vals);
				return 0;
			}
			val = value;
			size = sizeof(int8_t);
		}
		else if (type == 2) {
			int16_t value;
			if (fread(&value, sizeof(int16_t), 1, f) != 1) {
				fclose(f);
				free(d->vals);
				return 0;
			}
			val = value;
			size = sizeof(int16_t);
		}
		else if (type == 4) {
			int32_t value;
			if (fread(&value, sizeof(int32_t), 1, f) != 1) {
				fclose(f);
				free(d->vals);
				return 0;
			}
			val = value;
			size = sizeof(int32_t);
		}
		else {
			fclose(f);
			free(d->vals);
			return 0;
		}
		d->vals = realloc(d->vals, (d->len + 1) * sizeof(int));
		if (d->vals == NULL) {
			fclose(f);
			free(d->vals);
			return 0;
		}
		d->vals[d->len] = val;
		d->len++;
	}
	fclose(f);
	return 1;
}