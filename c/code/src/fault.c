#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>

#define SIZE  (4096)

void *memptr;

void realhandler(int signo, siginfo_t *info, void *context) {
  printf("receive protection fault in the extended handler\n");
  printf("addr %p\n", info->si_addr);
  mprotect(memptr, SIZE * sizeof(int), PROT_READ | PROT_WRITE);
  printf("fixed memory restarting\n");
}

int main(void) {
  /** register fault handler */
  struct sigaction action;
  action.sa_sigaction  = realhandler;
  sigemptyset(&action.sa_mask);
  action.sa_flags      = SA_SIGINFO;
  assert(!sigaction(SIGSEGV, &action, NULL));
  
  /** allocate aligned memory */
  assert(!posix_memalign(&memptr, getpagesize(), SIZE * sizeof(int)));
  printf("buffer starts at %p\n", memptr);
  assert(!mprotect(memptr, SIZE * sizeof(int), PROT_NONE));

  /** cause the fault */
  int *ptr = memptr;
  //  ptr[0] = 0x10;
  if (ptr[0] == 0x0) {
    printf("read succeeded\n");
  }

  printf("done accessing the buffer\n");
  free(memptr);

  return 1;
}
