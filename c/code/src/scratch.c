#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

uint64_t get_linear_addr(uint64_t taddr, uint64_t pitch, uint64_t length,
                         uint64_t width, uint64_t height) {
  uint64_t r0, c0, r, c, addr = 0;

  // printf("%s: taddr %"PRIu64" pitch %"PRIu64" length %"PRIu64" width %"PRIu64" height %"PRIu64"\n",
  //        __FUNCTION__, taddr, pitch, length, width, height);

  // calculate row, column values for the original window of dims pitch x height
  // forget about the inner window for now
  r0 = taddr / pitch;
  c0 = taddr % pitch;
  //  printf("r0 %"PRIu64" c0 %"PRIu64"\n", r0, c0);

  r  = r0 / height;
  c  = c0 / width;
  //  printf("r %"PRIu64" c %"PRIu64"\n", r, c);

  addr =  r * (width * height) + (c * width);
  addr += r0 * width + c0;

  return addr;
}

int main(void) {
  printf("%"PRIu64"\n", get_linear_addr(3,  8, 2, 2, 2));  

  return EXIT_SUCCESS;
}
