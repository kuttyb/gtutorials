#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sys/signal.h>
#include <pthread.h>
#include <unistd.h>
#include "types.h"


#define MAXTHREADS  (4)
#define MAXWRITES   (4)
#define SLEEPTIME   (2)
// Use Real Time Signals ... they can be queued, the regular ones cannot
#define SIGNUM      (SIGRTMIN + 1)

typedef struct {
    long id;
} PerThread;

int counter;
int registered;

void realhandler(int signo, siginfo_t *info, void *context) {
  printf("in the signal handler of thread %d\n", pthread_self());
    __sync_add_and_fetch(&counter, 1);
}

int registerSignalHandler(int signum, void (*handler)(int, siginfo_t*, void*)) {
    struct sigaction action;
    action.sa_sigaction = handler;
    sigemptyset(&action.sa_mask);
    return sigaction(signum, &action, NULL);
}

void* threadfunction(void* arg) {
    PerThread *pThread = arg;
    printf("starting thread %ld and pid %d\n",
            pThread->id, getpid());
    assert(!registerSignalHandler(SIGNUM, realhandler));
    __sync_fetch_and_add(&registered, 1);
    printf("thread registered signal handler\n");
    

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

int main(void) {
  counter = 0;
  registered = 0;
  barrier_write();

  /** launch threads */
  pthread_t threads[MAXTHREADS];
  PerThread perThread[MAXTHREADS];

  for (int counter = 0; counter < MAXTHREADS; counter++) {
    perThread[counter].id = counter;
    assert(!pthread_create(&threads[counter], NULL, threadfunction, &perThread[counter]));
  }


  /** wait till they ve registered signal handlers before sending signals */
  printf("main thread: waiting for worker threads to setup handlers\n");
  boolean value = false;
  do {
    int local = __sync_add_and_fetch(&registered, 0);
    if (local >= MAXTHREADS) break;
  } while(value == false);

  printf("about to send signals ...\n");

  for (int counter = 0; counter < MAXWRITES; counter++) {
    for (int tid = 0; tid < MAXTHREADS; tid++) {
      assert(!pthread_kill(threads[tid], SIGNUM));
    }
  }


  /** party's over */
  for (int counter = 0; counter < MAXTHREADS; counter++) {
    assert(!pthread_join(threads[counter], NULL));
  }


  return 0;
}
