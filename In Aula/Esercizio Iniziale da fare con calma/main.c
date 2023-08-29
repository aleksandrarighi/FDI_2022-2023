#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int x = 266;
	char s[] = "prova"; // array di 6 char (terminatore)
	FILE* f;

	f = fopen("out1", "w"); /*apre il file in scrittura in modalità traduci gli a capo: 
							ogni volta che scrivo un byte che vale 10 sul file, 
							lui scriverà un 13 e un 10*/
	fprintf(f, "%i\n%s", x, s); /*io gli do un x che è un valore in base 2 a 32 bit (int)
								e printf lo trasforma, né produce in output una 
								rappresentazione in formato testo in base 10
								x= '2' '6' '6' = 32 36 36
								/n= è un byte che vale 10, quindi 0a, ma lui scriverà 0d 0a
								%s= prendi tutti i caratteri puntati da s e buttali dentro =
								'p' 'r' 'o' 'v' 'a'*/
	fclose(f); /*troverò 10 byte*/

	f = fopen("out2", "wb"); /*apre il file in scrittura in modalità non tradotta (binaria)*/
	fprintf(f, "%i\n%s", x, s); /*32 36 36 0a p r o v a (binario)*/
	fclose(f);

	f = fopen("out3", "w");
	fwrite(&x, sizeof x, 1, f); /*va in memoria prende sizeof x e lo scrive sul file 
								x è in base 2 grande 32 bit
								100001010 = 266 in binario (256 + 10)
								266 = 0x0000010A
								0d 0a 01 00 00 (little endian)*/
	fwrite(&s, sizeof s, 1, f); //p r o v a 00, sizeof s vale 6
	fclose(f); //vale 11

	f = fopen("out4", "wb");
	fwrite(&x, sizeof x, 1, f);/*0a 01 00 00*/
	fwrite(&s, sizeof s, 1, f);//p r o v a 00, sizeof s vale 6
	fclose(f);// vale 10
	return 0;
}