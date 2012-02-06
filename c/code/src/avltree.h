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
#ifndef __avltree_h__
#define __avltree_h__

#include <inttypes.h>
#include "stack.h"
#include "qfifo.h"

typedef enum {
    false, true
} boolean;

typedef struct _RBNode {
    uint64_t computedkey;
    void* value;

    /** pointers */
    struct _RBNode* left;
    struct _RBNode* right;
} RBNode;


typedef uint64_t(*rbcompute)(void*);

typedef struct {
    RBNode* root;
    rbcompute keygen;
    Stack* stack;
    QFifo* fifo;
} RBTree;

RBTree* exportRBTree(rbcompute);
void destroyRBTree(RBTree*);
void* value(RBTree*, void* key);

#endif //__avltree_h__
