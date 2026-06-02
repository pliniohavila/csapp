#include <assert.h>
#include <string.h>
#include <stdio.h>

void copy_int(int val, void *buf, int maxbytes)
{
  // sizeof return a value of type unsigned integer type

  // if ((maxbytes - (int)sizeof(val)) >= 0) {
  if (maxbytes >= sizeof(val)) {
    memcpy(buf, (void *) &val, sizeof(val));
  }
}

int main(void)
{
  int out;

  /* ---------- Espaço suficiente ---------- */

  out = 0;
  copy_int(12345, &out, sizeof(int));
  assert(out == 12345);

  /* ---------- Espaço maior ---------- */

  out = 0;
  copy_int(67890, &out, 100);
  assert(out == 67890);

  /* ---------- Sem espaço ---------- */

  out = -1;
  copy_int(555, &out, sizeof(int) - 1);
  assert(out == -1);

  /* ---------- Espaço zero ---------- */

  out = -1;
  copy_int(777, &out, 0);
  assert(out == -1);

  /* ---------- Valor negativo ---------- */

  out = 0;
  copy_int(-42, &out, sizeof(int));
  assert(out == -42);

  return 0;
}