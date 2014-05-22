#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

int main(void) 
{
  uint32_t a = 10;
  uint32_t b = -2;

  uint32_t c = a + b;
  printf("%d + %d = %d\n", a, b, c);

  // These will work 
  c = a - b;
  printf("%d - %d = %d\n", a, b, c);

  c = a * b;
  printf("%d * %d = %d\n", a, b, c);

  // These do not work (division and comparisons do not work)
  c = a / b;
  printf("%d / %d = %d\n", a, b, c);

  c = b / a;
  printf("%d / %d = %d\n", b, a, c);

  c = a > b;
  printf("%d > %d = %d\n", a, b, c);

  return 0;
}
