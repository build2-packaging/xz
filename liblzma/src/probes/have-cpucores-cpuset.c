#ifndef CONTROL
#  include <sys/param.h>
#  include <sys/cpuset.h>
#endif

int f (void)
{
#ifndef CONTROL
  cpuset_t s;
  return cpuset_getaffinity (CPU_LEVEL_WHICH, CPU_WHICH_PID, -1,
                             sizeof (s), &s);
#else
  return 1;
#endif
}
