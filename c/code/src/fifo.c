#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include "fifo.h"
#include "barrier.h"

typedef struct {
  int  *get;
  int  *put;
  int   capacity;
} Pvt;

/**
Queue* create(int size);
void   destroy(Queue*);
void   put(Queue*,void*);
void*  get(Queue*);
*/

Queue* create(int size) {
  Pvt* pvt = calloc(1, sizeof(Pvt));
  if (!pvt) return NULL;
  
  posix_memalign((void**)&pvt->get, getpagesize() * 16, sizeof(int));
  posix_memalign((void**)&pvt->put, getpagesize() * 16, sizeof(int));
  pvt->capacity = 0;

  Queue* retvalue = calloc(1, sizeof(Queue*));
  retvalue->data = pvt;

  return retvalue;
}


int main(void) {

  return 1;
}
