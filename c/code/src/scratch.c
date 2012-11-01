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


typedef struct {
    int type;
    int x;
    static_array(int, y, 4);
} ABC;

int main(void) {
    static_array(int, opttrans, 10);

    uint32_t index = random() % 12;
    set_array(opttrans, index, 10);
    printf("index %d value %d\n", index, get_array(opttrans, index));

    ABC local;
    index = random() % 5;
    set_array(local.y, index, 0x9);
    printf("index %x value %d\n", index, get_array(local.y, index));

    return EXIT_SUCCESS;
}

