#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ABC {
  int a;
  int b;
};

int main(void) {
  struct ABC a;
  printf("%p %p\n", &a.a, &a.b);

  return 0;
}

