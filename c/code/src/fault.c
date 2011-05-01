#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>


#define SIZE  (4096)

void *memptr;

void handler(int signum) {
  printf("received protection fault\n");
  mprotect(memptr, SIZE * sizeof(int), PROT_READ | PROT_WRITE);
  printf("fixed memory restarting \n");
}

int main(void) {
  /** register fault handler */
  struct sigaction action;
  action.sa_handler  = handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags    = 0;
  assert(!sigaction(SIGSEGV, &action, NULL));
  
  /** allocate aligned memory */
  assert(!posix_memalign(&memptr, getpagesize(), SIZE * sizeof(int)));
  assert(!mprotect(memptr, SIZE * sizeof(int), PROT_READ));

  /** cause the fault */
  int *ptr = memptr;
  for (int counter = 0; counter < SIZE; counter++) {
    if (ptr[counter] ==  0x10) {
      printf("ooops\n");
    }
    ptr[counter] = 0x1;
  }
  
  printf("done accessing the buffer\n");
  free(memptr);

  return 1;
}
