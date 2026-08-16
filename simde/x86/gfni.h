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
 *   2020-2021 Christopher Moore <moore@free.fr>
 *   2020-2022 Evan Nemerson <evan@nemerson.com>
 *   2023      Michael R. Crusoe <crusoe@debian.org>
 */

#if !defined(SIMDE_X86_GFNI_H)
#define SIMDE_X86_GFNI_H

#include <stddef.h>
#include <stdint.h>

#include "../hedley.h"
#include "../simde-diagnostic.h"
#include "../simde-features.h"
#include "../simde-common.h"
#include "sse2.h"
#include "sse4.1.h"
#include "ssse3.h"
#include "avx.h"
#include "avx2.h"
#include "aes.h"
#include "avx512/types.h"
#include "avx512/add.h"
#include "avx512/and.h"
#include "avx512/broadcast.h"
#include "avx512/cmpeq.h"
#include "avx512/cmpge.h"
#include "avx512/cmpgt.h"
#include "avx512/cmplt.h"
#include "avx512/extract.h"
#include "avx512/insert.h"
#include "avx512/kshift.h"
#include "avx512/mov.h"
#include "avx512/mov_mask.h"
#include "avx512/permutex2var.h"
#include "avx512/set.h"
#include "avx512/set1.h"
#include "avx512/setzero.h"
#include "avx512/shuffle.h"
#include "avx512/srli.h"
#include "avx512/test.h"
#include "avx512/xor.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* In all the *gf2p8affine* intrinsics the argument b must be a compile-time constant so we must use macros and simde_x_mm* helper functions */

/* N.B. The _mm*gf2p8affineinv_epi64_epi8 and _mm*gf2p8mul_epi8 intrinsics are for a Field Generator Polynomial (FGP) (aka reduction polynomial) of 0x11B */
/* Only the _mm*gf2p8affine_epi64_epi8 intrinsics do not assume this specific FGP */

/* The field generator polynomial is 0x11B but we make the 0x100 bit implicit to fit inside 8 bits */
#define SIMDE_X86_GFNI_FGP 0x1B

/* Feature groups used by the algorithms below.
 * SIMDE_X_GFNI_HAVE_AES: a hardware AES S-box is reachable through
 *   simde_mm_aesenclast_si128 (x86 AES-NI, or ARMv8 crypto). We borrow it to
 *   compute the GF(2^8) inverse.
 * SIMDE_X_GFNI_HAVE_SHUFFLE: a byte-shuffle (PSHUFB / TBL / vec_perm / swizzle)
 *   is available, so the nibble-decomposition and GF((2^4)^2) tower-field
 *   algorithms can run. These are all expressed through simde_mm_shuffle_epi8
 *   et al. so a single implementation covers every backend. */
#if defined(SIMDE_X86_AES_NATIVE) || (defined(SIMDE_ARM_NEON_A32V7_NATIVE) && defined(SIMDE_ARCH_ARM_CRYPTO))
  #define SIMDE_X_GFNI_HAVE_AES
#endif
#if defined(SIMDE_X86_SSSE3_NATIVE) || defined(SIMDE_ARM_NEON_A32V7_NATIVE) || defined(SIMDE_POWER_ALTIVEC_P6_NATIVE) || defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE) || defined(SIMDE_WASM_SIMD128_NATIVE) || defined(SIMDE_MIPS_MSA_NATIVE)
  #define SIMDE_X_GFNI_HAVE_SHUFFLE
#endif

/* Computing the inverse of a GF element is expensive so use this LUT for an FGP
 * of 0x11B. Only the scalar fallback needs it; the AES-borrow and tower-field
 * paths compute the inverse without a 256-byte table. */
#if !defined(SIMDE_X_GFNI_HAVE_AES) && !defined(SIMDE_X_GFNI_HAVE_SHUFFLE)
static const union {
  uint8_t      u8[256];
  simde__m128i m128i[16];
} simde_x_gf2p8inverse_lut = {
  {
   0x00, 0x01, 0x8d, 0xf6, 0xcb, 0x52, 0x7b, 0xd1, 0xe8, 0x4f, 0x29, 0xc0, 0xb0, 0xe1, 0xe5, 0xc7,
   0x74, 0xb4, 0xaa, 0x4b, 0x99, 0x2b, 0x60, 0x5f, 0x58, 0x3f, 0xfd, 0xcc, 0xff, 0x40, 0xee, 0xb2,
   0x3a, 0x6e, 0x5a, 0xf1, 0x55, 0x4d, 0xa8, 0xc9, 0xc1, 0x0a, 0x98, 0x15, 0x30, 0x44, 0xa2, 0xc2,
   0x2c, 0x45, 0x92, 0x6c, 0xf3, 0x39, 0x66, 0x42, 0xf2, 0x35, 0x20, 0x6f, 0x77, 0xbb, 0x59, 0x19,
   0x1d, 0xfe, 0x37, 0x67, 0x2d, 0x31, 0xf5, 0x69, 0xa7, 0x64, 0xab, 0x13, 0x54, 0x25, 0xe9, 0x09,
   0xed, 0x5c, 0x05, 0xca, 0x4c, 0x24, 0x87, 0xbf, 0x18, 0x3e, 0x22, 0xf0, 0x51, 0xec, 0x61, 0x17,
   0x16, 0x5e, 0xaf, 0xd3, 0x49, 0xa6, 0x36, 0x43, 0xf4, 0x47, 0x91, 0xdf, 0x33, 0x93, 0x21, 0x3b,
   0x79, 0xb7, 0x97, 0x85, 0x10, 0xb5, 0xba, 0x3c, 0xb6, 0x70, 0xd0, 0x06, 0xa1, 0xfa, 0x81, 0x82,
   0x83, 0x7e, 0x7f, 0x80, 0x96, 0x73, 0xbe, 0x56, 0x9b, 0x9e, 0x95, 0xd9, 0xf7, 0x02, 0xb9, 0xa4,
   0xde, 0x6a, 0x32, 0x6d, 0xd8, 0x8a, 0x84, 0x72, 0x2a, 0x14, 0x9f, 0x88, 0xf9, 0xdc, 0x89, 0x9a,
   0xfb, 0x7c, 0x2e, 0xc3, 0x8f, 0xb8, 0x65, 0x48, 0x26, 0xc8, 0x12, 0x4a, 0xce, 0xe7, 0xd2, 0x62,
   0x0c, 0xe0, 0x1f, 0xef, 0x11, 0x75, 0x78, 0x71, 0xa5, 0x8e, 0x76, 0x3d, 0xbd, 0xbc, 0x86, 0x57,
   0x0b, 0x28, 0x2f, 0xa3, 0xda, 0xd4, 0xe4, 0x0f, 0xa9, 0x27, 0x53, 0x04, 0x1b, 0xfc, 0xac, 0xe6,
   0x7a, 0x07, 0xae, 0x63, 0xc5, 0xdb, 0xe2, 0xea, 0x94, 0x8b, 0xc4, 0xd5, 0x9d, 0xf8, 0x90, 0x6b,
   0xb1, 0x0d, 0xd6, 0xeb, 0xc6, 0x0e, 0xcf, 0xad, 0x08, 0x4e, 0xd7, 0xe3, 0x5d, 0x50, 0x1e, 0xb3,
   0x5b, 0x23, 0x38, 0x34, 0x68, 0x46, 0x03, 0x8c, 0xdd, 0x9c, 0x7d, 0xa0, 0xcd, 0x1a, 0x41, 0x1c
  }
};
#endif /* scalar inverse LUT */

/* GFNI matrix (qword) for "multiply by the GF(2^8) constant k": column j is
 * k (x) 2^j. Lets a constant-operand GF(2^8) multiply degenerate to an affine
 * transform (then to nibble decomposition). */
/* Fully precomputed so that, for a compile-time-constant multiplier k, the
 * matrix simde_x_gf2p8_mul_matrix_lut[k] folds to a literal (verified:
 * __builtin_constant_p(lut[const]) is true). That lets the constant-operand
 * GF(2^8) multiply collapse to matrix_multiply's compile-time nibble path
 * (two shuffles at run time) instead of rebuilding the matrix per call.
 * Generated for FGP 0x1B; entry k is the GF(2)-affine matrix of "multiply by k". */
