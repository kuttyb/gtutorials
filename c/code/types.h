#ifndef _types_h_
#define _types_h_

#include "barrier.h"

typedef struct {
  int data;
} _volatile;

#define volatile_store(var, value)  var.data = value; barrier_release();
// #define volatile_load(var) ({barrier_acquire(); var.data;})
static inline int volatile_load(_volatile var) { barrier_acquire(); return var.data;}

#endif
