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

int main(void) {
  const uint32_t numstreams = 5;
  const uint32_t start      = 0;
  const uint32_t end        = 13;

  uint32_t       counter = 0;
  uint32_t       localstart;
  uint32_t       localend;

  BULKFOR(start, end, (end - start + 1) / numstreams, localstart, localend) {
    printf("counter %d has %d to %d\n",
	   counter, localstart, localend);
    counter = (counter + 1) % numstreams;
  }

  return 0;
}

