#!/bin/bash
echo "::group::Trailing whitespace"
# Check for trailing whitespace
find simde/ \( -name '*.c' -o -name '*.h' \) -exec grep -nP '\s+$' {} + && exit 1
echo "::endgroup::"
echo "::group::Tabs"
# We use spaces, not tabs.  I don't want to start a holy war here;
# I don't actually have a strong preference between the two, but I
# do have a strong preference for consistency, so don't @ me.
find simde/ \( -name '*.c' -o -name '*.h' \) -exec grep -nP '\t' {} + && exit 1
echo "::endgroup::"
echo "::group::Bad substitutions"
# s/8/16/ will result in this if the input is x86.
git grep -i 'x''1''6''6' && exit 1
echo "::endgroup::"
echo "::group::Incorrect assertions in test/"
grep -PR '(?<=[^a-zA-Z0-9_])simde_assert_u?int(8|16|32|64)(?>[^a-zA-Z0-9_])' test/ && exit 1
echo "::endgroup::"
echo "::group::Executable sources"
# Check to make sure no source files have the executable bit set
find \( -name '*.c' -o -name '*.h' \) -executable | grep -q '.' && exit 1
echo "::endgroup::"
echo "::group::Missing NEON includes"
# Make sure neon.h includes all the NEON headers.
for f in simde/arm/neon/*.h; do grep -q "include \"neon/$(basename "$f")\"" simde/arm/neon.h || (echo "Missing $f" && exit 1); done
echo "::endgroup::"
echo "::group::Missing SVE includes"
# Make sure sve.h includes all the SVE headers.
for f in simde/arm/sve/*.h; do grep -q "include \"sve/$(basename "$f")\"" simde/arm/sve.h || (echo "Missing $f" && exit 1); done
echo "::endgroup::"
echo "::group::Missing MSA includes"
# Make sure msa.h includes all the MSA headers.
for f in simde/mips/msa/*.h; do grep -q "include \"msa/$(basename "$f")\"" simde/mips/msa.h || (echo "Missing $f" && exit 1); done
echo "::endgroup::"
echo "::group::Header guards"
# Make sure we can find the expected header guards.  It's easy to miss this when doing C&P
while IFS= read -r -d '' file
do
  grep -q "$(echo "$file" | tr '[:lower:]' '[:upper:]' | tr '[:punct:]' '_')" "$file" || (echo "Missing or incorrect header guard in $file" && exit 1)
done < <(find simde/*/ -name '*.h' -print0)
echo "::endgroup::"
echo "::group::Newline at EOF"
# There should be an empty line at the end of every file
while IFS= read -r -d '' file
do
  if [ -n "$(tail -c 1 "$file")" ]
  then echo "No newline at end of $file" && exit 1
  fi
done < <(find simde -name '*.h' -print0)
echo "::endgroup::"
echo "::group::ifndef"
# Don't #ifndef ; use !defined(...) instead.  ifndef leads to annoying inconsistencies
while IFS= read -r -d '' file
do
  grep -qP '^ *# *ifndef ' "${file}" && exit 1
done < <(find simde -name '*.h' -print0)
echo "::endgroup::"
echo "::group::Meson install headers"
# List of headers we want Meson to install
while IFS= read -r -d '' file
do
  grep -qF "$(basename "${file}" .h)" meson.build || (echo "${file} missing from top-level meson.build" && exit 1)
done < <(find simde -name '*.h' -print0)
echo "::endgroup::"
echo "::group::AltiVec raw vector keyword"
# Make sure we don't accidentally use `vector ...` instead of SIMDE_POWER_ALTIVEC_VECTOR(...)
find simde/ \( -name '*.c' -o -name '*.h' \) -exec grep -nP 'vector( +)((bool|signed|unsigned) +)?(double|float|long long|long|int|short|char)' {} + && exit 1
echo "::endgroup::"
echo "::group::Preprocessor directive indentation"
# Check indentation of preprocessor directives.
find simde/*/ -name 'avx*.h' -exec pcre2grep -M '{\n#' {} + && exit 1
echo "::endgroup::"
echo '::group::Stray "&& 0"'
git grep ' && 0' simde/ test/ && exit 1
echo "::endgroup::"

