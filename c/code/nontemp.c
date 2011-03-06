#include <stdio.h>
#include <stdlib.h>
#include <emmintrin.h>

int main(void) {
  __m128i src = _mm_set_epi32(200, 150, 100, 50);

  int *dst;
  if (posix_memalign((void**)&dst, 128, 1024)) {
    printf("allocation failed\n");
    return -1;
  }

  for(int counter = 0; counter < 1024/4; counter+=4) {
    _mm_stream_si128((__m128i*)&dst[counter], src);
  }
  __builtin_ia32_sfence();

  free(dst);

  return 1;
}
