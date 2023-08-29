double fattoriale(double n) {
    if (n == 0) {
        return 1;
    }

    double result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }

    return result;
}

double potenza(double x, int n) {
    if (n == 0) {
        return 1;
    }

    double result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * x;
    }

    return result;
}

double exp(double x) {
    double e = 0;
    double previousE = 0;
    int iterations = 10;
    int i = 0;
    int terminate = 0;

    for (; i <= iterations && !terminate; i++) {
        previousE = e;
        e = e + potenza(x, i) / fattoriale(i);

        if (i > 0 && e == previousE) {
            terminate = 1;
        }
    }

    return e;
}