#include <stdio.h>

#define W_LENGTH 8 * sizeof(int)

void print_binary(int n) {
  for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
    printf("%u", (n >> i) & 1);
  }
  printf("\n");
}

unsigned  srl(unsigned x, int k)
{
  unsigned  xsra;

  // Perform shift arithmetically
  xsra = (int) x >> k;

  return (xsra);
}

int     sra(int x, int k)
{
  int   xsrl;

  // Perform shift logically
  xsrl = (unsigned) x >> k;

  return (xsrl);
}


int     main(void)
{
    // signed char     x = 0b00010101;
    signed char     x = 10;
    unsigned        r1;

    r1 = srl(10, 2);

    // printf("%d - %x - ", x, x);
    print_binary(10);
    print_binary(r1);
    unsigned mask = ~((unsigned int)0xFF << (W_LENGTH - 3)); // 00011111111111111111111111111111
    print_binary(mask);
    unsigned mask2 = ((unsigned int)0xFF << (W_LENGTH - 3)); // 11100000000000000000000000000000
    print_binary(mask2);
    // x = x >> 4;
    // printf("%d - %x - ", x, x);
    // print_binary(x);
    return (0);
}