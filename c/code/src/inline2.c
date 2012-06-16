#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include "inline.h"

static int localstart(int input) {
  printf("final destination\n");
  return (int)random() % 20;
}

Type* exportType(void) {
   if (random() % 2) {
     return NULL;
   }

  Type* type = calloc(1, sizeof(Type));
  type->start = localstart;
  printf("done with allocation\n");
  return type;
}
