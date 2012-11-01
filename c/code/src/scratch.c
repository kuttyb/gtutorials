#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

#define static_array(T, var, e)  \
    struct var { \
        T array[e]; \
        uint32_t elements; \
    } var = { .elements = e }; 


#define set_array(var, index, value)    ({ assert(index < var.elements); var.array[index] = value; })
#define get_array(var, index)    ({ assert(index < var.elements); var.array[index]; })

int main(void) {
    static_array(int, opttrans, 10);

    set_array(opttrans, 10, 3);
    printf("%d\n", get_array(opttrans, 10));


    return EXIT_SUCCESS;
}

