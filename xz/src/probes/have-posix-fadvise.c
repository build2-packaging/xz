#ifndef CONTROL
#  include <fcntl.h>
#endif

int f (int fd)
{
#ifndef CONTROL
  return posix_fadvise (fd, 0, 0, POSIX_FADV_SEQUENTIAL);
#else
  return fd;
#endif
}
