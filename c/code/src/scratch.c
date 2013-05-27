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

static void stringcpy(const char *src, char *dst) {
  assert(src && dst);
  for (; (*dst = *src) && *src; src++, dst++) {
  }
}

static int stringcmp(const char *src, const char *dst, int *len) {
  int alen = 0;
  for (; *src && *dst && *dst == *src; src++, dst++, alen++);
  *len = alen;
  printf("%s: dst is at %c\n", __FUNCTION__, *dst);
  return *src - *dst;
}

static const char* strstr(const char *src, const char *dst) {
  assert(src && dst);
  const char *s;
  const char *d;
  for (; *src; ++src) {
    for (s = src, d = dst; *s && *d && *d == *s; s++, d++);
    if (!*d) return src;
  }
  return NULL;
}

int main(void) {
  if (0) {
  {
    char dst[100];
    printf("%s\n", stringrev("abc", dst));
    printf("%s\n", stringrev(" a b 123 c", dst));
  }

  {
    char src[20] = "abcccccccccc";
    src[2] = '\0';
    char adst[7] = "xxxxxx";
    stringcpy(src, adst);
    printf("%s\n", adst);
  }

  {
    const char src[] = "abc123";
    const char dst[] = "abc";
    int len = 0;
    printf("%d\n", stringcmp(dst, src, &len));
    printf("len %d\n", len);
  }
  }

  // strstr
  {
    const char src[] = "abc123xyz";
    const char dst[] = "1231";
    printf("%s\n", strstr(src, dst));
  }

  return 0;
}
