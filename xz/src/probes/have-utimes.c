#include <stddef.h>

#ifndef CONTROL
#  include <sys/time.h>
#endif

int f (const char* p)
{
#ifndef CONTROL
  return utimes (p, NULL);
#else
  return p != NULL;
#endif
}
