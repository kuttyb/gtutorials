#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "test.h"

typedef struct {
  uint8_t owner;
} mts_spinlock_t;

#define KERNIF_MAX_THREADS   (0x4)
mts_spinlock_t *mts_lastlock_grabbed[KERNIF_MAX_THREADS];

static inline mts_spinlock_t* mts_getlock_image(mts_spinlock_t *lock) {
  assert(lock->owner < KERNIF_MAX_THREADS);
  return mts_lastlock_grabbed[lock->owner];
}

void detect_deadlock() {
  // deadlock detection logic
  uint32_t tid, ctr;
  for (tid = 0; tid < KERNIF_MAX_THREADS; ++tid) {
    mts_spinlock_t *lock = mts_lastlock_grabbed[tid];
    if (!lock) continue;
    for (ctr = 0; (ctr < KERNIF_MAX_THREADS) && (lock = mts_getlock_image(lock)); ++ctr) {
      if (lock->owner == tid) {
        printf("locks %p and %p are deadlocked\n", 
               lock, mts_lastlock_grabbed[tid]);
        return;       
      }
    }
  }
}

void setup(void) {
  memset(mts_lastlock_grabbed, 0, sizeof(mts_spinlock_t*) * KERNIF_MAX_THREADS);
}

static void testSuccess_SimpleDeadlock(void) {
  mts_spinlock_t a,b;
  a.owner = 1;
  b.owner = 0;
  mts_lastlock_grabbed[0] = &a;
  mts_lastlock_grabbed[1] = &b;

  printf("\tlock a %p\n\tlock b %p\n", &a, &b);
  detect_deadlock();
}

static void testSuccess_NoDeadlock(void) {
  mts_spinlock_t a,b;
  a.owner = 2;
  b.owner = 1;
  mts_lastlock_grabbed[0] = &a;
  mts_lastlock_grabbed[2] = &b;

  printf("\tlock a %p\n\tlock b %p\n", &a, &b);
  detect_deadlock();  
}

static void testSuccess_PointingIntoCycle(void) {
  mts_spinlock_t a,b,c;
  a.owner = 2;
  b.owner = 2;
  c.owner = 1;
  mts_lastlock_grabbed[0] = &a;
  mts_lastlock_grabbed[1] = &b;
  mts_lastlock_grabbed[2] = &c;

  printf("\tlock a %p\n\tlock b %p\n\tlock c %p\n", 
         &a, &b, &c);
  detect_deadlock();  
}

static void testSuccess_PointingIntoCycle2(void) {
  mts_spinlock_t a,b,c;
  a.owner = 1;
  b.owner = 2;
  c.owner = 1;
  mts_lastlock_grabbed[0] = &a;
  mts_lastlock_grabbed[1] = &b;
  mts_lastlock_grabbed[2] = &c;

  printf("\tlock a %p\n\tlock b %p\n\tlock c %p\n", 
         &a, &b, &c);
  detect_deadlock();  
}


int main(void) {
  invoke(testSuccess_SimpleDeadlock, "simpledeadlock");
  invoke(testSuccess_NoDeadlock, "nodeadlock");
  invoke(testSuccess_PointingIntoCycle, "pointing_into_cycle");
  invoke(testSuccess_PointingIntoCycle2, "pointing_into_cycle2");

  return EXIT_SUCCESS;
}
