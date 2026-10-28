#include <stddef.h>

#ifndef CONTROL
// Upstream breaks this check on QNX where only sysconf() works.
//
#  ifdef __QNX__
#    error sysctl() does not work on QNX
#  endif
#  include <sys/param.h>
#  include <sys/sysctl.h>
#endif

int f (void)
{
  int c;
  size_t s = sizeof (c);

#ifndef CONTROL
#  ifdef HW_NCPUONLINE
  int n[2] = {CTL_HW, HW_NCPUONLINE}; // Preferred on OpenBSD.
#  else
  int n[2] = {CTL_HW, HW_NCPU};
#  endif
  return sysctl (n, 2, &c, &s, NULL, 0);
#else
  return (int) s;
#endif
}
