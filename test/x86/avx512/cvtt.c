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
 */

#define SIMDE_TEST_X86_AVX512_INSN cvtt

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/cvtt.h>

static int
test_simde_mm_cvttpd_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const int64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   548.43), SIMDE_FLOAT64_C(  -160.32) },
      {  INT64_C(                 548), -INT64_C(                 160) } },
    { { SIMDE_FLOAT64_C(  -665.23), SIMDE_FLOAT64_C(   909.86) },
      { -INT64_C(                 665),  INT64_C(                 909) } },
    { { SIMDE_FLOAT64_C(   869.84), SIMDE_FLOAT64_C(  -522.84) },
      {  INT64_C(                 869), -INT64_C(                 522) } },
    { { SIMDE_FLOAT64_C(  -396.75), SIMDE_FLOAT64_C(  -885.22) },
      { -INT64_C(                 396), -INT64_C(                 885) } },
    { { SIMDE_FLOAT64_C(   670.62), SIMDE_FLOAT64_C(  -665.50) },
      {  INT64_C(                 670), -INT64_C(                 665) } },
    { { SIMDE_FLOAT64_C(    66.13), SIMDE_FLOAT64_C(   606.16) },
      {  INT64_C(                  66),  INT64_C(                 606) } },
    { { SIMDE_FLOAT64_C(   -31.40), SIMDE_FLOAT64_C(  -401.49) },
      { -INT64_C(                  31), -INT64_C(                 401) } },
    { { SIMDE_FLOAT64_C(    27.98), SIMDE_FLOAT64_C(   872.01) },
      {  INT64_C(                  27),  INT64_C(                 872) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128i r = simde_mm_cvttpd_epi64(a);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d a = simde_test_x86_random_f64x2(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128i r = simde_mm_cvttpd_epi64(a);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cvttpd_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    const simde_float64 a[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C(  361962842543030048), -INT64_C( 3474737081876049297) },
      UINT8_C(108),
      { SIMDE_FLOAT64_C(   957.75), SIMDE_FLOAT64_C(   751.50) },
      { -INT64_C(  361962842543030048), -INT64_C( 3474737081876049297) } },
    { {  INT64_C(  688050963011175950), -INT64_C( 7209247915320387714) },
      UINT8_C( 81),
      { SIMDE_FLOAT64_C(   -23.92), SIMDE_FLOAT64_C(  -116.15) },
      { -INT64_C(                  23), -INT64_C( 7209247915320387714) } },
    { { -INT64_C( 1696959715454980277), -INT64_C( 8986700034522357505) },
      UINT8_C(136),
      { SIMDE_FLOAT64_C(    40.92), SIMDE_FLOAT64_C(  -333.21) },
      { -INT64_C( 1696959715454980277), -INT64_C( 8986700034522357505) } },
    { { -INT64_C( 3906979509015529327), -INT64_C( 7568519742650574791) },
      UINT8_C( 88),
      { SIMDE_FLOAT64_C(   414.99), SIMDE_FLOAT64_C(  -679.12) },
      { -INT64_C( 3906979509015529327), -INT64_C( 7568519742650574791) } },
    { {  INT64_C( 1324577026109679169), -INT64_C( 6354291571612128933) },
      UINT8_C(219),
      { SIMDE_FLOAT64_C(   727.53), SIMDE_FLOAT64_C(   -94.39) },
      {  INT64_C(                 727), -INT64_C(                  94) } },
    { {  INT64_C( 7972755038995392676), -INT64_C( 3786475889184342912) },
      UINT8_C(133),
      { SIMDE_FLOAT64_C(   -53.71), SIMDE_FLOAT64_C(   557.50) },
      { -INT64_C(                  53), -INT64_C( 3786475889184342912) } },
    { { -INT64_C( 2204071043036436841),  INT64_C( 6065779050755933240) },
      UINT8_C(112),
      { SIMDE_FLOAT64_C(   377.02), SIMDE_FLOAT64_C(  -369.85) },
      { -INT64_C( 2204071043036436841),  INT64_C( 6065779050755933240) } },
    { { -INT64_C( 7696596639603648289), -INT64_C( 5674106389503363330) },
      UINT8_C(151),
      { SIMDE_FLOAT64_C(  -383.32), SIMDE_FLOAT64_C(   295.30) },
      { -INT64_C(                 383),  INT64_C(                 295) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi64(test_vec[i].src);
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128i r = simde_mm_mask_cvttpd_epi64(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i64x2();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128i r = simde_mm_mask_cvttpd_epi64(src, k, a);

    simde_test_x86_write_i64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_cvttpd_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[2];
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C(120),
      { SIMDE_FLOAT64_C(  -637.12), SIMDE_FLOAT64_C(   286.78) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(201),
      { SIMDE_FLOAT64_C(    14.68), SIMDE_FLOAT64_C(  -536.46) },
      {  INT64_C(                  14),  INT64_C(                   0) } },
    { UINT8_C(194),
      { SIMDE_FLOAT64_C(     4.38), SIMDE_FLOAT64_C(  -326.23) },
      {  INT64_C(                   0), -INT64_C(                 326) } },
    { UINT8_C( 50),
      { SIMDE_FLOAT64_C(  -618.60), SIMDE_FLOAT64_C(   303.92) },
      {  INT64_C(                   0),  INT64_C(                 303) } },
    { UINT8_C( 17),
      { SIMDE_FLOAT64_C(  -934.04), SIMDE_FLOAT64_C(  -855.69) },
      { -INT64_C(                 934),  INT64_C(                   0) } },
    { UINT8_C(134),
      { SIMDE_FLOAT64_C(  -621.04), SIMDE_FLOAT64_C(   304.82) },
      {  INT64_C(                   0),  INT64_C(                 304) } },
    { UINT8_C(182),
      { SIMDE_FLOAT64_C(  -152.60), SIMDE_FLOAT64_C(   172.70) },
      {  INT64_C(                   0),  INT64_C(                 172) } },
    { UINT8_C(108),
      { SIMDE_FLOAT64_C(  -737.88), SIMDE_FLOAT64_C(  -401.93) },
      {  INT64_C(                   0),  INT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_cvttpd_epi64(test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128i r = simde_mm_maskz_cvttpd_epi64(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvttpd_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cvttpd_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_cvttpd_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
