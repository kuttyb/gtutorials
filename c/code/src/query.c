#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>


static void comparator(uint64_t compid, uint32_t wtile, ...) {
  printf("%s: compid %" PRIu64 " wtile %d\n", __FUNCTION__, compid, wtile);
}
static void ifstart() { printf("%s:\n", __FUNCTION__); }
static void ifend() { printf("%s:\n", __FUNCTION__); }
static void elsestart() { printf("%s:\n", __FUNCTION__);}
static void elseend()   { printf("%s:\n", __FUNCTION__);}
static void operator(uint32_t id) { printf("%s: Operator id %d\n", __FUNCTION__, id);}

#define _if(compid, wtile,...)   comparator(compid, wtile, __VA_ARGS__); ifstart(); \
  for (uint32_t ctr = 0; ctr < 1; ({ctr++;ifend();})) /** Uses GCC Statement Expressions */ 

#define _else   elsestart(); \
  for (uint32_t ctr = 0; ctr < 1;  ({ctr++;elseend();}))

int main(void) {
  
  _if(2, 3, 4, 5) {
    operator(3);
    operator(4);

    _if(20, 30, 40) {
      operator(200);
      operator(210);
    }

    operator(5);
  } _else {
    operator(9);
    operator(10);
  }

  return 0;
}

