#ifndef CONTROL
#  include <sys/param.h>
#  include <sys/pstat.h>
#endif

int f (void)
{
#ifndef CONTROL
  struct pst_static p;
  pstat_getstatic (&p, sizeof (p), 1, 0);
  return (int) (p.physical_memory + p.page_size);
#else
  return 1;
#endif
}
