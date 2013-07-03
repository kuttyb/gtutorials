#include <inttypes.h>
#include <assert.h>

#define lsb(m)   (m & ~(m - 1))

static inline uint32_t test_mask(uint32_t input) {
  /**
   *  For the numbers with all contigous 1's, 
   *  AND'ing with 1 subtracted, shifts the LSB left by 1 :)
   */
  uint32_t temp = input & (input - 1);
  return !temp ? 1 : lsb(temp) >> 1 == lsb(input);
}

int main(void) {  
  if (0) {
    assert(!test_mask(22));
    assert(!test_mask(11));
  }

  // Pass for powers of 2 and 0
  assert(test_mask(0));
  assert(test_mask(1));
  assert(test_mask(4));
  assert(test_mask(8));

  // Fail these
  assert(!test_mask(5));
  assert(!test_mask(10));
  assert(!test_mask(49));
  assert(!test_mask(52));
  assert(!test_mask(53));
  assert(!test_mask(0xffffffff - 2));

  // Pass these
  assert(test_mask(7));
  assert(test_mask(6));
  assert(test_mask(12));
  assert(test_mask(15));
  assert(test_mask(112));
  assert(test_mask(0xffffffff));
  assert(test_mask(0xffffffff - 1));
  
  return 1;
}

