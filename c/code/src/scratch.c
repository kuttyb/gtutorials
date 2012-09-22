#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

static bool
change_bbias(uint8_t oldinput, uint8_t newinput, uint8_t tolerance) {
  if (oldinput == newinput) return false;

  // make them signed
  int difference = oldinput - newinput;
  difference = difference < 0 ? difference * -1 : difference;

  if (difference > tolerance) 
    return true;
  else 
    return false;
}

int main(void) {
  assert(change_bbias(10, 20, 5));
  assert(!change_bbias(10, 20, 10));
  assert(change_bbias(10, 21, 10));
  assert(!change_bbias(10, 10, 0));

  assert(!change_bbias(20, 10, 10));
  assert(!change_bbias(20, 12, 10));
  assert(change_bbias(20, 10, 5));
  assert(change_bbias(20, 9, 10));

  return EXIT_SUCCESS;
}

