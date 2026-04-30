#include <stdio.h>
#include <string.h>


typedef     unsigned char *byte_pointer;

void    show_bytes(byte_pointer start, size_t len)
{
    for (int i = 0; i< len; i++) {
        printf(" %.2x", start[i]);
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

int     main(void)
{
    int     val;

    val = 123456;
    // test_bytes(val);
    char    *m = "12345\0";
    show_bytes((byte_pointer) m, strlen(m));

    return (0);
}