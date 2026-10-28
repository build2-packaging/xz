#ifndef CONTROL
#  include <sys/auxv.h>
#endif

unsigned long f (void)
{
#ifndef CONTROL
  return getauxval (AT_HWCAP);
#else
  return 1;
#endif
}
