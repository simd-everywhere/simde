/* Permission is hereby granted, free of charge, to any person
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
 */

#if !defined(SIMDE__AVX512F_H)
#  if !defined(SIMDE__AVX512F_H)
#    define SIMDE__AVX512F_H
#  endif
#  include "avx2.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

#  if defined(SIMDE_ARCH_X86_AVX512F) && !defined(SIMDE_AVX512F_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_AVX512F_NATIVE
#  elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_AVX512F_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_AVX512F_NEON
#  elif defined(SIMDE_ARCH_POWER_ALTIVEC)
#    define SIMDE_AVX512F_POWER_ALTIVEC
#  endif

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
#    if defined(SIMDE_AVX512F_NATIVE)
#      undef SIMDE_AVX512F_NATIVE
#      pragma message("Native AVX-512 support requires MSVC 2017 or later.  See comment above (in code) for details.")
#    endif
#    define SIMDE_AVX512_ALIGN SIMDE_ALIGN(32)
#  else
#    define SIMDE_AVX512_ALIGN SIMDE_ALIGN(64)
#  endif

#  if defined(SIMDE_AVX512F_NATIVE)
#    include <immintrin.h>
#  endif

#  if defined(SIMDE_AVX512F_POWER_ALTIVEC)
#    include <altivec.h>
#  endif

SIMDE__BEGIN_DECLS

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
  #if defined(SIMDE__HAVE_INT128)
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
  #if defined(SIMDE__HAVE_INT128)
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

#if defined(SIMDE_AVX512F_NATIVE)
  SIMDE_AVX512_ALIGN __m512         n;
#elif defined(SIMDE_ARCH_POWER_ALTIVEC)
  SIMDE_ALIGN(16) vector unsigned char      altivec_u8[4];
  SIMDE_ALIGN(16) vector unsigned short     altivec_u16[4];
  SIMDE_ALIGN(16) vector unsigned int       altivec_u32[4];
  SIMDE_ALIGN(16) vector unsigned long long altivec_u64[4];
  SIMDE_ALIGN(16) vector signed char        altivec_i8[4];
  SIMDE_ALIGN(16) vector signed short       altivec_i16[4];
  SIMDE_ALIGN(16) vector signed int         altivec_i32[4];
  SIMDE_ALIGN(16) vector signed long long   altivec_i64[4];
  SIMDE_ALIGN(16) vector float              altivec_f32[4];
  SIMDE_ALIGN(16) vector double             altivec_f64[4];
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
  #if defined(SIMDE__HAVE_INT128)
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
  #if defined(SIMDE__HAVE_INT128)
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

#if defined(SIMDE_AVX512F_NATIVE)
  SIMDE_AVX512_ALIGN __m512d        n;
#elif defined(SIMDE_ARCH_POWER_ALTIVEC)
  SIMDE_ALIGN(16) vector unsigned char      altivec_u8[4];
  SIMDE_ALIGN(16) vector unsigned short     altivec_u16[4];
  SIMDE_ALIGN(16) vector unsigned int       altivec_u32[4];
  SIMDE_ALIGN(16) vector unsigned long long altivec_u64[4];
  SIMDE_ALIGN(16) vector signed char        altivec_i8[4];
  SIMDE_ALIGN(16) vector signed short       altivec_i16[4];
  SIMDE_ALIGN(16) vector signed int         altivec_i32[4];
  SIMDE_ALIGN(16) vector signed long long   altivec_i64[4];
  SIMDE_ALIGN(16) vector float              altivec_f32[4];
  SIMDE_ALIGN(16) vector double             altivec_f64[4];
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
  #if defined(SIMDE__HAVE_INT128)
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
  #if defined(SIMDE__HAVE_INT128)
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

#if defined(SIMDE_AVX512F_NATIVE)
  SIMDE_AVX512_ALIGN __m512i        n;
#elif defined(SIMDE_ARCH_POWER_ALTIVEC)
  SIMDE_ALIGN(16) vector unsigned char      altivec_u8[4];
  SIMDE_ALIGN(16) vector unsigned short     altivec_u16[4];
  SIMDE_ALIGN(16) vector unsigned int       altivec_u32[4];
  SIMDE_ALIGN(16) vector unsigned long long altivec_u64[4];
  SIMDE_ALIGN(16) vector signed char        altivec_i8[4];
  SIMDE_ALIGN(16) vector signed short       altivec_i16[4];
  SIMDE_ALIGN(16) vector signed int         altivec_i32[4];
  SIMDE_ALIGN(16) vector signed long long   altivec_i64[4];
  SIMDE_ALIGN(16) vector float              altivec_f32[4];
  SIMDE_ALIGN(16) vector double             altivec_f64[4];
#endif
} simde__m512i_private;

#if defined(SIMDE_AVX512F_NATIVE)
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

  typedef uint_fast8_t simde__mmask8;
  typedef uint_fast16_t simde__mmask16;
  typedef uint_fast32_t simde__mmask32;
  typedef uint_fast64_t simde__mmask64;
#endif

