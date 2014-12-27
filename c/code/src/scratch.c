#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

void first() {
  printf("first speaking\n");
}

void second() {
  printf("second speaking\n");
}

void third() {
  printf("third speaking\n");
}

int main(void) 
{
  int x = rand() % 3;


  switch(x) {
  case 0:
    first(); 
    break;

  case 1:
    second();
    break;

  case 2:
  case 3:
    third();
    break;
  }

  return 0;
}
