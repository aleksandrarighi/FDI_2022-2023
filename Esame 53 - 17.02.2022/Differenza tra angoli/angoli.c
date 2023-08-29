#include "angoli.h"
#include <stdlib.h>

struct angolo differenza_angoli(struct angolo a, struct angolo b) {
	struct angolo differenza;

		uint16_t a_secondi = a.gradi * 3600 + a.primi * 60 + a.secondi;
		uint16_t b_secondi = b.gradi * 3600 + b.primi * 60 + b.secondi;
		
		if (a_secondi < b_secondi) {
			struct angolo nonvalido = { 0xFFFF, 0xFF, 0xFF };
			return nonvalido;
		}

		uint16_t differenzasecondi = a_secondi - b_secondi;

		differenza.gradi = (differenzasecondi) / 3600;
		differenza.primi = (differenzasecondi % 3600) / 60;
		differenza.secondi = (differenzasecondi % 3600) % 60;

		return differenza;
	
}