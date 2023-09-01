#include <math.h>
#include <stdlib.h>

double solve(double a) {
	double x = 0.0;
	double epsilon = 1e-10;

	while (1) {
        double next_x = x + (cos(x) - a * x) / (sin(x) + a);

        if (fabs(next_x - x) < epsilon) {
            return next_x;
        }

        x = next_x;
    }
}