#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>


int main(void) 
{
	const uint32_t max_elements = 0x8;
	const uint32_t max_mask     = (1 << (max_elements + 1)) - 1;
	printf("max_mask 0x%x\n", max_mask);

	uint32_t mask = 0;
	uint32_t sum = 0;
	for (uint32_t increment = 3; increment && (max_mask != mask); --increment) 
	{
		for (uint32_t i = 0; i <= max_elements; i+= increment) 
		{
			const uint32_t local_mask = 1 << i;
			if (mask & local_mask) continue;
			mask |= local_mask;

			printf("\nstart index : 0x%x\n", i);			
			sum++;
			
			
			if (i) 
			{
				printf("clip_plane: index 0x%x\n", i - 1);
			}
			
			printf("stop index: 0x%x\n\n", i);
			sum++;
		}
	}

	assert(mask == max_mask);
	assert(sum == (max_elements + 1) * 2);

	return 0;
}
