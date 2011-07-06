#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include "fifo.h"
#include "barrier.h"

#define  REALPTR(ptr)        ((ptr >> 1) << 1)
#define  ISPRODUCED(ptr)     (ptr != NULL)
#define  PRODUCTED(ptr)      (NULL)
#define  ISCONSUMED(ptr)     (REALPTR(ptr) != ptr)
#define  CONSUMED(ptr)       (ptr | 1)

typedef struct {
  int    *get;
  int    *put;
  void  **fifodata;
  int    bytes;
} Pvt;

/**
void   put(Queue*,void*);
void*  get(Queue*);
*/

Queue* create(int size) {
  Pvt* pvt = calloc(1, sizeof(Pvt));
  if (!pvt) return NULL;

  /** find out a good way to get dcache size */
  posix_memalign((void**)&pvt->get, getpagesize() * 16, sizeof(int));
  posix_memalign((void**)&pvt->put, getpagesize() * 16, sizeof(int));
  posix_memalign((void**)&pvt->fifodata, getpagesize(), pvt->bytes);
  pvt->bytes = 0;

  Queue* retvalue = calloc(1, sizeof(Queue*));
  retvalue->data = pvt;

  return retvalue;
}

void destroy(Queue* queue) {
  if (!(queue && queue->data)) return;

  Pvt* pvtdata = (Pvt*) queue->data;
  free(pvtdata->get);
  free(pvtdata->put);
  free(pvtdata);
  free(queue);
}


int main(void) {

  return 1;
}
