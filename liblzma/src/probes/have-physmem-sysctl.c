#include <stddef.h>

#ifndef CONTROL
#  include <sys/param.h>
#  include <sys/sysctl.h>
#endif

int f (void)
{
  unsigned long m;
  size_t s = sizeof (m);

#ifndef CONTROL
  int n[2] = {CTL_HW, HW_PHYSMEM};
  return sysctl (n, 2, &m, &s, NULL, 0);
#else
  return (int) s;
#endif
}
