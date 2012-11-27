#ifndef __test_h__
#define __test_h_

void setup(void);

static inline void invoke(void(*fn)(void), const char *msg) {
  setup();
  printf("START %s\n", msg);
  fn();
  printf("DONE %s\n\n", msg);
}

#endif //__test_h_
