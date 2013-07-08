#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

int main(void) {
     unsigned int a = 0x2;

     printf("0x%x 0x%x 0x%x\n", a, -a, ~a + 1);
     
     a = a * -1;
     if (a < 0) {
          printf("bad\n");
     }

     return EXIT_SUCCESS;
}

