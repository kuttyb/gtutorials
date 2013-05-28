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

int main(void) {
     printf("0x%x\n", getmask(4, 1));
     printf("0x%x\n", getval(0xf, 3, 1));
    return 0;
}
