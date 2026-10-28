#include <time.h>

#ifndef CONTROL
#  include <pthread.h>
#endif

int f (void)
{
#ifndef CONTROL
  pthread_condattr_t a;
  return pthread_condattr_setclock (&a, CLOCK_MONOTONIC);
#else
  return (int) CLOCK_MONOTONIC;
#endif
}
