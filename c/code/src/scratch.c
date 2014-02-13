#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

static void dump_program(const uint32_t * ptr, uint32_t datasize, uint32_t codesize)
{
	printf("kbb: ProgramPtr %p DataSize 0x%x CodeSize 0x%x\n", ptr, datasize, codesize);
	
	// print datasegment
	printf("kbb: Data Segment:\n");
	const uint32_t data_elements = datasize / 4;
	for (uint32_t i = 0; i < data_elements; ++i)
	{
		printf("\t\tData[0x%x] : 0x%x\n", i, ptr[i]);
	}
	
	// print codesegment
	printf("kbb: Code Segment:\n");
	const uint32_t code_elements = codesize / 4;
	for (uint32_t i = 0; i < code_elements; ++i)
	{
		printf("\t\tCode[0x%x] : 0x%x\n", i, ptr[data_elements + i]);
	}
}
	

int main(void) 
{
	const uint32_t a[] = 
		{
			0xa, 0xb, 0xc, 0xd,
			0xe, 0xf, 0xa, 0xb,
			0xc
		};
	const uint32_t data_elements = 4 * sizeof(uint32_t);
	const uint32_t code_elements = 5 * sizeof(uint32_t);

	dump_program(a, data_elements, code_elements);
	
	return 0;
}
