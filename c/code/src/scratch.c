#include <stdio.h>
#include <inttypes.h>
#include <assert.h>


int main(void) 
{
	const uint32_t agxk_gart_page_size = 0x1000;
	uint64_t last_va_committed = 0x0ULL;
	uint64_t virtual_address;
	uint64_t addr_loop[] = 
		{
			0x0, 0x1000, 0x2000, 0x4000,
			0x9000, 0xc000, 0xd000,
			0x12000
		};
	
	for (uint32_t i = 0; i < sizeof(addr_loop) / sizeof(addr_loop[0]); ++i)
	{
		virtual_address = addr_loop[i];
		
		if ((last_va_committed != 0x0ULL) &&
		    ((virtual_address - last_va_committed) > agxk_gart_page_size))
		{
			printf("kbb: Detected a hole between VA 0x%llx and 0x%llx -> Needs Padding\n", last_va_committed, virtual_address);	
			printf("kbb: Padding VA 0x%llx\n\n", last_va_committed + agxk_gart_page_size);			
		}
		last_va_committed = virtual_address;
	}
	
	return 0;
}
