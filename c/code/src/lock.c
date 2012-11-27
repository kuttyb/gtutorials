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
mts_spinlock_t *r0;
mts_spinlock_t *r1;

static inline mts_spinlock_t* mts_getlock_image(mts_spinlock_t *lock) {
  assert(lock->owner < KERNIF_MAX_THREADS);
  return mts_lastlock_grabbed[lock->owner];
}

void detect_deadlock(mts_spinlock_t **one, mts_spinlock_t **two) {
  // deadlock detection logic
  uint32_t tid, ctr;
  for (tid = 0; tid < KERNIF_MAX_THREADS; ++tid) {
    mts_spinlock_t *lock = mts_lastlock_grabbed[tid];
    if (!lock) continue;
    for (ctr = 0; (ctr < KERNIF_MAX_THREADS) && (lock = mts_getlock_image(lock)); ++ctr) {
      if (lock->owner == tid) {
        /* printf("locks %p and %p are deadlocked\n",  */
        /*        lock, mts_lastlock_grabbed[tid]); */
        *one = lock;
        *two = mts_lastlock_grabbed[tid];
        return;       
      }
    }
  }
}

void setup(void) {
  memset(mts_lastlock_grabbed, 0, sizeof(mts_spinlock_t*) * KERNIF_MAX_THREADS);
  r0 = NULL;
  r1 = NULL;
}

static void assert_locks(mts_spinlock_t *one, mts_spinlock_t *two) {
  if ((one == r0) && (two == r1)) {
    return;
  }

  if ((one == r1) && (two == r0)) {
    return;
  }
  
  printf("locks %p %p do not match r %p %p\n",
         one, two, r0, r1);
  assert(0);
}

static void testSuccess_SimpleDeadlock(void) {
  mts_spinlock_t a,b;
  a.owner = 1;
  b.owner = 0;
  mts_lastlock_grabbed[0] = &a;
  mts_lastlock_grabbed[1] = &b;

  detect_deadlock(&r0, &r1);
  assert_locks(&a, &b);
}

static void testSuccess_NoDeadlock(void) {
  mts_spinlock_t a,b;
  a.owner = 2;
  b.owner = 1;
  mts_lastlock_grabbed[0] = &a;
  mts_lastlock_grabbed[2] = &b;

  detect_deadlock(&r0, &r1);  
  assert_locks(NULL, NULL);
}

static void testSuccess_PointingIntoCycle(void) {
  mts_spinlock_t a,b,c;
  a.owner = 2;
  b.owner = 2;
  c.owner = 1;
  mts_lastlock_grabbed[0] = &a;
  mts_lastlock_grabbed[1] = &b;
  mts_lastlock_grabbed[2] = &c;

  detect_deadlock(&r0, &r1);
  assert_locks(&b, &c);
}

static void testSuccess_PointingIntoCycle2(void) {
  mts_spinlock_t a,b,c;
  a.owner = 1;
  b.owner = 2;
  c.owner = 1;
  mts_lastlock_grabbed[0] = &a;
  mts_lastlock_grabbed[1] = &b;
  mts_lastlock_grabbed[2] = &c;

  detect_deadlock(&r0, &r1);  
  assert_locks(&b, &c);
}


static void testSuccess_FirstEntryNull(void) {
  mts_spinlock_t b,c;
  b.owner = 2;
  c.owner = 1;
  mts_lastlock_grabbed[0] = NULL;
  mts_lastlock_grabbed[1] = &b;
  mts_lastlock_grabbed[2] = &c;

  detect_deadlock(&r0, &r1);  
  assert_locks(&b, &c);
}

/** all members are linked and last and first are connected */
static void testSuccess_FullCycle(void) {
  mts_spinlock_t a, b, c, d;
  a.owner = 1;
  b.owner = 2;
  c.owner = 3;
  d.owner = 0;
  mts_lastlock_grabbed[0] = &a;
  mts_lastlock_grabbed[1] = &b;
  mts_lastlock_grabbed[2] = &c;
  mts_lastlock_grabbed[3] = &d;
  
  detect_deadlock(&r0, &r1);
  assert_locks(&a, &d);
}

static void testSuccess_AllNull(void) {
  detect_deadlock(&r0, &r1);
  assert(!(r0 || r1));
}

int main(void) {
  invoke(testSuccess_SimpleDeadlock, "simpledeadlock");
  invoke(testSuccess_NoDeadlock, "nodeadlock");
  invoke(testSuccess_PointingIntoCycle, "pointing_into_cycle");
  invoke(testSuccess_PointingIntoCycle2, "pointing_into_cycle2");
  invoke(testSuccess_FirstEntryNull, "first_entry_null");
  invoke(testSuccess_FullCycle, "full_cycle");
  invoke(testSuccess_AllNull, "all_null");

  return EXIT_SUCCESS;
}
