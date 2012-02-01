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
        .maxentries = maxphases * MAX_ALIASES_PER_PA,
    };
    assert(table->entries);
    /** Init Entries */
    for (uint32_t ctr = 0; ctr < table->maxentries; ctr++) {
        table->entries[ctr].numpids = 0;
    }
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
    uint32_t freeslot;
    boolean bfreeslotfound = false;

    /** Open Chain and Search : You re searching for a va_and_phase match and if found a pid match */
    for (uint32_t ctr = index; ctr < table->maxentries; ctr++) {
        if (table->entries[ctr].va_and_phase == va_and_phase) {
            /** linear scan pid list and add if not present */
            for (uint32_t i = 0; i < table->entries[ctr].numpids; i++) {
                if (table->entries[ctr].pids[i] == pid) {
                    return true; /** <PA,VA, phase, pid> tuple is already present do nothing, trivial 80% case*/
                }
            }
            /** so pid is not present add it if there space */
            if (table->entries[ctr].numpids < MAX_PIDS_PER_ENTRY) {
                table->entries[ctr].pids[table->entries[ctr].numpids++] = pid;
                return true;
            } else {
                /** no space left for pids, drop it!! */
                return false;
            }
        } else if (table->entries[ctr].va_and_phase == 0) {
            /** Remember the nearest free slot in case we have to add va_and_phase */
            freeslot = ctr;
            bfreeslotfound = true;
        }
    }

    /** search from the top */
    for (uint32_t ctr = 0; ctr < index; ctr++) {
        if (table->entries[ctr].va_and_phase == va_and_phase) {
            /** linear scan pid list and add if not present */
            for (uint32_t i = 0; i < table->entries[ctr].numpids; i++) {
                if (table->entries[ctr].pids[i] == pid) {
                    /** <PA,VA, phase, pid> tuple is already present do nothing, the trivial 80% case*/
                    return true;
                }
            }
            /** so pid is not present add it if there space */
            if (table->entries[ctr].numpids < MAX_PIDS_PER_ENTRY) {
                table->entries[ctr].pids[table->entries[ctr].numpids++] = pid;
                return true;
            } else {
                /** no space left for pids, drop it!! */
                return false;
            }
        } else if (table->entries[ctr].va_and_phase == 0) {
            /** Remember the nearest free slot in case we have to add va_and_phase */
            freeslot = ctr;
            bfreeslotfound = true;
        }
    }

    /** Too bad, va_and_phase was not found, add it if theres a freeslot found amd create a new Entry */
    if (bfreeslotfound == true) {
        table->entries[freeslot].va_and_phase = va_and_phase;
        table->entries[freeslot].pids[0] = pid;
        table->entries[freeslot].numpids = 1;
        return true;
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
