#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
  uint64_t min_time;
  uint64_t max_time;
  uint64_t avg_time;
  uint64_t count;
} Stats;

static void dump_stats(Stats *input, bool force_print) {
  static uint32_t counter = 0;
  
  if ((!(counter % 5)) || force_print) {
    printf("kbb: Stats:\n");
    printf("kbb: \tMin:   0x%llx\nkbb:\tMax:   0x%llx\nkbb:\tAvg:   0x%llx\nkbb:\tCt:    0x%llx\n\n",
	   input->min_time, input->max_time, input->avg_time, input->count);
  } 

  if (!force_print) 
    counter++;
}

static inline void update_interval(Stats *input, uint64_t value) {

  if (value < input->min_time) 
    input->min_time = value;
  else if (value > input->max_time) 
    input->max_time = value;

  input->avg_time = ((input->avg_time * input->count) + value) / (input->count + 1);
  input->count++;

  dump_stats(input, false);
}

int main(void) 
{
  Stats a = (Stats) {
    .min_time  = 0x0ULL - 1,
    .max_time  = 0ULL,
    .avg_time  = 0ULL,
    .count     = 0,
  };

  const uint64_t intervals[12] = {
    0x10, 0x20, 0x10, 0x30, 0x40, 0x10,
    0x40, 0x90, 0x2,  0x30, 0x40, 0x10,
  };

  for (uint32_t i = 0; i < 12; ++i) {
    update_interval(&a, intervals[i]);
  }

  dump_stats(&a, true);

  return 0;
}
