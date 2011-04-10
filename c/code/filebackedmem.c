#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "barrier.h"

#define SIZE   (1024 * 1024 * 50)
#define SLEEPTIME  (10)
/** TILING */
#define  NUMTILES  (4)
#define  TILESIZE  (SIZE / NUMTILES)

static void* allocmem(int *fd, long size) {
  int lfd   = open("storage.dat", O_RDWR | O_CREAT, 0700);
  if (posix_fallocate(lfd, 0, SIZE * sizeof(int))) return NULL;

  void* ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, lfd, 0);
  if (!ptr) return NULL;
  *fd       = lfd;

  madvise(ptr, size, MADV_SEQUENTIAL);
  return ptr;
}

static void freemem(int fd, void *ptr, long size) {
  munmap(ptr, size);
  close(fd);
}

static void flushinvalidate(void *ptr, long size) {
  barrier_full();
  msync(ptr, size, MS_SYNC);
  //  madvise(ptr, size, MADV_DONTNEED);
}


int main(void) {
  int fd;
  int *ptr = allocmem(&fd, SIZE * sizeof(int));
  if (!ptr) {
    printf("allocmem failed\n");
    return -2;
  }

  long       offset   = 0; 
  // do a scan and check for zero
  printf("scanning file\n");
  for (int index = 0; index < SIZE; index++, offset++) {
    if (ptr[offset] != 0) {
      printf("file not initialized correctly\n");
      break;
    }
  }
  printf("done scanning sleeping ...\n");
  sleep(5);

  printf("editting pages from %p\n", ptr);
  offset = 0;
  for (int index = 0; index < NUMTILES; index++, offset+=TILESIZE) {
    memset(&ptr[offset], 0x20, TILESIZE * sizeof(int));
    flushinvalidate(&ptr[offset], TILESIZE * sizeof(int)); // free behind
  }

  // verify writes
  offset = 0;
  for (int index = 0; index < SIZE; index++, offset++) {
    if (ptr[offset] != 0x20202020) {
      printf("value read back incorrect 0x%x\n", ptr[offset]);
      break;
    }
  }

  sleep(SLEEPTIME);
  printf("done reading pages\n");

  printf("waking up dong munmap next\n");
  freemem(fd, ptr, SIZE * sizeof(int));
  return 1;
}
