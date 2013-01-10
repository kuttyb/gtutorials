#ifndef __allocator_h__
#define __allocator_h__

/** Memory efficient, cache friendly suballocator to be used by some of the utils libraries.
    Goals are avoid pointer chasing while searching for a free block, fit the entire metadata
    in a single 128B cacheline. Ideal for a suballocator but not a full mememory allocator.
*/
typedef struct {
  uint32_t bitmap[8];
  uint16_t base;
  uint8_t  nextfit_index;
} SLAB;

void* slab_alloc(uint32_t bytes);
void  slab_free(void *ptr, uint32_t bytes);

#endif //__allocator_h__
