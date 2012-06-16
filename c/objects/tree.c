#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <assert.h>
#include "inline.h"

typedef struct {
    uint32_t max;
} PvtData;
#define GETDATA(list)  ((PvtData*)list->pvt[TREE])

static boolean _addback(List* list, void* arg) {
    assert(list && arg);
    PvtData* pvt = GETDATA(list);
    assert(pvt && pvt->max == 10);
    return TRUE;
}


ATTR_FACTORY List* exportTree() {
    List* list = exportList();
    PvtData* pvt = calloc(1, sizeof (PvtData));
    assert(list && pvt);
    *pvt = (PvtData){
        .max = 10,
    };
    list->pvt[TREE] = pvt;
    list->addback = _addback;
    return list;
}

void destroyTree(List* list) {
    assert(list);
    free(GETDATA(list));
    destroyList(list);
}
