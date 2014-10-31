#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

void agxsAssert(uint32_t expr)
{
  assert(expr);
}

#define ALIGNGRAN_NPOT(V, G)    (((V) + (G) - 1ULL) - (((V) + (G) - 1ULL) % (G)))
#define ALIGNGRAN(V, G)         (({agxsAssert(ISPOT(G));}), (((V) + ((G) - 1ULL)) & ~((G) - 1ULL)))
#define ALIGNDIFF(V, G)         (((V) + ((G) - 1ULL)) / (G))
#define PADGRAN(V, G)           (ALIGNGRAN((V), (G)) - (V))
#define ALIGNSIZE(V, S)         (((V) + ((1U << (S)) - 1)) & ~((1U << (S)) - 1))
#define ALIGNFIELD(V, S)        (((V) + ((1 << (S)) - 1)) >> (S))
#define ISPOT(V)                ((V) && ((V) & ((V) - 1)) == 0)
#define IS_ALIGNED_TO_POT(V, A) (({agxsAssert(ISPOT(A));}), !((V) & ((A) - 1)))

const uint32_t agxk_gart_page_size  = 0x1000;
const uint32_t agxk_gart_page_shift = 12;


uint32_t getPadPages(uint32_t virtual_length, uint32_t * num_pad_pages, uint32_t cpu_page_size)
{
  printf("virtual_length: 0x%x\n", virtual_length);
  *num_pad_pages  = 1;
  virtual_length += agxk_gart_page_size;

  
  uint32_t new_length    = ALIGNGRAN(virtual_length, cpu_page_size);
  *num_pad_pages        += ((new_length - virtual_length) >> agxk_gart_page_shift);

  printf("padded_length : 0x%x\naligned_length: 0x%x\nnum_pad_pages : 0x%x\n", 
	 virtual_length, new_length, *num_pad_pages);
  printf("\n\n");

  return new_length;
}

int main(void) 
{
  uint32_t       num_pad_pages;
  const uint32_t small_page_size = 0x1000;
  const uint32_t large_page_size = 0x4000;

#if 0
  // POT sizes
  getPadPages(0x1000, &num_pad_pages, small_page_size);
  getPadPages(0x2000, &num_pad_pages, small_page_size);
  getPadPages(0x3000, &num_pad_pages, small_page_size);
  getPadPages(0x4000, &num_pad_pages, small_page_size);
  getPadPages(0x0,    &num_pad_pages, small_page_size);
#endif

#if 1
  // NPOT sizes
  getPadPages(0x50,   &num_pad_pages, small_page_size);
  getPadPages(0x1050, &num_pad_pages, small_page_size);
  getPadPages(0x2050, &num_pad_pages, small_page_size);
  getPadPages(0x3050, &num_pad_pages, small_page_size);
  getPadPages(0x4050, &num_pad_pages, small_page_size);
#endif

  return 0;
}