#if defined(SIMDE_CHECK_CONSTANT_) && defined(SIMDE_X_GFNI_HAVE_SHUFFLE)
static const uint64_t simde_x_gf2p8_mul_matrix_lut[256] = {
    UINT64_C(0x0000000000000000),UINT64_C(0x0102040810204080),UINT64_C(0x8081028488102040),UINT64_C(0x8183068c983060c0),
    UINT64_C(0x40c08142c4881020),UINT64_C(0x41c2854ad4a850a0),UINT64_C(0xc04183c64c983060),UINT64_C(0xc14387ce5cb870e0),
    UINT64_C(0x2060c0a162c48810),UINT64_C(0x2162c4a972e4c890),UINT64_C(0xa0e1c225ead4a850),UINT64_C(0xa1e3c62dfaf4e8d0),
    UINT64_C(0x60a041e3a64c9830),UINT64_C(0x61a245ebb66cd8b0),UINT64_C(0xe02143672e5cb870),UINT64_C(0xe123476f3e7cf8f0),
    UINT64_C(0x103060d0b162c488),UINT64_C(0x113264d8a1428408),UINT64_C(0x90b162543972e4c8),UINT64_C(0x91b3665c2952a448),
    UINT64_C(0x50f0e19275ead4a8),UINT64_C(0x51f2e59a65ca9428),UINT64_C(0xd071e316fdfaf4e8),UINT64_C(0xd173e71eeddab468),
    UINT64_C(0x3050a071d3a64c98),UINT64_C(0x3152a479c3860c18),UINT64_C(0xb0d1a2f55bb66cd8),UINT64_C(0xb1d3a6fd4b962c58),
    UINT64_C(0x70902133172e5cb8),UINT64_C(0x7192253b070e1c38),UINT64_C(0xf01123b79f3e7cf8),UINT64_C(0xf11327bf8f1e3c78),
    UINT64_C(0x889830e858b162c4),UINT64_C(0x899a34e048912244),UINT64_C(0x0819326cd0a14284),UINT64_C(0x091b3664c0810204),
    UINT64_C(0xc858b1aa9c3972e4),UINT64_C(0xc95ab5a28c193264),UINT64_C(0x48d9b32e142952a4),UINT64_C(0x49dbb72604091224),
    UINT64_C(0xa8f8f0493a75ead4),UINT64_C(0xa9faf4412a55aa54),UINT64_C(0x2879f2cdb265ca94),UINT64_C(0x297bf6c5a2458a14),
    UINT64_C(0xe838710bfefdfaf4),UINT64_C(0xe93a7503eeddba74),UINT64_C(0x68b9738f76eddab4),UINT64_C(0x69bb778766cd9a34),
    UINT64_C(0x98a85038e9d3a64c),UINT64_C(0x99aa5430f9f3e6cc),UINT64_C(0x182952bc61c3860c),UINT64_C(0x192b56b471e3c68c),
    UINT64_C(0xd868d17a2d5bb66c),UINT64_C(0xd96ad5723d7bf6ec),UINT64_C(0x58e9d3fea54b962c),UINT64_C(0x59ebd7f6b56bd6ac),
    UINT64_C(0xb8c890998b172e5c),UINT64_C(0xb9ca94919b376edc),UINT64_C(0x3849921d03070e1c),UINT64_C(0x394b961513274e9c),
    UINT64_C(0xf80811db4f9f3e7c),UINT64_C(0xf90a15d35fbf7efc),UINT64_C(0x7889135fc78f1e3c),UINT64_C(0x798b1757d7af5ebc),
    UINT64_C(0xc44c98f42c58b162),UINT64_C(0xc54e9cfc3c78f1e2),UINT64_C(0x44cd9a70a4489122),UINT64_C(0x45cf9e78b468d1a2),
    UINT64_C(0x848c19b6e8d0a142),UINT64_C(0x858e1dbef8f0e1c2),UINT64_C(0x040d1b3260c08102),UINT64_C(0x050f1f3a70e0c182),
    UINT64_C(0xe42c58554e9c3972),UINT64_C(0xe52e5c5d5ebc79f2),UINT64_C(0x64ad5ad1c68c1932),UINT64_C(0x65af5ed9d6ac59b2),
    UINT64_C(0xa4ecd9178a142952),UINT64_C(0xa5eedd1f9a3469d2),UINT64_C(0x246ddb9302040912),UINT64_C(0x256fdf9b12244992),
    UINT64_C(0xd47cf8249d3a75ea),UINT64_C(0xd57efc2c8d1a356a),UINT64_C(0x54fdfaa0152a55aa),UINT64_C(0x55fffea8050a152a),
    UINT64_C(0x94bc796659b265ca),UINT64_C(0x95be7d6e4992254a),UINT64_C(0x143d7be2d1a2458a),UINT64_C(0x153f7feac182050a),
    UINT64_C(0xf41c3885fffefdfa),UINT64_C(0xf51e3c8defdebd7a),UINT64_C(0x749d3a0177eeddba),UINT64_C(0x759f3e0967ce9d3a),
    UINT64_C(0xb4dcb9c73b76edda),UINT64_C(0xb5debdcf2b56ad5a),UINT64_C(0x345dbb43b366cd9a),UINT64_C(0x355fbf4ba3468d1a),
    UINT64_C(0x4cd4a81c74e9d3a6),UINT64_C(0x4dd6ac1464c99326),UINT64_C(0xcc55aa98fcf9f3e6),UINT64_C(0xcd57ae90ecd9b366),
    UINT64_C(0x0c14295eb061c386),UINT64_C(0x0d162d56a0418306),UINT64_C(0x8c952bda3871e3c6),UINT64_C(0x8d972fd22851a346),
    UINT64_C(0x6cb468bd162d5bb6),UINT64_C(0x6db66cb5060d1b36),UINT64_C(0xec356a399e3d7bf6),UINT64_C(0xed376e318e1d3b76),
    UINT64_C(0x2c74e9ffd2a54b96),UINT64_C(0x2d76edf7c2850b16),UINT64_C(0xacf5eb7b5ab56bd6),UINT64_C(0xadf7ef734a952b56),
    UINT64_C(0x5ce4c8ccc58b172e),UINT64_C(0x5de6ccc4d5ab57ae),UINT64_C(0xdc65ca484d9b376e),UINT64_C(0xdd67ce405dbb77ee),
    UINT64_C(0x1c24498e0103070e),UINT64_C(0x1d264d861123478e),UINT64_C(0x9ca54b0a8913274e),UINT64_C(0x9da74f02993367ce),
    UINT64_C(0x7c84086da74f9f3e),UINT64_C(0x7d860c65b76fdfbe),UINT64_C(0xfc050ae92f5fbf7e),UINT64_C(0xfd070ee13f7ffffe),
    UINT64_C(0x3c44892f63c78f1e),UINT64_C(0x3d468d2773e7cf9e),UINT64_C(0xbcc58babebd7af5e),UINT64_C(0xbdc78fa3fbf7efde),
    UINT64_C(0x62a64cfa962c58b1),UINT64_C(0x63a448f2860c1831),UINT64_C(0xe2274e7e1e3c78f1),UINT64_C(0xe3254a760e1c3871),
    UINT64_C(0x2266cdb852a44891),UINT64_C(0x2364c9b042840811),UINT64_C(0xa2e7cf3cdab468d1),UINT64_C(0xa3e5cb34ca942851),
    UINT64_C(0x42c68c5bf4e8d0a1),UINT64_C(0x43c48853e4c89021),UINT64_C(0xc2478edf7cf8f0e1),UINT64_C(0xc3458ad76cd8b061),
    UINT64_C(0x02060d193060c081),UINT64_C(0x0304091120408001),UINT64_C(0x82870f9db870e0c1),UINT64_C(0x83850b95a850a041),
    UINT64_C(0x72962c2a274e9c39),UINT64_C(0x73942822376edcb9),UINT64_C(0xf2172eaeaf5ebc79),UINT64_C(0xf3152aa6bf7efcf9),
    UINT64_C(0x3256ad68e3c68c19),UINT64_C(0x3354a960f3e6cc99),UINT64_C(0xb2d7afec6bd6ac59),UINT64_C(0xb3d5abe47bf6ecd9),
    UINT64_C(0x52f6ec8b458a1429),UINT64_C(0x53f4e88355aa54a9),UINT64_C(0xd277ee0fcd9a3469),UINT64_C(0xd375ea07ddba74e9),
    UINT64_C(0x12366dc981020409),UINT64_C(0x133469c191224489),UINT64_C(0x92b76f4d09122449),UINT64_C(0x93b56b45193264c9),
    UINT64_C(0xea3e7c12ce9d3a75),UINT64_C(0xeb3c781adebd7af5),UINT64_C(0x6abf7e96468d1a35),UINT64_C(0x6bbd7a9e56ad5ab5),
    UINT64_C(0xaafefd500a152a55),UINT64_C(0xabfcf9581a356ad5),UINT64_C(0x2a7fffd482050a15),UINT64_C(0x2b7dfbdc92254a95),
    UINT64_C(0xca5ebcb3ac59b265),UINT64_C(0xcb5cb8bbbc79f2e5),UINT64_C(0x4adfbe3724499225),UINT64_C(0x4bddba3f3469d2a5),
    UINT64_C(0x8a9e3df168d1a245),UINT64_C(0x8b9c39f978f1e2c5),UINT64_C(0x0a1f3f75e0c18205),UINT64_C(0x0b1d3b7df0e1c285),
    UINT64_C(0xfa0e1cc27ffffefd),UINT64_C(0xfb0c18ca6fdfbe7d),UINT64_C(0x7a8f1e46f7efdebd),UINT64_C(0x7b8d1a4ee7cf9e3d),
    UINT64_C(0xbace9d80bb77eedd),UINT64_C(0xbbcc9988ab57ae5d),UINT64_C(0x3a4f9f043367ce9d),UINT64_C(0x3b4d9b0c23478e1d),
    UINT64_C(0xda6edc631d3b76ed),UINT64_C(0xdb6cd86b0d1b366d),UINT64_C(0x5aefdee7952b56ad),UINT64_C(0x5beddaef850b162d),
    UINT64_C(0x9aae5d21d9b366cd),UINT64_C(0x9bac5929c993264d),UINT64_C(0x1a2f5fa551a3468d),UINT64_C(0x1b2d5bad4183060d),
    UINT64_C(0xa6ead40eba74e9d3),UINT64_C(0xa7e8d006aa54a953),UINT64_C(0x266bd68a3264c993),UINT64_C(0x2769d28222448913),
    UINT64_C(0xe62a554c7efcf9f3),UINT64_C(0xe72851446edcb973),UINT64_C(0x66ab57c8f6ecd9b3),UINT64_C(0x67a953c0e6cc9933),
    UINT64_C(0x868a14afd8b061c3),UINT64_C(0x878810a7c8902143),UINT64_C(0x060b162b50a04183),UINT64_C(0x0709122340800103),
    UINT64_C(0xc64a95ed1c3871e3),UINT64_C(0xc74891e50c183163),UINT64_C(0x46cb9769942851a3),UINT64_C(0x47c9936184081123),
    UINT64_C(0xb6dab4de0b162d5b),UINT64_C(0xb7d8b0d61b366ddb),UINT64_C(0x365bb65a83060d1b),UINT64_C(0x3759b25293264d9b),
    UINT64_C(0xf61a359ccf9e3d7b),UINT64_C(0xf7183194dfbe7dfb),UINT64_C(0x769b3718478e1d3b),UINT64_C(0x7799331057ae5dbb),
    UINT64_C(0x96ba747f69d2a54b),UINT64_C(0x97b8707779f2e5cb),UINT64_C(0x163b76fbe1c2850b),UINT64_C(0x173972f3f1e2c58b),
    UINT64_C(0xd67af53dad5ab56b),UINT64_C(0xd778f135bd7af5eb),UINT64_C(0x56fbf7b9254a952b),UINT64_C(0x57f9f3b1356ad5ab),
    UINT64_C(0x2e72e4e6e2c58b17),UINT64_C(0x2f70e0eef2e5cb97),UINT64_C(0xaef3e6626ad5ab57),UINT64_C(0xaff1e26a7af5ebd7),
    UINT64_C(0x6eb265a4264d9b37),UINT64_C(0x6fb061ac366ddbb7),UINT64_C(0xee336720ae5dbb77),UINT64_C(0xef316328be7dfbf7),
    UINT64_C(0x0e12244780010307),UINT64_C(0x0f10204f90214387),UINT64_C(0x8e9326c308112347),UINT64_C(0x8f9122cb183163c7),
    UINT64_C(0x4ed2a50544891327),UINT64_C(0x4fd0a10d54a953a7),UINT64_C(0xce53a781cc993367),UINT64_C(0xcf51a389dcb973e7),
    UINT64_C(0x3e42843653a74f9f),UINT64_C(0x3f40803e43870f1f),UINT64_C(0xbec386b2dbb76fdf),UINT64_C(0xbfc182bacb972f5f),
    UINT64_C(0x7e820574972f5fbf),UINT64_C(0x7f80017c870f1f3f),UINT64_C(0xfe0307f01f3f7fff),UINT64_C(0xff0103f80f1f3f7f),
    UINT64_C(0x1e2244973163c78f),UINT64_C(0x1f20409f2143870f),UINT64_C(0x9ea34613b973e7cf),UINT64_C(0x9fa1421ba953a74f),
    UINT64_C(0x5ee2c5d5f5ebd7af),UINT64_C(0x5fe0c1dde5cb972f),UINT64_C(0xde63c7517dfbf7ef),UINT64_C(0xdf61c3596ddbb76f)
};
#endif /* SIMDE_CHECK_CONSTANT_ && SIMDE_X_GFNI_HAVE_SHUFFLE */

/* Apply one GF(2) affine matrix row-set (a GFNI qword, no constant) to a single
 * byte. Identical to the scalar reference in the matrix-multiply fallback, so
 * it can generate the nibble tables for a compile-time-constant matrix. */
SIMDE_FUNCTION_ATTRIBUTES
uint8_t
simde_x_gf2p8_apply_matrix_byte (uint64_t A, uint8_t v) {
  const uint64_t ones = UINT64_C(0x0101010101010101);
  const uint64_t mask = UINT64_C(0x0102040810204080);
  uint64_t q = simde_endian_bswap64_le(A);
  q &= HEDLEY_STATIC_CAST(uint64_t, v) * ones;
  q ^= q >> 4; q ^= q >> 2; q ^= q >> 1;
  q &= ones; q *= 255; q &= mask;
  q |= q >> 32; q |= q >> 16; q |= q >> 8;
  return HEDLEY_STATIC_CAST(uint8_t, q);
}

/* Per-nibble tables for a (compile-time-constant) GF(2) affine matrix M.
 * M.x == shuffle(lo_table, x & 0xF) ^ shuffle(hi_table, x >> 4). When M is a
 * constant these fold to constant vectors at compile time. */
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_gf2p8_matrix_nibble_lo (uint64_t M) {
  #define SIMDE_X_GFNI_MROW(n) HEDLEY_STATIC_CAST(int8_t, simde_x_gf2p8_apply_matrix_byte(M, HEDLEY_STATIC_CAST(uint8_t, (n))))
  simde__m128i r = simde_mm_set_epi8(
    SIMDE_X_GFNI_MROW(15), SIMDE_X_GFNI_MROW(14), SIMDE_X_GFNI_MROW(13), SIMDE_X_GFNI_MROW(12),
    SIMDE_X_GFNI_MROW(11), SIMDE_X_GFNI_MROW(10), SIMDE_X_GFNI_MROW( 9), SIMDE_X_GFNI_MROW( 8),
    SIMDE_X_GFNI_MROW( 7), SIMDE_X_GFNI_MROW( 6), SIMDE_X_GFNI_MROW( 5), SIMDE_X_GFNI_MROW( 4),
    SIMDE_X_GFNI_MROW( 3), SIMDE_X_GFNI_MROW( 2), SIMDE_X_GFNI_MROW( 1), SIMDE_X_GFNI_MROW( 0));
  #undef SIMDE_X_GFNI_MROW
  return r;
}
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_gf2p8_matrix_nibble_hi (uint64_t M) {
  #define SIMDE_X_GFNI_MROW(n) HEDLEY_STATIC_CAST(int8_t, simde_x_gf2p8_apply_matrix_byte(M, HEDLEY_STATIC_CAST(uint8_t, (n) << 4)))
  simde__m128i r = simde_mm_set_epi8(
    SIMDE_X_GFNI_MROW(15), SIMDE_X_GFNI_MROW(14), SIMDE_X_GFNI_MROW(13), SIMDE_X_GFNI_MROW(12),
    SIMDE_X_GFNI_MROW(11), SIMDE_X_GFNI_MROW(10), SIMDE_X_GFNI_MROW( 9), SIMDE_X_GFNI_MROW( 8),
    SIMDE_X_GFNI_MROW( 7), SIMDE_X_GFNI_MROW( 6), SIMDE_X_GFNI_MROW( 5), SIMDE_X_GFNI_MROW( 4),
    SIMDE_X_GFNI_MROW( 3), SIMDE_X_GFNI_MROW( 2), SIMDE_X_GFNI_MROW( 1), SIMDE_X_GFNI_MROW( 0));
  #undef SIMDE_X_GFNI_MROW
  return r;
}

#if defined(SIMDE_X_GFNI_HAVE_AES)
/* AES-borrow inverse: inv(a) = A_aes^-1 . (SubBytes(a) ^ 0x63).
 * SubBytes(a) = InvShiftRows(AESENCLAST(a, 0)). A_aes^-1 is the fixed inverse
 * AES affine matrix; applied by nibble decomposition with the 0x63 affine
 * constant folded into the low-nibble table. */
static const union { uint8_t u8[16]; simde__m128i m128i; } simde_x_gf2p8_inv_undo_sr = { {
  0, 13, 10, 7, 4, 1, 14, 11, 8, 5, 2, 15, 12, 9, 6, 3 } };
static const union { uint8_t u8[16]; simde__m128i m128i; } simde_x_gf2p8_inv_tlo = { {
  0x05, 0x4f, 0x91, 0xdb, 0x2c, 0x66, 0xb8, 0xf2, 0x57, 0x1d, 0xc3, 0x89, 0x7e, 0x34, 0xea, 0xa0 } };
static const union { uint8_t u8[16]; simde__m128i m128i; } simde_x_gf2p8_inv_thi = { {
  0x00, 0xa4, 0x49, 0xed, 0x92, 0x36, 0xdb, 0x7f, 0x25, 0x81, 0x6c, 0xc8, 0xb7, 0x13, 0xfe, 0x5a } };
#endif /* SIMDE_X_GFNI_HAVE_AES */

#if defined(SIMDE_X_GFNI_HAVE_AES)
/* GFNI qwords (SIMDe convention) for the AES affine matrix and its inverse. */
#define SIMDE_X_GFNI_AAES_FWD UINT64_C(0xF1E3C78F1F3E7CF8)
#define SIMDE_X_GFNI_AAES_INV UINT64_C(0xA44992254A942952)

/* Apply M' = M . A_aes^-1 to one byte (composition of two GFNI matrices). */
SIMDE_FUNCTION_ATTRIBUTES
uint8_t
simde_x_gf2p8_apply_mprime (uint64_t M, uint8_t v) {
  return simde_x_gf2p8_apply_matrix_byte(M, simde_x_gf2p8_apply_matrix_byte(SIMDE_X_GFNI_AAES_INV, v));
}

/* Fused-affineinv nibble tables: result = M'_lo_c'[s&0xF] ^ M'_hi[s>>4] where
 * s = SubBytes(x), M' = M . A_aes^-1, c' = M'.0x63 ^ c folded into the low table.
 * Gives M.inv(x) ^ c directly. Fold to constants when M, c are compile-time. */
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_gf2p8_affineinv_nibble_lo (uint64_t M, uint8_t c) {
  uint8_t cp = HEDLEY_STATIC_CAST(uint8_t, simde_x_gf2p8_apply_mprime(M, 0x63) ^ c);
  #define SIMDE_X_GFNI_IROW(n) HEDLEY_STATIC_CAST(int8_t, simde_x_gf2p8_apply_mprime(M, HEDLEY_STATIC_CAST(uint8_t, (n))) ^ cp)
  simde__m128i r = simde_mm_set_epi8(
    SIMDE_X_GFNI_IROW(15), SIMDE_X_GFNI_IROW(14), SIMDE_X_GFNI_IROW(13), SIMDE_X_GFNI_IROW(12),
    SIMDE_X_GFNI_IROW(11), SIMDE_X_GFNI_IROW(10), SIMDE_X_GFNI_IROW( 9), SIMDE_X_GFNI_IROW( 8),
    SIMDE_X_GFNI_IROW( 7), SIMDE_X_GFNI_IROW( 6), SIMDE_X_GFNI_IROW( 5), SIMDE_X_GFNI_IROW( 4),
    SIMDE_X_GFNI_IROW( 3), SIMDE_X_GFNI_IROW( 2), SIMDE_X_GFNI_IROW( 1), SIMDE_X_GFNI_IROW( 0));
  #undef SIMDE_X_GFNI_IROW
  return r;
}
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_gf2p8_affineinv_nibble_hi (uint64_t M) {
  #define SIMDE_X_GFNI_IROW(n) HEDLEY_STATIC_CAST(int8_t, simde_x_gf2p8_apply_mprime(M, HEDLEY_STATIC_CAST(uint8_t, (n) << 4)))
  simde__m128i r = simde_mm_set_epi8(
    SIMDE_X_GFNI_IROW(15), SIMDE_X_GFNI_IROW(14), SIMDE_X_GFNI_IROW(13), SIMDE_X_GFNI_IROW(12),
    SIMDE_X_GFNI_IROW(11), SIMDE_X_GFNI_IROW(10), SIMDE_X_GFNI_IROW( 9), SIMDE_X_GFNI_IROW( 8),
    SIMDE_X_GFNI_IROW( 7), SIMDE_X_GFNI_IROW( 6), SIMDE_X_GFNI_IROW( 5), SIMDE_X_GFNI_IROW( 4),
    SIMDE_X_GFNI_IROW( 3), SIMDE_X_GFNI_IROW( 2), SIMDE_X_GFNI_IROW( 1), SIMDE_X_GFNI_IROW( 0));
  #undef SIMDE_X_GFNI_IROW
  return r;
}

