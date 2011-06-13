#include <stdio.h>
#include <stdlib.h>

const char *strchr(const char *string, int c) {
  for ( ; (*string != '\0') && (*string != (char) c); string++){}

  if (*string == '\0') 
    return NULL;
  else 
    return string;
}

int main(void) {

  printf("testing strings\n");

  printf("PRINTING==> %s\n", strchr("this is the data", 'i'));
  
  return 1;
}

