#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

#define  gmat(a, r, c, i, j)         (a + i*c + j)

static inline void transpose(uint32_t *matrix, uint32_t rows, uint32_t cols, uint32_t *dst) {
     for (uint32_t i = 0; i < cols; ++i) {
          for (uint32_t j = 0; j < rows; ++j) {
               *gmat(dst, cols, rows, i, j) = *gmat(matrix, rows, cols, j, i);
          }
     }
}

static inline void swap(uint32_t *a, uint32_t *b) {
     uint32_t temp = *a;
     *a = *b;
     *b = temp;
}

static inline void flipcolumns(uint32_t *matrix, uint32_t rows, uint32_t cols) {
     for (uint32_t i = 0; i < cols/2; ++i) {
          for (uint32_t j = 0; j < rows; ++j) {
               swap(gmat(matrix, rows, cols, j, i), gmat(matrix, rows, cols, j, cols - i - 1));
          }
     }
}

static inline void fliprows(uint32_t *matrix, uint32_t rows, uint32_t cols) {
     for (uint32_t i = 0; i < rows/2; ++i) {
          for (uint32_t j = 0; j < cols; ++j) {
               swap(gmat(matrix, rows, cols, i, j),
                    gmat(matrix, rows, cols, rows - i - 1, j));
          }
     }
}

static inline void print_matrix(uint32_t *matrix, uint32_t rows, uint32_t cols) {
     for (uint32_t i = 0; i < rows; ++i) {
          for (uint32_t j = 0; j < cols; ++j) {
               printf("%3d\t", *gmat(matrix, rows, cols, i, j));
          }
          printf("\n");
     }
     printf("------\n");
}

int main(void) {
     uint32_t mat[3][2] = {
          {0, 1},
          {2, 3 },
          {4, 5 }
     };
     uint32_t dst[2][3] = { {0} };


     return EXIT_SUCCESS;
}
