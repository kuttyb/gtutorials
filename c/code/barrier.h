#ifndef   __barrier_h__
#define   __barrier_h__

#if  (__GNUC__)
#if      (__x86_64__)
#define   barrier_compiler()   asm volatile ("" : : : "memory") 
#define   barrier_full()       asm volatile ("lock;addl $0,(%%rsp)" : : : "memory")
#define   barrier_acquire()    barrier_compiler()
#define   barrier_release()    barrier_full()
#elif    (__i386__)
#define   barrier_compiler()   asm volatile ("" : : : "memory") 
#define   barrier_full()       asm volatile ("lock; addl $0,0(%%esp)" : : : "memory")
#define   barrier_acquire()    barrier_compiler()
#define   barrier_release()    barrier_full()
#else /** fallback to GCC intrinsics */
#define   barrier_compiler()   asm volatile ("" : : : "memory") 
#define   barrier_full()       __sync_synchronize()
#define   barrier_acquire()    {unsigned int a = 0; __sync_lock_test_and_set(&a, 2);}
#define   barrier_release()    {unsigned int a = 2; __sync_lock_release(&a, 0);}
#endif 
#else
#error    "GCC is the only compiler supported so far"
#endif

#endif
