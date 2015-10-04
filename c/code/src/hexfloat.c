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


void float_to_hex(float input)
{
	printf("input %f output 0x%x\n", 
	       input, *(uint32_t*)&input);
}


int main(void) 
{
#if 1
	const uint32_t input[] = 
		{
			//0x0, 0x3f800000, 0x3fafdf3b, 0x3feeb852, 0x40034396
			// 0x0, 0x3f800000, 0x3fafd567, 0x3ffa2d0e, 0x3fabc6a8
			// 0x3f800000, 0x3fafd567, 0x3ffa2d0e, 0x3fabc6a8
			//			0x3f800000, 0x3fafd567, 0x3fd205bc, 0x3ffa2d0e
			//                      0x3f800000, 0x3fafd567, 0x3fd205bc, 0x3ffa2d0e
			//			0x0, 0x3f800000, 0x3faab021, 0x3fc820c5, 0x3fe9d495
			// 0x0, 0x3f800000, 0x3fafd567, 0x3fd20c4a, 0x3ffa1cac
			//0x0, 0x3f800000, 0x3fafd567, 0x3fd205bc, 0x3ffa2d0e
			//			0x0, 0x3f800000, 0x3fafd567, 0x3fd205bc, 0x3ffa2d0e
			// 0x0, 0x3f800000, 0x3fafd567, 0x3fd205bc, 0x3ffa2d0e
		  0x0, 0x3f800000, 0x3fa70a3d, 0x3fdf7cee, 0x3ffdd2f2,
			//			0x44f07c29, 0x44e9ceb8, 0x4577019a,
			// 0x0, 0x3f800000, 0x3fafdf3b, 0x3feeb852, 0x40034396
		};
	
	const uint32_t size = sizeof(input) / sizeof(input[0]);
	
	for (uint32_t i = 0; i < size; ++i) 
	{
		hex_to_float(input[i]);
	}
#endif

#if 0
	float      x  =  2.3041f;
	uint32_t   y  =  *(uint32_t*)&x;
	float      z;
	
	*(uint32_t*)&z = y;

	printf("%f 0x%x 0x%x %f\n", x, *(uint32_t*)&x, y, z);
	
#endif	

#if 1
	printf("\n");
	const float finput[] = 
		{
			//			1923.88f, 1870.46f, 3952.1f,
			//			0.0f, 1.0f, 1.3737f, 1.6408f, 1.9545f
			// 0.0f, 1.0f, 1.374f, 1.865f, 2.051f
			// 0.0f, 1.0f, 1.3335f, 1.5635f, 1.8268f
			//0.0f, 1.0f, 1.374f, 1.865f, 2.051f
		  0.0f, 1.0f, 1.305f, 1.746f, 1.983f
		};

	for (uint32_t i = 0; i < sizeof(finput) / sizeof(finput[0]); ++i) 
	{
		float_to_hex(finput[i]);
	}
	
#endif
	return 0;
}
