#include <stdio.h>
#include <stdarg.h>

int f (const char* fmt, ...)
{
  int r;
  va_list ap;
  va_start (ap, fmt);
#ifndef CONTROL
  {
    char* s;
    r = vasprintf (&s, fmt, ap);
  }
#else
  r = vprintf (fmt, ap);
#endif
  va_end (ap);
  return r;
}
