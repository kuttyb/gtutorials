#ifndef   __barrier_h__
#define   __barrier_h__

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

/** sparc */
#elif   defined(__sparc)
#include <mbarrier.h> /** SUN Studio header */
#define   barrier_compiler()   __compiler_barrier()
#define   barrier_full()       __machine_rw_barrier()
#define   barrier_acquire()    __machine_acq_barrier()
#define   barrier_release()    __machine_rel_barrier()
#define   barrier_read()       __machine_r_barrier()    
#define   barrier_write()      __machine_w_barrier()

/** undefined */
#else
#define  "barriers not supported for this platform"
#endif //${ARCH}

#endif // __barrier_h__
