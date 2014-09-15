#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
  uint64_t min_time;
  uint64_t max_time;
  uint64_t sum;
  uint64_t count;
} Stats;

static void dump_stats(Stats *input, bool force_print, uint64_t value) {
  static uint32_t counter = 0;
  
  if ((!(counter % 5)) || force_print) {
    printf("kbb: Stats (current_value 0x%llx:\n", value);
    printf("kbb: \tMin:   0x%llx\nkbb:\tMax:   0x%llx\nkbb:\tAvg:   0x%llx\nkbb:\tCt:    0x%llx\n\n",
	   input->min_time, input->max_time, input->sum / input->count, input->count);
  } 

  if (!force_print) 
    counter++;
}

static inline void update_interval(Stats *input, uint64_t value) {

  if (value < input->min_time) 
    input->min_time = value;
  else if (value > input->max_time) 
    input->max_time = value;

  input->sum += value;
  input->count++;

  dump_stats(input, false, value);
}

int main(void) 
{
  Stats a = (Stats) {
    .min_time  = 0x0ULL - 1,
    .max_time  = 0ULL,
    .sum       = 0ULL,
    .count     = 0,
  };

  const uint64_t intervals[12] = {
    1, 2, 3, 4, 5, 6,
    7, 8, 9, 10, 11, 12
  };

  for (uint32_t i = 0; i < 12; ++i) {
    update_interval(&a, intervals[i]);
  }

  dump_stats(&a, true, 0);

  return 0;
}
