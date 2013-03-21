#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

void func(uint32_t *a, uint32_t i) {
  uint32_t *b = &a[i];
  *b = 10;
}

int main(void) {
  uint32_t a[2] = {3, 5};

  func(a, 0);
  func(a, 1);
  func(a, 2);

  printf("values are %d %d\n", a[0], a[1]);

  return EXIT_SUCCESS;
}
