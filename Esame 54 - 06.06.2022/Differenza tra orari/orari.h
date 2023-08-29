#ifndef ORARI_H
#define ORARI_H

#include <stdint.h>
struct orario {
    uint8_t ore;
    uint8_t minuti;
    uint8_t secondi;
};

extern struct orario differenza_orari(struct orario a, struct orario b);

#endif
