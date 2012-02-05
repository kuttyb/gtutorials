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

typedef void (*rbvisitor)(RBNode*, void*arg);

/** For Iterative Inorder traversal, make a distinction between fwd pass and backwd pass
 *  by nix'ing the pointer
 */
#define BEENPUSHEDCOMPLETELY(addr) ((((uintptr_t)addr >> 1) << 1) != (uintptr_t)addr)
#define PUSHEDCOMPLETELY(addr) (void*)((uintptr_t)addr | 1)
#define GETADDR(addr)   (void*)(((uintptr_t)addr >> 1) << 1)

static void inordertraversal(RBTree* tree, rbvisitor v, void* arg) {
    assert(tree && v);
    if (!tree->root) goto traversal_end;

    Stack* stack = tree->stack;
    emptyStack(stack);

    pushStack(stack, tree->root);
    while (sizeStack(stack)) {
        RBNode* node = popStack(stack);
        RBNode* realnode = GETADDR(node);
        if (BEENPUSHEDCOMPLETELY(node)) {
            v(realnode, arg);
        } else {
            if (realnode->right) pushStack(stack, realnode->right);
            pushStack(stack, PUSHEDCOMPLETELY(realnode));
            if (realnode->left) pushStack(stack, realnode->left);
        }
    }
traversal_end:
    printf("%s: Height of Tree is %d\n", __FUNCTION__, tree->stack->height);
}

/** Search for key, if found return true else return false and set lastnode to 
 *  the point of insertion.
 */
static boolean search(RBTree* tree, void* key, RBNode** lastnode) {
    assert(tree && key);
    RBNode* node = tree->root;

    if (!node) {
        *lastnode = NULL;
        return false;
    }

    uint64_t realkey = tree->keygen(key);
    boolean bFound = true;
    while (bFound) {
        if (realkey == node->computedkey) {
            break;
        }

        /**  move down ... */
        if (realkey <= node->computedkey) {
            if (node->left) {
                node = node->left;
            } else {
                bFound = false;
                break;
            }
        } else if (realkey >= node->computedkey) {
            if (node->right) {
                node = node->right;
            } else {
                bFound = false;
                break;
            }
        }
    }

    *lastnode = node;
    return bFound;
}

RBTree * exportRBTree(rbcompute keygen) {
    RBTree* tree = calloc(1, sizeof (RBTree));
    assert(tree);
    *tree = (RBTree){
        .keygen = keygen,
        .root = NULL,
        .stack = exportStack(0x100)
    };
    return tree;
}

void destroyRBTree(RBTree * tree) {
    assert(tree);
    //traverse(tree, NULL, NULL); /** TODO wire up visitor that frees each node */
    destroyStack(tree->stack);
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

    RBNode* lastnode;
    boolean bvalue = search(tree, key, &lastnode);
    if (bvalue) {
        /** key exists, just change its value */
        lastnode->value = value;
    } else {
        if (!lastnode) {
            /** add the root */
            tree->root = node;
            return true;
        }
        /** key doesn't exist, insert behind the last node */
        if (node->computedkey > lastnode->computedkey) {
            lastnode->right = node;
        } else {
            lastnode->left = node;
        }
    }

    /** TODO: Balance the Tree based on whether we re AVL or RB */

    return true;
}

void* value(RBTree* tree, void*key) {
    assert(tree && key);
    RBNode* node;
    if (search(tree, key, &node)) {
        return node->value;
    } else {
        return NULL;
    }
}

uint64_t keygen(void* input) {
    assert(input);
    uint32_t* ptr = input;
    return *ptr;
}

static void printvisitor(RBNode* node, void* arg) {
    assert(node && !arg);
    printf("%s: node has key %" PRIu64 " value %p\n",
            __FUNCTION__, node->computedkey, node->value);
}

int main(void) {
    if (0) swap(NULL, NULL);
    if (0) inordertraversal(NULL, NULL, NULL);

    uint32_t a[] = {20, 2, 1, 7, 15, 3, 28, 31};
    const uint32_t SIZE = sizeof (a) / sizeof (a[0]);

    RBTree* tree = exportRBTree(keygen);
    assert(tree);

    for (uint32_t ctr = 0; ctr < SIZE; ctr++) {
        assert(insertKey(tree, &a[ctr], &a[ctr]));
    }

    for (uint32_t ctr = 0; ctr < SIZE; ctr++) {
        assert(*(uint32_t*) value(tree, &a[ctr]) == a[ctr]);
    }

    inordertraversal(tree, printvisitor, NULL);

    destroyRBTree(tree);

    return 0;
}

