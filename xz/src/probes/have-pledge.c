#include <stddef.h>

#ifndef CONTROL
#  include <unistd.h>
#endif

int f (void)
{
#ifndef CONTROL
  return pledge ("stdio", NULL);
#else
  return 0;
#endif
}
