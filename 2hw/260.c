#include <stdio.h>


unsigned    replace_byte(unsigned int x, int i, unsigned char b)
{
  unsigned int clear_mask;
  unsigned int mask;
  unsigned int result;

  if (i < 0 || i > 4)
    return x;
  
  clear_mask = ~((unsigned int)0xFF << (i * 8));
  result = ((unsigned char)b << (i * 8) | (x & clear_mask));

  return (result);
}

int   main(void)
{
  unsigned int    x;
  unsigned int    result;
  unsigned int    i;
  unsigned char   b;
  
  x = 0x12345678;
  i = 3;
  b = 0xAB;
  result = replace_byte(x, i, b);

  printf("Original: %08x \nResult: %08x\n", x, result);
  return (0);
}