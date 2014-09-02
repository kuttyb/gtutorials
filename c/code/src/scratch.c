#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

#define BIT(b) (1UL << b)

/* Performance state register definitions */
#define GPC_VCM_PERFORMANCE_STATE_CONTROL   0x001000
#define GPC_VCM_PERFORMANCE_NEXT_STATE      0x001004
#define GPC_VCM_PERFORMANCE_STATE_REQ_BIT   BIT(4)
#define GPC_VCM_PERFORMANCE_STATE_PID_MASK  0xf


void agfPollGPCReg(uint32_t reg, uint32_t value, uint32_t mask)
{
	printf("waiting for value 0x%x mask 0x%x\n",
	       value, mask);
#if 0
	while (value != (agfReadGPCReg(reg) & mask))
	{
		if (!max_tries--)
		{
			agfPrintf("ERROR: Timedout in GPC poll\n");			
			max_tries = 100;
		}
	}
#endif
}


void agfSetGPCPerformanceState(uint32_t type, uint32_t sync)
{
	/* Make sure the REQ bit is cleared */
	agfPollGPCReg(GPC_VCM_PERFORMANCE_STATE_CONTROL, 0, GPC_VCM_PERFORMANCE_STATE_REQ_BIT);

	
	/* Make sure we've reached our desired performance state */
	agfPollGPCReg(GPC_VCM_PERFORMANCE_STATE_CONTROL, type,
		      (GPC_VCM_PERFORMANCE_STATE_REQ_BIT | GPC_VCM_PERFORMANCE_STATE_PID_MASK));
}


int main(void) 
{
	agfSetGPCPerformanceState(2, 2);
	
	return 0;
}
