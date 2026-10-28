// Some compilers only warn about unsupported attributes and so this probe
// is compiled with warnings treated as errors (see buildfile).
//
#ifndef CONTROL
__attribute__ ((__constructor__))
#endif
static void g (void)
{
}

void f (void)
{
  g ();
}
