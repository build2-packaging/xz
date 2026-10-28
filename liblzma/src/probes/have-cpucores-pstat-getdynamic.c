#ifndef CONTROL
#  include <sys/param.h>
#  include <sys/pstat.h>
#endif

int f (void)
{
#ifndef CONTROL
  struct pst_dynamic p;
  pstat_getdynamic (&p, sizeof (p), 1, 0);
  return (int) p.psd_proc_cnt;
#else
  return 1;
#endif
}
