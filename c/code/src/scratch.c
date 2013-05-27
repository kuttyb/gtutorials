#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

int test(void) {
     return 3;
}

int main(void) {
     for (test(); test(); test()) {
          printf("3");
     }

    return 0;
}
