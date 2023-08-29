int conta_spazi(const char* s) {
	int contatore = 0;
	for (int i = 0; s[i] != 0; i++) {
		if (s[i] == ' ') {
			contatore += 1;
		}
	}
	return contatore;
}

/*int main() {
	const char* stringa = "Prova stringa in cui contare gli spazi";
	int numero_spazi = conta_spazi(stringa);

	printf("La stringa '%s' contiene %d spazi.\n", stringa, numero_spazi);

	return 0;
}*/