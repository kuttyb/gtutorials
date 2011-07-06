/** Lockless fifo */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include "fifo.h"
#include "barrier.h"
#include "types.h"

/** Pointer Manipulation */
#define  SETCONSUMED(ptr)            ((void*)((unsigned long)ptr | 1))
#define  REALPTR(ptr)                ((void*)(((unsigned long)ptr >> 1) << 1))
#define  TESTINITIALIZED(ptr)        (ptr != NULL)
#define  TESTNOTINITIALIZED(ptr)     (ptr == NULL)
#define  TESTCONSUMED(ptr)           (REALPTR(ptr) != ptr)
#define  TESTNOTCONSUMED(ptr)        (REALPTR(ptr) == ptr)

/** FIFO Invariants */
#define ISEMPTY(get, put, size) ({boolean a = false; if (get == put) a = true; a;})
#define ISFULL(get, put, size)  ({boolean a = false; if (get == ((put + 1) % size)) a = true; a;})
#define INCREMENT(var, maxelements) ((var + 1) % maxelements)

typedef struct {
    int *get;
    int *put;
    void **fifodata;
    int maxelements;
} Pvt;
#define GETPVT(queue) ((Pvt*)queue->data)

Queue* create(int maxelements) {
    Pvt* pvt = calloc(1, sizeof (Pvt));
    assert(pvt);

    /** find out a good way to get dcache size */
    assert(!posix_memalign((void**) &pvt->get, getpagesize() * 16, sizeof (int)));
    assert(!posix_memalign((void**) &pvt->put, getpagesize() * 16, sizeof (int)));
    assert(!posix_memalign((void**) &pvt->fifodata, getpagesize(), maxelements * sizeof (void*)));
    pvt->maxelements = maxelements;

    Queue* retvalue = calloc(1, sizeof (Queue*));
    retvalue->data = pvt;

    return retvalue;
}

void destroy(Queue* queue) {
    assert(queue && queue->data);

    Pvt* pvtdata = GETPVT(queue);
    free(pvtdata->get);
    free(pvtdata->put);
    free(pvtdata);
    free(queue);
}

void put(Queue* queue, void* input) {
    assert(queue && queue->data && input);
    Pvt* pvtdata = GETPVT(queue);

    /** contend with consumer and other producers to get your own unique put location */
    boolean value = false;
    int localput;
    do {
        localput = *pvtdata->put;
        if (ISFULL(*pvtdata->get, localput, pvtdata->maxelements)) continue;
        value = CAS(pvtdata->put, localput, INCREMENT(localput, pvtdata->maxelements));
    } while (value == false);

    /** at this point you are the only producer that owns localput .. go ahead and modify array */
    while (TESTINITIALIZED(pvtdata->fifodata[localput]) && TESTNOTCONSUMED(pvtdata->fifodata[localput])) {
    }

    /** at this point the data is ready to be written previuos owners have moved out */
    pvtdata->fifodata[localput] = input;
    barrier_write();
}

void* get(Queue* queue) {
    assert(queue && queue->data);
    Pvt* pvtdata = GETPVT(queue);

    int localget;
    boolean value = false;
    do {
        localget = *pvtdata->get;
        if (ISEMPTY(localget, *pvtdata->put, pvtdata->maxelements)) continue;
        value = CAS(pvtdata->get, localget, INCREMENT(localget, pvtdata->maxelements));
    } while (value == false);

    /** at this point consumer owns this slot */
    while (TESTNOTINITIALIZED(pvtdata->fifodata[localget]) || TESTCONSUMED(pvtdata->fifodata[localget])) {
    }

    void *data = pvtdata->fifodata[localget];
    pvtdata->fifodata[localget] = SETCONSUMED(pvtdata->fifodata[localget]);
    barrier_write();

    return data;
}

int main(void) {

    Queue* queue = create(200);
    assert(queue);

    int a[] = {2, 3, 4};

    put(queue, &a[0]);
    put(queue, &a[1]);

    int *one = (int*) get(queue);
    assert(*one == 2);
    one = (int*) get(queue);
    assert(*one == 3);

    destroy(queue);
    return 1;
}
