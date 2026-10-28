#include <stdint.h>
#include <string.h>

#include <lzma.h>

#undef NDEBUG
#include <assert.h>

int main ()
{
  /* Version.
   */
  {
    assert (lzma_version_number () == LZMA_VERSION);
    assert (strcmp (lzma_version_string (), LZMA_VERSION_STRING) == 0);
  }

  /* Integrity checks.
   */
  {
    assert (lzma_check_is_supported (LZMA_CHECK_CRC32));
    assert (lzma_check_is_supported (LZMA_CHECK_CRC64));
    assert (lzma_check_is_supported (LZMA_CHECK_SHA256));

    assert (lzma_crc32 ((const uint8_t*) "123456789", 9, 0) == 0xCBF43926);
  }

  /* Round trip through the .xz format.
   */
  {
    const uint8_t s[] = "Hello, World!";

    uint8_t c[256];
    size_t cn = 0;

    assert (lzma_easy_buffer_encode (LZMA_PRESET_DEFAULT, LZMA_CHECK_CRC64,
                                     NULL,
                                     s, sizeof (s),
                                     c, &cn, sizeof (c)) == LZMA_OK);

    uint8_t d[sizeof (s)];
    size_t ci = 0, dn = 0;
    uint64_t m = UINT64_MAX;

    assert (lzma_stream_buffer_decode (&m, 0, NULL,
                                       c, &ci, cn,
                                       d, &dn, sizeof (d)) == LZMA_OK);

    assert (ci == cn && dn == sizeof (s) && memcmp (d, s, sizeof (s)) == 0);
  }

  return 0;
}
