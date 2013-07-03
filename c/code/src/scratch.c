#include <inttypes.h>
#include <assert.h>

#define lsb(m)   (m & ~(m - 1))

static inline uint32_t test_m(uint32_t input) {
  uint32_t temp = input & (input - 1);
  return !temp ? 1 : lsb(temp) >> 1 == lsb(input);
}

static inline uint32_t test_mask(uint32_t input) {
  for (; input; input>>=1) {
    /** Consider the format 
           A1 - X - A0
        where A1 and A0 are 1s and X is the 0s.
        test_m() only works if len(A0) == 1.
        So this loop will run for len(A0) num
        of times.

        The other obvious solution to this problem is
        hi = MSB(x); lo = MSB(LSB(x);
        mask = ((1 << (hi - lo + 1)) - 1) << lo
        return mask & input
        The MSB part here will loop over len(A1 + X + A0)
        
        This solution one takes a much shorter loop length */
    if (!test_m(input)) return 0;
  }
  return 1;
}

int main(void) {  
  // Fail these (they are special in that they
  // have > 1 contig 1s before hitting a zero
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

