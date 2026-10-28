#include <stddef.h>

#ifndef CONTROL
#  include <sys/time.h>
#endif

int f (int fd)
{
#ifndef CONTROL
  return futimesat (fd, NULL, NULL);
#else
  return fd;
#endif
}