/* affineinv with a compile-time-constant matrix M and constant c, via the AES
 * S-box. M=A_aes & c=0x63 collapses to plain SubBytes (2 instructions). */
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_gf2p8affineinv_const (simde__m128i x, uint64_t M, int b) {
  simde__m128i s = simde_mm_shuffle_epi8(simde_mm_aesenclast_si128(x, simde_mm_setzero_si128()), simde_x_gf2p8_inv_undo_sr.m128i);
  if ((M == SIMDE_X_GFNI_AAES_FWD) && (b == 0x63))
    return s;
  {
    const simde__m128i mlo = simde_x_gf2p8_affineinv_nibble_lo(M, HEDLEY_STATIC_CAST(uint8_t, b));
    const simde__m128i mhi = simde_x_gf2p8_affineinv_nibble_hi(M);
    const simde__m128i nmask = simde_mm_set1_epi8(0x0F);
    return simde_mm_xor_si128(simde_mm_shuffle_epi8(mlo, simde_mm_and_si128(s, nmask)),
                              simde_mm_shuffle_epi8(mhi, simde_mm_and_si128(simde_mm_srli_epi16(s, 4), nmask)));
  }
}
#endif /* SIMDE_X_GFNI_HAVE_AES */

#if defined(SIMDE_X_GFNI_HAVE_SHUFFLE)
/* Tower field GF(2^8) ~= GF(2^4)[u]/(u^2 + u + nu), nu = 0xB in GF(2^4) with
 * reduction polynomial 0x13. A byte maps to (a_H, a_L), two GF(2^4) nibbles,
 * via the (linear) basis change below; the inverse map recombines them. */
static const union { uint8_t u8[16]; simde__m128i m128i; } simde_x_gf2p4_to_lo   = { {
  0x00, 0x01, 0x0b, 0x0a, 0x03, 0x02, 0x08, 0x09, 0x09, 0x08, 0x02, 0x03, 0x0a, 0x0b, 0x01, 0x00 } };
static const union { uint8_t u8[16]; simde__m128i m128i; } simde_x_gf2p4_to_hi   = { {
  0x00, 0x0b, 0x06, 0x0d, 0x03, 0x08, 0x05, 0x0e, 0x01, 0x0a, 0x07, 0x0c, 0x02, 0x09, 0x04, 0x0f } };
static const union { uint8_t u8[16]; simde__m128i m128i; } simde_x_gf2p4_toh_lo  = { {
  0x00, 0x00, 0x02, 0x02, 0x04, 0x04, 0x06, 0x06, 0x04, 0x04, 0x06, 0x06, 0x00, 0x00, 0x02, 0x02 } };
static const union { uint8_t u8[16]; simde__m128i m128i; } simde_x_gf2p4_toh_hi  = { {
  0x00, 0x03, 0x0d, 0x0e, 0x03, 0x00, 0x0e, 0x0d, 0x0e, 0x0d, 0x03, 0x00, 0x0d, 0x0e, 0x00, 0x03 } };
static const union { uint8_t u8[16]; simde__m128i m128i; } simde_x_gf2p4_from_l  = { {
  0x00, 0x01, 0x5c, 0x5d, 0xe0, 0xe1, 0xbc, 0xbd, 0x50, 0x51, 0x0c, 0x0d, 0xb0, 0xb1, 0xec, 0xed } };
static const union { uint8_t u8[16]; simde__m128i m128i; } simde_x_gf2p4_from_h  = { {
  0x00, 0x12, 0x0f, 0x1d, 0x59, 0x4b, 0x56, 0x44, 0xd7, 0xc5, 0xd8, 0xca, 0x8e, 0x9c, 0x81, 0x93 } };
static const union { uint8_t u8[16]; simde__m128i m128i; } simde_x_gf2p4_sqr     = { {
  0x00, 0x01, 0x04, 0x05, 0x03, 0x02, 0x07, 0x06, 0x0c, 0x0d, 0x08, 0x09, 0x0f, 0x0e, 0x0b, 0x0a } };
static const union { uint8_t u8[16]; simde__m128i m128i; } simde_x_gf2p4_mulnu   = { {
  0x00, 0x0b, 0x05, 0x0e, 0x0a, 0x01, 0x0f, 0x04, 0x07, 0x0c, 0x02, 0x09, 0x0d, 0x06, 0x08, 0x03 } };
static const union { uint8_t u8[16]; simde__m128i m128i; } simde_x_gf2p4_mulnusq = { {
  0x00, 0x0b, 0x0a, 0x01, 0x0e, 0x05, 0x04, 0x0f, 0x0d, 0x06, 0x07, 0x0c, 0x03, 0x08, 0x09, 0x02 } };
static const union { uint8_t u8[16]; simde__m128i m128i; } simde_x_gf2p4_inv     = { {
  0x00, 0x01, 0x09, 0x0e, 0x0d, 0x0b, 0x07, 0x06, 0x0f, 0x02, 0x0c, 0x05, 0x0a, 0x04, 0x03, 0x08 } };
static const union { uint8_t u8[16]; simde__m128i m128i; } simde_x_gf2p4_log     = { {
  0x00, 0x00, 0x01, 0x04, 0x02, 0x08, 0x05, 0x0a, 0x03, 0x0e, 0x09, 0x07, 0x06, 0x0d, 0x0b, 0x0c } };
static const union { uint8_t u8[16]; simde__m128i m128i; } simde_x_gf2p4_exp     = { {
  0x01, 0x02, 0x04, 0x08, 0x03, 0x06, 0x0c, 0x0b, 0x05, 0x0a, 0x07, 0x0e, 0x0f, 0x0d, 0x09, 0x00 } };
#endif /* SIMDE_X_GFNI_HAVE_SHUFFLE */

#if defined(SIMDE_X_GFNI_HAVE_SHUFFLE)
/* 3-way XOR. Uses ARMv8.2 SHA3 EOR3 when available (one instruction), else two
 * XORs. On x86 this is just two VPXOR. */
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_gfni_xor3 (simde__m128i a, simde__m128i b, simde__m128i c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE) && defined(SIMDE_ARCH_ARM_SHA3)
    return simde__m128i_from_neon_u8(veor3q_u8(simde__m128i_to_neon_u8(a), simde__m128i_to_neon_u8(b), simde__m128i_to_neon_u8(c)));
  #else
    return simde_mm_xor_si128(simde_mm_xor_si128(a, b), c);
  #endif
}

/* GF(2^4) multiply (both operands in the low nibble of each byte) via log/exp,
 * with the exponent reduced mod 15 and a zero mask for the 0 operands. */
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_gf2p4_mul (simde__m128i a, simde__m128i b) {
  const simde__m128i zero = simde_mm_setzero_si128();
  simde__m128i la = simde_mm_shuffle_epi8(simde_x_gf2p4_log.m128i, a);
  simde__m128i lb = simde_mm_shuffle_epi8(simde_x_gf2p4_log.m128i, b);
  simde__m128i idx = simde_mm_add_epi8(la, lb);
  simde__m128i ge = simde_mm_cmpgt_epi8(idx, simde_mm_set1_epi8(14));
  idx = simde_mm_sub_epi8(idx, simde_mm_and_si128(ge, simde_mm_set1_epi8(15)));
  simde__m128i r = simde_mm_shuffle_epi8(simde_x_gf2p4_exp.m128i, idx);
  simde__m128i z = simde_mm_or_si128(simde_mm_cmpeq_epi8(a, zero), simde_mm_cmpeq_epi8(b, zero));
  return simde_mm_andnot_si128(z, r);
}

/* Basis change between the standard byte and the tower (a_H, a_L) nibbles. */
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_gf2p8_tower_lo (simde__m128i x) {
  const simde__m128i nmask = simde_mm_set1_epi8(0x0F);
  const simde__m128i xlo = simde_mm_and_si128(x, nmask);
  const simde__m128i xhi = simde_mm_and_si128(simde_mm_srli_epi16(x, 4), nmask);
  return simde_mm_xor_si128(simde_mm_shuffle_epi8(simde_x_gf2p4_to_lo.m128i, xlo),
                            simde_mm_shuffle_epi8(simde_x_gf2p4_to_hi.m128i, xhi));
}
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_gf2p8_tower_hi (simde__m128i x) {
  const simde__m128i nmask = simde_mm_set1_epi8(0x0F);
  const simde__m128i xlo = simde_mm_and_si128(x, nmask);
  const simde__m128i xhi = simde_mm_and_si128(simde_mm_srli_epi16(x, 4), nmask);
  return simde_mm_xor_si128(simde_mm_shuffle_epi8(simde_x_gf2p4_toh_lo.m128i, xlo),
                            simde_mm_shuffle_epi8(simde_x_gf2p4_toh_hi.m128i, xhi));
}
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_gf2p8_tower_join (simde__m128i h, simde__m128i l) {
  return simde_mm_xor_si128(simde_mm_shuffle_epi8(simde_x_gf2p4_from_l.m128i, l),
                            simde_mm_shuffle_epi8(simde_x_gf2p4_from_h.m128i, h));
}

/* Fused tower-affine tables for constant-M SHUFFLE path: apply M to the
 * tower inverse's intermediate results directly, eliminating tower_join. */
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_gf2p8_fused_tower_lo (uint64_t M, uint8_t c) {
  #define SIMDE_X_GFNI_FROW(n) HEDLEY_STATIC_CAST(int8_t, simde_x_gf2p8_apply_matrix_byte(M, simde_x_gf2p4_from_l.u8[(n)]) ^ (c))
  simde__m128i r = simde_mm_set_epi8(
    SIMDE_X_GFNI_FROW(15), SIMDE_X_GFNI_FROW(14), SIMDE_X_GFNI_FROW(13), SIMDE_X_GFNI_FROW(12),
    SIMDE_X_GFNI_FROW(11), SIMDE_X_GFNI_FROW(10), SIMDE_X_GFNI_FROW( 9), SIMDE_X_GFNI_FROW( 8),
    SIMDE_X_GFNI_FROW( 7), SIMDE_X_GFNI_FROW( 6), SIMDE_X_GFNI_FROW( 5), SIMDE_X_GFNI_FROW( 4),
    SIMDE_X_GFNI_FROW( 3), SIMDE_X_GFNI_FROW( 2), SIMDE_X_GFNI_FROW( 1), SIMDE_X_GFNI_FROW( 0));
  #undef SIMDE_X_GFNI_FROW
  return r;
}
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_gf2p8_fused_tower_hi (uint64_t M) {
  #define SIMDE_X_GFNI_FROW(n) HEDLEY_STATIC_CAST(int8_t, simde_x_gf2p8_apply_matrix_byte(M, simde_x_gf2p4_from_h.u8[(n)]))
  simde__m128i r = simde_mm_set_epi8(
    SIMDE_X_GFNI_FROW(15), SIMDE_X_GFNI_FROW(14), SIMDE_X_GFNI_FROW(13), SIMDE_X_GFNI_FROW(12),
    SIMDE_X_GFNI_FROW(11), SIMDE_X_GFNI_FROW(10), SIMDE_X_GFNI_FROW( 9), SIMDE_X_GFNI_FROW( 8),
    SIMDE_X_GFNI_FROW( 7), SIMDE_X_GFNI_FROW( 6), SIMDE_X_GFNI_FROW( 5), SIMDE_X_GFNI_FROW( 4),
    SIMDE_X_GFNI_FROW( 3), SIMDE_X_GFNI_FROW( 2), SIMDE_X_GFNI_FROW( 1), SIMDE_X_GFNI_FROW( 0));
  #undef SIMDE_X_GFNI_FROW
  return r;
}

/* GF(2^8) inverse via the GF((2^4)^2) tower field (no AES needed). */
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_gf2p8inverse_tower (simde__m128i x) {
  const simde__m128i zero = simde_mm_setzero_si128();
  simde__m128i aL = simde_x_mm_gf2p8_tower_lo(x);
  simde__m128i aH = simde_x_mm_gf2p8_tower_hi(x);

  /* Inline delta multiply: compute log(aH), cache it and z_aH for later reuse. */
  simde__m128i log_aH = simde_mm_shuffle_epi8(simde_x_gf2p4_log.m128i, aH);
  simde__m128i z_aH = simde_mm_cmpeq_epi8(aH, zero);
  simde__m128i log_aL = simde_mm_shuffle_epi8(simde_x_gf2p4_log.m128i, aL);
  simde__m128i idx = simde_mm_add_epi8(log_aH, log_aL);
  simde__m128i ge = simde_mm_cmpgt_epi8(idx, simde_mm_set1_epi8(14));
  idx = simde_mm_sub_epi8(idx, simde_mm_and_si128(ge, simde_mm_set1_epi8(15)));
  simde__m128i mul_aHaL = simde_mm_shuffle_epi8(simde_x_gf2p4_exp.m128i, idx);
  simde__m128i z = simde_mm_or_si128(z_aH, simde_mm_cmpeq_epi8(aL, zero));
  mul_aHaL = simde_mm_andnot_si128(z, mul_aHaL);

  /* delta = a_H^2 . nu ^ a_H . a_L ^ a_L^2 (3-way XOR -> EOR3 on ARM SHA3) */
  simde__m128i delta = simde_x_gfni_xor3(
    simde_mm_shuffle_epi8(simde_x_gf2p4_mulnusq.m128i, aH),
    mul_aHaL,
    simde_mm_shuffle_epi8(simde_x_gf2p4_sqr.m128i, aL));

  /* Negated-log inversion: log(x^-1) = log(x) XOR 0x0F in GF(2^4)* (order 15). */
  simde__m128i neg_log_delta = simde_mm_xor_si128(
    simde_mm_shuffle_epi8(simde_x_gf2p4_log.m128i, delta),
    simde_mm_set1_epi8(0x0F));

  /* iH = aH * delta^-1, reusing cached log_aH, zero mask checks aH only. */
  idx = simde_mm_add_epi8(log_aH, neg_log_delta);
  ge = simde_mm_cmpgt_epi8(idx, simde_mm_set1_epi8(14));
  idx = simde_mm_sub_epi8(idx, simde_mm_and_si128(ge, simde_mm_set1_epi8(15)));
  simde__m128i iH = simde_mm_shuffle_epi8(simde_x_gf2p4_exp.m128i, idx);
  iH = simde_mm_andnot_si128(z_aH, iH);

  /* iL = (aH ^ aL) * delta^-1, zero mask checks (aH ^ aL) only. */
  simde__m128i aHxaL = simde_mm_xor_si128(aH, aL);
  simde__m128i log_aHxaL = simde_mm_shuffle_epi8(simde_x_gf2p4_log.m128i, aHxaL);
  idx = simde_mm_add_epi8(log_aHxaL, neg_log_delta);
  ge = simde_mm_cmpgt_epi8(idx, simde_mm_set1_epi8(14));
  idx = simde_mm_sub_epi8(idx, simde_mm_and_si128(ge, simde_mm_set1_epi8(15)));
  simde__m128i iL = simde_mm_shuffle_epi8(simde_x_gf2p4_exp.m128i, idx);
  z = simde_mm_cmpeq_epi8(aHxaL, zero);
  iL = simde_mm_andnot_si128(z, iL);

  return simde_x_mm_gf2p8_tower_join(iH, iL);
}

