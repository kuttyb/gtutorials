#include <stdio.h>
#include <stdlib.h>

static inline int countbits(int val) {
  int count = 0;
  for (count = 0; val; count++){
    val &= val - 1;
  }
  return count;
}

int main(void) {
  printf("testing signed numbers\n");

  printf("bitcount %d\n", countbits(3));

  signed int    a = -8;
  signed int    x = a>>1;
  signed int    y = a<<1;

  printf("%d %d\n", x, y);

  int t[] = { 3, 5, 10, 12 };
  int *v = &t[2];
  
  printf("%d %d\n", v[0], v[-1]);

  return 1;
}
