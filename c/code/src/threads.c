#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sys/signal.h>
#include <pthread.h>
#include <unistd.h>


#define MAXTHREADS  (3)
#define SLEEPTIME   (2)
// Use Real Time Signals ... they can be queue, the regular ones cannot
#define SIGNUM      (SIGRTMIN + 1)

typedef struct {
    long id;
} PerThread;

void* threadfunction(void* arg) {
    PerThread *pThread = arg;
    printf("starting thread %ld and pid %d\n",
            pThread->id, getpid());

    while (1) {
    };

    return NULL;
}

void realhandler(int signo, siginfo_t *info, void *context) {
    printf("in the signal handler\n");
    printf("info->si_code=%d\n", info->si_code);
    // sleep(SLEEPTIME);
    printf("waking up from sleep\n");
}

int main(void) {
    /** register signal handler */
    {
        struct sigaction action;
        action.sa_sigaction = realhandler;
        sigemptyset(&action.sa_mask);
        action.sa_flags = SA_SIGINFO;
        assert(!sigaction(SIGNUM, &action, NULL));
    }

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
    printf("sending signal returned %s\n",
            strerror(pthread_kill(threads[0], SIGNUM)));
    printf("sending signal returned %s\n",
            strerror(pthread_kill(threads[0], SIGNUM)));
    printf("sending signal returned %s\n",
            strerror(pthread_kill(threads[0], SIGNUM)));
    printf("sending signal returned %s\n",
            strerror(pthread_kill(threads[0], SIGNUM)));


    /** party's over */
    for (int counter = 0; counter < MAXTHREADS; counter++) {
        pthread_join(threads[counter], NULL);
    }


    return 0;
}
