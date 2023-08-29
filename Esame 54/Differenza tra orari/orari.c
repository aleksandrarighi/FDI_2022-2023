#include "orari.h"

struct orario differenza_orari(struct orario a, struct orario b) {
	struct orario differenza;

	if (a.ore >= b.ore && a.minuti >= b.minuti && a.secondi >= b.secondi) {
		uint8_t a_secondi = a.ore * 3600 + a.minuti * 60 + a.secondi;
		uint8_t b_secondi = b.ore * 3600 + b.minuti * 60+ b.secondi;
		uint8_t differenza_secondi;

		if (a.secondi >= b.secondi) {
			differenza_secondi = a_secondi - b_secondi;
		}
		else {
			differenza_secondi = (24 * 3600) - (a_secondi - b_secondi);
		}

		differenza.ore = differenza_secondi / 3600;
		differenza.minuti = (differenza_secondi % 3600) / 60;
		differenza.secondi = (differenza_secondi % 3600) % 60;

		return differenza;
	}
	else {
		struct orario nonvalido = { 0xFF, 0xFF, 0xFF };
		return nonvalido;
	}
}