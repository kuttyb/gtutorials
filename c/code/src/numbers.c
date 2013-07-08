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

/** truncate not round. Round is easy, just add 0.5 to float before doing the below 
    s -- exponent -- mantissa  -> 1 -- 8 -- 23
*/
static inline int float_to_int(float input) {
  uint32_t *x = (uint32_t*)&input;
  uint32_t mask = *x;

  /** handle the exponent and return for 0, negative numbers */
  int exponent = (get32(mask, 30, 23)) - 127;
  if (exponent < 0) {
    return 0;
  }

  /** mantissa handling, adjust for the invisible 24th bit
      and denormalize it */
  uint32_t mantissa = get32(mask, 22, 0);
  mantissa |= (1 << 23);
  mantissa >>= 23 - exponent; 

  /** check sign and return truncated integer */
  if (get32(mask, 31, 31)) 
    return mantissa * -1;
  else
    return mantissa;
}

static void test_float(void) {
  assert(float_to_int(101.1252f) == 101);
  assert(float_to_int(101.0f) == 101);

  assert(float_to_int(101.0f) == 101);
  assert(float_to_int(101.909f) == 101);

  assert(float_to_int(-101.0f) == -101);
  assert(float_to_int(-10242343.3423424234f) == -10242343);

  assert(float_to_int(0.02343f) == 0);
  assert(float_to_int(0.0f) == 0);
  assert(float_to_int(0.12419f) == 0);

  assert(float_to_int(1.25f) == 1);
  assert(float_to_int(0.25f) == 0);
}


/** Given binary32 memory, return the float value */
static inline float binary_to_float(uint32_t mask) {
  if (!mask) return 0.0f;

  /** handle the exponent and return for 0, negative numbers */
  int exponent = (get32(mask, 30, 23)) - 127;
         
  /** mantissa handling, adjust for the invisible 24th bit
      and denormalize it */
  uint32_t mantissa = get32(mask, 22, 0);
  mantissa |= (1 << 23);

  uint32_t non_fraction = get32(mantissa, 23, (23 - exponent));
  uint32_t fraction     = get32(mantissa, (22 - exponent), 0);
  if (1) printf("%s: mask 0x%x exponent %d mantissa 0x%x non_fraction 0x%x fraction 0x%x\n",
                __FUNCTION__, mask, exponent, mantissa, non_fraction, fraction);

  float value = non_fraction;
  /** add the fraction */
  uint32_t power = 22 - exponent + 1;
  for (; fraction; fraction>>=1) {
    if (fraction & 1) {
      value += 1.0f / ((1 << power) * 1.0f);
    }
    power--;
  }

  if (get32(mask, 31, 31)) 
    return value * -1.0f;
  else 
    return value;
}

static void test_to_float(void) {
  //  float a = 1.25f;
  float a = -1.512132f;
  uint32_t *ptr = (uint32_t*)&a;
  assert(binary_to_float(*ptr) == a);

  a = 1.25f;
  assert(binary_to_float(*ptr) == a);

  a = 1.5f;
  assert(binary_to_float(*ptr) == a);

  a = 0.2f;
  assert(binary_to_float(*ptr) == a);

  a = 0.01f;
  assert(binary_to_float(*ptr) == a);

  a = 0.0f;
  assert(binary_to_float(*ptr) == a);
}

int main(void) {
     float a = 2.0f;
     binary_to_float(*(uint32_t*)&a);

     a = 3.0f;
     binary_to_float(*(uint32_t*)&a);

     a = 1.0f;
     binary_to_float(*(uint32_t*)&a);

     if (0) {
          test_float();
     
          test_to_float();
     }
     
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
    
  return EXIT_SUCCESS;
}

