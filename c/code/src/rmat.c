#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <assert.h>
#include "rmat.h"

/**
RMAT* exportRMAT(uint64_t phys_memory_max, uint32_t pagesize, uint32_t maxphases);
void destroyRMAT(RMAT*);
void incrementPhaseRMAT(RMAT*);
boolean putRMAT(RMAT*, uint64_t physaddr, uint64_t vaaddr, uint32_t pid);
 */

RMAT* exportRMAT(uint64_t phys_memory_max, uint32_t pagesize, uint32_t maxphases) {
    RMAT* rmat = calloc(1, sizeof (RMAT));
    assert(rmat);

    uint64_t num_phys_pages = phys_memory_max / pagesize;
    *rmat = (RMAT){
        .currentphase = 0,
        .phys_addr_table = calloc(num_phys_pages, sizeof (VAHashTable*))
    };
    assert(rmat->phys_addr_table);

    return rmat;
}

void destroyRMAT(RMAT* rmat) {
    assert(rmat && rmat->phys_addr_table);
    free(rmat->phys_addr_table);
}

int main(void) {
    RMAT* rmat = exportRMAT(0x10000000, 0x1000, 0x100);
    assert(rmat);
    destroyRMAT(rmat);

    return 0;
}
