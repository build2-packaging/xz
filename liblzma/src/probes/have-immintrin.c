// Note that some compilers provide this header for all architectures but
// it fails to compile for non-x86 ones and so we compile it (as upstream
// does) instead of only checking for its presence.
//
#ifndef CONTROL
#  include <immintrin.h>
#endif

int f (void)
{
  return 0;
}
