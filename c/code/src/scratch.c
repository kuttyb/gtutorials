#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

#define MAXSIZE   (20)

typedef _Stack {
     uint32_t data[MAXSIZE];
     uint32_t tos;
} Stack;

static inline boolean isempty(Stack *stack) {
     if (!stack->tos) 
          return true;
     else 
          return false;
}

static  inline uint32_t peek(Stack *stack) {
     assert(stack->tos);
     return stack->tos;
}

static inline uint32_t pop(Stack *stack) {
     assert(stack->tos);
     stack->tos--;
     return stack->data[stack->tos];
}

static inline void push(Stack *stack, uint32_t data) {
     assert(stack->tos + 1 < MAXSIZE);
     stack->data[stack->tos] = data;
     stack->tos++;
}


int main(void) {
    return 0;
}
