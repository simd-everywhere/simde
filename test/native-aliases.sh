#!/bin/bash -e

# Convert SIMDe test cases to strip the simde_ prefix to test native
# aliases.
#
# Based on a script written by Michael R. Crusoe <michael.crusoe@gmail.com>
#
# After this is done, you should be able to do something like
#
#   cd path/to/simde/root
#   mkdir build && cd build
#   CFLAGS='-DSIMDE_ENABLE_NATIVE_ALIASES -DSIMDE_NATIVE_ALIASES_TESTING' CXXFLAGS='-DSIMDE_ENABLE_NATIVE_ALIASES -DSIMDE_NATIVE_ALIASES_TESTING' meson ..
#   ninja

DIRNAME="$(realpath "$(dirname "${0}")")"
cd "${DIRNAME}"

# x86

./download-iig.sh "${DIRNAME}/iig.xml"
PATTERN="$(xmllint --xpath '//intrinsic/@name' "${DIRNAME}/iig.xml" | grep -Po '(?<=")[^"]+' | grep -Pv '^(_mm256_cvtsi256_si32|_mm512_loadu_epi.+)$' | xargs printf '%s|' | rev | cut -c 2- | rev)"
echo "s/([^_])simde(${PATTERN})/\1\2/g" > pattern
ls x86/*.c | xargs -n1 -P$(nproc) sed -i -E -f pattern

# NEON

perl -p -i -e 's/([^a-zA-Z0-9_])simde_v/$1v/g' arm/neon/*.{c,h}

# SVE

perl -p -i -e 's/([^a-zA-Z0-9_])simde_sv/$1sv/g' arm/sve/*.{c,h}

# WASM SIMD128

perl -p -i -e 's/([^a-zA-Z0-9_])simde_wasm_/$1wasm_/g' wasm/*.{c,h}
