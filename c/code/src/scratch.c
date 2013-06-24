#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

int main(void) {
  uint32_t a[2][3] = {
    { 0, 1, 2},
    { 8, 9, 10}
  };

  // Row order layout print
  for (uint32_t i = 0; i < 2; i++) {
    for (uint32_t j = 0; j < 3; j++) {
      printf("%d\n", a[i][j]);
    }
  }

  // Core memory dump
  printf("core memory dump\n");
  uint32_t *ptr = &a[0][0];
  for (uint32_t i = 0; i < 3 * 2; i++, ptr++) {
    printf("%d\n", *ptr);
  }
  
  // column order layout print (aka transpose)
  printf("column order print\n");
  for (uint32_t i = 0; i < 3; ++i) {
    for (uint32_t j = 0; j < 2; ++j) {
      printf("%d\n", a[j][i]);
    }
  }



  return EXIT_SUCCESS;
}
