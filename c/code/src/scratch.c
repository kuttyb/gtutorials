#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

static inline uint32_t logbase(uint32_t input) {
    uint32_t ctr = 0;
    printf("log of %d is ", input);
    for (; input >>= 1; ctr++) {
    }
    printf("%d\n", ctr);
    return ctr;
}

int main(void) {
    logbase(0x1000);
    logbase(0x10);
    logbase(0x3);
    logbase(0x5);
    return 0;
}

