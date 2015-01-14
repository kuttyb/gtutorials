#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

/* TODO:
   =====
   [a] Add a Context which will contain the Register File, Code Pointer and Data Pointer
   [b] Add Code and Data next pointers in the Register File
   [c] Add Predicate Registers in the Register File
   [d] Add Class Selector (uses Code Pointer)
*/
static uint16_t OPCODES_CLASSA[10] = {};

static inline void copylabels(uint16_t * dst, const void ** src, uint8_t elements) {
  for (int i = 0; i < elements; ++i) {
    dst[i] = src[i] - src[0];
  }
}

#define  _SETUPLABELS  \
  if (initialized == true) {    \
    copylabels(opcode_table, (const void **)_labels, sizeof(_labels) / sizeof(_labels[0]));\
    return;\
  }

#define _DISPATCH \
{ \
void * addr = &&label_start + *code++; \
goto *addr; \
}

void func(uint16_t *code, bool initialized, uint16_t *opcode_table) 
{
  static void* _labels[] = { &&label_start, &&label1, &&label2, &&label_exit };
  _SETUPLABELS;

  _DISPATCH;

 label_start:
  {
    printf("label 0\n");
  }
  _DISPATCH;

 label1:
  {
  printf("label 1\n");
  }
  _DISPATCH;

 label2:
  {
    printf("label 2\n");
  }
  _DISPATCH;

 label_exit:
  {
    printf("label exit\n");
  }
  return;
}

int main(void) 
{
  /* To initialize the addresses */
  func(NULL, true, OPCODES_CLASSA);
  for (int i = 0; i < 3; ++i) {
    printf("\t0x%x\n", OPCODES_CLASSA[i]);
  }

  /* User submitted code buffer */
  uint16_t codebuffer[] = { 0, 0, 1, 2, 0, 1, 3 };

  /* Patch the buffer */
  for (int i = 0; i < sizeof(codebuffer) / sizeof(codebuffer[0]); ++i) {
    codebuffer[i] = OPCODES_CLASSA[codebuffer[i]];
  }

  func(codebuffer, false, NULL);

  return 0;
}
