#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

// ======================================================
// Use the template below and its leading 0's safe
// ======================================================

static int converter_from_hex(char t) {  
  /** Is it b/w 0-9 */
  if ((t >= '0') && (t <= '9')) {
    return t - '0';
  }

  /** since its > 9 lets convert to lowercase first */
  t = t | 32;
  if ((t > 'f') || (t < 'a')) {
    assert(0); /** invalid digit */
    return -1;
  }
  return t - 'a' + 10;
}

static int converter_from_binary(char input) {
  if (input == '0') return 0;
  if (input == '1') return 1;
  assert(0); /** invalid input */
  return -1;
}

static int convert_to_decimal(const char *str, uint32_t base, int(*converter)(char)) {
  int  sum = 0;

  for (; *str; str++) {
    sum *= base; /** first time around sum is zero so this is a noop */    
    sum += converter(*str);
  }
  return sum;
}

int main(void) {
  // hex to decimal
  assert(convert_to_decimal("31",  16, converter_from_hex) == 49);
  assert(convert_to_decimal("131", 16, converter_from_hex) == 305);
  assert(convert_to_decimal("10a", 16, converter_from_hex) == 266);
  assert(convert_to_decimal("A00", 16, converter_from_hex) == 2560);
  assert(convert_to_decimal("A0",  16, converter_from_hex) == 160);
  assert(convert_to_decimal("f",   16, converter_from_hex) == 15);
  
  // binary to decimal
  assert(convert_to_decimal("101", 2, converter_from_binary)   == 5);
  assert(convert_to_decimal("001", 2, converter_from_binary)   == 1);
  assert(convert_to_decimal("1", 2, converter_from_binary)     == 1);
  assert(convert_to_decimal("11", 2, converter_from_binary)    == 3);
  assert(convert_to_decimal("0", 2, converter_from_binary)     == 0);
  assert(convert_to_decimal("1111", 2, converter_from_binary)  == 15);
    
  return 0;
}