/* affineinv with constant M via the fused tower path (SHUFFLE without AES).
 * Computes tower inverse then applies M directly to (iH, iL) instead of
 * tower_join, using the compile-time fused tables. */
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_gf2p8affineinv_tower_const (simde__m128i x, uint64_t M, int b) {
  const simde__m128i zero = simde_mm_setzero_si128();
  simde__m128i aL = simde_x_mm_gf2p8_tower_lo(x);
  simde__m128i aH = simde_x_mm_gf2p8_tower_hi(x);

  /* Inline delta multiply: compute log(aH), cache it and z_aH for later reuse. */
  simde__m128i log_aH = simde_mm_shuffle_epi8(simde_x_gf2p4_log.m128i, aH);
  simde__m128i z_aH = simde_mm_cmpeq_epi8(aH, zero);
  simde__m128i log_aL = simde_mm_shuffle_epi8(simde_x_gf2p4_log.m128i, aL);
  simde__m128i idx = simde_mm_add_epi8(log_aH, log_aL);
  simde__m128i ge = simde_mm_cmpgt_epi8(idx, simde_mm_set1_epi8(14));
  idx = simde_mm_sub_epi8(idx, simde_mm_and_si128(ge, simde_mm_set1_epi8(15)));
  simde__m128i mul_aHaL = simde_mm_shuffle_epi8(simde_x_gf2p4_exp.m128i, idx);
  simde__m128i z = simde_mm_or_si128(z_aH, simde_mm_cmpeq_epi8(aL, zero));
  mul_aHaL = simde_mm_andnot_si128(z, mul_aHaL);

  /* delta = a_H^2 . nu ^ a_H . a_L ^ a_L^2 (3-way XOR -> EOR3 on ARM SHA3) */
  simde__m128i delta = simde_x_gfni_xor3(
    simde_mm_shuffle_epi8(simde_x_gf2p4_mulnusq.m128i, aH),
    mul_aHaL,
    simde_mm_shuffle_epi8(simde_x_gf2p4_sqr.m128i, aL));

  /* Negated-log inversion: log(x^-1) = log(x) XOR 0x0F in GF(2^4)* (order 15). */
  simde__m128i neg_log_delta = simde_mm_xor_si128(
    simde_mm_shuffle_epi8(simde_x_gf2p4_log.m128i, delta),
    simde_mm_set1_epi8(0x0F));

  /* iH = aH * delta^-1, reusing cached log_aH, zero mask checks aH only. */
  idx = simde_mm_add_epi8(log_aH, neg_log_delta);
  ge = simde_mm_cmpgt_epi8(idx, simde_mm_set1_epi8(14));
  idx = simde_mm_sub_epi8(idx, simde_mm_and_si128(ge, simde_mm_set1_epi8(15)));
  simde__m128i iH = simde_mm_shuffle_epi8(simde_x_gf2p4_exp.m128i, idx);
  iH = simde_mm_andnot_si128(z_aH, iH);

  /* iL = (aH ^ aL) * delta^-1, zero mask checks (aH ^ aL) only. */
  simde__m128i aHxaL = simde_mm_xor_si128(aH, aL);
  simde__m128i log_aHxaL = simde_mm_shuffle_epi8(simde_x_gf2p4_log.m128i, aHxaL);
  idx = simde_mm_add_epi8(log_aHxaL, neg_log_delta);
  ge = simde_mm_cmpgt_epi8(idx, simde_mm_set1_epi8(14));
  idx = simde_mm_sub_epi8(idx, simde_mm_and_si128(ge, simde_mm_set1_epi8(15)));
  simde__m128i iL = simde_mm_shuffle_epi8(simde_x_gf2p4_exp.m128i, idx);
  z = simde_mm_cmpeq_epi8(aHxaL, zero);
  iL = simde_mm_andnot_si128(z, iL);

  /* Fused output: apply M to (iH, iL) directly instead of tower_join then M. */
  const simde__m128i fused_lo = simde_x_gf2p8_fused_tower_lo(M, HEDLEY_STATIC_CAST(uint8_t, b));
  const simde__m128i fused_hi = simde_x_gf2p8_fused_tower_hi(M);
  return simde_mm_xor_si128(simde_mm_shuffle_epi8(fused_lo, iL),
                            simde_mm_shuffle_epi8(fused_hi, iH));
}

/* GF(2^8) multiply via the tower field (Karatsuba over GF(2^4)). */
SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_gf2p8mul_tower (simde__m128i a, simde__m128i b) {
  simde__m128i aL = simde_x_mm_gf2p8_tower_lo(a), aH = simde_x_mm_gf2p8_tower_hi(a);
  simde__m128i bL = simde_x_mm_gf2p8_tower_lo(b), bH = simde_x_mm_gf2p8_tower_hi(b);
  simde__m128i p = simde_x_mm_gf2p4_mul(aL, bL);
  simde__m128i q = simde_x_mm_gf2p4_mul(aH, bH);
  simde__m128i r = simde_x_mm_gf2p4_mul(simde_mm_xor_si128(aH, aL), simde_mm_xor_si128(bH, bL));
  simde__m128i oH = simde_mm_xor_si128(r, p);
  simde__m128i oL = simde_mm_xor_si128(p, simde_mm_shuffle_epi8(simde_x_gf2p4_mulnu.m128i, q));
  return simde_x_mm_gf2p8_tower_join(oH, oL);
}
#endif /* SIMDE_X_GFNI_HAVE_SHUFFLE */

#if defined(SIMDE_X_GFNI_HAVE_SHUFFLE) && defined(SIMDE_X86_AVX2_NATIVE)
/* 256-bit (AVX2) versions of the tower-field helpers. Same algorithms as the
 * 128-bit ones above, with the 16-byte tables broadcast to both lanes. On
 * full-width cores a ymm shuffle costs the same as an xmm one, so these double
 * the throughput of the wide multiply/inverse operations versus splitting into
 * two 128-bit halves. */
SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_x_mm256_gf2p4_mul (simde__m256i a, simde__m256i b) {
  const simde__m256i zero = simde_mm256_setzero_si256();
  const simde__m256i logt = simde_mm256_broadcastsi128_si256(simde_x_gf2p4_log.m128i);
  simde__m256i la = simde_mm256_shuffle_epi8(logt, a);
  simde__m256i lb = simde_mm256_shuffle_epi8(logt, b);
  simde__m256i idx = simde_mm256_add_epi8(la, lb);
  simde__m256i ge = simde_mm256_cmpgt_epi8(idx, simde_mm256_set1_epi8(14));
  idx = simde_mm256_sub_epi8(idx, simde_mm256_and_si256(ge, simde_mm256_set1_epi8(15)));
  simde__m256i r = simde_mm256_shuffle_epi8(simde_mm256_broadcastsi128_si256(simde_x_gf2p4_exp.m128i), idx);
  simde__m256i z = simde_mm256_or_si256(simde_mm256_cmpeq_epi8(a, zero), simde_mm256_cmpeq_epi8(b, zero));
  return simde_mm256_andnot_si256(z, r);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_x_mm256_gf2p8_tower_lo (simde__m256i x) {
  const simde__m256i nmask = simde_mm256_set1_epi8(0x0F);
  const simde__m256i xlo = simde_mm256_and_si256(x, nmask);
  const simde__m256i xhi = simde_mm256_and_si256(simde_mm256_srli_epi16(x, 4), nmask);
  return simde_mm256_xor_si256(
    simde_mm256_shuffle_epi8(simde_mm256_broadcastsi128_si256(simde_x_gf2p4_to_lo.m128i), xlo),
    simde_mm256_shuffle_epi8(simde_mm256_broadcastsi128_si256(simde_x_gf2p4_to_hi.m128i), xhi));
}
SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_x_mm256_gf2p8_tower_hi (simde__m256i x) {
  const simde__m256i nmask = simde_mm256_set1_epi8(0x0F);
  const simde__m256i xlo = simde_mm256_and_si256(x, nmask);
  const simde__m256i xhi = simde_mm256_and_si256(simde_mm256_srli_epi16(x, 4), nmask);
  return simde_mm256_xor_si256(
    simde_mm256_shuffle_epi8(simde_mm256_broadcastsi128_si256(simde_x_gf2p4_toh_lo.m128i), xlo),
    simde_mm256_shuffle_epi8(simde_mm256_broadcastsi128_si256(simde_x_gf2p4_toh_hi.m128i), xhi));
}
SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_x_mm256_gf2p8_tower_join (simde__m256i h, simde__m256i l) {
  return simde_mm256_xor_si256(
    simde_mm256_shuffle_epi8(simde_mm256_broadcastsi128_si256(simde_x_gf2p4_from_l.m128i), l),
    simde_mm256_shuffle_epi8(simde_mm256_broadcastsi128_si256(simde_x_gf2p4_from_h.m128i), h));
}

/* GF(2^8) inverse via the tower field, 256-bit. Mirrors the 128-bit version
 * including the cached log(aH) / zero-mask reuse. */
SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_x_mm256_gf2p8inverse_tower (simde__m256i x) {
  const simde__m256i zero = simde_mm256_setzero_si256();
  const simde__m256i logt = simde_mm256_broadcastsi128_si256(simde_x_gf2p4_log.m128i);
  const simde__m256i expt = simde_mm256_broadcastsi128_si256(simde_x_gf2p4_exp.m128i);
  simde__m256i aL = simde_x_mm256_gf2p8_tower_lo(x);
  simde__m256i aH = simde_x_mm256_gf2p8_tower_hi(x);

  /* Inline delta multiply: compute log(aH), cache it and z_aH for later reuse. */
  simde__m256i log_aH = simde_mm256_shuffle_epi8(logt, aH);
  simde__m256i z_aH = simde_mm256_cmpeq_epi8(aH, zero);
  simde__m256i log_aL = simde_mm256_shuffle_epi8(logt, aL);
  simde__m256i idx = simde_mm256_add_epi8(log_aH, log_aL);
  simde__m256i ge = simde_mm256_cmpgt_epi8(idx, simde_mm256_set1_epi8(14));
  idx = simde_mm256_sub_epi8(idx, simde_mm256_and_si256(ge, simde_mm256_set1_epi8(15)));
  simde__m256i mul_aHaL = simde_mm256_shuffle_epi8(expt, idx);
  simde__m256i z = simde_mm256_or_si256(z_aH, simde_mm256_cmpeq_epi8(aL, zero));
  mul_aHaL = simde_mm256_andnot_si256(z, mul_aHaL);

  /* delta = a_H^2 . nu ^ a_H . a_L ^ a_L^2 */
  simde__m256i delta = simde_mm256_xor_si256(simde_mm256_xor_si256(
    simde_mm256_shuffle_epi8(simde_mm256_broadcastsi128_si256(simde_x_gf2p4_mulnusq.m128i), aH),
    mul_aHaL),
    simde_mm256_shuffle_epi8(simde_mm256_broadcastsi128_si256(simde_x_gf2p4_sqr.m128i), aL));

  /* Negated-log inversion: log(x^-1) = log(x) XOR 0x0F in GF(2^4)* (order 15). */
  simde__m256i neg_log_delta = simde_mm256_xor_si256(
    simde_mm256_shuffle_epi8(logt, delta), simde_mm256_set1_epi8(0x0F));

  /* iH = aH * delta^-1, reusing cached log_aH, zero mask checks aH only. */
  idx = simde_mm256_add_epi8(log_aH, neg_log_delta);
  ge = simde_mm256_cmpgt_epi8(idx, simde_mm256_set1_epi8(14));
  idx = simde_mm256_sub_epi8(idx, simde_mm256_and_si256(ge, simde_mm256_set1_epi8(15)));
  simde__m256i iH = simde_mm256_shuffle_epi8(expt, idx);
  iH = simde_mm256_andnot_si256(z_aH, iH);

  /* iL = (aH ^ aL) * delta^-1, zero mask checks (aH ^ aL) only. */
  simde__m256i aHxaL = simde_mm256_xor_si256(aH, aL);
  simde__m256i log_aHxaL = simde_mm256_shuffle_epi8(logt, aHxaL);
  idx = simde_mm256_add_epi8(log_aHxaL, neg_log_delta);
  ge = simde_mm256_cmpgt_epi8(idx, simde_mm256_set1_epi8(14));
  idx = simde_mm256_sub_epi8(idx, simde_mm256_and_si256(ge, simde_mm256_set1_epi8(15)));
  simde__m256i iL = simde_mm256_shuffle_epi8(expt, idx);
  z = simde_mm256_cmpeq_epi8(aHxaL, zero);
  iL = simde_mm256_andnot_si256(z, iL);

  return simde_x_mm256_gf2p8_tower_join(iH, iL);
}

/* affineinv with constant M via the fused tower path, 256-bit. Mirrors the
 * 128-bit version: tower inverse guts, then M applied to (iH, iL) directly
 * through the compile-time fused tables (broadcast to both lanes). */
SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_x_mm256_gf2p8affineinv_tower_const (simde__m256i x, uint64_t M, int b) {
  const simde__m256i zero = simde_mm256_setzero_si256();
  const simde__m256i logt = simde_mm256_broadcastsi128_si256(simde_x_gf2p4_log.m128i);
  const simde__m256i expt = simde_mm256_broadcastsi128_si256(simde_x_gf2p4_exp.m128i);
  simde__m256i aL = simde_x_mm256_gf2p8_tower_lo(x);
  simde__m256i aH = simde_x_mm256_gf2p8_tower_hi(x);

  /* Inline delta multiply: compute log(aH), cache it and z_aH for later reuse. */
  simde__m256i log_aH = simde_mm256_shuffle_epi8(logt, aH);
  simde__m256i z_aH = simde_mm256_cmpeq_epi8(aH, zero);
  simde__m256i log_aL = simde_mm256_shuffle_epi8(logt, aL);
  simde__m256i idx = simde_mm256_add_epi8(log_aH, log_aL);
  simde__m256i ge = simde_mm256_cmpgt_epi8(idx, simde_mm256_set1_epi8(14));
  idx = simde_mm256_sub_epi8(idx, simde_mm256_and_si256(ge, simde_mm256_set1_epi8(15)));
  simde__m256i mul_aHaL = simde_mm256_shuffle_epi8(expt, idx);
  simde__m256i z = simde_mm256_or_si256(z_aH, simde_mm256_cmpeq_epi8(aL, zero));
  mul_aHaL = simde_mm256_andnot_si256(z, mul_aHaL);

  /* delta = a_H^2 . nu ^ a_H . a_L ^ a_L^2 */
  simde__m256i delta = simde_mm256_xor_si256(simde_mm256_xor_si256(
    simde_mm256_shuffle_epi8(simde_mm256_broadcastsi128_si256(simde_x_gf2p4_mulnusq.m128i), aH),
    mul_aHaL),
    simde_mm256_shuffle_epi8(simde_mm256_broadcastsi128_si256(simde_x_gf2p4_sqr.m128i), aL));

  /* Negated-log inversion: log(x^-1) = log(x) XOR 0x0F in GF(2^4)* (order 15). */
  simde__m256i neg_log_delta = simde_mm256_xor_si256(
    simde_mm256_shuffle_epi8(logt, delta), simde_mm256_set1_epi8(0x0F));

  /* iH = aH * delta^-1, reusing cached log_aH, zero mask checks aH only. */
  idx = simde_mm256_add_epi8(log_aH, neg_log_delta);
  ge = simde_mm256_cmpgt_epi8(idx, simde_mm256_set1_epi8(14));
  idx = simde_mm256_sub_epi8(idx, simde_mm256_and_si256(ge, simde_mm256_set1_epi8(15)));
  simde__m256i iH = simde_mm256_shuffle_epi8(expt, idx);
  iH = simde_mm256_andnot_si256(z_aH, iH);

  /* iL = (aH ^ aL) * delta^-1, zero mask checks (aH ^ aL) only. */
  simde__m256i aHxaL = simde_mm256_xor_si256(aH, aL);
  simde__m256i log_aHxaL = simde_mm256_shuffle_epi8(logt, aHxaL);
  idx = simde_mm256_add_epi8(log_aHxaL, neg_log_delta);
  ge = simde_mm256_cmpgt_epi8(idx, simde_mm256_set1_epi8(14));
  idx = simde_mm256_sub_epi8(idx, simde_mm256_and_si256(ge, simde_mm256_set1_epi8(15)));
  simde__m256i iL = simde_mm256_shuffle_epi8(expt, idx);
  z = simde_mm256_cmpeq_epi8(aHxaL, zero);
  iL = simde_mm256_andnot_si256(z, iL);

  /* Fused output: apply M to (iH, iL) directly instead of tower_join then M. */
  const simde__m256i fused_lo = simde_mm256_broadcastsi128_si256(simde_x_gf2p8_fused_tower_lo(M, HEDLEY_STATIC_CAST(uint8_t, b)));
  const simde__m256i fused_hi = simde_mm256_broadcastsi128_si256(simde_x_gf2p8_fused_tower_hi(M));
  return simde_mm256_xor_si256(simde_mm256_shuffle_epi8(fused_lo, iL),
                               simde_mm256_shuffle_epi8(fused_hi, iH));
}

/* GF(2^8) multiply via the tower field (Karatsuba over GF(2^4)), 256-bit. */
SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_x_mm256_gf2p8mul_tower (simde__m256i a, simde__m256i b) {
  simde__m256i aL = simde_x_mm256_gf2p8_tower_lo(a), aH = simde_x_mm256_gf2p8_tower_hi(a);
  simde__m256i bL = simde_x_mm256_gf2p8_tower_lo(b), bH = simde_x_mm256_gf2p8_tower_hi(b);
  simde__m256i p = simde_x_mm256_gf2p4_mul(aL, bL);
  simde__m256i q = simde_x_mm256_gf2p4_mul(aH, bH);
  simde__m256i r = simde_x_mm256_gf2p4_mul(simde_mm256_xor_si256(aH, aL), simde_mm256_xor_si256(bH, bL));
  simde__m256i oH = simde_mm256_xor_si256(r, p);
  simde__m256i oL = simde_mm256_xor_si256(p,
    simde_mm256_shuffle_epi8(simde_mm256_broadcastsi128_si256(simde_x_gf2p4_mulnu.m128i), q));
  return simde_x_mm256_gf2p8_tower_join(oH, oL);
}
#endif /* SIMDE_X_GFNI_HAVE_SHUFFLE && SIMDE_X86_AVX2_NATIVE */

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_gf2p8matrix_multiply_epi64_epi8 (simde__m128i x, simde__m128i A) {
  #if defined(SIMDE_CHECK_CONSTANT_) && defined(SIMDE_X_GFNI_HAVE_SHUFFLE)
    /* If the matrix is a compile-time constant (the same for both 64-bit
     * lanes) we can resolve M.x as M_lo[x & 0xF] ^ M_hi[x >> 4] with two byte
     * shuffles; the per-nibble tables fold to constants at compile time. */
    simde__m128i_private cA_ = simde__m128i_to_private(A);
    if (SIMDE_CHECK_CONSTANT_(cA_.u64[0]) && SIMDE_CHECK_CONSTANT_(cA_.u64[1]) && (cA_.u64[0] == cA_.u64[1])) {
      const simde__m128i mlo = simde_x_gf2p8_matrix_nibble_lo(cA_.u64[0]);
      const simde__m128i mhi = simde_x_gf2p8_matrix_nibble_hi(cA_.u64[0]);
      const simde__m128i nmask = simde_mm_set1_epi8(0x0F);
      const simde__m128i lo = simde_mm_and_si128(x, nmask);
      const simde__m128i hi = simde_mm_and_si128(simde_mm_srli_epi16(x, 4), nmask);
      return simde_mm_xor_si128(simde_mm_shuffle_epi8(mlo, lo), simde_mm_shuffle_epi8(mhi, hi));
    }
  #endif
  #if defined(SIMDE_X86_SSSE3_NATIVE)
    const __m128i byte_select = _mm_setr_epi8(0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1);
    const __m128i zero = _mm_setzero_si128();
    __m128i r, a, p, X;

    a = _mm_shuffle_epi8(A, _mm_setr_epi8(7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8));
    X = x;
    r = zero;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 8 ; i++) {
      p = _mm_insert_epi16(zero, _mm_movemask_epi8(a), 0);
      p = _mm_shuffle_epi8(p, byte_select);
      p = _mm_and_si128(p, _mm_cmpgt_epi8(zero, X));
      r = _mm_xor_si128(r, p);
      a = _mm_add_epi8(a, a);
      X = _mm_add_epi8(X, X);
    }

    return r;
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    const __m128i zero = _mm_setzero_si128();
    __m128i r, a, p, X;

    a = _mm_shufflehi_epi16(A, (0 << 6) + (1 << 4) + (2 << 2) + (3 << 0));
    a = _mm_shufflelo_epi16(a, (0 << 6) + (1 << 4) + (2 << 2) + (3 << 0));
    a = _mm_or_si128(_mm_slli_epi16(a, 8), _mm_srli_epi16(a, 8));
    X = _mm_unpacklo_epi8(x, _mm_unpackhi_epi64(x, x));
    r = zero;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 8 ; i++) {
      p = _mm_set1_epi16(HEDLEY_STATIC_CAST(short, _mm_movemask_epi8(a)));
      p = _mm_and_si128(p, _mm_cmpgt_epi8(zero, X));
      r = _mm_xor_si128(r, p);
      a = _mm_add_epi8(a, a);
      X = _mm_add_epi8(X, X);
    }

    return _mm_packus_epi16(_mm_srli_epi16(_mm_slli_epi16(r, 8), 8), _mm_srli_epi16(r, 8));
  #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    static const uint8_t byte_interleave[16] = {0, 8, 1, 9, 2, 10, 3, 11, 4, 12, 5, 13, 6, 14, 7, 15};
    static const uint8_t byte_deinterleave[16] = {0, 2, 4, 6, 8, 10, 12, 14, 1, 3, 5, 7, 9, 11, 13, 15};
    static const uint8_t mask_d[16] = {128, 128, 64, 64, 32, 32, 16, 16, 8, 8, 4, 4, 2, 2, 1, 1};
    const int8x16_t mask = vreinterpretq_s8_u8(vld1q_u8(mask_d));
    int8x16_t r, a, t, X;

    t = simde__m128i_to_neon_i8(A);
    a = vqtbl1q_s8(t, vld1q_u8(byte_interleave));
    t = simde__m128i_to_neon_i8(x);
    X = vqtbl1q_s8(t, vld1q_u8(byte_interleave));
    r = vdupq_n_s8(0);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 8 ; i++) {
      t = vshrq_n_s8(a, 7);
      t = vandq_s8(t, mask);
      t = vreinterpretq_s8_u16(vdupq_n_u16(vaddvq_u16(vreinterpretq_u16_s8(t))));
      t = vandq_s8(t, vshrq_n_s8(X, 7));
      r = veorq_s8(r, t);
      a = vshlq_n_s8(a, 1);
      X = vshlq_n_s8(X, 1);
    }

    r = vqtbl1q_s8(r, vld1q_u8(byte_deinterleave));
    return simde__m128i_from_neon_i8(r);
  #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    static const uint8_t mask_d[16] = {128, 64, 32, 16, 8, 4, 2, 1, 128, 64, 32, 16, 8, 4, 2, 1};
    const int8x16_t mask = vreinterpretq_s8_u8(vld1q_u8(mask_d));
    int8x16_t r, a, t, X;
    int16x8_t t16;
    int32x4_t t32;

    a = simde__m128i_to_neon_i8(A);
    X = simde__m128i_to_neon_i8(x);
    r = vdupq_n_s8(0);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 8 ; i++) {
      t = vshrq_n_s8(a, 7);
      t = vandq_s8(t, mask);
      t16 = vreinterpretq_s16_s8 (vorrq_s8 (t  , vrev64q_s8 (t  )));
      t32 = vreinterpretq_s32_s16(vorrq_s16(t16, vrev64q_s16(t16)));
      t   = vreinterpretq_s8_s32 (vorrq_s32(t32, vrev64q_s32(t32)));
      t = vandq_s8(t, vshrq_n_s8(X, 7));
      r = veorq_s8(r, t);
      a = vshlq_n_s8(a, 1);
      X = vshlq_n_s8(X, 1);
    }

    return simde__m128i_from_neon_i8(r);
  #elif defined(SIMDE_ZARCH_ZVECTOR_14_NATIVE)
    static const SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) byte_interleave = {0, 8, 1, 9, 2, 10, 3, 11, 4, 12, 5, 13, 6, 14, 7, 15};
    static const SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) byte_deinterleave= {0, 2, 4, 6, 8, 10, 12, 14, 1, 3, 5, 7, 9, 11, 13, 15};
    static const SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) bit_select = {0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120};
    static const SIMDE_POWER_ALTIVEC_VECTOR(signed char) zero = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) a, p, r;
    SIMDE_POWER_ALTIVEC_VECTOR(signed char) X;

    X = simde__m128i_to_altivec_i8(x);
    a = simde__m128i_to_altivec_u8(A);
    X = vec_perm(X, X, byte_interleave);
    r = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char), zero);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 8 ; i++) {
      #if defined(SIMDE_BUG_CLANG_50932)
        p = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char),
                              vec_bperm(HEDLEY_STATIC_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned __int128), a), bit_select));
      #else
        p = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char), vec_bperm_u128(a, bit_select));
      #endif
      p = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char),
                                  vec_splat(HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned short), p), 3));
      p &= X < zero;
      r ^= p;
      a += a;
      X += X;
    }

    r = vec_perm(r, r, byte_deinterleave);
    return simde__m128i_from_altivec_u8(r);
  #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
    static const SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) mask = {128, 64, 32, 16, 8, 4, 2, 1, 128, 64, 32, 16, 8, 4, 2, 1};
    static const SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) byte_select = {7, 7, 7, 7, 7, 7, 7, 7, 15, 15, 15, 15, 15, 15, 15, 15};
    static const SIMDE_POWER_ALTIVEC_VECTOR(signed char) zero = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) p, r;
    SIMDE_POWER_ALTIVEC_VECTOR(signed char) a, X;

    X = simde__m128i_to_altivec_i8(x);
    a = simde__m128i_to_altivec_i8(A);
    r = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char), zero);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 8 ; i++) {
      p = a < zero;
      p &= mask;
      p = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char),
                                  vec_sum2(vec_sum4(p, HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char), zero)),
                                           HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned int), zero)));
      p = vec_perm(p, p, byte_select);
      p &= X < zero;
      r ^= p;
      a += a;
      X += X;
    }

    return simde__m128i_from_altivec_u8(r);
  #elif defined(SIMDE_POWER_ALTIVEC_P8_NATIVE)
    static const SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) byte_interleave = {0, 8, 1, 9, 2, 10, 3, 11, 4, 12, 5, 13, 6, 14, 7, 15};
    static const SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) byte_deinterleave= {0, 2, 4, 6, 8, 10, 12, 14, 1, 3, 5, 7, 9, 11, 13, 15};
    static const SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) bit_select = {64, 72, 80, 88, 96, 104, 112, 120, 0, 8, 16, 24, 32, 40, 48, 56};
    const SIMDE_POWER_ALTIVEC_VECTOR(signed char) zero = vec_splats(HEDLEY_STATIC_CAST(signed char, 0));
    SIMDE_POWER_ALTIVEC_VECTOR(signed char) X;
    SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) a, p, r;

    X = simde__m128i_to_altivec_i8(x);
    a = simde__m128i_to_altivec_u8(A);
    X = vec_perm(X, X, byte_interleave);
    r = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char), zero);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 8 ; i++) {
      #if defined(SIMDE_BUG_CLANG_50932)
        p = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char),
                                    vec_bperm(HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned __int128), a), bit_select));
      #else
        p = vec_bperm(a, bit_select);
      #endif
      p = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char),
                                  vec_splat(HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned short), p), 4));
      p = vec_and(p, vec_cmplt(X, zero));
      r = vec_xor(r, p);
      a = vec_add(a, a);
      X = vec_add(X, X);
    }

    r = vec_perm(r, r, byte_deinterleave);
    return simde__m128i_from_altivec_u8(r);
  #elif defined(SIMDE_POWER_ALTIVEC_P6_NATIVE)
    static const SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) mask = {128, 64, 32, 16, 8, 4, 2, 1, 128, 64, 32, 16, 8, 4, 2, 1};
    static const SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) byte_select = {4, 4, 4, 4, 4, 4, 4, 4, 12, 12, 12, 12, 12, 12, 12, 12};
    const SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) sevens = vec_splats(HEDLEY_STATIC_CAST(unsigned char, 7));
    const SIMDE_POWER_ALTIVEC_VECTOR(signed char) zero = vec_splats(HEDLEY_STATIC_CAST(signed char, 0));
    SIMDE_POWER_ALTIVEC_VECTOR(signed char) X;
    SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) a, p, r;

    X = simde__m128i_to_altivec_i8(x);
    a = simde__m128i_to_altivec_u8(A);
    r = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char), zero);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 8 ; i++) {
      p = vec_sr(a, sevens);
      p = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char),
                                  vec_msum(p,
                                           mask,
                                           HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned int), zero)));
      p = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char),
                                  vec_sum2s(HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(signed int), p),
                                            HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(signed int), zero)));
      p = vec_perm(p, p, byte_select);
      p = vec_and(p, vec_cmplt(X, zero));
      r = vec_xor(r, p);
      a = vec_add(a, a);
      X = vec_add(X, X);
    }

    return simde__m128i_from_altivec_u8(r);
  #elif defined(SIMDE_WASM_SIMD128_NATIVE)
    const v128_t zero = wasm_i8x16_splat(0);
    v128_t a, p, r, X;

    X = simde__m128i_to_wasm_v128(x);
    a = simde__m128i_to_wasm_v128(A);
    a = wasm_i8x16_shuffle(a, a, 7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8);
    X = wasm_i8x16_shuffle(X, X, 0, 8, 1, 9, 2, 10, 3, 11, 4, 12, 5, 13, 6, 14, 7, 15);
    r = zero;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 8 ; i++) {
      p = wasm_i16x8_splat(HEDLEY_STATIC_CAST(int16_t, wasm_i8x16_bitmask(a)));
      p = wasm_v128_and(p, wasm_i8x16_lt(X, zero));
      r = wasm_v128_xor(r, p);
      a = wasm_i8x16_add(a, a);
      X = wasm_i8x16_add(X, X);
    }

    r = wasm_i8x16_shuffle(r, r, 0, 2, 4, 6, 8, 10, 12, 14, 1, 3, 5, 7, 9, 11, 13, 15);
    return simde__m128i_from_wasm_v128(r);
  #else
    simde__m128i_private
      r_,
      x_ = simde__m128i_to_private(x),
      A_ = simde__m128i_to_private(A);

    const uint64_t ones = UINT64_C(0x0101010101010101);
    const uint64_t mask = UINT64_C(0x0102040810204080);
    uint64_t q;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
      q = simde_endian_bswap64_le(A_.u64[i / 8]);
      q &= HEDLEY_STATIC_CAST(uint64_t, x_.u8[i]) * ones;
      q ^= q >> 4;
      q ^= q >> 2;
      q ^= q >> 1;
      q &= ones;
      q *= 255;
      q &= mask;
      q |= q >> 32;
      q |= q >> 16;
      q |= q >> 8;
      r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, q);
    }

    return simde__m128i_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_x_mm256_gf2p8matrix_multiply_epi64_epi8 (simde__m256i x, simde__m256i A) {
  #if defined(SIMDE_CHECK_CONSTANT_) && defined(SIMDE_X86_AVX2_NATIVE)
    simde__m256i_private cA_ = simde__m256i_to_private(A);
    if (SIMDE_CHECK_CONSTANT_(cA_.u64[0]) && SIMDE_CHECK_CONSTANT_(cA_.u64[1]) &&
        SIMDE_CHECK_CONSTANT_(cA_.u64[2]) && SIMDE_CHECK_CONSTANT_(cA_.u64[3]) &&
        (cA_.u64[0] == cA_.u64[1]) && (cA_.u64[0] == cA_.u64[2]) && (cA_.u64[0] == cA_.u64[3])) {
      const simde__m256i mlo = simde_mm256_broadcastsi128_si256(simde_x_gf2p8_matrix_nibble_lo(cA_.u64[0]));
      const simde__m256i mhi = simde_mm256_broadcastsi128_si256(simde_x_gf2p8_matrix_nibble_hi(cA_.u64[0]));
      const simde__m256i nmask = simde_mm256_set1_epi8(0x0F);
      const simde__m256i lo = simde_mm256_and_si256(x, nmask);
      const simde__m256i hi = simde_mm256_and_si256(simde_mm256_srli_epi16(x, 4), nmask);
      return simde_mm256_xor_si256(simde_mm256_shuffle_epi8(mlo, lo), simde_mm256_shuffle_epi8(mhi, hi));
    }
  #endif
  #if defined(SIMDE_X86_AVX2_NATIVE)
    simde__m256i r, a, p;
    const simde__m256i byte_select = simde_x_mm256_set_epu64x(UINT64_C(0x0303030303030303), UINT64_C(0x0202020202020202),
                                                              UINT64_C(0x0101010101010101), UINT64_C(0x0000000000000000));
    a = simde_mm256_shuffle_epi8(A, simde_mm256_broadcastsi128_si256(simde_x_mm_set_epu64x(UINT64_C(0x08090A0B0C0D0E0F), UINT64_C(0x0001020304050607))));
    r = simde_mm256_setzero_si256();

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 8 ; i++) {
      p = simde_mm256_set1_epi32(simde_mm256_movemask_epi8(a));
      p = simde_mm256_shuffle_epi8(p, byte_select);
      p = simde_mm256_xor_si256(r, p);
      r = simde_mm256_blendv_epi8(r, p, x);
      a = simde_mm256_add_epi8(a, a);
      x = simde_mm256_add_epi8(x, x);
    }

    return r;
  #else
    simde__m256i_private
      r_,
      x_ = simde__m256i_to_private(x),
      A_ = simde__m256i_to_private(A);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++) {
      r_.m128i[i] = simde_x_mm_gf2p8matrix_multiply_epi64_epi8(x_.m128i[i], A_.m128i[i]);
    }

    return simde__m256i_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_gf2p8matrix_multiply_epi64_epi8 (simde__m512i x, simde__m512i A) {
    simde__m512i_private
      r_,
      x_ = simde__m512i_to_private(x),
      A_ = simde__m512i_to_private(A);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
      r_.m256i[i] = simde_x_mm256_gf2p8matrix_multiply_epi64_epi8(x_.m256i[i], A_.m256i[i]);
    }

    return simde__m512i_from_private(r_);
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_x_mm_gf2p8inverse_epi8 (simde__m128i x) {
  #if defined(SIMDE_X_GFNI_HAVE_AES)
    /* Borrow the AES S-box: AESENCLAST(x, 0) = SubBytes(ShiftRows(x)). Undo
     * ShiftRows, then inv(x) = A_aes^-1 . (SubBytes(x) ^ 0x63), applied by
     * nibble decomposition with the 0x63 affine constant folded into the low
     * table. */
    simde__m128i s = simde_mm_aesenclast_si128(x, simde_mm_setzero_si128());
    s = simde_mm_shuffle_epi8(s, simde_x_gf2p8_inv_undo_sr.m128i);
    const simde__m128i nmask = simde_mm_set1_epi8(0x0F);
    const simde__m128i lo = simde_mm_and_si128(s, nmask);
    const simde__m128i hi = simde_mm_and_si128(simde_mm_srli_epi16(s, 4), nmask);
    return simde_mm_xor_si128(simde_mm_shuffle_epi8(simde_x_gf2p8_inv_tlo.m128i, lo),
                              simde_mm_shuffle_epi8(simde_x_gf2p8_inv_thi.m128i, hi));
  #elif defined(SIMDE_X_GFNI_HAVE_SHUFFLE)
    return simde_x_mm_gf2p8inverse_tower(x);
  #else
    simde__m128i_private
      r_,
      x_ = simde__m128i_to_private(x);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
      r_.u8[i] = simde_x_gf2p8inverse_lut.u8[x_.u8[i]];
    }

    return simde__m128i_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_x_mm256_gf2p8inverse_epi8 (simde__m256i x) {
  #if !defined(SIMDE_X_GFNI_HAVE_AES) && defined(SIMDE_X_GFNI_HAVE_SHUFFLE) && defined(SIMDE_X86_AVX2_NATIVE)
    /* Without AES the tower inverse runs at full ymm width. With AES the
     * 128-bit AES-borrow path below stays cheaper (aesenclast is 128-bit
     * anyway until a VAES path exists). */
    return simde_x_mm256_gf2p8inverse_tower(x);
  #else
    simde__m256i_private
      r_,
      x_ = simde__m256i_to_private(x);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++) {
      r_.m128i[i] = simde_x_mm_gf2p8inverse_epi8(x_.m128i[i]);
    }

    return simde__m256i_from_private(r_);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_x_mm512_gf2p8inverse_epi8 (simde__m512i x) {
    simde__m512i_private
      r_,
      x_ = simde__m512i_to_private(x);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
      r_.m256i[i] = simde_x_mm256_gf2p8inverse_epi8(x_.m256i[i]);
    }

    return simde__m512i_from_private(r_);
}

