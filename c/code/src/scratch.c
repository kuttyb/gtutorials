#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

typedef struct
{
	uint32_t	start;
	uint32_t	end;
} AGXRegisterRegion;

typedef struct
{
        AGXRegisterRegion  range;
        uint32_t        chipspecific_range_start;
} AGXChipSpecificRegisterRegion;


inline bool is_chipspecific_register(uint32_t reg_offset, const AGXChipSpecificRegisterRegion * per_chip_region, uint32_t per_chip_count,
                                     uint32_t *new_reg_offset)
{
  if (!(per_chip_region && new_reg_offset && per_chip_count))
  {
    return false;
  }
 
  for (int region = 0; region < per_chip_count; region++) {
    if ((per_chip_region[region].range.start <= reg_offset) && (reg_offset <= per_chip_region[region].range.end))
    {
      uint32_t diff = reg_offset - per_chip_region[region].range.start;
      *new_reg_offset = per_chip_region[region].chipspecific_range_start + diff;
      return true;
    }
  }

  return false;
}

static inline void print_region(const AGXRegisterRegion *region, uint32_t count) {
  printf("%s: region passed in starts at %p\n", 
         __FUNCTION__, region);

  for (uint32_t ctr = 0; ctr < count; ctr++) {
    printf("iteration %d: start %d end %d\n",
           ctr, region[ctr].start, region[ctr].end);
  }
}

static void testbasic(void) {
  const AGXRegisterRegion a[2] =  {
    //    .start = 10, .end = 20
    {10, 20},
    {40, 60}
  };
 
  printf("%s: address of array is %p\n", __FUNCTION__, a);
  uint32_t *ptr = (uint32_t*)a;
  printf("%s: %d %d %d %d\n", 
         __FUNCTION__, ptr[0], ptr[1], ptr[2], ptr[3]);
  

  print_region(a, sizeof(a) / sizeof(a[0]));
}

static inline bool print_stats(const AGXChipSpecificRegisterRegion *region, uint32_t count) {
  if (!(region && count)) return false;

  for(uint32_t ctr = 0; ctr < count; ctr++) {
    printf("start: %d end: %d new_range: %d\n",
           region[ctr].range.start, region[ctr].range.end, region[ctr].chipspecific_range_start);
  }

  return true;
}

static void testwholeregion(void) {
  const AGXChipSpecificRegisterRegion a[2] = {
    {{10, 40}, 110},
    {{60, 80}, 600}
  };

  print_stats(a, sizeof(a) / sizeof(a[0]));
}

int main(void) {
  if (0) testbasic();

  testwholeregion();
}
