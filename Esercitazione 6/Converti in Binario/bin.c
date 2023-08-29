#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 0) {
        return 1;
    }

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    char binaryString[33]; // Considero un massimo di 32 bit (lunghezza massima della rappresentazione binaria di un int)
    int index = 0;

    while (n != 0) {
        binaryString[index] = '0' + (n % 2);
        n /= 2;
        index++;
    }

    binaryString[index] = '\0'; // Aggiungi il terminatore di stringa

    int start = 0;
    int end = index - 1;

    while (start < end) {
        char temp = binaryString[start];
        binaryString[start] = binaryString[end];
        binaryString[end] = temp;

        start++;
        end--;
    }

    printf("%s\n", binaryString);

    return 0;
}
