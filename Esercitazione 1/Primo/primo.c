/*Nel file "primo.c", si definisca la seguente funzione utilizzando comandi del linguaggio C:

extern int primo (unsigned int val);
La funzione riceve un numero intero val e restituisce 1 se val è primo, 0 altrimenti. Se non conoscete la definizione di numero primo, usate Wikipedia.*/

int primo(unsigned int val) {
	if (val < 2) {
		return 0;
	}

	for (int i = 2; i < val; i++) {
		if (val % i == 0) {
			return 0;
		}
		else return 1;
	}
}