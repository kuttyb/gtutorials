#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  int *a = calloc(10, sizeof(int));
  
  sleep(5);

  printf("about to sbrk\n");
  void *c = sbrk(1024*1024*200);
  printf("done sbrking current value is %p\n", c);

  int *b = calloc(10, sizeof(int));
  printf("%p %p\n", a, b);

  free(a);
  free(b);

  return 1;
}
