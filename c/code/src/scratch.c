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
     printf("%s: value %d totalelements %d\n", 
            __FUNCTION__, stack->data[stack->tos - 1],
          stack->tos);
     return stack->data[stack->tos - 1];
}

static inline uint32_t pop(Stack *stack) {
     assert(stack->tos);
     stack->tos--;
     uint32_t val = stack->data[stack->tos];
     stack->data[stack->tos] = 0;
     printf("%s: value %d totalelements %d\n",
            __FUNCTION__, val, stack->tos);
     return val;
}

static inline uint32_t getsize(Stack *stack) {
     return stack->tos;
}

static inline void push(Stack *stack, uint32_t data) {
     assert(stack->tos + 1 < MAXSIZE);
     stack->data[stack->tos] = data;
     stack->tos++;
     printf("%s: value %d totalelements %d\n",
            __FUNCTION__, data, stack->tos);
}

static bool numexists(Stack *stack, uint32_t num) {
     for (uint32_t i = 0; i < stack->tos; ++i) {
          if (stack->data[i] == num) return true;
     }
     return false;
}

void teststack(void) {
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

     push(stack, 2);
     push(stack, 3);
     push(stack, 4);
     push(stack, 5);
     assert(pop(stack) == 5);
     for (uint32_t i = 0; i < MAXSIZE; ++i) {
          printf("stack[%d] = %d\n", i, stack->data[i]);
     }
     printf("tos %d\n", stack->tos);

     assert(!numexists(stack, 5));
     assert(numexists(stack, 2));
     assert(numexists(stack, 3));
     assert(numexists(stack, 4));
     assert(!numexists(stack, 0));
}

static bool checksquare(uint32_t num) {
     if ((num == 4) ||  (num == 9) ||
         (num == 16) || (num == 25)) {
          return true;
     } else {
          return false;
     }
}

int main(void) {
//     teststack();
     Stack *stack = exportStack();
     push(stack, 1);

     uint32_t lastvalue = 0;
     bool backtrack = false;
     while(!isempty(stack) || (getsize(stack) != 16)) {
          uint32_t val = peek(stack);

          if (!backtrack) {
               // Find the next element on the forward path
               bool bfound = false;
               for (uint32_t i = 1; i <= 16; ++i) {
                    if (checksquare(val + i) && !numexists(stack, i)) {
                         push(stack, i);
                         bfound = true;
                         break;
                    }
               }
               if (!bfound) {
                    lastvalue = pop(stack);
                    backtrack = true;
               }
          } else {
               // Backtrack path
               bool bfound = false;
               for (uint32_t i = lastvalue + 1; i <= 16; ++i) {
                    if (checksquare(val + i) && !numexists(stack, i)) {
                         push(stack, i);
                         bfound = true;
                         backtrack = false;
                    }
               } 
               if (!bfound) {
                    lastvalue = pop(stack);
                    backtrack = true;
               }
          }
     }


     destroyStack(stack);

     return 0;
}
