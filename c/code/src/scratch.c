#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

#define   A   1
#define   B   1
#define   C   0

int main(void) 
{
#if C || A
  printf("speaking\n");
#endif

  return 0;
}
