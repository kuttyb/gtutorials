#include <stdio.h>
#include "barrier.h"

struct _ABC {
  int   a;
  char  b __attribute__((aligned(8)));
  float c;
};

// __attribute__ is applied to declarations not definitions
static int func(int data)  __attribute__((always_inline));

int func(int data) {
  int size = data *2;
  if (size < 2) {
    return -1;
  }

  int retValue = size;
  for (int counter = 0; counter < size; counter++) {
    retValue += counter;
    if (retValue > 0x200) {
      break;
    }
  }

  return retValue;
}

int main(void) {
  struct _ABC variable;
  variable.a = 2;
  variable.b = '3';
  variable.c = 30.213f;

  printf("sizeof float  %zu\n", sizeof(float));
  printf("sizeof struct %zu\n", sizeof(variable));
  barrier_full();
  int value = func(sizeof(variable));
  barrier_full();
  printf("value returned %d\n", value);

  return 1;
}
