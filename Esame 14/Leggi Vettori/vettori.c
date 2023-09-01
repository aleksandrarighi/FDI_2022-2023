#include "vettori.h"
#include <stdlib.h>

struct vettore* vettori_leggi(FILE* f, size_t* n) {
    struct vettore* vettori = NULL;
    *n = 0;

    while (f != EOF) {
        int len;
        if (fscanf(f, "%d", &len) != 1) {
            break;
        }

        if (len <= 0) {
            continue;
        }

        struct vettore* tmp = realloc(vettori, (*n + 1) * sizeof(struct vettore));
        if (tmp == NULL) {
            for (size_t i = 0; i < *n; i++) {
                free(vettori[i].data);
            }
            free(vettori);
            return NULL;
        }
        vettori = tmp;

        vettori[*n].len = len;
        vettori[*n].data = malloc(len * sizeof(int));

        if (vettori[*n].data == NULL) {
            for (size_t i = 0; i < *n; i++) {
                free(vettori[i].data);
            }
            free(vettori);
            return NULL;
        }

        for (int i = 0; i < len; i++) {
            if (fscanf(f, "%d", &vettori[*n].data[i]) != 1) {
                for (size_t i = 0; i < *n + 1; i++) {
                    free(vettori[i].data);
                }
                free(vettori);
                return NULL;
            }
        }

        (*n)++;
    }

    return vettori;
}