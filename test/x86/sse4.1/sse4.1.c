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
#include <simde/x86/sse4.1.h>

#include <stdio.h>

static MunitResult
test_simde_mm_blendv_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i mask;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(0x34, 0xa7, 0x72, 0x78, 0x4b, 0xd1, 0x7a, 0xcf,
			0x2c, 0xe8, 0x66, 0x94, 0x48, 0xcc, 0xde, 0xee),
      simde_mm_set_epi8(0xc0, 0x9e, 0xe2, 0x5d, 0x63, 0xfb, 0x66, 0x2e,
			0x7b, 0x82, 0x71, 0x9e, 0xc8, 0x5c, 0x91, 0x46),
      simde_mm_set_epi8(0x05, 0xe4, 0x69, 0x00, 0x89, 0x60, 0xce, 0x3c,
			0x07, 0xc2, 0xe1, 0x5b, 0xb6, 0xb0, 0x01, 0x25),
      simde_mm_set_epi8(0x34, 0x9e, 0x72, 0x78, 0x63, 0xd1, 0x66, 0xcf,
			0x2c, 0x82, 0x71, 0x94, 0xc8, 0x5c, 0xde, 0xee) },
    { simde_mm_set_epi8(0xf2, 0x28, 0xce, 0x53, 0x90, 0xff, 0xa6, 0xa0,
			0x48, 0x5d, 0x95, 0x88, 0xe1, 0xee, 0x0b, 0x76),
      simde_mm_set_epi8(0xe6, 0x5d, 0xfc, 0x7b, 0x53, 0xa8, 0xe1, 0xf5,
			0x51, 0xa3, 0x9a, 0x18, 0xb3, 0x58, 0x71, 0xb1),
      simde_mm_set_epi8(0xea, 0x82, 0xe3, 0xcc, 0xb9, 0xab, 0x5a, 0x79,
			0x5c, 0x8a, 0x20, 0xef, 0xc9, 0xa7, 0x9e, 0x2f),
      simde_mm_set_epi8(0xe6, 0x5d, 0xfc, 0x7b, 0x53, 0xa8, 0xa6, 0xa0,
			0x48, 0xa3, 0x95, 0x18, 0xb3, 0x58, 0x71, 0x76) },
    { simde_mm_set_epi8(0x81, 0x28, 0xa8, 0x5c, 0xf7, 0xf4, 0xb6, 0xde,
			0xe2, 0xdb, 0xae, 0x81, 0x17, 0x13, 0x7f, 0xfb),
      simde_mm_set_epi8(0xfe, 0xbe, 0xbd, 0xee, 0xf8, 0x16, 0x29, 0x13,
			0x5b, 0xf2, 0xbe, 0x81, 0xb2, 0xa7, 0xa7, 0x55),
      simde_mm_set_epi8(0x0f, 0xaa, 0xef, 0x52, 0xee, 0xd2, 0x15, 0x92,
			0xda, 0xbb, 0xbb, 0x13, 0x8d, 0x7c, 0xed, 0x33),
      simde_mm_set_epi8(0x81, 0xbe, 0xbd, 0x5c, 0xf8, 0x16, 0xb6, 0x13,
			0x5b, 0xf2, 0xbe, 0x81, 0xb2, 0x13, 0xa7, 0xfb) },
    { simde_mm_set_epi8(0xa5, 0xde, 0x6f, 0xb2, 0x26, 0x2d, 0x47, 0x80,
			0xa7, 0xc0, 0xe5, 0xd1, 0x32, 0x11, 0xe4, 0xbf),
      simde_mm_set_epi8(0x46, 0xea, 0x2b, 0x73, 0x22, 0x24, 0xd5, 0x98,
			0x6d, 0x43, 0x61, 0x56, 0xd7, 0x78, 0x3f, 0x31),
      simde_mm_set_epi8(0x7c, 0x3a, 0x72, 0xe8, 0xcb, 0xdd, 0xf7, 0x2f,
			0xec, 0xda, 0xde, 0x92, 0x03, 0x4f, 0x41, 0x28),
      simde_mm_set_epi8(0xa5, 0xde, 0x6f, 0x73, 0x22, 0x24, 0xd5, 0x80,
			0x6d, 0x43, 0x61, 0x56, 0x32, 0x11, 0xe4, 0xbf) },
    { simde_mm_set_epi8(0xff, 0x4a, 0x0a, 0xab, 0x07, 0xc7, 0xb4, 0xe5,
			0x87, 0x46, 0xda, 0x67, 0x3b, 0x8b, 0x87, 0x16),
      simde_mm_set_epi8(0x45, 0xbd, 0x48, 0x02, 0xe3, 0xb7, 0xf1, 0x58,
			0x1b, 0xeb, 0x79, 0xd8, 0xaf, 0xa5, 0x6c, 0xde),
      simde_mm_set_epi8(0xd5, 0x47, 0xb2, 0xcb, 0x9c, 0xab, 0xc6, 0x76,
			0xe2, 0xc7, 0x30, 0x73, 0xfd, 0xf3, 0x83, 0x6a),
      simde_mm_set_epi8(0x45, 0x4a, 0x48, 0x02, 0xe3, 0xb7, 0xf1, 0xe5,
			0x1b, 0xeb, 0xda, 0x67, 0xaf, 0xa5, 0x6c, 0x16) },
    { simde_mm_set_epi8(0x39, 0xac, 0xc7, 0x31, 0x0e, 0xfe, 0xcd, 0x12,
			0x88, 0x73, 0x6c, 0x17, 0x4f, 0xaa, 0x02, 0xb1),
      simde_mm_set_epi8(0xee, 0xf3, 0x2a, 0xca, 0x08, 0x82, 0xe3, 0x0f,
			0xbc, 0x36, 0x8b, 0x32, 0x3d, 0x59, 0x6e, 0x13),
      simde_mm_set_epi8(0xa4, 0xb2, 0x1d, 0x5a, 0x1a, 0x32, 0x2e, 0x13,
			0xaf, 0xbc, 0xf3, 0x77, 0x19, 0xdc, 0xf7, 0x91),
      simde_mm_set_epi8(0xee, 0xf3, 0xc7, 0x31, 0x0e, 0xfe, 0xcd, 0x12,
			0xbc, 0x36, 0x8b, 0x17, 0x4f, 0x59, 0x6e, 0x13) },
    { simde_mm_set_epi8(0xc4, 0x5d, 0x16, 0xa8, 0x7c, 0x7b, 0x67, 0x40,
			0xa1, 0x74, 0x44, 0x65, 0x7e, 0xdc, 0x16, 0x01),
      simde_mm_set_epi8(0x02, 0xfb, 0xea, 0xd6, 0x7b, 0xa1, 0x89, 0xda,
			0x60, 0x2c, 0x2b, 0x22, 0x47, 0x99, 0xd0, 0xe7),
      simde_mm_set_epi8(0x36, 0xa1, 0x88, 0x6a, 0x2f, 0x6b, 0x06, 0x25,
			0x80, 0x98, 0x95, 0x84, 0x70, 0x95, 0xfe, 0xa6),
      simde_mm_set_epi8(0xc4, 0xfb, 0xea, 0xa8, 0x7c, 0x7b, 0x67, 0x40,
			0x60, 0x2c, 0x2b, 0x22, 0x7e, 0x99, 0xd0, 0xe7) },
    { simde_mm_set_epi8(0x21, 0x0c, 0x28, 0x62, 0x77, 0x32, 0xd2, 0x1f,
			0x9a, 0xa9, 0x93, 0xc5, 0xdb, 0x6b, 0x13, 0xef),
      simde_mm_set_epi8(0xa5, 0x7d, 0x8b, 0x2e, 0xb4, 0xb5, 0x8a, 0x37,
			0x25, 0xda, 0xec, 0x21, 0x7e, 0x89, 0x6a, 0x11),
      simde_mm_set_epi8(0x0f, 0x46, 0x0a, 0x7d, 0xdb, 0xd5, 0x8d, 0xfe,
			0x4e, 0x54, 0x03, 0x67, 0x13, 0xc5, 0x25, 0x19),
      simde_mm_set_epi8(0x21, 0x0c, 0x28, 0x62, 0xb4, 0xb5, 0x8a, 0x37,
			0x9a, 0xa9, 0x93, 0xc5, 0xdb, 0x89, 0x13, 0xef) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_blendv_epi8(test_vec[i].a, test_vec[i].b, test_vec[i].mask);
    simde_assert_m128_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_blend_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C( 13825), INT16_C(-17802), INT16_C( -1598), INT16_C( 25326),
                         INT16_C( 14943), INT16_C( -8227), INT16_C( 21745), INT16_C(  9989)),
      simde_mm_set_epi16(INT16_C(-11058), INT16_C(  4192), INT16_C(-28252), INT16_C( 10795),
                         INT16_C( 19700), INT16_C( 29704), INT16_C( -7052), INT16_C( 16432)),
      simde_mm_set_epi16(INT16_C( 13825), INT16_C(-17802), INT16_C( -1598), INT16_C( 25326),
                         INT16_C( 14943), INT16_C( -8227), INT16_C( -7052), INT16_C( 16432)) },
    { simde_mm_set_epi16(INT16_C(-17914), INT16_C(-32103), INT16_C( 17164), INT16_C(  -187),
                         INT16_C( 21942), INT16_C(-25306), INT16_C( -7849), INT16_C(-11297)),
      simde_mm_set_epi16(INT16_C( -9027), INT16_C(-14363), INT16_C( 16126), INT16_C( 30921),
                         INT16_C(  3730), INT16_C(-20492), INT16_C( -5510), INT16_C( 32723)),
      simde_mm_set_epi16(INT16_C(-17914), INT16_C(-32103), INT16_C( 17164), INT16_C(  -187),
                         INT16_C( 21942), INT16_C(-25306), INT16_C( -5510), INT16_C( 32723)) },
    { simde_mm_set_epi16(INT16_C(-25152), INT16_C( 30665), INT16_C( 26270), INT16_C( 23820),
                         INT16_C(-24322), INT16_C(   706), INT16_C(-26336), INT16_C(-13296)),
      simde_mm_set_epi16(INT16_C(-24671), INT16_C(-19680), INT16_C( 10653), INT16_C( -9500),
                         INT16_C(-16899), INT16_C(   495), INT16_C( 26780), INT16_C(-11315)),
      simde_mm_set_epi16(INT16_C(-25152), INT16_C( 30665), INT16_C( 26270), INT16_C( 23820),
                         INT16_C(-24322), INT16_C(   706), INT16_C( 26780), INT16_C(-11315)) },
    { simde_mm_set_epi16(INT16_C( 20562), INT16_C(-19834), INT16_C(  5180), INT16_C( -5117),
                         INT16_C( 16168), INT16_C( 23520), INT16_C(-16838), INT16_C( 28892)),
      simde_mm_set_epi16(INT16_C(  2860), INT16_C( -6670), INT16_C(-25365), INT16_C( -4954),
                         INT16_C( 30912), INT16_C(  6045), INT16_C(  2749), INT16_C(  4401)),
      simde_mm_set_epi16(INT16_C( 20562), INT16_C(-19834), INT16_C(  5180), INT16_C( -5117),
                         INT16_C( 16168), INT16_C( 23520), INT16_C(  2749), INT16_C(  4401)) },
    { simde_mm_set_epi16(INT16_C( 25997), INT16_C( -1860), INT16_C( -9126), INT16_C( 12214),
                         INT16_C(  7159), INT16_C( -2303), INT16_C(  7182), INT16_C(-20779)),
      simde_mm_set_epi16(INT16_C( -7432), INT16_C(   954), INT16_C(-26453), INT16_C( -2062),
                         INT16_C( 14984), INT16_C( -7563), INT16_C( 13369), INT16_C( -4134)),
      simde_mm_set_epi16(INT16_C( 25997), INT16_C( -1860), INT16_C( -9126), INT16_C( 12214),
                         INT16_C(  7159), INT16_C( -2303), INT16_C( 13369), INT16_C( -4134)) },
    { simde_mm_set_epi16(INT16_C( -6104), INT16_C(-18564), INT16_C(  5298), INT16_C( -6001),
                         INT16_C( -6122), INT16_C( 14804), INT16_C(-32440), INT16_C(-10960)),
      simde_mm_set_epi16(INT16_C(  8197), INT16_C( 14220), INT16_C(-10924), INT16_C( 17196),
                         INT16_C( 21768), INT16_C(  7639), INT16_C( -4935), INT16_C(  -993)),
      simde_mm_set_epi16(INT16_C( -6104), INT16_C(-18564), INT16_C(  5298), INT16_C( -6001),
                         INT16_C( -6122), INT16_C( 14804), INT16_C( -4935), INT16_C(  -993)) },
    { simde_mm_set_epi16(INT16_C(  6003), INT16_C( -5880), INT16_C( 31967), INT16_C(-28984),
                         INT16_C( -9503), INT16_C( 30320), INT16_C(-19146), INT16_C( 32146)),
      simde_mm_set_epi16(INT16_C(  4317), INT16_C( 22644), INT16_C(-25807), INT16_C(-30524),
                         INT16_C(   223), INT16_C( -7098), INT16_C(  9867), INT16_C( -9190)),
      simde_mm_set_epi16(INT16_C(  6003), INT16_C( -5880), INT16_C( 31967), INT16_C(-28984),
                         INT16_C( -9503), INT16_C( 30320), INT16_C(  9867), INT16_C( -9190)) },
    { simde_mm_set_epi16(INT16_C( 12033), INT16_C( 14639), INT16_C( 28420), INT16_C( 14334),
                         INT16_C( -3029), INT16_C(-20328), INT16_C(  8988), INT16_C( 23547)),
      simde_mm_set_epi16(INT16_C(  9966), INT16_C(-21867), INT16_C(   738), INT16_C(-29688),
                         INT16_C(  9349), INT16_C(  2360), INT16_C(-12771), INT16_C(-15402)),
      simde_mm_set_epi16(INT16_C( 12033), INT16_C( 14639), INT16_C( 28420), INT16_C( 14334),
                         INT16_C( -3029), INT16_C(-20328), INT16_C(-12771), INT16_C(-15402)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_blend_epi16(test_vec[i].a, test_vec[i].b, 3);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_blend_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  307.09), SIMDE_FLOAT64_C( -991.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -252.92), SIMDE_FLOAT64_C(  -56.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  307.09), SIMDE_FLOAT64_C(  -56.61)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  263.25), SIMDE_FLOAT64_C(  576.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -398.47), SIMDE_FLOAT64_C( -845.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  263.25), SIMDE_FLOAT64_C( -845.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -156.21), SIMDE_FLOAT64_C(  805.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -712.32), SIMDE_FLOAT64_C( -557.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -156.21), SIMDE_FLOAT64_C( -557.85)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  191.78), SIMDE_FLOAT64_C( -309.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -997.82), SIMDE_FLOAT64_C( -493.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  191.78), SIMDE_FLOAT64_C( -493.58)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -933.58), SIMDE_FLOAT64_C( -486.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  880.67), SIMDE_FLOAT64_C(  791.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -933.58), SIMDE_FLOAT64_C(  791.10)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   45.45), SIMDE_FLOAT64_C( -436.38)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  211.82), SIMDE_FLOAT64_C(  653.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   45.45), SIMDE_FLOAT64_C(  653.98)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  915.51), SIMDE_FLOAT64_C( -445.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -69.14), SIMDE_FLOAT64_C( -345.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  915.51), SIMDE_FLOAT64_C( -345.82)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -603.21), SIMDE_FLOAT64_C( -182.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -463.45), SIMDE_FLOAT64_C(  929.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -603.21), SIMDE_FLOAT64_C(  929.21)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_blend_pd(test_vec[i].a, test_vec[i].b, 1);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_blend_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  263.25), SIMDE_FLOAT32_C(  576.67), SIMDE_FLOAT32_C(  307.09), SIMDE_FLOAT32_C( -991.93)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -398.47), SIMDE_FLOAT32_C( -845.00), SIMDE_FLOAT32_C( -252.92), SIMDE_FLOAT32_C(  -56.61)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  263.25), SIMDE_FLOAT32_C(  576.67), SIMDE_FLOAT32_C( -252.92), SIMDE_FLOAT32_C( -991.93)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  191.78), SIMDE_FLOAT32_C( -309.61), SIMDE_FLOAT32_C( -156.21), SIMDE_FLOAT32_C(  805.98)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -997.82), SIMDE_FLOAT32_C( -493.58), SIMDE_FLOAT32_C( -712.32), SIMDE_FLOAT32_C( -557.85)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  191.78), SIMDE_FLOAT32_C( -309.61), SIMDE_FLOAT32_C( -712.32), SIMDE_FLOAT32_C(  805.98)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   45.45), SIMDE_FLOAT32_C( -436.38), SIMDE_FLOAT32_C( -933.58), SIMDE_FLOAT32_C( -486.36)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  211.82), SIMDE_FLOAT32_C(  653.98), SIMDE_FLOAT32_C(  880.67), SIMDE_FLOAT32_C(  791.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   45.45), SIMDE_FLOAT32_C( -436.38), SIMDE_FLOAT32_C(  880.67), SIMDE_FLOAT32_C( -486.36)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -603.21), SIMDE_FLOAT32_C( -182.69), SIMDE_FLOAT32_C(  915.51), SIMDE_FLOAT32_C( -445.43)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -463.45), SIMDE_FLOAT32_C(  929.21), SIMDE_FLOAT32_C(  -69.14), SIMDE_FLOAT32_C( -345.82)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -603.21), SIMDE_FLOAT32_C( -182.69), SIMDE_FLOAT32_C(  -69.14), SIMDE_FLOAT32_C( -445.43)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  898.89), SIMDE_FLOAT32_C(  -75.69), SIMDE_FLOAT32_C(  396.94), SIMDE_FLOAT32_C( -959.19)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -419.62), SIMDE_FLOAT32_C( -299.33), SIMDE_FLOAT32_C( -147.28), SIMDE_FLOAT32_C( -458.75)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  898.89), SIMDE_FLOAT32_C(  -75.69), SIMDE_FLOAT32_C( -147.28), SIMDE_FLOAT32_C( -959.19)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  480.97), SIMDE_FLOAT32_C(  316.97), SIMDE_FLOAT32_C( -700.74), SIMDE_FLOAT32_C(  -81.35)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -930.08), SIMDE_FLOAT32_C(   58.79), SIMDE_FLOAT32_C( -729.84), SIMDE_FLOAT32_C(  572.31)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  480.97), SIMDE_FLOAT32_C(  316.97), SIMDE_FLOAT32_C( -729.84), SIMDE_FLOAT32_C(  -81.35)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -51.53), SIMDE_FLOAT32_C(  742.30), SIMDE_FLOAT32_C(  440.93), SIMDE_FLOAT32_C( -885.24)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  883.38), SIMDE_FLOAT32_C( -314.94), SIMDE_FLOAT32_C( -805.26), SIMDE_FLOAT32_C(  843.17)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -51.53), SIMDE_FLOAT32_C(  742.30), SIMDE_FLOAT32_C( -805.26), SIMDE_FLOAT32_C( -885.24)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  812.23), SIMDE_FLOAT32_C( -335.37), SIMDE_FLOAT32_C(  369.92), SIMDE_FLOAT32_C( -137.19)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  119.89), SIMDE_FLOAT32_C(  901.62), SIMDE_FLOAT32_C( -234.15), SIMDE_FLOAT32_C(  494.86)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  812.23), SIMDE_FLOAT32_C( -335.37), SIMDE_FLOAT32_C( -234.15), SIMDE_FLOAT32_C( -137.19)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_blend_ps(test_vec[i].a, test_vec[i].b, 2);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_blendv_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128i mask;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  290.02), SIMDE_FLOAT64_C( -775.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  567.65), SIMDE_FLOAT64_C(  339.87)),
      simde_x_mm_set_epu64x(UINT64_C(                  0), UINT64_C(                  1)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  290.02), SIMDE_FLOAT64_C( -775.12)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  702.24), SIMDE_FLOAT64_C( -371.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  899.02), SIMDE_FLOAT64_C( -664.73)),
      simde_x_mm_set_epu64x(UINT64_C(                  1), UINT64_C(                  1)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  702.24), SIMDE_FLOAT64_C( -371.99)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  403.27), SIMDE_FLOAT64_C( -740.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  975.40), SIMDE_FLOAT64_C( -480.24)),
      simde_x_mm_set_epu64x(UINT64_C(                  0), UINT64_C(                  0)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  403.27), SIMDE_FLOAT64_C( -740.87)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -417.67), SIMDE_FLOAT64_C(  711.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -897.21), SIMDE_FLOAT64_C( -402.59)),
      simde_x_mm_set_epu64x(UINT64_C(                  1), UINT64_C(                  0)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -417.67), SIMDE_FLOAT64_C(  711.92)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  578.89), SIMDE_FLOAT64_C( -895.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -800.50), SIMDE_FLOAT64_C( -144.28)),
      simde_x_mm_set_epu64x(UINT64_C(                  1), UINT64_C(                  0)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  578.89), SIMDE_FLOAT64_C( -895.99)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  546.78), SIMDE_FLOAT64_C(  883.57)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  415.01), SIMDE_FLOAT64_C(  773.21)),
      simde_x_mm_set_epu64x(UINT64_C(                  1), UINT64_C(                  0)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  546.78), SIMDE_FLOAT64_C(  883.57)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   26.01), SIMDE_FLOAT64_C(  -59.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -530.26), SIMDE_FLOAT64_C(  580.89)),
      simde_x_mm_set_epu64x(UINT64_C(                  0), UINT64_C(                  1)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   26.01), SIMDE_FLOAT64_C(  -59.50)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -344.22), SIMDE_FLOAT64_C(  626.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  752.48), SIMDE_FLOAT64_C(  453.28)),
      simde_x_mm_set_epu64x(UINT64_C(                  0), UINT64_C(                  1)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -344.22), SIMDE_FLOAT64_C(  626.91)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_blendv_pd(test_vec[i].a, test_vec[i].b, *((simde__m128d*) &(test_vec[i].mask)));
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_blendv_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128i mask;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -155.18), SIMDE_FLOAT32_C( -698.08), SIMDE_FLOAT32_C( -535.18), SIMDE_FLOAT32_C( -144.32)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -362.54), SIMDE_FLOAT32_C( -779.39), SIMDE_FLOAT32_C(  825.01), SIMDE_FLOAT32_C( -777.93)),
      simde_x_mm_set_epu32(UINT32_C(         1), UINT32_C(         0), UINT32_C(         1), UINT32_C(         0)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -155.18), SIMDE_FLOAT32_C( -698.08), SIMDE_FLOAT32_C( -535.18), SIMDE_FLOAT32_C( -144.32)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -284.42), SIMDE_FLOAT32_C(  692.24), SIMDE_FLOAT32_C(  101.85), SIMDE_FLOAT32_C( -819.28)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  327.10), SIMDE_FLOAT32_C(  184.40), SIMDE_FLOAT32_C(  440.54), SIMDE_FLOAT32_C(  732.07)),
      simde_x_mm_set_epu32(UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         1)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -284.42), SIMDE_FLOAT32_C(  692.24), SIMDE_FLOAT32_C(  101.85), SIMDE_FLOAT32_C( -819.28)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  264.15), SIMDE_FLOAT32_C( -480.80), SIMDE_FLOAT32_C( -304.32), SIMDE_FLOAT32_C(  862.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  230.55), SIMDE_FLOAT32_C( -649.28), SIMDE_FLOAT32_C(  827.43), SIMDE_FLOAT32_C( -462.60)),
      simde_x_mm_set_epu32(UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  264.15), SIMDE_FLOAT32_C( -480.80), SIMDE_FLOAT32_C( -304.32), SIMDE_FLOAT32_C(  862.50)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  235.66), SIMDE_FLOAT32_C(  478.16), SIMDE_FLOAT32_C(  480.58), SIMDE_FLOAT32_C(  -53.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  982.67), SIMDE_FLOAT32_C( -772.62), SIMDE_FLOAT32_C( -150.10), SIMDE_FLOAT32_C( -737.86)),
      simde_x_mm_set_epu32(UINT32_C(         1), UINT32_C(         1), UINT32_C(         0), UINT32_C(         0)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  235.66), SIMDE_FLOAT32_C(  478.16), SIMDE_FLOAT32_C(  480.58), SIMDE_FLOAT32_C(  -53.52)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  121.52), SIMDE_FLOAT32_C(  798.57), SIMDE_FLOAT32_C(  563.90), SIMDE_FLOAT32_C(  845.42)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  593.41), SIMDE_FLOAT32_C(  201.43), SIMDE_FLOAT32_C( -263.22), SIMDE_FLOAT32_C(   41.51)),
      simde_x_mm_set_epu32(UINT32_C(         1), UINT32_C(         1), UINT32_C(         1), UINT32_C(         0)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  121.52), SIMDE_FLOAT32_C(  798.57), SIMDE_FLOAT32_C(  563.90), SIMDE_FLOAT32_C(  845.42)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -938.86), SIMDE_FLOAT32_C( -190.10), SIMDE_FLOAT32_C( -729.05), SIMDE_FLOAT32_C(  956.23)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  574.98), SIMDE_FLOAT32_C(  -82.92), SIMDE_FLOAT32_C(  247.07), SIMDE_FLOAT32_C( -802.43)),
      simde_x_mm_set_epu32(UINT32_C(         0), UINT32_C(         1), UINT32_C(         0), UINT32_C(         0)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -938.86), SIMDE_FLOAT32_C( -190.10), SIMDE_FLOAT32_C( -729.05), SIMDE_FLOAT32_C(  956.23)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -592.31), SIMDE_FLOAT32_C( -123.91), SIMDE_FLOAT32_C(  105.67), SIMDE_FLOAT32_C(  596.25)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -99.40), SIMDE_FLOAT32_C(   86.32), SIMDE_FLOAT32_C( -827.82), SIMDE_FLOAT32_C(  443.02)),
      simde_x_mm_set_epu32(UINT32_C(         1), UINT32_C(         1), UINT32_C(         1), UINT32_C(         0)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -592.31), SIMDE_FLOAT32_C( -123.91), SIMDE_FLOAT32_C(  105.67), SIMDE_FLOAT32_C(  596.25)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   59.00), SIMDE_FLOAT32_C(  -93.37), SIMDE_FLOAT32_C( -934.05), SIMDE_FLOAT32_C(  930.21)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -592.32), SIMDE_FLOAT32_C(  420.31), SIMDE_FLOAT32_C( -235.36), SIMDE_FLOAT32_C( -335.98)),
      simde_x_mm_set_epu32(UINT32_C(         1), UINT32_C(         1), UINT32_C(         1), UINT32_C(         1)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   59.00), SIMDE_FLOAT32_C(  -93.37), SIMDE_FLOAT32_C( -934.05), SIMDE_FLOAT32_C(  930.21)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_blendv_ps(test_vec[i].a, test_vec[i].b, *((simde__m128*) &(test_vec[i].mask)));
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_ceil_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  241.39), SIMDE_FLOAT64_C(  553.26)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  242.00), SIMDE_FLOAT64_C(  554.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  307.83), SIMDE_FLOAT64_C(  377.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  308.00), SIMDE_FLOAT64_C(  378.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  558.16), SIMDE_FLOAT64_C( -404.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  559.00), SIMDE_FLOAT64_C( -404.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  219.15), SIMDE_FLOAT64_C(  818.17)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  220.00), SIMDE_FLOAT64_C(  819.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   25.83), SIMDE_FLOAT64_C( -230.94)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   26.00), SIMDE_FLOAT64_C( -230.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  173.52), SIMDE_FLOAT64_C(   64.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  174.00), SIMDE_FLOAT64_C(   65.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -453.11), SIMDE_FLOAT64_C( -845.77)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -453.00), SIMDE_FLOAT64_C( -845.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -50.98), SIMDE_FLOAT64_C( -179.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -50.00), SIMDE_FLOAT64_C( -179.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_ceil_pd(test_vec[i].a);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_ceil_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -624.94), SIMDE_FLOAT32_C( -243.25), SIMDE_FLOAT32_C(  -61.63), SIMDE_FLOAT32_C( -948.73)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -624.00), SIMDE_FLOAT32_C( -243.00), SIMDE_FLOAT32_C(  -61.00), SIMDE_FLOAT32_C( -948.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -906.63), SIMDE_FLOAT32_C( -236.42), SIMDE_FLOAT32_C(  571.51), SIMDE_FLOAT32_C(  624.62)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -906.00), SIMDE_FLOAT32_C( -236.00), SIMDE_FLOAT32_C(  572.00), SIMDE_FLOAT32_C(  625.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  503.85), SIMDE_FLOAT32_C( -317.51), SIMDE_FLOAT32_C( -529.30), SIMDE_FLOAT32_C( -871.89)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  504.00), SIMDE_FLOAT32_C( -317.00), SIMDE_FLOAT32_C( -529.00), SIMDE_FLOAT32_C( -871.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  571.49), SIMDE_FLOAT32_C( -129.77), SIMDE_FLOAT32_C( -739.71), SIMDE_FLOAT32_C(  413.18)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  572.00), SIMDE_FLOAT32_C( -129.00), SIMDE_FLOAT32_C( -739.00), SIMDE_FLOAT32_C(  414.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  438.35), SIMDE_FLOAT32_C(  517.03), SIMDE_FLOAT32_C(  278.46), SIMDE_FLOAT32_C( -656.36)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  439.00), SIMDE_FLOAT32_C(  518.00), SIMDE_FLOAT32_C(  279.00), SIMDE_FLOAT32_C( -656.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -159.40), SIMDE_FLOAT32_C( -802.82), SIMDE_FLOAT32_C(  663.71), SIMDE_FLOAT32_C(  186.86)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -159.00), SIMDE_FLOAT32_C( -802.00), SIMDE_FLOAT32_C(  664.00), SIMDE_FLOAT32_C(  187.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -163.74), SIMDE_FLOAT32_C(  485.54), SIMDE_FLOAT32_C(  138.17), SIMDE_FLOAT32_C(  794.67)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -163.00), SIMDE_FLOAT32_C(  486.00), SIMDE_FLOAT32_C(  139.00), SIMDE_FLOAT32_C(  795.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -469.36), SIMDE_FLOAT32_C( -418.24), SIMDE_FLOAT32_C( -419.25), SIMDE_FLOAT32_C(  390.46)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -469.00), SIMDE_FLOAT32_C( -418.00), SIMDE_FLOAT32_C( -419.00), SIMDE_FLOAT32_C(  391.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_ceil_ps(test_vec[i].a);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_ceil_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -610.18), SIMDE_FLOAT64_C(  172.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  234.40), SIMDE_FLOAT64_C( -339.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -610.18), SIMDE_FLOAT64_C( -339.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -467.52), SIMDE_FLOAT64_C(  904.78)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -527.39), SIMDE_FLOAT64_C( -115.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -467.52), SIMDE_FLOAT64_C( -115.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  191.24), SIMDE_FLOAT64_C(  823.78)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  835.27), SIMDE_FLOAT64_C(  744.81)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  191.24), SIMDE_FLOAT64_C(  745.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -49.25), SIMDE_FLOAT64_C( -695.95)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  800.62), SIMDE_FLOAT64_C(  853.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -49.25), SIMDE_FLOAT64_C(  854.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  668.83), SIMDE_FLOAT64_C( -182.73)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -875.46), SIMDE_FLOAT64_C(  752.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  668.83), SIMDE_FLOAT64_C(  753.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  242.57), SIMDE_FLOAT64_C( -906.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -816.22), SIMDE_FLOAT64_C(  339.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  242.57), SIMDE_FLOAT64_C(  340.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -745.15), SIMDE_FLOAT64_C( -744.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -802.81), SIMDE_FLOAT64_C(  890.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -745.15), SIMDE_FLOAT64_C(  891.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  238.48), SIMDE_FLOAT64_C( -167.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -484.51), SIMDE_FLOAT64_C(  175.95)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  238.48), SIMDE_FLOAT64_C(  176.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_ceil_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_ceil_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -124.45), SIMDE_FLOAT32_C(  911.12), SIMDE_FLOAT32_C(  900.52), SIMDE_FLOAT32_C( -468.92)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -31.56), SIMDE_FLOAT32_C(  -29.76), SIMDE_FLOAT32_C( -939.35), SIMDE_FLOAT32_C(  459.71)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -124.45), SIMDE_FLOAT32_C(  911.12), SIMDE_FLOAT32_C(  900.52), SIMDE_FLOAT32_C(  460.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  514.22), SIMDE_FLOAT32_C( -972.44), SIMDE_FLOAT32_C( -908.76), SIMDE_FLOAT32_C( -817.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -711.78), SIMDE_FLOAT32_C(  489.62), SIMDE_FLOAT32_C( -109.52), SIMDE_FLOAT32_C(   -2.01)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  514.22), SIMDE_FLOAT32_C( -972.44), SIMDE_FLOAT32_C( -908.76), SIMDE_FLOAT32_C(   -2.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -269.88), SIMDE_FLOAT32_C( -875.85), SIMDE_FLOAT32_C( -139.27), SIMDE_FLOAT32_C( -841.56)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  501.05), SIMDE_FLOAT32_C(  280.43), SIMDE_FLOAT32_C( -173.91), SIMDE_FLOAT32_C(  644.42)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -269.88), SIMDE_FLOAT32_C( -875.85), SIMDE_FLOAT32_C( -139.27), SIMDE_FLOAT32_C(  645.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -643.26), SIMDE_FLOAT32_C(  616.48), SIMDE_FLOAT32_C(  835.28), SIMDE_FLOAT32_C(  527.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  636.48), SIMDE_FLOAT32_C(  -46.56), SIMDE_FLOAT32_C( -891.84), SIMDE_FLOAT32_C(  948.43)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -643.26), SIMDE_FLOAT32_C(  616.48), SIMDE_FLOAT32_C(  835.28), SIMDE_FLOAT32_C(  949.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    3.13), SIMDE_FLOAT32_C( -654.36), SIMDE_FLOAT32_C( -994.98), SIMDE_FLOAT32_C( -148.95)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  806.15), SIMDE_FLOAT32_C(  529.29), SIMDE_FLOAT32_C( -804.42), SIMDE_FLOAT32_C(  408.19)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    3.13), SIMDE_FLOAT32_C( -654.36), SIMDE_FLOAT32_C( -994.98), SIMDE_FLOAT32_C(  409.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -138.18), SIMDE_FLOAT32_C( -446.48), SIMDE_FLOAT32_C( -413.95), SIMDE_FLOAT32_C( -252.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  957.68), SIMDE_FLOAT32_C(  373.35), SIMDE_FLOAT32_C(  271.98), SIMDE_FLOAT32_C( -653.93)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -138.18), SIMDE_FLOAT32_C( -446.48), SIMDE_FLOAT32_C( -413.95), SIMDE_FLOAT32_C( -653.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  124.40), SIMDE_FLOAT32_C( -866.66), SIMDE_FLOAT32_C(  288.57), SIMDE_FLOAT32_C( -708.46)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  685.14), SIMDE_FLOAT32_C(  776.00), SIMDE_FLOAT32_C(  453.56), SIMDE_FLOAT32_C( -112.81)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  124.40), SIMDE_FLOAT32_C( -866.66), SIMDE_FLOAT32_C(  288.57), SIMDE_FLOAT32_C( -112.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -232.75), SIMDE_FLOAT32_C( -137.55), SIMDE_FLOAT32_C(   50.26), SIMDE_FLOAT32_C( -189.71)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -288.67), SIMDE_FLOAT32_C( -112.95), SIMDE_FLOAT32_C(  792.47), SIMDE_FLOAT32_C( -200.27)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -232.75), SIMDE_FLOAT32_C( -137.55), SIMDE_FLOAT32_C(   50.26), SIMDE_FLOAT32_C( -200.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_ceil_ss(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpeq_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu64x(UINT64_C(13269709557652540150), UINT64_C( 5229646237911669536)),
      simde_x_mm_set_epu64x(UINT64_C(13269709557652540150), UINT64_C( 5229646237911669536)),
      simde_x_mm_set_epu64x(UINT64_C(18446744073709551615), UINT64_C(18446744073709551615)) },
    { simde_x_mm_set_epu64x(UINT64_C(14039735832537203737), UINT64_C(18065414586371585158)),
      simde_x_mm_set_epu64x(UINT64_C( 7896134184979754273), UINT64_C(18065414586371585158)),
      simde_x_mm_set_epu64x(UINT64_C(                   0), UINT64_C(18446744073709551615)) },
    { simde_x_mm_set_epu64x(UINT64_C( 8088434365645432882), UINT64_C( 2110149590601129498)),
      simde_x_mm_set_epu64x(UINT64_C(12894308138858138936), UINT64_C( 7645444803376971084)),
      simde_x_mm_set_epu64x(UINT64_C(                   0), UINT64_C(                   0)) },
    { simde_x_mm_set_epu64x(UINT64_C( 6900998750312547586), UINT64_C(11115665826166806875)),
      simde_x_mm_set_epu64x(UINT64_C(  253910074237567150), UINT64_C(11115665826166806875)),
      simde_x_mm_set_epu64x(UINT64_C(                   0), UINT64_C(18446744073709551615)) },
    { simde_x_mm_set_epu64x(UINT64_C(15513947591537518317), UINT64_C( 6346622963553980783)),
      simde_x_mm_set_epu64x(UINT64_C( 1894817647097843127), UINT64_C( 9019647896255166506)),
      simde_x_mm_set_epu64x(UINT64_C(                   0), UINT64_C(                   0)) },
    { simde_x_mm_set_epu64x(UINT64_C(  189073800069710221), UINT64_C( 5830713182261233236)),
      simde_x_mm_set_epu64x(UINT64_C(  189073800069710221), UINT64_C( 8422068610497871432)),
      simde_x_mm_set_epu64x(UINT64_C(18446744073709551615), UINT64_C(                   0)) },
    { simde_x_mm_set_epu64x(UINT64_C(17115829668729212386), UINT64_C(11158226665026575121)),
      simde_x_mm_set_epu64x(UINT64_C(17115829668729212386), UINT64_C(11158226665026575121)),
      simde_x_mm_set_epu64x(UINT64_C(18446744073709551615), UINT64_C(18446744073709551615)) },
    { simde_x_mm_set_epu64x(UINT64_C( 9543887299291080046), UINT64_C(14913997234931691871)),
      simde_x_mm_set_epu64x(UINT64_C( 9543887299291080046), UINT64_C(12485648986158046833)),
      simde_x_mm_set_epu64x(UINT64_C(18446744073709551615), UINT64_C(                   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cmpeq_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtepi16_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(-15854,      0, -12807,   5951,  29318, -11078,  -2252,  10096),
      simde_mm_set_epi32( 29318, -11078,  -2252,  10096) },
    { simde_mm_set_epi16( 24388,  32521, -30980, -12289,  27092,  24521,  12106, -27709),
      simde_mm_set_epi32( 27092,  24521,  12106, -27709) },
    { simde_mm_set_epi16(-11871,  15750,  -7986,   4594,  22346,   1400, -21386,   7662),
      simde_mm_set_epi32( 22346,   1400, -21386,   7662) },
    { simde_mm_set_epi16(-15687, -15477, -26077, -28781, -29737, -30311,  16950,  14614),
      simde_mm_set_epi32(-29737, -30311,  16950,  14614) },
    { simde_mm_set_epi16(-30646,  13049, -24166,    637,   7297,   -627,   6143, -26200),
      simde_mm_set_epi32(  7297,   -627,   6143, -26200) },
    { simde_mm_set_epi16( 30171,   1922,   -122, -17991,  30806,  12552, -28515,  -9185),
      simde_mm_set_epi32( 30806,  12552, -28515,  -9185) },
    { simde_mm_set_epi16( 29385,  21267, -10152,  25553,  20674,   6661, -29222, -19848),
      simde_mm_set_epi32( 20674,   6661, -29222, -19848) },
    { simde_mm_set_epi16( 24527,  18305,  30094,  -5437, -26652,  20361,  10408,  -4948),
      simde_mm_set_epi32(-26652,  20361,  10408,  -4948) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepi16_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtepi16_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi16(INT16_C(-25288), INT16_C(   737), INT16_C(-31366), INT16_C(-21360),
                         INT16_C(  1927), INT16_C( 32195), INT16_C( -4472), INT16_C( -2085)),
      simde_mm_set_epi64x(INT64_C(               -4472), INT64_C(               -2085)) },
    { simde_mm_set_epi16(INT16_C(-30817), INT16_C(  5734), INT16_C( -6209), INT16_C(-18846),
                         INT16_C( 14970), INT16_C( 30345), INT16_C( -8853), INT16_C(-31121)),
      simde_mm_set_epi64x(INT64_C(               -8853), INT64_C(              -31121)) },
    { simde_mm_set_epi16(INT16_C(  -970), INT16_C(-11861), INT16_C(-11667), INT16_C( 14936),
                         INT16_C( 21732), INT16_C(-17006), INT16_C( -2668), INT16_C( 30170)),
      simde_mm_set_epi64x(INT64_C(               -2668), INT64_C(               30170)) },
    { simde_mm_set_epi16(INT16_C(  2721), INT16_C(-13375), INT16_C( -1976), INT16_C( 30833),
                         INT16_C(-18247), INT16_C( 16242), INT16_C(  4569), INT16_C( 10132)),
      simde_mm_set_epi64x(INT64_C(                4569), INT64_C(               10132)) },
    { simde_mm_set_epi16(INT16_C(-22879), INT16_C(-24842), INT16_C(-29886), INT16_C(-13312),
                         INT16_C( 24862), INT16_C(-30679), INT16_C(  6258), INT16_C(-19461)),
      simde_mm_set_epi64x(INT64_C(                6258), INT64_C(              -19461)) },
    { simde_mm_set_epi16(INT16_C( 15048), INT16_C(  5334), INT16_C( 21517), INT16_C( 10106),
                         INT16_C(-25890), INT16_C( -8759), INT16_C( 21361), INT16_C( 17584)),
      simde_mm_set_epi64x(INT64_C(               21361), INT64_C(               17584)) },
    { simde_mm_set_epi16(INT16_C( 18353), INT16_C(  9848), INT16_C( 20583), INT16_C(-28706),
                         INT16_C( 28353), INT16_C(   979), INT16_C(-15312), INT16_C( -4296)),
      simde_mm_set_epi64x(INT64_C(              -15312), INT64_C(               -4296)) },
    { simde_mm_set_epi16(INT16_C( 21066), INT16_C( 26185), INT16_C( 29520), INT16_C( -9848),
                         INT16_C(-20587), INT16_C(  -254), INT16_C(-19969), INT16_C( -2307)),
      simde_mm_set_epi64x(INT64_C(              -19969), INT64_C(               -2307)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepi16_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtepi32_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1750586859), INT32_C( 1743108010), INT32_C(  -56370522), INT32_C(  214732685)),
      simde_mm_set_epi64x(INT64_C(           -56370522), INT64_C(           214732685)) },
    { simde_mm_set_epi32(INT32_C( 1019578476), INT32_C( 2006962808), INT32_C( 1356966666), INT32_C(  443191452)),
      simde_mm_set_epi64x(INT64_C(          1356966666), INT64_C(           443191452)) },
    { simde_mm_set_epi32(INT32_C(  811952499), INT32_C( 1388789927), INT32_C( 1562076587), INT32_C( 1374574189)),
      simde_mm_set_epi64x(INT64_C(          1562076587), INT64_C(          1374574189)) },
    { simde_mm_set_epi32(INT32_C(-1130424581), INT32_C( -754503048), INT32_C( -175987570), INT32_C(  252857640)),
      simde_mm_set_epi64x(INT64_C(          -175987570), INT64_C(           252857640)) },
    { simde_mm_set_epi32(INT32_C( -662885345), INT32_C( -469769762), INT32_C( 1876427062), INT32_C(-1227144336)),
      simde_mm_set_epi64x(INT64_C(          1876427062), INT64_C(         -1227144336)) },
    { simde_mm_set_epi32(INT32_C(-1459145913), INT32_C( -624950308), INT32_C(-1740403350), INT32_C(-2023012954)),
      simde_mm_set_epi64x(INT64_C(         -1740403350), INT64_C(         -2023012954)) },
    { simde_mm_set_epi32(INT32_C(  807996884), INT32_C( -721517626), INT32_C(-1345085365), INT32_C(    3500292)),
      simde_mm_set_epi64x(INT64_C(         -1345085365), INT64_C(             3500292)) },
    { simde_mm_set_epi32(INT32_C( 1631614297), INT32_C(-2082769218), INT32_C(  285385405), INT32_C(-1874296921)),
      simde_mm_set_epi64x(INT64_C(           285385405), INT64_C(         -1874296921)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepi32_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtepi8_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -34), INT8_C(  20), INT8_C(  53), INT8_C(  81),
                        INT8_C(  37), INT8_C( -97), INT8_C( -59), INT8_C( 127),
                        INT8_C( -43), INT8_C( -82), INT8_C(  84), INT8_C(-127),
                        INT8_C(  11), INT8_C( 120), INT8_C( -98), INT8_C( -80)),
      simde_mm_set_epi16(INT16_C(   -43), INT16_C(   -82), INT16_C(    84), INT16_C(  -127),
                         INT16_C(    11), INT16_C(   120), INT16_C(   -98), INT16_C(   -80)) },
    { simde_mm_set_epi8(INT8_C(  66), INT8_C(  57), INT8_C(  40), INT8_C(-113),
                        INT8_C(  71), INT8_C(  -5), INT8_C(  70), INT8_C(  22),
                        INT8_C( -70), INT8_C(  14), INT8_C( -76), INT8_C(-101),
                        INT8_C(  13), INT8_C(  64), INT8_C( -86), INT8_C(  34)),
      simde_mm_set_epi16(INT16_C(   -70), INT16_C(    14), INT16_C(   -76), INT16_C(  -101),
                         INT16_C(    13), INT16_C(    64), INT16_C(   -86), INT16_C(    34)) },
    { simde_mm_set_epi8(INT8_C(  87), INT8_C( 115), INT8_C( 108), INT8_C( -88),
                        INT8_C( 113), INT8_C(  91), INT8_C( -95), INT8_C( -69),
                        INT8_C(  32), INT8_C(  98), INT8_C( -16), INT8_C( -55),
                        INT8_C(  11), INT8_C( -23), INT8_C(  72), INT8_C( 121)),
      simde_mm_set_epi16(INT16_C(    32), INT16_C(    98), INT16_C(   -16), INT16_C(   -55),
                         INT16_C(    11), INT16_C(   -23), INT16_C(    72), INT16_C(   121)) },
    { simde_mm_set_epi8(INT8_C(  88), INT8_C(  68), INT8_C( -76), INT8_C(  35),
                        INT8_C(-119), INT8_C( -67), INT8_C(  52), INT8_C(  58),
                        INT8_C(   7), INT8_C(  70), INT8_C( -26), INT8_C(  55),
                        INT8_C( 126), INT8_C(  69), INT8_C( 105), INT8_C(  40)),
      simde_mm_set_epi16(INT16_C(     7), INT16_C(    70), INT16_C(   -26), INT16_C(    55),
                         INT16_C(   126), INT16_C(    69), INT16_C(   105), INT16_C(    40)) },
    { simde_mm_set_epi8(INT8_C( 110), INT8_C(  -4), INT8_C(  41), INT8_C( -98),
                        INT8_C( -91), INT8_C( 117), INT8_C( -33), INT8_C(-110),
                        INT8_C( 126), INT8_C( -63), INT8_C( -65), INT8_C( -86),
                        INT8_C(-108), INT8_C( -64), INT8_C(  -4), INT8_C(  25)),
      simde_mm_set_epi16(INT16_C(   126), INT16_C(   -63), INT16_C(   -65), INT16_C(   -86),
                         INT16_C(  -108), INT16_C(   -64), INT16_C(    -4), INT16_C(    25)) },
    { simde_mm_set_epi8(INT8_C( 105), INT8_C( -31), INT8_C( -57), INT8_C( -74),
                        INT8_C( 119), INT8_C(  56), INT8_C( -36), INT8_C(-128),
                        INT8_C( 102), INT8_C(  57), INT8_C( -27), INT8_C(  19),
                        INT8_C( -50), INT8_C( -15), INT8_C(  36), INT8_C(-124)),
      simde_mm_set_epi16(INT16_C(   102), INT16_C(    57), INT16_C(   -27), INT16_C(    19),
                         INT16_C(   -50), INT16_C(   -15), INT16_C(    36), INT16_C(  -124)) },
    { simde_mm_set_epi8(INT8_C(  44), INT8_C( -84), INT8_C( -61), INT8_C(  59),
                        INT8_C(  18), INT8_C(-118), INT8_C(   6), INT8_C(  56),
                        INT8_C( -11), INT8_C(  78), INT8_C( -64), INT8_C( -28),
                        INT8_C( -85), INT8_C( -77), INT8_C( -25), INT8_C(-100)),
      simde_mm_set_epi16(INT16_C(   -11), INT16_C(    78), INT16_C(   -64), INT16_C(   -28),
                         INT16_C(   -85), INT16_C(   -77), INT16_C(   -25), INT16_C(  -100)) },
    { simde_mm_set_epi8(INT8_C( -13), INT8_C( -24), INT8_C(  94), INT8_C(  58),
                        INT8_C(   1), INT8_C( -14), INT8_C( -90), INT8_C(-123),
                        INT8_C(-101), INT8_C(  71), INT8_C( -51), INT8_C(  87),
                        INT8_C( -34), INT8_C(  77), INT8_C( 124), INT8_C( -63)),
      simde_mm_set_epi16(INT16_C(  -101), INT16_C(    71), INT16_C(   -51), INT16_C(    87),
                         INT16_C(   -34), INT16_C(    77), INT16_C(   124), INT16_C(   -63)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepi8_epi16(test_vec[i].a);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtepi8_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -34), INT8_C(  20), INT8_C(  53), INT8_C(  81),
                        INT8_C(  37), INT8_C( -97), INT8_C( -59), INT8_C( 127),
                        INT8_C( -43), INT8_C( -82), INT8_C(  84), INT8_C(-127),
                        INT8_C(  11), INT8_C( 120), INT8_C( -98), INT8_C( -80)),
      simde_mm_set_epi32(INT32_C(         11), INT32_C(        120), INT32_C(        -98), INT32_C(        -80)) },
    { simde_mm_set_epi8(INT8_C(  66), INT8_C(  57), INT8_C(  40), INT8_C(-113),
                        INT8_C(  71), INT8_C(  -5), INT8_C(  70), INT8_C(  22),
                        INT8_C( -70), INT8_C(  14), INT8_C( -76), INT8_C(-101),
                        INT8_C(  13), INT8_C(  64), INT8_C( -86), INT8_C(  34)),
      simde_mm_set_epi32(INT32_C(         13), INT32_C(         64), INT32_C(        -86), INT32_C(         34)) },
    { simde_mm_set_epi8(INT8_C(  87), INT8_C( 115), INT8_C( 108), INT8_C( -88),
                        INT8_C( 113), INT8_C(  91), INT8_C( -95), INT8_C( -69),
                        INT8_C(  32), INT8_C(  98), INT8_C( -16), INT8_C( -55),
                        INT8_C(  11), INT8_C( -23), INT8_C(  72), INT8_C( 121)),
      simde_mm_set_epi32(INT32_C(         11), INT32_C(        -23), INT32_C(         72), INT32_C(        121)) },
    { simde_mm_set_epi8(INT8_C(  88), INT8_C(  68), INT8_C( -76), INT8_C(  35),
                        INT8_C(-119), INT8_C( -67), INT8_C(  52), INT8_C(  58),
                        INT8_C(   7), INT8_C(  70), INT8_C( -26), INT8_C(  55),
                        INT8_C( 126), INT8_C(  69), INT8_C( 105), INT8_C(  40)),
      simde_mm_set_epi32(INT32_C(        126), INT32_C(         69), INT32_C(        105), INT32_C(         40)) },
    { simde_mm_set_epi8(INT8_C( 110), INT8_C(  -4), INT8_C(  41), INT8_C( -98),
                        INT8_C( -91), INT8_C( 117), INT8_C( -33), INT8_C(-110),
                        INT8_C( 126), INT8_C( -63), INT8_C( -65), INT8_C( -86),
                        INT8_C(-108), INT8_C( -64), INT8_C(  -4), INT8_C(  25)),
      simde_mm_set_epi32(INT32_C(       -108), INT32_C(        -64), INT32_C(         -4), INT32_C(         25)) },
    { simde_mm_set_epi8(INT8_C( 105), INT8_C( -31), INT8_C( -57), INT8_C( -74),
                        INT8_C( 119), INT8_C(  56), INT8_C( -36), INT8_C(-128),
                        INT8_C( 102), INT8_C(  57), INT8_C( -27), INT8_C(  19),
                        INT8_C( -50), INT8_C( -15), INT8_C(  36), INT8_C(-124)),
      simde_mm_set_epi32(INT32_C(        -50), INT32_C(        -15), INT32_C(         36), INT32_C(       -124)) },
    { simde_mm_set_epi8(INT8_C(  44), INT8_C( -84), INT8_C( -61), INT8_C(  59),
                        INT8_C(  18), INT8_C(-118), INT8_C(   6), INT8_C(  56),
                        INT8_C( -11), INT8_C(  78), INT8_C( -64), INT8_C( -28),
                        INT8_C( -85), INT8_C( -77), INT8_C( -25), INT8_C(-100)),
      simde_mm_set_epi32(INT32_C(        -85), INT32_C(        -77), INT32_C(        -25), INT32_C(       -100)) },
    { simde_mm_set_epi8(INT8_C( -13), INT8_C( -24), INT8_C(  94), INT8_C(  58),
                        INT8_C(   1), INT8_C( -14), INT8_C( -90), INT8_C(-123),
                        INT8_C(-101), INT8_C(  71), INT8_C( -51), INT8_C(  87),
                        INT8_C( -34), INT8_C(  77), INT8_C( 124), INT8_C( -63)),
      simde_mm_set_epi32(INT32_C(        -34), INT32_C(         77), INT32_C(        124), INT32_C(        -63)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepi8_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtepi8_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C( -34), INT8_C(  20), INT8_C(  53), INT8_C(  81),
                        INT8_C(  37), INT8_C( -97), INT8_C( -59), INT8_C( 127),
                        INT8_C( -43), INT8_C( -82), INT8_C(  84), INT8_C(-127),
                        INT8_C(  11), INT8_C( 120), INT8_C( -98), INT8_C( -80)),
      simde_mm_set_epi64x(INT64_C(                 -98), INT64_C(                 -80)) },
    { simde_mm_set_epi8(INT8_C(  66), INT8_C(  57), INT8_C(  40), INT8_C(-113),
                        INT8_C(  71), INT8_C(  -5), INT8_C(  70), INT8_C(  22),
                        INT8_C( -70), INT8_C(  14), INT8_C( -76), INT8_C(-101),
                        INT8_C(  13), INT8_C(  64), INT8_C( -86), INT8_C(  34)),
      simde_mm_set_epi64x(INT64_C(                 -86), INT64_C(                  34)) },
    { simde_mm_set_epi8(INT8_C(  87), INT8_C( 115), INT8_C( 108), INT8_C( -88),
                        INT8_C( 113), INT8_C(  91), INT8_C( -95), INT8_C( -69),
                        INT8_C(  32), INT8_C(  98), INT8_C( -16), INT8_C( -55),
                        INT8_C(  11), INT8_C( -23), INT8_C(  72), INT8_C( 121)),
      simde_mm_set_epi64x(INT64_C(                  72), INT64_C(                 121)) },
    { simde_mm_set_epi8(INT8_C(  88), INT8_C(  68), INT8_C( -76), INT8_C(  35),
                        INT8_C(-119), INT8_C( -67), INT8_C(  52), INT8_C(  58),
                        INT8_C(   7), INT8_C(  70), INT8_C( -26), INT8_C(  55),
                        INT8_C( 126), INT8_C(  69), INT8_C( 105), INT8_C(  40)),
      simde_mm_set_epi64x(INT64_C(                 105), INT64_C(                  40)) },
    { simde_mm_set_epi8(INT8_C( 110), INT8_C(  -4), INT8_C(  41), INT8_C( -98),
                        INT8_C( -91), INT8_C( 117), INT8_C( -33), INT8_C(-110),
                        INT8_C( 126), INT8_C( -63), INT8_C( -65), INT8_C( -86),
                        INT8_C(-108), INT8_C( -64), INT8_C(  -4), INT8_C(  25)),
      simde_mm_set_epi64x(INT64_C(                  -4), INT64_C(                  25)) },
    { simde_mm_set_epi8(INT8_C( 105), INT8_C( -31), INT8_C( -57), INT8_C( -74),
                        INT8_C( 119), INT8_C(  56), INT8_C( -36), INT8_C(-128),
                        INT8_C( 102), INT8_C(  57), INT8_C( -27), INT8_C(  19),
                        INT8_C( -50), INT8_C( -15), INT8_C(  36), INT8_C(-124)),
      simde_mm_set_epi64x(INT64_C(                  36), INT64_C(                -124)) },
    { simde_mm_set_epi8(INT8_C(  44), INT8_C( -84), INT8_C( -61), INT8_C(  59),
                        INT8_C(  18), INT8_C(-118), INT8_C(   6), INT8_C(  56),
                        INT8_C( -11), INT8_C(  78), INT8_C( -64), INT8_C( -28),
                        INT8_C( -85), INT8_C( -77), INT8_C( -25), INT8_C(-100)),
      simde_mm_set_epi64x(INT64_C(                 -25), INT64_C(                -100)) },
    { simde_mm_set_epi8(INT8_C( -13), INT8_C( -24), INT8_C(  94), INT8_C(  58),
                        INT8_C(   1), INT8_C( -14), INT8_C( -90), INT8_C(-123),
                        INT8_C(-101), INT8_C(  71), INT8_C( -51), INT8_C(  87),
                        INT8_C( -34), INT8_C(  77), INT8_C( 124), INT8_C( -63)),
      simde_mm_set_epi64x(INT64_C(                 124), INT64_C(                 -63)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepi8_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtepu8_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(UINT8_C(133), UINT8_C( 55), UINT8_C(102), UINT8_C(130),
                          UINT8_C(197), UINT8_C( 52), UINT8_C(225), UINT8_C( 87),
                          UINT8_C(218), UINT8_C( 15), UINT8_C(214), UINT8_C(152),
                          UINT8_C(108), UINT8_C( 18), UINT8_C(104), UINT8_C(  3)),
      simde_mm_set_epi16(INT16_C(   218), INT16_C(    15), INT16_C(   214), INT16_C(   152),
                         INT16_C(   108), INT16_C(    18), INT16_C(   104), INT16_C(     3)) },
    { simde_x_mm_set_epu8(UINT8_C( 51), UINT8_C(122), UINT8_C(167), UINT8_C(232),
                          UINT8_C(  3), UINT8_C(167), UINT8_C( 89), UINT8_C(206),
                          UINT8_C( 96), UINT8_C(235), UINT8_C(128), UINT8_C(134),
                          UINT8_C(187), UINT8_C(190), UINT8_C(232), UINT8_C(112)),
      simde_mm_set_epi16(INT16_C(    96), INT16_C(   235), INT16_C(   128), INT16_C(   134),
                         INT16_C(   187), INT16_C(   190), INT16_C(   232), INT16_C(   112)) },
    { simde_x_mm_set_epu8(UINT8_C( 15), UINT8_C( 99), UINT8_C(228), UINT8_C( 12),
                          UINT8_C(155), UINT8_C(138), UINT8_C( 87), UINT8_C( 96),
                          UINT8_C( 98), UINT8_C( 66), UINT8_C( 96), UINT8_C( 53),
                          UINT8_C( 65), UINT8_C(187), UINT8_C(183), UINT8_C(114)),
      simde_mm_set_epi16(INT16_C(    98), INT16_C(    66), INT16_C(    96), INT16_C(    53),
                         INT16_C(    65), INT16_C(   187), INT16_C(   183), INT16_C(   114)) },
    { simde_x_mm_set_epu8(UINT8_C( 58), UINT8_C( 51), UINT8_C(210), UINT8_C( 42),
                          UINT8_C(132), UINT8_C(100), UINT8_C( 83), UINT8_C( 44),
                          UINT8_C(115), UINT8_C(204), UINT8_C(195), UINT8_C( 11),
                          UINT8_C( 48), UINT8_C( 39), UINT8_C( 37), UINT8_C(183)),
      simde_mm_set_epi16(INT16_C(   115), INT16_C(   204), INT16_C(   195), INT16_C(    11),
                         INT16_C(    48), INT16_C(    39), INT16_C(    37), INT16_C(   183)) },
    { simde_x_mm_set_epu8(UINT8_C( 56), UINT8_C(101), UINT8_C(162), UINT8_C(107),
                          UINT8_C( 59), UINT8_C( 91), UINT8_C( 63), UINT8_C(129),
                          UINT8_C(189), UINT8_C(  4), UINT8_C(  9), UINT8_C(155),
                          UINT8_C(150), UINT8_C( 39), UINT8_C(140), UINT8_C( 87)),
      simde_mm_set_epi16(INT16_C(   189), INT16_C(     4), INT16_C(     9), INT16_C(   155),
                         INT16_C(   150), INT16_C(    39), INT16_C(   140), INT16_C(    87)) },
    { simde_x_mm_set_epu8(UINT8_C(203), UINT8_C(158), UINT8_C(175), UINT8_C(  0),
                          UINT8_C( 27), UINT8_C( 64), UINT8_C(129), UINT8_C( 41),
                          UINT8_C(208), UINT8_C(180), UINT8_C(174), UINT8_C( 83),
                          UINT8_C(142), UINT8_C(198), UINT8_C( 36), UINT8_C(158)),
      simde_mm_set_epi16(INT16_C(   208), INT16_C(   180), INT16_C(   174), INT16_C(    83),
                         INT16_C(   142), INT16_C(   198), INT16_C(    36), INT16_C(   158)) },
    { simde_x_mm_set_epu8(UINT8_C( 48), UINT8_C(139), UINT8_C( 69), UINT8_C( 42),
                          UINT8_C(239), UINT8_C(255), UINT8_C( 84), UINT8_C(226),
                          UINT8_C(180), UINT8_C(204), UINT8_C( 81), UINT8_C(133),
                          UINT8_C(230), UINT8_C( 25), UINT8_C(218), UINT8_C(139)),
      simde_mm_set_epi16(INT16_C(   180), INT16_C(   204), INT16_C(    81), INT16_C(   133),
                         INT16_C(   230), INT16_C(    25), INT16_C(   218), INT16_C(   139)) },
    { simde_x_mm_set_epu8(UINT8_C(213), UINT8_C(  5), UINT8_C( 37), UINT8_C(243),
                          UINT8_C(196), UINT8_C(241), UINT8_C( 11), UINT8_C( 32),
                          UINT8_C(137), UINT8_C(  5), UINT8_C(216), UINT8_C(243),
                          UINT8_C( 25), UINT8_C( 23), UINT8_C(212), UINT8_C( 57)),
      simde_mm_set_epi16(INT16_C(   137), INT16_C(     5), INT16_C(   216), INT16_C(   243),
                         INT16_C(    25), INT16_C(    23), INT16_C(   212), INT16_C(    57)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepu8_epi16(test_vec[i].a);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtepu8_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(216,  58,  77, 216, 179, 254,  83,  42,
                          179, 211,  84, 116, 211, 142,  19, 247),
      simde_mm_set_epi32(211, 142,  19, 247) },
    { simde_x_mm_set_epu8(161,  70,  71,  24,  62,  44,  28,  40,
                           34, 181, 114,  59,  33, 122,  68, 198),
      simde_mm_set_epi32( 33, 122,  68, 198) },
    { simde_x_mm_set_epu8(145, 160,  60, 140,  53, 127,  68, 235,
                          225, 143, 244,  79,  20,  67, 173, 209),
      simde_mm_set_epi32( 20,  67, 173, 209) },
    { simde_x_mm_set_epu8(117, 146, 120,  54, 143, 242, 141, 149,
                           73,  58,  87,  32, 199, 183, 202,  12),
      simde_mm_set_epi32(199, 183, 202,  12) },
    { simde_x_mm_set_epu8( 40,  57,  16,  79, 103, 249, 143, 197,
                          214,  78, 201,  95,  85,  53, 247, 134),
      simde_mm_set_epi32( 85,  53, 247, 134) },
    { simde_x_mm_set_epu8( 72, 163, 211, 103, 152, 114,   2, 140,
                           52,  64,   1,   9, 184, 145, 190, 245),
      simde_mm_set_epi32(184, 145, 190, 245) },
    { simde_x_mm_set_epu8(  7,  28, 147,   3,  70,  73, 159,  19,
                          118, 122, 100,  52, 236,  17, 135, 121),
      simde_mm_set_epi32(236,  17, 135, 121) },
    { simde_x_mm_set_epu8(100, 233, 199,  97, 158, 240, 121, 115,
                          142, 146, 159, 107, 202, 224, 156, 149),
      simde_mm_set_epi32(202, 224, 156, 149) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepu8_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtepu8_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu8(UINT8_C(165), UINT8_C(138), UINT8_C(  9), UINT8_C(193),
                          UINT8_C(199), UINT8_C(213), UINT8_C(108), UINT8_C(127),
                          UINT8_C( 76), UINT8_C( 44), UINT8_C( 97), UINT8_C( 43),
                          UINT8_C( 10), UINT8_C( 41), UINT8_C(226), UINT8_C(134)),
      simde_mm_set_epi64x(INT64_C(                 226), INT64_C(                 134)) },
    { simde_x_mm_set_epu8(UINT8_C(206), UINT8_C(216), UINT8_C(228), UINT8_C( 95),
                          UINT8_C( 16), UINT8_C(235), UINT8_C(117), UINT8_C(249),
                          UINT8_C(118), UINT8_C(169), UINT8_C( 43), UINT8_C(125),
                          UINT8_C(139), UINT8_C(  7), UINT8_C( 78), UINT8_C( 91)),
      simde_mm_set_epi64x(INT64_C(                  78), INT64_C(                  91)) },
    { simde_x_mm_set_epu8(UINT8_C(217), UINT8_C( 54), UINT8_C( 70), UINT8_C( 24),
                          UINT8_C( 18), UINT8_C(185), UINT8_C(  8), UINT8_C( 83),
                          UINT8_C(138), UINT8_C(127), UINT8_C(171), UINT8_C(232),
                          UINT8_C( 25), UINT8_C( 28), UINT8_C(187), UINT8_C(172)),
      simde_mm_set_epi64x(INT64_C(                 187), INT64_C(                 172)) },
    { simde_x_mm_set_epu8(UINT8_C(139), UINT8_C(164), UINT8_C(130), UINT8_C(202),
                          UINT8_C(244), UINT8_C(121), UINT8_C( 41), UINT8_C(156),
                          UINT8_C(187), UINT8_C( 51), UINT8_C( 98), UINT8_C( 32),
                          UINT8_C(179), UINT8_C(192), UINT8_C(214), UINT8_C(180)),
      simde_mm_set_epi64x(INT64_C(                 214), INT64_C(                 180)) },
    { simde_x_mm_set_epu8(UINT8_C(216), UINT8_C( 40), UINT8_C(253), UINT8_C(179),
                          UINT8_C(134), UINT8_C(199), UINT8_C(  8), UINT8_C( 38),
                          UINT8_C(169), UINT8_C(253), UINT8_C(114), UINT8_C( 51),
                          UINT8_C(228), UINT8_C(119), UINT8_C(103), UINT8_C(155)),
      simde_mm_set_epi64x(INT64_C(                 103), INT64_C(                 155)) },
    { simde_x_mm_set_epu8(UINT8_C(197), UINT8_C(169), UINT8_C( 70), UINT8_C(235),
                          UINT8_C(100), UINT8_C(250), UINT8_C( 64), UINT8_C(127),
                          UINT8_C(118), UINT8_C(162), UINT8_C( 19), UINT8_C(173),
                          UINT8_C(116), UINT8_C(180), UINT8_C(  7), UINT8_C(216)),
      simde_mm_set_epi64x(INT64_C(                   7), INT64_C(                 216)) },
    { simde_x_mm_set_epu8(UINT8_C( 50), UINT8_C( 69), UINT8_C( 69), UINT8_C(227),
                          UINT8_C( 69), UINT8_C(  0), UINT8_C( 34), UINT8_C(232),
                          UINT8_C( 24), UINT8_C( 46), UINT8_C(141), UINT8_C(128),
                          UINT8_C(115), UINT8_C(157), UINT8_C(112), UINT8_C( 71)),
      simde_mm_set_epi64x(INT64_C(                 112), INT64_C(                  71)) },
    { simde_x_mm_set_epu8(UINT8_C(120), UINT8_C(  3), UINT8_C(197), UINT8_C(139),
                          UINT8_C( 31), UINT8_C(200), UINT8_C(250), UINT8_C(106),
                          UINT8_C(219), UINT8_C(  4), UINT8_C(206), UINT8_C( 64),
                          UINT8_C(217), UINT8_C(231), UINT8_C(229), UINT8_C( 14)),
      simde_mm_set_epi64x(INT64_C(                 229), INT64_C(                  14)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepu8_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtepu16_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(UINT16_C(45997), UINT16_C(54881), UINT16_C( 8073), UINT16_C(50053),
                           UINT16_C(33513), UINT16_C(60494), UINT16_C(44453), UINT16_C(35449)),
      simde_mm_set_epi32(INT32_C(      33513), INT32_C(      60494), INT32_C(      44453), INT32_C(      35449)) },
    { simde_x_mm_set_epu16(UINT16_C(29322), UINT16_C(60312), UINT16_C(23894), UINT16_C( 5611),
                           UINT16_C(43169), UINT16_C(36178), UINT16_C(30857), UINT16_C(27437)),
      simde_mm_set_epi32(INT32_C(      43169), INT32_C(      36178), INT32_C(      30857), INT32_C(      27437)) },
    { simde_x_mm_set_epu16(UINT16_C(36165), UINT16_C(32250), UINT16_C(32420), UINT16_C(54083),
                           UINT16_C(37595), UINT16_C( 6323), UINT16_C(24868), UINT16_C(13806)),
      simde_mm_set_epi32(INT32_C(      37595), INT32_C(       6323), INT32_C(      24868), INT32_C(      13806)) },
    { simde_x_mm_set_epu16(UINT16_C(47473), UINT16_C(25142), UINT16_C(53974), UINT16_C(29717),
                           UINT16_C(38600), UINT16_C(37432), UINT16_C(33857), UINT16_C( 7799)),
      simde_mm_set_epi32(INT32_C(      38600), INT32_C(      37432), INT32_C(      33857), INT32_C(       7799)) },
    { simde_x_mm_set_epu16(UINT16_C( 9476), UINT16_C(49162), UINT16_C(59100), UINT16_C(46196),
                           UINT16_C(39403), UINT16_C(33179), UINT16_C(42032), UINT16_C(16407)),
      simde_mm_set_epi32(INT32_C(      39403), INT32_C(      33179), INT32_C(      42032), INT32_C(      16407)) },
    { simde_x_mm_set_epu16(UINT16_C(13947), UINT16_C(14884), UINT16_C(63463), UINT16_C(60885),
                           UINT16_C(44795), UINT16_C(57577), UINT16_C( 9399), UINT16_C(54740)),
      simde_mm_set_epi32(INT32_C(      44795), INT32_C(      57577), INT32_C(       9399), INT32_C(      54740)) },
    { simde_x_mm_set_epu16(UINT16_C(16348), UINT16_C(41263), UINT16_C(29933), UINT16_C( 7966),
                           UINT16_C(11747), UINT16_C(45808), UINT16_C(10076), UINT16_C(52634)),
      simde_mm_set_epi32(INT32_C(      11747), INT32_C(      45808), INT32_C(      10076), INT32_C(      52634)) },
    { simde_x_mm_set_epu16(UINT16_C(44921), UINT16_C(31426), UINT16_C(50653), UINT16_C(39011),
                           UINT16_C(15796), UINT16_C(28031), UINT16_C(50348), UINT16_C(35430)),
      simde_mm_set_epi32(INT32_C(      15796), INT32_C(      28031), INT32_C(      50348), INT32_C(      35430)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepu16_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtepu16_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu16(UINT16_C(36944), UINT16_C(47640), UINT16_C( 2187), UINT16_C(10560),
                           UINT16_C( 1923), UINT16_C(52017), UINT16_C(41190), UINT16_C(51381)),
      simde_mm_set_epi64x(INT64_C(               41190), INT64_C(               51381)) },
    { simde_x_mm_set_epu16(UINT16_C(59110), UINT16_C(  781), UINT16_C( 2267), UINT16_C(32518),
                           UINT16_C(16361), UINT16_C(14242), UINT16_C(28197), UINT16_C(27455)),
      simde_mm_set_epi64x(INT64_C(               28197), INT64_C(               27455)) },
    { simde_x_mm_set_epu16(UINT16_C(45312), UINT16_C( 9417), UINT16_C(53316), UINT16_C(54914),
                           UINT16_C( 6651), UINT16_C(32993), UINT16_C(51134), UINT16_C(31066)),
      simde_mm_set_epi64x(INT64_C(               51134), INT64_C(               31066)) },
    { simde_x_mm_set_epu16(UINT16_C( 6198), UINT16_C(41996), UINT16_C(34257), UINT16_C( 1856),
                           UINT16_C(54306), UINT16_C(57993), UINT16_C(28922), UINT16_C(25456)),
      simde_mm_set_epi64x(INT64_C(               28922), INT64_C(               25456)) },
    { simde_x_mm_set_epu16(UINT16_C(52812), UINT16_C(10727), UINT16_C(10105), UINT16_C(31173),
                           UINT16_C( 2196), UINT16_C(38149), UINT16_C(12797), UINT16_C(56721)),
      simde_mm_set_epi64x(INT64_C(               12797), INT64_C(               56721)) },
    { simde_x_mm_set_epu16(UINT16_C(43893), UINT16_C(22212), UINT16_C(55173), UINT16_C(39507),
                           UINT16_C(17371), UINT16_C( 1379), UINT16_C(37505), UINT16_C(51758)),
      simde_mm_set_epi64x(INT64_C(               37505), INT64_C(               51758)) },
    { simde_x_mm_set_epu16(UINT16_C(10102), UINT16_C(59029), UINT16_C(11878), UINT16_C(57288),
                           UINT16_C(63955), UINT16_C(62443), UINT16_C( 1106), UINT16_C(32843)),
      simde_mm_set_epi64x(INT64_C(                1106), INT64_C(               32843)) },
    { simde_x_mm_set_epu16(UINT16_C( 7384), UINT16_C(18925), UINT16_C(61664), UINT16_C(62156),
                           UINT16_C(64229), UINT16_C(12260), UINT16_C(17269), UINT16_C(  165)),
      simde_mm_set_epi64x(INT64_C(               17269), INT64_C(                 165)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepu16_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cvtepu32_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_x_mm_set_epu32(UINT32_C(1089356158), UINT32_C( 716812601), UINT32_C(2600352285), UINT32_C( 851998215)),
      simde_mm_set_epi64x(INT64_C(          2600352285), INT64_C(           851998215)) },
    { simde_x_mm_set_epu32(UINT32_C(2083471993), UINT32_C(3995663695), UINT32_C( 718227173), UINT32_C(3645469582)),
      simde_mm_set_epi64x(INT64_C(           718227173), INT64_C(          3645469582)) },
    { simde_x_mm_set_epu32(UINT32_C(3121544286), UINT32_C( 583537062), UINT32_C( 362422775), UINT32_C(3876080612)),
      simde_mm_set_epi64x(INT64_C(           362422775), INT64_C(          3876080612)) },
    { simde_x_mm_set_epu32(UINT32_C( 336299187), UINT32_C(1772325077), UINT32_C(4159021368), UINT32_C(3897849224)),
      simde_mm_set_epi64x(INT64_C(          4159021368), INT64_C(          3897849224)) },
    { simde_x_mm_set_epu32(UINT32_C(2614142766), UINT32_C(3735995755), UINT32_C(2880699788), UINT32_C( 410975381)),
      simde_mm_set_epi64x(INT64_C(          2880699788), INT64_C(           410975381)) },
    { simde_x_mm_set_epu32(UINT32_C(2584819359), UINT32_C(2278276482), UINT32_C(3087779260), UINT32_C(2573826343)),
      simde_mm_set_epi64x(INT64_C(          3087779260), INT64_C(          2573826343)) },
    { simde_x_mm_set_epu32(UINT32_C( 809379705), UINT32_C( 343015345), UINT32_C( 434582428), UINT32_C( 776037113)),
      simde_mm_set_epi64x(INT64_C(           434582428), INT64_C(           776037113)) },
    { simde_x_mm_set_epu32(UINT32_C(2474833343), UINT32_C(1439643533), UINT32_C(3207542234), UINT32_C(2907982947)),
      simde_mm_set_epi64x(INT64_C(          3207542234), INT64_C(          2907982947)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_cvtepu32_epi64(test_vec[i].a);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_dp_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -564.11), SIMDE_FLOAT64_C(  340.88)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -778.50), SIMDE_FLOAT64_C( -785.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(-267751.01)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -557.21), SIMDE_FLOAT64_C( -291.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -799.93), SIMDE_FLOAT64_C( -716.65)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(208803.14)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -377.58), SIMDE_FLOAT64_C(  860.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -199.70), SIMDE_FLOAT64_C( -642.81)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(-553215.14)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -782.59), SIMDE_FLOAT64_C(  223.96)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -805.25), SIMDE_FLOAT64_C(  736.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(164886.07)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  472.55), SIMDE_FLOAT64_C( -591.15)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  932.48), SIMDE_FLOAT64_C(  630.07)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(-372465.88)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  484.26), SIMDE_FLOAT64_C(  -41.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  593.03), SIMDE_FLOAT64_C(  955.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(-39765.39)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  820.67), SIMDE_FLOAT64_C(  120.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  576.08), SIMDE_FLOAT64_C(  524.49)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(63326.92)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  696.23), SIMDE_FLOAT64_C( -565.44)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  313.65), SIMDE_FLOAT64_C(  242.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(-136943.91)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_dp_pd(test_vec[i].a, test_vec[i].b, 85);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_dp_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  553.37), SIMDE_FLOAT32_C(  120.49), SIMDE_FLOAT32_C( -272.20), SIMDE_FLOAT32_C(  -36.55)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  115.84), SIMDE_FLOAT32_C(  676.89), SIMDE_FLOAT32_C( -919.81), SIMDE_FLOAT32_C( -927.02)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(250372.30), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(250372.30), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  329.44), SIMDE_FLOAT32_C(  -11.73), SIMDE_FLOAT32_C( -693.65), SIMDE_FLOAT32_C( -971.02)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -316.00), SIMDE_FLOAT32_C( -919.35), SIMDE_FLOAT32_C(  956.50), SIMDE_FLOAT32_C( -382.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-663476.25), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(-663476.25), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   48.87), SIMDE_FLOAT32_C( -212.15), SIMDE_FLOAT32_C(  812.72), SIMDE_FLOAT32_C(  350.56)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  612.16), SIMDE_FLOAT32_C( -336.28), SIMDE_FLOAT32_C( -314.44), SIMDE_FLOAT32_C(  725.39)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-255551.67), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(-255551.67), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -17.80), SIMDE_FLOAT32_C(   55.32), SIMDE_FLOAT32_C(  517.59), SIMDE_FLOAT32_C(  356.24)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  440.41), SIMDE_FLOAT32_C( -728.96), SIMDE_FLOAT32_C(  250.15), SIMDE_FLOAT32_C( -658.46)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(129475.14), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(129475.14), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  724.19), SIMDE_FLOAT32_C(  892.03), SIMDE_FLOAT32_C(  632.84), SIMDE_FLOAT32_C(  912.13)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  816.72), SIMDE_FLOAT32_C(  934.76), SIMDE_FLOAT32_C(  -86.66), SIMDE_FLOAT32_C(  780.21)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-54841.92), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(-54841.92), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  767.35), SIMDE_FLOAT32_C(  593.67), SIMDE_FLOAT32_C(  295.16), SIMDE_FLOAT32_C( -928.99)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  446.17), SIMDE_FLOAT32_C( -781.62), SIMDE_FLOAT32_C(  967.10), SIMDE_FLOAT32_C( -630.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(285449.22), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(285449.22), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  954.16), SIMDE_FLOAT32_C( -247.39), SIMDE_FLOAT32_C(   69.65), SIMDE_FLOAT32_C( -817.12)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  330.91), SIMDE_FLOAT32_C(  409.60), SIMDE_FLOAT32_C(  841.84), SIMDE_FLOAT32_C( -474.27)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(58634.16), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(58634.16), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -783.51), SIMDE_FLOAT32_C( -866.65), SIMDE_FLOAT32_C( -877.85), SIMDE_FLOAT32_C( -911.84)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    4.33), SIMDE_FLOAT32_C(  855.54), SIMDE_FLOAT32_C( -839.28), SIMDE_FLOAT32_C(  261.89)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(736761.94), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(736761.94), SIMDE_FLOAT32_C(    0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_dp_ps(test_vec[i].a, test_vec[i].b, 42);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_extract_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    int64_t r;
  } test_vec[8] = {
    { simde_mm_set_epi64x(UINT64_C(0x2d6953577f6833d6), UINT64_C(0x16f735ecbef74fb0)),
      UINT64_C(0x2d6953577f6833d6) },
    { simde_mm_set_epi64x(UINT64_C(0xaaf04de6a347535b), UINT64_C(0x7788e3823cf2dd88)),
      UINT64_C(0xaaf04de6a347535b) },
    { simde_mm_set_epi64x(UINT64_C(0xac0b5ad60a8ae313), UINT64_C(0xd8ff1f0e49d5732f)),
      UINT64_C(0xac0b5ad60a8ae313) },
    { simde_mm_set_epi64x(UINT64_C(0x14a013af8adde846), UINT64_C(0x94084d3fce3dc16a)),
      UINT64_C(0x14a013af8adde846) },
    { simde_mm_set_epi64x(UINT64_C(0xbbdc18f6133d616c), UINT64_C(0xaf38bb2c8ccea04d)),
      UINT64_C(0xbbdc18f6133d616c) },
    { simde_mm_set_epi64x(UINT64_C(0xe54cff88e2d2bf95), UINT64_C(0xb26d52ff06ed52cc)),
      UINT64_C(0xe54cff88e2d2bf95) },
    { simde_mm_set_epi64x(UINT64_C(0xcf0c1539d8ce6a60), UINT64_C(0x3f166cf969999ecb)),
      UINT64_C(0xcf0c1539d8ce6a60) },
    { simde_mm_set_epi64x(UINT64_C(0x54fa14fce453dab2), UINT64_C(0x192a2e66cbd255b7)),
      UINT64_C(0x54fa14fce453dab2) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_mm_extract_epi64(test_vec[i].a, 1);
    munit_assert_int64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_max_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8( -83,   29,    3,   84,   22,   -7,  112, -107,
                         -53, -125,  -41,  -27, -118,   43,   44,   16),
      simde_mm_set_epi8( -80,  -52,   93,   71,   45,  -99,  -14,  -97,
                          11,   62,  111,   17, -108,   -6,   95,    1),
      simde_mm_set_epi8( -80,   29,   93,   84,   45,   -7,  112,  -97,
                          11,   62,  111,   17, -108,   43,   95,   16) },
    { simde_mm_set_epi8(  61, -100,   79,   19,  -86,  116,  -34,   96,
                          70,  -48,  -13,  103, -107,   79,   24,  -71),
      simde_mm_set_epi8(  39,  -53, -117,   65,  -55,   21,   49,  -22,
                         118,  -71, -113,    2,  -83,  -74,  -11,   85),
      simde_mm_set_epi8(  61,  -53,   79,   65,  -55,  116,   49,   96,
                         118,  -48,  -13,  103,  -83,   79,   24,   85) },
    { simde_mm_set_epi8( -13, -124, -110,   22, -109,  127,  -45,  -62,
                           0,   51,  -98,  -11,  -54,  -75, -101, -109),
      simde_mm_set_epi8( -28, -120,   90,  -89,  -72,   93,  -68, -105,
                          39,   46,    2,    5,   16,   34,  -99,   64),
      simde_mm_set_epi8( -13, -120,   90,   22,  -72,  127,  -45,  -62,
                          39,   51,    2,    5,   16,   34,  -99,   64) },
    { simde_mm_set_epi8( -43, -102,  111,   97,  -69,  104,  -24,   -6,
                          29,   43,   65,   47,  -60,   52,    2,  -40),
      simde_mm_set_epi8(  -7,   85,  -63,   48, -117,   19,   99,   67,
                         -50, -116,    5,    2,  -96,  125,  -95,    0),
      simde_mm_set_epi8(  -7,   85,  111,   97,  -69,  104,   99,   67,
                          29,   43,   65,   47,  -60,  125,    2,    0) },
    { simde_mm_set_epi8(  98,   -7,  -56,    9,   74,   50,  -95,  127,
                         114,  118,  -76,  110,  -48,  -50,   57,  -47),
      simde_mm_set_epi8(  47,  -82,   66,  -76,    6,  117,   80,  -13,
                          80, -109,  126,   70,   60,   40,  -54,    3),
      simde_mm_set_epi8(  98,   -7,   66,    9,   74,  117,   80,  127,
                         114,  118,  126,  110,   60,   40,   57,    3) },
    { simde_mm_set_epi8( -80,  -39,  113,  -58,   58,  -88,   22,  -99,
                         112,  -21,   44,  -31,   -2,  109,   19,  -74),
      simde_mm_set_epi8(  71,  -38,   47,  -92,    8,   48,  105,  -82,
                          35,   54,   25,   36,  111,   -7,  -12,  -75),
      simde_mm_set_epi8(  71,  -38,  113,  -58,   58,   48,  105,  -82,
                         112,   54,   44,   36,  111,  109,   19,  -74) },
    { simde_mm_set_epi8(  18,  -41,  -74,   60,  -63,  -55,  -71,  118,
                          46,  -19,   19,   -7,  -55,  -75,  125,  -82),
      simde_mm_set_epi8(-125, -106, -127,  -23,  -63,    0,   56,  -23,
                         -34,  -32,   33,  127,   39,  -68, -103,  126),
      simde_mm_set_epi8(  18,  -41,  -74,   60,  -63,    0,   56,  118,
                          46,  -19,   33,  127,   39,  -68,  125,  126) },
    { simde_mm_set_epi8( -90,  -81,   72,  -34,  -85,  108,   42,   34,
                         -79,  -48,    3,  113,  -62,   25,  -74,   13),
      simde_mm_set_epi8( -44,  -22,   26,  -52,   29,   96,  -97,   88,
                         -11, -125,  -60,   88,  -55,   40,   76,  -80),
      simde_mm_set_epi8( -44,  -22,   72,  -34,   29,  108,   42,   88,
                         -11,  -48,    3,  113,  -55,   40,   76,   13) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_max_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_max_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  477039853), INT32_C( 1555162887), INT32_C(  960008067), INT32_C(-2078514865)),
      simde_mm_set_epi32(INT32_C( -346254872), INT32_C(   70690131), INT32_C( -249580279), INT32_C( -297974983)),
      simde_mm_set_epi32(INT32_C(  477039853), INT32_C( 1555162887), INT32_C(  960008067), INT32_C( -297974983)) },
    { simde_mm_set_epi32(INT32_C( 1946076095), INT32_C( 1626099315), INT32_C(  367020053), INT32_C( -768900730)),
      simde_mm_set_epi32(INT32_C( -534331032), INT32_C(-1542646073), INT32_C(  900332023), INT32_C( 1625404528)),
      simde_mm_set_epi32(INT32_C( 1946076095), INT32_C( 1626099315), INT32_C(  900332023), INT32_C( 1625404528)) },
    { simde_mm_set_epi32(INT32_C( 1785938855), INT32_C(  217054136), INT32_C(    6277613), INT32_C( 1323071612)),
      simde_mm_set_epi32(INT32_C(-1842447194), INT32_C( 1202045241), INT32_C(  391997517), INT32_C(  904511960)),
      simde_mm_set_epi32(INT32_C( 1785938855), INT32_C( 1202045241), INT32_C(  391997517), INT32_C( 1323071612)) },
    { simde_mm_set_epi32(INT32_C( -303416903), INT32_C(  131247622), INT32_C(-2038528381), INT32_C(-1774779832)),
      simde_mm_set_epi32(INT32_C(  307942484), INT32_C(-1408988466), INT32_C(-1799017519), INT32_C( 1885804693)),
      simde_mm_set_epi32(INT32_C(  307942484), INT32_C(  131247622), INT32_C(-1799017519), INT32_C( 1885804693)) },
    { simde_mm_set_epi32(INT32_C( -424176665), INT32_C(  531131808), INT32_C( -752351935), INT32_C(  650848232)),
      simde_mm_set_epi32(INT32_C(-1513144536), INT32_C( -875213417), INT32_C(-1592044131), INT32_C(-1714853090)),
      simde_mm_set_epi32(INT32_C( -424176665), INT32_C(  531131808), INT32_C( -752351935), INT32_C(  650848232)) },
    { simde_mm_set_epi32(INT32_C( 1901471013), INT32_C(-1928782687), INT32_C(-1204237637), INT32_C(-1735607658)),
      simde_mm_set_epi32(INT32_C( 1526238167), INT32_C( 1155872155), INT32_C( -981128645), INT32_C(-1655952235)),
      simde_mm_set_epi32(INT32_C( 1901471013), INT32_C( 1155872155), INT32_C( -981128645), INT32_C(-1655952235)) },
    { simde_mm_set_epi32(INT32_C( 2067002242), INT32_C( -967820279), INT32_C(-1842332164), INT32_C( 1466140749)),
      simde_mm_set_epi32(INT32_C(  -25857443), INT32_C(-1417095277), INT32_C(  -31302876), INT32_C(-1114441571)),
      simde_mm_set_epi32(INT32_C( 2067002242), INT32_C( -967820279), INT32_C(  -31302876), INT32_C( 1466140749)) },
    { simde_mm_set_epi32(INT32_C( -515864750), INT32_C( 1885657427), INT32_C(-1627411585), INT32_C( -455970760)),
      simde_mm_set_epi32(INT32_C( -505553594), INT32_C(-1363391302), INT32_C( 1929235496), INT32_C(-1212934452)),
      simde_mm_set_epi32(INT32_C( -505553594), INT32_C( 1885657427), INT32_C( 1929235496), INT32_C( -455970760)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_max_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_min_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(0xc9, 0xe9, 0x1f, 0x97, 0x87, 0x04, 0x80, 0x76,
			0x20, 0x62, 0xfb, 0x67, 0xc7, 0x9f, 0x8e, 0x0a),
      simde_mm_set_epi8(0xef, 0xdf, 0xe2, 0x1c, 0x8f, 0x43, 0xea, 0xb3,
			0xd0, 0xea, 0xbc, 0x1b, 0xea, 0x65, 0x20, 0x4c),
      simde_mm_set_epi8(0xc9, 0xdf, 0xe2, 0x97, 0x87, 0x04, 0x80, 0xb3,
			0xd0, 0xea, 0xbc, 0x1b, 0xc7, 0x9f, 0x8e, 0x0a) },
    { simde_mm_set_epi8(0xbc, 0x1a, 0xeb, 0xda, 0xa2, 0x25, 0x2b, 0x11,
			0xf0, 0x01, 0x7a, 0x88, 0x94, 0x03, 0x15, 0x05),
      simde_mm_set_epi8(0xb7, 0x9d, 0x0c, 0x35, 0x77, 0xa0, 0x46, 0x04,
			0xf3, 0x23, 0x08, 0xfc, 0x74, 0xb7, 0x81, 0xda),
      simde_mm_set_epi8(0xb7, 0x9d, 0xeb, 0xda, 0xa2, 0xa0, 0x2b, 0x04,
			0xf0, 0x01, 0x08, 0x88, 0x94, 0xb7, 0x81, 0xda) },
    { simde_mm_set_epi8(0x06, 0x59, 0x0c, 0x14, 0x01, 0x4f, 0x09, 0x5e,
			0x2d, 0xd8, 0x7d, 0x71, 0x02, 0xfa, 0x49, 0xaa),
      simde_mm_set_epi8(0xb1, 0xe8, 0xc9, 0x61, 0xcf, 0x61, 0x79, 0x6e,
			0x2c, 0xa6, 0x8b, 0x75, 0x95, 0xf4, 0xf3, 0x4b),
      simde_mm_set_epi8(0xb1, 0xe8, 0xc9, 0x14, 0xcf, 0x4f, 0x09, 0x5e,
			0x2c, 0xa6, 0x8b, 0x71, 0x95, 0xf4, 0xf3, 0xaa) },
    { simde_mm_set_epi8(0x97, 0x70, 0x9c, 0xb5, 0x18, 0x1f, 0x25, 0x8c,
			0xa8, 0x3e, 0xac, 0xc3, 0x96, 0x7b, 0xf4, 0x55),
      simde_mm_set_epi8(0x16, 0x4c, 0x0e, 0x4f, 0x75, 0xca, 0xbb, 0x3e,
			0x5f, 0x88, 0x96, 0x85, 0x48, 0xb8, 0xe1, 0xb5),
      simde_mm_set_epi8(0x97, 0x4c, 0x9c, 0xb5, 0x18, 0xca, 0xbb, 0x8c,
			0xa8, 0x88, 0x96, 0x85, 0x96, 0xb8, 0xe1, 0xb5) },
    { simde_mm_set_epi8(0x80, 0x42, 0x86, 0x16, 0xf0, 0xf2, 0x2e, 0x22,
			0xba, 0xd2, 0x26, 0xc1, 0x99, 0x1b, 0x32, 0xc9),
      simde_mm_set_epi8(0xf6, 0x93, 0x6c, 0x52, 0x4f, 0xff, 0xad, 0x24,
			0x04, 0xa7, 0x1e, 0xcc, 0x2c, 0x12, 0x32, 0x89),
      simde_mm_set_epi8(0x80, 0x93, 0x86, 0x16, 0xf0, 0xf2, 0xad, 0x22,
			0xba, 0xa7, 0x1e, 0xc1, 0x99, 0x12, 0x32, 0x89) },
    { simde_mm_set_epi8(0xa7, 0x80, 0x20, 0x27, 0x69, 0xfb, 0x1b, 0x03,
			0x57, 0xa8, 0x5f, 0x8b, 0x6a, 0x80, 0x38, 0x01),
      simde_mm_set_epi8(0x5b, 0xd3, 0x0e, 0x20, 0x4f, 0x0a, 0x58, 0x80,
			0xc2, 0x8b, 0x21, 0x13, 0x84, 0xf8, 0x01, 0xaf),
      simde_mm_set_epi8(0xa7, 0x80, 0x0e, 0x20, 0x4f, 0xfb, 0x1b, 0x80,
			0xc2, 0x8b, 0x21, 0x8b, 0x84, 0x80, 0x01, 0xaf) },
    { simde_mm_set_epi8(0x51, 0xed, 0xd3, 0xe0, 0x1d, 0x69, 0x38, 0xee,
			0x5b, 0xdc, 0x73, 0x98, 0xe6, 0x7a, 0x00, 0x88),
      simde_mm_set_epi8(0x9e, 0x8c, 0xcc, 0x07, 0x5b, 0x77, 0x11, 0xb1,
			0x7d, 0x99, 0x04, 0x3c, 0xc8, 0xce, 0xd2, 0x9f),
      simde_mm_set_epi8(0x9e, 0x8c, 0xcc, 0xe0, 0x1d, 0x69, 0x11, 0xb1,
			0x5b, 0x99, 0x04, 0x98, 0xc8, 0xce, 0xd2, 0x88) },
    { simde_mm_set_epi8(0xc3, 0xbd, 0x40, 0x28, 0x91, 0x09, 0x85, 0xdd,
			0x89, 0x9d, 0xc7, 0xaa, 0x61, 0xa4, 0x00, 0x31),
      simde_mm_set_epi8(0xcf, 0xe5, 0xdb, 0xbd, 0x87, 0x0f, 0x0b, 0xe6,
			0x98, 0x78, 0x38, 0xa3, 0x22, 0xb8, 0xe3, 0x59),
      simde_mm_set_epi8(0xc3, 0xbd, 0xdb, 0xbd, 0x87, 0x09, 0x85, 0xdd,
			0x89, 0x9d, 0xc7, 0xa3, 0x22, 0xa4, 0xe3, 0x31) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_min_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_min_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1390607532), INT32_C(  385446037), INT32_C( -880551963), INT32_C(-1976882160)),
      simde_mm_set_epi32(INT32_C(-1328784057), INT32_C(  765325983), INT32_C(  188641041), INT32_C(-1795531007)),
      simde_mm_set_epi32(INT32_C(-1390607532), INT32_C(  385446037), INT32_C( -880551963), INT32_C(-1976882160)) },
    { simde_mm_set_epi32(INT32_C( 1033654035), INT32_C(-1435181472), INT32_C( 1188098919), INT32_C(-1789978439)),
      simde_mm_set_epi32(INT32_C(  667650881), INT32_C( -921357846), INT32_C( 1991872258), INT32_C(-1380518571)),
      simde_mm_set_epi32(INT32_C(  667650881), INT32_C(-1435181472), INT32_C( 1188098919), INT32_C(-1789978439)) },
    { simde_mm_set_epi32(INT32_C( -209415658), INT32_C(-1820339262), INT32_C(    3383029), INT32_C( -894067821)),
      simde_mm_set_epi32(INT32_C( -460825945), INT32_C(-1201816425), INT32_C(  657326597), INT32_C(  270703936)),
      simde_mm_set_epi32(INT32_C( -460825945), INT32_C(-1820339262), INT32_C(    3383029), INT32_C( -894067821)) },
    { simde_mm_set_epi32(INT32_C( -711299231), INT32_C(-1150752518), INT32_C(  489373999), INT32_C(-1003224360)),
      simde_mm_set_epi32(INT32_C( -111820496), INT32_C(-1961663677), INT32_C( -829684478), INT32_C(-1602379520)),
      simde_mm_set_epi32(INT32_C( -711299231), INT32_C(-1961663677), INT32_C( -829684478), INT32_C(-1602379520)) },
    { simde_mm_set_epi32(INT32_C( 1660536841), INT32_C( 1244832127), INT32_C( 1920382062), INT32_C( -791791151)),
      simde_mm_set_epi32(INT32_C(  799949492), INT32_C(  108351731), INT32_C( 1351843398), INT32_C( 1009306115)),
      simde_mm_set_epi32(INT32_C(  799949492), INT32_C(  108351731), INT32_C( 1351843398), INT32_C( -791791151)) },
    { simde_mm_set_epi32(INT32_C(-1327926842), INT32_C(  984094365), INT32_C( 1894460641), INT32_C(  -26405962)),
      simde_mm_set_epi32(INT32_C( 1205481380), INT32_C(  137390510), INT32_C(  590747940), INT32_C( 1878652085)),
      simde_mm_set_epi32(INT32_C(-1327926842), INT32_C(  137390510), INT32_C(  590747940), INT32_C(  -26405962)) },
    { simde_mm_set_epi32(INT32_C(  316126780), INT32_C(-1043744394), INT32_C(  787289081), INT32_C( -910852690)),
      simde_mm_set_epi32(INT32_C(-2087288343), INT32_C(-1056950039), INT32_C( -555736705), INT32_C(  666671486)),
      simde_mm_set_epi32(INT32_C(-2087288343), INT32_C(-1056950039), INT32_C( -555736705), INT32_C( -910852690)) },
    { simde_mm_set_epi32(INT32_C(-1498461986), INT32_C(-1418974686), INT32_C(-1311767695), INT32_C(-1038502387)),
      simde_mm_set_epi32(INT32_C( -722855220), INT32_C(  492871512), INT32_C( -175913896), INT32_C( -920105808)),
      simde_mm_set_epi32(INT32_C(-1498461986), INT32_C(-1418974686), INT32_C(-1311767695), INT32_C(-1038502387)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_min_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_mullo_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1431531471), INT32_C(-1934656662), INT32_C( -638668877), INT32_C( 1966621031)),
      simde_mm_set_epi32(INT32_C( -646581607), INT32_C( 1232530244), INT32_C(  841047033), INT32_C(-1472432488)),
      simde_mm_set_epi32(INT32_C( 1865056439), INT32_C(-1849485784), INT32_C( 1840285211), INT32_C( 1940934440)) },
    { simde_mm_set_epi32(INT32_C( 2119691862), INT32_C( 1656188631), INT32_C(  949015012), INT32_C( -645064268)),
      simde_mm_set_epi32(INT32_C( 1854664684), INT32_C( 1364588379), INT32_C( -185048322), INT32_C( 1546431794)),
      simde_mm_set_epi32(INT32_C( -314310328), INT32_C( -410462355), INT32_C(  887719992), INT32_C( -220354264)) },
    { simde_mm_set_epi32(INT32_C(  390191893), INT32_C( 1246080619), INT32_C( 2032818940), INT32_C(-1664549536)),
      simde_mm_set_epi32(INT32_C( 1802476280), INT32_C(-1492538899), INT32_C( -866846002), INT32_C(-1929477089)),
      simde_mm_set_epi32(INT32_C( -357441960), INT32_C(-1318446065), INT32_C(-2019602744), INT32_C(-2076430688)) },
    { simde_mm_set_epi32(INT32_C( -629988407), INT32_C(-1719063308), INT32_C( -231912988), INT32_C( 1462330866)),
      simde_mm_set_epi32(INT32_C(-1320599620), INT32_C( -769970788), INT32_C( -625134420), INT32_C(  293199422)),
      simde_mm_set_epi32(INT32_C( -273826148), INT32_C(-1841674064), INT32_C(-1631324880), INT32_C( 1137740956)) },
    { simde_mm_set_epi32(INT32_C(-1221152076), INT32_C(-1223458578), INT32_C(-1263311025), INT32_C( 2089857790)),
      simde_mm_set_epi32(INT32_C(-2068401725), INT32_C( 1531524331), INT32_C( 1064638153), INT32_C( -843878287)),
      simde_mm_set_epi32(INT32_C( 1009816348), INT32_C( 1660269178), INT32_C( -203954425), INT32_C( -674749922)) },
    { simde_mm_set_epi32(INT32_C(-1283522478), INT32_C(  524522527), INT32_C( 1152886109), INT32_C( -438302719)),
      simde_mm_set_epi32(INT32_C(-2012975476), INT32_C(  -67951228), INT32_C(  258710699), INT32_C(  -25585755)),
      simde_mm_set_epi32(INT32_C( 1289709784), INT32_C( -508699908), INT32_C( 1615798559), INT32_C(  345423781)) },
    { simde_mm_set_epi32(INT32_C(  199098300), INT32_C(-1941350427), INT32_C(-1170519288), INT32_C( 2117275260)),
      simde_mm_set_epi32(INT32_C( 1736533752), INT32_C(  668304389), INT32_C(-1871663356), INT32_C( -231105582)),
      simde_mm_set_epi32(INT32_C( 1957733920), INT32_C(-1823880327), INT32_C( -994597856), INT32_C( -515705416)) },
    { simde_mm_set_epi32(INT32_C(  796248112), INT32_C(  -74441002), INT32_C(  756194998), INT32_C(  128690934)),
      simde_mm_set_epi32(INT32_C( -934813484), INT32_C( 1495167051), INT32_C(  549239917), INT32_C( 1315900336)),
      simde_mm_set_epi32(INT32_C( 1644414912), INT32_C(-1010128718), INT32_C(  723729278), INT32_C(-1157096672)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_mullo_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  TEST_FUNC(mm_blend_epi16),
  TEST_FUNC(mm_blend_pd),
  TEST_FUNC(mm_blend_ps),
  TEST_FUNC(mm_blendv_epi8),
  TEST_FUNC(mm_blendv_pd),
  TEST_FUNC(mm_blendv_ps),

  TEST_FUNC(mm_ceil_pd),
  TEST_FUNC(mm_ceil_ps),
  TEST_FUNC(mm_ceil_sd),
  TEST_FUNC(mm_ceil_ss),

  TEST_FUNC(mm_cmpeq_epi64),

  TEST_FUNC(mm_cvtepi8_epi16),
  TEST_FUNC(mm_cvtepi8_epi32),
  TEST_FUNC(mm_cvtepi8_epi64),
  TEST_FUNC(mm_cvtepu8_epi16),
  TEST_FUNC(mm_cvtepu8_epi32),
  TEST_FUNC(mm_cvtepu8_epi64),
  TEST_FUNC(mm_cvtepi16_epi32),
  TEST_FUNC(mm_cvtepi16_epi64),
  TEST_FUNC(mm_cvtepu16_epi32),
  TEST_FUNC(mm_cvtepu16_epi64),
  TEST_FUNC(mm_cvtepi32_epi64),
  TEST_FUNC(mm_cvtepu32_epi64),

  TEST_FUNC(mm_dp_pd),
  TEST_FUNC(mm_dp_ps),

  TEST_FUNC(mm_extract_epi64),

  TEST_FUNC(mm_max_epi32),
  TEST_FUNC(mm_max_epi8),
  TEST_FUNC(mm_min_epi8),
  TEST_FUNC(mm_min_epi32),

  TEST_FUNC(mm_mullo_epi32),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

#if defined(SIMDE_NO_NATIVE)
#  define simde_sse4_1_test_suite simde_sse4_1_emul_test_suite
#endif

MunitSuite simde_sse4_1_test_suite = {
  (char*) "/sse4.1",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
