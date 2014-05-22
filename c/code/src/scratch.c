#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

#define MAX(a,b) 					(((a) > (b)) ? (a) : (b))
#define MIN(a,b) 					(((a) < (b)) ? (a) : (b))

int main(void) 
{
  uint32_t transfer_output;
  uint32_t transfer_min_clamp   = (uint32_t)-260;
  uint32_t transfer_max_clamp   = 0;
  uint32_t transfer_output_base = 300; 

  float control = 0.073f;
  float transfer_gain = -13876.3f;

	transfer_output = control * transfer_gain;
	printf("transfer_min_clamp %d transfer_output %d\n", 
	       transfer_min_clamp, transfer_output);

	transfer_output = MAX((int32_t)transfer_output, (int32_t)transfer_min_clamp);
	printf("transfer_output %d\n", transfer_output);

	transfer_output = MIN((int32_t)transfer_output, (int32_t)transfer_max_clamp);
	printf("transfer_output %d\n", transfer_output);

	transfer_output = transfer_output_base + transfer_output;
	printf("transfer_output %d\n", transfer_output);

  return 0;
}
