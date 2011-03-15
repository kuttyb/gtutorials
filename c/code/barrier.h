#ifndef   __barrier_h__
#define   __barrier_h__

#if  (__GNUC__ && __x86_64__)
#define   barrier_compiler()   asm volatile ("" : : : "memory") 
#define   barrier_write()      asm volatile ("sfence" : : : "memory")
#define   barrier_read()       asm volatile ("lfence" : : : "memory")
#define   barrier_full()       asm volatile ("lock;addl $0,(%%rsp)" : : : "memory")
// This is indeed slower on both Opteron and i7 (first noted by DaveD Oracle)
//#define   barrier_full()       asm volatile ("mfence" : : : "memory")
#define   barrier_acquire()    barrier_compiler()
#define   barrier_release()    barrier_full()
#elif (__GNUC__ && __i386__)
#define   barrier_compiler()   asm volatile ("" : : : "memory") 
#define   barrier_write()      asm volatile ("sfence" : : : "memory")
#define   barrier_read()       asm volatile ("lfence" : : : "memory")
#define   barrier_full()       asm volatile ("lock; addl $0,0(%%esp)" : : : "memory")
#define   barrier_acquire()    barrier_compiler()
#define   barrier_release()    barrier_full()
#else
#error "Platform not supported!!"
#endif 

#endif
