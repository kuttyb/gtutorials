/**  Copyright 2012 Kutty Banerjee <kutty.banerjee@gmail.com> 
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "redblacktree.h"
#include "stack.h"

static void swap(RBNode* first, RBNode* second) {
    assert(first && second);
    RBNode temp = *first;
    first->computedkey = second->computedkey;
    first->left = second->left;
    first->right = second->right;
    first->value = second->value;

    second->computedkey = temp.computedkey;
    second->left = temp.left;
    second->right = temp.right;
    second->value = temp.value;
}

typedef void (*visitor)(RBNode*, void* arg);

static void traverse(RBTree* tree, visitor v, void* arg) {
    assert(tree);
    /** TODO write tree parse logic */
    v(tree->root, arg);
}

RBTree* exportRBTree(rbcompute keygen) {
    RBTree* tree = calloc(1, sizeof (RBTree));
    assert(tree);
    *tree = (RBTree){
        .keygen = keygen,
        .root = NULL
    };
    return tree;
}

void destroyRBTree(RBTree* tree) {
    assert(tree);
    traverse(tree, NULL, NULL); /** TODO wire up visitor that frees each node */
    free(tree);
}

boolean insertKey(RBTree* tree, void* key, void* value) {
    assert(tree && key);
    RBNode* node = calloc(1, sizeof (RBNode));
    assert(node);
    *node = (RBNode){
        .computedkey = tree->keygen(key),
        .left = NULL,
        .right = NULL,
        .value = value
    };
    return false;
}

int main(void) {
    if (0) swap(NULL, NULL);

    int a[] = {0, 1, 2, 3, 4, 5};
    const uint32_t size = sizeof (a) / sizeof (a[0]);

    Stack* stack = exportStack(10);
    for (uint32_t ctr = 0; ctr < size; ctr++) {
        pushStack(stack, &a[ctr]);
    }

    for (uint32_t ctr = 0; ctr < size; ctr++) {
        int* data = popStack(stack);
        assert(data);
        int index = size - ctr - 1;
        assert(index >= 0);
        assert(*data == a[index]);
    }

    destroyStack(stack);

    return 0;
}

