#ifndef FINANCE_H
#define FINANCE_H
#include <stdio.h>

struct value {
    char Date[11];
    double Open, High, Low, Close, AdjClose;
    long long Volume;
};

extern struct value* read_historical_series(const char* filename, size_t* n);

#endif
