#!/bin/bash

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
  curl "https://software.intel.com/sites/landingpage/IntrinsicsGuide/files/data-3.5.0.xml" > iig.xml
fi

PATTERN="$(xmllint --xpath '//intrinsic/@name' iig.xml | grep -Po '(?<=")[^"]+' | xargs printf '%s|' | rev | cut -c 2- | rev)"

for file in x86/*.c; do
  echo "${file}..."
  sed -i -E -e "s/([^_])simde(${PATTERN})/\1\2/g" "$file";
done