#define simde_x_mm_gf2p8matrix_multiply_inverse_epi64_epi8(x, A) simde_x_mm_gf2p8matrix_multiply_epi64_epi8(simde_x_mm_gf2p8inverse_epi8(x), A)
#define simde_x_mm256_gf2p8matrix_multiply_inverse_epi64_epi8(x, A) simde_x_mm256_gf2p8matrix_multiply_epi64_epi8(simde_x_mm256_gf2p8inverse_epi8(x), A)
#define simde_x_mm512_gf2p8matrix_multiply_inverse_epi64_epi8(x, A) simde_x_mm512_gf2p8matrix_multiply_epi64_epi8(simde_x_mm512_gf2p8inverse_epi8(x), A)

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_gf2p8affine_epi64_epi8 (simde__m128i x, simde__m128i A, int b)
    SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 255) {
  #if defined(SIMDE_CHECK_CONSTANT_) && defined(SIMDE_X_GFNI_HAVE_SHUFFLE)
    /* constant matrix: nibble decomposition with c folded into the low table. */
    simde__m128i_private cA_ = simde__m128i_to_private(A);
    if (SIMDE_CHECK_CONSTANT_(cA_.u64[0]) && SIMDE_CHECK_CONSTANT_(cA_.u64[1]) && (cA_.u64[0] == cA_.u64[1])) {
      const simde__m128i mlo = simde_mm_xor_si128(simde_x_gf2p8_matrix_nibble_lo(cA_.u64[0]), simde_mm_set1_epi8(HEDLEY_STATIC_CAST(int8_t, b)));
      const simde__m128i mhi = simde_x_gf2p8_matrix_nibble_hi(cA_.u64[0]);
      const simde__m128i nmask = simde_mm_set1_epi8(0x0F);
      return simde_mm_xor_si128(simde_mm_shuffle_epi8(mlo, simde_mm_and_si128(x, nmask)),
                                simde_mm_shuffle_epi8(mhi, simde_mm_and_si128(simde_mm_srli_epi16(x, 4), nmask)));
    }
  #endif
  return simde_mm_xor_si128(simde_x_mm_gf2p8matrix_multiply_epi64_epi8(x, A), simde_mm_set1_epi8(HEDLEY_STATIC_CAST(int8_t, b)));
}
#if defined(SIMDE_X86_GFNI_NATIVE)
  #define simde_mm_gf2p8affine_epi64_epi8(x, A, b) _mm_gf2p8affine_epi64_epi8(x, A, b)
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_gf2p8affine_epi64_epi8
  #define _mm_gf2p8affine_epi64_epi8(x, A, b) simde_mm_gf2p8affine_epi64_epi8(x, A, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_gf2p8affine_epi64_epi8 (simde__m256i x, simde__m256i A, int b)
    SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 255) {
  #if defined(SIMDE_CHECK_CONSTANT_) && defined(SIMDE_X86_AVX2_NATIVE)
    simde__m256i_private cA_ = simde__m256i_to_private(A);
    if (SIMDE_CHECK_CONSTANT_(cA_.u64[0]) && SIMDE_CHECK_CONSTANT_(cA_.u64[1]) &&
        SIMDE_CHECK_CONSTANT_(cA_.u64[2]) && SIMDE_CHECK_CONSTANT_(cA_.u64[3]) &&
        (cA_.u64[0] == cA_.u64[1]) && (cA_.u64[0] == cA_.u64[2]) && (cA_.u64[0] == cA_.u64[3])) {
      const simde__m256i mlo = simde_mm256_xor_si256(simde_mm256_broadcastsi128_si256(simde_x_gf2p8_matrix_nibble_lo(cA_.u64[0])), simde_mm256_set1_epi8(HEDLEY_STATIC_CAST(int8_t, b)));
      const simde__m256i mhi = simde_mm256_broadcastsi128_si256(simde_x_gf2p8_matrix_nibble_hi(cA_.u64[0]));
      const simde__m256i nmask = simde_mm256_set1_epi8(0x0F);
      return simde_mm256_xor_si256(simde_mm256_shuffle_epi8(mlo, simde_mm256_and_si256(x, nmask)),
                                   simde_mm256_shuffle_epi8(mhi, simde_mm256_and_si256(simde_mm256_srli_epi16(x, 4), nmask)));
    }
  #endif
  return simde_mm256_xor_si256(simde_x_mm256_gf2p8matrix_multiply_epi64_epi8(x, A), simde_mm256_set1_epi8(HEDLEY_STATIC_CAST(int8_t, b)));
}
#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
  #define simde_mm256_gf2p8affine_epi64_epi8(x, A, b) _mm256_gf2p8affine_epi64_epi8(x, A, b)
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_gf2p8affine_epi64_epi8
  #define _mm256_gf2p8affine_epi64_epi8(x, A, b) simde_mm256_gf2p8affine_epi64_epi8(x, A, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_gf2p8affine_epi64_epi8 (simde__m512i x, simde__m512i A, int b)
    SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 255) {
  return simde_mm512_xor_si512(simde_x_mm512_gf2p8matrix_multiply_epi64_epi8(x, A), simde_mm512_set1_epi8(HEDLEY_STATIC_CAST(int8_t, b)));
}
#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_gf2p8affine_epi64_epi8(x, A, b) _mm512_gf2p8affine_epi64_epi8(x, A, b)
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_gf2p8affine_epi64_epi8
  #define _mm512_gf2p8affine_epi64_epi8(x, A, b) simde_mm512_gf2p8affine_epi64_epi8(x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) _mm_mask_gf2p8affine_epi64_epi8(src, k, x, A, b)
