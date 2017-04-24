# SIMD Everywhere

SIMDe is an attempt to implement SIMD intrinsics on hardware which
doesn't natively support them, such as calling SSE functions on ARM.

The initial focus is on writing complete portable implementations.
Once that's complete we will start focusing on optimizations, such as
implementing one set of functions with another.

For an example of a project using SIMDe, see
[LZSSE-SIMDe](https://github.com/nemequ/LZSSE-SIMDe).

There are currently full implementations of the following instruction
sets:

 * MMX

Work is underway to support various versions of SSE.  For detailed
progress information, see the
[instruction-set-support](https://github.com/nemequ/simde/issues?q=is%3Aissue+is%3Aopen+label%3Ainstruction-set-support+sort%3Aupdated-desc)
label in the issue tracker.  If you'd like to be notified when an
instruction set is available you may subscribe to the relevant issue.

There are a *lot* of instructions to get through.  If you're
interested in helping please feel free to dive right in!  All
instructions must include tests (see `test/test-*.c`), as well as a
portable implementation in the relevant header.

## Usage

Each instruction set has a separate file; `mmx.h` for MMX, `sse.h` for
SSE, `sse2.h` for SSE2, and so on.  Just include the header for
whichever instruction sets you want.  If your compiler has enabled the
relevant instruction set SIMDe will use the native intrinsics,
otherwise a portable fallback will be used.

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

If you know of any other related projects, please [let us
know](https://github.com/nemequ/simde/issues/new)!

## Caveats

### SSE

If SSE support is emulated, `_MM_SET_ROUNDING_MODE()` will use
`fesetround()`, altering the global rounding mode.

## Platform Support

SIMDe requires C99.

Every commit is tested with relatively recent versions of GCC (4.4+),
clang (3.8+), and PGI (16.10), via [Travis
CI](https://travis-ci.org/nemequ/simde).  Intel C/C++ Compiler is also
tested sporadically (mostly because their optimization reports are
excellent).

I'm generally willing to accept patches to add support for other
compilers, as long as they're not too disruptive, *especially* if we
can get CI support going.  Travis and AppVeyor are great, but feel
free to use whatever works.

## License

To the extent possible under law, the authors have waived all
copyright and related or neighboring rights to this code.  For
details, see the Creative Commons Zero 1.0 Universal license at
https://creativecommons.org/publicdomain/zero/1.0/
