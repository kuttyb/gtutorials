#ifndef __fifo_h__
#define __fifo_h__

typedef struct {
  void *data;
} Queue;

void   put(Queue*,void*);

void*  get(Queue*);

int    size(Queue*);

#endif //__fifo_h__
