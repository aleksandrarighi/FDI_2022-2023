#ifndef READ_FILE_H
#define READ_FILE_H

#include <stdio.h>
typedef unsigned char byte;

extern byte* read_file(const char* szFileName, size_t* cb);

#endif
