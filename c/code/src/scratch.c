#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

int main(void) {

  void*a = calloc(1, sizeof(uint32_t));

  for( uint32_t i = (uint32_t) random(); i < 0x1000; i++) {
    printf("hehehaha\n");
  }

  free(a);

  return 0;
}

