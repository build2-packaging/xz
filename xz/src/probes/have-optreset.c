#ifndef CONTROL
#  include <getopt.h>
#endif

int f (void)
{
#ifndef CONTROL
  optreset = 1;
#endif
  return 0;
}
