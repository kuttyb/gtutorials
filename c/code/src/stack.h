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
#ifndef __stack_h__
#define __stack_h__

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

typedef struct {
    void** data;
    uint32_t* depth;
    uint32_t tos;
    uint32_t maxelements;
    uint32_t maxdepth;
} Stack;

static inline Stack* exportStack(uint32_t maxsize) {
    assert(maxsize);
    Stack* stack = calloc(1, sizeof (Stack));
    assert(stack);
    *stack = (Stack){
        .data = calloc(maxsize, sizeof (void*)),
        .maxelements = maxsize,
        .depth = calloc(maxsize, sizeof (uint32_t)),
        .maxdepth = 0,
        .tos = 0
    };
    assert(stack->data && stack->depth);
    return stack;
}

static inline void destroyStack(Stack* stack) {
    assert(stack && stack->data && stack->depth);
    assert(!stack->tos); /** warn if stack is not empty */
    free(stack->data);
    free(stack->depth);
    free(stack);
}

static inline void pushStack(Stack* stack, void* data, uint32_t depth) {
    assert(stack);
    if ((stack->tos + 1) >= stack->maxelements) {
        printf("%s: error, tos %d maxelements %d\n", __FUNCTION__, stack->tos, stack->maxelements);
        assert(0);
        return;
    }
    stack->data[stack->tos] = data;
    stack->depth[stack->tos++] = depth;
    if (depth > stack->maxdepth) {
        stack->maxdepth = depth;
    }
}

static inline void* popStack(Stack* stack, uint32_t* depth) {
    assert(stack && stack->tos && stack->depth && depth);
    void* data = stack->data[--stack->tos];
    *depth = stack->depth[stack->tos];
    return data;
}

static inline void emptyStack(Stack* stack) {
    assert(stack);
    stack->tos = 0;
    stack->maxdepth = 0;
}

static inline uint32_t sizeStack(Stack* stack) {
    assert(stack);
    return stack->tos;
}

static inline uint32_t maxDepthStack(Stack* stack) {
    assert(stack);
    return stack->maxdepth;
}

static inline void printStack(Stack* stack) {
    assert(stack);
    for (uint32_t ctr = 0; ctr < stack->tos; ctr++) {
        printf("%s: Stack[%d]=%p\n", __FUNCTION__, ctr, stack->data[ctr]);
    }
}

#endif //__stack_h__
