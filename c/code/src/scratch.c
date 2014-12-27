#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

static uint16_t labels[10] = {};

static inline void copylabels(uint16_t * dst, const void ** src, uint8_t elements) {
  for (int i = 0; i < elements; ++i) {
    dst[i] = src[i] - src[0];
  }
}

#define  _SETUPLABELS  \
  if (initialized == true) {    \
    copylabels(labels, (const void **)_labels, sizeof(_labels) / sizeof(_labels[0]));\
    return;\
  }

#define _DISPATCH \
{ \
void * addr = &&label1 + *code++; \
goto *addr; \
}

void func(uint16_t *code, bool initialized) 
{
  static void* _labels[] = { &&label1, &&label2, &&label3, &&label_exit };
  _SETUPLABELS;

  _DISPATCH;

 label1:
  printf("label 1\n");
  _DISPATCH;

 label2:
  printf("label 2\n");
  _DISPATCH;

 label3:
  printf("label 3\n");
  _DISPATCH;

 label_exit:
  printf("label exit\n");
  return;
}

int main(void) 
{
  /* To initialize the addresses */
  func(NULL, true);
  for (int i = 0; i < 3; ++i) {
    printf("\t0x%x\n", labels[i]);
  }

  func(labels, false);

  return 0;
}
