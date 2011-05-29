#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// This is useful in collections where we want to capture the empty case
// trivially and not have to do any search. Placing this information 
// in the address also means that detecing isempty doesnt require dependent
// loads

typedef enum { false, true } boolean ;

static inline void mark(void **ptr, boolean bPresent) {
  long lPtr = (long) *ptr;
  lPtr |= 1;
  if (bPresent == false) {
    lPtr ^= 1;
  } 
  *ptr = (void*) lPtr;
}

static inline boolean isPresent(void *ptr) {
  if ((((long)ptr) >> 1) == (long)ptr){
    return false;
  } else {
    return true;
  }
}

#define ADDR(ptr) (void*)((((long)ptr) >> 1) << 1)

int main(void) {
  printf("filters ...\n");

  void *ptr;
  assert(!posix_memalign(&ptr, sizeof(void*), 1024));

  printf("pointer value before marking %p\n", ptr);

  mark(&ptr, true);
  printf("pointer value after marking %p\n", ptr);
  printf("pointer value after cleaning %p\n", ADDR(ptr));

  free(ADDR(ptr));

  return 1;
}
