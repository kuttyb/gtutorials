#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

#define bitfor(t, num)  for(; num && ((t = num & 1) || 1); num>>=1)

int main(void) {
     uint32_t a = 0xa;
     uint32_t t;
     bitfor(t, a) {
          printf("%d\n", t);
     }

     return EXIT_SUCCESS;
}
