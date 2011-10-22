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
  uint32_t localstart, localend;
  BULKFOR(3, 9, 4, localstart, localend) {
    printf("localstart %d localend %d\n", localstart, localend);
  }

  return 0;
}

