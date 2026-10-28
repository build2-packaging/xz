# xz - XZ and LZMA data compression command line utility

This is a `build2` package for the [`xz`](https://tukaani.org/xz/)
executable. It is a general-purpose data compression utility with a command
line syntax similar to that of `gzip`. Its native file format is the `.xz`
format, but the legacy `.lzma` format and the `.lz` (`lzip`) format (for
decompression only) are supported as well.

On POSIX systems this package also provides the `unxz` and `xzcat` (as well
as `lzma`, `unlzma`, and `lzcat` for LZMA Utils compatibility) aliases and
the `xzdiff`, `xzgrep`, `xzless`, and `xzmore` scripts (plus their aliases)
for working with compressed files.


## Usage

To start using `xz` in your project, add the following build-time
`depends` value to your `manifest`, adjusting the version constraint as
appropriate:

```
depends: * xz ^5.8.4
```

Then import the executable in your `buildfile`:

```
import xz = xz%exe{xz}
```


## Importable targets

This package provides the following importable targets:

```
exe{xz}
exe{unxz}
exe{xzcat}
exe{lzma}
exe{unlzma}
exe{lzcat}
exe{xzdiff}
exe{xzcmp}
exe{xzgrep}
exe{xzegrep}
exe{xzfgrep}
exe{xzless}
exe{xzmore}
```

Where all the targets except `exe{xz}` are only available on POSIX systems.
The `lz*` aliases of the scripts are not listed but are available as well.
