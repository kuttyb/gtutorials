#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

int main(void) {
     int a = -10;
     int b = -3;
     int c = 200;
     int d = 5000;

     printf("0x%x 0x%x 0x%x\n", a, b, a ^ b);

     printf("0x%x 0x%x 0x%x\n", c, d, c ^ d);

     printf("0x%x 0x%x 0x%x\n", a, c, a ^ c);

     return EXIT_SUCCESS;
}

