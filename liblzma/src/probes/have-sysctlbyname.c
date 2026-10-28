#include <stddef.h>

#ifndef CONTROL
#  include <sys/sysctl.h>
#endif

int f (void)
{
  int v;
  size_t s = sizeof (v);

#ifndef CONTROL
  return sysctlbyname ("hw.optional.armv8_crc32", &v, &s, NULL, 0);
#else
  return (int) s;
#endif
}
