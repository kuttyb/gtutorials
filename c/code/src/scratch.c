#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

/** This is what the output should look like
(gdb) x /16xw mem
0x7fffffffe510:	0xf7b906e0	0x00007fff	0xf7abbea0	0x00007fff
0x7fffffffe520:	0x00000000	0x00000000	0x00f0b2e4	0x00000000
0x7fffffffe530:	0x00000009	0x00000000	0x000000c2	0x00000000
0x7fffffffe540:	0xffffe5ae     	0x00007fff      0x004006a0	0x00000000
*/

static uint32_t
asm_hexdump_uops(uint32_t ctr, uint32_t *mem, const uint32_t size, uint32_t uop)
{
  uint32_t index = ctr % size;
  if (!index && ctr) {

    for (uint32_t i = 0; i < size; ++i) {
      if (!(i % 4)) {
        printf("\n\t");
      }
      printf("0x%08x      ", mem[i]);
    }
  }
  mem[index] = uop;
  return ctr + 1;
}


int main(void) {
  // uops memory dump 
  const uint32_t hexdump_size = 16;  
  uint32_t hexdump_ctr = 0;
  uint32_t hexdump_mem[hexdump_size];

  for (uint32_t i = 0; i < 48; ++i) {
    hexdump_ctr = asm_hexdump_uops(hexdump_ctr, hexdump_mem, hexdump_size, i);
  }
  printf("\n");
  return EXIT_SUCCESS;
}

