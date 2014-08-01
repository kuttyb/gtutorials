#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

uint32_t load_4b(uint64_t addr) {
  return 0xaabbccdd;
}

uint8_t load_1b(uint64_t addr) {
  const uint8_t  sft    = (addr & 0x3) << 3;
  uint32_t       data   = load_4b(addr & ~(0x3U)) & (0xff << sft);
  return (uint8_t)(data >> sft);
}

uint16_t load_2b(uint64_t addr) {
  const uint8_t  sft    = (addr & 0x3) << 3;
  uint32_t       data   = load_4b(addr & ~(0x3U)) & (0xffff << sft);
  return (uint16_t)(data >> sft);
}

int main(void) 
{
#if 0
  printf("data is 0x%x\n", load_1b(0xab44));
  printf("data is 0x%x\n", load_1b(0xab45));
  printf("data is 0x%x\n", load_1b(0xab46));
  printf("data is 0x%x\n", load_1b(0xab47));
#endif

  printf("data is 0x%x\n", load_2b(0xab44));
  printf("data is 0x%x\n", load_2b(0xab45));
  printf("data is 0x%x\n", load_2b(0xab46));
  printf("data is 0x%x\n", load_2b(0xab47));

  return 0;
}
