#include "complessi.h"

void prodotto_complesso(struct complesso* comp1, const struct complesso* comp2) {
	double re = (comp1->re * comp2->re) - (comp1->im * comp2->im);
	double im = (comp1->re * comp2->im) + (comp1->im * comp2->re);

	comp1->re = re;
	comp1->im = im;
}

/*#include <stdio.h>
#include "complessi.h"

int main(void) {
    struct complesso comp1 = {3.0, 2.0};
    struct complesso comp2 = {4.0, -1.0};

    printf("Prima del prodotto: comp1 = %.1f + %.1fi\n", comp1.re, comp1.im);

    prodotto_complesso(&comp1, &comp2);

    printf("Dopo il prodotto: comp1 = %.1f + %.1fi\n", comp1.re, comp1.im);

    return 0;
}
*/
