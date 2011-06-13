#include <stdio.h>
#include <stdlib.h>

const char *strchr(const char *string, int c) {
  for ( ; (*string != '\0') && (*string != (char) c); string++){}

  if (*string == '\0') 
    return NULL;
  else 
    return string;
}

char *strncpy(const char *src, char *dst, int len) {
  char *s = dst;
  for (; (len-- > 0) && (*s++ = *src++) != '\0';) {}

  return dst;
}

int main(void) {

  printf("testing strings\n");

  printf("PRINTING==> %s\n", strchr("this is the data", 'i'));
 
  char *src = "first input buffer";
  char *dst = calloc(200, sizeof(char));

  printf("copying ==> %s\n", strncpy(src, dst, 4));
 
  free(dst);

  return 1;
}

