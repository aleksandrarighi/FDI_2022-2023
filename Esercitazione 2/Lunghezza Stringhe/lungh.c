#include <stdlib.h>

size_t lungh(const char* str) {
    size_t len = 1;
    for (size_t i = 1; str[i] != 0 ; i++) {
        len = i + 1;
    }
    return len;
}

int main(void) {
    char s[] = "Ecco la stringa di prova";
    size_t len;
    len = lungh(s);
    return 0;
}