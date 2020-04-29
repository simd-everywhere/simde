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

#if !defined(SIMDE_FEATURES_H)
#define SIMDE_FEATURES_H

#if !defined(SIMDE_MMX_NATIVE) && !defined(SIMDE_NO_NATIVE) && !defined(SIMDE_MMX_NO_NATIVE)
  #if defined(SIMDE_ARCH_X86_MMX)
    #define SIMDE_MMX_NATIVE
  #elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_NO_ARM_NEON) && !defined(SIMDE_MMX_NO_ARM_NEON)
    #define SIMDE_MMX_NEON
  #endif
#endif

#if !defined(SIMDE_SSE_NATIVE) && !defined(SIMDE_NO_NATIVE) && !defined(SIMDE_SSE_NO_NATIVE)
  #if defined(SIMDE_ARCH_X86_SSE)
    #define SIMDE_SSE_NATIVE
  #elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_NO_ARM_NEON) && !defined(SIMDE_SSE_NO_ARM_NEON)
    #define SIMDE_SSE_NEON
  #elif defined(SIMDE_ARCH_WASM_SIMD128) && !defined(SIMDE_NO_WASM_SIMD128) && !defined(SIMDE_SSE_NO_WASM_SIMD128)
    #define SIMDE_SSE_WASM_SIMD128
  #elif defined(SIMDE_ARCH_POWER_ALTIVEC) && !defined(SIMDE_NO_POWER_ALTIVEC) && !defined(SIMDE_SSE_NO_POWER_ALTIVEC)
    #define SIMDE_SSE_POWER_ALTIVEC
  #endif
#endif

#if !defined(SIMDE_SSE2_NATIVE) && !defined(SIMDE_NO_NATIVE) && !defined(SIMDE_SSE2_NO_NATIVE)
  #if defined(SIMDE_ARCH_X86_SSE2)
    #define SIMDE_SSE2_NATIVE
  #elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_NO_ARM_NEON) && !defined(SIMDE_SSE2_NO_ARM_NEON)
    #define SIMDE_SSE2_NEON
  #elif defined(SIMDE_ARCH_WASM_SIMD128) && !defined(SIMDE_NO_WASM_SIMD128) && !defined(SIMDE_SSE2_NO_WASM_SIMD128)
    #define SIMDE_SSE2_WASM_SIMD128
  #elif defined(SIMDE_ARCH_POWER_ALTIVEC) && !defined(SIMDE_NO_POWER_ALTIVEC) && !defined(SIMDE_SSE2_NO_POWER_ALTIVEC)
    #define SIMDE_SSE2_POWER_ALTIVEC
  #endif
#endif

#if !defined(SIMDE_SSE3_NATIVE) && !defined(SIMDE_NO_NATIVE) && !defined(SIMDE_SSE3_NO_NATIVE)
  #if defined(SIMDE_ARCH_X86_SSE3)
    #define SIMDE_SSE3_NATIVE
  #elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_NO_ARM_NEON) && !defined(SIMDE_SSE3_NO_ARM_NEON)
    #define SIMDE_SSE3_NEON
  #elif defined(SIMDE_ARCH_WASM_SIMD128) && !defined(SIMDE_NO_WASM_SIMD128) && !defined(SIMDE_SSE3_NO_WASM_SIMD128)
    #define SIMDE_SSE3_WASM_SIMD128
  #elif defined(SIMDE_ARCH_POWER_ALTIVEC) && !defined(SIMDE_NO_POWER_ALTIVEC) && !defined(SIMDE_SSE3_NO_POWER_ALTIVEC)
    #define SIMDE_SSE3_POWER_ALTIVEC
  #endif
#endif

