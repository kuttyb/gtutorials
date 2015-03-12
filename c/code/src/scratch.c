#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

typedef struct {
  uint32_t flag;
  uint64_t source;
} __attribute__((packed, aligned(8))) Data;

int main(void) 
{
  Data data;

  printf("data %p flag %p source %p\n",
	 &data, &data.flag, &data.source);

  data.flag = 0x10;
  data.source = 0;

  printf("0x%x 0x%llx\n", data.flag, data.source);

  return 0;
}


/*
  Output with "packed"
data 0x7fff500b2aa0 flag 0x7fff500b2aa0 source 0x7fff500b2aa4
0x10 0x0

  Output with "packed" dropped
data 0x7fff58989aa0 flag 0x7fff58989aa0 source 0x7fff58989aa8
0x10 0x0
*/
