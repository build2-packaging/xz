#include <stddef.h>

#ifndef CONTROL
#  include <utime.h>
#endif

int f (const char* p)
{
#ifndef CONTROL
  return utime (p, NULL);
#else
  return p != NULL;
#endif
}