#if !defined(SIMDE_SSSE3_NATIVE) && !defined(SIMDE_NO_NATIVE) && !defined(SIMDE_SSSE3_NO_NATIVE)
  #if defined(SIMDE_ARCH_X86_SSSE3)
    #define SIMDE_SSSE3_NATIVE
  #elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_NO_ARM_NEON) && !defined(SIMDE_SSSE3_NO_ARM_NEON)
    #define SIMDE_SSSE3_NEON
  #elif defined(SIMDE_ARCH_WASM_SIMD128) && !defined(SIMDE_NO_WASM_SIMD128) && !defined(SIMDE_SSSE3_NO_WASM_SIMD128)
    #define SIMDE_SSSE3_WASM_SIMD128
  #elif defined(SIMDE_ARCH_POWER_ALTIVEC) && !defined(SIMDE_NO_POWER_ALTIVEC) && !defined(SIMDE_SSSE3_NO_POWER_ALTIVEC)
    #define SIMDE_SSSE3_POWER_ALTIVEC
  #endif
#endif

#if !defined(SIMDE_SSE4_1_NATIVE) && !defined(SIMDE_NO_NATIVE) && !defined(SIMDE_SSE4_1_NO_NATIVE)
  #if defined(SIMDE_ARCH_X86_SSE4_1)
    #define SIMDE_SSE4_1_NATIVE
  #elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_NO_ARM_NEON) && !defined(SIMDE_SSE4_1_NO_ARM_NEON)
    #define SIMDE_SSE4_1_NEON
  #elif defined(SIMDE_ARCH_WASM_SIMD128) && !defined(SIMDE_NO_WASM_SIMD128) && !defined(SIMDE_SSE4_1_NO_WASM_SIMD128)
    #define SIMDE_SSE4_1_WASM_SIMD128
  #elif defined(SIMDE_ARCH_POWER_ALTIVEC) && !defined(SIMDE_NO_POWER_ALTIVEC) && !defined(SIMDE_SSE4_1_NO_POWER_ALTIVEC)
    #define SIMDE_SSE4_1_POWER_ALTIVEC
  #endif
#endif

#if !defined(SIMDE_SSE4_2_NATIVE) && !defined(SIMDE_NO_NATIVE) && !defined(SIMDE_SSE4_2_NO_NATIVE)
  #if defined(SIMDE_ARCH_X86_SSE4_2)
    #define SIMDE_SSE4_2_NATIVE
  #elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_NO_ARM_NEON) && !defined(SIMDE_SSE4_2_NO_ARM_NEON)
    #define SIMDE_SSE4_2_NEON
  #elif defined(SIMDE_ARCH_WASM_SIMD128) && !defined(SIMDE_NO_WASM_SIMD128) && !defined(SIMDE_SSE4_2_NO_WASM_SIMD128)
    #define SIMDE_SSE4_2_WASM_SIMD128
  #elif defined(SIMDE_ARCH_POWER_ALTIVEC) && !defined(SIMDE_NO_POWER_ALTIVEC) && !defined(SIMDE_SSE4_2_NO_POWER_ALTIVEC)
    #define SIMDE_SSE4_2_POWER_ALTIVEC
  #endif
#endif

#if !defined(SIMDE_AVX_NATIVE) && !defined(SIMDE_NO_NATIVE) && !defined(SIMDE_AVX_NO_NATIVE)
  #if defined(SIMDE_ARCH_X86_AVX)
    #define SIMDE_AVX_NATIVE
  #elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_NO_ARM_NEON) && !defined(SIMDE_AVX_NO_ARM_NEON)
    #define SIMDE_AVX_NEON
  #elif defined(SIMDE_ARCH_WASM_SIMD128) && !defined(SIMDE_NO_WASM_SIMD128) && !defined(SIMDE_AVX_NO_WASM_SIMD128)
    #define SIMDE_AVX_WASM_SIMD128
  #elif defined(SIMDE_ARCH_POWER_ALTIVEC) && !defined(SIMDE_NO_POWER_ALTIVEC) && !defined(SIMDE_AVX_NO_POWER_ALTIVEC)
    #define SIMDE_AVX_POWER_ALTIVEC
  #endif
#endif

