#include "punti.h"
#include <math.h>

int trova_piu_lontani(const struct punto3d* punti, size_t n, size_t* p1, size_t* p2) {
	if (n < 2) {
		return 0;
	}

	double max_distance = 0;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = i + 1; j < n; j++) {
			double distance = sqrt(pow(punti[i].coord[0] - punti[j].coord[0], 2) +
								   pow(punti[i].coord[1] - punti[j].coord[1], 2) +
								   pow(punti[i].coord[2] - punti[j].coord[2], 2));
			if (distance > max_distance) {
				max_distance = distance;
				*p1 = i;
				*p2 = j;
			}
		}
	}
	return 1;
}