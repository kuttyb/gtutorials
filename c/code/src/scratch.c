#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

uint32_t fact(uint32_t n) {
  if (!n) return 1;
  if (n == 1) return 1;
  
  return n * fact(n - 1);
}

uint32_t ifact(uint32_t n) {
  if (!n) return 1;
  
  uint32_t sum = 1;
  for (uint32_t i = 1; i <= n; ++i) {
    sum *= i;
  }
  return sum;
}

int main(void) {
  printf("%d %d\n", fact(2), ifact(2));
  printf("%d %d\n", fact(1), ifact(1));
  printf("%d %d\n", fact(0), ifact(0));
  printf("%d %d\n", fact(3), ifact(3));
  printf("%d %d\n", fact(4), ifact(4));
  printf("%d %d\n", fact(5), ifact(5));



  return EXIT_SUCCESS;
}
