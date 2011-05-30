#include <stdio.h>
#include <stdlib.h>

int func(int a, int b) {
  return a + b;
}

typedef int (*ABC)(int, int);
typedef int AX;
typedef enum { false, true } Boolean;

int main(void) {
  int a   = 20;
  int b[4] = {2, 3, 5, 6};
  int c   = 3;
  AX xx = 3;
  Boolean yy = false;

  if (xx < 2) return 0;
  if (yy != false) return 0;

  int *x  = &a;
  int (*y)[4] = &b;
  int *z[] = { &a, b, &c };
  
  printf("%d\n", *x);

  printf("%d\n", *(*y + 2));
  printf("%d %d %d\n", 
	 y[0][0], y[0][1], y[0][2]);

  printf("%d %d %d\n",
	 *z[0], z[1][2], *z[2]);

  // function pointers 
  ABC abc = func;
  printf("%d\n", abc(3, 8));
  
  return 1;
}

