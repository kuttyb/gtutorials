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


 bool is_chipspecific_register(uint32_t reg_offset, const AGXChipSpecificRegisterRegion * per_chip_region, uint32_t per_chip_count,
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


int main(void) {
  const AGXChipSpecificRegisterRegion a[2] = {
    {{10, 40}, 110},
    {{60, 80}, 600}
  };

  uint32_t new_range = 0;
  bool temp = false;

  temp = is_chipspecific_register(9, a, 2, &new_range);
  assert(temp == false);
  assert(new_range == 0);

  temp = is_chipspecific_register(10, a, 2, &new_range);
  assert(temp == true);
  assert(new_range == 110);


  temp = is_chipspecific_register(11, a, 2, &new_range);
  assert(temp == true);
  assert(new_range == 111);

  temp = is_chipspecific_register(12, a, 2, &new_range);
  assert(temp == true);
  assert(new_range == 112);

  temp = is_chipspecific_register(40, a, 2, &new_range);
  assert(temp == true);
  assert(new_range == 140);

  return 0;
}
