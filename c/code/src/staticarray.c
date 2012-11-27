#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

#define static_array(T, var, e) \
    struct { \
        T data[e]; \
    } var;
#define array_size(var)    (sizeof(var.data) / sizeof(var.data[0]))
#define set_array(var, index, value)   ({ assert(index < array_size(var)); var.data[index] = value; })
#define get_array(var, index)    ({ assert(index < array_size(var)); var.data[index]; })
#define foreach_array(var, ptr)  for (uint32_t ctr = 0; (ctr < array_size(var)) && (ptr = &var.data[ctr]); \
                                      ++ctr)
#define foreach_range_array(var, ptr, start, end) for (uint32_t ctr = start; (ctr < array_size(var)) && \
                                                       (ctr < end) && (ptr = &var.data[ctr]); ++ctr)

typedef struct {
    int type;
    int x;
    static_array(unsigned char, y, 4);
} ABC;

ABC local;

int main(void) {
    for (uint32_t i = 0; i < 4; ++i) {
        set_array(local.y, i, i + 1);
    }

    // test individual set/get
    set_array(local.y, 2, 0);
    printf("index %x value %d\n", 0, get_array(local.y, 0));

    // test basic iterator
    unsigned char *ptr;
    foreach_array(local.y, ptr) {
        printf("%d\n", *ptr);
    }

    // test range iterator
    foreach_range_array(local.y, ptr, 1, 2) {
        printf("range: %d\n", *ptr);
    }

    // test range iterator overflow
    foreach_range_array(local.y, ptr, 0, 200) {
      printf("overflow_test: %d\n", *ptr);
    }

    return EXIT_SUCCESS;
}

