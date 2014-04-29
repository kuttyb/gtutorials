#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
  uint32_t  freq;
  uint32_t  voltage;
} Unit;

typedef struct {
  float  freq;
  float  voltage;
} Ratio;

const Unit x[4]     =  { {1, 3}, {4, 9}, {12, 27}, {24, 108}};
Ratio      list[4]  =  { {0.0f, 0.0f}, {1.0f, 1.0f}, {12, 5}, {24, 6}};

int main(void) 
{
#if 0
  for (uint32_t i = 0; i < 4; ++i) {
    printf("freq %d voltage %d\n", x[i].freq, x[i].voltage);
  }
#endif
  
  for (uint32_t i = 2; i < 4; ++i) {
    list[i].freq     = x[i].freq     / x[i-1].freq;
    list[i].voltage  = x[i].voltage  / x[i-1].voltage;
  }

  for (uint32_t i = 0; i < 4; ++i) {
    printf("ratio: freq %f voltage %f\n", list[i].freq, list[i].voltage);
  }

  return 0;
}
