#ifndef CONTROL
#  include <sys/resource.h>
#endif

int f (void)
{
#ifndef CONTROL
  struct rlimit r;
  return getrlimit (RLIMIT_DATA, &r);
#else
  return 0;
#endif
}
