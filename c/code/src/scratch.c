#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

static uint32_t stringlen(const char *str) {
  uint32_t len = 0;
  for (; *str; str++, len++);
  return len;
}

static char* stringrev(const char *src, char *dst) {
  assert(src && dst);
  uint32_t len = stringlen(src);
  
  for (uint32_t i = 0; i < len; i++) {
    dst[i] = src[len - 1 - i];
  }
  dst[len] = '\0';
  return dst;
}

int main(void) {
  char dst[100];
  printf("%s\n", stringrev("abc", dst));
  printf("%s\n", stringrev(" a b 123 c", dst));

  return 0;
}
