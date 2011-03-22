#ifndef   __barrier_h__
#define   __barrier_h__

#if  (__GNUC__)
#if      (__x86_64__)
#define   barrier_compiler()   asm volatile ("" : : : "memory") 
#define   barrier_full()       asm volatile ("lock;addl $0,(%%rsp)" : : : "memory")
#define   barrier_acquire()    barrier_compiler()
#define   barrier_release()    barrier_full()
#define   barrier_loadload()   asm volatile ("lfence" : : : "memory") 
#define   barrier_storestore() asm volatile ("sfence" : : : "memory") 
#elif    (__i386__)
#define   barrier_compiler()   asm volatile ("" : : : "memory") 
#define   barrier_full()       asm volatile ("lock; addl $0,0(%%esp)" : : : "memory")
#define   barrier_acquire()    barrier_compiler()
#define   barrier_release()    barrier_full()
#define   barrier_loadload()   asm volatile ("lfence" : : : "memory") 
#define   barrier_storestore() asm volatile ("sfence" : : : "memory") 
#else /** fallback to GCC intrinsics */
#define   barrier_compiler()   asm volatile ("" : : : "memory") 
#define   barrier_full()       __sync_synchronize()
#define   barrier_acquire()    {unsigned int a = 0; __sync_lock_test_and_set(&a, 2);}
#define   barrier_release()    {unsigned int a = 2; __sync_lock_release(&a, 0);}
#define   barrier_loadload()   barrier_full() /** sorry dont know the correct ones yet */
#define   barrier_storestore() barrier_full() /** so erring on the stronger side */
#endif 
#else
#error    "GCC is the only compiler supported so far"
#endif

#endif
