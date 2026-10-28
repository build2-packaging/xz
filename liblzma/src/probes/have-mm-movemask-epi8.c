#ifndef CONTROL
#  include <immintrin.h>
#endif

int f (void)
{
#ifndef CONTROL
  __m128i x = {0};
  return _mm_movemask_epi8 (x);
#else
  return 1;
#endif
}
