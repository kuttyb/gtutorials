#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

static inline uint32_t getlocalend(uint32_t localstart, uint32_t globalend, uint32_t bulk) {
  uint32_t localend = localstart + bulk - 1;
  printf("localstart %d globalend %d bulk %d\n", localstart, globalend, bulk);
  if (localend > globalend) {
    printf("returning %d\n", globalend);
    return globalend; 
  } else {
    printf("returning %d\n", localend);
    return localend;
  }
}

#define BULKFOR(start, end, bulk, localstart, localend) \
  for(localstart = start; (localstart <= end) && ((localend = getlocalend(localstart, end, bulk)) <= end); \
      localstart+=bulk)

int main(void) {
  uint32_t localstart, localend;

  BULKFOR(1, 1, 1, localstart, localend) {
    printf("printing %d %d\n", localstart, localend);
  }

  return 0;
}

