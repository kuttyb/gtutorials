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

static void testSuccess_Basic(void) {
  mts_spinlock_t a,b;
  a.owner = 1;
  b.owner = 0;
  mts_lastlock_grabbed[0] = &a;
  mts_lastlock_grabbed[1] = &b;

  printf("lock a %p lock b %p\n", &a, &b);
  detect_deadlock();
}

int main(void) {
  invoke(testSuccess_Basic, "basic");

  return EXIT_SUCCESS;
}
