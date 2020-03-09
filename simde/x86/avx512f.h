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

#  if defined(SIMDE_AVX512F_NATIVE)
#    undef SIMDE_AVX512F_NATIVE
#  endif
#  if defined(SIMDE_ARCH_X86_AVX512F) && !defined(SIMDE_AVX512F_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_AVX512F_NATIVE
#  elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_AVX512F_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_AVX512F_NEON
#  elif defined(SIMDE_ARCH_POWER_ALTIVEC)
#    define SIMDE_AVX512F_POWER_ALTIVEC
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
  SIMDE_ALIGN(64) int8_t          i8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) int16_t        i16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) int32_t        i32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) int64_t        i64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) uint8_t         u8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) uint16_t       u16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) uint32_t       u32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) uint64_t       u64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #if defined(SIMDE__HAVE_INT128)
  SIMDE_ALIGN(64) simde_int128  i128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) simde_uint128 u128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #endif
  SIMDE_ALIGN(64) simde_float32  f32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) simde_float64  f64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) int_fast32_t  i32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) uint_fast32_t u32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
#else
  SIMDE_ALIGN(64) int8_t          i8[64];
  SIMDE_ALIGN(64) int16_t        i16[32];
  SIMDE_ALIGN(64) int32_t        i32[16];
  SIMDE_ALIGN(64) int64_t        i64[8];
  SIMDE_ALIGN(64) uint8_t         u8[64];
  SIMDE_ALIGN(64) uint16_t       u16[32];
  SIMDE_ALIGN(64) uint32_t       u32[16];
  SIMDE_ALIGN(64) uint64_t       u64[8];
  SIMDE_ALIGN(64) int_fast32_t  i32f[64 / sizeof(int_fast32_t)];
  SIMDE_ALIGN(64) uint_fast32_t u32f[64 / sizeof(uint_fast32_t)];
  #if defined(SIMDE__HAVE_INT128)
  SIMDE_ALIGN(64) simde_int128  i128[4];
  SIMDE_ALIGN(64) simde_uint128 u128[4];
  #endif
  SIMDE_ALIGN(64) simde_float32  f32[16];
  SIMDE_ALIGN(64) simde_float64  f64[8];
#endif

  SIMDE_ALIGN(64) simde__m128_private m128_private[4];
  SIMDE_ALIGN(64) simde__m128         m128[4];
  SIMDE_ALIGN(64) simde__m256_private m256_private[2];
  SIMDE_ALIGN(64) simde__m256         m256[2];

#if defined(SIMDE_AVX512F_NATIVE)
  SIMDE_ALIGN(64) __m512         n;
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
  SIMDE_ALIGN(64) int8_t          i8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) int16_t        i16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) int32_t        i32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) int64_t        i64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) uint8_t         u8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) uint16_t       u16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) uint32_t       u32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) uint64_t       u64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #if defined(SIMDE__HAVE_INT128)
  SIMDE_ALIGN(64) simde_int128  i128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) simde_uint128 u128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #endif
  SIMDE_ALIGN(64) simde_float32  f32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) simde_float64  f64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) int_fast32_t  i32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) uint_fast32_t u32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
#else
  SIMDE_ALIGN(64) int8_t          i8[64];
  SIMDE_ALIGN(64) int16_t        i16[32];
  SIMDE_ALIGN(64) int32_t        i32[16];
  SIMDE_ALIGN(64) int64_t        i64[8];
  SIMDE_ALIGN(64) uint8_t         u8[64];
  SIMDE_ALIGN(64) uint16_t       u16[32];
  SIMDE_ALIGN(64) uint32_t       u32[16];
  SIMDE_ALIGN(64) uint64_t       u64[8];
  #if defined(SIMDE__HAVE_INT128)
  SIMDE_ALIGN(64) simde_int128  i128[4];
  SIMDE_ALIGN(64) simde_uint128 u128[4];
  #endif
  SIMDE_ALIGN(64) simde_float32  f32[16];
  SIMDE_ALIGN(64) simde_float64  f64[8];
  SIMDE_ALIGN(64) int_fast32_t  i32f[64 / sizeof(int_fast32_t)];
  SIMDE_ALIGN(64) uint_fast32_t u32f[64 / sizeof(uint_fast32_t)];
#endif

  SIMDE_ALIGN(64) simde__m128d_private m128d_private[4];
  SIMDE_ALIGN(64) simde__m128d         m128d[4];
  SIMDE_ALIGN(64) simde__m256d_private m256d_private[2];
  SIMDE_ALIGN(64) simde__m256d         m256d[2];

#if defined(SIMDE_AVX512F_NATIVE)
  SIMDE_ALIGN(64) __m512d        n;
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
  SIMDE_ALIGN(64) int8_t          i8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) int16_t        i16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) int32_t        i32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) int64_t        i64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) uint8_t         u8 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) uint16_t       u16 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) uint32_t       u32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) uint64_t       u64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #if defined(SIMDE__HAVE_INT128)
  SIMDE_ALIGN(64) simde_int128  i128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) simde_uint128 u128 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  #endif
  SIMDE_ALIGN(64) simde_float32  f32 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) simde_float64  f64 SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) int_fast32_t  i32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(64) uint_fast32_t u32f SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
