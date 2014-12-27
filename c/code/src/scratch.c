#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

static void* labels[10] = {};

void func(void * value) 
{
  static void* _labels[] = { &&label1, &&label2, &&label3 };

  if (!value) {    
    memcpy(labels, _labels, sizeof(_labels));
    return;
  }

  /* Do the opcode dispatch */
  goto *value;
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
  func(NULL);
  for (int i = 0; i < 10; ++i) {
    if (labels[i]) printf("\t%p\n", labels[i]);
  }

  func(labels[0]);  

  func(labels[2]);

  func(labels[1]);

  return 0;
}
