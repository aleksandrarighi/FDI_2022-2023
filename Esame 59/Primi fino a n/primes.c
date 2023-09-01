#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}

	//converti stringa in int
	int n = atoi(argv[1]);
	// oppure int n = strtol(argv[1], NULL, 10);

	//oppure 
	/*int n;
	sscanf(argv[1], "%d", &n);*/

	if (n == 0 || n == 1) {
		return 1;
	}

	for (int i = 2; i < n; i++) {
		bool isprime = true;
		//controllo che il numero i sia primo
		//cioè se è divisibile per un numero diverso da 1 e se stesso return false;
		for (int j = 2; j < i; j++) { //j<i/2 è la stessa cosa,basta controllare solo la prima meta 
			if (i % j == 0) {
				isprime = false;
				return 1; //basta che ne trovo uno ed è gia falso
			}
		}
		if (isprime) {
			printf("%d ", i);
		}

	}
	printf("\n");
	return 0;
}