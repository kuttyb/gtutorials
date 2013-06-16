#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

uint32_t trib(uint32_t n) {
  if (!n) return 0;
  if (n == 1) return 1;
  if (n == 2) return 1;

  uint32_t f0 = 0;
  uint32_t f1 = 1;
  uint32_t f2 = 1;
  uint32_t fn = 0;

  for (uint32_t i = 3; i <= n; ++i) {
    fn = f0 + f1 + f2;
    uint32_t t1 = f2;
    uint32_t t0 = f1;
    f2 = fn;
    f1 = t1;
    f0 = t0;
  }

  return fn;
}

int main(void) {
  for (uint32_t i = 0; i < 11; ++i) {
    printf("%d\n", trib(i));
  }

  return EXIT_SUCCESS;
}
