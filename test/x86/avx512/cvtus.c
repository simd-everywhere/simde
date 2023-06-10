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

#define SIMDE_TEST_X86_AVX512_INSN cvtus

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/cvtus.h>

static int
test_simde_mm512_mask_cvtusepi32_storeu_epi8(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    int8_t src[32];
    simde__mmask16 k;
    int32_t a[16];
    int8_t r[32];
  } test_vec[8] = {
    { {  INT8_C(  85), -INT8_C(  10),  INT8_C( 115), -INT8_C(   9), -INT8_C(  42), -INT8_C( 127),  INT8_C(  18), -INT8_C(  60),
         INT8_C(  44),  INT8_C(  72), -INT8_C(   8),  INT8_C(  57),  INT8_C(  31),  INT8_C(  33), -INT8_C(   3),  INT8_C( 102),
         INT8_C( 107),  INT8_C( 109), -INT8_C(  43),  INT8_C(  36), -INT8_C(  38), -INT8_C(  14),  INT8_C(   0), -INT8_C( 120),
        -INT8_C(  88), -INT8_C(  47), -INT8_C(  52), -INT8_C( 101), -INT8_C(  97),  INT8_C(  18),      INT8_MIN, -INT8_C(  12) },
      UINT16_C(62217),
      { -INT32_C(    42672149), -INT32_C(  1689869917), -INT32_C(   675453478), -INT32_C(  1589368629),  INT32_C(  1284710220),  INT32_C(  1931295911),  INT32_C(  1468382423), -INT32_C(  1672769872),
         INT32_C(   295288686),  INT32_C(  1001250656),  INT32_C(   269642309), -INT32_C(   558803054),  INT32_C(   489309558),  INT32_C(  1485850497), -INT32_C(  1280305917),  INT32_C(   307231652) },
      { -INT8_C(   1), -INT8_C(  10),  INT8_C( 115), -INT8_C(   1), -INT8_C(  42), -INT8_C( 127),  INT8_C(  18), -INT8_C(  60),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   8),  INT8_C(  57), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
         INT8_C( 107),  INT8_C( 109), -INT8_C(  43),  INT8_C(  36), -INT8_C(  38), -INT8_C(  14),  INT8_C(   0), -INT8_C( 120),
        -INT8_C(  88), -INT8_C(  47), -INT8_C(  52), -INT8_C( 101), -INT8_C(  97),  INT8_C(  18),      INT8_MIN, -INT8_C(  12) } },
    { { -INT8_C(  70), -INT8_C(  23),  INT8_C(  35),  INT8_C(  27), -INT8_C(  56), -INT8_C(  48),  INT8_C(  86),  INT8_C(  13),
         INT8_C(  58),  INT8_C( 104),  INT8_C(  30), -INT8_C(  52), -INT8_C(  65), -INT8_C(  49), -INT8_C(  86),  INT8_C(  53),
         INT8_C(  20), -INT8_C(  44),  INT8_C(  82), -INT8_C( 107),  INT8_C(  27), -INT8_C(  30), -INT8_C(  18),  INT8_C(  30),
        -INT8_C(   8), -INT8_C(  98), -INT8_C(  46), -INT8_C( 100), -INT8_C( 103),  INT8_C(  33), -INT8_C(  82),  INT8_C(  83) },
      UINT16_C(53514),
      { -INT32_C(   995962002), -INT32_C(    30548768),  INT32_C(  1406069929),  INT32_C(  1948836386),  INT32_C(  1716994936),  INT32_C(   872697698), -INT32_C(  1722442261),  INT32_C(  1600807152),
         INT32_C(   321063987), -INT32_C(  1844293399),  INT32_C(  1608900669),  INT32_C(   986910146), -INT32_C(  1281349039),  INT32_C(  1692902521),  INT32_C(   855456833), -INT32_C(   812554084) },
      { -INT8_C(  70), -INT8_C(   1),  INT8_C(  35), -INT8_C(   1), -INT8_C(  56), -INT8_C(  48),  INT8_C(  86),  INT8_C(  13),
        -INT8_C(   1),  INT8_C( 104),  INT8_C(  30), -INT8_C(  52), -INT8_C(   1), -INT8_C(  49), -INT8_C(   1), -INT8_C(   1),
         INT8_C(  20), -INT8_C(  44),  INT8_C(  82), -INT8_C( 107),  INT8_C(  27), -INT8_C(  30), -INT8_C(  18),  INT8_C(  30),
        -INT8_C(   8), -INT8_C(  98), -INT8_C(  46), -INT8_C( 100), -INT8_C( 103),  INT8_C(  33), -INT8_C(  82),  INT8_C(  83) } },
    { {  INT8_C( 116), -INT8_C(  76), -INT8_C(  29),  INT8_C(  93),  INT8_C(   5), -INT8_C(  11), -INT8_C(  17),  INT8_C(  66),
        -INT8_C(  43), -INT8_C(  43), -INT8_C(  95), -INT8_C( 105), -INT8_C(  30),  INT8_C( 116), -INT8_C(  46),  INT8_C(  51),
        -INT8_C(  97),  INT8_C( 114), -INT8_C(  26),  INT8_C(  24),  INT8_C(  23), -INT8_C(  51),  INT8_C( 125),  INT8_C(  88),
         INT8_C(  10),  INT8_C( 122), -INT8_C( 118), -INT8_C(  90), -INT8_C(  30),  INT8_C(  27),  INT8_C( 118),  INT8_C(  87) },
      UINT16_C(22992),
      { -INT32_C(  1538337356), -INT32_C(  1200020713), -INT32_C(  1943249990),  INT32_C(  1979698063),  INT32_C(  1631786724), -INT32_C(   103068306),  INT32_C(  1762967283), -INT32_C(   909974507),
        -INT32_C(   798158663), -INT32_C(   293018061), -INT32_C(   780487358),  INT32_C(  1682340224), -INT32_C(    20608625), -INT32_C(   889740842),  INT32_C(  1949502303), -INT32_C(  1455556880) },
      {  INT8_C( 116), -INT8_C(  76), -INT8_C(  29),  INT8_C(  93), -INT8_C(   1), -INT8_C(  11), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(  43), -INT8_C(  95), -INT8_C(   1), -INT8_C(   1),  INT8_C( 116), -INT8_C(   1),  INT8_C(  51),
        -INT8_C(  97),  INT8_C( 114), -INT8_C(  26),  INT8_C(  24),  INT8_C(  23), -INT8_C(  51),  INT8_C( 125),  INT8_C(  88),
         INT8_C(  10),  INT8_C( 122), -INT8_C( 118), -INT8_C(  90), -INT8_C(  30),  INT8_C(  27),  INT8_C( 118),  INT8_C(  87) } },
    { {  INT8_C(   6), -INT8_C(  85),  INT8_C( 122),  INT8_C(  58), -INT8_C( 111),  INT8_C(   2),  INT8_C(  40), -INT8_C(  45),
        -INT8_C(  73), -INT8_C(  94), -INT8_C(  92),  INT8_C(  56),  INT8_C(  28), -INT8_C(  21), -INT8_C( 100), -INT8_C(  85),
         INT8_C( 116),  INT8_C(  98), -INT8_C(  87),  INT8_C(  75),  INT8_C(   3), -INT8_C(  96),  INT8_C(  21),  INT8_C(  98),
        -INT8_C(  84),  INT8_C(  72), -INT8_C(  42), -INT8_C( 100),  INT8_C(  62),  INT8_C(  19),  INT8_C(  69),  INT8_C(  69) },
      UINT16_C(49086),
      { -INT32_C(  1480437633), -INT32_C(   934708957),  INT32_C(  1320379825), -INT32_C(  1162860783), -INT32_C(  2024033422), -INT32_C(   338688235), -INT32_C(   386003293), -INT32_C(   760693421),
         INT32_C(   813263373), -INT32_C(  1778859037),  INT32_C(   971221800),  INT32_C(  1173656531),  INT32_C(  1540181830), -INT32_C(   112812714), -INT32_C(     2014037),  INT32_C(   248613121) },
      {  INT8_C(   6), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(  40), -INT8_C(   1),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C( 100), -INT8_C(   1),
         INT8_C( 116),  INT8_C(  98), -INT8_C(  87),  INT8_C(  75),  INT8_C(   3), -INT8_C(  96),  INT8_C(  21),  INT8_C(  98),
        -INT8_C(  84),  INT8_C(  72), -INT8_C(  42), -INT8_C( 100),  INT8_C(  62),  INT8_C(  19),  INT8_C(  69),  INT8_C(  69) } },
    { { -INT8_C(  13),  INT8_C(  75),  INT8_C(  63), -INT8_C(  41),  INT8_C(  14),  INT8_C(  55),  INT8_C( 108),  INT8_C(  54),
        -INT8_C(  29),  INT8_C(  79),  INT8_C( 112), -INT8_C(  74), -INT8_C(  30),  INT8_C( 100), -INT8_C(   5),  INT8_C(  40),
        -INT8_C(  77), -INT8_C(  56), -INT8_C( 125),  INT8_C(   9),  INT8_C( 101), -INT8_C(  55),  INT8_C(   2),  INT8_C(  17),
         INT8_C(  13), -INT8_C(  29),  INT8_C(  16),  INT8_C(  15),  INT8_C( 109), -INT8_C(  31),  INT8_C(  29),  INT8_C(  96) },
      UINT16_C(23596),
      { -INT32_C(  1550566857), -INT32_C(   504203407),  INT32_C(   675664941),  INT32_C(  2146564348),  INT32_C(    55072257),  INT32_C(  2011584103), -INT32_C(  2108075163), -INT32_C(   337672780),
         INT32_C(   831484864),  INT32_C(   387088874),  INT32_C(  1379882838),  INT32_C(  1355952207), -INT32_C(   296543609), -INT32_C(   714720912),  INT32_C(  1096335245),  INT32_C(    70006596) },
      { -INT8_C(  13),  INT8_C(  75), -INT8_C(   1), -INT8_C(   1),  INT8_C(  14), -INT8_C(   1),  INT8_C( 108),  INT8_C(  54),
        -INT8_C(  29),  INT8_C(  79), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C( 100), -INT8_C(   1),  INT8_C(  40),
        -INT8_C(  77), -INT8_C(  56), -INT8_C( 125),  INT8_C(   9),  INT8_C( 101), -INT8_C(  55),  INT8_C(   2),  INT8_C(  17),
         INT8_C(  13), -INT8_C(  29),  INT8_C(  16),  INT8_C(  15),  INT8_C( 109), -INT8_C(  31),  INT8_C(  29),  INT8_C(  96) } },
    { { -INT8_C(  86), -INT8_C(  69),  INT8_C(  53), -INT8_C( 108),  INT8_C(  61),  INT8_C(  71), -INT8_C(  85), -INT8_C( 109),
        -INT8_C(  98), -INT8_C(  22), -INT8_C(  27), -INT8_C(  19),  INT8_C(  27), -INT8_C(  73),  INT8_C(  61), -INT8_C(  94),
        -INT8_C(  46), -INT8_C( 112), -INT8_C( 112),  INT8_C(  66), -INT8_C(  54), -INT8_C(  10),  INT8_C(  24),  INT8_C(  87),
        -INT8_C(  75),  INT8_C( 112), -INT8_C( 104), -INT8_C(   6), -INT8_C(  89), -INT8_C(  60), -INT8_C(   2),  INT8_C(  81) },
      UINT16_C(13440),
      { -INT32_C(  1870938651),  INT32_C(   897194576),  INT32_C(  1173198087), -INT32_C(   925515977),  INT32_C(   431922945), -INT32_C(  1903594250),  INT32_C(  1817391214),  INT32_C(  1721815937),
        -INT32_C(   520741744),  INT32_C(  1024815414),  INT32_C(  1048707590), -INT32_C(  1022994239), -INT32_C(   287521545), -INT32_C(  1501796808),  INT32_C(   403951510),  INT32_C(   847164322) },
      { -INT8_C(  86), -INT8_C(  69),  INT8_C(  53), -INT8_C( 108),  INT8_C(  61),  INT8_C(  71), -INT8_C(  85), -INT8_C(   1),
        -INT8_C(  98), -INT8_C(  22), -INT8_C(   1), -INT8_C(  19), -INT8_C(   1), -INT8_C(   1),  INT8_C(  61), -INT8_C(  94),
        -INT8_C(  46), -INT8_C( 112), -INT8_C( 112),  INT8_C(  66), -INT8_C(  54), -INT8_C(  10),  INT8_C(  24),  INT8_C(  87),
        -INT8_C(  75),  INT8_C( 112), -INT8_C( 104), -INT8_C(   6), -INT8_C(  89), -INT8_C(  60), -INT8_C(   2),  INT8_C(  81) } },
    { { -INT8_C(  49),  INT8_C( 117),  INT8_C(  18),  INT8_C(   5), -INT8_C(  26),  INT8_C(  40),  INT8_C(  67), -INT8_C(  20),
         INT8_C(  42), -INT8_C(  59),  INT8_C(  42), -INT8_C(  20),  INT8_C(  29),  INT8_C(  48), -INT8_C(  81),  INT8_C(  21),
        -INT8_C(  11), -INT8_C( 117),  INT8_C(   3),  INT8_C(  45), -INT8_C(  15),      INT8_MAX, -INT8_C(  44), -INT8_C( 120),
         INT8_C(  79), -INT8_C(  25), -INT8_C(  96), -INT8_C(  15), -INT8_C( 102),  INT8_C(  30),  INT8_C(  36),  INT8_C( 106) },
      UINT16_C(13971),
      { -INT32_C(  1302431377), -INT32_C(  1871148698),  INT32_C(   616666485), -INT32_C(  1380993366), -INT32_C(  1221746205), -INT32_C(   912360407), -INT32_C(  1847117459),  INT32_C(   315128739),
         INT32_C(  1522870004),  INT32_C(   619396527),  INT32_C(  2101914834),  INT32_C(  1160444002), -INT32_C(  1023584359),  INT32_C(  1099668435),  INT32_C(  2010280660), -INT32_C(   494232851) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(  18),  INT8_C(   5), -INT8_C(   1),  INT8_C(  40),  INT8_C(  67), -INT8_C(   1),
         INT8_C(  42), -INT8_C(   1), -INT8_C(   1), -INT8_C(  20), -INT8_C(   1), -INT8_C(   1), -INT8_C(  81),  INT8_C(  21),
        -INT8_C(  11), -INT8_C( 117),  INT8_C(   3),  INT8_C(  45), -INT8_C(  15),      INT8_MAX, -INT8_C(  44), -INT8_C( 120),
         INT8_C(  79), -INT8_C(  25), -INT8_C(  96), -INT8_C(  15), -INT8_C( 102),  INT8_C(  30),  INT8_C(  36),  INT8_C( 106) } },
    { { -INT8_C(  63),  INT8_C(  79),  INT8_C(  60),  INT8_C( 112), -INT8_C( 116),  INT8_C(  39), -INT8_C( 107),  INT8_C(  94),
        -INT8_C(  45), -INT8_C(  35), -INT8_C(  37),  INT8_C(  53), -INT8_C(  43),  INT8_C(   6),  INT8_C( 123),  INT8_C( 110),
         INT8_C(  93),  INT8_C( 120),  INT8_C(  48),  INT8_C(  49),  INT8_C(  19), -INT8_C(  69),  INT8_C( 114), -INT8_C(  24),
         INT8_C(  46),  INT8_C(  68),  INT8_C(  95),  INT8_C(  27), -INT8_C(  33), -INT8_C(  23), -INT8_C(   3), -INT8_C(  96) },
      UINT16_C(14904),
      { -INT32_C(  1520319472), -INT32_C(    24955613), -INT32_C(   452700054), -INT32_C(   144874809),  INT32_C(    95646099), -INT32_C(  1203117735), -INT32_C(    90035972), -INT32_C(   650847544),
        -INT32_C(  1031891553),  INT32_C(   901775818),  INT32_C(   555402586), -INT32_C(  1172801497),  INT32_C(  1119865833), -INT32_C(  1443231572), -INT32_C(   106718159),  INT32_C(   382916471) },
      { -INT8_C(  63),  INT8_C(  79),  INT8_C(  60), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C( 107),  INT8_C(  94),
        -INT8_C(  45), -INT8_C(   1), -INT8_C(  37), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C( 123),  INT8_C( 110),
         INT8_C(  93),  INT8_C( 120),  INT8_C(  48),  INT8_C(  49),  INT8_C(  19), -INT8_C(  69),  INT8_C( 114), -INT8_C(  24),
         INT8_C(  46),  INT8_C(  68),  INT8_C(  95),  INT8_C(  27), -INT8_C(  33), -INT8_C(  23), -INT8_C(   3), -INT8_C(  96) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    int8_t dst[32];
    simde_memcpy(dst, test_vec[i].src, sizeof(dst));
    simde_mm512_mask_cvtusepi32_storeu_epi8(dst, test_vec[i].k, a);
    simde_test_x86_assert_equal_i8x32(simde_mm256_loadu_epi8(dst), simde_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i8x32();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    int8_t r[32];
    simde_memcpy(r, &src, sizeof(r));
    simde_mm512_mask_cvtusepi32_storeu_epi8(r, k, a);

    simde_test_x86_write_i8x32(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, simde_mm256_loadu_epi8(r), SIMDE_TEST_VEC_POS_LAST);
  }

  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cvtusepi32_storeu_epi8)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
