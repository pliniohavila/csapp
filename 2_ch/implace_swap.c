#include <stdio.h>

void     implace_swap(int *x, int *y)
{
  *y = *x ^ *y; // step 1
  *x = *x ^ *y; // step 2
  *y = *x ^ *y; // step 3
}

void    reverse_array(int a[], int cnt)
{
  int   first;
  int   last;

  for (first = 0, last = cnt - 1; first < last; first++, last--) {
    implace_swap(&a[first], &a[last]);
  }
}

void    print_array(int arr[], int l)
{
  for (int i = 0; i < l; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int   main(void)
{
  int   len = 6;
  int   arr[6] = {0, 1, 2, 3, 4, 6};

  printf("Before: ");
  print_array(arr, len);
  reverse_array(arr, len);
  printf("After: ");
  print_array(arr, len);

  return (0);
}