#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

static uint16_t labels[10] = {};

void func(int value) 
{
  static void* _labels[] = { &&label1, &&label2, &&label3 };

  if (value == 0xffff) {    
    labels[0] = 0;
    labels[1] = _labels[1] - _labels[0];
    labels[2] = _labels[2] - _labels[0];
    return;
  }

  /* Do the opcode dispatch */
  void * addr = _labels[0] + value;
  goto *addr;

 label1:
  printf("label 1\n");
  return;

 label2:
  printf("label 2\n");
  return;

 label3:
  printf("label 3\n");
  return;
}

int main(void) 
{
  /* To initialize the addresses */
  func(0xffff);
  for (int i = 0; i < 3; ++i) {
    printf("\t0x%x\n", labels[i]);
  }

  func(labels[0]);  

  func(labels[2]);

  func(labels[1]);

  return 0;
}