#else
  #define simde_mm_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) simde_mm_mask_mov_epi8(src, k, simde_mm_gf2p8affine_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_gf2p8affine_epi64_epi8
  #define _mm_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) simde_mm_mask_gf2p8affine_epi64_epi8(src, k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) _mm256_mask_gf2p8affine_epi64_epi8(src, k, x, A, b)
#else
  #define simde_mm256_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) simde_mm256_mask_mov_epi8(src, k, simde_mm256_gf2p8affine_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_gf2p8affine_epi64_epi8
  #define _mm256_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) simde_mm256_mask_gf2p8affine_epi64_epi8(src, k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) _mm512_mask_gf2p8affine_epi64_epi8(src, k, x, A, b)
#else
  #define simde_mm512_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) simde_mm512_mask_mov_epi8(src, k, simde_mm512_gf2p8affine_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_gf2p8affine_epi64_epi8
  #define _mm512_mask_gf2p8affine_epi64_epi8(src, k, x, A, b) simde_mm512_mask_gf2p8affine_epi64_epi8(src, k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_maskz_gf2p8affine_epi64_epi8(k, x, A, b) _mm_maskz_gf2p8affine_epi64_epi8(k, x, A, b)
#else
  #define simde_mm_maskz_gf2p8affine_epi64_epi8(k, x, A, b) simde_mm_maskz_mov_epi8(k, simde_mm_gf2p8affine_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_gf2p8affine_epi64_epi8
  #define _mm_maskz_gf2p8affine_epi64_epi8(k, x, A, b) simde_mm_maskz_gf2p8affine_epi64_epi8(k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_maskz_gf2p8affine_epi64_epi8(k, x, A, b) _mm256_maskz_gf2p8affine_epi64_epi8(k, x, A, b)
#else
  #define simde_mm256_maskz_gf2p8affine_epi64_epi8(k, x, A, b) simde_mm256_maskz_mov_epi8(k, simde_mm256_gf2p8affine_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_gf2p8affine_epi64_epi8
  #define _mm256_maskz_gf2p8affine_epi64_epi8(k, x, A, b) simde_mm256_maskz_gf2p8affine_epi64_epi8(k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_maskz_gf2p8affine_epi64_epi8(k, x, A, b) _mm512_maskz_gf2p8affine_epi64_epi8(k, x, A, b)
#else
  #define simde_mm512_maskz_gf2p8affine_epi64_epi8(k, x, A, b) simde_mm512_maskz_mov_epi8(k, simde_mm512_gf2p8affine_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_gf2p8affine_epi64_epi8
  #define _mm512_maskz_gf2p8affine_epi64_epi8(k, x, A, b) simde_mm512_maskz_gf2p8affine_epi64_epi8(k, x, A, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_gf2p8affineinv_epi64_epi8 (simde__m128i x, simde__m128i A, int b)
    SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 255) {
  #if defined(SIMDE_X_GFNI_HAVE_AES) && defined(SIMDE_CHECK_CONSTANT_)
    /* constant matrix: fuse M into the post-AES nibble tables (one AES + nibble);
     * M=A_aes & c=0x63 collapses to plain SubBytes. */
    simde__m128i_private cA_ = simde__m128i_to_private(A);
    if (SIMDE_CHECK_CONSTANT_(cA_.u64[0]) && SIMDE_CHECK_CONSTANT_(cA_.u64[1]) && (cA_.u64[0] == cA_.u64[1]) && SIMDE_CHECK_CONSTANT_(b)) {
      return simde_x_mm_gf2p8affineinv_const(x, cA_.u64[0], b);
    }
  #elif defined(SIMDE_X_GFNI_HAVE_SHUFFLE) && defined(SIMDE_CHECK_CONSTANT_)
    /* constant matrix: fused tower path (SHUFFLE without AES) */
    simde__m128i_private cA_ = simde__m128i_to_private(A);
    if (SIMDE_CHECK_CONSTANT_(cA_.u64[0]) && SIMDE_CHECK_CONSTANT_(cA_.u64[1]) && (cA_.u64[0] == cA_.u64[1]) && SIMDE_CHECK_CONSTANT_(b)) {
      return simde_x_mm_gf2p8affineinv_tower_const(x, cA_.u64[0], b);
    }
  #endif
  return simde_mm_xor_si128(simde_x_mm_gf2p8matrix_multiply_inverse_epi64_epi8(x, A), simde_mm_set1_epi8(HEDLEY_STATIC_CAST(int8_t, b)));
}
#if defined(SIMDE_X86_GFNI_NATIVE)
  #define simde_mm_gf2p8affineinv_epi64_epi8(x, A, b) _mm_gf2p8affineinv_epi64_epi8(x, A, b)
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_gf2p8affineinv_epi64_epi8
  #define _mm_gf2p8affineinv_epi64_epi8(x, A, b) simde_mm_gf2p8affineinv_epi64_epi8(x, A, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_gf2p8affineinv_epi64_epi8 (simde__m256i x, simde__m256i A, int b)
    SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 255) {
  #if defined(SIMDE_X_GFNI_HAVE_AES) && defined(SIMDE_CHECK_CONSTANT_)
    simde__m256i_private cA_ = simde__m256i_to_private(A);
    if (SIMDE_CHECK_CONSTANT_(cA_.u64[0]) && SIMDE_CHECK_CONSTANT_(cA_.u64[1]) &&
        SIMDE_CHECK_CONSTANT_(cA_.u64[2]) && SIMDE_CHECK_CONSTANT_(cA_.u64[3]) && SIMDE_CHECK_CONSTANT_(b) &&
        (cA_.u64[0] == cA_.u64[1]) && (cA_.u64[0] == cA_.u64[2]) && (cA_.u64[0] == cA_.u64[3])) {
      simde__m256i_private r_, x_ = simde__m256i_to_private(x);
      r_.m128i[0] = simde_x_mm_gf2p8affineinv_const(x_.m128i[0], cA_.u64[0], b);
      r_.m128i[1] = simde_x_mm_gf2p8affineinv_const(x_.m128i[1], cA_.u64[0], b);
      return simde__m256i_from_private(r_);
    }
  #elif defined(SIMDE_X_GFNI_HAVE_SHUFFLE) && defined(SIMDE_CHECK_CONSTANT_)
    simde__m256i_private cA_ = simde__m256i_to_private(A);
    if (SIMDE_CHECK_CONSTANT_(cA_.u64[0]) && SIMDE_CHECK_CONSTANT_(cA_.u64[1]) &&
        SIMDE_CHECK_CONSTANT_(cA_.u64[2]) && SIMDE_CHECK_CONSTANT_(cA_.u64[3]) && SIMDE_CHECK_CONSTANT_(b) &&
        (cA_.u64[0] == cA_.u64[1]) && (cA_.u64[0] == cA_.u64[2]) && (cA_.u64[0] == cA_.u64[3])) {
    #if defined(SIMDE_X86_AVX2_NATIVE)
      return simde_x_mm256_gf2p8affineinv_tower_const(x, cA_.u64[0], b);
    #else
      simde__m256i_private r_, x_ = simde__m256i_to_private(x);
      r_.m128i[0] = simde_x_mm_gf2p8affineinv_tower_const(x_.m128i[0], cA_.u64[0], b);
      r_.m128i[1] = simde_x_mm_gf2p8affineinv_tower_const(x_.m128i[1], cA_.u64[0], b);
      return simde__m256i_from_private(r_);
    #endif
    }
  #endif
  return simde_mm256_xor_si256(simde_x_mm256_gf2p8matrix_multiply_inverse_epi64_epi8(x, A), simde_mm256_set1_epi8(HEDLEY_STATIC_CAST(int8_t, b)));
}
#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX_NATIVE)
  #define simde_mm256_gf2p8affineinv_epi64_epi8(x, A, b) _mm256_gf2p8affineinv_epi64_epi8(x, A, b)
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_gf2p8affineinv_epi64_epi8
  #define _mm256_gf2p8affineinv_epi64_epi8(x, A, b) simde_mm256_gf2p8affineinv_epi64_epi8(x, A, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_gf2p8affineinv_epi64_epi8 (simde__m512i x, simde__m512i A, int b)
    SIMDE_REQUIRE_CONSTANT_RANGE(b, 0, 255) {
  #if defined(SIMDE_X_GFNI_HAVE_AES) && defined(SIMDE_CHECK_CONSTANT_)
    simde__m512i_private cA_ = simde__m512i_to_private(A);
    if (SIMDE_CHECK_CONSTANT_(cA_.u64[0]) && SIMDE_CHECK_CONSTANT_(cA_.u64[1]) &&
        SIMDE_CHECK_CONSTANT_(cA_.u64[2]) && SIMDE_CHECK_CONSTANT_(cA_.u64[3]) &&
        SIMDE_CHECK_CONSTANT_(cA_.u64[4]) && SIMDE_CHECK_CONSTANT_(cA_.u64[5]) &&
        SIMDE_CHECK_CONSTANT_(cA_.u64[6]) && SIMDE_CHECK_CONSTANT_(cA_.u64[7]) && SIMDE_CHECK_CONSTANT_(b) &&
        (cA_.u64[0] == cA_.u64[1]) && (cA_.u64[0] == cA_.u64[2]) && (cA_.u64[0] == cA_.u64[3]) &&
        (cA_.u64[0] == cA_.u64[4]) && (cA_.u64[0] == cA_.u64[5]) && (cA_.u64[0] == cA_.u64[6]) && (cA_.u64[0] == cA_.u64[7])) {
      simde__m512i_private r_, x_ = simde__m512i_to_private(x);
      for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++)
        r_.m128i[i] = simde_x_mm_gf2p8affineinv_const(x_.m128i[i], cA_.u64[0], b);
      return simde__m512i_from_private(r_);
    }
  #elif defined(SIMDE_X_GFNI_HAVE_SHUFFLE) && defined(SIMDE_CHECK_CONSTANT_)
    simde__m512i_private cA_ = simde__m512i_to_private(A);
    if (SIMDE_CHECK_CONSTANT_(cA_.u64[0]) && SIMDE_CHECK_CONSTANT_(cA_.u64[1]) &&
        SIMDE_CHECK_CONSTANT_(cA_.u64[2]) && SIMDE_CHECK_CONSTANT_(cA_.u64[3]) &&
        SIMDE_CHECK_CONSTANT_(cA_.u64[4]) && SIMDE_CHECK_CONSTANT_(cA_.u64[5]) &&
        SIMDE_CHECK_CONSTANT_(cA_.u64[6]) && SIMDE_CHECK_CONSTANT_(cA_.u64[7]) && SIMDE_CHECK_CONSTANT_(b) &&
        (cA_.u64[0] == cA_.u64[1]) && (cA_.u64[0] == cA_.u64[2]) && (cA_.u64[0] == cA_.u64[3]) &&
        (cA_.u64[0] == cA_.u64[4]) && (cA_.u64[0] == cA_.u64[5]) && (cA_.u64[0] == cA_.u64[6]) && (cA_.u64[0] == cA_.u64[7])) {
      simde__m512i_private r_, x_ = simde__m512i_to_private(x);
    #if defined(SIMDE_X86_AVX2_NATIVE)
      for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++)
        r_.m256i[i] = simde_x_mm256_gf2p8affineinv_tower_const(x_.m256i[i], cA_.u64[0], b);
    #else
      for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++)
        r_.m128i[i] = simde_x_mm_gf2p8affineinv_tower_const(x_.m128i[i], cA_.u64[0], b);
    #endif
      return simde__m512i_from_private(r_);
    }
  #endif
  return simde_mm512_xor_si512(simde_x_mm512_gf2p8matrix_multiply_inverse_epi64_epi8(x, A), simde_mm512_set1_epi8(HEDLEY_STATIC_CAST(int8_t, b)));
}
#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_gf2p8affineinv_epi64_epi8(x, A, b) _mm512_gf2p8affineinv_epi64_epi8(x, A, b)
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_gf2p8affineinv_epi64_epi8
  #define _mm512_gf2p8affineinv_epi64_epi8(x, A, b) simde_mm512_gf2p8affineinv_epi64_epi8(x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) _mm_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b)
#else
  #define simde_mm_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) simde_mm_mask_mov_epi8(src, k, simde_mm_gf2p8affineinv_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_gf2p8affineinv_epi64_epi8
  #define _mm_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) simde_mm_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) _mm256_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b)
#else
  #define simde_mm256_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) simde_mm256_mask_mov_epi8(src, k, simde_mm256_gf2p8affineinv_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_gf2p8affineinv_epi64_epi8
  #define _mm256_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) simde_mm256_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) _mm512_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b)
#else
  #define simde_mm512_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) simde_mm512_mask_mov_epi8(src, k, simde_mm512_gf2p8affineinv_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_gf2p8affineinv_epi64_epi8
  #define _mm512_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b) simde_mm512_mask_gf2p8affineinv_epi64_epi8(src, k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) _mm_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b)
#else
  #define simde_mm_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) simde_mm_maskz_mov_epi8(k, simde_mm_gf2p8affineinv_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_gf2p8affineinv_epi64_epi8
  #define _mm_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) simde_mm_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
  #define simde_mm256_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) _mm256_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b)
#else
  #define simde_mm256_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) simde_mm256_maskz_mov_epi8(k, simde_mm256_gf2p8affineinv_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_gf2p8affineinv_epi64_epi8
  #define _mm256_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) simde_mm256_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b)
#endif

#if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm512_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) _mm512_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b)
#else
  #define simde_mm512_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) simde_mm512_maskz_mov_epi8(k, simde_mm512_gf2p8affineinv_epi64_epi8(x, A, b))
