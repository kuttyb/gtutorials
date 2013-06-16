#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

int main(void) {
  unsigned int a = 0xaabbccdd;
  unsigned char *ptr;

  ptr = (unsigned char*)&a;

  // print from lower address to higher address 
  for (uint32_t i = 0; i < 4; ++i) {
    printf("ptr[%d] 0x%x\n", i, ptr[i]);
  }

  // change endianness
  for (uint32_t i = 0; i < 2; ++i) {
    unsigned char x = ptr[3 - i];
    ptr[3 - i] = ptr[i];
    ptr[i] = x;
  }

  printf("post endian conversion ...\n");
  for (uint32_t i = 0; i < 4; ++i) {
    printf("ptr[%d] 0x%x\n", i, ptr[i]);
  }


  return EXIT_SUCCESS;
}
