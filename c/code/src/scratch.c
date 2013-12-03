#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

#define GLD_STATE2_TRANSFORM_CLIP_PLANE_MODE0      0x01000000
#define GLD_STATE2_TRANSFORM_CLIP_PLANE_MODE1      0x02000000
#define GLD_STATE2_TRANSFORM_CLIP_PLANE_MODE2      0x04000000
#define GLD_STATE2_TRANSFORM_CLIP_PLANE_MODE3      0x08000000
#define GLD_STATE2_TRANSFORM_CLIP_PLANE_MODE4      0x10000000
#define GLD_STATE2_TRANSFORM_CLIP_PLANE_MODE5      0x20000000
#define GLD_STATE2_TRANSFORM_CLIP_PLANE_MODE6      0x40000000
#define GLD_STATE2_TRANSFORM_CLIP_PLANE_MODE7      0x80000000

typedef uint16_t bitfield16_t;

int main(void) 
{
	const uint32_t bitenable = 0x2;
	for (uint32_t i = 0, mask = 1; i < 32; ++i, mask <<= 1) 
	{
		if (bitenable & mask) 
		{
			printf("kbb: ctr %d bitenable 0x%x mask 0x%x\n",
			       i, bitenable, mask);
		}
		
	}
	
	
	
	return 0;
}
