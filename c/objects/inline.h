#ifndef _inline_h_
#define _inline_h_

#include <inttypes.h>
#include <stdbool.h>

#define  ATTR_FACTORY inline __attribute__((always_inline)) __attribute__((malloc)) 

typedef enum {
    FALSE, TRUE
} boolean;

typedef struct _List List;

struct _List {
    /** private */
    enum {
        LIST, TREE, MAX
    } CLASSID;
    void* pvt[MAX];
    /** public */
    boolean(*addback)(List*, void*);
    boolean(*remove)(List*, void*);
};

/** Factories */
List * exportList();
List * exportTree();
void destroyList(List*);
void destroyTree(List*);

#endif //_inline_h
