#include "libri.h"

extern bool libro_scrivi(const struct libro* p, FILE* f) {
    // Scrittura del titolo
    size_t titolo_length = strlen(p->titolo);
    if (fwrite(p->titolo, sizeof(char), titolo_length, f) != titolo_length) {
        return false;
    }
    if (fwrite("\0", sizeof(char), 1, f) != 1) {
        return false;
    }

    // Scrittura delle ristampe
    uint16_t* ristampe_ptr = p->anni_ristampe;
    while (*ristampe_ptr != 0) {
        if (fwrite(ristampe_ptr, sizeof(uint16_t), 1, f) != 1) {
            return false;
        }
        ristampe_ptr++;
    }
    // Scrittura del terminatore (0)
    if (fwrite(ristampe_ptr, sizeof(uint16_t), 1, f) != 1) {
        return false;
    }

    return true;
}