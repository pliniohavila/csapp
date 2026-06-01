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

int     rotate_left(unsigned x, int n)
{
  int     to_rotate;

  // Extract bits to left rotate
  to_rotate = (~(~0u >> n)) & x;
  to_rotate = to_rotate >> ((sizeof(int) << 8) - n);

  // Shift x to cretate space to rotate
  x = x << n;
  
  return (x | to_rotate);
}

int     main(void)
{
  unsigned     x;
  int          n;

  x = 0x12345678;
  n = 0;
  int r = rotate_left(x, n);

  printf("%x\n", x);
  printf("%x\n", r);
  print_binary(r);

  assert(rotate_left(x, 4) == 0x23456781);
  assert(rotate_left(x, 20) == 0x67812345);
  
  return (0);
}