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
 *   2023      Michael R. Crusoe <crusoe@debian.org>
 */

#define SIMDE_TEST_X86_AVX512_INSN gather

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/gather.h>

static simde_float32 f32_buffer[2048];

static int
test_simde_mm512_i32gather_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t vindex[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { {  INT32_C(          91),  INT32_C(           6),  INT32_C(         243),  INT32_C(         110),  INT32_C(         160),  INT32_C(           8),  INT32_C(          28),  INT32_C(         103),
         INT32_C(         208),  INT32_C(         170),  INT32_C(         227),  INT32_C(         152),  INT32_C(          69),  INT32_C(         234),  INT32_C(         211),  INT32_C(         131) },
      { SIMDE_FLOAT32_C(   182.00), SIMDE_FLOAT32_C(    12.00), SIMDE_FLOAT32_C(   486.00), SIMDE_FLOAT32_C(   220.00),
        SIMDE_FLOAT32_C(   320.00), SIMDE_FLOAT32_C(    16.00), SIMDE_FLOAT32_C(    56.00), SIMDE_FLOAT32_C(   206.00),
        SIMDE_FLOAT32_C(   416.00), SIMDE_FLOAT32_C(   340.00), SIMDE_FLOAT32_C(   454.00), SIMDE_FLOAT32_C(   304.00),
        SIMDE_FLOAT32_C(   138.00), SIMDE_FLOAT32_C(   468.00), SIMDE_FLOAT32_C(   422.00), SIMDE_FLOAT32_C(   262.00) } },
    { {  INT32_C(         180),  INT32_C(         211),  INT32_C(         170),  INT32_C(         243),  INT32_C(         162),  INT32_C(         194),  INT32_C(          27),  INT32_C(         150),
         INT32_C(         247),  INT32_C(          93),  INT32_C(         249),  INT32_C(          19),  INT32_C(         102),  INT32_C(          42),  INT32_C(         208),  INT32_C(         193) },
      { SIMDE_FLOAT32_C(   360.00), SIMDE_FLOAT32_C(   422.00), SIMDE_FLOAT32_C(   340.00), SIMDE_FLOAT32_C(   486.00),
        SIMDE_FLOAT32_C(   324.00), SIMDE_FLOAT32_C(   388.00), SIMDE_FLOAT32_C(    54.00), SIMDE_FLOAT32_C(   300.00),
        SIMDE_FLOAT32_C(   494.00), SIMDE_FLOAT32_C(   186.00), SIMDE_FLOAT32_C(   498.00), SIMDE_FLOAT32_C(    38.00),
        SIMDE_FLOAT32_C(   204.00), SIMDE_FLOAT32_C(    84.00), SIMDE_FLOAT32_C(   416.00), SIMDE_FLOAT32_C(   386.00) } },
    { {  INT32_C(          49),  INT32_C(         196),  INT32_C(          48),  INT32_C(         209),  INT32_C(         204),  INT32_C(          76),  INT32_C(          56),  INT32_C(         156),
         INT32_C(         246),  INT32_C(          27),  INT32_C(          52),  INT32_C(          60),  INT32_C(           5),  INT32_C(           8),  INT32_C(         191),  INT32_C(         186) },
      { SIMDE_FLOAT32_C(    98.00), SIMDE_FLOAT32_C(   392.00), SIMDE_FLOAT32_C(    96.00), SIMDE_FLOAT32_C(   418.00),
        SIMDE_FLOAT32_C(   408.00), SIMDE_FLOAT32_C(   152.00), SIMDE_FLOAT32_C(   112.00), SIMDE_FLOAT32_C(   312.00),
        SIMDE_FLOAT32_C(   492.00), SIMDE_FLOAT32_C(    54.00), SIMDE_FLOAT32_C(   104.00), SIMDE_FLOAT32_C(   120.00),
        SIMDE_FLOAT32_C(    10.00), SIMDE_FLOAT32_C(    16.00), SIMDE_FLOAT32_C(   382.00), SIMDE_FLOAT32_C(   372.00) } },
    { {  INT32_C(         219),  INT32_C(         105),  INT32_C(         173),  INT32_C(         126),  INT32_C(          44),  INT32_C(         200),  INT32_C(          20),  INT32_C(          35),
         INT32_C(          37),  INT32_C(          14),  INT32_C(          55),  INT32_C(         139),  INT32_C(          56),  INT32_C(           7),  INT32_C(          76),  INT32_C(         105) },
      { SIMDE_FLOAT32_C(   438.00), SIMDE_FLOAT32_C(   210.00), SIMDE_FLOAT32_C(   346.00), SIMDE_FLOAT32_C(   252.00),
        SIMDE_FLOAT32_C(    88.00), SIMDE_FLOAT32_C(   400.00), SIMDE_FLOAT32_C(    40.00), SIMDE_FLOAT32_C(    70.00),
        SIMDE_FLOAT32_C(    74.00), SIMDE_FLOAT32_C(    28.00), SIMDE_FLOAT32_C(   110.00), SIMDE_FLOAT32_C(   278.00),
        SIMDE_FLOAT32_C(   112.00), SIMDE_FLOAT32_C(    14.00), SIMDE_FLOAT32_C(   152.00), SIMDE_FLOAT32_C(   210.00) } },
    { {  INT32_C(         203),  INT32_C(         124),  INT32_C(          59),  INT32_C(         151),  INT32_C(         200),  INT32_C(         115),  INT32_C(          52),  INT32_C(         191),
         INT32_C(         143),  INT32_C(         104),  INT32_C(         251),  INT32_C(         148),  INT32_C(         112),  INT32_C(         186),  INT32_C(          78),  INT32_C(          76) },
      { SIMDE_FLOAT32_C(   406.00), SIMDE_FLOAT32_C(   248.00), SIMDE_FLOAT32_C(   118.00), SIMDE_FLOAT32_C(   302.00),
        SIMDE_FLOAT32_C(   400.00), SIMDE_FLOAT32_C(   230.00), SIMDE_FLOAT32_C(   104.00), SIMDE_FLOAT32_C(   382.00),
        SIMDE_FLOAT32_C(   286.00), SIMDE_FLOAT32_C(   208.00), SIMDE_FLOAT32_C(   502.00), SIMDE_FLOAT32_C(   296.00),
        SIMDE_FLOAT32_C(   224.00), SIMDE_FLOAT32_C(   372.00), SIMDE_FLOAT32_C(   156.00), SIMDE_FLOAT32_C(   152.00) } },
    { {  INT32_C(          36),  INT32_C(         251),  INT32_C(         202),  INT32_C(          80),  INT32_C(         195),  INT32_C(         222),  INT32_C(         115),  INT32_C(         232),
         INT32_C(         236),  INT32_C(         170),  INT32_C(         115),  INT32_C(          37),  INT32_C(         178),  INT32_C(         192),  INT32_C(         142),  INT32_C(         125) },
      { SIMDE_FLOAT32_C(    72.00), SIMDE_FLOAT32_C(   502.00), SIMDE_FLOAT32_C(   404.00), SIMDE_FLOAT32_C(   160.00),
        SIMDE_FLOAT32_C(   390.00), SIMDE_FLOAT32_C(   444.00), SIMDE_FLOAT32_C(   230.00), SIMDE_FLOAT32_C(   464.00),
        SIMDE_FLOAT32_C(   472.00), SIMDE_FLOAT32_C(   340.00), SIMDE_FLOAT32_C(   230.00), SIMDE_FLOAT32_C(    74.00),
        SIMDE_FLOAT32_C(   356.00), SIMDE_FLOAT32_C(   384.00), SIMDE_FLOAT32_C(   284.00), SIMDE_FLOAT32_C(   250.00) } },
    { {  INT32_C(          60),  INT32_C(         201),  INT32_C(          21),  INT32_C(           5),  INT32_C(          61),  INT32_C(          73),  INT32_C(         196),  INT32_C(         204),
         INT32_C(         177),  INT32_C(         191),  INT32_C(          96),  INT32_C(          34),  INT32_C(         121),  INT32_C(         175),  INT32_C(         110),  INT32_C(         157) },
      { SIMDE_FLOAT32_C(   120.00), SIMDE_FLOAT32_C(   402.00), SIMDE_FLOAT32_C(    42.00), SIMDE_FLOAT32_C(    10.00),
        SIMDE_FLOAT32_C(   122.00), SIMDE_FLOAT32_C(   146.00), SIMDE_FLOAT32_C(   392.00), SIMDE_FLOAT32_C(   408.00),
        SIMDE_FLOAT32_C(   354.00), SIMDE_FLOAT32_C(   382.00), SIMDE_FLOAT32_C(   192.00), SIMDE_FLOAT32_C(    68.00),
        SIMDE_FLOAT32_C(   242.00), SIMDE_FLOAT32_C(   350.00), SIMDE_FLOAT32_C(   220.00), SIMDE_FLOAT32_C(   314.00) } },
    { {  INT32_C(         170),  INT32_C(          56),  INT32_C(         237),  INT32_C(         110),  INT32_C(          22),  INT32_C(          97),  INT32_C(          86),  INT32_C(           3),
         INT32_C(          11),  INT32_C(         202),  INT32_C(          40),  INT32_C(         189),  INT32_C(         138),  INT32_C(         182),  INT32_C(          59),  INT32_C(         198) },
      { SIMDE_FLOAT32_C(   340.00), SIMDE_FLOAT32_C(   112.00), SIMDE_FLOAT32_C(   474.00), SIMDE_FLOAT32_C(   220.00),
        SIMDE_FLOAT32_C(    44.00), SIMDE_FLOAT32_C(   194.00), SIMDE_FLOAT32_C(   172.00), SIMDE_FLOAT32_C(     6.00),
        SIMDE_FLOAT32_C(    22.00), SIMDE_FLOAT32_C(   404.00), SIMDE_FLOAT32_C(    80.00), SIMDE_FLOAT32_C(   378.00),
        SIMDE_FLOAT32_C(   276.00), SIMDE_FLOAT32_C(   364.00), SIMDE_FLOAT32_C(   118.00), SIMDE_FLOAT32_C(   396.00) } },
  };
  for (size_t i = 0 ; i < (sizeof(f32_buffer) / sizeof(f32_buffer[0])) ; i++) { f32_buffer[i] = HEDLEY_STATIC_CAST(simde_float32, i); }

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i vindex = simde_mm512_loadu_epi32(test_vec[i].vindex);
    simde__m512 r = simde_mm512_i32gather_ps(vindex, HEDLEY_STATIC_CAST(const void*, f32_buffer), 8);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);

  for (size_t i = 0 ; i < (sizeof(f32_buffer) / sizeof(f32_buffer[0])) ; i++) { f32_buffer[i] = HEDLEY_STATIC_CAST(simde_float32, i); }

  for (int i = 0; i < 8; i++) {
    simde__m512i vindex = simde_mm512_set_epi32(
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())));
    simde__m512  r = simde_mm512_i32gather_ps(vindex, f32_buffer, 8);

    simde_test_x86_write_i32x16(2, vindex, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int32_t i32_buffer[2048];

static int
test_simde_mm512_i64gather_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t vindex[8];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT64_C(                  99),  INT64_C(                  54),  INT64_C(                 101),  INT64_C(                  76),
         INT64_C(                  81),  INT64_C(                 199),  INT64_C(                  78),  INT64_C(                 219) },
      {  INT32_C(         198),  INT32_C(         108),  INT32_C(         202),  INT32_C(         152),  INT32_C(         162),  INT32_C(         398),  INT32_C(         156),  INT32_C(         438) } },
    { {  INT64_C(                  10),  INT64_C(                 225),  INT64_C(                 193),  INT64_C(                 220),
         INT64_C(                 147),  INT64_C(                 180),  INT64_C(                 252),  INT64_C(                 161) },
      {  INT32_C(          20),  INT32_C(         450),  INT32_C(         386),  INT32_C(         440),  INT32_C(         294),  INT32_C(         360),  INT32_C(         504),  INT32_C(         322) } },
    { {  INT64_C(                  40),  INT64_C(                 182),  INT64_C(                 201),  INT64_C(                 129),
         INT64_C(                 121),  INT64_C(                 142),  INT64_C(                  14),  INT64_C(                 145) },
      {  INT32_C(          80),  INT32_C(         364),  INT32_C(         402),  INT32_C(         258),  INT32_C(         242),  INT32_C(         284),  INT32_C(          28),  INT32_C(         290) } },
    { {  INT64_C(                  60),  INT64_C(                  92),  INT64_C(                  26),  INT64_C(                 140),
         INT64_C(                 174),  INT64_C(                  29),  INT64_C(                 214),  INT64_C(                  18) },
      {  INT32_C(         120),  INT32_C(         184),  INT32_C(          52),  INT32_C(         280),  INT32_C(         348),  INT32_C(          58),  INT32_C(         428),  INT32_C(          36) } },
    { {  INT64_C(                  84),  INT64_C(                  60),  INT64_C(                  94),  INT64_C(                 165),
         INT64_C(                   3),  INT64_C(                 172),  INT64_C(                 128),  INT64_C(                  14) },
      {  INT32_C(         168),  INT32_C(         120),  INT32_C(         188),  INT32_C(         330),  INT32_C(           6),  INT32_C(         344),  INT32_C(         256),  INT32_C(          28) } },
    { {  INT64_C(                 141),  INT64_C(                  66),  INT64_C(                 234),  INT64_C(                  32),
         INT64_C(                 246),  INT64_C(                 231),  INT64_C(                 193),  INT64_C(                  30) },
      {  INT32_C(         282),  INT32_C(         132),  INT32_C(         468),  INT32_C(          64),  INT32_C(         492),  INT32_C(         462),  INT32_C(         386),  INT32_C(          60) } },
    { {  INT64_C(                 157),  INT64_C(                 139),  INT64_C(                 159),  INT64_C(                  23),
         INT64_C(                  25),  INT64_C(                 173),  INT64_C(                 168),  INT64_C(                  86) },
      {  INT32_C(         314),  INT32_C(         278),  INT32_C(         318),  INT32_C(          46),  INT32_C(          50),  INT32_C(         346),  INT32_C(         336),  INT32_C(         172) } },
    { {  INT64_C(                   9),  INT64_C(                 194),  INT64_C(                 226),  INT64_C(                 183),
         INT64_C(                 224),  INT64_C(                 184),  INT64_C(                 201),  INT64_C(                  52) },
      {  INT32_C(          18),  INT32_C(         388),  INT32_C(         452),  INT32_C(         366),  INT32_C(         448),  INT32_C(         368),  INT32_C(         402),  INT32_C(         104) } }
  };
  for (size_t i = 0 ; i < (sizeof(i32_buffer) / sizeof(i32_buffer[0])) ; i++) { i32_buffer[i] = HEDLEY_STATIC_CAST(int32_t, i); }

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i vindex = simde_mm512_loadu_epi64(test_vec[i].vindex);
    simde__m256i r = simde_mm512_i64gather_epi32(vindex, HEDLEY_STATIC_CAST(const void*, i32_buffer), 8);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (size_t i = 0 ; i < (sizeof(i32_buffer) / sizeof(i32_buffer[0])) ; i++) { i32_buffer[i] = HEDLEY_STATIC_CAST(int32_t, i); }

  for (int i = 0; i < 8; i++) {
    simde__m512i vindex = simde_mm512_set_epi64(
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())));
    simde__m256i r = simde_mm512_i64gather_epi32(vindex, i32_buffer, 8);

    simde_test_x86_write_i64x8(2, vindex, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_i64gather_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[8];
    simde__mmask8 k;
    const int64_t vindex[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(  1723041393),  INT32_C(    96312955),  INT32_C(  2084620542),  INT32_C(  1198400529), -INT32_C(   415893220), -INT32_C(  1193950777), -INT32_C(   764347007), -INT32_C(  1902811906) },
      UINT8_C(222),
      {  INT64_C(                 225),  INT64_C(                  39),  INT64_C(                  89),  INT64_C(                 127),
         INT64_C(                 228),  INT64_C(                  94),  INT64_C(                 125),  INT64_C(                 172) },
      { -INT32_C(  1723041393),  INT32_C(          78),  INT32_C(         178),  INT32_C(         254),  INT32_C(         456), -INT32_C(  1193950777),  INT32_C(         250),  INT32_C(         344) } },
    { { -INT32_C(  1010959970),  INT32_C(  1642005864), -INT32_C(    64436422), -INT32_C(  1703026276), -INT32_C(  1248309423), -INT32_C(   980211996),  INT32_C(   843377997), -INT32_C(   354500277) },
      UINT8_C(186),
      {  INT64_C(                 156),  INT64_C(                 173),  INT64_C(                  34),  INT64_C(                 161),
         INT64_C(                 140),  INT64_C(                 132),  INT64_C(                 219),  INT64_C(                  83) },
      { -INT32_C(  1010959970),  INT32_C(         346), -INT32_C(    64436422),  INT32_C(         322),  INT32_C(         280),  INT32_C(         264),  INT32_C(   843377997),  INT32_C(         166) } },
    { { -INT32_C(  1913595988), -INT32_C(  1545696684),  INT32_C(  1233622050),  INT32_C(   345394215),  INT32_C(  1365297296),  INT32_C(  1124879015), -INT32_C(  2082197769),  INT32_C(  1607974834) },
      UINT8_C(151),
      {  INT64_C(                 199),  INT64_C(                 236),  INT64_C(                 235),  INT64_C(                  81),
         INT64_C(                 203),  INT64_C(                 143),  INT64_C(                 115),  INT64_C(                  95) },
      {  INT32_C(         398),  INT32_C(         472),  INT32_C(         470),  INT32_C(   345394215),  INT32_C(         406),  INT32_C(  1124879015), -INT32_C(  2082197769),  INT32_C(         190) } },
    { {  INT32_C(  1669774358),  INT32_C(   468949843),  INT32_C(  1170359803),  INT32_C(  2134639953), -INT32_C(  1456291863),  INT32_C(  1564512662),  INT32_C(  1219373949), -INT32_C(   777575750) },
      UINT8_C(222),
      {  INT64_C(                  46),  INT64_C(                  52),  INT64_C(                  49),  INT64_C(                 201),
         INT64_C(                  39),  INT64_C(                  77),  INT64_C(                 196),  INT64_C(                 108) },
      {  INT32_C(  1669774358),  INT32_C(         104),  INT32_C(          98),  INT32_C(         402),  INT32_C(          78),  INT32_C(  1564512662),  INT32_C(         392),  INT32_C(         216) } },
    { {  INT32_C(   364710159),  INT32_C(    83770693),  INT32_C(    10200943),  INT32_C(   327022823), -INT32_C(   909261145), -INT32_C(  1683513747), -INT32_C(    94053934),  INT32_C(   895887398) },
      UINT8_C( 49),
      {  INT64_C(                  36),  INT64_C(                  74),  INT64_C(                 118),  INT64_C(                  97),
         INT64_C(                  73),  INT64_C(                 123),  INT64_C(                 208),  INT64_C(                 240) },
      {  INT32_C(          72),  INT32_C(    83770693),  INT32_C(    10200943),  INT32_C(   327022823),  INT32_C(         146),  INT32_C(         246), -INT32_C(    94053934),  INT32_C(   895887398) } },
    { {  INT32_C(   249090070),  INT32_C(   330689357),  INT32_C(  1468104376), -INT32_C(    14083034), -INT32_C(  1457183871), -INT32_C(  1361356150), -INT32_C(   300985947), -INT32_C(   488710196) },
      UINT8_C(175),
      {  INT64_C(                 182),  INT64_C(                 241),  INT64_C(                 252),  INT64_C(                 161),
         INT64_C(                 166),  INT64_C(                  16),  INT64_C(                  90),  INT64_C(                  37) },
      {  INT32_C(         364),  INT32_C(         482),  INT32_C(         504),  INT32_C(         322), -INT32_C(  1457183871),  INT32_C(          32), -INT32_C(   300985947),  INT32_C(          74) } },
    { { -INT32_C(  1387548271), -INT32_C(    30520614), -INT32_C(   913778577),  INT32_C(    74331827),  INT32_C(   617700421), -INT32_C(   237784261),  INT32_C(  1267978148),  INT32_C(  1886449119) },
      UINT8_C(158),
      {  INT64_C(                 187),  INT64_C(                  30),  INT64_C(                 120),  INT64_C(                   5),
         INT64_C(                  76),  INT64_C(                 118),  INT64_C(                 116),  INT64_C(                  36) },
      { -INT32_C(  1387548271),  INT32_C(          60),  INT32_C(         240),  INT32_C(          10),  INT32_C(         152), -INT32_C(   237784261),  INT32_C(  1267978148),  INT32_C(          72) } },
    { {  INT32_C(   886521342),  INT32_C(   142204076),  INT32_C(  1615044013),  INT32_C(  1074083184), -INT32_C(  1256238904),  INT32_C(  2069074112), -INT32_C(    92222546),  INT32_C(  1075835970) },
      UINT8_C( 49),
      {  INT64_C(                 246),  INT64_C(                 117),  INT64_C(                 221),  INT64_C(                 210),
         INT64_C(                 238),  INT64_C(                 230),  INT64_C(                 127),  INT64_C(                 140) },
      {  INT32_C(         492),  INT32_C(   142204076),  INT32_C(  1615044013),  INT32_C(  1074083184),  INT32_C(         476),  INT32_C(         460), -INT32_C(    92222546),  INT32_C(  1075835970) } },
  };
  for (size_t i = 0 ; i < (sizeof(i32_buffer) / sizeof(i32_buffer[0])) ; i++) { i32_buffer[i] = HEDLEY_STATIC_CAST(int32_t, i); }

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_mm256_loadu_epi32(test_vec[i].src);
    simde__m512i vindex = simde_mm512_loadu_epi64(test_vec[i].vindex);
    simde__m256i r = simde_mm512_mask_i64gather_epi32(src, test_vec[i].k, vindex, HEDLEY_STATIC_CAST(const void*, i32_buffer), 8);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (size_t i = 0 ; i < (sizeof(i32_buffer) / sizeof(i32_buffer[0])) ; i++) { i32_buffer[i] = HEDLEY_STATIC_CAST(int32_t, i); }

  for (int i = 0; i < 8; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i vindex = simde_mm512_set_epi64(
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())));
    simde__m256i r = simde_mm512_mask_i64gather_epi32(src, k, vindex, i32_buffer, 8);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, vindex, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int64_t i64_buffer[2048];

