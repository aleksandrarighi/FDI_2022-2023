#include <stdlib.h>
#include <string.h>

const void* memmem(const void* pagliaio, size_t psize, const void* ago, size_t asize) {
    if (pagliaio == NULL || psize == 0 || ago == NULL || asize == 0) {
        return NULL;
    }

    const char* puntatoreapagliaio = pagliaio;
    const char* ultimopossibilematch = puntatoreapagliaio + psize - asize;

    while ((puntatoreapagliaio = memchr(puntatoreapagliaio, *(const unsigned char*)ago, psize - (puntatoreapagliaio - (const char*)pagliaio)))) {
        if (puntatoreapagliaio > ultimopossibilematch) {
            return NULL;
        }
        if (memcmp(puntatoreapagliaio, ago, asize) == 0) {
            return puntatoreapagliaio;
        }
        puntatoreapagliaio++;
    }

    return NULL;
}
