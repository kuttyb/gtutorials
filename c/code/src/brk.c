#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  int *a = calloc(10, sizeof(int));

  unsigned int bb = 0xaabbccdd;
  unsigned char* xx = (unsigned char*)&bb;
  for( int counter = 0; counter < 4; counter++) {
    printf("== 0x%x\n", xx[counter]);
  }

  printf("about to sbrk\n");
  void *c = sbrk(1024*1024*200);
  printf("done sbrking current value is %p\n", c);

  int *b = calloc(10, sizeof(int));
  printf("%p %p\n", a, b);

  free(a);
  free(b);

  return 1;
}
