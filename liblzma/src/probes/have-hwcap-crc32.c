#include <sys/auxv.h>

unsigned long f (void)
{
#ifndef CONTROL
  return HWCAP_CRC32;
#else
  return AT_HWCAP;
#endif
}
