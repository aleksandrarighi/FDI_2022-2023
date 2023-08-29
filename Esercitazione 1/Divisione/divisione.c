/*Nel file "divisione.c", si definisca la seguente funzione utilizzando comandi del linguaggio C:

extern int divisione(double a, double b, double *q);
La funzione accetta due double a e b. Se b è diverso da 0, mette nella variabile puntata da q il risultato di a diviso b e ritorna 1, altrimenti ritorna 0 e non modifica la variabile puntata da q.*/

int divisione(double a, double b, double* q) {
	if (b != 0) {
		*q = a = a/ b;
		return 1;
	}
	if (b == 0) {
		return 0;
	}
}