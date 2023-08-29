#include <stdint.h>
#include <stdlib.h>

uint32_t* somme_2a2(uint32_t* vett, size_t size) {
    if (vett == NULL) {
        return;
    }

    size_t v = 0;
    *vett = malloc((size / 2) * sizeof(uint32_t));

    for (size_t i = 0; i < size; i+=2) {

        if (size % 2 != 0 && i == size - 1) {
            return vett;
        }

        vett[v] = vett[i] + vett[i + 1];
        v++;
    }
    return vett;
}

int main(void)
{
    size_t n = 6;
    uint32_t* v = malloc(n * sizeof(uint32_t));
    v[0] = 3; v[1] = 87; v[2] = 5; v[3] = 7; v[4] = 12; v[5] = 9;
    uint32_t* somme = somme_2a2(v, n);
    free(v);
    free(somme);
    return 0;
}