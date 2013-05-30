#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

/** =====================================================
    Stack Implementation 
    =====================================================
*/
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
     return stack->data[stack->tos - 1];
}

static inline uint32_t pop(Stack *stack) {
     assert(stack->tos);
     stack->tos--;
     uint32_t val = stack->data[stack->tos];
     stack->data[stack->tos] = 0;
     return val;
}

static inline uint32_t getsize(Stack *stack) {
     return stack->tos;
}

static inline void push(Stack *stack, uint32_t data) {
     assert(stack->tos + 1 < MAXSIZE);
     stack->data[stack->tos] = data;
     stack->tos++;
}

static bool numexists(Stack *stack, uint32_t num) {
     for (uint32_t i = 0; i < stack->tos; ++i) {
          if (stack->data[i] == num) return true;
     }
     return false;
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
     Stack *stack = exportStack();

     /** Push all roots between 1 - 16 until a match is found */
     for (uint32_t j = 1; j < 17; j++) {
          printf("Search with ROOT %d begun\n", j);
          push(stack, j);

          uint32_t lastvalue = 0;
          bool backtrack = false;

          while(!isempty(stack)) {
               if (getsize(stack) == 16) {
                    printf("Combination found with root %d\n", j);
                    for (uint32_t i = 0; i < 16; ++i) {
                         printf("POS %d\tVAL: %d\n", i, stack->data[i]);
                    }
                    goto exit_cleanup;
               }

               uint32_t val = peek(stack);

               if (!backtrack) {
                    // FORWARD PATH
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
                    // BACKTRACK PATH
                    bool bfound = false;
                    for (uint32_t i = lastvalue + 1; i <= 16; ++i) {
                         if (checksquare(val + i) && !numexists(stack, i)) {
                              push(stack, i);
                              bfound = true;
                              backtrack = false;
                              break;
                         }
                    } 
                    if (!bfound) {
                         lastvalue = pop(stack);
                         backtrack = true;
                    }
               }
          }
          printf("Search with ROOT %d done\n", j);
     }

exit_cleanup:
     destroyStack(stack);

     return 0;
}
