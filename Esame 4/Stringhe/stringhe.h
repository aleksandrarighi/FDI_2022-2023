#ifndef STRING_H
#define STRING_H

struct stringa {
    unsigned char length;
    char* s;
};

extern struct stringa* read_stringhe_bin(const char* filename, unsigned int* pn);

#endif
