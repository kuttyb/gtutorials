#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

uint32_t fib(uint32_t n) {
  if (!n) return 0;
  if (n == 1) return 1;

  uint32_t f0 = 0;
  uint32_t f1 = 1;
  uint32_t fn = 0;

  for (uint32_t i = 2; i <= n; ++i) {
    fn = f0 + f1;
    uint32_t t = f1;
    f1 = fn;
    f0 = t;
  }

  return fn;
}

int main(void) {
  printf("%d\n", fib(0));
  printf("%d\n", fib(1));
  printf("%d\n", fib(2));
  printf("%d\n", fib(3));
  printf("%d\n", fib(4));
  printf("%d\n", fib(5));

  return EXIT_SUCCESS;
}
