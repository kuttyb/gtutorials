#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("testing signed numbers\n");

  signed int    a = -8;
  signed int    x = a>>1;
  signed int    y = a<<1;

  printf("%d %d\n", x, y);

  return 1;
}
