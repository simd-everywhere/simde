# Contributing to SIMDe

First off, if you're even reading this, thank you!  There is a lot of
work to do, and any help is appreciated.

If you haven't already, please read the
[README](https://github.com/nemequ/simde/blob/master/README.md).  The
[wiki](https://github.com/nemequ/simde/wiki) also has some good
information, especially the
[FAQ](https://github.com/nemequ/simde/wiki/FAQ) and a guide on how to
[implement a new
function](https://github.com/nemequ/simde/wiki/Implementing-a-New-Function).

For information on developing for architectures you don't have access
to, please see the [Development
Environment](https://github.com/nemequ/simde/wiki/Development-Environment)
page on the wiki.

If you still have questions, or if anything below doesn't make sense
to you, please feel free to use the [issue
tracker](https://github.com/nemequ/simde/issues) or the [mailing
list](https://groups.google.com/forum/#!forum/simde) to ask.  I know
the SIMDe documentation needs a lot of improvement, and asking
questions will help us understand what is missing, so please don't be
shy!

## Building the Tests

SIMDe contains an extensive test suite used for development.  Most
users will never need to build the suite, but if you're contributing
code to SIMDe you'll need to build them.

Here is the basic procedure for compiling the tests:

```bash
mkdir test/build
cd test/build
CFLAGS="-march=native" CXXFLAGS="-march=native" cmake ..
make -j
./run-tests
```

Note that `-march=native` may not be the right flag for your compiler.
That should work for most compilers on x86/x86_64, though MSVC is an
exception (try `/arch:AVX2` instead of `-march=native`).  On other
architectures please consult your compiler documentation to find out
what flags you should use to enable the SIMD extension for your target
platform.  Here are a few to try:

 * ARM:
   * `-march=armv8-a+simd` (for ARMv8)
   * `-march=armv7-a -mfpu=neon` (for ARMv7)
 * POWER
   * `-mcpu=native`

If you need a flag not listed above, please let us know so we can add
it to the list.

## Coding Style

SIMDe uses two spaces for indentation.  Please adjust your editor
accordingly.

The coding style for preprocessor macros is a bit mixed since I made
some changes mid-project.  For new code, please indent the
preprocessor conditions before the hash to the same level as the
normal code would be, and indent the code inside of preprocessor
conditions as if the conditions were normal code.  For example:

```c
int
foo(void) {
  #if 1
    bar();
  #else
    baz();
  #endif
}
```

Other than that, please just try to follow the existing style.  We'll
add new rules here as the need arises.

## Commit Messages

Git commit messages should contain lines no longer than 72 characters.
The first line should always be a one-line summary of the commit, with
the relevant component followed by a colon and a space (if
applicable), then the summary.

If the one-line summary is insufficient to fully describe the changes
further descriptive paragraphs should be added, separated by blank
lines.

For example:

```
sse: add magical code to make everything go fast

Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur
interdum scelerisque risus non ultricies. Vivamus id tristique mauris.
Mauris et augue vel urna aliquam posuere. Morbi in sem nec ante
ullamcorper ultrices in quis nibh. In felis velit, semper a mauris sed,
congue ullamcorper enim. Vestibulum ante ipsum primis in faucibus orci
luctus et ultrices posuere cubilia Curae; Nulla facilisi. Donec
scelerisque elit dui, et aliquet magna tincidunt eu.

Curabitur rhoncus lacus ac elit pulvinar, quis posuere ante ultrices.
Suspendisse at mauris vitae justo pretium tempor et in mauris. Nunc
facilisis nulla a ante tincidunt, imperdiet rhoncus metus interdum.
Vivamus sed nunc vel tellus porta consequat. Donec quis porttitor elit,
et cursus urna. Donec et sapien lorem. In imperdiet magna at aliquet
hendrerit.
```