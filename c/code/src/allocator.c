#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

typedef struct {
  uint32_t bitmap[8];
  uint16_t base;
  uint8_t  nextfit_index;
} SLAB;

/** TODO: implement an array to store freed blocks, when array fills up 
    update SLAB with information. If SLAB does not have hte block you are
    looking for, search this array. Which also means array should be addr
    sorted */
SLAB small_slab[2];
SLAB large_slab;

// please don't test on x86_64, stick to 32bit
#define X86_TEST

#ifdef X86_TEST 
static inline uint16_t alloc_mem(bool issmallslab) {
  uintptr_t ptr;
  if (issmallslab) {
    ptr = (uintptr_t) calloc(64 * 1024, 1);
  } else {
    ptr = (uintptr_t) calloc(1024 * 1024, 1);
  }
  return (uint16_t)ptr;
}
#else // MTS Logic here

#endif

// TODO if this returns NULL go scan freelist cache for recently freed blocks before
// giving up (thats the price you pay for NEXTFIT)
// small has base 64K aligned and large has base 1MB aligned. This logic is hardcoded 
// and I don't see this changing for the purpose of our allocator.
static inline void* slab_alloc_nextfit(SLAB *slab, uint16_t units, bool issmallslab) {
  if (!slab->base) {
    slab->base = alloc_mem(issmallslab);
    assert(slab->base);
  }

  if (slab->nextfit_index + units >= 256) {
    return NULL;
  } 
  slab->nextfit_index += units;
  
  uintptr_t ptr;
  if (issmallslab) {
    ptr = slab->base << 16;
    ptr += slab->nextfit_index << 8;
  } else {
    ptr = slab->base << 20;
    ptr += slab->nextfit_index << 12;
  }
  return (void*) ptr;
}

int main(void) {
  
  return EXIT_SUCCESS;
}
