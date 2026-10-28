int f (void)
{
#ifndef CONTROL
  return (int) (__builtin_bswap16 (1) +
                __builtin_bswap32 (1) +
                __builtin_bswap64 (1));
#else
  return 1 + 1 + 1;
#endif
}
