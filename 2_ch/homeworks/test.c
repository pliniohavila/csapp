#include <stdio.h>

typedef unsigned char *word;

void print_binary(int n) {
  for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
    printf("%u", (n >> i) & 1);
  }
  printf("\n");
}

int     main(void)
{
    int             x;
    unsigned char   vector;
    
    x = 0xFF00;
    vector = (word) &x;

    print_binary(x);
    print_binary(vector);
    
    return (0);
}