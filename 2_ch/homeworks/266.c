#include <stdio.h>
#include <assert.h>

typedef     unsigned char *word;
// typedef     unsigned char *byte_pointer;

void show_bits(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
      printf("%d", (byte >> i) & 1);
    }
}

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

void      print_binary(int n) {
  for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
    printf("%u", (n >> i) & 1);
  }
  printf("\n");
}

int     leftmost_one(unsigned x)
{
  x |= (x >> 1);
  x |= (x >> 2);
  x |= (x >> 4);
  x |= (x >> 8);
  x |= (x >> 16);
  x -= (x >> 1);
  
  return (x);
}

int     main(void)
{
  assert(leftmost_one(0xff00)==0x8000);
  assert(leftmost_one(0x6600)==0x4000);
  
  return (0);
}