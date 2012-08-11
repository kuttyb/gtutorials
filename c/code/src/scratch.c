#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

typedef struct {
  uint64_t xlat_id;
  uint32_t td;
} Tran;

#define  MAXINDEX   (10)
Tran tdesc[MAXINDEX];

static inline void print_tran(Tran* tran, uint32_t id) {
  assert(tran);
  printf("id=0x%x xlat_id=0x%"PRIx64" &td=%p td=0x%x\n", 
	 id, tran->xlat_id, &tran->td, tran->td);
}

static inline uint32_t getindex(uint32_t* td) {
  uintptr_t td_t = (uintptr_t)td;
  td_t -= sizeof(uint64_t);
  
  uintptr_t index = (td_t - (uintptr_t) tdesc) / sizeof(Tran);
  return index;
}

int main(void) {
  printf("start addr %p element_size 0x%lx\n", tdesc, sizeof(Tran));

  for (uint32_t ctr = 0; ctr < MAXINDEX; ctr++) {
    tdesc[ctr].xlat_id = ctr + 100;
    tdesc[ctr].td      = 0x20;
  }

  print_tran(&tdesc[9], 9);
  printf("index returned is %d\n", getindex(&tdesc[9].td));

  return 0;
}

