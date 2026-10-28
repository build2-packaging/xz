# xz - XZ and LZMA data compression

This is a `build2` package repository for [`xz`](https://tukaani.org/xz/),
a general-purpose data compression library plus command line tools. The
native file format is the `.xz` format, but the legacy `.lzma` format is
supported as well.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`xz` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](liblzma/PACKAGE-README.md) file.

The development setup for `xz` uses the standard `bdep`-based workflow.
For example:

```
git clone --recurse-submodules .../xz.git
cd xz

bdep init -C @gcc cc config.c=gcc
bdep update
bdep test
```
