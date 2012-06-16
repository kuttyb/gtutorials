#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>
#include "inline.h"

int main(void) {
    List* list = exportList();
    assert(list->addback(list, list) == false);
    assert(list->remove(list, list) == false);
    destroyList(list);

    list = exportTree();
    assert(list->addback(list, list) == true);
    assert(list->remove(list, list) == false);
    destroyTree(list);

    return EXIT_SUCCESS;
}
