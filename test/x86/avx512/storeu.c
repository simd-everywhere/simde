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
 */

#define SIMDE_TEST_X86_AVX512_INSN storeu

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/storeu.h>

static int
test_simde_mm_storeu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  17), -INT8_C( 120), -INT8_C(  69), -INT8_C(  48), -INT8_C(  71),  INT8_C(  40), -INT8_C( 103),  INT8_C(  78),
        -INT8_C( 114), -INT8_C(  66), -INT8_C( 102), -INT8_C(  78),  INT8_C( 106),  INT8_C(  77),  INT8_C( 114), -INT8_C(  21) },
      { -INT8_C(  17), -INT8_C( 120), -INT8_C(  69), -INT8_C(  48), -INT8_C(  71),  INT8_C(  40), -INT8_C( 103),  INT8_C(  78),
        -INT8_C( 114), -INT8_C(  66), -INT8_C( 102), -INT8_C(  78),  INT8_C( 106),  INT8_C(  77),  INT8_C( 114), -INT8_C(  21) } },
    { { -INT8_C(  13),  INT8_C(   1),  INT8_C(  86),  INT8_C( 119),  INT8_C( 119), -INT8_C(  64), -INT8_C(  58), -INT8_C(  35),
         INT8_C(  17),  INT8_C(  77),  INT8_C(  78), -INT8_C(  43),  INT8_C(  70), -INT8_C(  24),  INT8_C(  88),  INT8_C(  54) },
      { -INT8_C(  13),  INT8_C(   1),  INT8_C(  86),  INT8_C( 119),  INT8_C( 119), -INT8_C(  64), -INT8_C(  58), -INT8_C(  35),
         INT8_C(  17),  INT8_C(  77),  INT8_C(  78), -INT8_C(  43),  INT8_C(  70), -INT8_C(  24),  INT8_C(  88),  INT8_C(  54) } },
    { {  INT8_C( 113),  INT8_C(  19),  INT8_C(   6),  INT8_C(  42),  INT8_C(  60), -INT8_C(  97),  INT8_C( 120), -INT8_C(  54),
         INT8_C(  93),  INT8_C(  18),  INT8_C( 124), -INT8_C(  56),  INT8_C(  96), -INT8_C(  18), -INT8_C(  77),  INT8_C(  83) },
      {  INT8_C( 113),  INT8_C(  19),  INT8_C(   6),  INT8_C(  42),  INT8_C(  60), -INT8_C(  97),  INT8_C( 120), -INT8_C(  54),
         INT8_C(  93),  INT8_C(  18),  INT8_C( 124), -INT8_C(  56),  INT8_C(  96), -INT8_C(  18), -INT8_C(  77),  INT8_C(  83) } },
    { { -INT8_C(  17),  INT8_C(   9), -INT8_C(  54),  INT8_C( 102), -INT8_C(  54), -INT8_C( 112),  INT8_C(  68), -INT8_C(  37),
        -INT8_C(  35), -INT8_C( 110), -INT8_C(  80),  INT8_C(  36),  INT8_C( 123),  INT8_C(   9),  INT8_C(  90), -INT8_C(  20) },
      { -INT8_C(  17),  INT8_C(   9), -INT8_C(  54),  INT8_C( 102), -INT8_C(  54), -INT8_C( 112),  INT8_C(  68), -INT8_C(  37),
        -INT8_C(  35), -INT8_C( 110), -INT8_C(  80),  INT8_C(  36),  INT8_C( 123),  INT8_C(   9),  INT8_C(  90), -INT8_C(  20) } },
    { {  INT8_C(  28),  INT8_C(  96),  INT8_C(  22),  INT8_C(  88), -INT8_C(   1), -INT8_C( 113),  INT8_C(  34),  INT8_C(  92),
        -INT8_C(  95), -INT8_C(  98),  INT8_C(  36),  INT8_C(   1), -INT8_C( 115), -INT8_C(  40),  INT8_C(  84),  INT8_C( 124) },
      {  INT8_C(  28),  INT8_C(  96),  INT8_C(  22),  INT8_C(  88), -INT8_C(   1), -INT8_C( 113),  INT8_C(  34),  INT8_C(  92),
        -INT8_C(  95), -INT8_C(  98),  INT8_C(  36),  INT8_C(   1), -INT8_C( 115), -INT8_C(  40),  INT8_C(  84),  INT8_C( 124) } },
    { { -INT8_C(  31),  INT8_C(  30), -INT8_C(  29), -INT8_C(  85), -INT8_C(  82),  INT8_C(  39), -INT8_C( 122), -INT8_C( 116),
        -INT8_C(  71),  INT8_C(  55), -INT8_C(  80),  INT8_C(  52),  INT8_C(  64),  INT8_C(  10),  INT8_C(  32),  INT8_C(  92) },
      { -INT8_C(  31),  INT8_C(  30), -INT8_C(  29), -INT8_C(  85), -INT8_C(  82),  INT8_C(  39), -INT8_C( 122), -INT8_C( 116),
        -INT8_C(  71),  INT8_C(  55), -INT8_C(  80),  INT8_C(  52),  INT8_C(  64),  INT8_C(  10),  INT8_C(  32),  INT8_C(  92) } },
    { {  INT8_C( 106),  INT8_C(  55), -INT8_C(  75),  INT8_C( 105), -INT8_C(  58), -INT8_C(  41), -INT8_C(  59),  INT8_C( 103),
         INT8_C( 118), -INT8_C(  22),  INT8_C( 105),  INT8_C(   3), -INT8_C(  62), -INT8_C(  67),      INT8_MAX, -INT8_C(  93) },
      {  INT8_C( 106),  INT8_C(  55), -INT8_C(  75),  INT8_C( 105), -INT8_C(  58), -INT8_C(  41), -INT8_C(  59),  INT8_C( 103),
         INT8_C( 118), -INT8_C(  22),  INT8_C( 105),  INT8_C(   3), -INT8_C(  62), -INT8_C(  67),      INT8_MAX, -INT8_C(  93) } },
    { { -INT8_C(  36),  INT8_C(  98),  INT8_C(  79), -INT8_C( 118), -INT8_C( 119), -INT8_C(  43),  INT8_C(  22),  INT8_C(  67),
         INT8_C(  12), -INT8_C(  58),  INT8_C( 119),  INT8_C(  76), -INT8_C(  48), -INT8_C( 104), -INT8_C(  87),  INT8_C(  58) },
      { -INT8_C(  36),  INT8_C(  98),  INT8_C(  79), -INT8_C( 118), -INT8_C( 119), -INT8_C(  43),  INT8_C(  22),  INT8_C(  67),
         INT8_C(  12), -INT8_C(  58),  INT8_C( 119),  INT8_C(  76), -INT8_C(  48), -INT8_C( 104), -INT8_C(  87),  INT8_C(  58) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    int8_t r[sizeof(simde__m128i) / sizeof(int8_t)] = {0};
    simde_mm_storeu_epi8(r, a);
    simde_assert_equal_vi8(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    int8_t r[sizeof(simde__m128i) / sizeof(int8_t)] = {0};
    simde_mm_storeu_epi8(r, a);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi8(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_storeu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { {  INT16_C( 24271), -INT16_C( 27229),  INT16_C( 26933), -INT16_C( 21508),  INT16_C( 25939),  INT16_C(  5550),  INT16_C( 11811), -INT16_C(    72) },
      {  INT16_C( 24271), -INT16_C( 27229),  INT16_C( 26933), -INT16_C( 21508),  INT16_C( 25939),  INT16_C(  5550),  INT16_C( 11811), -INT16_C(    72) } },
    { {  INT16_C(  1936),  INT16_C(  6793), -INT16_C( 24355), -INT16_C(  5795), -INT16_C( 11162),  INT16_C( 14134), -INT16_C(  8340),  INT16_C( 15217) },
      {  INT16_C(  1936),  INT16_C(  6793), -INT16_C( 24355), -INT16_C(  5795), -INT16_C( 11162),  INT16_C( 14134), -INT16_C(  8340),  INT16_C( 15217) } },
    { {  INT16_C(  5437),  INT16_C( 29392), -INT16_C( 12930), -INT16_C( 12002), -INT16_C( 13262),  INT16_C( 21990), -INT16_C( 24838), -INT16_C( 29868) },
      {  INT16_C(  5437),  INT16_C( 29392), -INT16_C( 12930), -INT16_C( 12002), -INT16_C( 13262),  INT16_C( 21990), -INT16_C( 24838), -INT16_C( 29868) } },
    { { -INT16_C(  8538), -INT16_C( 31835),  INT16_C(   638), -INT16_C(  7060), -INT16_C( 23850),  INT16_C( 17179), -INT16_C( 29311), -INT16_C( 16770) },
      { -INT16_C(  8538), -INT16_C( 31835),  INT16_C(   638), -INT16_C(  7060), -INT16_C( 23850),  INT16_C( 17179), -INT16_C( 29311), -INT16_C( 16770) } },
    { {  INT16_C( 20386),  INT16_C(  8241),  INT16_C( 20252),  INT16_C( 20209), -INT16_C( 10469),  INT16_C(  5796), -INT16_C(  1931),  INT16_C(  7073) },
      {  INT16_C( 20386),  INT16_C(  8241),  INT16_C( 20252),  INT16_C( 20209), -INT16_C( 10469),  INT16_C(  5796), -INT16_C(  1931),  INT16_C(  7073) } },
    { {  INT16_C( 18134),  INT16_C( 21662),  INT16_C(  2888),  INT16_C(  7737),  INT16_C( 21677),  INT16_C( 12129), -INT16_C(  7967), -INT16_C( 31763) },
      {  INT16_C( 18134),  INT16_C( 21662),  INT16_C(  2888),  INT16_C(  7737),  INT16_C( 21677),  INT16_C( 12129), -INT16_C(  7967), -INT16_C( 31763) } },
    { {  INT16_C(  7727),  INT16_C( 19363), -INT16_C( 27539), -INT16_C( 30311),  INT16_C( 15723), -INT16_C(  7777),  INT16_C( 16438),  INT16_C(  3324) },
      {  INT16_C(  7727),  INT16_C( 19363), -INT16_C( 27539), -INT16_C( 30311),  INT16_C( 15723), -INT16_C(  7777),  INT16_C( 16438),  INT16_C(  3324) } },
    { { -INT16_C( 25722), -INT16_C( 12703), -INT16_C( 25946),  INT16_C( 21484),  INT16_C( 20206), -INT16_C( 12158),  INT16_C( 28718),  INT16_C( 23891) },
      { -INT16_C( 25722), -INT16_C( 12703), -INT16_C( 25946),  INT16_C( 21484),  INT16_C( 20206), -INT16_C( 12158),  INT16_C( 28718),  INT16_C( 23891) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    int16_t r[sizeof(simde__m128i) / sizeof(int16_t)] = {0};
    simde_mm_storeu_epi16(r, a);
    simde_assert_equal_vi16(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    int16_t r[sizeof(simde__m128i) / sizeof(int16_t)] = {0};
    simde_mm_storeu_epi16(r, a);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi16(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_storeu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(    56035442), -INT32_C(   142261877), -INT32_C(  1244126081), -INT32_C(   356395932) },
      { -INT32_C(    56035442), -INT32_C(   142261877), -INT32_C(  1244126081), -INT32_C(   356395932) } },
    { {  INT32_C(   364388975), -INT32_C(  1419139908),  INT32_C(   544992242), -INT32_C(   360853925) },
      {  INT32_C(   364388975), -INT32_C(  1419139908),  INT32_C(   544992242), -INT32_C(   360853925) } },
    { {  INT32_C(  1374037445), -INT32_C(   431461529), -INT32_C(   207937393),  INT32_C(  1692228852) },
      {  INT32_C(  1374037445), -INT32_C(   431461529), -INT32_C(   207937393),  INT32_C(  1692228852) } },
    { {  INT32_C(   997823871),  INT32_C(   753328697),  INT32_C(   692871630), -INT32_C(   183252432) },
      {  INT32_C(   997823871),  INT32_C(   753328697),  INT32_C(   692871630), -INT32_C(   183252432) } },
    { {  INT32_C(  1447492079), -INT32_C(   214135196), -INT32_C(  1545152594), -INT32_C(  1291336908) },
      {  INT32_C(  1447492079), -INT32_C(   214135196), -INT32_C(  1545152594), -INT32_C(  1291336908) } },
    { { -INT32_C(  1829863336),  INT32_C(   834590051),  INT32_C(  1717176886), -INT32_C(  1000575276) },
      { -INT32_C(  1829863336),  INT32_C(   834590051),  INT32_C(  1717176886), -INT32_C(  1000575276) } },
    { { -INT32_C(   870669721), -INT32_C(   541108431),  INT32_C(  1652729390), -INT32_C(  1038775959) },
      { -INT32_C(   870669721), -INT32_C(   541108431),  INT32_C(  1652729390), -INT32_C(  1038775959) } },
    { {  INT32_C(  1834222602),  INT32_C(   262017753), -INT32_C(   243861476), -INT32_C(   826944922) },
      {  INT32_C(  1834222602),  INT32_C(   262017753), -INT32_C(   243861476), -INT32_C(   826944922) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    int32_t r[sizeof(simde__m128i) / sizeof(int32_t)] = {0};
    simde_mm_storeu_epi32(r, a);
    simde_assert_equal_vi32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    int32_t r[sizeof(simde__m128i) / sizeof(int32_t)] = {0};
    simde_mm_storeu_epi32(r, a);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi32(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_storeu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C( 6162429687648407412), -INT64_C( 7265487549404608513) },
      {  INT64_C( 6162429687648407412), -INT64_C( 7265487549404608513) } },
    { { -INT64_C( 5928524289903394863),  INT64_C( 8562278580415770526) },
      { -INT64_C( 5928524289903394863),  INT64_C( 8562278580415770526) } },
    { { -INT64_C( 4134690634389033693), -INT64_C(  804919326062717272) },
      { -INT64_C( 4134690634389033693), -INT64_C(  804919326062717272) } },
    { {  INT64_C( 2312413151324200153),  INT64_C( 3242301501575902855) },
      {  INT64_C( 2312413151324200153),  INT64_C( 3242301501575902855) } },
    { {  INT64_C( 7129783949923326565),  INT64_C( 6089270747629035882) },
      {  INT64_C( 7129783949923326565),  INT64_C( 6089270747629035882) } },
    { { -INT64_C(   76889433089106101),  INT64_C( 8196979085885707147) },
      { -INT64_C(   76889433089106101),  INT64_C( 8196979085885707147) } },
    { { -INT64_C( 5279187105101301857),  INT64_C( 1333001473940019120) },
      { -INT64_C( 5279187105101301857),  INT64_C( 1333001473940019120) } },
    { { -INT64_C( 7036084885255078427),  INT64_C(  315240317059326177) },
      { -INT64_C( 7036084885255078427),  INT64_C(  315240317059326177) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    int64_t r[sizeof(simde__m128i) / sizeof(int64_t)] = {0};
    simde_mm_storeu_epi64(r, a);
    simde_assert_equal_vi64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    int64_t r[sizeof(simde__m128i) / sizeof(int64_t)] = {0};
    simde_mm_storeu_epi64(r, a);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi64(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_storeu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int8_t a[16];
    const int8_t r[16];
  } test_vec[] = {
    { UINT16_C(64556),
      {  INT8_C(  94),  INT8_C( 120), -INT8_C( 116),  INT8_C(  26),  INT8_C(  47),  INT8_C(  60),  INT8_C( 113),  INT8_C( 115),
         INT8_C( 104),  INT8_C(  56),  INT8_C(  56), -INT8_C(  25),  INT8_C(  75),  INT8_C(  29),  INT8_C(  37),  INT8_C(  43) },
      {      INT8_MAX,  INT8_C(   0), -INT8_C( 116),  INT8_C(  26),  INT8_C(   0),  INT8_C(  60),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  56), -INT8_C(  25),  INT8_C(  75),  INT8_C(  29),  INT8_C(  37),  INT8_C(  43) } },
    { UINT16_C(14457),
      { -INT8_C(   7), -INT8_C(  45), -INT8_C(  42), -INT8_C(  38), -INT8_C(  76),  INT8_C(  10), -INT8_C(  56),  INT8_C(  25),
        -INT8_C(   1),  INT8_C(  39),  INT8_C(  30),  INT8_C(  43),  INT8_C(  35),  INT8_C( 124), -INT8_C(  92), -INT8_C(  81) },
      { -INT8_C(   7),  INT8_C(   0),  INT8_C(   0), -INT8_C(  38), -INT8_C(  76),  INT8_C(  10), -INT8_C(  56),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  43),  INT8_C(  35),  INT8_C( 124),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(54166),
      { -INT8_C(  20),  INT8_C(   7),  INT8_C(  70),  INT8_C(  84),  INT8_C(  64),  INT8_C( 126),  INT8_C(  59), -INT8_C( 117),
        -INT8_C( 100),  INT8_C(  96), -INT8_C(  74),  INT8_C(  21), -INT8_C( 104), -INT8_C(  81), -INT8_C(  23),  INT8_C( 111) },
      {      INT8_MAX,  INT8_C(   7),  INT8_C(  70),  INT8_C(   0),  INT8_C(  64),  INT8_C(   0),  INT8_C(   0), -INT8_C( 117),
        -INT8_C( 100),  INT8_C(  96),  INT8_C(   0),  INT8_C(   0), -INT8_C( 104),  INT8_C(   0), -INT8_C(  23),  INT8_C( 111) } },
    { UINT16_C(40329),
      {  INT8_C( 121),  INT8_C(  81), -INT8_C(  74),  INT8_C( 120),  INT8_C( 120), -INT8_C(  44), -INT8_C(  93), -INT8_C( 100),
         INT8_C(  80),  INT8_C(  71),  INT8_C(  75), -INT8_C(  26),  INT8_C(  26),  INT8_C(  55), -INT8_C(  18),  INT8_C(  96) },
      {  INT8_C( 121),  INT8_C(   0),  INT8_C(   0),  INT8_C( 120),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 100),
         INT8_C(  80),  INT8_C(   0),  INT8_C(  75), -INT8_C(  26),  INT8_C(  26),  INT8_C(   0),  INT8_C(   0),  INT8_C(  96) } },
    { UINT16_C(11915),
      { -INT8_C(  33), -INT8_C(  57), -INT8_C(  71),  INT8_C( 123),  INT8_C(  39),  INT8_C( 111), -INT8_C( 112), -INT8_C(  64),
         INT8_C(  30),  INT8_C( 121),  INT8_C(  47), -INT8_C(  89),  INT8_C(  22), -INT8_C(  88), -INT8_C(   7), -INT8_C(  51) },
      { -INT8_C(  33), -INT8_C(  57),  INT8_C(   0),  INT8_C( 123),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  64),
         INT8_C(   0),  INT8_C( 121),  INT8_C(  47), -INT8_C(  89),  INT8_C(   0), -INT8_C(  88),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(28960),
      { -INT8_C(  95), -INT8_C(  61),  INT8_C(  13), -INT8_C(  14),  INT8_C(  11),  INT8_C(  89), -INT8_C(  40),  INT8_C(  37),
        -INT8_C( 112), -INT8_C(  58), -INT8_C( 122),  INT8_C(  28), -INT8_C(  12),  INT8_C( 101), -INT8_C(  29), -INT8_C(  83) },
      {      INT8_MAX,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  89),  INT8_C(   0),  INT8_C(   0),
        -INT8_C( 112),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  12),  INT8_C( 101), -INT8_C(  29),  INT8_C(   0) } },
    { UINT16_C( 2784),
      {  INT8_C(  28),  INT8_C( 112), -INT8_C(  54),  INT8_C(  58), -INT8_C(  22), -INT8_C(   7), -INT8_C(  30),  INT8_C(   0),
        -INT8_C(  95), -INT8_C(  37), -INT8_C(  51), -INT8_C(  63),  INT8_C(  76),  INT8_C( 111), -INT8_C( 123),  INT8_C(  90) },
      {      INT8_MAX,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   7), -INT8_C(  30),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  37),  INT8_C(   0), -INT8_C(  63),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(36961),
      { -INT8_C(  77),  INT8_C(  57), -INT8_C(  75),  INT8_C(  67),  INT8_C(   0),  INT8_C(  59),  INT8_C(  95), -INT8_C(  12),
        -INT8_C(  96),  INT8_C(  66), -INT8_C(  94),      INT8_MIN,  INT8_C(  77), -INT8_C(  66), -INT8_C(  15),  INT8_C(  23) },
      { -INT8_C(  77),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  59),  INT8_C(  95),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  77),  INT8_C(   0),  INT8_C(   0),  INT8_C(  23) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi8(test_vec[i].a);
    int8_t r[sizeof(simde__m128i) / sizeof(int8_t)] = {INT8_MAX};
    simde_mm_mask_storeu_epi8(r, test_vec[i].k, a);
    simde_assert_equal_vi8(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m128i a = simde_test_x86_random_i8x16();
    int8_t r[sizeof(simde__m128i) / sizeof(int8_t)] = {INT8_MAX};
    simde_mm_mask_storeu_epi8(r, k, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vi8(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_storeu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t r[8];
  } test_vec[] = {
    { UINT8_C(249),
      {  INT16_C(  4571), -INT16_C(  9253), -INT16_C( 18766),  INT16_C( 29865),  INT16_C(  6146),  INT16_C( 23801), -INT16_C( 30343), -INT16_C( 19953) },
      {  INT16_C(  4571),  INT16_C(     0),  INT16_C(     0),  INT16_C( 29865),  INT16_C(  6146),  INT16_C( 23801), -INT16_C( 30343), -INT16_C( 19953) } },
    { UINT8_C( 62),
      { -INT16_C( 19885), -INT16_C( 19846),  INT16_C(  6823),  INT16_C( 18933),  INT16_C( 17051), -INT16_C( 29689),  INT16_C(    89),  INT16_C( 27239) },
      {        INT16_MAX, -INT16_C( 19846),  INT16_C(  6823),  INT16_C( 18933),  INT16_C( 17051), -INT16_C( 29689),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C(219),
      {  INT16_C(  7490), -INT16_C(  5231), -INT16_C( 27503), -INT16_C( 30205),  INT16_C( 31984),  INT16_C(    19),  INT16_C( 20783), -INT16_C(  7853) },
      {  INT16_C(  7490), -INT16_C(  5231),  INT16_C(     0), -INT16_C( 30205),  INT16_C( 31984),  INT16_C(     0),  INT16_C( 20783), -INT16_C(  7853) } },
    { UINT8_C(203),
      { -INT16_C( 30715), -INT16_C(  1306), -INT16_C( 32303), -INT16_C(  9924), -INT16_C( 27123),  INT16_C( 29913), -INT16_C( 19200),  INT16_C(  7606) },
      { -INT16_C( 30715), -INT16_C(  1306),  INT16_C(     0), -INT16_C(  9924),  INT16_C(     0),  INT16_C(     0), -INT16_C( 19200),  INT16_C(  7606) } },
    { UINT8_C( 70),
      { -INT16_C( 20830), -INT16_C( 23078), -INT16_C( 13512),  INT16_C( 19234),  INT16_C( 20939),  INT16_C(  7837),  INT16_C( 26674), -INT16_C( 17629) },
      {        INT16_MAX, -INT16_C( 23078), -INT16_C( 13512),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 26674),  INT16_C(     0) } },
    { UINT8_C( 78),
      { -INT16_C( 29666),  INT16_C( 23247), -INT16_C(  9115),  INT16_C( 16368), -INT16_C(  3760),  INT16_C(  2036),  INT16_C( 14862), -INT16_C( 16983) },
      {        INT16_MAX,  INT16_C( 23247), -INT16_C(  9115),  INT16_C( 16368),  INT16_C(     0),  INT16_C(     0),  INT16_C( 14862),  INT16_C(     0) } },
    { UINT8_C( 21),
      { -INT16_C(  2738),  INT16_C( 28896), -INT16_C( 21695), -INT16_C(  8511), -INT16_C(  2871), -INT16_C(  5050), -INT16_C( 27217),  INT16_C( 15114) },
      { -INT16_C(  2738),  INT16_C(     0), -INT16_C( 21695),  INT16_C(     0), -INT16_C(  2871),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C(100),
      { -INT16_C( 24219),  INT16_C( 21825), -INT16_C( 28192), -INT16_C( 11194),  INT16_C( 21912),  INT16_C( 16654),  INT16_C(  8978),  INT16_C(  1936) },
      {        INT16_MAX,  INT16_C(     0), -INT16_C( 28192),  INT16_C(     0),  INT16_C(     0),  INT16_C( 16654),  INT16_C(  8978),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    int16_t r[sizeof(simde__m128i) / sizeof(int16_t)] = {INT16_MAX};
    simde_mm_mask_storeu_epi16(r, test_vec[i].k, a);
    simde_assert_equal_vi16(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    int16_t r[sizeof(simde__m128i) / sizeof(int16_t)] = {INT16_MAX};
    simde_mm_mask_storeu_epi16(r, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vi16(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_storeu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C(  3),
      { -INT32_C(  1028765696),  INT32_C(  1840674598),  INT32_C(  1845650788),  INT32_C(  1104373408) },
      { -INT32_C(  1028765696),  INT32_C(  1840674598),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(167),
      {  INT32_C(  1866015017),  INT32_C(    80007669), -INT32_C(  1557670381),  INT32_C(   648227806) },
      {  INT32_C(  1866015017),  INT32_C(    80007669), -INT32_C(  1557670381),  INT32_C(           0) } },
    { UINT8_C(217),
      {  INT32_C(   458313061), -INT32_C(  1132415558), -INT32_C(   148758237), -INT32_C(  2078225822) },
      {  INT32_C(   458313061),  INT32_C(           0),  INT32_C(           0), -INT32_C(  2078225822) } },
    { UINT8_C(  3),
      {  INT32_C(  1423210895), -INT32_C(  1523914883),  INT32_C(   785385610),  INT32_C(  2090051887) },
      {  INT32_C(  1423210895), -INT32_C(  1523914883),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(250),
      {  INT32_C(   800011951),  INT32_C(   340841458), -INT32_C(   354503734), -INT32_C(  1334189769) },
      {              INT32_MAX,  INT32_C(   340841458),  INT32_C(           0), -INT32_C(  1334189769) } },
    { UINT8_C(182),
      { -INT32_C(   123916595), -INT32_C(  1560270637), -INT32_C(   380883114), -INT32_C(   510113877) },
      {              INT32_MAX, -INT32_C(  1560270637), -INT32_C(   380883114),  INT32_C(           0) } },
    { UINT8_C(246),
      {  INT32_C(   415880136), -INT32_C(   959736856), -INT32_C(   139984259), -INT32_C(   507224397) },
      {              INT32_MAX, -INT32_C(   959736856), -INT32_C(   139984259),  INT32_C(           0) } },
    { UINT8_C(251),
      { -INT32_C(  1121733444), -INT32_C(  1544783529), -INT32_C(    68511645),  INT32_C(  1304682873) },
      { -INT32_C(  1121733444), -INT32_C(  1544783529),  INT32_C(           0),  INT32_C(  1304682873) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    int32_t r[sizeof(simde__m128i) / sizeof(int32_t)] = {INT32_MAX};
    simde_mm_mask_storeu_epi32(r, test_vec[i].k, a);
    simde_assert_equal_vi32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    int32_t r[sizeof(simde__m128i) / sizeof(int32_t)] = {INT32_MAX};
    simde_mm_mask_storeu_epi32(r, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vi32(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_storeu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C( 52),
      {  INT64_C( 7701757442913005655), -INT64_C(  460158602655149192) },
      {                      INT64_MAX,  INT64_C(                   0) } },
    { UINT8_C( 31),
      {  INT64_C( 8630075685043134545), -INT64_C( 5597025724639073000) },
      {  INT64_C( 8630075685043134545), -INT64_C( 5597025724639073000) } },
    { UINT8_C(106),
      {  INT64_C( 1745996646011717638), -INT64_C( 4228765262816973982) },
      {                      INT64_MAX, -INT64_C( 4228765262816973982) } },
    { UINT8_C( 35),
      { -INT64_C( 9022562350136041001), -INT64_C( 8808676671954580889) },
      { -INT64_C( 9022562350136041001), -INT64_C( 8808676671954580889) } },
    { UINT8_C(216),
      { -INT64_C( 7471399966097918039),  INT64_C( 6586553464355075392) },
      {                      INT64_MAX,  INT64_C(                   0) } },
    { UINT8_C(118),
      {  INT64_C( 1610116262709539588),  INT64_C( 5867408672365319171) },
      {                      INT64_MAX,  INT64_C( 5867408672365319171) } },
    { UINT8_C( 24),
      {  INT64_C( 4204278724983103826), -INT64_C( 2118991803148545238) },
      {                      INT64_MAX,  INT64_C(                   0) } },
    { UINT8_C(181),
      { -INT64_C( 8191764951237519515),  INT64_C( 6739039516340284357) },
      { -INT64_C( 8191764951237519515),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    int64_t r[sizeof(simde__m128i) / sizeof(int64_t)] = {INT64_MAX};
    simde_mm_mask_storeu_epi64(r, test_vec[i].k, a);
    simde_assert_equal_vi64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    int64_t r[sizeof(simde__m128i) / sizeof(int64_t)] = {INT64_MAX};
    simde_mm_mask_storeu_epi64(r, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vi64(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_storeu_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT32_C(       147),
      { SIMDE_FLOAT32_C(   -85.97), SIMDE_FLOAT32_C(  -897.59), SIMDE_FLOAT32_C(  -103.61), SIMDE_FLOAT32_C(  -451.50) },
      { SIMDE_FLOAT32_C(   -85.97), SIMDE_FLOAT32_C(  -897.59), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT32_C(       121),
      { SIMDE_FLOAT32_C(   393.73), SIMDE_FLOAT32_C(  -928.51), SIMDE_FLOAT32_C(   764.87), SIMDE_FLOAT32_C(   970.29) },
      { SIMDE_FLOAT32_C(   393.73), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   970.29) } },
    { UINT32_C(        43),
      { SIMDE_FLOAT32_C(   381.44), SIMDE_FLOAT32_C(   232.55), SIMDE_FLOAT32_C(  -696.33), SIMDE_FLOAT32_C(  -165.07) },
      { SIMDE_FLOAT32_C(   381.44), SIMDE_FLOAT32_C(   232.55), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -165.07) } },
    { UINT32_C(       120),
      { SIMDE_FLOAT32_C(   159.72), SIMDE_FLOAT32_C(   944.60), SIMDE_FLOAT32_C(   278.90), SIMDE_FLOAT32_C(  -735.96) },
      {         SIMDE_MATH_FLT_MAX, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -735.96) } },
    { UINT32_C(       232),
      { SIMDE_FLOAT32_C(  -393.48), SIMDE_FLOAT32_C(  -920.98), SIMDE_FLOAT32_C(  -723.12), SIMDE_FLOAT32_C(  -554.42) },
      {         SIMDE_MATH_FLT_MAX, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -554.42) } },
    { UINT32_C(        93),
      { SIMDE_FLOAT32_C(  -601.52), SIMDE_FLOAT32_C(  -229.16), SIMDE_FLOAT32_C(  -591.66), SIMDE_FLOAT32_C(   645.45) },
      { SIMDE_FLOAT32_C(  -601.52), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -591.66), SIMDE_FLOAT32_C(   645.45) } },
    { UINT32_C(       131),
      { SIMDE_FLOAT32_C(  -121.40), SIMDE_FLOAT32_C(  -440.52), SIMDE_FLOAT32_C(   121.78), SIMDE_FLOAT32_C(   774.99) },
      { SIMDE_FLOAT32_C(  -121.40), SIMDE_FLOAT32_C(  -440.52), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT32_C(       202),
      { SIMDE_FLOAT32_C(  -368.13), SIMDE_FLOAT32_C(   168.72), SIMDE_FLOAT32_C(   179.47), SIMDE_FLOAT32_C(  -603.26) },
      {         SIMDE_MATH_FLT_MAX, SIMDE_FLOAT32_C(   168.72), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -603.26) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde_float32 r[sizeof(simde__m128) / sizeof(simde_float32)] = {SIMDE_MATH_FLT_MAX};
    simde_mm_mask_storeu_ps(r, test_vec[i].k, a);
    simde_assert_equal_vf32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_float32 r[sizeof(simde__m128) / sizeof(simde_float32)] = {SIMDE_MATH_FLT_MAX};
    simde_mm_mask_storeu_ps(r, k, a);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vf32(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_storeu_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { UINT32_C(        57),
      { SIMDE_FLOAT64_C(   -75.95), SIMDE_FLOAT64_C(   987.10) },
      { SIMDE_FLOAT64_C(   -75.95), SIMDE_FLOAT64_C(     0.00) } },
    { UINT32_C(       210),
      { SIMDE_FLOAT64_C(   209.25), SIMDE_FLOAT64_C(  -929.03) },
      {         SIMDE_MATH_DBL_MAX, SIMDE_FLOAT64_C(  -929.03) } },
    { UINT32_C(       253),
      { SIMDE_FLOAT64_C(   576.24), SIMDE_FLOAT64_C(  -929.90) },
      { SIMDE_FLOAT64_C(   576.24), SIMDE_FLOAT64_C(     0.00) } },
    { UINT32_C(       144),
      { SIMDE_FLOAT64_C(   165.88), SIMDE_FLOAT64_C(  -437.65) },
      {         SIMDE_MATH_DBL_MAX, SIMDE_FLOAT64_C(     0.00) } },
    { UINT32_C(        39),
      { SIMDE_FLOAT64_C(  -552.28), SIMDE_FLOAT64_C(  -130.29) },
      { SIMDE_FLOAT64_C(  -552.28), SIMDE_FLOAT64_C(  -130.29) } },
    { UINT32_C(       140),
      { SIMDE_FLOAT64_C(  -669.61), SIMDE_FLOAT64_C(    20.93) },
      {         SIMDE_MATH_DBL_MAX, SIMDE_FLOAT64_C(     0.00) } },
    { UINT32_C(        73),
      { SIMDE_FLOAT64_C(   540.40), SIMDE_FLOAT64_C(  -325.95) },
      { SIMDE_FLOAT64_C(   540.40), SIMDE_FLOAT64_C(     0.00) } },
    { UINT32_C(       155),
      { SIMDE_FLOAT64_C(  -284.84), SIMDE_FLOAT64_C(   949.13) },
      { SIMDE_FLOAT64_C(  -284.84), SIMDE_FLOAT64_C(   949.13) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde_float64 r[sizeof(simde__m128d) / sizeof(simde_float64)] = {SIMDE_MATH_DBL_MAX};
    simde_mm_mask_storeu_pd(r, test_vec[i].k, a);
    simde_assert_equal_vf64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64 r[sizeof(simde__m128d) / sizeof(simde_float64)] = {SIMDE_MATH_DBL_MAX};
    simde_mm_mask_storeu_pd(r, k, a);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vf64(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_storeu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const int8_t r[32];
  } test_vec[] = {
    { {  INT8_C(  75),  INT8_C(  44),  INT8_C( 120), -INT8_C(  77), -INT8_C(  11), -INT8_C(  54), -INT8_C( 120), -INT8_C(  90),
         INT8_C(  76), -INT8_C( 120),  INT8_C(  18),  INT8_C( 102), -INT8_C(  27),  INT8_C( 105), -INT8_C(  91), -INT8_C(  67),
        -INT8_C( 127), -INT8_C(  90), -INT8_C(  52), -INT8_C(   1), -INT8_C( 106),  INT8_C(  47), -INT8_C( 109), -INT8_C( 117),
        -INT8_C(  83), -INT8_C(  57),  INT8_C(   1),  INT8_C( 120), -INT8_C(  46),  INT8_C(  84), -INT8_C(  19),  INT8_C(  30) },
      {  INT8_C(  75),  INT8_C(  44),  INT8_C( 120), -INT8_C(  77), -INT8_C(  11), -INT8_C(  54), -INT8_C( 120), -INT8_C(  90),
         INT8_C(  76), -INT8_C( 120),  INT8_C(  18),  INT8_C( 102), -INT8_C(  27),  INT8_C( 105), -INT8_C(  91), -INT8_C(  67),
        -INT8_C( 127), -INT8_C(  90), -INT8_C(  52), -INT8_C(   1), -INT8_C( 106),  INT8_C(  47), -INT8_C( 109), -INT8_C( 117),
        -INT8_C(  83), -INT8_C(  57),  INT8_C(   1),  INT8_C( 120), -INT8_C(  46),  INT8_C(  84), -INT8_C(  19),  INT8_C(  30) } },
    { {      INT8_MIN,  INT8_C( 101), -INT8_C(  47),  INT8_C( 117),  INT8_C(  47),  INT8_C(  90),  INT8_C(  28),  INT8_C( 124),
        -INT8_C(  30),  INT8_C(  46), -INT8_C(  30), -INT8_C(  57), -INT8_C( 105), -INT8_C( 121), -INT8_C( 124),  INT8_C(  25),
         INT8_C(  45),  INT8_C(  80),  INT8_C(  24), -INT8_C(  61),      INT8_MAX, -INT8_C(  85),  INT8_C(  79),  INT8_C(  44),
         INT8_C( 114),  INT8_C(  80), -INT8_C(  92),  INT8_C(  69), -INT8_C(  91), -INT8_C( 110),  INT8_C(  99),  INT8_C(  37) },
      {      INT8_MIN,  INT8_C( 101), -INT8_C(  47),  INT8_C( 117),  INT8_C(  47),  INT8_C(  90),  INT8_C(  28),  INT8_C( 124),
        -INT8_C(  30),  INT8_C(  46), -INT8_C(  30), -INT8_C(  57), -INT8_C( 105), -INT8_C( 121), -INT8_C( 124),  INT8_C(  25),
         INT8_C(  45),  INT8_C(  80),  INT8_C(  24), -INT8_C(  61),      INT8_MAX, -INT8_C(  85),  INT8_C(  79),  INT8_C(  44),
         INT8_C( 114),  INT8_C(  80), -INT8_C(  92),  INT8_C(  69), -INT8_C(  91), -INT8_C( 110),  INT8_C(  99),  INT8_C(  37) } },
    { { -INT8_C(   9),  INT8_C(  52), -INT8_C( 101),  INT8_C(  39), -INT8_C( 114), -INT8_C(  73), -INT8_C(  93),  INT8_C( 113),
        -INT8_C(  27), -INT8_C( 123),  INT8_C(  56),  INT8_C( 124),  INT8_C(  13), -INT8_C(  67), -INT8_C( 107),  INT8_C(  58),
         INT8_C(  13), -INT8_C(  82), -INT8_C(   2), -INT8_C( 115),  INT8_C(  89),  INT8_C(  77), -INT8_C(  71), -INT8_C(  52),
        -INT8_C(  99),  INT8_C(  94),  INT8_C(  17),  INT8_C(  66), -INT8_C(  16),  INT8_C( 116),  INT8_C( 104), -INT8_C(  25) },
      { -INT8_C(   9),  INT8_C(  52), -INT8_C( 101),  INT8_C(  39), -INT8_C( 114), -INT8_C(  73), -INT8_C(  93),  INT8_C( 113),
        -INT8_C(  27), -INT8_C( 123),  INT8_C(  56),  INT8_C( 124),  INT8_C(  13), -INT8_C(  67), -INT8_C( 107),  INT8_C(  58),
         INT8_C(  13), -INT8_C(  82), -INT8_C(   2), -INT8_C( 115),  INT8_C(  89),  INT8_C(  77), -INT8_C(  71), -INT8_C(  52),
        -INT8_C(  99),  INT8_C(  94),  INT8_C(  17),  INT8_C(  66), -INT8_C(  16),  INT8_C( 116),  INT8_C( 104), -INT8_C(  25) } },
    { { -INT8_C(  88),  INT8_C(   3),  INT8_C(  14),  INT8_C(  55), -INT8_C(  70), -INT8_C(  79), -INT8_C(  88), -INT8_C(  97),
         INT8_C(  55), -INT8_C(  32),  INT8_C(  27),  INT8_C(  68), -INT8_C(  99), -INT8_C(  79),  INT8_C( 126), -INT8_C(  85),
         INT8_C(  95),  INT8_C( 124),  INT8_C(  56), -INT8_C(  72), -INT8_C(  55), -INT8_C(  15), -INT8_C( 124),  INT8_C( 103),
         INT8_C(  79), -INT8_C( 107), -INT8_C(  87),  INT8_C(  63),  INT8_C(   9),  INT8_C(  17),  INT8_C(  39), -INT8_C(  78) },
      { -INT8_C(  88),  INT8_C(   3),  INT8_C(  14),  INT8_C(  55), -INT8_C(  70), -INT8_C(  79), -INT8_C(  88), -INT8_C(  97),
         INT8_C(  55), -INT8_C(  32),  INT8_C(  27),  INT8_C(  68), -INT8_C(  99), -INT8_C(  79),  INT8_C( 126), -INT8_C(  85),
         INT8_C(  95),  INT8_C( 124),  INT8_C(  56), -INT8_C(  72), -INT8_C(  55), -INT8_C(  15), -INT8_C( 124),  INT8_C( 103),
         INT8_C(  79), -INT8_C( 107), -INT8_C(  87),  INT8_C(  63),  INT8_C(   9),  INT8_C(  17),  INT8_C(  39), -INT8_C(  78) } },
    { {  INT8_C(  20),  INT8_C(  53), -INT8_C(  23), -INT8_C(  50), -INT8_C(  25), -INT8_C( 111),  INT8_C( 109),  INT8_C(  30),
         INT8_C( 113), -INT8_C( 119),  INT8_C(  98),  INT8_C(  15),  INT8_C(  58), -INT8_C(  32), -INT8_C(  70), -INT8_C( 103),
         INT8_C(  93), -INT8_C(  14),  INT8_C(  81),  INT8_C(  38), -INT8_C(  29), -INT8_C(  42), -INT8_C( 115),  INT8_C(  51),
         INT8_C( 107),  INT8_C(  55),  INT8_C( 114),  INT8_C( 117),  INT8_C(  72), -INT8_C( 103),  INT8_C(  39),  INT8_C(  93) },
      {  INT8_C(  20),  INT8_C(  53), -INT8_C(  23), -INT8_C(  50), -INT8_C(  25), -INT8_C( 111),  INT8_C( 109),  INT8_C(  30),
         INT8_C( 113), -INT8_C( 119),  INT8_C(  98),  INT8_C(  15),  INT8_C(  58), -INT8_C(  32), -INT8_C(  70), -INT8_C( 103),
         INT8_C(  93), -INT8_C(  14),  INT8_C(  81),  INT8_C(  38), -INT8_C(  29), -INT8_C(  42), -INT8_C( 115),  INT8_C(  51),
         INT8_C( 107),  INT8_C(  55),  INT8_C( 114),  INT8_C( 117),  INT8_C(  72), -INT8_C( 103),  INT8_C(  39),  INT8_C(  93) } },
    { { -INT8_C(  49),  INT8_C(  16),  INT8_C(  43), -INT8_C(  74), -INT8_C(  95), -INT8_C( 103), -INT8_C(  44),  INT8_C(  18),
         INT8_C(  34),  INT8_C(  54),  INT8_C(  33),  INT8_C(  92),  INT8_C(  22), -INT8_C(  37), -INT8_C(  11),  INT8_C( 115),
        -INT8_C(  51),  INT8_C(  70), -INT8_C( 102), -INT8_C(  79),  INT8_C(  28),  INT8_C(  39), -INT8_C(  28), -INT8_C( 120),
         INT8_C(  94),  INT8_C(  86), -INT8_C(   3), -INT8_C(  89), -INT8_C(  16),  INT8_C(  36),  INT8_C(   4), -INT8_C(  65) },
      { -INT8_C(  49),  INT8_C(  16),  INT8_C(  43), -INT8_C(  74), -INT8_C(  95), -INT8_C( 103), -INT8_C(  44),  INT8_C(  18),
         INT8_C(  34),  INT8_C(  54),  INT8_C(  33),  INT8_C(  92),  INT8_C(  22), -INT8_C(  37), -INT8_C(  11),  INT8_C( 115),
        -INT8_C(  51),  INT8_C(  70), -INT8_C( 102), -INT8_C(  79),  INT8_C(  28),  INT8_C(  39), -INT8_C(  28), -INT8_C( 120),
         INT8_C(  94),  INT8_C(  86), -INT8_C(   3), -INT8_C(  89), -INT8_C(  16),  INT8_C(  36),  INT8_C(   4), -INT8_C(  65) } },
    { {  INT8_C(  52),  INT8_C(  47),  INT8_C( 117), -INT8_C(  43), -INT8_C(  56),  INT8_C(  73), -INT8_C(  25), -INT8_C(  22),
             INT8_MAX,  INT8_C(   9),  INT8_C(  70), -INT8_C( 107), -INT8_C(  28),  INT8_C(  59),  INT8_C(   9), -INT8_C(  78),
        -INT8_C( 126), -INT8_C(  93),  INT8_C(  99), -INT8_C(  98), -INT8_C(  54),  INT8_C(  71),  INT8_C(  38),  INT8_C(  41),
        -INT8_C(  99),  INT8_C(  35), -INT8_C(  48), -INT8_C( 115),  INT8_C(  71), -INT8_C(  44),  INT8_C(  76),  INT8_C( 123) },
      {  INT8_C(  52),  INT8_C(  47),  INT8_C( 117), -INT8_C(  43), -INT8_C(  56),  INT8_C(  73), -INT8_C(  25), -INT8_C(  22),
             INT8_MAX,  INT8_C(   9),  INT8_C(  70), -INT8_C( 107), -INT8_C(  28),  INT8_C(  59),  INT8_C(   9), -INT8_C(  78),
        -INT8_C( 126), -INT8_C(  93),  INT8_C(  99), -INT8_C(  98), -INT8_C(  54),  INT8_C(  71),  INT8_C(  38),  INT8_C(  41),
        -INT8_C(  99),  INT8_C(  35), -INT8_C(  48), -INT8_C( 115),  INT8_C(  71), -INT8_C(  44),  INT8_C(  76),  INT8_C( 123) } },
    { {  INT8_C(   3), -INT8_C(  63),  INT8_C(  80), -INT8_C(  52),  INT8_C(  10),  INT8_C(  56), -INT8_C(  74), -INT8_C( 119),
         INT8_C(  65), -INT8_C(   3),  INT8_C(  31),  INT8_C(  37),  INT8_C(  56),  INT8_C(  40), -INT8_C(  41), -INT8_C(  70),
        -INT8_C(  53),  INT8_C(  58),  INT8_C(  89), -INT8_C( 107), -INT8_C( 127),      INT8_MAX, -INT8_C(  66),  INT8_C(  31),
        -INT8_C(  93), -INT8_C( 114), -INT8_C(  84), -INT8_C(  22),  INT8_C(  98), -INT8_C(   7),  INT8_C( 102),  INT8_C( 102) },
      {  INT8_C(   3), -INT8_C(  63),  INT8_C(  80), -INT8_C(  52),  INT8_C(  10),  INT8_C(  56), -INT8_C(  74), -INT8_C( 119),
         INT8_C(  65), -INT8_C(   3),  INT8_C(  31),  INT8_C(  37),  INT8_C(  56),  INT8_C(  40), -INT8_C(  41), -INT8_C(  70),
        -INT8_C(  53),  INT8_C(  58),  INT8_C(  89), -INT8_C( 107), -INT8_C( 127),      INT8_MAX, -INT8_C(  66),  INT8_C(  31),
        -INT8_C(  93), -INT8_C( 114), -INT8_C(  84), -INT8_C(  22),  INT8_C(  98), -INT8_C(   7),  INT8_C( 102),  INT8_C( 102) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    int8_t r[sizeof(simde__m256i) / sizeof(int8_t)] = {0};
    simde_mm256_storeu_epi8(r, a);
    simde_assert_equal_vi8(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i8x32();
    int8_t r[sizeof(simde__m256i) / sizeof(int8_t)] = {0};
    simde_mm256_storeu_epi8(r, a);

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi8(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_storeu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { {  INT16_C( 27201), -INT16_C( 10931),  INT16_C( 26543), -INT16_C( 17697), -INT16_C(  5170), -INT16_C(  2379),  INT16_C( 24504), -INT16_C( 22914),
         INT16_C(  3457), -INT16_C( 18629), -INT16_C(  4523),  INT16_C(  1253), -INT16_C(  9921),  INT16_C( 31191),  INT16_C(  9211),  INT16_C( 15721) },
      {  INT16_C( 27201), -INT16_C( 10931),  INT16_C( 26543), -INT16_C( 17697), -INT16_C(  5170), -INT16_C(  2379),  INT16_C( 24504), -INT16_C( 22914),
         INT16_C(  3457), -INT16_C( 18629), -INT16_C(  4523),  INT16_C(  1253), -INT16_C(  9921),  INT16_C( 31191),  INT16_C(  9211),  INT16_C( 15721) } },
    { { -INT16_C( 18803),  INT16_C( 15634), -INT16_C(  3810), -INT16_C(  4873), -INT16_C( 21283), -INT16_C( 27166),  INT16_C( 24587), -INT16_C( 29381),
         INT16_C( 30573), -INT16_C( 15804),  INT16_C( 10597), -INT16_C( 23097), -INT16_C( 25086), -INT16_C(   482), -INT16_C( 30782),  INT16_C( 20283) },
      { -INT16_C( 18803),  INT16_C( 15634), -INT16_C(  3810), -INT16_C(  4873), -INT16_C( 21283), -INT16_C( 27166),  INT16_C( 24587), -INT16_C( 29381),
         INT16_C( 30573), -INT16_C( 15804),  INT16_C( 10597), -INT16_C( 23097), -INT16_C( 25086), -INT16_C(   482), -INT16_C( 30782),  INT16_C( 20283) } },
    { {  INT16_C( 19773),  INT16_C( 23436), -INT16_C( 31938),  INT16_C(  6983),  INT16_C( 10544),  INT16_C( 15281), -INT16_C(  4982), -INT16_C(  2104),
         INT16_C(  3171), -INT16_C( 13894), -INT16_C( 32458),  INT16_C( 14446), -INT16_C( 29665), -INT16_C(  7882),  INT16_C( 28947),  INT16_C( 20529) },
      {  INT16_C( 19773),  INT16_C( 23436), -INT16_C( 31938),  INT16_C(  6983),  INT16_C( 10544),  INT16_C( 15281), -INT16_C(  4982), -INT16_C(  2104),
         INT16_C(  3171), -INT16_C( 13894), -INT16_C( 32458),  INT16_C( 14446), -INT16_C( 29665), -INT16_C(  7882),  INT16_C( 28947),  INT16_C( 20529) } },
    { { -INT16_C( 16962), -INT16_C(   596), -INT16_C(  3263),  INT16_C( 28952), -INT16_C( 14051), -INT16_C( 22612),  INT16_C( 30134),  INT16_C(  6558),
         INT16_C( 22657), -INT16_C( 18462),  INT16_C( 20697), -INT16_C(  1552),  INT16_C(  9948), -INT16_C(  4134),  INT16_C(  2968),  INT16_C( 22080) },
      { -INT16_C( 16962), -INT16_C(   596), -INT16_C(  3263),  INT16_C( 28952), -INT16_C( 14051), -INT16_C( 22612),  INT16_C( 30134),  INT16_C(  6558),
         INT16_C( 22657), -INT16_C( 18462),  INT16_C( 20697), -INT16_C(  1552),  INT16_C(  9948), -INT16_C(  4134),  INT16_C(  2968),  INT16_C( 22080) } },
    { { -INT16_C(  4919),  INT16_C(  2643),  INT16_C( 27871), -INT16_C(   901),  INT16_C( 10037), -INT16_C(  5213),  INT16_C( 17052),  INT16_C(  7685),
        -INT16_C(  6246),  INT16_C( 29909), -INT16_C( 15048),  INT16_C(  5229),  INT16_C( 18412), -INT16_C( 31740),  INT16_C( 17491),  INT16_C(  7386) },
      { -INT16_C(  4919),  INT16_C(  2643),  INT16_C( 27871), -INT16_C(   901),  INT16_C( 10037), -INT16_C(  5213),  INT16_C( 17052),  INT16_C(  7685),
        -INT16_C(  6246),  INT16_C( 29909), -INT16_C( 15048),  INT16_C(  5229),  INT16_C( 18412), -INT16_C( 31740),  INT16_C( 17491),  INT16_C(  7386) } },
    { {  INT16_C( 11824),  INT16_C(  3878), -INT16_C( 24166), -INT16_C( 12532), -INT16_C( 20536),  INT16_C( 26043), -INT16_C( 16143), -INT16_C( 29565),
         INT16_C( 22695), -INT16_C(  8448),  INT16_C( 27934),  INT16_C(  2804), -INT16_C(  1868),  INT16_C(  1934),  INT16_C( 26684),  INT16_C( 27683) },
      {  INT16_C( 11824),  INT16_C(  3878), -INT16_C( 24166), -INT16_C( 12532), -INT16_C( 20536),  INT16_C( 26043), -INT16_C( 16143), -INT16_C( 29565),
         INT16_C( 22695), -INT16_C(  8448),  INT16_C( 27934),  INT16_C(  2804), -INT16_C(  1868),  INT16_C(  1934),  INT16_C( 26684),  INT16_C( 27683) } },
    { {  INT16_C( 18838),  INT16_C( 12411), -INT16_C( 30742), -INT16_C( 19712), -INT16_C( 17609),  INT16_C( 10264), -INT16_C( 25733),  INT16_C(  8884),
        -INT16_C( 19213),  INT16_C(  4354), -INT16_C(  2527), -INT16_C( 10725), -INT16_C( 22034),  INT16_C( 10973),  INT16_C(   274), -INT16_C( 22378) },
      {  INT16_C( 18838),  INT16_C( 12411), -INT16_C( 30742), -INT16_C( 19712), -INT16_C( 17609),  INT16_C( 10264), -INT16_C( 25733),  INT16_C(  8884),
        -INT16_C( 19213),  INT16_C(  4354), -INT16_C(  2527), -INT16_C( 10725), -INT16_C( 22034),  INT16_C( 10973),  INT16_C(   274), -INT16_C( 22378) } },
    { {  INT16_C(  4426),  INT16_C( 13785), -INT16_C(  9831), -INT16_C( 12056),  INT16_C(   148),  INT16_C(  4088), -INT16_C( 21093), -INT16_C( 29135),
         INT16_C( 13153), -INT16_C( 31840), -INT16_C( 17623),  INT16_C(  5977),  INT16_C( 13925),  INT16_C( 30529), -INT16_C( 10441), -INT16_C( 32225) },
      {  INT16_C(  4426),  INT16_C( 13785), -INT16_C(  9831), -INT16_C( 12056),  INT16_C(   148),  INT16_C(  4088), -INT16_C( 21093), -INT16_C( 29135),
         INT16_C( 13153), -INT16_C( 31840), -INT16_C( 17623),  INT16_C(  5977),  INT16_C( 13925),  INT16_C( 30529), -INT16_C( 10441), -INT16_C( 32225) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    int16_t r[sizeof(simde__m256i) / sizeof(int16_t)] = {0};
    simde_mm256_storeu_epi16(r, a);
    simde_assert_equal_vi16(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i16x16();
    int16_t r[sizeof(simde__m256i) / sizeof(int16_t)] = {0};
    simde_mm256_storeu_epi16(r, a);

    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi16(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_storeu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int8_t a[32];
    const int8_t r[32];
  } test_vec[] = {
    { UINT32_C(3182572817),
      {  INT8_C(  69), -INT8_C(  42), -INT8_C( 103), -INT8_C(  76), -INT8_C( 108), -INT8_C(  47), -INT8_C(  14),  INT8_C(  32),
        -INT8_C( 125), -INT8_C(  12), -INT8_C(  95), -INT8_C(  39), -INT8_C(  20),  INT8_C(  36),  INT8_C( 123), -INT8_C( 120),
         INT8_C(  92),  INT8_C( 114), -INT8_C(  70), -INT8_C(  66), -INT8_C(  90),  INT8_C(   9),  INT8_C( 124), -INT8_C(  52),
         INT8_C(  64), -INT8_C(   2), -INT8_C( 105),  INT8_C(  81),  INT8_C(  52),  INT8_C(  73),  INT8_C(  15),  INT8_C( 121) },
      {  INT8_C(  69),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 108),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C( 125),  INT8_C(   0), -INT8_C(  95),  INT8_C(   0), -INT8_C(  20),  INT8_C(  36),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C( 114),  INT8_C(   0),  INT8_C(   0), -INT8_C(  90),  INT8_C(   9),  INT8_C(   0), -INT8_C(  52),
         INT8_C(  64),  INT8_C(   0), -INT8_C( 105),  INT8_C(  81),  INT8_C(  52),  INT8_C(  73),  INT8_C(   0),  INT8_C( 121) } },
    { UINT32_C(3006113823),
      {  INT8_C( 121),  INT8_C(  31), -INT8_C(  44), -INT8_C(   3),  INT8_C(  19),  INT8_C( 117), -INT8_C(  42), -INT8_C(   1),
        -INT8_C( 103),  INT8_C(  81), -INT8_C( 121), -INT8_C(  10), -INT8_C(  60),  INT8_C(  65), -INT8_C(  76),  INT8_C( 106),
         INT8_C(  75),  INT8_C(  48),  INT8_C(  54), -INT8_C( 117),  INT8_C(  47), -INT8_C(  51), -INT8_C(  35),  INT8_C(  99),
         INT8_C(  22), -INT8_C(  20), -INT8_C(  36),  INT8_C(  53), -INT8_C( 108),  INT8_C(   9), -INT8_C(  23),  INT8_C(  14) },
      {  INT8_C( 121),  INT8_C(  31), -INT8_C(  44), -INT8_C(   3),  INT8_C(  19),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  10),  INT8_C(   0),  INT8_C(  65),  INT8_C(   0),  INT8_C( 106),
         INT8_C(  75),  INT8_C(   0),  INT8_C(  54), -INT8_C( 117),  INT8_C(   0), -INT8_C(  51),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  22), -INT8_C(  20),  INT8_C(   0),  INT8_C(   0), -INT8_C( 108),  INT8_C(   9),  INT8_C(   0),  INT8_C(  14) } },
    { UINT32_C(1007402280),
      {  INT8_C(  50), -INT8_C(  31),  INT8_C(  59), -INT8_C(  53),  INT8_C(  50), -INT8_C(  61), -INT8_C(  63), -INT8_C(  10),
         INT8_C(   4),  INT8_C( 117),  INT8_C(  96),  INT8_C(  79), -INT8_C(  90), -INT8_C( 106), -INT8_C(  37), -INT8_C(  43),
         INT8_C(  99), -INT8_C(  72),  INT8_C(  56),  INT8_C( 121), -INT8_C(  92),  INT8_C(  20), -INT8_C(  81),  INT8_C(  56),
         INT8_C(  29), -INT8_C( 104),  INT8_C(  70),  INT8_C(  69),  INT8_C(  85),  INT8_C(  81), -INT8_C( 127), -INT8_C( 121) },
      {      INT8_MAX,  INT8_C(   0),  INT8_C(   0), -INT8_C(  53),  INT8_C(   0), -INT8_C(  61),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   4),  INT8_C(   0),  INT8_C(  96),  INT8_C(  79), -INT8_C(  90), -INT8_C( 106),  INT8_C(   0), -INT8_C(  43),
         INT8_C(  99), -INT8_C(  72),  INT8_C(   0),  INT8_C( 121),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  70),  INT8_C(  69),  INT8_C(  85),  INT8_C(  81),  INT8_C(   0),  INT8_C(   0) } },
    { UINT32_C(1699921202),
      {      INT8_MIN,  INT8_C(  20),  INT8_C(  91), -INT8_C( 124), -INT8_C( 119), -INT8_C(  68), -INT8_C(  44),  INT8_C(  47),
         INT8_C(  82), -INT8_C(  81),  INT8_C(   4), -INT8_C(  74),  INT8_C( 103),  INT8_C(  60),  INT8_C(  47),  INT8_C(  11),
         INT8_C(  80), -INT8_C(  34),  INT8_C(  67),  INT8_C( 109),  INT8_C( 118), -INT8_C( 118), -INT8_C(  77), -INT8_C(  53),
        -INT8_C(  37),  INT8_C(  52),  INT8_C(  82),  INT8_C(  14), -INT8_C(  15), -INT8_C(  91),  INT8_C( 115),  INT8_C( 113) },
      {      INT8_MAX,  INT8_C(  20),  INT8_C(   0),  INT8_C(   0), -INT8_C( 119), -INT8_C(  68),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  82),  INT8_C(   0),  INT8_C(   4), -INT8_C(  74),  INT8_C( 103),  INT8_C(  60),  INT8_C(   0),  INT8_C(  11),
         INT8_C(   0), -INT8_C(  34),  INT8_C(   0),  INT8_C(   0),  INT8_C( 118),  INT8_C(   0), -INT8_C(  77),  INT8_C(   0),
        -INT8_C(  37),  INT8_C(   0),  INT8_C(  82),  INT8_C(   0),  INT8_C(   0), -INT8_C(  91),  INT8_C( 115),  INT8_C(   0) } },
    { UINT32_C(1123471033),
      { -INT8_C( 118), -INT8_C(  54),  INT8_C( 114), -INT8_C(  35),  INT8_C( 121),  INT8_C( 118), -INT8_C( 109), -INT8_C(  32),
        -INT8_C(  77), -INT8_C(  62), -INT8_C(  21),  INT8_C(   3), -INT8_C(  95),  INT8_C(  46),  INT8_C( 113),  INT8_C(  23),
        -INT8_C(  72),  INT8_C(  36), -INT8_C(  29), -INT8_C( 108),  INT8_C(  88),  INT8_C(  53), -INT8_C(  94),  INT8_C(  74),
        -INT8_C(  38),  INT8_C(  21), -INT8_C(  69), -INT8_C( 109), -INT8_C(  29), -INT8_C(  79), -INT8_C(  42),  INT8_C( 110) },
      { -INT8_C( 118),  INT8_C(   0),  INT8_C(   0), -INT8_C(  35),  INT8_C( 121),  INT8_C( 118),  INT8_C(   0), -INT8_C(  32),
         INT8_C(   0), -INT8_C(  62), -INT8_C(  21),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C( 113),  INT8_C(  23),
         INT8_C(   0),  INT8_C(  36), -INT8_C(  29),  INT8_C(   0),  INT8_C(  88),  INT8_C(  53), -INT8_C(  94),  INT8_C(  74),
         INT8_C(   0),  INT8_C(  21),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  42),  INT8_C(   0) } },
    { UINT32_C(4098574459),
      { -INT8_C(  66), -INT8_C(  34), -INT8_C(  44),  INT8_C( 113), -INT8_C(  96), -INT8_C(  65),  INT8_C( 117),  INT8_C(  65),
        -INT8_C(  18), -INT8_C(  26),  INT8_C(  89), -INT8_C(  90),  INT8_C(  10),  INT8_C(  60),  INT8_C(  58),  INT8_C(  98),
         INT8_C( 113), -INT8_C(  36), -INT8_C(  84),  INT8_C(  76), -INT8_C(  15),  INT8_C( 104), -INT8_C(  33), -INT8_C(  43),
         INT8_C(  25), -INT8_C(  75),  INT8_C(  67), -INT8_C( 107), -INT8_C(   3), -INT8_C( 114), -INT8_C( 119), -INT8_C(  68) },
      { -INT8_C(  66), -INT8_C(  34),  INT8_C(   0),  INT8_C( 113), -INT8_C(  96), -INT8_C(  65),  INT8_C( 117),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  90),  INT8_C(   0),  INT8_C(   0),  INT8_C(  58),  INT8_C(   0),
         INT8_C( 113), -INT8_C(  36),  INT8_C(   0),  INT8_C(  76),  INT8_C(   0),  INT8_C(   0), -INT8_C(  33),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  67),  INT8_C(   0), -INT8_C(   3), -INT8_C( 114), -INT8_C( 119), -INT8_C(  68) } },
    { UINT32_C( 204299884),
      {  INT8_C(  29), -INT8_C(  94),  INT8_C(  78),  INT8_C(  11), -INT8_C( 120), -INT8_C(  89), -INT8_C(  78), -INT8_C( 110),
        -INT8_C(  29), -INT8_C(  20), -INT8_C(  11),  INT8_C(  84), -INT8_C(  55), -INT8_C(  95), -INT8_C(  96), -INT8_C(  70),
         INT8_C(   9),      INT8_MIN, -INT8_C( 113),  INT8_C(  35),  INT8_C(  53), -INT8_C(  46), -INT8_C(  72),  INT8_C(  51),
         INT8_C(  96),  INT8_C(  65), -INT8_C(  17), -INT8_C(  52), -INT8_C(  97),  INT8_C(  28), -INT8_C(  39), -INT8_C(  67) },
      {      INT8_MAX,  INT8_C(   0),  INT8_C(  78),  INT8_C(  11),  INT8_C(   0), -INT8_C(  89), -INT8_C(  78),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  20), -INT8_C(  11),  INT8_C(  84), -INT8_C(  55),  INT8_C(   0), -INT8_C(  96),  INT8_C(   0),
         INT8_C(   9),  INT8_C(   0), -INT8_C( 113),  INT8_C(  35),  INT8_C(   0), -INT8_C(  46),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  52),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT32_C(1204299711),
      { -INT8_C(  50),  INT8_C( 122), -INT8_C(  38), -INT8_C(  79),  INT8_C( 103), -INT8_C(  49),  INT8_C(   5),  INT8_C(  48),
         INT8_C( 112), -INT8_C(  90), -INT8_C(  22),  INT8_C( 122),  INT8_C(  38),  INT8_C( 122), -INT8_C(  99),  INT8_C(  91),
         INT8_C(  76),  INT8_C(  85), -INT8_C( 114), -INT8_C(  83), -INT8_C( 106),  INT8_C( 125),  INT8_C( 121),  INT8_C(  54),
        -INT8_C( 102),  INT8_C(  82), -INT8_C(  13),  INT8_C(  89),  INT8_C( 121), -INT8_C(  69), -INT8_C(  96),  INT8_C(  71) },
      { -INT8_C(  50),  INT8_C( 122), -INT8_C(  38), -INT8_C(  79),  INT8_C( 103), -INT8_C(  49),  INT8_C(   0),  INT8_C(  48),
         INT8_C( 112), -INT8_C(  90), -INT8_C(  22),  INT8_C(   0),  INT8_C(   0),  INT8_C( 122),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  83),  INT8_C(   0),  INT8_C(   0),  INT8_C( 121),  INT8_C(  54),
        -INT8_C( 102),  INT8_C(  82), -INT8_C(  13),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  96),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi8(test_vec[i].a);
    int8_t r[sizeof(simde__m256i) / sizeof(int8_t)] = {INT8_MAX};
    simde_mm256_mask_storeu_epi8(r, test_vec[i].k, a);
    simde_assert_equal_vi8(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m256i a = simde_test_x86_random_i8x32();
    int8_t r[sizeof(simde__m256i) / sizeof(int8_t)] = {INT8_MAX};
    simde_mm256_mask_storeu_epi8(r, k, a);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vi8(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_storeu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { UINT16_C(14195),
      {  INT16_C( 28254),  INT16_C( 12017), -INT16_C(  6021),  INT16_C( 21613), -INT16_C( 18331),  INT16_C( 20927), -INT16_C( 17156), -INT16_C(  3395),
         INT16_C(  4436), -INT16_C( 15786), -INT16_C( 20629),  INT16_C( 17543),  INT16_C(  6926),  INT16_C( 11805), -INT16_C( 28253),  INT16_C(   357) },
      {  INT16_C( 28254),  INT16_C( 12017),  INT16_C(     0),  INT16_C(     0), -INT16_C( 18331),  INT16_C( 20927), -INT16_C( 17156),  INT16_C(     0),
         INT16_C(  4436), -INT16_C( 15786), -INT16_C( 20629),  INT16_C(     0),  INT16_C(  6926),  INT16_C( 11805),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(22527),
      {  INT16_C( 31280), -INT16_C( 25281), -INT16_C( 23089), -INT16_C( 29099),  INT16_C( 20982), -INT16_C( 19638), -INT16_C( 25020), -INT16_C( 25916),
         INT16_C( 12128), -INT16_C(  6326),  INT16_C( 22643), -INT16_C( 28414), -INT16_C( 23161), -INT16_C(  5086),  INT16_C(  8615), -INT16_C( 10429) },
      {  INT16_C( 31280), -INT16_C( 25281), -INT16_C( 23089), -INT16_C( 29099),  INT16_C( 20982), -INT16_C( 19638), -INT16_C( 25020), -INT16_C( 25916),
         INT16_C( 12128), -INT16_C(  6326),  INT16_C( 22643),  INT16_C(     0), -INT16_C( 23161),  INT16_C(     0),  INT16_C(  8615),  INT16_C(     0) } },
    { UINT16_C(33692),
      {  INT16_C( 27508), -INT16_C( 14040),  INT16_C(  7929),  INT16_C( 17178),  INT16_C( 24273), -INT16_C( 26911),  INT16_C( 16889),  INT16_C( 17349),
         INT16_C( 14633),  INT16_C( 11163),  INT16_C(  8906), -INT16_C(  4911),  INT16_C( 30735),  INT16_C( 21005), -INT16_C( 22193), -INT16_C( 15403) },
      {        INT16_MAX,  INT16_C(     0),  INT16_C(  7929),  INT16_C( 17178),  INT16_C( 24273),  INT16_C(     0),  INT16_C(     0),  INT16_C( 17349),
         INT16_C( 14633),  INT16_C( 11163),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 15403) } },
    { UINT16_C(64788),
      {  INT16_C(  3468), -INT16_C( 23013), -INT16_C(  4784),  INT16_C( 12549), -INT16_C(   381),  INT16_C( 18547), -INT16_C( 25535), -INT16_C(  9087),
         INT16_C( 19399), -INT16_C( 26369),  INT16_C(  3639),  INT16_C( 17680),  INT16_C( 24416),  INT16_C( 14062),  INT16_C(   802), -INT16_C( 20941) },
      {        INT16_MAX,  INT16_C(     0), -INT16_C(  4784),  INT16_C(     0), -INT16_C(   381),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 19399),  INT16_C(     0),  INT16_C(  3639),  INT16_C( 17680),  INT16_C( 24416),  INT16_C( 14062),  INT16_C(   802), -INT16_C( 20941) } },
    { UINT16_C(20240),
      {  INT16_C( 24917),  INT16_C( 23100), -INT16_C( 16494),  INT16_C(  1368), -INT16_C( 26361), -INT16_C( 30303),  INT16_C( 26997),  INT16_C( 29908),
         INT16_C(  3073),  INT16_C(  4738), -INT16_C(  7343),  INT16_C( 16241), -INT16_C( 27623),  INT16_C( 19522),  INT16_C( 21314), -INT16_C( 26725) },
      {        INT16_MAX,  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 26361),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(  3073),  INT16_C(  4738), -INT16_C(  7343),  INT16_C( 16241),  INT16_C(     0),  INT16_C(     0),  INT16_C( 21314),  INT16_C(     0) } },
    { UINT16_C(55220),
      {  INT16_C( 18161),  INT16_C( 18838), -INT16_C( 25012), -INT16_C(  4638),  INT16_C( 22567), -INT16_C(  1194),  INT16_C( 22732),  INT16_C( 20231),
         INT16_C( 22634), -INT16_C(  9422),  INT16_C( 19352), -INT16_C(  9617), -INT16_C( 19817),  INT16_C( 13101), -INT16_C(  7863),  INT16_C( 15114) },
      {        INT16_MAX,  INT16_C(     0), -INT16_C( 25012),  INT16_C(     0),  INT16_C( 22567), -INT16_C(  1194),  INT16_C(     0),  INT16_C( 20231),
         INT16_C( 22634), -INT16_C(  9422),  INT16_C( 19352),  INT16_C(     0), -INT16_C( 19817),  INT16_C(     0), -INT16_C(  7863),  INT16_C( 15114) } },
    { UINT16_C(41256),
      {  INT16_C( 29828),  INT16_C( 26431),  INT16_C( 26209), -INT16_C( 18241), -INT16_C( 29855),  INT16_C( 26896),  INT16_C( 31450),  INT16_C(  3265),
         INT16_C( 22869), -INT16_C( 15017), -INT16_C(  4300),  INT16_C( 24951), -INT16_C( 16350),  INT16_C( 11331),  INT16_C( 27643), -INT16_C( 32563) },
      {        INT16_MAX,  INT16_C(     0),  INT16_C(     0), -INT16_C( 18241),  INT16_C(     0),  INT16_C( 26896),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 22869),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 11331),  INT16_C(     0), -INT16_C( 32563) } },
    { UINT16_C( 3295),
      {  INT16_C( 16615), -INT16_C( 22926), -INT16_C( 11016),  INT16_C(  2097),  INT16_C(  3133), -INT16_C(   382), -INT16_C( 10216),  INT16_C( 28760),
        -INT16_C( 29539),  INT16_C(  5215), -INT16_C( 32275),  INT16_C( 12500), -INT16_C( 12115),  INT16_C( 31643),  INT16_C( 31312),  INT16_C( 14215) },
      {  INT16_C( 16615), -INT16_C( 22926), -INT16_C( 11016),  INT16_C(  2097),  INT16_C(  3133),  INT16_C(     0), -INT16_C( 10216),  INT16_C( 28760),
         INT16_C(     0),  INT16_C(     0), -INT16_C( 32275),  INT16_C( 12500),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    int16_t r[sizeof(simde__m256i) / sizeof(int16_t)] = {INT16_MAX};
    simde_mm256_mask_storeu_epi16(r, test_vec[i].k, a);
    simde_assert_equal_vi16(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i16x16();
    int16_t r[sizeof(simde__m256i) / sizeof(int16_t)] = {INT16_MAX};
    simde_mm256_mask_storeu_epi16(r, k, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vi16(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_storeu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(187),
      { -INT32_C(   827073030),  INT32_C(   436976654),  INT32_C(   372443454), -INT32_C(   306994335), -INT32_C(  2082748670),  INT32_C(  1815088028),  INT32_C(   566012839),  INT32_C(   769454899) },
      { -INT32_C(   827073030),  INT32_C(   436976654),  INT32_C(           0), -INT32_C(   306994335), -INT32_C(  2082748670),  INT32_C(  1815088028),  INT32_C(           0),  INT32_C(   769454899) } },
    { UINT8_C(208),
      {  INT32_C(  1289681808),  INT32_C(   260765958), -INT32_C(   814636756),  INT32_C(   483483220),  INT32_C(  1169708089),  INT32_C(   820782212), -INT32_C(   748483104),  INT32_C(  2057539818) },
      {              INT32_MAX,  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1169708089),  INT32_C(           0), -INT32_C(   748483104),  INT32_C(  2057539818) } },
    { UINT8_C(139),
      {  INT32_C(  2056373889), -INT32_C(   240738224),  INT32_C(  1883665681), -INT32_C(  1700175290),  INT32_C(  1042279962), -INT32_C(   400666662),  INT32_C(  1121120690),  INT32_C(   365776020) },
      {  INT32_C(  2056373889), -INT32_C(   240738224),  INT32_C(           0), -INT32_C(  1700175290),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   365776020) } },
    { UINT8_C( 18),
      { -INT32_C(    27094946), -INT32_C(  1408216010), -INT32_C(    51216230),  INT32_C(   404131113), -INT32_C(    68004692),  INT32_C(  1672338034), -INT32_C(   117968980),  INT32_C(   436866236) },
      {              INT32_MAX, -INT32_C(  1408216010),  INT32_C(           0),  INT32_C(           0), -INT32_C(    68004692),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(156),
      { -INT32_C(  1043130259), -INT32_C(  1470398680), -INT32_C(    19769487), -INT32_C(  1045763475), -INT32_C(  1221351972),  INT32_C(  1097045586), -INT32_C(  1711448947), -INT32_C(   751429786) },
      {              INT32_MAX,  INT32_C(           0), -INT32_C(    19769487), -INT32_C(  1045763475), -INT32_C(  1221351972),  INT32_C(           0),  INT32_C(           0), -INT32_C(   751429786) } },
    { UINT8_C( 48),
      { -INT32_C(  2007460855),  INT32_C(  1190724079), -INT32_C(  1112278829),  INT32_C(  1218016418),  INT32_C(  1033523367),  INT32_C(   281730228), -INT32_C(   243899175), -INT32_C(  1558099302) },
      {              INT32_MAX,  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1033523367),  INT32_C(   281730228),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(222),
      {  INT32_C(  2060331897),  INT32_C(   474813476),  INT32_C(  1019153096), -INT32_C(   186382428),  INT32_C(  2108170657),  INT32_C(  1347926252),  INT32_C(  2045397039), -INT32_C(   497578647) },
      {              INT32_MAX,  INT32_C(   474813476),  INT32_C(  1019153096), -INT32_C(   186382428),  INT32_C(  2108170657),  INT32_C(           0),  INT32_C(  2045397039), -INT32_C(   497578647) } },
    { UINT8_C(184),
      {  INT32_C(   987520293), -INT32_C(  1258096214), -INT32_C(  1084670280),  INT32_C(  1147161890), -INT32_C(  1372528906),  INT32_C(  2111668277), -INT32_C(   135899542), -INT32_C(   743454546) },
      {              INT32_MAX,  INT32_C(           0),  INT32_C(           0),  INT32_C(  1147161890), -INT32_C(  1372528906),  INT32_C(  2111668277),  INT32_C(           0), -INT32_C(   743454546) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    int32_t r[sizeof(simde__m256i) / sizeof(int32_t)] = {INT32_MAX};
    simde_mm256_mask_storeu_epi32(r, test_vec[i].k, a);
    simde_assert_equal_vi32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    int32_t r[sizeof(simde__m256i) / sizeof(int32_t)] = {INT32_MAX};
    simde_mm256_mask_storeu_epi32(r, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vi32(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_storeu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C( 37),
      {  INT64_C( 5637527135260249483),  INT64_C( 4188827436390087646),  INT64_C(  346474450812653796),  INT64_C(   54189931386553810) },
      {  INT64_C( 5637527135260249483),  INT64_C(                   0),  INT64_C(  346474450812653796),  INT64_C(                   0) } },
    { UINT8_C(147),
      { -INT64_C( 4831253263156083568),  INT64_C( 1223380683969797729), -INT64_C(  972846592556179775),  INT64_C( 7677625654944668275) },
      { -INT64_C( 4831253263156083568),  INT64_C( 1223380683969797729),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(235),
      { -INT64_C( 8034305796350378194), -INT64_C( 1254850012797430399), -INT64_C( 2534667036809018466), -INT64_C( 8734977386246386572) },
      { -INT64_C( 8034305796350378194), -INT64_C( 1254850012797430399),  INT64_C(                   0), -INT64_C( 8734977386246386572) } },
    { UINT8_C(159),
      { -INT64_C( 4945337057316592269),  INT64_C(  788473838513566322), -INT64_C( 1164838959175610285), -INT64_C( 1503975258598166176) },
      { -INT64_C( 4945337057316592269),  INT64_C(  788473838513566322), -INT64_C( 1164838959175610285), -INT64_C( 1503975258598166176) } },
    { UINT8_C(115),
      {  INT64_C( 6360864049442965553), -INT64_C( 2726319848616388194),  INT64_C( 1297297696251350007), -INT64_C( 3281305944083234507) },
      {  INT64_C( 6360864049442965553), -INT64_C( 2726319848616388194),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 61),
      { -INT64_C( 8862314492757563889), -INT64_C( 8071320232975672869),  INT64_C( 2164545447827381479), -INT64_C( 7836384834745332340) },
      { -INT64_C( 8862314492757563889),  INT64_C(                   0),  INT64_C( 2164545447827381479), -INT64_C( 7836384834745332340) } },
    { UINT8_C( 55),
      { -INT64_C( 3370477061425334622), -INT64_C( 2988028149774336329),  INT64_C( 8422454126154308948), -INT64_C( 4244208191866870960) },
      { -INT64_C( 3370477061425334622), -INT64_C( 2988028149774336329),  INT64_C( 8422454126154308948),  INT64_C(                   0) } },
    { UINT8_C(129),
      { -INT64_C( 7305600158166015171),  INT64_C( 2655059749943655968), -INT64_C(  864691056790524386),  INT64_C( 4036593039313396472) },
      { -INT64_C( 7305600158166015171),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    int64_t r[sizeof(simde__m256i) / sizeof(int64_t)] = {INT64_MAX};
    simde_mm256_mask_storeu_epi64(r, test_vec[i].k, a);
    simde_assert_equal_vi64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    int64_t r[sizeof(simde__m256i) / sizeof(int64_t)] = {INT64_MAX};
    simde_mm256_mask_storeu_epi64(r, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vi64(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_storeu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(  2101872407),  INT32_C(  1699913681),  INT32_C(   980699807),  INT32_C(  1506322167),  INT32_C(    64776409), -INT32_C(  1994771164), -INT32_C(  1560257429),  INT32_C(   472194867) },
      { -INT32_C(  2101872407),  INT32_C(  1699913681),  INT32_C(   980699807),  INT32_C(  1506322167),  INT32_C(    64776409), -INT32_C(  1994771164), -INT32_C(  1560257429),  INT32_C(   472194867) } },
    { { -INT32_C(   375464936),  INT32_C(   441446523),  INT32_C(   844415803),  INT32_C(  1133190249), -INT32_C(  1455003771),  INT32_C(   137519260), -INT32_C(   257215812),  INT32_C(  1762447441) },
      { -INT32_C(   375464936),  INT32_C(   441446523),  INT32_C(   844415803),  INT32_C(  1133190249), -INT32_C(  1455003771),  INT32_C(   137519260), -INT32_C(   257215812),  INT32_C(  1762447441) } },
    { {  INT32_C(   659794860), -INT32_C(   700341605), -INT32_C(   821455515),  INT32_C(   907187377), -INT32_C(  1730193156),  INT32_C(  1973424568), -INT32_C(  1788523709), -INT32_C(   939626213) },
      {  INT32_C(   659794860), -INT32_C(   700341605), -INT32_C(   821455515),  INT32_C(   907187377), -INT32_C(  1730193156),  INT32_C(  1973424568), -INT32_C(  1788523709), -INT32_C(   939626213) } },
    { { -INT32_C(  1192341220),  INT32_C(  1502490611),  INT32_C(  1982371780),  INT32_C(   682375724),  INT32_C(  1254132882), -INT32_C(   507551331), -INT32_C(   931781460), -INT32_C(  1299221354) },
      { -INT32_C(  1192341220),  INT32_C(  1502490611),  INT32_C(  1982371780),  INT32_C(   682375724),  INT32_C(  1254132882), -INT32_C(   507551331), -INT32_C(   931781460), -INT32_C(  1299221354) } },
    { { -INT32_C(  1184203066),  INT32_C(  1913846189), -INT32_C(  1125631344),  INT32_C(   115643508), -INT32_C(  1101945568), -INT32_C(  1298198522), -INT32_C(   881191627),  INT32_C(  1333594761) },
      { -INT32_C(  1184203066),  INT32_C(  1913846189), -INT32_C(  1125631344),  INT32_C(   115643508), -INT32_C(  1101945568), -INT32_C(  1298198522), -INT32_C(   881191627),  INT32_C(  1333594761) } },
    { {  INT32_C(   889841800),  INT32_C(  1906777057), -INT32_C(   902918314),  INT32_C(  1154552356), -INT32_C(  1123933513),  INT32_C(  1735434546),  INT32_C(  1077078710),  INT32_C(  2089791732) },
      {  INT32_C(   889841800),  INT32_C(  1906777057), -INT32_C(   902918314),  INT32_C(  1154552356), -INT32_C(  1123933513),  INT32_C(  1735434546),  INT32_C(  1077078710),  INT32_C(  2089791732) } },
    { {  INT32_C(  2041747608),  INT32_C(   183130548),  INT32_C(   232003817), -INT32_C(   497965781), -INT32_C(    90155833), -INT32_C(  1402924811), -INT32_C(   269708038), -INT32_C(   596935868) },
      {  INT32_C(  2041747608),  INT32_C(   183130548),  INT32_C(   232003817), -INT32_C(   497965781), -INT32_C(    90155833), -INT32_C(  1402924811), -INT32_C(   269708038), -INT32_C(   596935868) } },
    { { -INT32_C(   933946092),  INT32_C(  1624391543), -INT32_C(  2089965992),  INT32_C(   325434956),  INT32_C(   135070994),  INT32_C(   280260373),  INT32_C(  1207934979),  INT32_C(   790850075) },
      { -INT32_C(   933946092),  INT32_C(  1624391543), -INT32_C(  2089965992),  INT32_C(   325434956),  INT32_C(   135070994),  INT32_C(   280260373),  INT32_C(  1207934979),  INT32_C(   790850075) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    int32_t r[sizeof(simde__m256i) / sizeof(int32_t)] = {0};
    simde_mm256_storeu_epi32(r, a);
    simde_assert_equal_vi32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    int32_t r[sizeof(simde__m256i) / sizeof(int32_t)] = {0};
    simde_mm256_storeu_epi32(r, a);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi32(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_storeu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { { -INT64_C( 8520414791212126978),  INT64_C( 6470760737637609380),  INT64_C( 7372765298930470642),  INT64_C( 9137132392545280597) },
      { -INT64_C( 8520414791212126978),  INT64_C( 6470760737637609380),  INT64_C( 7372765298930470642),  INT64_C( 9137132392545280597) } },
    { { -INT64_C( 6181695135723249974),  INT64_C( 6582275189149771364),  INT64_C( 1378027538322451646), -INT64_C( 1793282446973829346) },
      { -INT64_C( 6181695135723249974),  INT64_C( 6582275189149771364),  INT64_C( 1378027538322451646), -INT64_C( 1793282446973829346) } },
    { {  INT64_C( 3047472147532648602),  INT64_C( 1960335077399948657),  INT64_C( 8772998174208204782), -INT64_C( 9045984628089229966) },
      {  INT64_C( 3047472147532648602),  INT64_C( 1960335077399948657),  INT64_C( 8772998174208204782), -INT64_C( 9045984628089229966) } },
    { {  INT64_C( 5166874341197089733),  INT64_C( 5643948629755485914), -INT64_C( 8302182390395426828), -INT64_C( 2733242877560954714) },
      {  INT64_C( 5166874341197089733),  INT64_C( 5643948629755485914), -INT64_C( 8302182390395426828), -INT64_C( 2733242877560954714) } },
    { {  INT64_C( 8843408995216798621),  INT64_C( 2640521362198879223), -INT64_C(   84940192658251989),  INT64_C( 2164997219794349596) },
      {  INT64_C( 8843408995216798621),  INT64_C( 2640521362198879223), -INT64_C(   84940192658251989),  INT64_C( 2164997219794349596) } },
    { {  INT64_C( 9217545211248472017), -INT64_C( 3712237534943208409),  INT64_C( 5003750052667256346),  INT64_C( 7741830259258359250) },
      {  INT64_C( 9217545211248472017), -INT64_C( 3712237534943208409),  INT64_C( 5003750052667256346),  INT64_C( 7741830259258359250) } },
    { {  INT64_C( 8501044911504360177),  INT64_C( 7336723655508676452), -INT64_C( 7375690268599065803), -INT64_C( 8265410862250190267) },
      {  INT64_C( 8501044911504360177),  INT64_C( 7336723655508676452), -INT64_C( 7375690268599065803), -INT64_C( 8265410862250190267) } },
    { {  INT64_C( 5990350384227821662),  INT64_C( 7601841099293388239), -INT64_C( 1914473353548638451),  INT64_C( 1562487073980897926) },
      {  INT64_C( 5990350384227821662),  INT64_C( 7601841099293388239), -INT64_C( 1914473353548638451),  INT64_C( 1562487073980897926) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    int64_t r[sizeof(simde__m256i) / sizeof(int64_t)] = {0};
    simde_mm256_storeu_epi64(r, a);
    simde_assert_equal_vi64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    int64_t r[sizeof(simde__m256i) / sizeof(int64_t)] = {0};
    simde_mm256_storeu_epi64(r, a);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vi64(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_storeu_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT8_C(  6),
      { SIMDE_FLOAT32_C(  -492.18), SIMDE_FLOAT32_C(    45.19), SIMDE_FLOAT32_C(  -393.76), SIMDE_FLOAT32_C(   204.03),
        SIMDE_FLOAT32_C(   492.14), SIMDE_FLOAT32_C(   604.27), SIMDE_FLOAT32_C(   778.63), SIMDE_FLOAT32_C(  -583.80) },
      {         SIMDE_MATH_FLT_MAX, SIMDE_FLOAT32_C(    45.19), SIMDE_FLOAT32_C(  -393.76), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(181),
      { SIMDE_FLOAT32_C(   870.89), SIMDE_FLOAT32_C(   625.45), SIMDE_FLOAT32_C(   662.34), SIMDE_FLOAT32_C(   846.45),
        SIMDE_FLOAT32_C(   201.69), SIMDE_FLOAT32_C(   732.44), SIMDE_FLOAT32_C(   641.83), SIMDE_FLOAT32_C(  -632.43) },
      { SIMDE_FLOAT32_C(   870.89), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   662.34), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   201.69), SIMDE_FLOAT32_C(   732.44), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -632.43) } },
    { UINT8_C(182),
      { SIMDE_FLOAT32_C(    21.61), SIMDE_FLOAT32_C(  -184.71), SIMDE_FLOAT32_C(   164.50), SIMDE_FLOAT32_C(   962.85),
        SIMDE_FLOAT32_C(   145.68), SIMDE_FLOAT32_C(  -814.57), SIMDE_FLOAT32_C(   344.42), SIMDE_FLOAT32_C(  -313.92) },
      {         SIMDE_MATH_FLT_MAX, SIMDE_FLOAT32_C(  -184.71), SIMDE_FLOAT32_C(   164.50), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   145.68), SIMDE_FLOAT32_C(  -814.57), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -313.92) } },
    { UINT8_C(217),
      { SIMDE_FLOAT32_C(   884.87), SIMDE_FLOAT32_C(   401.24), SIMDE_FLOAT32_C(  -191.38), SIMDE_FLOAT32_C(   -44.59),
        SIMDE_FLOAT32_C(   909.05), SIMDE_FLOAT32_C(   853.81), SIMDE_FLOAT32_C(   561.65), SIMDE_FLOAT32_C(   113.08) },
      { SIMDE_FLOAT32_C(   884.87), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -44.59),
        SIMDE_FLOAT32_C(   909.05), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   561.65), SIMDE_FLOAT32_C(   113.08) } },
    { UINT8_C( 54),
      { SIMDE_FLOAT32_C(   165.92), SIMDE_FLOAT32_C(  -108.29), SIMDE_FLOAT32_C(   762.15), SIMDE_FLOAT32_C(  -242.71),
        SIMDE_FLOAT32_C(  -237.40), SIMDE_FLOAT32_C(   387.60), SIMDE_FLOAT32_C(  -580.36), SIMDE_FLOAT32_C(  -390.95) },
      {         SIMDE_MATH_FLT_MAX, SIMDE_FLOAT32_C(  -108.29), SIMDE_FLOAT32_C(   762.15), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -237.40), SIMDE_FLOAT32_C(   387.60), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(155),
      { SIMDE_FLOAT32_C(  -847.92), SIMDE_FLOAT32_C(  -749.12), SIMDE_FLOAT32_C(   -43.15), SIMDE_FLOAT32_C(  -553.13),
        SIMDE_FLOAT32_C(   272.49), SIMDE_FLOAT32_C(   772.14), SIMDE_FLOAT32_C(   611.37), SIMDE_FLOAT32_C(   235.34) },
      { SIMDE_FLOAT32_C(  -847.92), SIMDE_FLOAT32_C(  -749.12), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -553.13),
        SIMDE_FLOAT32_C(   272.49), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   235.34) } },
    { UINT8_C(242),
      { SIMDE_FLOAT32_C(   796.80), SIMDE_FLOAT32_C(  -420.24), SIMDE_FLOAT32_C(   603.90), SIMDE_FLOAT32_C(  -343.71),
        SIMDE_FLOAT32_C(  -535.37), SIMDE_FLOAT32_C(     5.14), SIMDE_FLOAT32_C(   464.90), SIMDE_FLOAT32_C(   420.04) },
      {         SIMDE_MATH_FLT_MAX, SIMDE_FLOAT32_C(  -420.24), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -535.37), SIMDE_FLOAT32_C(     5.14), SIMDE_FLOAT32_C(   464.90), SIMDE_FLOAT32_C(   420.04) } },
    { UINT8_C( 13),
      { SIMDE_FLOAT32_C(   318.71), SIMDE_FLOAT32_C(   -18.31), SIMDE_FLOAT32_C(  -972.73), SIMDE_FLOAT32_C(  -335.34),
        SIMDE_FLOAT32_C(  -852.38), SIMDE_FLOAT32_C(   -81.02), SIMDE_FLOAT32_C(  -573.19), SIMDE_FLOAT32_C(   -95.09) },
      { SIMDE_FLOAT32_C(   318.71), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -972.73), SIMDE_FLOAT32_C(  -335.34),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde_float32 r[sizeof(simde__m256) / sizeof(simde_float32)] = {SIMDE_MATH_FLT_MAX};
    simde_mm256_mask_storeu_ps(r, test_vec[i].k, a);
    simde_assert_equal_vf32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float32 r[sizeof(simde__m256) / sizeof(simde_float32)] = {SIMDE_MATH_FLT_MAX};
    simde_mm256_mask_storeu_ps(r, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vf32(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_storeu_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { UINT8_C( 25),
      { SIMDE_FLOAT64_C(   814.41), SIMDE_FLOAT64_C(   324.55), SIMDE_FLOAT64_C(  -709.37), SIMDE_FLOAT64_C(  -596.31) },
      { SIMDE_FLOAT64_C(   814.41), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -596.31) } },
    { UINT8_C(178),
      { SIMDE_FLOAT64_C(  -458.50), SIMDE_FLOAT64_C(   360.54), SIMDE_FLOAT64_C(   923.50), SIMDE_FLOAT64_C(   814.00) },
      {         SIMDE_MATH_DBL_MAX, SIMDE_FLOAT64_C(   360.54), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(220),
      { SIMDE_FLOAT64_C(   534.87), SIMDE_FLOAT64_C(    49.34), SIMDE_FLOAT64_C(  -949.50), SIMDE_FLOAT64_C(   331.67) },
      {         SIMDE_MATH_DBL_MAX, SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -949.50), SIMDE_FLOAT64_C(   331.67) } },
    { UINT8_C(206),
      { SIMDE_FLOAT64_C(   654.40), SIMDE_FLOAT64_C(   987.96), SIMDE_FLOAT64_C(  -906.27), SIMDE_FLOAT64_C(  -340.46) },
      {         SIMDE_MATH_DBL_MAX, SIMDE_FLOAT64_C(   987.96), SIMDE_FLOAT64_C(  -906.27), SIMDE_FLOAT64_C(  -340.46) } },
    { UINT8_C(234),
      { SIMDE_FLOAT64_C(   513.78), SIMDE_FLOAT64_C(   573.73), SIMDE_FLOAT64_C(  -228.42), SIMDE_FLOAT64_C(  -504.53) },
      {         SIMDE_MATH_DBL_MAX, SIMDE_FLOAT64_C(   573.73), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -504.53) } },
    { UINT8_C(  0),
      { SIMDE_FLOAT64_C(   436.24), SIMDE_FLOAT64_C(  -356.91), SIMDE_FLOAT64_C(  -480.02), SIMDE_FLOAT64_C(   863.05) },
      {         SIMDE_MATH_DBL_MAX, SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(103),
      { SIMDE_FLOAT64_C(  -798.44), SIMDE_FLOAT64_C(   677.45), SIMDE_FLOAT64_C(  -127.46), SIMDE_FLOAT64_C(  -507.82) },
      { SIMDE_FLOAT64_C(  -798.44), SIMDE_FLOAT64_C(   677.45), SIMDE_FLOAT64_C(  -127.46), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(197),
      { SIMDE_FLOAT64_C(  -650.84), SIMDE_FLOAT64_C(    33.69), SIMDE_FLOAT64_C(   441.69), SIMDE_FLOAT64_C(  -727.34) },
      { SIMDE_FLOAT64_C(  -650.84), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   441.69), SIMDE_FLOAT64_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde_float64 r[sizeof(simde__m256d) / sizeof(simde_float64)] = {SIMDE_MATH_DBL_MAX};
    simde_mm256_mask_storeu_pd(r, test_vec[i].k, a);
    simde_assert_equal_vf64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64 r[sizeof(simde__m256d) / sizeof(simde_float64)] = {SIMDE_MATH_DBL_MAX};
    simde_mm256_mask_storeu_pd(r, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vf64(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_storeu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 k;
    const int8_t a[64];
    const int8_t r[64];
  } test_vec[] = {
    { UINT64_C(16374550487037254550),
      { -INT8_C(  92),  INT8_C(  18),  INT8_C( 121), -INT8_C( 113),  INT8_C(   1),  INT8_C(  28), -INT8_C(  40), -INT8_C(  28),
         INT8_C(  28), -INT8_C(  73), -INT8_C(  78), -INT8_C(  31), -INT8_C(  69),  INT8_C(  25), -INT8_C(  64),  INT8_C(  82),
         INT8_C(  76), -INT8_C(  13),  INT8_C(  23),  INT8_C(  49),  INT8_C(  46),  INT8_C(  87),  INT8_C( 101), -INT8_C(  60),
         INT8_C( 114), -INT8_C(  12),  INT8_C(  52),  INT8_C(  92),  INT8_C(  10),  INT8_C( 114),  INT8_C(  63), -INT8_C(  82),
        -INT8_C( 124), -INT8_C(  72),  INT8_C(  61), -INT8_C( 123), -INT8_C(  44),  INT8_C(  22),  INT8_C( 105), -INT8_C(  16),
        -INT8_C(  51),  INT8_C(  28), -INT8_C(  47), -INT8_C( 120),  INT8_C(  53), -INT8_C( 111), -INT8_C(  37), -INT8_C( 127),
        -INT8_C( 124), -INT8_C(  14), -INT8_C(  78), -INT8_C(  78),  INT8_C(  73),  INT8_C(  24),  INT8_C( 118), -INT8_C(  68),
         INT8_C(  12), -INT8_C(  86),  INT8_C(  24),  INT8_C(  22),  INT8_C(  29),  INT8_C(  87), -INT8_C(  60), -INT8_C(  95) },
      {      INT8_MAX,  INT8_C(  18),  INT8_C( 121),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(  28),
         INT8_C(  28), -INT8_C(  73),  INT8_C(   0), -INT8_C(  31), -INT8_C(  69),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  13),  INT8_C(  23),  INT8_C(  49),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  60),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  10),  INT8_C( 114),  INT8_C(  63),  INT8_C(   0),
        -INT8_C( 124),  INT8_C(   0),  INT8_C(   0), -INT8_C( 123),  INT8_C(   0),  INT8_C(  22),  INT8_C( 105), -INT8_C(  16),
         INT8_C(   0),  INT8_C(  28), -INT8_C(  47),  INT8_C(   0),  INT8_C(  53),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  14), -INT8_C(  78), -INT8_C(  78),  INT8_C(  73),  INT8_C(  24),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  12), -INT8_C(  86),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  87), -INT8_C(  60), -INT8_C(  95) } },
    { UINT64_C(16560738691336045071),
      { -INT8_C(  84), -INT8_C(  92),  INT8_C( 109), -INT8_C(  30),  INT8_C(  54),  INT8_C(  72),  INT8_C(  99), -INT8_C(  70),
         INT8_C(  59),  INT8_C(  22),  INT8_C( 109), -INT8_C( 124),  INT8_C(  46), -INT8_C(  29),  INT8_C(  64),  INT8_C(  58),
        -INT8_C( 114),  INT8_C(  88),  INT8_C(  80), -INT8_C(  85), -INT8_C(  81),  INT8_C(  20),  INT8_C(  76), -INT8_C(  66),
         INT8_C(  22),  INT8_C( 115), -INT8_C(  95),  INT8_C(  46),  INT8_C(   4),  INT8_C( 116),  INT8_C(  19), -INT8_C(  80),
         INT8_C(  25), -INT8_C( 127), -INT8_C( 110),  INT8_C(  79), -INT8_C(  55), -INT8_C(  10),  INT8_C(   9),  INT8_C(   4),
         INT8_C(  12),  INT8_C( 118), -INT8_C( 119),  INT8_C(  58),  INT8_C(  90), -INT8_C(  55),  INT8_C( 116), -INT8_C(  24),
         INT8_C(  34), -INT8_C(  60), -INT8_C( 109), -INT8_C(  47), -INT8_C(  40), -INT8_C(  33), -INT8_C( 112), -INT8_C(  17),
         INT8_C(  83),  INT8_C(  49),  INT8_C(  29),  INT8_C(  87), -INT8_C(  90),  INT8_C(  49),  INT8_C(   7), -INT8_C(  65) },
      { -INT8_C(  84), -INT8_C(  92),  INT8_C( 109), -INT8_C(  30),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  22),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C( 114),  INT8_C(  88),  INT8_C(  80),  INT8_C(   0),  INT8_C(   0),  INT8_C(  20),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  22),  INT8_C( 115),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 116),  INT8_C(  19), -INT8_C(  80),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  79), -INT8_C(  55),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  90),  INT8_C(   0),  INT8_C(   0), -INT8_C(  24),
         INT8_C(  34), -INT8_C(  60),  INT8_C(   0),  INT8_C(   0), -INT8_C(  40),  INT8_C(   0), -INT8_C( 112), -INT8_C(  17),
         INT8_C(  83),  INT8_C(   0),  INT8_C(  29),  INT8_C(   0),  INT8_C(   0),  INT8_C(  49),  INT8_C(   7), -INT8_C(  65) } },
    { UINT64_C(11277039376243006130),
      { -INT8_C( 114),  INT8_C(   9), -INT8_C(  42), -INT8_C(  24), -INT8_C(  46),  INT8_C(  74), -INT8_C(  48), -INT8_C(  12),
         INT8_C(  14),  INT8_C(  99), -INT8_C(  58), -INT8_C(  26),  INT8_C(  66),  INT8_C(  86), -INT8_C(  43), -INT8_C( 107),
        -INT8_C( 121), -INT8_C(  13), -INT8_C(  20),  INT8_C(  45),  INT8_C(  36), -INT8_C(  12), -INT8_C(  20), -INT8_C(  42),
        -INT8_C( 114), -INT8_C(   6),  INT8_C(  81),  INT8_C(  30),  INT8_C(  18), -INT8_C(  47), -INT8_C(  70), -INT8_C(  96),
        -INT8_C(  38), -INT8_C( 112), -INT8_C( 120), -INT8_C(  83), -INT8_C(  38),  INT8_C(  88), -INT8_C(  95), -INT8_C(  24),
        -INT8_C(  69),  INT8_C( 103), -INT8_C(  50), -INT8_C(   3), -INT8_C(  67), -INT8_C(  92), -INT8_C( 109),  INT8_C(  69),
        -INT8_C( 105),      INT8_MAX,  INT8_C( 114), -INT8_C(  69),  INT8_C( 115),  INT8_C(  95), -INT8_C( 111),  INT8_C(   1),
         INT8_C(  89), -INT8_C(  30),  INT8_C(  31),  INT8_C( 107), -INT8_C(  76), -INT8_C(  39),  INT8_C(  11), -INT8_C( 114) },
      {      INT8_MAX,  INT8_C(   9),  INT8_C(   0),  INT8_C(   0), -INT8_C(  46),  INT8_C(  74),  INT8_C(   0), -INT8_C(  12),
         INT8_C(   0),  INT8_C(  99),  INT8_C(   0), -INT8_C(  26),  INT8_C(  66),  INT8_C(   0),  INT8_C(   0), -INT8_C( 107),
         INT8_C(   0), -INT8_C(  13), -INT8_C(  20),  INT8_C(  45),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C( 114), -INT8_C(   6),  INT8_C(   0),  INT8_C(  30),  INT8_C(  18), -INT8_C(  47), -INT8_C(  70),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  38),  INT8_C(   0),  INT8_C(   0), -INT8_C(  24),
        -INT8_C(  69),  INT8_C( 103), -INT8_C(  50),  INT8_C(   0), -INT8_C(  67),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  31),  INT8_C( 107), -INT8_C(  76),  INT8_C(   0),  INT8_C(   0), -INT8_C( 114) } },
    { UINT64_C(11973908036809626473),
      {  INT8_C(  68), -INT8_C(   6), -INT8_C(  92),  INT8_C(   2), -INT8_C(  98),  INT8_C(  55),  INT8_C(  71),  INT8_C(  53),
        -INT8_C(  74), -INT8_C(  71), -INT8_C(  16),  INT8_C(  42),  INT8_C(  24), -INT8_C( 127),  INT8_C(  43),  INT8_C( 114),
         INT8_C(  99),  INT8_C(  75), -INT8_C(  35),  INT8_C(  23),  INT8_C(  36), -INT8_C(  23), -INT8_C(  90), -INT8_C( 114),
         INT8_C( 124), -INT8_C(  31), -INT8_C(  47),  INT8_C( 104), -INT8_C(  66), -INT8_C(   3),  INT8_C(  14),  INT8_C(   3),
        -INT8_C(   9), -INT8_C(  78),  INT8_C(   5), -INT8_C( 107), -INT8_C(  23),  INT8_C(  76), -INT8_C(  54), -INT8_C(  96),
         INT8_C(   5), -INT8_C(  70), -INT8_C(  54),  INT8_C(  30),  INT8_C(  59), -INT8_C(  11), -INT8_C( 112), -INT8_C(  98),
         INT8_C(  64),  INT8_C( 109), -INT8_C(  74),  INT8_C( 101),  INT8_C(  86),  INT8_C(  92), -INT8_C(  13), -INT8_C(  45),
         INT8_C(  61), -INT8_C(  60),  INT8_C(  59), -INT8_C(   4), -INT8_C(  63),  INT8_C(  73), -INT8_C(   1), -INT8_C(  72) },
      {  INT8_C(  68),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(  55),  INT8_C(  71),  INT8_C(   0),
        -INT8_C(  74), -INT8_C(  71),  INT8_C(   0),  INT8_C(   0),  INT8_C(  24),  INT8_C(   0),  INT8_C(   0),  INT8_C( 114),
         INT8_C(  99),  INT8_C(  75),  INT8_C(   0),  INT8_C(  23),  INT8_C(  36), -INT8_C(  23),  INT8_C(   0),  INT8_C(   0),
         INT8_C( 124), -INT8_C(  31),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  14),  INT8_C(   0),
        -INT8_C(   9), -INT8_C(  78),  INT8_C(   0), -INT8_C( 107),  INT8_C(   0),  INT8_C(  76), -INT8_C(  54), -INT8_C(  96),
         INT8_C(   5),  INT8_C(   0), -INT8_C(  54),  INT8_C(  30),  INT8_C(  59),  INT8_C(   0), -INT8_C( 112), -INT8_C(  98),
         INT8_C(  64),  INT8_C( 109),  INT8_C(   0),  INT8_C( 101),  INT8_C(   0),  INT8_C(  92),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  60),  INT8_C(  59),  INT8_C(   0),  INT8_C(   0),  INT8_C(  73),  INT8_C(   0), -INT8_C(  72) } },
    { UINT64_C( 6162357301338244348),
      { -INT8_C(  47),  INT8_C(  79),  INT8_C( 115),  INT8_C(  12),  INT8_C(  69),  INT8_C(   3), -INT8_C(  85), -INT8_C( 123),
         INT8_C( 113),  INT8_C(  97), -INT8_C(  22), -INT8_C(  57), -INT8_C(  67), -INT8_C(  35), -INT8_C( 102), -INT8_C(   6),
        -INT8_C(  94), -INT8_C(  43), -INT8_C(  10),  INT8_C(  99),  INT8_C(  31), -INT8_C(  11),  INT8_C(  28),  INT8_C(  27),
        -INT8_C(   7),  INT8_C( 105),  INT8_C(   0),  INT8_C(  73), -INT8_C( 127), -INT8_C( 122), -INT8_C(  97),  INT8_C(  82),
        -INT8_C(  43),  INT8_C(  18),  INT8_C(  95),  INT8_C(  26),  INT8_C(  22),  INT8_C(  10), -INT8_C(  96), -INT8_C( 121),
         INT8_C( 107), -INT8_C( 118),  INT8_C(  78),  INT8_C(  40),  INT8_C( 104), -INT8_C(  23),  INT8_C(  34),  INT8_C(  10),
        -INT8_C(  66),  INT8_C(  25),  INT8_C( 109), -INT8_C(  35),  INT8_C(  14), -INT8_C( 119), -INT8_C(   8),  INT8_C(   8),
        -INT8_C(  13), -INT8_C(   7),  INT8_C(  81),  INT8_C( 116),      INT8_MAX, -INT8_C(  16), -INT8_C(  58),  INT8_C(  84) },
      {      INT8_MAX,  INT8_C(   0),  INT8_C( 115),  INT8_C(  12),  INT8_C(  69),  INT8_C(   3), -INT8_C(  85), -INT8_C( 123),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  22),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  94),  INT8_C(   0), -INT8_C(  10),  INT8_C(  99),  INT8_C(   0),  INT8_C(   0),  INT8_C(  28),  INT8_C(   0),
        -INT8_C(   7),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 122), -INT8_C(  97),  INT8_C(  82),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  22),  INT8_C(   0), -INT8_C(  96),  INT8_C(   0),
         INT8_C( 107), -INT8_C( 118),  INT8_C(  78),  INT8_C(   0),  INT8_C( 104),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  66),  INT8_C(   0),  INT8_C( 109),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   8),
        -INT8_C(  13),  INT8_C(   0),  INT8_C(  81),  INT8_C(   0),      INT8_MAX,  INT8_C(   0), -INT8_C(  58),  INT8_C(   0) } },
    { UINT64_C(11141922173079201027),
      { -INT8_C( 103), -INT8_C(  18), -INT8_C(  62),  INT8_C(   1), -INT8_C(  41), -INT8_C(  27),  INT8_C(  11), -INT8_C( 106),
        -INT8_C(   2),  INT8_C( 121),  INT8_C( 115),  INT8_C(  12),  INT8_C(   2),  INT8_C( 108),  INT8_C(  20), -INT8_C(  11),
         INT8_C( 101),  INT8_C( 102),  INT8_C( 105), -INT8_C(  28),  INT8_C(  86),  INT8_C(  48),  INT8_C(  56),  INT8_C(  89),
         INT8_C(  85), -INT8_C(  89),  INT8_C( 114), -INT8_C( 123), -INT8_C(  74),  INT8_C(  18),  INT8_C(  31),  INT8_C(  80),
         INT8_C(   1), -INT8_C(  30),  INT8_C(  81), -INT8_C(  40), -INT8_C(  57),  INT8_C(  93),  INT8_C( 110), -INT8_C(  59),
        -INT8_C(  42), -INT8_C(  30), -INT8_C(  47), -INT8_C(  40),  INT8_C(  78), -INT8_C(  26), -INT8_C(  50), -INT8_C(  77),
         INT8_C(  76),  INT8_C(  55), -INT8_C( 105), -INT8_C(  94),  INT8_C( 103), -INT8_C(  49), -INT8_C(   4), -INT8_C(  67),
         INT8_C( 119),  INT8_C( 110),  INT8_C(  66),  INT8_C(  45), -INT8_C( 127),  INT8_C(  97),  INT8_C( 125), -INT8_C( 126) },
      { -INT8_C( 103), -INT8_C(  18),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   2),  INT8_C(   0),  INT8_C( 115),  INT8_C(   0),  INT8_C(   0),  INT8_C( 108),  INT8_C(   0),  INT8_C(   0),
         INT8_C( 101),  INT8_C( 102),  INT8_C( 105), -INT8_C(  28),  INT8_C(   0),  INT8_C(  48),  INT8_C(  56),  INT8_C(   0),
         INT8_C(  85),  INT8_C(   0),  INT8_C(   0), -INT8_C( 123), -INT8_C(  74),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   1), -INT8_C(  30),  INT8_C(  81), -INT8_C(  40),  INT8_C(   0),  INT8_C(  93),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  42), -INT8_C(  30), -INT8_C(  47), -INT8_C(  40),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  49),  INT8_C(   0), -INT8_C(  67),
         INT8_C(   0),  INT8_C( 110),  INT8_C(   0),  INT8_C(  45), -INT8_C( 127),  INT8_C(   0),  INT8_C(   0), -INT8_C( 126) } },
    { UINT64_C(  202601699244429123),
      { -INT8_C(  85), -INT8_C(  95), -INT8_C(  38), -INT8_C(   7), -INT8_C( 121), -INT8_C(  88), -INT8_C(  84), -INT8_C(  45),
        -INT8_C(  32),  INT8_C(  67),  INT8_C( 117),  INT8_C(  71),  INT8_C(  18),  INT8_C( 113),  INT8_C(   4), -INT8_C( 119),
        -INT8_C(  32),  INT8_C(  70), -INT8_C(  73),  INT8_C(  97), -INT8_C(  88),  INT8_C(  52), -INT8_C(  29), -INT8_C(  21),
         INT8_C(   3),  INT8_C(  61), -INT8_C(  10),  INT8_C(  47),  INT8_C(   6), -INT8_C(  59),  INT8_C(  49), -INT8_C(  79),
         INT8_C( 102),  INT8_C(  12), -INT8_C(  86), -INT8_C(  19), -INT8_C(  76),  INT8_C(  86), -INT8_C(  64), -INT8_C( 108),
        -INT8_C( 103),  INT8_C(  54), -INT8_C(  36), -INT8_C(  84), -INT8_C(  89), -INT8_C(  32),  INT8_C(  53), -INT8_C( 121),
         INT8_C(  39), -INT8_C(  20), -INT8_C(  24), -INT8_C(  49),  INT8_C(  33), -INT8_C(  53), -INT8_C(  70),  INT8_C(  36),
         INT8_C(   9), -INT8_C(  80),  INT8_C(  84),  INT8_C(  15),  INT8_C( 118), -INT8_C( 123), -INT8_C(  63), -INT8_C(  36) },
      { -INT8_C(  85), -INT8_C(  95),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  84),  INT8_C(   0),
        -INT8_C(  32),  INT8_C(  67),  INT8_C( 117),  INT8_C(  71),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4), -INT8_C( 119),
         INT8_C(   0),  INT8_C(  70),  INT8_C(   0),  INT8_C(  97), -INT8_C(  88),  INT8_C(   0), -INT8_C(  29),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  61),  INT8_C(   0),  INT8_C(  47),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  86), -INT8_C(  19),  INT8_C(   0),  INT8_C(  86),  INT8_C(   0),  INT8_C(   0),
        -INT8_C( 103),  INT8_C(   0),  INT8_C(   0), -INT8_C(  84),  INT8_C(   0),  INT8_C(   0),  INT8_C(  53), -INT8_C( 121),
         INT8_C(  39), -INT8_C(  20), -INT8_C(  24), -INT8_C(  49),  INT8_C(   0),  INT8_C(   0), -INT8_C(  70),  INT8_C(  36),
         INT8_C(   0), -INT8_C(  80),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT64_C( 6618755169390324625),
      { -INT8_C(  64), -INT8_C(  74),  INT8_C(   7),  INT8_C( 104), -INT8_C( 105),  INT8_C(  61), -INT8_C(  17), -INT8_C(  66),
         INT8_C(  41), -INT8_C(  40), -INT8_C( 115),  INT8_C(  74), -INT8_C(  93),  INT8_C(  71),  INT8_C( 111), -INT8_C(  84),
        -INT8_C(   8), -INT8_C(  61), -INT8_C(  68),  INT8_C( 110),  INT8_C(  72),  INT8_C( 125),  INT8_C(  74), -INT8_C(  38),
        -INT8_C(  24),  INT8_C(  20),  INT8_C(  32), -INT8_C(  86), -INT8_C(  97), -INT8_C(   6),  INT8_C(   6),  INT8_C(  95),
        -INT8_C(  79),  INT8_C(  13), -INT8_C(  57),  INT8_C(  72),  INT8_C(  74), -INT8_C(  73),  INT8_C(   6),  INT8_C( 116),
        -INT8_C( 113), -INT8_C( 109), -INT8_C(  66),  INT8_C(  50), -INT8_C(  38),  INT8_C(  45), -INT8_C(  33), -INT8_C(  46),
        -INT8_C(  16), -INT8_C( 101),  INT8_C(  64),  INT8_C(  57),  INT8_C(  24), -INT8_C( 117),  INT8_C(  19),  INT8_C(   0),
        -INT8_C(  97),  INT8_C(  51), -INT8_C(  85),  INT8_C(  62),  INT8_C(  45), -INT8_C(  79), -INT8_C(  98), -INT8_C(  34) },
      { -INT8_C(  64),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 105),  INT8_C(   0),  INT8_C(   0), -INT8_C(  66),
         INT8_C(  41), -INT8_C(  40),  INT8_C(   0),  INT8_C(  74),  INT8_C(   0),  INT8_C(  71),  INT8_C( 111),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  61),  INT8_C(   0),  INT8_C( 110),  INT8_C(   0),  INT8_C(   0),  INT8_C(  74), -INT8_C(  38),
         INT8_C(   0),  INT8_C(  20),  INT8_C(  32),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  13),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),  INT8_C( 116),
         INT8_C(   0), -INT8_C( 109),  INT8_C(   0),  INT8_C(  50),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  46),
         INT8_C(   0), -INT8_C( 101),  INT8_C(   0),  INT8_C(  57),  INT8_C(  24),  INT8_C(   0),  INT8_C(  19),  INT8_C(   0),
        -INT8_C(  97),  INT8_C(  51),  INT8_C(   0),  INT8_C(  62),  INT8_C(  45),  INT8_C(   0), -INT8_C(  98),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    int8_t r[sizeof(simde__m512i) / sizeof(int8_t)] = {INT8_MAX};
    simde_mm512_mask_storeu_epi8(r, test_vec[i].k, a);
    simde_assert_equal_vi8(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask64 k = simde_test_x86_random_mmask64();
    simde__m512i a = simde_test_x86_random_i8x64();
    int8_t r[sizeof(simde__m512i) / sizeof(int8_t)] = {INT8_MAX};
    simde_mm512_mask_storeu_epi8(r, k, a);

    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vi8(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_storeu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { UINT32_C(1511948030),
      { -INT16_C( 17462), -INT16_C(  5388), -INT16_C( 14087), -INT16_C( 16529),  INT16_C( 18291), -INT16_C( 28189),  INT16_C( 28534), -INT16_C( 31168),
         INT16_C( 16495),  INT16_C( 26490), -INT16_C( 28382),  INT16_C(  7914), -INT16_C(  4500),  INT16_C( 27478),  INT16_C( 29805),  INT16_C( 14277),
        -INT16_C( 17873),  INT16_C( 10273), -INT16_C( 28542), -INT16_C(  2584), -INT16_C( 13352),  INT16_C( 20102), -INT16_C( 14534), -INT16_C( 22060),
         INT16_C( 20231),  INT16_C( 10768), -INT16_C(  1312),  INT16_C( 19528), -INT16_C( 24855),  INT16_C( 22199),  INT16_C( 32019),  INT16_C( 17037) },
      {        INT16_MAX, -INT16_C(  5388), -INT16_C( 14087), -INT16_C( 16529),  INT16_C( 18291), -INT16_C( 28189),  INT16_C( 28534), -INT16_C( 31168),
         INT16_C(     0),  INT16_C( 26490), -INT16_C( 28382),  INT16_C(  7914), -INT16_C(  4500),  INT16_C( 27478),  INT16_C( 29805),  INT16_C(     0),
         INT16_C(     0),  INT16_C( 10273), -INT16_C( 28542), -INT16_C(  2584), -INT16_C( 13352),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C( 10768),  INT16_C(     0),  INT16_C( 19528), -INT16_C( 24855),  INT16_C(     0),  INT16_C( 32019),  INT16_C(     0) } },
    { UINT32_C(3110841911),
      {  INT16_C( 21311),  INT16_C(  6063),  INT16_C( 13598),  INT16_C( 22885),  INT16_C( 14844),  INT16_C(  1026),  INT16_C(  5000),  INT16_C( 26670),
         INT16_C( 30221), -INT16_C(  2379),  INT16_C( 27668),  INT16_C( 10060), -INT16_C(  9751),  INT16_C(  8298), -INT16_C( 10872), -INT16_C( 14374),
        -INT16_C( 30424),  INT16_C( 18142),  INT16_C( 17342), -INT16_C( 17505), -INT16_C( 23940),  INT16_C(  1471), -INT16_C(  4683), -INT16_C( 15763),
         INT16_C(  8803),  INT16_C( 30649),  INT16_C(  1423),  INT16_C( 30879),  INT16_C(  2527),  INT16_C( 26521),  INT16_C( 29662),  INT16_C(  1582) },
      {  INT16_C( 21311),  INT16_C(  6063),  INT16_C( 13598),  INT16_C(     0),  INT16_C( 14844),  INT16_C(  1026),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C(  2379),  INT16_C( 27668),  INT16_C( 10060),  INT16_C(     0),  INT16_C(  8298),  INT16_C(     0), -INT16_C( 14374),
        -INT16_C( 30424),  INT16_C( 18142),  INT16_C(     0), -INT16_C( 17505),  INT16_C(     0),  INT16_C(  1471), -INT16_C(  4683),  INT16_C(     0),
         INT16_C(  8803),  INT16_C(     0),  INT16_C(     0),  INT16_C( 30879),  INT16_C(  2527),  INT16_C( 26521),  INT16_C(     0),  INT16_C(  1582) } },
    { UINT32_C(3125546236),
      { -INT16_C(  5041), -INT16_C( 13451),  INT16_C( 13454),  INT16_C( 17360),  INT16_C( 15905), -INT16_C( 31739), -INT16_C( 16800), -INT16_C(  4100),
        -INT16_C( 25660), -INT16_C( 23704),  INT16_C(   420), -INT16_C( 32246),  INT16_C( 14452),  INT16_C( 28808), -INT16_C( 11196), -INT16_C( 27862),
        -INT16_C( 24384),  INT16_C( 20062),  INT16_C( 12244), -INT16_C(  2415), -INT16_C( 26771), -INT16_C( 12934),  INT16_C( 30293),  INT16_C(  6589),
         INT16_C(  9489), -INT16_C( 19012), -INT16_C( 14810), -INT16_C( 26057), -INT16_C( 16386),  INT16_C( 16906),  INT16_C( 13460),  INT16_C( 21717) },
      {        INT16_MAX,  INT16_C(     0),  INT16_C( 13454),  INT16_C( 17360),  INT16_C( 15905), -INT16_C( 31739), -INT16_C( 16800), -INT16_C(  4100),
         INT16_C(     0),  INT16_C(     0),  INT16_C(   420), -INT16_C( 32246),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C( 12244), -INT16_C(  2415),  INT16_C(     0),  INT16_C(     0),  INT16_C( 30293),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 19012),  INT16_C(     0), -INT16_C( 26057), -INT16_C( 16386),  INT16_C( 16906),  INT16_C(     0),  INT16_C( 21717) } },
    { UINT32_C(2846045396),
      {  INT16_C( 13411), -INT16_C( 12129),  INT16_C(  6603),  INT16_C(  8605),  INT16_C( 23184), -INT16_C( 24262), -INT16_C(  2177), -INT16_C( 23209),
        -INT16_C( 28995), -INT16_C( 17345),  INT16_C( 18766), -INT16_C(  7426), -INT16_C( 11138),  INT16_C( 21046), -INT16_C(  9976),  INT16_C( 27643),
        -INT16_C( 26098), -INT16_C(  9925), -INT16_C( 10060),  INT16_C( 17658),  INT16_C( 13619), -INT16_C( 19739),  INT16_C( 15404), -INT16_C(  5800),
        -INT16_C( 26677),  INT16_C(  6565), -INT16_C( 23327),  INT16_C( 24571),  INT16_C( 12664), -INT16_C( 32591), -INT16_C( 21237),  INT16_C(  6635) },
      {        INT16_MAX,  INT16_C(     0),  INT16_C(  6603),  INT16_C(     0),  INT16_C( 23184),  INT16_C(     0), -INT16_C(  2177), -INT16_C( 23209),
         INT16_C(     0),  INT16_C(     0),  INT16_C( 18766),  INT16_C(     0), -INT16_C( 11138),  INT16_C( 21046),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 26098), -INT16_C(  9925),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 19739),  INT16_C(     0), -INT16_C(  5800),
        -INT16_C( 26677),  INT16_C(     0),  INT16_C(     0),  INT16_C( 24571),  INT16_C(     0), -INT16_C( 32591),  INT16_C(     0),  INT16_C(  6635) } },
    { UINT32_C(4226950727),
      { -INT16_C(  4610),  INT16_C( 12607),  INT16_C(  9506),  INT16_C( 20196),  INT16_C( 15457),  INT16_C( 11319), -INT16_C(  8749), -INT16_C( 19387),
         INT16_C( 16513), -INT16_C(  1773), -INT16_C( 14990),  INT16_C( 32121),  INT16_C( 25714), -INT16_C( 18026), -INT16_C( 30582), -INT16_C( 30539),
        -INT16_C(  2955), -INT16_C( 26694), -INT16_C( 25063),  INT16_C( 31717),  INT16_C(  7642), -INT16_C( 21081), -INT16_C(  4614),  INT16_C( 31586),
         INT16_C( 29997), -INT16_C( 24716), -INT16_C(  4806), -INT16_C( 21476), -INT16_C( 19887), -INT16_C(  9370),  INT16_C(  6971), -INT16_C( 20381) },
      { -INT16_C(  4610),  INT16_C( 12607),  INT16_C(  9506),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  8749),  INT16_C(     0),
         INT16_C(     0), -INT16_C(  1773), -INT16_C( 14990),  INT16_C(     0),  INT16_C(     0), -INT16_C( 18026),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 26694),  INT16_C(     0),  INT16_C(     0),  INT16_C(  7642), -INT16_C( 21081), -INT16_C(  4614),  INT16_C( 31586),
         INT16_C( 29997), -INT16_C( 24716),  INT16_C(     0), -INT16_C( 21476), -INT16_C( 19887), -INT16_C(  9370),  INT16_C(  6971), -INT16_C( 20381) } },
    { UINT32_C( 692591887),
      {  INT16_C( 11707), -INT16_C( 27228),  INT16_C( 19274),  INT16_C( 17475), -INT16_C( 23240),  INT16_C( 26303),  INT16_C( 13082),  INT16_C( 21765),
         INT16_C(  8736),  INT16_C( 28929),  INT16_C( 26580),  INT16_C(  3916), -INT16_C( 20350), -INT16_C( 27968),  INT16_C(  2253), -INT16_C( 30277),
         INT16_C( 24373), -INT16_C( 32738),  INT16_C( 25002), -INT16_C(  7228), -INT16_C( 31738),  INT16_C(  8521),  INT16_C( 20151), -INT16_C( 10122),
         INT16_C( 30576),  INT16_C( 17737), -INT16_C( 26913),  INT16_C( 24916),  INT16_C(  5190),  INT16_C(  5107), -INT16_C( 20964),  INT16_C( 21148) },
      {  INT16_C( 11707), -INT16_C( 27228),  INT16_C( 19274),  INT16_C( 17475),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(  8736),  INT16_C(     0),  INT16_C( 26580),  INT16_C(  3916), -INT16_C( 20350),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  7228),  INT16_C(     0),  INT16_C(     0),  INT16_C( 20151),  INT16_C(     0),
         INT16_C( 30576),  INT16_C(     0),  INT16_C(     0),  INT16_C( 24916),  INT16_C(     0),  INT16_C(  5107),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(3100818189),
      { -INT16_C( 27108),  INT16_C(  9115), -INT16_C(  7142), -INT16_C( 11708), -INT16_C( 17870), -INT16_C( 23638), -INT16_C(  3279),  INT16_C(  4328),
         INT16_C( 15497), -INT16_C( 12430),  INT16_C( 25937),  INT16_C( 28131),  INT16_C( 32532),  INT16_C(  8639), -INT16_C( 28358),  INT16_C( 22489),
         INT16_C( 29736),  INT16_C( 17018), -INT16_C( 16808), -INT16_C( 29932), -INT16_C( 16776), -INT16_C( 22226),  INT16_C(  5810),  INT16_C( 15290),
         INT16_C( 11346), -INT16_C( 23797), -INT16_C(  4463), -INT16_C( 23279), -INT16_C( 12179), -INT16_C( 22329), -INT16_C( 24478), -INT16_C( 29953) },
      { -INT16_C( 27108),  INT16_C(     0), -INT16_C(  7142), -INT16_C( 11708),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 15497), -INT16_C( 12430),  INT16_C(     0),  INT16_C( 28131),  INT16_C( 32532),  INT16_C(  8639),  INT16_C(     0),  INT16_C( 22489),
         INT16_C(     0),  INT16_C( 17018),  INT16_C(     0),  INT16_C(     0), -INT16_C( 16776),  INT16_C(     0),  INT16_C(  5810),  INT16_C( 15290),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 23279), -INT16_C( 12179), -INT16_C( 22329),  INT16_C(     0), -INT16_C( 29953) } },
    { UINT32_C(1842116885),
      { -INT16_C(  7881), -INT16_C( 20488),  INT16_C(  9887),  INT16_C( 20824),  INT16_C(  4668), -INT16_C( 28787), -INT16_C( 26562), -INT16_C( 12238),
         INT16_C( 17286), -INT16_C(  3211),  INT16_C( 15380),  INT16_C( 30363), -INT16_C( 25891), -INT16_C(  3584), -INT16_C( 13293),  INT16_C( 19039),
         INT16_C( 22701),  INT16_C( 19961),  INT16_C( 21118), -INT16_C( 17506),  INT16_C( 11108), -INT16_C( 23734),  INT16_C( 31939),  INT16_C( 18803),
        -INT16_C(  5952), -INT16_C( 11203), -INT16_C( 10203),  INT16_C(   586),  INT16_C( 19059), -INT16_C( 30988),  INT16_C( 21270), -INT16_C( 15151) },
      { -INT16_C(  7881),  INT16_C(     0),  INT16_C(  9887),  INT16_C(     0),  INT16_C(  4668),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 17286),  INT16_C(     0),  INT16_C(     0),  INT16_C( 30363), -INT16_C( 25891), -INT16_C(  3584), -INT16_C( 13293),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C( 21118), -INT16_C( 17506),  INT16_C(     0),  INT16_C(     0),  INT16_C( 31939),  INT16_C( 18803),
        -INT16_C(  5952),  INT16_C(     0), -INT16_C( 10203),  INT16_C(   586),  INT16_C(     0), -INT16_C( 30988),  INT16_C( 21270),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    int16_t r[sizeof(simde__m512i) / sizeof(int16_t)] = {INT16_MAX};
    simde_mm512_mask_storeu_epi16(r, test_vec[i].k, a);
    simde_assert_equal_vi16(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    int16_t r[sizeof(simde__m512i) / sizeof(int16_t)] = {INT16_MAX};
    simde_mm512_mask_storeu_epi16(r, k, a);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vi16(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_storeu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C(51883),
      { -INT32_C(  1357108719),  INT32_C(   802914789), -INT32_C(  1750360540),  INT32_C(   629107688), -INT32_C(  1979866049), -INT32_C(  1697419098), -INT32_C(   923866377), -INT32_C(  1080911442),
        -INT32_C(  1469141053),  INT32_C(  1423395120), -INT32_C(   789871640),  INT32_C(   787835630), -INT32_C(  1246236145),  INT32_C(  1515228003),  INT32_C(   589446773), -INT32_C(  1679641385) },
      { -INT32_C(  1357108719),  INT32_C(   802914789),  INT32_C(           0),  INT32_C(   629107688),  INT32_C(           0), -INT32_C(  1697419098),  INT32_C(           0), -INT32_C(  1080911442),
         INT32_C(           0),  INT32_C(  1423395120),  INT32_C(           0),  INT32_C(   787835630),  INT32_C(           0),  INT32_C(           0),  INT32_C(   589446773), -INT32_C(  1679641385) } },
    { UINT16_C(20579),
      {  INT32_C(   463115075), -INT32_C(   761363737),  INT32_C(  1195215954),  INT32_C(  1916357818),  INT32_C(  1375575041),  INT32_C(   412054262),  INT32_C(  2009950101),  INT32_C(  1170681858),
        -INT32_C(  1419746876),  INT32_C(   897515235),  INT32_C(  1165802379),  INT32_C(   146257415),  INT32_C(  1230681170), -INT32_C(  1151211226),  INT32_C(  1379020368),  INT32_C(   597228127) },
      {  INT32_C(   463115075), -INT32_C(   761363737),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   412054262),  INT32_C(  2009950101),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1230681170),  INT32_C(           0),  INT32_C(  1379020368),  INT32_C(           0) } },
    { UINT16_C(63579),
      {  INT32_C(  1291272142), -INT32_C(   251166092),  INT32_C(  2141654727),  INT32_C(  1899231511), -INT32_C(  1537582526),  INT32_C(  1221765909), -INT32_C(  1790823939),  INT32_C(   596548948),
         INT32_C(  1366263260), -INT32_C(   834504953), -INT32_C(  1672615547),  INT32_C(   621642210), -INT32_C(   255235877),  INT32_C(   272145171),  INT32_C(   564558541), -INT32_C(   196856808) },
      {  INT32_C(  1291272142), -INT32_C(   251166092),  INT32_C(           0),  INT32_C(  1899231511), -INT32_C(  1537582526),  INT32_C(           0), -INT32_C(  1790823939),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   621642210), -INT32_C(   255235877),  INT32_C(   272145171),  INT32_C(   564558541), -INT32_C(   196856808) } },
    { UINT16_C(46265),
      { -INT32_C(  2027175867), -INT32_C(   596594546),  INT32_C(  1516065613),  INT32_C(  1103247480),  INT32_C(  1641862440), -INT32_C(  1931761178),  INT32_C(   264303563),  INT32_C(   767785448),
        -INT32_C(   944378311), -INT32_C(   324852321), -INT32_C(   263847816),  INT32_C(  1630603576), -INT32_C(   993915170), -INT32_C(  2108645961),  INT32_C(  2039615633), -INT32_C(  1029286519) },
      { -INT32_C(  2027175867),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1103247480),  INT32_C(  1641862440), -INT32_C(  1931761178),  INT32_C(           0),  INT32_C(   767785448),
         INT32_C(           0),  INT32_C(           0), -INT32_C(   263847816),  INT32_C(           0), -INT32_C(   993915170), -INT32_C(  2108645961),  INT32_C(           0), -INT32_C(  1029286519) } },
    { UINT16_C(23364),
      {  INT32_C(   763487114),  INT32_C(   355400143),  INT32_C(   454977258), -INT32_C(  1993736761),  INT32_C(   304603585), -INT32_C(   182273949), -INT32_C(   682906575), -INT32_C(   130838674),
         INT32_C(  1093055602), -INT32_C(  1755949907), -INT32_C(  2102168134),  INT32_C(   856415346),  INT32_C(   558183101),  INT32_C(   454453482), -INT32_C(  2097979116),  INT32_C(  1652238064) },
      {              INT32_MAX,  INT32_C(           0),  INT32_C(   454977258),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   682906575),  INT32_C(           0),
         INT32_C(  1093055602), -INT32_C(  1755949907),  INT32_C(           0),  INT32_C(   856415346),  INT32_C(   558183101),  INT32_C(           0), -INT32_C(  2097979116),  INT32_C(           0) } },
    { UINT16_C(41434),
      { -INT32_C(    84572253), -INT32_C(   764432609),  INT32_C(  1034871089),  INT32_C(  1517251604), -INT32_C(  1547543923),  INT32_C(  1745213045), -INT32_C(   745605800), -INT32_C(    76257192),
         INT32_C(   267741680),  INT32_C(  1256285209),  INT32_C(  1518833477), -INT32_C(  2001405957), -INT32_C(   970164655), -INT32_C(  1540411060),  INT32_C(  2121841958),  INT32_C(   377154598) },
      {              INT32_MAX, -INT32_C(   764432609),  INT32_C(           0),  INT32_C(  1517251604), -INT32_C(  1547543923),  INT32_C(           0), -INT32_C(   745605800), -INT32_C(    76257192),
         INT32_C(   267741680),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1540411060),  INT32_C(           0),  INT32_C(   377154598) } },
    { UINT16_C(28502),
      {  INT32_C(   114585381),  INT32_C(  1100290489),  INT32_C(   658018675),  INT32_C(  1167952153),  INT32_C(  2121722191),  INT32_C(   104635790), -INT32_C(  1779277285), -INT32_C(  1660598152),
         INT32_C(  1906563511),  INT32_C(  1722956018), -INT32_C(   477238583), -INT32_C(  1037554829), -INT32_C(  1572757740),  INT32_C(  1470659900),  INT32_C(  1475189727), -INT32_C(  1678445853) },
      {              INT32_MAX,  INT32_C(  1100290489),  INT32_C(   658018675),  INT32_C(           0),  INT32_C(  2121722191),  INT32_C(           0), -INT32_C(  1779277285),  INT32_C(           0),
         INT32_C(  1906563511),  INT32_C(  1722956018), -INT32_C(   477238583), -INT32_C(  1037554829),  INT32_C(           0),  INT32_C(  1470659900),  INT32_C(  1475189727),  INT32_C(           0) } },
    { UINT16_C(38859),
      { -INT32_C(  1093681908), -INT32_C(  1314350813), -INT32_C(  1529078916),  INT32_C(   507769053),  INT32_C(  1000046483), -INT32_C(   992576809), -INT32_C(   977880367),  INT32_C(  1633452373),
         INT32_C(  1646210110),  INT32_C(  1091815365), -INT32_C(  1075449886),  INT32_C(  1927162335),  INT32_C(  2142140840), -INT32_C(   985430796), -INT32_C(  1819543234), -INT32_C(  1175132294) },
      { -INT32_C(  1093681908), -INT32_C(  1314350813),  INT32_C(           0),  INT32_C(   507769053),  INT32_C(           0),  INT32_C(           0), -INT32_C(   977880367),  INT32_C(  1633452373),
         INT32_C(  1646210110),  INT32_C(  1091815365), -INT32_C(  1075449886),  INT32_C(           0),  INT32_C(  2142140840),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1175132294) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    int32_t r[sizeof(simde__m512i) / sizeof(int32_t)] = {INT32_MAX};
    simde_mm512_mask_storeu_epi32(r, test_vec[i].k, a);
    simde_assert_equal_vi32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    int32_t r[sizeof(simde__m512i) / sizeof(int32_t)] = {INT32_MAX};
    simde_mm512_mask_storeu_epi32(r, k, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vi32(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_storeu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { UINT8_C( 19),
      {  INT64_C( 2142615211752299283), -INT64_C( 3183922503525565185), -INT64_C( 8223417254364622819),  INT64_C( 8868643648410448664),
         INT64_C(  298946238107544539), -INT64_C( 5783470113559927922),  INT64_C( 2913037383019561804),  INT64_C( 1190985725486068900) },
      {  INT64_C( 2142615211752299283), -INT64_C( 3183922503525565185),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(  298946238107544539),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 38),
      {  INT64_C( 7169219612774177501), -INT64_C( 6438841095509678245),  INT64_C( 7406697289000387829),  INT64_C( 4209083743792256263),
         INT64_C( 2263526947112522949), -INT64_C(  515349882283270384),  INT64_C( 8644913955411497120),  INT64_C(  311913023838786493) },
      {                      INT64_MAX, -INT64_C( 6438841095509678245),  INT64_C( 7406697289000387829),  INT64_C(                   0),
         INT64_C(                   0), -INT64_C(  515349882283270384),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(183),
      { -INT64_C( 3298715808146191745), -INT64_C( 3039984431212893422), -INT64_C( 1400130915136085524),  INT64_C( 9102107997213731702),
         INT64_C( 8826736856552361016),  INT64_C( 1108860927864230985), -INT64_C( 2657840231396169512), -INT64_C( 5792256434604062689) },
      { -INT64_C( 3298715808146191745), -INT64_C( 3039984431212893422), -INT64_C( 1400130915136085524),  INT64_C(                   0),
         INT64_C( 8826736856552361016),  INT64_C( 1108860927864230985),  INT64_C(                   0), -INT64_C( 5792256434604062689) } },
    { UINT8_C(146),
      {  INT64_C( 3345175999661300548),  INT64_C(  390793222694238748),  INT64_C(  277046950126787908), -INT64_C( 2877755543647553607),
        -INT64_C( 7382693375998489981), -INT64_C( 9168315930228433823),  INT64_C( 3095118024986405942),  INT64_C( 1906634073785789960) },
      {                      INT64_MAX,  INT64_C(  390793222694238748),  INT64_C(                   0),  INT64_C(                   0),
        -INT64_C( 7382693375998489981),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 1906634073785789960) } },
    { UINT8_C(195),
      { -INT64_C( 2433955892857637008), -INT64_C( 1885148172450597369),  INT64_C( 3093270067863275732),  INT64_C( 7973020603101841705),
        -INT64_C( 4165128444658195118), -INT64_C( 4966839375944594317),  INT64_C( 1363620822301829125), -INT64_C( 2700865066752496361) },
      { -INT64_C( 2433955892857637008), -INT64_C( 1885148172450597369),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C( 1363620822301829125), -INT64_C( 2700865066752496361) } },
    { UINT8_C(126),
      { -INT64_C( 6000478741959135543),  INT64_C( 7038369726343735147),  INT64_C(  546162998537514736), -INT64_C(  619129298555524528),
         INT64_C( 1559645883664869015),  INT64_C( 8591296370868828384),  INT64_C( 3619638325854701017), -INT64_C( 3793856950092182989) },
      {                      INT64_MAX,  INT64_C( 7038369726343735147),  INT64_C(  546162998537514736), -INT64_C(  619129298555524528),
         INT64_C( 1559645883664869015),  INT64_C( 8591296370868828384),  INT64_C( 3619638325854701017),  INT64_C(                   0) } },
    { UINT8_C( 41),
      { -INT64_C( 6957804793266650217),  INT64_C(  714557780952238503),  INT64_C( 2544564958527102611), -INT64_C( 6708917540898754248),
         INT64_C( 5326812376747653606),  INT64_C( 4861993896824738540), -INT64_C( 5124902308984888221),  INT64_C( 4615724913002821473) },
      { -INT64_C( 6957804793266650217),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 6708917540898754248),
         INT64_C(                   0),  INT64_C( 4861993896824738540),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 18),
      { -INT64_C( 8299854313779065536),  INT64_C( 2162432310098280537), -INT64_C( 2958487141662933280), -INT64_C( 6037513545460982325),
         INT64_C( 4684974964431907582), -INT64_C( 6883502714649558880),  INT64_C( 4041174093241783968), -INT64_C( 5361655517030890113) },
      {                      INT64_MAX,  INT64_C( 2162432310098280537),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C( 4684974964431907582),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    int64_t r[sizeof(simde__m512i) / sizeof(int64_t)] = {INT64_MAX};
    simde_mm512_mask_storeu_epi64(r, test_vec[i].k, a);
    simde_assert_equal_vi64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    int64_t r[sizeof(simde__m512i) / sizeof(int64_t)] = {INT64_MAX};
    simde_mm512_mask_storeu_epi64(r, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vi64(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_storeu_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   397.85), SIMDE_FLOAT32_C(   280.50), SIMDE_FLOAT32_C(  -482.10), SIMDE_FLOAT32_C(  -764.38),
        SIMDE_FLOAT32_C(   375.26), SIMDE_FLOAT32_C(  -613.57), SIMDE_FLOAT32_C(    56.03), SIMDE_FLOAT32_C(   417.16),
        SIMDE_FLOAT32_C(  -424.36), SIMDE_FLOAT32_C(    64.48), SIMDE_FLOAT32_C(     0.84), SIMDE_FLOAT32_C(   101.24),
        SIMDE_FLOAT32_C(  -965.83), SIMDE_FLOAT32_C(   916.49), SIMDE_FLOAT32_C(   799.09), SIMDE_FLOAT32_C(   628.08) },
      { SIMDE_FLOAT32_C(   397.85), SIMDE_FLOAT32_C(   280.50), SIMDE_FLOAT32_C(  -482.10), SIMDE_FLOAT32_C(  -764.38),
        SIMDE_FLOAT32_C(   375.26), SIMDE_FLOAT32_C(  -613.57), SIMDE_FLOAT32_C(    56.03), SIMDE_FLOAT32_C(   417.16),
        SIMDE_FLOAT32_C(  -424.36), SIMDE_FLOAT32_C(    64.48), SIMDE_FLOAT32_C(     0.84), SIMDE_FLOAT32_C(   101.24),
        SIMDE_FLOAT32_C(  -965.83), SIMDE_FLOAT32_C(   916.49), SIMDE_FLOAT32_C(   799.09), SIMDE_FLOAT32_C(   628.08) } },
    { { SIMDE_FLOAT32_C(  -588.70), SIMDE_FLOAT32_C(   688.61), SIMDE_FLOAT32_C(   202.01), SIMDE_FLOAT32_C(  -610.64),
        SIMDE_FLOAT32_C(   838.07), SIMDE_FLOAT32_C(  -733.40), SIMDE_FLOAT32_C(  -127.00), SIMDE_FLOAT32_C(   993.35),
        SIMDE_FLOAT32_C(  -249.66), SIMDE_FLOAT32_C(   -45.23), SIMDE_FLOAT32_C(   849.71), SIMDE_FLOAT32_C(   -85.52),
        SIMDE_FLOAT32_C(   193.59), SIMDE_FLOAT32_C(  -257.46), SIMDE_FLOAT32_C(   827.23), SIMDE_FLOAT32_C(  -408.56) },
      { SIMDE_FLOAT32_C(  -588.70), SIMDE_FLOAT32_C(   688.61), SIMDE_FLOAT32_C(   202.01), SIMDE_FLOAT32_C(  -610.64),
        SIMDE_FLOAT32_C(   838.07), SIMDE_FLOAT32_C(  -733.40), SIMDE_FLOAT32_C(  -127.00), SIMDE_FLOAT32_C(   993.35),
        SIMDE_FLOAT32_C(  -249.66), SIMDE_FLOAT32_C(   -45.23), SIMDE_FLOAT32_C(   849.71), SIMDE_FLOAT32_C(   -85.52),
        SIMDE_FLOAT32_C(   193.59), SIMDE_FLOAT32_C(  -257.46), SIMDE_FLOAT32_C(   827.23), SIMDE_FLOAT32_C(  -408.56) } },
    { { SIMDE_FLOAT32_C(  -976.96), SIMDE_FLOAT32_C(  -654.87), SIMDE_FLOAT32_C(  -172.94), SIMDE_FLOAT32_C(   398.29),
        SIMDE_FLOAT32_C(  -268.45), SIMDE_FLOAT32_C(   883.09), SIMDE_FLOAT32_C(  -184.55), SIMDE_FLOAT32_C(   307.20),
        SIMDE_FLOAT32_C(   -52.43), SIMDE_FLOAT32_C(   816.29), SIMDE_FLOAT32_C(  -591.56), SIMDE_FLOAT32_C(   -18.26),
        SIMDE_FLOAT32_C(   732.78), SIMDE_FLOAT32_C(  -792.48), SIMDE_FLOAT32_C(  -390.18), SIMDE_FLOAT32_C(  -855.92) },
      { SIMDE_FLOAT32_C(  -976.96), SIMDE_FLOAT32_C(  -654.87), SIMDE_FLOAT32_C(  -172.94), SIMDE_FLOAT32_C(   398.29),
        SIMDE_FLOAT32_C(  -268.45), SIMDE_FLOAT32_C(   883.09), SIMDE_FLOAT32_C(  -184.55), SIMDE_FLOAT32_C(   307.20),
        SIMDE_FLOAT32_C(   -52.43), SIMDE_FLOAT32_C(   816.29), SIMDE_FLOAT32_C(  -591.56), SIMDE_FLOAT32_C(   -18.26),
        SIMDE_FLOAT32_C(   732.78), SIMDE_FLOAT32_C(  -792.48), SIMDE_FLOAT32_C(  -390.18), SIMDE_FLOAT32_C(  -855.92) } },
    { { SIMDE_FLOAT32_C(   896.13), SIMDE_FLOAT32_C(   811.83), SIMDE_FLOAT32_C(  -466.56), SIMDE_FLOAT32_C(   734.20),
        SIMDE_FLOAT32_C(  -921.57), SIMDE_FLOAT32_C(   406.44), SIMDE_FLOAT32_C(   727.55), SIMDE_FLOAT32_C(  -171.23),
        SIMDE_FLOAT32_C(  -638.79), SIMDE_FLOAT32_C(   577.26), SIMDE_FLOAT32_C(   743.25), SIMDE_FLOAT32_C(   554.80),
        SIMDE_FLOAT32_C(  -680.21), SIMDE_FLOAT32_C(   570.48), SIMDE_FLOAT32_C(  -853.75), SIMDE_FLOAT32_C(  -657.17) },
      { SIMDE_FLOAT32_C(   896.13), SIMDE_FLOAT32_C(   811.83), SIMDE_FLOAT32_C(  -466.56), SIMDE_FLOAT32_C(   734.20),
        SIMDE_FLOAT32_C(  -921.57), SIMDE_FLOAT32_C(   406.44), SIMDE_FLOAT32_C(   727.55), SIMDE_FLOAT32_C(  -171.23),
        SIMDE_FLOAT32_C(  -638.79), SIMDE_FLOAT32_C(   577.26), SIMDE_FLOAT32_C(   743.25), SIMDE_FLOAT32_C(   554.80),
        SIMDE_FLOAT32_C(  -680.21), SIMDE_FLOAT32_C(   570.48), SIMDE_FLOAT32_C(  -853.75), SIMDE_FLOAT32_C(  -657.17) } },
    { { SIMDE_FLOAT32_C(   915.61), SIMDE_FLOAT32_C(   -26.70), SIMDE_FLOAT32_C(   741.12), SIMDE_FLOAT32_C(  -352.84),
        SIMDE_FLOAT32_C(  -143.61), SIMDE_FLOAT32_C(  -443.43), SIMDE_FLOAT32_C(   954.36), SIMDE_FLOAT32_C(   803.96),
        SIMDE_FLOAT32_C(  -627.14), SIMDE_FLOAT32_C(  -637.21), SIMDE_FLOAT32_C(  -214.30), SIMDE_FLOAT32_C(  -894.36),
        SIMDE_FLOAT32_C(  -429.68), SIMDE_FLOAT32_C(   395.52), SIMDE_FLOAT32_C(  -750.28), SIMDE_FLOAT32_C(  -533.55) },
      { SIMDE_FLOAT32_C(   915.61), SIMDE_FLOAT32_C(   -26.70), SIMDE_FLOAT32_C(   741.12), SIMDE_FLOAT32_C(  -352.84),
        SIMDE_FLOAT32_C(  -143.61), SIMDE_FLOAT32_C(  -443.43), SIMDE_FLOAT32_C(   954.36), SIMDE_FLOAT32_C(   803.96),
        SIMDE_FLOAT32_C(  -627.14), SIMDE_FLOAT32_C(  -637.21), SIMDE_FLOAT32_C(  -214.30), SIMDE_FLOAT32_C(  -894.36),
        SIMDE_FLOAT32_C(  -429.68), SIMDE_FLOAT32_C(   395.52), SIMDE_FLOAT32_C(  -750.28), SIMDE_FLOAT32_C(  -533.55) } },
    { { SIMDE_FLOAT32_C(   207.35), SIMDE_FLOAT32_C(  -216.84), SIMDE_FLOAT32_C(  -799.36), SIMDE_FLOAT32_C(   285.78),
        SIMDE_FLOAT32_C(  -810.40), SIMDE_FLOAT32_C(   928.19), SIMDE_FLOAT32_C(  -885.45), SIMDE_FLOAT32_C(  -449.19),
        SIMDE_FLOAT32_C(   505.45), SIMDE_FLOAT32_C(   857.81), SIMDE_FLOAT32_C(  -894.39), SIMDE_FLOAT32_C(   825.24),
        SIMDE_FLOAT32_C(   428.29), SIMDE_FLOAT32_C(  -748.14), SIMDE_FLOAT32_C(  -831.93), SIMDE_FLOAT32_C(   343.89) },
      { SIMDE_FLOAT32_C(   207.35), SIMDE_FLOAT32_C(  -216.84), SIMDE_FLOAT32_C(  -799.36), SIMDE_FLOAT32_C(   285.78),
        SIMDE_FLOAT32_C(  -810.40), SIMDE_FLOAT32_C(   928.19), SIMDE_FLOAT32_C(  -885.45), SIMDE_FLOAT32_C(  -449.19),
        SIMDE_FLOAT32_C(   505.45), SIMDE_FLOAT32_C(   857.81), SIMDE_FLOAT32_C(  -894.39), SIMDE_FLOAT32_C(   825.24),
        SIMDE_FLOAT32_C(   428.29), SIMDE_FLOAT32_C(  -748.14), SIMDE_FLOAT32_C(  -831.93), SIMDE_FLOAT32_C(   343.89) } },
    { { SIMDE_FLOAT32_C(   225.16), SIMDE_FLOAT32_C(   909.19), SIMDE_FLOAT32_C(   991.05), SIMDE_FLOAT32_C(  -918.45),
        SIMDE_FLOAT32_C(  -534.23), SIMDE_FLOAT32_C(   945.41), SIMDE_FLOAT32_C(   885.51), SIMDE_FLOAT32_C(  -161.37),
        SIMDE_FLOAT32_C(  -691.80), SIMDE_FLOAT32_C(  -328.80), SIMDE_FLOAT32_C(   -55.73), SIMDE_FLOAT32_C(  -121.48),
        SIMDE_FLOAT32_C(  -933.28), SIMDE_FLOAT32_C(   193.99), SIMDE_FLOAT32_C(   344.96), SIMDE_FLOAT32_C(   274.08) },
      { SIMDE_FLOAT32_C(   225.16), SIMDE_FLOAT32_C(   909.19), SIMDE_FLOAT32_C(   991.05), SIMDE_FLOAT32_C(  -918.45),
        SIMDE_FLOAT32_C(  -534.23), SIMDE_FLOAT32_C(   945.41), SIMDE_FLOAT32_C(   885.51), SIMDE_FLOAT32_C(  -161.37),
        SIMDE_FLOAT32_C(  -691.80), SIMDE_FLOAT32_C(  -328.80), SIMDE_FLOAT32_C(   -55.73), SIMDE_FLOAT32_C(  -121.48),
        SIMDE_FLOAT32_C(  -933.28), SIMDE_FLOAT32_C(   193.99), SIMDE_FLOAT32_C(   344.96), SIMDE_FLOAT32_C(   274.08) } },
    { { SIMDE_FLOAT32_C(   977.14), SIMDE_FLOAT32_C(   545.61), SIMDE_FLOAT32_C(  -440.14), SIMDE_FLOAT32_C(  -833.26),
        SIMDE_FLOAT32_C(   473.80), SIMDE_FLOAT32_C(  -325.59), SIMDE_FLOAT32_C(  -282.45), SIMDE_FLOAT32_C(   -20.75),
        SIMDE_FLOAT32_C(  -467.78), SIMDE_FLOAT32_C(  -176.84), SIMDE_FLOAT32_C(  -195.51), SIMDE_FLOAT32_C(   960.51),
        SIMDE_FLOAT32_C(    75.02), SIMDE_FLOAT32_C(   -27.44), SIMDE_FLOAT32_C(   304.40), SIMDE_FLOAT32_C(  -699.82) },
      { SIMDE_FLOAT32_C(   977.14), SIMDE_FLOAT32_C(   545.61), SIMDE_FLOAT32_C(  -440.14), SIMDE_FLOAT32_C(  -833.26),
        SIMDE_FLOAT32_C(   473.80), SIMDE_FLOAT32_C(  -325.59), SIMDE_FLOAT32_C(  -282.45), SIMDE_FLOAT32_C(   -20.75),
        SIMDE_FLOAT32_C(  -467.78), SIMDE_FLOAT32_C(  -176.84), SIMDE_FLOAT32_C(  -195.51), SIMDE_FLOAT32_C(   960.51),
        SIMDE_FLOAT32_C(    75.02), SIMDE_FLOAT32_C(   -27.44), SIMDE_FLOAT32_C(   304.40), SIMDE_FLOAT32_C(  -699.82) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde_float32 r[sizeof(simde__m512) / sizeof(simde_float32)] = {0};
    simde_mm512_storeu_ps(r, a);
    simde_assert_equal_vf32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_float32 r[sizeof(simde__m512) / sizeof(simde_float32)] = {0};
    simde_mm512_storeu_ps(r, a);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vf32(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#if defined(SIMDE_FLOAT16_IS_SCALAR)
static int
test_simde_mm_storeu_ph (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float16 a[8];
    const simde_float16 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   460.00), SIMDE_FLOAT16_VALUE(   778.50), SIMDE_FLOAT16_VALUE(   314.50), SIMDE_FLOAT16_VALUE(  -760.50),
        SIMDE_FLOAT16_VALUE(  -716.00), SIMDE_FLOAT16_VALUE(  -707.00), SIMDE_FLOAT16_VALUE(    64.75), SIMDE_FLOAT16_VALUE(  -866.50) },
      { SIMDE_FLOAT16_VALUE(   460.00), SIMDE_FLOAT16_VALUE(   778.50), SIMDE_FLOAT16_VALUE(   314.50), SIMDE_FLOAT16_VALUE(  -760.50),
        SIMDE_FLOAT16_VALUE(  -716.00), SIMDE_FLOAT16_VALUE(  -707.00), SIMDE_FLOAT16_VALUE(    64.75), SIMDE_FLOAT16_VALUE(  -866.50) } },
    { { SIMDE_FLOAT16_VALUE(    16.27), SIMDE_FLOAT16_VALUE(   601.50), SIMDE_FLOAT16_VALUE(  -476.00), SIMDE_FLOAT16_VALUE(   185.75),
        SIMDE_FLOAT16_VALUE(    63.53), SIMDE_FLOAT16_VALUE(  -789.50), SIMDE_FLOAT16_VALUE(  -960.00), SIMDE_FLOAT16_VALUE(   790.50) },
      { SIMDE_FLOAT16_VALUE(    16.27), SIMDE_FLOAT16_VALUE(   601.50), SIMDE_FLOAT16_VALUE(  -476.00), SIMDE_FLOAT16_VALUE(   185.75),
        SIMDE_FLOAT16_VALUE(    63.53), SIMDE_FLOAT16_VALUE(  -789.50), SIMDE_FLOAT16_VALUE(  -960.00), SIMDE_FLOAT16_VALUE(   790.50) } },
    { { SIMDE_FLOAT16_VALUE(   637.50), SIMDE_FLOAT16_VALUE(  -816.50), SIMDE_FLOAT16_VALUE(   180.88), SIMDE_FLOAT16_VALUE(  -284.25),
        SIMDE_FLOAT16_VALUE(  -768.00), SIMDE_FLOAT16_VALUE(  -220.25), SIMDE_FLOAT16_VALUE(   591.50), SIMDE_FLOAT16_VALUE(  -748.50) },
      { SIMDE_FLOAT16_VALUE(   637.50), SIMDE_FLOAT16_VALUE(  -816.50), SIMDE_FLOAT16_VALUE(   180.88), SIMDE_FLOAT16_VALUE(  -284.25),
        SIMDE_FLOAT16_VALUE(  -768.00), SIMDE_FLOAT16_VALUE(  -220.25), SIMDE_FLOAT16_VALUE(   591.50), SIMDE_FLOAT16_VALUE(  -748.50) } },
    { { SIMDE_FLOAT16_VALUE(   700.50), SIMDE_FLOAT16_VALUE(  -439.75), SIMDE_FLOAT16_VALUE(   -97.50), SIMDE_FLOAT16_VALUE(  -302.00),
        SIMDE_FLOAT16_VALUE(  -214.25), SIMDE_FLOAT16_VALUE(  -683.50), SIMDE_FLOAT16_VALUE(   521.50), SIMDE_FLOAT16_VALUE(  -754.00) },
      { SIMDE_FLOAT16_VALUE(   700.50), SIMDE_FLOAT16_VALUE(  -439.75), SIMDE_FLOAT16_VALUE(   -97.50), SIMDE_FLOAT16_VALUE(  -302.00),
        SIMDE_FLOAT16_VALUE(  -214.25), SIMDE_FLOAT16_VALUE(  -683.50), SIMDE_FLOAT16_VALUE(   521.50), SIMDE_FLOAT16_VALUE(  -754.00) } },
    { { SIMDE_FLOAT16_VALUE(  -905.00), SIMDE_FLOAT16_VALUE(  -164.00), SIMDE_FLOAT16_VALUE(  -514.50), SIMDE_FLOAT16_VALUE(  -621.00),
        SIMDE_FLOAT16_VALUE(   128.75), SIMDE_FLOAT16_VALUE(   550.00), SIMDE_FLOAT16_VALUE(  -487.50), SIMDE_FLOAT16_VALUE(  -855.00) },
      { SIMDE_FLOAT16_VALUE(  -905.00), SIMDE_FLOAT16_VALUE(  -164.00), SIMDE_FLOAT16_VALUE(  -514.50), SIMDE_FLOAT16_VALUE(  -621.00),
        SIMDE_FLOAT16_VALUE(   128.75), SIMDE_FLOAT16_VALUE(   550.00), SIMDE_FLOAT16_VALUE(  -487.50), SIMDE_FLOAT16_VALUE(  -855.00) } },
    { { SIMDE_FLOAT16_VALUE(   151.38), SIMDE_FLOAT16_VALUE(    36.66), SIMDE_FLOAT16_VALUE(   330.75), SIMDE_FLOAT16_VALUE(  -785.00),
        SIMDE_FLOAT16_VALUE(   247.00), SIMDE_FLOAT16_VALUE(   370.75), SIMDE_FLOAT16_VALUE(  -994.50), SIMDE_FLOAT16_VALUE(  -115.44) },
      { SIMDE_FLOAT16_VALUE(   151.38), SIMDE_FLOAT16_VALUE(    36.66), SIMDE_FLOAT16_VALUE(   330.75), SIMDE_FLOAT16_VALUE(  -785.00),
        SIMDE_FLOAT16_VALUE(   247.00), SIMDE_FLOAT16_VALUE(   370.75), SIMDE_FLOAT16_VALUE(  -994.50), SIMDE_FLOAT16_VALUE(  -115.44) } },
    { { SIMDE_FLOAT16_VALUE(   554.50), SIMDE_FLOAT16_VALUE(   186.25), SIMDE_FLOAT16_VALUE(   600.50), SIMDE_FLOAT16_VALUE(   786.50),
        SIMDE_FLOAT16_VALUE(   966.00), SIMDE_FLOAT16_VALUE(   191.62), SIMDE_FLOAT16_VALUE(  -962.00), SIMDE_FLOAT16_VALUE(   666.50) },
      { SIMDE_FLOAT16_VALUE(   554.50), SIMDE_FLOAT16_VALUE(   186.25), SIMDE_FLOAT16_VALUE(   600.50), SIMDE_FLOAT16_VALUE(   786.50),
        SIMDE_FLOAT16_VALUE(   966.00), SIMDE_FLOAT16_VALUE(   191.62), SIMDE_FLOAT16_VALUE(  -962.00), SIMDE_FLOAT16_VALUE(   666.50) } },
    { { SIMDE_FLOAT16_VALUE(   752.00), SIMDE_FLOAT16_VALUE(   -59.50), SIMDE_FLOAT16_VALUE(  -635.50), SIMDE_FLOAT16_VALUE(  -462.25),
        SIMDE_FLOAT16_VALUE(   257.00), SIMDE_FLOAT16_VALUE(   886.00), SIMDE_FLOAT16_VALUE(  -216.38), SIMDE_FLOAT16_VALUE(   351.75) },
      { SIMDE_FLOAT16_VALUE(   752.00), SIMDE_FLOAT16_VALUE(   -59.50), SIMDE_FLOAT16_VALUE(  -635.50), SIMDE_FLOAT16_VALUE(  -462.25),
        SIMDE_FLOAT16_VALUE(   257.00), SIMDE_FLOAT16_VALUE(   886.00), SIMDE_FLOAT16_VALUE(  -216.38), SIMDE_FLOAT16_VALUE(   351.75) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128h a = simde_mm_loadu_ph(test_vec[i].a);
    simde_float16 r[sizeof(simde__m128h) / sizeof(simde_float16)] = { SIMDE_FLOAT16_VALUE(0.00) };
    simde_mm_storeu_ph(r, a);
    simde_assert_equal_vf16(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128h a = simde_test_x86_random_f16x8(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
    simde_float16 r[sizeof(simde__m128h) / sizeof(simde_float16)] = {0};
    simde_mm_storeu_ph(r, a);

    simde_test_x86_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vf16(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_storeu_ph (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float16 a[16];
    const simde_float16 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(  -277.75), SIMDE_FLOAT16_VALUE(   268.75), SIMDE_FLOAT16_VALUE(   731.00), SIMDE_FLOAT16_VALUE(   851.00),
        SIMDE_FLOAT16_VALUE(  -181.12), SIMDE_FLOAT16_VALUE(  -756.50), SIMDE_FLOAT16_VALUE(   996.00), SIMDE_FLOAT16_VALUE(   970.00),
        SIMDE_FLOAT16_VALUE(   280.00), SIMDE_FLOAT16_VALUE(   326.75), SIMDE_FLOAT16_VALUE(  -815.00), SIMDE_FLOAT16_VALUE(  -473.00),
        SIMDE_FLOAT16_VALUE(  -302.75), SIMDE_FLOAT16_VALUE(  -809.50), SIMDE_FLOAT16_VALUE(   411.50), SIMDE_FLOAT16_VALUE(  -748.50) },
      { SIMDE_FLOAT16_VALUE(  -277.75), SIMDE_FLOAT16_VALUE(   268.75), SIMDE_FLOAT16_VALUE(   731.00), SIMDE_FLOAT16_VALUE(   851.00),
        SIMDE_FLOAT16_VALUE(  -181.12), SIMDE_FLOAT16_VALUE(  -756.50), SIMDE_FLOAT16_VALUE(   996.00), SIMDE_FLOAT16_VALUE(   970.00),
        SIMDE_FLOAT16_VALUE(   280.00), SIMDE_FLOAT16_VALUE(   326.75), SIMDE_FLOAT16_VALUE(  -815.00), SIMDE_FLOAT16_VALUE(  -473.00),
        SIMDE_FLOAT16_VALUE(  -302.75), SIMDE_FLOAT16_VALUE(  -809.50), SIMDE_FLOAT16_VALUE(   411.50), SIMDE_FLOAT16_VALUE(  -748.50) } },
    { { SIMDE_FLOAT16_VALUE(   377.00), SIMDE_FLOAT16_VALUE(    11.76), SIMDE_FLOAT16_VALUE(  -962.00), SIMDE_FLOAT16_VALUE(   343.00),
        SIMDE_FLOAT16_VALUE(  -796.50), SIMDE_FLOAT16_VALUE(  -924.00), SIMDE_FLOAT16_VALUE(     9.63), SIMDE_FLOAT16_VALUE(   955.50),
        SIMDE_FLOAT16_VALUE(    16.52), SIMDE_FLOAT16_VALUE(   374.25), SIMDE_FLOAT16_VALUE(  -506.75), SIMDE_FLOAT16_VALUE(  -726.50),
        SIMDE_FLOAT16_VALUE(   260.50), SIMDE_FLOAT16_VALUE(   276.75), SIMDE_FLOAT16_VALUE(   625.50), SIMDE_FLOAT16_VALUE(   982.50) },
      { SIMDE_FLOAT16_VALUE(   377.00), SIMDE_FLOAT16_VALUE(    11.76), SIMDE_FLOAT16_VALUE(  -962.00), SIMDE_FLOAT16_VALUE(   343.00),
        SIMDE_FLOAT16_VALUE(  -796.50), SIMDE_FLOAT16_VALUE(  -924.00), SIMDE_FLOAT16_VALUE(     9.63), SIMDE_FLOAT16_VALUE(   955.50),
        SIMDE_FLOAT16_VALUE(    16.52), SIMDE_FLOAT16_VALUE(   374.25), SIMDE_FLOAT16_VALUE(  -506.75), SIMDE_FLOAT16_VALUE(  -726.50),
        SIMDE_FLOAT16_VALUE(   260.50), SIMDE_FLOAT16_VALUE(   276.75), SIMDE_FLOAT16_VALUE(   625.50), SIMDE_FLOAT16_VALUE(   982.50) } },
    { { SIMDE_FLOAT16_VALUE(  -454.25), SIMDE_FLOAT16_VALUE(   356.00), SIMDE_FLOAT16_VALUE(   833.50), SIMDE_FLOAT16_VALUE(   364.50),
        SIMDE_FLOAT16_VALUE(   599.50), SIMDE_FLOAT16_VALUE(   829.50), SIMDE_FLOAT16_VALUE(   334.75), SIMDE_FLOAT16_VALUE(  -120.69),
        SIMDE_FLOAT16_VALUE(   156.00), SIMDE_FLOAT16_VALUE(   520.00), SIMDE_FLOAT16_VALUE(   406.25), SIMDE_FLOAT16_VALUE(   853.50),
        SIMDE_FLOAT16_VALUE(   710.50), SIMDE_FLOAT16_VALUE(  -182.25), SIMDE_FLOAT16_VALUE(  -895.00), SIMDE_FLOAT16_VALUE(    87.44) },
      { SIMDE_FLOAT16_VALUE(  -454.25), SIMDE_FLOAT16_VALUE(   356.00), SIMDE_FLOAT16_VALUE(   833.50), SIMDE_FLOAT16_VALUE(   364.50),
        SIMDE_FLOAT16_VALUE(   599.50), SIMDE_FLOAT16_VALUE(   829.50), SIMDE_FLOAT16_VALUE(   334.75), SIMDE_FLOAT16_VALUE(  -120.69),
        SIMDE_FLOAT16_VALUE(   156.00), SIMDE_FLOAT16_VALUE(   520.00), SIMDE_FLOAT16_VALUE(   406.25), SIMDE_FLOAT16_VALUE(   853.50),
        SIMDE_FLOAT16_VALUE(   710.50), SIMDE_FLOAT16_VALUE(  -182.25), SIMDE_FLOAT16_VALUE(  -895.00), SIMDE_FLOAT16_VALUE(    87.44) } },
    { { SIMDE_FLOAT16_VALUE(   829.50), SIMDE_FLOAT16_VALUE(  -857.00), SIMDE_FLOAT16_VALUE(  -569.50), SIMDE_FLOAT16_VALUE(  -967.00),
        SIMDE_FLOAT16_VALUE(  -781.00), SIMDE_FLOAT16_VALUE(   440.00), SIMDE_FLOAT16_VALUE(   988.50), SIMDE_FLOAT16_VALUE(   235.50),
        SIMDE_FLOAT16_VALUE(  -185.62), SIMDE_FLOAT16_VALUE(  -518.50), SIMDE_FLOAT16_VALUE(   509.00), SIMDE_FLOAT16_VALUE(  -925.00),
        SIMDE_FLOAT16_VALUE(   758.50), SIMDE_FLOAT16_VALUE(   134.38), SIMDE_FLOAT16_VALUE(  -942.50), SIMDE_FLOAT16_VALUE(  -696.00) },
      { SIMDE_FLOAT16_VALUE(   829.50), SIMDE_FLOAT16_VALUE(  -857.00), SIMDE_FLOAT16_VALUE(  -569.50), SIMDE_FLOAT16_VALUE(  -967.00),
        SIMDE_FLOAT16_VALUE(  -781.00), SIMDE_FLOAT16_VALUE(   440.00), SIMDE_FLOAT16_VALUE(   988.50), SIMDE_FLOAT16_VALUE(   235.50),
        SIMDE_FLOAT16_VALUE(  -185.62), SIMDE_FLOAT16_VALUE(  -518.50), SIMDE_FLOAT16_VALUE(   509.00), SIMDE_FLOAT16_VALUE(  -925.00),
        SIMDE_FLOAT16_VALUE(   758.50), SIMDE_FLOAT16_VALUE(   134.38), SIMDE_FLOAT16_VALUE(  -942.50), SIMDE_FLOAT16_VALUE(  -696.00) } },
    { { SIMDE_FLOAT16_VALUE(  -509.50), SIMDE_FLOAT16_VALUE(   891.00), SIMDE_FLOAT16_VALUE(   668.50), SIMDE_FLOAT16_VALUE(  -910.00),
        SIMDE_FLOAT16_VALUE(   720.50), SIMDE_FLOAT16_VALUE(     3.48), SIMDE_FLOAT16_VALUE(   -30.88), SIMDE_FLOAT16_VALUE(  -123.75),
        SIMDE_FLOAT16_VALUE(  -476.50), SIMDE_FLOAT16_VALUE(  -624.50), SIMDE_FLOAT16_VALUE(  -270.50), SIMDE_FLOAT16_VALUE(  -766.00),
        SIMDE_FLOAT16_VALUE(   193.12), SIMDE_FLOAT16_VALUE(  -165.50), SIMDE_FLOAT16_VALUE(   321.50), SIMDE_FLOAT16_VALUE(    22.66) },
      { SIMDE_FLOAT16_VALUE(  -509.50), SIMDE_FLOAT16_VALUE(   891.00), SIMDE_FLOAT16_VALUE(   668.50), SIMDE_FLOAT16_VALUE(  -910.00),
        SIMDE_FLOAT16_VALUE(   720.50), SIMDE_FLOAT16_VALUE(     3.48), SIMDE_FLOAT16_VALUE(   -30.88), SIMDE_FLOAT16_VALUE(  -123.75),
        SIMDE_FLOAT16_VALUE(  -476.50), SIMDE_FLOAT16_VALUE(  -624.50), SIMDE_FLOAT16_VALUE(  -270.50), SIMDE_FLOAT16_VALUE(  -766.00),
        SIMDE_FLOAT16_VALUE(   193.12), SIMDE_FLOAT16_VALUE(  -165.50), SIMDE_FLOAT16_VALUE(   321.50), SIMDE_FLOAT16_VALUE(    22.66) } },
    { { SIMDE_FLOAT16_VALUE(   -22.52), SIMDE_FLOAT16_VALUE(   751.50), SIMDE_FLOAT16_VALUE(    55.62), SIMDE_FLOAT16_VALUE(   196.50),
        SIMDE_FLOAT16_VALUE(   191.75), SIMDE_FLOAT16_VALUE(    44.03), SIMDE_FLOAT16_VALUE(  -568.00), SIMDE_FLOAT16_VALUE(  -994.00),
        SIMDE_FLOAT16_VALUE(   525.50), SIMDE_FLOAT16_VALUE(   941.00), SIMDE_FLOAT16_VALUE(  -919.00), SIMDE_FLOAT16_VALUE(   284.25),
        SIMDE_FLOAT16_VALUE(    75.25), SIMDE_FLOAT16_VALUE(  -861.50), SIMDE_FLOAT16_VALUE(   588.50), SIMDE_FLOAT16_VALUE(   565.50) },
      { SIMDE_FLOAT16_VALUE(   -22.52), SIMDE_FLOAT16_VALUE(   751.50), SIMDE_FLOAT16_VALUE(    55.62), SIMDE_FLOAT16_VALUE(   196.50),
        SIMDE_FLOAT16_VALUE(   191.75), SIMDE_FLOAT16_VALUE(    44.03), SIMDE_FLOAT16_VALUE(  -568.00), SIMDE_FLOAT16_VALUE(  -994.00),
        SIMDE_FLOAT16_VALUE(   525.50), SIMDE_FLOAT16_VALUE(   941.00), SIMDE_FLOAT16_VALUE(  -919.00), SIMDE_FLOAT16_VALUE(   284.25),
        SIMDE_FLOAT16_VALUE(    75.25), SIMDE_FLOAT16_VALUE(  -861.50), SIMDE_FLOAT16_VALUE(   588.50), SIMDE_FLOAT16_VALUE(   565.50) } },
    { { SIMDE_FLOAT16_VALUE(  -971.00), SIMDE_FLOAT16_VALUE(   257.00), SIMDE_FLOAT16_VALUE(   655.50), SIMDE_FLOAT16_VALUE(   749.50),
        SIMDE_FLOAT16_VALUE(  -739.50), SIMDE_FLOAT16_VALUE(  -375.50), SIMDE_FLOAT16_VALUE(  -374.25), SIMDE_FLOAT16_VALUE(  -216.00),
        SIMDE_FLOAT16_VALUE(     0.02), SIMDE_FLOAT16_VALUE(   355.25), SIMDE_FLOAT16_VALUE(    17.95), SIMDE_FLOAT16_VALUE(  -807.00),
        SIMDE_FLOAT16_VALUE(  -810.00), SIMDE_FLOAT16_VALUE(  -660.50), SIMDE_FLOAT16_VALUE(   215.88), SIMDE_FLOAT16_VALUE(   167.38) },
      { SIMDE_FLOAT16_VALUE(  -971.00), SIMDE_FLOAT16_VALUE(   257.00), SIMDE_FLOAT16_VALUE(   655.50), SIMDE_FLOAT16_VALUE(   749.50),
        SIMDE_FLOAT16_VALUE(  -739.50), SIMDE_FLOAT16_VALUE(  -375.50), SIMDE_FLOAT16_VALUE(  -374.25), SIMDE_FLOAT16_VALUE(  -216.00),
        SIMDE_FLOAT16_VALUE(     0.02), SIMDE_FLOAT16_VALUE(   355.25), SIMDE_FLOAT16_VALUE(    17.95), SIMDE_FLOAT16_VALUE(  -807.00),
        SIMDE_FLOAT16_VALUE(  -810.00), SIMDE_FLOAT16_VALUE(  -660.50), SIMDE_FLOAT16_VALUE(   215.88), SIMDE_FLOAT16_VALUE(   167.38) } },
    { { SIMDE_FLOAT16_VALUE(  -909.00), SIMDE_FLOAT16_VALUE(  -728.50), SIMDE_FLOAT16_VALUE(  -636.00), SIMDE_FLOAT16_VALUE(   282.75),
        SIMDE_FLOAT16_VALUE(   315.50), SIMDE_FLOAT16_VALUE(  -204.25), SIMDE_FLOAT16_VALUE(   288.75), SIMDE_FLOAT16_VALUE(  -158.88),
        SIMDE_FLOAT16_VALUE(  -263.25), SIMDE_FLOAT16_VALUE(   369.75), SIMDE_FLOAT16_VALUE(  -874.50), SIMDE_FLOAT16_VALUE(   812.00),
        SIMDE_FLOAT16_VALUE(   508.00), SIMDE_FLOAT16_VALUE(   713.50), SIMDE_FLOAT16_VALUE(   377.50), SIMDE_FLOAT16_VALUE(   537.00) },
      { SIMDE_FLOAT16_VALUE(  -909.00), SIMDE_FLOAT16_VALUE(  -728.50), SIMDE_FLOAT16_VALUE(  -636.00), SIMDE_FLOAT16_VALUE(   282.75),
        SIMDE_FLOAT16_VALUE(   315.50), SIMDE_FLOAT16_VALUE(  -204.25), SIMDE_FLOAT16_VALUE(   288.75), SIMDE_FLOAT16_VALUE(  -158.88),
        SIMDE_FLOAT16_VALUE(  -263.25), SIMDE_FLOAT16_VALUE(   369.75), SIMDE_FLOAT16_VALUE(  -874.50), SIMDE_FLOAT16_VALUE(   812.00),
        SIMDE_FLOAT16_VALUE(   508.00), SIMDE_FLOAT16_VALUE(   713.50), SIMDE_FLOAT16_VALUE(   377.50), SIMDE_FLOAT16_VALUE(   537.00) } },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256h a = simde_mm256_loadu_ph(test_vec[i].a);
    simde_float16 r[sizeof(simde__m256h) / sizeof(simde_float16)] = { SIMDE_FLOAT16_VALUE(0.00) };
    simde_mm256_storeu_ph(r, a);
    simde_assert_equal_vf16(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256h a = simde_test_x86_random_f16x16(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
    simde_float16 r[sizeof(simde__m256h) / sizeof(simde_float16)] = {0};
    simde_mm256_storeu_ph(r, a);

    simde_test_x86_write_f16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vf16(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_storeu_ph (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float16 a[32];
    const simde_float16 r[32];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   614.50), SIMDE_FLOAT16_VALUE(   397.50), SIMDE_FLOAT16_VALUE(   743.00), SIMDE_FLOAT16_VALUE(   963.00),
        SIMDE_FLOAT16_VALUE(   996.00), SIMDE_FLOAT16_VALUE(  -396.25), SIMDE_FLOAT16_VALUE(   558.50), SIMDE_FLOAT16_VALUE(  -368.25),
        SIMDE_FLOAT16_VALUE(   209.25), SIMDE_FLOAT16_VALUE(   440.00), SIMDE_FLOAT16_VALUE(  -763.50), SIMDE_FLOAT16_VALUE(   731.00),
        SIMDE_FLOAT16_VALUE(  -291.50), SIMDE_FLOAT16_VALUE(  -477.50), SIMDE_FLOAT16_VALUE(   439.25), SIMDE_FLOAT16_VALUE(  -934.50),
        SIMDE_FLOAT16_VALUE(   999.50), SIMDE_FLOAT16_VALUE(  -494.75), SIMDE_FLOAT16_VALUE(    79.06), SIMDE_FLOAT16_VALUE(   249.88),
        SIMDE_FLOAT16_VALUE(  -358.00), SIMDE_FLOAT16_VALUE(   242.00), SIMDE_FLOAT16_VALUE(  -751.50), SIMDE_FLOAT16_VALUE(   483.25),
        SIMDE_FLOAT16_VALUE(  -873.00), SIMDE_FLOAT16_VALUE(   974.50), SIMDE_FLOAT16_VALUE(  -845.50), SIMDE_FLOAT16_VALUE(   801.00),
        SIMDE_FLOAT16_VALUE(  -563.50), SIMDE_FLOAT16_VALUE(    43.72), SIMDE_FLOAT16_VALUE(  -969.50), SIMDE_FLOAT16_VALUE(  -949.00) },
      { SIMDE_FLOAT16_VALUE(   614.50), SIMDE_FLOAT16_VALUE(   397.50), SIMDE_FLOAT16_VALUE(   743.00), SIMDE_FLOAT16_VALUE(   963.00),
        SIMDE_FLOAT16_VALUE(   996.00), SIMDE_FLOAT16_VALUE(  -396.25), SIMDE_FLOAT16_VALUE(   558.50), SIMDE_FLOAT16_VALUE(  -368.25),
        SIMDE_FLOAT16_VALUE(   209.25), SIMDE_FLOAT16_VALUE(   440.00), SIMDE_FLOAT16_VALUE(  -763.50), SIMDE_FLOAT16_VALUE(   731.00),
        SIMDE_FLOAT16_VALUE(  -291.50), SIMDE_FLOAT16_VALUE(  -477.50), SIMDE_FLOAT16_VALUE(   439.25), SIMDE_FLOAT16_VALUE(  -934.50),
        SIMDE_FLOAT16_VALUE(   999.50), SIMDE_FLOAT16_VALUE(  -494.75), SIMDE_FLOAT16_VALUE(    79.06), SIMDE_FLOAT16_VALUE(   249.88),
        SIMDE_FLOAT16_VALUE(  -358.00), SIMDE_FLOAT16_VALUE(   242.00), SIMDE_FLOAT16_VALUE(  -751.50), SIMDE_FLOAT16_VALUE(   483.25),
        SIMDE_FLOAT16_VALUE(  -873.00), SIMDE_FLOAT16_VALUE(   974.50), SIMDE_FLOAT16_VALUE(  -845.50), SIMDE_FLOAT16_VALUE(   801.00),
        SIMDE_FLOAT16_VALUE(  -563.50), SIMDE_FLOAT16_VALUE(    43.72), SIMDE_FLOAT16_VALUE(  -969.50), SIMDE_FLOAT16_VALUE(  -949.00) } },
    { { SIMDE_FLOAT16_VALUE(  -559.00), SIMDE_FLOAT16_VALUE(   773.50), SIMDE_FLOAT16_VALUE(  -985.50), SIMDE_FLOAT16_VALUE(  -562.50),
        SIMDE_FLOAT16_VALUE(  -622.50), SIMDE_FLOAT16_VALUE(   572.50), SIMDE_FLOAT16_VALUE(    69.19), SIMDE_FLOAT16_VALUE(   586.50),
        SIMDE_FLOAT16_VALUE(    12.58), SIMDE_FLOAT16_VALUE(   305.75), SIMDE_FLOAT16_VALUE(   317.75), SIMDE_FLOAT16_VALUE(   721.00),
        SIMDE_FLOAT16_VALUE(   828.50), SIMDE_FLOAT16_VALUE(  -243.00), SIMDE_FLOAT16_VALUE(   786.50), SIMDE_FLOAT16_VALUE(   828.00),
        SIMDE_FLOAT16_VALUE(   262.25), SIMDE_FLOAT16_VALUE(  -134.50), SIMDE_FLOAT16_VALUE(    77.88), SIMDE_FLOAT16_VALUE(   904.00),
        SIMDE_FLOAT16_VALUE(  -892.50), SIMDE_FLOAT16_VALUE(   326.00), SIMDE_FLOAT16_VALUE(   387.50), SIMDE_FLOAT16_VALUE(  -765.50),
        SIMDE_FLOAT16_VALUE(   300.50), SIMDE_FLOAT16_VALUE(   542.00), SIMDE_FLOAT16_VALUE(  -965.00), SIMDE_FLOAT16_VALUE(   737.00),
        SIMDE_FLOAT16_VALUE(  -414.00), SIMDE_FLOAT16_VALUE(  -934.50), SIMDE_FLOAT16_VALUE(   788.00), SIMDE_FLOAT16_VALUE(    27.16) },
      { SIMDE_FLOAT16_VALUE(  -559.00), SIMDE_FLOAT16_VALUE(   773.50), SIMDE_FLOAT16_VALUE(  -985.50), SIMDE_FLOAT16_VALUE(  -562.50),
        SIMDE_FLOAT16_VALUE(  -622.50), SIMDE_FLOAT16_VALUE(   572.50), SIMDE_FLOAT16_VALUE(    69.19), SIMDE_FLOAT16_VALUE(   586.50),
        SIMDE_FLOAT16_VALUE(    12.58), SIMDE_FLOAT16_VALUE(   305.75), SIMDE_FLOAT16_VALUE(   317.75), SIMDE_FLOAT16_VALUE(   721.00),
        SIMDE_FLOAT16_VALUE(   828.50), SIMDE_FLOAT16_VALUE(  -243.00), SIMDE_FLOAT16_VALUE(   786.50), SIMDE_FLOAT16_VALUE(   828.00),
        SIMDE_FLOAT16_VALUE(   262.25), SIMDE_FLOAT16_VALUE(  -134.50), SIMDE_FLOAT16_VALUE(    77.88), SIMDE_FLOAT16_VALUE(   904.00),
        SIMDE_FLOAT16_VALUE(  -892.50), SIMDE_FLOAT16_VALUE(   326.00), SIMDE_FLOAT16_VALUE(   387.50), SIMDE_FLOAT16_VALUE(  -765.50),
        SIMDE_FLOAT16_VALUE(   300.50), SIMDE_FLOAT16_VALUE(   542.00), SIMDE_FLOAT16_VALUE(  -965.00), SIMDE_FLOAT16_VALUE(   737.00),
        SIMDE_FLOAT16_VALUE(  -414.00), SIMDE_FLOAT16_VALUE(  -934.50), SIMDE_FLOAT16_VALUE(   788.00), SIMDE_FLOAT16_VALUE(    27.16) } },
    { { SIMDE_FLOAT16_VALUE(   839.00), SIMDE_FLOAT16_VALUE(   802.50), SIMDE_FLOAT16_VALUE(   464.50), SIMDE_FLOAT16_VALUE(  -783.50),
        SIMDE_FLOAT16_VALUE(   375.00), SIMDE_FLOAT16_VALUE(  -466.25), SIMDE_FLOAT16_VALUE(   803.00), SIMDE_FLOAT16_VALUE(  -612.50),
        SIMDE_FLOAT16_VALUE(   839.50), SIMDE_FLOAT16_VALUE(   120.81), SIMDE_FLOAT16_VALUE(  -891.00), SIMDE_FLOAT16_VALUE(   668.00),
        SIMDE_FLOAT16_VALUE(   878.00), SIMDE_FLOAT16_VALUE(   895.00), SIMDE_FLOAT16_VALUE(   495.75), SIMDE_FLOAT16_VALUE(   140.00),
        SIMDE_FLOAT16_VALUE(  -239.25), SIMDE_FLOAT16_VALUE(  -426.50), SIMDE_FLOAT16_VALUE(    44.31), SIMDE_FLOAT16_VALUE(  -131.75),
        SIMDE_FLOAT16_VALUE(   899.50), SIMDE_FLOAT16_VALUE(  -568.00), SIMDE_FLOAT16_VALUE(   102.56), SIMDE_FLOAT16_VALUE(   200.00),
        SIMDE_FLOAT16_VALUE(   974.00), SIMDE_FLOAT16_VALUE(   137.75), SIMDE_FLOAT16_VALUE(   -62.97), SIMDE_FLOAT16_VALUE(  -440.00),
        SIMDE_FLOAT16_VALUE(   203.38), SIMDE_FLOAT16_VALUE(  -275.00), SIMDE_FLOAT16_VALUE(   587.00), SIMDE_FLOAT16_VALUE(    42.59) },
      { SIMDE_FLOAT16_VALUE(   839.00), SIMDE_FLOAT16_VALUE(   802.50), SIMDE_FLOAT16_VALUE(   464.50), SIMDE_FLOAT16_VALUE(  -783.50),
        SIMDE_FLOAT16_VALUE(   375.00), SIMDE_FLOAT16_VALUE(  -466.25), SIMDE_FLOAT16_VALUE(   803.00), SIMDE_FLOAT16_VALUE(  -612.50),
        SIMDE_FLOAT16_VALUE(   839.50), SIMDE_FLOAT16_VALUE(   120.81), SIMDE_FLOAT16_VALUE(  -891.00), SIMDE_FLOAT16_VALUE(   668.00),
        SIMDE_FLOAT16_VALUE(   878.00), SIMDE_FLOAT16_VALUE(   895.00), SIMDE_FLOAT16_VALUE(   495.75), SIMDE_FLOAT16_VALUE(   140.00),
        SIMDE_FLOAT16_VALUE(  -239.25), SIMDE_FLOAT16_VALUE(  -426.50), SIMDE_FLOAT16_VALUE(    44.31), SIMDE_FLOAT16_VALUE(  -131.75),
        SIMDE_FLOAT16_VALUE(   899.50), SIMDE_FLOAT16_VALUE(  -568.00), SIMDE_FLOAT16_VALUE(   102.56), SIMDE_FLOAT16_VALUE(   200.00),
        SIMDE_FLOAT16_VALUE(   974.00), SIMDE_FLOAT16_VALUE(   137.75), SIMDE_FLOAT16_VALUE(   -62.97), SIMDE_FLOAT16_VALUE(  -440.00),
        SIMDE_FLOAT16_VALUE(   203.38), SIMDE_FLOAT16_VALUE(  -275.00), SIMDE_FLOAT16_VALUE(   587.00), SIMDE_FLOAT16_VALUE(    42.59) } },
    { { SIMDE_FLOAT16_VALUE(  -472.50), SIMDE_FLOAT16_VALUE(    51.56), SIMDE_FLOAT16_VALUE(   259.00), SIMDE_FLOAT16_VALUE(   902.50),
        SIMDE_FLOAT16_VALUE(   585.00), SIMDE_FLOAT16_VALUE(    62.31), SIMDE_FLOAT16_VALUE(  -710.00), SIMDE_FLOAT16_VALUE(   424.75),
        SIMDE_FLOAT16_VALUE(  -817.00), SIMDE_FLOAT16_VALUE(  -601.00), SIMDE_FLOAT16_VALUE(    92.44), SIMDE_FLOAT16_VALUE(  -939.00),
        SIMDE_FLOAT16_VALUE(  -706.00), SIMDE_FLOAT16_VALUE(  -411.75), SIMDE_FLOAT16_VALUE(   200.88), SIMDE_FLOAT16_VALUE(    54.81),
        SIMDE_FLOAT16_VALUE(   161.75), SIMDE_FLOAT16_VALUE(  -755.00), SIMDE_FLOAT16_VALUE(   923.00), SIMDE_FLOAT16_VALUE(    61.38),
        SIMDE_FLOAT16_VALUE(  -323.00), SIMDE_FLOAT16_VALUE(    25.62), SIMDE_FLOAT16_VALUE(  -738.50), SIMDE_FLOAT16_VALUE(  -349.00),
        SIMDE_FLOAT16_VALUE(  -836.50), SIMDE_FLOAT16_VALUE(   198.50), SIMDE_FLOAT16_VALUE(   211.00), SIMDE_FLOAT16_VALUE(   366.75),
        SIMDE_FLOAT16_VALUE(   923.50), SIMDE_FLOAT16_VALUE(  -201.88), SIMDE_FLOAT16_VALUE(  -590.50), SIMDE_FLOAT16_VALUE(  -549.00) },
      { SIMDE_FLOAT16_VALUE(  -472.50), SIMDE_FLOAT16_VALUE(    51.56), SIMDE_FLOAT16_VALUE(   259.00), SIMDE_FLOAT16_VALUE(   902.50),
        SIMDE_FLOAT16_VALUE(   585.00), SIMDE_FLOAT16_VALUE(    62.31), SIMDE_FLOAT16_VALUE(  -710.00), SIMDE_FLOAT16_VALUE(   424.75),
        SIMDE_FLOAT16_VALUE(  -817.00), SIMDE_FLOAT16_VALUE(  -601.00), SIMDE_FLOAT16_VALUE(    92.44), SIMDE_FLOAT16_VALUE(  -939.00),
        SIMDE_FLOAT16_VALUE(  -706.00), SIMDE_FLOAT16_VALUE(  -411.75), SIMDE_FLOAT16_VALUE(   200.88), SIMDE_FLOAT16_VALUE(    54.81),
        SIMDE_FLOAT16_VALUE(   161.75), SIMDE_FLOAT16_VALUE(  -755.00), SIMDE_FLOAT16_VALUE(   923.00), SIMDE_FLOAT16_VALUE(    61.38),
        SIMDE_FLOAT16_VALUE(  -323.00), SIMDE_FLOAT16_VALUE(    25.62), SIMDE_FLOAT16_VALUE(  -738.50), SIMDE_FLOAT16_VALUE(  -349.00),
        SIMDE_FLOAT16_VALUE(  -836.50), SIMDE_FLOAT16_VALUE(   198.50), SIMDE_FLOAT16_VALUE(   211.00), SIMDE_FLOAT16_VALUE(   366.75),
        SIMDE_FLOAT16_VALUE(   923.50), SIMDE_FLOAT16_VALUE(  -201.88), SIMDE_FLOAT16_VALUE(  -590.50), SIMDE_FLOAT16_VALUE(  -549.00) } },
    { { SIMDE_FLOAT16_VALUE(   849.50), SIMDE_FLOAT16_VALUE(   668.50), SIMDE_FLOAT16_VALUE(  -646.50), SIMDE_FLOAT16_VALUE(   435.00),
        SIMDE_FLOAT16_VALUE(  -269.25), SIMDE_FLOAT16_VALUE(  -356.25), SIMDE_FLOAT16_VALUE(  -140.38), SIMDE_FLOAT16_VALUE(   -86.06),
        SIMDE_FLOAT16_VALUE(    42.69), SIMDE_FLOAT16_VALUE(   952.00), SIMDE_FLOAT16_VALUE(   -25.16), SIMDE_FLOAT16_VALUE(   336.75),
        SIMDE_FLOAT16_VALUE(  -459.75), SIMDE_FLOAT16_VALUE(  -824.00), SIMDE_FLOAT16_VALUE(  -608.50), SIMDE_FLOAT16_VALUE(   702.00),
        SIMDE_FLOAT16_VALUE(  -579.00), SIMDE_FLOAT16_VALUE(  -685.50), SIMDE_FLOAT16_VALUE(  -236.75), SIMDE_FLOAT16_VALUE(    98.06),
        SIMDE_FLOAT16_VALUE(   340.25), SIMDE_FLOAT16_VALUE(    24.69), SIMDE_FLOAT16_VALUE(   749.00), SIMDE_FLOAT16_VALUE(   503.75),
        SIMDE_FLOAT16_VALUE(  -777.00), SIMDE_FLOAT16_VALUE(   -39.78), SIMDE_FLOAT16_VALUE(  -129.50), SIMDE_FLOAT16_VALUE(  -853.00),
        SIMDE_FLOAT16_VALUE(   758.50), SIMDE_FLOAT16_VALUE(   280.00), SIMDE_FLOAT16_VALUE(  -402.25), SIMDE_FLOAT16_VALUE(   608.00) },
      { SIMDE_FLOAT16_VALUE(   849.50), SIMDE_FLOAT16_VALUE(   668.50), SIMDE_FLOAT16_VALUE(  -646.50), SIMDE_FLOAT16_VALUE(   435.00),
        SIMDE_FLOAT16_VALUE(  -269.25), SIMDE_FLOAT16_VALUE(  -356.25), SIMDE_FLOAT16_VALUE(  -140.38), SIMDE_FLOAT16_VALUE(   -86.06),
        SIMDE_FLOAT16_VALUE(    42.69), SIMDE_FLOAT16_VALUE(   952.00), SIMDE_FLOAT16_VALUE(   -25.16), SIMDE_FLOAT16_VALUE(   336.75),
        SIMDE_FLOAT16_VALUE(  -459.75), SIMDE_FLOAT16_VALUE(  -824.00), SIMDE_FLOAT16_VALUE(  -608.50), SIMDE_FLOAT16_VALUE(   702.00),
        SIMDE_FLOAT16_VALUE(  -579.00), SIMDE_FLOAT16_VALUE(  -685.50), SIMDE_FLOAT16_VALUE(  -236.75), SIMDE_FLOAT16_VALUE(    98.06),
        SIMDE_FLOAT16_VALUE(   340.25), SIMDE_FLOAT16_VALUE(    24.69), SIMDE_FLOAT16_VALUE(   749.00), SIMDE_FLOAT16_VALUE(   503.75),
        SIMDE_FLOAT16_VALUE(  -777.00), SIMDE_FLOAT16_VALUE(   -39.78), SIMDE_FLOAT16_VALUE(  -129.50), SIMDE_FLOAT16_VALUE(  -853.00),
        SIMDE_FLOAT16_VALUE(   758.50), SIMDE_FLOAT16_VALUE(   280.00), SIMDE_FLOAT16_VALUE(  -402.25), SIMDE_FLOAT16_VALUE(   608.00) } },
    { { SIMDE_FLOAT16_VALUE(   -51.50), SIMDE_FLOAT16_VALUE(   -48.50), SIMDE_FLOAT16_VALUE(    42.84), SIMDE_FLOAT16_VALUE(   679.50),
        SIMDE_FLOAT16_VALUE(   595.50), SIMDE_FLOAT16_VALUE(   902.50), SIMDE_FLOAT16_VALUE(  -406.75), SIMDE_FLOAT16_VALUE(  -362.00),
        SIMDE_FLOAT16_VALUE(   854.50), SIMDE_FLOAT16_VALUE(   568.00), SIMDE_FLOAT16_VALUE(   975.00), SIMDE_FLOAT16_VALUE(  -605.50),
        SIMDE_FLOAT16_VALUE(   744.00), SIMDE_FLOAT16_VALUE(  -633.50), SIMDE_FLOAT16_VALUE(  -903.50), SIMDE_FLOAT16_VALUE(  -835.00),
        SIMDE_FLOAT16_VALUE(  -319.00), SIMDE_FLOAT16_VALUE(  -140.25), SIMDE_FLOAT16_VALUE(   263.00), SIMDE_FLOAT16_VALUE(  -979.00),
        SIMDE_FLOAT16_VALUE(   884.50), SIMDE_FLOAT16_VALUE(    12.23), SIMDE_FLOAT16_VALUE(   525.00), SIMDE_FLOAT16_VALUE(  -892.50),
        SIMDE_FLOAT16_VALUE(   972.50), SIMDE_FLOAT16_VALUE(  -604.50), SIMDE_FLOAT16_VALUE(  -745.50), SIMDE_FLOAT16_VALUE(   731.00),
        SIMDE_FLOAT16_VALUE(   675.50), SIMDE_FLOAT16_VALUE(  -147.75), SIMDE_FLOAT16_VALUE(   338.75), SIMDE_FLOAT16_VALUE(  -376.00) },
      { SIMDE_FLOAT16_VALUE(   -51.50), SIMDE_FLOAT16_VALUE(   -48.50), SIMDE_FLOAT16_VALUE(    42.84), SIMDE_FLOAT16_VALUE(   679.50),
        SIMDE_FLOAT16_VALUE(   595.50), SIMDE_FLOAT16_VALUE(   902.50), SIMDE_FLOAT16_VALUE(  -406.75), SIMDE_FLOAT16_VALUE(  -362.00),
        SIMDE_FLOAT16_VALUE(   854.50), SIMDE_FLOAT16_VALUE(   568.00), SIMDE_FLOAT16_VALUE(   975.00), SIMDE_FLOAT16_VALUE(  -605.50),
        SIMDE_FLOAT16_VALUE(   744.00), SIMDE_FLOAT16_VALUE(  -633.50), SIMDE_FLOAT16_VALUE(  -903.50), SIMDE_FLOAT16_VALUE(  -835.00),
        SIMDE_FLOAT16_VALUE(  -319.00), SIMDE_FLOAT16_VALUE(  -140.25), SIMDE_FLOAT16_VALUE(   263.00), SIMDE_FLOAT16_VALUE(  -979.00),
        SIMDE_FLOAT16_VALUE(   884.50), SIMDE_FLOAT16_VALUE(    12.23), SIMDE_FLOAT16_VALUE(   525.00), SIMDE_FLOAT16_VALUE(  -892.50),
        SIMDE_FLOAT16_VALUE(   972.50), SIMDE_FLOAT16_VALUE(  -604.50), SIMDE_FLOAT16_VALUE(  -745.50), SIMDE_FLOAT16_VALUE(   731.00),
        SIMDE_FLOAT16_VALUE(   675.50), SIMDE_FLOAT16_VALUE(  -147.75), SIMDE_FLOAT16_VALUE(   338.75), SIMDE_FLOAT16_VALUE(  -376.00) } },
    { { SIMDE_FLOAT16_VALUE(   803.50), SIMDE_FLOAT16_VALUE(  -618.50), SIMDE_FLOAT16_VALUE(  -697.00), SIMDE_FLOAT16_VALUE(   399.00),
        SIMDE_FLOAT16_VALUE(  -716.00), SIMDE_FLOAT16_VALUE(  -103.50), SIMDE_FLOAT16_VALUE(  -963.00), SIMDE_FLOAT16_VALUE(  -861.50),
        SIMDE_FLOAT16_VALUE(  -535.50), SIMDE_FLOAT16_VALUE(  -988.50), SIMDE_FLOAT16_VALUE(  -467.00), SIMDE_FLOAT16_VALUE(  -791.50),
        SIMDE_FLOAT16_VALUE(  -622.00), SIMDE_FLOAT16_VALUE(  -370.50), SIMDE_FLOAT16_VALUE(  -626.50), SIMDE_FLOAT16_VALUE(    59.03),
        SIMDE_FLOAT16_VALUE(   489.25), SIMDE_FLOAT16_VALUE(   636.50), SIMDE_FLOAT16_VALUE(    80.25), SIMDE_FLOAT16_VALUE(   373.75),
        SIMDE_FLOAT16_VALUE(  -351.25), SIMDE_FLOAT16_VALUE(  -394.75), SIMDE_FLOAT16_VALUE(   481.25), SIMDE_FLOAT16_VALUE(  -378.75),
        SIMDE_FLOAT16_VALUE(     0.61), SIMDE_FLOAT16_VALUE(   735.50), SIMDE_FLOAT16_VALUE(  -648.00), SIMDE_FLOAT16_VALUE(  -324.00),
        SIMDE_FLOAT16_VALUE(  -412.25), SIMDE_FLOAT16_VALUE(   690.50), SIMDE_FLOAT16_VALUE(   299.75), SIMDE_FLOAT16_VALUE(  -608.50) },
      { SIMDE_FLOAT16_VALUE(   803.50), SIMDE_FLOAT16_VALUE(  -618.50), SIMDE_FLOAT16_VALUE(  -697.00), SIMDE_FLOAT16_VALUE(   399.00),
        SIMDE_FLOAT16_VALUE(  -716.00), SIMDE_FLOAT16_VALUE(  -103.50), SIMDE_FLOAT16_VALUE(  -963.00), SIMDE_FLOAT16_VALUE(  -861.50),
        SIMDE_FLOAT16_VALUE(  -535.50), SIMDE_FLOAT16_VALUE(  -988.50), SIMDE_FLOAT16_VALUE(  -467.00), SIMDE_FLOAT16_VALUE(  -791.50),
        SIMDE_FLOAT16_VALUE(  -622.00), SIMDE_FLOAT16_VALUE(  -370.50), SIMDE_FLOAT16_VALUE(  -626.50), SIMDE_FLOAT16_VALUE(    59.03),
        SIMDE_FLOAT16_VALUE(   489.25), SIMDE_FLOAT16_VALUE(   636.50), SIMDE_FLOAT16_VALUE(    80.25), SIMDE_FLOAT16_VALUE(   373.75),
        SIMDE_FLOAT16_VALUE(  -351.25), SIMDE_FLOAT16_VALUE(  -394.75), SIMDE_FLOAT16_VALUE(   481.25), SIMDE_FLOAT16_VALUE(  -378.75),
        SIMDE_FLOAT16_VALUE(     0.61), SIMDE_FLOAT16_VALUE(   735.50), SIMDE_FLOAT16_VALUE(  -648.00), SIMDE_FLOAT16_VALUE(  -324.00),
        SIMDE_FLOAT16_VALUE(  -412.25), SIMDE_FLOAT16_VALUE(   690.50), SIMDE_FLOAT16_VALUE(   299.75), SIMDE_FLOAT16_VALUE(  -608.50) } },
    { { SIMDE_FLOAT16_VALUE(  -927.50), SIMDE_FLOAT16_VALUE(   603.00), SIMDE_FLOAT16_VALUE(   790.50), SIMDE_FLOAT16_VALUE(  -644.00),
        SIMDE_FLOAT16_VALUE(  -500.50), SIMDE_FLOAT16_VALUE(   827.50), SIMDE_FLOAT16_VALUE(  -505.25), SIMDE_FLOAT16_VALUE(   -35.69),
        SIMDE_FLOAT16_VALUE(   839.00), SIMDE_FLOAT16_VALUE(    27.69), SIMDE_FLOAT16_VALUE(   172.88), SIMDE_FLOAT16_VALUE(  -783.00),
        SIMDE_FLOAT16_VALUE(   657.00), SIMDE_FLOAT16_VALUE(   546.50), SIMDE_FLOAT16_VALUE(   276.25), SIMDE_FLOAT16_VALUE(   146.50),
        SIMDE_FLOAT16_VALUE(   183.00), SIMDE_FLOAT16_VALUE(  -643.50), SIMDE_FLOAT16_VALUE(  -479.75), SIMDE_FLOAT16_VALUE(   832.00),
        SIMDE_FLOAT16_VALUE(   -38.28), SIMDE_FLOAT16_VALUE(  -998.50), SIMDE_FLOAT16_VALUE(  -547.00), SIMDE_FLOAT16_VALUE(   962.50),
        SIMDE_FLOAT16_VALUE(   737.00), SIMDE_FLOAT16_VALUE(  -194.88), SIMDE_FLOAT16_VALUE(  -361.75), SIMDE_FLOAT16_VALUE(  -675.00),
        SIMDE_FLOAT16_VALUE(  -504.00), SIMDE_FLOAT16_VALUE(   938.00), SIMDE_FLOAT16_VALUE(  -283.50), SIMDE_FLOAT16_VALUE(  -431.75) },
      { SIMDE_FLOAT16_VALUE(  -927.50), SIMDE_FLOAT16_VALUE(   603.00), SIMDE_FLOAT16_VALUE(   790.50), SIMDE_FLOAT16_VALUE(  -644.00),
        SIMDE_FLOAT16_VALUE(  -500.50), SIMDE_FLOAT16_VALUE(   827.50), SIMDE_FLOAT16_VALUE(  -505.25), SIMDE_FLOAT16_VALUE(   -35.69),
        SIMDE_FLOAT16_VALUE(   839.00), SIMDE_FLOAT16_VALUE(    27.69), SIMDE_FLOAT16_VALUE(   172.88), SIMDE_FLOAT16_VALUE(  -783.00),
        SIMDE_FLOAT16_VALUE(   657.00), SIMDE_FLOAT16_VALUE(   546.50), SIMDE_FLOAT16_VALUE(   276.25), SIMDE_FLOAT16_VALUE(   146.50),
        SIMDE_FLOAT16_VALUE(   183.00), SIMDE_FLOAT16_VALUE(  -643.50), SIMDE_FLOAT16_VALUE(  -479.75), SIMDE_FLOAT16_VALUE(   832.00),
        SIMDE_FLOAT16_VALUE(   -38.28), SIMDE_FLOAT16_VALUE(  -998.50), SIMDE_FLOAT16_VALUE(  -547.00), SIMDE_FLOAT16_VALUE(   962.50),
        SIMDE_FLOAT16_VALUE(   737.00), SIMDE_FLOAT16_VALUE(  -194.88), SIMDE_FLOAT16_VALUE(  -361.75), SIMDE_FLOAT16_VALUE(  -675.00),
        SIMDE_FLOAT16_VALUE(  -504.00), SIMDE_FLOAT16_VALUE(   938.00), SIMDE_FLOAT16_VALUE(  -283.50), SIMDE_FLOAT16_VALUE(  -431.75) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512h a = simde_mm512_loadu_ph(test_vec[i].a);
    simde_float16 r[sizeof(simde__m512) / sizeof(simde_float16)] = { SIMDE_FLOAT16_VALUE(0.00) };
    simde_mm512_storeu_ph(r, a);
    simde_assert_equal_vf16(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512h a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-1000.0), SIMDE_FLOAT16_VALUE(1000.0));
    simde_float16 r[sizeof(simde__m512) / sizeof(simde_float16)] = {0};
    simde_mm512_storeu_ph(r, a);

    simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vf16(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
#endif

static int
test_simde_mm512_mask_storeu_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const simde_float32 a[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT32_C(     48935),
      { SIMDE_FLOAT32_C(   777.60), SIMDE_FLOAT32_C(  -115.88), SIMDE_FLOAT32_C(  -842.42), SIMDE_FLOAT32_C(  -642.89),
        SIMDE_FLOAT32_C(   108.91), SIMDE_FLOAT32_C(  -293.17), SIMDE_FLOAT32_C(  -456.16), SIMDE_FLOAT32_C(   -48.43),
        SIMDE_FLOAT32_C(  -968.61), SIMDE_FLOAT32_C(  -271.36), SIMDE_FLOAT32_C(  -229.49), SIMDE_FLOAT32_C(  -829.17),
        SIMDE_FLOAT32_C(  -862.03), SIMDE_FLOAT32_C(   363.59), SIMDE_FLOAT32_C(   573.10), SIMDE_FLOAT32_C(   408.01) },
      { SIMDE_FLOAT32_C(   777.60), SIMDE_FLOAT32_C(  -115.88), SIMDE_FLOAT32_C(  -842.42), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -293.17), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -968.61), SIMDE_FLOAT32_C(  -271.36), SIMDE_FLOAT32_C(  -229.49), SIMDE_FLOAT32_C(  -829.17),
        SIMDE_FLOAT32_C(  -862.03), SIMDE_FLOAT32_C(   363.59), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   408.01) } },
    { UINT32_C(     22792),
      { SIMDE_FLOAT32_C(     4.70), SIMDE_FLOAT32_C(     2.22), SIMDE_FLOAT32_C(  -581.97), SIMDE_FLOAT32_C(   257.59),
        SIMDE_FLOAT32_C(    31.28), SIMDE_FLOAT32_C(   977.18), SIMDE_FLOAT32_C(   872.23), SIMDE_FLOAT32_C(  -927.45),
        SIMDE_FLOAT32_C(   747.63), SIMDE_FLOAT32_C(   196.59), SIMDE_FLOAT32_C(   362.40), SIMDE_FLOAT32_C(  -705.03),
        SIMDE_FLOAT32_C(   122.25), SIMDE_FLOAT32_C(   140.00), SIMDE_FLOAT32_C(   179.09), SIMDE_FLOAT32_C(   279.83) },
      {         SIMDE_MATH_FLT_MAX, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   257.59),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   747.63), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -705.03),
        SIMDE_FLOAT32_C(   122.25), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   179.09), SIMDE_FLOAT32_C(     0.00) } },
    { UINT32_C(       947),
      { SIMDE_FLOAT32_C(   986.66), SIMDE_FLOAT32_C(  -959.05), SIMDE_FLOAT32_C(   239.58), SIMDE_FLOAT32_C(  -981.95),
        SIMDE_FLOAT32_C(  -230.41), SIMDE_FLOAT32_C(  -989.91), SIMDE_FLOAT32_C(  -811.12), SIMDE_FLOAT32_C(   -92.44),
        SIMDE_FLOAT32_C(   373.68), SIMDE_FLOAT32_C(   761.98), SIMDE_FLOAT32_C(  -684.43), SIMDE_FLOAT32_C(  -667.53),
        SIMDE_FLOAT32_C(  -990.31), SIMDE_FLOAT32_C(   320.27), SIMDE_FLOAT32_C(   334.69), SIMDE_FLOAT32_C(  -572.28) },
      { SIMDE_FLOAT32_C(   986.66), SIMDE_FLOAT32_C(  -959.05), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -230.41), SIMDE_FLOAT32_C(  -989.91), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -92.44),
        SIMDE_FLOAT32_C(   373.68), SIMDE_FLOAT32_C(   761.98), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT32_C(     54541),
      { SIMDE_FLOAT32_C(  -595.10), SIMDE_FLOAT32_C(  -549.92), SIMDE_FLOAT32_C(  -561.48), SIMDE_FLOAT32_C(  -847.47),
        SIMDE_FLOAT32_C(   646.67), SIMDE_FLOAT32_C(   800.92), SIMDE_FLOAT32_C(  -552.49), SIMDE_FLOAT32_C(  -231.08),
        SIMDE_FLOAT32_C(   -59.08), SIMDE_FLOAT32_C(   626.60), SIMDE_FLOAT32_C(  -951.25), SIMDE_FLOAT32_C(  -561.97),
        SIMDE_FLOAT32_C(   914.61), SIMDE_FLOAT32_C(  -964.59), SIMDE_FLOAT32_C(  -521.02), SIMDE_FLOAT32_C(   154.19) },
      { SIMDE_FLOAT32_C(  -595.10), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -561.48), SIMDE_FLOAT32_C(  -847.47),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   -59.08), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -951.25), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   914.61), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -521.02), SIMDE_FLOAT32_C(   154.19) } },
    { UINT32_C(     42882),
      { SIMDE_FLOAT32_C(   164.28), SIMDE_FLOAT32_C(  -757.66), SIMDE_FLOAT32_C(  -843.87), SIMDE_FLOAT32_C(  -462.04),
        SIMDE_FLOAT32_C(  -995.67), SIMDE_FLOAT32_C(  -528.30), SIMDE_FLOAT32_C(  -129.57), SIMDE_FLOAT32_C(  -985.98),
        SIMDE_FLOAT32_C(   791.96), SIMDE_FLOAT32_C(  -794.88), SIMDE_FLOAT32_C(  -558.26), SIMDE_FLOAT32_C(  -630.18),
        SIMDE_FLOAT32_C(  -428.91), SIMDE_FLOAT32_C(  -153.36), SIMDE_FLOAT32_C(  -180.10), SIMDE_FLOAT32_C(     9.62) },
      {         SIMDE_MATH_FLT_MAX, SIMDE_FLOAT32_C(  -757.66), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -985.98),
        SIMDE_FLOAT32_C(   791.96), SIMDE_FLOAT32_C(  -794.88), SIMDE_FLOAT32_C(  -558.26), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -153.36), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     9.62) } },
    { UINT32_C(     62268),
      { SIMDE_FLOAT32_C(  -189.46), SIMDE_FLOAT32_C(   446.69), SIMDE_FLOAT32_C(   235.49), SIMDE_FLOAT32_C(   751.46),
        SIMDE_FLOAT32_C(    73.29), SIMDE_FLOAT32_C(   284.24), SIMDE_FLOAT32_C(  -810.51), SIMDE_FLOAT32_C(   -12.10),
        SIMDE_FLOAT32_C(   319.65), SIMDE_FLOAT32_C(  -331.53), SIMDE_FLOAT32_C(  -857.91), SIMDE_FLOAT32_C(   373.11),
        SIMDE_FLOAT32_C(   917.04), SIMDE_FLOAT32_C(   306.37), SIMDE_FLOAT32_C(   615.45), SIMDE_FLOAT32_C(  -926.83) },
      {         SIMDE_MATH_FLT_MAX, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   235.49), SIMDE_FLOAT32_C(   751.46),
        SIMDE_FLOAT32_C(    73.29), SIMDE_FLOAT32_C(   284.24), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   319.65), SIMDE_FLOAT32_C(  -331.53), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   917.04), SIMDE_FLOAT32_C(   306.37), SIMDE_FLOAT32_C(   615.45), SIMDE_FLOAT32_C(  -926.83) } },
    { UINT32_C(     37103),
      { SIMDE_FLOAT32_C(  -455.13), SIMDE_FLOAT32_C(  -285.25), SIMDE_FLOAT32_C(   633.80), SIMDE_FLOAT32_C(  -663.17),
        SIMDE_FLOAT32_C(   -80.13), SIMDE_FLOAT32_C(  -924.46), SIMDE_FLOAT32_C(  -293.35), SIMDE_FLOAT32_C(   490.96),
        SIMDE_FLOAT32_C(   -77.82), SIMDE_FLOAT32_C(   526.55), SIMDE_FLOAT32_C(  -499.42), SIMDE_FLOAT32_C(   921.36),
        SIMDE_FLOAT32_C(   993.12), SIMDE_FLOAT32_C(   311.12), SIMDE_FLOAT32_C(   368.04), SIMDE_FLOAT32_C(   228.60) },
      { SIMDE_FLOAT32_C(  -455.13), SIMDE_FLOAT32_C(  -285.25), SIMDE_FLOAT32_C(   633.80), SIMDE_FLOAT32_C(  -663.17),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -924.46), SIMDE_FLOAT32_C(  -293.35), SIMDE_FLOAT32_C(   490.96),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   993.12), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   228.60) } },
    { UINT32_C(     10645),
      { SIMDE_FLOAT32_C(  -487.16), SIMDE_FLOAT32_C(   252.07), SIMDE_FLOAT32_C(   429.23), SIMDE_FLOAT32_C(   832.49),
        SIMDE_FLOAT32_C(   920.55), SIMDE_FLOAT32_C(   571.31), SIMDE_FLOAT32_C(   205.60), SIMDE_FLOAT32_C(   837.59),
        SIMDE_FLOAT32_C(  -122.32), SIMDE_FLOAT32_C(  -178.95), SIMDE_FLOAT32_C(   910.76), SIMDE_FLOAT32_C(  -278.00),
        SIMDE_FLOAT32_C(  -559.16), SIMDE_FLOAT32_C(  -544.38), SIMDE_FLOAT32_C(   436.75), SIMDE_FLOAT32_C(  -925.36) },
      { SIMDE_FLOAT32_C(  -487.16), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   429.23), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   920.55), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   837.59),
        SIMDE_FLOAT32_C(  -122.32), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -278.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -544.38), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde_float32 r[sizeof(simde__m512) / sizeof(simde_float32)] = {SIMDE_MATH_FLT_MAX};
    simde_mm512_mask_storeu_ps(r, test_vec[i].k, a);
    simde_assert_equal_vf32(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_float32 r[sizeof(simde__m512) / sizeof(simde_float32)] = {SIMDE_MATH_FLT_MAX};
    simde_mm512_mask_storeu_ps(r, k, a);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vf32(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_storeu_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { UINT8_C(190),
      { SIMDE_FLOAT64_C(  -857.66), SIMDE_FLOAT64_C(   830.90), SIMDE_FLOAT64_C(  -270.82), SIMDE_FLOAT64_C(   555.71),
        SIMDE_FLOAT64_C(  -157.75), SIMDE_FLOAT64_C(  -794.41), SIMDE_FLOAT64_C(  -111.43), SIMDE_FLOAT64_C(  -305.53) },
      {         SIMDE_MATH_DBL_MAX, SIMDE_FLOAT64_C(   830.90), SIMDE_FLOAT64_C(  -270.82), SIMDE_FLOAT64_C(   555.71),
        SIMDE_FLOAT64_C(  -157.75), SIMDE_FLOAT64_C(  -794.41), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -305.53) } },
    { UINT8_C( 59),
      { SIMDE_FLOAT64_C(   412.87), SIMDE_FLOAT64_C(  -847.46), SIMDE_FLOAT64_C(  -926.91), SIMDE_FLOAT64_C(   423.66),
        SIMDE_FLOAT64_C(  -190.61), SIMDE_FLOAT64_C(  -258.38), SIMDE_FLOAT64_C(  -803.66), SIMDE_FLOAT64_C(  -896.56) },
      { SIMDE_FLOAT64_C(   412.87), SIMDE_FLOAT64_C(  -847.46), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   423.66),
        SIMDE_FLOAT64_C(  -190.61), SIMDE_FLOAT64_C(  -258.38), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(146),
      { SIMDE_FLOAT64_C(   255.19), SIMDE_FLOAT64_C(  -488.31), SIMDE_FLOAT64_C(   394.02), SIMDE_FLOAT64_C(   585.62),
        SIMDE_FLOAT64_C(   576.39), SIMDE_FLOAT64_C(   507.86), SIMDE_FLOAT64_C(   859.87), SIMDE_FLOAT64_C(   755.59) },
      {         SIMDE_MATH_DBL_MAX, SIMDE_FLOAT64_C(  -488.31), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   576.39), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   755.59) } },
    { UINT8_C(  6),
      { SIMDE_FLOAT64_C(  -392.46), SIMDE_FLOAT64_C(   683.12), SIMDE_FLOAT64_C(   872.22), SIMDE_FLOAT64_C(   134.00),
        SIMDE_FLOAT64_C(   825.47), SIMDE_FLOAT64_C(   703.11), SIMDE_FLOAT64_C(   863.18), SIMDE_FLOAT64_C(   381.17) },
      {         SIMDE_MATH_DBL_MAX, SIMDE_FLOAT64_C(   683.12), SIMDE_FLOAT64_C(   872.22), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 55),
      { SIMDE_FLOAT64_C(  -931.22), SIMDE_FLOAT64_C(  -730.26), SIMDE_FLOAT64_C(   239.84), SIMDE_FLOAT64_C(   541.87),
        SIMDE_FLOAT64_C(   682.61), SIMDE_FLOAT64_C(   392.38), SIMDE_FLOAT64_C(   614.96), SIMDE_FLOAT64_C(   106.27) },
      { SIMDE_FLOAT64_C(  -931.22), SIMDE_FLOAT64_C(  -730.26), SIMDE_FLOAT64_C(   239.84), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   682.61), SIMDE_FLOAT64_C(   392.38), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(253),
      { SIMDE_FLOAT64_C(  -643.42), SIMDE_FLOAT64_C(   302.61), SIMDE_FLOAT64_C(  -694.79), SIMDE_FLOAT64_C(   -37.76),
        SIMDE_FLOAT64_C(  -442.20), SIMDE_FLOAT64_C(  -183.09), SIMDE_FLOAT64_C(  -643.73), SIMDE_FLOAT64_C(  -856.58) },
      { SIMDE_FLOAT64_C(  -643.42), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -694.79), SIMDE_FLOAT64_C(   -37.76),
        SIMDE_FLOAT64_C(  -442.20), SIMDE_FLOAT64_C(  -183.09), SIMDE_FLOAT64_C(  -643.73), SIMDE_FLOAT64_C(  -856.58) } },
    { UINT8_C(186),
      { SIMDE_FLOAT64_C(   864.13), SIMDE_FLOAT64_C(  -996.71), SIMDE_FLOAT64_C(  -851.11), SIMDE_FLOAT64_C(   817.67),
        SIMDE_FLOAT64_C(  -389.16), SIMDE_FLOAT64_C(   832.01), SIMDE_FLOAT64_C(   689.89), SIMDE_FLOAT64_C(   744.84) },
      {         SIMDE_MATH_DBL_MAX, SIMDE_FLOAT64_C(  -996.71), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   817.67),
        SIMDE_FLOAT64_C(  -389.16), SIMDE_FLOAT64_C(   832.01), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   744.84) } },
    { UINT8_C(157),
      { SIMDE_FLOAT64_C(   393.00), SIMDE_FLOAT64_C(   608.02), SIMDE_FLOAT64_C(    38.65), SIMDE_FLOAT64_C(   938.36),
        SIMDE_FLOAT64_C(   676.80), SIMDE_FLOAT64_C(   308.39), SIMDE_FLOAT64_C(   178.20), SIMDE_FLOAT64_C(   218.67) },
      { SIMDE_FLOAT64_C(   393.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    38.65), SIMDE_FLOAT64_C(   938.36),
        SIMDE_FLOAT64_C(   676.80), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   218.67) } },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde_float64 r[sizeof(simde__m512d) / sizeof(simde_float64)] = {SIMDE_MATH_DBL_MAX};
    simde_mm512_mask_storeu_pd(r, test_vec[i].k, a);
    simde_assert_equal_vf64(sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_float64 r[sizeof(simde__m512) / sizeof(simde_float64)] = {SIMDE_MATH_DBL_MAX};
    simde_mm512_mask_storeu_pd(r, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_vf64(2, sizeof(r) / sizeof(r[0]), r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storeu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storeu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storeu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_storeu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_storeu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_storeu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_storeu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_storeu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_storeu_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_storeu_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_storeu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_storeu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_storeu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_storeu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_storeu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_storeu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_storeu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_storeu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_storeu_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_storeu_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_storeu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_storeu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_storeu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_storeu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_storeu_ps)
  #if defined(SIMDE_FLOAT16_IS_SCALAR)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm_storeu_ph)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm256_storeu_ph)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_storeu_ph)
  #endif
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_storeu_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_storeu_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
