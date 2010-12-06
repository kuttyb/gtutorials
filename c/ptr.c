#include <stdlib.h>
#include <stdio.h>

void print(char *a) {
  printf("%s\n", a);
}

int main(void) {
  // host
  char *a[3];
  char **b[3];

  // elements
  char *x = "xxab";
  char *y = "yywe";

  a[0] = x;
  a[1] = x;
  a[2] = y;
  b[0] = a;
  b[1] = a;
  b[2] = a;


  printf("%ld  %ld %ld %ld\n",
	 sizeof(b), sizeof(*b), sizeof(**b), sizeof(***b));

  printf("%ld  %ld %ld %ld\n",
	 sizeof(a), sizeof(*a), sizeof(**a), sizeof(*a[1]));

  printf("%s\n",
	 a[0] + 2);

  printf("%s\n",
	 (a+2)[0]+2);

  print(*b[2]);
  
  return 1;
}
