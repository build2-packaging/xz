// TUKLIB_FAST_UNALIGNED_ACCESS : WORDS_BIGENDIAN

// This mirrors the guesses in upstream's cmake/tuklib_integer.cmake. Where
// upstream inspects the disassembly of a test object to detect GCC's
// -mstrict-align (ARM64, LoongArch), we assume it is not in effect since it
// is not the default.

#undef TUKLIB_FAST_UNALIGNED_ACCESS

/* x86 and x86-64.
 */
#if defined(__i386__) || defined(__x86_64__) || \
    defined(_M_IX86)  || defined(_M_X64)
#  define TUKLIB_FAST_UNALIGNED_ACCESS 1

/* 64-bit or big-endian PowerPC.
 */
#elif defined(__powerpc__) || defined(__ppc__) || defined(__PPC__)
#  if defined(__powerpc64__) || defined(__ppc64__) || defined(WORDS_BIGENDIAN)
#    define TUKLIB_FAST_UNALIGNED_ACCESS 1
#  endif

/* ARM64. Note that GCC defines __ARM_FEATURE_UNALIGNED even with
 * -mstrict-align (GCC bug 111555).
 */
#elif defined(__aarch64__) || defined(_M_ARM64)
#  if defined(__ARM_FEATURE_UNALIGNED) || defined(_MSC_VER)
#    define TUKLIB_FAST_UNALIGNED_ACCESS 1
#  endif

/* 32-bit ARM and RISC-V.
 */
#elif defined(__arm__) || defined(_M_ARM) || defined(__riscv)
#  if defined(__ARM_FEATURE_UNALIGNED)  || \
      defined(__riscv_misaligned_fast) || \
      defined(_MSC_VER)
#    define TUKLIB_FAST_UNALIGNED_ACCESS 1
#  endif

/* LoongArch.
 */
#elif defined(__loongarch__)
#  define TUKLIB_FAST_UNALIGNED_ACCESS 1
#endif
