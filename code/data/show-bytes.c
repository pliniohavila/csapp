#include <stdio.h>
#include <string.h>


typedef     unsigned char *byte_pointer;

void show_bits(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
}

void    show_bytes(byte_pointer start, size_t len)
{
    for (int i = 0; i< len; i++) {
        printf(" %.2x", start[i]);
    }

    printf(" ");

    for (int i = 0; i < len; i++) {
        printf(" ");
        show_bits(start[i]);
    }

    printf("\n");
}

void    show_int(int x)
{
    printf("value: %d ", x);
    show_bytes((byte_pointer) &x, sizeof(int));
}

void    show_float(float x)
{
    printf("value: %f ", x);
    show_bytes((byte_pointer) &x, sizeof(float));
}

void    show_pointer(void *x)
{
    printf("value: %p ", x);
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void    test_bytes(int val)
{
    int     ival;
    float   fval;
    int     *pval;

    ival = val;
    fval = (float) val;
    pval = &val;
    
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int     fun1(unsigned word) 
{
    return (int) ((word << 24) >> 24);
}

int     fun2(unsigned word)
{
    return ((int) word << 24) >> 24;
}

int     main(void)
{
    int     x = 53191;
    short   sx = (short) x;
    int     y = sx;

    show_int(x);
    show_int(sx);
    show_int(y);

    return (0);
}