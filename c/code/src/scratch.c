#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
  uint32_t  freq;
  uint32_t  voltage;
} Unit;

const Unit x[4]     =  { {1, 3}, {4, 9}, {12, 27}, {24, 108}};

float list[4] = {0.0f, 1.0f, 0.0f, 0.0f};

int main(void) 
{
  const float base_voltage_sq = x[1].voltage * x[1].voltage;
  for (uint32_t i = 2; i < 4; ++i) {
    list[i] = ((float)x[i].freq / (float)x[1].freq) * (((float)x[i].voltage * (float)x[i].voltage) / (float)base_voltage_sq);
  }

  for (uint32_t i = 0; i < 4; ++i) {
    printf("ratio  %f\n", list[i]);
  }

  return 0;
}
