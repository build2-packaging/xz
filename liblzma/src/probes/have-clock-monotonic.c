#include <time.h>

int f (void)
{
  struct timespec ts;

#ifndef CONTROL
  return clock_gettime (CLOCK_MONOTONIC, &ts);
#else
  return clock_gettime (CLOCK_REALTIME, &ts);
#endif
}
