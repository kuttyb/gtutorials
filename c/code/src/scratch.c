#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

uint64_t get_linear_addr(uint64_t taddr, uint64_t pitch, uint64_t length,
                         uint64_t width, uint64_t height) {
  uint64_t r0, c0, r, c, addr = 0;

  return addr;
}

int main(void) {
  printf("%"PRIu64"\n", get_linear_addr(65568, 65536, 65536, 64, 64));

  return EXIT_SUCCESS;
}
