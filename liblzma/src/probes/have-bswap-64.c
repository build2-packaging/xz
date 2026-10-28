#ifndef CONTROL
#  include <byteswap.h>
#endif

int f (void)
{
#ifndef CONTROL
  return (int) bswap_64 (1);
#else
  return 1;
#endif
}
