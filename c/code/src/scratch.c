#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>


int main(void) 
{
  static void* labels[] = { &&label1, &&label2 };
  goto *labels[1];

 label2:
  printf("statement just before the label\n");
  
 label1:
  printf("printing label\n");

  return 0;
}
