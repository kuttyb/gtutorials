#ifndef __allocator_h__
#define __allocator_h__

typedef struct {
  uint32_t bitmap[8];
  uint16_t base;
  uint8_t  nextfit_index;
} SLAB;

void* slab_alloc(SLAB *slab, uint16_t units, bool issmallslab);

#endif //__allocator_h__
