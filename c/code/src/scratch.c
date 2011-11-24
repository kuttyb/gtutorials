#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

#define PREDICATE_GETADDRESS(p)    (void*)((((uintptr_t)p) >> 1) << 1)
#define PREDICATE_SETTRUE(p)       (void*)(((uintptr_t)p) | 1)
#define PREDICATE_SETFALSE(p)      (void*)((((uintptr_t)p) | 1) ^ 1)
#define PREDICATE_GETPREDICATE(p)  (uint32_t)(((((uintptr_t)p) >> 1) << 1) != ((uintptr_t)p))


int main(void) {
  int* a = calloc(1, sizeof(int));
  *a = 2;

  int* b = PREDICATE_GETADDRESS(a);
  int* c = PREDICATE_SETTRUE(a);
  int* d = PREDICATE_SETFALSE(c);
  int* e = PREDICATE_SETTRUE(d);
  printf("oldptr %p newptr %p settrue_ptr %p setfalse_ptr %p\n", a, b, c, d);
  printf("value is %d\n", *b);

  printf("is c predicated %d\n", PREDICATE_GETPREDICATE(c));
  printf("is d predicated %d\n", PREDICATE_GETPREDICATE(d));
  printf("is b preidcated %d\n", PREDICATE_GETPREDICATE(b));
  printf("is e preidcated %d\n", PREDICATE_GETPREDICATE(e));

  free(a);
  return 0;
}

