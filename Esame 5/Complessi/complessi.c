#include "complessi.h"

int read_complesso(struct complesso* comp, FILE* f) {
	if (fscanf(f, "%lf%lf", &(comp->re), &(comp->im)) != 2) {
		return 0;
	}
	return 1;
}

void write_complesso(const struct complesso* comp, FILE* f) {
	fprintf(f, "%f %f\n", comp->re, comp->im);
}

void prodotto_complesso(struct complesso* comp1, const struct complesso* comp2) {
	double re = comp1->re * comp2->re - comp1->im * comp2->im;
	double im = comp1->im * comp2->re + comp1->re * comp2->im;

	comp1->re = re;
	comp1->im = im;
}
