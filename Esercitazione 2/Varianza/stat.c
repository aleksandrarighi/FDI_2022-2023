#include "stat.h"
#include <stdlib.h>

double media(double* x, unsigned int n) {
    if (x == NULL) {
        return;
    }
    if (n == 0) {
        return 0;
    }

    double somma = 0.0;

    for (unsigned int i = 0; i < n; i++) {
        somma = somma + x[i];
    }

    return somma / n;
}

double varianza(double* x, unsigned int n) {
    if (x == NULL) {
        return;
    }
    if (n == 0) {
        return 0;
    }

    if (n < 2) {
        return 0.0;
    }

    double average = media(x, n);
    double var = 0.0;

    for (unsigned int i = 0; i < n; i++) {
        var = var + (x[i] - average) * (x[i] - average);
    }

    return var / n;
}

/*#include <stdlib.h>
#include "stat.h"

	double potenza(double x, int n)
	{
		double pot = 1;
		for (int i = 0; i < n; ++i) {
			pot *= x;
		}
		return pot;
	}

	double media(double* x, unsigned int n)
	{
		if (x == NULL)
			return 0;
		double average = 0;
		if (n == 0)
			return 0;
		for (unsigned int i = 0; i < n; ++i) {
			average += x[i];
		}
		average /= n;
		return average;
	}

	double varianza(double* x, unsigned int n)
	{
		if (x == NULL)
			return 0;

		double var = 0;
		if (n < 2)
			return 0;

		double diff = 0;
		for (unsigned int i = 0; i < n; ++i) {
			diff += potenza((x[i] - media(x, n)), 2);
		}
		var = diff / n;
		return var;
	}

	stat.h
#if !defined MEDIA_H
#define MEDIA_H
		extern double media(double* x, unsigned int n);
#endif //MEDIA_H

#if !defined VARIANZA_H
#define VARIANZA_H
	extern double varianza(double* x, unsigned int n);
#endif //VARIANZA_H*/