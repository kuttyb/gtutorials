#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

int main(void) {
  uint32_t a = 0xaabbccdd;
 
  uint8_t *b;

  b = (uint8_t*) &a;

  printf("0x%x 0x%x 0x%x 0x%x\n",
         b[0], b[1], b[2], b[3]);

  return EXIT_SUCCESS;
}

