#include <immintrin.h>

// Upstream excludes Elbrus before ISA version 6.
//
#if !defined(CONTROL) && defined(__e2k__) && __iset__ < 6
#  error unusable CLMUL
#endif

#if (defined(__GNUC__) || defined(__clang__)) && !defined(__EDG__)
__attribute__ ((__target__ ("ssse3,sse4.1,pclmul")))
#endif
__m128i f (void)
{
  __m128i a = _mm_set_epi64x (1, 2);

#ifndef CONTROL
  a = _mm_clmulepi64_si128 (a, a, 0);
#endif

  return a;
}
