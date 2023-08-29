#ifndef FREQUENZA_H
#define FREQUENZA_H

struct oggetto {
    char* forma;
    char* colorenumero;
};
struct carta {
    struct oggetto* disegni;
    size_t n;
};

extern struct oggetto* piu_frequente(const struct carta* c);

#endif
