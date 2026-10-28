#ifndef CONTROL
#  include <sched.h>
#endif

int f (void)
{
#ifndef CONTROL
  cpu_set_t m;
  sched_getaffinity (0, sizeof (m), &m);
  return CPU_COUNT (&m);
#else
  return 1;
#endif
}
