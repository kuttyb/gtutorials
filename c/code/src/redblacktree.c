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
        .stack = exportStack(32)
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
    uint32_t* ptr = input;
    return *ptr;
}

int main(void) {
    uint64_t a[] = {0, 1, 2, 3, 4, 5};

    if (0) swap(NULL, NULL);

    RBTree* tree = exportRBTree(keygen);
    assert(tree);

    assert(insertKey(tree, &a[3], &a[3]));
    assert(insertKey(tree, &a[1], &a[1]));
    assert(insertKey(tree, &a[0], &a[0]));
    assert(insertKey(tree, &a[2], &a[2]));

    assert(value(tree, &a[0]) == &a[0]);
    assert(value(tree, &a[1]) == &a[1]);
    assert(value(tree, &a[2]) == &a[2]);
    assert(value(tree, &a[3]) == &a[3]);

    destroyRBTree(tree);

    return 0;
}

