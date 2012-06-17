#ifndef _inline_h_
#define _inline_h_

#include <inttypes.h>

#ifdef COMPILER_GCC
#define  ATTR_FACTORY inline __attribute__((always_inline)) __attribute__((malloc)) 
#else
#define  ATTR_FACTORY
#endif

typedef enum {
    FALSE, TRUE
} boolean;

typedef struct _List List;

struct _List {

    /** PRIVATE */
    enum {
        LIST, TREE, MAX
    } CLASSID;
    void* pvt[MAX];

    /** PROTECTED */
    struct {
        uint32_t size; /** Prot data, you can but please don't */
        void (*print)(List*);
    } Protected;

    /** PUBLIC */
    boolean(*addback)(List*, void*);
    boolean(*remove)(List*, void*);
};

/** STATICS */
/** Yep obeying Josh Bloch here, statics not ctors */
List * exportList();
List * exportTree();
void destroyList(List*);
void destroyTree(List*);

#endif //_inline_h
