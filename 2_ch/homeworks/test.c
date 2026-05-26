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
    int w = sizeof(int) << 3;

    print_binary(-(unsigned)!0);
    // print_binary(1);
    return (0);
}