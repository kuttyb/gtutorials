#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "types.h"

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

static void* allocmem(int *fd, size_t size) {
    int lfd = open(FILENAME, O_RDWR, 0700);
    void* ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, lfd, 0);
    *fd = lfd;
    madvise(ptr, size, MADV_SEQUENTIAL);
    return ptr;
}

static void freemem(int fd, void *ptr, size_t size) {
    munmap(ptr, size);
    close(fd);
}

static void flushinvalidate(void *ptr, size_t size) {
    // test volatile integers
    _volatile var;
    volatile_store(var, 20);
    printf("volatile integer value %d\n", volatile_load(var));

    // test volatile pointers
    int rr = 21;
    _volatileptr regptr;
    volatileptr_store(regptr, &rr);
    printf("volatile pointer chasing %d\n", *((int*) volatileptr_load(regptr)));

    msync(ptr, size, MS_SYNC | MS_INVALIDATE);
    //  madvise(ptr, size, MADV_DONTNEED);
}

int testmem(void) {
    long offset;
    int fd;
    char *ptr = allocmem(&fd, SIZE * sizeof (char));
    if (!ptr) return -2;

    if (WRITE > 0) {
        printf("writing to pages from %p\n", ptr);
        offset = 0;
        for (int index = 0; index < NUMTILES; index++, offset += TILESIZE) {
            memset(&ptr[offset], KONSTANT, TILESIZE * sizeof (char));
            flushinvalidate(&ptr[offset], TILESIZE * sizeof (char)); // free behind
        }
    }

    // verify writes
    if (READ > 0) {
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
        freemem(fd, ptr, SIZE * sizeof (char));
    }

}
