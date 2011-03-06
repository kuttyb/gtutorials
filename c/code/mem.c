#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>

#define FLAGS  (MAP_ANONYMOUS | MAP_SHARED)
#define PROT   (PROT_WRITE    | PROT_READ)
#define SIZE   (1024 * 1024 * 500 * 1)
#define SLEEPTIME  (8)
/** TILING */
#define  NUMTILES  (4)
#define  TILESIZE  (SIZE / NUMTILES)


int main(void) {
  int *ptr = mmap(NULL, SIZE * sizeof(int), PROT, FLAGS, -1, 0);
  if (!ptr) return -2;
  
  printf("sleeping right after allocation\n");
  sleep(SLEEPTIME);


  printf("editting pages from %p\n", ptr);
  long       offset   = 0; 
  for (int index = 0; index < NUMTILES; index++, offset+=TILESIZE) {
    memset(&ptr[offset], 0x20, TILESIZE * sizeof(int));
    // free behind
    msync(&ptr[offset], TILESIZE * sizeof(int), MS_SYNC | MS_INVALIDATE);
    madvise(&ptr[offset], TILESIZE * sizeof(int), MADV_DONTNEED);
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
  munmap(ptr, SIZE * sizeof(int));
  return 1;
}
