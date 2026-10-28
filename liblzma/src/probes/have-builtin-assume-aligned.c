const void* f (void)
{
#ifndef CONTROL
  return __builtin_assume_aligned ("", 1);
#else
  return "";
#endif
}
