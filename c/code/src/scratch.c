#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>


int main(void) 
{
  uint32_t a = 0;
  while (a < 10)
    {
      uint32_t result = a % 5;
      a++;
      switch( result ) {
      case 0:
	printf("divisible by 5\n"); continue;
	break;
	
      case 1:
	printf("not divisible by 5\n");
	break;
      }

      printf("post switch case\n");
    }
  printf("post loop\n");

  return 0;
}
