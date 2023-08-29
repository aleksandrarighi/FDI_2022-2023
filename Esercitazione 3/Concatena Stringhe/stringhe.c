#include <stdlib.h>
#include <string.h>

char* concatena(const char* prima, const char* seconda) {
    size_t len1 = strlen(prima);
    size_t len2 = strlen(seconda);
    size_t totlen = len1 + len2 + 1; //terminatore null
    
    if (prima == NULL || seconda == NULL || *prima == '\0' || *seconda == '\0') {
        char* str = malloc(sizeof(char));
        str[0] = '\0';
        return str;
    }

    char* str = malloc(totlen * sizeof(char));
    if (str == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < len1; i++) {
        str[i] = prima[i];
    }
    for (size_t i = 0; i < len2; i++) {
        str[len1 + i] = seconda[i];
    }

    str[totlen - 1] = '\0';
    return str;

}

/*int main(void)
{
    char s1[] = "Questa e' la ";
    char s2[] = "stringa risultante.";
    char* s;
    s = concatena(s1, s2);
    free(s);
    return 0;
}*/


#include <string.h>
#include <stdlib.h>

char* concatena(const char* prima, const char* seconda) {
    size_t len1;
    if (prima == NULL) {
        len1 = 0;
    }
    else {
        len1 = strlen(prima);
    }
    size_t len2;
    if (seconda == NULL) {
        len2 = 0;
    }
    else {
        len2 = strlen(seconda);
    }

    size_t totlen = len1 + len2;
    char* ris = malloc(totlen + 1);
    ris[len1 + len2] = 0;

    for (size_t i = 0; i < len1; ++i) {
        ris[i] = prima[i];
    }
    for (size_t i = 0; i < len2; ++i) {
        ris[len1 + i] = seconda[i];
    }

    return ris;
}

/*int main(void) {
    char s1[] = "Questa e' la ";
    char s2[] = "stringa risultante.";
    char* s;
    s = concatena(s1, s2);
    free(s);
    return 0;
}*/