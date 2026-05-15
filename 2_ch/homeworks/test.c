#include <stdio.h>


void print_binary(int n) {
  for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
    printf("%u", (n >> i) & 1);
  }
  printf("\n");
}

int     main(void)
{
    signed char     x = 0b00010101;
    // signed char     x = 149;

    printf("%d - %x - ", x, x);
    print_binary(x);
    x = x >> 4;
    printf("%d - %x - ", x, x);
    print_binary(x);
    return (0);
}