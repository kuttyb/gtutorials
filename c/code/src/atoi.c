#include <stdio.h>
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
    //    printf("char is %d i is %d num is %d\n", (temp - 48), i, num);
    assert(num >= oldnum); /** check for overflow */
    i *= 10;
    bsignchecked = true;
  }

  num = reverse(num);

  if (bisnegative)
    return num * -1;
  else 
    return num;
}

int main(void) {

  if (1) {  
  printf("%d\n", atoi( "- 10 $%23"));
  printf("%d\n", atoi( "10- $%23"));
  printf("%d\n", atoi( "1-0 $%23"));
  }

  //  printf("%d\n", reverse(1234));
  return 0;
}
