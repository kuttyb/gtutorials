#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <inttypes.h>
#include <assert.h>


int main(void) {
  const ssize_t size = 0x4000000;
  const int data = 0xabcdabcd;
  uint32_t *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
  assert(ptr);

  printf("accessing memory %p size 0x%lx\n", ptr, size);

  uint32_t i = 0;
  for (i = 0; i < 10; i++) {
    uint32_t ctr = 0;
    for (ctr = 0; ctr < size/sizeof(uint32_t); ctr++) {
      ptr[ctr] = data;
      if(ptr[ctr] != data) {
	printf("got garbage 0x%x at ctr 0x%x\n", ptr[ctr], ctr);
      }
    }
  }

  printf("done about to free\n");

  munmap(ptr, 0x1000);
  return 0;
}
