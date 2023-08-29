#include "punto.h"
#include <math.h>

struct punto_pol cartesiano2polare(const struct punto_cart* p) {
	struct punto_pol result;

	double r = sqrt(p->x * p->x + p->y * p->y);
	double t = atan2(p->y, p->x);

	result.r = r;
	result.t = t;
	
	return result;
}

struct punto_cart polare2cartesiano(const struct punto_pol* p) {
	struct punto_cart result;

	double x = (p->r) * cos(p->t);
	double y = (p->r) * sin(p->t);

	result.x = x;
	result.y = y;

	return result;
}