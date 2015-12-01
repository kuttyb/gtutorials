//
//  atomics.h
//  cpp-practise
//
//  Created by kuttyb on 12/1/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef atomics_h
#define atomics_h

#define   CAS(ptr, oldval, newval) __sync_bool_compare_and_swap(ptr, oldval, newval)
#define   barrier_compiler()   asm volatile ("" : : : "memory")
#define   barrier_full()       asm volatile ("lock;addl $0,(%%rsp)" : : : "memory")
#define   barrier_full_exp()   asm volatile ("mfence" : : : "memory")
#define   barrier_acquire()    barrier_compiler()
#define   barrier_release()    barrier_full()
#define   barrier_read()       barrier_compiler()
#define   barrier_write()      barrier_compiler()

#endif /* atomics_h */
