/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 *   2020      Himanshi Mathur <himanshi18037@iiitd.ac.in>
 *   2020      Hidayat Khan <huk2209@gmail.com>
 *   2020      Christopher Moore <moore@free.fr>
 */

#if !defined(SIMDE_X86_AVX512F_H)
#define SIMDE_X86_AVX512F_H

#include "avx2.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* The problem is that Microsoft doesn't support 64-byte aligned parameters, except for
  __m512/__m512i/__m512d.  Since our private union has an __m512 member it will be 64-byte
  aligned even if we reduce the alignment requirements of other members.

  Even if we're on x86 and use the native AVX-512 types for arguments/return values, the
  to/from private functions will break, and I'm not willing to change their APIs to use
  pointers (which would also require more verbose code on the caller side) just to make
  MSVC happy.

  If you want to use AVX-512 in SIMDe, you'll need to either upgrade to MSVC 2017 or later,
  or upgrade to a different compiler (clang-cl, perhaps?).  If you have an idea of how to
  fix this without requiring API changes (except transparently through macros), patches
  are welcome. */

#  if defined(HEDLEY_MSVC_VERSION) && !HEDLEY_MSVC_VERSION_CHECK(19,10,0)
#    if defined(SIMDE_X86_AVX512F_NATIVE)
#      undef SIMDE_X86_AVX512F_NATIVE
#      pragma message("Native AVX-512 support requires MSVC 2017 or later.  See comment above (in code) for details.")
#    endif
#    define SIMDE_AVX512_ALIGN SIMDE_ALIGN(32)
#  else
#    define SIMDE_AVX512_ALIGN SIMDE_ALIGN(64)
#  endif

typedef union {
#if defined(SIMDE_VECTOR_SUBSCRIPT)
  SIMDE_AVX512_ALIGN int8_t          i8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN int16_t        i16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN int32_t        i32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN int64_t        i64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN uint8_t         u8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN uint16_t       u16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN uint32_t       u32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN uint64_t       u64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #if defined(SIMDE_HAVE_INT128_)
  SIMDE_AVX512_ALIGN simde_int128  i128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN simde_uint128 u128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #endif
  SIMDE_AVX512_ALIGN simde_float32  f32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN simde_float64  f64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN int_fast32_t  i32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN uint_fast32_t u32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
#else
  SIMDE_AVX512_ALIGN int8_t          i8[64];
  SIMDE_AVX512_ALIGN int16_t        i16[32];
  SIMDE_AVX512_ALIGN int32_t        i32[16];
  SIMDE_AVX512_ALIGN int64_t        i64[8];
  SIMDE_AVX512_ALIGN uint8_t         u8[64];
  SIMDE_AVX512_ALIGN uint16_t       u16[32];
  SIMDE_AVX512_ALIGN uint32_t       u32[16];
  SIMDE_AVX512_ALIGN uint64_t       u64[8];
  SIMDE_AVX512_ALIGN int_fast32_t  i32f[64 / sizeof(int_fast32_t)];
  SIMDE_AVX512_ALIGN uint_fast32_t u32f[64 / sizeof(uint_fast32_t)];
  #if defined(SIMDE_HAVE_INT128_)
  SIMDE_AVX512_ALIGN simde_int128  i128[4];
  SIMDE_AVX512_ALIGN simde_uint128 u128[4];
  #endif
  SIMDE_AVX512_ALIGN simde_float32  f32[16];
  SIMDE_AVX512_ALIGN simde_float64  f64[8];
#endif

  SIMDE_AVX512_ALIGN simde__m128_private m128_private[4];
  SIMDE_AVX512_ALIGN simde__m128         m128[4];
  SIMDE_AVX512_ALIGN simde__m256_private m256_private[2];
  SIMDE_AVX512_ALIGN simde__m256         m256[2];

#if defined(SIMDE_X86_AVX512F_NATIVE)
  SIMDE_AVX512_ALIGN __m512         n;
#elif defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(unsigned char)      altivec_u8[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(unsigned short)     altivec_u16[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(unsigned int)       altivec_u32[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(signed char)        altivec_i8[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(signed short)       altivec_i16[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(signed int)         altivec_i32[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(float)              altivec_f32[4];
  #if defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
    SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(unsigned long long) altivec_u64[4];
    SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(signed long long)   altivec_i64[4];
    SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(double)             altivec_f64[4];
  #endif
#endif
} simde__m512_private;

typedef union {
#if defined(SIMDE_VECTOR_SUBSCRIPT)
  SIMDE_AVX512_ALIGN int8_t          i8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN int16_t        i16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN int32_t        i32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN int64_t        i64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN uint8_t         u8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN uint16_t       u16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN uint32_t       u32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN uint64_t       u64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #if defined(SIMDE_HAVE_INT128_)
  SIMDE_AVX512_ALIGN simde_int128  i128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN simde_uint128 u128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #endif
  SIMDE_AVX512_ALIGN simde_float32  f32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN simde_float64  f64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN int_fast32_t  i32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN uint_fast32_t u32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
#else
  SIMDE_AVX512_ALIGN int8_t          i8[64];
  SIMDE_AVX512_ALIGN int16_t        i16[32];
  SIMDE_AVX512_ALIGN int32_t        i32[16];
  SIMDE_AVX512_ALIGN int64_t        i64[8];
  SIMDE_AVX512_ALIGN uint8_t         u8[64];
  SIMDE_AVX512_ALIGN uint16_t       u16[32];
  SIMDE_AVX512_ALIGN uint32_t       u32[16];
  SIMDE_AVX512_ALIGN uint64_t       u64[8];
  #if defined(SIMDE_HAVE_INT128_)
  SIMDE_AVX512_ALIGN simde_int128  i128[4];
  SIMDE_AVX512_ALIGN simde_uint128 u128[4];
  #endif
  SIMDE_AVX512_ALIGN simde_float32  f32[16];
  SIMDE_AVX512_ALIGN simde_float64  f64[8];
  SIMDE_AVX512_ALIGN int_fast32_t  i32f[64 / sizeof(int_fast32_t)];
  SIMDE_AVX512_ALIGN uint_fast32_t u32f[64 / sizeof(uint_fast32_t)];
#endif

  SIMDE_AVX512_ALIGN simde__m128d_private m128d_private[4];
  SIMDE_AVX512_ALIGN simde__m128d         m128d[4];
  SIMDE_AVX512_ALIGN simde__m256d_private m256d_private[2];
  SIMDE_AVX512_ALIGN simde__m256d         m256d[2];

#if defined(SIMDE_X86_AVX512F_NATIVE)
  SIMDE_AVX512_ALIGN __m512d        n;
#elif defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(unsigned char)      altivec_u8[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(unsigned short)     altivec_u16[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(unsigned int)       altivec_u32[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(signed char)        altivec_i8[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(signed short)       altivec_i16[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(signed int)         altivec_i32[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(float)              altivec_f32[4];
  #if defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
    SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(unsigned long long) altivec_u64[4];
    SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(signed long long)   altivec_i64[4];
    SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(double)             altivec_f64[4];
  #endif
#endif
} simde__m512d_private;

