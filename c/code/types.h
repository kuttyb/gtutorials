#ifndef _types_h_
#define _types_h_

#include "barrier.h"

typedef struct {
  int data;
} _volatile;

#define volatile_store(var, value)  {var.data = value; barrier_release();}
// DONT do this its GCC only !
// #define volatile_load(var) ({barrier_acquire(); var.data;})
static inline int volatile_load(_volatile var) { barrier_acquire(); return var.data;}

typedef struct {
  void *ptr;
} _volatileptr;

#define volatileptr_store(var, value) {var.ptr = value; barrier_release();}
static inline void* volatileptr_load(_volatileptr var) { barrier_acquire(); return var.ptr;}

#endif
