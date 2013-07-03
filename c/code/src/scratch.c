#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

#define lsb(m)   (m & ~(m - 1))

static inline bool test_mask(uint32_t input) {
  if (!input) return true;
  uint32_t temp = input & (input - 1);
  if (!temp)  return true;
  return lsb(temp) >> 1 == lsb(input);
}

int main(void) {  
  assert(test_mask(8));
  assert(test_mask(7));
  assert(test_mask(0));
  assert(!test_mask(10));
  assert(test_mask(12));
  assert(test_mask(1));
  assert(test_mask(4));
  assert(!test_mask(5));

  assert(!test_mask(49));
  assert(!test_mask(52));
  assert(!test_mask(53));

  return 1;
}

