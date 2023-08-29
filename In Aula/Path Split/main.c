#include "path_split.h"
#include <stdlib.h>

int main(void)
{
	char* path, * filename;
	path_split("c:\\user\\esami\\FdI2017\\esercizi", &path, &filename);
	free(path);
	free(filename);

	path_split("c:\\user\\esami\\FdI2017\\esercizi\\file.txt", &path, &filename);
	free(path);
	free(filename);

	path_split("esercizi\\", &path, &filename);
	free(path);
	free(filename);
}