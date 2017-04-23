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

## Related Projects

This is similar in principle to the builtins module in
[portable-snippets](https://github.com/nemequ/portable-snippets).

## Caveats

### SSE

If SSE support is emulated, `_MM_SET_ROUNDING_MODE()` will use
`fesetround()`, altering the global rounding mode.

## Platform Support

SIMDe requires C99, and is tested with relatively recent versions of
GCC (4.4+), clang (3.8+), and PGI (16.10), via [Travis
CI](https://travis-ci.org/nemequ/simde).

## License

To the extent possible under law, the authors have waived all
copyright and related or neighboring rights to this code.  For
details, see the Creative Commons Zero 1.0 Universal license at
https://creativecommons.org/publicdomain/zero/1.0/
