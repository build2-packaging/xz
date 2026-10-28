#include <immintrin.h>

int f (void)
{
  __m128i x = {0};

#ifndef CONTROL
  return _mm_movemask_epi8 (x);
#else
  return (int) sizeof (x);
#endif
}
