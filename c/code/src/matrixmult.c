#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>



static inline void kernel(uint32_t *dst, uint32_t *one, uint32_t *two, uint32_t row, uint32_t column,
                          uint32_t stride, uint32_t innerdelta) {
  assert(dst && one && two && stride && innerdelta);

  uint32_t sum = 0;
  for (uint32_t i = 0; i < innerdelta; i++, one++, two += stride) {
    if (0) printf("sum %d one %d two %d\n",
           sum, *one, *two);
    sum += *one * *two;
  }
  *(dst + row * stride + column) = sum;
}

static inline void printmatrix_transpose(uint32_t *mat, uint32_t r, uint32_t c) {
  printf("printing matrix transpose ...\n");
  for (uint32_t i = 0; i < c; ++i) {
    for (uint32_t j = 0; j < r; ++j) {
      printf("%d\t", *(mat + (j * c) + i));
    }
    printf("\n");
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

int main(void) {
  uint32_t a[3][2] = {
    { 0, 1 },
    { 2, 3 },
    { 4, 5 }
  };

  uint32_t b[2][4] = {
    { 0, 1, 2, 3 },
    { 4, 5, 6, 7 }
  };

  if (0) {
    printmatrix(&a[0][0], 3, 2);
    printmatrix(&b[0][0], 2, 4);
    printmatrix_transpose(&a[0][0], 3, 2);
    printmatrix_transpose(&b[0][0], 2, 4);
  }

  const uint32_t rows = 3;
  const uint32_t cols = 4;
  const uint32_t innerdelta = 2;

  uint32_t c[rows][cols];
  memset(&c[0][0], 0, sizeof(uint32_t) * 3 * 4);
  printmatrix(&c[0][0], 3, 4);

  // Matrix multiplication outer two loops
  for (uint32_t i = 0; i < rows; ++i) {
    for (uint32_t j = 0; j < cols; ++j) {
      kernel(&c[0][0], &a[i][0], &b[0][j],
             i, j, cols, innerdelta);
    }
  }

  printmatrix(&c[0][0], 3, 4);

  return EXIT_SUCCESS;
}