static int
test_simde_mm512_i64gather_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t vindex[8];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C(                 101),  INT64_C(                  41),  INT64_C(                 148),  INT64_C(                  45),
         INT64_C(                 233),  INT64_C(                 157),  INT64_C(                  59),  INT64_C(                 178) },
      {  INT64_C(                 101),  INT64_C(                  41),  INT64_C(                 148),  INT64_C(                  45),
         INT64_C(                 233),  INT64_C(                 157),  INT64_C(                  59),  INT64_C(                 178) } },
    { {  INT64_C(                 105),  INT64_C(                 251),  INT64_C(                 212),  INT64_C(                  98),
         INT64_C(                 193),  INT64_C(                 235),  INT64_C(                 152),  INT64_C(                 121) },
      {  INT64_C(                 105),  INT64_C(                 251),  INT64_C(                 212),  INT64_C(                  98),
         INT64_C(                 193),  INT64_C(                 235),  INT64_C(                 152),  INT64_C(                 121) } },
    { {  INT64_C(                 133),  INT64_C(                  65),  INT64_C(                  37),  INT64_C(                 189),
         INT64_C(                 106),  INT64_C(                   7),  INT64_C(                 106),  INT64_C(                  95) },
      {  INT64_C(                 133),  INT64_C(                  65),  INT64_C(                  37),  INT64_C(                 189),
         INT64_C(                 106),  INT64_C(                   7),  INT64_C(                 106),  INT64_C(                  95) } },
    { {  INT64_C(                  87),  INT64_C(                  37),  INT64_C(                 119),  INT64_C(                   6),
         INT64_C(                 254),  INT64_C(                  23),  INT64_C(                 237),  INT64_C(                  99) },
      {  INT64_C(                  87),  INT64_C(                  37),  INT64_C(                 119),  INT64_C(                   6),
         INT64_C(                 254),  INT64_C(                  23),  INT64_C(                 237),  INT64_C(                  99) } },
    { {  INT64_C(                  64),  INT64_C(                 129),  INT64_C(                 145),  INT64_C(                  41),
         INT64_C(                  30),  INT64_C(                 204),  INT64_C(                 219),  INT64_C(                 135) },
      {  INT64_C(                  64),  INT64_C(                 129),  INT64_C(                 145),  INT64_C(                  41),
         INT64_C(                  30),  INT64_C(                 204),  INT64_C(                 219),  INT64_C(                 135) } },
    { {  INT64_C(                 199),  INT64_C(                 176),  INT64_C(                 234),  INT64_C(                 136),
         INT64_C(                 155),  INT64_C(                 130),  INT64_C(                   1),  INT64_C(                  32) },
      {  INT64_C(                 199),  INT64_C(                 176),  INT64_C(                 234),  INT64_C(                 136),
         INT64_C(                 155),  INT64_C(                 130),  INT64_C(                   1),  INT64_C(                  32) } },
    { {  INT64_C(                 195),  INT64_C(                  38),  INT64_C(                 221),  INT64_C(                  46),
         INT64_C(                  46),  INT64_C(                  71),  INT64_C(                 141),  INT64_C(                 133) },
      {  INT64_C(                 195),  INT64_C(                  38),  INT64_C(                 221),  INT64_C(                  46),
         INT64_C(                  46),  INT64_C(                  71),  INT64_C(                 141),  INT64_C(                 133) } },
    { {  INT64_C(                 109),  INT64_C(                   4),  INT64_C(                 139),  INT64_C(                 107),
         INT64_C(                  27),  INT64_C(                 120),  INT64_C(                 206),  INT64_C(                  91) },
      {  INT64_C(                 109),  INT64_C(                   4),  INT64_C(                 139),  INT64_C(                 107),
         INT64_C(                  27),  INT64_C(                 120),  INT64_C(                 206),  INT64_C(                  91) } },
  };
  for (size_t i = 0 ; i < (sizeof(i64_buffer) / sizeof(i64_buffer[0])) ; i++) { i64_buffer[i] = HEDLEY_STATIC_CAST(int64_t, i); }

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i vindex = simde_mm512_loadu_epi64(test_vec[i].vindex);
    simde__m512i r = simde_mm512_i64gather_epi64(vindex, HEDLEY_STATIC_CAST(const void*, i64_buffer), 8);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (size_t i = 0 ; i < (sizeof(i64_buffer) / sizeof(i64_buffer[0])) ; i++) { i64_buffer[i] = HEDLEY_STATIC_CAST(int64_t, i); }

  for (int i = 0; i < 8; i++) {
    simde__m512i vindex = simde_mm512_set_epi64(
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())));
    simde__m512i r = simde_mm512_i64gather_epi64(vindex, i64_buffer, 8);

    simde_test_x86_write_i64x8(2, vindex, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_i64gather_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[8];
    const simde__mmask8 k;
    const int64_t vindex[8];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 1984428018067240100), -INT64_C( 2414100954086902818), -INT64_C( 7968884413910531848), -INT64_C( 7442120368302142668),
        -INT64_C( 1577987146540387782),  INT64_C( 3145884408933699792),  INT64_C( 7500261619853647789),  INT64_C( 4440725167482125331) },
      UINT8_C(146),
      {  INT64_C(                 244),  INT64_C(                  60),  INT64_C(                 159),  INT64_C(                 209),
         INT64_C(                  85),  INT64_C(                 137),  INT64_C(                 162),  INT64_C(                  38) },
      {  INT64_C( 1984428018067240100),  INT64_C(                  60), -INT64_C( 7968884413910531848), -INT64_C( 7442120368302142668),
         INT64_C(                  85),  INT64_C( 3145884408933699792),  INT64_C( 7500261619853647789),  INT64_C(                  38) } },
    { {  INT64_C( 8327864985755151479), -INT64_C( 1459148486616868764),  INT64_C( 6641168328753596664), -INT64_C( 3826986200259966617),
         INT64_C( 2793149591949622332),  INT64_C( 8247096397624666714), -INT64_C(  855906521198206630),  INT64_C( 6421170022369021438) },
      UINT8_C(209),
      {  INT64_C(                 203),  INT64_C(                 169),  INT64_C(                 146),  INT64_C(                  13),
         INT64_C(                 108),  INT64_C(                 184),  INT64_C(                 103),  INT64_C(                 215) },
      {  INT64_C(                 203), -INT64_C( 1459148486616868764),  INT64_C( 6641168328753596664), -INT64_C( 3826986200259966617),
         INT64_C(                 108),  INT64_C( 8247096397624666714),  INT64_C(                 103),  INT64_C(                 215) } },
    { { -INT64_C( 4217405121059753845), -INT64_C( 6340427972967515186),  INT64_C( 4277609785035412472),  INT64_C( 3678509232149819592),
        -INT64_C( 1096405365637948000),  INT64_C( 6415084517789473284), -INT64_C( 5479961641881318327), -INT64_C( 8354189485610091469) },
      UINT8_C( 82),
      {  INT64_C(                  96),  INT64_C(                 143),  INT64_C(                 115),  INT64_C(                  41),
         INT64_C(                  88),  INT64_C(                  99),  INT64_C(                  45),  INT64_C(                 114) },
      { -INT64_C( 4217405121059753845),  INT64_C(                 143),  INT64_C( 4277609785035412472),  INT64_C( 3678509232149819592),
         INT64_C(                  88),  INT64_C( 6415084517789473284),  INT64_C(                  45), -INT64_C( 8354189485610091469) } },
    { {  INT64_C( 6815402617960893271),  INT64_C( 9045757209107582482), -INT64_C( 3302276028123487259),  INT64_C( 6435406385315028869),
         INT64_C( 7035813729533305780), -INT64_C( 3582544329707164279),  INT64_C( 3235787571848589986), -INT64_C( 4625661861519826318) },
      UINT8_C(124),
      {  INT64_C(                 116),  INT64_C(                   5),  INT64_C(                 203),  INT64_C(                 176),
         INT64_C(                 169),  INT64_C(                  45),  INT64_C(                  57),  INT64_C(                 150) },
      {  INT64_C( 6815402617960893271),  INT64_C( 9045757209107582482),  INT64_C(                 203),  INT64_C(                 176),
         INT64_C(                 169),  INT64_C(                  45),  INT64_C(                  57), -INT64_C( 4625661861519826318) } },
    { { -INT64_C(   16802405404441373), -INT64_C( 6756292520287217418), -INT64_C(  814750763960127012), -INT64_C( 8236839995799470735),
         INT64_C( 8299698144798519266), -INT64_C( 8886312731377019828),  INT64_C( 4007477744424802858),  INT64_C(   80784553426371048) },
      UINT8_C( 49),
      {  INT64_C(                 207),  INT64_C(                  48),  INT64_C(                 174),  INT64_C(                  66),
         INT64_C(                  94),  INT64_C(                  34),  INT64_C(                 142),  INT64_C(                  50) },
      {  INT64_C(                 207), -INT64_C( 6756292520287217418), -INT64_C(  814750763960127012), -INT64_C( 8236839995799470735),
         INT64_C(                  94),  INT64_C(                  34),  INT64_C( 4007477744424802858),  INT64_C(   80784553426371048) } },
    { { -INT64_C( 6772747226937910689), -INT64_C( 8472783511363212521), -INT64_C( 1502889334311093007),  INT64_C( 6011105884756628186),
        -INT64_C( 5026248478382406314),  INT64_C( 4155880484410075353), -INT64_C( 2617910794231458140), -INT64_C( 1555010071818938333) },
      UINT8_C(195),
      {  INT64_C(                 150),  INT64_C(                 136),  INT64_C(                 102),  INT64_C(                 196),
         INT64_C(                 199),  INT64_C(                  33),  INT64_C(                 157),  INT64_C(                 111) },
      {  INT64_C(                 150),  INT64_C(                 136), -INT64_C( 1502889334311093007),  INT64_C( 6011105884756628186),
        -INT64_C( 5026248478382406314),  INT64_C( 4155880484410075353),  INT64_C(                 157),  INT64_C(                 111) } },
    { { -INT64_C( 4491793711365636258), -INT64_C( 1328107704014444259), -INT64_C( 6128717313240618832), -INT64_C( 2870187715760072204),
        -INT64_C( 1011190250109803830),  INT64_C(  500726760839559664), -INT64_C( 3218339942577638504), -INT64_C( 7362335563379129215) },
      UINT8_C(156),
      {  INT64_C(                 176),  INT64_C(                 206),  INT64_C(                 112),  INT64_C(                  55),
         INT64_C(                 197),  INT64_C(                  97),  INT64_C(                  40),  INT64_C(                 126) },
      { -INT64_C( 4491793711365636258), -INT64_C( 1328107704014444259),  INT64_C(                 112),  INT64_C(                  55),
         INT64_C(                 197),  INT64_C(  500726760839559664), -INT64_C( 3218339942577638504),  INT64_C(                 126) } },
    { { -INT64_C( 7905828216691741248),  INT64_C( 1060955372299416592),  INT64_C( 4047459014712079572), -INT64_C( 4861187214007100603),
         INT64_C( 5293616568447294916),  INT64_C(  144743206574221481), -INT64_C( 7228352896858791953),  INT64_C( 8795018482906635862) },
      UINT8_C(140),
      {  INT64_C(                 122),  INT64_C(                  94),  INT64_C(                 196),  INT64_C(                  47),
         INT64_C(                 212),  INT64_C(                  13),  INT64_C(                 216),  INT64_C(                 188) },
      { -INT64_C( 7905828216691741248),  INT64_C( 1060955372299416592),  INT64_C(                 196),  INT64_C(                  47),
         INT64_C( 5293616568447294916),  INT64_C(  144743206574221481), -INT64_C( 7228352896858791953),  INT64_C(                 188) } },
  };
  for (size_t i = 0 ; i < (sizeof(i64_buffer) / sizeof(i64_buffer[0])) ; i++) { i64_buffer[i] = HEDLEY_STATIC_CAST(int64_t, i); }

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi64(test_vec[i].src);
    simde__m512i vindex = simde_mm512_loadu_epi64(test_vec[i].vindex);
    simde__m512i r = simde_mm512_mask_i64gather_epi64(src, test_vec[i].k, vindex, HEDLEY_STATIC_CAST(const void*, i64_buffer), 8);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (size_t i = 0 ; i < (sizeof(i64_buffer) / sizeof(i64_buffer[0])) ; i++) { i64_buffer[i] = HEDLEY_STATIC_CAST(int64_t, i); }

  for (int i = 0; i < 8; i++) {
    simde__m512i src = simde_test_x86_random_i64x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i vindex = simde_mm512_set_epi64(
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())));
    simde__m512i r = simde_mm512_mask_i64gather_epi64(src, k, vindex, i64_buffer, 8);

    simde_test_x86_write_i64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, vindex, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_i64gather_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t vindex[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { {  INT64_C(                  63),  INT64_C(                  72),  INT64_C(                 219),  INT64_C(                 201),
         INT64_C(                 236),  INT64_C(                 211),  INT64_C(                  60),  INT64_C(                 171) },
      { SIMDE_FLOAT32_C(   126.00), SIMDE_FLOAT32_C(   144.00), SIMDE_FLOAT32_C(   438.00), SIMDE_FLOAT32_C(   402.00),
        SIMDE_FLOAT32_C(   472.00), SIMDE_FLOAT32_C(   422.00), SIMDE_FLOAT32_C(   120.00), SIMDE_FLOAT32_C(   342.00) } },
    { {  INT64_C(                 163),  INT64_C(                 212),  INT64_C(                 237),  INT64_C(                 236),
         INT64_C(                  38),  INT64_C(                 221),  INT64_C(                 176),  INT64_C(                  15) },
      { SIMDE_FLOAT32_C(   326.00), SIMDE_FLOAT32_C(   424.00), SIMDE_FLOAT32_C(   474.00), SIMDE_FLOAT32_C(   472.00),
        SIMDE_FLOAT32_C(    76.00), SIMDE_FLOAT32_C(   442.00), SIMDE_FLOAT32_C(   352.00), SIMDE_FLOAT32_C(    30.00) } },
    { {  INT64_C(                 108),  INT64_C(                 118),  INT64_C(                 135),  INT64_C(                 245),
         INT64_C(                  24),  INT64_C(                  69),  INT64_C(                 121),  INT64_C(                 104) },
      { SIMDE_FLOAT32_C(   216.00), SIMDE_FLOAT32_C(   236.00), SIMDE_FLOAT32_C(   270.00), SIMDE_FLOAT32_C(   490.00),
        SIMDE_FLOAT32_C(    48.00), SIMDE_FLOAT32_C(   138.00), SIMDE_FLOAT32_C(   242.00), SIMDE_FLOAT32_C(   208.00) } },
    { {  INT64_C(                  38),  INT64_C(                  30),  INT64_C(                 220),  INT64_C(                  63),
         INT64_C(                 166),  INT64_C(                  80),  INT64_C(                 194),  INT64_C(                 230) },
      { SIMDE_FLOAT32_C(    76.00), SIMDE_FLOAT32_C(    60.00), SIMDE_FLOAT32_C(   440.00), SIMDE_FLOAT32_C(   126.00),
        SIMDE_FLOAT32_C(   332.00), SIMDE_FLOAT32_C(   160.00), SIMDE_FLOAT32_C(   388.00), SIMDE_FLOAT32_C(   460.00) } },
    { {  INT64_C(                 152),  INT64_C(                 158),  INT64_C(                 175),  INT64_C(                 132),
         INT64_C(                 113),  INT64_C(                 235),  INT64_C(                  47),  INT64_C(                  21) },
      { SIMDE_FLOAT32_C(   304.00), SIMDE_FLOAT32_C(   316.00), SIMDE_FLOAT32_C(   350.00), SIMDE_FLOAT32_C(   264.00),
        SIMDE_FLOAT32_C(   226.00), SIMDE_FLOAT32_C(   470.00), SIMDE_FLOAT32_C(    94.00), SIMDE_FLOAT32_C(    42.00) } },
    { {  INT64_C(                 191),  INT64_C(                  29),  INT64_C(                   1),  INT64_C(                 229),
         INT64_C(                 250),  INT64_C(                 177),  INT64_C(                 244),  INT64_C(                 102) },
      { SIMDE_FLOAT32_C(   382.00), SIMDE_FLOAT32_C(    58.00), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(   458.00),
        SIMDE_FLOAT32_C(   500.00), SIMDE_FLOAT32_C(   354.00), SIMDE_FLOAT32_C(   488.00), SIMDE_FLOAT32_C(   204.00) } },
    { {  INT64_C(                  40),  INT64_C(                 123),  INT64_C(                  91),  INT64_C(                  64),
         INT64_C(                 192),  INT64_C(                 213),  INT64_C(                 169),  INT64_C(                 230) },
      { SIMDE_FLOAT32_C(    80.00), SIMDE_FLOAT32_C(   246.00), SIMDE_FLOAT32_C(   182.00), SIMDE_FLOAT32_C(   128.00),
        SIMDE_FLOAT32_C(   384.00), SIMDE_FLOAT32_C(   426.00), SIMDE_FLOAT32_C(   338.00), SIMDE_FLOAT32_C(   460.00) } },
    { {  INT64_C(                 243),  INT64_C(                 133),  INT64_C(                  37),  INT64_C(                 154),
         INT64_C(                 213),  INT64_C(                 232),  INT64_C(                 128),  INT64_C(                 109) },
      { SIMDE_FLOAT32_C(   486.00), SIMDE_FLOAT32_C(   266.00), SIMDE_FLOAT32_C(    74.00), SIMDE_FLOAT32_C(   308.00),
        SIMDE_FLOAT32_C(   426.00), SIMDE_FLOAT32_C(   464.00), SIMDE_FLOAT32_C(   256.00), SIMDE_FLOAT32_C(   218.00) } },
  };
  for (size_t i = 0 ; i < (sizeof(f32_buffer) / sizeof(f32_buffer[0])) ; i++) { f32_buffer[i] = HEDLEY_STATIC_CAST(simde_float32, i); }

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i vindex = simde_mm512_loadu_epi64(test_vec[i].vindex);
    simde__m256 r = simde_mm512_i64gather_ps(vindex, HEDLEY_STATIC_CAST(const void*, f32_buffer), 8);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);

  for (size_t i = 0 ; i < (sizeof(f32_buffer) / sizeof(f32_buffer[0])) ; i++) { f32_buffer[i] = HEDLEY_STATIC_CAST(simde_float32, i); }

  for (int i = 0; i < 8; i++) {
    simde__m512i vindex = simde_mm512_set_epi64(
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())));
    simde__m256 r = simde_mm512_i64gather_ps(vindex, f32_buffer, 8);

    simde_test_x86_write_i64x8(2, vindex, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_i64gather_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[8];
    const simde__mmask8 k;
    const int64_t vindex[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -244.06), SIMDE_FLOAT32_C(  -573.24), SIMDE_FLOAT32_C(   330.53), SIMDE_FLOAT32_C(   541.20),
        SIMDE_FLOAT32_C(   260.56), SIMDE_FLOAT32_C(  -655.21), SIMDE_FLOAT32_C(    72.81), SIMDE_FLOAT32_C(   696.96) },
      UINT8_C(166),
      {  INT64_C(                 109),  INT64_C(                 244),  INT64_C(                  66),  INT64_C(                 157),
         INT64_C(                 184),  INT64_C(                 241),  INT64_C(                 218),  INT64_C(                 179) },
      { SIMDE_FLOAT32_C(  -244.06), SIMDE_FLOAT32_C(   488.00), SIMDE_FLOAT32_C(   132.00), SIMDE_FLOAT32_C(   541.20),
        SIMDE_FLOAT32_C(   260.56), SIMDE_FLOAT32_C(   482.00), SIMDE_FLOAT32_C(    72.81), SIMDE_FLOAT32_C(   358.00) } },
    { { SIMDE_FLOAT32_C(  -472.29), SIMDE_FLOAT32_C(  -259.46), SIMDE_FLOAT32_C(   370.51), SIMDE_FLOAT32_C(  -860.10),
        SIMDE_FLOAT32_C(  -882.37), SIMDE_FLOAT32_C(  -758.79), SIMDE_FLOAT32_C(   -30.79), SIMDE_FLOAT32_C(   738.31) },
      UINT8_C(136),
      {  INT64_C(                  55),  INT64_C(                  59),  INT64_C(                  72),  INT64_C(                 112),
         INT64_C(                 109),  INT64_C(                 238),  INT64_C(                 110),  INT64_C(                 164) },
      { SIMDE_FLOAT32_C(  -472.29), SIMDE_FLOAT32_C(  -259.46), SIMDE_FLOAT32_C(   370.51), SIMDE_FLOAT32_C(   224.00),
        SIMDE_FLOAT32_C(  -882.37), SIMDE_FLOAT32_C(  -758.79), SIMDE_FLOAT32_C(   -30.79), SIMDE_FLOAT32_C(   328.00) } },
    { { SIMDE_FLOAT32_C(   774.25), SIMDE_FLOAT32_C(  -229.38), SIMDE_FLOAT32_C(   492.09), SIMDE_FLOAT32_C(  -152.94),
        SIMDE_FLOAT32_C(  -532.42), SIMDE_FLOAT32_C(   268.84), SIMDE_FLOAT32_C(  -308.73), SIMDE_FLOAT32_C(   -58.59) },
      UINT8_C(187),
      {  INT64_C(                 141),  INT64_C(                 226),  INT64_C(                 173),  INT64_C(                 103),
         INT64_C(                 149),  INT64_C(                  89),  INT64_C(                 113),  INT64_C(                 232) },
      { SIMDE_FLOAT32_C(   282.00), SIMDE_FLOAT32_C(   452.00), SIMDE_FLOAT32_C(   492.09), SIMDE_FLOAT32_C(   206.00),
        SIMDE_FLOAT32_C(   298.00), SIMDE_FLOAT32_C(   178.00), SIMDE_FLOAT32_C(  -308.73), SIMDE_FLOAT32_C(   464.00) } },
    { { SIMDE_FLOAT32_C(   196.06), SIMDE_FLOAT32_C(   707.06), SIMDE_FLOAT32_C(   839.97), SIMDE_FLOAT32_C(  -834.73),
        SIMDE_FLOAT32_C(   445.37), SIMDE_FLOAT32_C(   482.10), SIMDE_FLOAT32_C(   110.19), SIMDE_FLOAT32_C(  -322.27) },
      UINT8_C(152),
      {  INT64_C(                  52),  INT64_C(                 100),  INT64_C(                 134),  INT64_C(                 163),
         INT64_C(                   9),  INT64_C(                 196),  INT64_C(                 204),  INT64_C(                 220) },
      { SIMDE_FLOAT32_C(   196.06), SIMDE_FLOAT32_C(   707.06), SIMDE_FLOAT32_C(   839.97), SIMDE_FLOAT32_C(   326.00),
        SIMDE_FLOAT32_C(    18.00), SIMDE_FLOAT32_C(   482.10), SIMDE_FLOAT32_C(   110.19), SIMDE_FLOAT32_C(   440.00) } },
    { { SIMDE_FLOAT32_C(   813.58), SIMDE_FLOAT32_C(   -58.24), SIMDE_FLOAT32_C(  -597.26), SIMDE_FLOAT32_C(  -495.15),
        SIMDE_FLOAT32_C(   883.17), SIMDE_FLOAT32_C(  -319.10), SIMDE_FLOAT32_C(   518.95), SIMDE_FLOAT32_C(  -680.42) },
      UINT8_C(189),
      {  INT64_C(                  43),  INT64_C(                 164),  INT64_C(                  22),  INT64_C(                 156),
         INT64_C(                 140),  INT64_C(                  41),  INT64_C(                 102),  INT64_C(                  84) },
      { SIMDE_FLOAT32_C(    86.00), SIMDE_FLOAT32_C(   -58.24), SIMDE_FLOAT32_C(    44.00), SIMDE_FLOAT32_C(   312.00),
        SIMDE_FLOAT32_C(   280.00), SIMDE_FLOAT32_C(    82.00), SIMDE_FLOAT32_C(   518.95), SIMDE_FLOAT32_C(   168.00) } },
    { { SIMDE_FLOAT32_C(   626.86), SIMDE_FLOAT32_C(   109.68), SIMDE_FLOAT32_C(   468.68), SIMDE_FLOAT32_C(  -262.95),
        SIMDE_FLOAT32_C(   787.42), SIMDE_FLOAT32_C(  -572.11), SIMDE_FLOAT32_C(   -69.46), SIMDE_FLOAT32_C(  -718.08) },
      UINT8_C(196),
      {  INT64_C(                  83),  INT64_C(                 135),  INT64_C(                 136),  INT64_C(                  31),
         INT64_C(                  99),  INT64_C(                 206),  INT64_C(                  33),  INT64_C(                 184) },
      { SIMDE_FLOAT32_C(   626.86), SIMDE_FLOAT32_C(   109.68), SIMDE_FLOAT32_C(   272.00), SIMDE_FLOAT32_C(  -262.95),
        SIMDE_FLOAT32_C(   787.42), SIMDE_FLOAT32_C(  -572.11), SIMDE_FLOAT32_C(    66.00), SIMDE_FLOAT32_C(   368.00) } },
    { { SIMDE_FLOAT32_C(   -94.89), SIMDE_FLOAT32_C(   933.21), SIMDE_FLOAT32_C(  -858.75), SIMDE_FLOAT32_C(  -575.94),
        SIMDE_FLOAT32_C(  -747.21), SIMDE_FLOAT32_C(   350.61), SIMDE_FLOAT32_C(  -208.11), SIMDE_FLOAT32_C(  -199.38) },
      UINT8_C(156),
      {  INT64_C(                 145),  INT64_C(                 140),  INT64_C(                 198),  INT64_C(                 247),
         INT64_C(                 224),  INT64_C(                 125),  INT64_C(                  25),  INT64_C(                 133) },
      { SIMDE_FLOAT32_C(   -94.89), SIMDE_FLOAT32_C(   933.21), SIMDE_FLOAT32_C(   396.00), SIMDE_FLOAT32_C(   494.00),
        SIMDE_FLOAT32_C(   448.00), SIMDE_FLOAT32_C(   350.61), SIMDE_FLOAT32_C(  -208.11), SIMDE_FLOAT32_C(   266.00) } },
    { { SIMDE_FLOAT32_C(   441.64), SIMDE_FLOAT32_C(   310.56), SIMDE_FLOAT32_C(  -169.63), SIMDE_FLOAT32_C(  -627.82),
        SIMDE_FLOAT32_C(   592.49), SIMDE_FLOAT32_C(  -549.48), SIMDE_FLOAT32_C(     6.28), SIMDE_FLOAT32_C(   516.21) },
      UINT8_C( 15),
      {  INT64_C(                  27),  INT64_C(                 154),  INT64_C(                 221),  INT64_C(                  60),
         INT64_C(                  82),  INT64_C(                 226),  INT64_C(                 138),  INT64_C(                  27) },
      { SIMDE_FLOAT32_C(    54.00), SIMDE_FLOAT32_C(   308.00), SIMDE_FLOAT32_C(   442.00), SIMDE_FLOAT32_C(   120.00),
        SIMDE_FLOAT32_C(   592.49), SIMDE_FLOAT32_C(  -549.48), SIMDE_FLOAT32_C(     6.28), SIMDE_FLOAT32_C(   516.21) } },
  };
  for (size_t i = 0 ; i < (sizeof(f32_buffer) / sizeof(f32_buffer[0])) ; i++) { f32_buffer[i] = HEDLEY_STATIC_CAST(simde_float32, i); }

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 src = simde_mm256_loadu_ps(test_vec[i].src);
    simde__m512i vindex = simde_mm512_loadu_epi64(test_vec[i].vindex);
    simde__m256 r = simde_mm512_mask_i64gather_ps(src, test_vec[i].k, vindex, HEDLEY_STATIC_CAST(const void*, f32_buffer), 8);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);

  for (size_t i = 0 ; i < (sizeof(f32_buffer) / sizeof(f32_buffer[0])) ; i++) { f32_buffer[i] = HEDLEY_STATIC_CAST(simde_float32, i); }

  for (int i = 0; i < 8; i++) {
    simde__m256 src = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i vindex = simde_mm512_set_epi64(
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())));
    simde__m256 r = simde_mm512_mask_i64gather_ps(src, k, vindex, f32_buffer, 8);

    simde_test_x86_write_f32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, vindex, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static simde_float64 f64_buffer[2048];

