#include <time.h>

int f (void)
{
#ifndef CONTROL
  struct timespec ts;
  return clock_gettime (CLOCK_REALTIME, &ts);
#else
  time_t t = time (NULL);
  return (int) t;
#endif
}
