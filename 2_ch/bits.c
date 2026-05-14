#include <stdio.h>

void print_binary(unsigned int n) {
  for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
    printf("%u", (n >> i) & 1);
  }
  printf("\n");
}



int   main(void)
{
  char   a = 127;
  // int   b = 10;
  // int   c = 42;

  print_binary(a);
  print_binary(a >> 4);

  return (0);
}