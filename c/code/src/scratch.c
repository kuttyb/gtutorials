#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

static int atoi(const char *input) {
  /** non null input */
  assert(input);

  uint32_t i =   1;
  int      num = 0;
  char     temp;
  bool     bisnegative  = false;
  bool     bsignchecked = false;
  
  for (; *input; input++) {
    temp = *input;

    if (!bsignchecked) {
      if (temp == '-') {
        bisnegative  = true;
        bsignchecked = true;
      }
    }

    if ((temp > 57) || (temp < 48)) continue;


    int oldnum = num;
    num += i * (temp - 48);
    printf("char is %d i is %d num is %d\n", (temp - 48), i, num);
    assert(num >= oldnum); /** check for overflow */
    i *= 10;
    bsignchecked = true;
  }

  if (bisnegative)
    return num * -1;
  else 
    return num;
}

int main(void) {
  
  printf("%d\n", atoi( "- 10 $%23"));
  printf("%d\n", atoi( "10- $%23"));
  printf("%d\n", atoi( "1-0 $%23"));
  return 0;
}
