#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

static uint16_t labels[10] = {};

static inline void copylabels(uint16_t * dst, const void ** src, uint8_t elements) {
  for (int i = 0; i < elements; ++i) {
    dst[i] = src[i] - src[0];
  }
}

#define  _SETUPLABELS  \
  if (value == 0xffff) {    \
    copylabels(labels, (const void **)_labels, sizeof(_labels) / sizeof(_labels[0]));\
    return;\
  }

void func(int value) 
{
  static void* _labels[] = { &&label1, &&label2, &&label3 };
  _SETUPLABELS

  /* Do the opcode dispatch */
  void * addr = &&label1 + value;
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

  for (int i = 0; i < 3; ++i) {
    printf("\n");
    func(labels[0]);  
    func(labels[2]);
    func(labels[1]);
  }

  return 0;
}
