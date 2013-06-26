#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

uint64_t get_linear_addr(uint64_t taddr, uint64_t pitch, uint64_t   length,
                         uint64_t width, uint64_t height, uint64_t *offset) {
  uint64_t r0, c0, r, c;

  // Calculate row, column within outer Tile
  r0 = taddr / pitch;
  c0 = taddr % pitch;

  // Calculate which SubTile it belongs to
  r  = r0 / height;
  c  = c0 / width;
  
  uint64_t start_addr = ((width * height) * (pitch / width) * r) + (c * (width * height));

  uint64_t r3 = r0 % height;
  uint64_t c3 = c0 % width;
  uint64_t off = r3 * width + c3;
  if (offset) *offset = off;
  return start_addr + off;
}

//
// To apply recursively for nested tiles, do 
//    addr = get_linear_addr(oldaddr, ....., &offset);
//    new_offset = get_linear_addr(offset, ...., NULL);
//    real_offset = addr - offset + new_offset;
// Do this recursively as many times as required!
//
int main(void) {
  uint64_t temp;
  assert(get_linear_addr(12, 8, 2, 2, 2, &temp) == 10);

  // 8 x 4 -> 4 x 2
  assert(get_linear_addr(10, 8, 4, 4, 2, &temp) == 6);
  assert(get_linear_addr(8, 8, 4, 4, 2, &temp) == 4);
  assert(get_linear_addr(9, 8, 4, 4, 2, &temp) == 5);

  // 8 x 2 -> 2 x 2
  assert(get_linear_addr(8, 8, 2, 2, 2, &temp) == 2);
  assert(get_linear_addr(9, 8, 2, 2, 2, &temp) == 3);
  assert(get_linear_addr(5, 8, 2, 2, 2, &temp) == 9);
  assert(get_linear_addr(10, 8, 2, 2, 2, &temp) == 6);

  // 4 * 4 -> 2 * 2
  assert(get_linear_addr(2, 4, 4, 2, 2, &temp) == 4);
  assert(get_linear_addr(3, 4, 4, 2, 2, &temp) == 5);
  assert(get_linear_addr(6, 4, 4, 2, 2, &temp) == 6);
  assert(get_linear_addr(7, 4, 4, 2, 2, &temp) == 7);

  assert(get_linear_addr(8, 4, 4, 2, 2, &temp) == 8);
  assert(get_linear_addr(9, 4, 4, 2, 2, &temp) == 9);
  assert(get_linear_addr(12, 4, 4, 2, 2, &temp) == 10);
  assert(get_linear_addr(13, 4, 4, 2, 2, &temp) == 11);

  assert(get_linear_addr(10, 4, 4, 2, 2, &temp) == 12);   assert(temp == 0);
  assert(get_linear_addr(11, 4, 4, 2, 2, &temp) == 13);   assert(temp == 1);
  assert(get_linear_addr(14, 4, 4, 2, 2, &temp) == 14);   assert(temp == 2);
  assert(get_linear_addr(15, 4, 4, 2, 2, &temp) == 15);   assert(temp == 3);
  
  // 8 x 2 -> 2 x 2
  assert(get_linear_addr(0 , 8, 2, 2, 2, &temp) == 0);   assert(temp == 0);
  assert(get_linear_addr(1 , 8, 2, 2, 2, &temp) == 1);   assert(temp == 1);
  assert(get_linear_addr(8 , 8, 2, 2, 2, &temp) == 2);   assert(temp == 2);
  assert(get_linear_addr(9 , 8, 2, 2, 2, &temp) == 3);   assert(temp == 3);

  assert(get_linear_addr(4 , 8, 2, 2, 2, &temp) == 8);   assert(temp == 0);
  assert(get_linear_addr(5 , 8, 2, 2, 2, &temp) == 9);   assert(temp == 1);
  assert(get_linear_addr(12 , 8, 2, 2, 2, &temp) == 10); assert(temp == 2);
  assert(get_linear_addr(13 , 8, 2, 2, 2, &temp) == 11); assert(temp == 3);

  return EXIT_SUCCESS;
}
