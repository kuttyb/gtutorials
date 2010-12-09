#include <stdio.h>
#include <stdlib.h>
#include "di.h"
#include "memory.h"

void func(int *c) {
    printf("%p\n", c);
    printf("0x%x  0x%x\n", c[0], c[1]);
}

void fun(int b[]){
    printf("%p\n", b);
    printf("0x%x 0x%x\n", b[0], b[1]);
}

int main(int argc, char** argv) {
    int a[] = {3, 4};

    printf("%ld %ld\n", sizeof(a), sizeof(int*));
    printf("%p %p 0x%x  0x%x\n", a, a + 1, *(a + 1), a[0]);
    func(a);

    printf("....");
    fun(a);

    return (EXIT_SUCCESS);
}



/**
   Just so you re not confused .... arrays are really nothing but pointers they are not a type of their own
   The [n] is a convenience *OPERATOR* that does *(ptr + n) for you nothing else. Got it? 
   
   Once again an array really is a type ptr. You can pass it around just like a pointer.

   No in the case of fun you are not passing the array by value. its a copy by value of the pointer variable.
   As is the case with func.
   
 */
