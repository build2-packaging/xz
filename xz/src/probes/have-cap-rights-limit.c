#include <stddef.h>

#ifndef CONTROL
#  include <sys/capsicum.h>
#endif

int f (int fd)
{
#ifndef CONTROL
  return cap_rights_limit (fd, NULL);
#else
  return fd;
#endif
}
