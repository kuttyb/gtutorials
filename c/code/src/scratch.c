#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

void print(char *a) {
  printf("%s\n", a);
}

int main(void) {
     char *a =  (char*)20;
     printf("%d %d %d\n",
            a, a + 1, (double*)a + 2);

  return 1;
}

