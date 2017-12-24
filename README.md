# SIMD Everywhere

SIMDe provides fast, portable implementations of SIMD intrinsics on
hardware which doesn't natively support them, such as calling SSE
functions on ARM.

The current focus is on writing complete portable implementations,
though a large number of functions already have accelerated
implementations using one (or more) of the following:

 * SIMD intrinsics from other ISA extensions (e.g., using NEON to
   implement SSE).
 * Compiler-specific vector extensions and built-ins such as
   [`__builtin_shufflevector`](http://clang.llvm.org/docs/LanguageExtensions.html#langext-builtin-shufflevector)
   and
   [`__builtin_convertvector`](http://clang.llvm.org/docs/LanguageExtensions.html#langext-builtin-convertvector)
 * Compiler auto-vectorization hints, using:
   * [OpenMP 4 SIMD](http://www.openmp.org/)
   * [Cilk Plus](https://www.cilkplus.org/)
   * [GCC loop-specific pragmas](https://gcc.gnu.org/onlinedocs/gcc/Loop-Specific-Pragmas.html)
   * [clang pragma loop hint directives](http://llvm.org/docs/Vectorizers.html#pragma-loop-hint-directives)

For an example of a project using SIMDe, see
[LZSSE-SIMDe](https://github.com/nemequ/LZSSE-SIMDe).

## Current Status

[![Travis](https://api.travis-ci.org/nemequ/simde.svg?branch=master)](https://travis-ci.org/nemequ/simde) [![AppVeyor](https://ci.appveyor.com/api/projects/status/1f3wp712w1ium5vi/branch/master?svg=true)](https://ci.appveyor.com/project/quixdb/simde/branch/master) [![Codecov](https://img.shields.io/codecov/c/github/nemequ/simde.svg)](https://codecov.io/gh/nemequ/simde)

There are currently complete implementations of the following instruction
sets:

 * MMX
 * SSE
 * SSE2
 * SSE3
 * SSSE3
 * SSE4.1

As well as partial support for many others; see the
[instruction-set-support](https://github.com/nemequ/simde/issues?q=is%3Aissue+is%3Aopen+label%3Ainstruction-set-support+sort%3Aupdated-desc)
label in the issue tracker for details on progress.  If you'd like to
be notified when an instruction set is available you may subscribe to
the relevant issue.

If you have a project you're interested in with SIMDe but we don't yet
support all the functions you need, please file an issue with a list
of what's missing so we know what to prioritize.

## Want to help?

There are a *lot* of instructions to get through, so any help would be
greatly appreciated!  It's pretty straightforward work, and a great
way to learn about the instructions.

There are three places you'll want to modify in order to implement a
new function:

 * ${arch}/${isax}.h — this is where the implementations live
 * test/${isax}/${isax}.c — tests comparing the implementation with
   the expected result.
 * test/${arch}/${isax}/compare.c — tests comparing the portable
   implementation with the "native" version, using random data for
   inputs.

The comparison test is optional, but very nice to have.  The regular
tests are required.

Hopefully it's clear what to do by using other functions in those
files as a template, but if you have trouble please feel free to
contact us; we're happy to help!

## Usage

Each instruction set has a separate file; `x86/mmx.h` for MMX,
`s`x86/se.h` for SSE, ``x86/sse2.h` for SSE2, and so on.  Just include
the header for whichever instruction set(s) you want, and SIMDe will
provide the fastest implementation it can given which extensions
you've enabled in your compiler (i.e., if you want to use NEON to
implement SSE, you'll need to pass something like `-mfpu=neon`).

Symbols are prefixed with `simde_`.  For example, the MMX
`_mm_add_pi8` intrinsic becomes `simde_mm_add_pi8`, and `__m64`
becomes `simde__m64`.

Since SIMDe is meant to be portable, many functions which assume types
are of a specific size have been altered to use fixed-width types
instead.  For example, Intel's APIs assume `int` is 32 bits, so
`simde_mm_set_pi32`'s arguments are `int32_t` instead of `int`.  On
platforms where the native API's assumptions hold (*i.e.*, if `int`
really is 32-bits) SIMDe's types should be compatible, so existing
code needn't be changed unless you're porting to a new platform.

For best performance, you should enable OpenMP 4 SIMD support by
defining `SIMDE_ENABLE_OPENMP` before including any SIMDe headers, and
enabling OpenMP support in your compiler.  GCC and ICC both support a
flag to enable only OpenMP SIMD support instead of full OpenMP (the
SIMD support doesn't require the OpenMP run-time library); for GCC the
flag is `-fopenmp-simd`, for ICC `-openmp-simd`.  SIMDe also supports
using [Cilk Plus](https://www.cilkplus.org/), [GCC loop-specific
pragmas](https://gcc.gnu.org/onlinedocs/gcc/Loop-Specific-Pragmas.html),
or [clang pragma loop hint
directives](http://llvm.org/docs/Vectorizers.html#pragma-loop-hint-directives),
though these are not as well tested.

## Portability

### Compilers

SIMDe requires C99.

Every commit is tested with several different versions of GCC, clang,
and PGI via [Travis CI](https://travis-ci.org/nemequ/simde) on Linux.
Microsoft Visual C++ is tested on Windows using
[AppVeyor](https://ci.appveyor.com/project/quixdb/simde).  Intel C/C++
Compiler is also tested sporadically (mostly because their
optimization reports are excellent).

I'm generally willing to accept patches to add support for other
compilers, as long as they're not too disruptive, *especially* if we
can get CI support going.  Travis and AppVeyor are great, but feel
free to use whatever works.

### Hardware

Currently only x86_64, x86, and ARMv7 receive any sort of regular
testing.  If you'd like to see more thorough testing of other
architectures, please consider finding a way to integrate it into CI.
One example might be running qemu on Travis CI (or some other hosted
CI).

## Related Projects

 * The "builtins" module in
   [portable-snippets](https://github.com/nemequ/portable-snippets)
   does much the same thing, but for compiler-specific intrinsics
   (think `__builtin_clz` and `_BitScanForward`), **not** SIMD
   intrinsics.
 * Intel offers an emulator, the [Intel® Software Development
   Emulator](https://software.intel.com/en-us/articles/intel-software-development-emulator/)
   which can be used to develop software which uses Intel intrinsics
   without having to own hardware which supports them, though AFAIK it
   doesn't help for deployment.
 * I'm not aware of anyone else trying to create portable
   implementations of an instruction set, but there are a few projects
   trying to implement one set with another:
   * [ARM_NEON_2_x86_SSE](https://github.com/intel/ARM_NEON_2_x86_SSE)
     — implementing NEON using SSE.  Quite extensive, Apache 2.0
     license.
   * [sse2neon](https://github.com/jratcliff63367/sse2neon) —
     implementing SSE using NEON.  This code has already been merged
     into SIMDe.
   * [veclib](https://github.com/IvantheDugtrio/veclib) — implementing
     SSE2 using AltiVec/VMX, using a non-free IBM library called
     [powerveclib](https://www.ibm.com/developerworks/community/groups/community/powerveclib/)
   * [SSE-to-NEON](https://github.com/otim/SSE-to-NEON) — implementing
     SSE with NEON.  Non-free.
 * [arm-neon-tests](https://github.com/christophe-lyon/arm-neon-tests)
   contains tests te verify NEON implementations.

If you know of any other related projects, please [let us
know](https://github.com/nemequ/simde/issues/new)!

## Caveats

Sometime features can't be emulated.  If SIMDe is operating in native
mode the functions will work as expected, but if there is no native
support the following caveats apply:

### SSE

 * `simde_MM_SET_ROUNDING_MODE()` will use `fesetround()`, altering
   the global rounding mode.
 * `simde_mm_getcsr` and `simde_mm_setcsr` only implement bits 13 and
   14 (rounding mode).

## License

SIMDe is distributed under an MIT-style license; see COPYING for
details.
