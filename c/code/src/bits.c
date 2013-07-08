#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

static inline uint32_t test_mask(uint32_t num) {
  /** remove trailing zeroes */
  for (; num; num>>=1) {
    if (((num >> 1) << 1) != num) break;
  }
  /** test if after adding 1 its a power of 2 :-) */
  return !((num + 1) & num);
}

static void test_masklogic(void) {  
  // Fail these (they are special in that they have > 1 contig 1s before hitting a zero  
  // followed by more 1s
  assert(!test_mask(22));
  assert(!test_mask(11));  
  assert(!test_mask(9));
  assert(!test_mask(47));
  assert(!test_mask(111));
  assert(!test_mask(188));
  assert(!test_mask(444));
  assert(!test_mask(495));
  assert(!test_mask(1980));

  // Pass for powers of 2 and 0
  assert(test_mask(0));
  assert(test_mask(1));
  assert(test_mask(4));
  assert(test_mask(8));
  assert(test_mask(16));
  assert(test_mask(32));
  assert(test_mask(64));

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
  assert(test_mask(48));
  assert(test_mask(12));
  assert(test_mask(15));
  assert(test_mask(112));
  assert(test_mask(0xffffffff));
}

int main(void) {
     test_masklogic();
     
     return 0;
}
