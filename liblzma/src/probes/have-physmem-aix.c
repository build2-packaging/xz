#ifndef CONTROL
#  include <sys/systemcfg.h>
#endif

unsigned long long f (void)
{
#ifndef CONTROL
  return (unsigned long long) _system_configuration.physmem;
#else
  return 1;
#endif
}
