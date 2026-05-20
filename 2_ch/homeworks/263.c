#include <stdio.h>

#define W_LENGTH 8 * sizeof(int)
#define ALL_ONES ~((int)0x0)

// 10, 2
// -10, 2
// 0xF0000000, 4
// 0, 3
// -1, 5

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

  mask = (unsigned)-1 >> k;

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
  // result = xsrl | mask;
  result = xsrl | mask;

  return (result);
}


int     main(void)
{
    int          x;
    unsigned     r1;
    int          k;

    x = 0x80000000;
    k = 31;
    printf("x: ");
    print_binary(x);
    printf("k: %d\n", k);
    r1 = srl(x, k);
    printf("Result: ");
    print_binary(r1);
    printf("Mirror: ");
    print_binary((unsigned) x >> k);

    return (0);
}