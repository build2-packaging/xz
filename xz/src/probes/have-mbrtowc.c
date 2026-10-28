#include <string.h>

#ifndef CONTROL
#  include <wchar.h>
#endif

int f (void)
{
#ifndef CONTROL
  mbstate_t s;
  wchar_t c;
  memset (&s, 0, sizeof (s));
  return (int) mbrtowc (&c, "a", 1, &s);
#else
  char s[1];
  memset (s, 0, sizeof (s));
  return s[0];
#endif
}
