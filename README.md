# SIMD Everywhere
[![Gitter chat](https://badges.gitter.im/gitterHQ/gitter.png)](https://gitter.im/simd-everywhere/community)

The SIMDe header-only library provides fast, portable implementations of 
[SIMD intrinsics](https://en.wikipedia.org/wiki/SIMD) on hardware which
doesn't natively support them, such as calling [SSE](https://en.wikipedia.org/wiki/Streaming_SIMD_Extensions)
functions on ARM.  There is no performance penalty if the hardware
supports the native implementation (*e.g.*, SSE/[AVX](https://en.wikipedia.org/wiki/Advanced_Vector_Extensions)
runs at full speed on [x86](https://en.wikipedia.org/wiki/X86),
[NEON](https://en.wikipedia.org/wiki/ARM_architecture#Advanced_SIMD_(Neon)) on [ARM](https://en.wikipedia.org/wiki/ARM_architecture),
*etc.*).

This makes porting code to other architectures much easier in a few
key ways:

First, instead of forcing you to rewrite everything for each
architecture, SIMDe lets you get a port up and running almost
effortlessly.  You can then start working on switching the most
performance-critical sections to native intrinsics, improving
performance gradually.  SIMDe lets (for example) SSE/AVX and NEON code
exist side-by-side, in the same implementation.

Second, SIMDe makes it easier to write code targeting [ISA](https://en.wikipedia.org/wiki/Instruction_set_architecture)
extensions you don't have convenient access to.  You can run NEON code on your
x86 machine *without an emulator*.  Obviously you'll eventually want
to test on the actual hardware you're targeting, but for most
development, SIMDe can provide a much easier path.

SIMDe takes a very different approach from most other SIMD abstraction
layers in that it aims to expose the entire functionality of the
underlying instruction set.  Instead of limiting functionality to the
lowest common denominator, SIMDe tries to minimize the amount of
effort required to port while still allowing you the space to optimize
as needed.

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

You can [try SIMDe online](https://simde.netlify.com/godbolt/demo)
using Compiler Explorer and an amalgamated SIMDe header.

If you have any questions, please feel free to use the
[issue tracker](https://github.com/nemequ/simde/issues) or the
[mailing list](https://groups.google.com/forum/#!forum/simde).

## Current Status

There are currently complete implementations of the following instruction
sets:

 * [MMX](https://en.wikipedia.org/wiki/MMX_(instruction_set))
 * [SSE](https://en.wikipedia.org/wiki/Streaming_SIMD_Extensions)
 * [SSE2](https://en.wikipedia.org/wiki/SSE2)
 * [SSE3](https://en.wikipedia.org/wiki/SSE3)
 * [SSSE3](https://en.wikipedia.org/wiki/SSSE3)
 * [SSE4.1](https://en.wikipedia.org/wiki/SSE4#SSE4.1)
 * [AVX](https://en.wikipedia.org/wiki/Advanced_Vector_Extensions)
 * [FMA](https://en.wikipedia.org/wiki/FMA_instruction_set)

As well as partial support for many others; see the
[instruction-set-support](https://github.com/nemequ/simde/issues?q=is%3Aissue+is%3Aopen+label%3Ainstruction-set-support+sort%3Aupdated-desc)
label in the issue tracker for details on progress.  If you'd like to
be notified when an instruction set is available you may subscribe to
the relevant issue.

If you have a project you're interested in using with SIMDe but we
don't yet support all the functions you need, please file an issue
with a list of what's missing so we know what to prioritize.

The `master` branch is protected so commits never reach it unless
they have passed extensive CI checks.  Status badges don't really
make sense since they will always be green, but here are the links:

* [Travis CI](https://travis-ci.org/nemequ/simde)
* [AppVeyor](https://ci.appveyor.com/project/quixdb/simde)
* [GitHub Actions](https://github.com/nemequ/simde/actions)
* [Azure Pipelines](https://dev.azure.com/simd-everywhere/SIMDe/_build)
* [Drone CI](https://cloud.drone.io/nemequ/simde)

## Contributing

First off, if you're reading this: thank you! Even considering
contributing to SIMDe is very much appreciated!

SIMDe is a fairly large undertaking; there are a *lot* of functions to
get through and a lot of opportunities for optimization on different
platforms, so we're very happy for any help you can provide.

Programmers of all skill levels are welcome, there are lots of tasks
which are pretty straightforward and don't require any special
expertise.

If you're not sure how you'd like to contribute, please consider taking
a look at [the issue tracker](https://github.com/nemequ/simde/issues).
There is a [good first issue](https://github.com/nemequ/simde/issues?q=is%3Aissue+is%3Aopen+label%3A%22good+first+issue%22)
tag if you want to ease into a your first contributions, but if you're
interested in something else please get in touch via the issue tracker;
we're happy to help you get a handle on whatever you are interested in.

If you're interested in implementing currently unimplemented functions,
there is [a
guide](https://github.com/nemequ/simde/wiki/Implementing-a-New-Function)
explaining how to add new functions and how to quickly and easily get
a test case in place.  It's a bit rough right now, but if anything is
unclear please feel free to use the issue tracker to ask about
anything you're not clear on.

## Usage

First, it is important to note that *you do not need two separate
versions* (one using SIMDe, the other native).  If the native functions
are available SIMDe will use them, and compilers easily optimize away
any overhead from SIMDe; all they have to do is some basic inlining.
`-O2` should be enough, but we strongly recommend `-O3` (or whatever
flag instructs your compiler to aggressizely optimize) since many of
the portable fallbacks are substantially faster with aggressive
auto-vectorization that isn't enabled at lower optimization levels.

Each instruction set has a separate file; `x86/mmx.h` for MMX,
`x86/sse.h` for SSE, `x86/sse2.h` for SSE2, and so on.  Just include
the header for whichever instruction set(s) you want, and SIMDe will
provide the fastest implementation it can given which extensions
you've enabled in your compiler (i.e., if you want to use NEON to
implement SSE, you may need to pass something like `-mfpu=neon`
or `-march=armv8-a+simd`.  See
[GCC ARM-Options](https://gcc.gnu.org/onlinedocs/gcc/ARM-Options.html)
for more information).

If you define `SIMDE_ENABLE_NATIVE_ALIASES` before including SIMDe
you can use the same names as the native functions.  Unfortunately,
this is somewhat error-prone due to portability issues in the APIs, so
it's recommended to only do this for testing.  When
`SIMDE_ENABLE_NATIVE_ALIASES` is undefined only the versions prefixed
with `simde_` will be available; for example, the MMX `_mm_add_pi8`
intrinsic becomes `simde_mm_add_pi8`, and `__m64` becomes `simde__m64`.

Since SIMDe is meant to be portable, many functions which assume types
are of a specific size have been altered to use fixed-width types
instead.  For example, Intel's APIs use `char` for signed 8-bit
integers, but `char` on ARM is generally unsigned.  SIMDe uses `int8_t`
to make the API portable, but that means your code may require some
minor changes (such as using `int8_t` instead of `char`) to work on
other platforms.

That said, the changes are usually quite minor.  It's often enough to
just use search and replace, manual changes are required pretty
infrequently.

For best performance, in addition to `-O3` (or whatever your compiler's
equivalent is), you should enable OpenMP 4 SIMD support by defining
`SIMDE_ENABLE_OPENMP` before including any SIMDe headers, and
enabling OpenMP support in your compiler.  GCC and ICC both support a
flag to enable only OpenMP SIMD support instead of full OpenMP (the OpenMP
SIMD support doesn't require the OpenMP run-time library); for GCC the
flag is `-fopenmp-simd`, for ICC `-qopenmp-simd`.  SIMDe also supports
using [Cilk Plus](https://www.cilkplus.org/), [GCC loop-specific
pragmas](https://gcc.gnu.org/onlinedocs/gcc/Loop-Specific-Pragmas.html),
or [clang pragma loop hint
directives](http://llvm.org/docs/Vectorizers.html#pragma-loop-hint-directives),
though these are not nearly as effective as OpenMP SIMD and depending
on them will likely result in less efficient code.

## Portability

### Compilers

SIMDe does depend on some C99 features, though the subset supported by
MSVC also works.  While we do our best to make sure we provide optimized
implementations where they are supported, SIMDe does contain portable
fallbacks which are designed to work on any C99 compiler.

Every commit is tested in CI on multiple compilers, platforms, and
configurations, and our test coverage is extremely extensive.
Currently tested compilers include:

 * GCC versions back to 4.8
 * Clang versions back to 7
 * Microsoft Visual Studio back to 12 (2013)
 * IBM XL C/C++
 * Intel C/C++ Compiler (ICC)
 * PGI C Compiler

I'm generally willing to accept patches to add support for other
compilers, as long as they're not too disruptive, *especially* if we
can get CI support going.  We currently use Travis CI, AppVeyor, and
Microsoft Azure Pipelines, but other CI platforms can be added as
necessary.

### Hardware

The following architectures are tested in CI for every commit:

 * x86_64
 * x86
 * AArch64
 * ARMv8
 * ARMv7
 * PPC64
 * MIPS

We would love to add more, so patches are extremely welcome!

The tests currently contain some assumptions that they are running on
a little-endian CPU.  We're working on this, but for now big endian
CPUs *should* work, but we can't promise.

## Related Projects

 * The "builtins" module in
   [portable-snippets](https://github.com/nemequ/portable-snippets)
   does much the same thing, but for compiler-specific intrinsics
   (think `__builtin_clz` and `_BitScanForward`), **not** SIMD
   intrinsics.
 * Intel offers an emulator, the [Intel® Software Development
   Emulator](https://software.intel.com/en-us/articles/intel-software-development-emulator/)
   which can be used to develop software which uses Intel intrinsics
   without having to own hardware which supports them, though it
   doesn't help for deployment.
 * [Iris](https://github.com/AlexYaruki/iris) is the only other project
   I'm aware of which is attempting to create portable implementations
   like SIMDe.  SIMDe is much further along on the Intel side, but Iris
   looks to be in better shape on ARM.  C++-only, Apache 2.0 license.
   AFAICT there are no accelerated fallbacks, nor is there a good way to
   add them since it relies extensively on templates.
 * There are a few projects trying to implement one set with another:
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
     SSE with NEON.  Non-free, C++.
 * [arm-neon-tests](https://github.com/christophe-lyon/arm-neon-tests)
   contains tests te verify NEON implementations.

If you know of any other related projects, please [let us
know](https://github.com/nemequ/simde/issues/new)!

## Caveats

Sometime features can't be emulated.  If SIMDe is operating in native
mode the functions will work as expected, but if there is no native
support some caveats apply:

 * Many functions require <math.h> and/or <fenv.h>.  SIMDe will still
   work without those headers, but the results of those functions are
   undefined.
 * x86 / x86_64
   * SSE
     * `SIMDE_MM_SET_ROUNDING_MODE()` will use `fesetround()`, altering
       the global rounding mode.
     * `simde_mm_getcsr` and `simde_mm_setcsr` only implement bits 13
       and 14 (rounding mode).
   * AVX
     * `simde_mm256_test*` do not set the CF/ZF registers as there is
       no portable way to implement that functionality.
     * `simde_mm256_zeroall` and `simde_mm256_zeroupper` are not
       implemented as there is no portable way to implement that
       functionality.

Additionally, there are some known limitations which apply when using
native aliases (`SIMDE_ENABLE_NATIVE_ALIASES`):

* On Windows x86 (but not x86_64), some MMX functions and SSE/SSE2
  functions which use MMX types (__m64) other than for pointers may
  return incorrect results.

Also, as mentioned earlier, while some APIs make assumptions about
basic types (*e.g.*, `int` is 32 bits), SIMDe does not, so many types
have been altered to use portable fixed-width versions such as
`int32_t`.

If you find any other differences, please file an issue so we can either fix
it or add it to the list above.

## Benefactors

SIMDe uses resources provided for free by a number of organizations.
While this shouldn't be taken to imply endorsement of SIMDe, we're
tremendously grateful for their support:

 * [GitHub](https://github.com/) — hosts our source repository, issue
   tracker, etc.
 * [Travis CI](https://travis-ci.org/) — provides CI testing on
   numerous platforms.
 * [AppVeyor](https://www.appveyor.com/) — provides CI testing on
   Windows.
 * [Drone CI](https://drone.io/) — provides CI testing on ARM 32 bits
   platform, etc.
 * [IntegriCloud](https://integricloud.com/) — provides access to a very
   fast POWER9 server for developing AltiVec/VMX support.
 * [GCC Compile Farm](https://gcc.gnu.org/wiki/CompileFarm) — provides
   access to a wide range of machines with different architectures for
   developing support for various ISA extensions.
 * [CodeCov.io](https://codecov.io/) — provides code coverage analysis
   for our test cases.

Without such organizations donating resources, SIMDe wouldn't be nearly
as useful or usable as it is today.

We would also like to thank anyone who has helped develop the myriad
of software on which SIMDe relies, including compilers and analysis
tools.

Finally, a special thank you to
[anyone who has contributed](https://github.com/nemequ/simde/graphs/contributors)
to SIMDe, filed bugs, provided suggestions, or helped with SIMDe
development in any way.

## License

SIMDe is distributed under an MIT-style license; see COPYING for
details.
