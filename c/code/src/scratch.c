#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

static inline uint32_t elem(uint32_t *matrix, uint32_t r, uint32_t c, uint32_t stride) {
  return matrix[(stride * r) + c];
}

static inline void swap_elem(uint32_t *matrix, uint32_t r, uint32_t c, uint32_t stride,
                                 uint32_t r1, uint32_t c1) {
  uint32_t temp = matrix[(stride * r1) + c1];
  matrix[(stride * r1) + c1] = matrix[(stride * r) + c];
  matrix[(stride * r) + c] = temp;
}

static inline void print_matrix(uint32_t *matrix, uint32_t r, uint32_t c) {
  for (uint32_t i = 0; i < r; ++i) {
    for (uint32_t j = 0; j < c; ++j) {
      printf("%d\t", elem((uint32_t*)matrix, i, j, c));
    }
    printf("\n");
  }
}


static inline void transpose_matrix(uint32_t *matrix, uint32_t r, uint32_t c) {
  uint32_t x = 0;
  for (uint32_t i = 0; i < r; i++) {
    for (uint32_t j = x; j < c; j++) {
      if (i == j) continue;
      swap_elem(matrix, i, j, c, j, i);
    }
    x++;
  }
}

int main(void) {
  uint32_t matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9 }
  };

  print_matrix((uint32_t*)matrix, 3, 3);

  printf("applying transpose in place\n");
  transpose_matrix((uint32_t*)matrix, 3, 3);
  print_matrix((uint32_t*)matrix, 3, 3);

  return 1;
}

