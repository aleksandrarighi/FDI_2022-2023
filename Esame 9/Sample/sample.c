#include "sample.h"

extern int sample_scrivi(FILE* f, const struct sample* s) {
	if (fwrite(&s->idSample, sizeof(int), 1, f) != 1) {
		return 0;
	}

	if (fwrite(s->nomeCategoria, sizeof(char), 20, f) != 20) {
		return 0;
	}

	if (fwrite(&s->accuracy, sizeof(double), 1, f) != 1) {
		return 0;
	}
		
	return 1;
}

extern int sample_leggi(FILE* f, struct sample* s) {
	if (fread(&s->idSample, sizeof(int), 1, f) != 1) {
		return 0;
	}
	if (fread(s->nomeCategoria, sizeof(char), 20, f) != 20) {
		return 0;
	}
	s->nomeCategoria[19] = '\0';
	
	if (fread(&s->accuracy, sizeof(double), 1, f) != 1 ) {
		return 0;
	}

	return 1;	
}