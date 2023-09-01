#include "audio.h"
#include <stdlib.h>

int audio_read(const char* filename, struct audio* a) {
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		return 0;
	}

	size_t size = 0; 

	a->left = NULL;
	a->right = NULL;

	while (1) {
		short left, right;
		if (fread(&left, sizeof(short), 1, f) != 1) {
			break;
		}
		if (fread(&right, sizeof(short), 1, f) != 1) {
			break;
		}

		short* new_left = realloc(a->left, (size + 1) * sizeof(short));
		short* new_right = realloc(a->right, (size + 1) * sizeof(short));
		if (new_left == NULL || new_right == NULL) {
			free(a->left);
			free(a->right);
			fclose(f);
			return 0; 
		}
		a->left = new_left;
		a->right = new_right;

		a->left[size] = left;
		a->right[size] = right;
		size++;
	}
	a->samples = size;
	fclose(f);

	return size > 0; 
}