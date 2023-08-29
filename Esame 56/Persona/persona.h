#ifndef PERSONA_H
#define PERSONA_H

struct persona {
    int anni;
    char nome[50];
};

extern struct persona* leggi_persone(const char* filename, size_t* size);

#endif