static int
test_simde_mm512_i64gather_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t vindex[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { {  INT64_C(                  81),  INT64_C(                 130),  INT64_C(                 178),  INT64_C(                 162),
         INT64_C(                  53),  INT64_C(                 146),  INT64_C(                 137),  INT64_C(                  11) },
      { SIMDE_FLOAT64_C(    81.00), SIMDE_FLOAT64_C(   130.00), SIMDE_FLOAT64_C(   178.00), SIMDE_FLOAT64_C(   162.00),
        SIMDE_FLOAT64_C(    53.00), SIMDE_FLOAT64_C(   146.00), SIMDE_FLOAT64_C(   137.00), SIMDE_FLOAT64_C(    11.00) } },
    { {  INT64_C(                 253),  INT64_C(                 179),  INT64_C(                   7),  INT64_C(                  97),
         INT64_C(                  77),  INT64_C(                 212),  INT64_C(                 130),  INT64_C(                  42) },
      { SIMDE_FLOAT64_C(   253.00), SIMDE_FLOAT64_C(   179.00), SIMDE_FLOAT64_C(     7.00), SIMDE_FLOAT64_C(    97.00),
        SIMDE_FLOAT64_C(    77.00), SIMDE_FLOAT64_C(   212.00), SIMDE_FLOAT64_C(   130.00), SIMDE_FLOAT64_C(    42.00) } },
    { {  INT64_C(                 173),  INT64_C(                 174),  INT64_C(                 104),  INT64_C(                  50),
         INT64_C(                 140),  INT64_C(                 171),  INT64_C(                   4),  INT64_C(                 218) },
      { SIMDE_FLOAT64_C(   173.00), SIMDE_FLOAT64_C(   174.00), SIMDE_FLOAT64_C(   104.00), SIMDE_FLOAT64_C(    50.00),
        SIMDE_FLOAT64_C(   140.00), SIMDE_FLOAT64_C(   171.00), SIMDE_FLOAT64_C(     4.00), SIMDE_FLOAT64_C(   218.00) } },
    { {  INT64_C(                  82),  INT64_C(                 179),  INT64_C(                 104),  INT64_C(                 230),
         INT64_C(                  78),  INT64_C(                 154),  INT64_C(                  88),  INT64_C(                 159) },
      { SIMDE_FLOAT64_C(    82.00), SIMDE_FLOAT64_C(   179.00), SIMDE_FLOAT64_C(   104.00), SIMDE_FLOAT64_C(   230.00),
        SIMDE_FLOAT64_C(    78.00), SIMDE_FLOAT64_C(   154.00), SIMDE_FLOAT64_C(    88.00), SIMDE_FLOAT64_C(   159.00) } },
    { {  INT64_C(                  28),  INT64_C(                  10),  INT64_C(                  65),  INT64_C(                  81),
         INT64_C(                 156),  INT64_C(                 202),  INT64_C(                  93),  INT64_C(                 153) },
      { SIMDE_FLOAT64_C(    28.00), SIMDE_FLOAT64_C(    10.00), SIMDE_FLOAT64_C(    65.00), SIMDE_FLOAT64_C(    81.00),
        SIMDE_FLOAT64_C(   156.00), SIMDE_FLOAT64_C(   202.00), SIMDE_FLOAT64_C(    93.00), SIMDE_FLOAT64_C(   153.00) } },
    { {  INT64_C(                 125),  INT64_C(                 100),  INT64_C(                 251),  INT64_C(                 202),
         INT64_C(                  56),  INT64_C(                 125),  INT64_C(                 245),  INT64_C(                 230) },
      { SIMDE_FLOAT64_C(   125.00), SIMDE_FLOAT64_C(   100.00), SIMDE_FLOAT64_C(   251.00), SIMDE_FLOAT64_C(   202.00),
        SIMDE_FLOAT64_C(    56.00), SIMDE_FLOAT64_C(   125.00), SIMDE_FLOAT64_C(   245.00), SIMDE_FLOAT64_C(   230.00) } },
    { {  INT64_C(                  43),  INT64_C(                  93),  INT64_C(                  24),  INT64_C(                 184),
         INT64_C(                   8),  INT64_C(                  28),  INT64_C(                 146),  INT64_C(                  90) },
      { SIMDE_FLOAT64_C(    43.00), SIMDE_FLOAT64_C(    93.00), SIMDE_FLOAT64_C(    24.00), SIMDE_FLOAT64_C(   184.00),
        SIMDE_FLOAT64_C(     8.00), SIMDE_FLOAT64_C(    28.00), SIMDE_FLOAT64_C(   146.00), SIMDE_FLOAT64_C(    90.00) } },
    { {  INT64_C(                 208),  INT64_C(                 250),  INT64_C(                  64),  INT64_C(                  30),
         INT64_C(                 148),  INT64_C(                 152),  INT64_C(                 190),  INT64_C(                 177) },
      { SIMDE_FLOAT64_C(   208.00), SIMDE_FLOAT64_C(   250.00), SIMDE_FLOAT64_C(    64.00), SIMDE_FLOAT64_C(    30.00),
        SIMDE_FLOAT64_C(   148.00), SIMDE_FLOAT64_C(   152.00), SIMDE_FLOAT64_C(   190.00), SIMDE_FLOAT64_C(   177.00) } },
  };
  for (size_t i = 0 ; i < (sizeof(f64_buffer) / sizeof(f64_buffer[0])) ; i++) { f64_buffer[i] = HEDLEY_STATIC_CAST(simde_float64, i); }

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i vindex = simde_mm512_loadu_epi64(test_vec[i].vindex);
    simde__m512d r = simde_mm512_i64gather_pd(vindex, f64_buffer, 8);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);

  for (size_t i = 0 ; i < (sizeof(f64_buffer) / sizeof(f64_buffer[0])) ; i++) { f64_buffer[i] = HEDLEY_STATIC_CAST(simde_float64, i); }

  for (int i = 0; i < 8; i++) {
    simde__m512i vindex = simde_mm512_set_epi64(
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())));
    simde__m512d r = simde_mm512_i64gather_pd(vindex, f64_buffer, 8);

    simde_test_x86_write_i64x8(2, vindex, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_i64gather_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[8];
    const simde__mmask8 k;
    const int64_t vindex[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   223.11), SIMDE_FLOAT64_C(  -710.72), SIMDE_FLOAT64_C(  -783.47), SIMDE_FLOAT64_C(   606.62),
        SIMDE_FLOAT64_C(  -643.82), SIMDE_FLOAT64_C(    31.73), SIMDE_FLOAT64_C(  -880.49), SIMDE_FLOAT64_C(  -115.50) },
      UINT8_C(189),
      {  INT64_C(                  16),  INT64_C(                 177),  INT64_C(                 193),  INT64_C(                  43),
         INT64_C(                  55),  INT64_C(                  99),  INT64_C(                  52),  INT64_C(                  36) },
      { SIMDE_FLOAT64_C(    16.00), SIMDE_FLOAT64_C(  -710.72), SIMDE_FLOAT64_C(   193.00), SIMDE_FLOAT64_C(    43.00),
        SIMDE_FLOAT64_C(    55.00), SIMDE_FLOAT64_C(    99.00), SIMDE_FLOAT64_C(  -880.49), SIMDE_FLOAT64_C(    36.00) } },
    { { SIMDE_FLOAT64_C(   204.01), SIMDE_FLOAT64_C(  -197.77), SIMDE_FLOAT64_C(  -836.10), SIMDE_FLOAT64_C(    97.36),
        SIMDE_FLOAT64_C(  -627.75), SIMDE_FLOAT64_C(   863.52), SIMDE_FLOAT64_C(   518.57), SIMDE_FLOAT64_C(   380.89) },
      UINT8_C(163),
      {  INT64_C(                  35),  INT64_C(                 113),  INT64_C(                  17),  INT64_C(                  27),
         INT64_C(                 193),  INT64_C(                 232),  INT64_C(                 114),  INT64_C(                 173) },
      { SIMDE_FLOAT64_C(    35.00), SIMDE_FLOAT64_C(   113.00), SIMDE_FLOAT64_C(  -836.10), SIMDE_FLOAT64_C(    97.36),
        SIMDE_FLOAT64_C(  -627.75), SIMDE_FLOAT64_C(   232.00), SIMDE_FLOAT64_C(   518.57), SIMDE_FLOAT64_C(   173.00) } },
    { { SIMDE_FLOAT64_C(  -139.16), SIMDE_FLOAT64_C(    40.30), SIMDE_FLOAT64_C(   -35.80), SIMDE_FLOAT64_C(   -19.65),
        SIMDE_FLOAT64_C(   924.81), SIMDE_FLOAT64_C(    68.78), SIMDE_FLOAT64_C(   419.72), SIMDE_FLOAT64_C(   550.54) },
      UINT8_C( 66),
      {  INT64_C(                  12),  INT64_C(                 237),  INT64_C(                 165),  INT64_C(                  65),
         INT64_C(                  17),  INT64_C(                 180),  INT64_C(                 149),  INT64_C(                 178) },
      { SIMDE_FLOAT64_C(  -139.16), SIMDE_FLOAT64_C(   237.00), SIMDE_FLOAT64_C(   -35.80), SIMDE_FLOAT64_C(   -19.65),
        SIMDE_FLOAT64_C(   924.81), SIMDE_FLOAT64_C(    68.78), SIMDE_FLOAT64_C(   149.00), SIMDE_FLOAT64_C(   550.54) } },
    { { SIMDE_FLOAT64_C(  -990.13), SIMDE_FLOAT64_C(   586.89), SIMDE_FLOAT64_C(    62.13), SIMDE_FLOAT64_C(   528.45),
        SIMDE_FLOAT64_C(   -32.21), SIMDE_FLOAT64_C(  -515.53), SIMDE_FLOAT64_C(   550.99), SIMDE_FLOAT64_C(   422.62) },
      UINT8_C( 27),
      {  INT64_C(                 104),  INT64_C(                  49),  INT64_C(                   3),  INT64_C(                 218),
         INT64_C(                 222),  INT64_C(                 111),  INT64_C(                  95),  INT64_C(                 161) },
      { SIMDE_FLOAT64_C(   104.00), SIMDE_FLOAT64_C(    49.00), SIMDE_FLOAT64_C(    62.13), SIMDE_FLOAT64_C(   218.00),
        SIMDE_FLOAT64_C(   222.00), SIMDE_FLOAT64_C(  -515.53), SIMDE_FLOAT64_C(   550.99), SIMDE_FLOAT64_C(   422.62) } },
    { { SIMDE_FLOAT64_C(   611.00), SIMDE_FLOAT64_C(   595.07), SIMDE_FLOAT64_C(   104.01), SIMDE_FLOAT64_C(    30.72),
        SIMDE_FLOAT64_C(   145.61), SIMDE_FLOAT64_C(  -578.55), SIMDE_FLOAT64_C(   653.32), SIMDE_FLOAT64_C(    69.82) },
      UINT8_C(  9),
      {  INT64_C(                 110),  INT64_C(                  23),  INT64_C(                 189),  INT64_C(                   3),
         INT64_C(                 202),  INT64_C(                  49),  INT64_C(                  97),  INT64_C(                  49) },
      { SIMDE_FLOAT64_C(   110.00), SIMDE_FLOAT64_C(   595.07), SIMDE_FLOAT64_C(   104.01), SIMDE_FLOAT64_C(     3.00),
        SIMDE_FLOAT64_C(   145.61), SIMDE_FLOAT64_C(  -578.55), SIMDE_FLOAT64_C(   653.32), SIMDE_FLOAT64_C(    69.82) } },
    { { SIMDE_FLOAT64_C(  -419.23), SIMDE_FLOAT64_C(   835.05), SIMDE_FLOAT64_C(  -150.23), SIMDE_FLOAT64_C(  -868.24),
        SIMDE_FLOAT64_C(   257.66), SIMDE_FLOAT64_C(   365.35), SIMDE_FLOAT64_C(  -922.40), SIMDE_FLOAT64_C(  -603.78) },
      UINT8_C( 90),
      {  INT64_C(                 236),  INT64_C(                 222),  INT64_C(                 201),  INT64_C(                  75),
         INT64_C(                 128),  INT64_C(                   8),  INT64_C(                 174),  INT64_C(                 162) },
      { SIMDE_FLOAT64_C(  -419.23), SIMDE_FLOAT64_C(   222.00), SIMDE_FLOAT64_C(  -150.23), SIMDE_FLOAT64_C(    75.00),
        SIMDE_FLOAT64_C(   128.00), SIMDE_FLOAT64_C(   365.35), SIMDE_FLOAT64_C(   174.00), SIMDE_FLOAT64_C(  -603.78) } },
    { { SIMDE_FLOAT64_C(  -592.47), SIMDE_FLOAT64_C(   118.51), SIMDE_FLOAT64_C(    27.94), SIMDE_FLOAT64_C(  -939.14),
        SIMDE_FLOAT64_C(  -811.67), SIMDE_FLOAT64_C(   157.88), SIMDE_FLOAT64_C(  -873.41), SIMDE_FLOAT64_C(  -707.13) },
      UINT8_C(205),
      {  INT64_C(                 199),  INT64_C(                 176),  INT64_C(                 254),  INT64_C(                  40),
         INT64_C(                 225),  INT64_C(                  90),  INT64_C(                 136),  INT64_C(                  28) },
      { SIMDE_FLOAT64_C(   199.00), SIMDE_FLOAT64_C(   118.51), SIMDE_FLOAT64_C(   254.00), SIMDE_FLOAT64_C(    40.00),
        SIMDE_FLOAT64_C(  -811.67), SIMDE_FLOAT64_C(   157.88), SIMDE_FLOAT64_C(   136.00), SIMDE_FLOAT64_C(    28.00) } },
    { { SIMDE_FLOAT64_C(   965.19), SIMDE_FLOAT64_C(   366.94), SIMDE_FLOAT64_C(  -823.55), SIMDE_FLOAT64_C(  -957.21),
        SIMDE_FLOAT64_C(   763.16), SIMDE_FLOAT64_C(   311.61), SIMDE_FLOAT64_C(  -249.66), SIMDE_FLOAT64_C(   230.41) },
      UINT8_C(149),
      {  INT64_C(                  75),  INT64_C(                 182),  INT64_C(                 158),  INT64_C(                 250),
         INT64_C(                  88),  INT64_C(                 199),  INT64_C(                 194),  INT64_C(                  94) },
      { SIMDE_FLOAT64_C(    75.00), SIMDE_FLOAT64_C(   366.94), SIMDE_FLOAT64_C(   158.00), SIMDE_FLOAT64_C(  -957.21),
        SIMDE_FLOAT64_C(    88.00), SIMDE_FLOAT64_C(   311.61), SIMDE_FLOAT64_C(  -249.66), SIMDE_FLOAT64_C(    94.00) } },
  };
  for (size_t i = 0 ; i < (sizeof(f64_buffer) / sizeof(f64_buffer[0])) ; i++) { f64_buffer[i] = HEDLEY_STATIC_CAST(simde_float64, i); }

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d src = simde_mm512_loadu_pd(test_vec[i].src);
    simde__m512i vindex = simde_mm512_loadu_epi64(test_vec[i].vindex);
    simde__m512d r = simde_mm512_mask_i64gather_pd(src, test_vec[i].k, vindex, f64_buffer, 8);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);

  for (size_t i = 0 ; i < (sizeof(f64_buffer) / sizeof(f64_buffer[0])) ; i++) { f64_buffer[i] = HEDLEY_STATIC_CAST(simde_float64, i); }

  for (int i = 0; i < 8; i++) {
    simde__m512d src = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i vindex = simde_mm512_set_epi64(
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int64_t, (simde_test_codegen_random_u8())));
    simde__m512d r = simde_mm512_mask_i64gather_pd(src, k, vindex, f64_buffer, 8);

    simde_test_x86_write_f64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, vindex, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_i32gather_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_i64gather_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_i64gather_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_i64gather_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_i64gather_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_i64gather_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_i64gather_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_i64gather_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_i64gather_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
