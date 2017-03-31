# SIMD Everywhere

SIMDe is an experimental project which attempts to implement SIMD
intrinsics on hardware which doesn't natively support them.

The first target for SIMDe is SSE.  The goal is to be able to to
include SIMDe's `sse.h` and have SSE functions like `_mm_add_ps()`
available for use everywhere (i.e., even on ARM).

Right now the focus is on portable implementations, but eventually I'd
like to try to implement instruction sets with one another (like
implementing SSE using NEON).

For information on which instruction sets we intend to support, or to
track progress, see the
[instruction-set-support](https://github.com/nemequ/simde/issues?q=is%3Aissue+is%3Aopen+label%3Ainstruction-set-support)
label in the issue tracker.

It's going to be a while before this project is really usable, if
ever.  There are a *lot* of instructions.  If you'd like to help,
please feel free to dive right in!  All instructions must have a test
(see `test.c`), which tends to be harder than writing the actual
implementation, but it's really not difficult work.

## Portability

The code currently requires GCC (or a compiler which implements GCC's
vector extensions, like clang or icc).  It wouldn't be too difficult
to support other compilers, one would mostly just need to add macros
for accessing individual elements in the vector types, and define
vector types in an ifdef to avoid relying on the `vector_size` GNU C
extension.

I don't know when, or if, I'll get around to it, but if you're willing
to work on it patches are welcome.

## Related Projects

This is very similar to the builtins module in
[portable-snippets](https://github.com/nemequ/portable-snippets).  In
the future, I may even choose to roll this project into
portable-snippets.

## License

To the extent possible under law, the authors have waived all
copyright and related or neighboring rights to this code.  For
details, see the Creative Commons Zero 1.0 Universal license at
https://creativecommons.org/publicdomain/zero/1.0/
