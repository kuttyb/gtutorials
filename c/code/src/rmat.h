#ifndef __rmat_h__
#define __rmat_h__

#include <inttypes.h>

/** Reverse Mapped Access Table */
typedef enum {
    false, true
} boolean;

/** These are the separate ProcessIDs that can share the same VA/PA during the same phase */
#define  MAX_PIDS_PER_ENTRY    (0x10) 
#define  MAX_ALIASES_PER_PA    (0x10)

typedef struct {
    /** putting these together is to speed up the everyday case where PA-VA hit several
     *  times during the same phase, avoid array look up 
     */
    uint32_t va_and_phase;
    uint8_t pids[MAX_PIDS_PER_ENTRY];
}
Entry;

/** Each Entry contains <Key, Value> tuple
       where:
       Key    = VA + PhaseID
       Value  = Array<Pid>
 */
typedef struct {
    Entry* entries;
    uint32_t maxentries;
} VAHashTable;

typedef struct {
    VAHashTable** phys_addr_table;
    uint64_t maxentries;
    uint32_t maxphases;
    uint32_t pagesizelog;
    uint32_t currentphase;
} RMAT;

RMAT* exportRMAT(uint64_t phys_memory_max, uint32_t pagesize, uint32_t maxphases);
void destroyRMAT(RMAT*);
VAHashTable* exportVAHashTable(uint32_t maxphases);
boolean putRMAT(RMAT*, uint64_t physaddr, uint64_t vaaddr, uint32_t pid);

static inline void incrementPhaseRMAT(RMAT* rmat) {
    assert(rmat);
    uint32_t max = 1 << rmat->pagesizelog;
    if (rmat->currentphase < max) {
        rmat->currentphase++;
    } else {
        assert(0);
    }
}

static inline uint32_t logbase(uint32_t input) {
    uint32_t ctr = 0;
    for (; input >>= 1; ctr++) {
    }
    return ctr;
}

#endif //__rmat_h__
