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

static void perlogbase(const uint32_t inlogctr, const uint32_t totalelements, const uint32_t threads) {
  const uint32_t maxelements = totalelements - 1;
  uint32_t logctr = inlogctr <= maxelements ? inlogctr : totalelements;
  uint32_t range = maxelements / (threads * logctr);
  if (!range) range = 1;
  range = range * logctr;
  printf("%s LOGCTR %d Range %d\n", __FUNCTION__, logctr, range);

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
  const uint32_t logbase     = 2;

  uint8_t stop = 0;
  for (uint32_t i = logbase; ; i*=logbase) {
    if (i >= maxelements) {
      if (stop) break;
      else stop = 1;
    }
    perlogbase(i, maxelements, threads);
  }
}

int main(void) {

  predux();

  return 0;
}

