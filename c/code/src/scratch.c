#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

#define MAXSIZE   (20)

typedef struct _Stack {
     uint32_t data[MAXSIZE];
     uint32_t tos;
} Stack;

static Stack *exportStack(void) {
     Stack* stack = calloc(1, sizeof(Stack));
     assert(stack);
     *stack = (Stack) {
          .tos = 0
     };
     memset(&stack->data, 0, MAXSIZE * sizeof(uint32_t));
     return stack;
}

void destroyStack(Stack *stack) {
     assert(stack);
     free(stack);     
}

static inline bool isempty(Stack *stack) {
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

static inline uint32_t getsize(Stack *stack) {
     return stack->tos;
}

static inline void push(Stack *stack, uint32_t data) {
     assert(stack->tos + 1 < MAXSIZE);
     stack->data[stack->tos] = data;
     stack->tos++;
}


int main(void) {
     Stack *stack = exportStack();
     assert(isempty(stack));
     assert(!getsize(stack));

     push(stack, 1);
     push(stack, 2);
     assert(getsize(stack) == 2);
     assert(!isempty(stack));
     assert(peek(stack) == 2);

     assert(pop(stack) == 2);
     assert(pop(stack) == 1);
     assert(isempty(stack));
     assert(!getsize(stack));


     return 0;
}
