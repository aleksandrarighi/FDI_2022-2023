#include "angoli.h"

struct angolo differenza_angoli(struct angolo a, struct angolo b) {
	int asec = a.gradi * 60 * 60 + a.primi * 60 + a.secondi;
	int bsec = b.gradi * 60 * 60 + b.primi * 60 + b.secondi;

	struct angolo ret = { 0xFFFF, 0xFF, 0xFF };

	if (asec > bsec) {
		int diffsec = asec - bsec;

		ret.secondi = diffsec % 60;
		int diffprimi = diffsec / 60;

		ret.primi = diffprimi % 60;
		int diffgradi = diffprimi / 60;

		ret.gradi = diffgradi;
	}
	return ret;
}