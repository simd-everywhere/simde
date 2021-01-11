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
 *   2020      Hidayat Khan <huk2209@gmail.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN set4

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/set4.h>

static int
test_simde_mm512_set4_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int32_t d; int32_t c; int32_t b; int32_t a;
    simde__m512i r;
  } test_vec[8] = {
    { INT32_C( 1704071444),
      INT32_C(-1428654423),
      INT32_C( 1780802031),
      INT32_C(  917850215),
      simde_mm512_set_epi32(INT32_C( 1704071444), INT32_C(-1428654423), INT32_C( 1780802031), INT32_C(  917850215),
                            INT32_C( 1704071444), INT32_C(-1428654423), INT32_C( 1780802031), INT32_C(  917850215),
                            INT32_C( 1704071444), INT32_C(-1428654423), INT32_C( 1780802031), INT32_C(  917850215),
                            INT32_C( 1704071444), INT32_C(-1428654423), INT32_C( 1780802031), INT32_C(  917850215)) },
    { INT32_C( -585790761),
      INT32_C( -876839881),
      INT32_C(  793753163),
      INT32_C(-1831291840),
      simde_mm512_set_epi32(INT32_C( -585790761), INT32_C( -876839881), INT32_C(  793753163), INT32_C(-1831291840),
                            INT32_C( -585790761), INT32_C( -876839881), INT32_C(  793753163), INT32_C(-1831291840),
                            INT32_C( -585790761), INT32_C( -876839881), INT32_C(  793753163), INT32_C(-1831291840),
                            INT32_C( -585790761), INT32_C( -876839881), INT32_C(  793753163), INT32_C(-1831291840)) },
    { INT32_C( 1386668759),
      INT32_C( -584767031),
      INT32_C( -774218527),
      INT32_C( -668438843),
      simde_mm512_set_epi32(INT32_C( 1386668759), INT32_C( -584767031), INT32_C( -774218527), INT32_C( -668438843),
                            INT32_C( 1386668759), INT32_C( -584767031), INT32_C( -774218527), INT32_C( -668438843),
                            INT32_C( 1386668759), INT32_C( -584767031), INT32_C( -774218527), INT32_C( -668438843),
                            INT32_C( 1386668759), INT32_C( -584767031), INT32_C( -774218527), INT32_C( -668438843)) },
    { INT32_C(-1303355692),
      INT32_C( -501990193),
      INT32_C( 1644239252),
      INT32_C( 1280971850),
      simde_mm512_set_epi32(INT32_C(-1303355692), INT32_C( -501990193), INT32_C( 1644239252), INT32_C( 1280971850),
                            INT32_C(-1303355692), INT32_C( -501990193), INT32_C( 1644239252), INT32_C( 1280971850),
                            INT32_C(-1303355692), INT32_C( -501990193), INT32_C( 1644239252), INT32_C( 1280971850),
                            INT32_C(-1303355692), INT32_C( -501990193), INT32_C( 1644239252), INT32_C( 1280971850)) },
    { INT32_C( -594731794),
      INT32_C( 1836344530),
      INT32_C(-1063862321),
      INT32_C(   -5810296),
      simde_mm512_set_epi32(INT32_C( -594731794), INT32_C( 1836344530), INT32_C(-1063862321), INT32_C(   -5810296),
                            INT32_C( -594731794), INT32_C( 1836344530), INT32_C(-1063862321), INT32_C(   -5810296),
                            INT32_C( -594731794), INT32_C( 1836344530), INT32_C(-1063862321), INT32_C(   -5810296),
                            INT32_C( -594731794), INT32_C( 1836344530), INT32_C(-1063862321), INT32_C(   -5810296)) },
    { INT32_C(-1188761421),
      INT32_C( -479336401),
      INT32_C(  651981060),
      INT32_C( 1888988895),
      simde_mm512_set_epi32(INT32_C(-1188761421), INT32_C( -479336401), INT32_C(  651981060), INT32_C( 1888988895),
                            INT32_C(-1188761421), INT32_C( -479336401), INT32_C(  651981060), INT32_C( 1888988895),
                            INT32_C(-1188761421), INT32_C( -479336401), INT32_C(  651981060), INT32_C( 1888988895),
                            INT32_C(-1188761421), INT32_C( -479336401), INT32_C(  651981060), INT32_C( 1888988895)) },
    { INT32_C(-1384652575),
      INT32_C( -302711392),
      INT32_C(   -7833127),
      INT32_C( 1710017817),
      simde_mm512_set_epi32(INT32_C(-1384652575), INT32_C( -302711392), INT32_C(   -7833127), INT32_C( 1710017817),
                            INT32_C(-1384652575), INT32_C( -302711392), INT32_C(   -7833127), INT32_C( 1710017817),
                            INT32_C(-1384652575), INT32_C( -302711392), INT32_C(   -7833127), INT32_C( 1710017817),
                            INT32_C(-1384652575), INT32_C( -302711392), INT32_C(   -7833127), INT32_C( 1710017817)) },
    { INT32_C(-1634061345),
      INT32_C( 1275812965),
      INT32_C(  644899010),
      INT32_C(-1359876073),
      simde_mm512_set_epi32(INT32_C(-1634061345), INT32_C( 1275812965), INT32_C(  644899010), INT32_C(-1359876073),
                            INT32_C(-1634061345), INT32_C( 1275812965), INT32_C(  644899010), INT32_C(-1359876073),
                            INT32_C(-1634061345), INT32_C( 1275812965), INT32_C(  644899010), INT32_C(-1359876073),
                            INT32_C(-1634061345), INT32_C( 1275812965), INT32_C(  644899010), INT32_C(-1359876073)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_set4_epi32(test_vec[i].d, test_vec[i].c, test_vec[i].b, test_vec[i].a);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_set4_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    int64_t d; int64_t c; int64_t b; int64_t a;
    simde__m512i r;
  } test_vec[8] = {
    { INT64_C(-2593705665723537468),
      INT64_C( 7248735595083828941),
      INT64_C(-1480325022577808917),
      INT64_C(-3460515645430413676),
      simde_mm512_set_epi64(INT64_C(-2593705665723537468), INT64_C( 7248735595083828941),
                            INT64_C(-1480325022577808917), INT64_C(-3460515645430413676),
                            INT64_C(-2593705665723537468), INT64_C( 7248735595083828941),
                            INT64_C(-1480325022577808917), INT64_C(-3460515645430413676)) },
    { INT64_C( 9178362238632935456),
      INT64_C( 4357840778555019964),
      INT64_C(-4052759487924272616),
      INT64_C( 5679911602698625292),
      simde_mm512_set_epi64(INT64_C( 9178362238632935456), INT64_C( 4357840778555019964),
                            INT64_C(-4052759487924272616), INT64_C( 5679911602698625292),
                            INT64_C( 9178362238632935456), INT64_C( 4357840778555019964),
                            INT64_C(-4052759487924272616), INT64_C( 5679911602698625292)) },
    { INT64_C( 4752422498272537365),
      INT64_C(-8834973358315632886),
      INT64_C(-3972020332791269926),
      INT64_C( 1768010603398062576),
      simde_mm512_set_epi64(INT64_C( 4752422498272537365), INT64_C(-8834973358315632886),
                            INT64_C(-3972020332791269926), INT64_C( 1768010603398062576),
                            INT64_C( 4752422498272537365), INT64_C(-8834973358315632886),
                            INT64_C(-3972020332791269926), INT64_C( 1768010603398062576)) },
    { INT64_C( 1080024807241277031),
      INT64_C( 6916234010560042694),
      INT64_C(-5226061354301241362),
      INT64_C(-7556111188703729544),
      simde_mm512_set_epi64(INT64_C( 1080024807241277031), INT64_C( 6916234010560042694),
                            INT64_C(-5226061354301241362), INT64_C(-7556111188703729544),
                            INT64_C( 1080024807241277031), INT64_C( 6916234010560042694),
                            INT64_C(-5226061354301241362), INT64_C(-7556111188703729544)) },
    { INT64_C(-2308292611043682685),
      INT64_C(-4902179645913622872),
      INT64_C( 1328708783259675127),
      INT64_C(-8034995773554670267),
      simde_mm512_set_epi64(INT64_C(-2308292611043682685), INT64_C(-4902179645913622872),
                            INT64_C( 1328708783259675127), INT64_C(-8034995773554670267),
                            INT64_C(-2308292611043682685), INT64_C(-4902179645913622872),
                            INT64_C( 1328708783259675127), INT64_C(-8034995773554670267)) },
    { INT64_C( -429235303463415783),
      INT64_C( 3969176932066333632),
      INT64_C(-3604302014217727944),
      INT64_C( 3066662634116690752),
      simde_mm512_set_epi64(INT64_C( -429235303463415783), INT64_C( 3969176932066333632),
                            INT64_C(-3604302014217727944), INT64_C( 3066662634116690752),
                            INT64_C( -429235303463415783), INT64_C( 3969176932066333632),
                            INT64_C(-3604302014217727944), INT64_C( 3066662634116690752)) },
    { INT64_C( 4584355551724557735),
      INT64_C(-3275746751222287827),
      INT64_C(-3251679101250531673),
      INT64_C(-3482741022099573882),
      simde_mm512_set_epi64(INT64_C( 4584355551724557735), INT64_C(-3275746751222287827),
                            INT64_C(-3251679101250531673), INT64_C(-3482741022099573882),
                            INT64_C( 4584355551724557735), INT64_C(-3275746751222287827),
                            INT64_C(-3251679101250531673), INT64_C(-3482741022099573882)) },
    { INT64_C(-8676900622553771545),
      INT64_C(-1335594618905000828),
      INT64_C( -120183447945767440),
      INT64_C(-4223741771381142614),
      simde_mm512_set_epi64(INT64_C(-8676900622553771545), INT64_C(-1335594618905000828),
                            INT64_C( -120183447945767440), INT64_C(-4223741771381142614),
                            INT64_C(-8676900622553771545), INT64_C(-1335594618905000828),
                            INT64_C( -120183447945767440), INT64_C(-4223741771381142614)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_set4_epi64(test_vec[i].d, test_vec[i].c, test_vec[i].b, test_vec[i].a);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_set4_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde_float32 d; simde_float32 c; simde_float32 b; simde_float32 a;
    simde__m512 r;
  } test_vec[8] = {
    { SIMDE_FLOAT32_C(   549.42),
      SIMDE_FLOAT32_C(   390.74),
      SIMDE_FLOAT32_C(  -762.45),
      SIMDE_FLOAT32_C(   105.60),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   549.42), SIMDE_FLOAT32_C(   390.74), SIMDE_FLOAT32_C(  -762.45), SIMDE_FLOAT32_C(   105.60),
                         SIMDE_FLOAT32_C(   549.42), SIMDE_FLOAT32_C(   390.74), SIMDE_FLOAT32_C(  -762.45), SIMDE_FLOAT32_C(   105.60),
                         SIMDE_FLOAT32_C(   549.42), SIMDE_FLOAT32_C(   390.74), SIMDE_FLOAT32_C(  -762.45), SIMDE_FLOAT32_C(   105.60),
                         SIMDE_FLOAT32_C(   549.42), SIMDE_FLOAT32_C(   390.74), SIMDE_FLOAT32_C(  -762.45), SIMDE_FLOAT32_C(   105.60)) },
    { SIMDE_FLOAT32_C(  -455.28),
      SIMDE_FLOAT32_C(   904.62),
      SIMDE_FLOAT32_C(    43.64),
      SIMDE_FLOAT32_C(  -136.13),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -455.28), SIMDE_FLOAT32_C(   904.62), SIMDE_FLOAT32_C(    43.64), SIMDE_FLOAT32_C(  -136.13),
                         SIMDE_FLOAT32_C(  -455.28), SIMDE_FLOAT32_C(   904.62), SIMDE_FLOAT32_C(    43.64), SIMDE_FLOAT32_C(  -136.13),
                         SIMDE_FLOAT32_C(  -455.28), SIMDE_FLOAT32_C(   904.62), SIMDE_FLOAT32_C(    43.64), SIMDE_FLOAT32_C(  -136.13),
                         SIMDE_FLOAT32_C(  -455.28), SIMDE_FLOAT32_C(   904.62), SIMDE_FLOAT32_C(    43.64), SIMDE_FLOAT32_C(  -136.13)) },
    { SIMDE_FLOAT32_C(   780.38),
      SIMDE_FLOAT32_C(  -314.57),
      SIMDE_FLOAT32_C(   -46.15),
      SIMDE_FLOAT32_C(  -499.56),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   780.38), SIMDE_FLOAT32_C(  -314.57), SIMDE_FLOAT32_C(   -46.15), SIMDE_FLOAT32_C(  -499.56),
                         SIMDE_FLOAT32_C(   780.38), SIMDE_FLOAT32_C(  -314.57), SIMDE_FLOAT32_C(   -46.15), SIMDE_FLOAT32_C(  -499.56),
                         SIMDE_FLOAT32_C(   780.38), SIMDE_FLOAT32_C(  -314.57), SIMDE_FLOAT32_C(   -46.15), SIMDE_FLOAT32_C(  -499.56),
                         SIMDE_FLOAT32_C(   780.38), SIMDE_FLOAT32_C(  -314.57), SIMDE_FLOAT32_C(   -46.15), SIMDE_FLOAT32_C(  -499.56)) },
    { SIMDE_FLOAT32_C(  -150.61),
      SIMDE_FLOAT32_C(  -652.43),
      SIMDE_FLOAT32_C(   308.34),
      SIMDE_FLOAT32_C(   420.76),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -150.61), SIMDE_FLOAT32_C(  -652.43), SIMDE_FLOAT32_C(   308.34), SIMDE_FLOAT32_C(   420.76),
                         SIMDE_FLOAT32_C(  -150.61), SIMDE_FLOAT32_C(  -652.43), SIMDE_FLOAT32_C(   308.34), SIMDE_FLOAT32_C(   420.76),
                         SIMDE_FLOAT32_C(  -150.61), SIMDE_FLOAT32_C(  -652.43), SIMDE_FLOAT32_C(   308.34), SIMDE_FLOAT32_C(   420.76),
                         SIMDE_FLOAT32_C(  -150.61), SIMDE_FLOAT32_C(  -652.43), SIMDE_FLOAT32_C(   308.34), SIMDE_FLOAT32_C(   420.76)) },
    { SIMDE_FLOAT32_C(   591.99),
      SIMDE_FLOAT32_C(   726.98),
      SIMDE_FLOAT32_C(   873.87),
      SIMDE_FLOAT32_C(  -584.98),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   591.99), SIMDE_FLOAT32_C(   726.98), SIMDE_FLOAT32_C(   873.87), SIMDE_FLOAT32_C(  -584.98),
                         SIMDE_FLOAT32_C(   591.99), SIMDE_FLOAT32_C(   726.98), SIMDE_FLOAT32_C(   873.87), SIMDE_FLOAT32_C(  -584.98),
                         SIMDE_FLOAT32_C(   591.99), SIMDE_FLOAT32_C(   726.98), SIMDE_FLOAT32_C(   873.87), SIMDE_FLOAT32_C(  -584.98),
                         SIMDE_FLOAT32_C(   591.99), SIMDE_FLOAT32_C(   726.98), SIMDE_FLOAT32_C(   873.87), SIMDE_FLOAT32_C(  -584.98)) },
    { SIMDE_FLOAT32_C(  -867.47),
      SIMDE_FLOAT32_C(  -316.79),
      SIMDE_FLOAT32_C(   168.26),
      SIMDE_FLOAT32_C(  -818.10),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -867.47), SIMDE_FLOAT32_C(  -316.79), SIMDE_FLOAT32_C(   168.26), SIMDE_FLOAT32_C(  -818.10),
                         SIMDE_FLOAT32_C(  -867.47), SIMDE_FLOAT32_C(  -316.79), SIMDE_FLOAT32_C(   168.26), SIMDE_FLOAT32_C(  -818.10),
                         SIMDE_FLOAT32_C(  -867.47), SIMDE_FLOAT32_C(  -316.79), SIMDE_FLOAT32_C(   168.26), SIMDE_FLOAT32_C(  -818.10),
                         SIMDE_FLOAT32_C(  -867.47), SIMDE_FLOAT32_C(  -316.79), SIMDE_FLOAT32_C(   168.26), SIMDE_FLOAT32_C(  -818.10)) },
    { SIMDE_FLOAT32_C(   307.87),
      SIMDE_FLOAT32_C(  -536.04),
      SIMDE_FLOAT32_C(   660.51),
      SIMDE_FLOAT32_C(   761.16),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(   307.87), SIMDE_FLOAT32_C(  -536.04), SIMDE_FLOAT32_C(   660.51), SIMDE_FLOAT32_C(   761.16),
                         SIMDE_FLOAT32_C(   307.87), SIMDE_FLOAT32_C(  -536.04), SIMDE_FLOAT32_C(   660.51), SIMDE_FLOAT32_C(   761.16),
                         SIMDE_FLOAT32_C(   307.87), SIMDE_FLOAT32_C(  -536.04), SIMDE_FLOAT32_C(   660.51), SIMDE_FLOAT32_C(   761.16),
                         SIMDE_FLOAT32_C(   307.87), SIMDE_FLOAT32_C(  -536.04), SIMDE_FLOAT32_C(   660.51), SIMDE_FLOAT32_C(   761.16)) },
    { SIMDE_FLOAT32_C(  -886.20),
      SIMDE_FLOAT32_C(   955.45),
      SIMDE_FLOAT32_C(  -821.28),
      SIMDE_FLOAT32_C(  -285.01),
      simde_mm512_set_ps(SIMDE_FLOAT32_C(  -886.20), SIMDE_FLOAT32_C(   955.45), SIMDE_FLOAT32_C(  -821.28), SIMDE_FLOAT32_C(  -285.01),
                         SIMDE_FLOAT32_C(  -886.20), SIMDE_FLOAT32_C(   955.45), SIMDE_FLOAT32_C(  -821.28), SIMDE_FLOAT32_C(  -285.01),
                         SIMDE_FLOAT32_C(  -886.20), SIMDE_FLOAT32_C(   955.45), SIMDE_FLOAT32_C(  -821.28), SIMDE_FLOAT32_C(  -285.01),
                         SIMDE_FLOAT32_C(  -886.20), SIMDE_FLOAT32_C(   955.45), SIMDE_FLOAT32_C(  -821.28), SIMDE_FLOAT32_C(  -285.01)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_set4_ps(test_vec[i].d, test_vec[i].c, test_vec[i].b, test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm512_set4_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde_float64 d; simde_float64 c; simde_float64 b; simde_float64 a;
    simde__m512d r;
  } test_vec[8] = {
    { SIMDE_FLOAT64_C( -466.05),
      SIMDE_FLOAT64_C(  -39.63),
      SIMDE_FLOAT64_C(  479.17),
      SIMDE_FLOAT64_C(  865.09),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -466.05), SIMDE_FLOAT64_C(  -39.63),
                         SIMDE_FLOAT64_C(  479.17), SIMDE_FLOAT64_C(  865.09),
                         SIMDE_FLOAT64_C( -466.05), SIMDE_FLOAT64_C(  -39.63),
                         SIMDE_FLOAT64_C(  479.17), SIMDE_FLOAT64_C(  865.09)) },
    { SIMDE_FLOAT64_C( -466.60),
      SIMDE_FLOAT64_C(   25.52),
      SIMDE_FLOAT64_C(  108.39),
      SIMDE_FLOAT64_C( -438.48),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -466.60), SIMDE_FLOAT64_C(   25.52),
                         SIMDE_FLOAT64_C(  108.39), SIMDE_FLOAT64_C( -438.48),
                         SIMDE_FLOAT64_C( -466.60), SIMDE_FLOAT64_C(   25.52),
                         SIMDE_FLOAT64_C(  108.39), SIMDE_FLOAT64_C( -438.48)) },
    { SIMDE_FLOAT64_C(  192.69),
      SIMDE_FLOAT64_C( -608.10),
      SIMDE_FLOAT64_C( -132.84),
      SIMDE_FLOAT64_C(  545.82),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  192.69), SIMDE_FLOAT64_C( -608.10),
                         SIMDE_FLOAT64_C( -132.84), SIMDE_FLOAT64_C(  545.82),
                         SIMDE_FLOAT64_C(  192.69), SIMDE_FLOAT64_C( -608.10),
                         SIMDE_FLOAT64_C( -132.84), SIMDE_FLOAT64_C(  545.82)) },
    { SIMDE_FLOAT64_C( -398.73),
      SIMDE_FLOAT64_C(  115.78),
      SIMDE_FLOAT64_C(  863.37),
      SIMDE_FLOAT64_C( -519.72),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -398.73), SIMDE_FLOAT64_C(  115.78),
                         SIMDE_FLOAT64_C(  863.37), SIMDE_FLOAT64_C( -519.72),
                         SIMDE_FLOAT64_C( -398.73), SIMDE_FLOAT64_C(  115.78),
                         SIMDE_FLOAT64_C(  863.37), SIMDE_FLOAT64_C( -519.72)) },
    { SIMDE_FLOAT64_C( -372.73),
      SIMDE_FLOAT64_C(  151.17),
      SIMDE_FLOAT64_C(  865.66),
      SIMDE_FLOAT64_C(  411.45),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -372.73), SIMDE_FLOAT64_C(  151.17),
                         SIMDE_FLOAT64_C(  865.66), SIMDE_FLOAT64_C(  411.45),
                         SIMDE_FLOAT64_C( -372.73), SIMDE_FLOAT64_C(  151.17),
                         SIMDE_FLOAT64_C(  865.66), SIMDE_FLOAT64_C(  411.45)) },
    { SIMDE_FLOAT64_C(  448.07),
      SIMDE_FLOAT64_C(  391.44),
      SIMDE_FLOAT64_C(  859.02),
      SIMDE_FLOAT64_C(   20.32),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(  448.07), SIMDE_FLOAT64_C(  391.44),
                         SIMDE_FLOAT64_C(  859.02), SIMDE_FLOAT64_C(   20.32),
                         SIMDE_FLOAT64_C(  448.07), SIMDE_FLOAT64_C(  391.44),
                         SIMDE_FLOAT64_C(  859.02), SIMDE_FLOAT64_C(   20.32)) },
    { SIMDE_FLOAT64_C( -644.29),
      SIMDE_FLOAT64_C(  326.35),
      SIMDE_FLOAT64_C(  131.23),
      SIMDE_FLOAT64_C( -950.42),
      simde_mm512_set_pd(SIMDE_FLOAT64_C( -644.29), SIMDE_FLOAT64_C(  326.35),
                         SIMDE_FLOAT64_C(  131.23), SIMDE_FLOAT64_C( -950.42),
                         SIMDE_FLOAT64_C( -644.29), SIMDE_FLOAT64_C(  326.35),
                         SIMDE_FLOAT64_C(  131.23), SIMDE_FLOAT64_C( -950.42)) },
    { SIMDE_FLOAT64_C(    9.75),
      SIMDE_FLOAT64_C(  116.77),
      SIMDE_FLOAT64_C(   62.44),
      SIMDE_FLOAT64_C(  838.89),
      simde_mm512_set_pd(SIMDE_FLOAT64_C(    9.75), SIMDE_FLOAT64_C(  116.77),
                         SIMDE_FLOAT64_C(   62.44), SIMDE_FLOAT64_C(  838.89),
                         SIMDE_FLOAT64_C(    9.75), SIMDE_FLOAT64_C(  116.77),
                         SIMDE_FLOAT64_C(   62.44), SIMDE_FLOAT64_C(  838.89)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_set4_pd(test_vec[i].d, test_vec[i].c, test_vec[i].b, test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set4_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set4_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set4_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_set4_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
