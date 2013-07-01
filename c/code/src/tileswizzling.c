#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

/** Conclusions: (VERY IMPORTANT, PLEASE READ!!)
    -----------
    [a] To go from pitch to tiled use pitch_to_tiled below
    
    [b] To go from tiled to pitch again, apply the same function 
        below with exactly the same arguments and you'll get your
        old form back :) See examples/tests below

    [c] To get a transpose of a matrix, apply a special Tile of 
        dimensions mx1 on a mxn matrix. To get the original back
        apply the same function back but with different arguments.
        Essentially now you have a nxm matrix with 1xn Tile.
        So feed this back and you'll get it back.

    [d] TODO: Write an in place-swizzler

    [e] TODO: Write a burst routine for out-of-place blit
        between different Surface formats
*/

/** THR: (To Help Remember)
    r  =  a / p
    c  =  a % p

    r1 =  r / h
    c1 =  c / w
                  saddr  =  [(w.h) x (p / w) x r1] + w.h.c1
    r2 =  r % h
    c2 =  c % w
                  offset =  r2.w + c2
    -------------------------------------------------------
    This is to get from Pitch to Tiled Format
*/
uint64_t pitch_to_tiled(uint64_t taddr, uint64_t pitch, uint64_t   length,
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

static void tile_to_pitch_to_back(void) {
  uint64_t temp;

  // 4x2, 2x2
  printf("going from pitch to tiled memory\n");
  const uint64_t p[4] = {4, 2, 2, 2};
  for (uint64_t i = 0; i < 8; ++i) {
    printf("original offset %ld new offset %ld\n",
           i, pitch_to_tiled(i, p[0], p[1], p[2], p[3], &temp));
  }

  printf("going from tiled to pitch memory\n");
  const uint64_t input[8] = {
    0, 1, 4, 5, 2, 3, 6, 7
    //    0, 2, 4, 6, 1, 3, 5, 7
  };
  for (uint64_t i = 0; i < 8; ++i) {
    printf("original offset %ld new offset %ld\n",
           input[i], 
           pitch_to_tiled(input[i], p[0], p[1], p[2], p[3], &temp));

  }
}

static inline void printmatrix(uint32_t *mat, uint32_t r, uint32_t c) {
  printf("printing matrix ...\n");
  for (uint32_t i = 0; i < r; ++i) {
    for (uint32_t j = 0; j < c; ++j) {
      printf("%d\t", *(mat + (i * c) + j));
    }
    printf("\n");
  }
}

static void matrix_transpose_using_tiling(void) {
  uint64_t temp;

  const uint32_t input[6] = { 0, 1, 2, 3, 4, 5 };
  uint32_t op[6];
  uint32_t op2[6];

  printmatrix((uint32_t*)input, 2, 3);

  // Matrix transpose using Tiling (remember mxn matrix, transpose is a tiled
  // surface of tile dims 1xm)
  printf("doing a transpose\n");
  uint64_t addr;
  for (uint64_t i = 0; i < 6; ++i) {    
    addr = pitch_to_tiled(i, 3, 2, 1, 2, &temp);
    op[addr] = input[i];
  }
  printmatrix((uint32_t*)op, 3, 2);

  printf("reverting transpose\n");
  for (uint64_t i = 0; i < 6; ++i) {
    addr = pitch_to_tiled(i, 2, 3, 1, 3, &temp);
    op2[addr] = op[i];
  }
  printmatrix((uint32_t*)op2, 2, 3);
}

static void tile_to_pitch_to_back_nonsquare_nontranspose(void) {
  uint64_t temp;

  // 4x8, 2x4
  printf("going from pitch to tiled memory\n");
  const uint64_t p[4] = {8, 4, 4, 2};
  uint32_t input[32];
  for (uint64_t i = 0; i < 32; ++i) {
    uint64_t addr = pitch_to_tiled(i, p[0], p[1], p[2], p[3], &temp);
    input[i] = (uint32_t)addr;
  }

  printmatrix((uint32_t*)input, 4, 8);

  uint32_t output[32];
  printf("going from tiled to pitch memory\n");
  for (uint64_t i = 0; i < 32; ++i) {
    output[i] = (uint32_t)pitch_to_tiled(input[i], p[0], p[1], p[2], p[3], &temp);
  }
  printmatrix((uint32_t*)output, 4, 8);
}

//
// To apply recursively for nested tiles, do 
//    addr = pitch_to_tiled(oldaddr, ....., &offset);
//    new_offset = pitch_to_tiled(offset, ...., NULL);
//    real_offset = addr - offset + new_offset;
// Do this recursively as many times as required!
//
int main(void) {
  uint64_t temp;

  if (0) {
  assert(pitch_to_tiled(12, 8, 2, 2, 2, &temp) == 10);

  // 8 x 4 -> 4 x 2
  assert(pitch_to_tiled(10, 8, 4, 4, 2, &temp) == 6);
  assert(pitch_to_tiled(8, 8, 4, 4, 2, &temp) == 4);
  assert(pitch_to_tiled(9, 8, 4, 4, 2, &temp) == 5);

  // 8 x 2 -> 2 x 2
  assert(pitch_to_tiled(8, 8, 2, 2, 2, &temp) == 2);
  assert(pitch_to_tiled(9, 8, 2, 2, 2, &temp) == 3);
  assert(pitch_to_tiled(5, 8, 2, 2, 2, &temp) == 9);
  assert(pitch_to_tiled(10, 8, 2, 2, 2, &temp) == 6);

  // 4 * 4 -> 2 * 2
  assert(pitch_to_tiled(2, 4, 4, 2, 2, &temp) == 4);
  assert(pitch_to_tiled(3, 4, 4, 2, 2, &temp) == 5);
  assert(pitch_to_tiled(6, 4, 4, 2, 2, &temp) == 6);
  assert(pitch_to_tiled(7, 4, 4, 2, 2, &temp) == 7);

  assert(pitch_to_tiled(8, 4, 4, 2, 2, &temp) == 8);
  assert(pitch_to_tiled(9, 4, 4, 2, 2, &temp) == 9);
  assert(pitch_to_tiled(12, 4, 4, 2, 2, &temp) == 10);
  assert(pitch_to_tiled(13, 4, 4, 2, 2, &temp) == 11);

  assert(pitch_to_tiled(10, 4, 4, 2, 2, &temp) == 12);   assert(temp == 0);
  assert(pitch_to_tiled(11, 4, 4, 2, 2, &temp) == 13);   assert(temp == 1);
  assert(pitch_to_tiled(14, 4, 4, 2, 2, &temp) == 14);   assert(temp == 2);
  assert(pitch_to_tiled(15, 4, 4, 2, 2, &temp) == 15);   assert(temp == 3);
  
  // 8 x 2 -> 2 x 2
  assert(pitch_to_tiled(0 , 8, 2, 2, 2, &temp) == 0);   assert(temp == 0);
  assert(pitch_to_tiled(1 , 8, 2, 2, 2, &temp) == 1);   assert(temp == 1);
  assert(pitch_to_tiled(8 , 8, 2, 2, 2, &temp) == 2);   assert(temp == 2);
  assert(pitch_to_tiled(9 , 8, 2, 2, 2, &temp) == 3);   assert(temp == 3);

  assert(pitch_to_tiled(4 , 8, 2, 2, 2, &temp) == 8);   assert(temp == 0);
  assert(pitch_to_tiled(5 , 8, 2, 2, 2, &temp) == 9);   assert(temp == 1);
  assert(pitch_to_tiled(12 , 8, 2, 2, 2, &temp) == 10); assert(temp == 2);
  assert(pitch_to_tiled(13 , 8, 2, 2, 2, &temp) == 11); assert(temp == 3);
  }

  if (0) matrix_transpose_using_tiling();

  if (0) tile_to_pitch_to_back();

  if (1) tile_to_pitch_to_back_nonsquare_nontranspose();

  return EXIT_SUCCESS;
}
