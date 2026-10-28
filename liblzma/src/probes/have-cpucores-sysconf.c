#ifndef CONTROL
#  include <unistd.h>
#endif

long f (void)
{
#ifndef CONTROL
#  ifdef _SC_NPROCESSORS_ONLN
  return sysconf (_SC_NPROCESSORS_ONLN);
#  else
  return sysconf (_SC_NPROC_ONLN); // IRIX.
#  endif
#else
  return 1;
#endif
}
