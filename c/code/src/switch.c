#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

int main(void) {
  uint32_t value = (uint32_t)random() % 0x1000;
  printf("value is %d\n", value);
  switch(value) {
  case 0: printf("0\n");break;
  case 1: printf("1\n");break;
  case 2: printf("2\n");break;
  case 3: printf("3\n");break;
  case 4: printf("4\n");break;
  case 0x1000: printf("0x1000\n"); break;
  }
  
  return 0;
}

