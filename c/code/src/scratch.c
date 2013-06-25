#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

uint64_t get_linear_addr(uint64_t taddr, uint64_t pitch, uint64_t length,
                         uint64_t width, uint64_t height) {
  uint64_t r0, c0, r, c, addr = 0;

  printf("%s: taddr %"PRIu64" pitch %"PRIu64" length %"PRIu64" width %"PRIu64" height %"PRIu64"\n",
         __FUNCTION__, taddr, pitch, length, width, height);

  // calculate row, column values for the original window of dims pitch x height
  // forget about the inner window for now
  r0 = taddr / pitch;
  c0 = taddr % pitch;
  printf("r0 %"PRIu64" c0 %"PRIu64"\n", r0, c0);

  r  = r0 / height;
  c  = c0 / width;
  printf("r %"PRIu64" c %"PRIu64"\n", r, c);

  addr =  r * (width * height) + (c * width);
  addr += r0 * width + c0;

  return addr;
}

int main(void) {
  if (0) {
  // test the first row
  printf("%"PRIu64"\n", get_linear_addr(0, 4, 4, 2, 2));
  printf("%"PRIu64"\n", get_linear_addr(1, 4, 4, 2, 2));
  printf("%"PRIu64"\n", get_linear_addr(4, 4, 4, 2, 2));
  printf("%"PRIu64"\n", get_linear_addr(5, 4, 4, 2, 2));
  }

  // test the second row
  if (0) {
  printf("%"PRIu64"\n", get_linear_addr(2, 4, 4, 2, 2));  
  printf("%"PRIu64"\n", get_linear_addr(3, 4, 4, 2, 2));  
  printf("%"PRIu64"\n", get_linear_addr(6, 4, 4, 2, 2));  
  printf("%"PRIu64"\n", get_linear_addr(7, 4, 4, 2, 2));  
  }

  if (0) {
  printf("%"PRIu64"\n", get_linear_addr(8,  4, 4, 2, 2));  
  printf("%"PRIu64"\n", get_linear_addr(9,  4, 4, 2, 2));  
  printf("%"PRIu64"\n", get_linear_addr(12, 4, 4, 2, 2));  
  printf("%"PRIu64"\n", get_linear_addr(13, 4, 4, 2, 2));  
  }

  if (1) {
  printf("%"PRIu64"\n", get_linear_addr(10,  4, 4, 2, 2));  
  printf("%"PRIu64"\n", get_linear_addr(11,  4, 4, 2, 2));  
  printf("%"PRIu64"\n", get_linear_addr(14,  4, 4, 2, 2));  
  printf("%"PRIu64"\n", get_linear_addr(15,  4, 4, 2, 2));  
  }

  return EXIT_SUCCESS;
}
