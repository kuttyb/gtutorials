#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

int main(void) {
  uint32_t a = 0x8;
  uint32_t b = 0x4;
  uint32_t c = 0x9;

  int diff1 = a - b;
  int diff2 = a - c;
  int diff3 = b - c;
  int diff4 = c - b;

  printf("%d %d %d %d\n", diff1, diff2, diff3, diff4);

  uint32_t offset = 32;
  offset = offset - (diff1);
  printf("offset %d\n", offset);

  offset = 32;
  offset = offset - (diff2);
  printf("offset %d\n", offset);

  return EXIT_SUCCESS;
}
