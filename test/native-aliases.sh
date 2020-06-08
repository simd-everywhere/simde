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

cd "$(dirname "${0}")"

if [ ! -e iig.xml ]; then
  VERSION="$(curl -s 'https://software.intel.com/sites/landingpage/IntrinsicsGuide/' | grep -Po '(?<=intrinsicsguide.min.js\?)([0-9\.]+)')"
  curl "https://software.intel.com/sites/landingpage/IntrinsicsGuide/files/data-${VERSION}.xml" > iig.xml
fi

PATTERN="$(xmllint --xpath '//intrinsic/@name' iig.xml | grep -Po '(?<=")[^"]+' | grep -Pv '^(_mm256_cvtsi256_si32|_mm512_loadu_epi.+)$' | xargs printf '%s|' | rev | cut -c 2- | rev)"
echo "s/([^_])simde(${PATTERN})/\1\2/g" > pattern

ls x86/*.c | xargs -n1 -P$(nproc) sed -i -E -f pattern
