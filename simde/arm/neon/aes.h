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
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 */

#if !defined(SIMDE_ARM_NEON_AES_H)
#define SIMDE_ARM_NEON_AES_H

#include "types.h"
#include "../../simde-aes.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

static uint8_t xtime(uint8_t x)
{
  return HEDLEY_STATIC_CAST(uint8_t, (x<<1) ^ (((x>>7) & 1) * 0x1b));
}

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vaeseq_u8(simde_uint8x16_t data, simde_uint8x16_t key) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(__ARM_FEATURE_AES)
    return vaeseq_u8(data, key);
  #else
    /* ref: https://github.com/kokke/tiny-AES-c/blob/master/aes.c */
    simde_uint8x16_private
      r_,
      a_ = simde_uint8x16_to_private(data),
      b_ = simde_uint8x16_to_private(key);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] ^ b_.values[i];
    }
    // AESShiftRows
    uint8_t tmp;
    tmp = r_.values[1];
    r_.values[1] = r_.values[5];
    r_.values[5] = r_.values[9];
    r_.values[9] = r_.values[13];
    r_.values[13] = tmp;

    tmp = r_.values[2];
    r_.values[2] = r_.values[10];
    r_.values[10] = tmp;

    tmp = r_.values[6];
    r_.values[6] = r_.values[14];
    r_.values[14] = tmp;

    tmp = r_.values[3];
    r_.values[3] = r_.values[15];
    r_.values[15] = r_.values[11];
    r_.values[11] = r_.values[7];
    r_.values[7] = tmp;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = simde_x_aes_s_box[r_.values[i]];
    }
    return simde_uint8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vaeseq_u8
  #define vaeseq_u8(data, key) simde_vaeseq_u8((data), (key))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vaesdq_u8(simde_uint8x16_t data, simde_uint8x16_t key) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(__ARM_FEATURE_AES)
    return vaesdq_u8(data, key);
  #else
    /* ref: https://github.com/kokke/tiny-AES-c/blob/master/aes.c */
    simde_uint8x16_private
      r_,
      a_ = simde_uint8x16_to_private(data),
      b_ = simde_uint8x16_to_private(key);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = a_.values[i] ^ b_.values[i];
    }
    // AESInvShiftRows
    uint8_t tmp;
    tmp = r_.values[13];
    r_.values[13] = r_.values[9];
    r_.values[9] = r_.values[5];
    r_.values[5] = r_.values[1];
    r_.values[1] = tmp;

    tmp = r_.values[2];
    r_.values[2] = r_.values[10];
    r_.values[10] = tmp;

    tmp = r_.values[6];
    r_.values[6] = r_.values[14];
    r_.values[14] = tmp;

    tmp = r_.values[3];
    r_.values[3] = r_.values[7];
    r_.values[7] = r_.values[11];
    r_.values[11] = r_.values[15];
    r_.values[15] = tmp;
    for(int i = 0; i < 16; ++i) {
      r_.values[i] = simde_x_aes_inv_s_box[r_.values[i]];
    }
    return simde_uint8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vaesdq_u8
  #define vaesdq_u8(data, key) simde_vaesdq_u8((data), (key))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vaesmcq_u8(simde_uint8x16_t data) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(__ARM_FEATURE_AES)
    return vaesmcq_u8(data);
  #else
    /* ref: https://github.com/kokke/tiny-AES-c/blob/master/aes.c */
    simde_uint8x16_private
      a_ = simde_uint8x16_to_private(data);
    uint8_t i;
    uint8_t Tmp, Tm, t;
    for (i = 0; i < 4; ++i)
    {
      t   = a_.values[i*4+0];
      Tmp = a_.values[i*4+0] ^ a_.values[i*4+1] ^ a_.values[i*4+2] ^ a_.values[i*4+3] ;
      Tm  = a_.values[i*4+0] ^ a_.values[i*4+1] ; Tm = xtime(Tm);  a_.values[i*4+0] ^= Tm ^ Tmp ;
      Tm  = a_.values[i*4+1] ^ a_.values[i*4+2] ; Tm = xtime(Tm);  a_.values[i*4+1] ^= Tm ^ Tmp ;
      Tm  = a_.values[i*4+2] ^ a_.values[i*4+3] ; Tm = xtime(Tm);  a_.values[i*4+2] ^= Tm ^ Tmp ;
      Tm  = a_.values[i*4+3] ^ t ;        Tm = xtime(Tm);  a_.values[i*4+3] ^= Tm ^ Tmp ;
    }
    return simde_uint8x16_from_private(a_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vaesmcq_u8
  #define vaesmcq_u8(data) simde_vaesmcq_u8((data))
#endif

static uint8_t Multiply(uint8_t x, uint8_t y)
{
  return (((y & 1) * x) ^
       ((y>>1 & 1) * xtime(x)) ^
       ((y>>2 & 1) * xtime(xtime(x))) ^
       ((y>>3 & 1) * xtime(xtime(xtime(x)))) ^
       ((y>>4 & 1) * xtime(xtime(xtime(xtime(x)))))); /* this last call to xtime() can be omitted */
}

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vaesimcq_u8(simde_uint8x16_t data) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE) && defined(__ARM_FEATURE_AES)
    return vaesimcq_u8(data);
  #else
    /* ref: https://github.com/kokke/tiny-AES-c/blob/master/aes.c */
    simde_uint8x16_private
      a_ = simde_uint8x16_to_private(data);
    #if defined(SIMDE_X86_AES_NATIVE)
      a_.m128i = _mm_aesimc_si128(a_.m128i);
    #else
      int i;
      uint8_t a, b, c, d;
      for (i = 0; i < 4; ++i)
      {
        a = a_.values[i*4+0];
        b = a_.values[i*4+1];
        c = a_.values[i*4+2];
        d = a_.values[i*4+3];

        a_.values[i*4+0] = Multiply(a, 0x0e) ^ Multiply(b, 0x0b) ^ Multiply(c, 0x0d) ^ Multiply(d, 0x09);
        a_.values[i*4+1] = Multiply(a, 0x09) ^ Multiply(b, 0x0e) ^ Multiply(c, 0x0b) ^ Multiply(d, 0x0d);
        a_.values[i*4+2] = Multiply(a, 0x0d) ^ Multiply(b, 0x09) ^ Multiply(c, 0x0e) ^ Multiply(d, 0x0b);
        a_.values[i*4+3] = Multiply(a, 0x0b) ^ Multiply(b, 0x0d) ^ Multiply(c, 0x09) ^ Multiply(d, 0x0e);
      }
    #endif
    return simde_uint8x16_from_private(a_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vaesimcq_u8
  #define vaesimcq_u8(data) simde_vaesimcq_u8((data))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_AES_H) */
