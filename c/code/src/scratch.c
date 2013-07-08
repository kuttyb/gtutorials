#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

int main(void) {
     uint32_t a = 0xfffffffe;
     int b = a;

     printf("0x%x 0x%x\n", a, b);

     return EXIT_SUCCESS;
}

