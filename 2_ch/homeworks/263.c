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
  unsigned  pre_mask;
  unsigned  mask;
  unsigned  result;

  // Perform shift logically
  xsrl = (unsigned) x >> k;
  // Create a mask with shift in k
  pre_mask = (unsigned int)0xF << (W_LENGTH - k);
  // print_binary(pre_mask);
  // print_binary((unsigned int)0xF << (W_LENGTH - k));
  // print_binary((unsigned int)0xFF << (W_LENGTH - k));
  // Get MSB to know if field k shift with 0 or 1 and create a new mask with MSB
  mask = (x >> (W_LENGTH - 1)) & pre_mask;
  //Aplly mask to simulate shift arithmetically
  result = xsrl | mask;

  return (result);
}


int     main(void)
{
    int          x;
    unsigned     r1;
    int          k;

    // x = 0xF0000000;
    // k = 16;
    x = -10;
    k = 2;
    // print_binary(x);
    // r1 = sra(x, k);
    // print_binary((int)0xFF << 28);
    print_binary((int)0xF << 28);
    print_binary((int)15);
    // print_binary(r1);

    return (0);
}