#if !defined(SIMDE_AVX512F_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
  #define SIMDE_AVX512F_ENABLE_NATIVE_ALIASES
  typedef simde__m512 __m512;
  typedef simde__m512i __m512i;
  typedef simde__m512d __m512d;
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

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde__m512_from_private(simde__m512_private v) {
  simde__m512 r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m512_private
simde__m512_to_private(simde__m512 v) {
  simde__m512_private r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde__m512i_from_private(simde__m512i_private v) {
  simde__m512i r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i_private
simde__m512i_to_private(simde__m512i v) {
  simde__m512i_private r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde__m512d_from_private(simde__m512d_private v) {
  simde__m512d r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d_private
simde__m512d_to_private(simde__m512d v) {
  simde__m512d_private r;
  simde_memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__mmask16
simde__m512i_private_to_mmask16 (simde__m512i_private a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    HEDLEY_UNREACHABLE_RETURN(0);
  #else
    simde__mmask16 r = 0;

    /* Note: using addition instead of a bitwise or for the reduction
       seems like it should improve things since hardware support for
       horizontal addition is better than bitwise or.  However, GCC
       generates the same code, and clang is actually a bit slower.
       I suspect this can be optimized quite a bit, and this function
       is probably going to be pretty hot. */
    SIMDE__VECTORIZE_REDUCTION(|:r)
    for (size_t i = 0 ; i < (sizeof(a.i32) / sizeof(a.i32[0])) ; i++) {
      r |= !!(a.i32[i]) << i;
    }

    return r;
  #endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__mmask8
simde__m512i_private_to_mmask8 (simde__m512i_private a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    HEDLEY_UNREACHABLE_RETURN(0);
  #else
    simde__mmask8 r = 0;
    SIMDE__VECTORIZE_REDUCTION(|:r)
    for (size_t i = 0 ; i < (sizeof(a.i64) / sizeof(a.i64[0])) ; i++) {
      r |= !!(a.i64[i]) << i;
    }

    return r;
  #endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde__m512i_from_mmask16 (simde__mmask16 k) {
  #if defined(SIMDE_AVX512F_NATIVE)
    /* Should never be reached. */
    return _mm512_mask_mov_epi32(_mm512_setzero_epi32(), k, _mm512_set1_epi32(~INT32_C(0)));
  #else
    simde__m512i_private r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = (k & (1 << i)) ? ~INT32_C(0) : INT32_C(0);
    }

    return simde__m512i_from_private(r_);
  #endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_castpd_ps (simde__m512d a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castpd_ps(a);
  #else
    simde__m512 r;
    memcpy(&r, &a, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castpd_ps(a) simde_mm512_castpd_ps(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_castpd_si512 (simde__m512d a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castpd_si512(a);
  #else
    simde__m512i r;
    memcpy(&r, &a, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castpd_si512(a) simde_mm512_castpd_si512(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_castps_pd (simde__m512 a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castps_pd(a);
  #else
    simde__m512d r;
    memcpy(&r, &a, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castps_pd(a) simde_mm512_castps_pd(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_castps_si512 (simde__m512 a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castps_si512(a);
  #else
    simde__m512i r;
    memcpy(&r, &a, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castps_si512(a) simde_mm512_castps_si512(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_castsi512_ps (simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castsi512_ps(a);
  #else
    simde__m512 r;
    memcpy(&r, &a, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castsi512_ps(a) simde_mm512_castsi512_ps(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_castsi512_pd (simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castsi512_pd(a);
  #else
    simde__m512d r;
    memcpy(&r, &a, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castsi512_pd(a) simde_mm512_castsi512_pd(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_castpd128_pd512 (simde__m128d a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castpd128_pd512(a);
  #else
    simde__m512d_private r_;
    r_.m128d[0] = a;
    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castpd128_pd512(a) simde_mm512_castpd128_pd512(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_castpd256_pd512 (simde__m256d a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castpd256_pd512(a);
  #else
    simde__m512d_private r_;
    r_.m256d[0] = a;
    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castpd256_pd512(a) simde_mm512_castpd256_pd512(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128d
simde_mm512_castpd512_pd128 (simde__m512d a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castpd512_pd128(a);
  #else
    simde__m512d_private a_ = simde__m512d_to_private(a);
    return a_.m128d[0];
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castpd512_pd128(a) simde_mm512_castpd512_pd128(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256d
simde_mm512_castpd512_pd256 (simde__m512d a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castpd512_pd256(a);
  #else
    simde__m512d_private a_ = simde__m512d_to_private(a);
    return a_.m256d[0];
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castpd512_pd256(a) simde_mm512_castpd512_pd256(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_castps128_ps512 (simde__m128 a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castps128_ps512(a);
  #else
    simde__m512_private r_;
    r_.m128[0] = a;
    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castps128_ps512(a) simde_mm512_castps128_ps512(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_castps256_ps512 (simde__m256 a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castps256_ps512(a);
  #else
    simde__m512_private r_;
    r_.m256[0] = a;
    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castps256_ps512(a) simde_mm512_castps256_ps512(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128
simde_mm512_castps512_ps128 (simde__m512 a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castps512_ps128(a);
  #else
    simde__m512_private a_ = simde__m512_to_private(a);
    return a_.m128[0];
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castps512_ps128(a) simde_mm512_castps512_ps128(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256
simde_mm512_castps512_ps256 (simde__m512 a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castps512_ps256(a);
  #else
    simde__m512_private a_ = simde__m512_to_private(a);
    return a_.m256[0];
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castps512_ps256(a) simde_mm512_castps512_ps256(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_castsi128_si512 (simde__m128i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castsi128_si512(a);
  #else
    simde__m512i_private r_;
    r_.m128i[0] = a;
    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castsi128_si512(a) simde_mm512_castsi128_si512(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_castsi256_si512 (simde__m256i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castsi256_si512(a);
  #else
    simde__m512i_private r_;
    r_.m256i[0] = a;
    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castsi256_si512(a) simde_mm512_castsi256_si512(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_castsi512_si128 (simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castsi512_si128(a);
  #else
    simde__m512i_private a_ = simde__m512i_to_private(a);
    return a_.m128i[0];
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castsi512_si128(a) simde_mm512_castsi512_si128(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_castsi512_si256 (simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_castsi512_si256(a);
  #else
    simde__m512i_private a_ = simde__m512i_to_private(a);
    return a_.m256i[0];
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_castsi512_si256(a) simde_mm512_castsi512_si256(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_set_epi8(e63, e62, e61, e60, e59, e58, e57, e56, e55, e54, e53, e52, e51, e50, e49, e48, e47, e46, e45, e44, e43, e42, e41, e40, e39, e38, e37, e36, e35, e34, e33, e32, e31, e30, e29, e28, e27, e26, e25, e24, e23, e22, e21, e20, e19, e18, e17, e16, e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_epi8(e63, e62, e61, e60, e59, e58, e57, e56, e55, e54, e53, e52, e51, e50, e49, e48, e47, e46, e45, e44, e43, e42, e41, e40, e39, e38, e37, e36, e35, e34, e33, e32, e31, e30, e29, e28, e27, e26, e25, e24, e23, e22, e21, e20, e19, e18, e17, e16, e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_set_epi16(e31, e30, e29, e28, e27, e26, e25, e24, e23, e22, e21, e20, e19, e18, e17, e16, e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_epi16(e31, e30, e29, e28, e27, e26, e25, e24, e23, e22, e21, e20, e19, e18, e17, e16, e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_set_epi32(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_epi32(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_set_epi64(e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_epi64(e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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

SIMDE__FUNCTION_ATTRIBUTES
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

SIMDE__FUNCTION_ATTRIBUTES
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

SIMDE__FUNCTION_ATTRIBUTES
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

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_set_ps(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_ps(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_set_pd(e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_pd(e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_set1_epi8 (int8_t a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_set1_epi8(a);
  #else
    simde__m512i_private r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = a;
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_set1_epi8(a) simde_mm512_set1_epi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_set1_epi16 (int16_t a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_set1_epi16(a);
  #else
    simde__m512i_private r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
      r_.i16[i] = a;
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_set1_epi16(a) simde_mm512_set1_epi16(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_set1_epi32 (int32_t a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_set1_epi32(a);
  #else
    simde__m512i_private r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = a;
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_set1_epi32(a) simde_mm512_set1_epi32(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_set1_epi64 (int64_t a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_set1_epi64(a);
  #else
    simde__m512i_private r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = a;
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_set1_epi64(a) simde_mm512_set1_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_set1_epu8 (uint8_t a) {
  simde__m512i_private r_;

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    r_.u8[i] = a;
  }

  return simde__m512i_from_private(r_);
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_set1_epu16 (uint16_t a) {
  simde__m512i_private r_;

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    r_.u16[i] = a;
  }

  return simde__m512i_from_private(r_);
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_set1_epu32 (uint32_t a) {
  simde__m512i_private r_;

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
    r_.u32[i] = a;
  }

  return simde__m512i_from_private(r_);
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_set1_epu64 (uint64_t a) {
  simde__m512i_private r_;

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
    r_.u64[i] = a;
  }

  return simde__m512i_from_private(r_);
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_set1_ps (simde_float32 a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_set1_ps(a);
  #else
    simde__m512_private r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = a;
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_set1_ps(a) simde_mm512_set1_ps(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_set1_pd (simde_float64 a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_set1_pd(a);
  #else
    simde__m512d_private r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = a;
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_set1_pd(a) simde_mm512_set1_pd(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_set4_epi32(d,c,b,a) simde_mm512_set4_epi32(d,c,b,a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_set4_epi64(d,c,b,a) simde_mm512_set4_epi64(d,c,b,a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_set4_ps(d,c,b,a) simde_mm512_set4_ps(d,c,b,a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_set4_pd(d,c,b,a) simde_mm512_set4_pd(d,c,b,a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_setr_epi32(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_setr_epi32(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_setr_epi64(e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_setr_epi64(e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_setr_ps(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_setr_ps(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_setr_pd(e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_setr_pd(e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_setr4_epi32(d,c,b,a) simde_mm512_setr4_epi32(d,c,b,a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_setr4_epi64(d,c,b,a) simde_mm512_setr4_epi64(d,c,b,a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_setr4_ps(d,c,b,a) simde_mm512_setr4_ps(d,c,b,a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_setr4_pd(d,c,b,a) simde_mm512_setr4_pd(d,c,b,a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_setzero_si512(void) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_setzero_si512();
  #else
    simde__m512i r;
    simde_memset(&r, 0, sizeof(r));
    return r;
  #endif
}
#define simde_mm512_setzero_epi32() simde_mm512_setzero_si512()
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_setzero_si512() simde_mm512_setzero_si512()
  #define _mm512_setzero_epi32() simde_mm512_setzero_si512()
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_setone_si512(void) {
  simde__m512i_private r_;

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
    r_.i32f[i] = ~((int_fast32_t) 0);
  }

  return simde__m512i_from_private(r_);
}
#define simde_mm512_setone_epi32() simde_mm512_setone_si512()

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_setzero_ps(void) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_setzero_ps();
  #else
    return simde_mm512_castsi512_ps(simde_mm512_setzero_si512());
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_setzero_si512() simde_mm512_setzero_si512()
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_setone_ps(void) {
  return simde_mm512_castsi512_ps(simde_mm512_setone_si512());
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_setzero_pd(void) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_setzero_pd();
  #else
    return simde_mm512_castsi512_pd(simde_mm512_setzero_si512());
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_setzero_si512() simde_mm512_setzero_si512()
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_setone_pd(void) {
  return simde_mm512_castsi512_pd(simde_mm512_setone_si512());
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_mov_epi32(simde__m512i src, simde__mmask16 k, simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_mov_epi32(src, k, a);
  #else
    simde__m512i_private
      src_ = simde__m512i_to_private(src),
      a_ = simde__m512i_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = ((k >> i) & 1) ? a_.i32[i] : src_.i32[i];
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_mov_epi32(src, k, a) simde_mm512_mask_mov_epi32(src, k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_mov_epi64(simde__m512i src, simde__mmask8 k, simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_mov_epi64(src, k, a);
  #else
    simde__m512i_private
      src_ = simde__m512i_to_private(src),
      a_ = simde__m512i_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = ((k >> i) & 1) ? a_.i64[i] : src_.i64[i];
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_mov_epi64(src, k, a) simde_mm512_mask_mov_epi64(src, k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_mov_ps(simde__m512 src, simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_mov_ps(src, k, a);
  #else
    simde__m512_private
      src_ = simde__m512_to_private(src),
      a_ = simde__m512_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = ((k >> i) & 1) ? a_.f32[i] : src_.f32[i];
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_mov_ps(src, k, a) simde_mm512_mask_mov_ps(src, k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_mov_pd(simde__m512d src, simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_mov_pd(src, k, a);
  #else
    simde__m512d_private
      src_ = simde__m512d_to_private(src),
      a_ = simde__m512d_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = ((k >> i) & 1) ? a_.f64[i] : src_.f64[i];
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_mov_pd(src, k, a) simde_mm512_mask_mov_pd(src, k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_mov_epi32(simde__mmask16 k, simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_mov_epi32(k, a);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
      r_.i32[i] = ((k >> i) & 1) ? a_.i32[i] : INT32_C(0);
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_mov_epi32(k, a) simde_mm512_maskz_mov_epi32(k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_mov_epi64(simde__mmask8 k, simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_mov_epi64(k, a);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
      r_.i64[i] = ((k >> i) & 1) ? a_.i64[i] : INT64_C(0);
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_mov_epi64(k, a) simde_mm512_maskz_mov_epi64(k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_mov_ps(simde__mmask16 k, simde__m512 a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_mov_ps(k, a);
  #else
    simde__m512_private
      a_ = simde__m512_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f32) / sizeof(r_.f32[0])) ; i++) {
      r_.f32[i] = ((k >> i) & 1) ? a_.f32[i] : SIMDE_FLOAT32_C(0.0);
    }

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_mov_ps(k, a) simde_mm512_maskz_mov_ps(k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_mov_pd(simde__mmask8 k, simde__m512d a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_mov_pd(k, a);
  #else
    simde__m512d_private
      a_ = simde__m512d_to_private(a),
      r_;

    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.f64) / sizeof(r_.f64[0])) ; i++) {
      r_.f64[i] = ((k >> i) & 1) ? a_.f64[i] : SIMDE_FLOAT64_C(0.0);
    }

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_mov_pd(k, a) simde_mm512_maskz_mov_pd(k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_abs_epi32(simde__m512i a) {
#if defined(SIMDE_AVX512F_NATIVE)
  return _mm512_abs_epi32(a);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    r_.i32[i] = (a_.i32[i] < INT64_C(0)) ? -a_.i32[i] : a_.i32[i];
  }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
#  define _mm512_abs_epi32(a) simde_mm512_abs_epi32(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_abs_epi32(simde__m512i src, simde__mmask16 k, simde__m512i a) {
#if defined(SIMDE_AVX512F_NATIVE)
  return _mm512_mask_abs_epi32(src, k, a);
#else
  return simde_mm512_mask_mov_epi32(src, k, simde_mm512_abs_epi32(a));
#endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_abs_epi32(src, k, a) simde_mm512_mask_abs_epi32(src, k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_abs_epi32(simde__mmask16 k, simde__m512i a) {
#if defined(SIMDE_AVX512F_NATIVE)
  return _mm512_maskz_abs_epi32(k, a);
#else
  return simde_mm512_maskz_mov_epi32(k, simde_mm512_abs_epi32(a));
#endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_abs_epi32(k, a) simde_mm512_maskz_abs_epi32(k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_abs_epi64(simde__m512i a) {
#if defined(SIMDE_AVX512F_NATIVE)
  return _mm512_abs_epi64(a);
#else
  simde__m512i_private
    r_,
    a_ = simde__m512i_to_private(a);

  SIMDE__VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i64) / sizeof(r_.i64[0])); i++) {
    r_.i64[i] = (a_.i64[i] < INT64_C(0)) ? -a_.i64[i] : a_.i64[i];
  }

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
#  define _mm512_abs_epi64(a) simde_mm512_abs_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_abs_epi64(simde__m512i src, simde__mmask8 k, simde__m512i a) {
#if defined(SIMDE_AVX512F_NATIVE)
  return _mm512_mask_abs_epi64(src, k, a);
#else
  return simde_mm512_mask_mov_epi64(src, k, simde_mm512_abs_epi64(a));
#endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_mask_abs_epi64(src, k, a) simde_mm512_mask_abs_epi64(src, k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_abs_epi64(simde__mmask8 k, simde__m512i a) {
#if defined(SIMDE_AVX512F_NATIVE)
  return _mm512_maskz_abs_epi64(k, a);
#else
  return simde_mm512_maskz_mov_epi64(k, simde_mm512_abs_epi64(a));
#endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
#define _mm512_maskz_abs_epi64(k, a) simde_mm512_maskz_abs_epi64(k, a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_add_epi32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_add_epi32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = a_.i32 + b_.i32;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_add_epi32(a_.m256i[i], b_.m256i[i]);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_add_epi32(a, b) simde_mm512_add_epi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_add_epi32(simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_add_epi32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_add_epi32(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_add_epi32(src, k, a, b) simde_mm512_mask_add_epi32(src, k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_add_epi32(simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_add_epi32(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi32(k, simde_mm512_add_epi32(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_add_epi32(k, a, b) simde_mm512_maskz_add_epi32(k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_add_epi64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_add_epi64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 + b_.i64;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_add_epi64(a_.m256i[i], b_.m256i[i]);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_add_epi64(a, b) simde_mm512_add_epi64(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_add_epi64(simde__m512i src, simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_add_epi64(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_add_epi64(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_add_epi64(src, k, a, b) simde_mm512_mask_add_epi64(src, k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_add_epi64(simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_add_epi64(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_add_epi64(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_add_epi64(k, a, b) simde_mm512_maskz_add_epi64(k, a, b)
#endif


SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_add_ps (simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_add_ps(a, b);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f32 = a_.f32 + b_.f32;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256) / sizeof(r_.m256[0])) ; i++) {
        r_.m256[i] = simde_mm256_add_ps(a_.m256[i], b_.m256[i]);
      }
    #endif

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_add_ps(a, b) simde_mm512_add_ps(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_add_ps(simde__m512 src, simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_add_ps(src, k, a, b);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_add_ps(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_add_ps(src, k, a, b) simde_mm512_mask_add_ps(src, k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_add_ps(simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_add_ps(k, a, b);
  #else
    return simde_mm512_maskz_mov_ps(k, simde_mm512_add_ps(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_add_ps(k, a, b) simde_mm512_maskz_add_ps(k, a, b)
#endif


SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_add_pd (simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_add_pd(a, b);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f64 = a_.f64 + b_.f64;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256d) / sizeof(r_.m256d[0])) ; i++) {
        r_.m256d[i] = simde_mm256_add_pd(a_.m256d[i], b_.m256d[i]);
      }
    #endif

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_add_pd(a, b) simde_mm512_add_pd(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_add_pd(simde__m512d src, simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_add_pd(src, k, a, b);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_add_pd(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_add_pd(src, k, a, b) simde_mm512_mask_add_pd(src, k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_add_pd(simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_add_pd(k, a, b);
  #else
    return simde_mm512_maskz_mov_pd(k, simde_mm512_add_pd(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_add_pd(k, a, b) simde_mm512_maskz_add_pd(k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_and_si512 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_and_si512(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_ARCH_X86_AVX2)
      r_.m256i[0] = simde_mm256_and_si256(a_.m256i[0], b_.m256i[0]);
      r_.m256i[1] = simde_mm256_and_si256(a_.m256i[1], b_.m256i[1]);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = a_.i32f & b_.i32f;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i32[i] & b_.i32[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_and_si512(a, b) simde_mm512_and_si512(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_andnot_si512 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_andnot_si512(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_ARCH_X86_AVX2)
      r_.m256i[0] = simde_mm256_andnot_si256(a_.m256i[0], b_.m256i[0]);
      r_.m256i[1] = simde_mm256_andnot_si256(a_.m256i[1], b_.m256i[1]);
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
        r_.i32f[i] = ~(a_.i32f[i]) & b_.i32f[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_andnot_si512(a, b) simde_mm512_andnot_si512(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_broadcast_i32x4 (simde__m128i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_broadcast_i32x4(a);
  #else
    simde__m512i_private r_;

    #if defined(SIMDE_ARCH_X86_AVX2)
      r_.m256i[1] = r_.m256i[0] = simde_mm256_broadcastsi128_si256(a);
    #elif defined(SIMDE_ARCH_X86_SSE2)
      r_.m128i[3] = r_.m128i[2] = r_.m128i[1] = r_.m128i[0] = a;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++) {
        r_.m128i[i] = a;
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_broadcast_i32x4(a) simde_mm512_broadcast_i32x4(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_cmpeq_epi32_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_cmpeq_epi32_mask(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
      r_.m256i[i] = simde_mm256_cmpeq_epi32(a_.m256i[i], b_.m256i[i]);
    }

    return simde__m512i_private_to_mmask16(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_cmpeq_epi32_mask(a, b) simde_mm512_cmpeq_epi32_mask(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_mask_cmpeq_epi32_mask (simde__mmask16 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_cmpeq_epi32_mask(k1, a, b);
  #else
    return simde_mm512_cmpeq_epi32_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_cmpeq_epi32_mask(k1, a, b) simde_mm512_mask_cmpeq_epi32_mask(k1, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_cmpeq_epi64_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_cmpeq_epi64_mask(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
      r_.m256i[i] = simde_mm256_cmpeq_epi64(a_.m256i[i], b_.m256i[i]);
    }

    return simde__m512i_private_to_mmask8(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_cmpeq_epi64_mask(a, b) simde_mm512_cmpeq_epi64_mask(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_mask_cmpeq_epi64_mask (simde__mmask8 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_cmpeq_epi64_mask(k1, a, b);
  #else
    return simde_mm512_cmpeq_epi64_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_cmpeq_epi64_mask(k1, a, b) simde_mm512_mask_cmpeq_epi64_mask(k1, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_cmpgt_epi32_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_cmpgt_epi32_mask(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
      r_.m256i[i] = simde_mm256_cmpgt_epi32(a_.m256i[i], b_.m256i[i]);
    }

    return simde__m512i_private_to_mmask16(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_cmpgt_epi32_mask(a, b) simde_mm512_cmpgt_epi32_mask(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_mask_cmpgt_epi32_mask (simde__mmask16 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_cmpgt_epi32_mask(k1, a, b);
  #else
    return simde_mm512_cmpgt_epi32_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_cmpgt_epi32_mask(k1, a, b) simde_mm512_mask_cmpgt_epi32_mask(k1, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_cmpgt_epi64_mask (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_cmpgt_epi64_mask(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
      r_.m256i[i] = simde_mm256_cmpgt_epi64(a_.m256i[i], b_.m256i[i]);
    }

    return simde__m512i_private_to_mmask8(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_cmpgt_epi64_mask(a, b) simde_mm512_cmpgt_epi64_mask(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_mask_cmpgt_epi64_mask (simde__mmask8 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_cmpgt_epi64_mask(k1, a, b);
  #else
    return simde_mm512_cmpgt_epi64_mask(a, b) & k1;
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_cmpgt_epi64_mask(k1, a, b) simde_mm512_mask_cmpgt_epi64_mask(k1, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_cvtepi8_epi32 (simde__m128i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_cvtepi8_epi32(a);
  #else
    simde__m512i_private r_;
    simde__m128i_private a_ = simde__m128i_to_private(a);

    #if defined(SIMDE__CONVERT_VECTOR)
      SIMDE__CONVERT_VECTOR(r_.i32, a_.i8);
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32[i] = a_.i8[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_cvtepi8_epi32(a) simde_mm512_cvtepi8_epi32(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_cvtepi8_epi64 (simde__m128i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_cvtepi8_epi64(a);
  #else
    simde__m512i_private r_;
    simde__m128i_private a_ = simde__m128i_to_private(a);

    #if defined(SIMDE__CONVERT_VECTOR)
      SIMDE__CONVERT_VECTOR(r_.i64, a_.m64_private[0].i8);
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = a_.i8[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_cvtepi8_epi64(a) simde_mm512_cvtepi8_epi64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_cvtepi32_epi8 (simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_cvtepi32_epi8(a);
  #else
    simde__m128i_private r_;
    simde__m512i_private a_ = simde__m512i_to_private(a);

    #if defined(SIMDE__CONVERT_VECTOR)
      SIMDE__CONVERT_VECTOR(r_.i8, a_.i32);
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
        r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, a_.i32[i]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_cvtepi32_epi8(a) simde_mm512_cvtepi32_epi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
  simde_mm512_cvtepi32_epi16 (simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_cvtepi32_epi16(a);
  #else
    simde__m256i_private r_;
    simde__m512i_private a_ = simde__m512i_to_private(a);

    #if defined(SIMDE__CONVERT_VECTOR)
      SIMDE__CONVERT_VECTOR(r_.i16, a_.i32);
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
        r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, a_.i32[i]);
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_cvtepi32_epi16(a) simde_mm512_cvtepi32_epi16(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_cvtepi64_epi8 (simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_cvtepi64_epi8(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m512i_private a_ = simde__m512i_to_private(a);

    #if defined(SIMDE__CONVERT_VECTOR)
      SIMDE__CONVERT_VECTOR(r_.m64_private[0].i8, a_.i64);
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
        r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, a_.i64[i]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_cvtepi64_epi8(a) simde_mm512_cvtepi64_epi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_cvtepi64_epi16 (simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_cvtepi64_epi16(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m512i_private a_ = simde__m512i_to_private(a);

    #if defined(SIMDE__CONVERT_VECTOR)
      SIMDE__CONVERT_VECTOR(r_.i16, a_.i64);
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
        r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, a_.i64[i]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_cvtepi64_epi16(a) simde_mm512_cvtepi64_epi16(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_cvtepi64_epi32 (simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_cvtepi64_epi32(a);
  #else
    simde__m256i_private r_;
    simde__m512i_private a_ = simde__m512i_to_private(a);

    #if defined(SIMDE__CONVERT_VECTOR)
      SIMDE__CONVERT_VECTOR(r_.i32, a_.i64);
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
        r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, a_.i64[i]);
      }
    #endif

    return simde__m256i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_cvtepi64_epi32(a) simde_mm512_cvtepi64_epi32(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_cvtsepi32_epi8 (simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_cvtsepi32_epi8(a);
  #else
    simde__m128i_private r_;
    simde__m512i_private a_ = simde__m512i_to_private(a);

    SIMDE__VECTORIZE
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_cvtsepi32_epi8(a) simde_mm512_cvtsepi32_epi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_cvtsepi32_epi16 (simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_cvtsepi32_epi16(a);
  #else
    simde__m256i_private r_;
    simde__m512i_private a_ = simde__m512i_to_private(a);

    SIMDE__VECTORIZE
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_cvtsepi32_epi16(a) simde_mm512_cvtsepi32_epi16(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_cvtsepi64_epi8 (simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_cvtsepi64_epi8(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m512i_private a_ = simde__m512i_to_private(a);

    SIMDE__VECTORIZE
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_cvtsepi64_epi8(a) simde_mm512_cvtsepi64_epi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m128i
simde_mm512_cvtsepi64_epi16 (simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_cvtsepi64_epi16(a);
  #else
    simde__m128i_private r_ = simde__m128i_to_private(simde_mm_setzero_si128());
    simde__m512i_private a_ = simde__m512i_to_private(a);

      SIMDE__VECTORIZE
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_cvtsepi64_epi16(a) simde_mm512_cvtsepi64_epi16(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m256i
simde_mm512_cvtsepi64_epi32 (simde__m512i a) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_cvtsepi64_epi32(a);
  #else
    simde__m256i_private r_;
    simde__m512i_private a_ = simde__m512i_to_private(a);

      SIMDE__VECTORIZE
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
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_cvtsepi64_epi32(a) simde_mm512_cvtsepi64_epi32(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_div_ps (simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_div_ps(a, b);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f32 = a_.f32 / b_.f32;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256) / sizeof(r_.m256[0])) ; i++) {
        r_.m256[i] = simde_mm256_div_ps(a_.m256[i], b_.m256[i]);
      }
    #endif

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_div_ps(a, b) simde_mm512_div_ps(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_div_ps(simde__m512 src, simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_div_ps(src, k, a, b);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_div_ps(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_div_ps(src, k, a, b) simde_mm512_mask_div_ps(src, k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_div_ps(simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_div_ps(k, a, b);
  #else
    return simde_mm512_maskz_mov_ps(k, simde_mm512_div_ps(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_div_ps(k, a, b) simde_mm512_maskz_div_ps(k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_div_pd (simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_div_pd(a, b);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f64 = a_.f64 / b_.f64;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256d) / sizeof(r_.m256d[0])) ; i++) {
        r_.m256d[i] = simde_mm256_div_pd(a_.m256d[i], b_.m256d[i]);
      }
    #endif

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_div_pd(a, b) simde_mm512_div_pd(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_div_pd(simde__m512d src, simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_div_pd(src, k, a, b);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_div_pd(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_div_pd(src, k, a, b) simde_mm512_mask_div_pd(src, k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_div_pd(simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_div_pd(k, a, b);
  #else
    return simde_mm512_maskz_mov_pd(k, simde_mm512_div_pd(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_div_pd(k, a, b) simde_mm512_maskz_div_pd(k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_load_si512 (simde__m512i const * mem_addr) {
  simde_assert_aligned(64, mem_addr);

  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_load_si512((__m512i const*) mem_addr);
  #elif defined(SIMDE_ARCH_AARCH64) && (defined(HEDLEY_GCC_VERSION) && !HEDLEY_GCC_VERSION_CHECK(8,0,0))
    simde__m512i r;
    memcpy(&r, mem_addr, sizeof(r));
    return r;
  #else
    return *mem_addr;
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_load_si512(a) simde_mm512_load_si512(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_loadu_si512 (simde__m512i const * mem_addr) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_loadu_si512((__m512i const*) mem_addr);
  #else
    simde__m512i r;
    simde_memcpy(&r, mem_addr, sizeof(r));
    return r;
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_loadu_si512(a) simde_mm512_loadu_si512(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mul_ps (simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mul_ps(a, b);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f32 = a_.f32 * b_.f32;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256) / sizeof(r_.m256[0])) ; i++) {
        r_.m256[i] = simde_mm256_mul_ps(a_.m256[i], b_.m256[i]);
      }
    #endif

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mul_ps(a, b) simde_mm512_mul_ps(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_mul_ps(simde__m512 src, simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_mul_ps(src, k, a, b);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_mul_ps(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_mul_ps(src, k, a, b) simde_mm512_mask_mul_ps(src, k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_mul_ps(simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_mul_ps(k, a, b);
  #else
    return simde_mm512_maskz_mov_ps(k, simde_mm512_mul_ps(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_mul_ps(k, a, b) simde_mm512_maskz_mul_ps(k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mul_pd (simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mul_pd(a, b);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f64 = a_.f64 * b_.f64;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256d) / sizeof(r_.m256d[0])) ; i++) {
        r_.m256d[i] = simde_mm256_mul_pd(a_.m256d[i], b_.m256d[i]);
      }
    #endif

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mul_pd(a, b) simde_mm512_mul_pd(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_mul_pd(simde__m512d src, simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_mul_pd(src, k, a, b);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_mul_pd(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_mul_pd(src, k, a, b) simde_mm512_mask_mul_pd(src, k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_mul_pd(simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_mul_pd(k, a, b);
  #else
    return simde_mm512_maskz_mov_pd(k, simde_mm512_mul_pd(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_mul_pd(k, a, b) simde_mm512_maskz_mul_pd(k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mul_epi32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mul_epi32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE__CONVERT_VECTOR) && defined(SIMDE__SHUFFLE_VECTOR)
      simde__m512i_private x;
      __typeof__(r_.i64) ta, tb;

      /* Get even numbered 32-bit values */
      x.i32 = SIMDE__SHUFFLE_VECTOR(32, 64, a_.i32, b_.i32, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30);
      /* Cast to 64 bits */
      SIMDE__CONVERT_VECTOR(ta, x.m256i_private[0].i32);
      SIMDE__CONVERT_VECTOR(tb, x.m256i_private[1].i32);
      r_.i64 = ta * tb;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i64) / sizeof(r_.i64[0])) ; i++) {
        r_.i64[i] = HEDLEY_STATIC_CAST(int64_t, a_.i32[i << 1]) * HEDLEY_STATIC_CAST(int64_t, b_.i32[i << 1]);
      }
    #endif
      return simde__m512i_from_private(r_);
    #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mul_epi32(a, b) simde_mm512_mul_epi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_mul_epi32(simde__m512i src, simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_mul_epi32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_mul_epi32(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_mul_epi32(src, k, a, b) simde_mm512_mask_mul_epi32(src, k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_mul_epi32(simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_mul_epi32(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_mul_epi32(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_mul_epi32(k, a, b) simde_mm512_maskz_mul_epi32(k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mul_epu32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mul_epu32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE__CONVERT_VECTOR) && defined(SIMDE__SHUFFLE_VECTOR)
      simde__m512i_private x;
      __typeof__(r_.u64) ta, tb;

      x.u32 = SIMDE__SHUFFLE_VECTOR(32, 64, a_.u32, b_.u32, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30);
      SIMDE__CONVERT_VECTOR(ta, x.m256i_private[0].u32);
      SIMDE__CONVERT_VECTOR(tb, x.m256i_private[1].u32);
      r_.u64 = ta * tb;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
        r_.u64[i] = HEDLEY_STATIC_CAST(uint64_t, a_.u32[i << 1]) * HEDLEY_STATIC_CAST(uint64_t, b_.u32[i << 1]);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mul_epu32(a, b) simde_mm512_mul_epu32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_mul_epu32(simde__m512i src, simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_mul_epu32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_mul_epu32(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_mul_epu32(src, k, a, b) simde_mm512_mask_mul_epu32(src, k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_mul_epu32(simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_mul_epu32(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_mul_epu32(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_mul_epu32(k, a, b) simde_mm512_maskz_mul_epu32(k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_or_si512 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_or_si512(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_ARCH_X86_AVX2)
      r_.m256i[0] = simde_mm256_or_si256(a_.m256i[0], b_.m256i[0]);
      r_.m256i[1] = simde_mm256_or_si256(a_.m256i[1], b_.m256i[1]);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = a_.i32f | b_.i32f;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
        r_.i32f[i] = a_.i32f[i] | b_.i32f[i];
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_or_si512(a, b) simde_mm512_or_si512(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_sub_epi32 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_sub_epi32(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32 = a_.i32 - b_.i32;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_sub_epi32(a_.m256i[i], b_.m256i[i]);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_sub_epi32(a, b) simde_mm512_sub_epi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_sub_epi32 (simde__m512i src, simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_sub_epi32(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi32(src, k, simde_mm512_sub_epi32(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_sub_epi32(src, k, a, b) simde_mm512_mask_sub_epi32(src, k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_sub_epi32(simde__mmask16 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_sub_epi32(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi32(k, simde_mm512_sub_epi32(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_sub_epi32(k, a, b) simde_mm512_maskz_sub_epi32(k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_sub_epi64 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_sub_epi64(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i64 = a_.i64 - b_.i64;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
        r_.m256i[i] = simde_mm256_sub_epi64(a_.m256i[i], b_.m256i[i]);
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_sub_epi64(a, b) simde_mm512_sub_epi64(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_sub_epi64 (simde__m512i src, simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_sub_epi64(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi64(src, k, simde_mm512_sub_epi64(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_sub_epi64(src, k, a, b) simde_mm512_mask_sub_epi64(src, k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_sub_epi64(simde__mmask8 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_sub_epi64(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi64(k, simde_mm512_sub_epi64(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_sub_epi64(k, a, b) simde_mm512_maskz_sub_epi64(k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_sub_ps (simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_sub_ps(a, b);
  #else
    simde__m512_private
      r_,
      a_ = simde__m512_to_private(a),
      b_ = simde__m512_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f32 = a_.f32 - b_.f32;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256) / sizeof(r_.m256[0])) ; i++) {
        r_.m256[i] = simde_mm256_sub_ps(a_.m256[i], b_.m256[i]);
      }
    #endif

    return simde__m512_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_sub_ps(a, b) simde_mm512_sub_ps(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_mask_sub_ps (simde__m512 src, simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_sub_ps(src, k, a, b);
  #else
    return simde_mm512_mask_mov_ps(src, k, simde_mm512_sub_ps(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_sub_ps(src, k, a, b) simde_mm512_mask_sub_ps(src, k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512
simde_mm512_maskz_sub_ps(simde__mmask16 k, simde__m512 a, simde__m512 b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_sub_ps(k, a, b);
  #else
    return simde_mm512_maskz_mov_ps(k, simde_mm512_sub_ps(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_sub_ps(k, a, b) simde_mm512_maskz_sub_ps(k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_sub_pd (simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_sub_pd(a, b);
  #else
    simde__m512d_private
      r_,
      a_ = simde__m512d_to_private(a),
      b_ = simde__m512d_to_private(b);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.f64 = a_.f64 - b_.f64;
    #else
      SIMDE__VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.m256d) / sizeof(r_.m256d[0])) ; i++) {
        r_.m256d[i] = simde_mm256_sub_pd(a_.m256d[i], b_.m256d[i]);
      }
    #endif

    return simde__m512d_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_sub_pd(a, b) simde_mm512_sub_pd(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_mask_sub_pd (simde__m512d src, simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_sub_pd(src, k, a, b);
  #else
    return simde_mm512_mask_mov_pd(src, k, simde_mm512_sub_pd(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_sub_pd(src, k, a, b) simde_mm512_mask_sub_pd(src, k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512d
simde_mm512_maskz_sub_pd(simde__mmask8 k, simde__m512d a, simde__m512d b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_maskz_sub_pd(k, a, b);
  #else
    return simde_mm512_maskz_mov_pd(k, simde_mm512_sub_pd(a, b));
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_maskz_sub_pd(k, a, b) simde_mm512_maskz_sub_pd(k, a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_srli_epi32 (simde__m512i a, unsigned int imm8) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_srli_epi32(a, imm8);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a);

    #if defined(SIMDE_ARCH_X86_AVX2)
      r_.m256i[0] = simde_mm256_srli_epi32(a_.m256i[0], imm8);
      r_.m256i[1] = simde_mm256_srli_epi32(a_.m256i[1], imm8);
    #elif defined(SIMDE_ARCH_X86_SSE2)
      r_.m128i[0] = simde_mm_srli_epi32(a_.m128i[0], imm8);
      r_.m128i[1] = simde_mm_srli_epi32(a_.m128i[1], imm8);
      r_.m128i[2] = simde_mm_srli_epi32(a_.m128i[2], imm8);
      r_.m128i[3] = simde_mm_srli_epi32(a_.m128i[3], imm8);
    #else
      if (imm8 > 31) {
        simde_memset(&r_, 0, sizeof(r_));
      } else {
        #if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
          r_.u32 = a_.u32 >> imm8;
        #else
          SIMDE__VECTORIZE
          for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
            r_.u32[i] = a_.u32[i] >> imm8;
          }
        #endif
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_srli_epi32(a, imm8) simde_mm512_srli_epi32(a, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_srli_epi64 (simde__m512i a, unsigned int imm8) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_srli_epi64(a, imm8);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a);

    #if defined(SIMDE_ARCH_X86_AVX2)
      r_.m256i[0] = simde_mm256_srli_epi64(a_.m256i[0], imm8);
      r_.m256i[1] = simde_mm256_srli_epi64(a_.m256i[1], imm8);
    #elif defined(SIMDE_ARCH_X86_SSE2)
      r_.m128i[0] = simde_mm_srli_epi64(a_.m128i[0], imm8);
      r_.m128i[1] = simde_mm_srli_epi64(a_.m128i[1], imm8);
      r_.m128i[2] = simde_mm_srli_epi64(a_.m128i[2], imm8);
      r_.m128i[3] = simde_mm_srli_epi64(a_.m128i[3], imm8);
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
          SIMDE__VECTORIZE
          for (size_t i = 0 ; i < (sizeof(r_.u64) / sizeof(r_.u64[0])) ; i++) {
            r_.u64[i] = a_.u64[i] >> imm8;
          }
        #endif
      }
    #endif

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_srli_epi64(a, imm8) simde_mm512_srli_epi64(a, imm8)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__mmask16
simde_mm512_mask_test_epi32_mask (simde__mmask16 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_test_epi32_mask(k1, a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask16 r = 0;

    SIMDE__VECTORIZE_REDUCTION(|:r)
    for (size_t i = 0 ; i < (sizeof(a_.i32) / sizeof(a_.i32[0])) ; i++) {
      r |= !!(a_.i32[i] & b_.i32[i]) << i;
    }

    return r & k1;
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_test_epi32_mask(a, b) simde_mm512_mask_test_epi32_mask(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__mmask8
simde_mm512_mask_test_epi64_mask (simde__mmask8 k1, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_mask_test_epi64_mask(k1, a, b);
  #else
    simde__m512i_private
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);
    simde__mmask8 r = 0;

    SIMDE__VECTORIZE_REDUCTION(|:r)
    for (size_t i = 0 ; i < (sizeof(a_.i64) / sizeof(a_.i64[0])) ; i++) {
      r |= !!(a_.i64[i] & b_.i64[i]) << i;
    }

    return r & k1;
  #endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_mask_test_epi64_mask(a, b) simde_mm512_mask_test_epi64_mask(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_xor_si512 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_AVX512F_NATIVE)
    return _mm512_xor_si512(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

  #if defined(SIMDE_ARCH_X86_AVX2)
    r_.m256i[0] = simde_mm256_xor_si256(a_.m256i[0], b_.m256i[0]);
    r_.m256i[1] = simde_mm256_xor_si256(a_.m256i[1], b_.m256i[1]);
  #elif defined(SIMDE_ARCH_X86_SSE2)
    r_.m128i[0] = simde_mm_xor_si128(a_.m128i[0], b_.m128i[0]);
    r_.m128i[1] = simde_mm_xor_si128(a_.m128i[1], b_.m128i[1]);
    r_.m128i[2] = simde_mm_xor_si128(a_.m128i[2], b_.m128i[2]);
    r_.m128i[3] = simde_mm_xor_si128(a_.m128i[3], b_.m128i[3]);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i32f = a_.i32f ^ b_.i32f;
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
      r_.i32f[i] = a_.i32f[i] ^ b_.i32f[i];
    }
  #endif

  return simde__m512i_from_private(r_);
#endif
}
#if defined(SIMDE_AVX512F_ENABLE_NATIVE_ALIASES)
  #define _mm512_xor_si512(a, b) simde_mm512_xor_si512(a, b)
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE__AVX512F_H) */
