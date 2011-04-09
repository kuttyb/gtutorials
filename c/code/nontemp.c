#include <stdlib.h>
#include <emmintrin.h>
#include "barrier.h"

void testnontemp() {
    __m128i src = _mm_set_epi32(200, 150, 100, 50);

    int *dst;
    if (posix_memalign((void**) &dst, 128, 1024)) {
        return;
    }

    barrier_write();

    for (int counter = 0; counter < 1024 / 4; counter += 4) {
        _mm_stream_si128((__m128i*) & dst[counter], src);
    }
    barrier_write();

    free(dst);
}
