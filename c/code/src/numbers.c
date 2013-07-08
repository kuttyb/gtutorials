#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

typedef union {
  int    num;
  signed short s;
  float  f;
  unsigned char mem[4];
} A;

static void printnum(A x) {
  printf("%d:\t", x.num);
  printf("0x%x%x%x%x\n",
         (unsigned char)x.mem[3], 
         (unsigned char)x.mem[2], 
         (unsigned char)x.mem[1],
         (unsigned char)x.mem[0]);
}

#define getmask32(hi, lo) (unsigned int)(0xffffffff >> \
                                         (32 - \
                                          ((unsigned int)hi - (unsigned int)lo + 1))) << (unsigned int)lo

#define get32(value, hi, lo) ((unsigned int)value & \
                              getmask32((unsigned int)hi, (unsigned int)lo)) >> (unsigned int)lo

#define set32(value, fieldValue, hi, lo) ((unsigned int)value & \
                                          ~getmask32((unsigned int)hi, (unsigned int)lo)) | \
    ((unsigned int)fieldValue << (unsigned int)lo)

/** truncate not round. Round is easy, just add 0.5 to float before doing the below */
static inline int float_to_int(float finput) {
  uint32_t *x = (uint32_t*)&finput;
  uint32_t mask = *x;

  int exponent = (get32(mask, 30, 23)) - 127;
  if (0) printf("exponent 0x%x\n", exponent);
  if (exponent <= 0) {
    return 0;
  }

  exponent = exponent > 22 ? 22 : exponent;

  uint32_t mantissa = get32(mask, 22, 0);
  mantissa |= (1 << 23);
  if (0) printf("mantissa 0x%x\n", mantissa);
  mantissa >>= 23 - exponent;
  if (0) printf("normalized mantissa 0x%x\n\n", mantissa);

  if (get32(mask, 31, 31)) 
    return mantissa * -1;
  else
    return mantissa;
}

int main(void) {
  printf("%d\n", float_to_int(101.1252f));
  printf("%d\n", float_to_int(101.0f));
  printf("%d\n", float_to_int(101.90f));
  printf("%d\n", float_to_int(-101.90f));

  /** understand 2s complement basics */
  if (0) {
    A x = { -2 };
    printnum(x);

    x.num = -3;
    printnum(x);

    x.num = -1;
    printnum(x);
  }

  /** understand sign extension */
  if (0) {
    A x = { 0 };
    x.s = -2;
    printnum(x);
    x.num = x.s;
    printnum(x);
  }
  
  /** floating point arithmetic (binary32) */
  /** s--exponent--mantissa 1-8-23 
      exponenent can be negative in the biased
      form. Do e - 127 to get the number */
  if (0) {
    A x = { 0 };
    x.f = 1.213415f;
    printnum(x);

    A y = { 0 };
    y.f = 1.113415f;
    printnum(y);
  }
  
  return EXIT_SUCCESS;
}

