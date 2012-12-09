#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

int main(void) {
  uint64_t a = 9223934988129639136UL;
  printf("num 0x%"PRIx64"\n", a);

  return EXIT_SUCCESS;
}
