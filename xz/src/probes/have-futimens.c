#include <stddef.h>

#ifndef CONTROL
#  include <sys/types.h>
#  include <sys/stat.h>
#endif

int f (int fd)
{
#ifndef CONTROL
  return futimens (fd, NULL);
#else
  return fd;
#endif
}
