#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

#define ALIGNGRAN(V, G)         (({assert(ISPOT(G));}), (((V) + ((G) - 1ULL)) & ~((G) - 1ULL)))
#define ISPOT(V)                ((V) && ((V) & ((V) - 1)) == 0)
	

int main(void) 
{
  const uint32_t x = 0x4;
  const uint32_t a = 0x1000;

  printf("0x%x 0x%llx\n", x, ALIGNGRAN(x, a));

  return 0;
}
