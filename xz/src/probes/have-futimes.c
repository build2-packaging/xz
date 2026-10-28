#include <stddef.h>

#ifndef CONTROL
#  include <sys/time.h>
#endif

int f (int fd)
{
#ifndef CONTROL
  return futimes (fd, NULL);
#else
  return fd;
#endif
}
