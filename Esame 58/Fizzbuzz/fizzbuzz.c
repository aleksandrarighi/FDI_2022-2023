#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 != 0) {
            printf("Fizz\n");
        }
        else if (i % 5 == 0 && i % 3 != 0) {
            printf("Buzz\n");
        }
        else if (i % 3 == 0 && i % 5 == 0) {
            printf("FizzBuzz\n");
        }
        else {
            printf("%d\n", i);
        }
    }
    return 0;
}
