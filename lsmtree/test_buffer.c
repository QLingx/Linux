#include<stdio.h>
#include"buffer.h"

unsigned _next_power(unsigned x)
{
    --x;
    x |= x >> 0x01;
    x |= x >> 0x02;
    x |= x >> 0x04;
    x |= x >> 0x08;
    x |= x >> 0x10;
    return ++x;
}

int main(){
    // unsigned p = _next_power(9);
    unsigned x = 17;
    --x;
    x |= x >> 0x01;
    x |= x >> 0x02;
    x |= x >> 0x04;
    x |= x >> 0x08;
    x |= x >> 0x10;
    ++x;
    printf("%d\n",x);
    return 0;
}