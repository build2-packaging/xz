# lzmainfo - .lzma file header information command line utility

This is a `build2` package for the [`xz`](https://tukaani.org/xz/)
`lzmainfo` executable. It shows the information stored in the header of
legacy `.lzma` files, such as the uncompressed size, the dictionary size,
and the LZMA properties.


## Usage

To start using `lzmainfo` in your project, add the following build-time
`depends` value to your `manifest`, adjusting the version constraint as
appropriate:

```
depends: * lzmainfo ^5.8.4
```

Then import the executable in your `buildfile`:

```
import lzmainfo = lzmainfo%exe{lzmainfo}
```
