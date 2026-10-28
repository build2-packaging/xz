#include <stddef.h>

#ifndef CONTROL
#  include <getopt.h>
#endif

int f (int argc, char* argv[])
{
#ifndef CONTROL
  static const struct option o[] = {{"a", no_argument, NULL, 'a'},
                                    {NULL, 0, NULL, 0}};
  return getopt_long (argc, argv, "", o, NULL);
#else
  return argv[argc - 1] != NULL;
#endif
}
