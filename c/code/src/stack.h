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

#include <inttypes.h>
#include <assert.h>

typedef struct {
    void** data;
    uint32_t tos;
    uint32_t maxelements;
} Stack;

static inline Stack* exportStack(uint32_t maxsize) {
    assert(maxsize);
    Stack* stack = calloc(1, sizeof (Stack));
    assert(stack);
    *stack = (Stack){
        .data = calloc(maxsize, sizeof (void*)),
        .maxelements = maxsize,
        .tos = 0
    };
    return stack;
}

static inline void destroyStack(Stack* stack) {
    assert(stack && stack->data);
    assert(!stack->tos); /** warn if stack is not empty */
    free(stack->data);
    free(stack);
}

static inline void pushStack(Stack* stack, void* data) {
    assert(stack && data && (stack->tos + 1 < stack->maxelements));
    stack->data[stack->tos++] = data;
}

static inline void* popStack(Stack* stack) {
    assert(stack && stack->tos);
    void* data = stack->data[--stack->tos];
    return data;
}

static inline void emptyStack(Stack* stack) {
    assert(stack);
    stack->tos = 0;
}

static inline uint32_t sizeStack(Stack* stack) {
    assert(stack);
    return stack->tos;
}

#endif //__stack_h__
