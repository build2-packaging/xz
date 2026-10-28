// Upstream only supports 64-bit LoongArch.
//
#ifndef CONTROL
#  if !(defined(__loongarch__) && __loongarch_grlen >= 64)
#    error not 64-bit LoongArch
#  endif
#  include <larchintrin.h>
#endif

int f (void)
{
#ifndef CONTROL
  return __crc_w_w_w (1, 2);
#else
  return 1;
#endif
}
