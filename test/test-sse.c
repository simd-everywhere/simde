/* Copyright (c) 2017 Evan Nemerson <evan@nemerson.com>
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
 */

#include "test.h"
#include "../sse.h"

#include <stdio.h>
#include <math.h>

#define assert_m128_ps(a, cmp, b)					\
  do {									\
    munit_assert_float(((float*) (&a))[0], cmp, ((float*) (&b))[0]);	\
    munit_assert_float(((float*) (&a))[1], cmp, ((float*) (&b))[1]);	\
    munit_assert_float(((float*) (&a))[2], cmp, ((float*) (&b))[2]);	\
    munit_assert_float(((float*) (&a))[3], cmp, ((float*) (&b))[3]);	\
  } while (0)

static inline simde__m128
random_m128_float(void) {
  simde__m128 r;
  random_floatv(sizeof(r.f32) / sizeof(r.f32[0]), (float*) &r);
  return r;
}

static inline simde__m128
simde_m128_set_u32(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
  simde__m128 r;
  uint32_t* rp = (uint32_t*) &r;
  rp[3] = a;
  rp[2] = b;
  rp[1] = c;
  rp[0] = d;
  return r;
}

static MunitResult
test_simde_mm_set_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  float d[4];
  random_floatv(sizeof(d) / sizeof(d[0]), d);

  simde__m128 x = simde_mm_set_ps(d[0], d[1], d[2], d[3]);

  float* f = (float*) &x;
  munit_assert_float(f[0], ==, d[3]);
  munit_assert_float(f[1], ==, d[2]);
  munit_assert_float(f[2], ==, d[1]);
  munit_assert_float(f[3], ==, d[0]);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set1_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  float d;
  random_floatv(1, &d);

  simde__m128 x = simde_mm_set1_ps(d);

  float* f = (float*) &x;
  munit_assert_float(f[0], ==, d);
  munit_assert_float(f[1], ==, d);
  munit_assert_float(f[2], ==, d);
  munit_assert_float(f[3], ==, d);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_add_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const simde__m128 expected = simde_mm_set_ps(6.0f, 8.0f, 10.0f, 12.0f);

  simde__m128 a = simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f);
  simde__m128 b = simde_mm_set_ps(5.0f, 6.0f, 7.0f, 8.0f);
  simde__m128 r = simde_mm_add_ps(a, b);

  assert_m128_ps(r, ==, expected);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_add_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const simde__m128 expected = simde_mm_set_ps(1.0f, 2.0f, 3.0f, 12.0f);

  simde__m128 a = simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f);
  simde__m128 b = simde_mm_set_ps(5.0f, 6.0f, 7.0f, 8.0f);
  simde__m128 r = simde_mm_add_ss(a, b);

  assert_m128_ps(r, ==, expected);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_and_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x815d2f44, 0x8b914eb4, 0xa596a496, 0x609345c2),
      simde_m128_set_u32(0x63899b14, 0xe53c2289, 0x5495ba65, 0x87e357db),
      simde_m128_set_u32(0x01090b04, 0x81100280, 0x0494a004, 0x008345c2) },
    { simde_m128_set_u32(0xbcbd985c, 0xf62a9298, 0x6f3a487c, 0xf4b40bf7),
      simde_m128_set_u32(0x93beebd6, 0xea852e98, 0x07bfe129, 0x8de07224),
      simde_m128_set_u32(0x90bc8854, 0xe2000298, 0x073a4028, 0x84a00224) },
    { simde_m128_set_u32(0x0ede7aae, 0x44473a32, 0x36f199d6, 0x18e1e7d4),
      simde_m128_set_u32(0xf29bd53d, 0x9f1fe5b6, 0xb318d1d6, 0xa3dcbecc),
      simde_m128_set_u32(0x029a502c, 0x04072032, 0x321091d6, 0x00c0a6c4) },
    { simde_m128_set_u32(0x31b12176, 0x95934f5e, 0x9ad31c78, 0x5aa8aacb),
      simde_m128_set_u32(0xecb69c03, 0x2c6ca4fb, 0x4bd86f88, 0x226469a8),
      simde_m128_set_u32(0x20b00002, 0x0400045a, 0x0ad00c08, 0x02202888) },
    { simde_m128_set_u32(0x20c3027f, 0xf258a48b, 0xaa2a2520, 0x5105db7f),
      simde_m128_set_u32(0xc56b2d69, 0x38baafd9, 0xd4064045, 0xd5e3759f),
      simde_m128_set_u32(0x00430069, 0x3018a489, 0x80020000, 0x5101511f) },
    { simde_m128_set_u32(0xf9dfe7c0, 0x584f031e, 0xb3e08d37, 0x700e3750),
      simde_m128_set_u32(0xb142cfe2, 0x5510fca2, 0x7f3609d7, 0x2716f896),
      simde_m128_set_u32(0xb142c7c0, 0x50000002, 0x33200917, 0x20063010) },
    { simde_m128_set_u32(0x7ef0e470, 0x97539bde, 0x9cb179c2, 0xeed3f223),
      simde_m128_set_u32(0x6a81e995, 0x6d35f368, 0xf8984955, 0x426e807a),
      simde_m128_set_u32(0x6a80e010, 0x05119348, 0x98904940, 0x42428022) },
    { simde_m128_set_u32(0xc9c85b10, 0x5586c223, 0x8dbca9d1, 0x8da53a09),
      simde_m128_set_u32(0x9a002ceb, 0xc1be3782, 0xde2d6651, 0x9ce47d71),
      simde_m128_set_u32(0x88000800, 0x41860202, 0x8c2c2051, 0x8ca43801) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_and_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_andnot_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[] = {
    { simde_m128_set_u32(0x68a765a6U, 0x3615220eU, 0xf27caeb4U, 0x145357a5U),
      simde_m128_set_u32(0x7db442f9U, 0xc2f92119U, 0xdf75482eU, 0xa5d29ccaU),
      simde_m128_set_u32(0x15100259U, 0xc0e80111U, 0x0d01400aU, 0xa180884aU) },
    { simde_m128_set_u32(0xbac21a36U, 0x1b8c1a30U, 0x207e65f1U, 0x7e986bc6U),
      simde_m128_set_u32(0xb4e0053fU, 0xb1b443c2U, 0x1df73f23U, 0xb88c9b63U),
      simde_m128_set_u32(0x04200509U, 0xa03041c2U, 0x1d811a02U, 0x80049021U) },
    { simde_m128_set_u32(0x9f9907b0U, 0x266cf90bU, 0xefbcb2daU, 0x63721e2fU),
      simde_m128_set_u32(0xb418e8e0U, 0x04c49252U, 0x85f1d529U, 0x20ab72fcU),
      simde_m128_set_u32(0x2000e840U, 0x00800250U, 0x00414521U, 0x008960d0U) },
    { simde_m128_set_u32(0x32a6778fU, 0x927fa890U, 0x2f76ea91U, 0x9fdc18a3U),
      simde_m128_set_u32(0x9a45c22bU, 0xfb88b4f5U, 0x8d063b31U, 0x832b9acdU),
      simde_m128_set_u32(0x88418020U, 0x69801465U, 0x80001120U, 0x0023824cU) },
    { simde_m128_set_u32(0x659de4f8U, 0xf213fa5eU, 0xc6c9e0beU, 0x6b9bf277U),
      simde_m128_set_u32(0x31908876U, 0x1eeec04cU, 0x5310af8fU, 0xef14b6d9U),
      simde_m128_set_u32(0x10000806U, 0x0cec0000U, 0x11100f01U, 0x84040488U) },
    { simde_m128_set_u32(0x6d451104U, 0x027c2d5cU, 0xdc87cb64U, 0x6bf717a5U),
      simde_m128_set_u32(0x01e81e45U, 0xa1fea0d1U, 0x68287855U, 0x54e0538dU),
      simde_m128_set_u32(0x00a80e41U, 0xa1828081U, 0x20283011U, 0x14004008U) },
    { simde_m128_set_u32(0xb1e89e3aU, 0x6d79a9c6U, 0x43e7d670U, 0x98a011a6U),
      simde_m128_set_u32(0x96a71891U, 0x43f287c0U, 0x125aace7U, 0x8e69b84bU),
      simde_m128_set_u32(0x06070081U, 0x02820600U, 0x10182887U, 0x0649a849U) },
    { simde_m128_set_u32(0xe497a675U, 0x9ab8e09eU, 0x25f2ae74U, 0xfc5647eaU),
      simde_m128_set_u32(0x045e24cdU, 0xd72971afU, 0x1ec71d1fU, 0x9f4d091dU),
      simde_m128_set_u32(0x00480088U, 0x45011121U, 0x1a05110bU, 0x03090815U) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r;
    r = simde_mm_andnot_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_avg_pu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[] = {
    { simde_mm_set_pi16(0x17f0, 0x1d12, 0x84d4, 0xeba7),
      simde_mm_set_pi16(0x7b42, 0x57c8, 0x476d, 0x63a8),
      simde_mm_set_pi16(0x4999, 0x3a6d, 0x6621, 0xa7a8) },
    { simde_mm_set_pi16(0xb202, 0x0f18, 0x3692, 0xbdb1),
      simde_mm_set_pi16(0x6fa1, 0xcff5, 0xff17, 0x8952),
      simde_mm_set_pi16(0x90d2, 0x6f87, 0x9ad5, 0xa382) },
    { simde_mm_set_pi16(0xcf1f, 0x3628, 0x83c5, 0xe2f0),
      simde_mm_set_pi16(0x32cf, 0x24dc, 0xddc7, 0xa531),
      simde_mm_set_pi16(0x80f7, 0x2d82, 0xb0c6, 0xc411) },
    { simde_mm_set_pi16(0xc61c, 0xebfe, 0x53f3, 0x6af8),
      simde_mm_set_pi16(0xb2be, 0x3b7c, 0xd646, 0xf5db),
      simde_mm_set_pi16(0xbc6d, 0x93bd, 0x951d, 0xb06a) },
    { simde_mm_set_pi16(0x2d75, 0x8696, 0xac92, 0x4be4),
      simde_mm_set_pi16(0xa670, 0x20d1, 0x5440, 0x5836),
      simde_mm_set_pi16(0x69f3, 0x53b4, 0x8069, 0x520d) },
    { simde_mm_set_pi16(0xc169, 0xc53a, 0x0562, 0x7fc4),
      simde_mm_set_pi16(0x2c37, 0xeb5f, 0x7086, 0xc453),
      simde_mm_set_pi16(0x76d0, 0xd84d, 0x3af4, 0xa20c) },
    { simde_mm_set_pi16(0x2d16, 0xa1eb, 0x56bd, 0x87a5),
      simde_mm_set_pi16(0x44d2, 0xd7c8, 0x02b6, 0xd1e0),
      simde_mm_set_pi16(0x38f4, 0xbcda, 0x2cba, 0xacc3) },
    { simde_mm_set_pi16(0x918e, 0x1c4e, 0xe910, 0x1816),
      simde_mm_set_pi16(0x8630, 0x1e27, 0xe859, 0xdf6a),
      simde_mm_set_pi16(0x8bdf, 0x1d3b, 0xe8b5, 0x7bc0) },
    { simde_mm_set_pi16(0xbefa, 0xcb05, 0x36f0, 0xc0b6),
      simde_mm_set_pi16(0x4a77, 0xfd64, 0xfb05, 0x550c),
      simde_mm_set_pi16(0x84b9, 0xe435, 0x98fb, 0x8ae1) },
    { simde_mm_set_pi16(0xdc01, 0xa585, 0xa004, 0xe495),
      simde_mm_set_pi16(0x14aa, 0xc327, 0x8fc7, 0x2d75),
      simde_mm_set_pi16(0x7856, 0xb456, 0x97e6, 0x8905) },
    { simde_mm_set_pi16(0xd015, 0x5fa8, 0x45c6, 0x286b),
      simde_mm_set_pi16(0x83ee, 0x7908, 0x9036, 0x7427),
      simde_mm_set_pi16(0xaa02, 0x6c58, 0x6afe, 0x4e49) },
    { simde_mm_set_pi16(0x0f0a, 0xa363, 0x0d88, 0x3ab0),
      simde_mm_set_pi16(0xdfa0, 0x604c, 0x0f68, 0x1aef),
      simde_mm_set_pi16(0x7755, 0x81d8, 0x0e78, 0x2ad0) },
    { simde_mm_set_pi16(0x680e, 0x33e3, 0xd83f, 0x75d8),
      simde_mm_set_pi16(0x54bf, 0x1fa6, 0x50a9, 0xbf47),
      simde_mm_set_pi16(0x5e67, 0x29c5, 0x9474, 0x9a90) },
    { simde_mm_set_pi16(0xe38a, 0x410b, 0x96b6, 0xe13b),
      simde_mm_set_pi16(0xf64a, 0x4490, 0x4565, 0x742c),
      simde_mm_set_pi16(0xecea, 0x42ce, 0x6e0e, 0xaab4) },
    { simde_mm_set_pi16(0x9293, 0xd89a, 0x3823, 0x5d17),
      simde_mm_set_pi16(0x745a, 0xd347, 0xe5a1, 0x2926),
      simde_mm_set_pi16(0x8377, 0xd5f1, 0x8ee2, 0x431f) },
    { simde_mm_set_pi16(0xaeac, 0x7278, 0x2343, 0xcd26),
      simde_mm_set_pi16(0xc004, 0x65ab, 0x2d47, 0x7148),
      simde_mm_set_pi16(0xb758, 0x6c12, 0x2845, 0x9f37) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_mm_avg_pu16(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_avg_pu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[16] = {
    { simde_mm_set_pi8(0x91, 0xe1, 0x7e, 0x06, 0x12, 0x2f, 0xf1, 0x7f),
      simde_mm_set_pi8(0xd1, 0xfc, 0x30, 0x76, 0x81, 0xc7, 0x76, 0x03),
      simde_mm_set_pi8(0xb1, 0xef, 0x57, 0x3e, 0x4a, 0x7b, 0xb4, 0x41) },
    { simde_mm_set_pi8(0x28, 0xe2, 0xc6, 0x08, 0xc6, 0xf1, 0x56, 0x1f),
      simde_mm_set_pi8(0xe8, 0x95, 0x6e, 0x04, 0x09, 0x51, 0xd2, 0xb3),
      simde_mm_set_pi8(0x88, 0xbc, 0x9a, 0x06, 0x68, 0xa1, 0x94, 0x69) },
    { simde_mm_set_pi8(0xc0, 0xc2, 0x13, 0x4c, 0x22, 0x94, 0x45, 0x19),
      simde_mm_set_pi8(0x10, 0x0f, 0x38, 0xff, 0xa0, 0x9f, 0x10, 0xe4),
      simde_mm_set_pi8(0x68, 0x69, 0x26, 0xa6, 0x61, 0x9a, 0x2b, 0x7f) },
    { simde_mm_set_pi8(0x1e, 0x80, 0x8f, 0x2a, 0x75, 0x0c, 0xbe, 0xe8),
      simde_mm_set_pi8(0x8d, 0x95, 0x48, 0x12, 0x5d, 0xed, 0x02, 0xff),
      simde_mm_set_pi8(0x56, 0x8b, 0x6c, 0x1e, 0x69, 0x7d, 0x60, 0xf4) },
    { simde_mm_set_pi8(0xbd, 0x28, 0x85, 0x34, 0xe4, 0x5d, 0x36, 0xff),
      simde_mm_set_pi8(0x7f, 0xfe, 0x2a, 0xf8, 0xc0, 0x72, 0x81, 0xcf),
      simde_mm_set_pi8(0x9e, 0x93, 0x58, 0x96, 0xd2, 0x68, 0x5c, 0xe7) },
    { simde_mm_set_pi8(0x33, 0x41, 0x89, 0x25, 0xcd, 0x5d, 0xba, 0x64),
      simde_mm_set_pi8(0x25, 0xee, 0xc1, 0xdf, 0x79, 0x43, 0x6a, 0x26),
      simde_mm_set_pi8(0x2c, 0x98, 0xa5, 0x82, 0xa3, 0x50, 0x92, 0x45) },
    { simde_mm_set_pi8(0xf0, 0xd0, 0x63, 0x95, 0xd8, 0x9e, 0xdf, 0xc9),
      simde_mm_set_pi8(0x83, 0x4f, 0x74, 0x6b, 0x67, 0x46, 0x8d, 0x5f),
      simde_mm_set_pi8(0xba, 0x90, 0x6c, 0x80, 0xa0, 0x72, 0xb6, 0x94) },
    { simde_mm_set_pi8(0x88, 0xbf, 0x20, 0xd2, 0x99, 0x57, 0x5b, 0x7d),
      simde_mm_set_pi8(0x85, 0xce, 0x9f, 0xfc, 0xd5, 0xa1, 0xaf, 0xba),
      simde_mm_set_pi8(0x87, 0xc7, 0x60, 0xe7, 0xb7, 0x7c, 0x85, 0x9c) },
    { simde_mm_set_pi8(0x1d, 0x88, 0xc2, 0xc4, 0xcf, 0x95, 0x3c, 0x27),
      simde_mm_set_pi8(0x84, 0xd6, 0x51, 0xf3, 0x4d, 0x28, 0x78, 0x9e),
      simde_mm_set_pi8(0x51, 0xaf, 0x8a, 0xdc, 0x8e, 0x5f, 0x5a, 0x63) },
    { simde_mm_set_pi8(0x7f, 0x7e, 0x22, 0xe5, 0x13, 0x92, 0x9a, 0xfa),
      simde_mm_set_pi8(0x5b, 0xd1, 0xd0, 0x82, 0x0e, 0x8b, 0xcf, 0x12),
      simde_mm_set_pi8(0x6d, 0xa8, 0x79, 0xb4, 0x11, 0x8f, 0xb5, 0x86) },
    { simde_mm_set_pi8(0x98, 0x86, 0xf1, 0xd3, 0xbd, 0x99, 0x22, 0x5c),
      simde_mm_set_pi8(0x65, 0xb2, 0x34, 0x36, 0x68, 0x16, 0xbe, 0xf9),
      simde_mm_set_pi8(0x7f, 0x9c, 0x93, 0x85, 0x93, 0x58, 0x70, 0xab) },
    { simde_mm_set_pi8(0xb2, 0x3b, 0x6f, 0xf0, 0x4a, 0xd1, 0x08, 0xd4),
      simde_mm_set_pi8(0x53, 0xe9, 0x83, 0xf8, 0xeb, 0x24, 0xf5, 0xd7),
      simde_mm_set_pi8(0x83, 0x92, 0x79, 0xf4, 0x9b, 0x7b, 0x7f, 0xd6) },
    { simde_mm_set_pi8(0x83, 0x6a, 0x3b, 0x8e, 0x5a, 0xf6, 0x9c, 0xc5),
      simde_mm_set_pi8(0x1c, 0xa3, 0xe7, 0x5b, 0x87, 0xa5, 0x06, 0x06),
      simde_mm_set_pi8(0x50, 0x87, 0x91, 0x75, 0x71, 0xce, 0x51, 0x66) },
    { simde_mm_set_pi8(0x5c, 0x3a, 0xa5, 0x0f, 0x3f, 0x23, 0x6a, 0x18),
      simde_mm_set_pi8(0x1a, 0xe4, 0xee, 0xf4, 0xec, 0xbc, 0xc9, 0x4e),
      simde_mm_set_pi8(0x3b, 0x8f, 0xca, 0x82, 0x96, 0x70, 0x9a, 0x33) },
    { simde_mm_set_pi8(0xa3, 0x77, 0x5c, 0x7e, 0x51, 0x77, 0xf1, 0xf4),
      simde_mm_set_pi8(0x2d, 0x3c, 0xd3, 0xbc, 0x5e, 0x32, 0xa6, 0x64),
      simde_mm_set_pi8(0x68, 0x5a, 0x98, 0x9d, 0x58, 0x55, 0xcc, 0xac) },
    { simde_mm_set_pi8(0x92, 0xb8, 0xc8, 0xb8, 0x4d, 0x82, 0xc4, 0xff),
      simde_mm_set_pi8(0xf7, 0x65, 0xea, 0xb9, 0x1d, 0x6f, 0xf1, 0x53),
      simde_mm_set_pi8(0xc5, 0x8f, 0xd9, 0xb9, 0x35, 0x79, 0xdb, 0xa9) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_mm_avg_pu8(test_vec[i].a, test_vec[i].b);
    simde_mm_empty();
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpeq_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[] = {
    { simde_m128_set_u32(0x99351ff1, 0xd60b73a1, 0x380164ff, 0xa875e41c),
      simde_m128_set_u32(0x849b2cd8, 0xd60b73a1, 0x344cab6a, 0x3533e9b1),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0x75dcf69b, 0x5cb10389, 0x9534c7de, 0x19281c86),
      simde_m128_set_u32(0xac5952e9, 0x5cb10389, 0xd2a0dd17, 0x19281c86),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0x00000000, 0xffffffff) },
    { simde_m128_set_u32(0x8165a0c1, 0xecc73f45, 0x63a3a3f8, 0x16f44857),
      simde_m128_set_u32(0xcce343c7, 0x969c8f11, 0x63a3a3f8, 0x16f44857),
      simde_m128_set_u32(0x00000000, 0x00000000, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0xb3f30e98, 0xb5008858, 0xc8e5ce07, 0x78516c88),
      simde_m128_set_u32(0xb3f30e98, 0xc5f3f771, 0x35d5330d, 0xa553135e),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0x8528f502, 0x8719d017, 0x19382c92, 0xfa0604a4),
      simde_m128_set_u32(0x8528f502, 0x8719d017, 0xb1528279, 0x9868ca04),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0x237b4546, 0x176f5879, 0x80f07dd4, 0xb69f6612),
      simde_m128_set_u32(0x6388cc76, 0x6ca06981, 0x80f07dd4, 0xf7771283),
      simde_m128_set_u32(0x00000000, 0x00000000, 0xffffffff, 0x00000000) },
    { simde_m128_set_u32(0x472b0da5, 0xed194d39, 0xda07c592, 0x9d654dfd),
      simde_m128_set_u32(0x018747e7, 0xed194d39, 0xda07c592, 0x9d654dfd),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0x1dbfc43d, 0x25c37ea9, 0x19dfdf64, 0xdcbfeed8),
      simde_m128_set_u32(0x1dbfc43d, 0x870dbac2, 0xef8667e0, 0x12c7dd6b),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0x00000000, 0x00000000) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpeq_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpeq_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0xa6574d82, 0xb94bcf37, 0xeccddc73, 0x79167856),
      simde_m128_set_u32(0xa6574d82, 0xb94bcf37, 0xeccddc73, 0x79167856),
      simde_m128_set_u32(0xa6574d82, 0xb94bcf37, 0xeccddc73, 0xffffffff) },
    { simde_m128_set_u32(0x8c4fe762, 0x809c6312, 0x3bde6a2a, 0x5ea93f55),
      simde_m128_set_u32(0x8c4fe762, 0xa482a63c, 0x3bde6a2a, 0xf6bb01d9),
      simde_m128_set_u32(0x8c4fe762, 0x809c6312, 0x3bde6a2a, 0x00000000) },
    { simde_m128_set_u32(0xc156c184, 0x9ac0fe6c, 0xd43c7f87, 0x58d72804),
      simde_m128_set_u32(0x638bab80, 0x97ec01aa, 0x9d960580, 0x06ec884c),
      simde_m128_set_u32(0xc156c184, 0x9ac0fe6c, 0xd43c7f87, 0x00000000) },
    { simde_m128_set_u32(0x40ef8c7a, 0x93efc1d7, 0x96c26a81, 0x3d6b2392),
      simde_m128_set_u32(0xf3b08306, 0x44190fb2, 0x12f378a0, 0x0a65d958),
      simde_m128_set_u32(0x40ef8c7a, 0x93efc1d7, 0x96c26a81, 0x00000000) },
    { simde_m128_set_u32(0xf90747a7, 0x3efc6757, 0x860c4199, 0x488e3a33),
      simde_m128_set_u32(0xb4c85a6e, 0xe52343d6, 0xbf373304, 0x54b5455a),
      simde_m128_set_u32(0xf90747a7, 0x3efc6757, 0x860c4199, 0x00000000) },
    { simde_m128_set_u32(0x4ea89aaf, 0xa1c773f9, 0xa942ca51, 0x2b3ebc24),
      simde_m128_set_u32(0x4ea89aaf, 0xa1c773f9, 0x9ebf77fb, 0xa70bb6f5),
      simde_m128_set_u32(0x4ea89aaf, 0xa1c773f9, 0xa942ca51, 0x00000000) },
    { simde_m128_set_u32(0x22b5a2bd, 0x1b011210, 0x11ae70f0, 0x9a4ac327),
      simde_m128_set_u32(0x22b5a2bd, 0x440b1887, 0x941fb87d, 0x9a4ac327),
      simde_m128_set_u32(0x22b5a2bd, 0x1b011210, 0x11ae70f0, 0xffffffff) },
    { simde_m128_set_u32(0xda532220, 0xd0157b6d, 0xf4a01ee7, 0xb338a46c),
      simde_m128_set_u32(0xda532220, 0xa23036f3, 0xf4a01ee7, 0x4919d016),
      simde_m128_set_u32(0xda532220, 0xd0157b6d, 0xf4a01ee7, 0x00000000) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpeq_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpge_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x686b5a31, 0x7e5dec47, 0x252dc72f, 0xe906fece),
      simde_m128_set_u32(0xf07ececb, 0x8c9f15e8, 0xe57594c1, 0x0737a686),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000) },
    { simde_m128_set_u32(0xac2caa66, 0x4a97874c, 0xb332fd1a, 0xbee510e7),
      simde_m128_set_u32(0x6f4be0ee, 0xb381023b, 0x55bcdb39, 0x2e5a67ff),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0x45c20fbb, 0xc95ff3e6, 0x07b81248, 0x015d1799),
      simde_m128_set_u32(0x77643221, 0xb7523ebc, 0x96db7d37, 0xa6904be4),
      simde_m128_set_u32(0x00000000, 0x00000000, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0x633c6e5d, 0x86ea72f1, 0xd626c2b9, 0x67090981),
      simde_m128_set_u32(0xc0129bce, 0x25a836c2, 0xdbacfd8c, 0xda6383fb),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0x5bd66181, 0x93f75626, 0xb2edc3c9, 0x018073ec),
      simde_m128_set_u32(0x8d8d3a03, 0x6e586ad6, 0xd20e18ec, 0xef868d2e),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0xc5899227, 0x822bbafe, 0x06bd34a5, 0xd15b0981),
      simde_m128_set_u32(0x21889ff5, 0x60b65831, 0xc46d3d04, 0x282ab806),
      simde_m128_set_u32(0x00000000, 0x00000000, 0xffffffff, 0x00000000) },
    { simde_m128_set_u32(0x70d0f6f8, 0x1bf3ca73, 0x7bffd263, 0x77c18a78),
      simde_m128_set_u32(0xbd2d859e, 0xdf8cbbca, 0x6be263f5, 0xcb27810d),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0x58ef0e30, 0x9f27dcda, 0xbafc47e8, 0xb37f729c),
      simde_m128_set_u32(0x849e6b65, 0x10b4e6d9, 0x1c9550d5, 0xce96597f),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0x00000000, 0xffffffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpge_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpge_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  SIMDE_SKIP_PGI("http://www.pgroup.com/userforum/viewtopic.php?t=5578");

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x686b5a31, 0x7e5dec47, 0x252dc72f, 0xe906fece),
      simde_m128_set_u32(0xf07ececb, 0x8c9f15e8, 0xe57594c1, 0x0737a686),
      simde_m128_set_u32(0x686b5a31, 0x7e5dec47, 0x252dc72f, 0x00000000) },
    { simde_m128_set_u32(0xac2caa66, 0x4a97874c, 0xb332fd1a, 0xbee510e7),
      simde_m128_set_u32(0x6f4be0ee, 0xb381023b, 0x55bcdb39, 0x2e5a67ff),
      simde_m128_set_u32(0xac2caa66, 0x4a97874c, 0xb332fd1a, 0x00000000) },
    { simde_m128_set_u32(0x45c20fbb, 0xc95ff3e6, 0x07b81248, 0x015d1799),
      simde_m128_set_u32(0x77643221, 0xb7523ebc, 0x96db7d37, 0xa6904be4),
      simde_m128_set_u32(0x45c20fbb, 0xc95ff3e6, 0x07b81248, 0xffffffff) },
    { simde_m128_set_u32(0x633c6e5d, 0x86ea72f1, 0xd626c2b9, 0x67090981),
      simde_m128_set_u32(0xc0129bce, 0x25a836c2, 0xdbacfd8c, 0xda6383fb),
      simde_m128_set_u32(0x633c6e5d, 0x86ea72f1, 0xd626c2b9, 0xffffffff) },
    { simde_m128_set_u32(0x5bd66181, 0x93f75626, 0xb2edc3c9, 0x018073ec),
      simde_m128_set_u32(0x8d8d3a03, 0x6e586ad6, 0xd20e18ec, 0xef868d2e),
      simde_m128_set_u32(0x5bd66181, 0x93f75626, 0xb2edc3c9, 0xffffffff) },
    { simde_m128_set_u32(0xc5899227, 0x822bbafe, 0x06bd34a5, 0xd15b0981),
      simde_m128_set_u32(0x21889ff5, 0x60b65831, 0xc46d3d04, 0x282ab806),
      simde_m128_set_u32(0xc5899227, 0x822bbafe, 0x06bd34a5, 0x00000000) },
    { simde_m128_set_u32(0x70d0f6f8, 0x1bf3ca73, 0x7bffd263, 0x77c18a78),
      simde_m128_set_u32(0xbd2d859e, 0xdf8cbbca, 0x6be263f5, 0xcb27810d),
      simde_m128_set_u32(0x70d0f6f8, 0x1bf3ca73, 0x7bffd263, 0xffffffff) },
    { simde_m128_set_u32(0x58ef0e30, 0x9f27dcda, 0xbafc47e8, 0xb37f729c),
      simde_m128_set_u32(0x58ef0e30, 0x9f27dcda, 0xbafc47e8, 0xb37f729c),
      simde_m128_set_u32(0x58ef0e30, 0x9f27dcda, 0xbafc47e8, 0xffffffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpge_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpgt_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x774a8b87, 0x1e69026d, 0x697ab3e1, 0x310eea14),
      simde_m128_set_u32(0x8b361f8a, 0xbff5cef6, 0x2097f294, 0x90eff61d),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0xf6e52813, 0x439d4b0a, 0x6bf364cb, 0xddd80909),
      simde_m128_set_u32(0x655d0c81, 0x14171abf, 0x10419e37, 0x0bd60b16),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0xffffffff, 0x00000000) },
    { simde_m128_set_u32(0x50ca6c2b, 0xfb293bab, 0x50e95c26, 0x208d1127),
      simde_m128_set_u32(0x00558133, 0xba954b0a, 0xe6a5c37e, 0xe89613a0),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0xf2680651, 0x4d652b55, 0xabd58f7e, 0x2c707a02),
      simde_m128_set_u32(0xf8bd655e, 0xe9c6fce9, 0xb3139090, 0xfea80285),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0xc1a92d21, 0x6ed312ce, 0x625e6f3d, 0x4955bf1f),
      simde_m128_set_u32(0x65333d29, 0xe175dbdf, 0x583c38cc, 0xa5d6ea79),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0xdb3d120a, 0x5a03e9bc, 0x1a3709b8, 0x234c95f3),
      simde_m128_set_u32(0x773f072d, 0x926c51d4, 0xaa57f531, 0x3bbc40cd),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0xffffffff, 0x00000000) },
    { simde_m128_set_u32(0xa34419fa, 0x6cdefdf7, 0x54811f1e, 0x6af8c730),
      simde_m128_set_u32(0x6fc7a0fb, 0x950b0fea, 0xe817a199, 0x6c75fcc0),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0xffffffff, 0x00000000) },
    { simde_m128_set_u32(0xb462d675, 0xadebf6d0, 0x6ed0371d, 0x337e50b5),
      simde_m128_set_u32(0xb462d675, 0xadebf6d0, 0x6ed0371d, 0x337e50b5),
      simde_m128_set_u32(0x00000000, 0x00000000, 0x00000000, 0x00000000) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpgt_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpgt_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  SIMDE_SKIP_PGI("http://www.pgroup.com/userforum/viewtopic.php?t=5578");

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x774a8b87, 0x1e69026d, 0x697ab3e1, 0x310eea14),
      simde_m128_set_u32(0x8b361f8a, 0xbff5cef6, 0x2097f294, 0x90eff61d),
      simde_m128_set_u32(0x774a8b87, 0x1e69026d, 0x697ab3e1, 0xffffffff) },
    { simde_m128_set_u32(0xf6e52813, 0x439d4b0a, 0x6bf364cb, 0xddd80909),
      simde_m128_set_u32(0x655d0c81, 0x14171abf, 0x10419e37, 0x0bd60b16),
      simde_m128_set_u32(0xf6e52813, 0x439d4b0a, 0x6bf364cb, 0x00000000) },
    { simde_m128_set_u32(0x50ca6c2b, 0xfb293bab, 0x50e95c26, 0x208d1127),
      simde_m128_set_u32(0x00558133, 0xba954b0a, 0xe6a5c37e, 0xe89613a0),
      simde_m128_set_u32(0x50ca6c2b, 0xfb293bab, 0x50e95c26, 0xffffffff) },
    { simde_m128_set_u32(0xf2680651, 0x4d652b55, 0xabd58f7e, 0x2c707a02),
      simde_m128_set_u32(0xf8bd655e, 0xe9c6fce9, 0xb3139090, 0xfea80285),
      simde_m128_set_u32(0xf2680651, 0x4d652b55, 0xabd58f7e, 0xffffffff) },
    { simde_m128_set_u32(0xc1a92d21, 0x6ed312ce, 0x625e6f3d, 0x4955bf1f),
      simde_m128_set_u32(0x65333d29, 0xe175dbdf, 0x583c38cc, 0xa5d6ea79),
      simde_m128_set_u32(0xc1a92d21, 0x6ed312ce, 0x625e6f3d, 0xffffffff) },
    { simde_m128_set_u32(0xdb3d120a, 0x5a03e9bc, 0x1a3709b8, 0x234c95f3),
      simde_m128_set_u32(0x773f072d, 0x926c51d4, 0xaa57f531, 0x3bbc40cd),
      simde_m128_set_u32(0xdb3d120a, 0x5a03e9bc, 0x1a3709b8, 0x00000000) },
    { simde_m128_set_u32(0xa34419fa, 0x6cdefdf7, 0x54811f1e, 0x6af8c730),
      simde_m128_set_u32(0x6fc7a0fb, 0x950b0fea, 0xe817a199, 0x6c75fcc0),
      simde_m128_set_u32(0xa34419fa, 0x6cdefdf7, 0x54811f1e, 0x00000000) },
    { simde_m128_set_u32(0xb462d675, 0xadebf6d0, 0x6ed0371d, 0x337e50b5),
      simde_m128_set_u32(0x3148f72a, 0x33bf7eb9, 0x8b97a9b8, 0x337e50b5),
      simde_m128_set_u32(0xb462d675, 0xadebf6d0, 0x6ed0371d, 0x00000000) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpgt_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmple_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x05eee78f, 0xf457654b, 0xaba21f16, 0xcb4e660f),
      simde_m128_set_u32(0xf4ed0396, 0x18710b1a, 0x121dcbb7, 0x9c7c8737),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0x940744e9, 0xc520c647, 0xf726849a, 0xc5596de3),
      simde_m128_set_u32(0x2065f0fc, 0x91c225d3, 0x88423691, 0x5d1b4dd7),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0x228c6438, 0x5d9b72c3, 0x2a7ead94, 0x574cfeea),
      simde_m128_set_u32(0x45b57810, 0xfb083776, 0x21599748, 0xbac1cc07),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0x98099d44, 0xd152d304, 0xe5935a20, 0x1a04455f),
      simde_m128_set_u32(0xef3ea15c, 0x3a1f3142, 0x5f8fa8a4, 0x9c3b1fc8),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0xffffffff, 0x00000000) },
    { simde_m128_set_u32(0xdcff8341, 0xac35cecf, 0x63d5943d, 0xba54309b),
      simde_m128_set_u32(0x66f6b7e2, 0x9ee34d7b, 0x06dcf743, 0x7eb62040),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0x00000000, 0xffffffff) },
    { simde_m128_set_u32(0xe0005ed1, 0xf79d4587, 0x7109dac7, 0x19b86ada),
      simde_m128_set_u32(0x30240b7c, 0xe3d0325a, 0xd2e4ecfc, 0xefb95ccb),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0xed720175, 0xe4c0953f, 0x123485c4, 0x5b9af61a),
      simde_m128_set_u32(0x3dac472f, 0x10b3a869, 0xafb85bf8, 0xb91f4387),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0xafd15ec8, 0xad7325c3, 0xacaff96f, 0x863a0830),
      simde_m128_set_u32(0xafd15ec8, 0xad7325c3, 0xacaff96f, 0x863a0830),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmple_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmple_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x05eee78f, 0xf457654b, 0xaba21f16, 0xcb4e660f),
      simde_m128_set_u32(0xf4ed0396, 0x18710b1a, 0x121dcbb7, 0x9c7c8737),
      simde_m128_set_u32(0x05eee78f, 0xf457654b, 0xaba21f16, 0xffffffff) },
    { simde_m128_set_u32(0x940744e9, 0xc520c647, 0xf726849a, 0xc5596de3),
      simde_m128_set_u32(0x2065f0fc, 0x91c225d3, 0x88423691, 0x5d1b4dd7),
      simde_m128_set_u32(0x940744e9, 0xc520c647, 0xf726849a, 0xffffffff) },
    { simde_m128_set_u32(0x228c6438, 0x5d9b72c3, 0x2a7ead94, 0x574cfeea),
      simde_m128_set_u32(0x45b57810, 0xfb083776, 0x21599748, 0xbac1cc07),
      simde_m128_set_u32(0x228c6438, 0x5d9b72c3, 0x2a7ead94, 0x00000000) },
    { simde_m128_set_u32(0x98099d44, 0xd152d304, 0xe5935a20, 0x1a04455f),
      simde_m128_set_u32(0xef3ea15c, 0x3a1f3142, 0x5f8fa8a4, 0x9c3b1fc8),
      simde_m128_set_u32(0x98099d44, 0xd152d304, 0xe5935a20, 0x00000000) },
    { simde_m128_set_u32(0xdcff8341, 0xac35cecf, 0x63d5943d, 0xba54309b),
      simde_m128_set_u32(0x66f6b7e2, 0x9ee34d7b, 0x06dcf743, 0x7eb62040),
      simde_m128_set_u32(0xdcff8341, 0xac35cecf, 0x63d5943d, 0xffffffff) },
    { simde_m128_set_u32(0xe0005ed1, 0xf79d4587, 0x7109dac7, 0x19b86ada),
      simde_m128_set_u32(0x30240b7c, 0xe3d0325a, 0xd2e4ecfc, 0xefb95ccb),
      simde_m128_set_u32(0xe0005ed1, 0xf79d4587, 0x7109dac7, 0x00000000) },
    { simde_m128_set_u32(0xed720175, 0xe4c0953f, 0x123485c4, 0x5b9af61a),
      simde_m128_set_u32(0x3dac472f, 0x10b3a869, 0xafb85bf8, 0xb91f4387),
      simde_m128_set_u32(0xed720175, 0xe4c0953f, 0x123485c4, 0x00000000) },
    { simde_m128_set_u32(0xafd15ec8, 0xad7325c3, 0xacaff96f, 0x863a0830),
      simde_m128_set_u32(0x553218f8, 0xff206954, 0x27ca47bd, 0x863a0830),
      simde_m128_set_u32(0xafd15ec8, 0xad7325c3, 0xacaff96f, 0xffffffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmple_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmplt_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x05eee78f, 0xf457654b, 0xaba21f16, 0xcb4e660f),
      simde_m128_set_u32(0xf4ed0396, 0x18710b1a, 0x121dcbb7, 0x9c7c8737),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0x940744e9, 0xc520c647, 0xf726849a, 0xc5596de3),
      simde_m128_set_u32(0x2065f0fc, 0x91c225d3, 0x88423691, 0x5d1b4dd7),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0x228c6438, 0x5d9b72c3, 0x2a7ead94, 0x574cfeea),
      simde_m128_set_u32(0x45b57810, 0xfb083776, 0x21599748, 0xbac1cc07),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0x98099d44, 0xd152d304, 0xe5935a20, 0x1a04455f),
      simde_m128_set_u32(0xef3ea15c, 0x3a1f3142, 0x5f8fa8a4, 0x9c3b1fc8),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0xffffffff, 0x00000000) },
    { simde_m128_set_u32(0xdcff8341, 0xac35cecf, 0x63d5943d, 0xba54309b),
      simde_m128_set_u32(0x66f6b7e2, 0x9ee34d7b, 0x06dcf743, 0x7eb62040),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0x00000000, 0xffffffff) },
    { simde_m128_set_u32(0xe0005ed1, 0xf79d4587, 0x7109dac7, 0x19b86ada),
      simde_m128_set_u32(0x30240b7c, 0xe3d0325a, 0xd2e4ecfc, 0xefb95ccb),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0xed720175, 0xe4c0953f, 0x123485c4, 0x5b9af61a),
      simde_m128_set_u32(0x3dac472f, 0x10b3a869, 0xafb85bf8, 0xb91f4387),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0xafd15ec8, 0xad7325c3, 0xacaff96f, 0x863a0830),
      simde_m128_set_u32(0xafd15ec8, 0xad7325c3, 0xacaff96f, 0x863a0830),
      simde_m128_set_u32(0x00000000, 0x00000000, 0x00000000, 0x00000000) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmplt_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmplt_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x05eee78f, 0xf457654b, 0xaba21f16, 0xcb4e660f),
      simde_m128_set_u32(0xf4ed0396, 0x18710b1a, 0x121dcbb7, 0x9c7c8737),
      simde_m128_set_u32(0x05eee78f, 0xf457654b, 0xaba21f16, 0xffffffff) },
    { simde_m128_set_u32(0x940744e9, 0xc520c647, 0xf726849a, 0xc5596de3),
      simde_m128_set_u32(0x2065f0fc, 0x91c225d3, 0x88423691, 0x5d1b4dd7),
      simde_m128_set_u32(0x940744e9, 0xc520c647, 0xf726849a, 0xffffffff) },
    { simde_m128_set_u32(0x228c6438, 0x5d9b72c3, 0x2a7ead94, 0x574cfeea),
      simde_m128_set_u32(0x45b57810, 0xfb083776, 0x21599748, 0xbac1cc07),
      simde_m128_set_u32(0x228c6438, 0x5d9b72c3, 0x2a7ead94, 0x00000000) },
    { simde_m128_set_u32(0x98099d44, 0xd152d304, 0xe5935a20, 0x1a04455f),
      simde_m128_set_u32(0xef3ea15c, 0x3a1f3142, 0x5f8fa8a4, 0x9c3b1fc8),
      simde_m128_set_u32(0x98099d44, 0xd152d304, 0xe5935a20, 0x00000000) },
    { simde_m128_set_u32(0xdcff8341, 0xac35cecf, 0x63d5943d, 0xba54309b),
      simde_m128_set_u32(0x66f6b7e2, 0x9ee34d7b, 0x06dcf743, 0x7eb62040),
      simde_m128_set_u32(0xdcff8341, 0xac35cecf, 0x63d5943d, 0xffffffff) },
    { simde_m128_set_u32(0xe0005ed1, 0xf79d4587, 0x7109dac7, 0x19b86ada),
      simde_m128_set_u32(0x30240b7c, 0xe3d0325a, 0xd2e4ecfc, 0xefb95ccb),
      simde_m128_set_u32(0xe0005ed1, 0xf79d4587, 0x7109dac7, 0x00000000) },
    { simde_m128_set_u32(0xed720175, 0xe4c0953f, 0x123485c4, 0x5b9af61a),
      simde_m128_set_u32(0x3dac472f, 0x10b3a869, 0xafb85bf8, 0xb91f4387),
      simde_m128_set_u32(0xed720175, 0xe4c0953f, 0x123485c4, 0x00000000) },
    { simde_m128_set_u32(0xafd15ec8, 0xad7325c3, 0xacaff96f, 0x863a0830),
      simde_m128_set_u32(0x553218f8, 0xff206954, 0x27ca47bd, 0x863a0830),
      simde_m128_set_u32(0xafd15ec8, 0xad7325c3, 0xacaff96f, 0x00000000) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmplt_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpneq_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x1d555bc7, 0x407f90f7, 0xf771b18b, 0xcddee635),
      simde_m128_set_u32(0x084bb494, 0xc04179dd, 0xf771b18b, 0x3a120310),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0x00000000, 0xffffffff) },
    { simde_m128_set_u32(0xf48121e9, 0xed332aa6, 0x9cf8ce4b, 0xe7f9b14a),
      simde_m128_set_u32(0x6ffb0549, 0xd9aa2b79, 0x8523bb1a, 0x780de619),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0xf196a725, 0x92ab759f, 0xb3da5fbb, 0x61c73a5b),
      simde_m128_set_u32(0xf196a725, 0x9d3ee300, 0xb3da5fbb, 0x6c20b1d4),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0x00000000, 0xffffffff) },
    { simde_m128_set_u32(0x645697b7, 0x22b63d27, 0x88167ad7, 0x91f5577f),
      simde_m128_set_u32(0x5cc48f77, 0x22a17d87, 0xbb3783ad, 0xe4dca5a1),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0xfa425aa7, 0xfd4fa1ae, 0x5207f8e4, 0x900fa5b7),
      simde_m128_set_u32(0xf212c716, 0xa3594351, 0x5207f8e4, 0x900fa5b7),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0x915b9da1, 0x2855b963, 0xb759c9a3, 0x00ef0349),
      simde_m128_set_u32(0xdcc7a3b8, 0x2855b963, 0x965457b7, 0xb6c1f47f),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0xd49dc5d7, 0x8a346fa1, 0x07e5ff13, 0x83e16e3f),
      simde_m128_set_u32(0x2d6a5648, 0x2a13528b, 0xc8fbfeaf, 0x9fe04a3f),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0x88781e0e, 0xfc83f902, 0x3e2f8a03, 0xec93d8a0),
      simde_m128_set_u32(0x88781e0e, 0x93f2b487, 0xfb3617e6, 0xf6aa75b7),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0xffffffff, 0xffffffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpneq_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpneq_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x1d555bc7, 0x407f90f7, 0xf771b18b, 0xcddee635),
      simde_m128_set_u32(0x084bb494, 0xc04179dd, 0xf771b18b, 0x3a120310),
      simde_m128_set_u32(0x1d555bc7, 0x407f90f7, 0xf771b18b, 0xffffffff) },
    { simde_m128_set_u32(0xf48121e9, 0xed332aa6, 0x9cf8ce4b, 0xe7f9b14a),
      simde_m128_set_u32(0x6ffb0549, 0xd9aa2b79, 0x8523bb1a, 0x780de619),
      simde_m128_set_u32(0xf48121e9, 0xed332aa6, 0x9cf8ce4b, 0xffffffff) },
    { simde_m128_set_u32(0xf196a725, 0x92ab759f, 0xb3da5fbb, 0x61c73a5b),
      simde_m128_set_u32(0xf196a725, 0x9d3ee300, 0xb3da5fbb, 0x6c20b1d4),
      simde_m128_set_u32(0xf196a725, 0x92ab759f, 0xb3da5fbb, 0xffffffff) },
    { simde_m128_set_u32(0x645697b7, 0x22b63d27, 0x88167ad7, 0x91f5577f),
      simde_m128_set_u32(0x5cc48f77, 0x22a17d87, 0xbb3783ad, 0xe4dca5a1),
      simde_m128_set_u32(0x645697b7, 0x22b63d27, 0x88167ad7, 0xffffffff) },
    { simde_m128_set_u32(0xfa425aa7, 0xfd4fa1ae, 0x5207f8e4, 0x900fa5b7),
      simde_m128_set_u32(0xf212c716, 0xa3594351, 0x5207f8e4, 0x900fa5b7),
      simde_m128_set_u32(0xfa425aa7, 0xfd4fa1ae, 0x5207f8e4, 0x00000000) },
    { simde_m128_set_u32(0x915b9da1, 0x2855b963, 0xb759c9a3, 0x00ef0349),
      simde_m128_set_u32(0xdcc7a3b8, 0x2855b963, 0x965457b7, 0xb6c1f47f),
      simde_m128_set_u32(0x915b9da1, 0x2855b963, 0xb759c9a3, 0xffffffff) },
    { simde_m128_set_u32(0xd49dc5d7, 0x8a346fa1, 0x07e5ff13, 0x83e16e3f),
      simde_m128_set_u32(0x2d6a5648, 0x2a13528b, 0xc8fbfeaf, 0x9fe04a3f),
      simde_m128_set_u32(0xd49dc5d7, 0x8a346fa1, 0x07e5ff13, 0xffffffff) },
    { simde_m128_set_u32(0x88781e0e, 0xfc83f902, 0x3e2f8a03, 0xec93d8a0),
      simde_m128_set_u32(0x88781e0e, 0x93f2b487, 0xfb3617e6, 0xf6aa75b7),
      simde_m128_set_u32(0x88781e0e, 0xfc83f902, 0x3e2f8a03, 0xffffffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpneq_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpnge_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0xb9aa0550, 0xe5fe268a, 0x956557e2, 0x5bae1b7a),
      simde_m128_set_u32(0xb9aa0550, 0x0a85c1d6, 0x956557e2, 0x7c4c89eb),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0x00000000, 0xffffffff) },
    { simde_m128_set_u32(0x274c2af7, 0x9fdb94ef, 0x307d27d4, 0x9de8ddbb),
      simde_m128_set_u32(0x6fe2efd0, 0x9fdb94ef, 0xa8a7fc71, 0x9de8ddbb),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0xa004a62d, 0x59046fee, 0x569c67ce, 0x8d8a7a6a),
      simde_m128_set_u32(0x8dbd08d5, 0x3cbdee02, 0x569c67ce, 0x8d8a7a6a),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0xe70d332d, 0x00988f8f, 0x04fd7ecc, 0x4f78ada2),
      simde_m128_set_u32(0xe70d332d, 0xf28e73b6, 0x04fd7ecc, 0x4f78ada2),
      simde_m128_set_u32(0x00000000, 0x00000000, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0x4f2b8528, 0x742ab38a, 0x726966f2, 0xfedb4a2d),
      simde_m128_set_u32(0x4f2b8528, 0x03b09e55, 0x726966f2, 0xd9fa52f2),
      simde_m128_set_u32(0x00000000, 0x00000000, 0x00000000, 0xffffffff) },
    { simde_m128_set_u32(0xa98bae5d, 0xde94fee2, 0x4f83ee32, 0xb166d3c3),
      simde_m128_set_u32(0xa98bae5d, 0xde94fee2, 0x4f83ee32, 0xb166d3c3),
      simde_m128_set_u32(0x00000000, 0x00000000, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0x63d7e483, 0x4fc41129, 0x3169c30c, 0xa910ee43),
      simde_m128_set_u32(0x63d7e483, 0xbd863018, 0x9b379fdb, 0xa910ee43),
      simde_m128_set_u32(0x00000000, 0x00000000, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0xa000cf4c, 0x51d0a160, 0xb914affd, 0x06ebf67b),
      simde_m128_set_u32(0x65dd62f7, 0x51d0a160, 0xb914affd, 0x06ebf67b),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0x00000000, 0x00000000) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpnge_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpnge_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  SIMDE_SKIP_PGI("http://www.pgroup.com/userforum/viewtopic.php?t=5578");

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0xb9aa0550, 0xe5fe268a, 0x956557e2, 0x5bae1b7a),
      simde_m128_set_u32(0xb9aa0550, 0x0a85c1d6, 0x956557e2, 0x7c4c89eb),
      simde_m128_set_u32(0xb9aa0550, 0xe5fe268a, 0x956557e2, 0xffffffff) },
    { simde_m128_set_u32(0x274c2af7, 0x9fdb94ef, 0x307d27d4, 0x9de8ddbb),
      simde_m128_set_u32(0x6fe2efd0, 0x9fdb94ef, 0xa8a7fc71, 0x9de8ddbb),
      simde_m128_set_u32(0x274c2af7, 0x9fdb94ef, 0x307d27d4, 0x00000000) },
    { simde_m128_set_u32(0xa004a62d, 0x59046fee, 0x569c67ce, 0x8d8a7a6a),
      simde_m128_set_u32(0x8dbd08d5, 0x3cbdee02, 0x569c67ce, 0x8d8a7a6a),
      simde_m128_set_u32(0xa004a62d, 0x59046fee, 0x569c67ce, 0x00000000) },
    { simde_m128_set_u32(0xe70d332d, 0x00988f8f, 0x04fd7ecc, 0x4f78ada2),
      simde_m128_set_u32(0xe70d332d, 0xf28e73b6, 0x04fd7ecc, 0x4f78ada2),
      simde_m128_set_u32(0xe70d332d, 0x00988f8f, 0x04fd7ecc, 0x00000000) },
    { simde_m128_set_u32(0x4f2b8528, 0x742ab38a, 0x726966f2, 0xfedb4a2d),
      simde_m128_set_u32(0x4f2b8528, 0x03b09e55, 0x726966f2, 0xd9fa52f2),
      simde_m128_set_u32(0x4f2b8528, 0x742ab38a, 0x726966f2, 0xffffffff) },
    { simde_m128_set_u32(0xa98bae5d, 0xde94fee2, 0x4f83ee32, 0xb166d3c3),
      simde_m128_set_u32(0xa98bae5d, 0xde94fee2, 0x4f83ee32, 0xb166d3c3),
      simde_m128_set_u32(0xa98bae5d, 0xde94fee2, 0x4f83ee32, 0x00000000) },
    { simde_m128_set_u32(0x63d7e483, 0x4fc41129, 0x3169c30c, 0xa910ee43),
      simde_m128_set_u32(0x63d7e483, 0xbd863018, 0x9b379fdb, 0xa910ee43),
      simde_m128_set_u32(0x63d7e483, 0x4fc41129, 0x3169c30c, 0x00000000) },
    { simde_m128_set_u32(0xa000cf4c, 0x51d0a160, 0xb914affd, 0x06ebf67b),
      simde_m128_set_u32(0x65dd62f7, 0x51d0a160, 0xb914affd, 0x06ebf67b),
      simde_m128_set_u32(0xa000cf4c, 0x51d0a160, 0xb914affd, 0x00000000) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpnge_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpngt_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x7bf7f424, 0x75ba04c4, 0x29a17063, 0x6a458ad5),
      simde_m128_set_u32(0x104cc8e1, 0x75ba04c4, 0x1671c275, 0x909980a7),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0x1ed1d1a7, 0xacadaad7, 0xe5e02b73, 0x0d531e5b),
      simde_m128_set_u32(0x1ed1d1a7, 0xacadaad7, 0x63d7fed1, 0x0d531e5b),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0x0e9738e2, 0xcc511daa, 0xd6fb923c, 0xf7bcb00a),
      simde_m128_set_u32(0x0e9738e2, 0xcc511daa, 0xd6fb923c, 0xeccdb0b5),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0xeccba5e2, 0x57b5b3e9, 0xbad371f6, 0xae22ee04),
      simde_m128_set_u32(0xde991633, 0x57b5b3e9, 0x1bec3de9, 0x497a9b3f),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0x6593fed2, 0xe31e7445, 0x6f9cf8ce, 0x81bab478),
      simde_m128_set_u32(0x6593fed2, 0x56ab0a96, 0x117b9afb, 0xfe4a2278),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0x64452194, 0x75de7d1e, 0x26b72384, 0x58c83885),
      simde_m128_set_u32(0x64c54c83, 0x75de7d1e, 0x26b72384, 0x58c83885),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0x40a6a51f, 0x293f5ee0, 0xab6664c2, 0xb0c8c5ff),
      simde_m128_set_u32(0x40a6a51f, 0x293f5ee0, 0xab6664c2, 0xb0c8c5ff),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0x57652673, 0xc9240570, 0xc7018c75, 0xf0e9b330),
      simde_m128_set_u32(0x57652673, 0xc9240570, 0x9c09d09c, 0x735bc240),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpngt_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpngt_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  SIMDE_SKIP_PGI("http://www.pgroup.com/userforum/viewtopic.php?t=5578");

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x7bf7f424, 0x75ba04c4, 0x29a17063, 0x6a458ad5),
      simde_m128_set_u32(0x104cc8e1, 0x75ba04c4, 0x1671c275, 0x909980a7),
      simde_m128_set_u32(0x7bf7f424, 0x75ba04c4, 0x29a17063, 0x00000000) },
    { simde_m128_set_u32(0x1ed1d1a7, 0xacadaad7, 0xe5e02b73, 0x0d531e5b),
      simde_m128_set_u32(0x1ed1d1a7, 0xacadaad7, 0x63d7fed1, 0x0d531e5b),
      simde_m128_set_u32(0x1ed1d1a7, 0xacadaad7, 0xe5e02b73, 0xffffffff) },
    { simde_m128_set_u32(0x0e9738e2, 0xcc511daa, 0xd6fb923c, 0xf7bcb00a),
      simde_m128_set_u32(0x0e9738e2, 0xcc511daa, 0xd6fb923c, 0xeccdb0b5),
      simde_m128_set_u32(0x0e9738e2, 0xcc511daa, 0xd6fb923c, 0xffffffff) },
    { simde_m128_set_u32(0xeccba5e2, 0x57b5b3e9, 0xbad371f6, 0xae22ee04),
      simde_m128_set_u32(0xde991633, 0x57b5b3e9, 0x1bec3de9, 0x497a9b3f),
      simde_m128_set_u32(0xeccba5e2, 0x57b5b3e9, 0xbad371f6, 0xffffffff) },
    { simde_m128_set_u32(0x6593fed2, 0xe31e7445, 0x6f9cf8ce, 0x81bab478),
      simde_m128_set_u32(0x6593fed2, 0x56ab0a96, 0x117b9afb, 0xfe4a2278),
      simde_m128_set_u32(0x6593fed2, 0xe31e7445, 0x6f9cf8ce, 0x00000000) },
    { simde_m128_set_u32(0x64452194, 0x75de7d1e, 0x26b72384, 0x58c83885),
      simde_m128_set_u32(0x64c54c83, 0x75de7d1e, 0x26b72384, 0x58c83885),
      simde_m128_set_u32(0x64452194, 0x75de7d1e, 0x26b72384, 0xffffffff) },
    { simde_m128_set_u32(0x40a6a51f, 0x293f5ee0, 0xab6664c2, 0xb0c8c5ff),
      simde_m128_set_u32(0x40a6a51f, 0x293f5ee0, 0xab6664c2, 0xb0c8c5ff),
      simde_m128_set_u32(0x40a6a51f, 0x293f5ee0, 0xab6664c2, 0xffffffff) },
    { simde_m128_set_u32(0x57652673, 0xc9240570, 0xc7018c75, 0xf0e9b330),
      simde_m128_set_u32(0x57652673, 0xc9240570, 0x9c09d09c, 0x735bc240),
      simde_m128_set_u32(0x57652673, 0xc9240570, 0xc7018c75, 0xffffffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpngt_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpnle_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x54f58ff5, 0xedbbd422, 0x4cbd4da0, 0x2931f29b),
      simde_m128_set_u32(0x54f58ff5, 0xedbbd422, 0x4cbd4da0, 0x2931f29b),
      simde_m128_set_u32(0x00000000, 0x00000000, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0x74b99a59, 0xc4af8c43, 0xe71d0bc8, 0xad0a6b43),
      simde_m128_set_u32(0x74b99a59, 0xb78a3d8f, 0xc9a2b493, 0xad0a6b43),
      simde_m128_set_u32(0x00000000, 0x00000000, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0x5c8f4e94, 0x85592310, 0x62ef2ac1, 0x3f8db3d2),
      simde_m128_set_u32(0xc76ed556, 0x66790621, 0x62ef2ac1, 0x3f8db3d2),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0x040c5b15, 0xba327ec1, 0x4b21b9ce, 0x6083df1e),
      simde_m128_set_u32(0xda12ac19, 0xba327ec1, 0xc2a2760c, 0x6083df1e),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0xffffffff, 0x00000000) },
    { simde_m128_set_u32(0xe94aedbe, 0xc7df2bf7, 0x4286cc01, 0xaa82d6a5),
      simde_m128_set_u32(0xe94aedbe, 0x4e208835, 0x4286cc01, 0x63f204e3),
      simde_m128_set_u32(0x00000000, 0x00000000, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0xd52fe435, 0xab53afec, 0xb9e0a626, 0x069f2d69),
      simde_m128_set_u32(0xd52fe435, 0xab53afec, 0x61ab6916, 0x069f2d69),
      simde_m128_set_u32(0x00000000, 0x00000000, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0x608c0ecf, 0xbd136d39, 0xc3feb91e, 0x1588ec7e),
      simde_m128_set_u32(0x608c0ecf, 0xbd136d39, 0xc3feb91e, 0x1ff04df6),
      simde_m128_set_u32(0x00000000, 0x00000000, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0xb63e38ee, 0x22d6e15b, 0x21f7702b, 0xe4fada8e),
      simde_m128_set_u32(0xb63e38ee, 0x39bb03b7, 0x21f7702b, 0x14573e35),
      simde_m128_set_u32(0x00000000, 0x00000000, 0x00000000, 0x00000000) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpnle_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpnle_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x0e1f191d, 0xb595bc4b, 0x09458e49, 0x7c658a44),
      simde_m128_set_u32(0x48921fda, 0xb595bc4b, 0xfca1479a, 0x99e5f990),
      simde_m128_set_u32(0x0e1f191d, 0xb595bc4b, 0x09458e49, 0xffffffff) },
    { simde_m128_set_u32(0xb88735b6, 0x405ca259, 0xfe4a2b25, 0x655214ad),
      simde_m128_set_u32(0xb88735b6, 0xd0c136ff, 0x24bae19b, 0x655214ad),
      simde_m128_set_u32(0xb88735b6, 0x405ca259, 0xfe4a2b25, 0x00000000) },
    { simde_m128_set_u32(0xfe7c5e56, 0x70c52441, 0x4976c250, 0x34c7eb14),
      simde_m128_set_u32(0xfe7c5e56, 0x24d020b9, 0x4976c250, 0xe4460c8d),
      simde_m128_set_u32(0xfe7c5e56, 0x70c52441, 0x4976c250, 0xffffffff) },
    { simde_m128_set_u32(0x78562b5e, 0xf0adf1d9, 0x205b58cd, 0xae491ec7),
      simde_m128_set_u32(0xa36019ef, 0x89296686, 0xfff243e1, 0xae491ec7),
      simde_m128_set_u32(0x78562b5e, 0xf0adf1d9, 0x205b58cd, 0x00000000) },
    { simde_m128_set_u32(0x6eb53604, 0xb9f69752, 0xd3d89a88, 0x46825a73),
      simde_m128_set_u32(0x8ca54d79, 0xfe29a815, 0xd3d89a88, 0x46825a73),
      simde_m128_set_u32(0x6eb53604, 0xb9f69752, 0xd3d89a88, 0x00000000) },
    { simde_m128_set_u32(0x9e576e14, 0x27996e0c, 0x6a8218d6, 0x00e8cd22),
      simde_m128_set_u32(0x9e576e14, 0x27996e0c, 0x083a5829, 0x00e8cd22),
      simde_m128_set_u32(0x9e576e14, 0x27996e0c, 0x6a8218d6, 0x00000000) },
    { simde_m128_set_u32(0x904273a7, 0x8079b4f8, 0x5a6b18c9, 0xc4b94349),
      simde_m128_set_u32(0x904273a7, 0x8079b4f8, 0x68046ecf, 0xc4b94349),
      simde_m128_set_u32(0x904273a7, 0x8079b4f8, 0x5a6b18c9, 0x00000000) },
    { simde_m128_set_u32(0x620682ad, 0x36a698f0, 0x033e43fe, 0xf33acd76),
      simde_m128_set_u32(0x7a5eeeec, 0x924fca67, 0x033e43fe, 0xf33acd76),
      simde_m128_set_u32(0x620682ad, 0x36a698f0, 0x033e43fe, 0x00000000) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpnle_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpnlt_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x0d1726eb, 0x7c85732b, 0x53a3eec8, 0x026308f9),
      simde_m128_set_u32(0x0d1726eb, 0x40ae91c9, 0x53a3eec8, 0x026308f9),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0xba653f29, 0x817a4638, 0xe9e0b7b7, 0x5116873d),
      simde_m128_set_u32(0xba653f29, 0x144af499, 0x3b0aea56, 0x6edeedc9),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0x00000000, 0x00000000) },
    { simde_m128_set_u32(0x852f4811, 0x1be831f8, 0x0debd166, 0x403f9ddf),
      simde_m128_set_u32(0xf9093291, 0x1be831f8, 0x0debd166, 0x403f9ddf),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0xf029f9a3, 0xa4dffeae, 0xa2e6204c, 0x706c202e),
      simde_m128_set_u32(0xf029f9a3, 0x45447555, 0xa2e6204c, 0x783aac6f),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0xffffffff, 0x00000000) },
    { simde_m128_set_u32(0x3ed5ba6c, 0x1df5b583, 0x51367487, 0x408ebf11),
      simde_m128_set_u32(0x3ed5ba6c, 0x261e799e, 0x51367487, 0x408ebf11),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0xffffffff, 0xffffffff) },
    { simde_m128_set_u32(0xcecb81ca, 0xa0c4611a, 0x3d558bfe, 0xfad7f488),
      simde_m128_set_u32(0x5f7aa6af, 0xd0a138b0, 0x16ba181d, 0x836853cf),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0xffffffff, 0x00000000) },
    { simde_m128_set_u32(0x9a50274b, 0x6248798b, 0xadcd1549, 0xcb0fe3c9),
      simde_m128_set_u32(0x9a50274b, 0xe4ab3b92, 0xadcd1549, 0x39d3c500),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0x00000000) },
    { simde_m128_set_u32(0x4be876cc, 0x73f7077d, 0x65fb9238, 0x5ca08c4a),
      simde_m128_set_u32(0x4be876cc, 0x73f7077d, 0x65fb9238, 0x5ca08c4a),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpnlt_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpnlt_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x9c2983cd, 0x9cec13ad, 0xffbb2318, 0x0b82b0d4),
      simde_m128_set_u32(0x9c2983cd, 0x9cec13ad, 0xffbb2318, 0x0b82b0d4),
      simde_m128_set_u32(0x9c2983cd, 0x9cec13ad, 0xffbb2318, 0xffffffff) },
    { simde_m128_set_u32(0x95314a7a, 0xe6a295c5, 0xb74e2019, 0x5941fcc6),
      simde_m128_set_u32(0x95314a7a, 0xcd2fa99d, 0x4961c5e3, 0xa0e6f408),
      simde_m128_set_u32(0x95314a7a, 0xe6a295c5, 0xb74e2019, 0xffffffff) },
    { simde_m128_set_u32(0xce3f0fe3, 0x4b00cf8c, 0xe3cce91c, 0xfec5b41e),
      simde_m128_set_u32(0xce3f0fe3, 0x4b00cf8c, 0x31ae7a0f, 0xfec5b41e),
      simde_m128_set_u32(0xce3f0fe3, 0x4b00cf8c, 0xe3cce91c, 0xffffffff) },
    { simde_m128_set_u32(0xc2046369, 0xf78a028e, 0xfbe469a5, 0x89ec824d),
      simde_m128_set_u32(0x843484ac, 0x28fdf5e3, 0xfbe469a5, 0x89ec824d),
      simde_m128_set_u32(0xc2046369, 0xf78a028e, 0xfbe469a5, 0xffffffff) },
    { simde_m128_set_u32(0xedecceac, 0x1f6e786f, 0xa99053ad, 0xdf67f2b9),
      simde_m128_set_u32(0x8f2710a4, 0x9e1cf71f, 0x2faa6e42, 0x4dbb2f0f),
      simde_m128_set_u32(0xedecceac, 0x1f6e786f, 0xa99053ad, 0x00000000) },
    { simde_m128_set_u32(0xde18b55b, 0xd1039be8, 0x85e4ff98, 0xd6b8a6c6),
      simde_m128_set_u32(0x76b61f1f, 0x11865da9, 0x85e4ff98, 0xc673bce1),
      simde_m128_set_u32(0xde18b55b, 0xd1039be8, 0x85e4ff98, 0x00000000) },
    { simde_m128_set_u32(0xd1ed302b, 0x42cb6b9b, 0x213791e9, 0xf992a7d3),
      simde_m128_set_u32(0xce308f38, 0x25eb8437, 0x213791e9, 0xce38ecaf),
      simde_m128_set_u32(0xd1ed302b, 0x42cb6b9b, 0x213791e9, 0x00000000) },
    { simde_m128_set_u32(0xcbdae5bb, 0x9624acbf, 0x8d3cb45b, 0x4aa55092),
      simde_m128_set_u32(0x85201eb2, 0x62cc3bfa, 0x0810ddd9, 0x186a5798),
      simde_m128_set_u32(0xcbdae5bb, 0x9624acbf, 0x8d3cb45b, 0xffffffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpnlt_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpord_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[] = {
    { simde_mm_set_ps(1.0f,  NAN,  NAN, 2.0f),
      simde_mm_set_ps( NAN, 3.0f,  NAN, 4.0f),
      simde_m128_set_u32(0x0, 0x0, 0x0, 0xffffffff) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpord_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpord_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[] = {
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x3f800000, 0x40000000, 0x40400000, 0xffffffff) },
    { simde_mm_set_ps( NAN,  NAN,  NAN,  NAN),
      simde_mm_set_ps( NAN,  NAN,  NAN,  NAN),
      simde_m128_set_u32(0x7fc00000, 0x7fc00000, 0x7fc00000, 0x00000000) },
    { simde_mm_set_ps(NAN,  2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x7fc00000, 0x40000000, 0x40400000, 0xffffffff) },
    { simde_mm_set_ps(1.0f,  NAN, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x3f800000, 0x7fc00000, 0x40400000, 0xffffffff) },
    { simde_mm_set_ps(1.0f, 2.0f,  NAN, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x3f800000, 0x40000000, 0x7fc00000, 0xffffffff) },
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, NAN),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x3f800000, 0x40000000, 0x40400000, 0x00000000) },
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_mm_set_ps( NAN, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x3f800000, 0x40000000, 0x40400000, 0xffffffff) },
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f,  NAN, 3.0f, 4.0f),
      simde_m128_set_u32(0x3f800000, 0x40000000, 0x40400000, 0xffffffff) },
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f,  NAN, 4.0f),
      simde_m128_set_u32(0x3f800000, 0x40000000, 0x40400000, 0xffffffff) },
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f,  NAN),
      simde_m128_set_u32(0x3f800000, 0x40000000, 0x40400000, 0x00000000) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpord_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpunord_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[] = {
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x00000000, 0x00000000, 0x00000000, 0x00000000) },
    { simde_mm_set_ps( NAN,  NAN,  NAN,  NAN),
      simde_mm_set_ps( NAN,  NAN,  NAN,  NAN),
      simde_m128_set_u32(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff) },
    { simde_mm_set_ps(NAN,  2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0x00000000, 0x00000000) },
    { simde_mm_set_ps(1.0f,  NAN, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0x00000000, 0x00000000) },
    { simde_mm_set_ps(1.0f, 2.0f,  NAN, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x00000000, 0x00000000, 0xffffffff, 0x00000000) },
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, NAN),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x00000000, 0x00000000, 0x00000000, 0xffffffff) },
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_mm_set_ps( NAN, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0xffffffff, 0x00000000, 0x00000000, 0x00000000) },
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f,  NAN, 3.0f, 4.0f),
      simde_m128_set_u32(0x00000000, 0xffffffff, 0x00000000, 0x00000000) },
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f,  NAN, 4.0f),
      simde_m128_set_u32(0x00000000, 0x00000000, 0xffffffff, 0x00000000) },
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f,  NAN),
      simde_m128_set_u32(0x00000000, 0x00000000, 0x00000000, 0xffffffff) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpunord_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_comieq_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.4193, 0.8439, 0.8100, 0.2669),
      simde_mm_set_ps(0.4193, 0.8439, 0.8100, 0.2669),
      1 },
    { simde_mm_set_ps(0.9426, 0.1679, 0.2845, 0.1698),
      simde_mm_set_ps(0.9426, 0.6931, 0.2845, 0.1698),
      1 },
    { simde_mm_set_ps(0.0547, 0.2368, 0.3365, 0.9146),
      simde_mm_set_ps(0.0547, 0.5935, 0.3365, 0.5014),
      0 },
    { simde_mm_set_ps(0.7179, 0.8607, 0.4372, 0.6140),
      simde_mm_set_ps(0.7179, 0.7239, 0.4372, 0.6140),
      1 },
    { simde_mm_set_ps(0.4474, 0.6848, 0.4305, 0.8738),
      simde_mm_set_ps(0.6059, 0.8463, 0.4305, 0.1517),
      0 },
    { simde_mm_set_ps(0.4537, 0.7254, 0.9987, 0.9115),
      simde_mm_set_ps(0.1771, 0.2982, 0.9987, 0.9003),
      0 },
    { simde_mm_set_ps(0.2162, 0.6303, 0.0602, 0.9986),
      simde_mm_set_ps(0.2162, 0.5872, 0.0602, 0.2491),
      0 },
    { simde_mm_set_ps(0.4836, 0.9929, 0.8942, 0.2367),
      simde_mm_set_ps(0.4836, 0.9929, 0.4202, 0.2367),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_comieq_ss(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_comige_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174, 0.9995, 0.7362, 0.9966),
      simde_mm_set_ps(0.1174, 0.5850, 0.0225, 0.0035),
      1 },
    { simde_mm_set_ps(0.6820, 0.9892, 0.6235, 0.1819),
      simde_mm_set_ps(0.0898, 0.9892, 0.6235, 0.3305),
      0 },
    { simde_mm_set_ps(0.7152, 0.9286, 0.9635, 0.8823),
      simde_mm_set_ps(0.3403, 0.4177, 0.9635, 0.8737),
      1 },
    { simde_mm_set_ps(0.5619, 0.6892, 0.2137, 0.5336),
      simde_mm_set_ps(0.1340, 0.0152, 0.9280, 0.5336),
      1 },
    { simde_mm_set_ps(0.5476, 0.8606, 0.2177, 0.5284),
      simde_mm_set_ps(0.5476, 0.6253, 0.1285, 0.7135),
      0 },
    { simde_mm_set_ps(0.6649, 0.2053, 0.5053, 0.0378),
      simde_mm_set_ps(0.0308, 0.2053, 0.5053, 0.8789),
      0 },
    { simde_mm_set_ps(0.3714, 0.8736, 0.8711, 0.9491),
      simde_mm_set_ps(0.8296, 0.2212, 0.5986, 0.9491),
      1 },
    { simde_mm_set_ps(0.8791, 0.5862, 0.4977, 0.0888),
      simde_mm_set_ps(0.8669, 0.7545, 0.4977, 0.0888),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_comige_ss(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_comigt_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174, 0.9995, 0.7362, 0.9966),
      simde_mm_set_ps(0.1174, 0.5850, 0.0225, 0.0035),
      1 },
    { simde_mm_set_ps(0.6820, 0.9892, 0.6235, 0.1819),
      simde_mm_set_ps(0.0898, 0.9892, 0.6235, 0.3305),
      0 },
    { simde_mm_set_ps(0.7152, 0.9286, 0.9635, 0.8823),
      simde_mm_set_ps(0.3403, 0.4177, 0.9635, 0.8737),
      1 },
    { simde_mm_set_ps(0.5619, 0.6892, 0.2137, 0.5336),
      simde_mm_set_ps(0.1340, 0.0152, 0.9280, 0.5336),
      0 },
    { simde_mm_set_ps(0.5476, 0.8606, 0.2177, 0.5284),
      simde_mm_set_ps(0.5476, 0.6253, 0.1285, 0.7135),
      0 },
    { simde_mm_set_ps(0.6649, 0.2053, 0.5053, 0.0378),
      simde_mm_set_ps(0.0308, 0.2053, 0.5053, 0.8789),
      0 },
    { simde_mm_set_ps(0.3714, 0.8736, 0.8711, 0.9491),
      simde_mm_set_ps(0.8296, 0.2212, 0.5986, 0.9491),
      0 },
    { simde_mm_set_ps(0.8791, 0.5862, 0.4977, 0.0888),
      simde_mm_set_ps(0.8669, 0.7545, 0.4977, 0.0888),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_comigt_ss(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_comile_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174, 0.9995, 0.7362, 0.9966),
      simde_mm_set_ps(0.1174, 0.5850, 0.0225, 0.0035),
      0 },
    { simde_mm_set_ps(0.6820, 0.9892, 0.6235, 0.1819),
      simde_mm_set_ps(0.0898, 0.9892, 0.6235, 0.3305),
      1 },
    { simde_mm_set_ps(0.7152, 0.9286, 0.9635, 0.8823),
      simde_mm_set_ps(0.3403, 0.4177, 0.9635, 0.8737),
      0 },
    { simde_mm_set_ps(0.5619, 0.6892, 0.2137, 0.5336),
      simde_mm_set_ps(0.1340, 0.0152, 0.9280, 0.5336),
      1 },
    { simde_mm_set_ps(0.5476, 0.8606, 0.2177, 0.5284),
      simde_mm_set_ps(0.5476, 0.6253, 0.1285, 0.7135),
      1 },
    { simde_mm_set_ps(0.6649, 0.2053, 0.5053, 0.0378),
      simde_mm_set_ps(0.0308, 0.2053, 0.5053, 0.8789),
      1 },
    { simde_mm_set_ps(0.3714, 0.8736, 0.8711, 0.9491),
      simde_mm_set_ps(0.8296, 0.2212, 0.5986, 0.9491),
      1 },
    { simde_mm_set_ps(0.8791, 0.5862, 0.4977, 0.0888),
      simde_mm_set_ps(0.8669, 0.7545, 0.4977, 0.0888),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_comile_ss(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_comilt_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174, 0.9995, 0.7362, 0.9966),
      simde_mm_set_ps(0.1174, 0.5850, 0.0225, 0.0035),
      0 },
    { simde_mm_set_ps(0.6820, 0.9892, 0.6235, 0.1819),
      simde_mm_set_ps(0.0898, 0.9892, 0.6235, 0.3305),
      1 },
    { simde_mm_set_ps(0.7152, 0.9286, 0.9635, 0.8823),
      simde_mm_set_ps(0.3403, 0.4177, 0.9635, 0.8737),
      0 },
    { simde_mm_set_ps(0.5619, 0.6892, 0.2137, 0.5336),
      simde_mm_set_ps(0.1340, 0.0152, 0.9280, 0.5336),
      0 },
    { simde_mm_set_ps(0.5476, 0.8606, 0.2177, 0.5284),
      simde_mm_set_ps(0.5476, 0.6253, 0.1285, 0.7135),
      1 },
    { simde_mm_set_ps(0.6649, 0.2053, 0.5053, 0.0378),
      simde_mm_set_ps(0.0308, 0.2053, 0.5053, 0.8789),
      1 },
    { simde_mm_set_ps(0.3714, 0.8736, 0.8711, 0.9491),
      simde_mm_set_ps(0.8296, 0.2212, 0.5986, 0.9491),
      0 },
    { simde_mm_set_ps(0.8791, 0.5862, 0.4977, 0.0888),
      simde_mm_set_ps(0.8669, 0.7545, 0.4977, 0.0888),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_comilt_ss(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_comineq_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174, 0.9995, 0.7362, 0.9966),
      simde_mm_set_ps(0.1174, 0.5850, 0.0225, 0.0035),
      1 },
    { simde_mm_set_ps(0.6820, 0.9892, 0.6235, 0.1819),
      simde_mm_set_ps(0.0898, 0.9892, 0.6235, 0.3305),
      1 },
    { simde_mm_set_ps(0.7152, 0.9286, 0.9635, 0.8823),
      simde_mm_set_ps(0.3403, 0.4177, 0.9635, 0.8737),
      1 },
    { simde_mm_set_ps(0.5619, 0.6892, 0.2137, 0.5336),
      simde_mm_set_ps(0.1340, 0.0152, 0.9280, 0.5336),
      0 },
    { simde_mm_set_ps(0.5476, 0.8606, 0.2177, 0.5284),
      simde_mm_set_ps(0.5476, 0.6253, 0.1285, 0.7135),
      1 },
    { simde_mm_set_ps(0.6649, 0.2053, 0.5053, 0.0378),
      simde_mm_set_ps(0.0308, 0.2053, 0.5053, 0.8789),
      1 },
    { simde_mm_set_ps(0.3714, 0.8736, 0.8711, 0.9491),
      simde_mm_set_ps(0.8296, 0.2212, 0.5986, 0.9491),
      0 },
    { simde_mm_set_ps(0.8791, 0.5862, 0.4977, 0.0888),
      simde_mm_set_ps(0.8669, 0.7545, 0.4977, 0.0888),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_comineq_ss(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpunord_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  SIMDE_SKIP_PGI("http://www.pgroup.com/userforum/viewtopic.php?t=5578");

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[] = {
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x3f800000, 0x40000000, 0x40400000, 0x00000000) },
    { simde_mm_set_ps( NAN,  NAN,  NAN,  NAN),
      simde_mm_set_ps( NAN,  NAN,  NAN,  NAN),
      simde_m128_set_u32(0x7fc00000, 0x7fc00000, 0x7fc00000, 0xffffffff) },
    { simde_mm_set_ps(NAN,  2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x7fc00000, 0x40000000, 0x40400000, 0x00000000) },
    { simde_mm_set_ps(1.0f,  NAN, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x3f800000, 0x7fc00000, 0x40400000, 0x00000000) },
    { simde_mm_set_ps(1.0f, 2.0f,  NAN, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x3f800000, 0x40000000, 0x7fc00000, 0x00000000) },
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, NAN),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x3f800000, 0x40000000, 0x40400000, 0xffffffff) },
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_mm_set_ps( NAN, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x3f800000, 0x40000000, 0x40400000, 0x00000000) },
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f,  NAN, 3.0f, 4.0f),
      simde_m128_set_u32(0x3f800000, 0x40000000, 0x40400000, 0x00000000) },
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f,  NAN, 4.0f),
      simde_m128_set_u32(0x3f800000, 0x40000000, 0x40400000, 0x00000000) },
    { simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f,  NAN),
      simde_m128_set_u32(0x3f800000, 0x40000000, 0x40400000, 0xffffffff) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_cmpunord_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvt_pi2ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a, r;
    simde__m64 b;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_cvt_pi2ps(a, b);

    munit_assert_float(r.f32[0], ==, (float) b.i32[0]);
    munit_assert_float(r.f32[1], ==, (float) b.i32[1]);
    munit_assert_int32(r.i32[2], ==, a.i32[2]);
    munit_assert_int32(r.i32[3], ==, a.i32[3]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvt_ps2pi(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a;
    simde__m64 r;

    a = random_m128_float();

    r = simde_mm_cvt_ps2pi(a);

    for (size_t j = 0 ; j < 2 ; j++) {
      int32_t n = (int32_t) a.f32[j];
      if (n != r.i32[j] && (n + 1) != r.i32[j] && (n - 1) != r.i32[j])
	munit_errorf("expected %d, got %d (from %g)", n, r.i32[j], a.f32[j]);
    }
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvt_si2ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a, r;
    int32_t b;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_cvt_si2ss(a, b);

    munit_assert_float(r.f32[0], ==, (float) b);
    munit_assert_float(r.i32[1], ==, a.i32[1]);
    munit_assert_int32(r.i32[2], ==, a.i32[2]);
    munit_assert_int32(r.i32[3], ==, a.i32[3]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvt_ss2si(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a;
    int32_t r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);

    r = simde_mm_cvt_ss2si(a);

    simde_assert_int32_close(r, (int32_t) a.f32[0]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtpi16_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m64 a;
    simde__m128 r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);

    r = simde_mm_cvtpi16_ps(a);

    for (size_t j = 0 ; j < 4 ; j++) {
      simde_assert_int32_close(a.i16[j], (int16_t) r.f32[j]);
    }
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtpi32_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a, r;
    simde__m64 b;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    for (size_t j = 0 ; j < 2 ; j++) {
      a.i32[j] = (int32_t) munit_rand_int_range(-65536, 65535);
      b.i32[j] = (int32_t) munit_rand_int_range(-65536, 65535);
    }

    r = simde_mm_cvtpi32_ps(a, b);

    simde_assert_int32_close(b.i32[0], (int32_t) r.f32[0]);
    simde_assert_int32_close(b.i32[1], (int32_t) r.f32[1]);
    munit_assert_int32(a.i32[2], ==, r.i32[2]);
    munit_assert_int32(a.i32[3], ==, r.i32[3]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtpi32x2_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m64 a, b;
    simde__m128 r;

    for (size_t j = 0 ; j < 2 ; j++) {
      a.i32[j] = munit_rand_int_range(-65536, 65535);
      b.i32[j] = munit_rand_int_range(-65536, 65535);
    }

    r = simde_mm_cvtpi32x2_ps(a, b);

    simde_assert_int32_close(a.i32[0], (int32_t) r.f32[0]);
    simde_assert_int32_close(a.i32[1], (int32_t) r.f32[1]);
    simde_assert_int32_close(b.i32[0], (int32_t) r.f32[2]);
    simde_assert_int32_close(b.i32[1], (int32_t) r.f32[3]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtpi8_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m64 a;
    simde__m128 r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);

    r = simde_mm_cvtpi8_ps(a);

    simde_assert_int32_close(a.i8[0], (int32_t) r.f32[0]);
    simde_assert_int32_close(a.i8[1], (int32_t) r.f32[1]);
    simde_assert_int32_close(a.i8[2], (int32_t) r.f32[2]);
    simde_assert_int32_close(a.i8[3], (int32_t) r.f32[3]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtps_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a;
    simde__m64 r;

    for (size_t j = 0 ; j < (sizeof(a.f32) / sizeof(a.f32[0])) ; j++) {
      a.f32[j] = (float) random_double_range((double) INT16_MIN, (double) INT16_MAX);
    }

    r = simde_mm_cvtps_pi16(a);

    simde_assert_int32_close(r.i16[0], (int16_t) a.f32[0]);
    simde_assert_int32_close(r.i16[1], (int16_t) a.f32[1]);
    simde_assert_int32_close(r.i16[2], (int16_t) a.f32[2]);
    simde_assert_int32_close(r.i16[3], (int16_t) a.f32[3]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtps_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a;
    simde__m64 r;

    for (size_t j = 0 ; j < (sizeof(a.f32) / sizeof(a.f32[0])) ; j++) {
      a.f32[j] = (float) random_double_range((double) INT32_MIN, (double) INT32_MAX);
    }

    r = simde_mm_cvtps_pi32(a);

    simde_assert_int32_close(r.i32[0], (int32_t) a.f32[0]);
    simde_assert_int32_close(r.i32[1], (int32_t) a.f32[1]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtps_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a;
    simde__m64 r;

    for (size_t j = 0 ; j < (sizeof(a.f32) / sizeof(a.f32[0])) ; j++) {
      a.f32[j] = (float) random_double_range((double) INT8_MIN, (double) INT8_MAX);
    }

    r = simde_mm_cvtps_pi8(a);

    simde_assert_int32_close(r.i8[0], (int32_t) a.f32[0]);
    simde_assert_int32_close(r.i8[1], (int32_t) a.f32[1]);
    simde_assert_int32_close(r.i8[2], (int32_t) a.f32[2]);
    simde_assert_int32_close(r.i8[3], (int32_t) a.f32[3]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtpu16_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m64 a;
    simde__m128 r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);

    r = simde_mm_cvtpu16_ps(a);

    simde_assert_int32_close((uint16_t) r.f32[0], a.u16[0]);
    simde_assert_int32_close((uint16_t) r.f32[1], a.u16[1]);
    simde_assert_int32_close((uint16_t) r.f32[2], a.u16[2]);
    simde_assert_int32_close((uint16_t) r.f32[3], a.u16[3]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtpu8_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m64 a;
    simde__m128 r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);

    r = simde_mm_cvtpu8_ps(a);

    simde_assert_int32_close((uint16_t) r.f32[0], a.u8[0]);
    simde_assert_int32_close((uint16_t) r.f32[1], a.u8[1]);
    simde_assert_int32_close((uint16_t) r.f32[2], a.u8[2]);
    simde_assert_int32_close((uint16_t) r.f32[3], a.u8[3]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsi32_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a, r;
    int32_t b;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    b = (int32_t) munit_rand_int_range(INT16_MIN, INT16_MAX);

    r = simde_mm_cvtsi32_ss(a, b);

    simde_assert_int32_close((int) r.f32[0], b);
    munit_assert_int32(r.i32[1], ==, a.i32[1]);
    munit_assert_int32(r.i32[2], ==, a.i32[2]);
    munit_assert_int32(r.i32[3], ==, a.i32[3]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtsi64_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a, r;
    int64_t b;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    b = (int64_t) munit_rand_int_range(INT16_MIN, INT16_MAX);

    r = simde_mm_cvtsi64_ss(a, b);

    simde_assert_int32_close((int) r.f32[0], (int) b);
    munit_assert_int32(r.i32[1], ==, a.i32[1]);
    munit_assert_int32(r.i32[2], ==, a.i32[2]);
    munit_assert_int32(r.i32[3], ==, a.i32[3]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtss_f32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a;
    float r;

    random_floatv(sizeof(a.f32) / sizeof(a.f32[0]), (float*) &a);

    r = simde_mm_cvtss_f32(a);

    munit_assert_float(r, ==, a.f32[0]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtss_si32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a;
    int32_t r;

    random_floatv(sizeof(a.f32) / sizeof(a.f32[0]), (float*) &a);

    r = simde_mm_cvtss_si32(a);

    simde_assert_int32_close(r, (int) a.f32[0]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtss_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a;
    int64_t r;

    random_floatv(sizeof(a.f32) / sizeof(a.f32[0]), (float*) &a);

    r = simde_mm_cvtss_si64(a);

    simde_assert_int64_close((int64_t) r, (int64_t) a.f32[0]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtt_ps2pi(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a;
    simde__m64 r;

    for (size_t j = 0 ; j < (sizeof(a.f32) / sizeof(a.f32[0])) ; j++) {
      a.f32[j] = (float) random_double_range((double) INT16_MIN, (double) INT16_MAX);
    }

    r = simde_mm_cvtt_ps2pi(a);

    munit_assert_int32(r.i32[0], ==, (int32_t) truncf(a.f32[0]));
    munit_assert_int32(r.i32[1], ==, (int32_t) truncf(a.f32[1]));
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtt_ss2si(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a;
    int32_t r;

    for (size_t j = 0 ; j < (sizeof(a.f32) / sizeof(a.f32[0])) ; j++) {
      a.f32[j] = (float) random_double_range((double) INT16_MIN, (double) INT16_MAX);
    }

    r = simde_mm_cvtt_ss2si(a);

    munit_assert_int32(r, ==, (int32_t) truncf(a.f32[0]));
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvttss_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a;
    int64_t r;

    for (size_t j = 0 ; j < (sizeof(a.f32) / sizeof(a.f32[0])) ; j++) {
      a.f32[j] = (float) random_double_range((double) INT16_MIN, (double) INT16_MAX);
    }

    r = simde_mm_cvttss_si64(a);

    munit_assert_int64(r, ==, (int64_t) truncf(a.f32[0]));
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a, b, r, x;

    for (size_t j = 0 ; j < (sizeof(a.f32) / sizeof(a.f32[0])) ; j++) {
      a.f32[j] = (float) random_double_range((double) INT32_MIN, (double) INT32_MAX);
      b.f32[j] = (float) random_double_range((double) INT32_MIN, (double) INT32_MAX);
      x.f32[j] = a.f32[j] / b.f32[j];
    }

    r = simde_mm_div_ps(a, b);

    assert_m128_ps(r, ==, x);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_div_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m128 a, b, r, x;

    for (size_t j = 0 ; j < (sizeof(a.f32) / sizeof(a.f32[0])) ; j++) {
      a.f32[j] = (float) random_double_range((double) INT32_MIN, (double) INT32_MAX);
      b.f32[j] = (float) random_double_range((double) INT32_MIN, (double) INT32_MAX);
      x.f32[j] = (j == 0) ? (a.f32[j] / b.f32[j]) : a.f32[j];
    }

    r = simde_mm_div_ss(a, b);

    assert_m128_ps(r, ==, x);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_extract_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < TEST_PREFERRED_ITERATIONS ; i++) {
    simde__m64 a;
    int r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);

    r = simde_mm_extract_pi16(a, 2);

    munit_assert_int16((int16_t) (r & 0xffff), ==, a.i16[2]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_insert_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t j = 0 ; j < TEST_PREFERRED_ITERATIONS ; j++) {
    simde__m64 a, r, x;
    int16_t i;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    i = munit_rand_int_range(INT16_MIN, INT16_MAX);

    r = simde_mm_insert_pi16(a, i, 2);
    x.i64[0] = a.i64[0];
    x.i16[2] = i;

    simde_assert_m64_i16(r, ==, x);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sub_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const simde__m128 expected = simde_mm_set1_ps(-4.0f);

  simde__m128 a = simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f);
  simde__m128 b = simde_mm_set_ps(5.0f, 6.0f, 7.0f, 8.0f);
  simde__m128 sum = simde_mm_sub_ps(a, b);

  assert_m128_ps(sum, ==, expected);

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  { (char*) "/sse/mm_set_ps",        test_simde_mm_set_ps,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_set1_ps",       test_simde_mm_set1_ps,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_add_ps",        test_simde_mm_add_ps,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_add_ss",        test_simde_mm_add_ss,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_and_ps",        test_simde_mm_and_ps,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_andnot_ps",     test_simde_mm_andnot_ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_avg_pu16",      test_simde_mm_avg_pu16,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_avg_pu8",       test_simde_mm_avg_pu8,       NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpeq_ps",      test_simde_mm_cmpeq_ps,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpeq_ss",      test_simde_mm_cmpeq_ss,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpge_ps",      test_simde_mm_cmpge_ps,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpge_ss",      test_simde_mm_cmpge_ss,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpgt_ps",      test_simde_mm_cmpgt_ps,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpgt_ss",      test_simde_mm_cmpgt_ss,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmple_ps",      test_simde_mm_cmple_ps,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmple_ss",      test_simde_mm_cmple_ss,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmplt_ps",      test_simde_mm_cmplt_ps,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmplt_ss",      test_simde_mm_cmplt_ss,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpneq_ps",     test_simde_mm_cmpneq_ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpneq_ss",     test_simde_mm_cmpneq_ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpnge_ps",     test_simde_mm_cmpnge_ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpnge_ss",     test_simde_mm_cmpnge_ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpngt_ps",     test_simde_mm_cmpngt_ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpngt_ss",     test_simde_mm_cmpngt_ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpnle_ps",     test_simde_mm_cmpnle_ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpnle_ss",     test_simde_mm_cmpnle_ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpnlt_ps",     test_simde_mm_cmpnlt_ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpnlt_ss",     test_simde_mm_cmpnlt_ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpord_ps",     test_simde_mm_cmpord_ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpord_ss",     test_simde_mm_cmpord_ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpunord_ps",   test_simde_mm_cmpunord_ps,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cmpunord_ss",   test_simde_mm_cmpunord_ss,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_comieq_ss",     test_simde_mm_comieq_ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_comige_ss",     test_simde_mm_comige_ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_comigt_ss",     test_simde_mm_comigt_ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_comile_ss",     test_simde_mm_comile_ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_comilt_ss",     test_simde_mm_comilt_ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_comineq_ss",    test_simde_mm_comineq_ss,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvt_pi2ps",     test_simde_mm_cvt_pi2ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvt_ps2pi",     test_simde_mm_cvt_ps2pi,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvt_si2ss",     test_simde_mm_cvt_si2ss,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvt_ss2si",     test_simde_mm_cvt_ss2si,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvtpi16_ps",    test_simde_mm_cvtpi16_ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvtpi32_ps",    test_simde_mm_cvtpi32_ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvtpi32x2_ps",  test_simde_mm_cvtpi32x2_ps,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvtpi8_ps",     test_simde_mm_cvtpi8_ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvtps_pi16",    test_simde_mm_cvtps_pi16,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvtps_pi32",    test_simde_mm_cvtps_pi32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvtps_pi8",     test_simde_mm_cvtps_pi8,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvtpu16_ps",    test_simde_mm_cvtpu16_ps,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvtpu8_ps",     test_simde_mm_cvtpu8_ps,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvtsi32_ss",    test_simde_mm_cvtsi32_ss,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvtsi64_ss",    test_simde_mm_cvtsi64_ss,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvtss_f32",     test_simde_mm_cvtss_f32,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvtss_si32",    test_simde_mm_cvtss_si32,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvtss_si64",    test_simde_mm_cvtss_si64,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvtt_ps2pi",    test_simde_mm_cvtt_ps2pi,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvtt_ss2si",    test_simde_mm_cvtt_ss2si,    NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_cvttss_si64",   test_simde_mm_cvttss_si64,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_div_ps",        test_simde_mm_div_ps,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_div_ss",        test_simde_mm_div_ss,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_extract_pi16",  test_simde_mm_extract_pi16,  NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_insert_pi16",   test_simde_mm_insert_pi16,   NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "/sse/mm_sub_ps",        test_simde_mm_sub_ps,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

const MunitSuite simde_sse_test_suite = {
  (char*) "/sse",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
