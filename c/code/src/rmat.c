#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <assert.h>
#include "rmat.h"

RMAT* exportRMAT(uint64_t phys_memory_max, uint32_t pagesize, uint32_t maxphases) {
    assert(phys_memory_max && pagesize && maxphases);

    RMAT* rmat = calloc(1, sizeof (RMAT));
    assert(rmat);

    uint64_t num_phys_pages = phys_memory_max / pagesize;
    *rmat = (RMAT){
        .currentphase = 0,
        .maxentries = num_phys_pages,
        .maxphases = maxphases,
        .pagesizelog = logbase(pagesize),
        .phys_addr_table = calloc(num_phys_pages, sizeof (VAHashTable*))
    };
    assert(rmat->phys_addr_table);

    return rmat;
}

VAHashTable* exportVAHashTable(uint32_t maxphases) {
    assert(maxphases);
    VAHashTable* table = calloc(1, sizeof (VAHashTable));
    assert(table);
    *table = (VAHashTable){
        .entries = calloc(maxphases * MAX_ALIASES_PER_PA, sizeof (Entry)),
        .maxentries = maxphases * MAX_ALIASES_PER_PA
    };
    assert(table->entries);
    return table;
}

void destroyVAHashTable(VAHashTable* table) {
    assert(table && table->entries);
    free(table->entries);
    free(table);
}

boolean putRMAT(RMAT* rmat, uint64_t physaddr, uint64_t vaddr, uint32_t pid) {
    assert(rmat);
    uint64_t paindex = physaddr >> rmat->pagesizelog;
    VAHashTable* table = rmat->phys_addr_table[paindex];
    if (!table) {
        table = exportVAHashTable(rmat->maxentries);
        rmat->phys_addr_table[paindex] = table;
    }

    uint32_t va_and_phase = (vaddr >> rmat->pagesizelog) << rmat->pagesizelog;
    va_and_phase |= rmat->currentphase;

    /** hash it */
    uint32_t index = va_and_phase % table->maxentries;

    /** open chain and search */
    uint32_t freeslot;
    boolean balreadypresent = false;
    boolean bfreeslotfound = false;
    for (uint32_t ctr = index; ctr < table->maxentries; ctr++) {
        if (table->entries[ctr].va_and_phase == va_and_phase) {
            /** linear scan pid list and add if not present */
            balreadypresent = true;
        } else if (table->entries[ctr].va_and_phase == 0) {
            freeslot = ctr; /** thats right choose the latest one to minimize memory distance */
            bfreeslotfound = true;
        }
    }

    /** search from the top */
    if (balreadypresent == false) {
        for (uint32_t ctr = 0; ctr < index; ctr++) {
            if (table->entries[ctr].va_and_phase == va_and_phase) {
                /** TODO linear scan pid list and add if not present */
            } else if (table->entries[ctr].va_and_phase == 0) {
                freeslot = ctr; /** thats right choose the latest one to minimize memory distance */
                bfreeslotfound = true;
            }
        }
    }

    if (balreadypresent == false) {
        if (bfreeslotfound == true) {
            table->entries[freeslot].va_and_phase = va_and_phase;
            /** TODO insert pid */
            return true;
        }
    }

    return false;
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
