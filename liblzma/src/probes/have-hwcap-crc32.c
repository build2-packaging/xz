#ifndef CONTROL
#  include <sys/auxv.h>
#endif

unsigned long f (void)
{
#ifndef CONTROL
  return HWCAP_CRC32;
#else
  return 1;
#endif
}
