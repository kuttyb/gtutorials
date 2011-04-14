#include <stdio.h>
#include <stdlib.h>
#include "barrier.h"
#include "types.h"

#define MAX (0x1000000)

#if 0
#define  TYPE  int
#define  SET(var, value)  var = value
#define  GET(var)         ({var;})
#else
#define  TYPE  _volatile
#define  SET(var, value)  volatile_store(var, value)
#define  GET(var)         volatile_load(var)
#endif 

int main(void) {
  TYPE a;
  SET(a, 0);

  for(long counter = 0; counter < MAX; counter++) {
    if (GET(a) == 4096634) { continue;}
    SET(a, random());
  }

  printf("last value is %d\n", GET(a));

  return 1;
}

