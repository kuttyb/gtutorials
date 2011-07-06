#ifndef __fifo_h__
#define __fifo_h__

typedef struct {
  void *data;
} Queue;

Queue* create(int size);
void   destroy(Queue*);
void   put(Queue*,void*);
void*  get(Queue*);

#endif //__fifo_h__
