#include <stdlib.h>
#include <string.h>

char* extract_number(const char* message) {
    if (message == NULL) {
        return NULL;
    }

    const char* italianNumbers[11] = {
        "zero", "uno", "una", "due", "tre", "quattro", "cinque",
        "sei", "sette", "otto", "nove"
    };

    char* new_str = NULL;
    int count = 0;

    for (const char* i = message; *i != '\0'; i++) {
        for (int j = 0; j < 11; j++) {
            if (strncmp(i, italianNumbers[j], strlen(italianNumbers[j])) == 0) {
                new_str = realloc(new_str, (count + 2)*sizeof(char));
                if (new_str == NULL) {
                    return NULL;
                }
                new_str[count++] = '0' + j; //scrivo il numero in new_str che occupa count
                i += strlen(italianNumbers[j]) - 1; //vado alla parola successiva
                break;
            }
        }
    }

    if (new_str != NULL) {
        new_str[count] = '\0';
    }

    return new_str;
}
