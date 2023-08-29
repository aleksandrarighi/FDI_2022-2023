/*Nel file "prossimo_primo.c", si definisca la seguente funzione utilizzando comandi del linguaggio C:

extern unsigned int prossimo_primo(unsigned int x);
La funzione deve ritornare il più piccolo numero primo maggiore di x.*/

int primo(unsigned int val) {
	if (val < 2) {
		return 0;
	}
	for (unsigned int i = 2; i < val; i++) {
		if (val % i == 0) {
			return 0;
		}
	}
	return 1;
}

unsigned int prossimo_primo(unsigned int x)
{
	int i = 1;
	while (primo(x + i) == 0)
		++i;
	if (primo(x + i) == 1)
		return x + i;
	else
		return 0;
}