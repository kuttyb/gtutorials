#ifndef   __barrier_h__
#define   __barrier_h__

#define   barrier_compiler()   asm volatile ("" : : : "memory") 
#define   barrier_write()      asm volatile ("sfence" : : : "memory")
#define   barrier_read()       asm volatile ("lfence" : : : "memory")
#define   barrier_full()       asm volatile ("mfence" : : : "memory")

#endif
