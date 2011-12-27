#include <stdio.h>
#include <inttypes.h>
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

/** Iterate over the range start-end both inclusive in bulk if possible */ 
#define BULKFOR(start, end, bulk, localstart, localend) \
  for(localstart = start; (bulk > 0) && (localstart <= end) && ((localend = getlocalend(localstart, end, bulk)) || 1); \
      localstart+=bulk)

int main(void) {
  uint32_t localstart, localend;
  
  BULKFOR(2, 2, 2, localstart, localend) {
    printf("localstart %d localend %d size %d\n",
	   localstart, localend, localend - localstart + 1);
  }

  return 0;
}

