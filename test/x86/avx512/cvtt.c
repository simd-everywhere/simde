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

static int
test_simde_mm512_cvttps_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const int32_t r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   729.57), SIMDE_FLOAT32_C(  -785.48), SIMDE_FLOAT32_C(  -245.56), SIMDE_FLOAT32_C(   741.78),
        SIMDE_FLOAT32_C(  -900.88), SIMDE_FLOAT32_C(  -418.95), SIMDE_FLOAT32_C(  -554.45), SIMDE_FLOAT32_C(  -819.65),
        SIMDE_FLOAT32_C(   260.27), SIMDE_FLOAT32_C(   953.13), SIMDE_FLOAT32_C(  -926.11), SIMDE_FLOAT32_C(   341.73),
        SIMDE_FLOAT32_C(  -339.95), SIMDE_FLOAT32_C(   886.92), SIMDE_FLOAT32_C(   452.88), SIMDE_FLOAT32_C(   215.16) },
      {  INT32_C(         729), -INT32_C(         785), -INT32_C(         245),  INT32_C(         741), -INT32_C(         900), -INT32_C(         418), -INT32_C(         554), -INT32_C(         819),
         INT32_C(         260),  INT32_C(         953), -INT32_C(         926),  INT32_C(         341), -INT32_C(         339),  INT32_C(         886),  INT32_C(         452),  INT32_C(         215) } },
    { { SIMDE_FLOAT32_C(  -840.48), SIMDE_FLOAT32_C(   618.54), SIMDE_FLOAT32_C(   980.39), SIMDE_FLOAT32_C(   428.66),
        SIMDE_FLOAT32_C(  -251.24), SIMDE_FLOAT32_C(   397.38), SIMDE_FLOAT32_C(  -975.80), SIMDE_FLOAT32_C(   766.05),
        SIMDE_FLOAT32_C(  -458.73), SIMDE_FLOAT32_C(   215.13), SIMDE_FLOAT32_C(  -841.38), SIMDE_FLOAT32_C(  -638.70),
        SIMDE_FLOAT32_C(  -411.92), SIMDE_FLOAT32_C(  -220.19), SIMDE_FLOAT32_C(   165.38), SIMDE_FLOAT32_C(  -682.35) },
      { -INT32_C(         840),  INT32_C(         618),  INT32_C(         980),  INT32_C(         428), -INT32_C(         251),  INT32_C(         397), -INT32_C(         975),  INT32_C(         766),
        -INT32_C(         458),  INT32_C(         215), -INT32_C(         841), -INT32_C(         638), -INT32_C(         411), -INT32_C(         220),  INT32_C(         165), -INT32_C(         682) } },
    { { SIMDE_FLOAT32_C(    -5.67), SIMDE_FLOAT32_C(   919.82), SIMDE_FLOAT32_C(  -940.57), SIMDE_FLOAT32_C(    93.45),
        SIMDE_FLOAT32_C(  -499.13), SIMDE_FLOAT32_C(  -495.03), SIMDE_FLOAT32_C(   273.79), SIMDE_FLOAT32_C(   761.13),
        SIMDE_FLOAT32_C(  -541.89), SIMDE_FLOAT32_C(   347.69), SIMDE_FLOAT32_C(   102.86), SIMDE_FLOAT32_C(   118.16),
        SIMDE_FLOAT32_C(   234.61), SIMDE_FLOAT32_C(  -444.26), SIMDE_FLOAT32_C(  -666.68), SIMDE_FLOAT32_C(   394.13) },
      { -INT32_C(           5),  INT32_C(         919), -INT32_C(         940),  INT32_C(          93), -INT32_C(         499), -INT32_C(         495),  INT32_C(         273),  INT32_C(         761),
        -INT32_C(         541),  INT32_C(         347),  INT32_C(         102),  INT32_C(         118),  INT32_C(         234), -INT32_C(         444), -INT32_C(         666),  INT32_C(         394) } },
    { { SIMDE_FLOAT32_C(  -825.71), SIMDE_FLOAT32_C(  -686.29), SIMDE_FLOAT32_C(  -177.21), SIMDE_FLOAT32_C(   -76.96),
        SIMDE_FLOAT32_C(   711.09), SIMDE_FLOAT32_C(  -153.01), SIMDE_FLOAT32_C(  -310.91), SIMDE_FLOAT32_C(  -747.64),
        SIMDE_FLOAT32_C(  -937.88), SIMDE_FLOAT32_C(  -152.29), SIMDE_FLOAT32_C(  -386.34), SIMDE_FLOAT32_C(  -349.81),
        SIMDE_FLOAT32_C(   627.52), SIMDE_FLOAT32_C(   779.04), SIMDE_FLOAT32_C(   -32.16), SIMDE_FLOAT32_C(  -378.15) },
      { -INT32_C(         825), -INT32_C(         686), -INT32_C(         177), -INT32_C(          76),  INT32_C(         711), -INT32_C(         153), -INT32_C(         310), -INT32_C(         747),
        -INT32_C(         937), -INT32_C(         152), -INT32_C(         386), -INT32_C(         349),  INT32_C(         627),  INT32_C(         779), -INT32_C(          32), -INT32_C(         378) } },
    { { SIMDE_FLOAT32_C(   698.86), SIMDE_FLOAT32_C(    27.27), SIMDE_FLOAT32_C(   715.30), SIMDE_FLOAT32_C(  -800.28),
        SIMDE_FLOAT32_C(   532.24), SIMDE_FLOAT32_C(   -10.91), SIMDE_FLOAT32_C(   960.86), SIMDE_FLOAT32_C(   990.35),
        SIMDE_FLOAT32_C(  -663.22), SIMDE_FLOAT32_C(    63.72), SIMDE_FLOAT32_C(   108.52), SIMDE_FLOAT32_C(   571.39),
        SIMDE_FLOAT32_C(   619.47), SIMDE_FLOAT32_C(   441.84), SIMDE_FLOAT32_C(   -34.48), SIMDE_FLOAT32_C(   793.75) },
      {  INT32_C(         698),  INT32_C(          27),  INT32_C(         715), -INT32_C(         800),  INT32_C(         532), -INT32_C(          10),  INT32_C(         960),  INT32_C(         990),
        -INT32_C(         663),  INT32_C(          63),  INT32_C(         108),  INT32_C(         571),  INT32_C(         619),  INT32_C(         441), -INT32_C(          34),  INT32_C(         793) } },
    { { SIMDE_FLOAT32_C(   755.54), SIMDE_FLOAT32_C(   788.31), SIMDE_FLOAT32_C(  -283.21), SIMDE_FLOAT32_C(   466.63),
        SIMDE_FLOAT32_C(  -364.70), SIMDE_FLOAT32_C(   405.88), SIMDE_FLOAT32_C(   719.00), SIMDE_FLOAT32_C(  -302.58),
        SIMDE_FLOAT32_C(  -746.40), SIMDE_FLOAT32_C(  -667.34), SIMDE_FLOAT32_C(   347.62), SIMDE_FLOAT32_C(   881.12),
        SIMDE_FLOAT32_C(  -888.30), SIMDE_FLOAT32_C(  -684.54), SIMDE_FLOAT32_C(  -497.03), SIMDE_FLOAT32_C(   810.56) },
      {  INT32_C(         755),  INT32_C(         788), -INT32_C(         283),  INT32_C(         466), -INT32_C(         364),  INT32_C(         405),  INT32_C(         719), -INT32_C(         302),
        -INT32_C(         746), -INT32_C(         667),  INT32_C(         347),  INT32_C(         881), -INT32_C(         888), -INT32_C(         684), -INT32_C(         497),  INT32_C(         810) } },
    { { SIMDE_FLOAT32_C(   342.73), SIMDE_FLOAT32_C(  -781.74), SIMDE_FLOAT32_C(  -989.72), SIMDE_FLOAT32_C(  -125.03),
        SIMDE_FLOAT32_C(   207.36), SIMDE_FLOAT32_C(   971.14), SIMDE_FLOAT32_C(  -134.67), SIMDE_FLOAT32_C(   544.14),
        SIMDE_FLOAT32_C(    34.86), SIMDE_FLOAT32_C(   973.84), SIMDE_FLOAT32_C(   115.53), SIMDE_FLOAT32_C(  -345.67),
        SIMDE_FLOAT32_C(   415.68), SIMDE_FLOAT32_C(  -918.96), SIMDE_FLOAT32_C(  -551.92), SIMDE_FLOAT32_C(   171.22) },
      {  INT32_C(         342), -INT32_C(         781), -INT32_C(         989), -INT32_C(         125),  INT32_C(         207),  INT32_C(         971), -INT32_C(         134),  INT32_C(         544),
         INT32_C(          34),  INT32_C(         973),  INT32_C(         115), -INT32_C(         345),  INT32_C(         415), -INT32_C(         918), -INT32_C(         551),  INT32_C(         171) } },
    { { SIMDE_FLOAT32_C(   869.36), SIMDE_FLOAT32_C(   164.87), SIMDE_FLOAT32_C(  -362.14), SIMDE_FLOAT32_C(  -495.34),
        SIMDE_FLOAT32_C(  -429.24), SIMDE_FLOAT32_C(  -643.14), SIMDE_FLOAT32_C(   202.08), SIMDE_FLOAT32_C(  -175.65),
        SIMDE_FLOAT32_C(  -310.49), SIMDE_FLOAT32_C(  -450.30), SIMDE_FLOAT32_C(  -294.53), SIMDE_FLOAT32_C(  -198.79),
        SIMDE_FLOAT32_C(  -134.84), SIMDE_FLOAT32_C(   208.44), SIMDE_FLOAT32_C(  -388.23), SIMDE_FLOAT32_C(  -792.11) },
      {  INT32_C(         869),  INT32_C(         164), -INT32_C(         362), -INT32_C(         495), -INT32_C(         429), -INT32_C(         643),  INT32_C(         202), -INT32_C(         175),
        -INT32_C(         310), -INT32_C(         450), -INT32_C(         294), -INT32_C(         198), -INT32_C(         134),  INT32_C(         208), -INT32_C(         388), -INT32_C(         792) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512i r = simde_mm512_cvttps_epi32(a);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_f32x16(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512i r = simde_mm512_cvttps_epi32(a);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvttpd_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cvttpd_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_cvttpd_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cvttps_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
