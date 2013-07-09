#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

__attribute__((noinline)) static void bottom(uintptr_t *addr) {
   int localvar = random() % 201;
   *addr = (uintptr_t)&localvar;
   printf("lower addr 0x%"PRIxPTR"\n", *addr);
}

__attribute__((noinline)) static bool grow_downwards(void) {
   int localvar = random() % 12;
   uintptr_t cur  = (uintptr_t)&localvar;
   printf("upper addr 0x%"PRIxPTR"\n", cur);

   uintptr_t next;
   bottom(&next);

   if (next < cur) 
      return true;
   else
      return false;
}

int main(void) {
     printf("Does stack grow downwards? %s\n",
            grow_downwards() ? "yes" : "no");
     
     return EXIT_SUCCESS;
}
