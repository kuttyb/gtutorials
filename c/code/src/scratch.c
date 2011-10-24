#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

int main(void) {

  void*a = calloc(1, sizeof(uint32_t));

  uint32_t counter;
  while( (counter = (uint32_t)random()) < 0x1000 ) {
    printf("hehe\n");
  }

  free(a);

  return 0;
}

