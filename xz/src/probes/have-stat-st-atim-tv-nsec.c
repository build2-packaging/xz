#include <sys/types.h>
#include <sys/stat.h>

long f (const struct stat* s)
{
#ifndef CONTROL
  return (long) s->st_atim.tv_nsec;
#else
  return (long) s->st_size;
#endif
}
