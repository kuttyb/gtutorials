#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

#define LOCKSECTION  __attribute__ ((section (".locks")))

typedef struct {
    uint8_t acquired;  // Zero implies nobody has the lock.
    uint8_t level : 4; // The level to be set in the mts_thread_lock_level
    uint8_t owner : 4; // The owner of the lock (if acquired)
} mts_spinlock_t;

#define MTS_LOCK_DECL  LOCKSECTION mts_spinlock_t

MTS_LOCK_DECL a;

typedef mts_spinlock_t a_t;

int main(void) {
  a_t x;

  return EXIT_SUCCESS;
}

