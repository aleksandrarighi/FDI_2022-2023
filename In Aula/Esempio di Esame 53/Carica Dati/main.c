#include "dataset.h"

int main(void) {
	struct dataset* p;
	p= dataset_load("file1.txt");
	for (size_t i = 0; i < p->nrows; ++i) {
		free(p->data[i].filename);
	}
	free(p->data);
	free(p);

	p= dataset_load("file2.txt");
	for (size_t i = 0; i < p->nrows; ++i) {
		free(p->data[i].filename);
	}
	free(p->data);
	free(p);

	p= dataset_load("file3.txt");
	for (size_t i = 0; i < p->nrows; ++i) {
		free(p->data[i].filename);
	}

	free(p->data);
	free(p);

	return 0;
}