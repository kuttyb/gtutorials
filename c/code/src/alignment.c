#include <stdio.h>
#include <stdlib.h>
#include "barrier.h"

/** MORAL :
    For struct fields that you want to see aligned this attribute will
    help only for stack allocations not heap as &localvar->getput 
    shows.

    If you do need it aligned the best way is to declare it as a pointer
    and use aligned heap allocs 
*/

struct ABC {
  int   a;
  char  b;
  unsigned long getput[2] __attribute__((aligned(16)));
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
  struct ABC variable = 
    { 
      .getput[0] = 0,
      .getput[1] = 0,
      .a         = 3, 
      .b         = 0, 
      .c         = 32.12f 
    };

  printf("==== printing addresses off stack\n");
  printf("address of getput getput a b c is %p %p %p %p\n",
	 &variable.getput,
	 &variable.a, 
	 &variable.b, 
	 &variable.c);

  printf("==== printing addresses off heap\n");
  struct ABC *localvar = calloc(1, sizeof(struct ABC));
  printf("address of getput getput a b c is %p %p %p %p\n",
	 &localvar->getput,
	 &localvar->a, 
	 &localvar->b, 
	 &localvar->c);
  free(localvar);

  printf("sizeof float  %zu\n", sizeof(float));
  printf("sizeof struct %zu\n", sizeof(variable));
  barrier_full();
  int value = func(sizeof(variable));
  barrier_full();
  printf("value returned %d\n", value);

  return 1;
}
