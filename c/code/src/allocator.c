#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>
#include "allocator.h"

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

static inline void set_bit(SLAB *slab, uint16_t start_unit, uint16_t units) {
}

static inline void reset_bit(SLAB *slab, uint16_t start_unit, uint16_t units){
}

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
    reset_bit(slab, slab->nextfit_index, units);
    ptr += slab->nextfit_index << 8;
  } else {
    ptr = slab->base << 20;
    reset_bit(slab, slab->nextfit_index, units);
    ptr += slab->nextfit_index << 12;
  }
  return (void*) ptr;
}

void* slab_alloc(uint32_t bytes) {
  SLAB *slab;
  bool issmallslab;
  uint16_t units;

  if (bytes < 4096) {
    slab = &small_slab[0];
    issmallslab = true;
    units = bytes >> 8;
    if (((bytes >> 8) << 8) != bytes) units++;
  } else if (bytes < 65536) {
    slab = &large_slab;
    issmallslab = false;
    units = bytes >> 12;
    if (((bytes >> 8) << 12) != bytes) units++;
  } else {
    printf("%d bytes exceeds block size that our allocator can allocate\n",
           bytes);
    assert(0);
    return NULL;
  }
  return slab_alloc_nextfit(slab, units, issmallslab);
}

void slab_free(void *ptr, uint32_t bytes) {
  assert(ptr);
  // locate the slab
  SLAB *slab;
  uint16_t units;
  uint16_t start_unit;

  if (bytes < 4096) {
    slab = &small_slab[0];
    units = bytes >> 8;
    if (((bytes >> 8) << 8) != bytes) units++;
    start_unit = (uint16_t)((uintptr_t)ptr >> 8);
  } else if (bytes < 65536) {
    slab = &large_slab;
    units = bytes >> 12;
    if (((bytes >> 8) << 12) != bytes) units++;
    start_unit = (uint16_t)((uintptr_t)ptr >> 12);
  } else {
    assert(0);
  }

  set_bit(slab, start_unit, units);
}

int main(void) {
  
  return EXIT_SUCCESS;
}
