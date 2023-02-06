# Contributing to SIMDe

First off, if you're even reading this, thank you!  There is a lot of
work to do, and any help is appreciated.

If you haven't already, please read the
[README](https://github.com/simd-everywhere/simde/blob/master/README.md).  The
[wiki](https://github.com/simd-everywhere/simde/wiki) also has some good
information, especially the
[FAQ](https://github.com/simd-everywhere/simde/wiki/FAQ) and a guide on how to
[implement a new
function](https://github.com/simd-everywhere/simde/wiki/Implementing-a-New-Function).

For information on developing for architectures you don't have access
to, please see the [Development
Environment](https://github.com/simd-everywhere/simde/wiki/Development-Environment)
page on the wiki.

If you still have questions, or if anything below doesn't make sense
to you, please feel free to use the [issue
tracker](https://github.com/simd-everywhere/simde/issues) or the [mailing
list](https://groups.google.com/forum/#!forum/simde) to ask.  I know
the SIMDe documentation needs a lot of improvement, and asking
questions will help us understand what is missing, so please don't be
shy!

## Building the Tests

SIMDe contains an extensive test suite used for development.  Most
users will never need to build the suite, but if you're contributing
code to SIMDe you'll need to build them.

Here is the basic procedure for compiling and running the tests:

### On Unix
```bash
mkdir -p build
cd build
CFLAGS="-march=native" CXXFLAGS="-march=native" meson setup ..
ninja test
```

Note that `-march=native` may not be the right flag for your compiler.
That should work for most compilers on x86/x86_64, though MSVC is an
exception (try `/arch:AVX2` instead of `-march=native`).  On other
architectures please consult your compiler documentation to find out
what flags you should use to enable the SIMD extension for your target
platform.  Here are a few to try:

 * ARM:
   * `-march=armv8-a+simd` (for AArch64)
   * `-march=armv8-a+simd -mfpu=auto` (for ARMv8)
   * `-march=armv7-a -mfpu=neon` (for ARMv7)
 * POWER
   * `-mcpu=native`

If you need a flag not listed above, please let us know so we can add
it to the list.

### On Windows:
```bash
"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" arm64
mkdir build
cd build
set CFLAGS="/std:c11"
set CXXFLAGS="/Zc:preprocessor"
meson setup ..
ninja test
```
Note change arm64 to x64 on x86_64 CPU.

You may also want to take a look at the
[Docker container](https://github.com/simd-everywhere/simde/tree/master/docker)
which has many builds pre-configured, including cross-compilers and emulators.

## Coding Style

SIMDe has an [EditorConfig](https://editorconfig.org/) file to
configure your editor for things like tabs vs. spaces, how many spaces,
etc. If you use an editor which doesn't support it out of the box then
odds are good there is a plugin you can download; please do so.

For other coding style information, please see the
[Coding Style](https://github.com/simd-everywhere/simde/wiki/Coding-Style)
document in the Wiki.
