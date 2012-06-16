#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <assert.h>
#include "inline.h"

typedef struct {
    uint32_t start;
    uint32_t end;
} PvtData;
#define GETDATA(list)  (PvtData*)list->pvt[LIST]

static boolean _addback(List* list, void* arg) {
    assert(list && arg);
    PvtData* data = GETDATA(list);
    ++data->end;
    ++data->start;
    list->Protected.print(list);
    return FALSE;
}

static boolean _remove(List* list, void* arg) {
    assert(list && arg);
    return FALSE;
}

static void _printList(List* list) {
    PvtData* data = GETDATA(list);
    printf("%s: size is %d start %d end %d\n",
            __FUNCTION__, list->Protected.size,
            data->start, data->end);
}

ATTR_FACTORY List* exportList() {
    List* list = calloc(1, sizeof (List));
    PvtData* pvt = calloc(1, sizeof (PvtData));
    assert(pvt && list);
    *list = (List){
        .pvt[LIST] = pvt,
        .addback = _addback,
        .remove = _remove,
        .Protected.print = _printList,
        .Protected.size = 21,
    };
    return list;
}

void destroyList(List* list) {
    assert(list);
    free(GETDATA(list));
    free(list);
}
