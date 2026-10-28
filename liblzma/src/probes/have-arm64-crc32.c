#include <stdint.h>

#if !defined(CONTROL) && !defined(_MSC_VER)
#  include <arm_acle.h>
#endif

#if !defined(CONTROL) && \
    (defined(__GNUC__) || defined(__clang__)) && !defined(__EDG__)
__attribute__ ((__target__ ("+crc")))
#endif
uint32_t f (void)
{
#ifndef CONTROL
  return __crc32d (1, 2);
#else
  return 1;
#endif
}
