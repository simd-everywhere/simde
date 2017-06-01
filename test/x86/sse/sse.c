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

#include <test/x86/x86-internal.h>
#include <simde/x86/sse.h>

#include <stdio.h>
#include <math.h>

#define NAN_AS_U32 (((union { simde_float32 f32; uint32_t u32; }) { .f32 = NAN }).u32)

#define assert_m128_ps(a, cmp, b)					\
  do {									\
    munit_assert_float(((simde_float32*) (&a))[0], cmp, ((simde_float32*) (&b))[0]);	\
    munit_assert_float(((simde_float32*) (&a))[1], cmp, ((simde_float32*) (&b))[1]);	\
    munit_assert_float(((simde_float32*) (&a))[2], cmp, ((simde_float32*) (&b))[2]);	\
    munit_assert_float(((simde_float32*) (&a))[3], cmp, ((simde_float32*) (&b))[3]);	\
  } while (0)

static inline simde__m128
random_m128_f32(void) {
  simde__m128 r;
  random_f32v(sizeof(r.f32) / sizeof(r.f32[0]), (simde_float32*) &r);
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

  simde_float32 d[4];
  random_f32v(sizeof(d) / sizeof(d[0]), d);

  simde__m128 x = simde_mm_set_ps(d[0], d[1], d[2], d[3]);

  simde_float32* f = (simde_float32*) &x;
  munit_assert_float(f[0], ==, d[3]);
  munit_assert_float(f[1], ==, d[2]);
  munit_assert_float(f[2], ==, d[1]);
  munit_assert_float(f[3], ==, d[0]);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde_float32 d;
  random_f32v(1, &d);

  simde__m128 x = simde_mm_set_ss(d);

  simde_float32* f = (simde_float32*) &x;
  munit_assert_float(f[0], ==, d);
  munit_assert_float(f[1], ==, 0.0f);
  munit_assert_float(f[2], ==, 0.0f);
  munit_assert_float(f[3], ==, 0.0f);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_set1_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde_float32 d;
  random_f32v(1, &d);

  simde__m128 x = simde_mm_set1_ps(d);

  simde_float32* f = (simde_float32*) &x;
  munit_assert_float(f[0], ==, d);
  munit_assert_float(f[1], ==, d);
  munit_assert_float(f[2], ==, d);
  munit_assert_float(f[3], ==, d);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_setr_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde_float32 d[4];
  random_f32v(sizeof(d) / sizeof(d[0]), d);

  simde__m128 x = simde_mm_setr_ps(d[3], d[2], d[1], d[0]);

  simde_float32* f = (simde_float32*) &x;
  munit_assert_float(f[0], ==, d[3]);
  munit_assert_float(f[1], ==, d[2]);
  munit_assert_float(f[2], ==, d[1]);
  munit_assert_float(f[3], ==, d[0]);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_setzero_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m128 r = simde_mm_setzero_ps();

  simde_float32* f = (simde_float32*) &r;
  munit_assert_float(f[0], ==, 0.0f);
  munit_assert_float(f[1], ==, 0.0f);
  munit_assert_float(f[2], ==, 0.0f);
  munit_assert_float(f[3], ==, 0.0f);

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
    simde_assert_m64_u8(r, ==, test_vec[i].r);
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
      simde_m128_set_u32(NAN_AS_U32, NAN_AS_U32, NAN_AS_U32, 0x00000000) },
    { simde_mm_set_ps(NAN,  2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(NAN_AS_U32, 0x40000000, 0x40400000, 0xffffffff) },
    { simde_mm_set_ps(1.0f,  NAN, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x3f800000, NAN_AS_U32, 0x40400000, 0xffffffff) },
    { simde_mm_set_ps(1.0f, 2.0f,  NAN, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x3f800000, 0x40000000, NAN_AS_U32, 0xffffffff) },
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
    simde_assert_m128_u32(r, ==, test_vec[i].r);
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
    { simde_mm_set_ps(0.4193f, 0.8439f, 0.8100f, 0.2669f),
      simde_mm_set_ps(0.4193f, 0.8439f, 0.8100f, 0.2669f),
      1 },
    { simde_mm_set_ps(0.9426f, 0.1679f, 0.2845f, 0.1698f),
      simde_mm_set_ps(0.9426f, 0.6931f, 0.2845f, 0.1698f),
      1 },
    { simde_mm_set_ps(0.0547f, 0.2368f, 0.3365f, 0.9146f),
      simde_mm_set_ps(0.0547f, 0.5935f, 0.3365f, 0.5014f),
      0 },
    { simde_mm_set_ps(0.7179f, 0.8607f, 0.4372f, 0.6140f),
      simde_mm_set_ps(0.7179f, 0.7239f, 0.4372f, 0.6140f),
      1 },
    { simde_mm_set_ps(0.4474f, 0.6848f, 0.4305f, 0.8738f),
      simde_mm_set_ps(0.6059f, 0.8463f, 0.4305f, 0.1517f),
      0 },
    { simde_mm_set_ps(0.4537f, 0.7254f, 0.9987f, 0.9115f),
      simde_mm_set_ps(0.1771f, 0.2982f, 0.9987f, 0.9003f),
      0 },
    { simde_mm_set_ps(0.2162f, 0.6303f, 0.0602f, 0.9986f),
      simde_mm_set_ps(0.2162f, 0.5872f, 0.0602f, 0.2491f),
      0 },
    { simde_mm_set_ps(0.4836f, 0.9929f, 0.8942f, 0.2367f),
      simde_mm_set_ps(0.4836f, 0.9929f, 0.4202f, 0.2367f),
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
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      1 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      0 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      1 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      1 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      0 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      0 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      1 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
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
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      1 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      0 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      1 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      0 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      0 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      0 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      0 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
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
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      0 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      1 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      0 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      1 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      1 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      1 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      1 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
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
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      0 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      1 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      0 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      0 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      1 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      1 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      0 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
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
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      1 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      1 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      1 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      0 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      1 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      1 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      0 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
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
      simde_m128_set_u32(NAN_AS_U32, NAN_AS_U32, NAN_AS_U32, 0xffffffff) },
    { simde_mm_set_ps(NAN,  2.0f, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(NAN_AS_U32, 0x40000000, 0x40400000, 0x00000000) },
    { simde_mm_set_ps(1.0f,  NAN, 3.0f, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x3f800000, NAN_AS_U32, 0x40400000, 0x00000000) },
    { simde_mm_set_ps(1.0f, 2.0f,  NAN, 4.0f),
      simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f),
      simde_m128_set_u32(0x3f800000, 0x40000000, NAN_AS_U32, 0x00000000) },
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

    munit_assert_float(r.f32[0], ==, (simde_float32) b.i32[0]);
    munit_assert_float(r.f32[1], ==, (simde_float32) b.i32[1]);
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

    a = random_m128_f32();

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

    munit_assert_float(r.f32[0], ==, (simde_float32) b);
    /* Use int32 since comparing NaNs is always false. */
    munit_assert_int32(r.i32[1], ==, a.i32[1]);
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
      a.f32[j] = (simde_float32) random_f64_range((simde_float64) INT16_MIN, (simde_float64) INT16_MAX);
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
      a.f32[j] = (simde_float32) random_f64_range((simde_float64) INT32_MIN, (simde_float64) INT32_MAX);
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
      a.f32[j] = (simde_float32) random_f64_range((simde_float64) INT8_MIN, (simde_float64) INT8_MAX);
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
    simde_float32 r;

    random_f32v(sizeof(a.f32) / sizeof(a.f32[0]), (simde_float32*) &a);

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

    random_f32v(sizeof(a.f32) / sizeof(a.f32[0]), (simde_float32*) &a);

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

    random_f32v(sizeof(a.f32) / sizeof(a.f32[0]), (simde_float32*) &a);

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
      a.f32[j] = (simde_float32) random_f64_range((simde_float64) INT16_MIN, (simde_float64) INT16_MAX);
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
      a.f32[j] = (simde_float32) random_f64_range((simde_float64) INT16_MIN, (simde_float64) INT16_MAX);
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
      a.f32[j] = (simde_float32) random_f64_range((simde_float64) INT16_MIN, (simde_float64) INT16_MAX);
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
      a.f32[j] = (simde_float32) random_f64_range((simde_float64) INT32_MIN, (simde_float64) INT32_MAX);
      b.f32[j] = (simde_float32) random_f64_range((simde_float64) INT32_MIN, (simde_float64) INT32_MAX);
      x.f32[j] = a.f32[j] / b.f32[j];
    }

    r = simde_mm_div_ps(a, b);

    simde_assert_m128_f32_equal(r, x, 1);
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
      a.f32[j] = (simde_float32) random_f64_range((simde_float64) INT32_MIN, (simde_float64) INT32_MAX);
      b.f32[j] = (simde_float32) random_f64_range((simde_float64) INT32_MIN, (simde_float64) INT32_MAX);
      x.f32[j] = (j == 0) ? (a.f32[j] / b.f32[j]) : a.f32[j];
    }

    r = simde_mm_div_ss(a, b);

    simde_assert_m128_f32_equal(r, x, 2);
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
    i = (int16_t) munit_rand_int_range(INT16_MIN, INT16_MAX);

    r = simde_mm_insert_pi16(a, i, 2);
    x.i64[0] = a.i64[0];
    x.i16[2] = i;

    simde_assert_m64_i16(r, ==, x);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_load_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t j = 0 ; j < TEST_PREFERRED_ITERATIONS ; j++) {
    simde__m128 a, r;

    a = random_m128_f32();

    r = simde_mm_load_ps((simde_float32*) &a);

    simde_assert_m128_f32(r, ==, a);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_load_ps1(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t j = 0 ; j < TEST_PREFERRED_ITERATIONS ; j++) {
    simde__m128 r;
    simde_float32 a;

    random_f32v(1, &a);

    r = simde_mm_load_ps1(&a);

    for (size_t i = 0 ; i < sizeof(r.f32) / sizeof(r.f32[0]) ; i++) {
      munit_assert_float(r.f32[i], ==, a);
    }
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_load_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t j = 0 ; j < TEST_PREFERRED_ITERATIONS ; j++) {
    simde__m128 r;
    simde_float32 a;

    r.i32[0] = 0;
    r.i32[1] = 0;
    r.i32[2] = 0;
    r.i32[3] = 0;

    random_f32v(1, &a);

    r = simde_mm_load_ss(&a);

    munit_assert_float(r.f32[0], ==, a);
    munit_assert_int32(r.i32[1], ==, 0);
    munit_assert_int32(r.i32[2], ==, 0);
    munit_assert_int32(r.i32[3], ==, 0);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_loadh_pi(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t j = 0 ; j < TEST_PREFERRED_ITERATIONS ; j++) {
    simde__m128 a, r;
    simde__m64 b;

    a = random_m128_f32();
    random_f32v(sizeof(b) / sizeof(simde_float32), (simde_float32*) &b);

    r = simde_mm_loadh_pi(a, &b);

    munit_assert_double_equal(r.f32[0], a.f32[0], 4);
    munit_assert_double_equal(r.f32[1], a.f32[1], 4);
    munit_assert_double_equal(r.f32[2], b.f32[0], 4);
    munit_assert_double_equal(r.f32[3], b.f32[1], 4);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_loadl_pi(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t j = 0 ; j < TEST_PREFERRED_ITERATIONS ; j++) {
    simde__m128 a, r;
    simde__m64 b;

    a = random_m128_f32();
    random_f32v(sizeof(b) / sizeof(simde_float32), (simde_float32*) &b);

    r = simde_mm_loadl_pi(a, &b);

    munit_assert_double_equal(r.f32[0], b.f32[0], 4);
    munit_assert_double_equal(r.f32[1], b.f32[1], 4);
    munit_assert_double_equal(r.f32[2], a.f32[2], 4);
    munit_assert_double_equal(r.f32[3], a.f32[3], 4);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_loadr_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t j = 0 ; j < TEST_PREFERRED_ITERATIONS ; j++) {
    simde__m128 r;
    simde_float32 a[4];

    random_f32v(sizeof(a) / sizeof(a[0]), a);

    r = simde_mm_loadr_ps(a);

    munit_assert_double_equal(r.f32[0], a[3], 4);
    munit_assert_double_equal(r.f32[1], a[2], 4);
    munit_assert_double_equal(r.f32[2], a[1], 4);
    munit_assert_double_equal(r.f32[3], a[0], 4);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_loadu_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t j = 0 ; j < TEST_PREFERRED_ITERATIONS ; j++) {
    simde__m128 r;
    simde_float32 a[4];

    random_f32v(sizeof(a) / sizeof(a[0]), a);

    r = simde_mm_loadu_ps(a);

    munit_assert_double_equal(r.f32[0], a[0], 4);
    munit_assert_double_equal(r.f32[1], a[1], 4);
    munit_assert_double_equal(r.f32[2], a[2], 4);
    munit_assert_double_equal(r.f32[3], a[3], 4);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_maskmove_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    char b[8];
    simde__m64 mask;
    char r[8];
  } test_vec[8] = {
    { simde_mm_set_pi8(0xfb, 0x70, 0x6d, 0xf7, 0xf6, 0xe2, 0x99, 0xf3),
      { 0xbd, 0xeb, 0x6b, 0x60, 0xd1, 0x5f, 0x22, 0x94 },
      simde_mm_set_pi8(-112,   64,  -92,   19,  -70,  -49,  -42,   75),
      { 0xbd, 0x99, 0xe2, 0xf6, 0xd1, 0x6d, 0x22, 0xfb } },
    { simde_mm_set_pi8(0x91, 0xf8, 0xac, 0x50, 0x08, 0xc3, 0xb0, 0xab),
      { 0x42, 0x13, 0x60, 0x06, 0xe2, 0x55, 0x61, 0xd4 },
      simde_mm_set_pi8( -90,  -11, -113,   11,  -96, -125,  121, -113),
      { 0xab, 0x13, 0xc3, 0x08, 0xe2, 0xac, 0xf8, 0x91 } },
    { simde_mm_set_pi8(0x78, 0x97, 0x02, 0x15, 0x5d, 0x84, 0xfe, 0x4f),
      { 0x57, 0x62, 0xcc, 0x1c, 0x25, 0x88, 0x6d, 0x4f },
      simde_mm_set_pi8(  34,  106,  -74,   83, -114,  -10,   67,  111),
      { 0x57, 0x62, 0x84, 0x5d, 0x25, 0x02, 0x6d, 0x4f } },
    { simde_mm_set_pi8(0xe6, 0x60, 0x8d, 0x4e, 0x23, 0x31, 0x24, 0xe7),
      { 0x1d, 0x1c, 0x1e, 0xb0, 0xf4, 0x51, 0xaf, 0x78 },
      simde_mm_set_pi8( -59,  -55, -111, -119,   86,   -5,   74,    2),
      { 0x1d, 0x1c, 0x31, 0xb0, 0x4e, 0x8d, 0x60, 0xe6 } },
    { simde_mm_set_pi8(0xdb, 0x29, 0x7b, 0x95, 0x85, 0x20, 0x21, 0x05),
      { 0x82, 0x5e, 0xe2, 0xf3, 0x63, 0x7e, 0x10, 0x05 },
      simde_mm_set_pi8( 113,    1,   66,    5,  -18,   77,  -41,   -4),
      { 0x05, 0x21, 0xe2, 0x85, 0x63, 0x7e, 0x10, 0x05 } },
    { simde_mm_set_pi8(0xa6, 0x8f, 0x61, 0x49, 0x21, 0xfd, 0x6d, 0x3f),
      { 0xd7, 0xa9, 0x8d, 0xe6, 0x44, 0xdf, 0x07, 0xbb },
      simde_mm_set_pi8(  28,  106,  -56,  -23, -126, -119,   22,  -23),
      { 0x3f, 0xa9, 0xfd, 0x21, 0x49, 0x61, 0x07, 0xbb } },
    { simde_mm_set_pi8(0x0c, 0x09, 0xbe, 0x8e, 0x13, 0x5e, 0x99, 0x26),
      { 0x66, 0xb9, 0x37, 0x28, 0x86, 0x5e, 0x47, 0x9d },
      simde_mm_set_pi8(  78,   82, -126,   33,  118,   93, -125,  113),
      { 0x66, 0x99, 0x37, 0x28, 0x86, 0xbe, 0x47, 0x9d } },
    { simde_mm_set_pi8(0x43, 0x6c, 0x37, 0xbc, 0xfb, 0xee, 0x73, 0x7e),
      { 0x5c, 0xae, 0x65, 0xd0, 0x2d, 0x65, 0x5f, 0x33 },
      simde_mm_set_pi8( -92,  -27,   65,  -21,   36,  126,   80,   50),
      { 0x5c, 0xae, 0x65, 0xd0, 0xbc, 0x65, 0x6c, 0x43 } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    char r[8];
    memcpy(r, test_vec[i].b, sizeof(r));

    simde_mm_maskmove_si64(test_vec[i].a, test_vec[i].mask, r);
    simde_assert_int8vx(8, (int8_t*) r, ==, (int8_t*) test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_max_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi8(  79, -120,    6,   13,  -78,  -13,  -16,   54),
      simde_mm_set_pi8(   5,  -78,   46,   46,  -22,   54,  126,  -85),
      simde_mm_set_pi8(  79, -120,   46,   46,  -22,   54,  126,  -85) },
    { simde_mm_set_pi8( 127,   51,   47, -108,   82,  -85,  -83,   11),
      simde_mm_set_pi8(-104,  -98,  -35,   -9,  -38,   92,    0,   10),
      simde_mm_set_pi8( 127,   51,   47, -108,   82,  -85,    0,   10) },
    { simde_mm_set_pi8( 110,   85,  -80,   87, -127,  -32, -121, -101),
      simde_mm_set_pi8( 105,  -98,   69, -109,  -78, -124,  -76,  -55),
      simde_mm_set_pi8( 110,   85,   69, -109,  -78, -124,  -76,  -55) },
    { simde_mm_set_pi8( -52,   59,   86, -104,  113,   82, -123,  119),
      simde_mm_set_pi8(  47,   29,  110,  -75,   83,  -56,   -6,  -11),
      simde_mm_set_pi8(  47,   29,  110,  -75,  113,   82,   -6,  -11) },
    { simde_mm_set_pi8(  99,  -23,    8,   -8,  -76,   -7, -106,   28),
      simde_mm_set_pi8( -85,   79,  -49,  -76,   40,  -66,   26,   72),
      simde_mm_set_pi8(  99,  -23,    8,   -8,   40,  -66,   26,   72) },
    { simde_mm_set_pi8( -57,  104, -109,  -39,   -2,  -10, -113,   72),
      simde_mm_set_pi8(  44,    7,  108,   98,   31,   78,  -79,    8),
      simde_mm_set_pi8(  44,    7,  108,   98,   31,   78,  -79,    8) },
    { simde_mm_set_pi8( -91,  -97,  -40,   31,  -83,  -78,   87,  -84),
      simde_mm_set_pi8(  43,   17,   57,   -3, -119,   78,  -66,   74),
      simde_mm_set_pi8(  43,   17,   57,   -3,  -83,  -78,   87,  -84) },
    { simde_mm_set_pi8(  52,  -99,  -84,   61,   17,   -5, -105,   72),
      simde_mm_set_pi8(  33,   -2,    0,  -88,  -17,  -91,   -4, -127),
      simde_mm_set_pi8(  52,  -99,    0,  -88,   17,   -5,   -4, -127) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_mm_max_pi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_max_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 243.39f,  726.06f, -707.75f,  539.11f),
      simde_mm_set_ps( 452.06f, -743.40f, -959.79f, -625.85f),
      simde_mm_set_ps( 452.06f,  726.06f, -707.75f,  539.11f) },
    { simde_mm_set_ps( 927.87f,  825.19f, -742.41f, -106.29f),
      simde_mm_set_ps(-988.96f, -513.77f,  271.05f, -506.77f),
      simde_mm_set_ps( 927.87f,  825.19f,  271.05f, -106.29f) },
    { simde_mm_set_ps( 501.07f, -751.90f,  333.57f,  862.44f),
      simde_mm_set_ps(-129.71f,  542.65f,  -99.64f, -609.96f),
      simde_mm_set_ps( 501.07f,  542.65f,  333.57f,  862.44f) },
    { simde_mm_set_ps( 237.27f, -100.72f,  806.63f,  318.52f),
      simde_mm_set_ps(  75.91f,  129.34f, -169.38f, -401.83f),
      simde_mm_set_ps( 237.27f,  129.34f,  806.63f,  318.52f) },
    { simde_mm_set_ps(-664.90f,  204.37f, -623.14f,   77.06f),
      simde_mm_set_ps(-909.66f,  849.83f, -206.26f, -162.33f),
      simde_mm_set_ps(-664.90f,  849.83f, -206.26f,   77.06f) },
    { simde_mm_set_ps(-141.59f, -323.72f, -113.68f, -564.18f),
      simde_mm_set_ps( 293.03f, -880.63f,  701.27f, -113.42f),
      simde_mm_set_ps( 293.03f, -323.72f,  701.27f, -113.42f) },
    { simde_mm_set_ps(-158.10f, -618.57f,  197.04f,  507.93f),
      simde_mm_set_ps(-813.81f, -476.03f, -357.06f,  262.52f),
      simde_mm_set_ps(-158.10f, -476.03f,  197.04f,  507.93f) },
    { simde_mm_set_ps( 336.66f, -150.62f, -774.81f,  -52.00f),
      simde_mm_set_ps(-283.99f, -939.93f, -115.92f,  471.61f),
      simde_mm_set_ps( 336.66f, -150.62f, -115.92f,  471.61f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_max_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_max_pu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu8( 95,  35, 185, 136, 198,  90, 109, 138),
      simde_x_mm_set_pu8(165,  90, 139, 114, 195, 147,  62, 160),
      simde_x_mm_set_pu8(165,  90, 185, 136, 198, 147, 109, 160) },
    { simde_x_mm_set_pu8(192, 104, 198, 106, 121, 208, 222,  80),
      simde_x_mm_set_pu8( 14,  66, 107, 237,  19, 244, 121, 240),
      simde_x_mm_set_pu8(192, 104, 198, 237, 121, 244, 222, 240) },
    { simde_x_mm_set_pu8( 95,  71, 177, 202,  66,  32,  85, 206),
      simde_x_mm_set_pu8(206, 134,  86, 165, 246, 242, 112, 247),
      simde_x_mm_set_pu8(206, 134, 177, 202, 246, 242, 112, 247) },
    { simde_x_mm_set_pu8(247, 220,   6,  72, 190, 176, 185, 129),
      simde_x_mm_set_pu8(102, 233,  69,  70,  65,  36, 164, 122),
      simde_x_mm_set_pu8(247, 233,  69,  72, 190, 176, 185, 129) },
    { simde_x_mm_set_pu8(121,  66, 178,  31,  46,  35, 117,  91),
      simde_x_mm_set_pu8(162, 127, 145,  79, 214,  91, 102,  58),
      simde_x_mm_set_pu8(162, 127, 178,  79, 214,  91, 117,  91) },
    { simde_x_mm_set_pu8( 75,  55, 102,  27, 144, 219,  63,  26),
      simde_x_mm_set_pu8(178, 228,  83,  88,  34,  43, 215,  34),
      simde_x_mm_set_pu8(178, 228, 102,  88, 144, 219, 215,  34) },
    { simde_x_mm_set_pu8( 71, 199, 130, 210,  23, 163, 117, 223),
      simde_x_mm_set_pu8( 47, 138,  43,  60, 152,  77, 246,   8),
      simde_x_mm_set_pu8( 71, 199, 130, 210, 152, 163, 246, 223) },
    { simde_x_mm_set_pu8( 65, 226,  26,  83, 148,  71,   8, 192),
      simde_x_mm_set_pu8( 48,  22, 250, 180,  93,  65,  44,  38),
      simde_x_mm_set_pu8( 65, 226, 250, 180, 148,  71,  44, 192) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_mm_max_pu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_max_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 275.98f,  244.68f,  294.03f,  414.26f),
      simde_mm_set_ps( 915.80f,   -0.19f,   23.06f,   81.33f),
      simde_mm_set_ps( 275.98f,  244.68f,  294.03f,  414.26f) },
    { simde_mm_set_ps(-813.38f,  435.35f,  419.41f, -441.22f),
      simde_mm_set_ps( 389.17f, -536.41f, -137.18f, -787.72f),
      simde_mm_set_ps(-813.38f,  435.35f,  419.41f, -441.22f) },
    { simde_mm_set_ps(-619.96f, -614.05f, -479.78f, -823.70f),
      simde_mm_set_ps(-814.29f,  295.27f, -132.00f,  -70.04f),
      simde_mm_set_ps(-619.96f, -614.05f, -479.78f,  -70.04f) },
    { simde_mm_set_ps(-480.26f, -233.90f,  242.17f, -129.02f),
      simde_mm_set_ps(-777.79f, -728.41f,  -33.93f, -163.52f),
      simde_mm_set_ps(-480.26f, -233.90f,  242.17f, -129.02f) },
    { simde_mm_set_ps(-442.14f,  410.97f,  665.05f, -946.79f),
      simde_mm_set_ps(-545.42f,   47.51f,  -78.24f, -648.70f),
      simde_mm_set_ps(-442.14f,  410.97f,  665.05f, -648.70f) },
    { simde_mm_set_ps(-136.30f, -558.74f,  355.69f,   48.70f),
      simde_mm_set_ps(-820.06f, -448.36f,  -48.18f, -396.98f),
      simde_mm_set_ps(-136.30f, -558.74f,  355.69f,   48.70f) },
    { simde_mm_set_ps( 955.43f, -448.98f, -165.93f,   79.87f),
      simde_mm_set_ps(-380.33f,  295.42f,  -77.30f,  721.77f),
      simde_mm_set_ps( 955.43f, -448.98f, -165.93f,  721.77f) },
    { simde_mm_set_ps( -40.78f,  393.73f,  -60.99f, -143.02f),
      simde_mm_set_ps(-232.14f,   77.20f, -606.64f, -624.14f),
      simde_mm_set_ps( -40.78f,  393.73f,  -60.99f, -143.02f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_max_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_min_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(-17712,  12551, -23434, -13133),
      simde_mm_set_pi16( 26266, -20490,   7912,  29803),
      simde_mm_set_pi16(-17712, -20490, -23434, -13133) },
    { simde_mm_set_pi16(-24457,  29877, -26735, -29539),
      simde_mm_set_pi16( 11486,  18014,  20714, -14577),
      simde_mm_set_pi16(-24457,  18014, -26735, -29539) },
    { simde_mm_set_pi16(-20528,   7690,  11233,  -7462),
      simde_mm_set_pi16(-32519,   4248, -31417, -32471),
      simde_mm_set_pi16(-32519,   4248, -31417, -32471) },
    { simde_mm_set_pi16(-31520,   3559, -26842,  21046),
      simde_mm_set_pi16( 13846,  -3714,  16375,  18158),
      simde_mm_set_pi16(-31520,  -3714, -26842,  18158) },
    { simde_mm_set_pi16( 21922,   9874,  13654,  24031),
      simde_mm_set_pi16( 23732,  13322,   8641,  -2491),
      simde_mm_set_pi16( 21922,   9874,   8641,  -2491) },
    { simde_mm_set_pi16( 14557,   3319,  16372,  28742),
      simde_mm_set_pi16(-29436,  20833, -11479, -29779),
      simde_mm_set_pi16(-29436,   3319, -11479, -29779) },
    { simde_mm_set_pi16( 14514,  25528,  18329,  19467),
      simde_mm_set_pi16(  7807, -10832,  -5002, -30632),
      simde_mm_set_pi16(  7807, -10832,  -5002, -30632) },
    { simde_mm_set_pi16( 10007,  31428,  28911, -29602),
      simde_mm_set_pi16( 29865, -25102,  11884,   9524),
      simde_mm_set_pi16( 10007, -25102,  11884, -29602) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_mm_min_pi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_min_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-208.76f, -538.62f,  274.66f, -108.23f),
      simde_mm_set_ps(  64.30f,  627.51f, -431.61f, -737.40f),
      simde_mm_set_ps(-208.76f, -538.62f, -431.61f, -737.40f) },
    { simde_mm_set_ps( -73.05f,  464.03f,  573.95f, -332.31f),
      simde_mm_set_ps( 981.43f,  170.70f,  925.44f,   10.20f),
      simde_mm_set_ps( -73.05f,  170.70f,  573.95f, -332.31f) },
    { simde_mm_set_ps(-607.82f, -692.09f,  269.02f, -871.09f),
      simde_mm_set_ps( -20.67f,  813.79f,  396.23f, -759.77f),
      simde_mm_set_ps(-607.82f, -692.09f,  269.02f, -871.09f) },
    { simde_mm_set_ps(-134.36f,  503.32f,  958.70f, -249.82f),
      simde_mm_set_ps(  85.42f,  559.57f, -188.45f, -400.64f),
      simde_mm_set_ps(-134.36f,  503.32f, -188.45f, -400.64f) },
    { simde_mm_set_ps(-181.45f,  972.62f, -574.93f,  785.60f),
      simde_mm_set_ps( 831.31f,  832.49f,  748.83f,  657.11f),
      simde_mm_set_ps(-181.45f,  832.49f, -574.93f,  657.11f) },
    { simde_mm_set_ps( 510.02f, -639.06f, -929.32f, -561.38f),
      simde_mm_set_ps( 470.99f,  798.01f, -752.21f, -260.75f),
      simde_mm_set_ps( 470.99f, -639.06f, -929.32f, -561.38f) },
    { simde_mm_set_ps( 948.37f,  798.25f,  885.60f, -998.75f),
      simde_mm_set_ps(  -1.83f, -742.81f,   99.17f,   81.46f),
      simde_mm_set_ps(  -1.83f, -742.81f,   99.17f, -998.75f) },
    { simde_mm_set_ps(-202.80f, -308.12f,    5.40f, -806.83f),
      simde_mm_set_ps( 249.52f, -139.94f,  736.53f, -851.39f),
      simde_mm_set_ps(-202.80f, -308.12f,    5.40f, -851.39f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_min_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_min_pu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu8(  3,  32, 201, 226, 126, 175,  31,  50),
      simde_x_mm_set_pu8(220, 148, 109, 216,  32, 219, 221, 116),
      simde_x_mm_set_pu8(  3,  32, 109, 216,  32, 175,  31,  50) },
    { simde_x_mm_set_pu8(123, 186, 147,  62,  85, 163, 217, 248),
      simde_x_mm_set_pu8( 50, 187, 220, 240, 243, 231, 241, 209),
      simde_x_mm_set_pu8( 50, 186, 147,  62,  85, 163, 217, 209) },
    { simde_x_mm_set_pu8(100,  27,  19,  67, 100, 214, 111, 154),
      simde_x_mm_set_pu8( 31,  16,  59, 138, 178,  43,  63, 213),
      simde_x_mm_set_pu8( 31,  16,  19,  67, 100,  43,  63, 154) },
    { simde_x_mm_set_pu8(205, 136,  79, 245, 178, 167,   7,   9),
      simde_x_mm_set_pu8(103, 214, 180, 123,  12, 141,  59, 104),
      simde_x_mm_set_pu8(103, 136,  79, 123,  12, 141,   7,   9) },
    { simde_x_mm_set_pu8(143, 111, 158,  95, 192,  18,  83,  18),
      simde_x_mm_set_pu8( 81, 138, 112,  76,  64, 169,  64,  35),
      simde_x_mm_set_pu8( 81, 111, 112,  76,  64,  18,  64,  18) },
    { simde_x_mm_set_pu8(246, 106, 240, 187, 202, 248,   5, 105),
      simde_x_mm_set_pu8(184, 221, 161, 239, 162, 163,  17, 109),
      simde_x_mm_set_pu8(184, 106, 161, 187, 162, 163,   5, 105) },
    { simde_x_mm_set_pu8(172,  59,  82,   1, 130,  31, 233,  87),
      simde_x_mm_set_pu8( 51, 153, 219,  33, 100, 204, 105, 228),
      simde_x_mm_set_pu8( 51,  59,  82,   1, 100,  31, 105,  87) },
    { simde_x_mm_set_pu8(228, 182, 179, 248,  70,  35,  65,  84),
      simde_x_mm_set_pu8( 84, 159, 106,   2, 156, 107, 120,  67),
      simde_x_mm_set_pu8( 84, 159, 106,   2,  70,  35,  65,  67) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_mm_min_pu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_min_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 905.52f, -330.94f, -743.29f,  -10.28f),
      simde_mm_set_ps(-603.64f,  -33.37f,  723.28f, -975.56f),
      simde_mm_set_ps( 905.52f, -330.94f, -743.29f, -975.56f) },
    { simde_mm_set_ps(-901.94f,  395.72f,  391.94f, -212.21f),
      simde_mm_set_ps(-188.76f,  605.72f, -757.32f, -217.92f),
      simde_mm_set_ps(-901.94f,  395.72f,  391.94f, -217.92f) },
    { simde_mm_set_ps( 270.60f,  585.69f, -494.83f,  500.56f),
      simde_mm_set_ps( 444.26f,  925.14f, -362.96f,  120.59f),
      simde_mm_set_ps( 270.60f,  585.69f, -494.83f,  120.59f) },
    { simde_mm_set_ps( 222.03f, -452.05f, -212.51f,   16.60f),
      simde_mm_set_ps(-338.89f,  786.83f, -596.87f,  345.56f),
      simde_mm_set_ps( 222.03f, -452.05f, -212.51f,   16.60f) },
    { simde_mm_set_ps( 130.17f, -389.05f, -693.23f, -558.79f),
      simde_mm_set_ps( 351.18f,    1.64f,  661.55f,  667.31f),
      simde_mm_set_ps( 130.17f, -389.05f, -693.23f, -558.79f) },
    { simde_mm_set_ps(-492.87f,  857.67f,   99.45f, -129.44f),
      simde_mm_set_ps( 424.94f,  552.64f,   68.12f,  195.21f),
      simde_mm_set_ps(-492.87f,  857.67f,   99.45f, -129.44f) },
    { simde_mm_set_ps( 213.75f,  969.89f, -341.00f,  -19.41f),
      simde_mm_set_ps( 773.33f, -228.51f,   68.57f, -153.07f),
      simde_mm_set_ps( 213.75f,  969.89f, -341.00f, -153.07f) },
    { simde_mm_set_ps(-482.05f, -169.03f, -647.88f, -151.80f),
      simde_mm_set_ps( 604.32f, -221.45f,  450.87f, -490.43f),
      simde_mm_set_ps(-482.05f, -169.03f, -647.88f, -490.43f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_min_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_move_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-358.23f,  557.58f,  318.93f, -758.38f),
      simde_mm_set_ps(   1.51f,  975.39f, -136.78f, -157.41f),
      simde_mm_set_ps(-358.23f,  557.58f,  318.93f, -157.41f) },
    { simde_mm_set_ps(-944.08f, -768.00f,  457.67f,  835.58f),
      simde_mm_set_ps(-700.69f,  960.42f,  670.21f, -766.17f),
      simde_mm_set_ps(-944.08f, -768.00f,  457.67f, -766.17f) },
    { simde_mm_set_ps(-640.75f,   79.11f, -809.30f, -582.60f),
      simde_mm_set_ps( 451.92f,  260.70f, -368.72f, -418.36f),
      simde_mm_set_ps(-640.75f,   79.11f, -809.30f, -418.36f) },
    { simde_mm_set_ps(-265.37f, -906.15f,  463.48f,  857.51f),
      simde_mm_set_ps(  52.86f, -189.27f,  -89.79f,  636.22f),
      simde_mm_set_ps(-265.37f, -906.15f,  463.48f,  636.22f) },
    { simde_mm_set_ps( 627.30f, -419.51f,  242.55f, -669.89f),
      simde_mm_set_ps( 891.75f,  884.03f,  808.69f,   48.90f),
      simde_mm_set_ps( 627.30f, -419.51f,  242.55f,   48.90f) },
    { simde_mm_set_ps( 162.10f, -144.97f,  -36.34f,  747.42f),
      simde_mm_set_ps( 962.83f,  377.89f, -519.04f, -497.15f),
      simde_mm_set_ps( 162.10f, -144.97f,  -36.34f, -497.15f) },
    { simde_mm_set_ps(-230.32f,  536.55f, -396.11f,  274.97f),
      simde_mm_set_ps(-442.89f,  237.99f, -587.16f,  603.90f),
      simde_mm_set_ps(-230.32f,  536.55f, -396.11f,  603.90f) },
    { simde_mm_set_ps(-213.83f,  999.36f,  795.03f,  885.52f),
      simde_mm_set_ps(-878.99f, -162.39f,   89.22f, -749.67f),
      simde_mm_set_ps(-213.83f,  999.36f,  795.03f, -749.67f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_move_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_movehl_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 448.42f,  812.28f, -569.58f, -612.98f),
      simde_mm_set_ps(-260.91f,  851.49f, -543.31f, -452.37f),
      simde_mm_set_ps( 448.42f,  812.28f, -260.91f,  851.49f) },
    { simde_mm_set_ps( 164.79f, -510.29f, -875.53f,  338.43f),
      simde_mm_set_ps( 195.22f, -222.31f, -247.28f, -544.38f),
      simde_mm_set_ps( 164.79f, -510.29f,  195.22f, -222.31f) },
    { simde_mm_set_ps( 632.26f, -381.04f, -465.25f, -913.48f),
      simde_mm_set_ps(-790.33f, -504.12f, -321.51f, -760.29f),
      simde_mm_set_ps( 632.26f, -381.04f, -790.33f, -504.12f) },
    { simde_mm_set_ps( 203.91f,  884.83f, -352.58f, -259.85f),
      simde_mm_set_ps(  92.13f,  448.80f,  494.59f,  -13.35f),
      simde_mm_set_ps( 203.91f,  884.83f,   92.13f,  448.80f) },
    { simde_mm_set_ps( 223.91f, -533.66f,  185.50f, -579.52f),
      simde_mm_set_ps(-316.81f, -862.60f, -895.66f,  129.46f),
      simde_mm_set_ps( 223.91f, -533.66f, -316.81f, -862.60f) },
    { simde_mm_set_ps(-731.11f,  221.64f,  388.77f,   -5.75f),
      simde_mm_set_ps(-220.42f,  -24.67f, -629.56f, -668.90f),
      simde_mm_set_ps(-731.11f,  221.64f, -220.42f,  -24.67f) },
    { simde_mm_set_ps(-367.65f,  429.37f,  435.99f,  954.93f),
      simde_mm_set_ps( 382.29f, -511.24f,  874.66f,  450.20f),
      simde_mm_set_ps(-367.65f,  429.37f,  382.29f, -511.24f) },
    { simde_mm_set_ps( 917.13f, -437.03f, -611.86f, -766.78f),
      simde_mm_set_ps( -43.20f, -568.30f,  -68.56f, -878.32f),
      simde_mm_set_ps( 917.13f, -437.03f,  -43.20f, -568.30f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_movehl_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_movelh_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-126.61f, -366.61f,  342.01f, -290.15f),
      simde_mm_set_ps( 691.90f, -944.15f,   99.58f,  438.89f),
      simde_mm_set_ps(  99.58f,  438.89f,  342.01f, -290.15f) },
    { simde_mm_set_ps(-879.79f,  930.29f,  951.33f,  492.78f),
      simde_mm_set_ps( 600.74f, -198.87f,  936.84f,  313.69f),
      simde_mm_set_ps( 936.84f,  313.69f,  951.33f,  492.78f) },
    { simde_mm_set_ps(-467.81f, -802.41f,  821.13f, -596.55f),
      simde_mm_set_ps( 695.24f,  173.94f, -480.51f,  -41.27f),
      simde_mm_set_ps(-480.51f,  -41.27f,  821.13f, -596.55f) },
    { simde_mm_set_ps( 645.54f,  -99.35f, -669.53f, -518.75f),
      simde_mm_set_ps( 261.98f,   -2.77f,  -35.85f, -725.12f),
      simde_mm_set_ps( -35.85f, -725.12f, -669.53f, -518.75f) },
    { simde_mm_set_ps( 851.93f,  376.50f, -125.53f,  315.67f),
      simde_mm_set_ps( 722.06f, -287.10f,  806.63f, -831.38f),
      simde_mm_set_ps( 806.63f, -831.38f, -125.53f,  315.67f) },
    { simde_mm_set_ps(-180.42f, -861.51f,  293.97f,  929.27f),
      simde_mm_set_ps( -61.47f, -964.08f, -555.27f,  147.09f),
      simde_mm_set_ps(-555.27f,  147.09f,  293.97f,  929.27f) },
    { simde_mm_set_ps( 294.20f,   18.46f,  779.53f, -177.14f),
      simde_mm_set_ps( 664.57f,  349.92f,  797.65f,  206.26f),
      simde_mm_set_ps( 797.65f,  206.26f,  779.53f, -177.14f) },
    { simde_mm_set_ps(-737.06f, -946.48f, -251.45f, -808.64f),
      simde_mm_set_ps(-245.46f,  616.13f, -342.03f,  914.50f),
      simde_mm_set_ps(-342.03f,  914.50f, -251.45f, -808.64f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_movelh_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_movemask_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pi8(   7,  -33,    4,  -58,  -87,   16,   83,  -97),  89 },
    { simde_mm_set_pi8(  28,  -40,  -15, -114,  -71,  -97,  -12,  -53), 127 },
    { simde_mm_set_pi8( -16,  -80,   47,   37,   16, -111,  120,  -12), 197 },
    { simde_mm_set_pi8(   4,  -17,  -44,   -3,  -35,   81,  -87,   97), 122 },
    { simde_mm_set_pi8( -84,   23,   93,   30,   87,  114,   66,   94), 128 },
    { simde_mm_set_pi8(  -1,  -24,   -4,  -87,   33,   91,   32,   43), 240 },
    { simde_mm_set_pi8( -11,   96,  -68,   84,   53, -120,  124,   -4), 165 },
    { simde_mm_set_pi8(-122,   91,   -3,  -17,  -54,   62,  119,  -40), 185 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_movemask_pi8(test_vec[i].a);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_movemask_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    int r;
  } test_vec[8] = {
    { simde_m128_set_u32(0xa67d815d, 0x313ba9ba, 0x21c24eef, 0x423f8c9e),   8 },
    { simde_m128_set_u32(0x489edd7d, 0x67cd5a03, 0x615ae189, 0x97259ce3),   1 },
    { simde_m128_set_u32(0xe28d2b70, 0xe91a3281, 0x73d2c004, 0x7cc3587e),  12 },
    { simde_m128_set_u32(0xb38e9200, 0xd86e4d45, 0xd67c3858, 0x6dd9c655),  14 },
    { simde_m128_set_u32(0x3324bf52, 0x86f260cf, 0x1c6c8682, 0x53be68fe),   4 },
    { simde_m128_set_u32(0xf2018c61, 0x250c57a7, 0x0654d448, 0x8a06fe60),   9 },
    { simde_m128_set_u32(0x0430e063, 0x7ffc7ad3, 0x9306516d, 0x5896591c),   2 },
    { simde_m128_set_u32(0xfa68023e, 0x2e799bce, 0x88c4c4ea, 0x31bc8ed8),  10 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_movemask_ps(test_vec[i].a);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mul_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const simde__m128 expected = simde_mm_set_ps(5.0f, 12.0f, 21.0f, 32.0f);

  simde__m128 a = simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f);
  simde__m128 b = simde_mm_set_ps(5.0f, 6.0f, 7.0f, 8.0f);
  simde__m128 r = simde_mm_mul_ps(a, b);

  assert_m128_ps(r, ==, expected);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mul_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const simde__m128 expected = simde_mm_set_ps(1.0f, 2.0f, 3.0f, 32.0f);

  simde__m128 a = simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f);
  simde__m128 b = simde_mm_set_ps(5.0f, 6.0f, 7.0f, 8.0f);
  simde__m128 r = simde_mm_mul_ss(a, b);

  assert_m128_ps(r, ==, expected);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mulhi_pu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(0x0ce6, 0xb80e, 0x7370, 0xd027),
      simde_mm_set_pi16(0x509b, 0x03d0, 0x5141, 0x6c78),
      simde_mm_set_pi16(0x040f, 0x02bd, 0x24a3, 0x5832) },
    { simde_mm_set_pi16(0xbdda, 0xb7d6, 0x927d, 0x3380),
      simde_mm_set_pi16(0x622f, 0xb9cc, 0x85a2, 0x28fd),
      simde_mm_set_pi16(0x48d0, 0x856c, 0x4c77, 0x083e) },
    { simde_mm_set_pi16(0xebb4, 0xadbd, 0x17fd, 0x28d6),
      simde_mm_set_pi16(0xc75e, 0x2684, 0x2168, 0x03c0),
      simde_mm_set_pi16(0xb78f, 0x1a23, 0x0321, 0x0099) },
    { simde_mm_set_pi16(0xba47, 0xd90f, 0xc530, 0x9098),
      simde_mm_set_pi16(0x9f18, 0x98a8, 0x975a, 0xf29e),
      simde_mm_set_pi16(0x73c3, 0x816f, 0x7494, 0x8908) },
    { simde_mm_set_pi16(0x9f46, 0xfcc8, 0xf55d, 0x817b),
      simde_mm_set_pi16(0x8ea0, 0xf8e8, 0xa753, 0x19c4),
      simde_mm_set_pi16(0x58bc, 0xf5c6, 0xa05f, 0x0d08) },
    { simde_mm_set_pi16(0xf8ed, 0x93a0, 0xa9b0, 0xb163),
      simde_mm_set_pi16(0xc189, 0x257a, 0x93ae, 0xf896),
      simde_mm_set_pi16(0xbc2f, 0x159c, 0x61e3, 0xac3f) },
    { simde_mm_set_pi16(0xeac8, 0xea2b, 0x63ca, 0x7108),
      simde_mm_set_pi16(0xb9c3, 0x265b, 0x9f92, 0xcc1b),
      simde_mm_set_pi16(0xaa5d, 0x2315, 0x3e33, 0x5a1e) },
    { simde_mm_set_pi16(0x8543, 0xa935, 0x9bc6, 0x13aa),
      simde_mm_set_pi16(0x2b51, 0x040f, 0xb622, 0x7c25),
      simde_mm_set_pi16(0x168c, 0x02ae, 0x6ed3, 0x0989) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_mm_mulhi_pu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_or_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(0x3f15cce0, 0xc9e102f7, 0x4ab44838, 0x5bcd6039),
      simde_m128_set_u32(0x15e48867, 0xd6298bba, 0x8405d277, 0x897f4e3e),
      simde_m128_set_u32(0x3ff5cce7, 0xdfe98bff, 0xceb5da7f, 0xdbff6e3f) },
    { simde_m128_set_u32(0xa184791e, 0x09fa0504, 0x3d22f3d7, 0xcac1099b),
      simde_m128_set_u32(0xd346da14, 0xa334ef18, 0x9edd6028, 0xfada120d),
      simde_m128_set_u32(0xf3c6fb1e, 0xabfeef1c, 0xbffff3ff, 0xfadb1b9f) },
    { simde_m128_set_u32(0x32a3f44e, 0xa6658097, 0xb5df14a2, 0x26f0f39a),
      simde_m128_set_u32(0x7cd48cb0, 0xcd3e8015, 0x9b14a112, 0xd25bc865),
      simde_m128_set_u32(0x7ef7fcfe, 0xef7f8097, 0xbfdfb5b2, 0xf6fbfbff) },
    { simde_m128_set_u32(0x31f7aa8c, 0x66e88f0b, 0xc0127212, 0x8a751789),
      simde_m128_set_u32(0xaf254e63, 0xe25dc364, 0x1af40823, 0xba4c2120),
      simde_m128_set_u32(0xbff7eeef, 0xe6fdcf6f, 0xdaf67a33, 0xba7d37a9) },
    { simde_m128_set_u32(0x5e7cc730, 0x88243815, 0x35f22425, 0xb46c9b6d),
      simde_m128_set_u32(0x30058d37, 0xea0ed70a, 0x7e38690b, 0x872e2bec),
      simde_m128_set_u32(0x7e7dcf37, 0xea2eff1f, 0x7ffa6d2f, 0xb76ebbed) },
    { simde_m128_set_u32(0xb3361fea, 0xd7e3ebea, 0x049a4d7b, 0xa4ddb93c),
      simde_m128_set_u32(0xeb98f3e1, 0x4d469573, 0x0edab5c9, 0x56e22997),
      simde_m128_set_u32(0xfbbeffeb, 0xdfe7fffb, 0x0edafdfb, 0xf6ffb9bf) },
    { simde_m128_set_u32(0x836329d3, 0x7c88cc2e, 0x22049925, 0x67726596),
      simde_m128_set_u32(0xdf253de0, 0x0fd75660, 0x0f23b348, 0x351290d1),
      simde_m128_set_u32(0xdf673df3, 0x7fdfde6e, 0x2f27bb6d, 0x7772f5d7) },
    { simde_m128_set_u32(0x7f123165, 0x98931e26, 0x7fc611a1, 0xf9b4e373),
      simde_m128_set_u32(0xb4dd8bb4, 0x3a9ec4d4, 0x4aa2e147, 0x9b090515),
      simde_m128_set_u32(0xffdfbbf5, 0xba9fdef6, 0x7fe6f1e7, 0xfbbde777) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_or_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_rcp_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-8.23f, -5.18f,  3.66f, -3.55f),
      simde_mm_set_ps(-0.12f, -0.19f,  0.27f, -0.28f) },
    { simde_mm_set_ps( 5.27f,  1.94f, -1.37f,  3.59f),
      simde_mm_set_ps( 0.19f,  0.52f, -0.73f,  0.28f) },
    { simde_mm_set_ps( 1.70f, -6.14f,  4.86f,  1.14f),
      simde_mm_set_ps( 0.59f, -0.16f,  0.21f,  0.88f) },
    { simde_mm_set_ps(-6.46f,  0.31f,  0.95f,  1.02f),
      simde_mm_set_ps(-0.15f,  3.25f,  1.05f,  0.98f) },
    { simde_mm_set_ps( 0.27f,  3.55f, -8.33f, -7.65f),
      simde_mm_set_ps( 3.70f,  0.28f, -0.12f, -0.13f) },
    { simde_mm_set_ps( 3.04f, -3.61f,  1.60f, -3.92f),
      simde_mm_set_ps( 0.33f, -0.28f,  0.62f, -0.25f) },
    { simde_mm_set_ps( 4.81f,  3.50f,  6.45f,  9.52f),
      simde_mm_set_ps( 0.21f,  0.29f,  0.15f,  0.11f) },
    { simde_mm_set_ps( 6.39f,  6.57f, -0.50f,  6.01f),
      simde_mm_set_ps( 0.16f,  0.15f, -2.00f,  0.17f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_rcp_ps(test_vec[i].a);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_rcp_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-0.17f, -5.82f,  9.03f,  0.51f),
      simde_mm_set_ps(-0.17f, -5.82f,  9.03f,  1.97f) },
    { simde_mm_set_ps( 3.71f,  8.82f,  3.74f, -1.45f),
      simde_mm_set_ps( 3.71f,  8.82f,  3.74f, -0.69f) },
    { simde_mm_set_ps( 6.34f, -2.54f, -3.13f, -5.87f),
      simde_mm_set_ps( 6.34f, -2.54f, -3.13f, -0.17f) },
    { simde_mm_set_ps(-3.12f,  8.32f,  6.67f,  6.69f),
      simde_mm_set_ps(-3.12f,  8.32f,  6.67f,  0.15f) },
    { simde_mm_set_ps( 8.74f,  8.53f,  5.33f,  6.71f),
      simde_mm_set_ps( 8.74f,  8.53f,  5.33f,  0.15f) },
    { simde_mm_set_ps( 8.56f, -4.33f,  4.16f, -1.33f),
      simde_mm_set_ps( 8.56f, -4.33f,  4.16f, -0.75f) },
    { simde_mm_set_ps( 0.83f, -2.25f, -0.87f,  8.44f),
      simde_mm_set_ps( 0.83f, -2.25f, -0.87f,  0.12f) },
    { simde_mm_set_ps( 0.99f,  5.65f, -2.23f,  1.17f),
      simde_mm_set_ps( 0.99f,  5.65f, -2.23f,  0.85f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_rcp_ss(test_vec[i].a);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_rsqrt_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 19.76f,  43.05f,  24.93f,  44.79f),
      simde_mm_set_ps(  0.22f,   0.15f,   0.20f,   0.15f) },
    { simde_mm_set_ps( 53.16f,  37.63f,  14.64f,  91.38f),
      simde_mm_set_ps(  0.14f,   0.16f,   0.26f,   0.10f) },
    { simde_mm_set_ps( 51.45f,  20.86f,  31.69f,  22.93f),
      simde_mm_set_ps(  0.14f,   0.22f,   0.18f,   0.21f) },
    { simde_mm_set_ps( 70.34f,  27.96f,  47.70f,  68.63f),
      simde_mm_set_ps(  0.12f,   0.19f,   0.14f,   0.12f) },
    { simde_mm_set_ps( 15.37f,  83.67f,  71.19f,  29.53f),
      simde_mm_set_ps(  0.26f,   0.11f,   0.12f,   0.18f) },
    { simde_mm_set_ps( 54.38f,   5.48f,  29.73f,  69.45f),
      simde_mm_set_ps(  0.14f,   0.43f,   0.18f,   0.12f) },
    { simde_mm_set_ps( 84.04f,  25.31f,  28.88f,  94.95f),
      simde_mm_set_ps(  0.11f,   0.20f,   0.19f,   0.10f) },
    { simde_mm_set_ps( 62.50f,   1.25f,  73.97f,  57.92f),
      simde_mm_set_ps(  0.13f,   0.90f,   0.12f,   0.13f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_rsqrt_ps(test_vec[i].a);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_rsqrt_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 19.76f,  43.05f,  24.93f,  44.79f),
      simde_mm_set_ps( 19.76f,  43.05f,  24.93f,   0.15f) },
    { simde_mm_set_ps( 53.16f,  37.63f,  14.64f,  91.38f),
      simde_mm_set_ps( 53.16f,  37.63f,  14.64f,   0.10f) },
    { simde_mm_set_ps( 51.45f,  20.86f,  31.69f,  22.93f),
      simde_mm_set_ps( 51.45f,  20.86f,  31.69f,   0.21f) },
    { simde_mm_set_ps( 70.34f,  27.96f,  47.70f,  68.63f),
      simde_mm_set_ps( 70.34f,  27.96f,  47.70f,   0.12f) },
    { simde_mm_set_ps( 15.37f,  83.67f,  71.19f,  29.53f),
      simde_mm_set_ps( 15.37f,  83.67f,  71.19f,   0.18f) },
    { simde_mm_set_ps( 54.38f,   5.48f,  29.73f,  69.45f),
      simde_mm_set_ps( 54.38f,   5.48f,  29.73f,   0.12f) },
    { simde_mm_set_ps( 84.04f,  25.31f,  28.88f,  94.95f),
      simde_mm_set_ps( 84.04f,  25.31f,  28.88f,   0.10f) },
    { simde_mm_set_ps( 62.50f,   1.25f,  73.97f,  57.92f),
      simde_mm_set_ps( 62.50f,   1.25f,  73.97f,   0.13f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_rsqrt_ss(test_vec[i].a);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sad_pu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_x_mm_set_pu8(158,  38, 204, 230, 242, 108, 135, 100),
      simde_x_mm_set_pu8(130, 168, 102, 233, 237, 176,  22, 158),
      simde_x_mm_set_pu16(0, 0, 0, 507) },
    { simde_x_mm_set_pu8( 15, 252, 176, 193, 115,  44,   0,  83),
      simde_x_mm_set_pu8( 99, 169,  76, 203, 218, 181, 138, 226),
      simde_x_mm_set_pu16(0, 0, 0, 798) },
    { simde_x_mm_set_pu8(230,  50, 152, 234, 252,  79, 170, 145),
      simde_x_mm_set_pu8(225, 219, 116, 170, 250, 129, 102, 178),
      simde_x_mm_set_pu16(0, 0, 0, 427) },
    { simde_x_mm_set_pu8( 77, 112,  20, 247, 206, 117, 128, 107),
      simde_x_mm_set_pu8(189, 223, 203, 181,  71, 239,  64, 186),
      simde_x_mm_set_pu16(0, 0, 0, 872) },
    { simde_x_mm_set_pu8(128, 104,  93, 138, 250, 105, 219, 255),
      simde_x_mm_set_pu8(113, 248, 217,  59,  72,   4, 165,  83),
      simde_x_mm_set_pu16(0, 0, 0, 867) },
    { simde_x_mm_set_pu8(143,  12,  71,  81, 251, 175,  44, 206),
      simde_x_mm_set_pu8( 80, 100, 129,  82,  59,  63,  26,  22),
      simde_x_mm_set_pu16(0, 0, 0, 716) },
    { simde_x_mm_set_pu8(  7, 202, 222,  71, 138,  18, 223,  92),
      simde_x_mm_set_pu8(208, 174,  15, 221,  13,  93, 209, 116),
      simde_x_mm_set_pu16(0, 0, 0, 824) },
    { simde_x_mm_set_pu8( 92, 133, 132,   0,  24, 132, 201, 186),
      simde_x_mm_set_pu8(194,  29, 160,  58,  50,  10,  65, 234),
      simde_x_mm_set_pu16(0, 0, 0, 624) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_sad_pu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_u16(r, ==, test_vec[i].r);
  }

  simde_mm_empty();
  return MUNIT_OK;
}

static MunitResult
test_simde_mm_shuffle_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16( 20374,  -8020,   9831, -21724),
      simde_mm_set_pi16(-21724, -21724,   9831,   9831) },
    { simde_mm_set_pi16( 26825,   6867,  -1457,  28819),
      simde_mm_set_pi16( 28819,  28819,  -1457,  -1457) },
    { simde_mm_set_pi16( -4347, -12641,  -8333, -18450),
      simde_mm_set_pi16(-18450, -18450,  -8333,  -8333) },
    { simde_mm_set_pi16( 22439,  23179, -32421,  -3266),
      simde_mm_set_pi16( -3266,  -3266, -32421, -32421) },
    { simde_mm_set_pi16(  9337,  -3310,  22225, -14472),
      simde_mm_set_pi16(-14472, -14472,  22225,  22225) },
    { simde_mm_set_pi16(-17114, -15656,  26827,  -1486),
      simde_mm_set_pi16( -1486,  -1486,  26827,  26827) },
    { simde_mm_set_pi16(  8123,   8758,  31545,  -8216),
      simde_mm_set_pi16( -8216,  -8216,  31545,  31545) },
    { simde_mm_set_pi16(-32324,  31163,  -3386,  23646),
      simde_mm_set_pi16( 23646,  23646,  -3386,  -3386) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r = simde_mm_shuffle_pi16(test_vec[i].a, 5);
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_shuffle_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 387.45f, -469.79f,  719.43f,  371.94f),
      simde_mm_set_ps( 641.56f,  341.35f,  292.84f,  441.22f),
      simde_mm_set_ps( 441.22f,  441.22f, -469.79f,  387.45f) },
    { simde_mm_set_ps( 648.82f,  641.81f, -789.10f,  982.80f),
      simde_mm_set_ps( 472.27f, -304.33f,  524.09f, -589.31f),
      simde_mm_set_ps(-589.31f, -589.31f,  641.81f,  648.82f) },
    { simde_mm_set_ps(-163.67f, -311.30f, -600.60f,  597.71f),
      simde_mm_set_ps(-247.76f,  246.42f, -742.25f,  -20.93f),
      simde_mm_set_ps( -20.93f,  -20.93f, -311.30f, -163.67f) },
    { simde_mm_set_ps( 968.74f,  810.41f, -699.53f,  224.20f),
      simde_mm_set_ps(-966.41f,  917.94f, -300.26f,   64.06f),
      simde_mm_set_ps(  64.06f,   64.06f,  810.41f,  968.74f) },
    { simde_mm_set_ps(  99.15f,  957.94f,  380.12f, -611.50f),
      simde_mm_set_ps( -77.49f, -255.84f,  787.35f, -671.91f),
      simde_mm_set_ps(-671.91f, -671.91f,  957.94f,   99.15f) },
    { simde_mm_set_ps(-280.55f, -182.50f,  340.17f,  473.64f),
      simde_mm_set_ps(  -3.29f, -413.78f, -406.24f,  521.82f),
      simde_mm_set_ps( 521.82f,  521.82f, -182.50f, -280.55f) },
    { simde_mm_set_ps(-677.92f,  481.01f,  494.26f,  565.24f),
      simde_mm_set_ps( 205.66f,  769.40f, -900.58f, -847.82f),
      simde_mm_set_ps(-847.82f, -847.82f,  481.01f, -677.92f) },
    { simde_mm_set_ps( 703.71f,  397.64f,  773.55f, -739.53f),
      simde_mm_set_ps(  99.18f, -932.61f, -902.04f,  169.61f),
      simde_mm_set_ps( 169.61f,  169.61f,  397.64f,  703.71f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_shuffle_ps(test_vec[i].a, test_vec[i].b, 11);
    simde_assert_m128_f32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sqrt_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 407.59f,  875.44f,  929.81f,  658.11f),
      simde_mm_set_ps(  20.19f,   29.59f,   30.49f,   25.65f) },
    { simde_mm_set_ps( 511.62f,  750.84f,  820.58f,  601.07f),
      simde_mm_set_ps(  22.62f,   27.40f,   28.65f,   24.52f) },
    { simde_mm_set_ps(  67.49f,  303.60f,  282.76f,  795.53f),
      simde_mm_set_ps(   8.22f,   17.42f,   16.82f,   28.21f) },
    { simde_mm_set_ps( 777.54f,   62.15f,  901.98f,  524.87f),
      simde_mm_set_ps(  27.88f,    7.88f,   30.03f,   22.91f) },
    { simde_mm_set_ps( 397.99f,  291.75f,  558.37f,  417.44f),
      simde_mm_set_ps(  19.95f,   17.08f,   23.63f,   20.43f) },
    { simde_mm_set_ps( 855.95f,  696.25f,  826.76f,  664.95f),
      simde_mm_set_ps(  29.26f,   26.39f,   28.75f,   25.79f) },
    { simde_mm_set_ps( 435.38f,  218.65f,  679.39f,  587.73f),
      simde_mm_set_ps(  20.87f,   14.79f,   26.07f,   24.24f) },
    { simde_mm_set_ps( 384.56f,  314.94f,   34.58f,   10.06f),
      simde_mm_set_ps(  19.61f,   17.75f,    5.88f,    3.17f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_sqrt_ps(test_vec[i].a);
    simde_assert_m128_f32_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sqrt_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 619.69f,  412.13f,  497.92f,  538.00f),
      simde_mm_set_ps( 619.69f,  412.13f,  497.92f,   23.19f) },
    { simde_mm_set_ps( 620.13f,  731.84f,  667.03f,  801.31f),
      simde_mm_set_ps( 620.13f,  731.84f,  667.03f,   28.31f) },
    { simde_mm_set_ps( 720.02f,  314.91f,  596.04f,  727.65f),
      simde_mm_set_ps( 720.02f,  314.91f,  596.04f,   26.97f) },
    { simde_mm_set_ps( 888.04f,  213.48f,  907.68f,  515.93f),
      simde_mm_set_ps( 888.04f,  213.48f,  907.68f,   22.71f) },
    { simde_mm_set_ps( 196.63f,  888.92f,  163.58f,  421.90f),
      simde_mm_set_ps( 196.63f,  888.92f,  163.58f,   20.54f) },
    { simde_mm_set_ps( 966.24f,  260.28f,  707.39f,  467.81f),
      simde_mm_set_ps( 966.24f,  260.28f,  707.39f,   21.63f) },
    { simde_mm_set_ps( 762.80f,  805.99f,  106.70f,  460.44f),
      simde_mm_set_ps( 762.80f,  805.99f,  106.70f,   21.46f) },
    { simde_mm_set_ps( 398.96f,  926.80f,  642.37f,  392.46f),
      simde_mm_set_ps( 398.96f,  926.80f,  642.37f,   19.81f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_sqrt_ss(test_vec[i].a);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_store_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde_float32 r[4];
  } test_vec[8] = {
    { simde_mm_set_ps( 797.84f,  342.63f,  173.26f,  427.65f),
      {  427.65f,  173.26f,  342.63f,  797.84f } },
    { simde_mm_set_ps( 911.58f,  127.96f,   79.17f,    4.20f),
      {    4.20f,   79.17f,  127.96f,  911.58f } },
    { simde_mm_set_ps( 206.93f,  418.54f,  921.68f,  840.36f),
      {  840.36f,  921.68f,  418.54f,  206.93f } },
    { simde_mm_set_ps( 692.59f,   90.67f,  787.67f,  591.30f),
      {  591.30f,  787.67f,   90.67f,  692.59f } },
    { simde_mm_set_ps(  57.64f,   25.24f,  486.10f,  797.60f),
      {  797.60f,  486.10f,   25.24f,   57.64f } },
    { simde_mm_set_ps( 987.53f,  693.84f,  633.62f,  186.39f),
      {  186.39f,  633.62f,  693.84f,  987.53f } },
    { simde_mm_set_ps( 772.05f,  227.52f,  175.91f,  879.34f),
      {  879.34f,  175.91f,  227.52f,  772.05f } },
    { simde_mm_set_ps( 640.49f,  596.15f,  891.32f,   37.15f),
      {   37.15f,  891.32f,  596.15f,  640.49f } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_float32 r[4];
    simde_mm_store_ps(r, test_vec[i].a);
    for (size_t j = 0 ; j < 4 ; j++) {
      munit_assert_float(r[j], ==, test_vec[i].r[j]);
    }
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_store_ps1(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde_float32 r[4];
  } test_vec[8] = {
    { simde_mm_set_ps( 854.57f,  299.85f,   53.35f,  467.01f),
      {  467.01f,  467.01f,  467.01f,  467.01f } },
    { simde_mm_set_ps( 477.02f,  854.94f,  677.55f,  339.79f),
      {  339.79f,  339.79f,  339.79f,  339.79f } },
    { simde_mm_set_ps( 736.99f,  148.01f,  536.77f,  621.38f),
      {  621.38f,  621.38f,  621.38f,  621.38f } },
    { simde_mm_set_ps( 947.26f,  901.13f,  502.63f,  117.54f),
      {  117.54f,  117.54f,  117.54f,  117.54f } },
    { simde_mm_set_ps( 193.39f,  545.92f,  514.75f,  687.45f),
      {  687.45f,  687.45f,  687.45f,  687.45f } },
    { simde_mm_set_ps( 844.08f,  252.82f,  783.61f,  372.00f),
      {  372.00f,  372.00f,  372.00f,  372.00f } },
    { simde_mm_set_ps( 988.23f,  778.23f,  199.92f,  424.51f),
      {  424.51f,  424.51f,  424.51f,  424.51f } },
    { simde_mm_set_ps( 515.70f,  944.74f,  777.26f,  470.44f),
      {  470.44f,  470.44f,  470.44f,  470.44f } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_float32 r[4];
    simde_mm_store_ps1(r, test_vec[i].a);
    for (size_t j = 0 ; j < 4 ; j++) {
      munit_assert_float(r[j], ==, test_vec[i].r[j]);
    }
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_store_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde_float32 r[4];
  } test_vec[8] = {
    { simde_mm_set_ps( 854.57f,  299.85f,   53.35f,  467.01f),
      {  467.01f,    0.00f,    0.00f,    0.00f } },
    { simde_mm_set_ps( 477.02f,  854.94f,  677.55f,  339.79f),
      {  339.79f,    0.00f,    0.00f,    0.00f } },
    { simde_mm_set_ps( 736.99f,  148.01f,  536.77f,  621.38f),
      {  621.38f,    0.00f,    0.00f,    0.00f } },
    { simde_mm_set_ps( 947.26f,  901.13f,  502.63f,  117.54f),
      {  117.54f,    0.00f,    0.00f,    0.00f } },
    { simde_mm_set_ps( 193.39f,  545.92f,  514.75f,  687.45f),
      {  687.45f,    0.00f,    0.00f,    0.00f } },
    { simde_mm_set_ps( 844.08f,  252.82f,  783.61f,  372.00f),
      {  372.00f,    0.00f,    0.00f,    0.00f } },
    { simde_mm_set_ps( 988.23f,  778.23f,  199.92f,  424.51f),
      {  424.51f,    0.00f,    0.00f,    0.00f } },
    { simde_mm_set_ps( 515.70f,  944.74f,  777.26f,  470.44f),
      {  470.44f,    0.00f,    0.00f,    0.00f } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_float32 r[4] = { 0, };
    simde_mm_store_ss(r, test_vec[i].a);
    for (size_t j = 0 ; j < 4 ; j++) {
      munit_assert_float(r[j], ==, test_vec[i].r[j]);
    }
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_store1_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde_float32 r[4];
  } test_vec[8] = {
    { simde_mm_set_ps( 274.23f,   89.27f,  784.72f,  646.53f),
      {  646.53f,  646.53f,  646.53f,  646.53f } },
    { simde_mm_set_ps( 322.23f,  913.84f,  883.41f,  484.76f),
      {  484.76f,  484.76f,  484.76f,  484.76f } },
    { simde_mm_set_ps( 272.81f,  739.51f,  776.03f,   57.85f),
      {   57.85f,   57.85f,   57.85f,   57.85f } },
    { simde_mm_set_ps( 414.64f,  733.36f,  680.70f,  973.86f),
      {  973.86f,  973.86f,  973.86f,  973.86f } },
    { simde_mm_set_ps( 541.43f,  860.27f,  162.49f,  726.46f),
      {  726.46f,  726.46f,  726.46f,  726.46f } },
    { simde_mm_set_ps( 735.30f,  924.35f,   18.46f,  634.38f),
      {  634.38f,  634.38f,  634.38f,  634.38f } },
    { simde_mm_set_ps( 676.23f,   61.60f,   24.97f,  803.79f),
      {  803.79f,  803.79f,  803.79f,  803.79f } },
    { simde_mm_set_ps( 373.81f,  509.18f,  233.96f,  910.43f),
      {  910.43f,  910.43f,  910.43f,  910.43f } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_float32 r[4] = { 0, };
    simde_mm_store1_ps(r, test_vec[i].a);
    for (size_t j = 0 ; j < 4 ; j++) {
      munit_assert_float(r[j], ==, test_vec[i].r[j]);
    }
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_storeh_pi(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 575.54f,  220.03f,  206.01f,  870.81f),
      { .f32 = {  220.03f,  575.54f } } },
    { simde_mm_set_ps( 289.58f,  629.51f,  767.25f,  704.01f),
      { .f32 = {  629.51f,  289.58f } } },
    { simde_mm_set_ps( 627.14f,  949.08f,  581.33f,  434.65f),
      { .f32 = {  949.08f,  627.14f } } },
    { simde_mm_set_ps( 369.75f,  459.24f,  702.99f,   90.66f),
      { .f32 = {  459.24f,  369.75f } } },
    { simde_mm_set_ps(  57.99f,  910.00f,  605.74f,   76.21f),
      { .f32 = {  910.00f,   57.99f } } },
    { simde_mm_set_ps( 918.98f,  456.74f,  224.68f,  627.20f),
      { .f32 = {  456.74f,  918.98f } } },
    { simde_mm_set_ps( 963.09f,  356.12f,   33.23f,  995.23f),
      { .f32 = {  356.12f,  963.09f } } },
    { simde_mm_set_ps( 967.89f,  231.25f,  230.84f,  538.31f),
      { .f32 = {  231.25f,  967.89f } } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r;
    simde_mm_storeh_pi(&r, test_vec[i].a);
    for (size_t j = 0 ; j < 2 ; j++) {
      munit_assert_float(r.f32[j], ==, test_vec[i].r.f32[j]);
    }
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_storel_pi(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_ps( 258.22f,  461.17f,  500.19f,  792.00f),
      { .f32 = {  792.00f,  500.19f } } },
    { simde_mm_set_ps( 839.05f,  239.15f,  886.65f,  576.97f),
      { .f32 = {  576.97f,  886.65f } } },
    { simde_mm_set_ps( 905.98f,  580.29f,   37.85f,  782.47f),
      { .f32 = {  782.47f,   37.85f } } },
    { simde_mm_set_ps( 367.06f,  905.12f,  385.52f,  288.25f),
      { .f32 = {  288.25f,  385.52f } } },
    { simde_mm_set_ps( 345.47f,   91.39f,  757.41f,  177.58f),
      { .f32 = {  177.58f,  757.41f } } },
    { simde_mm_set_ps(  41.60f,  601.66f,  873.51f,  499.62f),
      { .f32 = {  499.62f,  873.51f } } },
    { simde_mm_set_ps( 185.64f,  301.30f,   85.92f,  684.99f),
      { .f32 = {  684.99f,   85.92f } } },
    { simde_mm_set_ps( 556.83f,  958.68f,  557.15f,  788.14f),
      { .f32 = {  788.14f,  557.15f } } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r;
    simde_mm_storel_pi(&r, test_vec[i].a);
    for (size_t j = 0 ; j < 2 ; j++) {
      munit_assert_float(r.f32[j], ==, test_vec[i].r.f32[j]);
    }
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_storer_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde_float32 r[4];
  } test_vec[8] = {
    { simde_mm_set_ps( 709.97f,  746.23f,  453.60f,  303.28f),
      {  709.97f,  746.23f,  453.60f,  303.28f } },
    { simde_mm_set_ps( 764.16f,  229.13f,  431.64f,  384.08f),
      {  764.16f,  229.13f,  431.64f,  384.08f } },
    { simde_mm_set_ps( 237.88f,  156.25f,  582.89f,   91.67f),
      {  237.88f,  156.25f,  582.89f,   91.67f } },
    { simde_mm_set_ps( 244.82f,   86.89f,  868.91f,  106.59f),
      {  244.82f,   86.89f,  868.91f,  106.59f } },
    { simde_mm_set_ps( 570.53f,  397.46f,  850.83f,  961.86f),
      {  570.53f,  397.46f,  850.83f,  961.86f } },
    { simde_mm_set_ps( 946.89f,  801.12f,  881.81f,  752.94f),
      {  946.89f,  801.12f,  881.81f,  752.94f } },
    { simde_mm_set_ps( 779.85f,   31.75f,  218.17f,  299.71f),
      {  779.85f,   31.75f,  218.17f,  299.71f } },
    { simde_mm_set_ps( 409.61f,  712.65f,  619.44f,  952.97f),
      {  409.61f,  712.65f,  619.44f,  952.97f } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_float32 r[4] = { 0, };
    simde_mm_storer_ps(r, test_vec[i].a);
    for (size_t j = 0 ; j < 4 ; j++) {
      munit_assert_float(r[j], ==, test_vec[i].r[j]);
    }
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_storeu_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde_float32 r[4];
  } test_vec[8] = {
    { simde_mm_set_ps( 304.73f,  535.11f,   34.80f,  759.84f),
      {  759.84f,   34.80f,  535.11f,  304.73f } },
    { simde_mm_set_ps( 360.59f,  120.47f,  501.36f,  116.79f),
      {  116.79f,  501.36f,  120.47f,  360.59f } },
    { simde_mm_set_ps( 709.31f,  269.06f,  586.46f,  622.65f),
      {  622.65f,  586.46f,  269.06f,  709.31f } },
    { simde_mm_set_ps( 653.72f,  295.37f,   94.24f,  886.62f),
      {  886.62f,   94.24f,  295.37f,  653.72f } },
    { simde_mm_set_ps(   4.93f,  676.49f,  303.89f,  920.73f),
      {  920.73f,  303.89f,  676.49f,    4.93f } },
    { simde_mm_set_ps( 930.44f,  841.16f,  891.12f,  349.34f),
      {  349.34f,  891.12f,  841.16f,  930.44f } },
    { simde_mm_set_ps( 899.13f,  242.56f,  161.77f,   99.90f),
      {   99.90f,  161.77f,  242.56f,  899.13f } },
    { simde_mm_set_ps( 350.94f,  738.74f,  750.24f,  329.42f),
      {  329.42f,  750.24f,  738.74f,  350.94f } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_float32 r[4] = { 0, };
    simde_mm_storeu_ps(r, test_vec[i].a);
    for (size_t j = 0 ; j < 4 ; j++) {
      munit_assert_float(r[j], ==, test_vec[i].r[j]);
    }
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sub_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-670.13f, -257.04f,  449.06f,  965.86f),
      simde_mm_set_ps(-637.34f,  741.89f,  -14.02f,  918.72f),
      simde_mm_set_ps( -32.80f, -998.93f,  463.07f,   47.13f) },
    { simde_mm_set_ps(-744.89f,  -52.84f,  460.90f,  134.66f),
      simde_mm_set_ps( 177.89f, -904.94f,  443.55f, -742.83f),
      simde_mm_set_ps(-922.78f,  852.10f,   17.35f,  877.49f) },
    { simde_mm_set_ps( 807.56f,  945.11f,  259.44f,  557.41f),
      simde_mm_set_ps( 404.99f,  399.93f,  -68.79f,  957.61f),
      simde_mm_set_ps( 402.57f,  545.19f,  328.23f, -400.20f) },
    { simde_mm_set_ps(  74.77f,  473.53f, -483.74f,  415.65f),
      simde_mm_set_ps(-608.38f,  553.08f, -146.88f,   64.98f),
      simde_mm_set_ps( 683.15f,  -79.55f, -336.86f,  350.67f) },
    { simde_mm_set_ps( 879.68f, -763.80f,  -53.30f,   95.40f),
      simde_mm_set_ps( 164.85f,  427.62f,  174.59f,  925.02f),
      simde_mm_set_ps( 714.82f, -1191.42f, -227.89f, -829.62f) },
    { simde_mm_set_ps( 571.32f,  207.75f,  439.31f, -973.48f),
      simde_mm_set_ps(-719.88f, -346.38f, -249.12f, -239.62f),
      simde_mm_set_ps(1291.20f,  554.13f,  688.43f, -733.86f) },
    { simde_mm_set_ps( 995.34f, -761.80f, -600.36f,  665.89f),
      simde_mm_set_ps( 578.64f, -853.98f,  329.02f, -360.51f),
      simde_mm_set_ps( 416.70f,   92.18f, -929.38f, 1026.41f) },
    { simde_mm_set_ps(-961.63f,  818.44f, -364.30f, -740.41f),
      simde_mm_set_ps(  86.59f,  540.64f,  243.58f,  458.04f),
      simde_mm_set_ps(-1048.22f,  277.80f, -607.89f, -1198.46f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_sub_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sub_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-670.13f, -257.04f,  449.06f,  965.86f),
      simde_mm_set_ps(-637.34f,  741.89f,  -14.02f,  918.72f),
      simde_mm_set_ps(-670.13f, -257.04f,  449.06f,   47.13f) },
    { simde_mm_set_ps(-744.89f,  -52.84f,  460.90f,  134.66f),
      simde_mm_set_ps( 177.89f, -904.94f,  443.55f, -742.83f),
      simde_mm_set_ps(-744.89f,  -52.84f,  460.90f,  877.49f) },
    { simde_mm_set_ps( 807.56f,  945.11f,  259.44f,  557.41f),
      simde_mm_set_ps( 404.99f,  399.93f,  -68.79f,  957.61f),
      simde_mm_set_ps( 807.56f,  945.11f,  259.44f, -400.20f) },
    { simde_mm_set_ps(  74.77f,  473.53f, -483.74f,  415.65f),
      simde_mm_set_ps(-608.38f,  553.08f, -146.88f,   64.98f),
      simde_mm_set_ps(  74.77f,  473.53f, -483.74f,  350.67f) },
    { simde_mm_set_ps( 879.68f, -763.80f,  -53.30f,   95.40f),
      simde_mm_set_ps( 164.85f,  427.62f,  174.59f,  925.02f),
      simde_mm_set_ps( 879.68f, -763.80f,  -53.30f, -829.62f) },
    { simde_mm_set_ps( 571.32f,  207.75f,  439.31f, -973.48f),
      simde_mm_set_ps(-719.88f, -346.38f, -249.12f, -239.62f),
      simde_mm_set_ps( 571.32f,  207.75f,  439.31f, -733.86f) },
    { simde_mm_set_ps( 995.34f, -761.80f, -600.36f,  665.89f),
      simde_mm_set_ps( 578.64f, -853.98f,  329.02f, -360.51f),
      simde_mm_set_ps( 995.34f, -761.80f, -600.36f, 1026.41f) },
    { simde_mm_set_ps(-961.63f,  818.44f, -364.30f, -740.41f),
      simde_mm_set_ps(  86.59f,  540.64f,  243.58f,  458.04f),
      simde_mm_set_ps(-961.63f,  818.44f, -364.30f, -1198.46f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_sub_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_ucomieq_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.4193f, 0.8439f, 0.8100f, 0.2669f),
      simde_mm_set_ps(0.4193f, 0.8439f, 0.8100f, 0.2669f),
      1 },
    { simde_mm_set_ps(0.9426f, 0.1679f, 0.2845f, 0.1698f),
      simde_mm_set_ps(0.9426f, 0.6931f, 0.2845f, 0.1698f),
      1 },
    { simde_mm_set_ps(0.0547f, 0.2368f, 0.3365f, 0.9146f),
      simde_mm_set_ps(0.0547f, 0.5935f, 0.3365f, 0.5014f),
      0 },
    { simde_mm_set_ps(0.7179f, 0.8607f, 0.4372f, 0.6140f),
      simde_mm_set_ps(0.7179f, 0.7239f, 0.4372f, 0.6140f),
      1 },
    { simde_mm_set_ps(0.4474f, 0.6848f, 0.4305f, 0.8738f),
      simde_mm_set_ps(0.6059f, 0.8463f, 0.4305f, 0.1517f),
      0 },
    { simde_mm_set_ps(0.4537f, 0.7254f, 0.9987f, 0.9115f),
      simde_mm_set_ps(0.1771f, 0.2982f, 0.9987f, 0.9003f),
      0 },
    { simde_mm_set_ps(0.2162f, 0.6303f, 0.0602f, 0.9986f),
      simde_mm_set_ps(0.2162f, 0.5872f, 0.0602f, 0.2491f),
      0 },
    { simde_mm_set_ps(0.4836f, 0.9929f, 0.8942f, 0.2367f),
      simde_mm_set_ps(0.4836f, 0.9929f, 0.4202f, 0.2367f),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_ucomieq_ss(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_ucomige_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      1 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      0 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      1 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      1 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      0 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      0 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      1 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_ucomige_ss(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_ucomigt_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      1 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      0 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      1 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      0 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      0 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      0 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      0 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_ucomigt_ss(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_ucomile_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      0 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      1 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      0 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      1 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      1 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      1 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      1 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_ucomile_ss(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_ucomilt_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      0 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      1 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      0 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      0 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      1 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      1 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      0 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_ucomilt_ss(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_ucomineq_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(0.1174f, 0.9995f, 0.7362f, 0.9966f),
      simde_mm_set_ps(0.1174f, 0.5850f, 0.0225f, 0.0035f),
      1 },
    { simde_mm_set_ps(0.6820f, 0.9892f, 0.6235f, 0.1819f),
      simde_mm_set_ps(0.0898f, 0.9892f, 0.6235f, 0.3305f),
      1 },
    { simde_mm_set_ps(0.7152f, 0.9286f, 0.9635f, 0.8823f),
      simde_mm_set_ps(0.3403f, 0.4177f, 0.9635f, 0.8737f),
      1 },
    { simde_mm_set_ps(0.5619f, 0.6892f, 0.2137f, 0.5336f),
      simde_mm_set_ps(0.1340f, 0.0152f, 0.9280f, 0.5336f),
      0 },
    { simde_mm_set_ps(0.5476f, 0.8606f, 0.2177f, 0.5284f),
      simde_mm_set_ps(0.5476f, 0.6253f, 0.1285f, 0.7135f),
      1 },
    { simde_mm_set_ps(0.6649f, 0.2053f, 0.5053f, 0.0378f),
      simde_mm_set_ps(0.0308f, 0.2053f, 0.5053f, 0.8789f),
      1 },
    { simde_mm_set_ps(0.3714f, 0.8736f, 0.8711f, 0.9491f),
      simde_mm_set_ps(0.8296f, 0.2212f, 0.5986f, 0.9491f),
      0 },
    { simde_mm_set_ps(0.8791f, 0.5862f, 0.4977f, 0.0888f),
      simde_mm_set_ps(0.8669f, 0.7545f, 0.4977f, 0.0888f),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    int r = simde_mm_ucomineq_ss(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpackhi_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-756.38f, -450.47f,  901.78f,  859.60f),
      simde_mm_set_ps( -17.95f, -383.47f,  601.72f,  328.61f),
      simde_mm_set_ps( -17.95f, -756.38f, -383.47f, -450.47f) },
    { simde_mm_set_ps(-696.67f, -318.67f, -746.84f,  486.97f),
      simde_mm_set_ps(  76.54f, -173.13f,  775.95f,  744.80f),
      simde_mm_set_ps(  76.54f, -696.67f, -173.13f, -318.67f) },
    { simde_mm_set_ps(-181.38f,  -64.52f, -525.50f,  383.47f),
      simde_mm_set_ps(-830.80f,  462.90f,  208.76f, -840.43f),
      simde_mm_set_ps(-830.80f, -181.38f,  462.90f,  -64.52f) },
    { simde_mm_set_ps(-437.50f, -751.51f, -255.04f,  713.97f),
      simde_mm_set_ps(-835.16f,  838.19f, -968.67f, -800.39f),
      simde_mm_set_ps(-835.16f, -437.50f,  838.19f, -751.51f) },
    { simde_mm_set_ps( 252.51f,  219.43f,  234.16f,  718.42f),
      simde_mm_set_ps( 737.55f, -360.52f,  129.47f,  866.75f),
      simde_mm_set_ps( 737.55f,  252.51f, -360.52f,  219.43f) },
    { simde_mm_set_ps(-543.89f,  -12.39f,  996.39f, -521.27f),
      simde_mm_set_ps(-330.73f, -334.66f,  798.87f, -360.08f),
      simde_mm_set_ps(-330.73f, -543.89f, -334.66f,  -12.39f) },
    { simde_mm_set_ps( 633.16f,  239.27f,  625.35f,  330.43f),
      simde_mm_set_ps(-890.86f,  495.17f, -524.21f,  275.19f),
      simde_mm_set_ps(-890.86f,  633.16f,  495.17f,  239.27f) },
    { simde_mm_set_ps(-443.30f, -851.22f,  842.49f,  697.77f),
      simde_mm_set_ps(   8.81f, -953.12f,   -1.45f, -983.63f),
      simde_mm_set_ps(   8.81f, -443.30f, -953.12f, -851.22f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_unpackhi_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_unpacklo_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(-756.38f, -450.47f,  901.78f,  859.60f),
      simde_mm_set_ps( -17.95f, -383.47f,  601.72f,  328.61f),
      simde_mm_set_ps( 601.72f,  901.78f,  328.61f,  859.60f) },
    { simde_mm_set_ps(-696.67f, -318.67f, -746.84f,  486.97f),
      simde_mm_set_ps(  76.54f, -173.13f,  775.95f,  744.80f),
      simde_mm_set_ps( 775.95f, -746.84f,  744.80f,  486.97f) },
    { simde_mm_set_ps(-181.38f,  -64.52f, -525.50f,  383.47f),
      simde_mm_set_ps(-830.80f,  462.90f,  208.76f, -840.43f),
      simde_mm_set_ps( 208.76f, -525.50f, -840.43f,  383.47f) },
    { simde_mm_set_ps(-437.50f, -751.51f, -255.04f,  713.97f),
      simde_mm_set_ps(-835.16f,  838.19f, -968.67f, -800.39f),
      simde_mm_set_ps(-968.67f, -255.04f, -800.39f,  713.97f) },
    { simde_mm_set_ps( 252.51f,  219.43f,  234.16f,  718.42f),
      simde_mm_set_ps( 737.55f, -360.52f,  129.47f,  866.75f),
      simde_mm_set_ps( 129.47f,  234.16f,  866.75f,  718.42f) },
    { simde_mm_set_ps(-543.89f,  -12.39f,  996.39f, -521.27f),
      simde_mm_set_ps(-330.73f, -334.66f,  798.87f, -360.08f),
      simde_mm_set_ps( 798.87f,  996.39f, -360.08f, -521.27f) },
    { simde_mm_set_ps( 633.16f,  239.27f,  625.35f,  330.43f),
      simde_mm_set_ps(-890.86f,  495.17f, -524.21f,  275.19f),
      simde_mm_set_ps(-524.21f,  625.35f,  275.19f,  330.43f) },
    { simde_mm_set_ps(-443.30f, -851.22f,  842.49f,  697.77f),
      simde_mm_set_ps(   8.81f, -953.12f,   -1.45f, -983.63f),
      simde_mm_set_ps(  -1.45f,  842.49f, -983.63f,  697.77f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_unpacklo_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xor_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_m128_set_u32(UINT32_C(0x024f4584), UINT32_C(0xa17da0be), UINT32_C(0x58a7e615), UINT32_C(0x4a3b7e6a)),
      simde_m128_set_u32(UINT32_C(0x48d3d04c), UINT32_C(0xdc574d32), UINT32_C(0x6c3bc006), UINT32_C(0xc8120e07)),
      simde_m128_set_u32(UINT32_C(0x4a9c95c8), UINT32_C(0x7d2aed8c), UINT32_C(0x349c2613), UINT32_C(0x8229706d)) },
    { simde_m128_set_u32(UINT32_C(0x430ea8b4), UINT32_C(0x2c6e1c1f), UINT32_C(0x4634b744), UINT32_C(0xc1a535c3)),
      simde_m128_set_u32(UINT32_C(0x2ebc830c), UINT32_C(0x09ff7c77), UINT32_C(0xb03e6975), UINT32_C(0x3b6351c2)),
      simde_m128_set_u32(UINT32_C(0x6db22bb8), UINT32_C(0x25916068), UINT32_C(0xf60ade31), UINT32_C(0xfac66401)) },
    { simde_m128_set_u32(UINT32_C(0xc2025c69), UINT32_C(0xb9a74036), UINT32_C(0x7a940029), UINT32_C(0x0ba4d901)),
      simde_m128_set_u32(UINT32_C(0xc3fc959c), UINT32_C(0x59083db4), UINT32_C(0x915055e4), UINT32_C(0x5dbf7703)),
      simde_m128_set_u32(UINT32_C(0x01fec9f5), UINT32_C(0xe0af7d82), UINT32_C(0xebc455cd), UINT32_C(0x561bae02)) },
    { simde_m128_set_u32(UINT32_C(0xf802d7d5), UINT32_C(0xed34ed1c), UINT32_C(0x9d828497), UINT32_C(0xc6637f1f)),
      simde_m128_set_u32(UINT32_C(0xdba38586), UINT32_C(0x7071b51f), UINT32_C(0xcac3fcc0), UINT32_C(0x8f7eb2d1)),
      simde_m128_set_u32(UINT32_C(0x23a15253), UINT32_C(0x9d455803), UINT32_C(0x57417857), UINT32_C(0x491dcdce)) },
    { simde_m128_set_u32(UINT32_C(0x79606c79), UINT32_C(0xf71d7967), UINT32_C(0xada55028), UINT32_C(0xb78eeb2e)),
      simde_m128_set_u32(UINT32_C(0x69d0518e), UINT32_C(0x2752e0c6), UINT32_C(0x3f450894), UINT32_C(0x77f477b4)),
      simde_m128_set_u32(UINT32_C(0x10b03df7), UINT32_C(0xd04f99a1), UINT32_C(0x92e058bc), UINT32_C(0xc07a9c9a)) },
    { simde_m128_set_u32(UINT32_C(0x441b98db), UINT32_C(0xe94eb7e6), UINT32_C(0xb63975b0), UINT32_C(0x3d68f9d5)),
      simde_m128_set_u32(UINT32_C(0x26f600f1), UINT32_C(0x5d69ebb6), UINT32_C(0x58f8ec40), UINT32_C(0xae6e3695)),
      simde_m128_set_u32(UINT32_C(0x62ed982a), UINT32_C(0xb4275c50), UINT32_C(0xeec199f0), UINT32_C(0x9306cf40)) },
    { simde_m128_set_u32(UINT32_C(0xdd0bf52e), UINT32_C(0x1aac98e2), UINT32_C(0x9f63c82f), UINT32_C(0x9e5b5bfb)),
      simde_m128_set_u32(UINT32_C(0xb98fae38), UINT32_C(0xf9bff81d), UINT32_C(0x54613b0c), UINT32_C(0x2d9c5cba)),
      simde_m128_set_u32(UINT32_C(0x64845b16), UINT32_C(0xe31360ff), UINT32_C(0xcb02f323), UINT32_C(0xb3c70741)) },
    { simde_m128_set_u32(UINT32_C(0xba2156c4), UINT32_C(0xdb2aa6aa), UINT32_C(0xd67bed5a), UINT32_C(0xdab4319d)),
      simde_m128_set_u32(UINT32_C(0xc2c3ccf5), UINT32_C(0xabb0afdd), UINT32_C(0x96fd5dd6), UINT32_C(0xa2b25a76)),
      simde_m128_set_u32(UINT32_C(0x78e29a31), UINT32_C(0x709a0977), UINT32_C(0x4086b08c), UINT32_C(0x78066beb)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 r = simde_mm_xor_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_stream_pi(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(  6761, -22445, -23476, -30705),
      simde_mm_set_pi16(  6761, -22445, -23476, -30705) },
    { simde_mm_set_pi16( 19012, -30608,  30482, -20411),
      simde_mm_set_pi16( 19012, -30608,  30482, -20411) },
    { simde_mm_set_pi16( 23487, -28638,  -4660,  -3430),
      simde_mm_set_pi16( 23487, -28638,  -4660,  -3430) },
    { simde_mm_set_pi16( -9884,  -9588,  -4377, -27077),
      simde_mm_set_pi16( -9884,  -9588,  -4377, -27077) },
    { simde_mm_set_pi16( 15488, -17321,   2333,   8745),
      simde_mm_set_pi16( 15488, -17321,   2333,   8745) },
    { simde_mm_set_pi16( 30278,   5796, -17311,  13106),
      simde_mm_set_pi16( 30278,   5796, -17311,  13106) },
    { simde_mm_set_pi16(-18652,  26507,  -8174,  31557),
      simde_mm_set_pi16(-18652,  26507,  -8174,  31557) },
    { simde_mm_set_pi16(-16725,  22668,   9074,   1013),
      simde_mm_set_pi16(-16725,  22668,   9074,   1013) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 r;
    simde_mm_stream_pi(&r, test_vec[i].a);
    munit_assert_int64(r.i64[0], ==, test_vec[i].r.i64[0]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_stream_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde_float32 r[4];
  } test_vec[8] = {
    { simde_mm_set_ps(-386.97f,  492.19f,  318.83f,  345.85f),
      {  345.85f,  318.83f,  492.19f, -386.97f } },
    { simde_mm_set_ps( 908.43f,  787.88f, -776.77f, -773.68f),
      { -773.68f, -776.77f,  787.88f,  908.43f } },
    { simde_mm_set_ps( 241.81f,  684.64f, -474.83f,  614.26f),
      {  614.26f, -474.83f,  684.64f,  241.81f } },
    { simde_mm_set_ps(-327.50f, -550.14f, -266.51f, -677.19f),
      { -677.19f, -266.51f, -550.14f, -327.50f } },
    { simde_mm_set_ps( 706.39f, -425.59f,  678.55f, -877.83f),
      { -877.83f,  678.55f, -425.59f,  706.39f } },
    { simde_mm_set_ps( 902.50f,  144.03f,  -93.04f,  995.74f),
      {  995.74f,  -93.04f,  144.03f,  902.50f } },
    { simde_mm_set_ps( 898.99f, -437.71f, -170.25f,  875.61f),
      {  875.61f, -170.25f, -437.71f,  898.99f } },
    { simde_mm_set_ps( 347.85f, -128.18f,  904.62f,  936.88f),
      {  936.88f,  904.62f, -128.18f,  347.85f } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_float32 r[4];
    simde_mm_stream_ps(r, test_vec[i].a);
    for (size_t j = 0 ; j < sizeof(simde__m128) / sizeof(simde_float32) ; j++) {
      munit_assert_float(r[j], ==, test_vec[i].r[j]);
    }
  }

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  TEST_FUNC(mm_set_ps),
  TEST_FUNC(mm_set1_ps),
  TEST_FUNC(mm_set_ss),
  TEST_FUNC(mm_setr_ps),
  TEST_FUNC(mm_setzero_ps),
  TEST_FUNC(mm_add_ps),
  TEST_FUNC(mm_add_ss),
  TEST_FUNC(mm_and_ps),
  TEST_FUNC(mm_andnot_ps),
  TEST_FUNC(mm_avg_pu16),
  TEST_FUNC(mm_avg_pu8),
  TEST_FUNC(mm_cmpeq_ps),
  TEST_FUNC(mm_cmpeq_ss),
  TEST_FUNC(mm_cmpge_ps),
  TEST_FUNC(mm_cmpge_ss),
  TEST_FUNC(mm_cmpgt_ps),
  TEST_FUNC(mm_cmpgt_ss),
  TEST_FUNC(mm_cmple_ps),
  TEST_FUNC(mm_cmple_ss),
  TEST_FUNC(mm_cmplt_ps),
  TEST_FUNC(mm_cmplt_ss),
  TEST_FUNC(mm_cmpneq_ps),
  TEST_FUNC(mm_cmpneq_ss),
  TEST_FUNC(mm_cmpnge_ps),
  TEST_FUNC(mm_cmpnge_ss),
  TEST_FUNC(mm_cmpngt_ps),
  TEST_FUNC(mm_cmpngt_ss),
  TEST_FUNC(mm_cmpnle_ps),
  TEST_FUNC(mm_cmpnle_ss),
  TEST_FUNC(mm_cmpnlt_ps),
  TEST_FUNC(mm_cmpnlt_ss),
  TEST_FUNC(mm_cmpord_ps),
  TEST_FUNC(mm_cmpord_ss),
  TEST_FUNC(mm_cmpunord_ps),
  TEST_FUNC(mm_cmpunord_ss),
  TEST_FUNC(mm_comieq_ss),
  TEST_FUNC(mm_comige_ss),
  TEST_FUNC(mm_comigt_ss),
  TEST_FUNC(mm_comile_ss),
  TEST_FUNC(mm_comilt_ss),
  TEST_FUNC(mm_comineq_ss),
  TEST_FUNC(mm_cvt_pi2ps),
  TEST_FUNC(mm_cvt_ps2pi),
  TEST_FUNC(mm_cvt_si2ss),
  TEST_FUNC(mm_cvt_ss2si),
  TEST_FUNC(mm_cvtpi16_ps),
  TEST_FUNC(mm_cvtpi32_ps),
  TEST_FUNC(mm_cvtpi32x2_ps),
  TEST_FUNC(mm_cvtpi8_ps),
  TEST_FUNC(mm_cvtps_pi16),
  TEST_FUNC(mm_cvtps_pi32),
  TEST_FUNC(mm_cvtps_pi8),
  TEST_FUNC(mm_cvtpu16_ps),
  TEST_FUNC(mm_cvtpu8_ps),
  TEST_FUNC(mm_cvtsi32_ss),
  TEST_FUNC(mm_cvtsi64_ss),
  TEST_FUNC(mm_cvtss_f32),
  TEST_FUNC(mm_cvtss_si32),
  TEST_FUNC(mm_cvtss_si64),
  TEST_FUNC(mm_cvtt_ps2pi),
  TEST_FUNC(mm_cvtt_ss2si),
  TEST_FUNC(mm_cvttss_si64),
  TEST_FUNC(mm_div_ps),
  TEST_FUNC(mm_div_ss),
  TEST_FUNC(mm_extract_pi16),
  TEST_FUNC(mm_insert_pi16),
  TEST_FUNC(mm_load_ps),
  TEST_FUNC(mm_load_ps1),
  TEST_FUNC(mm_load_ss),
  TEST_FUNC(mm_loadh_pi),
  TEST_FUNC(mm_loadl_pi),
  TEST_FUNC(mm_loadr_ps),
  TEST_FUNC(mm_loadu_ps),
  TEST_FUNC(mm_maskmove_si64),
  TEST_FUNC(mm_max_pi16),
  TEST_FUNC(mm_max_pu8),
  TEST_FUNC(mm_max_ps),
  TEST_FUNC(mm_max_ss),
  TEST_FUNC(mm_min_pi16),
  TEST_FUNC(mm_min_pu8),
  TEST_FUNC(mm_min_ps),
  TEST_FUNC(mm_min_ss),
  TEST_FUNC(mm_move_ss),
  TEST_FUNC(mm_movehl_ps),
  TEST_FUNC(mm_movelh_ps),
  TEST_FUNC(mm_movemask_pi8),
  TEST_FUNC(mm_movemask_ps),
  TEST_FUNC(mm_mul_ps),
  TEST_FUNC(mm_mul_ss),
  TEST_FUNC(mm_mulhi_pu16),
  TEST_FUNC(mm_or_ps),
  TEST_FUNC(mm_rcp_ps),
  TEST_FUNC(mm_rcp_ss),
  TEST_FUNC(mm_rsqrt_ps),
  TEST_FUNC(mm_rsqrt_ss),
  TEST_FUNC(mm_sad_pu8),
  TEST_FUNC(mm_shuffle_pi16),
  TEST_FUNC(mm_shuffle_ps),
  TEST_FUNC(mm_sqrt_ps),
  TEST_FUNC(mm_sqrt_ss),
  TEST_FUNC(mm_store_ps),
  TEST_FUNC(mm_store_ps1),
  TEST_FUNC(mm_store_ss),
  TEST_FUNC(mm_store1_ps),
  TEST_FUNC(mm_storeh_pi),
  TEST_FUNC(mm_storel_pi),
  TEST_FUNC(mm_storer_ps),
  TEST_FUNC(mm_storeu_ps),
  TEST_FUNC(mm_sub_ps),
  TEST_FUNC(mm_sub_ss),
  TEST_FUNC(mm_ucomieq_ss),
  TEST_FUNC(mm_ucomige_ss),
  TEST_FUNC(mm_ucomigt_ss),
  TEST_FUNC(mm_ucomile_ss),
  TEST_FUNC(mm_ucomilt_ss),
  TEST_FUNC(mm_ucomineq_ss),
  TEST_FUNC(mm_unpackhi_ps),
  TEST_FUNC(mm_unpacklo_ps),
  TEST_FUNC(mm_xor_ps),
  TEST_FUNC(mm_stream_pi),
  TEST_FUNC(mm_stream_ps),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

#if defined(SIMDE_NO_NATIVE)
#  define simde_sse_test_suite simde_sse_emul_test_suite
#endif

MunitSuite simde_sse_test_suite = {
  (char*) "/sse",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