typedef union {
#if defined(SIMDE_VECTOR_SUBSCRIPT)
  SIMDE_AVX512_ALIGN int8_t          i8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN int16_t        i16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN int32_t        i32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN int64_t        i64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN uint8_t         u8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN uint16_t       u16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN uint32_t       u32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN uint64_t       u64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #if defined(SIMDE_HAVE_INT128_)
  SIMDE_AVX512_ALIGN simde_int128  i128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN simde_uint128 u128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #endif
  SIMDE_AVX512_ALIGN simde_float32  f32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN simde_float64  f64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN int_fast32_t  i32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_AVX512_ALIGN uint_fast32_t u32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
#else
  SIMDE_AVX512_ALIGN int8_t          i8[64];
  SIMDE_AVX512_ALIGN int16_t        i16[32];
  SIMDE_AVX512_ALIGN int32_t        i32[16];
  SIMDE_AVX512_ALIGN int64_t        i64[8];
  SIMDE_AVX512_ALIGN uint8_t         u8[64];
  SIMDE_AVX512_ALIGN uint16_t       u16[32];
  SIMDE_AVX512_ALIGN uint32_t       u32[16];
  SIMDE_AVX512_ALIGN uint64_t       u64[8];
  SIMDE_AVX512_ALIGN int_fast32_t  i32f[64 / sizeof(int_fast32_t)];
  SIMDE_AVX512_ALIGN uint_fast32_t u32f[64 / sizeof(uint_fast32_t)];
  #if defined(SIMDE_HAVE_INT128_)
  SIMDE_AVX512_ALIGN simde_int128  i128[4];
  SIMDE_AVX512_ALIGN simde_uint128 u128[4];
  #endif
  SIMDE_AVX512_ALIGN simde_float32  f32[16];
  SIMDE_AVX512_ALIGN simde_float64  f64[8];
#endif

  SIMDE_AVX512_ALIGN simde__m128i_private m128i_private[4];
  SIMDE_AVX512_ALIGN simde__m128i         m128i[4];
  SIMDE_AVX512_ALIGN simde__m256i_private m256i_private[2];
  SIMDE_AVX512_ALIGN simde__m256i         m256i[2];

#if defined(SIMDE_X86_AVX512F_NATIVE)
  SIMDE_AVX512_ALIGN __m512i        n;
#elif defined(SIMDE_POWER_ALTIVEC_P5_NATIVE)
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(unsigned char)      altivec_u8[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(unsigned short)     altivec_u16[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(unsigned int)       altivec_u32[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(signed char)        altivec_i8[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(signed short)       altivec_i16[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(signed int)         altivec_i32[4];
  SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(float)              altivec_f32[4];
  #if defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
    SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(unsigned long long) altivec_u64[4];
    SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(signed long long)   altivec_i64[4];
    SIMDE_ALIGN(16) SIMDE_POWER_ALTIVEC_VECTOR(double)             altivec_f64[4];
  #endif
#endif
} simde__m512i_private;

/* Intel uses the same header (immintrin.h) for everything AVX and
 * later.  If native aliases are enabled, and the machine has native
 * support for AVX imintrin.h will already have been included, which
 * means simde__m512* will already have been defined.  So, even
 * if the machine doesn't support AVX512F we need to use the native
 * type; it has already been defined.
 *
 * However, we also can't just assume that including immintrin.h does
 * actually define these.  It could be a compiler which supports AVX
 * but not AVX512F, such as GCC < 4.9 or VS < 2017.  That's why we
 * check to see if _MM_CMPINT_GE is defined; it's part of AVX512F,
 * so we assume that if it's present AVX-512F has already been
 * declared.
 *
 * Note that the choice of _MM_CMPINT_GE is deliberate; while GCC
 * uses the preprocessor to define all the _MM_CMPINT_* members,
 * in most compilers they are simply normal enum members.  However,
 * all compilers I've looked at use an object-like macro for
 * _MM_CMPINT_GE, which is defined to _MM_CMPINT_NLT.  _MM_CMPINT_NLT
 * is included in case a compiler does the reverse, though I haven't
 * run into one which does.
 *
 * As for the ICC check, unlike other compilers, merely using the
 * AVX-512 types causes ICC to generate AVX-512 instructions. */
#if (defined(_MM_CMPINT_GE) || defined(_MM_CMPINT_NLT)) && (defined(SIMDE_X86_AVX512F_NATIVE) || !defined(HEDLEY_INTEL_VERSION))
  typedef __m512 simde__m512;
  typedef __m512i simde__m512i;
  typedef __m512d simde__m512d;
  typedef __mmask8 simde__mmask8;
  typedef __mmask16 simde__mmask16;
  typedef __mmask32 simde__mmask32;
  typedef __mmask64 simde__mmask64;
#else
 #if defined(SIMDE_VECTOR_SUBSCRIPT)
   typedef simde_float32 simde__m512  SIMDE_AVX512_ALIGN SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
   typedef int_fast32_t  simde__m512i SIMDE_AVX512_ALIGN SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
   typedef simde_float64 simde__m512d SIMDE_AVX512_ALIGN SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #else
    typedef simde__m512_private  simde__m512;
    typedef simde__m512i_private simde__m512i;
    typedef simde__m512d_private simde__m512d;
  #endif

  typedef uint8_t simde__mmask8;
  typedef uint16_t simde__mmask16;
  typedef uint32_t simde__mmask32;
  typedef uint64_t simde__mmask64;
#endif

#if !defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
  #if !defined(HEDLEY_INTEL_VERSION)
    typedef simde__m512 __m512;
    typedef simde__m512i __m512i;
    typedef simde__m512d __m512d;
  #else
    #define __m512 simde__m512
    #define __m512i simde__m512i
    #define __m512d simde__m512d
  #endif
#endif

HEDLEY_STATIC_ASSERT(64 == sizeof(simde__m512), "simde__m512 size incorrect");
HEDLEY_STATIC_ASSERT(64 == sizeof(simde__m512_private), "simde__m512_private size incorrect");
HEDLEY_STATIC_ASSERT(64 == sizeof(simde__m512i), "simde__m512i size incorrect");
HEDLEY_STATIC_ASSERT(64 == sizeof(simde__m512i_private), "simde__m512i_private size incorrect");
HEDLEY_STATIC_ASSERT(64 == sizeof(simde__m512d), "simde__m512d size incorrect");
HEDLEY_STATIC_ASSERT(64 == sizeof(simde__m512d_private), "simde__m512d_private size incorrect");
#if defined(SIMDE_CHECK_ALIGNMENT) && defined(SIMDE_ALIGN_OF)
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m512) == 32, "simde__m512 is not 32-byte aligned");
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m512_private) == 32, "simde__m512_private is not 32-byte aligned");
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m512i) == 32, "simde__m512i is not 32-byte aligned");
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m512i_private) == 32, "simde__m512i_private is not 32-byte aligned");
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m512d) == 32, "simde__m512d is not 32-byte aligned");
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m512d_private) == 32, "simde__m512d_private is not 32-byte aligned");
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde__m512_from_private(simde__m512_private v) {
  simde__m512 r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512_private
simde__m512_to_private(simde__m512 v) {
  simde__m512_private r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde__m512i_from_private(simde__m512i_private v) {
  simde__m512i r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i_private
simde__m512i_to_private(simde__m512i v) {
  simde__m512i_private r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde__m512d_from_private(simde__m512d_private v) {
  simde__m512d r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d_private
simde__m512d_to_private(simde__m512d v) {
  simde__m512d_private r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_castpd_ps (simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castpd_ps(a);
  #else
    simde__m512 r;
    simde_memcpy(&r, &a, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castpd_ps
  #define _mm512_castpd_ps(a) simde_mm512_castpd_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_castpd_si512 (simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castpd_si512(a);
  #else
    simde__m512i r;
    simde_memcpy(&r, &a, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castpd_si512
  #define _mm512_castpd_si512(a) simde_mm512_castpd_si512(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_castps_pd (simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castps_pd(a);
  #else
    simde__m512d r;
    simde_memcpy(&r, &a, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castps_pd
  #define _mm512_castps_pd(a) simde_mm512_castps_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_castps_si512 (simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castps_si512(a);
  #else
    simde__m512i r;
    simde_memcpy(&r, &a, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castps_si512
  #define _mm512_castps_si512(a) simde_mm512_castps_si512(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_castsi512_ps (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castsi512_ps(a);
  #else
    simde__m512 r;
    simde_memcpy(&r, &a, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castsi512_ps
  #define _mm512_castsi512_ps(a) simde_mm512_castsi512_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_castsi512_pd (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castsi512_pd(a);
  #else
    simde__m512d r;
    simde_memcpy(&r, &a, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castsi512_pd
  #define _mm512_castsi512_pd(a) simde_mm512_castsi512_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_castpd128_pd512 (simde__m128d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castpd128_pd512(a);
  #else
    simde__m512d_private r_;
    r_.m128d[0] = a;
    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castpd128_pd512
  #define _mm512_castpd128_pd512(a) simde_mm512_castpd128_pd512(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_castpd256_pd512 (simde__m256d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castpd256_pd512(a);
  #else
    simde__m512d_private r_;
    r_.m256d[0] = a;
    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castpd256_pd512
  #define _mm512_castpd256_pd512(a) simde_mm512_castpd256_pd512(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm512_castpd512_pd128 (simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castpd512_pd128(a);
  #else
    simde__m512d_private a_ = simde__m512d_to_private(a);
    return a_.m128d[0];
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castpd512_pd128
  #define _mm512_castpd512_pd128(a) simde_mm512_castpd512_pd128(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm512_castpd512_pd256 (simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castpd512_pd256(a);
  #else
    simde__m512d_private a_ = simde__m512d_to_private(a);
    return a_.m256d[0];
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castpd512_pd256
  #define _mm512_castpd512_pd256(a) simde_mm512_castpd512_pd256(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_castps128_ps512 (simde__m128 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castps128_ps512(a);
  #else
    simde__m512_private r_;
    r_.m128[0] = a;
    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castps128_ps512
  #define _mm512_castps128_ps512(a) simde_mm512_castps128_ps512(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_castps256_ps512 (simde__m256 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castps256_ps512(a);
  #else
    simde__m512_private r_;
    r_.m256[0] = a;
    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castps256_ps512
  #define _mm512_castps256_ps512(a) simde_mm512_castps256_ps512(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm512_castps512_ps128 (simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castps512_ps128(a);
  #else
    simde__m512_private a_ = simde__m512_to_private(a);
    return a_.m128[0];
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castps512_ps128
  #define _mm512_castps512_ps128(a) simde_mm512_castps512_ps128(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm512_castps512_ps256 (simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castps512_ps256(a);
  #else
    simde__m512_private a_ = simde__m512_to_private(a);
    return a_.m256[0];
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castps512_ps256
  #define _mm512_castps512_ps256(a) simde_mm512_castps512_ps256(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_castsi128_si512 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castsi128_si512(a);
  #else
    simde__m512i_private r_;
    r_.m128i[0] = a;
    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castsi128_si512
  #define _mm512_castsi128_si512(a) simde_mm512_castsi128_si512(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_castsi256_si512 (simde__m256i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castsi256_si512(a);
  #else
    simde__m512i_private r_;
    r_.m256i[0] = a;
    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castsi256_si512
  #define _mm512_castsi256_si512(a) simde_mm512_castsi256_si512(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_castsi512_si128 (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castsi512_si128(a);
  #else
    simde__m512i_private a_ = simde__m512i_to_private(a);
    return a_.m128i[0];
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castsi512_si128
  #define _mm512_castsi512_si128(a) simde_mm512_castsi512_si128(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_castsi512_si256 (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_castsi512_si256(a);
  #else
    simde__m512i_private a_ = simde__m512i_to_private(a);
    return a_.m256i[0];
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_castsi512_si256
  #define _mm512_castsi512_si256(a) simde_mm512_castsi512_si256(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_movm_epi8 (simde__mmask16 k) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_movm_epi8(k);
  #elif defined(SIMDE_X86_SSSE3_NATIVE)
    const simde__m128i zero = simde_mm_setzero_si128();
    const simde__m128i bits = simde_mm_set_epi16(0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80);
    const simde__m128i shuffle = simde_mm_set_epi8(15, 13, 11, 9, 7, 5, 3, 1, 14, 12, 10, 8, 6, 4, 2, 0);
    simde__m128i r;

    r = simde_mm_set1_epi16(HEDLEY_STATIC_CAST(short, k));
    r = simde_mm_mullo_epi16(r, bits);
    r = simde_mm_shuffle_epi8(r, shuffle);
    r = simde_mm_cmpgt_epi8(zero, r);

    return r;
  #else
    simde__m128i_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = ((k >> i) & 1) ? ~INT8_C(0) : INT8_C(0);
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_movm_epi8
  #define _mm_movm_epi8(k) simde_mm_movm_epi8(k)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_movm_epi8 (simde__mmask32 k) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_movm_epi8(k);
  #elif defined(SIMDE_X86_AVX2_NATIVE)
    const simde__m256i zero = simde_mm256_setzero_si256();
    const simde__m256i bits = simde_mm256_broadcastsi128_si256(simde_mm_set_epi16(0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80));
    const simde__m256i shuffle = simde_mm256_broadcastsi128_si256(simde_mm_set_epi8(15, 13, 11, 9, 7, 5, 3, 1, 14, 12, 10, 8, 6, 4, 2, 0));
    simde__m256i r;

    r = simde_mm256_set_m128i(simde_mm_set1_epi16(HEDLEY_STATIC_CAST(short, k >> 16)), simde_mm_set1_epi16(HEDLEY_STATIC_CAST(short, k)));
    r = simde_mm256_mullo_epi16(r, bits);
    r = simde_mm256_shuffle_epi8(r, shuffle);
    r = simde_mm256_cmpgt_epi8(zero, r);

    return r;
  #else
    simde__m256i_private r_;

    #if defined(SIMDE_X86_SSSE3_NATIVE)
      r_.m128i[0] = simde_mm_movm_epi8(HEDLEY_STATIC_CAST(simde__mmask16, k));
      r_.m128i[1] = simde_mm_movm_epi8(HEDLEY_STATIC_CAST(simde__mmask16, k >> 16));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = ((k >> i) & 1) ? ~INT8_C(0) : INT8_C(0);
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_movm_epi8
  #define _mm256_movm_epi8(k) simde_mm256_movm_epi8(k)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_movm_epi8 (simde__mmask64 k) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_movm_epi8(k);
  #else
    simde__m512i_private r_;

    #if defined(SIMDE_X86_SSSE3_NATIVE)
      r_.m256i[0] = simde_mm256_movm_epi8(HEDLEY_STATIC_CAST(simde__mmask32, k));
      r_.m256i[1] = simde_mm256_movm_epi8(HEDLEY_STATIC_CAST(simde__mmask32, k >> 32));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = ((k >> i) & 1) ? ~INT8_C(0) : INT8_C(0);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_movm_epi8
  #define _mm512_movm_epi8(k) simde_mm512_movm_epi8(k)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_movm_epi16 (simde__mmask8 k) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_movm_epi16(k);
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    const simde__m128i bits = simde_mm_set_epi16(0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, INT16_MIN /* 0x8000 */);
    simde__m128i r;

    r = simde_mm_set1_epi16(HEDLEY_STATIC_CAST(short, k));
    r = simde_mm_mullo_epi16(r, bits);
    r = simde_mm_srai_epi16(r, 15);

    return r;
  #else
    simde__m128i_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = ((k >> i) & 1) ? ~INT16_C(0) : INT16_C(0);
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_movm_epi16
  #define _mm_movm_epi16(k) simde_mm_movm_epi16(k)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_movm_epi16 (simde__mmask16 k) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_movm_epi16(k);
  #elif defined(SIMDE_X86_AVX2_NATIVE)
    const simde__m256i bits = simde_mm256_set_epi16(0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080,
                                                    0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, INT16_MIN /* 0x8000 */);
    simde__m256i r;

    r = simde_mm256_set1_epi16(HEDLEY_STATIC_CAST(short, k));
    r = simde_mm256_mullo_epi16(r, bits);
    r = simde_mm256_srai_epi16(r, 15);

    return r;
  #else
    simde__m256i_private r_;

    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i[0] = simde_mm_movm_epi16(HEDLEY_STATIC_CAST(simde__mmask8, k));
      r_.m128i[1] = simde_mm_movm_epi16(HEDLEY_STATIC_CAST(simde__mmask8, k >> 8));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = ((k >> i) & 1) ? ~INT16_C(0) : INT16_C(0);
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_movm_epi16
  #define _mm256_movm_epi16(k) simde_mm256_movm_epi16(k)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_movm_epi16 (simde__mmask32 k) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_movm_epi16(k);
  #else
    simde__m512i_private r_;

    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m256i[0] = simde_mm256_movm_epi16(HEDLEY_STATIC_CAST(simde__mmask16, k));
      r_.m256i[1] = simde_mm256_movm_epi16(HEDLEY_STATIC_CAST(simde__mmask16, k >> 16));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = ((k >> i) & 1) ? ~INT16_C(0) : INT16_C(0);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_movm_epi16
  #define _mm512_movm_epi16(k) simde_mm512_movm_epi16(k)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_movm_epi32 (simde__mmask8 k) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_movm_epi32(k);
  #elif defined(SIMDE_X86_AVX2_NATIVE)
    const simde__m128i shifts = simde_mm_set_epi32(28, 29, 30, 31);
    simde__m128i r;

    r = simde_mm_set1_epi32(HEDLEY_STATIC_CAST(int, k));
    r = simde_mm_sllv_epi32(r, shifts);
    r = simde_mm_srai_epi32(r, 31);

    return r;
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    const simde__m128i bits = simde_mm_set_epi32(0x10000000, 0x20000000, 0x40000000, INT32_MIN /* 0x80000000 */);
    simde__m128i r;

    r = simde_mm_set1_epi16(HEDLEY_STATIC_CAST(short, k));
    r = simde_mm_mullo_epi16(r, bits);
    r = simde_mm_srai_epi32(r, 31);

    return r;
  #else
    simde__m128i_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = ((k >> i) & 1) ? ~INT32_C(0) : INT32_C(0);
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_movm_epi32
  #define _mm_movm_epi32(k) simde_mm_movm_epi32(k)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_movm_epi32 (simde__mmask8 k) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_movm_epi32(k);
  #elif defined(SIMDE_X86_AVX2_NATIVE)
    const simde__m256i shifts = simde_mm256_set_epi32(24, 25, 26, 27, 28, 29, 30, 31);
    simde__m256i r;

    r = simde_mm256_set1_epi32(HEDLEY_STATIC_CAST(int, k));
    r = simde_mm256_sllv_epi32(r, shifts);
    r = simde_mm256_srai_epi32(r, 31);

    return r;
  #else
    simde__m256i_private r_;

    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i[0] = simde_mm_movm_epi32(k     );
      r_.m128i[1] = simde_mm_movm_epi32(k >> 4);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = ((k >> i) & 1) ? ~INT32_C(0) : INT32_C(0);
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_movm_epi32
  #define _mm256_movm_epi32(k) simde_mm256_movm_epi32(k)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_movm_epi32 (simde__mmask16 k) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return _mm512_movm_epi32(k);
  #else
    simde__m512i_private r_;

    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m256i[0] = simde_mm256_movm_epi32(HEDLEY_STATIC_CAST(simde__mmask8, k     ));
      r_.m256i[1] = simde_mm256_movm_epi32(HEDLEY_STATIC_CAST(simde__mmask8, k >> 8));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = ((k >> i) & 1) ? ~INT32_C(0) : INT32_C(0);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_movm_epi32
  #define _mm512_movm_epi32(k) simde_mm512_movm_epi32(k)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_movm_epi64 (simde__mmask8 k) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_movm_epi64(k);
    /* N.B. CM: These fallbacks may not be faster as there are only two elements */
  #elif defined(SIMDE_X86_AVX2_NATIVE)
    const simde__m128i shifts = simde_mm_set_epi32(30, 30, 31, 31);
    simde__m128i r;

    r = simde_mm_set1_epi32(HEDLEY_STATIC_CAST(int, k));
    r = simde_mm_sllv_epi32(r, shifts);
    r = simde_mm_srai_epi32(r, 31);

    return r;
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    const simde__m128i bits = simde_mm_set_epi32(0x40000000, 0x40000000, INT32_MIN /* 0x80000000 */, INT32_MIN /* 0x80000000 */);
    simde__m128i r;

    r = simde_mm_set1_epi16(HEDLEY_STATIC_CAST(short, k));
    r = simde_mm_mullo_epi16(r, bits);
    r = simde_mm_srai_epi32(r, 31);

    return r;
  #else
    simde__m128i_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = ((k >> i) & 1) ? ~INT64_C(0) : INT64_C(0);
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_movm_epi64
  #define _mm_movm_epi64(k) simde_mm_movm_epi64(k)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_movm_epi64 (simde__mmask8 k) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_movm_epi64(k);
  #elif defined(SIMDE_X86_AVX2_NATIVE)
    const simde__m256i shifts = simde_mm256_set_epi32(28, 28, 29, 29, 30, 30, 31, 31);
    simde__m256i r;

    r = simde_mm256_set1_epi32(HEDLEY_STATIC_CAST(int, k));
    r = simde_mm256_sllv_epi32(r, shifts);
    r = simde_mm256_srai_epi32(r, 31);

    return r;
  #else
    simde__m256i_private r_;

    /* N.B. CM: This fallback may not be faster as there are only four elements */
    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i[0] = simde_mm_movm_epi64(k     );
      r_.m128i[1] = simde_mm_movm_epi64(k >> 2);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = ((k >> i) & 1) ? ~INT64_C(0) : INT64_C(0);
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_movm_epi64
  #define _mm256_movm_epi64(k) simde_mm256_movm_epi64(k)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_movm_epi64 (simde__mmask8 k) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return _mm512_movm_epi64(k);
  #else
    simde__m512i_private r_;

    /* N.B. CM: Without AVX2 this fallback may not be faster as there are only eight elements */
    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m256i[0] = simde_mm256_movm_epi64(k     );
      r_.m256i[1] = simde_mm256_movm_epi64(k >> 4);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = ((k >> i) & 1) ? ~INT64_C(0) : INT64_C(0);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_movm_epi64
  #define _mm512_movm_epi64(k) simde_mm512_movm_epi64(k)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_mov_epi8 (simde__m128i src, simde__mmask16 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_mov_epi8(src, k, a);
  #elif defined(SIMDE_X86_SSE4_1_NATIVE)
    return simde_mm_blendv_epi8(src, a, simde_mm_movm_epi8(k));
  #elif defined(SIMDE_X86_SSSE3_NATIVE)
    simde__m128i mask = simde_mm_movm_epi8(k);
    return simde_mm_or_si128(simde_mm_and_si128(mask, a), simde_mm_andnot_si128(mask, src));
  #else
    simde__m128i_private
      src_ = simde__m128i_to_private(src),
      a_ = simde__m128i_to_private(a),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = ((k >> i) & 1) ? a_.i8[i] : src_.i8[i];
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_mov_epi8
  #define _mm_mask_mov_epi8(src, k, a) simde_mm_mask_mov_epi8(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_mov_epi16 (simde__m128i src, simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_mov_epi16(src, k, a);
  #elif defined(SIMDE_X86_SSE4_1_NATIVE)
    return simde_mm_blendv_epi8(src, a, simde_mm_movm_epi16(k));
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    simde__m128i mask = simde_mm_movm_epi16(k);
    return simde_mm_or_si128(simde_mm_and_si128(mask, a), simde_mm_andnot_si128(mask, src));
  #else
    simde__m128i_private
      src_ = simde__m128i_to_private(src),
      a_ = simde__m128i_to_private(a),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = ((k >> i) & 1) ? a_.i16[i] : src_.i16[i];
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_mov_epi16
  #define _mm_mask_mov_epi16(src, k, a) simde_mm_mask_mov_epi16(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_mov_epi32 (simde__m128i src, simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_mov_epi32(src, k, a);
  #elif defined(SIMDE_X86_SSE4_1_NATIVE)
    return simde_mm_blendv_epi8(src, a, simde_mm_movm_epi32(k));
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    simde__m128i mask = simde_mm_movm_epi32(k);
    return simde_mm_or_si128(simde_mm_and_si128(mask, a), simde_mm_andnot_si128(mask, src));
  #else
    simde__m128i_private
      src_ = simde__m128i_to_private(src),
      a_ = simde__m128i_to_private(a),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = ((k >> i) & 1) ? a_.i32[i] : src_.i32[i];
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_mov_epi32
  #define _mm_mask_mov_epi32(src, k, a) simde_mm_mask_mov_epi32(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_mov_epi64 (simde__m128i src, simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_mov_epi64(src, k, a);
  #else
    simde__m128i_private
      src_ = simde__m128i_to_private(src),
      a_ = simde__m128i_to_private(a),
      r_;

    /* N.B. CM: No fallbacks as there are only two elements */
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = ((k >> i) & 1) ? a_.i64[i] : src_.i64[i];
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_mov_epi64
  #define _mm_mask_mov_epi64(src, k, a) simde_mm_mask_mov_epi64(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_mask_mov_pd(simde__m128d src, simde__mmask8 k, simde__m128d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_mov_pd(src, k, a);
  #else
    return simde_mm_castsi128_pd(simde_mm_mask_mov_epi64(simde_mm_castpd_si128(src), k, simde_mm_castpd_si128(a)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_mov_pd
  #define _mm_mask_mov_pd(src, k, a) simde_mm_mask_mov_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_mask_mov_ps (simde__m128 src, simde__mmask8 k, simde__m128 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_mov_ps(src, k, a);
  #else
    return simde_mm_castsi128_ps(simde_mm_mask_mov_epi32(simde_mm_castps_si128(src), k, simde_mm_castps_si128(a)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_mov_ps
  #define _mm_mask_mov_ps(src, k, a) simde_mm_mask_mov_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_mov_epi8 (simde__m256i src, simde__mmask32 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_mov_epi8(src, k, a);
  #elif defined(SIMDE_X86_AVX2_NATIVE)
    return simde_mm256_blendv_epi8(src, a, simde_mm256_movm_epi8(k));
  #else
    simde__m256i_private
      r_,
      src_ = simde__m256i_to_private(src),
      a_ = simde__m256i_to_private(a);

    #if defined(SIMDE_X86_SSSE3_NATIVE)
      r_.m128i[0] = simde_mm_mask_mov_epi8(src_.m128i[0], HEDLEY_STATIC_CAST(simde__mmask16, k      ), a_.m128i[0]);
      r_.m128i[1] = simde_mm_mask_mov_epi8(src_.m128i[1], HEDLEY_STATIC_CAST(simde__mmask16, k >> 16), a_.m128i[1]);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = ((k >> i) & 1) ? a_.i8[i] : src_.i8[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_mov_epi8
  #define _mm256_mask_mov_epi8(src, k, a) simde_mm256_mask_mov_epi8(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_mov_epi16 (simde__m256i src, simde__mmask16 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_mov_epi16(src, k, a);
  #elif defined(SIMDE_X86_AVX2_NATIVE)
    return simde_mm256_blendv_epi8(src, a, simde_mm256_movm_epi16(k));
  #else
    simde__m256i_private
      src_ = simde__m256i_to_private(src),
      a_ = simde__m256i_to_private(a),
      r_;

    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i[0] = simde_mm_mask_mov_epi16(src_.m128i[0], HEDLEY_STATIC_CAST(simde__mmask8, k     ), a_.m128i[0]);
      r_.m128i[1] = simde_mm_mask_mov_epi16(src_.m128i[1], HEDLEY_STATIC_CAST(simde__mmask8, k >> 8), a_.m128i[1]);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = ((k >> i) & 1) ? a_.i16[i] : src_.i16[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_mov_epi16
  #define _mm256_mask_mov_epi16(src, k, a) simde_mm256_mask_mov_epi16(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_mov_epi32 (simde__m256i src, simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_mov_epi32(src, k, a);
  #elif defined(SIMDE_X86_AVX2_NATIVE)
    return simde_mm256_blendv_epi8(src, a, simde_mm256_movm_epi32(k));
  #else
    simde__m256i_private
      src_ = simde__m256i_to_private(src),
      a_ = simde__m256i_to_private(a),
      r_;

    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i[0] = simde_mm_mask_mov_epi32(src_.m128i[0], k     , a_.m128i[0]);
      r_.m128i[1] = simde_mm_mask_mov_epi32(src_.m128i[1], k >> 4, a_.m128i[1]);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = ((k >> i) & 1) ? a_.i32[i] : src_.i32[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_mov_epi32
  #define _mm256_mask_mov_epi32(src, k, a) simde_mm256_mask_mov_epi32(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_mov_epi64 (simde__m256i src, simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_mov_epi64(src, k, a);
  #elif defined(SIMDE_X86_AVX2_NATIVE)
    return simde_mm256_blendv_epi8(src, a, simde_mm256_movm_epi64(k));
  #else
    simde__m256i_private
      src_ = simde__m256i_to_private(src),
      a_ = simde__m256i_to_private(a),
      r_;

    /* N.B. CM: This fallback may not be faster as there are only four elements */
    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i[0] = simde_mm_mask_mov_epi64(src_.m128i[0], k     , a_.m128i[0]);
      r_.m128i[1] = simde_mm_mask_mov_epi64(src_.m128i[1], k >> 2, a_.m128i[1]);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = ((k >> i) & 1) ? a_.i64[i] : src_.i64[i];
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_mov_epi64
  #define _mm256_mask_mov_epi64(src, k, a) simde_mm256_mask_mov_epi64(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_mask_mov_pd (simde__m256d src, simde__mmask8 k, simde__m256d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_mov_pd(src, k, a);
  #else
    return simde_mm256_castsi256_pd(simde_mm256_mask_mov_epi64(simde_mm256_castpd_si256(src), k, simde_mm256_castpd_si256(a)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_mov_pd
  #define _mm256_mask_mov_pd(src, k, a) simde_mm256_mask_mov_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_mask_mov_ps (simde__m256 src, simde__mmask8 k, simde__m256 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_mov_ps(src, k, a);
  #else
    return simde_mm256_castsi256_ps(simde_mm256_mask_mov_epi32(simde_mm256_castps_si256(src), k, simde_mm256_castps_si256(a)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_mov_ps
  #define _mm256_mask_mov_ps(src, k, a) simde_mm256_mask_mov_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_mov_epi8 (simde__m512i src, simde__mmask64 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_mov_epi8(src, k, a);
  #else
    simde__m512i_private
      src_ = simde__m512i_to_private(src),
      a_ = simde__m512i_to_private(a),
      r_;

    #if defined(SIMDE_X86_SSSE3_NATIVE)
      r_.m256i[0] = simde_mm256_mask_mov_epi8(src_.m256i[0], HEDLEY_STATIC_CAST(simde__mmask32, k      ), a_.m256i[0]);
      r_.m256i[1] = simde_mm256_mask_mov_epi8(src_.m256i[1], HEDLEY_STATIC_CAST(simde__mmask32, k >> 32), a_.m256i[1]);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = ((k >> i) & 1) ? a_.i8[i] : src_.i8[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_mov_epi8
  #define _mm512_mask_mov_epi8(src, k, a) simde_mm512_mask_mov_epi8(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_mov_epi16 (simde__m512i src, simde__mmask32 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_mov_epi16(src, k, a);
  #else
    simde__m512i_private
      src_ = simde__m512i_to_private(src),
      a_ = simde__m512i_to_private(a),
      r_;

    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m256i[0] = simde_mm256_mask_mov_epi16(src_.m256i[0], HEDLEY_STATIC_CAST(simde__mmask16, k      ), a_.m256i[0]);
      r_.m256i[1] = simde_mm256_mask_mov_epi16(src_.m256i[1], HEDLEY_STATIC_CAST(simde__mmask16, k >> 16), a_.m256i[1]);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = ((k >> i) & 1) ? a_.i16[i] : src_.i16[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_mov_epi16
  #define _mm512_mask_mov_epi16(src, k, a) simde_mm512_mask_mov_epi16(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_mov_epi32 (simde__m512i src, simde__mmask16 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_mov_epi32(src, k, a);
  #else
    simde__m512i_private
      src_ = simde__m512i_to_private(src),
      a_ = simde__m512i_to_private(a),
      r_;

    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m256i[0] = simde_mm256_mask_mov_epi32(src_.m256i[0], HEDLEY_STATIC_CAST(simde__mmask8, k     ), a_.m256i[0]);
      r_.m256i[1] = simde_mm256_mask_mov_epi32(src_.m256i[1], HEDLEY_STATIC_CAST(simde__mmask8, k >> 8), a_.m256i[1]);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = ((k >> i) & 1) ? a_.i32[i] : src_.i32[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_mov_epi32
  #define _mm512_mask_mov_epi32(src, k, a) simde_mm512_mask_mov_epi32(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_mov_epi64 (simde__m512i src, simde__mmask8 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_mov_epi64(src, k, a);
  #else
    simde__m512i_private
      src_ = simde__m512i_to_private(src),
      a_ = simde__m512i_to_private(a),
      r_;

    /* N.B. CM: Without AVX2 this fallback may not be faster as there are only eight elements */
    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m256i[0] = simde_mm256_mask_mov_epi64(src_.m256i[0], k     , a_.m256i[0]);
      r_.m256i[1] = simde_mm256_mask_mov_epi64(src_.m256i[1], k >> 4, a_.m256i[1]);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = ((k >> i) & 1) ? a_.i64[i] : src_.i64[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_mov_epi64
  #define _mm512_mask_mov_epi64(src, k, a) simde_mm512_mask_mov_epi64(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_mov_pd (simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_mov_pd(src, k, a);
  #else
    return simde_mm512_castsi512_pd(simde_mm512_mask_mov_epi64(simde_mm512_castpd_si512(src), k, simde_mm512_castpd_si512(a)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_mov_pd
  #define _mm512_mask_mov_pd(src, k, a) simde_mm512_mask_mov_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_mov_ps (simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_mov_ps(src, k, a);
  #else
    return simde_mm512_castsi512_ps(simde_mm512_mask_mov_epi32(simde_mm512_castps_si512(src), k, simde_mm512_castps_si512(a)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_mov_ps
  #define _mm512_mask_mov_ps(src, k, a) simde_mm512_mask_mov_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_mov_epi8 (simde__mmask16 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_mov_epi8(k, a);
  #elif defined(SIMDE_X86_SSSE3_NATIVE)
    return simde_mm_and_si128(a, simde_mm_movm_epi8(k));
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = ((k >> i) & 1) ? a_.i8[i] : INT8_C(0);
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_mov_epi8
  #define _mm_maskz_mov_epi8(k, a) simde_mm_maskz_mov_epi8(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_mov_epi16 (simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_mov_epi16(k, a);
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    return simde_mm_and_si128(a, simde_mm_movm_epi16(k));
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = ((k >> i) & 1) ? a_.i16[i] : INT16_C(0);
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_mov_epi16
  #define _mm_maskz_mov_epi16(k, a) simde_mm_maskz_mov_epi16(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_mov_epi32 (simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_mov_epi32(k, a);
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    return simde_mm_and_si128(a, simde_mm_movm_epi32(k));
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = ((k >> i) & 1) ? a_.i32[i] : INT32_C(0);
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_mov_epi32
  #define _mm_maskz_mov_epi32(k, a) simde_mm_maskz_mov_epi32(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_mov_epi64 (simde__mmask8 k, simde__m128i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_mov_epi64(k, a);
  #else
    simde__m128i_private
      a_ = simde__m128i_to_private(a),
      r_;

    /* N.B. CM: No fallbacks as there are only two elements */
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = ((k >> i) & 1) ? a_.i64[i] : INT64_C(0);
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_mov_epi64
  #define _mm_maskz_mov_epi64(k, a) simde_mm_maskz_mov_epi64(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128d
simde_mm_maskz_mov_pd (simde__mmask8 k, simde__m128d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_mov_pd(k, a);
  #else
    return simde_mm_castsi128_pd(simde_mm_maskz_mov_epi64(k, simde_mm_castpd_si128(a)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_mov_pd
  #define _mm_maskz_mov_pd(k, a) simde_mm_maskz_mov_pd(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm_maskz_mov_ps (simde__mmask8 k, simde__m128 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_mov_ps(k, a);
  #else
    return simde_mm_castsi128_ps(simde_mm_maskz_mov_epi32(k, simde_mm_castps_si128(a)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_mov_ps
  #define _mm_maskz_mov_ps(k, a) simde_mm_maskz_mov_ps(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_mov_epi8 (simde__mmask32 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_mov_epi8(k, a);
  #elif defined(SIMDE_X86_AVX2_NATIVE)
    return simde_mm256_and_si256(a, simde_mm256_movm_epi8(k));
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      r_;

    #if defined(SIMDE_X86_SSSE3_NATIVE)
      r_.m128i[0] = simde_mm_maskz_mov_epi8(HEDLEY_STATIC_CAST(simde__mmask16, k      ), a_.m128i[0]);
      r_.m128i[1] = simde_mm_maskz_mov_epi8(HEDLEY_STATIC_CAST(simde__mmask16, k >> 16), a_.m128i[1]);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = ((k >> i) & 1) ? a_.i8[i] : INT8_C(0);
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_mov_epi8
  #define _mm256_maskz_mov_epi8(k, a) simde_mm256_maskz_mov_epi8(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_mov_epi16 (simde__mmask16 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_mov_epi16(k, a);
  #elif defined(SIMDE_X86_AVX2_NATIVE)
    return simde_mm256_and_si256(a, simde_mm256_movm_epi16(k));
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      r_;

    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i[0] = simde_mm_maskz_mov_epi16(HEDLEY_STATIC_CAST(simde__mmask8, k     ), a_.m128i[0]);
      r_.m128i[1] = simde_mm_maskz_mov_epi16(HEDLEY_STATIC_CAST(simde__mmask8, k >> 8), a_.m128i[1]);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = ((k >> i) & 1) ? a_.i16[i] : INT16_C(0);
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_mov_epi16
  #define _mm256_maskz_mov_epi16(k, a) simde_mm256_maskz_mov_epi16(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_mov_epi32 (simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_mov_epi32(k, a);
  #elif defined(SIMDE_X86_AVX2_NATIVE)
    return simde_mm256_and_si256(a, simde_mm256_movm_epi32(k));
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      r_;

    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i[0] = simde_mm_maskz_mov_epi32(k     , a_.m128i[0]);
      r_.m128i[1] = simde_mm_maskz_mov_epi32(k >> 4, a_.m128i[1]);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = ((k >> i) & 1) ? a_.i32[i] : INT32_C(0);
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_mov_epi32
  #define _mm256_maskz_mov_epi32(k, a) simde_mm256_maskz_mov_epi32(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_mov_epi64 (simde__mmask8 k, simde__m256i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_mov_epi64(k, a);
  #else
    simde__m256i_private
      a_ = simde__m256i_to_private(a),
      r_;

    /* N.B. CM: This fallback may not be faster as there are only four elements */
    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i[0] = simde_mm_maskz_mov_epi64(k     , a_.m128i[0]);
      r_.m128i[1] = simde_mm_maskz_mov_epi64(k >> 2, a_.m128i[1]);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = ((k >> i) & 1) ? a_.i64[i] : INT64_C(0);
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_mov_epi64
  #define _mm256_maskz_mov_epi64(k, a) simde_mm256_maskz_mov_epi64(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_maskz_mov_pd (simde__mmask8 k, simde__m256d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_mov_pd(k, a);
  #else
    return simde_mm256_castsi256_pd(simde_mm256_maskz_mov_epi64(k, simde_mm256_castpd_si256(a)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_mov_pd
  #define _mm256_maskz_mov_pd(k, a) simde_mm256_maskz_mov_pd(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_maskz_mov_ps (simde__mmask8 k, simde__m256 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_mov_ps(k, a);
  #else
    return simde_mm256_castsi256_ps(simde_mm256_maskz_mov_epi32(k, simde_mm256_castps_si256(a)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_mov_ps
  #define _mm256_maskz_mov_ps(k, a) simde_mm256_maskz_mov_ps(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_mov_epi8 (simde__mmask64 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_mov_epi8(k, a);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      r_;

    #if defined(SIMDE_X86_SSSE3_NATIVE)
      r_.m256i[0] = simde_mm256_maskz_mov_epi8(HEDLEY_STATIC_CAST(simde__mmask32, k      ), a_.m256i[0]);
      r_.m256i[1] = simde_mm256_maskz_mov_epi8(HEDLEY_STATIC_CAST(simde__mmask32, k >> 32), a_.m256i[1]);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
        r_.i8[i] = ((k >> i) & 1) ? a_.i8[i] : INT8_C(0);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_mov_epi8
  #define _mm512_maskz_mov_epi8(k, a) simde_mm512_maskz_mov_epi8(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_mov_epi16 (simde__mmask32 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_mov_epi16(k, a);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      r_;

    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m256i[0] = simde_mm256_maskz_mov_epi16(HEDLEY_STATIC_CAST(simde__mmask16, k      ), a_.m256i[0]);
      r_.m256i[1] = simde_mm256_maskz_mov_epi16(HEDLEY_STATIC_CAST(simde__mmask16, k >> 16), a_.m256i[1]);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
        r_.i16[i] = ((k >> i) & 1) ? a_.i16[i] : INT16_C(0);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_mov_epi16
  #define _mm512_maskz_mov_epi16(k, a) simde_mm512_maskz_mov_epi16(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_mov_epi32 (simde__mmask16 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_mov_epi32(k, a);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      r_;

    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m256i[0] = simde_mm256_maskz_mov_epi32(HEDLEY_STATIC_CAST(simde__mmask8, k     ), a_.m256i[0]);
      r_.m256i[1] = simde_mm256_maskz_mov_epi32(HEDLEY_STATIC_CAST(simde__mmask8, k >> 8), a_.m256i[1]);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = ((k >> i) & 1) ? a_.i32[i] : INT32_C(0);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_mov_epi32
  #define _mm512_maskz_mov_epi32(k, a) simde_mm512_maskz_mov_epi32(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_mov_epi64 (simde__mmask8 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_mov_epi64(k, a);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      r_;

    /* N.B. CM: Without AVX2 this fallback may not be faster as there are only eight elements */
    #if defined(SIMDE_X86_SSE2_NATIVE)
      r_.m256i[0] = simde_mm256_maskz_mov_epi64(k     , a_.m256i[0]);
      r_.m256i[1] = simde_mm256_maskz_mov_epi64(k >> 4, a_.m256i[1]);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = ((k >> i) & 1) ? a_.i64[i] : INT64_C(0);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_mov_epi64
  #define _mm512_maskz_mov_epi64(k, a) simde_mm512_maskz_mov_epi64(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_mov_pd (simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_mov_pd(k, a);
  #else
    return simde_mm512_castsi512_pd(simde_mm512_maskz_mov_epi64(k, simde_mm512_castpd_si512(a)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_mov_pd
  #define _mm512_maskz_mov_pd(k, a) simde_mm512_maskz_mov_pd(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_mov_ps (simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_mov_ps(k, a);
  #else
    return simde_mm512_castsi512_ps(simde_mm512_maskz_mov_epi32(k, simde_mm512_castps_si512(a)));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_mov_ps
  #define _mm512_maskz_mov_ps(k, a) simde_mm512_maskz_mov_ps(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask64
simde_mm512_movepi8_mask (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_movepi8_mask(a);
  #else
    simde__m512i_private a_ = simde__m512i_to_private(a);
    simde__mmask64 r;

    #if defined(SIMDE_X86_AVX2_NATIVE)
      r =             HEDLEY_STATIC_CAST(simde__mmask64, HEDLEY_STATIC_CAST(unsigned int, simde_mm256_movemask_epi8(a_.m256i[1])));
      r = (r << 32) | HEDLEY_STATIC_CAST(simde__mmask64, HEDLEY_STATIC_CAST(unsigned int, simde_mm256_movemask_epi8(a_.m256i[0])));
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      r =             HEDLEY_STATIC_CAST(simde__mmask64, HEDLEY_STATIC_CAST(unsigned int, simde_mm_movemask_epi8(a_.m128i[3])));
      r = (r << 16) | HEDLEY_STATIC_CAST(simde__mmask64, HEDLEY_STATIC_CAST(unsigned int, simde_mm_movemask_epi8(a_.m128i[2])));
      r = (r << 16) | HEDLEY_STATIC_CAST(simde__mmask64, HEDLEY_STATIC_CAST(unsigned int, simde_mm_movemask_epi8(a_.m128i[1])));
      r = (r << 16) | HEDLEY_STATIC_CAST(simde__mmask64, HEDLEY_STATIC_CAST(unsigned int, simde_mm_movemask_epi8(a_.m128i[0])));
    #else
      r = 0;

      SIMDE_VECTORIZE_REDUCTION(|:r)
      for (size_t i = 0 ; i < (sizeof(a_.i8) / sizeof(a_.i8[0])) ; i++) {
        r |= (a_.i8[i] < 0) ? (UINT64_C(1) << i) : 0;
      }
    #endif

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_movepi8_mask
  #define _mm512_movepi8_mask(a) simde_mm512_movepi8_mask(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask32
simde_mm512_movepi16_mask (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_movepi16_mask(a);
  #else
    simde__m512i_private a_ = simde__m512i_to_private(a);
    simde__mmask32 r = 0;

    SIMDE_VECTORIZE_REDUCTION(|:r)
    for (size_t i = 0 ; i < (sizeof(a_.i16) / sizeof(a_.i16[0])) ; i++) {
      r |= (a_.i16[i] < 0) ? (UINT32_C(1) << i) : 0;
    }

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_movepi16_mask
  #define _mm512_movepi16_mask(a) simde_mm512_movepi16_mask(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_movepi32_mask (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return _mm512_movepi32_mask(a);
  #else
    simde__m512i_private a_ = simde__m512i_to_private(a);
    simde__mmask16 r = 0;

    SIMDE_VECTORIZE_REDUCTION(|:r)
    for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
      r |= (a_.i32[i] < 0) ? (UINT32_C(1) << i) : 0;
    }

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_movepi32_mask
  #define _mm512_movepi32_mask(a) simde_mm512_movepi32_mask(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_movepi64_mask (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512DQ_NATIVE)
    return _mm512_movepi64_mask(a);
  #else
    simde__m512i_private a_ = simde__m512i_to_private(a);
    simde__mmask8 r = 0;

    SIMDE_VECTORIZE_REDUCTION(|:r)
    for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
      r |= (a_.i64[i] < 0) ? (UINT32_C(1) << i) : 0;
    }

    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512DQ_ENABLE_NATIVE_ALIASES)
  #undef _mm512_movepi64_mask
  #define _mm512_movepi64_mask(a) simde_mm512_movepi64_mask(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_loadu_ps (void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_loadu_ps(mem_addr);
  #else
    simde__m512 r;
    simde_memcpy(&r, mem_addr, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_loadu_ps
  #define _mm512_loadu_ps(a) simde_mm512_loadu_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_loadu_pd (void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_loadu_pd(mem_addr);
  #else
    simde__m512d r;
    simde_memcpy(&r, mem_addr, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_loadu_pd
  #define _mm512_loadu_pd(a) simde_mm512_loadu_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_load_si512 (void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_load_si512(HEDLEY_REINTERPRET_CAST(void const*, mem_addr));
  #else
    simde__m512i r;
    simde_memcpy(&r, SIMDE_ASSUME_ALIGNED_AS(simde__m512i, mem_addr), sizeof(r));
    return r;
  #endif
}
#define simde_mm512_load_epi8(mem_addr) simde_mm512_load_si512(mem_addr)
#define simde_mm512_load_epi16(mem_addr) simde_mm512_load_si512(mem_addr)
#define simde_mm512_load_epi32(mem_addr) simde_mm512_load_si512(mem_addr)
#define simde_mm512_load_epi64(mem_addr) simde_mm512_load_si512(mem_addr)
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_load_epi8
  #undef _mm512_load_epi16
  #undef _mm512_load_epi32
  #undef _mm512_load_epi64
  #undef _mm512_load_si512
  #define _mm512_load_si512(a) simde_mm512_load_si512(a)
  #define _mm512_load_epi8(a) simde_mm512_load_si512(a)
  #define _mm512_load_epi16(a) simde_mm512_load_si512(a)
  #define _mm512_load_epi32(a) simde_mm512_load_si512(a)
  #define _mm512_load_epi64(a) simde_mm512_load_si512(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_loadu_si512 (void const * mem_addr) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_loadu_si512(HEDLEY_REINTERPRET_CAST(void const*, mem_addr));
  #else
    simde__m512i r;

    #if HEDLEY_GNUC_HAS_ATTRIBUTE(may_alias,3,3,0)
      HEDLEY_DIAGNOSTIC_PUSH
      SIMDE_DIAGNOSTIC_DISABLE_PACKED_
      struct simde_mm512_loadu_si512_s {
        __typeof__(r) v;
      } __attribute__((__packed__, __may_alias__));
      r = HEDLEY_REINTERPRET_CAST(const struct simde_mm512_loadu_si512_s *, mem_addr)->v;
      HEDLEY_DIAGNOSTIC_POP
    #else
      simde_memcpy(&r, mem_addr, sizeof(r));
    #endif

    return r;
  #endif
}
#define simde_mm512_loadu_epi8(mem_addr) simde_mm512_loadu_si512(mem_addr)
#define simde_mm512_loadu_epi16(mem_addr) simde_mm512_loadu_si512(mem_addr)
#define simde_mm512_loadu_epi32(mem_addr) simde_mm512_loadu_si512(mem_addr)
#define simde_mm512_loadu_epi64(mem_addr) simde_mm512_loadu_si512(mem_addr)
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_loadu_epi8
  #undef _mm512_loadu_epi16
  #undef _mm512_loadu_epi32
  #undef _mm512_loadu_epi64
  #undef _mm512_loadu_si512
  #define _mm512_loadu_si512(a) simde_mm512_loadu_si512(a)
  #define _mm512_loadu_epi8(a) simde_mm512_loadu_si512(a)
  #define _mm512_loadu_epi16(a) simde_mm512_loadu_si512(a)
  #define _mm512_loadu_epi32(a) simde_mm512_loadu_si512(a)
  #define _mm512_loadu_epi64(a) simde_mm512_loadu_si512(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm512_store_ps (void * mem_addr, simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    _mm512_store_ps(mem_addr, a);
  #else
    simde_memcpy(SIMDE_ASSUME_ALIGNED_AS(simde__m512, mem_addr), &a, sizeof(a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_store_ps
  #define _mm512_store_ps(mem_addr, a) simde_mm512_store_ps(mem_addr, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm512_storeu_ps (void * mem_addr, simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    _mm512_storeu_ps(mem_addr, a);
  #else
    simde_memcpy(mem_addr, &a, sizeof(a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_storeu_ps
  #define _mm512_storeu_ps(mem_addr, a) simde_mm512_storeu_ps(mem_addr, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm512_store_pd (void * mem_addr, simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    _mm512_store_pd(mem_addr, a);
  #else
    simde_memcpy(SIMDE_ASSUME_ALIGNED_AS(simde__m512d, mem_addr), &a, sizeof(a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_store_pd
  #define _mm512_store_pd(mem_addr, a) simde_mm512_store_pd(mem_addr, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm512_storeu_pd (void * mem_addr, simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    _mm512_storeu_pd(mem_addr, a);
  #else
    simde_memcpy(mem_addr, &a, sizeof(a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_storeu_pd
  #define _mm512_storeu_pd(mem_addr, a) simde_mm512_storeu_pd(mem_addr, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm512_store_si512 (void * mem_addr, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    _mm512_store_si512(HEDLEY_REINTERPRET_CAST(void*, mem_addr), a);
  #else
    simde_memcpy(SIMDE_ASSUME_ALIGNED_AS(simde__m512i, mem_addr), &a, sizeof(a));
  #endif
}
#define simde_mm512_store_epi8(mem_addr, a) simde_mm512_store_si512(mem_addr, a)
#define simde_mm512_store_epi16(mem_addr, a) simde_mm512_store_si512(mem_addr, a)
#define simde_mm512_store_epi32(mem_addr, a) simde_mm512_store_si512(mem_addr, a)
#define simde_mm512_store_epi64(mem_addr, a) simde_mm512_store_si512(mem_addr, a)
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_store_epi8
  #undef _mm512_store_epi16
  #undef _mm512_store_epi32
  #undef _mm512_store_epi64
  #undef _mm512_store_si512
  #define _mm512_store_si512(mem_addr, a) simde_mm512_store_si512(mem_addr, a)
  #define _mm512_store_epi8(mem_addr, a) simde_mm512_store_si512(mem_addr, a)
  #define _mm512_store_epi16(mem_addr, a) simde_mm512_store_si512(mem_addr, a)
  #define _mm512_store_epi32(mem_addr, a) simde_mm512_store_si512(mem_addr, a)
  #define _mm512_store_epi64(mem_addr, a) simde_mm512_store_si512(mem_addr, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm512_storeu_si512 (void * mem_addr, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    _mm512_storeu_si512(HEDLEY_REINTERPRET_CAST(void*, mem_addr), a);
  #else
    simde_memcpy(mem_addr, &a, sizeof(a));
  #endif
}
#define simde_mm512_storeu_epi8(mem_addr, a) simde_mm512_storeu_si512(mem_addr, a)
#define simde_mm512_storeu_epi16(mem_addr, a) simde_mm512_storeu_si512(mem_addr, a)
#define simde_mm512_storeu_epi32(mem_addr, a) simde_mm512_storeu_si512(mem_addr, a)
#define simde_mm512_storeu_epi64(mem_addr, a) simde_mm512_storeu_si512(mem_addr, a)
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_storeu_epi8
  #undef _mm512_storeu_epi16
  #undef _mm512_storeu_epi32
  #undef _mm512_storeu_epi64
  #undef _mm512_storeu_si512
  #define _mm512_storeu_si512(mem_addr, a) simde_mm512_storeu_si512(mem_addr, a)
  #define _mm512_storeu_epi8(mem_addr, a) simde_mm512_storeu_si512(mem_addr, a)
  #define _mm512_storeu_epi16(mem_addr, a) simde_mm512_storeu_si512(mem_addr, a)
  #define _mm512_storeu_epi32(mem_addr, a) simde_mm512_storeu_si512(mem_addr, a)
  #define _mm512_storeu_epi64(mem_addr, a) simde_mm512_storeu_si512(mem_addr, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_set_epi8 (int8_t e63, int8_t e62, int8_t e61, int8_t e60, int8_t e59, int8_t e58, int8_t e57, int8_t e56,
                      int8_t e55, int8_t e54, int8_t e53, int8_t e52, int8_t e51, int8_t e50, int8_t e49, int8_t e48,
                      int8_t e47, int8_t e46, int8_t e45, int8_t e44, int8_t e43, int8_t e42, int8_t e41, int8_t e40,
                      int8_t e39, int8_t e38, int8_t e37, int8_t e36, int8_t e35, int8_t e34, int8_t e33, int8_t e32,
                      int8_t e31, int8_t e30, int8_t e29, int8_t e28, int8_t e27, int8_t e26, int8_t e25, int8_t e24,
                      int8_t e23, int8_t e22, int8_t e21, int8_t e20, int8_t e19, int8_t e18, int8_t e17, int8_t e16,
                      int8_t e15, int8_t e14, int8_t e13, int8_t e12, int8_t e11, int8_t e10, int8_t  e9, int8_t  e8,
                      int8_t  e7, int8_t  e6, int8_t  e5, int8_t  e4, int8_t  e3, int8_t  e2, int8_t  e1, int8_t  e0) {
  simde__m512i_private r_;

  r_.i8[ 0] = e0;
  r_.i8[ 1] = e1;
  r_.i8[ 2] = e2;
  r_.i8[ 3] = e3;
  r_.i8[ 4] = e4;
  r_.i8[ 5] = e5;
  r_.i8[ 6] = e6;
  r_.i8[ 7] = e7;
  r_.i8[ 8] = e8;
  r_.i8[ 9] = e9;
  r_.i8[10] = e10;
  r_.i8[11] = e11;
  r_.i8[12] = e12;
  r_.i8[13] = e13;
  r_.i8[14] = e14;
  r_.i8[15] = e15;
  r_.i8[16] = e16;
  r_.i8[17] = e17;
  r_.i8[18] = e18;
  r_.i8[19] = e19;
  r_.i8[20] = e20;
  r_.i8[21] = e21;
  r_.i8[22] = e22;
  r_.i8[23] = e23;
  r_.i8[24] = e24;
  r_.i8[25] = e25;
  r_.i8[26] = e26;
  r_.i8[27] = e27;
  r_.i8[28] = e28;
  r_.i8[29] = e29;
  r_.i8[30] = e30;
  r_.i8[31] = e31;
  r_.i8[32] = e32;
  r_.i8[33] = e33;
  r_.i8[34] = e34;
  r_.i8[35] = e35;
  r_.i8[36] = e36;
  r_.i8[37] = e37;
  r_.i8[38] = e38;
  r_.i8[39] = e39;
  r_.i8[40] = e40;
  r_.i8[41] = e41;
  r_.i8[42] = e42;
  r_.i8[43] = e43;
  r_.i8[44] = e44;
  r_.i8[45] = e45;
  r_.i8[46] = e46;
  r_.i8[47] = e47;
  r_.i8[48] = e48;
  r_.i8[49] = e49;
  r_.i8[50] = e50;
  r_.i8[51] = e51;
  r_.i8[52] = e52;
  r_.i8[53] = e53;
  r_.i8[54] = e54;
  r_.i8[55] = e55;
  r_.i8[56] = e56;
  r_.i8[57] = e57;
  r_.i8[58] = e58;
  r_.i8[59] = e59;
  r_.i8[60] = e60;
  r_.i8[61] = e61;
  r_.i8[62] = e62;
  r_.i8[63] = e63;

  return simde__m512i_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_set_epi8
  #define _mm512_set_epi8(e63, e62, e61, e60, e59, e58, e57, e56, e55, e54, e53, e52, e51, e50, e49, e48, e47, e46, e45, e44, e43, e42, e41, e40, e39, e38, e37, e36, e35, e34, e33, e32, e31, e30, e29, e28, e27, e26, e25, e24, e23, e22, e21, e20, e19, e18, e17, e16, e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_epi8(e63, e62, e61, e60, e59, e58, e57, e56, e55, e54, e53, e52, e51, e50, e49, e48, e47, e46, e45, e44, e43, e42, e41, e40, e39, e38, e37, e36, e35, e34, e33, e32, e31, e30, e29, e28, e27, e26, e25, e24, e23, e22, e21, e20, e19, e18, e17, e16, e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_set_epi16 (int16_t e31, int16_t e30, int16_t e29, int16_t e28, int16_t e27, int16_t e26, int16_t e25, int16_t e24,
                       int16_t e23, int16_t e22, int16_t e21, int16_t e20, int16_t e19, int16_t e18, int16_t e17, int16_t e16,
                       int16_t e15, int16_t e14, int16_t e13, int16_t e12, int16_t e11, int16_t e10, int16_t  e9, int16_t  e8,
                       int16_t  e7, int16_t  e6, int16_t  e5, int16_t  e4, int16_t  e3, int16_t  e2, int16_t  e1, int16_t  e0) {
  simde__m512i_private r_;

  r_.i16[ 0] = e0;
  r_.i16[ 1] = e1;
  r_.i16[ 2] = e2;
  r_.i16[ 3] = e3;
  r_.i16[ 4] = e4;
  r_.i16[ 5] = e5;
  r_.i16[ 6] = e6;
  r_.i16[ 7] = e7;
  r_.i16[ 8] = e8;
  r_.i16[ 9] = e9;
  r_.i16[10] = e10;
  r_.i16[11] = e11;
  r_.i16[12] = e12;
  r_.i16[13] = e13;
  r_.i16[14] = e14;
  r_.i16[15] = e15;
  r_.i16[16] = e16;
  r_.i16[17] = e17;
  r_.i16[18] = e18;
  r_.i16[19] = e19;
  r_.i16[20] = e20;
  r_.i16[21] = e21;
  r_.i16[22] = e22;
  r_.i16[23] = e23;
  r_.i16[24] = e24;
  r_.i16[25] = e25;
  r_.i16[26] = e26;
  r_.i16[27] = e27;
  r_.i16[28] = e28;
  r_.i16[29] = e29;
  r_.i16[30] = e30;
  r_.i16[31] = e31;

  return simde__m512i_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_set_epi16
  #define _mm512_set_epi16(e31, e30, e29, e28, e27, e26, e25, e24, e23, e22, e21, e20, e19, e18, e17, e16, e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_epi16(e31, e30, e29, e28, e27, e26, e25, e24, e23, e22, e21, e20, e19, e18, e17, e16, e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_set_epi32 (int32_t e15, int32_t e14, int32_t e13, int32_t e12, int32_t e11, int32_t e10, int32_t  e9, int32_t  e8,
                       int32_t  e7, int32_t  e6, int32_t  e5, int32_t  e4, int32_t  e3, int32_t  e2, int32_t  e1, int32_t  e0) {
  simde__m512i_private r_;

  r_.i32[ 0] = e0;
  r_.i32[ 1] = e1;
  r_.i32[ 2] = e2;
  r_.i32[ 3] = e3;
  r_.i32[ 4] = e4;
  r_.i32[ 5] = e5;
  r_.i32[ 6] = e6;
  r_.i32[ 7] = e7;
  r_.i32[ 8] = e8;
  r_.i32[ 9] = e9;
  r_.i32[10] = e10;
  r_.i32[11] = e11;
  r_.i32[12] = e12;
  r_.i32[13] = e13;
  r_.i32[14] = e14;
  r_.i32[15] = e15;

  return simde__m512i_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_set_epi32
  #define _mm512_set_epi32(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_epi32(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_set_epi64 (int64_t e7, int64_t e6, int64_t e5, int64_t e4, int64_t e3, int64_t e2, int64_t e1, int64_t e0) {
  simde__m512i_private r_;

  r_.i64[0] = e0;
  r_.i64[1] = e1;
  r_.i64[2] = e2;
  r_.i64[3] = e3;
  r_.i64[4] = e4;
  r_.i64[5] = e5;
  r_.i64[6] = e6;
  r_.i64[7] = e7;

  return simde__m512i_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_set_epi64
  #define _mm512_set_epi64(e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_epi64(e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_set_epu8 (uint8_t e63, uint8_t e62, uint8_t e61, uint8_t e60, uint8_t e59, uint8_t e58, uint8_t e57, uint8_t e56,
                        uint8_t e55, uint8_t e54, uint8_t e53, uint8_t e52, uint8_t e51, uint8_t e50, uint8_t e49, uint8_t e48,
                        uint8_t e47, uint8_t e46, uint8_t e45, uint8_t e44, uint8_t e43, uint8_t e42, uint8_t e41, uint8_t e40,
                        uint8_t e39, uint8_t e38, uint8_t e37, uint8_t e36, uint8_t e35, uint8_t e34, uint8_t e33, uint8_t e32,
                        uint8_t e31, uint8_t e30, uint8_t e29, uint8_t e28, uint8_t e27, uint8_t e26, uint8_t e25, uint8_t e24,
                        uint8_t e23, uint8_t e22, uint8_t e21, uint8_t e20, uint8_t e19, uint8_t e18, uint8_t e17, uint8_t e16,
                        uint8_t e15, uint8_t e14, uint8_t e13, uint8_t e12, uint8_t e11, uint8_t e10, uint8_t  e9, uint8_t  e8,
                        uint8_t  e7, uint8_t  e6, uint8_t  e5, uint8_t  e4, uint8_t  e3, uint8_t  e2, uint8_t  e1, uint8_t  e0) {
  simde__m512i_private r_;

  r_.u8[ 0] = e0;
  r_.u8[ 1] = e1;
  r_.u8[ 2] = e2;
  r_.u8[ 3] = e3;
  r_.u8[ 4] = e4;
  r_.u8[ 5] = e5;
  r_.u8[ 6] = e6;
  r_.u8[ 7] = e7;
  r_.u8[ 8] = e8;
  r_.u8[ 9] = e9;
  r_.u8[10] = e10;
  r_.u8[11] = e11;
  r_.u8[12] = e12;
  r_.u8[13] = e13;
  r_.u8[14] = e14;
  r_.u8[15] = e15;
  r_.u8[16] = e16;
  r_.u8[17] = e17;
  r_.u8[18] = e18;
  r_.u8[19] = e19;
  r_.u8[20] = e20;
  r_.u8[21] = e21;
  r_.u8[22] = e22;
  r_.u8[23] = e23;
  r_.u8[24] = e24;
  r_.u8[25] = e25;
  r_.u8[26] = e26;
  r_.u8[27] = e27;
  r_.u8[28] = e28;
  r_.u8[29] = e29;
  r_.u8[30] = e30;
  r_.u8[31] = e31;
  r_.u8[32] = e32;
  r_.u8[33] = e33;
  r_.u8[34] = e34;
  r_.u8[35] = e35;
  r_.u8[36] = e36;
  r_.u8[37] = e37;
  r_.u8[38] = e38;
  r_.u8[39] = e39;
  r_.u8[40] = e40;
  r_.u8[41] = e41;
  r_.u8[42] = e42;
  r_.u8[43] = e43;
  r_.u8[44] = e44;
  r_.u8[45] = e45;
  r_.u8[46] = e46;
  r_.u8[47] = e47;
  r_.u8[48] = e48;
  r_.u8[49] = e49;
  r_.u8[50] = e50;
  r_.u8[51] = e51;
  r_.u8[52] = e52;
  r_.u8[53] = e53;
  r_.u8[54] = e54;
  r_.u8[55] = e55;
  r_.u8[56] = e56;
  r_.u8[57] = e57;
  r_.u8[58] = e58;
  r_.u8[59] = e59;
  r_.u8[60] = e60;
  r_.u8[61] = e61;
  r_.u8[62] = e62;
  r_.u8[63] = e63;

  return simde__m512i_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_set_epu16 (uint16_t e31, uint16_t e30, uint16_t e29, uint16_t e28, uint16_t e27, uint16_t e26, uint16_t e25, uint16_t e24,
                       uint16_t e23, uint16_t e22, uint16_t e21, uint16_t e20, uint16_t e19, uint16_t e18, uint16_t e17, uint16_t e16,
                       uint16_t e15, uint16_t e14, uint16_t e13, uint16_t e12, uint16_t e11, uint16_t e10, uint16_t  e9, uint16_t  e8,
                       uint16_t  e7, uint16_t  e6, uint16_t  e5, uint16_t  e4, uint16_t  e3, uint16_t  e2, uint16_t  e1, uint16_t  e0) {
  simde__m512i_private r_;

  r_.u16[ 0] = e0;
  r_.u16[ 1] = e1;
  r_.u16[ 2] = e2;
  r_.u16[ 3] = e3;
  r_.u16[ 4] = e4;
  r_.u16[ 5] = e5;
  r_.u16[ 6] = e6;
  r_.u16[ 7] = e7;
  r_.u16[ 8] = e8;
  r_.u16[ 9] = e9;
  r_.u16[10] = e10;
  r_.u16[11] = e11;
  r_.u16[12] = e12;
  r_.u16[13] = e13;
  r_.u16[14] = e14;
  r_.u16[15] = e15;
  r_.u16[16] = e16;
  r_.u16[17] = e17;
  r_.u16[18] = e18;
  r_.u16[19] = e19;
  r_.u16[20] = e20;
  r_.u16[21] = e21;
  r_.u16[22] = e22;
  r_.u16[23] = e23;
  r_.u16[24] = e24;
  r_.u16[25] = e25;
  r_.u16[26] = e26;
  r_.u16[27] = e27;
  r_.u16[28] = e28;
  r_.u16[29] = e29;
  r_.u16[30] = e30;
  r_.u16[31] = e31;

  return simde__m512i_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_set_epu32 (uint32_t e15, uint32_t e14, uint32_t e13, uint32_t e12, uint32_t e11, uint32_t e10, uint32_t  e9, uint32_t  e8,
                         uint32_t  e7, uint32_t  e6, uint32_t  e5, uint32_t  e4, uint32_t  e3, uint32_t  e2, uint32_t  e1, uint32_t  e0) {
  simde__m512i_private r_;

  r_.u32[ 0] = e0;
  r_.u32[ 1] = e1;
  r_.u32[ 2] = e2;
  r_.u32[ 3] = e3;
  r_.u32[ 4] = e4;
  r_.u32[ 5] = e5;
  r_.u32[ 6] = e6;
  r_.u32[ 7] = e7;
  r_.u32[ 8] = e8;
  r_.u32[ 9] = e9;
  r_.u32[10] = e10;
  r_.u32[11] = e11;
  r_.u32[12] = e12;
  r_.u32[13] = e13;
  r_.u32[14] = e14;
  r_.u32[15] = e15;

  return simde__m512i_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_set_epu64 (uint64_t  e7, uint64_t  e6, uint64_t  e5, uint64_t  e4, uint64_t  e3, uint64_t  e2, uint64_t  e1, uint64_t  e0) {
  simde__m512i_private r_;

  r_.u64[ 0] = e0;
  r_.u64[ 1] = e1;
  r_.u64[ 2] = e2;
  r_.u64[ 3] = e3;
  r_.u64[ 4] = e4;
  r_.u64[ 5] = e5;
  r_.u64[ 6] = e6;
  r_.u64[ 7] = e7;

  return simde__m512i_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_set_m128i (simde__m128i a, simde__m128i b, simde__m128i c, simde__m128i d) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    SIMDE_ALIGN(64) simde__m128i v[] = { d, c, b, a };
    return simde_mm512_load_si512(HEDLEY_STATIC_CAST(__m512i *, HEDLEY_STATIC_CAST(void *, v)));
  #else
    simde__m512i_private r_;

    r_.m128i[0] = d;
    r_.m128i[1] = c;
    r_.m128i[2] = b;
    r_.m128i[3] = a;

    return simde__m512i_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_set_m256i (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    SIMDE_ALIGN(64) simde__m256i v[] = { b, a };
    return simde_mm512_load_si512(HEDLEY_STATIC_CAST(__m512i *, HEDLEY_STATIC_CAST(void *, v)));
  #else
    simde__m512i_private r_;

    r_.m256i[0] = b;
    r_.m256i[1] = a;

    return simde__m512i_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_set_ps (simde_float32 e15, simde_float32 e14, simde_float32 e13, simde_float32 e12,
                    simde_float32 e11, simde_float32 e10, simde_float32  e9, simde_float32  e8,
                    simde_float32  e7, simde_float32  e6, simde_float32  e5, simde_float32  e4,
                    simde_float32  e3, simde_float32  e2, simde_float32  e1, simde_float32  e0) {
  simde__m512_private r_;

  r_.f32[ 0] = e0;
  r_.f32[ 1] = e1;
  r_.f32[ 2] = e2;
  r_.f32[ 3] = e3;
  r_.f32[ 4] = e4;
  r_.f32[ 5] = e5;
  r_.f32[ 6] = e6;
  r_.f32[ 7] = e7;
  r_.f32[ 8] = e8;
  r_.f32[ 9] = e9;
  r_.f32[10] = e10;
  r_.f32[11] = e11;
  r_.f32[12] = e12;
  r_.f32[13] = e13;
  r_.f32[14] = e14;
  r_.f32[15] = e15;

  return simde__m512_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_set_ps
  #define _mm512_set_ps(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_ps(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_set_pd (simde_float64 e7, simde_float64 e6, simde_float64 e5, simde_float64 e4, simde_float64 e3, simde_float64 e2, simde_float64 e1, simde_float64 e0) {
  simde__m512d_private r_;

  r_.f64[0] = e0;
  r_.f64[1] = e1;
  r_.f64[2] = e2;
  r_.f64[3] = e3;
  r_.f64[4] = e4;
  r_.f64[5] = e5;
  r_.f64[6] = e6;
  r_.f64[7] = e7;

  return simde__m512d_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_set_pd
  #define _mm512_set_pd(e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_pd(e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_set1_epi8 (int8_t a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_set1_epi8(a);
  #else
    simde__m512i_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = a;
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_set1_epi8
  #define _mm512_set1_epi8(a) simde_mm512_set1_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_set1_epi16 (int16_t a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_set1_epi16(a);
  #else
    simde__m512i_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = a;
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_set1_epi16
  #define _mm512_set1_epi16(a) simde_mm512_set1_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_set1_epi32 (int32_t a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_set1_epi32(a);
  #else
    simde__m512i_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a;
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_set1_epi32
  #define _mm512_set1_epi32(a) simde_mm512_set1_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_set1_epi32(simde__m512i src, simde__mmask16 k, int32_t a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_set1_epi32(src, k, a);
#else
  return simde_mm512_mask_mov_epi32(src, k, simde_mm512_set1_epi32(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_set1_epi32(src, k, a) simde_mm512_mask_set1_epi32(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_set1_epi32(simde__mmask16 k, int32_t a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_set1_epi32(k, a);
#else
  return simde_mm512_maskz_mov_epi32(k, simde_mm512_set1_epi32(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_set1_epi32(k, a) simde_mm512_maskz_set1_epi32(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_set1_epi64 (int64_t a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_set1_epi64(a);
  #else
    simde__m512i_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a;
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_set1_epi64
  #define _mm512_set1_epi64(a) simde_mm512_set1_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_set1_epi64(simde__m512i src, simde__mmask8 k, int64_t a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_set1_epi64(src, k, a);
#else
  return simde_mm512_mask_mov_epi64(src, k, simde_mm512_set1_epi64(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_set1_epi64(src, k, a) simde_mm512_mask_set1_epi64(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_set1_epi64(simde__mmask8 k, int64_t a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_set1_epi64(k, a);
#else
  return simde_mm512_maskz_mov_epi64(k, simde_mm512_set1_epi64(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_set1_epi64(k, a) simde_mm512_maskz_set1_epi64(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_set1_epu8 (uint8_t a) {
  simde__m512i_private r_;

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    r_.u8[i] = a;
  }

  return simde__m512i_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_set1_epu16 (uint16_t a) {
  simde__m512i_private r_;

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    r_.u16[i] = a;
  }

  return simde__m512i_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_set1_epu32 (uint32_t a) {
  simde__m512i_private r_;

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
    r_.u32[i] = a;
  }

  return simde__m512i_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_set1_epu64 (uint64_t a) {
  simde__m512i_private r_;

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
    r_.u64[i] = a;
  }

  return simde__m512i_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_set1_ps (simde_float32 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_set1_ps(a);
  #else
    simde__m512_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = a;
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_set1_ps
  #define _mm512_set1_ps(a) simde_mm512_set1_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_set1_pd (simde_float64 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_set1_pd(a);
  #else
    simde__m512d_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = a;
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_set1_pd
  #define _mm512_set1_pd(a) simde_mm512_set1_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_set4_epi32 (int32_t d, int32_t c, int32_t b, int32_t a) {
  simde__m512i_private r_;

  r_.i32[ 0] = a;
  r_.i32[ 1] = b;
  r_.i32[ 2] = c;
  r_.i32[ 3] = d;
  r_.i32[ 4] = a;
  r_.i32[ 5] = b;
  r_.i32[ 6] = c;
  r_.i32[ 7] = d;
  r_.i32[ 8] = a;
  r_.i32[ 9] = b;
  r_.i32[10] = c;
  r_.i32[11] = d;
  r_.i32[12] = a;
  r_.i32[13] = b;
  r_.i32[14] = c;
  r_.i32[15] = d;

  return simde__m512i_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_set4_epi32
  #define _mm512_set4_epi32(d,c,b,a) simde_mm512_set4_epi32(d,c,b,a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_set4_epi64 (int64_t d, int64_t c, int64_t b, int64_t a) {
  simde__m512i_private r_;

  r_.i64[0] = a;
  r_.i64[1] = b;
  r_.i64[2] = c;
  r_.i64[3] = d;
  r_.i64[4] = a;
  r_.i64[5] = b;
  r_.i64[6] = c;
  r_.i64[7] = d;

  return simde__m512i_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_set4_epi64
  #define _mm512_set4_epi64(d,c,b,a) simde_mm512_set4_epi64(d,c,b,a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_set4_ps (simde_float32 d, simde_float32 c, simde_float32 b, simde_float32 a) {
  simde__m512_private r_;

  r_.f32[ 0] = a;
  r_.f32[ 1] = b;
  r_.f32[ 2] = c;
  r_.f32[ 3] = d;
  r_.f32[ 4] = a;
  r_.f32[ 5] = b;
  r_.f32[ 6] = c;
  r_.f32[ 7] = d;
  r_.f32[ 8] = a;
  r_.f32[ 9] = b;
  r_.f32[10] = c;
  r_.f32[11] = d;
  r_.f32[12] = a;
  r_.f32[13] = b;
  r_.f32[14] = c;
  r_.f32[15] = d;

  return simde__m512_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_set4_ps
  #define _mm512_set4_ps(d,c,b,a) simde_mm512_set4_ps(d,c,b,a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_set4_pd (simde_float64 d, simde_float64 c, simde_float64 b, simde_float64 a) {
  simde__m512d_private r_;

  r_.f64[0] = a;
  r_.f64[1] = b;
  r_.f64[2] = c;
  r_.f64[3] = d;
  r_.f64[4] = a;
  r_.f64[5] = b;
  r_.f64[6] = c;
  r_.f64[7] = d;

  return simde__m512d_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_set4_pd
  #define _mm512_set4_pd(d,c,b,a) simde_mm512_set4_pd(d,c,b,a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_setr_epi32 (int32_t e15, int32_t e14, int32_t e13, int32_t e12, int32_t e11, int32_t e10, int32_t  e9, int32_t  e8,
                       int32_t  e7, int32_t  e6, int32_t  e5, int32_t  e4, int32_t  e3, int32_t  e2, int32_t  e1, int32_t  e0) {
  simde__m512i_private r_;

  r_.i32[ 0] = e15;
  r_.i32[ 1] = e14;
  r_.i32[ 2] = e13;
  r_.i32[ 3] = e12;
  r_.i32[ 4] = e11;
  r_.i32[ 5] = e10;
  r_.i32[ 6] = e9;
  r_.i32[ 7] = e8;
  r_.i32[ 8] = e7;
  r_.i32[ 9] = e6;
  r_.i32[10] = e5;
  r_.i32[11] = e4;
  r_.i32[12] = e3;
  r_.i32[13] = e2;
  r_.i32[14] = e1;
  r_.i32[15] = e0;

  return simde__m512i_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_setr_epi32
  #define _mm512_setr_epi32(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_setr_epi32(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_setr_epi64 (int64_t e7, int64_t e6, int64_t e5, int64_t e4, int64_t e3, int64_t e2, int64_t e1, int64_t e0) {
  simde__m512i_private r_;

  r_.i64[0] = e7;
  r_.i64[1] = e6;
  r_.i64[2] = e5;
  r_.i64[3] = e4;
  r_.i64[4] = e3;
  r_.i64[5] = e2;
  r_.i64[6] = e1;
  r_.i64[7] = e0;

  return simde__m512i_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_setr_epi64
  #define _mm512_setr_epi64(e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_setr_epi64(e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_setr_ps (simde_float32 e15, simde_float32 e14, simde_float32 e13, simde_float32 e12,
                    simde_float32 e11, simde_float32 e10, simde_float32  e9, simde_float32  e8,
                    simde_float32  e7, simde_float32  e6, simde_float32  e5, simde_float32  e4,
                    simde_float32  e3, simde_float32  e2, simde_float32  e1, simde_float32  e0) {
  simde__m512_private r_;

  r_.f32[ 0] = e15;
  r_.f32[ 1] = e14;
  r_.f32[ 2] = e13;
  r_.f32[ 3] = e12;
  r_.f32[ 4] = e11;
  r_.f32[ 5] = e10;
  r_.f32[ 6] = e9;
  r_.f32[ 7] = e8;
  r_.f32[ 8] = e7;
  r_.f32[ 9] = e6;
  r_.f32[10] = e5;
  r_.f32[11] = e4;
  r_.f32[12] = e3;
  r_.f32[13] = e2;
  r_.f32[14] = e1;
  r_.f32[15] = e0;

  return simde__m512_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_setr_ps
  #define _mm512_setr_ps(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_setr_ps(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_setr_pd (simde_float64 e7, simde_float64 e6, simde_float64 e5, simde_float64 e4, simde_float64 e3, simde_float64 e2, simde_float64 e1, simde_float64 e0) {
  simde__m512d_private r_;

  r_.f64[0] = e7;
  r_.f64[1] = e6;
  r_.f64[2] = e5;
  r_.f64[3] = e4;
  r_.f64[4] = e3;
  r_.f64[5] = e2;
  r_.f64[6] = e1;
  r_.f64[7] = e0;

  return simde__m512d_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_setr_pd
  #define _mm512_setr_pd(e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_setr_pd(e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_setr4_epi32 (int32_t d, int32_t c, int32_t b, int32_t a) {
  simde__m512i_private r_;

  r_.i32[ 0] = d;
  r_.i32[ 1] = c;
  r_.i32[ 2] = b;
  r_.i32[ 3] = a;
  r_.i32[ 4] = d;
  r_.i32[ 5] = c;
  r_.i32[ 6] = b;
  r_.i32[ 7] = a;
  r_.i32[ 8] = d;
  r_.i32[ 9] = c;
  r_.i32[10] = b;
  r_.i32[11] = a;
  r_.i32[12] = d;
  r_.i32[13] = c;
  r_.i32[14] = b;
  r_.i32[15] = a;

  return simde__m512i_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_setr4_epi32
  #define _mm512_setr4_epi32(d,c,b,a) simde_mm512_setr4_epi32(d,c,b,a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_setr4_epi64 (int64_t d, int64_t c, int64_t b, int64_t a) {
  simde__m512i_private r_;

  r_.i64[0] = d;
  r_.i64[1] = c;
  r_.i64[2] = b;
  r_.i64[3] = a;
  r_.i64[4] = d;
  r_.i64[5] = c;
  r_.i64[6] = b;
  r_.i64[7] = a;

  return simde__m512i_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_setr4_epi64
  #define _mm512_setr4_epi64(d,c,b,a) simde_mm512_setr4_epi64(d,c,b,a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_setr4_ps (simde_float32 d, simde_float32 c, simde_float32 b, simde_float32 a) {
  simde__m512_private r_;

  r_.f32[ 0] = d;
  r_.f32[ 1] = c;
  r_.f32[ 2] = b;
  r_.f32[ 3] = a;
  r_.f32[ 4] = d;
  r_.f32[ 5] = c;
  r_.f32[ 6] = b;
  r_.f32[ 7] = a;
  r_.f32[ 8] = d;
  r_.f32[ 9] = c;
  r_.f32[10] = b;
  r_.f32[11] = a;
  r_.f32[12] = d;
  r_.f32[13] = c;
  r_.f32[14] = b;
  r_.f32[15] = a;

  return simde__m512_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_setr4_ps
  #define _mm512_setr4_ps(d,c,b,a) simde_mm512_setr4_ps(d,c,b,a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_setr4_pd (simde_float64 d, simde_float64 c, simde_float64 b, simde_float64 a) {
  simde__m512d_private r_;

  r_.f64[0] = d;
  r_.f64[1] = c;
  r_.f64[2] = b;
  r_.f64[3] = a;
  r_.f64[4] = d;
  r_.f64[5] = c;
  r_.f64[6] = b;
  r_.f64[7] = a;

  return simde__m512d_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_setr4_pd
  #define _mm512_setr4_pd(d,c,b,a) simde_mm512_setr4_pd(d,c,b,a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_setzero_si512(void) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_setzero_si512();
  #else
    simde__m512i r;
    simde_memset(&r, 0, sizeof(r));
    return r;
  #endif
}
#define simde_mm512_setzero_epi32() simde_mm512_setzero_si512()
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_setzero_si512
  #define _mm512_setzero_si512() simde_mm512_setzero_si512()
  #undef _mm512_setzero_epi32
  #define _mm512_setzero_epi32() simde_mm512_setzero_si512()
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_setone_si512(void) {
  simde__m512i_private r_;

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
    r_.i32f[i] = ~HEDLEY_STATIC_CAST(int_fast32_t, 0);
  }

  return simde__m512i_from_private(r_);
}
#define simde_x_mm512_setone_epi32() simde_x_mm512_setone_si512()

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_setzero_ps(void) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_setzero_ps();
  #else
    return simde_mm512_castsi512_ps(simde_mm512_setzero_si512());
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_setzero_si512
  #define _mm512_setzero_si512() simde_mm512_setzero_si512()
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_x_mm512_setone_ps(void) {
  return simde_mm512_castsi512_ps(simde_x_mm512_setone_si512());
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_setzero_pd(void) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_setzero_pd();
  #else
    return simde_mm512_castsi512_pd(simde_mm512_setzero_si512());
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_setzero_si512
  #define _mm512_setzero_si512() simde_mm512_setzero_si512()
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_x_mm512_setone_pd(void) {
  return simde_mm512_castsi512_pd(simde_x_mm512_setone_si512());
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_abs_epi32(simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_abs_epi32(a);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    r_.i32[i] = (a_.i32[i] < INT64_C(0)) ? -a_.i32[i] : a_.i32[i];
  }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_abs_epi32
  #define _mm512_abs_epi32(a) simde_mm512_abs_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_abs_epi32(simde__m512i src, simde__mmask16 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_abs_epi32(src, k, a);
#else
  return simde_mm512_mask_mov_epi32(src, k, simde_mm512_abs_epi32(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_abs_epi32(src, k, a) simde_mm512_mask_abs_epi32(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_abs_epi32(simde__mmask16 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_abs_epi32(k, a);
#else
  return simde_mm512_maskz_mov_epi32(k, simde_mm512_abs_epi32(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_abs_epi32(k, a) simde_mm512_maskz_abs_epi32(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_abs_epi64(simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_abs_epi64(a);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i64) / sizeof(r_.i64[0])); i++) {
    r_.i64[i] = (a_.i64[i] < INT64_C(0)) ? -a_.i64[i] : a_.i64[i];
  }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_abs_epi64
  #define _mm512_abs_epi64(a) simde_mm512_abs_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_abs_epi64(simde__m512i src, simde__mmask8 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_abs_epi64(src, k, a);
#else
  return simde_mm512_mask_mov_epi64(src, k, simde_mm512_abs_epi64(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_abs_epi64(src, k, a) simde_mm512_mask_abs_epi64(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_abs_epi64(simde__mmask8 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_abs_epi64(k, a);
#else
  return simde_mm512_maskz_mov_epi64(k, simde_mm512_abs_epi64(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_abs_epi64(k, a) simde_mm512_maskz_abs_epi64(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_abs_ps(simde__m512 v2) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_abs_ps(v2);
#else
  simde__m512_private
    r_,
    v2_ = simde__m512_to_private(v2);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.f32) / sizeof(r_.f32[0])); i++) {
    r_.f32[i] = (v2_.f32[i] < INT64_C(0)) ? -v2_.f32[i] : v2_.f32[i];
  }

  return simde__m512_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_abs_ps
  #define _mm512_abs_ps(v2) simde_mm512_abs_ps(v2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_abs_ps(simde__m512 src, simde__mmask16 k, simde__m512 v2) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_abs_ps(src, k, v2);
#else
  return simde_mm512_mask_mov_ps(src, k, simde_mm512_abs_ps(v2));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_abs_ps(src, k, v2) simde_mm512_mask_abs_ps(src, k, v2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_abs_pd(simde__m512d v2) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_abs_pd(v2);
#else
  simde__m512d_private
    r_,
    v2_ = simde__m512d_to_private(v2);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.f64) / sizeof(r_.f64[0])); i++) {
    r_.f64[i] = (v2_.f64[i] < INT64_C(0)) ? -v2_.f64[i] : v2_.f64[i];
  }

  return simde__m512d_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_abs_pd
  #define _mm512_abs_pd(v2) simde_mm512_abs_pd(v2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_abs_pd(simde__m512d src, simde__mmask8 k, simde__m512d v2) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_abs_pd(src, k, v2);
#else
  return simde_mm512_mask_mov_pd(src, k, simde_mm512_abs_pd(v2));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_abs_pd(src, k, v2) simde_mm512_mask_abs_pd(src, k, v2)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_add_epi32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_add_epi32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = a_.i32 + b_.i32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_add_epi32(a_.m256i[i], b_.m256i[i]);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_add_epi32
  #define _mm512_add_epi32(a, b) simde_mm512_add_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_add_epi32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_add_epi32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_add_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_add_epi32
  #define _mm512_mask_add_epi32(src, k, a, b) simde_mm512_mask_add_epi32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_add_epi32(simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_add_epi32(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi32(k, simde_mm512_add_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_add_epi32
  #define _mm512_maskz_add_epi32(k, a, b) simde_mm512_maskz_add_epi32(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_add_epi64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_add_epi64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 + b_.i64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_add_epi64(a_.m256i[i], b_.m256i[i]);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_add_epi64
  #define _mm512_add_epi64(a, b) simde_mm512_add_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_add_epi64(simde__m512i src, simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_add_epi64(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_add_epi64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_add_epi64
  #define _mm512_mask_add_epi64(src, k, a, b) simde_mm512_mask_add_epi64(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_add_epi64(simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_add_epi64(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_add_epi64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_add_epi64
  #define _mm512_maskz_add_epi64(k, a, b) simde_mm512_maskz_add_epi64(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_add_ps (simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_add_ps(a, b);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f32 = a_.f32 + b_.f32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256) / sizeof(r_.m256[0])) ; i++) {
        r_.m256[i] = simde_mm256_add_ps(a_.m256[i], b_.m256[i]);
      }
    #endif

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_add_ps
  #define _mm512_add_ps(a, b) simde_mm512_add_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_add_ps(simde__m512 src, simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_add_ps(src, k, a, b);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_add_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_add_ps
  #define _mm512_mask_add_ps(src, k, a, b) simde_mm512_mask_add_ps(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_add_ps(simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_add_ps(k, a, b);
  #else
    return simde_mm512_maskz_mov_ps(k, simde_mm512_add_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_add_ps
  #define _mm512_maskz_add_ps(k, a, b) simde_mm512_maskz_add_ps(k, a, b)
#endif


SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_add_pd (simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_add_pd(a, b);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f64 = a_.f64 + b_.f64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256d) / sizeof(r_.m256d[0])) ; i++) {
        r_.m256d[i] = simde_mm256_add_pd(a_.m256d[i], b_.m256d[i]);
      }
    #endif

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_add_pd
  #define _mm512_add_pd(a, b) simde_mm512_add_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_add_pd(simde__m512d src, simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_add_pd(src, k, a, b);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_add_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_add_pd
  #define _mm512_mask_add_pd(src, k, a, b) simde_mm512_mask_add_pd(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_add_pd(simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_add_pd(k, a, b);
  #else
    return simde_mm512_maskz_mov_pd(k, simde_mm512_add_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_add_pd
  #define _mm512_maskz_add_pd(k, a, b) simde_mm512_maskz_add_pd(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_and_epi32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_and_epi32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = a_.i32 & b_.i32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i32[i] & b_.i32[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_and_epi32
  #define _mm512_and_epi32(a, b) simde_mm512_and_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_and_epi32(simde__m512i src, simde__mmask16 k, simde__m512i v2, simde__m512i v3) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_and_epi32(src, k, v2, v3);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_and_epi32(v2, v3));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_and_epi32
  #define _mm512_mask_and_epi32(src, k, v2, v3) simde_mm512_mask_and_epi32(src, k, v2, v3)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_and_epi32(simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_and_epi32(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi32(k, simde_mm512_and_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_and_epi32
  #define _mm512_maskz_and_epi32(k, a, b) simde_mm512_maskz_and_epi32(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_and_epi64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_and_epi64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 & b_.i64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a_.i64[i] & b_.i64[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_and_epi64
  #define _mm512_and_epi64(a, b) simde_mm512_and_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_and_epi64(simde__m512i src, simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_and_epi64(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_and_epi64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_and_epi64
  #define _mm512_mask_and_epi64(src, k, a, b) simde_mm512_mask_and_epi64(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_and_epi64(simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_and_epi64(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_and_epi64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_and_epi64
  #define _mm512_maskz_and_epi64(k, a, b) simde_mm512_maskz_and_epi64(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_and_si512 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_and_si512(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_X86_AVX2_NATIVE)
      r_.m256i[0] = simde_mm256_and_si256(a_.m256i[0], b_.m256i[0]);
      r_.m256i[1] = simde_mm256_and_si256(a_.m256i[1], b_.m256i[1]);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = a_.i32f & b_.i32f;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i32[i] & b_.i32[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_and_si512
  #define _mm512_and_si512(a, b) simde_mm512_and_si512(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_andnot_si512 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_andnot_si512(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_X86_AVX2_NATIVE)
      r_.m256i[0] = simde_mm256_andnot_si256(a_.m256i[0], b_.m256i[0]);
      r_.m256i[1] = simde_mm256_andnot_si256(a_.m256i[1], b_.m256i[1]);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
        r_.i32f[i] = ~(a_.i32f[i]) & b_.i32f[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#define simde_mm512_andnot_epi32(a, b) simde_mm512_andnot_si512(a, b)
#define simde_mm512_andnot_epi64(a, b) simde_mm512_andnot_si512(a, b)
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_andnot_si512
  #define _mm512_andnot_si512(a, b) simde_mm512_andnot_si512(a, b)
  #undef _mm512_andnot_epi32
  #define _mm512_andnot_epi32(a, b) simde_mm512_andnot_si512(a, b)
  #undef _mm512_andnot_epi64
  #define _mm512_andnot_epi64(a, b) simde_mm512_andnot_si512(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_andnot_epi32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_andnot_epi32(src, k, a, b);
#else
  return simde_mm512_mask_mov_epi32(src, k, simde_mm512_andnot_epi32(a, b));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_andnot_epi32(src, k, a, b) simde_mm512_mask_andnot_epi32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_andnot_epi32(simde__mmask16 k, simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_andnot_epi32(k, a, b);
#else
  return simde_mm512_maskz_mov_epi32(k, simde_mm512_andnot_epi32(a, b));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_andnot_epi32(k, a, b) simde_mm512_maskz_andnot_epi32(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_andnot_epi64(simde__m512i src, simde__mmask8 k, simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_andnot_epi64(src, k, a, b);
#else
  return simde_mm512_mask_mov_epi64(src, k, simde_mm512_andnot_epi64(a, b));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_andnot_epi64(src, k, a, b) simde_mm512_mask_andnot_epi64(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_andnot_epi64(simde__mmask8 k, simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_andnot_epi64(k, a, b);
#else
  return simde_mm512_maskz_mov_epi64(k, simde_mm512_andnot_epi64(a, b));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_andnot_epi64(k, a, b) simde_mm512_maskz_andnot_epi64(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_blend_epi32(simde__mmask16 k, simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_blend_epi32(k, a, b);
#else
  return simde_mm512_mask_mov_epi32(a, k, b);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_blend_epi32(k, a, b) simde_mm512_mask_blend_epi32(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_blend_epi64(simde__mmask8 k, simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_blend_epi64(k, a, b);
#else
  return simde_mm512_mask_mov_epi64(a, k, b);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_blend_epi64(k, a, b) simde_mm512_mask_blend_epi64(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_blend_ps(simde__mmask16 k, simde__m512 a, simde__m512 b) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_blend_ps(k, a, b);
#else
  return simde_mm512_mask_mov_ps(a, k, b);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_blend_ps(k, a, b) simde_mm512_mask_blend_ps(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_blend_pd(simde__mmask8 k, simde__m512d a, simde__m512d b) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_blend_pd(k, a, b);
#else
  return simde_mm512_mask_mov_pd(a, k, b);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_blend_pd(k, a, b) simde_mm512_mask_blend_pd(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_broadcast_f32x4 (simde__m128 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_broadcast_f32x4(a);
  #else
    simde__m512_private r_;

    #if defined(SIMDE_X86_AVX2_NATIVE)
      r_.m256[1] = r_.m256[0] = simde_mm256_castsi256_ps(simde_mm256_broadcastsi128_si256(simde_mm_castps_si128(a)));
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m128) / sizeof(r_.m128[0])) ; i++) {
        r_.m128[i] = a;
      }
    #endif

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_broadcast_f32x4
  #define _mm512_broadcast_f32x4(a) simde_mm512_broadcast_f32x4(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_broadcast_f32x4(simde__m512 src, simde__mmask16 k, simde__m128 a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_broadcast_f32x4(src, k, a);
#else
  return simde_mm512_mask_mov_ps(src, k, simde_mm512_broadcast_f32x4(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_broadcast_f32x4(src, k, a) simde_mm512_mask_broadcast_f32x4(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_broadcast_f32x4(simde__mmask16 k, simde__m128 a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_broadcast_f32x4(k, a);
#else
  return simde_mm512_maskz_mov_ps(k, simde_mm512_broadcast_f32x4(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_broadcast_f32x4(k, a) simde_mm512_maskz_broadcast_f32x4(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_broadcast_f64x4 (simde__m256d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_broadcast_f64x4(a);
  #else
    simde__m512d_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.m256d) / sizeof(r_.m256d[0])) ; i++) {
      r_.m256d[i] = a;
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_broadcast_f64x4
  #define _mm512_broadcast_f64x4(a) simde_mm512_broadcast_f64x4(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_broadcast_f64x4(simde__m512d src, simde__mmask8 k, simde__m256d a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_broadcast_f64x4(src, k, a);
#else
  return simde_mm512_mask_mov_pd(src, k, simde_mm512_broadcast_f64x4(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_broadcast_f64x4(src, k, a) simde_mm512_mask_broadcast_f64x4(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_broadcast_f64x4(simde__mmask8 k, simde__m256d a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_broadcast_f64x4(k, a);
#else
  return simde_mm512_maskz_mov_pd(k, simde_mm512_broadcast_f64x4(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_broadcast_f64x4(k, a) simde_mm512_maskz_broadcast_f64x4(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_broadcast_i32x4 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_broadcast_i32x4(a);
  #else
    simde__m512i_private r_;

    #if defined(SIMDE_X86_AVX2_NATIVE)
      r_.m256i[1] = r_.m256i[0] = simde_mm256_broadcastsi128_si256(a);
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i[3] = r_.m128i[2] = r_.m128i[1] = r_.m128i[0] = a;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++) {
        r_.m128i[i] = a;
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_broadcast_i32x4
  #define _mm512_broadcast_i32x4(a) simde_mm512_broadcast_i32x4(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_broadcast_i32x4(simde__m512i src, simde__mmask16 k, simde__m128i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_broadcast_i32x4(src, k, a);
#else
  return simde_mm512_mask_mov_epi32(src, k, simde_mm512_broadcast_i32x4(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_broadcast_i32x4(src, k, a) simde_mm512_mask_broadcast_i32x4(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_broadcast_i32x4(simde__mmask16 k, simde__m128i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_broadcast_i32x4(k, a);
#else
  return simde_mm512_maskz_mov_epi32(k, simde_mm512_broadcast_i32x4(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_broadcast_i32x4(k, a) simde_mm512_maskz_broadcast_i32x4(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_broadcast_i64x4 (simde__m256i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_broadcast_i64x4(a);
  #else
    simde__m512i_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
      r_.m256i[i] = a;
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_broadcast_i64x4
  #define _mm512_broadcast_i64x4(a) simde_mm512_broadcast_i64x4(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_broadcast_i64x4(simde__m512i src, simde__mmask8 k, simde__m256i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_broadcast_i64x4(src, k, a);
#else
  return simde_mm512_mask_mov_epi64(src, k, simde_mm512_broadcast_i64x4(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_broadcast_i64x4(src, k, a) simde_mm512_mask_broadcast_i64x4(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_broadcast_i64x4(simde__mmask8 k, simde__m256i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_broadcast_i64x4(k, a);
#else
  return simde_mm512_maskz_mov_epi64(k, simde_mm512_broadcast_i64x4(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_broadcast_i64x4(k, a) simde_mm512_maskz_broadcast_i64x4(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_broadcastd_epi32 (simde__m128i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_broadcastd_epi32(a);
#else
  simde__m512i_private r_;
  simde__m128i_private a_= simde__m128i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[0];
  }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_broadcastd_epi32
  #define _mm512_broadcastd_epi32(a) simde_mm512_broadcastd_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_broadcastd_epi32(simde__m512i src, simde__mmask16 k, simde__m128i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_broadcastd_epi32(src, k, a);
#else
  return simde_mm512_mask_mov_epi32(src, k, simde_mm512_broadcastd_epi32(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_broadcastd_epi32(src, k, a) simde_mm512_mask_broadcastd_epi32(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_broadcastd_epi32(simde__mmask16 k, simde__m128i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_broadcastd_epi32(k, a);
#else
  return simde_mm512_maskz_mov_epi32(k, simde_mm512_broadcastd_epi32(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_broadcastd_epi32(k, a) simde_mm512_maskz_broadcastd_epi32(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_broadcastq_epi64 (simde__m128i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_broadcastq_epi64(a);
#else
  simde__m512i_private r_;
  simde__m128i_private a_= simde__m128i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
    r_.i64[i] = a_.i64[0];
  }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_broadcastq_epi64
  #define _mm512_broadcastq_epi64(a) simde_mm512_broadcastq_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_broadcastq_epi64(simde__m512i src, simde__mmask8 k, simde__m128i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_broadcastq_epi64(src, k, a);
#else
  return simde_mm512_mask_mov_epi64(src, k, simde_mm512_broadcastq_epi64(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_broadcastq_epi64(src, k, a) simde_mm512_mask_broadcastq_epi64(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_broadcastq_epi64(simde__mmask8 k, simde__m128i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_broadcastq_epi64(k, a);
#else
  return simde_mm512_maskz_mov_epi64(k, simde_mm512_broadcastq_epi64(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_broadcastq_epi64(k, a) simde_mm512_maskz_broadcastq_epi64(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_broadcastss_ps (simde__m128 a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_broadcastss_ps(a);
#else
  simde__m512_private r_;
  simde__m128_private a_= simde__m128_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = a_.f32[0];
  }

  return simde__m512_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_broadcastss_ps
  #define _mm512_broadcastss_ps(a) simde_mm512_broadcastss_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_broadcastss_ps(simde__m512 src, simde__mmask16 k, simde__m128 a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_broadcastss_ps(src, k, a);
#else
  simde__m512_private
    src_ = simde__m512_to_private(src),
    r_;
  simde__m128_private
    a_ = simde__m128_to_private(a);


  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = ((k >> i) & 1) ? a_.f32[0] : src_.f32[i];
  }

  return simde__m512_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_broadcastss_ps(src, k, a) simde_mm512_mask_broadcastss_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_broadcastss_ps(simde__mmask16 k, simde__m128 a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_broadcastss_ps(k, a);
#else
  simde__m512_private
    r_;
  simde__m128_private
    a_ = simde__m128_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
    r_.f32[i] = ((k >> i) & 1) ? a_.f32[0] : INT32_C(0);
  }

  return simde__m512_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_broadcastss_ps(k, a) simde_mm512_maskz_broadcastss_ps(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_broadcastsd_pd (simde__m128d a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_broadcastsd_pd(a);
#else
  simde__m512d_private r_;
  simde__m128d_private a_= simde__m128d_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
    r_.f64[i] = a_.f64[0];
  }

  return simde__m512d_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_broadcastsd_pd
  #define _mm512_broadcastsd_pd(a) simde_mm512_broadcastsd_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_broadcastsd_pd(simde__m512d src, simde__mmask8 k, simde__m128d a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_broadcastsd_pd(src, k, a);
#else
  simde__m512d_private
    src_ = simde__m512d_to_private(src),
    r_;
  simde__m128d_private
    a_ = simde__m128d_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
    r_.f64[i] = ((k >> i) & 1) ? a_.f64[0] : src_.f64[i];
  }

  return simde__m512d_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_broadcastsd_pd(src, k, a) simde_mm512_mask_broadcastsd_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_broadcastsd_pd(simde__mmask8 k, simde__m128d a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_broadcastsd_pd(k, a);
#else
  simde__m512d_private
    r_;
  simde__m128d_private
    a_ = simde__m128d_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
    r_.f64[i] = ((k >> i) & 1) ? a_.f64[0] : INT64_C(0);
  }

  return simde__m512d_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_broadcastsd_pd(k, a) simde_mm512_maskz_broadcastsd_pd(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_cmpeq_epi32_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cmpeq_epi32_mask(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
      r_.m256i[i] = simde_mm256_cmpeq_epi32(a_.m256i[i], b_.m256i[i]);
    }

    return simde_mm512_movepi32_mask(simde__m512i_from_private(r_));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpeq_epi32_mask
  #define _mm512_cmpeq_epi32_mask(a, b) simde_mm512_cmpeq_epi32_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_mask_cmpeq_epi32_mask (simde__mmask16 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cmpeq_epi32_mask(k1, a, b);
  #else
    return simde_mm512_cmpeq_epi32_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cmpeq_epi32_mask
  #define _mm512_mask_cmpeq_epi32_mask(k1, a, b) simde_mm512_mask_cmpeq_epi32_mask(k1, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_cmpeq_epi64_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cmpeq_epi64_mask(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
      r_.m256i[i] = simde_mm256_cmpeq_epi64(a_.m256i[i], b_.m256i[i]);
    }

    return simde_mm512_movepi64_mask(simde__m512i_from_private(r_));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpeq_epi64_mask
  #define _mm512_cmpeq_epi64_mask(a, b) simde_mm512_cmpeq_epi64_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_mask_cmpeq_epi64_mask (simde__mmask8 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cmpeq_epi64_mask(k1, a, b);
  #else
    return simde_mm512_cmpeq_epi64_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cmpeq_epi64_mask
  #define _mm512_mask_cmpeq_epi64_mask(k1, a, b) simde_mm512_mask_cmpeq_epi64_mask(k1, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_cmpgt_epi32_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cmpgt_epi32_mask(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
      r_.m256i[i] = simde_mm256_cmpgt_epi32(a_.m256i[i], b_.m256i[i]);
    }

    return simde_mm512_movepi32_mask(simde__m512i_from_private(r_));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpgt_epi32_mask
  #define _mm512_cmpgt_epi32_mask(a, b) simde_mm512_cmpgt_epi32_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_mask_cmpgt_epi32_mask (simde__mmask16 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cmpgt_epi32_mask(k1, a, b);
  #else
    return simde_mm512_cmpgt_epi32_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cmpgt_epi32_mask
  #define _mm512_mask_cmpgt_epi32_mask(k1, a, b) simde_mm512_mask_cmpgt_epi32_mask(k1, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_cmpgt_epi64_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cmpgt_epi64_mask(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
      r_.m256i[i] = simde_mm256_cmpgt_epi64(a_.m256i[i], b_.m256i[i]);
    }

    return simde_mm512_movepi64_mask(simde__m512i_from_private(r_));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cmpgt_epi64_mask
  #define _mm512_cmpgt_epi64_mask(a, b) simde_mm512_cmpgt_epi64_mask(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_mask_cmpgt_epi64_mask (simde__mmask8 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cmpgt_epi64_mask(k1, a, b);
  #else
    return simde_mm512_cmpgt_epi64_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cmpgt_epi64_mask
  #define _mm512_mask_cmpgt_epi64_mask(k1, a, b) simde_mm512_mask_cmpgt_epi64_mask(k1, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_cvtepi8_epi32 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cvtepi8_epi32(a);
  #else
    simde__m512i_private r_;
    simde__m128i_private a_ = simde__m128i_to_private(a);

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.i32, a_.i8);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i8[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cvtepi8_epi32
  #define _mm512_cvtepi8_epi32(a) simde_mm512_cvtepi8_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_cvtepi8_epi32 (simde__m512i src, simde__mmask16 k, simde__m128i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_cvtepi8_epi32(src, k, a);
#else
  return simde_mm512_mask_mov_epi32(src, k, simde_mm512_cvtepi8_epi32(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_cvtepi8_epi32(src, k, a) simde_mm512_mask_cvtepi8_epi32(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_cvtepi8_epi32 (simde__mmask16 k, simde__m128i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_cvtepi8_epi32(k, a);
#else
  return simde_mm512_maskz_mov_epi32(k, simde_mm512_cvtepi8_epi32(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_cvtepi8_epi32(k, a) simde_mm512_maskz_cvtepi8_epi32(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_cvtepi8_epi64 (simde__m128i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cvtepi8_epi64(a);
  #else
    simde__m512i_private r_;
    simde__m128i_private a_ = simde__m128i_to_private(a);

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.i64, a_.m64_private[0].i8);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a_.i8[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cvtepi8_epi64
  #define _mm512_cvtepi8_epi64(a) simde_mm512_cvtepi8_epi64(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_cvtepi8_epi64 (simde__m512i src, simde__mmask8 k, simde__m128i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_cvtepi8_epi64(src, k, a);
#else
  return simde_mm512_mask_mov_epi64(src, k, simde_mm512_cvtepi8_epi64(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_cvtepi8_epi64(src, k, a) simde_mm512_mask_cvtepi8_epi64(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_cvtepi8_epi64 (simde__mmask8 k, simde__m128i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_cvtepi8_epi64(k, a);
#else
  return simde_mm512_maskz_mov_epi64(k, simde_mm512_cvtepi8_epi64(a));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_cvtepi8_epi64(k, a) simde_mm512_maskz_cvtepi8_epi64(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_cvtepi32_epi8 (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cvtepi32_epi8(a);
  #else
    simde__m128i_private r_;
    simde__m512i_private a_ = simde__m512i_to_private(a);

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.i8, a_.i32);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
        r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, a_.i32[i]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cvtepi32_epi8
  #define _mm512_cvtepi32_epi8(a) simde_mm512_cvtepi32_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_mask_cvtepi32_epi8 (simde__m128i src, simde__mmask16 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_cvtepi32_epi8(src, k, a);
#else
  simde__m128i_private r_;
  simde__m128i_private src_ = simde__m128i_to_private(src);
  simde__m512i_private a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
    r_.i8[i] = ( (k>>i) & 1 ) ? HEDLEY_STATIC_CAST(int8_t, a_.i32[i]) : src_.i8[i];
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_cvtepi32_epi8(src, k, a) simde_mm512_mask_cvtepi32_epi8(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_maskz_cvtepi32_epi8 (simde__mmask16 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_cvtepi32_epi8(k, a);
#else
  simde__m128i_private r_;
  simde__m512i_private a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
    r_.i8[i] = ( (k>>i) & 1 ) ? HEDLEY_STATIC_CAST(int8_t, a_.i32[i]) : INT8_C(0);
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_cvtepi32_epi8(k, a) simde_mm512_maskz_cvtepi32_epi8(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_cvtepi32_epi16 (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cvtepi32_epi16(a);
  #else
    simde__m256i_private r_;
    simde__m512i_private a_ = simde__m512i_to_private(a);

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.i16, a_.i32);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
        r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, a_.i32[i]);
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cvtepi32_epi16
  #define _mm512_cvtepi32_epi16(a) simde_mm512_cvtepi32_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_mask_cvtepi32_epi16 (simde__m256i src, simde__mmask16 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_cvtepi32_epi16(src, k, a);
#else
  simde__m256i_private r_;
  simde__m256i_private src_ = simde__m256i_to_private(src);
  simde__m512i_private a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
    r_.i16[i] = ( (k>>i) & 1 ) ? HEDLEY_STATIC_CAST(int16_t, a_.i32[i]) : src_.i16[i];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_cvtepi32_epi16(src, k, a) simde_mm512_mask_cvtepi32_epi16(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_maskz_cvtepi32_epi16 (simde__mmask16 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_cvtepi32_epi16(k, a);
#else
  simde__m256i_private r_;
  simde__m512i_private a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
    r_.i16[i] = ( (k>>i) & 1 ) ? HEDLEY_STATIC_CAST(int16_t, a_.i32[i]) : INT16_C(0);
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_cvtepi32_epi16(k, a) simde_mm512_maskz_cvtepi32_epi16(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_cvtepi64_epi8 (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cvtepi64_epi8(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m512i_private a_ = simde__m512i_to_private(a);

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.m64_private[0].i8, a_.i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
        r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, a_.i64[i]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cvtepi64_epi8
  #define _mm512_cvtepi64_epi8(a) simde_mm512_cvtepi64_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_mask_cvtepi64_epi8 (simde__m128i src, simde__mmask8 k,simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cvtepi64_epi8(src, k, a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m128i_private src_ = simde__m128i_to_private(src);
    simde__m512i_private a_ = simde__m512i_to_private(a);

      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
        r_.i8[i] = ( (k>>i) & 1 ) ? HEDLEY_STATIC_CAST(int8_t, a_.i64[i]) : src_.i8[i] ;
      }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cvtepi64_epi8
  #define _mm512_mask_cvtepi64_epi8(src, k, a) simde_mm512_mask_cvtepi64_epi8(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_maskz_cvtepi64_epi8 (simde__mmask8 k,simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_cvtepi64_epi8(k, a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m512i_private a_ = simde__m512i_to_private(a);

      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
        r_.i8[i] = ( (k>>i) & 1 ) ? HEDLEY_STATIC_CAST(int8_t, a_.i64[i]) : INT8_C(0) ;
      }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_cvtepi64_epi8
  #define _mm512_maskz_cvtepi64_epi8(k, a) simde_mm512_maskz_cvtepi64_epi8(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_cvtepi64_epi16 (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cvtepi64_epi16(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m512i_private a_ = simde__m512i_to_private(a);

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.i16, a_.i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
        r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, a_.i64[i]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cvtepi64_epi16
  #define _mm512_cvtepi64_epi16(a) simde_mm512_cvtepi64_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_mask_cvtepi64_epi16 (simde__m128i src, simde__mmask8 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_cvtepi64_epi16(src, k, a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m128i_private src_ = simde__m128i_to_private(src);
    simde__m512i_private a_ = simde__m512i_to_private(a);

      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
        r_.i16[i] = ( (k>>i) & 1 ) ? HEDLEY_STATIC_CAST(int16_t, a_.i64[i]) : src_.i16[i];
      }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cvtepi64_epi16
  #define _mm512_mask_cvtepi64_epi16(src, k, a) simde_mm512_mask_cvtepi64_epi16(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_maskz_cvtepi64_epi16 (simde__mmask8 k, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_cvtepi64_epi16(k, a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m512i_private a_ = simde__m512i_to_private(a);

      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
        r_.i16[i] = ( (k>>i) & 1 ) ? HEDLEY_STATIC_CAST(int16_t, a_.i64[i]) : INT16_C(0);
      }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_cvtepi64_epi16
  #define _mm512_maskz_cvtepi64_epi16(k, a) simde_mm512_maskz_cvtepi64_epi16(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_cvtepi64_epi32 (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cvtepi64_epi32(a);
  #else
    simde__m256i_private r_;
    simde__m512i_private a_ = simde__m512i_to_private(a);

    #if defined(SIMDE_CONVERT_VECTOR_)
      SIMDE_CONVERT_VECTOR_(r_.i32, a_.i64);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
        r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, a_.i64[i]);
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cvtepi64_epi32
  #define _mm512_cvtepi64_epi32(a) simde_mm512_cvtepi64_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_mask_cvtepi64_epi32 (simde__m256i src, simde__mmask8 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_cvtepi64_epi32(src, k, a);
#else
  simde__m256i_private src_= simde__m256i_to_private(src);
  simde__m256i_private r_;
  simde__m512i_private a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
    r_.i32[i] = ( (k>>i) & 1 ) ? HEDLEY_STATIC_CAST(int32_t, a_.i64[i]) : src_.i32[i];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_cvtepi64_epi32(src, k, a) simde_mm512_mask_cvtepi64_epi32(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_maskz_cvtepi64_epi32 (simde__mmask8 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_cvtepi64_epi32(k, a);
#else
  simde__m256i_private r_;
  simde__m512i_private a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
    r_.i32[i] = ( (k>>i) & 1 ) ? HEDLEY_STATIC_CAST(int32_t, a_.i64[i]) : INT32_C(0);
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_cvtepi64_epi32(k, a) simde_mm512_maskz_cvtepi64_epi32(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_cvtsepi32_epi8 (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cvtsepi32_epi8(a);
  #else
    simde__m128i_private r_;
    simde__m512i_private a_ = simde__m512i_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
      r_.i8[i] =
        (a_.i32[i] < INT8_MIN)
          ? (INT8_MIN)
          : ((a_.i32[i] > INT8_MAX)
            ? (INT8_MAX)
            : HEDLEY_STATIC_CAST(int8_t, a_.i32[i]));
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cvtsepi32_epi8
  #define _mm512_cvtsepi32_epi8(a) simde_mm512_cvtsepi32_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_mask_cvtsepi32_epi8 (simde__m128i src, simde__mmask16 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_cvtsepi32_epi8(src, k, a);
#else
  simde__m128i_private r_;
  simde__m128i_private src_ = simde__m128i_to_private(src);
  simde__m512i_private a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
    r_.i8[i] = ((k>>i) &1 ) ?
      ((a_.i32[i] < INT8_MIN)
      ? (INT8_MIN)
      : ((a_.i32[i] > INT8_MAX)
         ? (INT8_MAX)
         : HEDLEY_STATIC_CAST(int8_t, a_.i32[i]))) : src_.i8[i] ;
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_cvtsepi32_epi8(src, k, a) simde_mm512_mask_cvtsepi32_epi8(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_maskz_cvtsepi32_epi8 (simde__mmask16 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_cvtsepi32_epi8(k, a);
#else
  simde__m128i_private r_;
  simde__m512i_private a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
    r_.i8[i] = ((k>>i) &1 ) ?
               ((a_.i32[i] < INT8_MIN)
                ? (INT8_MIN)
                : ((a_.i32[i] > INT8_MAX)
                   ? (INT8_MAX)
                   : HEDLEY_STATIC_CAST(int8_t, a_.i32[i]))) : INT8_C(0) ;
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_cvtsepi32_epi8(k, a) simde_mm512_maskz_cvtsepi32_epi8(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_cvtsepi32_epi16 (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cvtsepi32_epi16(a);
  #else
    simde__m256i_private r_;
    simde__m512i_private a_ = simde__m512i_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
      r_.i16[i] =
        (a_.i32[i] < INT16_MIN)
          ? (INT16_MIN)
          : ((a_.i32[i] > INT16_MAX)
            ? (INT16_MAX)
            : HEDLEY_STATIC_CAST(int16_t, a_.i32[i]));
    }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cvtsepi32_epi16
  #define _mm512_cvtsepi32_epi16(a) simde_mm512_cvtsepi32_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_mask_cvtsepi32_epi16 (simde__m256i src, simde__mmask16 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_cvtsepi32_epi16(src, k, a);
#else
  simde__m256i_private r_;
  simde__m256i_private src_ = simde__m256i_to_private(src);
  simde__m512i_private a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
    r_.i16[i] = ((k>>i) &1 ) ?
      ((a_.i32[i] < INT16_MIN)
      ? (INT16_MIN)
      : ((a_.i32[i] > INT16_MAX)
         ? (INT16_MAX)
         : HEDLEY_STATIC_CAST(int16_t, a_.i32[i]))) : src_.i16[i];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_cvtsepi32_epi16(src, k, a) simde_mm512_mask_cvtsepi32_epi16(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_maskz_cvtsepi32_epi16 (simde__mmask16 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_cvtsepi32_epi16(k, a);
#else
  simde__m256i_private r_;
  simde__m512i_private a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
    r_.i16[i] = ((k>>i) &1 ) ?
                ((a_.i32[i] < INT16_MIN)
                 ? (INT16_MIN)
                 : ((a_.i32[i] > INT16_MAX)
                    ? (INT16_MAX)
                    : HEDLEY_STATIC_CAST(int16_t, a_.i32[i]))) : INT16_C(0);
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_cvtsepi32_epi16(k, a) simde_mm512_maskz_cvtsepi32_epi16(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_cvtsepi64_epi8 (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cvtsepi64_epi8(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m512i_private a_ = simde__m512i_to_private(a);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
       r_.i8[i] =
        (a_.i64[i] < INT8_MIN)
          ? (INT8_MIN)
          : ((a_.i64[i] > INT8_MAX)
            ? (INT8_MAX)
            : HEDLEY_STATIC_CAST(int8_t, a_.i64[i]));
    }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cvtsepi64_epi8
  #define _mm512_cvtsepi64_epi8(a) simde_mm512_cvtsepi64_epi8(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_mask_cvtsepi64_epi8 (simde__m128i src, simde__mmask8 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_cvtsepi64_epi8(src, k, a);
#else
  simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
  simde__m128i_private src_ = simde__m128i_to_private(src);
  simde__m512i_private a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
    r_.i8[i] = ((k>>i) &1 ) ?
               ((a_.i64[i] < INT8_MIN)
                ? (INT8_MIN)
                : ((a_.i64[i] > INT8_MAX)
                   ? (INT8_MAX)
                   : HEDLEY_STATIC_CAST(int8_t, a_.i64[i]))) : src_.i8[i];
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cvtsepi64_epi8
  #define _mm512_mask_cvtsepi64_epi8(src, k, a) simde_mm512_mask_cvtsepi64_epi8(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_maskz_cvtsepi64_epi8 (simde__mmask8 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_cvtsepi64_epi8(k, a);
#else
  simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
  simde__m512i_private a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
    r_.i8[i] = ((k>>i) &1 ) ?
               ((a_.i64[i] < INT8_MIN)
                ? (INT8_MIN)
                : ((a_.i64[i] > INT8_MAX)
                   ? (INT8_MAX)
                   : HEDLEY_STATIC_CAST(int8_t, a_.i64[i]))) : INT8_C(0);
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_cvtsepi64_epi8(k, a) simde_mm512_maskz_cvtsepi64_epi8(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_cvtsepi64_epi16 (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cvtsepi64_epi16(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m512i_private a_ = simde__m512i_to_private(a);

      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
        r_.i16[i] =
        (a_.i64[i] < INT16_MIN)
          ? (INT16_MIN)
          : ((a_.i64[i] > INT16_MAX)
            ? (INT16_MAX)
            : HEDLEY_STATIC_CAST(int16_t, a_.i64[i]));
      }

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cvtsepi64_epi16
  #define _mm512_cvtsepi64_epi16(a) simde_mm512_cvtsepi64_epi16(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_mask_cvtsepi64_epi16 (simde__m128i src, simde__mmask8 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_cvtsepi64_epi16(src, k, a);
#else
  simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
  simde__m128i_private src_ = simde__m128i_to_private(src);
  simde__m512i_private a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
    r_.i16[i] = ((k>>i) & 1) ?
                ((a_.i64[i] < INT16_MIN)
                 ? (INT16_MIN)
                 : ((a_.i64[i] > INT16_MAX)
                    ? (INT16_MAX)
                    : HEDLEY_STATIC_CAST(int16_t, a_.i64[i]))) : src_.i16[i];
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_cvtsepi64_epi16
  #define _mm512_mask_cvtsepi64_epi16(src, k, a) simde_mm512_mask_cvtsepi64_epi16(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_maskz_cvtsepi64_epi16 (simde__mmask8 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_cvtsepi64_epi16(k, a);
#else
  simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
  simde__m512i_private a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
    r_.i16[i] = ((k>>i) & 1) ?
                ((a_.i64[i] < INT16_MIN)
                 ? (INT16_MIN)
                 : ((a_.i64[i] > INT16_MAX)
                    ? (INT16_MAX)
                    : HEDLEY_STATIC_CAST(int16_t, a_.i64[i]))) : INT16_C(0);
  }

  return simde__m128i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_cvtsepi64_epi16(k, a) simde_mm512_maskz_cvtsepi64_epi16(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_cvtsepi64_epi32 (simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_cvtsepi64_epi32(a);
  #else
    simde__m256i_private r_;
    simde__m512i_private a_ = simde__m512i_to_private(a);

      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
        r_.i32[i] =
        (a_.i64[i] < INT32_MIN)
          ? (INT32_MIN)
          : ((a_.i64[i] > INT32_MAX)
            ? (INT32_MAX)
            : HEDLEY_STATIC_CAST(int32_t, a_.i64[i]));
      }

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_cvtsepi64_epi32
  #define _mm512_cvtsepi64_epi32(a) simde_mm512_cvtsepi64_epi32(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_mask_cvtsepi64_epi32 (simde__m256i src, simde__mmask8 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_cvtsepi64_epi32(src, k, a);
#else
  simde__m256i_private r_;
  simde__m256i_private src_ = simde__m256i_to_private(src);
  simde__m512i_private a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
    r_.i32[i] = ((k>>i) & 1) ?
      ((a_.i64[i] < INT32_MIN)
      ? (INT32_MIN)
      : ((a_.i64[i] > INT32_MAX)
         ? (INT32_MAX)
         : HEDLEY_STATIC_CAST(int32_t, a_.i64[i]))) : src_.i32[i];
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_cvtsepi64_epi32(src, k, a) simde_mm512_mask_cvtsepi64_epi32(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_maskz_cvtsepi64_epi32 (simde__mmask8 k, simde__m512i a) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_cvtsepi64_epi32(k, a);
#else
  simde__m256i_private r_;
  simde__m512i_private a_ = simde__m512i_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
    r_.i32[i] = ((k>>i) & 1) ?
                ((a_.i64[i] < INT32_MIN)
                 ? (INT32_MIN)
                 : ((a_.i64[i] > INT32_MAX)
                    ? (INT32_MAX)
                    : HEDLEY_STATIC_CAST(int32_t, a_.i64[i]))) : INT32_C(0);
  }

  return simde__m256i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_cvtsepi64_epi32(k, a) simde_mm512_maskz_cvtsepi64_epi32(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_div_ps (simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_div_ps(a, b);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f32 = a_.f32 / b_.f32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256) / sizeof(r_.m256[0])) ; i++) {
        r_.m256[i] = simde_mm256_div_ps(a_.m256[i], b_.m256[i]);
      }
    #endif

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_div_ps
  #define _mm512_div_ps(a, b) simde_mm512_div_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_div_ps(simde__m512 src, simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_div_ps(src, k, a, b);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_div_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_div_ps
  #define _mm512_mask_div_ps(src, k, a, b) simde_mm512_mask_div_ps(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_div_ps(simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_div_ps(k, a, b);
  #else
    return simde_mm512_maskz_mov_ps(k, simde_mm512_div_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_div_ps
  #define _mm512_maskz_div_ps(k, a, b) simde_mm512_maskz_div_ps(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_div_pd (simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_div_pd(a, b);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f64 = a_.f64 / b_.f64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256d) / sizeof(r_.m256d[0])) ; i++) {
        r_.m256d[i] = simde_mm256_div_pd(a_.m256d[i], b_.m256d[i]);
      }
    #endif

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_div_pd
  #define _mm512_div_pd(a, b) simde_mm512_div_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_div_pd(simde__m512d src, simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_div_pd(src, k, a, b);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_div_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_div_pd
  #define _mm512_mask_div_pd(src, k, a, b) simde_mm512_mask_div_pd(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_div_pd(simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_div_pd(k, a, b);
  #else
    return simde_mm512_maskz_mov_pd(k, simde_mm512_div_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_div_pd
  #define _mm512_maskz_div_pd(k, a, b) simde_mm512_maskz_div_pd(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128
simde_mm512_extractf32x4_ps (simde__m512 a, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 3) {
  simde__m512_private a_ = simde__m512_to_private(a);

  return a_.m128[imm8 & 3];
}
#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_extractf32x4_ps(a, imm8) _mm512_extractf32x4_ps(a, imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_extractf32x4_ps
  #define _mm512_extractf32x4_ps(a, imm8) simde_mm512_extractf32x4_ps(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_mask_extractf32x4_ps(src, k, a, imm8) _mm512_mask_extractf32x4_ps(src, k, a, imm8)
#else
  #define simde_mm512_mask_extractf32x4_ps(src, k, a, imm8) simde_mm_mask_mov_ps(src, k, simde_mm512_extractf32x4_ps(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_extractf32x4_ps
  #define _mm512_mask_extractf32x4_ps(src, k, a, imm8) simde_mm512_mask_extractf32x4_ps(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_maskz_extractf32x4_ps(k, a, imm8) _mm512_maskz_extractf32x4_ps(k, a, imm8)
#else
  #define simde_mm512_maskz_extractf32x4_ps(k, a, imm8) simde_mm_maskz_mov_ps(k, simde_mm512_extractf32x4_ps(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_extractf32x4_ps
  #define _mm512_maskz_extractf32x4_ps(k, a, imm8) simde_mm512_maskz_extractf32x4_ps(k, a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm512_extractf64x4_pd (simde__m512d a, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 1) {
  simde__m512d_private a_ = simde__m512d_to_private(a);

  return a_.m256d[imm8 & 1];
}
#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_extractf64x4_pd(a, imm8) _mm512_extractf64x4_pd(a, imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_extractf64x4_pd
  #define _mm512_extractf64x4_pd(a, imm8) simde_mm512_extractf64x4_pd(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_mask_extractf64x4_pd(src, k, a, imm8) _mm512_mask_extractf64x4_pd(src, k, a, imm8)
#else
  #define simde_mm512_mask_extractf64x4_pd(src, k, a, imm8) simde_mm256_mask_mov_pd(src, k, simde_mm512_extractf64x4_pd(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_extractf64x4_pd
  #define _mm512_mask_extractf64x4_pd(src, k, a, imm8) simde_mm512_mask_extractf64x4_pd(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_maskz_extractf64x4_pd(k, a, imm8) _mm512_maskz_extractf64x4_pd(k, a, imm8)
#else
  #define simde_mm512_maskz_extractf64x4_pd(k, a, imm8) simde_mm256_maskz_mov_pd(k, simde_mm512_extractf64x4_pd(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_extractf64x4_pd
  #define _mm512_maskz_extractf64x4_pd(k, a, imm8) simde_mm512_maskz_extractf64x4_pd(k, a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_extracti32x4_epi32 (simde__m512i a, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 3) {
  simde__m512i_private a_ = simde__m512i_to_private(a);

  return a_.m128i[imm8 & 3];
}
#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_extracti32x4_epi32(a, imm8) _mm512_extracti32x4_epi32(a, imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_extracti32x4_epi32
  #define _mm512_extracti32x4_epi32(a, imm8) simde_mm512_extracti32x4_epi32(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_mask_extracti32x4_epi32(src, k, a, imm8) _mm512_mask_extracti32x4_epi32(src, k, a, imm8)
#else
  #define simde_mm512_mask_extracti32x4_epi32(src, k, a, imm8) simde_mm_mask_mov_epi32(src, k, simde_mm512_extracti32x4_epi32(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_extracti32x4_epi32
  #define _mm512_mask_extracti32x4_epi32(src, k, a, imm8) simde_mm512_mask_extracti32x4_epi32(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_maskz_extracti32x4_epi32(k, a, imm8) _mm512_maskz_extracti32x4_epi32(k, a, imm8)
#else
  #define simde_mm512_maskz_extracti32x4_epi32(k, a, imm8) simde_mm_maskz_mov_epi32(k, simde_mm512_extracti32x4_epi32(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_extracti32x4_epi32
  #define _mm512_maskz_extracti32x4_epi32(k, a, imm8) simde_mm512_maskz_extracti32x4_epi32(k, a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_extracti64x4_epi64 (simde__m512i a, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 1) {
  simde__m512i_private a_ = simde__m512i_to_private(a);

  return a_.m256i[imm8 & 1];
}
#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_extracti64x4_epi64(a, imm8) _mm512_extracti64x4_epi64(a, imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_extracti64x4_epi64
  #define _mm512_extracti64x4_epi64(a, imm8) simde_mm512_extracti64x4_epi64(a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_mask_extracti64x4_epi64(src, k, a, imm8) _mm512_mask_extracti64x4_epi64(src, k, a, imm8)
#else
  #define simde_mm512_mask_extracti64x4_epi64(src, k, a, imm8) simde_mm256_mask_mov_epi64(src, k, simde_mm512_extracti64x4_epi64(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_extracti64x4_epi64
  #define _mm512_mask_extracti64x4_epi64(src, k, a, imm8) simde_mm512_mask_extracti64x4_epi64(src, k, a, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_maskz_extracti64x4_epi64(k, a, imm8) _mm512_maskz_extracti64x4_epi64(k, a, imm8)
#else
  #define simde_mm512_maskz_extracti64x4_epi64(k, a, imm8) simde_mm256_maskz_mov_epi64(k, simde_mm512_extracti64x4_epi64(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_extracti64x4_epi64
  #define _mm512_maskz_extracti64x4_epi64(k, a, imm8) simde_mm512_maskz_extracti64x4_epi64(k, a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_insertf32x4 (simde__m512 a, simde__m128 b, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 3) {
  simde__m512_private a_ = simde__m512_to_private(a);

  a_.m128[imm8 & 3] = b;

  return simde__m512_from_private(a_);
}
#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_insertf32x4(a, b, imm8) _mm512_insertf32x4(a, b, imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_insertf32x4
  #define _mm512_insertf32x4(a, b, imm8) simde_mm512_insertf32x4(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(8,0,0))
  #define simde_mm512_mask_insertf32x4(src, k, a, b, imm8) _mm512_mask_insertf32x4(src, k, a, b, imm8)
#else
  #define simde_mm512_mask_insertf32x4(src, k, a, b, imm8) simde_mm512_mask_mov_ps(src, k, simde_mm512_insertf32x4(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_insertf32x4
  #define _mm512_mask_insertf32x4(src, k, a, b, imm8) simde_mm512_mask_insertf32x4(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(8,0,0))
  #define simde_mm512_maskz_insertf32x4(k, a, b, imm8) _mm512_maskz_insertf32x4(k, a, b, imm8)
#else
  #define simde_mm512_maskz_insertf32x4(k, a, b, imm8) simde_mm512_maskz_mov_ps(k, simde_mm512_insertf32x4(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_insertf32x4
  #define _mm512_maskz_insertf32x4(k, a, b, imm8) simde_mm512_maskz_insertf32x4(k, a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_insertf64x4 (simde__m512d a, simde__m256d b, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 1) {
  simde__m512d_private a_ = simde__m512d_to_private(a);

  a_.m256d[imm8 & 1] = b;

  return simde__m512d_from_private(a_);
}
#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_insertf64x4(a, b, imm8) _mm512_insertf64x4(a, b, imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_insertf64x4
  #define _mm512_insertf64x4(a, b, imm8) simde_mm512_insertf64x4(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_mask_insertf64x4(src, k, a, b, imm8) _mm512_mask_insertf64x4(src, k, a, b, imm8)
#else
  #define simde_mm512_mask_insertf64x4(src, k, a, b, imm8) simde_mm512_mask_mov_pd(src, k, simde_mm512_insertf64x4(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_insertf64x4
  #define _mm512_mask_insertf64x4(src, k, a, b, imm8) simde_mm512_mask_insertf64x4(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_maskz_insertf64x4(k, a, b, imm8) _mm512_maskz_insertf64x4(k, a, b, imm8)
#else
  #define simde_mm512_maskz_insertf64x4(k, a, b, imm8) simde_mm512_maskz_mov_pd(k, simde_mm512_insertf64x4(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_insertf64x4
  #define _mm512_maskz_insertf64x4(k, a, b, imm8) simde_mm512_maskz_insertf64x4(k, a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_inserti32x4 (simde__m512i a, simde__m128i b, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 3) {
  simde__m512i_private a_ = simde__m512i_to_private(a);

  a_.m128i[imm8 & 3] = b;

  return simde__m512i_from_private(a_);
}
#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_inserti32x4(a, b, imm8) _mm512_inserti32x4(a, b, imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_inserti32x4
  #define _mm512_inserti32x4(a, b, imm8) simde_mm512_inserti32x4(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(8,0,0))
  #define simde_mm512_mask_inserti32x4(src, k, a, b, imm8) _mm512_mask_inserti32x4(src, k, a, b, imm8)
#else
  #define simde_mm512_mask_inserti32x4(src, k, a, b, imm8) simde_mm512_mask_mov_epi32(src, k, simde_mm512_inserti32x4(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_inserti32x4
  #define _mm512_mask_inserti32x4(src, k, a, b, imm8) simde_mm512_mask_inserti32x4(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE) && (!defined(HEDLEY_GCC_VERSION) || HEDLEY_GCC_VERSION_CHECK(8,0,0))
  #define simde_mm512_maskz_inserti32x4(k, a, b, imm8) _mm512_maskz_inserti32x4(k, a, b, imm8)
#else
  #define simde_mm512_maskz_inserti32x4(k, a, b, imm8) simde_mm512_maskz_mov_epi32(k, simde_mm512_inserti32x4(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_inserti32x4
  #define _mm512_maskz_inserti32x4(k, a, b, imm8) simde_mm512_maskz_inserti32x4(k, a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_inserti64x4 (simde__m512i a, simde__m256i b, int imm8)
    SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 1) {
  simde__m512i_private a_ = simde__m512i_to_private(a);

  a_.m256i[imm8 & 1] = b;

  return simde__m512i_from_private(a_);
}
#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_inserti64x4(a, b, imm8) _mm512_inserti64x4(a, b, imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_inserti64x4
  #define _mm512_inserti64x4(a, b, imm8) simde_mm512_inserti64x4(a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_mask_inserti64x4(src, k, a, b, imm8) _mm512_mask_inserti64x4(src, k, a, b, imm8)
#else
  #define simde_mm512_mask_inserti64x4(src, k, a, b, imm8) simde_mm512_mask_mov_epi64(src, k, simde_mm512_inserti64x4(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_inserti64x4
  #define _mm512_mask_inserti64x4(src, k, a, b, imm8) simde_mm512_mask_inserti64x4(src, k, a, b, imm8)
#endif

#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_maskz_inserti64x4(k, a, b, imm8) _mm512_maskz_inserti64x4(k, a, b, imm8)
#else
  #define simde_mm512_maskz_inserti64x4(k, a, b, imm8) simde_mm512_maskz_mov_epi64(k, simde_mm512_inserti64x4(a, b, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_inserti64x4
  #define _mm512_maskz_inserti64x4(k, a, b, imm8) simde_mm512_maskz_inserti64x4(k, a, b, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_min_epi32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_min_epi32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_X86_AVX2_NATIVE)
    r_.m256i[0] = simde_mm256_min_epi32(a_.m256i[0], b_.m256i[0]);
    r_.m256i[1] = simde_mm256_min_epi32(a_.m256i[1], b_.m256i[1]);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a_.i32[i] < b_.i32[i] ? a_.i32[i] : b_.i32[i];
    }
  #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_min_epi32
  #define _mm512_min_epi32(a, b) simde_mm512_min_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_min_epi32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_min_epi32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_min_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_min_epi32
  #define _mm512_mask_min_epi32(src, k, a, b) simde_mm512_mask_min_epi32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_min_epi32(simde__mmask16 k, simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_min_epi32(k, a, b);
#else
  return simde_mm512_maskz_mov_epi32(k, simde_mm512_min_epi32(a, b));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_min_epi32
  #define _mm512_maskz_min_epi32(k, a, b) simde_mm512_maskz_min_epi32(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_min_epu32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_min_epu32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_X86_AVX2_NATIVE)
    r_.m256i[0] = simde_mm256_min_epu32(a_.m256i[0], b_.m256i[0]);
    r_.m256i[1] = simde_mm256_min_epu32(a_.m256i[1], b_.m256i[1]);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
      r_.u32[i] = (a_.u32[i] < b_.u32[i]) ? a_.u32[i] : b_.u32[i];
    }
  #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_min_epu32
  #define _mm512_min_epu32(a, b) simde_mm512_min_epu32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_min_epu32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_min_epu32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_min_epu32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_min_epu32
  #define _mm512_mask_min_epu32(src, k, a, b) simde_mm512_mask_min_epu32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_min_epu32(simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_min_epu32(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi32(k, simde_mm512_min_epu32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_min_epu32
  #define _mm512_maskz_min_epu32(k, a, b) simde_mm512_maskz_min_epu32(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_min_epi64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_min_epi64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a_.i64[i] < b_.i64[i] ? a_.i64[i] : b_.i64[i];
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_min_epi64
  #define _mm512_min_epi64(a, b) simde_mm512_min_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_min_epi64(simde__m512i src, simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_min_epi64(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_min_epi64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_min_epi64
  #define _mm512_mask_min_epi64(src, k, a, b) simde_mm512_mask_min_epi64(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_min_epi64(simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_min_epi64(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_min_epi64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_min_epi64
  #define _mm512_maskz_min_epi64(k, a, b) simde_mm512_maskz_min_epi64(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_min_epu64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_min_epu64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
      r_.u64[i] = (a_.u64[i] < b_.u64[i]) ? a_.u64[i] : b_.u64[i];
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_min_epu64
  #define _mm512_min_epu64(a, b) simde_mm512_min_epu64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_min_epu64(simde__m512i src, simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_min_epu64(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_min_epu64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_min_epu64
  #define _mm512_mask_min_epu64(src, k, a, b) simde_mm512_mask_min_epu64(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_min_epu64(simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_min_epu64(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_min_epu64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_min_epu64
  #define _mm512_maskz_min_epu64(k, a, b) simde_mm512_maskz_min_epu64(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_min_ps (simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_min_ps(a, b);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b);

  #if defined(SIMDE_X86_AVX2_NATIVE)
    r_.m256[0] = simde_mm256_min_ps(a_.m256[0], b_.m256[0]);
    r_.m256[1] = simde_mm256_min_ps(a_.m256[1], b_.m256[1]);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = a_.f32[i] < b_.f32[i] ? a_.f32[i] : b_.f32[i];
    }
  #endif

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_min_ps
  #define _mm512_min_ps(a, b) simde_mm512_min_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_min_ps(simde__m512 src, simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_min_ps(src, k, a, b);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_min_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_min_ps
  #define _mm512_mask_min_ps(src, k, a, b) simde_mm512_mask_min_ps(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_min_ps(simde__mmask16 k, simde__m512 a, simde__m512 b) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_min_ps(k, a, b);
#else
  return simde_mm512_maskz_mov_ps(k, simde_mm512_min_ps(a, b));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_min_ps
  #define _mm512_maskz_min_ps(k, a, b) simde_mm512_maskz_min_ps(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_min_pd (simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_min_pd(a, b);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = a_.f64[i] < b_.f64[i] ? a_.f64[i] : b_.f64[i];
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_min_pd
  #define _mm512_min_pd(a, b) simde_mm512_min_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_min_pd(simde__m512d src, simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_min_pd(src, k, a, b);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_min_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_min_pd
  #define _mm512_mask_min_pd(src, k, a, b) simde_mm512_mask_min_pd(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_min_pd(simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_min_pd(k, a, b);
  #else
    return simde_mm512_maskz_mov_pd(k, simde_mm512_min_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_min_pd
  #define _mm512_maskz_min_pd(k, a, b) simde_mm512_maskz_min_pd(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_max_epi32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_max_epi32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_X86_AVX2_NATIVE)
    r_.m256i[0] = simde_mm256_max_epi32(a_.m256i[0], b_.m256i[0]);
    r_.m256i[1] = simde_mm256_max_epi32(a_.m256i[1], b_.m256i[1]);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a_.i32[i] > b_.i32[i] ? a_.i32[i] : b_.i32[i];
    }
  #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_max_epi32
  #define _mm512_max_epi32(a, b) simde_mm512_max_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_max_epi32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_max_epi32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_max_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_max_epi32
  #define _mm512_mask_max_epi32(src, k, a, b) simde_mm512_mask_max_epi32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_max_epi32(simde__mmask16 k, simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_max_epi32(k, a, b);
#else
  return simde_mm512_maskz_mov_epi32(k, simde_mm512_max_epi32(a, b));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_max_epi32
  #define _mm512_maskz_max_epi32(k, a, b) simde_mm512_maskz_max_epi32(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_max_epu32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_max_epu32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_X86_AVX2_NATIVE)
    r_.m256i[0] = simde_mm256_max_epu32(a_.m256i[0], b_.m256i[0]);
    r_.m256i[1] = simde_mm256_max_epu32(a_.m256i[1], b_.m256i[1]);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
      r_.u32[i] = (a_.u32[i] > b_.u32[i]) ? a_.u32[i] : b_.u32[i];
    }
  #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_max_epu32
  #define _mm512_max_epu32(a, b) simde_mm512_max_epu32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_max_epu32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_max_epu32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_max_epu32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_max_epu32
  #define _mm512_mask_max_epu32(src, k, a, b) simde_mm512_mask_max_epu32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_max_epu32(simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_max_epu32(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi32(k, simde_mm512_max_epu32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_max_epu32
  #define _mm512_maskz_max_epu32(k, a, b) simde_mm512_maskz_max_epu32(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_max_epi64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_max_epi64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a_.i64[i] > b_.i64[i] ? a_.i64[i] : b_.i64[i];
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_max_epi64
  #define _mm512_max_epi64(a, b) simde_mm512_max_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_max_epi64(simde__m512i src, simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_max_epi64(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_max_epi64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_max_epi64
  #define _mm512_mask_max_epi64(src, k, a, b) simde_mm512_mask_max_epi64(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_max_epi64(simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_max_epi64(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_max_epi64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_max_epi64
  #define _mm512_maskz_max_epi64(k, a, b) simde_mm512_maskz_max_epi64(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_max_epu64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_max_epu64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
      r_.u64[i] = (a_.u64[i] > b_.u64[i]) ? a_.u64[i] : b_.u64[i];
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_max_epu64
  #define _mm512_max_epu64(a, b) simde_mm512_max_epu64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_max_epu64(simde__m512i src, simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_max_epu64(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_max_epu64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_max_epu64
  #define _mm512_mask_max_epu64(src, k, a, b) simde_mm512_mask_max_epu64(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_max_epu64(simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_max_epu64(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_max_epu64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_max_epu64
  #define _mm512_maskz_max_epu64(k, a, b) simde_mm512_maskz_max_epu64(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_max_ps (simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_max_ps(a, b);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b);

  #if defined(SIMDE_X86_AVX2_NATIVE)
    r_.m256[0] = simde_mm256_max_ps(a_.m256[0], b_.m256[0]);
    r_.m256[1] = simde_mm256_max_ps(a_.m256[1], b_.m256[1]);
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = a_.f32[i] > b_.f32[i] ? a_.f32[i] : b_.f32[i];
    }
  #endif

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_max_ps
  #define _mm512_max_ps(a, b) simde_mm512_max_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_max_ps(simde__m512 src, simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_max_ps(src, k, a, b);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_max_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_max_ps
  #define _mm512_mask_max_ps(src, k, a, b) simde_mm512_mask_max_ps(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_max_ps(simde__mmask16 k, simde__m512 a, simde__m512 b) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_max_ps(k, a, b);
#else
  return simde_mm512_maskz_mov_ps(k, simde_mm512_max_ps(a, b));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_max_ps
  #define _mm512_maskz_max_ps(k, a, b) simde_mm512_maskz_max_ps(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_max_pd (simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_max_pd(a, b);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = a_.f64[i] > b_.f64[i] ? a_.f64[i] : b_.f64[i];
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_max_pd
  #define _mm512_max_pd(a, b) simde_mm512_max_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_max_pd(simde__m512d src, simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_max_pd(src, k, a, b);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_max_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_max_pd
  #define _mm512_mask_max_pd(src, k, a, b) simde_mm512_mask_max_pd(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_max_pd(simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_max_pd(k, a, b);
  #else
    return simde_mm512_maskz_mov_pd(k, simde_mm512_max_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_max_pd
  #define _mm512_maskz_max_pd(k, a, b) simde_mm512_maskz_max_pd(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mul_ps (simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mul_ps(a, b);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f32 = a_.f32 * b_.f32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256) / sizeof(r_.m256[0])) ; i++) {
        r_.m256[i] = simde_mm256_mul_ps(a_.m256[i], b_.m256[i]);
      }
    #endif

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mul_ps
  #define _mm512_mul_ps(a, b) simde_mm512_mul_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_mul_ps(simde__m512 src, simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_mul_ps(src, k, a, b);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_mul_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_mul_ps
  #define _mm512_mask_mul_ps(src, k, a, b) simde_mm512_mask_mul_ps(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_mul_ps(simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_mul_ps(k, a, b);
  #else
    return simde_mm512_maskz_mov_ps(k, simde_mm512_mul_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_mul_ps
  #define _mm512_maskz_mul_ps(k, a, b) simde_mm512_maskz_mul_ps(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mul_pd (simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mul_pd(a, b);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f64 = a_.f64 * b_.f64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256d) / sizeof(r_.m256d[0])) ; i++) {
        r_.m256d[i] = simde_mm256_mul_pd(a_.m256d[i], b_.m256d[i]);
      }
    #endif

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mul_pd
  #define _mm512_mul_pd(a, b) simde_mm512_mul_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_mul_pd(simde__m512d src, simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_mul_pd(src, k, a, b);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_mul_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_mul_pd
  #define _mm512_mask_mul_pd(src, k, a, b) simde_mm512_mask_mul_pd(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_mul_pd(simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_mul_pd(k, a, b);
  #else
    return simde_mm512_maskz_mov_pd(k, simde_mm512_mul_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_mul_pd
  #define _mm512_maskz_mul_pd(k, a, b) simde_mm512_maskz_mul_pd(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mul_epi32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mul_epi32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_SHUFFLE_VECTOR_)
      simde__m512i_private x;
      __typeof__(r_.i64) ta, tb;

      /* Get even numbered 32-bit values */
      x.i32 = SIMDE_SHUFFLE_VECTOR_(32, 64, a_.i32, b_.i32, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30);
      /* Cast to 64 bits */
      SIMDE_CONVERT_VECTOR_(ta, x.m256i_private[0].i32);
      SIMDE_CONVERT_VECTOR_(tb, x.m256i_private[1].i32);
      r_.i64 = ta * tb;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = HEDLEY_STATIC_CAST(int64_t, a_.i32[i << 1]) * HEDLEY_STATIC_CAST(int64_t, b_.i32[i << 1]);
      }
    #endif
      return simde__m512i_from_private(r_);
    #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mul_epi32
  #define _mm512_mul_epi32(a, b) simde_mm512_mul_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_mul_epi32(simde__m512i src, simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_mul_epi32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_mul_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_mul_epi32
  #define _mm512_mask_mul_epi32(src, k, a, b) simde_mm512_mask_mul_epi32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_mul_epi32(simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_mul_epi32(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_mul_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_mul_epi32
  #define _mm512_maskz_mul_epi32(k, a, b) simde_mm512_maskz_mul_epi32(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mul_epu32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mul_epu32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_CONVERT_VECTOR_) && defined(SIMDE_SHUFFLE_VECTOR_)
      simde__m512i_private x;
      __typeof__(r_.u64) ta, tb;

      x.u32 = SIMDE_SHUFFLE_VECTOR_(32, 64, a_.u32, b_.u32, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30);
      SIMDE_CONVERT_VECTOR_(ta, x.m256i_private[0].u32);
      SIMDE_CONVERT_VECTOR_(tb, x.m256i_private[1].u32);
      r_.u64 = ta * tb;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
        r_.u64[i] = HEDLEY_STATIC_CAST(uint64_t, a_.u32[i << 1]) * HEDLEY_STATIC_CAST(uint64_t, b_.u32[i << 1]);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mul_epu32
  #define _mm512_mul_epu32(a, b) simde_mm512_mul_epu32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_mul_epu32(simde__m512i src, simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_mul_epu32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_mul_epu32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_mul_epu32
  #define _mm512_mask_mul_epu32(src, k, a, b) simde_mm512_mask_mul_epu32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_mul_epu32(simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_mul_epu32(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_mul_epu32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_mul_epu32
  #define _mm512_maskz_mul_epu32(k, a, b) simde_mm512_maskz_mul_epu32(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mullo_epi32 (simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mullo_epi32(a, b);
#else
  simde__m512i_private
    a_ = simde__m512i_to_private(a),
    b_ = simde__m512i_to_private(b),
    r_;

  SIMDE_VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, a_.i32[i] * b_.i32[i]);
  }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mullo_epi32
  #define _mm512_mullo_epi32(a, b) simde_mm512_mullo_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_mullo_epi32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_mask_mullo_epi32(src, k, a, b);
#else
  return simde_mm512_mask_mov_epi32(src, k, simde_mm512_mullo_epi32(a, b));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_mullo_epi32
  #define _mm512_mask_mullo_epi32(src, k, a, b) simde_mm512_mask_mullo_epi32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_mullo_epi32(simde__mmask16 k, simde__m512i a, simde__m512i b) {
#if defined(SIMDE_X86_AVX512F_NATIVE)
  return _mm512_maskz_mullo_epi32(k, a, b);
#else
  return simde_mm512_maskz_mov_epi32(k, simde_mm512_mullo_epi32(a, b));
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_mullo_epi32
  #define _mm512_maskz_mullo_epi32(k, a, b) simde_mm512_maskz_mullo_epi32(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_or_epi32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_or_epi32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = a_.i32 | b_.i32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i32[i] | b_.i32[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_or_epi32
  #define _mm512_or_epi32(a, b) simde_mm512_or_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_or_epi32(simde__m512i src, simde__mmask16 k, simde__m512i v2, simde__m512i v3) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_or_epi32(src, k, v2, v3);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_or_epi32(v2, v3));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_or_epi32
  #define _mm512_mask_or_epi32(src, k, v2, v3) simde_mm512_mask_or_epi32(src, k, v2, v3)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_or_epi32(simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_or_epi32(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi32(k, simde_mm512_or_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_or_epi32
  #define _mm512_maskz_or_epi32(k, a, b) simde_mm512_maskz_or_epi32(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_or_epi64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_or_epi64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 | b_.i64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a_.i64[i] | b_.i64[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_or_epi64
  #define _mm512_or_epi64(a, b) simde_mm512_or_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_or_epi64(simde__m512i src, simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_or_epi64(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_or_epi64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_or_epi64
  #define _mm512_mask_or_epi64(src, k, a, b) simde_mm512_mask_or_epi64(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_or_epi64(simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_or_epi64(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_or_epi64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_or_epi64
  #define _mm512_maskz_or_epi64(k, a, b) simde_mm512_maskz_or_epi64(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_or_si512 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_or_si512(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_X86_AVX2_NATIVE)
      r_.m256i[0] = simde_mm256_or_si256(a_.m256i[0], b_.m256i[0]);
      r_.m256i[1] = simde_mm256_or_si256(a_.m256i[1], b_.m256i[1]);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = a_.i32f | b_.i32f;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32f[i] = a_.i32f[i] | b_.i32f[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_or_si512
  #define _mm512_or_si512(a, b) simde_mm512_or_si512(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_permutexvar_epi32 (simde__m512i idx, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_permutexvar_epi32(idx, a);
  #else
    simde__m512i_private
      idx_ = simde__m512i_to_private(idx),
      a_ = simde__m512i_to_private(a),
      r_;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a_.i32[idx_.i32[i] & 0x0F];
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_permutexvar_epi32
  #define _mm512_permutexvar_epi32(idx, a) simde_mm512_permutexvar_epi32(idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_permutexvar_epi32 (simde__m512i src, simde__mmask16 k, simde__m512i idx, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_permutexvar_epi32(src, k, idx, a);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_permutexvar_epi32(idx, a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_permutexvar_epi32
  #define _mm512_mask_permutexvar_epi32(src, k, idx, a) simde_mm512_mask_permutexvar_epi32(src, k, idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_permutexvar_epi32 (simde__mmask16 k, simde__m512i idx, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_permutexvar_epi32(k, idx, a);
  #else
    return simde_mm512_maskz_mov_epi32(k, simde_mm512_permutexvar_epi32(idx, a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_permutexvar_epi32
  #define _mm512_maskz_permutexvar_epi32(k, idx, a) simde_mm512_maskz_permutexvar_epi32(k, idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_permutexvar_epi64 (simde__m512i idx, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_permutexvar_epi64(idx, a);
  #else
    simde__m512i_private
      idx_ = simde__m512i_to_private(idx),
      a_ = simde__m512i_to_private(a),
      r_;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a_.i64[idx_.i64[i] & 7];
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_permutexvar_epi64
  #define _mm512_permutexvar_epi64(idx, a) simde_mm512_permutexvar_epi64(idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_permutexvar_epi64 (simde__m512i src, simde__mmask8 k, simde__m512i idx, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_permutexvar_epi64(src, k, idx, a);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_permutexvar_epi64(idx, a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_permutexvar_epi64
  #define _mm512_mask_permutexvar_epi64(src, k, idx, a) simde_mm512_mask_permutexvar_epi64(src, k, idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_permutexvar_epi64 (simde__mmask8 k, simde__m512i idx, simde__m512i a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_permutexvar_epi64(k, idx, a);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_permutexvar_epi64(idx, a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_permutexvar_epi64
  #define _mm512_maskz_permutexvar_epi64(k, idx, a) simde_mm512_maskz_permutexvar_epi64(k, idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_permutexvar_pd (simde__m512i idx, simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_permutexvar_pd(idx, a);
  #else
    simde__m512i_private idx_ = simde__m512i_to_private(idx);
    simde__m512d_private
      a_ = simde__m512d_to_private(a),
      r_;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = a_.f64[idx_.i64[i] & 7];
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_permutexvar_pd
  #define _mm512_permutexvar_pd(idx, a) simde_mm512_permutexvar_pd(idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_permutexvar_pd (simde__m512d src, simde__mmask8 k, simde__m512i idx, simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_permutexvar_pd(src, k, idx, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_permutexvar_pd(idx, a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_permutexvar_pd
  #define _mm512_mask_permutexvar_pd(src, k, idx, a) simde_mm512_mask_permutexvar_pd(src, k, idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_permutexvar_pd (simde__mmask8 k, simde__m512i idx, simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_permutexvar_pd(k, idx, a);
  #else
    return simde_mm512_maskz_mov_pd(k, simde_mm512_permutexvar_pd(idx, a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_permutexvar_pd
  #define _mm512_maskz_permutexvar_pd(k, idx, a) simde_mm512_maskz_permutexvar_pd(k, idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_permutexvar_ps (simde__m512i idx, simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_permutexvar_ps(idx, a);
  #else
    simde__m512i_private idx_ = simde__m512i_to_private(idx);
    simde__m512_private
      a_ = simde__m512_to_private(a),
      r_;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = a_.f32[idx_.i32[i] & 0x0F];
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_permutexvar_ps
  #define _mm512_permutexvar_ps(idx, a) simde_mm512_permutexvar_ps(idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_permutexvar_ps (simde__m512 src, simde__mmask16 k, simde__m512i idx, simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_permutexvar_ps(src, k, idx, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_permutexvar_ps(idx, a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_permutexvar_ps
  #define _mm512_mask_permutexvar_ps(src, k, idx, a) simde_mm512_mask_permutexvar_ps(src, k, idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_permutexvar_ps (simde__mmask16 k, simde__m512i idx, simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_permutexvar_ps(k, idx, a);
  #else
    return simde_mm512_maskz_mov_ps(k, simde_mm512_permutexvar_ps(idx, a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_permutexvar_ps
  #define _mm512_maskz_permutexvar_ps(k, idx, a) simde_mm512_maskz_permutexvar_ps(k, idx, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_permutex2var_epi32 (simde__m512i a, simde__m512i idx, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_permutex2var_epi32(a, idx, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      idx_ = simde__m512i_to_private(idx),
      b_ = simde__m512i_to_private(b),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = ((idx_.i32[i] & 0x10) ? b_ : a_).i32[idx_.i32[i] & 0x0F];
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_permutex2var_epi32
  #define _mm512_permutex2var_epi32(a, idx, b) simde_mm512_permutex2var_epi32(a, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_permutex2var_epi32 (simde__m512i a, simde__mmask16 k, simde__m512i idx, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_permutex2var_epi32(a, k, idx, b);
  #else
    return simde_mm512_mask_mov_epi32(a, k, simde_mm512_permutex2var_epi32(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_permutex2var_epi32
#define _mm512_mask_permutex2var_epi32(a, k, idx, b) simde_mm512_mask_permutex2var_epi32(a, k, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask2_permutex2var_epi32 (simde__m512i a, simde__m512i idx, simde__mmask16 k, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask2_permutex2var_epi32(a, idx, k, b);
  #else
    return simde_mm512_mask_mov_epi32(idx, k, simde_mm512_permutex2var_epi32(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask2_permutex2var_epi32
#define _mm512_mask2_permutex2var_epi32(a, idx, k, b) simde_mm512_mask2_permutex2var_epi32(a, idx, k, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_permutex2var_epi32 (simde__mmask16 k, simde__m512i a, simde__m512i idx, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_permutex2var_epi32(k, a, idx, b);
  #else
    return simde_mm512_maskz_mov_epi32(k, simde_mm512_permutex2var_epi32(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_permutex2var_epi32
#define _mm512_maskz_permutex2var_epi32(k, a, idx, b) simde_mm512_maskz_permutex2var_epi32(k, a, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_permutex2var_epi64 (simde__m512i a, simde__m512i idx, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_permutex2var_epi64(a, idx, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      idx_ = simde__m512i_to_private(idx),
      b_ = simde__m512i_to_private(b),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = ((idx_.i64[i] & 0x08) ? b_ : a_).i64[idx_.i64[i] & 0x07];
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_permutex2var_epi64
  #define _mm512_permutex2var_epi64(a, idx, b) simde_mm512_permutex2var_epi64(a, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_permutex2var_epi64 (simde__m512i a, simde__mmask8 k, simde__m512i idx, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_permutex2var_epi64(a, k, idx, b);
  #else
    return simde_mm512_mask_mov_epi64(a, k, simde_mm512_permutex2var_epi64(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_permutex2var_epi64
#define _mm512_mask_permutex2var_epi64(a, k, idx, b) simde_mm512_mask_permutex2var_epi64(a, k, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask2_permutex2var_epi64 (simde__m512i a, simde__m512i idx, simde__mmask8 k, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask2_permutex2var_epi64(a, idx, k, b);
  #else
    return simde_mm512_mask_mov_epi64(idx, k, simde_mm512_permutex2var_epi64(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask2_permutex2var_epi64
#define _mm512_mask2_permutex2var_epi64(a, idx, k, b) simde_mm512_mask2_permutex2var_epi64(a, idx, k, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_permutex2var_epi64 (simde__mmask8 k, simde__m512i a, simde__m512i idx, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_permutex2var_epi64(k, a, idx, b);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_permutex2var_epi64(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_permutex2var_epi64
#define _mm512_maskz_permutex2var_epi64(k, a, idx, b) simde_mm512_maskz_permutex2var_epi64(k, a, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_permutex2var_pd (simde__m512d a, simde__m512i idx, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_permutex2var_pd(a, idx, b);
  #else
    simde__m512i_private idx_ = simde__m512i_to_private(idx);
    simde__m512d_private
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = ((idx_.i64[i] & 0x08) ? b_ : a_).f64[idx_.i64[i] & 0x07];
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_permutex2var_pd
  #define _mm512_permutex2var_pd(a, idx, b) simde_mm512_permutex2var_pd(a, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_permutex2var_pd (simde__m512d a, simde__mmask8 k, simde__m512i idx, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_permutex2var_pd(a, k, idx, b);
  #else
    return simde_mm512_mask_mov_pd(a, k, simde_mm512_permutex2var_pd(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_permutex2var_pd
#define _mm512_mask_permutex2var_pd(a, k, idx, b) simde_mm512_mask_permutex2var_pd(a, k, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask2_permutex2var_pd (simde__m512d a, simde__m512i idx, simde__mmask8 k, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask2_permutex2var_pd(a, idx, k, b);
  #else
    return simde_mm512_mask_mov_pd(simde_mm512_castsi512_pd(idx), k, simde_mm512_permutex2var_pd(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask2_permutex2var_pd
#define _mm512_mask2_permutex2var_pd(a, idx, k, b) simde_mm512_mask2_permutex2var_pd(a, idx, k, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_permutex2var_pd (simde__mmask8 k, simde__m512d a, simde__m512i idx, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_permutex2var_pd(k, a, idx, b);
  #else
    return simde_mm512_maskz_mov_pd(k, simde_mm512_permutex2var_pd(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_permutex2var_pd
#define _mm512_maskz_permutex2var_pd(k, a, idx, b) simde_mm512_maskz_permutex2var_pd(k, a, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_permutex2var_ps (simde__m512 a, simde__m512i idx, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_permutex2var_ps(a, idx, b);
  #else
    simde__m512i_private idx_ = simde__m512i_to_private(idx);
    simde__m512_private
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b),
      r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = ((idx_.i32[i] & 0x10) ? b_ : a_).f32[idx_.i32[i] & 0x0F];
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_permutex2var_ps
  #define _mm512_permutex2var_ps(a, idx, b) simde_mm512_permutex2var_ps(a, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_permutex2var_ps (simde__m512 a, simde__mmask16 k, simde__m512i idx, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask_permutex2var_ps(a, k, idx, b);
  #else
    return simde_mm512_mask_mov_ps(a, k, simde_mm512_permutex2var_ps(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_permutex2var_ps
#define _mm512_mask_permutex2var_ps(a, k, idx, b) simde_mm512_mask_permutex2var_ps(a, k, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask2_permutex2var_ps (simde__m512 a, simde__m512i idx, simde__mmask16 k, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_mask2_permutex2var_ps(a, idx, k, b);
  #else
    return simde_mm512_mask_mov_ps(simde_mm512_castsi512_ps(idx), k, simde_mm512_permutex2var_ps(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask2_permutex2var_ps
#define _mm512_mask2_permutex2var_ps(a, idx, k, b) simde_mm512_mask2_permutex2var_ps(a, idx, k, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_permutex2var_ps (simde__mmask16 k, simde__m512 a, simde__m512i idx, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512BW_NATIVE)
    return _mm512_maskz_permutex2var_ps(k, a, idx, b);
  #else
    return simde_mm512_maskz_mov_ps(k, simde_mm512_permutex2var_ps(a, idx, b));
  #endif
}
#if defined(SIMDE_X86_AVX512BW_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_permutex2var_ps
#define _mm512_maskz_permutex2var_ps(k, a, idx, b) simde_mm512_maskz_permutex2var_ps(k, a, idx, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_sqrt_ps (simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_sqrt_ps(a);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a);

    #if defined(SIMDE_X86_AVX_NATIVE)
      r_.m256[0] = simde_mm256_sqrt_ps(a_.m256[0]);
      r_.m256[1] = simde_mm256_sqrt_ps(a_.m256[1]);
    #elif defined(simde_math_sqrtf)
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
        r_.f32[i] = simde_math_sqrtf(a_.f32[i]);
      }
    #else
      HEDLEY_UNREACHABLE();
    #endif

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#  define _mm512_sqrt_ps(a) simde_mm512_sqrt_ps(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_sqrt_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_sqrt_ps(src, k, a);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_sqrt_ps(a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_sqrt_ps
  #define _mm512_mask_sqrt_ps(src, k, a) simde_mm512_mask_sqrt_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_sqrt_pd (simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_sqrt_pd(a);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a);

    #if defined(SIMDE_X86_AVX_NATIVE)
      r_.m256d[0] = simde_mm256_sqrt_pd(a_.m256d[0]);
      r_.m256d[1] = simde_mm256_sqrt_pd(a_.m256d[1]);
    #elif defined(simde_math_sqrt)
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
        r_.f64[i] = simde_math_sqrt(a_.f64[i]);
      }
    #else
      HEDLEY_UNREACHABLE();
    #endif

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
#  define _mm512_sqrt_pd(a) simde_mm512_sqrt_pd(a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_sqrt_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_sqrt_pd(src, k, a);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_sqrt_pd(a));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_sqrt_pd
  #define _mm512_mask_sqrt_pd(src, k, a) simde_mm512_mask_sqrt_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_sub_epi32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_sub_epi32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = a_.i32 - b_.i32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_sub_epi32(a_.m256i[i], b_.m256i[i]);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_sub_epi32
  #define _mm512_sub_epi32(a, b) simde_mm512_sub_epi32(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_sub_epi32 (simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_sub_epi32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_sub_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_sub_epi32
  #define _mm512_mask_sub_epi32(src, k, a, b) simde_mm512_mask_sub_epi32(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_sub_epi32(simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_sub_epi32(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi32(k, simde_mm512_sub_epi32(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_sub_epi32
  #define _mm512_maskz_sub_epi32(k, a, b) simde_mm512_maskz_sub_epi32(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_sub_epi64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_sub_epi64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 - b_.i64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_sub_epi64(a_.m256i[i], b_.m256i[i]);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_sub_epi64
  #define _mm512_sub_epi64(a, b) simde_mm512_sub_epi64(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_sub_epi64 (simde__m512i src, simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_sub_epi64(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_sub_epi64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_sub_epi64
  #define _mm512_mask_sub_epi64(src, k, a, b) simde_mm512_mask_sub_epi64(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_sub_epi64(simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_sub_epi64(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_sub_epi64(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_sub_epi64
  #define _mm512_maskz_sub_epi64(k, a, b) simde_mm512_maskz_sub_epi64(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_sub_ps (simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_sub_ps(a, b);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f32 = a_.f32 - b_.f32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256) / sizeof(r_.m256[0])) ; i++) {
        r_.m256[i] = simde_mm256_sub_ps(a_.m256[i], b_.m256[i]);
      }
    #endif

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_sub_ps
  #define _mm512_sub_ps(a, b) simde_mm512_sub_ps(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_sub_ps (simde__m512 src, simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_sub_ps(src, k, a, b);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_sub_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_sub_ps
  #define _mm512_mask_sub_ps(src, k, a, b) simde_mm512_mask_sub_ps(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_sub_ps(simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_sub_ps(k, a, b);
  #else
    return simde_mm512_maskz_mov_ps(k, simde_mm512_sub_ps(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_sub_ps
  #define _mm512_maskz_sub_ps(k, a, b) simde_mm512_maskz_sub_ps(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_sub_pd (simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_sub_pd(a, b);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f64 = a_.f64 - b_.f64;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256d) / sizeof(r_.m256d[0])) ; i++) {
        r_.m256d[i] = simde_mm256_sub_pd(a_.m256d[i], b_.m256d[i]);
      }
    #endif

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_sub_pd
  #define _mm512_sub_pd(a, b) simde_mm512_sub_pd(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_sub_pd (simde__m512d src, simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_sub_pd(src, k, a, b);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_sub_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_sub_pd
  #define _mm512_mask_sub_pd(src, k, a, b) simde_mm512_mask_sub_pd(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_sub_pd(simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_sub_pd(k, a, b);
  #else
    return simde_mm512_maskz_mov_pd(k, simde_mm512_sub_pd(a, b));
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_sub_pd
  #define _mm512_maskz_sub_pd(k, a, b) simde_mm512_maskz_sub_pd(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_slli_epi32 (simde__m512i a, unsigned int imm8) {
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a);

  /* The Intel Intrinsics Guide says that only the 8 LSBits of imm8 are
   * used.  In this case we should do "imm8 &= 0xff".  However in
   * practice all bits are used. */
  if (imm8 > 31) {
    simde_memset(&r_, 0, sizeof(r_));
  } else {
    #if defined(SIMDE_X86_AVX2_NATIVE)
      r_.m256i[0] = simde_mm256_slli_epi32(a_.m256i[0], HEDLEY_STATIC_CAST(int, imm8));
      r_.m256i[1] = simde_mm256_slli_epi32(a_.m256i[1], HEDLEY_STATIC_CAST(int, imm8));
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i[0] = simde_mm_slli_epi32(a_.m128i[0], HEDLEY_STATIC_CAST(int, imm8));
      r_.m128i[1] = simde_mm_slli_epi32(a_.m128i[1], HEDLEY_STATIC_CAST(int, imm8));
      r_.m128i[2] = simde_mm_slli_epi32(a_.m128i[2], HEDLEY_STATIC_CAST(int, imm8));
      r_.m128i[3] = simde_mm_slli_epi32(a_.m128i[3], HEDLEY_STATIC_CAST(int, imm8));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.u32 = a_.u32 << imm8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
        r_.u32[i] = a_.u32[i] << imm8;
      }
    #endif
  }

  return simde__m512i_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_slli_epi32(a, imm8) SIMDE_BUG_IGNORE_SIGN_CONVERSION(_mm512_slli_epi32(a, imm8))
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_slli_epi32
  #define _mm512_slli_epi32(a, imm8) simde_mm512_slli_epi32(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_slli_epi64 (simde__m512i a, unsigned int imm8) {
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a);

  /* The Intel Intrinsics Guide says that only the 8 LSBits of imm8 are
   * used.  In this case we should do "imm8 &= 0xff".  However in
   * practice all bits are used. */
  if (imm8 > 63) {
    simde_memset(&r_, 0, sizeof(r_));
  } else {
    #if defined(SIMDE_X86_AVX2_NATIVE)
      r_.m256i[0] = simde_mm256_slli_epi64(a_.m256i[0], HEDLEY_STATIC_CAST(int, imm8));
      r_.m256i[1] = simde_mm256_slli_epi64(a_.m256i[1], HEDLEY_STATIC_CAST(int, imm8));
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i[0] = simde_mm_slli_epi64(a_.m128i[0], HEDLEY_STATIC_CAST(int, imm8));
      r_.m128i[1] = simde_mm_slli_epi64(a_.m128i[1], HEDLEY_STATIC_CAST(int, imm8));
      r_.m128i[2] = simde_mm_slli_epi64(a_.m128i[2], HEDLEY_STATIC_CAST(int, imm8));
      r_.m128i[3] = simde_mm_slli_epi64(a_.m128i[3], HEDLEY_STATIC_CAST(int, imm8));
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
      r_.u64 = a_.u64 << imm8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
        r_.u64[i] = a_.u64[i] << imm8;
      }
    #endif
  }

  return simde__m512i_from_private(r_);
}
#if defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_slli_epi64(a, imm8) _mm512_slli_epi64(a, imm8)
#endif
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_slli_epi64
  #define _mm512_slli_epi64(a, imm8) simde_mm512_slli_epi64(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_srli_epi32 (simde__m512i a, unsigned int imm8) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return SIMDE_BUG_IGNORE_SIGN_CONVERSION(_mm512_srli_epi32(a, imm8));
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a);

    #if defined(SIMDE_X86_AVX2_NATIVE)
      r_.m256i[0] = simde_mm256_srli_epi32(a_.m256i[0], HEDLEY_STATIC_CAST(int, imm8));
      r_.m256i[1] = simde_mm256_srli_epi32(a_.m256i[1], HEDLEY_STATIC_CAST(int, imm8));
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i[0] = simde_mm_srli_epi32(a_.m128i[0], HEDLEY_STATIC_CAST(int, imm8));
      r_.m128i[1] = simde_mm_srli_epi32(a_.m128i[1], HEDLEY_STATIC_CAST(int, imm8));
      r_.m128i[2] = simde_mm_srli_epi32(a_.m128i[2], HEDLEY_STATIC_CAST(int, imm8));
      r_.m128i[3] = simde_mm_srli_epi32(a_.m128i[3], HEDLEY_STATIC_CAST(int, imm8));
    #else
      if (imm8 > 31) {
        simde_memset(&r_, 0, sizeof(r_));
      } else {
        #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
          r_.u32 = a_.u32 >> imm8;
        #else
          SIMDE_VECTORIZE
          for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
            r_.u32[i] = a_.u32[i] >> imm8;
          }
        #endif
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_srli_epi32
  #define _mm512_srli_epi32(a, imm8) simde_mm512_srli_epi32(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_srli_epi64 (simde__m512i a, unsigned int imm8) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_srli_epi64(a, imm8);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a);

    #if defined(SIMDE_X86_AVX2_NATIVE)
      r_.m256i[0] = simde_mm256_srli_epi64(a_.m256i[0], HEDLEY_STATIC_CAST(int, imm8));
      r_.m256i[1] = simde_mm256_srli_epi64(a_.m256i[1], HEDLEY_STATIC_CAST(int, imm8));
    #elif defined(SIMDE_X86_SSE2_NATIVE)
      r_.m128i[0] = simde_mm_srli_epi64(a_.m128i[0], HEDLEY_STATIC_CAST(int, imm8));
      r_.m128i[1] = simde_mm_srli_epi64(a_.m128i[1], HEDLEY_STATIC_CAST(int, imm8));
      r_.m128i[2] = simde_mm_srli_epi64(a_.m128i[2], HEDLEY_STATIC_CAST(int, imm8));
      r_.m128i[3] = simde_mm_srli_epi64(a_.m128i[3], HEDLEY_STATIC_CAST(int, imm8));
    #else
      /* The Intel Intrinsics Guide says that only the 8 LSBits of imm8 are
      * used.  In this case we should do "imm8 &= 0xff" here.  However in
      * practice all bits are used. */
      if (imm8 > 63) {
        simde_memset(&r_, 0, sizeof(r_));
      } else {
        #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
          r_.u64 = a_.u64 >> imm8;
        #else
          SIMDE_VECTORIZE
          for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
            r_.u64[i] = a_.u64[i] >> imm8;
          }
        #endif
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_srli_epi64
  #define _mm512_srli_epi64(a, imm8) simde_mm512_srli_epi64(a, imm8)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_mask_test_epi32_mask (simde__mmask16 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_test_epi32_mask(k1, a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask16 r = 0;

    SIMDE_VECTORIZE_REDUCTION(|:r)
    for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
      r |= HEDLEY_STATIC_CAST(simde__mmask16, !!(a_.i32[i] & b_.i32[i]) << i);
    }

    return r & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_test_epi32_mask
  #define _mm512_mask_test_epi32_mask(k1, a, b) simde_mm512_mask_test_epi32_mask(k1, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_mask_test_epi64_mask (simde__mmask8 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_test_epi64_mask(k1, a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask8 r = 0;

    SIMDE_VECTORIZE_REDUCTION(|:r)
    for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
      r |= !!(a_.i64[i] & b_.i64[i]) << i;
    }

    return r & k1;
  #endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_test_epi64_mask
  #define _mm512_mask_test_epi64_mask(k1, a, b) simde_mm512_mask_test_epi64_mask(k1, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_xor_si512 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_xor_si512(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_X86_AVX2_NATIVE)
    r_.m256i[0] = simde_mm256_xor_si256(a_.m256i[0], b_.m256i[0]);
    r_.m256i[1] = simde_mm256_xor_si256(a_.m256i[1], b_.m256i[1]);
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    r_.m128i[0] = simde_mm_xor_si128(a_.m128i[0], b_.m128i[0]);
    r_.m128i[1] = simde_mm_xor_si128(a_.m128i[1], b_.m128i[1]);
    r_.m128i[2] = simde_mm_xor_si128(a_.m128i[2], b_.m128i[2]);
    r_.m128i[3] = simde_mm_xor_si128(a_.m128i[3], b_.m128i[3]);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i32f = a_.i32f ^ b_.i32f;
  #else
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
      r_.i32f[i] = a_.i32f[i] ^ b_.i32f[i];
    }
  #endif

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_xor_si512
  #define _mm512_xor_si512(a, b) simde_mm512_xor_si512(a, b)
#endif

SIMDE_END_DECLS_

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512F_H) */
