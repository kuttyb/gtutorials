#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void) {
  int* a = calloc(1, sizeof(int));

  a[0]= 2;
  a = realloc(a, 8192);
  a[8190] = 2;

  assert(a[0] == 2);
  assert(a[8190] == 2);

  free(a);
  printf("done freeing\n");
  return 1;
}

