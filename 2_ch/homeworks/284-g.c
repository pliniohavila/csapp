#include <stdio.h>

void      print_binary(int n) {
  for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
    printf("%u", (n >> i) & 1);
  }
  printf("\n");
}

int main(void)
{
  unsigned a, b;
  a = 1;
  b = 0;
  print_binary(!a);
  print_binary(!b);

  return (0);
}