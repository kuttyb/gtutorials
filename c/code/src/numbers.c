#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

typedef union {
  int    num;
  signed short s;
  float  f;
  unsigned char mem[4];
} A;

static void printnum(A x) {
  printf("%d:\t", x.num);
  printf("0x%x%x%x%x\n",
         (unsigned char)x.mem[3], 
         (unsigned char)x.mem[2], 
         (unsigned char)x.mem[1],
         (unsigned char)x.mem[0]);
}


int main(void) {
  /** understand 2s complement basics */
  if (0) 
  {
    A x = { -2 };
    printnum(x);

    x.num = -3;
    printnum(x);

    x.num = -1;
    printnum(x);
  }

  /** understand sign extension */
  {
    A x = { 0 };
    x.s = -2;
    printnum(x);
    x.num = x.s;
    printnum(x);
  }
  
  return EXIT_SUCCESS;
}

