#ifndef _types_h_
#define _types_h_

#include "barrier.h"

typedef struct {
    int data;
} _volatile;

#define volatile_store(var, value)  {var.data = value; barrier_release();}
#define volatile_load(var) ({barrier_acquire(); var.data;})

typedef struct {
    void *ptr;
} _volatileptr;

#define volatileptr_store(var, value) {var.ptr = value; barrier_release();}
#define volatileptr_load(var) ({barrier_acquire(); var.ptr;})

typedef enum {
    false, true
} boolean;

#endif
