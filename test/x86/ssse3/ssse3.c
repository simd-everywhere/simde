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
test_simde_mm_hadd_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[] = {
    { simde_mm_set_epi16(INT16_C(7), INT16_C(6), INT16_C(5), INT16_C(4),
                         INT16_C(3), INT16_C(2), INT16_C(1), INT16_C(0)),
      simde_mm_set_epi16(INT16_C(15), INT16_C(14), INT16_C(13), INT16_C(12),
                         INT16_C(11), INT16_C(10), INT16_C(9), INT16_C(8)),
      simde_mm_set_epi16(INT16_C(29), INT16_C(25), INT16_C(21), INT16_C(17),
                         INT16_C(13), INT16_C(9), INT16_C(5), INT16_C(1)) },
    { simde_mm_set_epi16(INT16_C( 16862), INT16_C(-22769), INT16_C(  1276), INT16_C(-11614),
                         INT16_C( 27365), INT16_C(-21745), INT16_C(-20072), INT16_C( 24895)),
      simde_mm_set_epi16(INT16_C( 27022), INT16_C(-16957), INT16_C(  -577), INT16_C(  5907),
                         INT16_C( 27331), INT16_C(-14214), INT16_C( 23860), INT16_C( -4618)),
      simde_mm_set_epi16(INT16_C( 10065), INT16_C(  5330), INT16_C( 13117), INT16_C( 19242),
                         INT16_C( -5907), INT16_C(-10338), INT16_C(  5620), INT16_C(  4823)) },
    { simde_mm_set_epi16(INT16_C( 10296), INT16_C( 16929), INT16_C( -7697), INT16_C(-29772),
                         INT16_C(  8760), INT16_C( 11055), INT16_C(-21639), INT16_C( -9735)),
      simde_mm_set_epi16(INT16_C( 17587), INT16_C(  2522), INT16_C( 12430), INT16_C(-26697),
                         INT16_C( 10766), INT16_C( 15055), INT16_C(-19640), INT16_C( 28548)),
      simde_mm_set_epi16(INT16_C( 20109), INT16_C(-14267), INT16_C( 25821), INT16_C(  8908),
                         INT16_C( 27225), INT16_C( 28067), INT16_C( 19815), INT16_C(-31374)) },
    { simde_mm_set_epi16(INT16_C( 25001), INT16_C(  2984), INT16_C( 25634), INT16_C( 18284),
                         INT16_C(   332), INT16_C( 30339), INT16_C( -8894), INT16_C( 21932)),
      simde_mm_set_epi16(INT16_C(-29538), INT16_C( -9241), INT16_C(-32628), INT16_C(-14450),
                         INT16_C( 29835), INT16_C(   605), INT16_C( -3960), INT16_C( -9885)),
      simde_mm_set_epi16(INT16_C( 26757), INT16_C( 18458), INT16_C( 30440), INT16_C(-13845),
                         INT16_C( 27985), INT16_C(-21618), INT16_C( 30671), INT16_C( 13038)) },
    { simde_mm_set_epi16(INT16_C(  9544), INT16_C(  1869), INT16_C( 10876), INT16_C( 18425),
                         INT16_C(-23507), INT16_C( -6113), INT16_C(-14498), INT16_C( 22949)),
      simde_mm_set_epi16(INT16_C(-18197), INT16_C(-29870), INT16_C(-22608), INT16_C( 17229),
                         INT16_C(-25091), INT16_C( 26338), INT16_C( 15760), INT16_C(-13942)),
      simde_mm_set_epi16(INT16_C( 17469), INT16_C( -5379), INT16_C(  1247), INT16_C(  1818),
                         INT16_C( 11413), INT16_C( 29301), INT16_C(-29620), INT16_C(  8451)) },
    { simde_mm_set_epi16(INT16_C(-12014), INT16_C( -2859), INT16_C(-10534), INT16_C(   -75),
                         INT16_C( 11851), INT16_C( 10033), INT16_C(-13975), INT16_C( 29701)),
      simde_mm_set_epi16(INT16_C( 32129), INT16_C(-30871), INT16_C(-23818), INT16_C(-30018),
                         INT16_C( -9498), INT16_C(-14851), INT16_C(-11614), INT16_C( -9352)),
      simde_mm_set_epi16(INT16_C(  1258), INT16_C( 11700), INT16_C(-24349), INT16_C(-20966),
                         INT16_C(-14873), INT16_C(-10609), INT16_C( 21884), INT16_C( 15726)) },
    { simde_mm_set_epi16(INT16_C(-21544), INT16_C(-15577), INT16_C(-26221), INT16_C( -9036),
                         INT16_C( 27367), INT16_C( 25240), INT16_C( 27963), INT16_C( 16531)),
      simde_mm_set_epi16(INT16_C(-17413), INT16_C( -3083), INT16_C(  7975), INT16_C(  3251),
                         INT16_C(-12476), INT16_C(-31198), INT16_C(-31819), INT16_C( 23479)),
      simde_mm_set_epi16(INT16_C(-20496), INT16_C( 11226), INT16_C( 21862), INT16_C( -8340),
                         INT16_C( 28415), INT16_C( 30279), INT16_C(-12929), INT16_C(-21042)) },
    { simde_mm_set_epi16(INT16_C(-26423), INT16_C( 20632), INT16_C(-27879), INT16_C( 26257),
                         INT16_C(-14251), INT16_C(-18865), INT16_C(  -651), INT16_C(-29238)),
      simde_mm_set_epi16(INT16_C( -3019), INT16_C( 26530), INT16_C(-15590), INT16_C( -2378),
                         INT16_C(  9416), INT16_C(-20831), INT16_C(-30518), INT16_C(-20357)),
      simde_mm_set_epi16(INT16_C( 23511), INT16_C(-17968), INT16_C(-11415), INT16_C( 14661),
                         INT16_C( -5791), INT16_C( -1622), INT16_C( 32420), INT16_C(-29889)) },
    { simde_mm_set_epi16(INT16_C( 31117), INT16_C(   717), INT16_C( -4833), INT16_C(-22028),
                         INT16_C(-11773), INT16_C( -2769), INT16_C(-29232), INT16_C(  7017)),
      simde_mm_set_epi16(INT16_C( 29029), INT16_C(-19941), INT16_C( 32677), INT16_C(  1632),
                         INT16_C(  3095), INT16_C( 13355), INT16_C( 25984), INT16_C( 16468)),
      simde_mm_set_epi16(INT16_C(  9088), INT16_C(-31227), INT16_C( 16450), INT16_C(-23084),
                         INT16_C( 31834), INT16_C(-26861), INT16_C(-14542), INT16_C(-22215)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_hadd_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_hadd_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[] = {
    { simde_mm_set_epi32(INT32_C(65535), INT32_C(0), INT32_C(1), INT32_C(-1)),
      simde_mm_set_epi32(INT32_C(-32), INT32_C(128), INT32_C(0), INT32_C(-65535)),
      simde_mm_set_epi32(INT32_C(96), INT32_C(-65535), INT32_C(65535), INT32_C(0)) },
    { simde_mm_set_epi32(INT32_C(  935437342), INT32_C( -511860991), INT32_C(-1852765223), INT32_C( -899948884)),
      simde_mm_set_epi32(INT32_C( -691754121), INT32_C(-1808366785), INT32_C( 1428445569), INT32_C(  851103099)),
      simde_mm_set_epi32(INT32_C( 1794846390), INT32_C(-2015418628), INT32_C(  423576351), INT32_C( 1542253189)) },
    { simde_mm_set_epi32(INT32_C( 1769801323), INT32_C( -534202186), INT32_C(   93006588), INT32_C(  -39722690)),
      simde_mm_set_epi32(INT32_C(-1819301058), INT32_C( 1538855279), INT32_C(-1162552057), INT32_C( 1560248404)),
      simde_mm_set_epi32(INT32_C( -280445779), INT32_C(  397696347), INT32_C( 1235599137), INT32_C(   53283898)) },
    { simde_mm_set_epi32(INT32_C( -236962758), INT32_C( 1371307856), INT32_C(-1291984296), INT32_C(-1633301517)),
      simde_mm_set_epi32(INT32_C(  553343851), INT32_C( 1511250694), INT32_C( 2041109339), INT32_C(  952253154)),
      simde_mm_set_epi32(INT32_C( 2064594545), INT32_C(-1301604803), INT32_C( 1134345098), INT32_C( 1369681483)) },
    { simde_mm_set_epi32(INT32_C(-2133195983), INT32_C(-1476381094), INT32_C( -832093237), INT32_C( 2141200401)),
      simde_mm_set_epi32(INT32_C( -724061580), INT32_C( 1346631337), INT32_C( 1990809669), INT32_C( -817015526)),
      simde_mm_set_epi32(INT32_C(  622569757), INT32_C( 1173794143), INT32_C(  685390219), INT32_C( 1309107164)) },
    { simde_mm_set_epi32(INT32_C(-1087680391), INT32_C( 1056661878), INT32_C( -847385783), INT32_C( 1172111556)),
      simde_mm_set_epi32(INT32_C( 1557644526), INT32_C( -640816363), INT32_C( 1498664548), INT32_C(  -26761096)),
      simde_mm_set_epi32(INT32_C(  916828163), INT32_C( 1471903452), INT32_C(  -31018513), INT32_C(  324725773)) },
    { simde_mm_set_epi32(INT32_C( -253519263), INT32_C(-1665749954), INT32_C(-1108971746), INT32_C( -797234951)),
      simde_mm_set_epi32(INT32_C(-1588481692), INT32_C( 1983191492), INT32_C(  429969831), INT32_C(  285907454)),
      simde_mm_set_epi32(INT32_C(  394709800), INT32_C(  715877285), INT32_C(-1919269217), INT32_C(-1906206697)) },
    { simde_mm_set_epi32(INT32_C( 1025048627), INT32_C(  475870360), INT32_C( 1357422197), INT32_C(-1008236470)),
      simde_mm_set_epi32(INT32_C(-1420053195), INT32_C( 1212624672), INT32_C(  209820777), INT32_C( -555572396)),
      simde_mm_set_epi32(INT32_C( -207428523), INT32_C( -345751619), INT32_C( 1500918987), INT32_C(  349185727)) },
    { simde_mm_set_epi32(INT32_C(   64730366), INT32_C( 1169670008), INT32_C( 1098115199), INT32_C( -738462226)),
      simde_mm_set_epi32(INT32_C( -991739835), INT32_C(   26982665), INT32_C(-1747857410), INT32_C( -648157645)),
      simde_mm_set_epi32(INT32_C( -964757170), INT32_C( 1898952241), INT32_C( 1234400374), INT32_C(  359652973)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_hadd_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_hadd_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[] = {
    { simde_mm_set_pi16(INT16_C( 30239), INT16_C( 25845), INT16_C( -9936), INT16_C(-27213)),
      simde_mm_set_pi16(INT16_C( -1015), INT16_C(-20873), INT16_C( -7356), INT16_C(-31477)),
      simde_mm_set_pi16(INT16_C(-21888), INT16_C( 26703), INT16_C( -9452), INT16_C( 28387)) },
    { simde_mm_set_pi16(INT16_C(-21918), INT16_C(-12935), INT16_C(-22245), INT16_C(-19824)),
      simde_mm_set_pi16(INT16_C(-12980), INT16_C( 31520), INT16_C(-30945), INT16_C( 24768)),
      simde_mm_set_pi16(INT16_C( 18540), INT16_C( -6177), INT16_C( 30683), INT16_C( 23467)) },
    { simde_mm_set_pi16(INT16_C( 17846), INT16_C(-20510), INT16_C( 28205), INT16_C( 22502)),
      simde_mm_set_pi16(INT16_C( 30262), INT16_C( 19390), INT16_C(-31190), INT16_C(-31299)),
      simde_mm_set_pi16(INT16_C(-15884), INT16_C(  3047), INT16_C( -2664), INT16_C(-14829)) },
    { simde_mm_set_pi16(INT16_C(  4995), INT16_C(  5024), INT16_C(-16313), INT16_C( 32041)),
      simde_mm_set_pi16(INT16_C( 28210), INT16_C( -6335), INT16_C( 24660), INT16_C(  8387)),
      simde_mm_set_pi16(INT16_C( 21875), INT16_C(-32489), INT16_C( 10019), INT16_C( 15728)) },
    { simde_mm_set_pi16(INT16_C( 18074), INT16_C( 21929), INT16_C(-17147), INT16_C(  5980)),
      simde_mm_set_pi16(INT16_C(-29293), INT16_C(-14044), INT16_C( -7765), INT16_C( 15197)),
      simde_mm_set_pi16(INT16_C( 22199), INT16_C(  7432), INT16_C(-25533), INT16_C(-11167)) },
    { simde_mm_set_pi16(INT16_C(  9742), INT16_C( 25346), INT16_C(-16677), INT16_C(-18703)),
      simde_mm_set_pi16(INT16_C( 12116), INT16_C( -6252), INT16_C(-29587), INT16_C( -2727)),
      simde_mm_set_pi16(INT16_C(  5864), INT16_C(-32314), INT16_C(-30448), INT16_C( 30156)) },
    { simde_mm_set_pi16(INT16_C( -2031), INT16_C( 13829), INT16_C( 22178), INT16_C( 10932)),
      simde_mm_set_pi16(INT16_C( -3860), INT16_C(-21638), INT16_C( 11349), INT16_C( 24248)),
      simde_mm_set_pi16(INT16_C(-25498), INT16_C(-29939), INT16_C( 11798), INT16_C(-32426)) },
    { simde_mm_set_pi16(INT16_C( 14725), INT16_C(-26631), INT16_C(  3352), INT16_C( -9709)),
      simde_mm_set_pi16(INT16_C(-29523), INT16_C( -5771), INT16_C(-32233), INT16_C( 27043)),
      simde_mm_set_pi16(INT16_C( 30242), INT16_C( -5190), INT16_C(-11906), INT16_C( -6357)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_hadd_pi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_hadd_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C( 1862318516), INT32_C( -295748827)),
      simde_mm_set_pi32(INT32_C( -228228131), INT32_C(  379370564)),
      simde_mm_set_pi32(INT32_C(  151142433), INT32_C( 1566569689)) },
    { simde_mm_set_pi32(INT32_C(-1716341852), INT32_C(-1567376242)),
      simde_mm_set_pi32(INT32_C(  627426320), INT32_C(-1742027445)),
      simde_mm_set_pi32(INT32_C(-1114601125), INT32_C( 1011249202)) },
    { simde_mm_set_pi32(INT32_C(   -8890841), INT32_C( -182169327)),
      simde_mm_set_pi32(INT32_C( 1909098453), INT32_C( -755712802)),
      simde_mm_set_pi32(INT32_C( 1153385651), INT32_C( -191060168)) },
    { simde_mm_set_pi32(INT32_C( 1354356939), INT32_C(  781213984)),
      simde_mm_set_pi32(INT32_C( 1569601432), INT32_C(  249731348)),
      simde_mm_set_pi32(INT32_C( 1819332780), INT32_C( 2135570923)) },
    { simde_mm_set_pi32(INT32_C( -205846038), INT32_C(  760290342)),
      simde_mm_set_pi32(INT32_C(  261312612), INT32_C(  953650902)),
      simde_mm_set_pi32(INT32_C( 1214963514), INT32_C(  554444304)) },
    { simde_mm_set_pi32(INT32_C( 2091951994), INT32_C( -868981806)),
      simde_mm_set_pi32(INT32_C(  908827748), INT32_C( 1571868066)),
      simde_mm_set_pi32(INT32_C(-1814271482), INT32_C( 1222970188)) },
    { simde_mm_set_pi32(INT32_C(   -4189226), INT32_C(  874353707)),
      simde_mm_set_pi32(INT32_C( -220724007), INT32_C(-1561593917)),
      simde_mm_set_pi32(INT32_C(-1782317924), INT32_C(  870164481)) },
    { simde_mm_set_pi32(INT32_C(-2051599335), INT32_C( 1030472719)),
      simde_mm_set_pi32(INT32_C(   98310968), INT32_C(-1800274139)),
      simde_mm_set_pi32(INT32_C(-1701963171), INT32_C(-1021126616)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_hadd_pi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_hadds_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C( 10807), INT16_C(-14198), INT16_C(-16689), INT16_C( 21115),
                         INT16_C(  -910), INT16_C( 23363), INT16_C(  -393), INT16_C( 24341)),
      simde_mm_set_epi16(INT16_C( -1948), INT16_C( 14976), INT16_C(-17960), INT16_C(-14860),
                         INT16_C(    77), INT16_C( 22746), INT16_C( 31556), INT16_C(-27912)),
      simde_mm_set_epi16(INT16_C( 13028), INT16_C(-32768), INT16_C( 22823), INT16_C(  3644),
                         INT16_C( -3391), INT16_C(  4426), INT16_C( 22453), INT16_C( 23948)) },
    { simde_mm_set_epi16(INT16_C( 16701), INT16_C( 18413), INT16_C( 19864), INT16_C(-30571),
                         INT16_C(  -296), INT16_C( 12833), INT16_C(-21580), INT16_C(  1624)),
      simde_mm_set_epi16(INT16_C(  8006), INT16_C( 10793), INT16_C(  9022), INT16_C(  6615),
                         INT16_C( 21610), INT16_C( 15062), INT16_C( -1089), INT16_C( 11200)),
      simde_mm_set_epi16(INT16_C( 18799), INT16_C( 15637), INT16_C( 32767), INT16_C( 10111),
                         INT16_C( 32767), INT16_C(-10707), INT16_C( 12537), INT16_C(-19956)) },
    { simde_mm_set_epi16(INT16_C(  2796), INT16_C( 22044), INT16_C( -3038), INT16_C( -2824),
                         INT16_C(-32407), INT16_C(-18333), INT16_C(  4913), INT16_C(-15422)),
      simde_mm_set_epi16(INT16_C(-26141), INT16_C(-23205), INT16_C(  4999), INT16_C( 14674),
                         INT16_C( 14693), INT16_C( 30409), INT16_C(  -432), INT16_C( -2349)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C( 19673), INT16_C( 32767), INT16_C( -2781),
                         INT16_C( 24840), INT16_C( -5862), INT16_C(-32768), INT16_C(-10509)) },
    { simde_mm_set_epi16(INT16_C( -4935), INT16_C( -6562), INT16_C( 11817), INT16_C(-25630),
                         INT16_C( -5658), INT16_C(  9543), INT16_C( 31115), INT16_C(-17967)),
      simde_mm_set_epi16(INT16_C(-31577), INT16_C(   203), INT16_C(  2138), INT16_C(-23787),
                         INT16_C(   -59), INT16_C(  6347), INT16_C( -3043), INT16_C(  3327)),
      simde_mm_set_epi16(INT16_C(-31374), INT16_C(-21649), INT16_C(  6288), INT16_C(   284),
                         INT16_C(-11497), INT16_C(-13813), INT16_C(  3885), INT16_C( 13148)) },
    { simde_mm_set_epi16(INT16_C( 23859), INT16_C(-22406), INT16_C( 18603), INT16_C(-25617),
                         INT16_C( 15903), INT16_C(-31522), INT16_C(  6447), INT16_C(-30595)),
      simde_mm_set_epi16(INT16_C(-12207), INT16_C(-15255), INT16_C( 20239), INT16_C(-16128),
                         INT16_C(  1700), INT16_C( -5295), INT16_C(-26969), INT16_C(  1404)),
      simde_mm_set_epi16(INT16_C(-27462), INT16_C(  4111), INT16_C( -3595), INT16_C(-25565),
                         INT16_C(  1453), INT16_C( -7014), INT16_C(-15619), INT16_C(-24148)) },
    { simde_mm_set_epi16(INT16_C(-23882), INT16_C( 20710), INT16_C(-17743), INT16_C(-12929),
                         INT16_C(-26672), INT16_C(  7004), INT16_C( -7681), INT16_C(-15327)),
      simde_mm_set_epi16(INT16_C(  9169), INT16_C(-20513), INT16_C( 32026), INT16_C(-32016),
                         INT16_C( 11237), INT16_C( 13212), INT16_C(  5807), INT16_C(-22948)),
      simde_mm_set_epi16(INT16_C(-11344), INT16_C(    10), INT16_C( 24449), INT16_C(-17141),
                         INT16_C( -3172), INT16_C(-30672), INT16_C(-19668), INT16_C(-23008)) },
    { simde_mm_set_epi16(INT16_C( -1265), INT16_C(-31938), INT16_C(   205), INT16_C( -2042),
                         INT16_C(  8951), INT16_C( -9923), INT16_C( -5120), INT16_C( 21641)),
      simde_mm_set_epi16(INT16_C( 29316), INT16_C(-11244), INT16_C(-12652), INT16_C( 22497),
                         INT16_C(-29075), INT16_C(-14808), INT16_C(-17541), INT16_C( -2061)),
      simde_mm_set_epi16(INT16_C( 18072), INT16_C(  9845), INT16_C(-32768), INT16_C(-19602),
                         INT16_C(-32768), INT16_C( -1837), INT16_C(  -972), INT16_C( 16521)) },
    { simde_mm_set_epi16(INT16_C(  4920), INT16_C( 25576), INT16_C(-20472), INT16_C(  4642),
                         INT16_C( 22777), INT16_C( 17155), INT16_C(-22672), INT16_C(  7646)),
      simde_mm_set_epi16(INT16_C(-28362), INT16_C(  2256), INT16_C(  1158), INT16_C(-32564),
                         INT16_C( 15997), INT16_C(  8308), INT16_C( -8252), INT16_C( 27950)),
      simde_mm_set_epi16(INT16_C(-26106), INT16_C(-31406), INT16_C( 24305), INT16_C( 19698),
                         INT16_C( 30496), INT16_C(-15830), INT16_C( 32767), INT16_C(-15026)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_hadds_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_hadds_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( -2215), INT16_C( -3731), INT16_C( 30165), INT16_C(-21248)),
      simde_mm_set_pi16(INT16_C( 21370), INT16_C(  7316), INT16_C(-29830), INT16_C( -6216)),
      simde_mm_set_pi16(INT16_C( 28686), INT16_C(-32768), INT16_C( -5946), INT16_C(  8917)) },
    { simde_mm_set_pi16(INT16_C( -8625), INT16_C( -7885), INT16_C(  3501), INT16_C( -8065)),
      simde_mm_set_pi16(INT16_C( -9522), INT16_C(-24178), INT16_C( 32056), INT16_C( 21007)),
      simde_mm_set_pi16(INT16_C(-32768), INT16_C( 32767), INT16_C(-16510), INT16_C( -4564)) },
    { simde_mm_set_pi16(INT16_C(-17715), INT16_C( 16677), INT16_C( 21397), INT16_C(-29267)),
      simde_mm_set_pi16(INT16_C(   -49), INT16_C(-24556), INT16_C(  4165), INT16_C(  5183)),
      simde_mm_set_pi16(INT16_C(-24605), INT16_C(  9348), INT16_C( -1038), INT16_C( -7870)) },
    { simde_mm_set_pi16(INT16_C( 18073), INT16_C( 17217), INT16_C(-23152), INT16_C( -2700)),
      simde_mm_set_pi16(INT16_C( 24553), INT16_C(-26123), INT16_C( 21553), INT16_C(-14922)),
      simde_mm_set_pi16(INT16_C( -1570), INT16_C(  6631), INT16_C( 32767), INT16_C(-25852)) },
    { simde_mm_set_pi16(INT16_C( -8686), INT16_C(-29702), INT16_C(   977), INT16_C( -5566)),
      simde_mm_set_pi16(INT16_C( 10007), INT16_C( 21523), INT16_C(-17042), INT16_C(  8204)),
      simde_mm_set_pi16(INT16_C( 31530), INT16_C( -8838), INT16_C(-32768), INT16_C( -4589)) },
    { simde_mm_set_pi16(INT16_C( 20389), INT16_C( 12774), INT16_C( 24895), INT16_C(-10733)),
      simde_mm_set_pi16(INT16_C(  4070), INT16_C( 21710), INT16_C(-25629), INT16_C( 32624)),
      simde_mm_set_pi16(INT16_C( 25780), INT16_C(  6995), INT16_C( 32767), INT16_C( 14162)) },
    { simde_mm_set_pi16(INT16_C(-26507), INT16_C(-18711), INT16_C(   -30), INT16_C(-27258)),
      simde_mm_set_pi16(INT16_C( 30229), INT16_C(-20659), INT16_C(-12166), INT16_C( 11942)),
      simde_mm_set_pi16(INT16_C(  9570), INT16_C(  -224), INT16_C(-32768), INT16_C(-27288)) },
    { simde_mm_set_pi16(INT16_C(  8239), INT16_C(  4822), INT16_C( -7926), INT16_C(  5523)),
      simde_mm_set_pi16(INT16_C(  4807), INT16_C(-26347), INT16_C( 27248), INT16_C(-14552)),
      simde_mm_set_pi16(INT16_C(-21540), INT16_C( 12696), INT16_C( 13061), INT16_C( -2403)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_hadds_pi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_hsub_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-23858), INT16_C( -4873), INT16_C( 25529), INT16_C( 28813),
                         INT16_C( 32687), INT16_C(  7141), INT16_C(-18881), INT16_C(-22018)),
      simde_mm_set_epi16(INT16_C( 18662), INT16_C( -3351), INT16_C(-22586), INT16_C( 17125),
                         INT16_C( 13505), INT16_C(  8156), INT16_C(-22303), INT16_C(   260)),
      simde_mm_set_epi16(INT16_C(-22013), INT16_C(-25825), INT16_C( -5349), INT16_C( 22563),
                         INT16_C( 18985), INT16_C(  3284), INT16_C(-25546), INT16_C( -3137)) },
    { simde_mm_set_epi16(INT16_C(-16905), INT16_C(-23899), INT16_C( 22124), INT16_C( -9244),
                         INT16_C( -8704), INT16_C(-14521), INT16_C( 29325), INT16_C(  9647)),
      simde_mm_set_epi16(INT16_C(-14947), INT16_C( 11007), INT16_C(-31280), INT16_C(-24736),
                         INT16_C( 12124), INT16_C( 14146), INT16_C(  2823), INT16_C( 31264)),
      simde_mm_set_epi16(INT16_C( 25954), INT16_C(  6544), INT16_C(  2022), INT16_C( 28441),
                         INT16_C( -6994), INT16_C(-31368), INT16_C( -5817), INT16_C(-19678)) },
    { simde_mm_set_epi16(INT16_C( 20412), INT16_C(-23342), INT16_C(-11221), INT16_C( 22543),
                         INT16_C( 31042), INT16_C( 25207), INT16_C( 22911), INT16_C( 28646)),
      simde_mm_set_epi16(INT16_C( 20001), INT16_C(-23713), INT16_C( -2107), INT16_C( -9501),
                         INT16_C(-11898), INT16_C( 13884), INT16_C(-15609), INT16_C( 29959)),
      simde_mm_set_epi16(INT16_C( 21822), INT16_C( -7394), INT16_C( 25782), INT16_C(-19968),
                         INT16_C( 21782), INT16_C(-31772), INT16_C( -5835), INT16_C(  5735)) },
    { simde_mm_set_epi16(INT16_C(-21670), INT16_C( 22724), INT16_C(-29935), INT16_C(-11113),
                         INT16_C(-27399), INT16_C(  1226), INT16_C(-32445), INT16_C( 25109)),
      simde_mm_set_epi16(INT16_C(  6376), INT16_C( 14599), INT16_C(-22701), INT16_C( 30172),
                         INT16_C( 12539), INT16_C(-29335), INT16_C(-14900), INT16_C(  5269)),
      simde_mm_set_epi16(INT16_C(  8223), INT16_C(-12663), INT16_C( 23662), INT16_C( 20169),
                         INT16_C(-21142), INT16_C( 18822), INT16_C( 28625), INT16_C( -7982)) },
    { simde_mm_set_epi16(INT16_C( 12440), INT16_C(-24086), INT16_C( 16668), INT16_C( -2312),
                         INT16_C(  5277), INT16_C(  2451), INT16_C( 29149), INT16_C( 16634)),
      simde_mm_set_epi16(INT16_C(-13694), INT16_C( 20767), INT16_C( 26711), INT16_C(-18489),
                         INT16_C(  7419), INT16_C( 20190), INT16_C(  6918), INT16_C(-26228)),
      simde_mm_set_epi16(INT16_C(-31075), INT16_C( 20336), INT16_C( 12771), INT16_C( 32390),
                         INT16_C( 29010), INT16_C(-18980), INT16_C( -2826), INT16_C(-12515)) },
    { simde_mm_set_epi16(INT16_C(-18064), INT16_C(-22080), INT16_C( 31211), INT16_C(-24234),
                         INT16_C( 17815), INT16_C( 19504), INT16_C(-18918), INT16_C(-22478)),
      simde_mm_set_epi16(INT16_C(  1846), INT16_C( 29599), INT16_C( -8713), INT16_C(-21885),
                         INT16_C(-32548), INT16_C(  8452), INT16_C( -6739), INT16_C(-17538)),
      simde_mm_set_epi16(INT16_C( 27753), INT16_C(-13172), INT16_C(-24536), INT16_C(-10799),
                         INT16_C( -4016), INT16_C( 10091), INT16_C(  1689), INT16_C( -3560)) },
    { simde_mm_set_epi16(INT16_C(-26649), INT16_C( 24453), INT16_C( 28697), INT16_C( 11094),
                         INT16_C( 15458), INT16_C(-20509), INT16_C( 21060), INT16_C( 31323)),
      simde_mm_set_epi16(INT16_C( 13710), INT16_C(-23834), INT16_C(  8691), INT16_C(  6543),
                         INT16_C( 24367), INT16_C(  6903), INT16_C( -2074), INT16_C(-12200)),
      simde_mm_set_epi16(INT16_C( 27992), INT16_C( -2148), INT16_C(-17464), INT16_C(-10126),
                         INT16_C(-14434), INT16_C(-17603), INT16_C( 29569), INT16_C( 10263)) },
    { simde_mm_set_epi16(INT16_C( 30864), INT16_C( 20241), INT16_C( 16902), INT16_C( 20663),
                         INT16_C(-20841), INT16_C(-32594), INT16_C(-27087), INT16_C( 20516)),
      simde_mm_set_epi16(INT16_C( 20660), INT16_C( -7551), INT16_C(-22127), INT16_C( 27693),
                         INT16_C( -9668), INT16_C(-19341), INT16_C( 24481), INT16_C(-15352)),
      simde_mm_set_epi16(INT16_C(-28211), INT16_C(-15716), INT16_C( -9673), INT16_C( 25703),
                         INT16_C(-10623), INT16_C(  3761), INT16_C(-11753), INT16_C(-17933)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_hsub_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_hsub_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( -479907977), INT32_C( -696539570), INT32_C(-1398601783), INT32_C(  536165734)),
      simde_mm_set_epi32(INT32_C(    5565618), INT32_C( -381463958), INT32_C(   42537933), INT32_C( -711333282)),
      simde_mm_set_epi32(INT32_C( -387029576), INT32_C( -753871215), INT32_C( -216631593), INT32_C( 1934767517)) },
    { simde_mm_set_epi32(INT32_C(  818650962), INT32_C(  824145104), INT32_C(-1844195506), INT32_C(-1825969675)),
      simde_mm_set_epi32(INT32_C( 2083359703), INT32_C(-2060086869), INT32_C( 1669409252), INT32_C(-1777354497)),
      simde_mm_set_epi32(INT32_C(  151520724), INT32_C(  848203547), INT32_C(    5494142), INT32_C(   18225831)) },
    { simde_mm_set_epi32(INT32_C(-1587888977), INT32_C( -591401974), INT32_C( -147902824), INT32_C( 1830002670)),
      simde_mm_set_epi32(INT32_C(  399705498), INT32_C(-1859698091), INT32_C( 1482907200), INT32_C( 1392342146)),
      simde_mm_set_epi32(INT32_C( 2035563707), INT32_C(  -90565054), INT32_C(  996487003), INT32_C( 1977905494)) },
    { simde_mm_set_epi32(INT32_C(-1814888934), INT32_C(-1949362692), INT32_C( 1433235748), INT32_C( -537299867)),
      simde_mm_set_epi32(INT32_C( -273399868), INT32_C( 1316606109), INT32_C( 1234934819), INT32_C( 2143067132)),
      simde_mm_set_epi32(INT32_C( 1590005977), INT32_C(  908132313), INT32_C( -134473758), INT32_C(-1970535615)) },
    { simde_mm_set_epi32(INT32_C(-2102962425), INT32_C(  -70755375), INT32_C(-2145299060), INT32_C(  305166546)),
      simde_mm_set_epi32(INT32_C( -140541285), INT32_C(-1875101359), INT32_C(-1065221069), INT32_C( 2018475568)),
      simde_mm_set_epi32(INT32_C(-1734560074), INT32_C(-1211270659), INT32_C( 2032207050), INT32_C(-1844501690)) },
    { simde_mm_set_epi32(INT32_C( -996291163), INT32_C( -192227992), INT32_C(-1330314074), INT32_C( -761581524)),
      simde_mm_set_epi32(INT32_C(-1442240024), INT32_C(-1983945374), INT32_C( 1651588405), INT32_C(-2097842058)),
      simde_mm_set_epi32(INT32_C( -541705350), INT32_C(  545536833), INT32_C(  804063171), INT32_C(  568732550)) },
    { simde_mm_set_epi32(INT32_C(-1780627386), INT32_C(  769411793), INT32_C( 1731523542), INT32_C(  660129568)),
      simde_mm_set_epi32(INT32_C( -469002090), INT32_C( -974572540), INT32_C(  829774662), INT32_C(-1194362973)),
      simde_mm_set_epi32(INT32_C( -505570450), INT32_C(-2024137635), INT32_C(-1744928117), INT32_C(-1071393974)) },
    { simde_mm_set_epi32(INT32_C(  -87824878), INT32_C(-2145465811), INT32_C(  968986944), INT32_C(  617458465)),
      simde_mm_set_epi32(INT32_C( 1888345900), INT32_C( 1243027853), INT32_C(-2115148095), INT32_C( -711680076)),
      simde_mm_set_epi32(INT32_C( -645318047), INT32_C( 1403468019), INT32_C(-2057640933), INT32_C( -351528479)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_hsub_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_hsub_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C(-21341), INT16_C(  1993), INT16_C(  8181), INT16_C( 15718)),
      simde_mm_set_pi16(INT16_C( -7323), INT16_C( 12151), INT16_C(-10629), INT16_C(-22962)),
      simde_mm_set_pi16(INT16_C( 19474), INT16_C(-12333), INT16_C( 23334), INT16_C(  7537)) },
    { simde_mm_set_pi16(INT16_C(   649), INT16_C(  5069), INT16_C(-10855), INT16_C( -5538)),
      simde_mm_set_pi16(INT16_C(    84), INT16_C( -4942), INT16_C( -5821), INT16_C( 21098)),
      simde_mm_set_pi16(INT16_C( -5026), INT16_C( 26919), INT16_C(  4420), INT16_C(  5317)) },
    { simde_mm_set_pi16(INT16_C(-28141), INT16_C(-12466), INT16_C(-27863), INT16_C( -5643)),
      simde_mm_set_pi16(INT16_C( 12491), INT16_C(-24750), INT16_C( 12575), INT16_C( 29904)),
      simde_mm_set_pi16(INT16_C( 28295), INT16_C( 17329), INT16_C( 15675), INT16_C( 22220)) },
    { simde_mm_set_pi16(INT16_C( 25473), INT16_C( 10724), INT16_C(-27121), INT16_C(-18177)),
      simde_mm_set_pi16(INT16_C( 31789), INT16_C(-29737), INT16_C(-31435), INT16_C(-28245)),
      simde_mm_set_pi16(INT16_C(  4010), INT16_C(  3190), INT16_C(-14749), INT16_C(  8944)) },
    { simde_mm_set_pi16(INT16_C( -2257), INT16_C( 11928), INT16_C( 27923), INT16_C(-24594)),
      simde_mm_set_pi16(INT16_C(-24230), INT16_C(-17233), INT16_C( -9025), INT16_C( -5110)),
      simde_mm_set_pi16(INT16_C(  6997), INT16_C(  3915), INT16_C( 14185), INT16_C( 13019)) },
    { simde_mm_set_pi16(INT16_C( 22627), INT16_C( 24128), INT16_C( 21245), INT16_C( 29826)),
      simde_mm_set_pi16(INT16_C(  6099), INT16_C(  1434), INT16_C(-28377), INT16_C( 16981)),
      simde_mm_set_pi16(INT16_C( -4665), INT16_C(-20178), INT16_C(  1501), INT16_C(  8581)) },
    { simde_mm_set_pi16(INT16_C( 21869), INT16_C( 28964), INT16_C( -8199), INT16_C( 29797)),
      simde_mm_set_pi16(INT16_C(-27694), INT16_C(  -486), INT16_C(-29745), INT16_C(  5628)),
      simde_mm_set_pi16(INT16_C( 27208), INT16_C(-30163), INT16_C(  7095), INT16_C(-27540)) },
    { simde_mm_set_pi16(INT16_C( 18843), INT16_C(-25565), INT16_C( 32700), INT16_C(-25604)),
      simde_mm_set_pi16(INT16_C( -4172), INT16_C( 16324), INT16_C( 20089), INT16_C(-12131)),
      simde_mm_set_pi16(INT16_C( 20496), INT16_C(-32220), INT16_C( 21128), INT16_C(  7232)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_hsub_pi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_hsub_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C(-1398601783), INT32_C(  536165734)),
      simde_mm_set_pi32(INT32_C( -479907977), INT32_C( -696539570)),
      simde_mm_set_pi32(INT32_C( -216631593), INT32_C( 1934767517)) },
    { simde_mm_set_pi32(INT32_C(   42537933), INT32_C( -711333282)),
      simde_mm_set_pi32(INT32_C(    5565618), INT32_C( -381463958)),
      simde_mm_set_pi32(INT32_C( -387029576), INT32_C( -753871215)) },
    { simde_mm_set_pi32(INT32_C(-1844195506), INT32_C(-1825969675)),
      simde_mm_set_pi32(INT32_C(  818650962), INT32_C(  824145104)),
      simde_mm_set_pi32(INT32_C(    5494142), INT32_C(   18225831)) },
    { simde_mm_set_pi32(INT32_C( 1669409252), INT32_C(-1777354497)),
      simde_mm_set_pi32(INT32_C( 2083359703), INT32_C(-2060086869)),
      simde_mm_set_pi32(INT32_C(  151520724), INT32_C(  848203547)) },
    { simde_mm_set_pi32(INT32_C( -147902824), INT32_C( 1830002670)),
      simde_mm_set_pi32(INT32_C(-1587888977), INT32_C( -591401974)),
      simde_mm_set_pi32(INT32_C(  996487003), INT32_C( 1977905494)) },
    { simde_mm_set_pi32(INT32_C( 1482907200), INT32_C( 1392342146)),
      simde_mm_set_pi32(INT32_C(  399705498), INT32_C(-1859698091)),
      simde_mm_set_pi32(INT32_C( 2035563707), INT32_C(  -90565054)) },
    { simde_mm_set_pi32(INT32_C( 1433235748), INT32_C( -537299867)),
      simde_mm_set_pi32(INT32_C(-1814888934), INT32_C(-1949362692)),
      simde_mm_set_pi32(INT32_C( -134473758), INT32_C(-1970535615)) },
    { simde_mm_set_pi32(INT32_C( 1234934819), INT32_C( 2143067132)),
      simde_mm_set_pi32(INT32_C( -273399868), INT32_C( 1316606109)),
      simde_mm_set_pi32(INT32_C( 1590005977), INT32_C(  908132313)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_hsub_pi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_hsubs_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C( 13774), INT16_C(-29689), INT16_C( 10999), INT16_C( -6147),
                         INT16_C(-29800), INT16_C( 18242), INT16_C( 25067), INT16_C( -9729)),
      simde_mm_set_epi16(INT16_C( 12949), INT16_C( 20521), INT16_C(-28557), INT16_C(-22012),
                         INT16_C(-30915), INT16_C( -6461), INT16_C( 26181), INT16_C(  4500)),
      simde_mm_set_epi16(INT16_C(  7572), INT16_C(  6545), INT16_C( 24454), INT16_C(-21681),
                         INT16_C(-32768), INT16_C(-17146), INT16_C( 32767), INT16_C(-32768)) },
    { simde_mm_set_epi16(INT16_C( 29988), INT16_C(-16786), INT16_C( 24082), INT16_C(-25968),
                         INT16_C( 12374), INT16_C( 28178), INT16_C(  2246), INT16_C(-16612)),
      simde_mm_set_epi16(INT16_C( 21001), INT16_C( 21933), INT16_C(-28339), INT16_C(-21262),
                         INT16_C(-18820), INT16_C( -7213), INT16_C(-31232), INT16_C( -7091)),
      simde_mm_set_epi16(INT16_C(   932), INT16_C(  7077), INT16_C( 11607), INT16_C( 24141),
                         INT16_C(-32768), INT16_C(-32768), INT16_C( 15804), INT16_C(-18858)) },
    { simde_mm_set_epi16(INT16_C( -2178), INT16_C(  7231), INT16_C(  1749), INT16_C(-11837),
                         INT16_C( 29652), INT16_C(-23237), INT16_C( -3549), INT16_C(-11367)),
      simde_mm_set_epi16(INT16_C(-28533), INT16_C( 19954), INT16_C( 15418), INT16_C( 23837),
                         INT16_C( 27116), INT16_C( -2562), INT16_C(-12163), INT16_C( 27809)),
      simde_mm_set_epi16(INT16_C( 32767), INT16_C(  8419), INT16_C(-29678), INT16_C( 32767),
                         INT16_C(  9409), INT16_C(-13586), INT16_C(-32768), INT16_C( -7818)) },
    { simde_mm_set_epi16(INT16_C(  9359), INT16_C( 10457), INT16_C( -9481), INT16_C(  7337),
                         INT16_C( -7865), INT16_C( -8059), INT16_C(-27714), INT16_C(-26625)),
      simde_mm_set_epi16(INT16_C(  1382), INT16_C(  7017), INT16_C(  1603), INT16_C( 12659),
                         INT16_C(-15886), INT16_C( 13804), INT16_C( 23429), INT16_C(-30064)),
      simde_mm_set_epi16(INT16_C(  5635), INT16_C( 11056), INT16_C( 29690), INT16_C(-32768),
                         INT16_C(  1098), INT16_C( 16818), INT16_C(  -194), INT16_C(  1089)) },
    { simde_mm_set_epi16(INT16_C( -6864), INT16_C( 32077), INT16_C(-12988), INT16_C(-19165),
                         INT16_C(-26014), INT16_C(  8246), INT16_C( 27640), INT16_C( 25410)),
      simde_mm_set_epi16(INT16_C( 19800), INT16_C(-22857), INT16_C( -2668), INT16_C( 12159),
                         INT16_C(  9895), INT16_C( -9099), INT16_C(-14776), INT16_C(  4666)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C( 14827), INT16_C(-18994), INT16_C( 19442),
                         INT16_C( 32767), INT16_C( -6177), INT16_C( 32767), INT16_C( -2230)) },
    { simde_mm_set_epi16(INT16_C( 19814), INT16_C( 25204), INT16_C(  1688), INT16_C(-25917),
                         INT16_C( -4068), INT16_C(-22336), INT16_C( 14502), INT16_C( 27222)),
      simde_mm_set_epi16(INT16_C(-18197), INT16_C( 12530), INT16_C(  8023), INT16_C(  5629),
                         INT16_C( 32454), INT16_C(  4791), INT16_C( -4481), INT16_C( 19744)),
      simde_mm_set_epi16(INT16_C( 30727), INT16_C( -2394), INT16_C(-27663), INT16_C( 24225),
                         INT16_C(  5390), INT16_C(-27605), INT16_C(-18268), INT16_C( 12720)) },
    { simde_mm_set_epi16(INT16_C( -7171), INT16_C( 12346), INT16_C(   491), INT16_C( -3389),
                         INT16_C(-18032), INT16_C( -9295), INT16_C(-27339), INT16_C( 18234)),
      simde_mm_set_epi16(INT16_C( -7625), INT16_C( 17942), INT16_C(-16463), INT16_C( 19005),
                         INT16_C(-15122), INT16_C( 15452), INT16_C( 28218), INT16_C(  7688)),
      simde_mm_set_epi16(INT16_C( 25567), INT16_C( 32767), INT16_C( 30574), INT16_C(-20530),
                         INT16_C( 19517), INT16_C( -3880), INT16_C(  8737), INT16_C( 32767)) },
    { simde_mm_set_epi16(INT16_C(   680), INT16_C(  3648), INT16_C(  9121), INT16_C( 26085),
                         INT16_C( 21203), INT16_C( -8528), INT16_C( 17475), INT16_C(-10092)),
      simde_mm_set_epi16(INT16_C(  9701), INT16_C( 32227), INT16_C(  -294), INT16_C(-17758),
                         INT16_C( 13795), INT16_C(-28706), INT16_C( 28077), INT16_C(-10927)),
      simde_mm_set_epi16(INT16_C( 22526), INT16_C(-17464), INT16_C(-32768), INT16_C(-32768),
                         INT16_C(  2968), INT16_C( 16964), INT16_C(-29731), INT16_C(-27567)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_hsubs_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_hsubs_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C(-29800), INT16_C( 18242), INT16_C( 25067), INT16_C( -9729)),
      simde_mm_set_pi16(INT16_C( 13774), INT16_C(-29689), INT16_C( 10999), INT16_C( -6147)),
      simde_mm_set_pi16(INT16_C(-32768), INT16_C(-17146), INT16_C( 32767), INT16_C(-32768)) },
    { simde_mm_set_pi16(INT16_C(-30915), INT16_C( -6461), INT16_C( 26181), INT16_C(  4500)),
      simde_mm_set_pi16(INT16_C( 12949), INT16_C( 20521), INT16_C(-28557), INT16_C(-22012)),
      simde_mm_set_pi16(INT16_C(  7572), INT16_C(  6545), INT16_C( 24454), INT16_C(-21681)) },
    { simde_mm_set_pi16(INT16_C( 12374), INT16_C( 28178), INT16_C(  2246), INT16_C(-16612)),
      simde_mm_set_pi16(INT16_C( 29988), INT16_C(-16786), INT16_C( 24082), INT16_C(-25968)),
      simde_mm_set_pi16(INT16_C(-32768), INT16_C(-32768), INT16_C( 15804), INT16_C(-18858)) },
    { simde_mm_set_pi16(INT16_C(-18820), INT16_C( -7213), INT16_C(-31232), INT16_C( -7091)),
      simde_mm_set_pi16(INT16_C( 21001), INT16_C( 21933), INT16_C(-28339), INT16_C(-21262)),
      simde_mm_set_pi16(INT16_C(   932), INT16_C(  7077), INT16_C( 11607), INT16_C( 24141)) },
    { simde_mm_set_pi16(INT16_C( 29652), INT16_C(-23237), INT16_C( -3549), INT16_C(-11367)),
      simde_mm_set_pi16(INT16_C( -2178), INT16_C(  7231), INT16_C(  1749), INT16_C(-11837)),
      simde_mm_set_pi16(INT16_C(  9409), INT16_C(-13586), INT16_C(-32768), INT16_C( -7818)) },
    { simde_mm_set_pi16(INT16_C( 27116), INT16_C( -2562), INT16_C(-12163), INT16_C( 27809)),
      simde_mm_set_pi16(INT16_C(-28533), INT16_C( 19954), INT16_C( 15418), INT16_C( 23837)),
      simde_mm_set_pi16(INT16_C( 32767), INT16_C(  8419), INT16_C(-29678), INT16_C( 32767)) },
    { simde_mm_set_pi16(INT16_C( -7865), INT16_C( -8059), INT16_C(-27714), INT16_C(-26625)),
      simde_mm_set_pi16(INT16_C(  9359), INT16_C( 10457), INT16_C( -9481), INT16_C(  7337)),
      simde_mm_set_pi16(INT16_C(  1098), INT16_C( 16818), INT16_C(  -194), INT16_C(  1089)) },
    { simde_mm_set_pi16(INT16_C(-15886), INT16_C( 13804), INT16_C( 23429), INT16_C(-30064)),
      simde_mm_set_pi16(INT16_C(  1382), INT16_C(  7017), INT16_C(  1603), INT16_C( 12659)),
      simde_mm_set_pi16(INT16_C(  5635), INT16_C( 11056), INT16_C( 29690), INT16_C(-32768)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_hsubs_pi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_maddubs_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C( 15493), INT16_C( 22461), INT16_C( 11604), INT16_C( -5120),
                         INT16_C( -1917), INT16_C( 28081), INT16_C( -7857), INT16_C( -9579)),
      simde_mm_set_epi16(INT16_C(-17211), INT16_C(-30029), INT16_C( -1981), INT16_C(-27918),
                         INT16_C( 14022), INT16_C(  5514), INT16_C(-12885), INT16_C(-14901)),
      simde_mm_set_epi16(INT16_C(-11927), INT16_C(-24819), INT16_C(  5268), INT16_C(-25960),
                         INT16_C(  5794), INT16_C(-18597), INT16_C(-18190), INT16_C(-20759)) },
    { simde_mm_set_epi16(INT16_C( -7054), INT16_C( -8494), INT16_C(  8961), INT16_C(-19084),
                         INT16_C( 22900), INT16_C( -5832), INT16_C(  -878), INT16_C(-28730)),
      simde_mm_set_epi16(INT16_C( 16680), INT16_C( 10125), INT16_C( 28247), INT16_C( -7463),
                         INT16_C( 29138), INT16_C(-24062), INT16_C( 20722), INT16_C( 30405)),
      simde_mm_set_epi16(INT16_C( 19380), INT16_C(-15492), INT16_C(  3937), INT16_C( -9954),
                         INT16_C(  4721), INT16_C(-21790), INT16_C( 18116), INT16_C(  5192)) },
    { simde_mm_set_epi16(INT16_C(-21155), INT16_C( -1267), INT16_C( 31098), INT16_C( 22236),
                         INT16_C( 23324), INT16_C(  9270), INT16_C(-17519), INT16_C(-24780)),
      simde_mm_set_epi16(INT16_C( 14051), INT16_C( 15063), INT16_C(-16168), INT16_C( 19040),
                         INT16_C(-31143), INT16_C(   -88), INT16_C( 16260), INT16_C(  4496)),
      simde_mm_set_epi16(INT16_C(  6645), INT16_C( 14025), INT16_C(-12624), INT16_C( 27484),
                         INT16_C( -8610), INT16_C( -4788), INT16_C( -6199), INT16_C( -3121)) },
    { simde_mm_set_epi16(INT16_C( 29655), INT16_C(-19145), INT16_C( -3742), INT16_C(  3274),
                         INT16_C(-30407), INT16_C( 20021), INT16_C(  8791), INT16_C(-15030)),
      simde_mm_set_epi16(INT16_C(-15707), INT16_C(  1220), INT16_C(-14387), INT16_C( 26680),
                         INT16_C(-20978), INT16_C(-10274), INT16_C( -7620), INT16_C(-25428)),
      simde_mm_set_epi16(INT16_C(-26695), INT16_C( -2576), INT16_C(-18735), INT16_C( 12560),
                         INT16_C(-10436), INT16_C( -5000), INT16_C(  4200), INT16_C(-25916)) },
    { simde_mm_set_epi16(INT16_C( 19302), INT16_C(  4146), INT16_C(  -748), INT16_C(-17059),
                         INT16_C( 29288), INT16_C( 26862), INT16_C( 15826), INT16_C(-30487)),
      simde_mm_set_epi16(INT16_C( 23617), INT16_C(-30379), INT16_C( -1032), INT16_C( 16592),
                         INT16_C(-22941), INT16_C(-20372), INT16_C( -4767), INT16_C( 13780)),
      simde_mm_set_epi16(INT16_C( 13530), INT16_C(  2346), INT16_C( -1425), INT16_C(  7632),
                         INT16_C(    36), INT16_C( 17384), INT16_C( 19211), INT16_C( -3044)) },
    { simde_mm_set_epi16(INT16_C( -7786), INT16_C(-25679), INT16_C(-13833), INT16_C(-11578),
                         INT16_C( 24961), INT16_C( 10246), INT16_C( 24603), INT16_C(-13878)),
      simde_mm_set_epi16(INT16_C(-29054), INT16_C(-30650), INT16_C( 25695), INT16_C(  5158),
                         INT16_C(-10198), INT16_C( 23562), INT16_C( 16456), INT16_C( 10990)),
      simde_mm_set_epi16(INT16_C(-32768), INT16_C( -6210), INT16_C( 32767), INT16_C( 11724),
                         INT16_C(  1538), INT16_C(  3740), INT16_C(  8088), INT16_C(  4806)) },
    { simde_mm_set_epi16(INT16_C( 31378), INT16_C(-14053), INT16_C( 22339), INT16_C(-31750),
                         INT16_C( 14700), INT16_C(-30571), INT16_C(-16614), INT16_C( 25221)),
      simde_mm_set_epi16(INT16_C( 16511), INT16_C(-30158), INT16_C( 23618), INT16_C(  2395),
                         INT16_C(  9980), INT16_C( -5004), INT16_C( 30350), INT16_C(-22435)),
      simde_mm_set_epi16(INT16_C( 26350), INT16_C(-22368), INT16_C( 12426), INT16_C( 23929),
                         INT16_C(  1734), INT16_C( 14564), INT16_C( 19574), INT16_C(  3745)) },
    { simde_mm_set_epi16(INT16_C(-12886), INT16_C(-13371), INT16_C(-24575), INT16_C(  2166),
                         INT16_C(-32184), INT16_C( 25064), INT16_C( 25148), INT16_C( 10977)),
      simde_mm_set_epi16(INT16_C(   708), INT16_C(-29843), INT16_C( 22599), INT16_C(  9442),
                         INT16_C( 11889), INT16_C( -8420), INT16_C(  9406), INT16_C( 19673)),
      simde_mm_set_epi16(INT16_C( -9790), INT16_C( -2278), INT16_C( 14151), INT16_C( -3252),
                         INT16_C( 14116), INT16_C(  3295), INT16_C(  -432), INT16_C( -5583)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_maddubs_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_maddubs_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( 29462), INT16_C( 30267), INT16_C( 31248), INT16_C(-26353)),
      simde_mm_set_pi16(INT16_C(-24799), INT16_C(-27427), INT16_C( -6247), INT16_C( -7142)),
      simde_mm_set_pi16(INT16_C(-10429), INT16_C(-14809), INT16_C( -4698), INT16_C( -3894)) },
    { simde_mm_set_pi16(INT16_C( -7018), INT16_C( -6648), INT16_C( -6109), INT16_C(  1128)),
      simde_mm_set_pi16(INT16_C( 25271), INT16_C( 11818), INT16_C(-26313), INT16_C( -2951)),
      simde_mm_set_pi16(INT16_C( 11394), INT16_C( 10916), INT16_C(-21971), INT16_C( 12536)) },
    { simde_mm_set_pi16(INT16_C(-15639), INT16_C(  1685), INT16_C( -7183), INT16_C( 19750)),
      simde_mm_set_pi16(INT16_C( 31264), INT16_C(  8558), INT16_C(-19962), INT16_C(  4628)),
      simde_mm_set_pi16(INT16_C( 31124), INT16_C( 16588), INT16_C(-16260), INT16_C(  2146)) },
    { simde_mm_set_pi16(INT16_C( -4290), INT16_C(-23576), INT16_C(  7882), INT16_C( 31527)),
      simde_mm_set_pi16(INT16_C( 18110), INT16_C(   507), INT16_C( -9066), INT16_C(-25108)),
      simde_mm_set_pi16(INT16_C( 12638), INT16_C(  -997), INT16_C(-22492), INT16_C(-12957)) },
    { simde_mm_set_pi16(INT16_C( -9260), INT16_C(-12922), INT16_C(-26200), INT16_C( 24690)),
      simde_mm_set_pi16(INT16_C( -3479), INT16_C( 31960), INT16_C( 14283), INT16_C( 24092)),
      simde_mm_set_pi16(INT16_C( 19194), INT16_C( 20060), INT16_C(  -489), INT16_C( 12216)) },
    { simde_mm_set_pi16(INT16_C( 10328), INT16_C( -7704), INT16_C( -7564), INT16_C(  7510)),
      simde_mm_set_pi16(INT16_C(  6722), INT16_C(-24880), INT16_C( 15270), INT16_C( 20202)),
      simde_mm_set_pi16(INT16_C(  6848), INT16_C(-32768), INT16_C(  2894), INT16_C(   370)) },
    { simde_mm_set_pi16(INT16_C( 18163), INT16_C(  1844), INT16_C( 20414), INT16_C( 28251)),
      simde_mm_set_pi16(INT16_C( 28698), INT16_C( -5912), INT16_C( 10712), INT16_C(  -757)),
      simde_mm_set_pi16(INT16_C( 14158), INT16_C( -1416), INT16_C( -4361), INT16_C(   671)) },
    { simde_mm_set_pi16(INT16_C(-31674), INT16_C(-30524), INT16_C( -4544), INT16_C( 14571)),
      simde_mm_set_pi16(INT16_C(-27150), INT16_C( 12798), INT16_C( -8585), INT16_C(-32193)),
      simde_mm_set_pi16(INT16_C(-15104), INT16_C(  6272), INT16_C(  -476), INT16_C(  7749)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_maddubs_pi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mulhrs_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-22170), INT16_C(  3338), INT16_C( 16927), INT16_C(-30825),
                         INT16_C( -5333), INT16_C(-26742), INT16_C(    73), INT16_C( 12836)),
      simde_mm_set_epi16(INT16_C(-20552), INT16_C(  2947), INT16_C( 22103), INT16_C( -1959),
                         INT16_C(  9399), INT16_C(-17978), INT16_C( 24358), INT16_C( -8616)),
      simde_mm_set_epi16(INT16_C( 13905), INT16_C(   300), INT16_C( 11418), INT16_C(  1843),
                         INT16_C( -1530), INT16_C( 14672), INT16_C(    54), INT16_C( -3375)) },
    { simde_mm_set_epi16(INT16_C( 13543), INT16_C(-11087), INT16_C(  -705), INT16_C( -8016),
                         INT16_C(  5997), INT16_C(-15738), INT16_C(-26326), INT16_C(-25662)),
      simde_mm_set_epi16(INT16_C(  6685), INT16_C(-23579), INT16_C( 14091), INT16_C( -6956),
                         INT16_C(-18113), INT16_C( 23901), INT16_C( 31684), INT16_C(  2110)),
      simde_mm_set_epi16(INT16_C(  2763), INT16_C(  7978), INT16_C(  -303), INT16_C(  1702),
                         INT16_C( -3315), INT16_C(-11479), INT16_C(-25455), INT16_C( -1652)) },
    { simde_mm_set_epi16(INT16_C(  2735), INT16_C(-11575), INT16_C(-10031), INT16_C( 17488),
                         INT16_C(-28766), INT16_C(  -754), INT16_C( 27755), INT16_C(-14828)),
      simde_mm_set_epi16(INT16_C(-18261), INT16_C( -2558), INT16_C( 20250), INT16_C(-32745),
                         INT16_C( 26468), INT16_C( 12462), INT16_C(  -600), INT16_C( 27533)),
      simde_mm_set_epi16(INT16_C( -1524), INT16_C(   904), INT16_C( -6199), INT16_C(-17476),
                         INT16_C(-23235), INT16_C(  -287), INT16_C(  -508), INT16_C(-12459)) },
    { simde_mm_set_epi16(INT16_C( 18118), INT16_C( 19684), INT16_C( 21218), INT16_C( 11012),
                         INT16_C(  4581), INT16_C( 31051), INT16_C(-22370), INT16_C( 18948)),
      simde_mm_set_epi16(INT16_C(  4495), INT16_C(-26951), INT16_C( 10375), INT16_C( 11197),
                         INT16_C(-22121), INT16_C( 27826), INT16_C(-13849), INT16_C( 15915)),
      simde_mm_set_epi16(INT16_C(  2485), INT16_C(-16190), INT16_C(  6718), INT16_C(  3763),
                         INT16_C( -3093), INT16_C( 26368), INT16_C(  9454), INT16_C(  9203)) },
    { simde_mm_set_epi16(INT16_C( -8749), INT16_C(  9365), INT16_C( -7001), INT16_C( 29368),
                         INT16_C( 22035), INT16_C( 22575), INT16_C( 15151), INT16_C(  8924)),
      simde_mm_set_epi16(INT16_C( -5832), INT16_C(-10538), INT16_C(-26586), INT16_C(-26292),
                         INT16_C( 24365), INT16_C( 31099), INT16_C( -6578), INT16_C(-26373)),
      simde_mm_set_epi16(INT16_C(  1557), INT16_C( -3012), INT16_C(  5680), INT16_C(-23564),
                         INT16_C( 16384), INT16_C( 21425), INT16_C( -3041), INT16_C( -7182)) },
    { simde_mm_set_epi16(INT16_C(-16986), INT16_C(-15026), INT16_C( 27907), INT16_C( 22865),
                         INT16_C( 12487), INT16_C( -3271), INT16_C(-20289), INT16_C(-18773)),
      simde_mm_set_epi16(INT16_C( 12991), INT16_C(  -159), INT16_C( -6884), INT16_C(-32273),
                         INT16_C( 15955), INT16_C( 23229), INT16_C(-21266), INT16_C(  5578)),
      simde_mm_set_epi16(INT16_C( -6734), INT16_C(    73), INT16_C( -5863), INT16_C(-22520),
                         INT16_C(  6080), INT16_C( -2319), INT16_C( 13167), INT16_C( -3196)) },
    { simde_mm_set_epi16(INT16_C( -4913), INT16_C(-31702), INT16_C( -5693), INT16_C( 25724),
                         INT16_C(  8769), INT16_C( -4014), INT16_C(-21883), INT16_C(-17971)),
      simde_mm_set_epi16(INT16_C(  5100), INT16_C( -4154), INT16_C(  5428), INT16_C( 15121),
                         INT16_C( 10050), INT16_C( -9982), INT16_C(-14810), INT16_C( 21413)),
      simde_mm_set_epi16(INT16_C(  -765), INT16_C(  4019), INT16_C(  -943), INT16_C( 11871),
                         INT16_C(  2689), INT16_C(  1223), INT16_C(  9890), INT16_C(-11744)) },
    { simde_mm_set_epi16(INT16_C(-31657), INT16_C(-25785), INT16_C(  -931), INT16_C(  4611),
                         INT16_C(-30993), INT16_C(-28215), INT16_C( 22556), INT16_C( 13103)),
      simde_mm_set_epi16(INT16_C( 16378), INT16_C( 14367), INT16_C(-20270), INT16_C(  6205),
                         INT16_C(  3145), INT16_C(  1055), INT16_C( -2582), INT16_C(-27163)),
      simde_mm_set_epi16(INT16_C(-15823), INT16_C(-11305), INT16_C(   576), INT16_C(   873),
                         INT16_C( -2975), INT16_C(  -908), INT16_C( -1777), INT16_C(-10862)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mulhrs_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mulhrs_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( 10873), INT16_C( 20470), INT16_C(-22699), INT16_C( -8299)),
      simde_mm_set_pi16(INT16_C(  2803), INT16_C( 17070), INT16_C(  3401), INT16_C(  5228)),
      simde_mm_set_pi16(INT16_C(   930), INT16_C( 10664), INT16_C( -2356), INT16_C( -1324)) },
    { simde_mm_set_pi16(INT16_C(-25757), INT16_C(-26678), INT16_C(-28851), INT16_C( -6466)),
      simde_mm_set_pi16(INT16_C( 14685), INT16_C(-28969), INT16_C(-23351), INT16_C(-21231)),
      simde_mm_set_pi16(INT16_C(-11543), INT16_C( 23585), INT16_C( 20560), INT16_C(  4189)) },
    { simde_mm_set_pi16(INT16_C(-15507), INT16_C( 30038), INT16_C( 30487), INT16_C( 19821)),
      simde_mm_set_pi16(INT16_C( 12343), INT16_C(-21596), INT16_C(-10324), INT16_C(-29925)),
      simde_mm_set_pi16(INT16_C( -5841), INT16_C(-19797), INT16_C( -9605), INT16_C(-18101)) },
    { simde_mm_set_pi16(INT16_C( -7595), INT16_C( 32328), INT16_C(  -530), INT16_C( 25195)),
      simde_mm_set_pi16(INT16_C( 24804), INT16_C( 24789), INT16_C( 13974), INT16_C(-29149)),
      simde_mm_set_pi16(INT16_C( -5749), INT16_C( 24456), INT16_C(  -226), INT16_C(-22412)) },
    { simde_mm_set_pi16(INT16_C(-25620), INT16_C(-10236), INT16_C( -5862), INT16_C( -6331)),
      simde_mm_set_pi16(INT16_C(   850), INT16_C(-23039), INT16_C(-12194), INT16_C( 18653)),
      simde_mm_set_pi16(INT16_C(  -665), INT16_C(  7197), INT16_C(  2181), INT16_C( -3604)) },
    { simde_mm_set_pi16(INT16_C( -3270), INT16_C( 28976), INT16_C(-17448), INT16_C(-17812)),
      simde_mm_set_pi16(INT16_C( 22918), INT16_C(-11286), INT16_C(-17728), INT16_C( 18555)),
      simde_mm_set_pi16(INT16_C( -2287), INT16_C( -9980), INT16_C(  9440), INT16_C(-10086)) },
    { simde_mm_set_pi16(INT16_C( -7562), INT16_C(-25114), INT16_C(-28747), INT16_C( 15932)),
      simde_mm_set_pi16(INT16_C( 19935), INT16_C( -3041), INT16_C( -4324), INT16_C( 19473)),
      simde_mm_set_pi16(INT16_C( -4600), INT16_C(  2331), INT16_C(  3793), INT16_C(  9468)) },
    { simde_mm_set_pi16(INT16_C(  2783), INT16_C( -5706), INT16_C( 21220), INT16_C(-16928)),
      simde_mm_set_pi16(INT16_C(  5658), INT16_C( 25482), INT16_C(  -693), INT16_C(  7606)),
      simde_mm_set_pi16(INT16_C(   481), INT16_C( -4437), INT16_C(  -449), INT16_C( -3929)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_mulhrs_pi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i16(r, ==, test_vec[i].r);
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

static MunitResult
test_simde_mm_shuffle_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi8(INT8_C(  74), INT8_C(-101), INT8_C(  15), INT8_C( -66),
                       INT8_C( -20), INT8_C(  87), INT8_C(  16), INT8_C( -79)),
      simde_mm_set_pi8(INT8_C(  29), INT8_C( -65), INT8_C(  38), INT8_C( -40),
                       INT8_C( -70), INT8_C(  88), INT8_C( -38), INT8_C(-118)),
      simde_mm_set_pi8(INT8_C(  15), INT8_C(   0), INT8_C(-101), INT8_C(   0),
                       INT8_C(   0), INT8_C( -79), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C(  72), INT8_C( -15), INT8_C( -72), INT8_C( -84),
                       INT8_C( -21), INT8_C( -95), INT8_C( -76), INT8_C( -92)),
      simde_mm_set_pi8(INT8_C( -94), INT8_C( -81), INT8_C(  23), INT8_C(  85),
                       INT8_C(-111), INT8_C(  24), INT8_C(-116), INT8_C(  34)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(  72), INT8_C( -72),
                       INT8_C(   0), INT8_C( -92), INT8_C(   0), INT8_C( -95)) },
    { simde_mm_set_pi8(INT8_C(  72), INT8_C(  95), INT8_C( 109), INT8_C( -45),
                       INT8_C(  11), INT8_C(  -2), INT8_C(  -6), INT8_C(  80)),
      simde_mm_set_pi8(INT8_C( -77), INT8_C(-102), INT8_C(  57), INT8_C( -50),
                       INT8_C(  85), INT8_C( -92), INT8_C( 102), INT8_C( -10)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(  -6), INT8_C(   0),
                       INT8_C( 109), INT8_C(   0), INT8_C(  95), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C( -13), INT8_C(  -1), INT8_C( -80), INT8_C( 110),
                       INT8_C( -12), INT8_C( -38), INT8_C(  43), INT8_C(-126)),
      simde_mm_set_pi8(INT8_C(  94), INT8_C( -52), INT8_C( -58), INT8_C( 119),
                       INT8_C( -62), INT8_C( 119), INT8_C( -96), INT8_C(-113)),
      simde_mm_set_pi8(INT8_C(  -1), INT8_C(   0), INT8_C(   0), INT8_C( -13),
                       INT8_C(   0), INT8_C( -13), INT8_C(   0), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C(-107), INT8_C(-111), INT8_C(  58), INT8_C( -52),
                       INT8_C( -31), INT8_C( -75), INT8_C(-114), INT8_C(  50)),
      simde_mm_set_pi8(INT8_C( -40), INT8_C( -66), INT8_C(  33), INT8_C( 101),
                       INT8_C(  11), INT8_C( -41), INT8_C(  77), INT8_C(  71)),
      simde_mm_set_pi8(INT8_C(   0), INT8_C(   0), INT8_C(-114), INT8_C(  58),
                       INT8_C( -31), INT8_C(   0), INT8_C(  58), INT8_C(-107)) },
    { simde_mm_set_pi8(INT8_C( -92), INT8_C( -56), INT8_C(  22), INT8_C( -56),
                       INT8_C( -63), INT8_C( -78), INT8_C( 106), INT8_C( -87)),
      simde_mm_set_pi8(INT8_C(  95), INT8_C(  65), INT8_C(  46), INT8_C(  64),
                       INT8_C(  39), INT8_C( -81), INT8_C(  83), INT8_C( -54)),
      simde_mm_set_pi8(INT8_C( -92), INT8_C( 106), INT8_C( -56), INT8_C( -87),
                       INT8_C( -92), INT8_C(   0), INT8_C( -63), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C(  33), INT8_C(-110), INT8_C(  35), INT8_C( -83),
                       INT8_C( -76), INT8_C(  59), INT8_C(  45), INT8_C( -42)),
      simde_mm_set_pi8(INT8_C(  73), INT8_C( -44), INT8_C(  97), INT8_C( -65),
                       INT8_C( -88), INT8_C( -50), INT8_C(  19), INT8_C( -79)),
      simde_mm_set_pi8(INT8_C(  45), INT8_C(   0), INT8_C(  45), INT8_C(   0),
                       INT8_C(   0), INT8_C(   0), INT8_C( -76), INT8_C(   0)) },
    { simde_mm_set_pi8(INT8_C( -28), INT8_C( -77), INT8_C( 105), INT8_C( 105),
                       INT8_C(  22), INT8_C(   1), INT8_C( 100), INT8_C( -15)),
      simde_mm_set_pi8(INT8_C( 115), INT8_C( -11), INT8_C(  20), INT8_C(  80),
                       INT8_C(  40), INT8_C(-114), INT8_C( -49), INT8_C(-108)),
      simde_mm_set_pi8(INT8_C(  22), INT8_C(   0), INT8_C( 105), INT8_C( -15),
                       INT8_C( -15), INT8_C(   0), INT8_C(   0), INT8_C(   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_shuffle_pi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sign_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(  37), INT8_C( -69), INT8_C( -16), INT8_C( -99),
                        INT8_C(  36), INT8_C(  10), INT8_C(  56), INT8_C( -63),
                        INT8_C(-117), INT8_C(  66), INT8_C(  76), INT8_C(  31),
                        INT8_C(  61), INT8_C( -83), INT8_C(  44), INT8_C( -66)),
      simde_mm_set_epi8(INT8_C( -96), INT8_C(  30), INT8_C(  67), INT8_C(  75),
                        INT8_C(  24), INT8_C(  56), INT8_C(  14), INT8_C(  75),
                        INT8_C( -85), INT8_C(-103), INT8_C(   1), INT8_C( -80),
                        INT8_C( -93), INT8_C(  37), INT8_C( -46), INT8_C(  95)),
      simde_mm_set_epi8(INT8_C( -37), INT8_C( -69), INT8_C( -16), INT8_C( -99),
                        INT8_C(  36), INT8_C(  10), INT8_C(  56), INT8_C( -63),
                        INT8_C( 117), INT8_C( -66), INT8_C(  76), INT8_C( -31),
                        INT8_C( -61), INT8_C( -83), INT8_C( -44), INT8_C( -66)) },
    { simde_mm_set_epi8(INT8_C( -16), INT8_C(  66), INT8_C(   6), INT8_C( 126),
                        INT8_C( -12), INT8_C( -78), INT8_C(-121), INT8_C( -64),
                        INT8_C(  49), INT8_C( -16), INT8_C(  89), INT8_C( -61),
                        INT8_C(  60), INT8_C(  17), INT8_C( -94), INT8_C( 113)),
      simde_mm_set_epi8(INT8_C(  70), INT8_C(  27), INT8_C( 101), INT8_C( 119),
                        INT8_C( -80), INT8_C( 103), INT8_C( -28), INT8_C(  79),
                        INT8_C(  90), INT8_C(-127), INT8_C( -36), INT8_C(  57),
                        INT8_C( -22), INT8_C( -74), INT8_C(  75), INT8_C( 106)),
      simde_mm_set_epi8(INT8_C( -16), INT8_C(  66), INT8_C(   6), INT8_C( 126),
                        INT8_C(  12), INT8_C( -78), INT8_C( 121), INT8_C( -64),
                        INT8_C(  49), INT8_C(  16), INT8_C( -89), INT8_C( -61),
                        INT8_C( -60), INT8_C( -17), INT8_C( -94), INT8_C( 113)) },
    { simde_mm_set_epi8(INT8_C(  99), INT8_C(  38), INT8_C(-110), INT8_C(  26),
                        INT8_C( 106), INT8_C(  50), INT8_C( -36), INT8_C(-109),
                        INT8_C( -69), INT8_C( -52), INT8_C(  61), INT8_C( -24),
                        INT8_C( -63), INT8_C(  96), INT8_C(  45), INT8_C( 113)),
      simde_mm_set_epi8(INT8_C(  91), INT8_C( -69), INT8_C(  13), INT8_C(  48),
                        INT8_C( -63), INT8_C( -35), INT8_C(  91), INT8_C(-109),
                        INT8_C( -12), INT8_C( -94), INT8_C( 121), INT8_C( -64),
                        INT8_C( -56), INT8_C( -95), INT8_C( 123), INT8_C( -38)),
      simde_mm_set_epi8(INT8_C(  99), INT8_C( -38), INT8_C(-110), INT8_C(  26),
                        INT8_C(-106), INT8_C( -50), INT8_C( -36), INT8_C( 109),
                        INT8_C(  69), INT8_C(  52), INT8_C(  61), INT8_C(  24),
                        INT8_C(  63), INT8_C( -96), INT8_C(  45), INT8_C(-113)) },
    { simde_mm_set_epi8(INT8_C( -46), INT8_C( -25), INT8_C( -91), INT8_C( -54),
                        INT8_C(  77), INT8_C( -42), INT8_C(  -7), INT8_C(  -4),
                        INT8_C( -52), INT8_C(  81), INT8_C( -53), INT8_C( -30),
                        INT8_C(  73), INT8_C(  25), INT8_C( -34), INT8_C( 101)),
      simde_mm_set_epi8(INT8_C( 122), INT8_C( -35), INT8_C(  -5), INT8_C( -48),
                        INT8_C( -70), INT8_C(   5), INT8_C(   5), INT8_C(  -1),
                        INT8_C(  84), INT8_C(  42), INT8_C(   8), INT8_C(  11),
                        INT8_C(  -3), INT8_C(-102), INT8_C( -19), INT8_C(  36)),
      simde_mm_set_epi8(INT8_C( -46), INT8_C(  25), INT8_C(  91), INT8_C(  54),
                        INT8_C( -77), INT8_C( -42), INT8_C(  -7), INT8_C(   4),
                        INT8_C( -52), INT8_C(  81), INT8_C( -53), INT8_C( -30),
                        INT8_C( -73), INT8_C( -25), INT8_C(  34), INT8_C( 101)) },
    { simde_mm_set_epi8(INT8_C( 100), INT8_C(-100), INT8_C(  72), INT8_C(  21),
                        INT8_C( 116), INT8_C(  44), INT8_C(-111), INT8_C(  65),
                        INT8_C( -91), INT8_C(  30), INT8_C( -90), INT8_C(  -7),
                        INT8_C( -19), INT8_C(  82), INT8_C(-121), INT8_C(-102)),
      simde_mm_set_epi8(INT8_C(  52), INT8_C(  93), INT8_C(-112), INT8_C( -21),
                        INT8_C(  14), INT8_C( -56), INT8_C( -64), INT8_C(  86),
                        INT8_C(  73), INT8_C( 115), INT8_C(-120), INT8_C( -32),
                        INT8_C(  80), INT8_C( -83), INT8_C(  50), INT8_C(  58)),
      simde_mm_set_epi8(INT8_C( 100), INT8_C(-100), INT8_C( -72), INT8_C( -21),
                        INT8_C( 116), INT8_C( -44), INT8_C( 111), INT8_C(  65),
                        INT8_C( -91), INT8_C(  30), INT8_C(  90), INT8_C(   7),
                        INT8_C( -19), INT8_C( -82), INT8_C(-121), INT8_C(-102)) },
    { simde_mm_set_epi8(INT8_C(-106), INT8_C(  24), INT8_C( -64), INT8_C(-116),
                        INT8_C(  54), INT8_C(  12), INT8_C(   9), INT8_C(  21),
                        INT8_C( -21), INT8_C(  44), INT8_C( -75), INT8_C(   4),
                        INT8_C(-124), INT8_C( -51), INT8_C( -45), INT8_C(  84)),
      simde_mm_set_epi8(INT8_C( -44), INT8_C( -17), INT8_C(  49), INT8_C(  10),
                        INT8_C(  41), INT8_C(  -6), INT8_C( -23), INT8_C( -29),
                        INT8_C(  18), INT8_C( -37), INT8_C( -56), INT8_C( -37),
                        INT8_C( -49), INT8_C(   7), INT8_C( 101), INT8_C( -47)),
      simde_mm_set_epi8(INT8_C( 106), INT8_C( -24), INT8_C( -64), INT8_C(-116),
                        INT8_C(  54), INT8_C( -12), INT8_C(  -9), INT8_C( -21),
                        INT8_C( -21), INT8_C( -44), INT8_C(  75), INT8_C(  -4),
                        INT8_C( 124), INT8_C( -51), INT8_C( -45), INT8_C( -84)) },
    { simde_mm_set_epi8(INT8_C(  54), INT8_C( -94), INT8_C( 102), INT8_C(  77),
                        INT8_C(  43), INT8_C(  70), INT8_C( -80), INT8_C(  96),
                        INT8_C( -60), INT8_C( -75), INT8_C(  42), INT8_C( -31),
                        INT8_C(  -2), INT8_C( 121), INT8_C(  29), INT8_C(  54)),
      simde_mm_set_epi8(INT8_C(  44), INT8_C(  49), INT8_C(  46), INT8_C( 120),
                        INT8_C( -14), INT8_C(  89), INT8_C(   3), INT8_C(-114),
                        INT8_C( -54), INT8_C( -45), INT8_C( 113), INT8_C( -76),
                        INT8_C(  25), INT8_C( -90), INT8_C( -10), INT8_C(  65)),
      simde_mm_set_epi8(INT8_C(  54), INT8_C( -94), INT8_C( 102), INT8_C(  77),
                        INT8_C( -43), INT8_C(  70), INT8_C( -80), INT8_C( -96),
                        INT8_C(  60), INT8_C(  75), INT8_C(  42), INT8_C(  31),
                        INT8_C(  -2), INT8_C(-121), INT8_C( -29), INT8_C(  54)) },
    { simde_mm_set_epi8(INT8_C( -18), INT8_C( -38), INT8_C(  -9), INT8_C( -44),
                        INT8_C( -53), INT8_C( -14), INT8_C( -61), INT8_C(  59),
                        INT8_C(  58), INT8_C( -68), INT8_C( -23), INT8_C( -51),
                        INT8_C(  43), INT8_C(  -1), INT8_C(  -6), INT8_C(  20)),
      simde_mm_set_epi8(INT8_C(   9), INT8_C( -16), INT8_C( -71), INT8_C( -90),
                        INT8_C( -92), INT8_C(  58), INT8_C( -15), INT8_C( 115),
                        INT8_C( -11), INT8_C(  34), INT8_C( 122), INT8_C( -11),
                        INT8_C(  46), INT8_C( -86), INT8_C(  51), INT8_C(  -3)),
      simde_mm_set_epi8(INT8_C( -18), INT8_C(  38), INT8_C(   9), INT8_C(  44),
                        INT8_C(  53), INT8_C( -14), INT8_C(  61), INT8_C(  59),
                        INT8_C( -58), INT8_C( -68), INT8_C( -23), INT8_C(  51),
                        INT8_C(  43), INT8_C(   1), INT8_C(  -6), INT8_C( -20)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sign_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sign_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-15759), INT16_C( 25741), INT16_C(  3088), INT16_C(-12147),
                         INT16_C( 11906), INT16_C( 15052), INT16_C( 20544), INT16_C(-28879)),
      simde_mm_set_epi16(INT16_C( 31434), INT16_C(-10402), INT16_C( 15330), INT16_C(-15336),
                         INT16_C(-27365), INT16_C(  7051), INT16_C(-15134), INT16_C( 30438)),
      simde_mm_set_epi16(INT16_C(-15759), INT16_C(-25741), INT16_C(  3088), INT16_C( 12147),
                         INT16_C(-11906), INT16_C( 15052), INT16_C(-20544), INT16_C(-28879)) },
    { simde_mm_set_epi16(INT16_C( 25362), INT16_C(  8410), INT16_C( -5772), INT16_C( 11356),
                         INT16_C( -5145), INT16_C(  -528), INT16_C( -3800), INT16_C(-22538)),
      simde_mm_set_epi16(INT16_C( 28705), INT16_C( 22529), INT16_C(-24415), INT16_C( 10605),
                         INT16_C(  8581), INT16_C(   348), INT16_C( 17147), INT16_C(-28679)),
      simde_mm_set_epi16(INT16_C( 25362), INT16_C(  8410), INT16_C(  5772), INT16_C( 11356),
                         INT16_C( -5145), INT16_C(  -528), INT16_C( -3800), INT16_C( 22538)) },
    { simde_mm_set_epi16(INT16_C(-15793), INT16_C(-15692), INT16_C(-32639), INT16_C(  2140),
                         INT16_C( -7199), INT16_C(-11564), INT16_C(  8190), INT16_C(  1872)),
      simde_mm_set_epi16(INT16_C(-14750), INT16_C( -5416), INT16_C( -2422), INT16_C(-28769),
                         INT16_C(  5810), INT16_C(  4853), INT16_C(-22556), INT16_C(  2950)),
      simde_mm_set_epi16(INT16_C( 15793), INT16_C( 15692), INT16_C( 32639), INT16_C( -2140),
                         INT16_C( -7199), INT16_C(-11564), INT16_C( -8190), INT16_C(  1872)) },
    { simde_mm_set_epi16(INT16_C( -6949), INT16_C( 14948), INT16_C(-19128), INT16_C(    99),
                         INT16_C( -9508), INT16_C( 29377), INT16_C( 26021), INT16_C( 21262)),
      simde_mm_set_epi16(INT16_C( 31478), INT16_C(-23157), INT16_C( 27993), INT16_C( 18819),
                         INT16_C( 21708), INT16_C( 11006), INT16_C(-32250), INT16_C( 28821)),
      simde_mm_set_epi16(INT16_C( -6949), INT16_C(-14948), INT16_C(-19128), INT16_C(    99),
                         INT16_C( -9508), INT16_C( 29377), INT16_C(-26021), INT16_C( 21262)) },
    { simde_mm_set_epi16(INT16_C(-27259), INT16_C( 15633), INT16_C( 24307), INT16_C( 25640),
                         INT16_C( 23376), INT16_C(-30654), INT16_C( 19896), INT16_C(-14888)),
      simde_mm_set_epi16(INT16_C(-26725), INT16_C( -6818), INT16_C(   478), INT16_C( 25662),
                         INT16_C( 26003), INT16_C( 21963), INT16_C(  1012), INT16_C( 16019)),
      simde_mm_set_epi16(INT16_C( 27259), INT16_C(-15633), INT16_C( 24307), INT16_C( 25640),
                         INT16_C( 23376), INT16_C(-30654), INT16_C( 19896), INT16_C(-14888)) },
    { simde_mm_set_epi16(INT16_C(-18809), INT16_C(  2505), INT16_C(-14233), INT16_C( 26092),
                         INT16_C( 30746), INT16_C(   286), INT16_C(-10480), INT16_C( 18834)),
      simde_mm_set_epi16(INT16_C( 32423), INT16_C(-20791), INT16_C(  -741), INT16_C( 17070),
                         INT16_C( -8670), INT16_C(  1759), INT16_C(-27846), INT16_C( 12891)),
      simde_mm_set_epi16(INT16_C(-18809), INT16_C( -2505), INT16_C( 14233), INT16_C( 26092),
                         INT16_C(-30746), INT16_C(   286), INT16_C( 10480), INT16_C( 18834)) },
    { simde_mm_set_epi16(INT16_C( 10084), INT16_C(-24493), INT16_C(  7465), INT16_C(  3573),
                         INT16_C(-29669), INT16_C( -5452), INT16_C( 25244), INT16_C( 30808)),
      simde_mm_set_epi16(INT16_C(  7390), INT16_C(  4062), INT16_C( -2410), INT16_C(-18994),
                         INT16_C(  4689), INT16_C(  1376), INT16_C(-23142), INT16_C( 31884)),
      simde_mm_set_epi16(INT16_C( 10084), INT16_C(-24493), INT16_C( -7465), INT16_C( -3573),
                         INT16_C(-29669), INT16_C( -5452), INT16_C(-25244), INT16_C( 30808)) },
    { simde_mm_set_epi16(INT16_C( 11692), INT16_C( 22876), INT16_C(-18223), INT16_C(-22058),
                         INT16_C(-12080), INT16_C( 30075), INT16_C( 16936), INT16_C(-31252)),
      simde_mm_set_epi16(INT16_C( -4320), INT16_C(-15410), INT16_C( 21240), INT16_C(-12323),
                         INT16_C( -6944), INT16_C(-29167), INT16_C( 21220), INT16_C( 24483)),
      simde_mm_set_epi16(INT16_C(-11692), INT16_C(-22876), INT16_C(-18223), INT16_C( 22058),
                         INT16_C( 12080), INT16_C(-30075), INT16_C( 16936), INT16_C(-31252)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sign_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sign_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  633073821), INT32_C(  604649665), INT32_C(-1958589409), INT32_C( 1034759358)),
      simde_mm_set_epi32(INT32_C(-1608629429), INT32_C(  406326859), INT32_C(-1416035920), INT32_C(-1557802401)),
      simde_mm_set_epi32(INT32_C( -633073821), INT32_C(  604649665), INT32_C( 1958589409), INT32_C(-1034759358)) },
    { simde_mm_set_epi32(INT32_C( -264108418), INT32_C( -189626432), INT32_C(  837835203), INT32_C( 1007788657)),
      simde_mm_set_epi32(INT32_C( 1176200567), INT32_C(-1335368625), INT32_C( 1518459961), INT32_C( -357151894)),
      simde_mm_set_epi32(INT32_C( -264108418), INT32_C(  189626432), INT32_C(  837835203), INT32_C(-1007788657)) },
    { simde_mm_set_epi32(INT32_C( 1663472154), INT32_C( 1781718163), INT32_C(-1144242712), INT32_C(-1050661519)),
      simde_mm_set_epi32(INT32_C( 1538985264), INT32_C(-1042457709), INT32_C( -190678592), INT32_C( -928941094)),
      simde_mm_set_epi32(INT32_C( 1663472154), INT32_C(-1781718163), INT32_C( 1144242712), INT32_C( 1050661519)) },
    { simde_mm_set_epi32(INT32_C( -756570678), INT32_C( 1305934332), INT32_C( -867054622), INT32_C( 1226432101)),
      simde_mm_set_epi32(INT32_C( 2061368272), INT32_C(-1174075905), INT32_C( 1412040715), INT32_C(  -40178396)),
      simde_mm_set_epi32(INT32_C( -756570678), INT32_C(-1305934332), INT32_C( -867054622), INT32_C(-1226432101)) },
    { simde_mm_set_epi32(INT32_C( 1687963669), INT32_C( 1949077825), INT32_C(-1524717831), INT32_C( -313358438)),
      simde_mm_set_epi32(INT32_C(  878547179), INT32_C(  248037462), INT32_C( 1232308448), INT32_C( 1353527866)),
      simde_mm_set_epi32(INT32_C( 1687963669), INT32_C( 1949077825), INT32_C(-1524717831), INT32_C( -313358438)) },
    { simde_mm_set_epi32(INT32_C(-1776762740), INT32_C(  906758421), INT32_C( -349391612), INT32_C(-2066885804)),
      simde_mm_set_epi32(INT32_C( -722521846), INT32_C(  704309731), INT32_C(  316393691), INT32_C( -821598767)),
      simde_mm_set_epi32(INT32_C( 1776762740), INT32_C(  906758421), INT32_C( -349391612), INT32_C( 2066885804)) },
    { simde_mm_set_epi32(INT32_C(  916612685), INT32_C(  726052960), INT32_C( -994759967), INT32_C(  -25617098)),
      simde_mm_set_epi32(INT32_C(  741420664), INT32_C( -229047410), INT32_C( -892112460), INT32_C(  430372417)),
      simde_mm_set_epi32(INT32_C(  916612685), INT32_C( -726052960), INT32_C(  994759967), INT32_C(  -25617098)) },
    { simde_mm_set_epi32(INT32_C( -287639596), INT32_C( -873282757), INT32_C(  985459149), INT32_C(  738195988)),
      simde_mm_set_epi32(INT32_C(  166771110), INT32_C(-1539640973), INT32_C( -182289675), INT32_C(  782906365)),
      simde_mm_set_epi32(INT32_C( -287639596), INT32_C(  873282757), INT32_C( -985459149), INT32_C(  738195988)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_sign_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sign_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi8(INT8_C(  41), INT8_C( -70), INT8_C(  22), INT8_C( -60),
                       INT8_C( -48), INT8_C( -81), INT8_C(  97), INT8_C(-114)),
      simde_mm_set_pi8(INT8_C(  12), INT8_C(  54), INT8_C( 116), INT8_C( 111),
                       INT8_C(   3), INT8_C(  16), INT8_C(-115), INT8_C(  56)),
      simde_mm_set_pi8(INT8_C(  41), INT8_C( -70), INT8_C(  22), INT8_C( -60),
                       INT8_C( -48), INT8_C( -81), INT8_C( -97), INT8_C(-114)) },
    { simde_mm_set_pi8(INT8_C( -31), INT8_C( -22), INT8_C(  55), INT8_C(-115),
                       INT8_C( -14), INT8_C(  -2), INT8_C(  92), INT8_C(  11)),
      simde_mm_set_pi8(INT8_C(  67), INT8_C( -80), INT8_C(  19), INT8_C( -63),
                       INT8_C( -35), INT8_C( -59), INT8_C(  -4), INT8_C(  14)),
      simde_mm_set_pi8(INT8_C( -31), INT8_C(  22), INT8_C(  55), INT8_C( 115),
                       INT8_C(  14), INT8_C(   2), INT8_C( -92), INT8_C(  11)) },
    { simde_mm_set_pi8(INT8_C( 123), INT8_C(  72), INT8_C( 109), INT8_C(  92),
                       INT8_C( -54), INT8_C(  74), INT8_C(  42), INT8_C( 113)),
      simde_mm_set_pi8(INT8_C(  49), INT8_C( -54), INT8_C( 108), INT8_C(  45),
                       INT8_C(  63), INT8_C(-116), INT8_C(  46), INT8_C(  95)),
      simde_mm_set_pi8(INT8_C( 123), INT8_C( -72), INT8_C( 109), INT8_C(  92),
                       INT8_C( -54), INT8_C( -74), INT8_C(  42), INT8_C( 113)) },
    { simde_mm_set_pi8(INT8_C(  51), INT8_C(  95), INT8_C(  90), INT8_C( -33),
                       INT8_C(  15), INT8_C(-121), INT8_C(  -5), INT8_C(  54)),
      simde_mm_set_pi8(INT8_C(  88), INT8_C(  89), INT8_C( -32), INT8_C(  32),
                       INT8_C(   7), INT8_C(  21), INT8_C( -69), INT8_C(  56)),
      simde_mm_set_pi8(INT8_C(  51), INT8_C(  95), INT8_C( -90), INT8_C( -33),
                       INT8_C(  15), INT8_C(-121), INT8_C(   5), INT8_C(  54)) },
    { simde_mm_set_pi8(INT8_C(  10), INT8_C(  79), INT8_C( -53), INT8_C(  15),
                       INT8_C(  22), INT8_C( -53), INT8_C( -60), INT8_C( -88)),
      simde_mm_set_pi8(INT8_C(  40), INT8_C(-102), INT8_C( -67), INT8_C( 115),
                       INT8_C( -77), INT8_C( -15), INT8_C( -36), INT8_C( -80)),
      simde_mm_set_pi8(INT8_C(  10), INT8_C( -79), INT8_C(  53), INT8_C(  15),
                       INT8_C( -22), INT8_C(  53), INT8_C(  60), INT8_C(  88)) },
    { simde_mm_set_pi8(INT8_C(-120), INT8_C(-122), INT8_C( -65), INT8_C(  22),
                       INT8_C(-100), INT8_C(  44), INT8_C( -91), INT8_C(  42)),
      simde_mm_set_pi8(INT8_C( -87), INT8_C(  50), INT8_C(  14), INT8_C(  36),
                       INT8_C( -95), INT8_C(  69), INT8_C( -70), INT8_C(  38)),
      simde_mm_set_pi8(INT8_C( 120), INT8_C(-122), INT8_C( -65), INT8_C(  22),
                       INT8_C( 100), INT8_C(  44), INT8_C(  91), INT8_C(  42)) },
    { simde_mm_set_pi8(INT8_C(  71), INT8_C( -24), INT8_C( 115), INT8_C(  90),
                       INT8_C(  52), INT8_C(  52), INT8_C( -42), INT8_C( 119)),
      simde_mm_set_pi8(INT8_C( -78), INT8_C( -10), INT8_C(  31), INT8_C( 106),
                       INT8_C( -76), INT8_C( -74), INT8_C(  82), INT8_C( 103)),
      simde_mm_set_pi8(INT8_C( -71), INT8_C(  24), INT8_C( 115), INT8_C(  90),
                       INT8_C( -52), INT8_C( -52), INT8_C( -42), INT8_C( 119)) },
    { simde_mm_set_pi8(INT8_C( -29), INT8_C( -55), INT8_C(-107), INT8_C( -94),
                       INT8_C(-100), INT8_C(-105), INT8_C( 110), INT8_C(  49)),
      simde_mm_set_pi8(INT8_C( 116), INT8_C( -73), INT8_C(-114), INT8_C(  -3),
                       INT8_C(  58), INT8_C( 101), INT8_C(-111), INT8_C(-116)),
      simde_mm_set_pi8(INT8_C( -29), INT8_C(  55), INT8_C( 107), INT8_C(  94),
                       INT8_C(-100), INT8_C(-105), INT8_C(-110), INT8_C( -49)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_sign_pi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sign_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi16(INT16_C( 10682), INT16_C(  5828), INT16_C(-12113), INT16_C( 24974)),
      simde_mm_set_pi16(INT16_C(  3126), INT16_C( 29807), INT16_C(   784), INT16_C(-29384)),
      simde_mm_set_pi16(INT16_C( 10682), INT16_C(  5828), INT16_C(-12113), INT16_C(-24974)) },
    { simde_mm_set_pi16(INT16_C( -7702), INT16_C( 14221), INT16_C( -3330), INT16_C( 23563)),
      simde_mm_set_pi16(INT16_C( 17328), INT16_C(  5057), INT16_C( -8763), INT16_C( -1010)),
      simde_mm_set_pi16(INT16_C( -7702), INT16_C( 14221), INT16_C(  3330), INT16_C(-23563)) },
    { simde_mm_set_pi16(INT16_C( 31560), INT16_C( 27996), INT16_C(-13750), INT16_C( 10865)),
      simde_mm_set_pi16(INT16_C( 12746), INT16_C( 27693), INT16_C( 16268), INT16_C( 11871)),
      simde_mm_set_pi16(INT16_C( 31560), INT16_C( 27996), INT16_C(-13750), INT16_C( 10865)) },
    { simde_mm_set_pi16(INT16_C( 13151), INT16_C( 23263), INT16_C(  3975), INT16_C( -1226)),
      simde_mm_set_pi16(INT16_C( 22617), INT16_C( -8160), INT16_C(  1813), INT16_C(-17608)),
      simde_mm_set_pi16(INT16_C( 13151), INT16_C(-23263), INT16_C(  3975), INT16_C(  1226)) },
    { simde_mm_set_pi16(INT16_C(  2639), INT16_C(-13553), INT16_C(  5835), INT16_C(-15192)),
      simde_mm_set_pi16(INT16_C( 10394), INT16_C(-17037), INT16_C(-19471), INT16_C( -9040)),
      simde_mm_set_pi16(INT16_C(  2639), INT16_C( 13553), INT16_C( -5835), INT16_C( 15192)) },
    { simde_mm_set_pi16(INT16_C(-30586), INT16_C(-16618), INT16_C(-25556), INT16_C(-23254)),
      simde_mm_set_pi16(INT16_C(-22222), INT16_C(  3620), INT16_C(-24251), INT16_C(-17882)),
      simde_mm_set_pi16(INT16_C( 30586), INT16_C(-16618), INT16_C( 25556), INT16_C( 23254)) },
    { simde_mm_set_pi16(INT16_C( 18408), INT16_C( 29530), INT16_C( 13364), INT16_C(-10633)),
      simde_mm_set_pi16(INT16_C(-19722), INT16_C(  8042), INT16_C(-19274), INT16_C( 21095)),
      simde_mm_set_pi16(INT16_C(-18408), INT16_C( 29530), INT16_C(-13364), INT16_C(-10633)) },
    { simde_mm_set_pi16(INT16_C( -7223), INT16_C(-27230), INT16_C(-25449), INT16_C( 28209)),
      simde_mm_set_pi16(INT16_C( 29879), INT16_C(-28931), INT16_C( 14949), INT16_C(-28276)),
      simde_mm_set_pi16(INT16_C( -7223), INT16_C( 27230), INT16_C(-25449), INT16_C(-28209)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_sign_pi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_sign_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {
    { simde_mm_set_pi32(INT32_C(  700061380), INT32_C( -793812594)),
      simde_mm_set_pi32(INT32_C(  204895343), INT32_C(   51416376)),
      simde_mm_set_pi32(INT32_C(  700061380), INT32_C( -793812594)) },
    { simde_mm_set_pi32(INT32_C( -504744051), INT32_C( -218211317)),
      simde_mm_set_pi32(INT32_C( 1135612865), INT32_C( -574227442)),
      simde_mm_set_pi32(INT32_C( -504744051), INT32_C(  218211317)) },
    { simde_mm_set_pi32(INT32_C( 2068344156), INT32_C( -901109135)),
      simde_mm_set_pi32(INT32_C(  835349549), INT32_C( 1066151519)),
      simde_mm_set_pi32(INT32_C( 2068344156), INT32_C( -901109135)) },
    { simde_mm_set_pi32(INT32_C(  861887199), INT32_C(  260569910)),
      simde_mm_set_pi32(INT32_C( 1482285088), INT32_C(  118864696)),
      simde_mm_set_pi32(INT32_C(  861887199), INT32_C(  260569910)) },
    { simde_mm_set_pi32(INT32_C(  173001487), INT32_C(  382452904)),
      simde_mm_set_pi32(INT32_C(  681229683), INT32_C(-1275994960)),
      simde_mm_set_pi32(INT32_C(  173001487), INT32_C( -382452904)) },
    { simde_mm_set_pi32(INT32_C(-2004435178), INT32_C(-1674795734)),
      simde_mm_set_pi32(INT32_C(-1456337372), INT32_C(-1589265882)),
      simde_mm_set_pi32(INT32_C( 2004435178), INT32_C( 1674795734)) },
    { simde_mm_set_pi32(INT32_C( 1206416218), INT32_C(  875878007)),
      simde_mm_set_pi32(INT32_C(-1292492950), INT32_C(-1263119769)),
      simde_mm_set_pi32(INT32_C(-1206416218), INT32_C( -875878007)) },
    { simde_mm_set_pi32(INT32_C( -473328222), INT32_C(-1667797455)),
      simde_mm_set_pi32(INT32_C( 1958186749), INT32_C(  979734924)),
      simde_mm_set_pi32(INT32_C( -473328222), INT32_C(-1667797455)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_sign_pi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i32(r, ==, test_vec[i].r);
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
  TEST_FUNC(mm_hadd_epi16),
  TEST_FUNC(mm_hadd_epi32),
  TEST_FUNC(mm_hadd_pi16),
  TEST_FUNC(mm_hadd_pi32),
  TEST_FUNC(mm_hadds_epi16),
  TEST_FUNC(mm_hadds_pi16),
  TEST_FUNC(mm_hsub_epi16),
  TEST_FUNC(mm_hsub_epi32),
  TEST_FUNC(mm_hsub_pi16),
  TEST_FUNC(mm_hsub_pi32),
  TEST_FUNC(mm_hsubs_epi16),
  TEST_FUNC(mm_hsubs_pi16),
  TEST_FUNC(mm_maddubs_epi16),
  TEST_FUNC(mm_maddubs_pi16),
  TEST_FUNC(mm_mulhrs_epi16),
  TEST_FUNC(mm_mulhrs_pi16),
  TEST_FUNC(mm_shuffle_epi8),
  TEST_FUNC(mm_shuffle_pi8),
  TEST_FUNC(mm_sign_epi8),
  TEST_FUNC(mm_sign_epi16),
  TEST_FUNC(mm_sign_epi32),
  TEST_FUNC(mm_sign_pi8),
  TEST_FUNC(mm_sign_pi16),
  TEST_FUNC(mm_sign_pi32),

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
