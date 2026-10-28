#ifndef CONTROL
#  include <wchar.h>
#endif

int f (void)
{
#ifndef CONTROL
  return wcwidth (L'a');
#else
  return 1;
#endif
}
