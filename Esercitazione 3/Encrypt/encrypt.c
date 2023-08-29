/*Creare il file "encrypt.c" che contenga la definizione della seguente funzione:

extern void encrypt(char *s, unsigned int n);
La funzione accetta una sequenza s di n char e la codifica sostituendo ad ogni char il suo valore trasformato con uno XOR bit a bit con il valore esadecimale AA.

Per le proprietà dello XOR, l'operazione è invertibile, quindi, riapplicando la funzione sulla sequenza codificata, si riottiene quella originale. Non è richiesto, né è garantito che la sequenza sia 0 terminata. Per questo motivo viene passato un parametro apposito.*/

void encrypt(char* s, unsigned int n) {
	for (unsigned int i = 0; i < n; i++) {
		s[i] = s[i] ^ 0xAA;
	}
}