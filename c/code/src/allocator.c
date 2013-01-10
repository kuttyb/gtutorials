#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

typedef struct {
  uint32_t bitmap[8];
  uint32_t base:16;
} SLAB;

/** TODO: alloc intra slab growth/shrink */
SLAB small_slab[2];
SLAB large_slab;

int main(void) {
  
  return EXIT_SUCCESS;
}
