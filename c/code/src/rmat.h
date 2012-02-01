#ifndef __rmat_h__
#define __rmat_h__

#include <inttypes.h>

/** Reverse Mapped Access Table */
typedef enum {
    false, true
} boolean;

#define  MAX_PIDS_PER_ENTRY    (0x10) /** These are the separate ProcessIDs that can share the same VA/PA during the same phase */

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
} VAHashTable;

typedef struct {
    VAHashTable** phys_addr_table;
    uint32_t currentphase;
} RMAT;

RMAT* exportRMAT(uint64_t phys_memory_max, uint32_t pagesize, uint32_t maxphases);
void destroyRMAT(RMAT*);
void incrementPhaseRMAT(RMAT*);
boolean putRMAT(RMAT*, uint64_t physaddr, uint64_t vaaddr, uint32_t pid);

#endif //__rmat_h__
