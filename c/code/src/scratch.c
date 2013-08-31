#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

typedef uint32_t (^ fptr)(uint32_t a);

void execute(fptr a, uint32_t input) {
  uint32_t value = a(input);
  printf("returned value of closure was %d\n", value);
}

int main(void) {
  uint32_t value = 23;
  execute(^(uint32_t input) {
      printf("speaking from inside a closure with value %d\n", input);
      return input + 10;
    }, value);
  
  value++;
  printf("local value is %d\n", value);
  
    return EXIT_SUCCESS;
}
