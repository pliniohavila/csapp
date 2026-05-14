#include <stdio.h>

typedef     unsigned char *byte_pointer;

void show_bits(unsigned char byte) {
  for (int i = 7; i >= 0; i--) {
      printf("%d", (byte >> i) & 1);
  }
}

void     implace_swap(unsigned char *x, unsigned char *y)
{
  *y = *x ^ *y; // step 1
  *x = *x ^ *y; // step 2
  *y = *x ^ *y; // step 3
}

unsigned    replace_byte(unsigned x, int i, unsigned char b)
{
  byte_pointer  word;
  size_t        len;

  word = (byte_pointer) &x;
  len = sizeof(unsigned);
  // printf("word: %s - Len: %ld\n", word, len);
  if (i < 0 || i > len)
    return x;
  
  for (int j = 0; j < len; j++) {
    printf("%.2x", word[j]);
  }

  for (int j = 0; j < len; j++) {
    if (j == i) {
      implace_swap(&word[i], &b);
    }
  }

  printf("\n");
  return x;
}

int   main(void)
{
  unsigned    x;
  unsigned    result;

  x = 0x12345678;
  // x = 0x41414141;
  unsigned char y = 0x41; // 65 A

  // printf("X: %x - Y: %c\n", x, y); // & 0xFF
  result = replace_byte(x, 0, 0xAB);
  printf("result: %x\n", result);
  return (0);
}