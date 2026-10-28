# xzdec - XZ and LZMA data decompression command line utilities

This is a `build2` package for the [`xz`](https://tukaani.org/xz/)
`xzdec` and `lzmadec` executables. These are small decompression-only
utilities for the `.xz` and the legacy `.lzma` formats, respectively. They
are intended as drop-in replacements for `xz --decompress --stdout` (and
`xz --format=lzma --decompress --stdout`) where the size of the full `xz`
utility matters.


## Usage

To start using `xzdec` in your project, add the following build-time
`depends` value to your `manifest`, adjusting the version constraint as
appropriate:

```
depends: * xzdec ^5.8.4
```

Then import the executables in your `buildfile`:

```
import xzdec = xzdec%exe{xzdec}
import lzmadec = xzdec%exe{lzmadec}
```


## Importable targets

This package provides the following importable targets:

```
exe{xzdec}
exe{lzmadec}
```

The `exe{xzdec}` executable decompresses `.xz` files while `exe{lzmadec}`
decompresses `.lzma` files.
