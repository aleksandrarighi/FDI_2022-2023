#include<stdio.h>
#include <string.h>

int accodaTuttiFile(const char* fileConNomi, const char* fileOutput) {
	FILE* f_nomi = fopen(fileConNomi, "r");
	if (f_nomi == NULL) {
		return NULL;
	}

	FILE* f_output = fopen(fileOutput, "wb");
	if (f_output == NULL) {
		return NULL;
	}

    int successCount = 0;
    char fileName[256];

    while (fgets(fileName, sizeof(fileName), f_nomi) != NULL) {
        size_t len = strlen(fileName);
        if (len > 0 && fileName[len - 1] == '\n') {
            fileName[len - 1] = '\0';
        }

        FILE* inputFile = fopen(fileName, "rb");
        if (inputFile != NULL) {
            int c;
            while ((c = fgetc(inputFile)) != EOF) {
                fputc(c, f_output);
            }
            fclose(inputFile);
            successCount++;
        }
    }

    fclose(f_nomi);
    fclose(f_output);
    return successCount;
}