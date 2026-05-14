#include <stdio.h>


int     main(void)
{
    unsigned int     x;
    unsigned char    *y;

    x = 001;
    y = (unsigned char*)&x;
    
    // printf("INT: %d - CHAR: %s\n", x, y);
    if (*y == 1)
        return (0); // Little Endian x = 100 = 001 - x = 001 = 100
    return (1);     // Big Endian
}