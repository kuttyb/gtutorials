#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FLAGS  (MAP_SHARED)
#define PROT   (PROT_WRITE    | PROT_READ)
#define SIZE   (1024 * 1024 * 100 * 2)
#define FILENAME "/home/kutty/daji/code/2/zero.dat"
#define CALLOC 1

int main(void) {
  char *buf = NULL;
#ifdef CALLOC
  buf = calloc(SIZE, 1);
  if (!buf) return 2;
#endif

  /** open a file and mmap it */
  int fd = open(FILENAME, O_RDWR);
  if (fd <0) return 2;
  char *ptr = mmap(buf, SIZE, PROT, FLAGS, fd, 0);
  if (!ptr) return 2;

  /** read only */
  printf("file mmaped\n");
  for(int counter = 0; counter < SIZE; counter++) {
    int value = ptr[counter];
    if (value == 2) {
      printf("this is definitely weird\n");
    }
    ptr[counter] = 10;
  }
  printf("done reading pages\n");


  /** munmap and close file */
  munmap(ptr, SIZE);
  close(fd);
#ifdef CALLOC
  free(buf);
#endif

  return 1;
}
