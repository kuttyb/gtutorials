#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <assert.h>

typedef struct {
  uint32_t handle;
} Tile;


static void comparator(uint64_t compid, uint32_t wtile, ...) {
  printf("%s: compid %" PRIu64 " wtile %d\n", __FUNCTION__, compid, wtile);
}

static void intconstants(uint32_t count,...) {
  va_list list;
  va_start(list, count);
  for (uint32_t ctr = 0; ctr < count; ctr++) {
    printf("arg[%d] = %d\n", ctr, va_arg(list, int));
  }
  va_end(list);
}

static void rtiles(uint32_t count,...) {
  va_list list;
  va_start(list, count);
  for (uint32_t ctr = 0; ctr < count; ctr++) {
    Tile tile = va_arg(list, Tile);
    printf("arg[%d] = %d\n", ctr, tile.handle);
  }
  va_end(list);
}

static void stringconstants(uint32_t count,...) {
  va_list list;
  va_start(list, count);
  for (uint32_t ctr = 0; ctr < count; ctr++) {
    printf("arg[%d] = %s\n", ctr, va_arg(list, char*));
  }
  va_end(list);
}

static void ifstart() { printf("%s:\n", __FUNCTION__); }
static void ifend() { printf("%s:\n", __FUNCTION__); }
static void elsestart() { printf("%s:\n", __FUNCTION__);}
static void elseend()   { printf("%s:\n", __FUNCTION__);}
static void loopstart() { printf("%s:\n", __FUNCTION__);}
static void loopend()   { printf("%s:\n", __FUNCTION__);}
static void operator(uint32_t id) { printf("%s: Operator id %d\n", __FUNCTION__, id);}

#define _if(compid, wtile,...)   comparator(compid, wtile, __VA_ARGS__); ifstart(); \
  for (uint32_t ctr = 0; ctr < 1; ({ctr++;ifend();})) /** Uses GCC Statement Expressions */ 

#define _else   elsestart(); \
  for (uint32_t ctr = 0; ctr < 1;  ({ctr++;elseend();}))

#define _while(compid, wtile,...) comparator(compid, wtile, __VA_ARGS__); loopstart(); \
  for (uint32_t ctr = 0; ctr < 1;  ({ctr++;loopend();}))

static void program() {
  /** Branches */
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

  /** Loops */
  _while(50, 51, 52, 53, 55) {
    operator(920);
    _if(60, 61, 62) {
      operator(63);
      operator(64);
    }
    operator(930);
  }
}

static void testvarargs() {
  intconstants(4, 1, 2, 3, 4);
  stringconstants(3, "first", "second", "third");
}

int main(void) {
  if (0) program();
  
  if (0) testvarargs();


  return 0;
}

