#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

static uint32_t reverse(uint32_t input) {
  uint32_t temp  = 0;

  while(input) {    
    temp  += input % 10;
    input /= 10;
    if (input) temp *= 10;
  }
  return temp;
}

static uint32_t countdigits(uint32_t a) {
  if (!a) return 1;

  uint32_t i = 0;
  for (; a; ++i) { 
    a /= 10;
  }
  return i;
}

static char* itoa(int a) {
  uint32_t digits = countdigits(a);
  char *str = calloc(digits + 1, sizeof(char));
  assert(str);

  int b = reverse(a);
  printf("input num %d reverse %d digits %d\n", 
         a, b, digits);

  for (uint32_t i = 0; i < digits; ++i) {
    uint8_t t = b % 10;
    printf("adding value %d to pos %d b is %d\n", 
           t, i, b);
    str[i] = t + 48;
    b /= 10;
  }

  /** add the null character */
  str[digits] = '\0';
  return str;
}

int main(void) {
  printf("%s\n", itoa(0));
  return 0;
}
