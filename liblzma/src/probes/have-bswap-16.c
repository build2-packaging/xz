#include <byteswap.h>

int f (void)
{
#ifndef CONTROL
  return (int) bswap_16 (1);
#else
  return 1;
#endif
}
