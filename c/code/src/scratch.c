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
const uint64_t gran                 = 0x4000;

uint32_t getPadPages(uint32_t virtual_length, uint32_t * num_pad_pages)
{
  printf("virtual_length: 0x%x\n", virtual_length);
  virtual_length += agxk_gart_page_size;
  uint32_t new_length    = ALIGNGRAN(virtual_length, gran);
  *num_pad_pages         = ((new_length - virtual_length) >> agxk_gart_page_shift) + 1;

  printf("padded_length : 0x%x\naligned_length: 0x%x\nnum_pad_pages : 0x%x\n", 
	 virtual_length, new_length, *num_pad_pages);
  printf("\n\n");

  return new_length;
}

int main(void) 
{
  uint32_t       num_pad_pages;

  getPadPages(0x1000, &num_pad_pages);
  getPadPages(0x2000, &num_pad_pages);
  getPadPages(0x3000, &num_pad_pages);
  getPadPages(0x4000, &num_pad_pages);
  getPadPages(0x0, &num_pad_pages);

  return 0;
}
