#ifndef CONTROL
#  include <sys/utime.h>
#endif

int f (int fd)
{
#ifndef CONTROL
  struct _utimbuf b;
  b.actime = 0;
  b.modtime = 0;
  return _futime (fd, &b);
#else
  return fd;
#endif
}
