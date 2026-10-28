# liblzma - XZ and LZMA data compression C library

This is a `build2` package for the [`xz`](https://tukaani.org/xz/) C
library. It provides a general-purpose data compression library with an
API similar to that of `zlib`. Its native file format is the `.xz` format,
but the legacy `.lzma` format and the `.lz` (`lzip`) format are supported as
well. The primary compression algorithm (filter) is LZMA2, which can be
chained with additional filters, such as the BCJ filters that improve the
compression ratio of executable files.


## Usage

To start using `liblzma` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: liblzma ^5.8.4
```

Then import the library in your `buildfile`:

```
import libs = liblzma%lib{lzma}
```

The library is built with upstream's default feature set: all the filter
encoders and decoders, integrity checks, and match finders, as well as the
`lzip` decoder, MicroLZMA support, and multithreaded compression and
decompression. Note also that the `lib{lzma}` library provides `build2`
metadata that describes its configuration:

```
lib{lzma}:
{
  liblzma.encoders          = [strings] lzma1 lzma2 delta x86 arm ...
  liblzma.decoders          = [strings] lzma1 lzma2 delta x86 arm ...
  liblzma.checks            = [strings] crc32 crc64 sha256
  liblzma.lzip_decoder      = [bool] true
  liblzma.microlzma_encoder = [bool] true
  liblzma.microlzma_decoder = [bool] true
  liblzma.threads           = [string] posix
}
```

Where `liblzma.threads` is the threading method used by the library, which
is `posix` (POSIX threads), `vista` (Windows Vista threads), or `win95`
(Windows 95 threads, used for the 32-bit Windows targets).
