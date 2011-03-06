#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define SIZE   (1024 * 1024 * 500 * 1)
#define SLEEPTIME  (0)
/** TILING */
#define  NUMTILES  (4)
#define  TILESIZE  (SIZE / NUMTILES)

void* allocmem(int *fd, long size) {
  int lfd   = open("storage.dat", O_RDWR, 0700);
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
  __builtin_ia32_sfence();
  msync(ptr, size, MS_SYNC | MS_INVALIDATE);
  madvise(ptr, size, MADV_DONTNEED);
}


int main(void) {
  int fd;
  int *ptr = allocmem(&fd, SIZE * sizeof(int));
  if (!ptr) return -2;

  
  printf("sleeping right after allocation\n");
  sleep(SLEEPTIME);


  printf("editting pages from %p\n", ptr);
  long       offset   = 0; 
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
