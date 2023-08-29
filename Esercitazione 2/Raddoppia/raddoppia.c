/*Nel file "raddoppia.c", definire la funzione raddoppia() sapendo che deve prendere un vettore di interi senza segno a 32 bit e il loro numero n, e per ognuno dei suoi elementi deve calcolarne il doppio e memorizzarlo all'interno del vettore nella stessa posizione.

extern void raddoppia(uint32_t *x, size_t n);
Se x è NULL, la funzione non deve fare nulla.*/

#include <stdint.h>
#include <stdlib.h>

void raddoppia(uint32_t* x, size_t n) {
    if (x == NULL) {
        return;
    }

    for (size_t i = 0; i < n; i++) {
        x[i] *= 2;
    }
}


/*int main(void)
{
    size_t n = 3;
    uint32_t* v = malloc(n * sizeof(uint32_t));
    v[0] = 12;
    v[1] = 59;
    v[2] = 83;
    raddoppia(v, n);
    free(v);
    return 0;
}*/