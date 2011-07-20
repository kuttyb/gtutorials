#include <stdio.h>
#include <stdlib.h>


#define ISSIGNALLED(ptr)  (((((unsigned long)ptr) >> 1) << 1) != (unsigned long)ptr)
#define SIGNAL(ptr)       (void*)(((unsigned long)ptr) | 1)
#define GETPTR(ptr)       (void*)((((unsigned long)ptr) >> 1) << 1)

int main(void) {
  int  a = 20;
  int *b = &a;

  printf("b = %p\n", b);
  
  int *c = SIGNAL(b);
  printf("SIGNAL(b) = %p\n", c);
  printf("ISSIGNALLED(c) = %d\n", ISSIGNALLED(c));
  printf("ISSIGNALLED(b) = %d\n", ISSIGNALLED(b));
  printf("GETPTR(c) = %p\n",      GETPTR(c));

  return 1;
}

