#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>


int main(void) 
{
	const uint32_t max_elements = 0x5;
	const uint32_t max_mask     = (1 << max_elements) - 1;
	printf("max_mask 0x%x\n", max_mask);

	bool bzero = false;
	for (uint32_t increment = 3, mask = 0; increment && (max_mask != mask); --increment) 
	{
		for (uint32_t i = 0; i <= max_elements; i+= increment) 
		{
			if (!i && bzero) continue;
			bzero = true;
			
			if (i) 
			{
				const uint32_t j = i - 1;
				const uint32_t local_mask = 1 << j;
				if (mask & local_mask) continue;
				mask |= local_mask;
			}
			
			printf("increment 0x%x: index 0x%x mask 0x%x\n", increment, i, mask);
		}
	}

	return 0;
}
