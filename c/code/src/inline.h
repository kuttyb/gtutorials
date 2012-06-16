#ifndef _inline_h_
#define _inline_h_

typedef struct {
  int(*start)(int);
} Type;


__attribute__((malloc))  Type* exportType(void);

#endif //_inline_h_
