#include <stdio.h>

float   sum_elements(float a[], unsigned length)
{
    int     i;
    float   result;

    i = 0;
    result = 0;

    for (i = 0; i <= length - 1; i++) {
        result += a[i];
    }
    return (result);
}


int     main(void)
{
    // float   a[] = {1};
    // float   r;

    // r = sum_elements(a, 0);
    // printf("V: %.2f\n", r);
    unsigned int l = 0;
    l = l - 1;
    printf("V: %d\n", l);

    return (0);
}