#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

static inline void print_region(uint32_t *ptr, uint32_t elems) {
  for(uint32_t i = 0; i < elems; ++i) {
    printf("%d\n", ptr[i]);
  }
}

int main(void) {
  uint32_t *list = calloc(5, sizeof(uint32_t));
  assert(list);

  print_region(list, 5);

  uint32_t a[5] = { 0, 1, 2, 3, 4};
  

  print_region(list, 5);

  free(list);

  return 0;
}
