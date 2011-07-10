#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sys/signal.h>
#include <pthread.h>
#include <unistd.h>
#include "types.h"


#define MAXTHREADS  (10)
#define MAXWRITES   (5000)
#define SLEEPTIME   (2)
#define MAXPENDINGSIGNALS (10)
// Use Real Time Signals ... they can be queued, the regular ones cannot
#define SIGNUM      (SIGRTMIN + 1)

typedef struct {
    long id;
} PerThread;

int counter;
int registered;
int pendingSignals;

void realhandler(int signo, siginfo_t *info, void *context) {
  //printf("in the signal handler of thread %d\n", pthread_self());
    int temp = __sync_add_and_fetch(&counter, 1);
    __sync_fetch_and_sub(&pendingSignals, 1);
    if (!(temp % (MAXWRITES  * MAXTHREADS / 10))) {
      printf("signal handler: Current ticket %d\n", temp);
    }
}

int registerSignalHandler(int signum, void (*handler)(int, siginfo_t*, void*)) {
    struct sigaction action;
    action.sa_sigaction = handler;
    sigemptyset(&action.sa_mask);
    return sigaction(signum, &action, NULL);
}

void* threadfunction(void* arg) {
    assert(!registerSignalHandler(SIGNUM, realhandler));
    __sync_fetch_and_add(&registered, 1);
//    printf("thread registered signal handler\n");
    

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
  /** initialize globals */
  counter        = 0;
  registered     = 0;
  pendingSignals = 0;
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
      /** RT signals fail on backpressure .. add credits on the sender side */
      while(true) {
	int tempValue = __sync_add_and_fetch(&pendingSignals, 0);
	if (tempValue >= MAXPENDINGSIGNALS) continue;
	if (CAS(&pendingSignals, tempValue, tempValue + 1) == true)  {
	  break;
	} 
      }
	
      /** we have a token to send the signal */
      assert(!pthread_kill(threads[tid], SIGNUM));
    }
  }

  /** party's over */
  for (int counter = 0; counter < MAXTHREADS; counter++) {
    assert(!pthread_join(threads[counter], NULL));
  }


  return 0;
}
