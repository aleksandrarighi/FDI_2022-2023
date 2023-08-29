#ifndef DATASET_H
#define DATSET_H

struct row {
    char* filename; // max 255 characters
    char prognosis; // M or S
};

struct dataset {
    struct row* data;
    size_t nrows;
};

extern struct dataset* dataset_load(const char* filename);

#endif
