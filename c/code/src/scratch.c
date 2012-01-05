#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

int main(void) {
  uint32_t comp = 2;
  uint32_t t0 = 0;
  uint32_t t1 = 2;
  uint32_t t2 = 2;

  for (uint32_t ctr = 0; ctr < 4; ctr++) {
    t2 = t2 + 0x40;

    if (1) {
      t2 = t2 + 0x9000;
    }

    t0 = t0 + t1 + t2 + comp;
  }

  t1 = t1 + 0x100;
  t2 = t2 + 0x200;

  printf("t0 0x%x t1 0x%x t2 0x%x\n", t0, t1, t2);

  return 0;
}

