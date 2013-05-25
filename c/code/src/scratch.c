#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

static uint32_t atoi(const char *input) {
  assert(input);
  uint32_t i =   1;
  uint32_t num = 0;
  char     temp;
  for (; *input; input++) {
    temp = *input;
    if ((temp > 57) || (temp < 48)) continue;
    uint32_t oldnum = num;
    uint8_t  x = temp - 48;
    num += x ? i * x : i;
    assert(num >= oldnum); /** check for overflow */
    i *= 10;    
  }
  return num;
}

int main(void) {
  
  printf("%d\n", atoi( " 1 $%23"));
  return 0;
}
