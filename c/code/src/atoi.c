#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

// ================================================================
// For reverse multiply temp by 10 and for atoi multiply diff by 10
// ================================================================
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
    num += (temp -48) * i;
    // printf("char is %d i is %d num is %d\n", (temp - 48), i, num);
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
  assert(atoi( "- 10 $%23") == -1023);
  assert(atoi( "10- $%23")  == 1023);
  assert(atoi( "1-0 $%23")  == 1023);

  assert(reverse(1234) == 4321);
  assert(reverse(1023) == 3201);
  assert(reverse(130)  == 31);

  return 0;
}