#else
  SIMDE_ALIGN(64) int8_t          i8[64];
  SIMDE_ALIGN(64) int16_t        i16[32];
  SIMDE_ALIGN(64) int32_t        i32[16];
  SIMDE_ALIGN(64) int64_t        i64[8];
  SIMDE_ALIGN(64) uint8_t         u8[64];
  SIMDE_ALIGN(64) uint16_t       u16[32];
  SIMDE_ALIGN(64) uint32_t       u32[16];
  SIMDE_ALIGN(64) uint64_t       u64[8];
  SIMDE_ALIGN(64) int_fast32_t  i32f[64 / sizeof(int_fast32_t)];
  SIMDE_ALIGN(64) uint_fast32_t u32f[64 / sizeof(uint_fast32_t)];
  #if defined(SIMDE__HAVE_INT128)
  SIMDE_ALIGN(64) simde_int128  i128[4];
  SIMDE_ALIGN(64) simde_uint128 u128[4];
  #endif
  SIMDE_ALIGN(64) simde_float32  f32[16];
  SIMDE_ALIGN(64) simde_float64  f64[8];
#endif

  SIMDE_ALIGN(64) simde__m128i_private m128i_private[4];
  SIMDE_ALIGN(64) simde__m128i         m128i[4];
  SIMDE_ALIGN(64) simde__m256i_private m256i_private[2];
  SIMDE_ALIGN(64) simde__m256i         m256i[2];

#if defined(SIMDE_AVX512F_NATIVE)
  SIMDE_ALIGN(64) __m512i        n;
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
#elif defined(SIMDE_VECTOR_SUBSCRIPT)
  typedef simde_float32 simde__m512  SIMDE_ALIGN(64) SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  typedef int_fast32_t  simde__m512i SIMDE_ALIGN(64) SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
  typedef simde_float64 simde__m512d SIMDE_ALIGN(64) SIMDE_VECTOR(64) SIMDE_MAY_ALIAS;
#else
  typedef simde__m512_private  simde__m512;
  typedef simde__m512i_private simde__m512i;
  typedef simde__m512d_private simde__m512d;
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
#if defined(SIMDE_AVX512_ENABLE_NATIVE_ALIASES)
#  define _mm512_set_epi8(e63, e62, e61, e60, e59, e58, e57, e56, e55, e54, e53, e52, e51, e50, e49, e48, e47, e46, e45, e44, e43, e42, e41, e40, e39, e38, e37, e36, e35, e34, e33, e32, e31, e30, e29, e28, e27, e26, e25, e24, e23, e22, e21, e20, e19, e18, e17, e16, e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_epi8(e63, e62, e61, e60, e59, e58, e57, e56, e55, e54, e53, e52, e51, e50, e49, e48, e47, e46, e45, e44, e43, e42, e41, e40, e39, e38, e37, e36, e35, e34, e33, e32, e31, e30, e29, e28, e27, e26, e25, e24, e23, e22, e21, e20, e19, e18, e17, e16, e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
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
#if defined(SIMDE_AVX512_ENABLE_NATIVE_ALIASES)
#  define _mm512_set_epi16(e31, e30, e29, e28, e27, e26, e25, e24, e23, e22, e21, e20, e19, e18, e17, e16, e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_epi16(e31, e30, e29, e28, e27, e26, e25, e24, e23, e22, e21, e20, e19, e18, e17, e16, e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
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
#if defined(SIMDE_AVX512_ENABLE_NATIVE_ALIASES)
#  define _mm512_set_epi32(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_epi32(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
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
#if defined(SIMDE_AVX512_ENABLE_NATIVE_ALIASES)
#  define _mm512_set_epi64(e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_epi64(e7, e6, e5, e4, e3, e2, e1, e0)
#endif

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
#if defined(SIMDE_AVX512_ENABLE_NATIVE_ALIASES)
#  define _mm512_set_ps(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_ps(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0)
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
#if defined(SIMDE_AVX512_ENABLE_NATIVE_ALIASES)
#  define _mm512_set_pd(e7, e6, e5, e4, e3, e2, e1, e0) simde_mm512_set_pd(e7, e6, e5, e4, e3, e2, e1, e0)
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
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm512_add_epi32(a, b) simde_mm512_add_epi32(a, b)
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
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm512_add_epi64(a, b) simde_mm512_add_epi64(a, b)
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
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm512_add_ps(a, b) simde_mm512_add_ps(a, b)
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
#if defined(SIMDE_AVX2_ENABLE_NATIVE_ALIASES)
#  define _mm512_add_pd(a, b) simde_mm512_add_pd(a, b)
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE__AVX512F_H) */
