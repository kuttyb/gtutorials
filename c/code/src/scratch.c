#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

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
  bool start = true;

  for (; *str; str++) {
    if (!start) {
      sum *= base;
    }
    sum += converter(*str);
    start = false;
  }
  return sum;
}

int main(void) {
  if (1) {
  printf("%d\n", convert_to_decimal("31", 16, converter_from_hex));
  printf("%d\n", convert_to_decimal("131", 16, converter_from_hex));
  printf("%d\n", convert_to_decimal("10a", 16, converter_from_hex));
  printf("%d\n", convert_to_decimal("A00", 16, converter_from_hex));
  printf("%d\n", convert_to_decimal("A0", 16, converter_from_hex));
  printf("%d\n", convert_to_decimal("f", 16, converter_from_hex));
  }


  return 0;
}
