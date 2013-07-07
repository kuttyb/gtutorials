#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

typedef union {
  int num;
  unsigned char mem[4];
} A;

static void print(A x) {
  printf("%d\n", x.num);
  printf("0x%x-%x-%x-%x\n",
         (unsigned char)x.mem[3], 
         (unsigned char)x.mem[2], 
         (unsigned char)x.mem[1],
         (unsigned char)x.mem[0]);
}

int main(void) {
  A x = { -2 };
  print(x);

  x.num = -3;
  print(x);

  x.num = -1;
  print(x);
  
  return EXIT_SUCCESS;
}

