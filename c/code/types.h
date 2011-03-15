#ifndef _types_h_
#define _types_h_

#include "barrier.h"

typedef struct {
  int data;
} _volatile;


static inline void volatile_store(_volatile var, int value) {
  var.data = value;
  barrier_release();
}

static inline int volatile_load(_volatile var) {
  barrier_acquire();
  return var.data;
}

#endif
