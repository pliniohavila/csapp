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
  unsigned  mask;
  unsigned  result;

  // Perform shift arithmetically
  xsra = (int) x >> k;

  // Create a mask with shift in k
  mask = ~((unsigned int)0xFF << (W_LENGTH - k));
  //Aplly mask to simulate shift logically
  result = xsra & mask;

  return (result);
}

int     sra(int x, int k)
{
  int       xsrl;
  unsigned  mask;
  unsigned  result;

  // Perform shift logically
  xsrl = (unsigned) x >> k;
  // Create a mask with shift in k
  // mask = ((unsigned int)0xFF << (W_LENGTH - k));
  mask = x >> 31;
  print_binary(mask);
  //Aplly mask to simulate shift logically
  unsigned msb = (x >> (W_LENGTH - 1)) & ((unsigned int)0xFF << (W_LENGTH - 31));
  // print_binary(msb);
  // result = xsrl | mask;

  return (result);
}


int     main(void)
{
    int          x;
    unsigned     r1;
    int          k;

    // x = 0xF0000000;
    // k = 4;
    x = -10;
    k = 2;
    print_binary(x);
    r1 = sra(x, k);
    // print_binary(r1);
    return (0);
}