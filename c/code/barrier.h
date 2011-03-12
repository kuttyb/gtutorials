#ifndef   __barrier_h__
#define   __barrier_h__

#include <emmintrin.h>

#define   barrier_compiler()   asm volatile ("" : : : "memory") 
#define   barrier_storestore() _mm_sfence()
#define   barrier_storeload()  _mm_mfence()
#define   barrier_loadload()   _mm_lfence()
#define   barrier_loadstore()  _mm_lfence()
#define   barrier_full()       _mm_mfence()

#endif
