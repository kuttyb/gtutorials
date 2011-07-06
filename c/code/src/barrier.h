#ifndef   __barrier_h__
#define   __barrier_h__

/** should work for SunStudio and GCC */
#define   CAS(ptr, oldval, newval) __sync_bool_compare_and_swap(ptr, oldval, newval)

/** x86-64 */
#if     defined(__x86_64)
#define   barrier_compiler()   asm volatile ("" : : : "memory") 
#define   barrier_full()       asm volatile ("lock;addl $0,(%%rsp)" : : : "memory")
#define   barrier_acquire()    barrier_compiler()
#define   barrier_release()    barrier_full()
#define   barrier_read()       asm volatile ("lfence" : : : "memory") 
#define   barrier_write()      asm volatile ("sfence" : : : "memory") 

/** i386 */
#elif   defined(__i386)
#define   barrier_compiler()   asm volatile ("" : : : "memory") 
#define   barrier_full()       asm volatile ("lock; addl $0,0(%%esp)" : : : "memory")
#define   barrier_acquire()    barrier_compiler()
#define   barrier_release()    barrier_full()
#define   barrier_read()       asm volatile ("lfence" : : : "memory") 
#define   barrier_write()      asm volatile ("sfence" : : : "memory") 

/** SPARC (we will assume TSO ... nooped membars are not free) */
#elif   defined(__sparc)
#define   barrier_compiler()   asm volatile("":::"memory")
#define   barrier_full()       asm volatile("membar #StoreLoad" ::: "memory")
#define   barrier_acquire()    barrier_compiler()
#define   barrier_release()    barrier_full()
#define   barrier_read()       barrier_compiler()
#define   barrier_write()      barrier_compiler()

/** undefined */
#else
#define  "barriers not supported for this platform"
#endif //${ARCH}

#endif // __barrier_h__
