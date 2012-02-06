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

static void swapvalues(RBNode* first, RBNode* second) {
    assert(first && second);
    RBNode temp = *first;

    first->computedkey = second->computedkey;
    first->value = second->value;

    second->computedkey = temp.computedkey;
    second->value = temp.value;
}

static inline void leftrotate(RBNode* src, RBNode* dst) {
    assert(src && dst);
    /** Reason we swap values is to contain the impact of rotation.
     *  If we didn't then the node in the Tree that points to dst
     *  would have to be fixed to point to src instead. Its easy to 
     *  avoid that by just copying the values (value + key) from 
     *  src to dst so the illusion is maintained.
     */
    swapvalues(src, dst);
    RBNode temp;
    temp = *src;

    temp.left = dst->left;
    temp.right = src->left;

    dst->left = src;
    dst->right = src->right;

    *src = temp;
}

static inline void rightrotate(RBNode* src, RBNode* dst) {
    assert(src && dst);
    swapvalues(src, dst);
    RBNode temp;
    temp = *src;

    temp.left = src->right;
    temp.right = dst->right;

    dst->right = src;
    dst->left = src->left;

    *src = temp;
}

typedef void (*rbvisitor)(RBNode*, void*arg);

/** For Iterative Inorder traversal, make a distinction between fwd pass and backwd pass
 *  by nix'ing the pointer
 */
#define BEENPUSHEDCOMPLETELY(addr) ((((uintptr_t)addr >> 1) << 1) != (uintptr_t)addr)
#define PUSHEDCOMPLETELY(addr) (void*)((uintptr_t)addr | 1)
#define GETADDR(addr)   (void*)(((uintptr_t)addr >> 1) << 1)

static uint32_t preordertraversal(RBTree* tree, RBNode* start, rbvisitor v, void* arg) {
    assert(tree && v && tree->stack);
    if (!start) goto preordertraversal_end;

    QFifo* fifo = tree->fifo;
    emptyFifo(fifo);

    put(fifo, start, 0);
    while (sizeFifo(fifo)) {
        uint32_t depth;
        RBNode* node = get(fifo, &depth);
        v(node, arg);
        if (node->left) put(fifo, node->left, depth + 1);
        if (node->right) put(fifo, node->right, depth + 1);
    }
preordertraversal_end:
    printf("%s: Height of Tree is %d\n", __FUNCTION__, maxDepthFifo(fifo));
    return maxDepthFifo(fifo);
}

/** returns depth of the tree. Tree with only a root is at depth 0 */
static uint32_t inordertraversal(RBTree* tree, RBNode* start, rbvisitor v, void* arg) {
    assert(tree && v && tree->stack);
    if (!start) goto traversal_end;

    Stack* stack = tree->stack;
    emptyStack(stack);

    pushStack(stack, start, 0);
    while (sizeStack(stack)) {
        uint32_t depth;
        RBNode* node = popStack(stack, &depth);
        RBNode* realnode = GETADDR(node);
        if (BEENPUSHEDCOMPLETELY(node)) {
            v(realnode, arg);
        } else {
            if (realnode->right) pushStack(stack, realnode->right, depth + 1);
            pushStack(stack, PUSHEDCOMPLETELY(realnode), depth);
            if (realnode->left) pushStack(stack, realnode->left, depth + 1);
        }
    }
traversal_end:
    printf("%s: Depth of Tree %d\n", __FUNCTION__, maxDepthStack(stack));
    return maxDepthStack(stack);
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
        .stack = exportStack(0x100),
        .fifo = exportQFifo(0x100)
    };
    return tree;
}

void freenodevisitor(RBNode* node, void* arg) {
    assert(node && !arg);
    //printf("%s: freeing node %p\n", __FUNCTION__, node);
    free(node);
}

void destroyRBTree(RBTree * tree) {
    assert(tree);
    preordertraversal(tree, tree->root, freenodevisitor, NULL);
    destroyStack(tree->stack);
    destroyQFifo(tree->fifo);
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
    printf("%s: node %p key %" PRIu64 "\n",
            __FUNCTION__, node, node->computedkey);
    if (0) {
        if (node->left) {
            printf("\tLeftChild  %p key %" PRIu64 "\n", node->left, node->left->computedkey);
        }
        if (node->right) {
            printf("\tRightChild %p key %" PRIu64 "\n", node->right, node->right->computedkey);
        }
    }
}

static void testtree() {
    if (0) preordertraversal(NULL, NULL, NULL, NULL);

    uint32_t a[] = {20, 2, 1, 7, 15, 3, 28, 31};
    const uint32_t SIZE = sizeof (a) / sizeof (a[0]);

    RBTree* tree = exportRBTree(keygen);
    assert(tree);

    for (uint32_t ctr = 0; ctr < SIZE; ctr++) {
        assert(insertKey(tree, &a[ctr], &a[ctr]));
    }

    if (1) inordertraversal(tree, tree->root, printvisitor, NULL);

    /** search for 2 and then 7, then we ll apply rotations on the tree */
    RBNode* two;
    search(tree, &a[1], &two);
    assert(*(uint32_t*) two->value == 2);
    RBNode* seven;
    search(tree, &a[3], &seven);
    assert(*(uint32_t*) seven->value == 7);

    /** Great now left rotate about two */
    leftrotate(seven, two);
    printf("done with rotation ... printing\n");

    if (1) inordertraversal(tree, tree->root, printvisitor, NULL);

    printf("done printing ...\n");

    /** RIGHT ROTATE AND GET THE ORIGINAL TREE BACK */
    search(tree, &a[1], &two);
    assert(*(uint32_t*) two->value == 2);
    search(tree, &a[3], &seven);
    assert(*(uint32_t*) seven->value == 7);
    printf("\n\n =============== RIGHT ROTATE ====\n");
    rightrotate(two, seven);
    if (1) inordertraversal(tree, tree->root, printvisitor, NULL);
    printf(".... PREORDER\n");
    if (1) preordertraversal(tree, tree->root, printvisitor, NULL);

    destroyRBTree(tree);
}

int main(void) {
    if (1) testtree();

    return 0;
}

