#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("filters ...\n");

  void *ptr;
  int retvalue = posix_memalign(&ptr, sizeof(void*), 1024);

  printf("size of void* %d\n", sizeof(void*));
  printf("returned %d %p\n", retvalue, ptr);

  long data = (long) ptr;
  data = (data | 1);
  ptr  = (void*) data;
  
  printf("new address 0x%lx\n", data);
  printf("new pointer address %p\n", ptr);

  return 1;
}

