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

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* ref: https://github.com/kokke/tiny-AES-c/blob/master/aes.c */
static const uint8_t sbox[256] = {
  //0     1    2      3     4    5     6     7      8    9     A      B    C     D     E     F
  0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
  0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
  0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
  0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
  0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
  0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
  0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
  0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
  0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
  0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
  0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
  0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
  0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
  0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
  0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
  0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 };

static const uint8_t rsbox[256] = {
  0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
  0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
  0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
  0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
  0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
  0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
  0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
  0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
  0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
  0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
  0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
  0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
  0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
  0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
  0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
  0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d };

static uint8_t xtime(uint8_t x)
{
  return ((x<<1) ^ (((x>>7) & 1) * 0x1b));
}

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vaeseq_u8(simde_uint8x16_t data, simde_uint8x16_t key) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
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
      r_.values[i] = sbox[r_.values[i]];
    }
    return simde_uint8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vaeseq_u8
  #define vaeseq_u8(a, b) simde_vaeseq_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vaesdq_u8(simde_uint8x16_t data, simde_uint8x16_t key) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
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
      r_.values[i] = rsbox[r_.values[i]];
    }
    return simde_uint8x16_from_private(r_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vaesdq_u8
  #define vaesdq_u8(a, b) simde_vaesdq_u8((a), (b))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_uint8x16_t
simde_vaesmcq_u8(simde_uint8x16_t data) {
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
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
  #define vaesmcq_u8(a) simde_vaesmcq_u8((a))
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
  #if defined(SIMDE_ARM_NEON_A32V8_NATIVE)
    return vaesimcq_u8(data);
  #else
    /* ref: https://github.com/kokke/tiny-AES-c/blob/master/aes.c */
    simde_uint8x16_private
      a_ = simde_uint8x16_to_private(data);
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
    return simde_uint8x16_from_private(a_);
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V8_ENABLE_NATIVE_ALIASES)
  #undef vaesimcq_u8
  #define vaesimcq_u8(a) simde_vaesimcq_u8((a))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_AES_H) */
