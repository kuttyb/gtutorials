#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

typedef union  {
  float f;
  unsigned char c[4];
  int i;
} ABC ;

int main(void) {
  ABC a;
  a.f = 2.465123f;

  printf("%f %d %d\n",
         a.f, a.i, (int)a.f);
  printf("0x%x 0x%x 0x%x 0x%x\n",
         a.c[0], a.c[1], a.c[2], a.c[3]);

  unsigned char *ptr = (unsigned char*) &a.f;
  printf("0x%x 0x%x 0x%x 0x%x\n",
         ptr[0], ptr[1], ptr[2], ptr[3]);
  int *iptr = (int *)ptr;
  printf("%d\n", *iptr);

  return EXIT_SUCCESS;
}

