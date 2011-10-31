#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

static inline uint32_t getlocalend(uint32_t localstart, uint32_t globalend, uint32_t bulk) {
  uint32_t localend = localstart + bulk - 1;
  if (localend > globalend) {
    return globalend; 
  } else {
    return localend;
  }
}

#define BULKFOR(start, end, bulk, localstart, localend) \
  for(localstart = start; (localstart <= end) && (localend = getlocalend(localstart, end, bulk)); \
      localstart+=bulk)

static void perlogbase(const uint32_t logctr, const uint32_t totalelements, const uint32_t threads) {
  const uint32_t maxelements = totalelements - 1;
  uint32_t range = maxelements / (threads * logctr);
  range = range * logctr;
  printf("%s range is %d\n", __FUNCTION__, range);

  uint32_t ls, le;
  uint32_t sid = 0;
  BULKFOR(0, maxelements, range, ls, le) {
    uint32_t lls, lle;
    printf("sid %d\t", sid);
    BULKFOR(ls, le, logctr, lls, lle) {
      printf("%d - %d  ", lls, lle);
    }
    printf("\n");
    sid = (sid + 1) % threads;
  }
}

static void predux() {
  const uint32_t threads     = 5;
  const uint32_t maxelements = 50;
  const uint32_t logbase     = 4;

  perlogbase(logbase, maxelements, threads);
}

int main(void) {

  predux();

  return 0;
}

