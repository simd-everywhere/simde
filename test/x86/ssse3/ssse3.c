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
#include <simde/x86/ssse3.h>

#include <stdio.h>

static MunitResult
test_simde_mm_abs_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(-128), INT8_C( 127), INT8_C(   0), INT8_C(  -1),
                        INT8_C( 125), INT8_C( -56), INT8_C(-120), INT8_C( -18),
                        INT8_C( -45), INT8_C(  42), INT8_C(  62), INT8_C( -99),
                        INT8_C( -57), INT8_C(  32), INT8_C( -68), INT8_C(  66)),
      simde_x_mm_set_epu8(UINT8_C( 128), UINT8_C( 127), UINT8_C(   0), UINT8_C(   1),
                          UINT8_C( 125), UINT8_C(  56), UINT8_C( 120), UINT8_C(  18),
                          UINT8_C(  45), UINT8_C(  42), UINT8_C(  62), UINT8_C(  99),
                          UINT8_C(  57), UINT8_C(  32), UINT8_C(  68), UINT8_C(  66)) },
    { simde_mm_set_epi8(INT8_C( 113), INT8_C( -60), INT8_C(   1), INT8_C(  32),
                        INT8_C(  41), INT8_C(  40), INT8_C( 112), INT8_C( -39),
                        INT8_C( -65), INT8_C(  54), INT8_C(-116), INT8_C( -97),
                        INT8_C( -18), INT8_C(  78), INT8_C( -84), INT8_C(  94)),
      simde_x_mm_set_epu8(UINT8_C( 113), UINT8_C(  60), UINT8_C(   1), UINT8_C(  32),
                          UINT8_C(  41), UINT8_C(  40), UINT8_C( 112), UINT8_C(  39),
                          UINT8_C(  65), UINT8_C(  54), UINT8_C( 116), UINT8_C(  97),
                          UINT8_C(  18), UINT8_C(  78), UINT8_C(  84), UINT8_C(  94)) },
    { simde_mm_set_epi8(INT8_C( 126), INT8_C( -67), INT8_C( -75), INT8_C(  48),
                        INT8_C( -49), INT8_C(  -8), INT8_C( 105), INT8_C( -28),
                        INT8_C(-100), INT8_C(  -1), INT8_C( 112), INT8_C( -27),
                        INT8_C( -35), INT8_C( 114), INT8_C( -81), INT8_C( 121)),
      simde_x_mm_set_epu8(UINT8_C( 126), UINT8_C(  67), UINT8_C(  75), UINT8_C(  48),
                          UINT8_C(  49), UINT8_C(   8), UINT8_C( 105), UINT8_C(  28),
                          UINT8_C( 100), UINT8_C(   1), UINT8_C( 112), UINT8_C(  27),
                          UINT8_C(  35), UINT8_C( 114), UINT8_C(  81), UINT8_C( 121)) },
    { simde_mm_set_epi8(INT8_C(  94), INT8_C(  74), INT8_C(   0), INT8_C( -58),
                        INT8_C(-112), INT8_C(  29), INT8_C(-113), INT8_C( -48),
                        INT8_C(  92), INT8_C( -26), INT8_C( -61), INT8_C(  19),
                        INT8_C( -82), INT8_C( -78), INT8_C( -59), INT8_C( 102)),
      simde_x_mm_set_epu8(UINT8_C(  94), UINT8_C(  74), UINT8_C(   0), UINT8_C(  58),
                          UINT8_C( 112), UINT8_C(  29), UINT8_C( 113), UINT8_C(  48),
                          UINT8_C(  92), UINT8_C(  26), UINT8_C(  61), UINT8_C(  19),
                          UINT8_C(  82), UINT8_C(  78), UINT8_C(  59), UINT8_C( 102)) },
    { simde_mm_set_epi8(INT8_C( -47), INT8_C(   2), INT8_C(  14), INT8_C(  29),
                        INT8_C(  46), INT8_C( 102), INT8_C(-121), INT8_C( 118),
                        INT8_C( 113), INT8_C(  31), INT8_C(  96), INT8_C( -45),
                        INT8_C(  -4), INT8_C(  59), INT8_C( -14), INT8_C(-113)),
      simde_x_mm_set_epu8(UINT8_C(  47), UINT8_C(   2), UINT8_C(  14), UINT8_C(  29),
                          UINT8_C(  46), UINT8_C( 102), UINT8_C( 121), UINT8_C( 118),
                          UINT8_C( 113), UINT8_C(  31), UINT8_C(  96), UINT8_C(  45),
                          UINT8_C(   4), UINT8_C(  59), UINT8_C(  14), UINT8_C( 113)) },
    { simde_mm_set_epi8(INT8_C(  -4), INT8_C( -36), INT8_C( -71), INT8_C( 103),
                        INT8_C(-106), INT8_C(  36), INT8_C( -43), INT8_C( 119),
                        INT8_C(  62), INT8_C(  74), INT8_C(  88), INT8_C(  28),
                        INT8_C(   5), INT8_C(  31), INT8_C( -84), INT8_C( -65)),
      simde_x_mm_set_epu8(UINT8_C(   4), UINT8_C(  36), UINT8_C(  71), UINT8_C( 103),
                          UINT8_C( 106), UINT8_C(  36), UINT8_C(  43), UINT8_C( 119),
                          UINT8_C(  62), UINT8_C(  74), UINT8_C(  88), UINT8_C(  28),
                          UINT8_C(   5), UINT8_C(  31), UINT8_C(  84), UINT8_C(  65)) },
    { simde_mm_set_epi8(INT8_C( -76), INT8_C(  66), INT8_C(-116), INT8_C(  14),
                        INT8_C(  42), INT8_C( -27), INT8_C( 102), INT8_C( 115),
                        INT8_C( -18), INT8_C(  33), INT8_C(  48), INT8_C( 113),
                        INT8_C(  64), INT8_C(  25), INT8_C(-128), INT8_C(-121)),
      simde_x_mm_set_epu8(UINT8_C(  76), UINT8_C(  66), UINT8_C( 116), UINT8_C(  14),
                          UINT8_C(  42), UINT8_C(  27), UINT8_C( 102), UINT8_C( 115),
                          UINT8_C(  18), UINT8_C(  33), UINT8_C(  48), UINT8_C( 113),
                          UINT8_C(  64), UINT8_C(  25), UINT8_C( 128), UINT8_C( 121)) },
    { simde_mm_set_epi8(INT8_C(  83), INT8_C(  29), INT8_C( -57), INT8_C(-122),
                        INT8_C( -78), INT8_C(  -6), INT8_C( 104), INT8_C( -66),
                        INT8_C( -96), INT8_C( -79), INT8_C( -74), INT8_C( -82),
                        INT8_C( -64), INT8_C(   4), INT8_C(  64), INT8_C( -63)),
      simde_x_mm_set_epu8(UINT8_C(  83), UINT8_C(  29), UINT8_C(  57), UINT8_C( 122),
                          UINT8_C(  78), UINT8_C(   6), UINT8_C( 104), UINT8_C(  66),
                          UINT8_C(  96), UINT8_C(  79), UINT8_C(  74), UINT8_C(  82),
                          UINT8_C(  64), UINT8_C(   4), UINT8_C(  64), UINT8_C(  63)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_abs_epi8(test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_abs_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-32768), INT16_C( 32767), INT16_C(0), INT16_C(-1),
                         INT16_C( 17002), INT16_C(-16782), INT16_C( 31724), INT16_C( 17895)),
      simde_x_mm_set_epu16(UINT16_C(32768), UINT16_C(32767), UINT16_C(    0), UINT16_C(    1),
                           UINT16_C(17002), UINT16_C(16782), UINT16_C(31724), UINT16_C(17895)) },
    { simde_mm_set_epi16(INT16_C(   516), INT16_C(-21666), INT16_C(  7667), INT16_C( 17413),
                         INT16_C(-25469), INT16_C( 28873), INT16_C(-13553), INT16_C(-30319)),
      simde_x_mm_set_epu16(UINT16_C(  516), UINT16_C(21666), UINT16_C( 7667), UINT16_C(17413),
                           UINT16_C(25469), UINT16_C(28873), UINT16_C(13553), UINT16_C(30319)) },
    { simde_mm_set_epi16(INT16_C(-19076), INT16_C(-28644), INT16_C( -3095), INT16_C( -4676),
                         INT16_C(  7446), INT16_C( -2630), INT16_C( 16197), INT16_C(-16562)),
      simde_x_mm_set_epu16(UINT16_C(19076), UINT16_C(28644), UINT16_C( 3095), UINT16_C( 4676),
                           UINT16_C( 7446), UINT16_C( 2630), UINT16_C(16197), UINT16_C(16562)) },
    { simde_mm_set_epi16(INT16_C( 17533), INT16_C( 20338), INT16_C(  8248), INT16_C(  6751),
                         INT16_C( -3126), INT16_C( 26964), INT16_C( 14690), INT16_C(-25810)),
      simde_x_mm_set_epu16(UINT16_C(17533), UINT16_C(20338), UINT16_C( 8248), UINT16_C( 6751),
                           UINT16_C( 3126), UINT16_C(26964), UINT16_C(14690), UINT16_C(25810)) },
    { simde_mm_set_epi16(INT16_C( 18848), INT16_C(  6581), INT16_C(-32132), INT16_C( 14259),
                         INT16_C( 20181), INT16_C(  8393), INT16_C(  8677), INT16_C( 24318)),
      simde_x_mm_set_epu16(UINT16_C(18848), UINT16_C( 6581), UINT16_C(32132), UINT16_C(14259),
                           UINT16_C(20181), UINT16_C( 8393), UINT16_C( 8677), UINT16_C(24318)) },
    { simde_mm_set_epi16(INT16_C(-16277), INT16_C(-19021), INT16_C( -2631), INT16_C(  6570),
                         INT16_C( 17968), INT16_C(-24371), INT16_C(-26844), INT16_C( -2593)),
      simde_x_mm_set_epu16(UINT16_C(16277), UINT16_C(19021), UINT16_C( 2631), UINT16_C( 6570),
                           UINT16_C(17968), UINT16_C(24371), UINT16_C(26844), UINT16_C( 2593)) },
    { simde_mm_set_epi16(INT16_C( 23202), INT16_C(-30664), INT16_C( 14496), INT16_C(-10863),
                         INT16_C(-12787), INT16_C( -4044), INT16_C( 13497), INT16_C(  6178)),
      simde_x_mm_set_epu16(UINT16_C(23202), UINT16_C(30664), UINT16_C(14496), UINT16_C(10863),
                           UINT16_C(12787), UINT16_C( 4044), UINT16_C(13497), UINT16_C( 6178)) },
    { simde_mm_set_epi16(INT16_C(-16084), INT16_C( 24093), INT16_C( -9776), INT16_C( 28468),
                         INT16_C( -9561), INT16_C( -3016), INT16_C( -8976), INT16_C(-19890)),
      simde_x_mm_set_epu16(UINT16_C(16084), UINT16_C(24093), UINT16_C( 9776), UINT16_C(28468),
                           UINT16_C( 9561), UINT16_C( 3016), UINT16_C( 8976), UINT16_C(19890)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_abs_epi16(test_vec[i].a);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_abs_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-2147483648), INT32_C(2147483647), INT32_C(0), INT32_C(-1)),
      simde_x_mm_set_epu32(UINT32_C(2147483648), UINT32_C(2147483647), UINT32_C(0), UINT32_C(1)) },
    { simde_mm_set_epi32(INT32_C(-1840848639), INT32_C( 1050450514), INT32_C( -157155149), INT32_C(-1343526078)),
      simde_x_mm_set_epu32(UINT32_C(1840848639), UINT32_C(1050450514), UINT32_C( 157155149), UINT32_C(1343526078)) },
    { simde_mm_set_epi32(INT32_C( 1334116049), INT32_C( 2129925302), INT32_C(   23778640), INT32_C(  713371303)),
      simde_x_mm_set_epu32(UINT32_C(1334116049), UINT32_C(2129925302), UINT32_C(  23778640), UINT32_C( 713371303)) },
    { simde_mm_set_epi32(INT32_C( -302860244), INT32_C( 2030687021), INT32_C( 1060978877), INT32_C( -670900580)),
      simde_x_mm_set_epu32(UINT32_C( 302860244), UINT32_C(2030687021), UINT32_C(1060978877), UINT32_C( 670900580)) },
    { simde_mm_set_epi32(INT32_C( 2040528386), INT32_C( 1361895717), INT32_C(  147208745), INT32_C(  773158561)),
      simde_x_mm_set_epu32(UINT32_C(2040528386), UINT32_C(1361895717), UINT32_C( 147208745), UINT32_C( 773158561)) },
    { simde_mm_set_epi32(INT32_C(-1860066775), INT32_C(  109120839), INT32_C(  825660888), INT32_C( 1402710636)),
      simde_x_mm_set_epu32(UINT32_C(1860066775), UINT32_C( 109120839), UINT32_C( 825660888), UINT32_C(1402710636)) },
    { simde_mm_set_epi32(INT32_C( 1113257677), INT32_C( 2062218865), INT32_C( 1785064575), INT32_C( 1289174686)),
      simde_x_mm_set_epu32(UINT32_C(1113257677), UINT32_C(2062218865), UINT32_C(1785064575), UINT32_C(1289174686)) },
    { simde_mm_set_epi32(INT32_C(-2072383870), INT32_C( 1611206266), INT32_C( 1414397723), INT32_C(-1863310079)),
      simde_x_mm_set_epu32(UINT32_C(2072383870), UINT32_C(1611206266), UINT32_C(1414397723), UINT32_C(1863310079)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_abs_epi32(test_vec[i].a);
    simde_assert_m128i_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_abs_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi8(INT8_C(  38), INT8_C(  28), INT8_C( -38), INT8_C(-113),
                       INT8_C(-109), INT8_C( -88), INT8_C(  99), INT8_C( -40)),
      simde_x_mm_set_pu8(UINT8_C( 38), UINT8_C( 28), UINT8_C( 38), UINT8_C(113),
                       UINT8_C(109), UINT8_C( 88), UINT8_C( 99), UINT8_C( 40)) },
    { simde_mm_set_pi8(INT8_C(  57), INT8_C(  21), INT8_C(  63), INT8_C(  38),
                       INT8_C(  75), INT8_C( -74), INT8_C( -71), INT8_C(  58)),
      simde_x_mm_set_pu8(UINT8_C( 57), UINT8_C( 21), UINT8_C( 63), UINT8_C( 38),
                       UINT8_C( 75), UINT8_C( 74), UINT8_C( 71), UINT8_C( 58)) },
    { simde_mm_set_pi8(INT8_C( 107), INT8_C(-123), INT8_C( -46), INT8_C( 116),
                       INT8_C(  49), INT8_C(-110), INT8_C( -27), INT8_C( -14)),
      simde_x_mm_set_pu8(UINT8_C(107), UINT8_C(123), UINT8_C( 46), UINT8_C(116),
                       UINT8_C( 49), UINT8_C(110), UINT8_C( 27), UINT8_C( 14)) },
    { simde_mm_set_pi8(INT8_C(  94), INT8_C( -17), INT8_C(-121), INT8_C( -59),
                       INT8_C( -39), INT8_C(-120), INT8_C(  -6), INT8_C(-128)),
      simde_x_mm_set_pu8(UINT8_C( 94), UINT8_C( 17), UINT8_C(121), UINT8_C( 59),
                       UINT8_C( 39), UINT8_C(120), UINT8_C(  6), UINT8_C(128)) },
    { simde_mm_set_pi8(INT8_C(-113), INT8_C( -83), INT8_C(  56), INT8_C(  12),
                       INT8_C( 114), INT8_C(  46), INT8_C( -44), INT8_C(  75)),
      simde_x_mm_set_pu8(UINT8_C(113), UINT8_C( 83), UINT8_C( 56), UINT8_C( 12),
                       UINT8_C(114), UINT8_C( 46), UINT8_C( 44), UINT8_C( 75)) },
    { simde_mm_set_pi8(INT8_C( -28), INT8_C(  63), INT8_C( 103), INT8_C(-127),
                       INT8_C(  94), INT8_C(  94), INT8_C(  64), INT8_C( 107)),
      simde_x_mm_set_pu8(UINT8_C( 28), UINT8_C( 63), UINT8_C(103), UINT8_C(127),
                       UINT8_C( 94), UINT8_C( 94), UINT8_C( 64), UINT8_C(107)) },
    { simde_mm_set_pi8(INT8_C( -42), INT8_C( 122), INT8_C( 121), INT8_C(   5),
                       INT8_C(  93), INT8_C( -41), INT8_C( -24), INT8_C(  13)),
      simde_x_mm_set_pu8(UINT8_C( 42), UINT8_C(122), UINT8_C(121), UINT8_C(  5),
                       UINT8_C( 93), UINT8_C( 41), UINT8_C( 24), UINT8_C( 13)) },
    { simde_mm_set_pi8(INT8_C( -78), INT8_C( -48), INT8_C(  35), INT8_C(   4),
                       INT8_C( -62), INT8_C(  -9), INT8_C(  70), INT8_C(  20)),
      simde_x_mm_set_pu8(UINT8_C( 78), UINT8_C( 48), UINT8_C( 35), UINT8_C(  4),
                       UINT8_C( 62), UINT8_C(  9), UINT8_C( 70), UINT8_C( 20)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_abs_pi8(test_vec[i].a);
    simde_assert_m64_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_abs_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( 22656), INT16_C(  -516), INT16_C( 11935), INT16_C(-27223)),
      simde_x_mm_set_pu16(UINT16_C(22656), UINT16_C(  516), UINT16_C(11935), UINT16_C(27223)) },
    { simde_mm_set_pi16(INT16_C(-22991), INT16_C( -6351), INT16_C(-10389), INT16_C( -8080)),
      simde_x_mm_set_pu16(UINT16_C(22991), UINT16_C( 6351), UINT16_C(10389), UINT16_C( 8080)) },
    { simde_mm_set_pi16(INT16_C( 30466), INT16_C(-32585), INT16_C( 19645), INT16_C(-10576)),
      simde_x_mm_set_pu16(UINT16_C(30466), UINT16_C(32585), UINT16_C(19645), UINT16_C(10576)) },
    { simde_mm_set_pi16(INT16_C(-16502), INT16_C( -5192), INT16_C(  4129), INT16_C(  3864)),
      simde_x_mm_set_pu16(UINT16_C(16502), UINT16_C( 5192), UINT16_C( 4129), UINT16_C( 3864)) },
    { simde_mm_set_pi16(INT16_C( 21069), INT16_C( 17958), INT16_C(-13493), INT16_C(  9609)),
      simde_x_mm_set_pu16(UINT16_C(21069), UINT16_C(17958), UINT16_C(13493), UINT16_C( 9609)) },
    { simde_mm_set_pi16(INT16_C(   400), INT16_C( 20835), INT16_C( 20896), INT16_C( 11278)),
      simde_x_mm_set_pu16(UINT16_C(  400), UINT16_C(20835), UINT16_C(20896), UINT16_C(11278)) },
    { simde_mm_set_pi16(INT16_C(-12492), INT16_C(-12858), INT16_C( 23414), INT16_C(-21576)),
      simde_x_mm_set_pu16(UINT16_C(12492), UINT16_C(12858), UINT16_C(23414), UINT16_C(21576)) },
    { simde_mm_set_pi16(INT16_C(  6654), INT16_C(-24897), INT16_C(-24943), INT16_C(-25087)),
      simde_x_mm_set_pu16(UINT16_C( 6654), UINT16_C(24897), UINT16_C(24943), UINT16_C(25087)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_abs_pi16(test_vec[i].a);
    simde_assert_m64_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_abs_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C(  -13878279), INT32_C(-1713620712)),
      simde_x_mm_set_pu32(UINT32_C(  13878279), UINT32_C(1713620712)) },
    { simde_mm_set_pi32(INT32_C( -727247206), INT32_C( -746817076)),
      simde_x_mm_set_pu32(UINT32_C( 727247206), UINT32_C( 746817076)) },
    { simde_mm_set_pi32(INT32_C(  850085177), INT32_C( -729101966)),
      simde_x_mm_set_pu32(UINT32_C( 850085177), UINT32_C( 729101966)) },
    { simde_mm_set_pi32(INT32_C(   64469638), INT32_C(  403976835)),
      simde_x_mm_set_pu32(UINT32_C(  64469638), UINT32_C( 403976835)) },
    { simde_mm_set_pi32(INT32_C( 1585672991), INT32_C( 1784425824)),
      simde_x_mm_set_pu32(UINT32_C(1585672991), UINT32_C(1784425824)) },
    { simde_mm_set_pi32(INT32_C( -137548456), INT32_C(-1080835717)),
      simde_x_mm_set_pu32(UINT32_C( 137548456), UINT32_C(1080835717)) },
    { simde_mm_set_pi32(INT32_C( -942357541), INT32_C(  223746416)),
      simde_x_mm_set_pu32(UINT32_C( 942357541), UINT32_C( 223746416)) },
    { simde_mm_set_pi32(INT32_C(  -21393113), INT32_C( -293603855)),
      simde_x_mm_set_pu32(UINT32_C(  21393113), UINT32_C( 293603855)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_abs_pi32(test_vec[i].a);
    simde_assert_m64_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_alignr_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(0x0e, 0xa6, 0x78, 0xc5, 0x44, 0x8c, 0x1c, 0xc6,
			0xd6, 0x3a, 0x0a, 0xa5, 0x36, 0xb7, 0xb8, 0x8a),
      simde_mm_set_epi8(0x1c, 0x44, 0xfe, 0xcd, 0x20, 0x7b, 0x4a, 0xaf,
			0x2a, 0x99, 0xf9, 0x5b, 0xcb, 0xda, 0xf8, 0x99),
      simde_mm_set_epi8(0x00, 0x0e, 0xa6, 0x78, 0xc5, 0x44, 0x8c, 0x1c,
			0xc6, 0xd6, 0x3a, 0x0a, 0xa5, 0x36, 0xb7, 0xb8) },
    { simde_mm_set_epi8(0x39, 0x47, 0x02, 0x20, 0xd3, 0x40, 0x93, 0x07,
			0xff, 0xd4, 0xed, 0x44, 0xc5, 0xc9, 0x57, 0x8b),
      simde_mm_set_epi8(0xfa, 0x88, 0xf3, 0xa9, 0xbb, 0xde, 0x94, 0x6f,
			0x6c, 0x1b, 0xea, 0xc3, 0x33, 0x72, 0x48, 0x3a),
      simde_mm_set_epi8(0x00, 0x39, 0x47, 0x02, 0x20, 0xd3, 0x40, 0x93,
			0x07, 0xff, 0xd4, 0xed, 0x44, 0xc5, 0xc9, 0x57) },
    { simde_mm_set_epi8(0x77, 0x95, 0xd2, 0x06, 0xce, 0x70, 0xc2, 0x4e,
			0x9e, 0x4f, 0x53, 0xc4, 0xc7, 0xaf, 0x6b, 0x44),
      simde_mm_set_epi8(0x65, 0xea, 0x07, 0xb7, 0x82, 0xf1, 0xad, 0x6b,
			0x47, 0xd9, 0x5f, 0x75, 0xcb, 0x02, 0x70, 0x2d),
      simde_mm_set_epi8(0x00, 0x77, 0x95, 0xd2, 0x06, 0xce, 0x70, 0xc2,
			0x4e, 0x9e, 0x4f, 0x53, 0xc4, 0xc7, 0xaf, 0x6b) },
    { simde_mm_set_epi8(0x27, 0x27, 0x35, 0x16, 0x41, 0xeb, 0xb5, 0xd6,
			0x7d, 0x83, 0xc7, 0x1f, 0xb9, 0x74, 0xad, 0x9d),
      simde_mm_set_epi8(0x8f, 0x7c, 0xef, 0x14, 0xe6, 0xe6, 0xa4, 0x40,
			0xc6, 0xd2, 0xb7, 0xe4, 0x93, 0x67, 0xc1, 0x44),
      simde_mm_set_epi8(0x00, 0x27, 0x27, 0x35, 0x16, 0x41, 0xeb, 0xb5,
			0xd6, 0x7d, 0x83, 0xc7, 0x1f, 0xb9, 0x74, 0xad) },
    { simde_mm_set_epi8(0x6c, 0xb7, 0x16, 0xc7, 0x11, 0x7d, 0x8b, 0x68,
			0x20, 0x1c, 0x0b, 0x41, 0x93, 0xe4, 0x25, 0x3b),
      simde_mm_set_epi8(0xde, 0xdf, 0xa5, 0xa0, 0xac, 0xda, 0x89, 0x41,
			0x1a, 0x28, 0xc7, 0xc7, 0x16, 0x36, 0x9a, 0xbe),
      simde_mm_set_epi8(0x00, 0x6c, 0xb7, 0x16, 0xc7, 0x11, 0x7d, 0x8b,
			0x68, 0x20, 0x1c, 0x0b, 0x41, 0x93, 0xe4, 0x25) },
    { simde_mm_set_epi8(0xdb, 0xac, 0xcc, 0x45, 0xab, 0x27, 0x91, 0x2f,
			0xe5, 0xed, 0x3c, 0x06, 0xe3, 0x9d, 0x2a, 0x89),
      simde_mm_set_epi8(0xd0, 0x98, 0x42, 0x74, 0xd9, 0xb8, 0x8a, 0xcc,
			0x55, 0x28, 0x89, 0xfa, 0xd3, 0x16, 0x6f, 0x9a),
      simde_mm_set_epi8(0x00, 0xdb, 0xac, 0xcc, 0x45, 0xab, 0x27, 0x91,
			0x2f, 0xe5, 0xed, 0x3c, 0x06, 0xe3, 0x9d, 0x2a) },
    { simde_mm_set_epi8(0x72, 0xae, 0x35, 0x1f, 0xa3, 0x0d, 0xc0, 0x4c,
			0x85, 0x0c, 0x09, 0x79, 0x46, 0x8c, 0xa5, 0x69),
      simde_mm_set_epi8(0x13, 0xa0, 0x97, 0xc2, 0x9b, 0x6c, 0x15, 0xb7,
			0xe4, 0x4c, 0x45, 0x88, 0xb8, 0x2f, 0xa8, 0x6d),
      simde_mm_set_epi8(0x00, 0x72, 0xae, 0x35, 0x1f, 0xa3, 0x0d, 0xc0,
			0x4c, 0x85, 0x0c, 0x09, 0x79, 0x46, 0x8c, 0xa5) },
    { simde_mm_set_epi8(0xb8, 0xa4, 0xd1, 0x25, 0xbc, 0x6e, 0xb4, 0x07,
			0x5c, 0x3c, 0x82, 0x4e, 0x4e, 0x8f, 0x89, 0x88),
      simde_mm_set_epi8(0xcd, 0xdc, 0xa8, 0x18, 0x32, 0xef, 0xe7, 0x84,
			0x82, 0xdc, 0x0b, 0x30, 0x15, 0x12, 0x4f, 0xc9),
      simde_mm_set_epi8(0x00, 0xb8, 0xa4, 0xd1, 0x25, 0xbc, 0x6e, 0xb4,
			0x07, 0x5c, 0x3c, 0x82, 0x4e, 0x4e, 0x8f, 0x89) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_alignr_epi8(test_vec[i].a, test_vec[i].b, 17);
    simde_assert_m128_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_alignr_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r3;
    simde__m64 r12;
  } test_vec[8] = {
    { simde_mm_set_pi8(INT8_C( -39), INT8_C(-110), INT8_C(  56), INT8_C(  87),
                       INT8_C(  10), INT8_C( -78), INT8_C(  61), INT8_C( -21)),
      simde_mm_set_pi8(INT8_C(  13), INT8_C( -51), INT8_C(   6), INT8_C( -66),
                       INT8_C( -73), INT8_C(  87), INT8_C( -77), INT8_C( 108)),
      simde_mm_set_pi8(INT8_C( -78), INT8_C(  61), INT8_C( -21), INT8_C(  13),
                       INT8_C( -51), INT8_C(   6), INT8_C( -66), INT8_C( -73)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                       INT8_C( -39), INT8_C(-110), INT8_C(  56), INT8_C(  87)) },
    { simde_mm_set_pi8(INT8_C(  51), INT8_C( -90), INT8_C(-118), INT8_C( -36),
                       INT8_C(  81), INT8_C(  52), INT8_C(  14), INT8_C(  46)),
      simde_mm_set_pi8(INT8_C(  26), INT8_C( -56), INT8_C( -35), INT8_C( -50),
                       INT8_C( 106), INT8_C(  71), INT8_C(  68), INT8_C(  40)),
      simde_mm_set_pi8(INT8_C(  52), INT8_C(  14), INT8_C(  46), INT8_C(  26),
                       INT8_C( -56), INT8_C( -35), INT8_C( -50), INT8_C( 106)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                       INT8_C(  51), INT8_C( -90), INT8_C(-118), INT8_C( -36)) },
    { simde_mm_set_pi8(INT8_C(  -8), INT8_C( -77), INT8_C(-125), INT8_C( -59),
                       INT8_C(   8), INT8_C( -89), INT8_C( -90), INT8_C( -97)),
      simde_mm_set_pi8(INT8_C( -59), INT8_C( -51), INT8_C( -30), INT8_C( -57),
                       INT8_C(  35), INT8_C(-105), INT8_C(  -5), INT8_C(  -3)),
      simde_mm_set_pi8(INT8_C( -89), INT8_C( -90), INT8_C( -97), INT8_C( -59),
                       INT8_C( -51), INT8_C( -30), INT8_C( -57), INT8_C(  35)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                       INT8_C(  -8), INT8_C( -77), INT8_C(-125), INT8_C( -59)) },
    { simde_mm_set_pi8(INT8_C(  67), INT8_C(  48), INT8_C( -81), INT8_C( -50),
                       INT8_C(  41), INT8_C( -92), INT8_C(  -5), INT8_C(  14)),
      simde_mm_set_pi8(INT8_C( -86), INT8_C( -71), INT8_C(  17), INT8_C( 108),
                       INT8_C( -44), INT8_C(  60), INT8_C(  44), INT8_C(  75)),
      simde_mm_set_pi8(INT8_C( -92), INT8_C(  -5), INT8_C(  14), INT8_C( -86),
                       INT8_C( -71), INT8_C(  17), INT8_C( 108), INT8_C( -44)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                       INT8_C(  67), INT8_C(  48), INT8_C( -81), INT8_C( -50)) },
    { simde_mm_set_pi8(INT8_C( -89), INT8_C(-124), INT8_C(-127), INT8_C(  44),
                       INT8_C( 127), INT8_C(  11), INT8_C(-119), INT8_C( -70)),
      simde_mm_set_pi8(INT8_C(  39), INT8_C( -13), INT8_C(  68), INT8_C( -96),
                       INT8_C(-112), INT8_C(-118), INT8_C( 122), INT8_C( -32)),
      simde_mm_set_pi8(INT8_C(  11), INT8_C(-119), INT8_C( -70), INT8_C(  39),
                       INT8_C( -13), INT8_C(  68), INT8_C( -96), INT8_C(-112)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                       INT8_C( -89), INT8_C(-124), INT8_C(-127), INT8_C(  44)) },
    { simde_mm_set_pi8(INT8_C(-100), INT8_C( -55), INT8_C(   7), INT8_C( -95),
                       INT8_C( -19), INT8_C(-101), INT8_C(  80), INT8_C( -82)),
      simde_mm_set_pi8(INT8_C( -54), INT8_C(   2), INT8_C( 109), INT8_C( 126),
                       INT8_C(-123), INT8_C( -75), INT8_C( -35), INT8_C(-107)),
      simde_mm_set_pi8(INT8_C(-101), INT8_C(  80), INT8_C( -82), INT8_C( -54),
                       INT8_C(   2), INT8_C( 109), INT8_C( 126), INT8_C(-123)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                       INT8_C(-100), INT8_C( -55), INT8_C(   7), INT8_C( -95)) },
    { simde_mm_set_pi8(INT8_C( -17), INT8_C( 109), INT8_C(-102), INT8_C( -75),
                       INT8_C( -61), INT8_C(  83), INT8_C(   8), INT8_C(  -7)),
      simde_mm_set_pi8(INT8_C(  94), INT8_C(-110), INT8_C( 105), INT8_C(   1),
                       INT8_C( 125), INT8_C(  57), INT8_C( -29), INT8_C(  60)),
      simde_mm_set_pi8(INT8_C(  83), INT8_C(   8), INT8_C(  -7), INT8_C(  94),
                       INT8_C(-110), INT8_C( 105), INT8_C(   1), INT8_C( 125)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                       INT8_C( -17), INT8_C( 109), INT8_C(-102), INT8_C( -75)) },
    { simde_mm_set_pi8(INT8_C( 127), INT8_C(-126), INT8_C( -37), INT8_C( -53),
                       INT8_C(  30), INT8_C(  85), INT8_C( -75), INT8_C(  62)),
      simde_mm_set_pi8(INT8_C(  72), INT8_C(  61), INT8_C(-110), INT8_C(  76),
                       INT8_C(  26), INT8_C(-125), INT8_C( -54), INT8_C( -64)),
      simde_mm_set_pi8(INT8_C(  85), INT8_C( -75), INT8_C(  62), INT8_C(  72),
                       INT8_C(  61), INT8_C(-110), INT8_C(  76), INT8_C(  26)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                       INT8_C( 127), INT8_C(-126), INT8_C( -37), INT8_C( -53)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_alignr_pi8(test_vec[i].a, test_vec[i].b, 3);
    simde_assert_m64_i8(r, ==, test_vec[i].r3);
    r = simde_mm_alignr_pi8(test_vec[i].a, test_vec[i].b, 12);
    simde_assert_m64_i8(r, ==, test_vec[i].r12);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_shuffle_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(0x68, 0xb8, 0x67, 0x53, 0x63, 0xcb, 0xf5, 0x64,
			0xb1, 0xa8, 0xbb, 0xde, 0x62, 0xf0, 0x9b, 0x43),
      simde_mm_set_epi8(0x8f, 0xc0, 0x0c, 0xa5, 0xfe, 0xa1, 0xb7, 0xe0,
			0xd9, 0xe7, 0x73, 0x71, 0x32, 0xf8, 0x20, 0x24),
      simde_mm_set_epi8(0x00, 0x00, 0x53, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x62, 0x9b, 0xf0, 0x00, 0x43, 0xde) },
    { simde_mm_set_epi8(0x65, 0xfa, 0xbd, 0xd7, 0xb4, 0xfc, 0x05, 0x2c,
			0xb4, 0x2d, 0xe5, 0x10, 0x21, 0x07, 0x5b, 0x88),
      simde_mm_set_epi8(0xf2, 0x24, 0x77, 0xe7, 0xb5, 0xae, 0x7e, 0x99,
			0x35, 0xf8, 0x5e, 0xdb, 0x4f, 0xbe, 0x21, 0x59),
      simde_mm_set_epi8(0x00, 0x10, 0xb4, 0x00, 0x00, 0x00, 0xfa, 0x00,
			0xe5, 0x00, 0xfa, 0x00, 0x65, 0x00, 0x5b, 0x05) },
    { simde_mm_set_epi8(0xba, 0xf3, 0x94, 0xab, 0xf8, 0x74, 0x1b, 0x34,
			0x34, 0x70, 0x14, 0xf4, 0xfa, 0x53, 0x4f, 0x22),
      simde_mm_set_epi8(0x5b, 0x8e, 0xef, 0xef, 0xb6, 0x34, 0x42, 0x57,
			0x9e, 0xcb, 0xfe, 0x0d, 0xe2, 0xa2, 0x24, 0x05),
      simde_mm_set_epi8(0xf8, 0x00, 0x00, 0x00, 0x00, 0xf4, 0x53, 0x34,
			0x00, 0x00, 0x00, 0x94, 0x00, 0x00, 0xf4, 0x14) },
    { simde_mm_set_epi8(0x9f, 0x7f, 0x0d, 0x92, 0x43, 0x29, 0x0f, 0x1d,
			0xbe, 0xd8, 0x12, 0xec, 0x8d, 0xfc, 0xd0, 0xc4),
      simde_mm_set_epi8(0xc6, 0x53, 0x66, 0xe2, 0xd5, 0x10, 0xd0, 0x20,
			0x5d, 0x7e, 0x2e, 0x15, 0xee, 0x4e, 0x2b, 0x28),
      simde_mm_set_epi8(0x00, 0x8d, 0xd8, 0x00, 0x00, 0xc4, 0x00, 0xc4,
			0x0d, 0x7f, 0x7f, 0x12, 0x00, 0x7f, 0x43, 0x1d) },
    { simde_mm_set_epi8(0xe4, 0x3f, 0x74, 0xed, 0x72, 0xa4, 0x19, 0x62,
			0x04, 0x0c, 0x51, 0xb3, 0x65, 0xf3, 0x86, 0xeb),
      simde_mm_set_epi8(0xd8, 0x14, 0x9b, 0xa8, 0x2c, 0x19, 0xd8, 0xf0,
			0xb1, 0x68, 0x19, 0x6a, 0xd3, 0x32, 0x89, 0x9f),
      simde_mm_set_epi8(0x00, 0xb3, 0x00, 0x00, 0xed, 0x19, 0x00, 0x00,
			0x00, 0x62, 0x19, 0xa4, 0x00, 0xf3, 0x00, 0x00) },
    { simde_mm_set_epi8(0xde, 0x84, 0x0d, 0x39, 0x30, 0x1a, 0x97, 0x4c,
			0x26, 0xb5, 0x43, 0x0f, 0x56, 0x34, 0xbd, 0x6f),
      simde_mm_set_epi8(0x7f, 0xee, 0x93, 0xdc, 0x3d, 0xa6, 0xeb, 0x54,
			0x43, 0x50, 0x21, 0x80, 0xa4, 0xaf, 0xd9, 0x74),
      simde_mm_set_epi8(0xde, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x0f,
			0x56, 0x6f, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x0f) },
    { simde_mm_set_epi8(0x0d, 0x52, 0x91, 0x0b, 0x52, 0xfb, 0xd6, 0xa4,
			0x55, 0x0b, 0x88, 0x79, 0x1c, 0xaa, 0xc6, 0x87),
      simde_mm_set_epi8(0x54, 0x3f, 0x7e, 0xf4, 0x3c, 0xed, 0x41, 0xec,
			0xd6, 0xca, 0xe4, 0x65, 0xcc, 0xad, 0xff, 0x0c),
      simde_mm_set_epi8(0x79, 0x0d, 0x52, 0x00, 0x0b, 0x00, 0xc6, 0x00,
			0x00, 0x00, 0x00, 0x88, 0x00, 0x00, 0x00, 0x0b) },
    { simde_mm_set_epi8(0x76, 0x1b, 0x22, 0xf5, 0x78, 0xff, 0xbe, 0xe2,
			0xc7, 0x50, 0xeb, 0x31, 0x80, 0x79, 0x01, 0xe0),
      simde_mm_set_epi8(0x69, 0xf7, 0x27, 0x4f, 0xcb, 0xf5, 0x91, 0x71,
			0xec, 0xad, 0x11, 0x6b, 0x22, 0x39, 0x05, 0x0b),
      simde_mm_set_epi8(0xbe, 0x00, 0xc7, 0x76, 0x00, 0x00, 0x00, 0x01,
			0x00, 0x00, 0x01, 0x78, 0x79, 0xbe, 0xeb, 0x78) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_shuffle_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  TEST_FUNC(mm_abs_epi8),
  TEST_FUNC(mm_abs_epi16),
  TEST_FUNC(mm_abs_epi32),
  TEST_FUNC(mm_abs_pi8),
  TEST_FUNC(mm_abs_pi16),
  TEST_FUNC(mm_abs_pi32),
  TEST_FUNC(mm_alignr_epi8),
  TEST_FUNC(mm_alignr_pi8),
  TEST_FUNC(mm_shuffle_epi8),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

#if defined(SIMDE_NO_NATIVE)
#  define simde_ssse3_test_suite simde_ssse3_emul_test_suite
#endif

MunitSuite simde_ssse3_test_suite = {
  (char*) "/ssse3",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
