#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

void agxsAssert(uint32_t expr)
{
  assert(expr);
}
#define ALIGNGRAN(V, G)         (({agxsAssert(ISPOT(G));}), (((V) + ((G) - 1ULL)) & ~((G) - 1ULL)))
#define ISPOT(V)                ((V) && ((V) & ((V) - 1)) == 0)


const uint32_t agxk_gart_page_size  = 0x1000;
const uint32_t agxk_gart_page_shift = 12;

static inline void do_padding(uint64_t base_address, uint32_t virtual_length, uint32_t num_pad_pages)
{
  uint64_t address = virtual_length - agxk_gart_page_size;
  for (; num_pad_pages; address -= agxk_gart_page_size, num_pad_pages--)
  {
    printf("mapping dummy page to 0x%llx\n", address);
  }
  printf("---\n");
}

static inline uint32_t getPadPages(uint32_t virtual_length, uint32_t * num_pad_pages, uint32_t cpu_page_size)
{
  printf("virtual_length: 0x%x\n", virtual_length);
  *num_pad_pages  = 1;
  virtual_length += agxk_gart_page_size;

  
  uint32_t new_length    = ALIGNGRAN(virtual_length, cpu_page_size);
  *num_pad_pages        += ((new_length - virtual_length) >> agxk_gart_page_shift);

  printf("padded_length : 0x%x\naligned_length: 0x%x\nnum_pad_pages : 0x%x\n", 
	 virtual_length, new_length, *num_pad_pages);
  printf("---\n");
  do_padding(0, new_length, *num_pad_pages);

  printf("\n\n");
  return new_length;
}

int main(void) 
{
  uint32_t       num_pad_pages;
  //const uint32_t page_size = 0x1000;
  const uint32_t page_size = 0x4000;

#if 1
  // POT sizes
  getPadPages(0x1000, &num_pad_pages, page_size);
  getPadPages(0x2000, &num_pad_pages, page_size);
  getPadPages(0x3000, &num_pad_pages, page_size);
  getPadPages(0x4000, &num_pad_pages, page_size);
  getPadPages(0x0,    &num_pad_pages, page_size);
#endif

#if 1
  // NPOT sizes
  getPadPages(0x50,   &num_pad_pages, page_size);
  getPadPages(0x1050, &num_pad_pages, page_size);
  getPadPages(0x2050, &num_pad_pages, page_size);
  getPadPages(0x3050, &num_pad_pages, page_size);
  getPadPages(0x4050, &num_pad_pages, page_size);
#endif

  return 0;
}
