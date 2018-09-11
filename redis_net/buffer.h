#ifndef ANET_AEBUFFER_H
#define ANET_AEBUFFER_H

#include<sys/types.h>

typedef struct{
    unsigned char *buff;
    size_t size;
    size_t read_idx;
    size_t write_idx;
}buffer_t;

#endif