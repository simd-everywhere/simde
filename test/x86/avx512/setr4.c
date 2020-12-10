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
 */

#define SIMDE_TEST_X86_AVX512_INSN setr4

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/setr4.h>

static int
test_simde_mm512_setr4_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int32_t d; int32_t c; int32_t b; int32_t a;
    simde__m512i r;
  } test_vec[8] = {
    { INT32_C(  440568275),
      INT32_C(-1307171366),
      INT32_C( -667071334),
      INT32_C(-1006059139),
      simde_mm512_set_epi32(INT32_C(-1006059139), INT32_C( -667071334), INT32_C(-1307171366), INT32_C(  440568275),
                            INT32_C(-1006059139), INT32_C( -667071334), INT32_C(-1307171366), INT32_C(  440568275),
                            INT32_C(-1006059139), INT32_C( -667071334), INT32_C(-1307171366), INT32_C(  440568275),
                            INT32_C(-1006059139), INT32_C( -667071334), INT32_C(-1307171366), INT32_C(  440568275)) },
    { INT32_C(  985235756),
      INT32_C(-2117652171),
      INT32_C( -492848785),
      INT32_C(  765678538),
      simde_mm512_set_epi32(INT32_C(  765678538), INT32_C( -492848785), INT32_C(-2117652171), INT32_C(  985235756),
                            INT32_C(  765678538), INT32_C( -492848785), INT32_C(-2117652171), INT32_C(  985235756),
                            INT32_C(  765678538), INT32_C( -492848785), INT32_C(-2117652171), INT32_C(  985235756),
                            INT32_C(  765678538), INT32_C( -492848785), INT32_C(-2117652171), INT32_C(  985235756)) },
    { INT32_C( 1812566322),
      INT32_C( -457041277),
      INT32_C(-1069434801),
      INT32_C( -605856203),
      simde_mm512_set_epi32(INT32_C( -605856203), INT32_C(-1069434801), INT32_C( -457041277), INT32_C( 1812566322),
                            INT32_C( -605856203), INT32_C(-1069434801), INT32_C( -457041277), INT32_C( 1812566322),
                            INT32_C( -605856203), INT32_C(-1069434801), INT32_C( -457041277), INT32_C( 1812566322),
                            INT32_C( -605856203), INT32_C(-1069434801), INT32_C( -457041277), INT32_C( 1812566322)) },
    { INT32_C( 1968671665),
      INT32_C(  838296696),
      INT32_C( -693015358),
      INT32_C(-1386069498),
      simde_mm512_set_epi32(INT32_C(-1386069498), INT32_C( -693015358), INT32_C(  838296696), INT32_C( 1968671665),
                            INT32_C(-1386069498), INT32_C( -693015358), INT32_C(  838296696), INT32_C( 1968671665),
                            INT32_C(-1386069498), INT32_C( -693015358), INT32_C(  838296696), INT32_C( 1968671665),
                            INT32_C(-1386069498), INT32_C( -693015358), INT32_C(  838296696), INT32_C( 1968671665)) },
    { INT32_C(  717585874),
      INT32_C( -870190090),
      INT32_C(   62628055),
      INT32_C(-1058408989),
      simde_mm512_set_epi32(INT32_C(-1058408989), INT32_C(   62628055), INT32_C( -870190090), INT32_C(  717585874),
                            INT32_C(-1058408989), INT32_C(   62628055), INT32_C( -870190090), INT32_C(  717585874),
                            INT32_C(-1058408989), INT32_C(   62628055), INT32_C( -870190090), INT32_C(  717585874),
                            INT32_C(-1058408989), INT32_C(   62628055), INT32_C( -870190090), INT32_C(  717585874)) },
    { INT32_C( -646678116),
      INT32_C( -636471021),
      INT32_C( 2050242002),
      INT32_C( 1467573389),
      simde_mm512_set_epi32(INT32_C( 1467573389), INT32_C( 2050242002), INT32_C( -636471021), INT32_C( -646678116),
                            INT32_C( 1467573389), INT32_C( 2050242002), INT32_C( -636471021), INT32_C( -646678116),
                            INT32_C( 1467573389), INT32_C( 2050242002), INT32_C( -636471021), INT32_C( -646678116),
                            INT32_C( 1467573389), INT32_C( 2050242002), INT32_C( -636471021), INT32_C( -646678116)) },
    { INT32_C( -468604998),
      INT32_C(  416458537),
      INT32_C(-1356493538),
      INT32_C( -338084785),
      simde_mm512_set_epi32(INT32_C( -338084785), INT32_C(-1356493538), INT32_C(  416458537), INT32_C( -468604998),
                            INT32_C( -338084785), INT32_C(-1356493538), INT32_C(  416458537), INT32_C( -468604998),
                            INT32_C( -338084785), INT32_C(-1356493538), INT32_C(  416458537), INT32_C( -468604998),
                            INT32_C( -338084785), INT32_C(-1356493538), INT32_C(  416458537), INT32_C( -468604998)) },
    { INT32_C( 1519812884),
      INT32_C(  743581731),
      INT32_C(-1035717687),
      INT32_C(  -38963525),
      simde_mm512_set_epi32(INT32_C(  -38963525), INT32_C(-1035717687), INT32_C(  743581731), INT32_C( 1519812884),
                            INT32_C(  -38963525), INT32_C(-1035717687), INT32_C(  743581731), INT32_C( 1519812884),
                            INT32_C(  -38963525), INT32_C(-1035717687), INT32_C(  743581731), INT32_C( 1519812884),
                            INT32_C(  -38963525), INT32_C(-1035717687), INT32_C(  743581731), INT32_C( 1519812884)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_setr4_epi32( test_vec[i].d, test_vec[i].c, test_vec[i].b, test_vec[i].a);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_setr4_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int64_t d; int64_t c; int64_t b; int64_t a;
    simde__m512i r;
  } test_vec[8] = {
    { INT64_C( 6563849718269597141),
      INT64_C(-6183679436467555899),
      INT64_C( -626758305238464386),
      INT64_C( 8994159492887548356),
      simde_mm512_set_epi64(INT64_C( 8994159492887548356), INT64_C( -626758305238464386),
                            INT64_C(-6183679436467555899), INT64_C( 6563849718269597141),
                            INT64_C( 8994159492887548356), INT64_C( -626758305238464386),
                            INT64_C(-6183679436467555899), INT64_C( 6563849718269597141)) },
    { INT64_C( 6729148419260484779),
      INT64_C( -277511807975612216),
      INT64_C(-8071294684814160544),
      INT64_C( 9097495128638227239),
      simde_mm512_set_epi64(INT64_C( 9097495128638227239), INT64_C(-8071294684814160544),
                            INT64_C( -277511807975612216), INT64_C( 6729148419260484779),
                            INT64_C( 9097495128638227239), INT64_C(-8071294684814160544),
                            INT64_C( -277511807975612216), INT64_C( 6729148419260484779)) },
    { INT64_C( 2451446111308764542),
      INT64_C( 7443262200234995807),
      INT64_C( 1452118817457897022),
      INT64_C( 8577124855339817739),
      simde_mm512_set_epi64(INT64_C( 8577124855339817739), INT64_C( 1452118817457897022),
                            INT64_C( 7443262200234995807), INT64_C( 2451446111308764542),
                            INT64_C( 8577124855339817739), INT64_C( 1452118817457897022),
                            INT64_C( 7443262200234995807), INT64_C( 2451446111308764542)) },
    { INT64_C( 5794476453905478874),
      INT64_C(-1405809235656433875),
      INT64_C(-9152840578969258696),
      INT64_C( 8562326329950659697),
      simde_mm512_set_epi64(INT64_C( 8562326329950659697), INT64_C(-9152840578969258696),
                            INT64_C(-1405809235656433875), INT64_C( 5794476453905478874),
                            INT64_C( 8562326329950659697), INT64_C(-9152840578969258696),
                            INT64_C(-1405809235656433875), INT64_C( 5794476453905478874)) },
    { INT64_C(-8764167661207563767),
      INT64_C( -157881503650322899),
      INT64_C(-4202918664443291804),
      INT64_C( 2806446076990238010),
      simde_mm512_set_epi64(INT64_C( 2806446076990238010), INT64_C(-4202918664443291804),
                            INT64_C( -157881503650322899), INT64_C(-8764167661207563767),
                            INT64_C( 2806446076990238010), INT64_C(-4202918664443291804),
                            INT64_C( -157881503650322899), INT64_C(-8764167661207563767)) },
    { INT64_C(-5837281652074857748),
      INT64_C(-7080037588592146058),
      INT64_C(-4482514275105483583),
      INT64_C( 7870122127635681284),
      simde_mm512_set_epi64(INT64_C( 7870122127635681284), INT64_C(-4482514275105483583),
                            INT64_C(-7080037588592146058), INT64_C(-5837281652074857748),
                            INT64_C( 7870122127635681284), INT64_C(-4482514275105483583),
                            INT64_C(-7080037588592146058), INT64_C(-5837281652074857748)) },
    { INT64_C(-2741649954653767454),
      INT64_C( 7022257894354348987),
      INT64_C(-7607333645615092101),
      INT64_C( 3821399499306603551),
      simde_mm512_set_epi64(INT64_C( 3821399499306603551), INT64_C(-7607333645615092101),
                            INT64_C( 7022257894354348987), INT64_C(-2741649954653767454),
                            INT64_C( 3821399499306603551), INT64_C(-7607333645615092101),
                            INT64_C( 7022257894354348987), INT64_C(-2741649954653767454)) },
    { INT64_C( 6134432460743068033),
      INT64_C( 1716871541978724160),
      INT64_C(-7436535278984624040),
      INT64_C( 1873233539406121615),
      simde_mm512_set_epi64(INT64_C( 1873233539406121615), INT64_C(-7436535278984624040),
                            INT64_C( 1716871541978724160), INT64_C( 6134432460743068033),
                            INT64_C( 1873233539406121615), INT64_C(-7436535278984624040),
                            INT64_C( 1716871541978724160), INT64_C( 6134432460743068033)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_setr4_epi64( test_vec[i].d, test_vec[i].c, test_vec[i].b, test_vec[i].a);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_setr4_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde_float32 d; simde_float32 c; simde_float32 b; simde_float32 a;
    simde__m512 r;
  } test_vec[8] = {
    { SIMDE_FLOAT32_C(   -92.68),
      SIMDE_FLOAT32_C(   845.12),
      SIMDE_FLOAT32_C(  -953.73),
      SIMDE_FLOAT32_C(   237.00),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   237.00), SIMDE_FLOAT32_C(  -953.73), SIMDE_FLOAT32_C(   845.12), SIMDE_FLOAT32_C(   -92.68),
                         SIMDE_FLOAT32_C(   237.00), SIMDE_FLOAT32_C(  -953.73), SIMDE_FLOAT32_C(   845.12), SIMDE_FLOAT32_C(   -92.68),
                         SIMDE_FLOAT32_C(   237.00), SIMDE_FLOAT32_C(  -953.73), SIMDE_FLOAT32_C(   845.12), SIMDE_FLOAT32_C(   -92.68),
                         SIMDE_FLOAT32_C(   237.00), SIMDE_FLOAT32_C(  -953.73), SIMDE_FLOAT32_C(   845.12), SIMDE_FLOAT32_C(   -92.68)) },
    { SIMDE_FLOAT32_C(  -555.84),
      SIMDE_FLOAT32_C(  -722.05),
      SIMDE_FLOAT32_C(  -788.55),
      SIMDE_FLOAT32_C(   545.68),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   545.68), SIMDE_FLOAT32_C(  -788.55), SIMDE_FLOAT32_C(  -722.05), SIMDE_FLOAT32_C(  -555.84),
                         SIMDE_FLOAT32_C(   545.68), SIMDE_FLOAT32_C(  -788.55), SIMDE_FLOAT32_C(  -722.05), SIMDE_FLOAT32_C(  -555.84),
                         SIMDE_FLOAT32_C(   545.68), SIMDE_FLOAT32_C(  -788.55), SIMDE_FLOAT32_C(  -722.05), SIMDE_FLOAT32_C(  -555.84),
                         SIMDE_FLOAT32_C(   545.68), SIMDE_FLOAT32_C(  -788.55), SIMDE_FLOAT32_C(  -722.05), SIMDE_FLOAT32_C(  -555.84)) },
    { SIMDE_FLOAT32_C(   823.18),
      SIMDE_FLOAT32_C(  -207.95),
      SIMDE_FLOAT32_C(  -413.77),
      SIMDE_FLOAT32_C(   808.21),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   808.21), SIMDE_FLOAT32_C(  -413.77), SIMDE_FLOAT32_C(  -207.95), SIMDE_FLOAT32_C(   823.18),
                         SIMDE_FLOAT32_C(   808.21), SIMDE_FLOAT32_C(  -413.77), SIMDE_FLOAT32_C(  -207.95), SIMDE_FLOAT32_C(   823.18),
                         SIMDE_FLOAT32_C(   808.21), SIMDE_FLOAT32_C(  -413.77), SIMDE_FLOAT32_C(  -207.95), SIMDE_FLOAT32_C(   823.18),
                         SIMDE_FLOAT32_C(   808.21), SIMDE_FLOAT32_C(  -413.77), SIMDE_FLOAT32_C(  -207.95), SIMDE_FLOAT32_C(   823.18)) },
    { SIMDE_FLOAT32_C(  -179.14),
      SIMDE_FLOAT32_C(    28.27),
      SIMDE_FLOAT32_C(  -190.88),
      SIMDE_FLOAT32_C(  -337.32),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -337.32), SIMDE_FLOAT32_C(  -190.88), SIMDE_FLOAT32_C(    28.27), SIMDE_FLOAT32_C(  -179.14),
                         SIMDE_FLOAT32_C(  -337.32), SIMDE_FLOAT32_C(  -190.88), SIMDE_FLOAT32_C(    28.27), SIMDE_FLOAT32_C(  -179.14),
                         SIMDE_FLOAT32_C(  -337.32), SIMDE_FLOAT32_C(  -190.88), SIMDE_FLOAT32_C(    28.27), SIMDE_FLOAT32_C(  -179.14),
                         SIMDE_FLOAT32_C(  -337.32), SIMDE_FLOAT32_C(  -190.88), SIMDE_FLOAT32_C(    28.27), SIMDE_FLOAT32_C(  -179.14)) },
    { SIMDE_FLOAT32_C(  -691.46),
      SIMDE_FLOAT32_C(  -801.82),
      SIMDE_FLOAT32_C(  -579.89),
      SIMDE_FLOAT32_C(  -420.42),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -420.42), SIMDE_FLOAT32_C(  -579.89), SIMDE_FLOAT32_C(  -801.82), SIMDE_FLOAT32_C(  -691.46),
                         SIMDE_FLOAT32_C(  -420.42), SIMDE_FLOAT32_C(  -579.89), SIMDE_FLOAT32_C(  -801.82), SIMDE_FLOAT32_C(  -691.46),
                         SIMDE_FLOAT32_C(  -420.42), SIMDE_FLOAT32_C(  -579.89), SIMDE_FLOAT32_C(  -801.82), SIMDE_FLOAT32_C(  -691.46),
                         SIMDE_FLOAT32_C(  -420.42), SIMDE_FLOAT32_C(  -579.89), SIMDE_FLOAT32_C(  -801.82), SIMDE_FLOAT32_C(  -691.46)) },
    { SIMDE_FLOAT32_C(   490.22),
      SIMDE_FLOAT32_C(   560.02),
      SIMDE_FLOAT32_C(  -244.24),
      SIMDE_FLOAT32_C(   184.70),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   184.70), SIMDE_FLOAT32_C(  -244.24), SIMDE_FLOAT32_C(   560.02), SIMDE_FLOAT32_C(   490.22),
                         SIMDE_FLOAT32_C(   184.70), SIMDE_FLOAT32_C(  -244.24), SIMDE_FLOAT32_C(   560.02), SIMDE_FLOAT32_C(   490.22),
                         SIMDE_FLOAT32_C(   184.70), SIMDE_FLOAT32_C(  -244.24), SIMDE_FLOAT32_C(   560.02), SIMDE_FLOAT32_C(   490.22),
                         SIMDE_FLOAT32_C(   184.70), SIMDE_FLOAT32_C(  -244.24), SIMDE_FLOAT32_C(   560.02), SIMDE_FLOAT32_C(   490.22)) },
    { SIMDE_FLOAT32_C(   353.38),
      SIMDE_FLOAT32_C(   199.20),
      SIMDE_FLOAT32_C(   132.74),
      SIMDE_FLOAT32_C(   599.57),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   599.57), SIMDE_FLOAT32_C(   132.74), SIMDE_FLOAT32_C(   199.20), SIMDE_FLOAT32_C(   353.38),
                         SIMDE_FLOAT32_C(   599.57), SIMDE_FLOAT32_C(   132.74), SIMDE_FLOAT32_C(   199.20), SIMDE_FLOAT32_C(   353.38),
                         SIMDE_FLOAT32_C(   599.57), SIMDE_FLOAT32_C(   132.74), SIMDE_FLOAT32_C(   199.20), SIMDE_FLOAT32_C(   353.38),
                         SIMDE_FLOAT32_C(   599.57), SIMDE_FLOAT32_C(   132.74), SIMDE_FLOAT32_C(   199.20), SIMDE_FLOAT32_C(   353.38)) },
    { SIMDE_FLOAT32_C(  -109.85),
      SIMDE_FLOAT32_C(    62.56),
      SIMDE_FLOAT32_C(   250.77),
      SIMDE_FLOAT32_C(  -873.95),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -873.95), SIMDE_FLOAT32_C(   250.77), SIMDE_FLOAT32_C(    62.56), SIMDE_FLOAT32_C(  -109.85),
                         SIMDE_FLOAT32_C(  -873.95), SIMDE_FLOAT32_C(   250.77), SIMDE_FLOAT32_C(    62.56), SIMDE_FLOAT32_C(  -109.85),
                         SIMDE_FLOAT32_C(  -873.95), SIMDE_FLOAT32_C(   250.77), SIMDE_FLOAT32_C(    62.56), SIMDE_FLOAT32_C(  -109.85),
                         SIMDE_FLOAT32_C(  -873.95), SIMDE_FLOAT32_C(   250.77), SIMDE_FLOAT32_C(    62.56), SIMDE_FLOAT32_C(  -109.85)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_setr4_ps( test_vec[i].d, test_vec[i].c, test_vec[i].b, test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_setr4_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde_float64  d; simde_float64  c; simde_float64  b; simde_float64  a;
    simde__m512d r;
  } test_vec[8] = {
   {  SIMDE_FLOAT64_C( -159.85),
      SIMDE_FLOAT64_C(  360.42),
      SIMDE_FLOAT64_C( -560.02),
      SIMDE_FLOAT64_C( -340.11),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -340.11), SIMDE_FLOAT64_C( -560.02),
                         SIMDE_FLOAT64_C(  360.42), SIMDE_FLOAT64_C( -159.85),
                         SIMDE_FLOAT64_C( -340.11), SIMDE_FLOAT64_C( -560.02),
                         SIMDE_FLOAT64_C(  360.42), SIMDE_FLOAT64_C( -159.85)) },
   {  SIMDE_FLOAT64_C(   76.83),
      SIMDE_FLOAT64_C( -871.20),
      SIMDE_FLOAT64_C(  277.42),
      SIMDE_FLOAT64_C(  632.86),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  632.86), SIMDE_FLOAT64_C(  277.42),
                         SIMDE_FLOAT64_C( -871.20), SIMDE_FLOAT64_C(   76.83),
                         SIMDE_FLOAT64_C(  632.86), SIMDE_FLOAT64_C(  277.42),
                         SIMDE_FLOAT64_C( -871.20), SIMDE_FLOAT64_C(   76.83)) },
   {  SIMDE_FLOAT64_C(  908.32),
      SIMDE_FLOAT64_C( -754.84),
      SIMDE_FLOAT64_C( -232.66),
      SIMDE_FLOAT64_C(  453.94),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  453.94), SIMDE_FLOAT64_C( -232.66),
                         SIMDE_FLOAT64_C( -754.84), SIMDE_FLOAT64_C(  908.32),
                         SIMDE_FLOAT64_C(  453.94), SIMDE_FLOAT64_C( -232.66),
                         SIMDE_FLOAT64_C( -754.84), SIMDE_FLOAT64_C(  908.32)) },
   {  SIMDE_FLOAT64_C(  389.27),
      SIMDE_FLOAT64_C(  400.56),
      SIMDE_FLOAT64_C(  223.12),
      SIMDE_FLOAT64_C( -299.15),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -299.15), SIMDE_FLOAT64_C(  223.12),
                         SIMDE_FLOAT64_C(  400.56), SIMDE_FLOAT64_C(  389.27),
                         SIMDE_FLOAT64_C( -299.15), SIMDE_FLOAT64_C(  223.12),
                         SIMDE_FLOAT64_C(  400.56), SIMDE_FLOAT64_C(  389.27)) },
   {  SIMDE_FLOAT64_C(  642.96),
      SIMDE_FLOAT64_C(  603.97),
      SIMDE_FLOAT64_C( -782.74),
      SIMDE_FLOAT64_C(  593.11),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  593.11), SIMDE_FLOAT64_C( -782.74),
                         SIMDE_FLOAT64_C(  603.97), SIMDE_FLOAT64_C(  642.96),
                         SIMDE_FLOAT64_C(  593.11), SIMDE_FLOAT64_C( -782.74),
                         SIMDE_FLOAT64_C(  603.97), SIMDE_FLOAT64_C(  642.96)) },
   {  SIMDE_FLOAT64_C(  918.13),
      SIMDE_FLOAT64_C(  886.70),
      SIMDE_FLOAT64_C(  337.10),
      SIMDE_FLOAT64_C( -359.87),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -359.87), SIMDE_FLOAT64_C(  337.10),
                         SIMDE_FLOAT64_C(  886.70), SIMDE_FLOAT64_C(  918.13),
                         SIMDE_FLOAT64_C( -359.87), SIMDE_FLOAT64_C(  337.10),
                         SIMDE_FLOAT64_C(  886.70), SIMDE_FLOAT64_C(  918.13)) },
   {  SIMDE_FLOAT64_C(  794.16),
      SIMDE_FLOAT64_C( -191.83),
      SIMDE_FLOAT64_C( -298.69),
      SIMDE_FLOAT64_C(  612.50),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  612.50), SIMDE_FLOAT64_C( -298.69),
                         SIMDE_FLOAT64_C( -191.83), SIMDE_FLOAT64_C(  794.16),
                         SIMDE_FLOAT64_C(  612.50), SIMDE_FLOAT64_C( -298.69),
                         SIMDE_FLOAT64_C( -191.83), SIMDE_FLOAT64_C(  794.16)) },
   {  SIMDE_FLOAT64_C(  850.90),
      SIMDE_FLOAT64_C( -669.22),
      SIMDE_FLOAT64_C(  -90.20),
      SIMDE_FLOAT64_C(  431.18),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  431.18), SIMDE_FLOAT64_C(  -90.20),
                         SIMDE_FLOAT64_C( -669.22), SIMDE_FLOAT64_C(  850.90),
                         SIMDE_FLOAT64_C(  431.18), SIMDE_FLOAT64_C(  -90.20),
                         SIMDE_FLOAT64_C( -669.22), SIMDE_FLOAT64_C(  850.90)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_setr4_pd(test_vec[i].d, test_vec[i].c, test_vec[i].b, test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_setr4_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_setr4_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_setr4_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_setr4_pd )
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
