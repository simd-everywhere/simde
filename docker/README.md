# SIMDe Development Container

## WORK IN PROGRESS

This isn't fully functional yet.  Emscripten and clang cross builds
don't work yet.  There are also some bugs in qemu on a couple of
platforms which cause tests to fail, but you can still compile.

The basic idea is to set up a Debian system with lots of different
compilers and emulators for different architectures and configure
multiple builds in different directories.

Note that there are also several docker files in the test/
subdirectory.  These can be used to test other operating systems,
especially older compilers which aren't supported on Debian testing
anymore.

Note that I use Podman not Docker, so this may require some tweaks to
run on Docker.  Patches welcome.  If it works for you please let us
know so we can remove this paragraph.

To use this, just run the `simde-dev.sh` script.  Once the container is
ready it will drop you into a bash shell in `/opt/simde`; this is the
build directory.  Run `simde-reset-build.sh` and it should be populated
with a bunch of subdirectories which you can build with ninja.  For
example, `ninja -C gcc-10` will build SIMDe using GCC 10.  If you want
to run the tests, `ninja -C gcc-10 test`.

This will bind the parent directory (the root of the SIMDe checkout)
to `/usr/local/src/simde`; any changes to either will propogate to the
other, meaning you can continue using your normal development
environment and just re-run ninja to rebuild SIMDe.

## CMake-Based Builds

A couple of directories are different because I haven't managed to get
them working with Meson yet:

For Emscripten, don't include the "test", argument with ninja since
CMake isn't smart enough to actually build the tests before it tries to
run them.  Even if it were, you need to run them in v8 not node since
the version of node bundled with emscripten doesn't support WASM SIMD.
To use emscripten, do something like:

```bash
cd emscripten
ninja
v8 --enable-experimental-wasm run-tests.js
```

I also haven't figured out how to get clang cross-compiling with Meson
yet, so most of the clang cross-compilation builds don't work yet.
There is a CMake-based aarch64-clang-10 build, though.  To use it:

```bash
cd aarch64-clang-10
ninja
qemu-aarch64-system ./run-tests
```
