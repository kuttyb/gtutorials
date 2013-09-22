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
        .numvalidentries = 0,
        .phys_addr_table = calloc(num_phys_pages, sizeof (VAHashTable*))
    };
    assert(rmat->phys_addr_table);

    return rmat;
}

VAHashTable* exportVAHashTable(uint32_t maxphases) {
    assert(maxphases);
    VAHashTable* table = calloc(1, sizeof (VAHashTable));
    assert(table);
    const uint32_t size = MAX_VAALIASES_PER_PA * MAX_PIDS_ALIASING_VAPA * maxphases;
    *table = (VAHashTable){
        .entries = calloc(size, sizeof (Entry)),
        .maxentries = size,
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

static inline uint32_t get_va_and_phase(RMAT* rmat, uint32_t vaddr) {
    uint32_t va_and_phase = (vaddr >> rmat->pagesizelog) << rmat->pagesizelog;
    va_and_phase |= rmat->currentphase;
    return va_and_phase;
}

static inline void split_va_and_phase(RMAT* rmat, uint32_t va_and_phase, uint32_t* vaddr, uint32_t* phase) {
    assert(rmat && vaddr && phase);
    uint32_t mask = (1 << rmat->pagesizelog) - 1;
    *phase = va_and_phase & mask;

    va_and_phase >>= rmat->pagesizelog;
    va_and_phase <<= rmat->pagesizelog;
    *vaddr = va_and_phase;
}

boolean putRMAT(RMAT* rmat, uint64_t physaddr, uint64_t vaddr, uint32_t pid) {
    assert(rmat);
    uint64_t paindex = physaddr >> rmat->pagesizelog;
    VAHashTable* table = rmat->phys_addr_table[paindex];
    if (!table) {
        rmat->phys_addr_table[paindex] = exportVAHashTable(rmat->maxentries);
        table = rmat->phys_addr_table[paindex];
        rmat->numvalidentries++;
    }

    uint32_t va_and_phase = get_va_and_phase(rmat, vaddr);

    /** hash it */
    uint32_t index = va_and_phase % table->maxentries;
    uint32_t freeslot;
    boolean bfreeslotfound = false;

    /** Open Chain and Search : You re searching for a va_and_phase match and if found a pid match */
    for (uint32_t ctr = index; ctr < table->maxentries; ctr += MAX_PIDS_ALIASING_VAPA * rmat->maxphases) {
        if (table->entries[ctr].va_and_phase == va_and_phase) {
            /** linear scan pid list and add if not present */
            for (uint32_t i = 0; i < table->entries[ctr].numpids; i++) {
                if (table->entries[ctr].pids[i] == pid) {
                    return true; /** <PA,VA, phase, pid> tuple is already present do nothing, trivial 80% case*/
                }
            }
            /** so pid is not present add it if there space */
            if (table->entries[ctr].numpids < MAX_PIDS_ALIASING_VAPA) {
                table->entries[ctr].pids[table->entries[ctr].numpids++] = pid;
                return true;
            } else {
                /** no space left for pids, drop it!! */
                assert(false);
                return false;
            }
        } else if (table->entries[ctr].va_and_phase == 0) {
            /** Remember the nearest free slot in case we have to add va_and_phase */
            freeslot = ctr;
            bfreeslotfound = true;
        }
    }

    /** search from the top */
    for (uint32_t ctr = 0; ctr < index; ctr += MAX_PIDS_ALIASING_VAPA * rmat->maxphases) {
        if (table->entries[ctr].va_and_phase == va_and_phase) {
            /** linear scan pid list and add if not present */
            for (uint32_t i = 0; i < table->entries[ctr].numpids; i++) {
                if (table->entries[ctr].pids[i] == pid) {
                    /** <PA,VA, phase, pid> tuple is already present do nothing, the trivial 80% case*/
                    return true;
                }
            }
            /** so pid is not present add it if there space */
            if (table->entries[ctr].numpids < MAX_PIDS_ALIASING_VAPA) {
                table->entries[ctr].pids[table->entries[ctr].numpids++] = pid;
                return true;
            } else {
                /** no space left for pids, drop it!! */
                assert(false);
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

void printRMAT(RMAT* rmat) {
    assert(rmat);
    printf("--------------------------------------\n");
    printf("RMAT Header\n");
    printf("  PA_PAGESIZE   0x%x\n", 1 << rmat->pagesizelog);
    printf("  PHASES        0x%x\n", rmat->currentphase + 1);
    printf("  MAXENTRIES    0x%"PRIx64"\n", rmat->maxentries);
    printf("  VALIDENTRIES  0x%x\n", rmat->numvalidentries);
    printf("--------------------------------------\n");
    const uint32_t pagesize = 1 << rmat->pagesizelog;

    for (uint32_t ctr = 0; ctr < rmat->maxentries; ctr++) {
        VAHashTable* table = rmat->phys_addr_table[ctr];
        if (!table) continue;

        uint64_t paddr = pagesize * ctr;
        /** Parse VAHashTable */
        for (uint32_t i = 0; i < table->maxentries; i++) {
            uint32_t va_and_phase = table->entries[i].va_and_phase;
            if (!va_and_phase) continue;
            uint32_t vaddr;
            uint32_t phase;
            split_va_and_phase(rmat, va_and_phase, &vaddr, &phase);
            printf("\tPhase %d: PA 0x%"PRIx64" VA 0x%x\n",
                    phase, paddr, vaddr);
            for (uint32_t j = 0; j < table->entries[i].numpids; j++) {

                printf("\t\t\tPID %d\n", table->entries[i].pids[j]);
            }
        }
    }
    printf("--------------------------------------\n");
}

int main(void) {
    RMAT* rmat = exportRMAT(0x20000000, 0x1000, 0x100);
    assert(rmat);

    assert(putRMAT(rmat, 0x4000, 0x1000, 2));
    assert(putRMAT(rmat, 0x4000, 0x1000, 3));
    assert(putRMAT(rmat, 0x4000, 0x1000, 4));
    assert(putRMAT(rmat, 0x4000, 0x2000, 4));
    assert(putRMAT(rmat, 0x4000, 0x2000, 0));

    for (uint32_t i = 0; i < 0x1000; i++) {
        //assert(putRMAT(rmat, 0x4000, 0x2000 + i * 0x1000, 4));
        assert(putRMAT(rmat, 0x4000, 0x2000, 4));
    }

    incrementPhaseRMAT(rmat);

    assert(putRMAT(rmat, 0x4000, 0x1000, 2));
    assert(putRMAT(rmat, 0x4000, 0x1000, 3));
    assert(putRMAT(rmat, 0x4000, 0x1000, 4));
    assert(putRMAT(rmat, 0x10000, 0x2000, 4));
    assert(putRMAT(rmat, 0x4000, 0x2000, 0));

    for (uint32_t i = 0; i < 0x1000; i++) {
        //assert(putRMAT(rmat, 0x4000, 0x2000 + i * 0x1000, 4));
        assert(putRMAT(rmat, 0x4000, 0x2000, 4));
    }

    printRMAT(rmat);

    destroyRMAT(rmat);
    return 0;
}
