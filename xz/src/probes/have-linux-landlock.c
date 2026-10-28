// Some systems have linux/landlock.h but not the system calls and so we
// check for both (as upstream does).
//
#ifndef CONTROL
#  include <linux/landlock.h>
#  include <sys/syscall.h>
#  include <sys/prctl.h>
#endif

int f (void)
{
#ifndef CONTROL
  (void) prctl (PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0);
  (void) SYS_landlock_create_ruleset;
  (void) SYS_landlock_restrict_self;
  (void) LANDLOCK_CREATE_RULESET_VERSION;
#endif
  return 0;
}
