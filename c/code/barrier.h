#ifndef   __barrier_h__
#define   __barrier_h__

#define   barrier_compiler()   asm volatile ("" : : : "memory") 
#define   barrier_storestore() asm volatile ("sfence" : : : "memory")
#define   barrier_storeload()  asm volatile ("sfence" : : : "memory")
#define   barrier_loadload()   asm volatile ("lfence" : : : "memory")
#define   barrier_loadstore()  asm volatile ("lfence" : : : "memory")
#define   barrier_full()       asm volatile ("mfence" : : : "memory")

#endif