#if !defined(SIMDE_AVX2_NATIVE) && !defined(SIMDE_NO_NATIVE) && !defined(SIMDE_AVX2_NO_NATIVE)
  #if defined(SIMDE_ARCH_X86_AVX2)
    #define SIMDE_AVX2_NATIVE
  #elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_NO_ARM_NEON) && !defined(SIMDE_AVX2_NO_ARM_NEON)
    #define SIMDE_AVX2_NEON
  #elif defined(SIMDE_ARCH_WASM_SIMD128) && !defined(SIMDE_NO_WASM_SIMD128) && !defined(SIMDE_AVX2_NO_WASM_SIMD128)
    #define SIMDE_AVX2_WASM_SIMD128
  #elif defined(SIMDE_ARCH_POWER_ALTIVEC) && !defined(SIMDE_NO_POWER_ALTIVEC) && !defined(SIMDE_AVX2_NO_POWER_ALTIVEC)
    #define SIMDE_AVX2_POWER_ALTIVEC
  #endif
#endif

#if !defined(SIMDE_FMA_NATIVE) && !defined(SIMDE_NO_NATIVE) && !defined(SIMDE_FMA_NO_NATIVE)
  #if defined(SIMDE_ARCH_X86_FMA)
    #define SIMDE_FMA_NATIVE
  #elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_NO_ARM_NEON) && !defined(SIMDE_FMA_NO_ARM_NEON)
    #define SIMDE_FMA_NEON
  #elif defined(SIMDE_ARCH_WASM_SIMD128) && !defined(SIMDE_NO_WASM_SIMD128) && !defined(SIMDE_FMA_NO_WASM_SIMD128)
    #define SIMDE_FMA_WASM_SIMD128
  #elif defined(SIMDE_ARCH_POWER_ALTIVEC) && !defined(SIMDE_NO_POWER_ALTIVEC) && !defined(SIMDE_FMA_NO_POWER_ALTIVEC)
    #define SIMDE_FMA_POWER_ALTIVEC
  #endif
#endif

#if !defined(SIMDE_AVX512F_NATIVE) && !defined(SIMDE_NO_NATIVE) && !defined(SIMDE_AVX512F_NO_NATIVE)
  #if defined(SIMDE_ARCH_X86_AVX512F)
    #define SIMDE_AVX512F_NATIVE
  #elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_NO_ARM_NEON) && !defined(SIMDE_AVX512F_NO_ARM_NEON)
    #define SIMDE_AVX512F_NEON
  #elif defined(SIMDE_ARCH_WASM_SIMD128) && !defined(SIMDE_NO_WASM_SIMD128) && !defined(SIMDE_AVX512F_NO_WASM_SIMD128)
    #define SIMDE_AVX512F_WASM_SIMD128
  #elif defined(SIMDE_ARCH_POWER_ALTIVEC) && !defined(SIMDE_NO_POWER_ALTIVEC) && !defined(SIMDE_AVX512F_NO_POWER_ALTIVEC)
    #define SIMDE_AVX512F_POWER_ALTIVEC
  #endif
#endif

#if !defined(SIMDE_AVX512BW_NATIVE) && !defined(SIMDE_NO_NATIVE) && !defined(SIMDE_AVX512BW_NO_NATIVE)
  #if defined(SIMDE_ARCH_X86_AVX512BW)
    #define SIMDE_AVX512BW_NATIVE
  #elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_NO_ARM_NEON) && !defined(SIMDE_AVX512BW_NO_ARM_NEON)
    #define SIMDE_AVX512BW_NEON
  #elif defined(SIMDE_ARCH_WASM_SIMD128) && !defined(SIMDE_NO_WASM_SIMD128) && !defined(SIMDE_AVX512BW_NO_WASM_SIMD128)
    #define SIMDE_AVX512BW_WASM_SIMD128
  #elif defined(SIMDE_ARCH_POWER_ALTIVEC) && !defined(SIMDE_NO_POWER_ALTIVEC) && !defined(SIMDE_AVX512BW_NO_POWER_ALTIVEC)
    #define SIMDE_AVX512BW_POWER_ALTIVEC
  #endif
