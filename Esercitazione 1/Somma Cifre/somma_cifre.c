/*Nel file "somma_cifre.c", si definisca la seguente funzione utilizzando comandi del linguaggio C:

extern unsigned int somma_cifre(unsigned int x);
La funzione deve restituire la somma delle cifre della rappresentazione in base 10 di x. Ad esempio, se x vale 123, la funzione deve restituire 6.*/

unsigned int somma_cifre(unsigned int x) {
	unsigned int i = 0;
	while (x != 0) {
		i = i + (x % 10);
		x = x / 10;
	}
	return i;
}