#endif
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_gf2p8affineinv_epi64_epi8
  #define _mm512_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b) simde_mm512_maskz_gf2p8affineinv_epi64_epi8(k, x, A, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i simde_mm_gf2p8mul_epi8 (simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_GFNI_NATIVE) && (defined(SIMDE_X86_AVX512VL_NATIVE) || !defined(SIMDE_X86_AVX512F_NATIVE))
    return _mm_gf2p8mul_epi8(a, b);
  #else
    #if defined(SIMDE_CHECK_CONSTANT_) && defined(SIMDE_X_GFNI_HAVE_SHUFFLE)
      {
        /* If b is a compile-time constant broadcast of a single byte, multiplying
        * by it is a GF(2) affine transform, so it degenerates to a matrix
        * multiply (which itself uses the nibble path).
        * Gated on SIMDE_X_GFNI_HAVE_SHUFFLE: without a byte-shuffle the matrix
        * multiply falls back to a movemask loop that is slower than the
        * schoolbook GF multiply below. */
        simde__m128i_private simde_x_gfni_bc_ = simde__m128i_to_private(b);
        if (SIMDE_CHECK_CONSTANT_(simde_x_gfni_bc_.u64[0]) && (simde_x_gfni_bc_.u64[0] == simde_x_gfni_bc_.u64[1]) &&
            (simde_x_gfni_bc_.u64[0] == HEDLEY_STATIC_CAST(uint64_t, simde_x_gfni_bc_.u8[0]) * UINT64_C(0x0101010101010101))) {
          if (simde_x_gfni_bc_.u8[0] == 0x00) return simde_mm_setzero_si128();  /* a (x) 0 = 0 */
          if (simde_x_gfni_bc_.u8[0] == 0x01) return a;                         /* a (x) 1 = a */
          return simde_x_mm_gf2p8matrix_multiply_epi64_epi8(a,
            simde_mm_set1_epi64x(HEDLEY_STATIC_CAST(int64_t, simde_x_gf2p8_mul_matrix_lut[simde_x_gfni_bc_.u8[0]])));
        }
      }
    #endif
    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    const poly8x16_t pa = vreinterpretq_p8_u8(simde__m128i_to_neon_u8(a));
    const poly8x16_t pb = vreinterpretq_p8_u8(simde__m128i_to_neon_u8(b));
    const uint8x16_t lo = vreinterpretq_u8_p16(vmull_p8(vget_low_p8(pa), vget_low_p8(pb)));
    #if defined (SIMDE_ARM_NEON_A64V8_NATIVE)
      uint8x16_t hi = vreinterpretq_u8_p16(vmull_high_p8(pa, pb));
    #else
      uint8x16_t hi = vreinterpretq_u8_p16(vmull_p8(vget_high_p8(pa), vget_high_p8(pb)));
    #endif
    uint8x16x2_t hilo = vuzpq_u8(lo, hi);
    uint8x16_t r = hilo.val[0];
    hi = hilo.val[1];
    const uint8x16_t idxHi = vshrq_n_u8(hi, 4);
    const uint8x16_t idxLo = vandq_u8(hi, vdupq_n_u8(0xF));

    #if defined (SIMDE_ARM_NEON_A64V8_NATIVE)
      static const uint8_t reduceLutHiData[] = {
        0x00, 0xab, 0x4d, 0xe6, 0x9a, 0x31, 0xd7, 0x7c,
        0x2f, 0x84, 0x62, 0xc9, 0xb5, 0x1e, 0xf8, 0x53
      };
      static const uint8_t reduceLutLoData[] = {
        0x00, 0x1b, 0x36, 0x2d, 0x6c, 0x77, 0x5a, 0x41,
        0xd8, 0xc3, 0xee, 0xf5, 0xb4, 0xaf, 0x82, 0x99
      };
      const uint8x16_t reduceLutHi = vld1q_u8(reduceLutHiData);
      const uint8x16_t reduceLutLo = vld1q_u8(reduceLutLoData);
      r = veorq_u8(r, vqtbl1q_u8(reduceLutHi, idxHi));
      r = veorq_u8(r, vqtbl1q_u8(reduceLutLo, idxLo));
    #else
      static const uint8_t reduceLutHiData[] = {
        0x00, 0x2f,
        0xab, 0x84,
        0x4d, 0x62,
        0xe6, 0xc9,
        0x9a, 0xb5,
        0x31, 0x1e,
        0xd7, 0xf8,
        0x7c, 0x53
      };
      static const uint8_t reduceLutLoData[] = {
        0x00, 0xd8,
        0x1b, 0xc3,
        0x36, 0xee,
        0x2d, 0xf5,
        0x6c, 0xb4,
        0x77, 0xaf,
        0x5a, 0x82,
        0x41, 0x99
      };
      const uint8x8x2_t reduceLutHi = vld2_u8(reduceLutHiData);
      const uint8x8x2_t reduceLutLo = vld2_u8(reduceLutLoData);
      r = veorq_u8(r, vcombine_u8(vtbl2_u8(reduceLutHi, vget_low_u8(idxHi)), vtbl2_u8(reduceLutHi, vget_high_u8(idxHi))));
      r = veorq_u8(r, vcombine_u8(vtbl2_u8(reduceLutLo, vget_low_u8(idxLo)), vtbl2_u8(reduceLutLo, vget_high_u8(idxLo))));
    #endif
    return simde__m128i_from_neon_u8(r);
  #elif defined(SIMDE_ZARCH_ZVECTOR_13_NATIVE)
    SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) x, y, lo, hi;
    SIMDE_POWER_ALTIVEC_VECTOR(unsigned short) even, odd, mask0x00FF;
    x = simde__m128i_to_altivec_u8(a);
    y = simde__m128i_to_altivec_u8(b);
    mask0x00FF = vec_splats(HEDLEY_STATIC_CAST(unsigned short, 0x00FF));
    lo = y & HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char), mask0x00FF);
    hi = y ^ lo;
    even = vec_gfmsum(x, lo);
    odd  = vec_gfmsum(x, hi);
    lo = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char), vec_sel(vec_rli(odd, 8), even, mask0x00FF));
    hi = HEDLEY_REINTERPRET_CAST(SIMDE_POWER_ALTIVEC_VECTOR(unsigned char), vec_sel(odd, vec_rli(even, 8), mask0x00FF));
    const SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) reduceLutHi = {0x00, 0xab, 0x4d, 0xe6, 0x9a, 0x31, 0xd7, 0x7c, 0x2f, 0x84, 0x62, 0xc9, 0xb5, 0x1e, 0xf8, 0x53};
    const SIMDE_POWER_ALTIVEC_VECTOR(unsigned char) reduceLutLo = {0x00, 0x1b, 0x36, 0x2d, 0x6c, 0x77, 0x5a, 0x41, 0xd8, 0xc3, 0xee, 0xf5, 0xb4, 0xaf, 0x82, 0x99};
    lo = lo ^ vec_perm(reduceLutHi, reduceLutHi, vec_rli(hi, 4));
    lo = lo ^ vec_perm(reduceLutLo, reduceLutLo, hi);
    return simde__m128i_from_altivec_u8(lo);
    #elif defined(SIMDE_X_GFNI_HAVE_SHUFFLE)
      return simde_x_mm_gf2p8mul_tower(a, b);
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    simde__m128i r, t;
    const simde__m128i zero = simde_mm_setzero_si128();
    const simde__m128i ones = simde_mm_set1_epi8(0x01);

    const simde__m128i fgp = simde_mm_set1_epi8(SIMDE_X86_GFNI_FGP);

    t = simde_mm_and_si128(b, ones);
    t = simde_mm_cmpeq_epi8(t, ones);
    r = simde_mm_and_si128(a, t);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (int i = 0 ; i < 7 ; i++) {
      t = simde_mm_cmpgt_epi8(zero, a);
      t = simde_mm_and_si128(fgp, t);
      a = simde_mm_add_epi8(a, a);
      a = simde_mm_xor_si128(a, t);
      b = simde_mm_srli_epi64(b, 1);
      t = simde_mm_and_si128(b, ones);
      t = simde_mm_cmpeq_epi8(t, ones);
      t = simde_mm_and_si128(a, t);
      r = simde_mm_xor_si128(r, t);
    }

    return r;
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b);

    const uint8_t fgp = SIMDE_X86_GFNI_FGP;

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
      r_.u8[i] = 0;
      while ((a_.u8[i] != 0) && (b_.u8[i] != 0)) {
        if (b_.u8[i] & 1)
          r_.u8[i] ^= a_.u8[i];

        if (a_.u8[i] & 0x80)
          a_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, (a_.u8[i] << 1) ^ fgp);
        else
          a_.u8[i] <<= 1;

        b_.u8[i] >>= 1;
      }
    }

    return simde__m128i_from_private(r_);
  #endif
  #endif
}
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_gf2p8mul_epi8
  #define _mm_gf2p8mul_epi8(a, b) simde_mm_gf2p8mul_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_gf2p8mul_epi8 (simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_GFNI_NATIVE) && (defined(SIMDE_X86_AVX512VL_NATIVE) || (defined(SIMDE_X86_AVX_NATIVE) && !defined(SIMDE_X86_AVX512F_NATIVE)))
    return _mm256_gf2p8mul_epi8(a, b);
  #else
  #if defined(SIMDE_CHECK_CONSTANT_) && defined(SIMDE_X_GFNI_HAVE_SHUFFLE) && defined(SIMDE_X86_AVX2_NATIVE)
    {
      /* Same constant-multiplier degeneration as the 128-bit version, kept at
        * 256-bit width so the matrix multiply takes its ymm nibble path. */
      simde__m256i_private simde_x_gfni_bc_ = simde__m256i_to_private(b);
      if (SIMDE_CHECK_CONSTANT_(simde_x_gfni_bc_.u64[0]) &&
          (simde_x_gfni_bc_.u64[0] == simde_x_gfni_bc_.u64[1]) &&
          (simde_x_gfni_bc_.u64[0] == simde_x_gfni_bc_.u64[2]) &&
          (simde_x_gfni_bc_.u64[0] == simde_x_gfni_bc_.u64[3]) &&
          (simde_x_gfni_bc_.u64[0] == HEDLEY_STATIC_CAST(uint64_t, simde_x_gfni_bc_.u8[0]) * UINT64_C(0x0101010101010101))) {
        if (simde_x_gfni_bc_.u8[0] == 0x00) return simde_mm256_setzero_si256();  /* a (x) 0 = 0 */
        if (simde_x_gfni_bc_.u8[0] == 0x01) return a;                            /* a (x) 1 = a */
        return simde_x_mm256_gf2p8matrix_multiply_epi64_epi8(a,
          simde_mm256_set1_epi64x(HEDLEY_STATIC_CAST(int64_t, simde_x_gf2p8_mul_matrix_lut[simde_x_gfni_bc_.u8[0]])));
      }
    }
  #endif
  #if defined(SIMDE_X_GFNI_HAVE_SHUFFLE) && defined(SIMDE_X86_AVX2_NATIVE)
    return simde_x_mm256_gf2p8mul_tower(a, b);
  #else
    simde__m256i_private
      r_,
      a_ = simde__m256i_to_private(a),
      b_ = simde__m256i_to_private(b);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.m128i) / sizeof(r_.m128i[0])) ; i++) {
      r_.m128i[i] = simde_mm_gf2p8mul_epi8(a_.m128i[i], b_.m128i[i]);
    }

    return simde__m256i_from_private(r_);
  #endif
  #endif
}
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX_ENABLE_NATIVE_ALIASES)
  #undef _mm256_gf2p8mul_epi8
  #define _mm256_gf2p8mul_epi8(a, b) simde_mm256_gf2p8mul_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_gf2p8mul_epi8 (simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_gf2p8mul_epi8(a, b);
  #else
    simde__m512i_private
      r_,
      a_ = simde__m512i_to_private(a),
      b_ = simde__m512i_to_private(b);

    #if !defined(__INTEL_COMPILER)
      SIMDE_VECTORIZE
    #endif
    for (size_t i = 0 ; i < (sizeof(r_.m256i) / sizeof(r_.m256i[0])) ; i++) {
      r_.m256i[i] = simde_mm256_gf2p8mul_epi8(a_.m256i[i], b_.m256i[i]);
    }

    return simde__m512i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_gf2p8mul_epi8
  #define _mm512_gf2p8mul_epi8(a, b) simde_mm512_gf2p8mul_epi8(a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_mask_gf2p8mul_epi8 (simde__m128i src, simde__mmask16 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_mask_gf2p8mul_epi8(src, k, a, b);
  #else
    return simde_mm_mask_mov_epi8(src, k, simde_mm_gf2p8mul_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_mask_gf2p8mul_epi8
  #define _mm_mask_gf2p8mul_epi8(src, k, a, b) simde_mm_mask_gf2p8mul_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_mask_gf2p8mul_epi8 (simde__m256i src, simde__mmask32 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_mask_gf2p8mul_epi8(src, k, a, b);
  #else
    return simde_mm256_mask_mov_epi8(src, k, simde_mm256_gf2p8mul_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_gf2p8mul_epi8
  #define _mm256_mask_gf2p8mul_epi8(src, k, a, b) simde_mm256_mask_gf2p8mul_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_mask_gf2p8mul_epi8 (simde__m512i src, simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_mask_gf2p8mul_epi8(src, k, a, b);
  #else
    return simde_mm512_mask_mov_epi8(src, k, simde_mm512_gf2p8mul_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_mask_gf2p8mul_epi8
  #define _mm512_mask_gf2p8mul_epi8(src, k, a, b) simde_mm512_mask_gf2p8mul_epi8(src, k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_maskz_gf2p8mul_epi8 (simde__mmask16 k, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_maskz_gf2p8mul_epi8(k, a, b);
  #else
    return simde_mm_maskz_mov_epi8(k, simde_mm_gf2p8mul_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm_maskz_gf2p8mul_epi8
  #define _mm_maskz_gf2p8mul_epi8(k, a, b) simde_mm_maskz_gf2p8mul_epi8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_maskz_gf2p8mul_epi8 (simde__mmask32 k, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_maskz_gf2p8mul_epi8(k, a, b);
  #else
    return  simde_mm256_maskz_mov_epi8(k, simde_mm256_gf2p8mul_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_gf2p8mul_epi8
  #define _mm256_maskz_gf2p8mul_epi8(k, a, b) simde_mm256_maskz_gf2p8mul_epi8(k, a, b)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_maskz_gf2p8mul_epi8 (simde__mmask64 k, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_GFNI_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm512_maskz_gf2p8mul_epi8(k, a, b);
  #else
    return simde_mm512_maskz_mov_epi8(k, simde_mm512_gf2p8mul_epi8(a, b));
  #endif
}
#if defined(SIMDE_X86_GFNI_ENABLE_NATIVE_ALIASES) || defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm512_maskz_gf2p8mul_epi8
  #define _mm512_maskz_gf2p8mul_epi8(k, a, b) simde_mm512_maskz_gf2p8mul_epi8(k, a, b)
#endif

SIMDE_END_DECLS_

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_GFNI_H) */
