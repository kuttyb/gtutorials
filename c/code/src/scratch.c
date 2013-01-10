#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

static uint32_t
asm_hexdump_getbase(uint32_t input, uint32_t size) {
  if (!input) return 0;

  if (!(input % size)) {
    return input - size;
  } else {
    return (input / size) * size;
  }
}

static uint32_t
asm_hexdump_uops(uint32_t ctr, uint32_t *mem, const uint32_t size, uint32_t uop,
                 bool forceflush)
{
  uint32_t index = ctr % size;

  // print out old entries and clear array
  if (forceflush || (!index && ctr)) {
    uint32_t base = asm_hexdump_getbase(ctr, size) * 4;
    uint32_t i;
    for (i = 0; i < size; ++i) {
      if (!(i % 4)) {
        printf("\n0x%08x:     ", base);
        base += 16;
      }
      printf("0x%08x      ", mem[i]);
    }
    memset(mem, 0, size * sizeof(uint32_t));
  }
  
  if (!forceflush) mem[index] = uop;

  return ctr + 1;
}

int main(void) {
  // uops memory dump 
  const uint32_t hexdump_size = 16;  
  uint32_t hexdump_ctr = 0;
  uint32_t hexdump_mem[hexdump_size];
  memset(hexdump_mem, 0, hexdump_size * sizeof(uint32_t));

  for (uint32_t i = 0; i < 80; ++i) {
    hexdump_ctr = asm_hexdump_uops(hexdump_ctr, hexdump_mem, hexdump_size, i, false);
  }
  asm_hexdump_uops(hexdump_ctr, hexdump_mem, hexdump_size, 0, true);
  printf("\n");
  return EXIT_SUCCESS;
}


/** This is what the output should look like
(gdb) x /16xw mem
0x7fffffffe510:	0xf7b906e0	0x00007fff	0xf7abbea0	0x00007fff
0x7fffffffe520:	0x00000000	0x00000000	0x00f0b2e4	0x00000000
0x7fffffffe530:	0x00000009	0x00000000	0x000000c2	0x00000000
0x7fffffffe540:	0xffffe5ae     	0x00007fff      0x004006a0	0x00000000
*/
