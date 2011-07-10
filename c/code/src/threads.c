#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sys/signal.h>
#include <pthread.h>
#include <unistd.h>
#include "types.h"


#define MAXTHREADS  (10)
#define MAXWRITES   (250)
#define SLEEPTIME   (2)
// Use Real Time Signals ... they can be queued, the regular ones cannot
#define SIGNUM      (SIGRTMIN + 1)

typedef struct {
    long id;
} PerThread;

int counter = 0;
void* threadfunction(void* arg) {
    PerThread *pThread = arg;
    printf("starting thread %ld and pid %d\n",
            pThread->id, getpid());
    
    const int max = MAXTHREADS * MAXWRITES;
    while (true) {
      int value = __sync_fetch_and_add(&counter, 0);
      if (value >= max) {
	printf("all writes visible exitting thread\n");
	break;
      }
    };

    return NULL;
}

void realhandler(int signo, siginfo_t *info, void *context) {
  //    printf("in the signal handler\n");
    __sync_add_and_fetch(&counter, 1);
}

int registerSignalHandler(int signum, void (*handler)(int, siginfo_t*, void*)) {
    struct sigaction action;
    action.sa_sigaction = handler;
    sigemptyset(&action.sa_mask);
    return sigaction(signum, &action, NULL);
}

int main(void) {
  /** register signal handler */
  assert(!registerSignalHandler(SIGNUM, realhandler));

  /** launch threads */
  pthread_t threads[MAXTHREADS];
  PerThread perThread[MAXTHREADS];

  for (int counter = 0; counter < MAXTHREADS; counter++) {
    perThread[counter].id = counter;
    assert(!pthread_create(&threads[counter], NULL, threadfunction, &perThread[counter]));
  }


  /** send them a few signals */

  /** unfortunately cant seem to get pthread_sigqueue to work ....
      but its ok .. we can pass value in separate per thread
      queues ... much easier
  */
  for (int counter = 0; counter < MAXWRITES; counter++) {
    for (int tid = 0; tid < MAXTHREADS; tid++) {
      pthread_kill(threads[tid], SIGNUM);
    }
  }


  /** party's over */
  for (int counter = 0; counter < MAXTHREADS; counter++) {
    pthread_join(threads[counter], NULL);
  }


  return 0;
}
