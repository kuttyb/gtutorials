#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>
#include "inline.h"

int main(void) {
    List* list = exportList();
    assert(list->addback(list, list) == FALSE);
    assert(list->remove(list, list) == FALSE);
    destroyList(list);

    list = exportTree();
    assert(list->addback(list, list) == TRUE);
    assert(list->remove(list, list) == FALSE);
    destroyTree(list);

    return EXIT_SUCCESS;
}
