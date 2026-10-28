#ifndef CONTROL
#  include <byteswap.h>
#endif

int f (void)
{
#ifndef CONTROL
  return (int) bswap_32 (1);
#else
  return 1;
#endif
}
