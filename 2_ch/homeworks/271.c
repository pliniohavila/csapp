#include <stdio.h>
#include <assert.h>

typedef unsigned packed_t;

void      print_binary(int n) {
  for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
    printf("%u", (n >> i) & 1);
  }
  printf("\n");
}

void show_bits(unsigned char byte) {
  for (int i = 7; i >= 0; i--) {
    printf("%d", (byte >> i) & 1);
  }
}

typedef     unsigned char *word;
void    show_bytes(word start, size_t len)
{
  for (int i = 0; i< len; i++) {
    printf("%.2x ", start[i]);
  }

  printf(" ");

  for (int i = 0; i < len; i++) {
    printf(" ");
    show_bits(start[i]);
  }

  printf("\n");
}


int xbyte(packed_t word, int bytenum)
{
  int   extracted;
  int   msb_extracted;
  int   mask;

  // Extract the byte choosed 
  extracted = (word >> (bytenum << 3)) & 0xFF;

  // Isolates the most significative bit from byte extracted
  msb_extracted = extracted >> 7;

  // Create mask to assign singnal
  mask = (~0xFF) & (-!!msb_extracted);

  return (extracted | mask);
}

int main(void)
{
    /* ---------- Casos básicos positivos ---------- */

    /* bytes = [0x12, 0x34, 0x56, 0x78] */
    packed_t w1 = 0x78563412;

    assert(xbyte(w1, 0) == 0x12);
    assert(xbyte(w1, 1) == 0x34);
    assert(xbyte(w1, 2) == 0x56);
    assert(xbyte(w1, 3) == 0x78);

    /* ---------- Sign extension ---------- */

    /* byte 0 = 0xFF (-1) */
    assert(xbyte(0x000000FF, 0) == -1);

    /* byte 0 = 0x80 (-128) */
    assert(xbyte(0x00000080, 0) == -128);

    /* byte 0 = 0x81 (-127) */
    assert(xbyte(0x00000081, 0) == -127);

    /* byte 0 = 0x7F (+127) */
    assert(xbyte(0x0000007F, 0) == 127);

    /* ---------- Testando bytes diferentes ---------- */

    /* bytes = [0x80, 0x7F, 0xFF, 0x01] */
    packed_t w2 = 0x01FF7F80;

    assert(xbyte(w2, 0) == -128); /* 0x80 */
    assert(xbyte(w2, 1) == 127);  /* 0x7F */
    assert(xbyte(w2, 2) == -1);   /* 0xFF */
    assert(xbyte(w2, 3) == 1);    /* 0x01 */

    /* ---------- Todos negativos ---------- */

    packed_t w3 = 0x80808080;

    assert(xbyte(w3, 0) == -128);
    assert(xbyte(w3, 1) == -128);
    assert(xbyte(w3, 2) == -128);
    assert(xbyte(w3, 3) == -128);

    /* ---------- Todos -1 ---------- */

    packed_t w4 = 0xFFFFFFFF;

    assert(xbyte(w4, 0) == -1);
    assert(xbyte(w4, 1) == -1);
    assert(xbyte(w4, 2) == -1);
    assert(xbyte(w4, 3) == -1);

    return 0;
}