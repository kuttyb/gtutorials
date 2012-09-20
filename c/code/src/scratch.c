#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

#define CONVERGE_MAX   (5)
static uint8_t
converge(uint8_t anchor, uint32_t movable, uint32_t iterations) {
  const uint32_t maxiterations = iterations > CONVERGE_MAX ? CONVERGE_MAX : iterations;
  uint32_t i;

  for (i = 0; i < maxiterations && anchor != movable; ++i) {
    movable = (anchor + movable) / 2;
  }

  return movable;
}

int main(void) {
  assert(converge(20, 40, 6) == 20);
  assert(converge(20, 40, 5) == 20);
  assert(converge(20, 40, 2) == 25);
  assert(converge(20, 40, 3) == 22);
  return 0;
}

