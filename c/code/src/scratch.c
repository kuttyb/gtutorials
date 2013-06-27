#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

int main(void) {
     uint32_t num = 0xaabbccdd;
     unsigned char *x = (unsigned char*) &num;

     uint8_t temp;
     temp = x[0];
     x[0] = x[3];
     x[3] = temp;

     temp = x[1];
     x[1] = x[2];
     x[2] = temp;

     printf("0x%x\n", num);

     return EXIT_SUCCESS;
}
