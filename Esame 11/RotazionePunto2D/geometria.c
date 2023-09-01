#include <math.h>

struct punto {
    double x, y;
};

void rotazione(struct punto* p, double alfa) {
    p->x = p->x * cos(alfa) - p->y * sin(alfa);
    p->y = p->x * sin(alfa) + p->y * cos(alfa);
}