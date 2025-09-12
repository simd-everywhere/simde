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

# num_cpus() is from https://sources.debian.org/src/util-linux/2.40.2-13/tests/run.sh/?hl=39#L39
function num_cpus()
{
	local num

	# coreutils
	if num=$(nproc 2>/dev/null); then
		:
	# BSD, OSX
	elif num=$(sysctl -n hw.ncpu 2>/dev/null); then
		:
	else
		num=$(grep -c "^processor" /proc/cpuinfo 2>/dev/null)
	fi

	# translate garbage output to "1"
	if test "$num" -gt "0" 2>/dev/null ;then
		echo "$num"
	else
		echo 1
	fi
}

# x86

./download-iig.sh "${DIRNAME}/iig.xml"
PATTERN="$(xmllint --xpath '//intrinsic/@name' "${DIRNAME}/iig.xml" | grep -Po '(?<=")[^"]+' | grep -Pv '^(_mm256_cvtsi256_si32|_mm512_loadu_epi.+)$' | xargs printf '%s|' | rev | cut -c 2- | rev)"
PATTERN="${PATTERN}|__m64[ ,]|__m128[ ,]|__m128i[ ,]|__m128d[ ,]|__m128bh[ ,]|__m128h[ ,]|__m256[ ,]|__m256i[ ,]|__m256d[ ,]|__m256bh[ ,]|__m256h[ ,]|__m512[ ,]|__m512i[ ,]|__m512d[ ,]|__m512bh[ ,]|__m512h[ ,]|__mmask8[ ,]|__mmask16[ ,]|__mmask32[ ,]|__mmask64[ ,]"
echo "s/([^_])simde(${PATTERN})/\1\2/g" > pattern
ls x86/*.c | xargs -n1 -P$(num_cpus) sed -i -E -f pattern
ls x86/avx512/*.c | xargs -n1 -P$(num_cpus) sed -i -E -f pattern

# MSA

perl -p -i -e 's/([^a-zA-Z0-9_])simde_msa_/$1__msa_/g' mips/msa/*.{c,h}

# NEON

perl -p -i -e 's/([^a-zA-Z0-9_])simde_v/$1v/g' $(ls arm/neon/*.{c,h} | grep -v test-neon.h)
perl -p -i -e 's/([^a-zA-Z0-9_])simde_int8x/$1int8x/g' $(ls arm/neon/*.{c,h} | grep -v test-neon.h | grep -v reinterpret)
perl -p -i -e 's/([^a-zA-Z0-9_])simde_int16x/$1int16x/g' $(ls arm/neon/*.{c,h} | grep -v test-neon.h | grep -v reinterpret)
perl -p -i -e 's/([^a-zA-Z0-9_])simde_int32x/$1int32x/g' $(ls arm/neon/*.{c,h} | grep -v test-neon.h | grep -v reinterpret)
perl -p -i -e 's/([^a-zA-Z0-9_])simde_int64x/$1int64x/g' $(ls arm/neon/*.{c,h} | grep -v test-neon.h | grep -v reinterpret)
perl -p -i -e 's/([^a-zA-Z0-9_])simde_uint8x/$1uint8x/g' $(ls arm/neon/*.{c,h} | grep -v test-neon.h | grep -v reinterpret)
perl -p -i -e 's/([^a-zA-Z0-9_])simde_uint16x/$1uint16x/g' $(ls arm/neon/*.{c,h} | grep -v test-neon.h | grep -v reinterpret)
perl -p -i -e 's/([^a-zA-Z0-9_])simde_uint32x/$1uint32x/g' $(ls arm/neon/*.{c,h} | grep -v test-neon.h | grep -v reinterpret)
perl -p -i -e 's/([^a-zA-Z0-9_])simde_uint64x/$1uint64x/g' $(ls arm/neon/*.{c,h} | grep -v test-neon.h | grep -v reinterpret)
perl -p -i -e 's/([^a-zA-Z0-9_])simde_float16x/$1float16x/g' $(ls arm/neon/*.{c,h} | grep -v test-neon.h | grep -v reinterpret)
perl -p -i -e 's/([^a-zA-Z0-9_])simde_float32x/$1float32x/g' $(ls arm/neon/*.{c,h} | grep -v test-neon.h | grep -v reinterpret)
perl -p -i -e 's/([^a-zA-Z0-9_])simde_float64x/$1float64x/g' $(ls arm/neon/*.{c,h} | grep -v test-neon.h | grep -v reinterpret)

# SVE

perl -p -i -e 's/([^a-zA-Z0-9_])simde_sv/$1sv/g' arm/sve/*.{c,h}

# WASM SIMD128

perl -p -i -e 's/([^a-zA-Z0-9_])simde_wasm_/$1wasm_/g' wasm/simd128/*.{c,h}
