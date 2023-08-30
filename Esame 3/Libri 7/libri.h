#ifndef LIBRI_H
#define LIBRI_H

struct libro {
    unsigned int codice;
    char titolo[255];
    unsigned int pagine;
};

struct libro* filtra_libri(struct libro* plibri, unsigned int* pn, const char* cerca);

#endif
