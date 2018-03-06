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

static MunitTest test_suite_tests[] = {
  TEST_FUNC(mm256_add_epi8),
  TEST_FUNC(mm256_add_epi16),
  TEST_FUNC(mm256_add_epi32),
  TEST_FUNC(mm256_add_epi64),

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
