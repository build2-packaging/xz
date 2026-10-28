#ifndef CONTROL
#  include <unistd.h>
#endif

long f (void)
{
#ifndef CONTROL
  return sysconf (_SC_PAGESIZE) * sysconf (_SC_PHYS_PAGES);
#else
  return 1;
#endif
}
