#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

uint32_t load_4b(uint64_t addr) {
  return 0xaabbccdd;
}

uint8_t load_1b(uint64_t addr) {
  uint32_t tmask     = (0xff << ((addr & 0x3) << 3));
  uint32_t data      = load_4b(addr & ~(0x3U)) & tmask;
  
  return (uint8_t)(data >> ((addr & 0x3) << 3));
}

int main(void) 
{
  printf("data is 0x%x\n", load_1b(0xab49));
	
  return 0;
}
