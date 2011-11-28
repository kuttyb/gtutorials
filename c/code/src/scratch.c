#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

int comp(const void* o, const void* t) {
  assert(o && t);
  const uint32_t *one = o;
  const uint32_t *two = t;
  
  if (*one == *two) 
    return 0;
  else if (*one > *two)  
    return 1;
  else 
    return -1;
}

int main(void) {
  uint32_t array[] = { 10, 5, 21, 2, 19 };

  qsort(array, 5, sizeof(array[0]), comp);

  for (uint32_t i = 0; i < 5; i++) {
    printf("%d\n", array[i]);
  }

  return 0;
}