#endif

#if !defined(SIMDE_AVX512VL_NATIVE) && !defined(SIMDE_NO_NATIVE) && !defined(SIMDE_AVX512VL_NO_NATIVE)
  #if defined(SIMDE_ARCH_X86_AVX512VL)
    #define SIMDE_AVX512VL_NATIVE
  #elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_NO_ARM_NEON) && !defined(SIMDE_AVX512VL_NO_ARM_NEON)
    #define SIMDE_AVX512VL_NEON
  #elif defined(SIMDE_ARCH_WASM_SIMD128) && !defined(SIMDE_NO_WASM_SIMD128) && !defined(SIMDE_AVX512VL_NO_WASM_SIMD128)
    #define SIMDE_AVX512VL_WASM_SIMD128
  #elif defined(SIMDE_ARCH_POWER_ALTIVEC) && !defined(SIMDE_NO_POWER_ALTIVEC) && !defined(SIMDE_AVX512VL_NO_POWER_ALTIVEC)
    #define SIMDE_AVX512VL_POWER_ALTIVEC
  #endif
#endif

#if !defined(SIMDE_AVX512DQ_NATIVE) && !defined(SIMDE_NO_NATIVE) && !defined(SIMDE_AVX512DQ_NO_NATIVE)
  #if defined(SIMDE_ARCH_X86_AVX512DQ)
    #define SIMDE_AVX512DQ_NATIVE
  #elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_NO_ARM_NEON) && !defined(SIMDE_AVX512DQ_NO_ARM_NEON)
    #define SIMDE_AVX512DQ_NEON
  #elif defined(SIMDE_ARCH_WASM_SIMD128) && !defined(SIMDE_NO_WASM_SIMD128) && !defined(SIMDE_AVX512DQ_NO_WASM_SIMD128)
    #define SIMDE_AVX512DQ_WASM_SIMD128
  #elif defined(SIMDE_ARCH_POWER_ALTIVEC) && !defined(SIMDE_NO_POWER_ALTIVEC) && !defined(SIMDE_AVX512DQ_NO_POWER_ALTIVEC)
    #define SIMDE_AVX512DQ_POWER_ALTIVEC
  #endif
#endif

#if !defined(SIMDE_SVML_NATIVE) && !defined(SIMDE_NO_NATIVE) && !defined(SIMDE_SVML_NO_NATIVE)
  #if defined(SIMDE_ARCH_X86_SVML)
    #define SIMDE_SVML_NATIVE
  #elif defined(SIMDE_ARCH_ARM_NEON) && !defined(SIMDE_NO_ARM_NEON) && !defined(SIMDE_SVML_NO_ARM_NEON)
    #define SIMDE_SVML_NEON
  #elif defined(SIMDE_ARCH_WASM_SIMD128) && !defined(SIMDE_NO_WASM_SIMD128) && !defined(SIMDE_SVML_NO_WASM_SIMD128)
    #define SIMDE_SVML_WASM_SIMD128
  #elif defined(SIMDE_ARCH_POWER_ALTIVEC) && !defined(SIMDE_NO_POWER_ALTIVEC) && !defined(SIMDE_SVML_NO_POWER_ALTIVEC)
    #define SIMDE_SVML_POWER_ALTIVEC
  #endif
#endif

#if defined(SIMDE_ARCH_ARM_NEON)
  #include <arm_neon.h>
#elif defined(SIMDE_ARCH_WASM_SIMD128)
  #if !defined(__wasm_unimplemented_simd128__)
    #define __wasm_unimplemented_simd128__
  #endif
  #include <wasm_simd128.h>
#elif defined(SIMDE_ARCH_POWER_ALTIVEC)
  #include <altivec.h>
#endif

#endif /* !defined(SIMDE_FEATURES_H) */
