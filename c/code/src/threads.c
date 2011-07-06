#include <stdio.h>
#include <unistd.h>
#include <sys/signal.h>
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

  /** launch threads */
  for (int counter = 0; counter < 10; counter++) {
    perThread[counter].id = counter;
    assert(!pthread_create(&threads[counter], NULL, func, &perThread[counter]));
  }

  /** send them a few signals */
  printf("sending signal retvalue %d\n", pthread_kill(threads[0], 0));
  printf("sending signal retvalue %d\n", pthread_kill(threads[2], 0));

  /** party's over */
  for (int counter = 0; counter < 10; counter++) {
    pthread_join(threads[counter], NULL);
  }

  return 0;
}
