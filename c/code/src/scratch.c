#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

int main(void) {
  float f = 21.94f;
  int   x = (int)f;

  printf("%f %d\n", f, x);
  
  return EXIT_SUCCESS;
}

