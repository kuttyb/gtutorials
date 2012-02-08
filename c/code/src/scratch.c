#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

int main(void) {
  FILE* out = fopen("data.txt", "w+");
  assert(out);

  fprintf(out, "first src of data %s\n", "text");
  fprintf(out, "second line of text %s\n", "more text");

  fclose(out);
  return 0;
}

