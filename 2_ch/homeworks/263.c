#include <stdio.h>

#define W_LENGTH sizeof(int) << 3
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

  // w = número de bits em int
  int w = sizeof(int) << 3;
  
  /*
  * Extrair o MSB (bit de sinal) de x.
  * x >> (w-1): shift aritmético propaga o sinal para todos os bits.
  * & 1: isola apenas o bit menos significativo → msb ∈ {0, 1}.
  */
  int msb = (x >> (w-1)) & 1;

  /*
  * Construção da máscara de correção: 1^k 0^(w-k)
  * Mesma técnica de divisão de shift para evitar UB.
  * Para k=0: nenhuma correção necessária → tratado via bitwise-if.
  */
  unsigned kmask_nonzero = (~0u << 1) << (w - k - 1);
  
  // Bitwise-if para k == 0: máscara de correção é 0 quando k=0
  unsigned is_k_zero = -(unsigned)!k;
  unsigned kmask = kmask_nonzero & ~is_k_zero;

  /*
  * Condicionar ao sinal:
  * -(unsigned)msb = ~0u se msb=1 (x negativo), 0 se msb=0 (x positivo).
  * correction: máscara com 1s nos k bits superiores apenas se x < 0.
  */
  unsigned correction = kmask & (-(unsigned)msb);

  return xsrl & (int)correction;
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