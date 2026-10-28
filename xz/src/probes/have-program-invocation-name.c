#ifndef CONTROL
#  include <errno.h>
#endif

int f (void)
{
#ifndef CONTROL
  return program_invocation_name[0];
#else
  return 0;
#endif
}
