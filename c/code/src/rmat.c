#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <assert.h>
#include "rmat.h"

/**
void incrementPhaseRMAT(RMAT*);
boolean putRMAT(RMAT*, uint64_t physaddr, uint64_t vaaddr, uint32_t pid);
 */

RMAT* exportRMAT(uint64_t phys_memory_max, uint32_t pagesize, uint32_t maxphases) {
    assert(phys_memory_max && pagesize && maxphases);

    RMAT* rmat = calloc(1, sizeof (RMAT));
    assert(rmat);

    uint64_t num_phys_pages = phys_memory_max / pagesize;
    *rmat = (RMAT){
        .currentphase = 0,
        .maxentries = num_phys_pages,
        .phys_addr_table = calloc(num_phys_pages, sizeof (VAHashTable*))
    };
    assert(rmat->phys_addr_table);

    return rmat;
}

VAHashTable* exportVAHashTable(uint32_t maxphases) {
    assert(maxphases);
    VAHashTable* table = calloc(1, sizeof (VAHashTable));
    assert(table);
    table->entries = calloc(maxphases * MAX_ALIASES_PER_PA, sizeof (Entry));
    assert(table->entries);
    return table;
}

void destroyVAHashTable(VAHashTable* table) {
    assert(table && table->entries);
    free(table->entries);
    free(table);
}

void destroyRMAT(RMAT* rmat) {
    assert(rmat && rmat->phys_addr_table);

    for (uint32_t ctr = 0; ctr < rmat->maxentries; ctr++) {
        if (rmat->phys_addr_table[ctr])
            destroyVAHashTable(rmat->phys_addr_table[ctr]);
    }
    free(rmat->phys_addr_table);
}

int main(void) {
    RMAT* rmat = exportRMAT(0x10000000, 0x1000, 0x100);
    assert(rmat);
    destroyRMAT(rmat);

    return 0;
}
