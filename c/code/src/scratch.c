#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

typedef struct A {
  int data;
  struct A* next;
} ABC;

int main(void) {
  ABC x = { 2, NULL};

  printf("%d %p\n", x.data, x.next);

  printf("%ld\n", sizeof(((ABC*)0)->next));

  return 0;
}

