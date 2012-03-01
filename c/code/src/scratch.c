#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

static inline unsigned long _getmask(int hi, int lo) {
  return (unsigned long)(0xffffffffUL >> (32UL - ((unsigned long)hi - (unsigned long)lo + 1UL))) << (unsigned long)lo;
}

static inline int _get(unsigned long value, int hi, int lo) {
  return ((unsigned long)value & _getmask((unsigned long)hi, (unsigned long)lo)) >> (unsigned long)lo;
}

static inline unsigned long _set(unsigned long value, int fieldvalue, int hi, int lo) {
  return ((unsigned long)value & ~_getmask((unsigned long)hi, (unsigned long)lo)) | \
    ((unsigned long)fieldvalue << (unsigned long)lo);
}

static inline unsigned long vmsapte_convert_smallpage_to_largepage(unsigned long oldpte) {
	unsigned long newpte = oldpte;

	/** copy B(0) to B(15) ; Set B(0) */
	newpte = _set(newpte, _get(oldpte, 0, 0), 15, 15);
	newpte = _set(newpte, 1, 0, 0);

	/** Reset B(1) */
	newpte = _set(newpte, 0, 1, 1);
	
	/** Move B(8-6) to B(14-12) ; Reset B(8-6) */
	newpte = _set(newpte, _get(oldpte, 8, 6), 14, 12);
	newpte = _set(newpte, 0, 8, 6);

	return newpte;
}


int main(void) {
  /** Test B0/ B15 / B1 */
  assert(vmsapte_convert_smallpage_to_largepage(2) == 0x1);
  assert(vmsapte_convert_smallpage_to_largepage(3) == 0x8001);
  assert(vmsapte_convert_smallpage_to_largepage(5) == 0x8005);
  assert(vmsapte_convert_smallpage_to_largepage(7) == 0x8005);
  assert(vmsapte_convert_smallpage_to_largepage(6) == 0x5);

  /** Test B8-B6 / B14-B12 */
  unsigned long val = 0x00c1;
  printf("0x%lx 0x%lx\n", val, vmsapte_convert_smallpage_to_largepage(val));

  val = 0xfff;
  printf("0x%lx 0x%lx\n", val, vmsapte_convert_smallpage_to_largepage(val));

  return 0;
}

