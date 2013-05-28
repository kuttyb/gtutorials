#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

static inline uint32_t getmask(uint32_t hi, uint32_t lo) {
     uint32_t mask =  1 << (hi - lo + 1);
     mask -= 1;
     mask <<= lo;
     return mask;
}

static inline uint32_t getval(uint32_t val, uint32_t hi, 
                              uint32_t lo) {
     return (val & getmask(hi, lo)) >> lo;
}


static inline uint32_t countsetbits(uint32_t val) {
     uint32_t ctr = 0;
     for (; val ; ctr++) {
          val &= val - 1;
     }
     return ctr;
}
 
int main(void) {
     printf("%d\n", countsetbits(5));
     printf("%d\n", countsetbits(3));
     printf("%d\n", countsetbits(0));
     printf("%d\n", countsetbits(1));
    return 0;
}
