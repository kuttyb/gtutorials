#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

void hex_to_float(uint32_t input) 
{
	float *ptr = (float *)&input;
	printf("input 0x%x output %f\n", input, *ptr);
}

int main(void) 
{
	const uint32_t input[] = 
		{
			0xfe6 
		};
	
	const uint32_t size = sizeof(input) / sizeof(input[0]);
	
	for (uint32_t i = 0; i < size; ++i) 
	{
		hex_to_float(input[i]);
	}
	
	return 0;
}
