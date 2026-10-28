#ifndef CONTROL
#  include <sys/auxv.h>
#endif

int f (void)
{
  unsigned long h;

#ifndef CONTROL
  return elf_aux_info (AT_HWCAP, &h, sizeof (h));
#else
  return (int) sizeof (h);
#endif
}
