#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

int main(void) {
  float a = 2.341234f;
  
  printf("%f %e\n",
         a, a);

  return EXIT_SUCCESS;
}

