# SIMD Everywhere

SIMDe is an experimental project which attempts to implement SIMD
intrinsics on hardware which doesn't natively support them (*e.g.*,
calling SSE functions on ARM).

The initial focus is on writing complete portable implementations.
Once that's complete we will start focusing on optimizations, such as
implementing one set of functions with another (*e.g.*, a NEON
implementation of SSE).

Currently, there are full implementations of the following instruction
sets:

 * MMX

For information on which instruction sets we intend to support, as
well as detailed progress information, see the
[instruction-set-support](https://github.com/nemequ/simde/issues?q=is%3Aissue+is%3Aopen+label%3Ainstruction-set-support)
label in the issue tracker.  If you'd like to be notified when an
instruction set is available you may subscribe to the relevant issue.

There are a *lot* of instructions to get through.  If you're
interested in helping please feel free to dive right in!  All
instructions must have a test (see `test.c`), as well as a portable
implementation in the relevant header.

## Related Projects

This is very similar to the builtins module in
[portable-snippets](https://github.com/nemequ/portable-snippets).  In
the future, I may even choose to roll this project into
portable-snippets.

## Why?

Ideas include:

 * Run code which relies on ISA extensions on CPUs which don't support
   them without a rewrite.
 * An easy way to port code to an instruction set your CPU doesn't
   support without having to run your tests in an emulator.
 * Understanding how an instruction works when the documentation fails
   you.

## License

To the extent possible under law, the authors have waived all
copyright and related or neighboring rights to this code.  For
details, see the Creative Commons Zero 1.0 Universal license at
https://creativecommons.org/publicdomain/zero/1.0/
