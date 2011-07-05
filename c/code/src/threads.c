#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>

typedef struct {
  long id;
} PerThread;


void* func(void* arg) {
  PerThread *pThread = arg;
  printf("starting thread %ld\n", pThread->id);
  sleep(2);
  return NULL;
}


int main(void) {
  pthread_t threads[10];
  PerThread perThread[10];

  for (int counter = 0; counter < 10; counter++) {
    perThread[counter].id = counter;
    pthread_create(&threads[counter], NULL, func, &perThread[counter]); 
  }

  for (int counter = 0; counter < 10; counter++) {
    pthread_join(threads[counter], NULL);
  }

  return 0;
}
