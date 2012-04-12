#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>

typedef struct {
  int(*start)(int);
} Type;

int localstart(int input) {
  return random() % 0x10;
}

__attribute__((always_inline)) Type* exportType(void) {
  Type* type = calloc(1, sizeof(Type));
  type->start = localstart;
  return type;
}


int main(void) {
  Type* type = exportType();

  return type->start(20);
}
