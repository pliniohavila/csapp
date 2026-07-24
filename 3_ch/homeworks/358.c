#include "stdio.h"

long    decode2(long x, long y, long z)
{
    long    r;

    y = y - z;
    x = x * y;
    r = y;
    r = r << 63;
    r = r >> 63;
    r = r ^ x;

    return r;
}

int     main()
{
    // should be return 105 velue
    printf("> %ld\n", decode2(10, 20, 5));
    return (0);
}