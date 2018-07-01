/* Copyright (c) 2018 Evan Nemerson <evan@nemerson.com>
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
#include <simde/x86/avx2.h>

#include <stdio.h>

static MunitResult
test_simde_mm256_add_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C(  38), INT8_C(   7), INT8_C(  -2), INT8_C(  58),
                           INT8_C( 110), INT8_C( -99), INT8_C( -44), INT8_C(  54),
                           INT8_C(  -7), INT8_C(  11), INT8_C(  37), INT8_C(  89),
                           INT8_C(-116), INT8_C( -61), INT8_C( -62), INT8_C(-100),
                           INT8_C(  93), INT8_C(-106), INT8_C( -93), INT8_C( -65),
                           INT8_C(  41), INT8_C(  48), INT8_C( 119), INT8_C( -81),
                           INT8_C( 111), INT8_C(-127), INT8_C( -20), INT8_C(  49),
                           INT8_C( -86), INT8_C(  40), INT8_C(   8), INT8_C( -11)),
      simde_mm256_set_epi8(INT8_C(  39), INT8_C(  75), INT8_C(  21), INT8_C( -79),
                           INT8_C(  76), INT8_C( -46), INT8_C(  91), INT8_C(  40),
                           INT8_C(  97), INT8_C( -98), INT8_C( -82), INT8_C(  44),
                           INT8_C( -73), INT8_C( -89), INT8_C(-127), INT8_C( -32),
                           INT8_C( 120), INT8_C( 113), INT8_C( -53), INT8_C( -49),
                           INT8_C( -63), INT8_C(  81), INT8_C( -64), INT8_C(  90),
                           INT8_C( 100), INT8_C( -73), INT8_C( -51), INT8_C(-117),
                           INT8_C( -40), INT8_C(  69), INT8_C(-110), INT8_C( -48)),
      simde_mm256_set_epi8(INT8_C(  77), INT8_C(  82), INT8_C(  19), INT8_C( -21),
                           INT8_C( -70), INT8_C( 111), INT8_C(  47), INT8_C(  94),
                           INT8_C(  90), INT8_C( -87), INT8_C( -45), INT8_C(-123),
                           INT8_C(  67), INT8_C( 106), INT8_C(  67), INT8_C( 124),
                           INT8_C( -43), INT8_C(   7), INT8_C( 110), INT8_C(-114),
                           INT8_C( -22), INT8_C(-127), INT8_C(  55), INT8_C(   9),
                           INT8_C( -45), INT8_C(  56), INT8_C( -71), INT8_C( -68),
                           INT8_C(-126), INT8_C( 109), INT8_C(-102), INT8_C( -59)) },
    { simde_mm256_set_epi8(INT8_C(  71), INT8_C(   4), INT8_C(  70), INT8_C( -16),
                           INT8_C( -60), INT8_C( -69), INT8_C( -49), INT8_C( 108),
                           INT8_C( 108), INT8_C(  12), INT8_C(  69), INT8_C( -44),
                           INT8_C( 104), INT8_C(-122), INT8_C(  94), INT8_C( -44),
                           INT8_C(  20), INT8_C( -27), INT8_C(  55), INT8_C( 116),
                           INT8_C( 117), INT8_C(-108), INT8_C(  62), INT8_C(-118),
                           INT8_C(  86), INT8_C( -59), INT8_C(   3), INT8_C(  -3),
                           INT8_C( -82), INT8_C( 110), INT8_C(  88), INT8_C(  57)),
      simde_mm256_set_epi8(INT8_C( -80), INT8_C( 112), INT8_C(  78), INT8_C( -63),
                           INT8_C( 105), INT8_C(  59), INT8_C(  13), INT8_C( -94),
                           INT8_C( 116), INT8_C( -39), INT8_C(  42), INT8_C(  69),
                           INT8_C( 119), INT8_C(  -2), INT8_C( -96), INT8_C( -26),
                           INT8_C(  78), INT8_C(  -3), INT8_C( 125), INT8_C(  93),
                           INT8_C( -99), INT8_C( -92), INT8_C(  87), INT8_C( 115),
                           INT8_C( -58), INT8_C( 102), INT8_C(  77), INT8_C(  14),
                           INT8_C(-124), INT8_C(  69), INT8_C( 123), INT8_C(  22)),
      simde_mm256_set_epi8(INT8_C(  -9), INT8_C( 116), INT8_C(-108), INT8_C( -79),
                           INT8_C(  45), INT8_C( -10), INT8_C( -36), INT8_C(  14),
                           INT8_C( -32), INT8_C( -27), INT8_C( 111), INT8_C(  25),
                           INT8_C( -33), INT8_C(-124), INT8_C(  -2), INT8_C( -70),
                           INT8_C(  98), INT8_C( -30), INT8_C( -76), INT8_C( -47),
                           INT8_C(  18), INT8_C(  56), INT8_C(-107), INT8_C(  -3),
                           INT8_C(  28), INT8_C(  43), INT8_C(  80), INT8_C(  11),
                           INT8_C(  50), INT8_C( -77), INT8_C( -45), INT8_C(  79)) },
    { simde_mm256_set_epi8(INT8_C(  35), INT8_C(  50), INT8_C(-118), INT8_C( -51),
                           INT8_C( 104), INT8_C(  20), INT8_C( -38), INT8_C(-105),
                           INT8_C(  57), INT8_C(  19), INT8_C( -89), INT8_C( -46),
                           INT8_C(  27), INT8_C( -40), INT8_C(  -8), INT8_C( -54),
                           INT8_C(  74), INT8_C(-108), INT8_C( -11), INT8_C(  36),
                           INT8_C(  14), INT8_C(  26), INT8_C( -19), INT8_C( -47),
                           INT8_C(  70), INT8_C( -22), INT8_C(   1), INT8_C(  48),
                           INT8_C(-104), INT8_C(  96), INT8_C(  54), INT8_C( -65)),
      simde_mm256_set_epi8(INT8_C(  28), INT8_C( -52), INT8_C( 107), INT8_C(-103),
                           INT8_C( 110), INT8_C(  86), INT8_C(  60), INT8_C(   2),
                           INT8_C( -17), INT8_C(  30), INT8_C( -28), INT8_C( -92),
                           INT8_C(  93), INT8_C( 112), INT8_C( -31), INT8_C(  -9),
                           INT8_C(   8), INT8_C( -36), INT8_C( -58), INT8_C(-120),
                           INT8_C( -53), INT8_C(  26), INT8_C( -55), INT8_C( -73),
                           INT8_C(  20), INT8_C(  83), INT8_C( 124), INT8_C(  54),
                           INT8_C(  30), INT8_C( -54), INT8_C( -43), INT8_C(-123)),
      simde_mm256_set_epi8(INT8_C(  63), INT8_C(  -2), INT8_C( -11), INT8_C( 102),
                           INT8_C( -42), INT8_C( 106), INT8_C(  22), INT8_C(-103),
                           INT8_C(  40), INT8_C(  49), INT8_C(-117), INT8_C( 118),
                           INT8_C( 120), INT8_C(  72), INT8_C( -39), INT8_C( -63),
                           INT8_C(  82), INT8_C( 112), INT8_C( -69), INT8_C( -84),
                           INT8_C( -39), INT8_C(  52), INT8_C( -74), INT8_C(-120),
                           INT8_C(  90), INT8_C(  61), INT8_C( 125), INT8_C( 102),
                           INT8_C( -74), INT8_C(  42), INT8_C(  11), INT8_C(  68)) },
    { simde_mm256_set_epi8(INT8_C( -39), INT8_C( 114), INT8_C(  -7), INT8_C( 121),
                           INT8_C(  92), INT8_C(  79), INT8_C( 102), INT8_C(  76),
                           INT8_C( 109), INT8_C( -19), INT8_C(  70), INT8_C( -60),
                           INT8_C(  69), INT8_C( -31), INT8_C(  37), INT8_C(  40),
                           INT8_C( -46), INT8_C(  88), INT8_C( -21), INT8_C( -43),
                           INT8_C(  83), INT8_C(  14), INT8_C( -23), INT8_C( -33),
                           INT8_C(  86), INT8_C( -85), INT8_C(   8), INT8_C(  59),
                           INT8_C( 123), INT8_C(  93), INT8_C( -22), INT8_C(  26)),
      simde_mm256_set_epi8(INT8_C( 116), INT8_C( -91), INT8_C(  32), INT8_C( -33),
                           INT8_C(-123), INT8_C(-113), INT8_C(  98), INT8_C( -60),
                           INT8_C(-116), INT8_C( -75), INT8_C(  96), INT8_C(  10),
                           INT8_C( -53), INT8_C( -10), INT8_C( -80), INT8_C(-128),
                           INT8_C(  59), INT8_C( -73), INT8_C( -11), INT8_C(   8),
                           INT8_C(-127), INT8_C(-108), INT8_C(-124), INT8_C( 111),
                           INT8_C( -79), INT8_C(  28), INT8_C(  24), INT8_C(  40),
                           INT8_C(  40), INT8_C(  29), INT8_C( 119), INT8_C( 100)),
      simde_mm256_set_epi8(INT8_C(  77), INT8_C(  23), INT8_C(  25), INT8_C(  88),
                           INT8_C( -31), INT8_C( -34), INT8_C( -56), INT8_C(  16),
                           INT8_C(  -7), INT8_C( -94), INT8_C( -90), INT8_C( -50),
                           INT8_C(  16), INT8_C( -41), INT8_C( -43), INT8_C( -88),
                           INT8_C(  13), INT8_C(  15), INT8_C( -32), INT8_C( -35),
                           INT8_C( -44), INT8_C( -94), INT8_C( 109), INT8_C(  78),
                           INT8_C(   7), INT8_C( -57), INT8_C(  32), INT8_C(  99),
                           INT8_C( -93), INT8_C( 122), INT8_C(  97), INT8_C( 126)) },
    { simde_mm256_set_epi8(INT8_C(-108), INT8_C( -39), INT8_C( -41), INT8_C( 120),
                           INT8_C(-106), INT8_C( -66), INT8_C( -98), INT8_C( -12),
                           INT8_C(-106), INT8_C( -94), INT8_C( -31), INT8_C( -14),
                           INT8_C(  -2), INT8_C( -34), INT8_C( -30), INT8_C( -64),
                           INT8_C(  65), INT8_C(  50), INT8_C(  73), INT8_C( -32),
                           INT8_C( 106), INT8_C(-126), INT8_C(  67), INT8_C(  53),
                           INT8_C( 104), INT8_C(  17), INT8_C( -36), INT8_C(  95),
                           INT8_C(  57), INT8_C(  32), INT8_C( -59), INT8_C( -12)),
      simde_mm256_set_epi8(INT8_C(  29), INT8_C(  61), INT8_C( -31), INT8_C( 122),
                           INT8_C(   8), INT8_C( -70), INT8_C(  11), INT8_C(  62),
                           INT8_C( -73), INT8_C( -96), INT8_C( -10), INT8_C( -40),
                           INT8_C( -52), INT8_C( -38), INT8_C(  92), INT8_C(  51),
                           INT8_C(  35), INT8_C(  53), INT8_C(  88), INT8_C( -11),
                           INT8_C(  57), INT8_C(-113), INT8_C(-123), INT8_C( 106),
                           INT8_C(-110), INT8_C(-110), INT8_C(   2), INT8_C(  67),
                           INT8_C( -30), INT8_C( -96), INT8_C( -97), INT8_C( -86)),
      simde_mm256_set_epi8(INT8_C( -79), INT8_C(  22), INT8_C( -72), INT8_C( -14),
                           INT8_C( -98), INT8_C( 120), INT8_C( -87), INT8_C(  50),
                           INT8_C(  77), INT8_C(  66), INT8_C( -41), INT8_C( -54),
                           INT8_C( -54), INT8_C( -72), INT8_C(  62), INT8_C( -13),
                           INT8_C( 100), INT8_C( 103), INT8_C( -95), INT8_C( -43),
                           INT8_C( -93), INT8_C(  17), INT8_C( -56), INT8_C( -97),
                           INT8_C(  -6), INT8_C( -93), INT8_C( -34), INT8_C( -94),
                           INT8_C(  27), INT8_C( -64), INT8_C( 100), INT8_C( -98)) },
    { simde_mm256_set_epi8(INT8_C( -25), INT8_C( -91), INT8_C(  57), INT8_C( -61),
                           INT8_C(  27), INT8_C( -92), INT8_C(-114), INT8_C(-104),
                           INT8_C( 125), INT8_C( 120), INT8_C( -30), INT8_C(   8),
                           INT8_C(  88), INT8_C( -75), INT8_C( 100), INT8_C(  97),
                           INT8_C( -61), INT8_C( 122), INT8_C(  27), INT8_C( -70),
                           INT8_C( -30), INT8_C( -60), INT8_C( -90), INT8_C( -43),
                           INT8_C( -10), INT8_C( -38), INT8_C(  12), INT8_C(  90),
                           INT8_C(   1), INT8_C(  39), INT8_C( -80), INT8_C(  53)),
      simde_mm256_set_epi8(INT8_C( 121), INT8_C(  85), INT8_C(-111), INT8_C(-111),
                           INT8_C(  84), INT8_C(  54), INT8_C( -52), INT8_C( -62),
                           INT8_C( -55), INT8_C(  17), INT8_C(  68), INT8_C(  63),
                           INT8_C( 113), INT8_C( -67), INT8_C( -38), INT8_C(-118),
                           INT8_C(-104), INT8_C( -71), INT8_C(  55), INT8_C(  21),
                           INT8_C( -66), INT8_C(  19), INT8_C(-123), INT8_C(  95),
                           INT8_C( 118), INT8_C(  65), INT8_C( -70), INT8_C( -13),
                           INT8_C( 120), INT8_C( -27), INT8_C( -66), INT8_C( 122)),
      simde_mm256_set_epi8(INT8_C(  96), INT8_C(  -6), INT8_C( -54), INT8_C(  84),
                           INT8_C( 111), INT8_C( -38), INT8_C(  90), INT8_C(  90),
                           INT8_C(  70), INT8_C(-119), INT8_C(  38), INT8_C(  71),
                           INT8_C( -55), INT8_C( 114), INT8_C(  62), INT8_C( -21),
                           INT8_C(  91), INT8_C(  51), INT8_C(  82), INT8_C( -49),
                           INT8_C( -96), INT8_C( -41), INT8_C(  43), INT8_C(  52),
                           INT8_C( 108), INT8_C(  27), INT8_C( -58), INT8_C(  77),
                           INT8_C( 121), INT8_C(  12), INT8_C( 110), INT8_C( -81)) },
    { simde_mm256_set_epi8(INT8_C( 117), INT8_C( -64), INT8_C(  32), INT8_C( -52),
                           INT8_C(  16), INT8_C( -33), INT8_C(  14), INT8_C( -85),
                           INT8_C(   3), INT8_C( -57), INT8_C( -94), INT8_C( -41),
                           INT8_C( -98), INT8_C( 127), INT8_C(  42), INT8_C(  48),
                           INT8_C(  17), INT8_C( 106), INT8_C( -29), INT8_C( -56),
                           INT8_C(  75), INT8_C(-117), INT8_C( 106), INT8_C(  46),
                           INT8_C(-110), INT8_C( 123), INT8_C(  46), INT8_C(   8),
                           INT8_C(-118), INT8_C( 103), INT8_C(  19), INT8_C(  26)),
      simde_mm256_set_epi8(INT8_C(-123), INT8_C(  76), INT8_C( 117), INT8_C(  39),
                           INT8_C( 120), INT8_C( -11), INT8_C(  12), INT8_C( -12),
                           INT8_C( -32), INT8_C(   7), INT8_C(  13), INT8_C(  45),
                           INT8_C(  60), INT8_C( -83), INT8_C( -84), INT8_C( -17),
                           INT8_C( -88), INT8_C( -57), INT8_C( 102), INT8_C( -44),
                           INT8_C( 119), INT8_C(  16), INT8_C( 101), INT8_C( -86),
                           INT8_C(-106), INT8_C(-124), INT8_C(  83), INT8_C(-127),
                           INT8_C(  55), INT8_C( -92), INT8_C(  15), INT8_C(-114)),
      simde_mm256_set_epi8(INT8_C(  -6), INT8_C(  12), INT8_C(-107), INT8_C( -13),
                           INT8_C(-120), INT8_C( -44), INT8_C(  26), INT8_C( -97),
                           INT8_C( -29), INT8_C( -50), INT8_C( -81), INT8_C(   4),
                           INT8_C( -38), INT8_C(  44), INT8_C( -42), INT8_C(  31),
                           INT8_C( -71), INT8_C(  49), INT8_C(  73), INT8_C(-100),
                           INT8_C( -62), INT8_C(-101), INT8_C( -49), INT8_C( -40),
                           INT8_C(  40), INT8_C(  -1), INT8_C(-127), INT8_C(-119),
                           INT8_C( -63), INT8_C(  11), INT8_C(  34), INT8_C( -88)) },
    { simde_mm256_set_epi8(INT8_C(-111), INT8_C( -68), INT8_C( -72), INT8_C(-123),
                           INT8_C(  60), INT8_C(  19), INT8_C( -56), INT8_C( -34),
                           INT8_C(  75), INT8_C(-101), INT8_C(  82), INT8_C(  25),
                           INT8_C( 119), INT8_C(  87), INT8_C(  12), INT8_C( -81),
                           INT8_C( 120), INT8_C(  58), INT8_C(  77), INT8_C(-102),
                           INT8_C( -65), INT8_C(  14), INT8_C(  32), INT8_C(-111),
                           INT8_C(  72), INT8_C(  -1), INT8_C( 117), INT8_C(-104),
                           INT8_C(  81), INT8_C( -80), INT8_C( -43), INT8_C( -80)),
      simde_mm256_set_epi8(INT8_C( 114), INT8_C( -63), INT8_C(  59), INT8_C( -32),
                           INT8_C( 113), INT8_C(-103), INT8_C( -89), INT8_C( -53),
                           INT8_C( -11), INT8_C(  31), INT8_C(  71), INT8_C( -59),
                           INT8_C(  89), INT8_C(  28), INT8_C(  76), INT8_C(  62),
                           INT8_C(  13), INT8_C( 105), INT8_C( -93), INT8_C(  64),
                           INT8_C( -40), INT8_C(  38), INT8_C( -73), INT8_C(-114),
                           INT8_C(-121), INT8_C( -54), INT8_C(-113), INT8_C(   1),
                           INT8_C( -77), INT8_C( -55), INT8_C(  24), INT8_C( -16)),
      simde_mm256_set_epi8(INT8_C(   3), INT8_C( 125), INT8_C( -13), INT8_C( 101),
                           INT8_C( -83), INT8_C( -84), INT8_C( 111), INT8_C( -87),
                           INT8_C(  64), INT8_C( -70), INT8_C(-103), INT8_C( -34),
                           INT8_C( -48), INT8_C( 115), INT8_C(  88), INT8_C( -19),
                           INT8_C(-123), INT8_C( -93), INT8_C( -16), INT8_C( -38),
                           INT8_C(-105), INT8_C(  52), INT8_C( -41), INT8_C(  31),
                           INT8_C( -49), INT8_C( -55), INT8_C(   4), INT8_C(-103),
                           INT8_C(   4), INT8_C( 121), INT8_C( -19), INT8_C( -96)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_add_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_add_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi16(INT16_C(-12908), INT16_C(-15352), INT16_C( -9871), INT16_C( 11131),
                            INT16_C(-13055), INT16_C( 26967), INT16_C(-23057), INT16_C( 20309),
                            INT16_C(-12549), INT16_C(-20367), INT16_C(  6732), INT16_C( -7853),
                            INT16_C(-23923), INT16_C( -3719), INT16_C(-28976), INT16_C( 10001)),
      simde_mm256_set_epi16(INT16_C( 13883), INT16_C( 24989), INT16_C(-27634), INT16_C( 20264),
                            INT16_C( 15739), INT16_C(-13782), INT16_C( -2125), INT16_C(-14153),
                            INT16_C( -5381), INT16_C(-18938), INT16_C(-15901), INT16_C( -7111),
                            INT16_C(-11138), INT16_C( 23506), INT16_C( -6177), INT16_C(-29557)),
      simde_mm256_set_epi16(INT16_C(   975), INT16_C(  9637), INT16_C( 28031), INT16_C( 31395),
                            INT16_C(  2684), INT16_C( 13185), INT16_C(-25182), INT16_C(  6156),
                            INT16_C(-17930), INT16_C( 26231), INT16_C( -9169), INT16_C(-14964),
                            INT16_C( 30475), INT16_C( 19787), INT16_C( 30383), INT16_C(-19556)) },
    { simde_mm256_set_epi16(INT16_C(-20529), INT16_C(-26039), INT16_C( 27693), INT16_C(-13325),
                            INT16_C(-24443), INT16_C(-32106), INT16_C(-21283), INT16_C( -3709),
                            INT16_C(   747), INT16_C( 18820), INT16_C(-26624), INT16_C( 10967),
                            INT16_C( 25066), INT16_C( 19698), INT16_C(-32202), INT16_C(-11757)),
      simde_mm256_set_epi16(INT16_C( 10244), INT16_C(-18450), INT16_C(  5048), INT16_C( -3511),
                            INT16_C(-16723), INT16_C(-30842), INT16_C( 22572), INT16_C( -8065),
                            INT16_C( 30703), INT16_C(-26965), INT16_C( 23628), INT16_C(-27177),
                            INT16_C(-17808), INT16_C(-15958), INT16_C( 15529), INT16_C( 11766)),
      simde_mm256_set_epi16(INT16_C(-10285), INT16_C( 21047), INT16_C( 32741), INT16_C(-16836),
                            INT16_C( 24370), INT16_C(  2588), INT16_C(  1289), INT16_C(-11774),
                            INT16_C( 31450), INT16_C( -8145), INT16_C( -2996), INT16_C(-16210),
                            INT16_C(  7258), INT16_C(  3740), INT16_C(-16673), INT16_C(     9)) },
    { simde_mm256_set_epi16(INT16_C( 20347), INT16_C( 23946), INT16_C( 24055), INT16_C(  9643),
                            INT16_C( -2110), INT16_C(-31092), INT16_C(-13787), INT16_C( -6302),
                            INT16_C(  1396), INT16_C(  8481), INT16_C(-32148), INT16_C( 29268),
                            INT16_C( -9419), INT16_C( -3935), INT16_C( -1720), INT16_C(-10026)),
      simde_mm256_set_epi16(INT16_C( 15679), INT16_C( -2155), INT16_C( 32033), INT16_C( -2216),
                            INT16_C(-11561), INT16_C( 32737), INT16_C(-28164), INT16_C(  9867),
                            INT16_C( 17610), INT16_C(-22692), INT16_C(-28058), INT16_C(  7040),
                            INT16_C( 26754), INT16_C( -3306), INT16_C( -7351), INT16_C( 27370)),
      simde_mm256_set_epi16(INT16_C(-29510), INT16_C( 21791), INT16_C( -9448), INT16_C(  7427),
                            INT16_C(-13671), INT16_C(  1645), INT16_C( 23585), INT16_C(  3565),
                            INT16_C( 19006), INT16_C(-14211), INT16_C(  5330), INT16_C(-29228),
                            INT16_C( 17335), INT16_C( -7241), INT16_C( -9071), INT16_C( 17344)) },
    { simde_mm256_set_epi16(INT16_C(-27154), INT16_C(-23947), INT16_C(  1952), INT16_C(  7823),
                            INT16_C( 29492), INT16_C( -6766), INT16_C( 11046), INT16_C( 22007),
                            INT16_C( 15625), INT16_C( -6212), INT16_C( 31802), INT16_C( 17826),
                            INT16_C( 14647), INT16_C( 24188), INT16_C(-26765), INT16_C( 18766)),
      simde_mm256_set_epi16(INT16_C(-26373), INT16_C( 11481), INT16_C(-29646), INT16_C(-31758),
                            INT16_C(-13826), INT16_C( 16818), INT16_C( -2585), INT16_C(  3549),
                            INT16_C(   930), INT16_C(-29705), INT16_C(-19505), INT16_C(-18939),
                            INT16_C(-22195), INT16_C(  6794), INT16_C(  4204), INT16_C( 28707)),
      simde_mm256_set_epi16(INT16_C( 12009), INT16_C(-12466), INT16_C(-27694), INT16_C(-23935),
                            INT16_C( 15666), INT16_C( 10052), INT16_C(  8461), INT16_C( 25556),
                            INT16_C( 16555), INT16_C( 29619), INT16_C( 12297), INT16_C( -1113),
                            INT16_C( -7548), INT16_C( 30982), INT16_C(-22561), INT16_C(-18063)) },
    { simde_mm256_set_epi16(INT16_C( 30710), INT16_C( 24751), INT16_C( -4369), INT16_C( 18532),
                            INT16_C( 22682), INT16_C( 30280), INT16_C( 11292), INT16_C( 11710),
                            INT16_C(-17556), INT16_C( 10009), INT16_C(-27333), INT16_C( 22196),
                            INT16_C(-19056), INT16_C( -7837), INT16_C( 29666), INT16_C(  6547)),
      simde_mm256_set_epi16(INT16_C( -2566), INT16_C(  5814), INT16_C( 26818), INT16_C( 27091),
                            INT16_C(-10234), INT16_C( 23509), INT16_C( 13267), INT16_C( -7338),
                            INT16_C( 13949), INT16_C(  1472), INT16_C( 11063), INT16_C( -7215),
                            INT16_C( -8090), INT16_C(-23785), INT16_C(-15335), INT16_C(  4848)),
      simde_mm256_set_epi16(INT16_C( 28144), INT16_C( 30565), INT16_C( 22449), INT16_C(-19913),
                            INT16_C( 12448), INT16_C(-11747), INT16_C( 24559), INT16_C(  4372),
                            INT16_C( -3607), INT16_C( 11481), INT16_C(-16270), INT16_C( 14981),
                            INT16_C(-27146), INT16_C(-31622), INT16_C( 14331), INT16_C( 11395)) },
    { simde_mm256_set_epi16(INT16_C( 30207), INT16_C(-18325), INT16_C(  1180), INT16_C(-26389),
                            INT16_C( 14745), INT16_C(  7441), INT16_C(-23138), INT16_C(-20960),
                            INT16_C( 16686), INT16_C(-12834), INT16_C( -5724), INT16_C(  1237),
                            INT16_C( 12783), INT16_C( -1549), INT16_C(  7604), INT16_C(-25399)),
      simde_mm256_set_epi16(INT16_C( -5331), INT16_C(-23526), INT16_C( 14670), INT16_C(-15592),
                            INT16_C( 18159), INT16_C(  4760), INT16_C( 10369), INT16_C(-25724),
                            INT16_C(-28583), INT16_C( -6941), INT16_C(-17844), INT16_C(-14094),
                            INT16_C( 16769), INT16_C( 12540), INT16_C(-26071), INT16_C(  8463)),
      simde_mm256_set_epi16(INT16_C( 24876), INT16_C( 23685), INT16_C( 15850), INT16_C( 23555),
                            INT16_C(-32632), INT16_C( 12201), INT16_C(-12769), INT16_C( 18852),
                            INT16_C(-11897), INT16_C(-19775), INT16_C(-23568), INT16_C(-12857),
                            INT16_C( 29552), INT16_C( 10991), INT16_C(-18467), INT16_C(-16936)) },
    { simde_mm256_set_epi16(INT16_C( 28357), INT16_C( 20172), INT16_C( 17421), INT16_C(-11866),
                            INT16_C(-11434), INT16_C( 24363), INT16_C( 30807), INT16_C( -1507),
                            INT16_C(-31442), INT16_C( 25409), INT16_C( 25186), INT16_C( 22807),
                            INT16_C(-13333), INT16_C(-32257), INT16_C(-15570), INT16_C(  2752)),
      simde_mm256_set_epi16(INT16_C(-19799), INT16_C(-19809), INT16_C(-16948), INT16_C( -1715),
                            INT16_C( 29345), INT16_C(-32027), INT16_C(  5007), INT16_C(  4903),
                            INT16_C( -2392), INT16_C(-30038), INT16_C( 23207), INT16_C(-24060),
                            INT16_C( 29275), INT16_C( 13317), INT16_C( 26431), INT16_C( 23940)),
      simde_mm256_set_epi16(INT16_C(  8558), INT16_C(   363), INT16_C(   473), INT16_C(-13581),
                            INT16_C( 17911), INT16_C( -7664), INT16_C(-29722), INT16_C(  3396),
                            INT16_C( 31702), INT16_C( -4629), INT16_C(-17143), INT16_C( -1253),
                            INT16_C( 15942), INT16_C(-18940), INT16_C( 10861), INT16_C( 26692)) },
    { simde_mm256_set_epi16(INT16_C(  6003), INT16_C( 21193), INT16_C( 27446), INT16_C( 12164),
                            INT16_C(-15839), INT16_C(-27621), INT16_C( 27366), INT16_C(  3166),
                            INT16_C(-14586), INT16_C( 16192), INT16_C( 17380), INT16_C(  2397),
                            INT16_C( 17243), INT16_C(  7969), INT16_C(-18393), INT16_C(-28306)),
      simde_mm256_set_epi16(INT16_C( -9798), INT16_C(  1801), INT16_C(-11340), INT16_C(-25270),
                            INT16_C( -7120), INT16_C( -2660), INT16_C( 23941), INT16_C( 18110),
                            INT16_C( -3348), INT16_C( -5762), INT16_C( 30271), INT16_C(  3473),
                            INT16_C( -7979), INT16_C( -3070), INT16_C( 12208), INT16_C( 30362)),
      simde_mm256_set_epi16(INT16_C( -3795), INT16_C( 22994), INT16_C( 16106), INT16_C(-13106),
                            INT16_C(-22959), INT16_C(-30281), INT16_C(-14229), INT16_C( 21276),
                            INT16_C(-17934), INT16_C( 10430), INT16_C(-17885), INT16_C(  5870),
                            INT16_C(  9264), INT16_C(  4899), INT16_C( -6185), INT16_C(  2056)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_add_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_add_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( 1102687755), INT32_C( 1275949869), INT32_C( -388043296), INT32_C( 1616523445),
                            INT32_C( -312991452), INT32_C(-1980926618), INT32_C( 1274012126), INT32_C(  -45808693)),
      simde_mm256_set_epi32(INT32_C(-1821401638), INT32_C( 1143218625), INT32_C(-1072188421), INT32_C( -228883992),
                            INT32_C( 1453787917), INT32_C(-1686415046), INT32_C(-1856178723), INT32_C(-1344248495)),
      simde_mm256_set_epi32(INT32_C( -718713883), INT32_C(-1875798802), INT32_C(-1460231717), INT32_C( 1387639453),
                            INT32_C( 1140796465), INT32_C(  627625632), INT32_C( -582166597), INT32_C(-1390057188)) },
    { simde_mm256_set_epi32(INT32_C( -511556352), INT32_C(  512138684), INT32_C( 2115720361), INT32_C( -345092241),
                            INT32_C( -115713034), INT32_C( 1435785542), INT32_C( -578341737), INT32_C(  626663856)),
      simde_mm256_set_epi32(INT32_C( 1905028737), INT32_C(  164639990), INT32_C(-1952346601), INT32_C( 1853095591),
                            INT32_C(-1825217200), INT32_C(-1102744367), INT32_C(-1105586227), INT32_C(-1908622941)),
      simde_mm256_set_epi32(INT32_C( 1393472385), INT32_C(  676778674), INT32_C(  163373760), INT32_C( 1508003350),
                            INT32_C(-1940930234), INT32_C(  333041175), INT32_C(-1683927964), INT32_C(-1281959085)) },
    { simde_mm256_set_epi32(INT32_C(  841608097), INT32_C(-2001797484), INT32_C(-1658305288), INT32_C(  966942303),
                            INT32_C(  842108123), INT32_C(  697774066), INT32_C(-1273233002), INT32_C( -331057125)),
      simde_mm256_set_epi32(INT32_C(  824745259), INT32_C( 1162513122), INT32_C( 1536105364), INT32_C( 1572988069),
                            INT32_C( 1601630355), INT32_C(  105174023), INT32_C( -548723565), INT32_C(  342919548)),
      simde_mm256_set_epi32(INT32_C( 1666353356), INT32_C( -839284362), INT32_C( -122199924), INT32_C(-1755036924),
                            INT32_C(-1851228818), INT32_C(  802948089), INT32_C(-1821956567), INT32_C(   11862423)) },
    { simde_mm256_set_epi32(INT32_C(-1982661498), INT32_C( -454967885), INT32_C( 1606399367), INT32_C( 1911771725),
                            INT32_C( -320200723), INT32_C( 2055189331), INT32_C( 1782567162), INT32_C(  617047003)),
      simde_mm256_set_epi32(INT32_C(-1988185598), INT32_C( 1350171177), INT32_C( -741176174), INT32_C( 1024642864),
                            INT32_C( 1174775607), INT32_C(-1489493977), INT32_C( 2114610376), INT32_C(-1150946108)),
      simde_mm256_set_epi32(INT32_C(  324120200), INT32_C(  895203292), INT32_C(  865223193), INT32_C(-1358552707),
                            INT32_C(  854574884), INT32_C(  565695354), INT32_C( -397789758), INT32_C( -533899105)) },
    { simde_mm256_set_epi32(INT32_C(-1636237507), INT32_C(-2022044523), INT32_C( 1298417038), INT32_C( -498789244),
                            INT32_C(-1120565370), INT32_C(  -10552717), INT32_C( 1267811859), INT32_C( 1736112342)),
      simde_mm256_set_epi32(INT32_C(   30746202), INT32_C( 1464439343), INT32_C( 1694184093), INT32_C(-1066802952),
                            INT32_C( -664495133), INT32_C(-2016253412), INT32_C(-1975304715), INT32_C(  -70672826)),
      simde_mm256_set_epi32(INT32_C(-1605491305), INT32_C( -557605180), INT32_C(-1302366165), INT32_C(-1565592196),
                            INT32_C(-1785060503), INT32_C(-2026806129), INT32_C( -707492856), INT32_C( 1665439516)) },
    { simde_mm256_set_epi32(INT32_C(  289000373), INT32_C( 1573632519), INT32_C(  -39248751), INT32_C( -989305129),
                            INT32_C( -946333511), INT32_C( -275686449), INT32_C(  -98660627), INT32_C(-1519479102)),
      simde_mm256_set_epi32(INT32_C(  297476793), INT32_C(  436731799), INT32_C(  124294563), INT32_C(-1635813332),
                            INT32_C(  263383074), INT32_C( -533172755), INT32_C( 1125990821), INT32_C( -786980387)),
      simde_mm256_set_epi32(INT32_C(  586477166), INT32_C( 2010364318), INT32_C(   85045812), INT32_C( 1669848835),
                            INT32_C( -682950437), INT32_C( -808859204), INT32_C( 1027330194), INT32_C( 1988507807)) },
    { simde_mm256_set_epi32(INT32_C(  518182194), INT32_C(-1204047142), INT32_C(  -66070725), INT32_C(  499109808),
                            INT32_C(-2041576579), INT32_C( -621515360), INT32_C(  566201077), INT32_C(  301667364)),
      simde_mm256_set_epi32(INT32_C(-1846226401), INT32_C(-1479610627), INT32_C( -205605694), INT32_C( 2074175879),
                            INT32_C(  797873427), INT32_C(  232260429), INT32_C( 2122451120), INT32_C(-1502060759)),
      simde_mm256_set_epi32(INT32_C(-1328044207), INT32_C( 1611309527), INT32_C( -271676419), INT32_C(-1721681609),
                            INT32_C(-1243703152), INT32_C( -389254931), INT32_C(-1606315099), INT32_C(-1200393395)) },
    { simde_mm256_set_epi32(INT32_C(  405834501), INT32_C(-1910761465), INT32_C(  957239954), INT32_C( -786856288),
                            INT32_C(  843920617), INT32_C(  327146567), INT32_C( -333483012), INT32_C(-1269489720)),
      simde_mm256_set_epi32(INT32_C( -343554450), INT32_C( -768698719), INT32_C(-1629325598), INT32_C(  -86112156),
                            INT32_C(-1762054840), INT32_C(-1230219631), INT32_C(-1955142376), INT32_C(  681367456)),
      simde_mm256_set_epi32(INT32_C(   62280051), INT32_C( 1615507112), INT32_C( -672085644), INT32_C( -872968444),
                            INT32_C( -918134223), INT32_C( -903073064), INT32_C( 2006341908), INT32_C( -588122264)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_add_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_add_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C( -919395005897301486), INT64_C( -150854599157471417),
                             INT64_C( 8808382520295569970), INT64_C(-2573562509116397532)),
      simde_mm256_set_epi64x(INT64_C( 3276842246935198107), INT64_C(  509596195322373870),
                             INT64_C( 5497236691336464382), INT64_C( 7792219835689675301)),
      simde_mm256_set_epi64x(INT64_C( 2357447241037896621), INT64_C(  358741596164902453),
                             INT64_C(-4141124862077517264), INT64_C( 5218657326573277769)) },
    { simde_mm256_set_epi64x(INT64_C(-8319032728400165160), INT64_C( 5761166475766138642),
                             INT64_C( 1889840457419449714), INT64_C(-7866468136110945528)),
      simde_mm256_set_epi64x(INT64_C(-7943707797090752726), INT64_C(-3031420544278169311),
                             INT64_C( -274806827926037798), INT64_C(-6305854756278616306)),
      simde_mm256_set_epi64x(INT64_C( 2184003548218633730), INT64_C( 2729745931487969331),
                             INT64_C( 1615033629493411916), INT64_C( 4274421181319989782)) },
    { simde_mm256_set_epi64x(INT64_C( 5895960517559859999), INT64_C( 6208968053276251170),
                             INT64_C( 7761614749466428803), INT64_C(-6998556565488043930)),
      simde_mm256_set_epi64x(INT64_C(-7645095141522766353), INT64_C( 7326575676453958933),
                             INT64_C( 1354311398343021783), INT64_C( 5074528974494991107)),
      simde_mm256_set_epi64x(INT64_C(-1749134623962906354), INT64_C(-4911200343979341513),
                             INT64_C( 9115926147809450586), INT64_C(-1924027590993052823)) },
    { simde_mm256_set_epi64x(INT64_C( 7265152682832433510), INT64_C(-3085894531646767861),
                             INT64_C(-9131129251692740054), INT64_C(  -13949299420174832)),
      simde_mm256_set_epi64x(INT64_C(-8945299951793325147), INT64_C( 1105999600596947619),
                             INT64_C( 1005965954309535795), INT64_C( 6577596548744990052)),
      simde_mm256_set_epi64x(INT64_C(-1680147268960891637), INT64_C(-1979894931049820242),
                             INT64_C(-8125163297383204259), INT64_C( 6563647249324815220)) },
    { simde_mm256_set_epi64x(INT64_C(-1757821625677084255), INT64_C(-2404608367637526264),
                             INT64_C(  707296317246937957), INT64_C(-8620111396460581683)),
      simde_mm256_set_epi64x(INT64_C(-3596883371125205809), INT64_C( 2676371285603083419),
                             INT64_C( 6821095199901887872), INT64_C(-7512247745220049837)),
      simde_mm256_set_epi64x(INT64_C(-5354704996802290064), INT64_C(  271762917965557155),
                             INT64_C( 7528391517148825829), INT64_C( 2314384932028920096)) },
    { simde_mm256_set_epi64x(INT64_C( 6839811261830973327), INT64_C( 5631394124827236824),
                             INT64_C(-5955019407573777834), INT64_C(-3458836099791348328)),
      simde_mm256_set_epi64x(INT64_C( 7744082525445212477), INT64_C(-8800502010596219205),
                             INT64_C(  384951712332227405), INT64_C(  430518285591300198)),
      simde_mm256_set_epi64x(INT64_C(-3862850286433365812), INT64_C(-3169107885768982381),
                             INT64_C(-5570067695241550429), INT64_C(-3028317814200048130)) },
    { simde_mm256_set_epi64x(INT64_C(-3472881623031498101), INT64_C(-1430648476837955016),
                             INT64_C(-3715397159055217239), INT64_C( 5273106926976979674)),
      simde_mm256_set_epi64x(INT64_C(-4550310691059172162), INT64_C( 3088580064706171589),
                             INT64_C( 5815698628016314327), INT64_C(-8735000016575196569)),
      simde_mm256_set_epi64x(INT64_C(-8023192314090670263), INT64_C( 1657931587868216573),
                             INT64_C( 2100301468961097088), INT64_C(-3461893089598216895)) },
    { simde_mm256_set_epi64x(INT64_C(-8609934348254886079), INT64_C( 4626495260054383935),
                             INT64_C(-1742895605763712389), INT64_C( 8190624861564512538)),
      simde_mm256_set_epi64x(INT64_C(-1653872282243675761), INT64_C(-8277823144431279152),
                             INT64_C( 5269960775097450688), INT64_C( 3526432474948394359)),
      simde_mm256_set_epi64x(INT64_C( 8182937443210989776), INT64_C(-3651327884376895217),
                             INT64_C( 3527065169333738299), INT64_C(-6729686737196644719)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_add_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_and_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C( 8722470578646828517), INT64_C(  891261850847437783),
                             INT64_C( 8698554819020653857), INT64_C(-7282900013878242954)),
      simde_mm256_set_epi64x(INT64_C(-8128142018056442141), INT64_C( 5559182722028422309),
                             INT64_C( 2093267872519066825), INT64_C(-7117023562774970023)),
      simde_mm256_set_epi64x(INT64_C(  648519197013312737), INT64_C(  866420841735143557),
                             INT64_C( 1730587322060899329), INT64_C(-7482378910948097712)) },
    { simde_mm256_set_epi64x(INT64_C(-2297219683620407228), INT64_C(-2314825045857877411),
                             INT64_C(-2223407797787304327), INT64_C( 5408595704702705619)),
      simde_mm256_set_epi64x(INT64_C( 1902387556947256757), INT64_C(-4636290958455233996),
                             INT64_C( -193279292138890017), INT64_C( 2387678637527501964)),
      simde_mm256_set_epi64x(INT64_C(    1867272746704900), INT64_C(-6944527661819330028),
                             INT64_C(-2233693047608222631), INT64_C(   72674428659436672)) },
    { simde_mm256_set_epi64x(INT64_C(-8083909718117301567), INT64_C(   11995607010100125),
                             INT64_C(-6068617776224060223), INT64_C(-6387203967446836987)),
      simde_mm256_set_epi64x(INT64_C(-8320376883848651160), INT64_C(-4950145821323384534),
                             INT64_C(-7969688999974624617), INT64_C(  659904372446782737)),
      simde_mm256_set_epi64x(INT64_C(-8322647438183611840), INT64_C(    2406350531494152),
                             INT64_C(-9131628786599059327), INT64_C(   74330855942160641)) },
    { simde_mm256_set_epi64x(INT64_C(-7862557356832127783), INT64_C(-5197238245936512816),
                             INT64_C(-1440736387308233171), INT64_C( -422437923560182700)),
      simde_mm256_set_epi64x(INT64_C( 4501573497311276896), INT64_C( 1568099047173454230),
                             INT64_C( 6784671475384752865), INT64_C(-5901872067663085826)),
      simde_mm256_set_epi64x(INT64_C( 1324204786773460032), INT64_C( 1568098471546732688),
                             INT64_C( 5476791399028365857), INT64_C(-6196932668584612780)) },
    { simde_mm256_set_epi64x(INT64_C(  -83457062575009429), INT64_C(-7222721162513873213),
                             INT64_C( 8275972355230696496), INT64_C( 5685146925209815999)),
      simde_mm256_set_epi64x(INT64_C( 7621095561231011691), INT64_C(-1384347240916299959),
                             INT64_C( 8784701942784527649), INT64_C(-6329984144489188000)),
      simde_mm256_set_epi64x(INT64_C( 7549018173429252459), INT64_C(-8592431562369268159),
                             INT64_C( 8126746635764630560), INT64_C(  586910516468318496)) },
    { simde_mm256_set_epi64x(INT64_C( 5973184558080946927), INT64_C(-1786695518880322601),
                             INT64_C(  564422817571527071), INT64_C( 4038585732338755869)),
      simde_mm256_set_epi64x(INT64_C(-8901168232869945121), INT64_C( 8118630853720063073),
                             INT64_C( -228868271804772649), INT64_C(-6456700929251086932)),
      simde_mm256_set_epi64x(INT64_C(   27024505729917135), INT64_C( 6926573216261613633),
                             INT64_C(  346814025888696471), INT64_C( 2306177340255840524)) },
    { simde_mm256_set_epi64x(INT64_C( 4967668340414178010), INT64_C(-2410168209476403592),
                             INT64_C(-3019436090811439415), INT64_C(-6965119139859890192)),
      simde_mm256_set_epi64x(INT64_C(-5120337331222163918), INT64_C(-1589564432494918546),
                             INT64_C( 5292723257474752308), INT64_C( 2511807878775255697)),
      simde_mm256_set_epi64x(INT64_C(   67729921108361746), INT64_C(-3999169530918599576),
                             INT64_C( 4616337787987166720), INT64_C(  167381957966049936)) },
    { simde_mm256_set_epi64x(INT64_C(-6179811667909625694), INT64_C(-2471055444546593648),
                             INT64_C( 7540412455883833292), INT64_C( 6654843089135720963)),
      simde_mm256_set_epi64x(INT64_C( -939588147635733509), INT64_C(-1340596046637757449),
                             INT64_C(-1662948605324253370), INT64_C(  817158485966988858)),
      simde_mm256_set_epi64x(INT64_C(-6758530821969135454), INT64_C(-3664509346923870064),
                             INT64_C( 7540157231680104260), INT64_C(  599541701488411138)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_and_si256(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_broadcastsi128_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm_set_epi64x   (INT64_C( 3783485884510153131), INT64_C( 5322848723863790661)),
      simde_mm256_set_epi64x(INT64_C( 3783485884510153131), INT64_C( 5322848723863790661),
                             INT64_C( 3783485884510153131), INT64_C( 5322848723863790661)) },
    { simde_mm_set_epi64x   (INT64_C( 3709494745882156155), INT64_C(-6688158465955285293)),
      simde_mm256_set_epi64x(INT64_C( 3709494745882156155), INT64_C(-6688158465955285293),
                             INT64_C( 3709494745882156155), INT64_C(-6688158465955285293)) },
    { simde_mm_set_epi64x   (INT64_C(-8419237038829073489), INT64_C(-1707044583358729761)),
      simde_mm256_set_epi64x(INT64_C(-8419237038829073489), INT64_C(-1707044583358729761),
                             INT64_C(-8419237038829073489), INT64_C(-1707044583358729761)) },
    { simde_mm_set_epi64x   (INT64_C( -168447772491176834), INT64_C(-4784151950425519944)),
      simde_mm256_set_epi64x(INT64_C( -168447772491176834), INT64_C(-4784151950425519944),
                             INT64_C( -168447772491176834), INT64_C(-4784151950425519944)) },
    { simde_mm_set_epi64x   (INT64_C(  992172666234330248), INT64_C( 7115358650695109080)),
      simde_mm256_set_epi64x(INT64_C(  992172666234330248), INT64_C( 7115358650695109080),
                             INT64_C(  992172666234330248), INT64_C( 7115358650695109080)) },
    { simde_mm_set_epi64x   (INT64_C( 6019682307676879898), INT64_C( -745177675559433697)),
      simde_mm256_set_epi64x(INT64_C( 6019682307676879898), INT64_C( -745177675559433697),
                             INT64_C( 6019682307676879898), INT64_C( -745177675559433697)) },
    { simde_mm_set_epi64x   (INT64_C(-8364368011425569946), INT64_C( 1685080214233190853)),
      simde_mm256_set_epi64x(INT64_C(-8364368011425569946), INT64_C( 1685080214233190853),
                             INT64_C(-8364368011425569946), INT64_C( 1685080214233190853)) },
    { simde_mm_set_epi64x   (INT64_C( 6712859087758853138), INT64_C( 2170550621944299043)),
      simde_mm256_set_epi64x(INT64_C( 6712859087758853138), INT64_C( 2170550621944299043),
                             INT64_C( 6712859087758853138), INT64_C( 2170550621944299043)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_broadcastsi128_si256(test_vec[i].a);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_shuffle_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_x_mm256_set_epu8(UINT8_C(132), UINT8_C(100), UINT8_C(115), UINT8_C( 94),
                             UINT8_C( 73), UINT8_C(247), UINT8_C(104), UINT8_C(220),
                             UINT8_C(117), UINT8_C( 74), UINT8_C( 39), UINT8_C(125),
                             UINT8_C( 51), UINT8_C( 55), UINT8_C(148), UINT8_C(183),
                             UINT8_C(  5), UINT8_C(228), UINT8_C( 33), UINT8_C( 72),
                             UINT8_C( 84), UINT8_C(  4), UINT8_C(172), UINT8_C(134),
                             UINT8_C( 26), UINT8_C(247), UINT8_C(250), UINT8_C(  1),
                             UINT8_C(220), UINT8_C( 43), UINT8_C( 83), UINT8_C(118)),
      simde_x_mm256_set_epu8(UINT8_C( 24), UINT8_C(160), UINT8_C( 38), UINT8_C(201),
                             UINT8_C(108), UINT8_C( 32), UINT8_C( 93), UINT8_C( 16),
                             UINT8_C(104), UINT8_C(146), UINT8_C(128), UINT8_C(127),
                             UINT8_C(240), UINT8_C(187), UINT8_C(163), UINT8_C( 93),
                             UINT8_C(161), UINT8_C(148), UINT8_C(236), UINT8_C(208),
                             UINT8_C(110), UINT8_C( 19), UINT8_C(  3), UINT8_C(142),
                             UINT8_C( 56), UINT8_C( 74), UINT8_C(  2), UINT8_C(168),
                             UINT8_C(100), UINT8_C(209), UINT8_C( 27), UINT8_C( 46)),
      simde_x_mm256_set_epu8(UINT8_C(220), UINT8_C(  0), UINT8_C( 74), UINT8_C(  0),
                             UINT8_C( 94), UINT8_C(183), UINT8_C(115), UINT8_C(183),
                             UINT8_C(220), UINT8_C(  0), UINT8_C(  0), UINT8_C(132),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(115),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(228), UINT8_C(220), UINT8_C(220), UINT8_C(  0),
                             UINT8_C(134), UINT8_C(  4), UINT8_C( 43), UINT8_C(  0),
                             UINT8_C(  1), UINT8_C(  0), UINT8_C( 84), UINT8_C(228)) },
    { simde_x_mm256_set_epu8(UINT8_C( 53), UINT8_C(227), UINT8_C(193), UINT8_C(203),
                             UINT8_C(188), UINT8_C( 31), UINT8_C(134), UINT8_C(151),
                             UINT8_C( 90), UINT8_C(227), UINT8_C(228), UINT8_C( 42),
                             UINT8_C(223), UINT8_C( 71), UINT8_C( 37), UINT8_C(166),
                             UINT8_C(115), UINT8_C( 13), UINT8_C(136), UINT8_C( 67),
                             UINT8_C(142), UINT8_C( 55), UINT8_C(218), UINT8_C(135),
                             UINT8_C(160), UINT8_C(121), UINT8_C(105), UINT8_C(225),
                             UINT8_C( 67), UINT8_C(106), UINT8_C( 80), UINT8_C(187)),
      simde_x_mm256_set_epu8(UINT8_C(139), UINT8_C(207), UINT8_C(188), UINT8_C(170),
                             UINT8_C(232), UINT8_C(172), UINT8_C( 51), UINT8_C( 14),
                             UINT8_C( 50), UINT8_C(186), UINT8_C( 76), UINT8_C(187),
                             UINT8_C( 22), UINT8_C( 90), UINT8_C(150), UINT8_C(148),
                             UINT8_C(123), UINT8_C( 36), UINT8_C(145), UINT8_C( 72),
                             UINT8_C(252), UINT8_C(171), UINT8_C(109), UINT8_C( 77),
                             UINT8_C(145), UINT8_C( 77), UINT8_C(121), UINT8_C(107),
                             UINT8_C(138), UINT8_C(154), UINT8_C(236), UINT8_C( 13)),
      simde_x_mm256_set_epu8(UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(223), UINT8_C(227),
                             UINT8_C( 71), UINT8_C(  0), UINT8_C(203), UINT8_C(  0),
                             UINT8_C(227), UINT8_C( 31), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(142), UINT8_C(225), UINT8_C(  0), UINT8_C(135),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(136), UINT8_C(136),
                             UINT8_C(  0), UINT8_C(136), UINT8_C(218), UINT8_C(142),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(136)) },
    { simde_x_mm256_set_epu8(UINT8_C(147), UINT8_C(175), UINT8_C(103), UINT8_C(105),
                             UINT8_C(115), UINT8_C( 25), UINT8_C( 88), UINT8_C( 95),
                             UINT8_C(108), UINT8_C(195), UINT8_C( 30), UINT8_C( 32),
                             UINT8_C(183), UINT8_C(198), UINT8_C(177), UINT8_C( 61),
                             UINT8_C(213), UINT8_C(  7), UINT8_C(150), UINT8_C(186),
                             UINT8_C( 52), UINT8_C(  9), UINT8_C( 76), UINT8_C(240),
                             UINT8_C(240), UINT8_C(126), UINT8_C(242), UINT8_C(203),
                             UINT8_C(162), UINT8_C( 72), UINT8_C(186), UINT8_C( 35)),
      simde_x_mm256_set_epu8(UINT8_C( 26), UINT8_C(  1), UINT8_C(253), UINT8_C(220),
                             UINT8_C(156), UINT8_C(126), UINT8_C(237), UINT8_C(228),
                             UINT8_C(210), UINT8_C( 82), UINT8_C(  8), UINT8_C(  8),
                             UINT8_C(104), UINT8_C( 35), UINT8_C( 98), UINT8_C( 24),
                             UINT8_C(230), UINT8_C(227), UINT8_C( 73), UINT8_C(233),
                             UINT8_C(132), UINT8_C( 49), UINT8_C( 63), UINT8_C(172),
                             UINT8_C(137), UINT8_C( 87), UINT8_C( 85), UINT8_C(128),
                             UINT8_C(136), UINT8_C(108), UINT8_C( 70), UINT8_C(218)),
      simde_x_mm256_set_epu8(UINT8_C( 25), UINT8_C(177), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(175), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(198), UINT8_C( 95), UINT8_C( 95),
                             UINT8_C( 95), UINT8_C(183), UINT8_C(198), UINT8_C( 95),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C( 76), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(186), UINT8_C(213), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(240), UINT8_C(242), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(186), UINT8_C(126), UINT8_C(  0)) },
    { simde_x_mm256_set_epu8(UINT8_C(132), UINT8_C( 22), UINT8_C(115), UINT8_C(245),
                             UINT8_C(139), UINT8_C(127), UINT8_C( 30), UINT8_C( 96),
                             UINT8_C(123), UINT8_C(228), UINT8_C( 73), UINT8_C(244),
                             UINT8_C( 12), UINT8_C( 46), UINT8_C( 26), UINT8_C( 36),
                             UINT8_C(186), UINT8_C( 18), UINT8_C(169), UINT8_C(233),
                             UINT8_C(  8), UINT8_C(185), UINT8_C(123), UINT8_C( 50),
                             UINT8_C(171), UINT8_C(240), UINT8_C(159), UINT8_C(176),
                             UINT8_C( 29), UINT8_C(146), UINT8_C( 85), UINT8_C( 34)),
      simde_x_mm256_set_epu8(UINT8_C(197), UINT8_C( 93), UINT8_C( 52), UINT8_C(130),
                             UINT8_C(124), UINT8_C( 87), UINT8_C( 88), UINT8_C( 89),
                             UINT8_C( 56), UINT8_C(209), UINT8_C( 85), UINT8_C(235),
                             UINT8_C( 45), UINT8_C(236), UINT8_C(154), UINT8_C( 72),
                             UINT8_C(164), UINT8_C(253), UINT8_C(196), UINT8_C( 41),
                             UINT8_C( 28), UINT8_C(181), UINT8_C(180), UINT8_C(237),
                             UINT8_C( 65), UINT8_C(122), UINT8_C(110), UINT8_C( 94),
                             UINT8_C(125), UINT8_C( 60), UINT8_C( 80), UINT8_C(209)),
      simde_x_mm256_set_epu8(UINT8_C(  0), UINT8_C(115), UINT8_C(244), UINT8_C(  0),
                             UINT8_C(245), UINT8_C(123), UINT8_C( 96), UINT8_C( 30),
                             UINT8_C( 96), UINT8_C(  0), UINT8_C( 73), UINT8_C(  0),
                             UINT8_C(115), UINT8_C(  0), UINT8_C(  0), UINT8_C( 96),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(123),
                             UINT8_C(233), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C( 85), UINT8_C(185), UINT8_C( 18), UINT8_C( 18),
                             UINT8_C(169), UINT8_C(233), UINT8_C( 34), UINT8_C(  0)) },
    { simde_x_mm256_set_epu8(UINT8_C(233), UINT8_C(108), UINT8_C(215), UINT8_C(181),
                             UINT8_C(100), UINT8_C( 72), UINT8_C(220), UINT8_C( 52),
                             UINT8_C( 24), UINT8_C(  0), UINT8_C(242), UINT8_C(125),
                             UINT8_C(116), UINT8_C(102), UINT8_C( 94), UINT8_C( 64),
                             UINT8_C(158), UINT8_C(177), UINT8_C(  3), UINT8_C(246),
                             UINT8_C(164), UINT8_C(171), UINT8_C(138), UINT8_C( 15),
                             UINT8_C( 30), UINT8_C( 68), UINT8_C(246), UINT8_C(147),
                             UINT8_C(162), UINT8_C( 13), UINT8_C( 93), UINT8_C( 58)),
      simde_x_mm256_set_epu8(UINT8_C(159), UINT8_C(224), UINT8_C(140), UINT8_C(117),
                             UINT8_C( 95), UINT8_C( 45), UINT8_C(144), UINT8_C( 69),
                             UINT8_C(174), UINT8_C( 34), UINT8_C(237), UINT8_C( 42),
                             UINT8_C( 78), UINT8_C(  7), UINT8_C(200), UINT8_C(173),
                             UINT8_C(137), UINT8_C( 75), UINT8_C(170), UINT8_C(110),
                             UINT8_C(182), UINT8_C(180), UINT8_C(173), UINT8_C(172),
                             UINT8_C(227), UINT8_C(222), UINT8_C(132), UINT8_C(  4),
                             UINT8_C(190), UINT8_C(  7), UINT8_C( 12), UINT8_C( 21)),
      simde_x_mm256_set_epu8(UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(242),
                             UINT8_C(233), UINT8_C(215), UINT8_C(  0), UINT8_C(242),
                             UINT8_C(  0), UINT8_C(102), UINT8_C(  0), UINT8_C( 72),
                             UINT8_C(108), UINT8_C( 24), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(164), UINT8_C(  0), UINT8_C(177),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(147),
                             UINT8_C(  0), UINT8_C( 30), UINT8_C(246), UINT8_C(246)) },
    { simde_x_mm256_set_epu8(UINT8_C(239), UINT8_C(190), UINT8_C( 67), UINT8_C(183),
                             UINT8_C(162), UINT8_C( 57), UINT8_C(249), UINT8_C(218),
                             UINT8_C(176), UINT8_C(139), UINT8_C(  3), UINT8_C(248),
                             UINT8_C(214), UINT8_C( 36), UINT8_C(105), UINT8_C( 96),
                             UINT8_C( 80), UINT8_C(108), UINT8_C(142), UINT8_C(  2),
                             UINT8_C(196), UINT8_C(162), UINT8_C( 38), UINT8_C(  4),
                             UINT8_C(175), UINT8_C(178), UINT8_C( 88), UINT8_C(165),
                             UINT8_C(168), UINT8_C( 71), UINT8_C( 76), UINT8_C(232)),
      simde_x_mm256_set_epu8(UINT8_C(199), UINT8_C( 95), UINT8_C( 43), UINT8_C(216),
                             UINT8_C(128), UINT8_C(137), UINT8_C(103), UINT8_C( 51),
                             UINT8_C(121), UINT8_C( 84), UINT8_C(196), UINT8_C(101),
                             UINT8_C(251), UINT8_C(  4), UINT8_C( 89), UINT8_C( 54),
                             UINT8_C(216), UINT8_C(149), UINT8_C(145), UINT8_C( 73),
                             UINT8_C(162), UINT8_C( 73), UINT8_C(124), UINT8_C(146),
                             UINT8_C( 70), UINT8_C(151), UINT8_C(137), UINT8_C(218),
                             UINT8_C(230), UINT8_C(112), UINT8_C( 45), UINT8_C(226)),
      simde_x_mm256_set_epu8(UINT8_C(  0), UINT8_C(239), UINT8_C(162), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(176), UINT8_C(214),
                             UINT8_C(249), UINT8_C(248), UINT8_C(  0), UINT8_C(  3),
                             UINT8_C(  0), UINT8_C(248), UINT8_C(249), UINT8_C(139),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 38),
                             UINT8_C(  0), UINT8_C( 38), UINT8_C(  2), UINT8_C(  0),
                             UINT8_C(178), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(232), UINT8_C(142), UINT8_C(  0)) },
    { simde_x_mm256_set_epu8(UINT8_C( 81), UINT8_C(102), UINT8_C( 49), UINT8_C(133),
                             UINT8_C(250), UINT8_C( 13), UINT8_C(233), UINT8_C( 67),
                             UINT8_C(205), UINT8_C(254), UINT8_C( 41), UINT8_C(  6),
                             UINT8_C(117), UINT8_C(148), UINT8_C(222), UINT8_C(171),
                             UINT8_C(  8), UINT8_C( 99), UINT8_C( 93), UINT8_C( 39),
                             UINT8_C(103), UINT8_C(215), UINT8_C(216), UINT8_C( 75),
                             UINT8_C( 94), UINT8_C(171), UINT8_C( 41), UINT8_C(173),
                             UINT8_C(217), UINT8_C(138), UINT8_C(180), UINT8_C(160)),
      simde_x_mm256_set_epu8(UINT8_C(200), UINT8_C(107), UINT8_C(119), UINT8_C(216),
                             UINT8_C( 73), UINT8_C(187), UINT8_C(212), UINT8_C( 20),
                             UINT8_C( 22), UINT8_C( 11), UINT8_C(155), UINT8_C(106),
                             UINT8_C( 35), UINT8_C(108), UINT8_C( 43), UINT8_C( 58),
                             UINT8_C(102), UINT8_C(228), UINT8_C(  5), UINT8_C(227),
                             UINT8_C(106), UINT8_C(119), UINT8_C(184), UINT8_C(199),
                             UINT8_C( 57), UINT8_C(120), UINT8_C( 14), UINT8_C( 56),
                             UINT8_C( 82), UINT8_C( 19), UINT8_C( 33), UINT8_C( 82)),
      simde_x_mm256_set_epu8(UINT8_C(  0), UINT8_C(250), UINT8_C(205), UINT8_C(  0),
                             UINT8_C(233), UINT8_C(  0), UINT8_C(  0), UINT8_C(  6),
                             UINT8_C(254), UINT8_C(250), UINT8_C(  0), UINT8_C( 13),
                             UINT8_C(117), UINT8_C(133), UINT8_C(250), UINT8_C( 13),
                             UINT8_C(171), UINT8_C(  0), UINT8_C( 41), UINT8_C(  0),
                             UINT8_C(215), UINT8_C( 94), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(216), UINT8_C( 75), UINT8_C( 99), UINT8_C( 75),
                             UINT8_C(138), UINT8_C(217), UINT8_C(180), UINT8_C(138)) },
    { simde_x_mm256_set_epu8(UINT8_C(173), UINT8_C(218), UINT8_C( 20), UINT8_C( 45),
                             UINT8_C(110), UINT8_C( 90), UINT8_C(183), UINT8_C( 54),
                             UINT8_C(102), UINT8_C(126), UINT8_C(167), UINT8_C(135),
                             UINT8_C( 42), UINT8_C( 74), UINT8_C( 22), UINT8_C(137),
                             UINT8_C( 56), UINT8_C(  5), UINT8_C( 18), UINT8_C(105),
                             UINT8_C( 83), UINT8_C(146), UINT8_C(229), UINT8_C( 54),
                             UINT8_C(169), UINT8_C( 55), UINT8_C(228), UINT8_C(168),
                             UINT8_C(  1), UINT8_C(126), UINT8_C(169), UINT8_C(235)),
      simde_x_mm256_set_epu8(UINT8_C(254), UINT8_C( 56), UINT8_C(  4), UINT8_C(163),
                             UINT8_C( 35), UINT8_C( 52), UINT8_C(182), UINT8_C( 52),
                             UINT8_C(  1), UINT8_C( 45), UINT8_C(119), UINT8_C(169),
                             UINT8_C(175), UINT8_C(254), UINT8_C( 71), UINT8_C( 63),
                             UINT8_C( 24), UINT8_C(116), UINT8_C(194), UINT8_C(184),
                             UINT8_C(150), UINT8_C(167), UINT8_C(101), UINT8_C(133),
                             UINT8_C( 95), UINT8_C( 84), UINT8_C(199), UINT8_C(134),
                             UINT8_C(251), UINT8_C(101), UINT8_C( 38), UINT8_C( 43)),
      simde_x_mm256_set_epu8(UINT8_C(  0), UINT8_C( 54), UINT8_C(135), UINT8_C(  0),
                             UINT8_C( 42), UINT8_C(135), UINT8_C(  0), UINT8_C(135),
                             UINT8_C( 22), UINT8_C( 20), UINT8_C(102), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(102), UINT8_C(173),
                             UINT8_C( 54), UINT8_C(168), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(  0), UINT8_C(228), UINT8_C(  0),
                             UINT8_C( 56), UINT8_C(168), UINT8_C(  0), UINT8_C(  0),
                             UINT8_C(  0), UINT8_C(228), UINT8_C( 55), UINT8_C( 83)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_shuffle_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_srli_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C(-4256718216449012213), INT64_C( 6954428280967509650),
                             INT64_C( 1187214080985021589), INT64_C(-4702330273301320405)),
      simde_mm256_set_epi64x(INT64_C(    1732180890778874), INT64_C(     848929233516541),
                             INT64_C(     144923593870241), INT64_C(    1677784887745145)) },
    { simde_mm256_set_epi64x(INT64_C(-3743076857167596375), INT64_C(-2949526633471503649),
                             INT64_C( -669110663294743741), INT64_C( 7371470111003579569)),
      simde_mm256_set_epi64x(INT64_C(    1794881252019281), INT64_C(    1891750175810308),
                             INT64_C(    2170121265919776), INT64_C(     899837660034616)) },
    { simde_mm256_set_epi64x(INT64_C(-1169177286944430348), INT64_C( 6455539972528691466),
                             INT64_C(-3144731664245862155), INT64_C( 8588725191818949696)),
      simde_mm256_set_epi64x(INT64_C(    2109077976900039), INT64_C(     788029781802818),
                             INT64_C(    1867921436702110), INT64_C(    1048428368141961)) },
    { simde_mm256_set_epi64x(INT64_C( 5021751163006482875), INT64_C( 2964602111576624904),
                             INT64_C(-4368546882672922616), INT64_C(-5401573381584498754)),
      simde_mm256_set_epi64x(INT64_C(     613006733765439), INT64_C(     361889906198318),
                             INT64_C(    1718529930546463), INT64_C(    1592428063003546)) },
    { simde_mm256_set_epi64x(INT64_C( 3259692229419136160), INT64_C( 7535593008241291393),
                             INT64_C( 5636342892427003163), INT64_C(-1571672726362789760)),
      simde_mm256_set_epi64x(INT64_C(     397911649099015), INT64_C(     919872193388829),
                             INT64_C(     688030138235718), INT64_C(    2059945232830415)) },
    { simde_mm256_set_epi64x(INT64_C(  989750983639101530), INT64_C( 8678458181172187091),
                             INT64_C(-2685498580325005795), INT64_C( 3115460859126861666)),
      simde_mm256_set_epi64x(INT64_C(     120819211870007), INT64_C(    1059382102193870),
                             INT64_C(    1923980162766668), INT64_C(     380305280655134)) },
    { simde_mm256_set_epi64x(INT64_C( 4213211340014625996), INT64_C( 2088661399522998885),
                             INT64_C( 8429870025320256082), INT64_C( 3926130149086841056)),
      simde_mm256_set_epi64x(INT64_C(     514308024904129), INT64_C(     254963549746459),
                             INT64_C(    1029036868325226), INT64_C(     479263934214702)) },
    { simde_mm256_set_epi64x(INT64_C(-1914589078060239315), INT64_C(-3242383134288733864),
                             INT64_C( 7743081591170414486), INT64_C( 6381904702631892778)),
      simde_mm256_set_epi64x(INT64_C(    2018085326617347), INT64_C(    1856001091237892),
                             INT64_C(     945200389547169), INT64_C(     779041101395494)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_srli_epi64(test_vec[i].a, 13);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_xor_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C( 5259297934522696228), INT64_C( -431388325374833226),
                             INT64_C(-9156654280217339654), INT64_C( 3013799969040676174)),
      simde_mm256_set_epi64x(INT64_C(-5610681863545377343), INT64_C(  612481038911101319),
                             INT64_C( 6883094940018615339), INT64_C( 5567527613349466758)),
      simde_mm256_set_epi64x(INT64_C( -369826194426859547), INT64_C( -973728768696970191),
                             INT64_C(-2348436908296831791), INT64_C( 7246573032282466248)) },
    { simde_mm256_set_epi64x(INT64_C( 3972970387578047990), INT64_C(-3229803026080205617),
                             INT64_C(-6416566799554918012), INT64_C( 7243493956554503841)),
      simde_mm256_set_epi64x(INT64_C(-2328069278528400967), INT64_C( -866344990039815627),
                             INT64_C( 5191362241164177707), INT64_C( 6965508020004735797)),
      simde_mm256_set_epi64x(INT64_C(-1687764814515086257), INT64_C( 2366483896335154938),
                             INT64_C(-1227043938297071441), INT64_C(  300751355152891284)) },
    { simde_mm256_set_epi64x(INT64_C(-2206747055975530789), INT64_C( 4273990306427029435),
                             INT64_C(-8066951550635951807), INT64_C(-6928425273442710875)),
      simde_mm256_set_epi64x(INT64_C(-4939687486626430761), INT64_C(-1679871113178117518),
                             INT64_C( -257233978894060261), INT64_C( 3512456176079583747)),
      simde_mm256_set_epi64x(INT64_C( 6490456006491962892), INT64_C(-3170633551353754167),
                             INT64_C( 7809929228804508762), INT64_C(-5807521855463853914)) },
    { simde_mm256_set_epi64x(INT64_C(-8921324304875098515), INT64_C( 7821700200964206339),
                             INT64_C( 2994261353466796408), INT64_C(-3540068018343188204)),
      simde_mm256_set_epi64x(INT64_C( 4294357400656496399), INT64_C( 3626952931332295508),
                             INT64_C(-7673859083891959013), INT64_C( 1757595472193292730)),
      simde_mm256_set_epi64x(INT64_C(-4636023147992241822), INT64_C( 6834710091372766295),
                             INT64_C(-4896194530503130525), INT64_C(-2973751098574872402)) },
    { simde_mm256_set_epi64x(INT64_C( 6035067220796971838), INT64_C(  776715589999365452),
                             INT64_C( 6384421609504908311), INT64_C(-8816267298986390401)),
      simde_mm256_set_epi64x(INT64_C(-5739247744839421985), INT64_C( 4653816358777581262),
                             INT64_C( 1021833051660996174), INT64_C(-2812490060666099514)),
      simde_mm256_set_epi64x(INT64_C(-2046106215006112543), INT64_C( 5355589079452705666),
                             INT64_C( 6247691286445288025), INT64_C( 6727907985691518137)) },
    { simde_mm256_set_epi64x(INT64_C( 8351942705843556286), INT64_C(-6873744911563016812),
                             INT64_C(-3359807879676804643), INT64_C( 8110291315370526762)),
      simde_mm256_set_epi64x(INT64_C( -126725188666547082), INT64_C( 4977977654704902461),
                             INT64_C(-7727661347289141755), INT64_C( 7453179086506187618)),
      simde_mm256_set_epi64x(INT64_C(-8226449520241153080), INT64_C(-1905346832462535511),
                             INT64_C( 5016522326789730264), INT64_C( 1721087647877354312)) },
    { simde_mm256_set_epi64x(INT64_C(-3541650301143541882), INT64_C( 2340510988864802758),
                             INT64_C(-2484352519219712887), INT64_C(-7823366500674586971)),
      simde_mm256_set_epi64x(INT64_C( 8787496485572343767), INT64_C( 5972980855318355117),
                             INT64_C( 1254817555351506981), INT64_C( 3585972827969393388)),
      simde_mm256_set_epi64x(INT64_C(-5248115586102763439), INT64_C( 8259425971222532971),
                             INT64_C(-3679494355159515988), INT64_C(-6724368097479220151)) },
    { simde_mm256_set_epi64x(INT64_C(-8306510049557921760), INT64_C(-3952727854475033325),
                             INT64_C(-2945542500559658351), INT64_C(  937552523927336948)),
      simde_mm256_set_epi64x(INT64_C( 4952101385331357252), INT64_C( 3142376059888144776),
                             INT64_C(-5526391810306106309), INT64_C( 1965153668529504230)),
      simde_mm256_set_epi64x(INT64_C(-4035158306098612636), INT64_C(-2108000641444326245),
                             INT64_C( 7228588967820590762), INT64_C( 1605387943167658002)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_xor_si256(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  TEST_FUNC(mm256_add_epi8),
  TEST_FUNC(mm256_add_epi16),
  TEST_FUNC(mm256_add_epi32),
  TEST_FUNC(mm256_add_epi64),

  TEST_FUNC(mm256_and_si256),

  TEST_FUNC(mm256_broadcastsi128_si256),

  TEST_FUNC(mm256_shuffle_epi8),

  TEST_FUNC(mm256_srli_epi64),

  TEST_FUNC(mm256_xor_si256),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

#if defined(SIMDE_NO_NATIVE)
#  define simde_avx2_test_suite simde_avx2_emul_test_suite
#endif

MunitSuite simde_avx2_test_suite = {
  (char*) "/avx2",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
