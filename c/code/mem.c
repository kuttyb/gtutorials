#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "barrier.h"

#define SIZE   (1024 * 1024 * 100 * 1)
#define SLEEPTIME  (0)
/** TILING */
#define  NUMTILES  (4)
#define  TILESIZE  (SIZE / NUMTILES)
/** CONFIG */
#define  READ      (1)
#define  KONSTANT  (0xa)
#define  WRITE     (1)
#define  FILENAME  ("/dev/zero")

void* allocmem(int *fd, long size) {
  int lfd   = open(FILENAME, O_RDWR, 0700);
  void* ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, lfd, 0);
  *fd       = lfd;
  madvise(ptr, size, MADV_SEQUENTIAL);
  return ptr;
}

void freemem(int fd, void *ptr, long size) {
  munmap(ptr, size);
  close(fd);
}

void flushinvalidate(void *ptr, long size) {
  barrier_compiler();
  barrier_storestore();
  barrier_loadstore();
  msync(ptr, size, MS_SYNC | MS_INVALIDATE);
  //  madvise(ptr, size, MADV_DONTNEED);
}


int main(void) {
  long  offset;
  int   fd;
  char *ptr = allocmem(&fd, SIZE * sizeof(char));
  if (!ptr) return -2;

  if (WRITE) {
    printf("writing to pages from %p\n", ptr);
    offset   = 0; 
    for (int index = 0; index < NUMTILES; index++, offset+=TILESIZE) {
      memset(&ptr[offset], KONSTANT, TILESIZE * sizeof(char));
      flushinvalidate(&ptr[offset], TILESIZE * sizeof(char)); // free behind
    }
  }

  // verify writes
  if (READ) {
    printf("reading pages\n");
    offset = 0;
    char match = 1;
    for (int index = 0; index < SIZE; index++, offset++) {
      if (ptr[offset] != KONSTANT) {
	printf("value read back incorrect 0x%x\n", ptr[offset]);
	match = 0;
	break;
      }
    }
    if (match) {
      printf("reads match writes\n");
    }
  }

  if (READ || WRITE) {
    printf("freeing memory \n");
    freemem(fd, ptr, SIZE * sizeof(char));
  }

  return 1;
}
