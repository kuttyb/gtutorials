#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

int main(void) {
     uint32_t a = 0xc;
     uint32_t b = -a;
     float x = (float) (a & -a);
     
     printf("0x%x 0x%x 0x%x 0x%x\n", a, b, a & b, a & ~(a-1));
     printf("0x%x 0x%x\n", *(uint32_t*)&x, ((*(uint32_t*)&x) >> 23) - 127);
     
     

     return EXIT_SUCCESS;
}
