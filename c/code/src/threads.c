#include <stdio.h>
#include <unistd.h>
#include <sys/signal.h>
#include <pthread.h>
#include <assert.h>

#define MAXTHREADS  (3)
#define SLEEPTIME   (2)

typedef struct {
  long id;
} PerThread;


void* threadfunction(void* arg) {
  PerThread *pThread = arg;
  printf("starting thread %ld\n", pThread->id);
  
  while(1) {};

  return NULL;
}

void realhandler(int signo, siginfo_t *info, void *context) {
  printf("in the signal handler\n");
  printf("info->si_code=%d\n", info->si_code); 
  sleep(SLEEPTIME);
  printf("waking up from sleep\n");
}


int main(void) {
  /** register signal handler */
  {
    struct sigaction action;
    action.sa_sigaction  = realhandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags      = SA_SIGINFO;
    assert(!sigaction(SIGUSR1, &action, NULL));
  }

  {
    struct sigaction action;
    action.sa_sigaction  = realhandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags      = SA_SIGINFO;
    assert(!sigaction(SIGUSR2, &action, NULL));
  }


  /** launch threads */
  pthread_t threads[MAXTHREADS];
  PerThread perThread[MAXTHREADS];

  for (int counter = 0; counter < MAXTHREADS; counter++) {
    perThread[counter].id = counter;
    assert(!pthread_create(&threads[counter], NULL, threadfunction, &perThread[counter]));
  }


  /** send them a few signals */
  printf("sending signal retvalue %d\n", pthread_kill(threads[0], SIGUSR1));
  printf("sending signal retvalue %d\n", pthread_kill(threads[0], SIGUSR1));

  /** party's over */
  for (int counter = 0; counter < MAXTHREADS; counter++) {
    pthread_join(threads[counter], NULL);
  }


  return 0;
}
