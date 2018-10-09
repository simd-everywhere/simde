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
#include <simde/x86/avx.h>

#include <stdio.h>

static MunitResult
test_simde_mm256_set_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    int8_t a[32];
    simde__m256i r;

    munit_rand_memory(sizeof(a), (uint8_t*) a);
    r = simde_mm256_set_epi8(a[31], a[30], a[29], a[28], a[27], a[26], a[25], a[24],
                             a[23], a[22], a[21], a[20], a[19], a[18], a[17], a[16],
                             a[15], a[14], a[13], a[12], a[11], a[10], a[ 9], a[ 8],
                             a[ 7], a[ 6], a[ 5], a[ 4], a[ 3], a[ 2], a[ 1], a[ 0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 16 ; i++) {
    int16_t a[16];
    simde__m256i r;

    munit_rand_memory(sizeof(a), (uint8_t*) a);
    r = simde_mm256_set_epi16(a[15], a[14], a[13], a[12], a[11], a[10], a[ 9], a[ 8],
                              a[ 7], a[ 6], a[ 5], a[ 4], a[ 3], a[ 2], a[ 1], a[ 0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    int32_t a[8];
    simde__m256i r;

    munit_rand_memory(sizeof(a), (uint8_t*) a);
    r = simde_mm256_set_epi32(a[7], a[6], a[5], a[4], a[3], a[2], a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set_epi64x(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 64 ; i++) {
    int64_t a[4];
    simde__m256i r;

    munit_rand_memory(sizeof(a), (uint8_t*) a);
    r = simde_mm256_set_epi64x(a[3], a[2], a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    simde_float32 a[8];
    simde__m256 r;

    random_f32v(8, a);
    r = simde_mm256_set_ps(a[7], a[6], a[5], a[4], a[3], a[2], a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 64 ; i++) {
    simde_float64 a[4];
    simde__m256d r;

    random_f64v(4, a);
    r = simde_mm256_set_pd(a[3], a[2], a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set_m128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 64 ; i++) {
    simde__m128 a[2];
    simde__m256 r;

    random_f32v(8, (simde_float32*) a);
    r = simde_mm256_set_m128(a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set_m128d(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 64 ; i++) {
    simde__m128d a[2];
    simde__m256d r;

    random_f64v(4, (simde_float64*) a);
    r = simde_mm256_set_m128d(a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set_m128i(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 64 ; i++) {
    simde__m128i a[2];
    simde__m256i r;

    munit_rand_memory(sizeof(a), (uint8_t*) a);
    r = simde_mm256_set_m128i(a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set1_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int8_t a;
    simde__m256i r;
  } test_vec[8] = {
    { 41,
      simde_mm256_set_epi8(INT8_C(  41), INT8_C(  41), INT8_C(  41), INT8_C(  41),
                           INT8_C(  41), INT8_C(  41), INT8_C(  41), INT8_C(  41),
                           INT8_C(  41), INT8_C(  41), INT8_C(  41), INT8_C(  41),
                           INT8_C(  41), INT8_C(  41), INT8_C(  41), INT8_C(  41),
                           INT8_C(  41), INT8_C(  41), INT8_C(  41), INT8_C(  41),
                           INT8_C(  41), INT8_C(  41), INT8_C(  41), INT8_C(  41),
                           INT8_C(  41), INT8_C(  41), INT8_C(  41), INT8_C(  41),
                           INT8_C(  41), INT8_C(  41), INT8_C(  41), INT8_C(  41)) },
    { -5,
      simde_mm256_set_epi8(INT8_C(  -5), INT8_C(  -5), INT8_C(  -5), INT8_C(  -5),
                           INT8_C(  -5), INT8_C(  -5), INT8_C(  -5), INT8_C(  -5),
                           INT8_C(  -5), INT8_C(  -5), INT8_C(  -5), INT8_C(  -5),
                           INT8_C(  -5), INT8_C(  -5), INT8_C(  -5), INT8_C(  -5),
                           INT8_C(  -5), INT8_C(  -5), INT8_C(  -5), INT8_C(  -5),
                           INT8_C(  -5), INT8_C(  -5), INT8_C(  -5), INT8_C(  -5),
                           INT8_C(  -5), INT8_C(  -5), INT8_C(  -5), INT8_C(  -5),
                           INT8_C(  -5), INT8_C(  -5), INT8_C(  -5), INT8_C(  -5)) },
    { -85,
      simde_mm256_set_epi8(INT8_C( -85), INT8_C( -85), INT8_C( -85), INT8_C( -85),
                           INT8_C( -85), INT8_C( -85), INT8_C( -85), INT8_C( -85),
                           INT8_C( -85), INT8_C( -85), INT8_C( -85), INT8_C( -85),
                           INT8_C( -85), INT8_C( -85), INT8_C( -85), INT8_C( -85),
                           INT8_C( -85), INT8_C( -85), INT8_C( -85), INT8_C( -85),
                           INT8_C( -85), INT8_C( -85), INT8_C( -85), INT8_C( -85),
                           INT8_C( -85), INT8_C( -85), INT8_C( -85), INT8_C( -85),
                           INT8_C( -85), INT8_C( -85), INT8_C( -85), INT8_C( -85)) },
    { 61,
      simde_mm256_set_epi8(INT8_C(  61), INT8_C(  61), INT8_C(  61), INT8_C(  61),
                           INT8_C(  61), INT8_C(  61), INT8_C(  61), INT8_C(  61),
                           INT8_C(  61), INT8_C(  61), INT8_C(  61), INT8_C(  61),
                           INT8_C(  61), INT8_C(  61), INT8_C(  61), INT8_C(  61),
                           INT8_C(  61), INT8_C(  61), INT8_C(  61), INT8_C(  61),
                           INT8_C(  61), INT8_C(  61), INT8_C(  61), INT8_C(  61),
                           INT8_C(  61), INT8_C(  61), INT8_C(  61), INT8_C(  61),
                           INT8_C(  61), INT8_C(  61), INT8_C(  61), INT8_C(  61)) },
    { -125,
      simde_mm256_set_epi8(INT8_C(-125), INT8_C(-125), INT8_C(-125), INT8_C(-125),
                           INT8_C(-125), INT8_C(-125), INT8_C(-125), INT8_C(-125),
                           INT8_C(-125), INT8_C(-125), INT8_C(-125), INT8_C(-125),
                           INT8_C(-125), INT8_C(-125), INT8_C(-125), INT8_C(-125),
                           INT8_C(-125), INT8_C(-125), INT8_C(-125), INT8_C(-125),
                           INT8_C(-125), INT8_C(-125), INT8_C(-125), INT8_C(-125),
                           INT8_C(-125), INT8_C(-125), INT8_C(-125), INT8_C(-125),
                           INT8_C(-125), INT8_C(-125), INT8_C(-125), INT8_C(-125)) },
    { -117,
      simde_mm256_set_epi8(INT8_C(-117), INT8_C(-117), INT8_C(-117), INT8_C(-117),
                           INT8_C(-117), INT8_C(-117), INT8_C(-117), INT8_C(-117),
                           INT8_C(-117), INT8_C(-117), INT8_C(-117), INT8_C(-117),
                           INT8_C(-117), INT8_C(-117), INT8_C(-117), INT8_C(-117),
                           INT8_C(-117), INT8_C(-117), INT8_C(-117), INT8_C(-117),
                           INT8_C(-117), INT8_C(-117), INT8_C(-117), INT8_C(-117),
                           INT8_C(-117), INT8_C(-117), INT8_C(-117), INT8_C(-117),
                           INT8_C(-117), INT8_C(-117), INT8_C(-117), INT8_C(-117)) },
    { 5,
      simde_mm256_set_epi8(INT8_C(   5), INT8_C(   5), INT8_C(   5), INT8_C(   5),
                           INT8_C(   5), INT8_C(   5), INT8_C(   5), INT8_C(   5),
                           INT8_C(   5), INT8_C(   5), INT8_C(   5), INT8_C(   5),
                           INT8_C(   5), INT8_C(   5), INT8_C(   5), INT8_C(   5),
                           INT8_C(   5), INT8_C(   5), INT8_C(   5), INT8_C(   5),
                           INT8_C(   5), INT8_C(   5), INT8_C(   5), INT8_C(   5),
                           INT8_C(   5), INT8_C(   5), INT8_C(   5), INT8_C(   5),
                           INT8_C(   5), INT8_C(   5), INT8_C(   5), INT8_C(   5)) },
    { -41,
      simde_mm256_set_epi8(INT8_C( -41), INT8_C( -41), INT8_C( -41), INT8_C( -41),
                           INT8_C( -41), INT8_C( -41), INT8_C( -41), INT8_C( -41),
                           INT8_C( -41), INT8_C( -41), INT8_C( -41), INT8_C( -41),
                           INT8_C( -41), INT8_C( -41), INT8_C( -41), INT8_C( -41),
                           INT8_C( -41), INT8_C( -41), INT8_C( -41), INT8_C( -41),
                           INT8_C( -41), INT8_C( -41), INT8_C( -41), INT8_C( -41),
                           INT8_C( -41), INT8_C( -41), INT8_C( -41), INT8_C( -41),
                           INT8_C( -41), INT8_C( -41), INT8_C( -41), INT8_C( -41)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_set1_epi8(test_vec[i].a);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set1_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int16_t a;
    simde__m256i r;
  } test_vec[8] = {
    { INT16_C( -7117),
      simde_mm256_set_epi16(INT16_C( -7117), INT16_C( -7117), INT16_C( -7117), INT16_C( -7117),
                            INT16_C( -7117), INT16_C( -7117), INT16_C( -7117), INT16_C( -7117),
                            INT16_C( -7117), INT16_C( -7117), INT16_C( -7117), INT16_C( -7117),
                            INT16_C( -7117), INT16_C( -7117), INT16_C( -7117), INT16_C( -7117)) },
    { INT16_C( -4832),
      simde_mm256_set_epi16(INT16_C( -4832), INT16_C( -4832), INT16_C( -4832), INT16_C( -4832),
                            INT16_C( -4832), INT16_C( -4832), INT16_C( -4832), INT16_C( -4832),
                            INT16_C( -4832), INT16_C( -4832), INT16_C( -4832), INT16_C( -4832),
                            INT16_C( -4832), INT16_C( -4832), INT16_C( -4832), INT16_C( -4832)) },
    { INT16_C( 20615),
      simde_mm256_set_epi16(INT16_C( 20615), INT16_C( 20615), INT16_C( 20615), INT16_C( 20615),
                            INT16_C( 20615), INT16_C( 20615), INT16_C( 20615), INT16_C( 20615),
                            INT16_C( 20615), INT16_C( 20615), INT16_C( 20615), INT16_C( 20615),
                            INT16_C( 20615), INT16_C( 20615), INT16_C( 20615), INT16_C( 20615)) },
    { INT16_C(-30117),
      simde_mm256_set_epi16(INT16_C(-30117), INT16_C(-30117), INT16_C(-30117), INT16_C(-30117),
                            INT16_C(-30117), INT16_C(-30117), INT16_C(-30117), INT16_C(-30117),
                            INT16_C(-30117), INT16_C(-30117), INT16_C(-30117), INT16_C(-30117),
                            INT16_C(-30117), INT16_C(-30117), INT16_C(-30117), INT16_C(-30117)) },
    { INT16_C( 32088),
      simde_mm256_set_epi16(INT16_C( 32088), INT16_C( 32088), INT16_C( 32088), INT16_C( 32088),
                            INT16_C( 32088), INT16_C( 32088), INT16_C( 32088), INT16_C( 32088),
                            INT16_C( 32088), INT16_C( 32088), INT16_C( 32088), INT16_C( 32088),
                            INT16_C( 32088), INT16_C( 32088), INT16_C( 32088), INT16_C( 32088)) },
    { INT16_C(-14076),
      simde_mm256_set_epi16(INT16_C(-14076), INT16_C(-14076), INT16_C(-14076), INT16_C(-14076),
                            INT16_C(-14076), INT16_C(-14076), INT16_C(-14076), INT16_C(-14076),
                            INT16_C(-14076), INT16_C(-14076), INT16_C(-14076), INT16_C(-14076),
                            INT16_C(-14076), INT16_C(-14076), INT16_C(-14076), INT16_C(-14076)) },
    { INT16_C( -9132),
      simde_mm256_set_epi16(INT16_C( -9132), INT16_C( -9132), INT16_C( -9132), INT16_C( -9132),
                            INT16_C( -9132), INT16_C( -9132), INT16_C( -9132), INT16_C( -9132),
                            INT16_C( -9132), INT16_C( -9132), INT16_C( -9132), INT16_C( -9132),
                            INT16_C( -9132), INT16_C( -9132), INT16_C( -9132), INT16_C( -9132)) },
    { INT16_C(-24801),
      simde_mm256_set_epi16(INT16_C(-24801), INT16_C(-24801), INT16_C(-24801), INT16_C(-24801),
                            INT16_C(-24801), INT16_C(-24801), INT16_C(-24801), INT16_C(-24801),
                            INT16_C(-24801), INT16_C(-24801), INT16_C(-24801), INT16_C(-24801),
                            INT16_C(-24801), INT16_C(-24801), INT16_C(-24801), INT16_C(-24801)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_set1_epi16(test_vec[i].a);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set1_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t a;
    simde__m256i r;
  } test_vec[8] = {
    { INT32_C( 1458307866),
      simde_mm256_set_epi32(INT32_C( 1458307866), INT32_C( 1458307866), INT32_C( 1458307866), INT32_C( 1458307866),
                            INT32_C( 1458307866), INT32_C( 1458307866), INT32_C( 1458307866), INT32_C( 1458307866)) },
    { INT32_C(-1231481357),
      simde_mm256_set_epi32(INT32_C(-1231481357), INT32_C(-1231481357), INT32_C(-1231481357), INT32_C(-1231481357),
                            INT32_C(-1231481357), INT32_C(-1231481357), INT32_C(-1231481357), INT32_C(-1231481357)) },
    { INT32_C( 1330347041),
      simde_mm256_set_epi32(INT32_C( 1330347041), INT32_C( 1330347041), INT32_C( 1330347041), INT32_C( 1330347041),
                            INT32_C( 1330347041), INT32_C( 1330347041), INT32_C( 1330347041), INT32_C( 1330347041)) },
    { INT32_C(-2031969158),
      simde_mm256_set_epi32(INT32_C(-2031969158), INT32_C(-2031969158), INT32_C(-2031969158), INT32_C(-2031969158),
                            INT32_C(-2031969158), INT32_C(-2031969158), INT32_C(-2031969158), INT32_C(-2031969158)) },
    { INT32_C(  138293031),
      simde_mm256_set_epi32(INT32_C(  138293031), INT32_C(  138293031), INT32_C(  138293031), INT32_C(  138293031),
                            INT32_C(  138293031), INT32_C(  138293031), INT32_C(  138293031), INT32_C(  138293031)) },
    { INT32_C( -870589211),
      simde_mm256_set_epi32(INT32_C( -870589211), INT32_C( -870589211), INT32_C( -870589211), INT32_C( -870589211),
                            INT32_C( -870589211), INT32_C( -870589211), INT32_C( -870589211), INT32_C( -870589211)) },
    { INT32_C( 1439279097),
      simde_mm256_set_epi32(INT32_C( 1439279097), INT32_C( 1439279097), INT32_C( 1439279097), INT32_C( 1439279097),
                            INT32_C( 1439279097), INT32_C( 1439279097), INT32_C( 1439279097), INT32_C( 1439279097)) },
    { INT32_C( -102725779),
      simde_mm256_set_epi32(INT32_C( -102725779), INT32_C( -102725779), INT32_C( -102725779), INT32_C( -102725779),
                            INT32_C( -102725779), INT32_C( -102725779), INT32_C( -102725779), INT32_C( -102725779)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_set1_epi32(test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set1_epi64x(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int64_t a;
    simde__m256i r;
  } test_vec[8] = {
    { INT64_C( 5105791061004147197),
      simde_mm256_set_epi64x(INT64_C( 5105791061004147197), INT64_C( 5105791061004147197),
                             INT64_C( 5105791061004147197), INT64_C( 5105791061004147197)) },
    { INT64_C(-2078502026959165134),
      simde_mm256_set_epi64x(INT64_C(-2078502026959165134), INT64_C(-2078502026959165134),
                             INT64_C(-2078502026959165134), INT64_C(-2078502026959165134)) },
    { INT64_C( 3468007801991671414),
      simde_mm256_set_epi64x(INT64_C( 3468007801991671414), INT64_C( 3468007801991671414),
                             INT64_C( 3468007801991671414), INT64_C( 3468007801991671414)) },
    { INT64_C(-1026830878024479084),
      simde_mm256_set_epi64x(INT64_C(-1026830878024479084), INT64_C(-1026830878024479084),
                             INT64_C(-1026830878024479084), INT64_C(-1026830878024479084)) },
    { INT64_C(-5815393469667065909),
      simde_mm256_set_epi64x(INT64_C(-5815393469667065909), INT64_C(-5815393469667065909),
                             INT64_C(-5815393469667065909), INT64_C(-5815393469667065909)) },
    { INT64_C(-1858841878581774308),
      simde_mm256_set_epi64x(INT64_C(-1858841878581774308), INT64_C(-1858841878581774308),
                             INT64_C(-1858841878581774308), INT64_C(-1858841878581774308)) },
    { INT64_C( 6272125310275044670),
      simde_mm256_set_epi64x(INT64_C( 6272125310275044670), INT64_C( 6272125310275044670),
                             INT64_C( 6272125310275044670), INT64_C( 6272125310275044670)) },
    { INT64_C( 6393396529564376044),
      simde_mm256_set_epi64x(INT64_C( 6393396529564376044), INT64_C( 6393396529564376044),
                             INT64_C( 6393396529564376044), INT64_C( 6393396529564376044)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_set1_epi64x(test_vec[i].a);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set1_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32 a;
    simde__m256 r;
  } test_vec[8] = {
    { SIMDE_FLOAT32_C(  -73.91),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -73.91), SIMDE_FLOAT32_C(  -73.91),
                         SIMDE_FLOAT32_C(  -73.91), SIMDE_FLOAT32_C(  -73.91),
                         SIMDE_FLOAT32_C(  -73.91), SIMDE_FLOAT32_C(  -73.91),
                         SIMDE_FLOAT32_C(  -73.91), SIMDE_FLOAT32_C(  -73.91)) },
    { SIMDE_FLOAT32_C(  953.36),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  953.36), SIMDE_FLOAT32_C(  953.36),
                         SIMDE_FLOAT32_C(  953.36), SIMDE_FLOAT32_C(  953.36),
                         SIMDE_FLOAT32_C(  953.36), SIMDE_FLOAT32_C(  953.36),
                         SIMDE_FLOAT32_C(  953.36), SIMDE_FLOAT32_C(  953.36)) },
    { SIMDE_FLOAT32_C(  888.18),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  888.18), SIMDE_FLOAT32_C(  888.18),
                         SIMDE_FLOAT32_C(  888.18), SIMDE_FLOAT32_C(  888.18),
                         SIMDE_FLOAT32_C(  888.18), SIMDE_FLOAT32_C(  888.18),
                         SIMDE_FLOAT32_C(  888.18), SIMDE_FLOAT32_C(  888.18)) },
    { SIMDE_FLOAT32_C(  232.71),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  232.71), SIMDE_FLOAT32_C(  232.71),
                         SIMDE_FLOAT32_C(  232.71), SIMDE_FLOAT32_C(  232.71),
                         SIMDE_FLOAT32_C(  232.71), SIMDE_FLOAT32_C(  232.71),
                         SIMDE_FLOAT32_C(  232.71), SIMDE_FLOAT32_C(  232.71)) },
    { SIMDE_FLOAT32_C( -598.38),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -598.38), SIMDE_FLOAT32_C( -598.38),
                         SIMDE_FLOAT32_C( -598.38), SIMDE_FLOAT32_C( -598.38),
                         SIMDE_FLOAT32_C( -598.38), SIMDE_FLOAT32_C( -598.38),
                         SIMDE_FLOAT32_C( -598.38), SIMDE_FLOAT32_C( -598.38)) },
    { SIMDE_FLOAT32_C(  762.88),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  762.88), SIMDE_FLOAT32_C(  762.88),
                         SIMDE_FLOAT32_C(  762.88), SIMDE_FLOAT32_C(  762.88),
                         SIMDE_FLOAT32_C(  762.88), SIMDE_FLOAT32_C(  762.88),
                         SIMDE_FLOAT32_C(  762.88), SIMDE_FLOAT32_C(  762.88)) },
    { SIMDE_FLOAT32_C( -225.89),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -225.89), SIMDE_FLOAT32_C( -225.89),
                         SIMDE_FLOAT32_C( -225.89), SIMDE_FLOAT32_C( -225.89),
                         SIMDE_FLOAT32_C( -225.89), SIMDE_FLOAT32_C( -225.89),
                         SIMDE_FLOAT32_C( -225.89), SIMDE_FLOAT32_C( -225.89)) },
    { SIMDE_FLOAT32_C( -115.32),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -115.32), SIMDE_FLOAT32_C( -115.32),
                         SIMDE_FLOAT32_C( -115.32), SIMDE_FLOAT32_C( -115.32),
                         SIMDE_FLOAT32_C( -115.32), SIMDE_FLOAT32_C( -115.32),
                         SIMDE_FLOAT32_C( -115.32), SIMDE_FLOAT32_C( -115.32)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_set1_ps(test_vec[i].a);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set1_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64 a;
    simde__m256d r;
  } test_vec[8] = {
    { SIMDE_FLOAT64_C( -494.25),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -494.25), SIMDE_FLOAT64_C( -494.25),
                         SIMDE_FLOAT64_C( -494.25), SIMDE_FLOAT64_C( -494.25)) },
    { SIMDE_FLOAT64_C(  610.20),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  610.20), SIMDE_FLOAT64_C(  610.20),
                         SIMDE_FLOAT64_C(  610.20), SIMDE_FLOAT64_C(  610.20)) },
    { SIMDE_FLOAT64_C( -471.35),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -471.35), SIMDE_FLOAT64_C( -471.35),
                         SIMDE_FLOAT64_C( -471.35), SIMDE_FLOAT64_C( -471.35)) },
    { SIMDE_FLOAT64_C( -211.28),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -211.28), SIMDE_FLOAT64_C( -211.28),
                         SIMDE_FLOAT64_C( -211.28), SIMDE_FLOAT64_C( -211.28)) },
    { SIMDE_FLOAT64_C(  -27.80),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -27.80), SIMDE_FLOAT64_C(  -27.80),
                         SIMDE_FLOAT64_C(  -27.80), SIMDE_FLOAT64_C(  -27.80)) },
    { SIMDE_FLOAT64_C(  866.02),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  866.02), SIMDE_FLOAT64_C(  866.02),
                         SIMDE_FLOAT64_C(  866.02), SIMDE_FLOAT64_C(  866.02)) },
    { SIMDE_FLOAT64_C( -278.22),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -278.22), SIMDE_FLOAT64_C( -278.22),
                         SIMDE_FLOAT64_C( -278.22), SIMDE_FLOAT64_C( -278.22)) },
    { SIMDE_FLOAT64_C(  868.90),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  868.90), SIMDE_FLOAT64_C(  868.90),
                         SIMDE_FLOAT64_C(  868.90), SIMDE_FLOAT64_C(  868.90)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_set1_pd(test_vec[i].a);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_add_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  770.99), SIMDE_FLOAT32_C(  104.99),
                         SIMDE_FLOAT32_C( -101.89), SIMDE_FLOAT32_C( -513.24),
                         SIMDE_FLOAT32_C( -417.43), SIMDE_FLOAT32_C( -288.54),
                         SIMDE_FLOAT32_C(  266.43), SIMDE_FLOAT32_C( -560.62)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  587.57), SIMDE_FLOAT32_C( -411.17),
                         SIMDE_FLOAT32_C(  235.43), SIMDE_FLOAT32_C(  663.07),
                         SIMDE_FLOAT32_C( -931.58), SIMDE_FLOAT32_C( -273.94),
                         SIMDE_FLOAT32_C( -824.43), SIMDE_FLOAT32_C(  308.33)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 1358.56), SIMDE_FLOAT32_C( -306.18),
                         SIMDE_FLOAT32_C(  133.54), SIMDE_FLOAT32_C(  149.83),
                         SIMDE_FLOAT32_C(-1349.01), SIMDE_FLOAT32_C( -562.48),
                         SIMDE_FLOAT32_C( -558.00), SIMDE_FLOAT32_C( -252.29)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -380.17), SIMDE_FLOAT32_C( -292.76),
                         SIMDE_FLOAT32_C(  -50.19), SIMDE_FLOAT32_C(  631.87),
                         SIMDE_FLOAT32_C(  407.07), SIMDE_FLOAT32_C(   82.94),
                         SIMDE_FLOAT32_C(  710.14), SIMDE_FLOAT32_C(  140.15)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  175.15), SIMDE_FLOAT32_C(  286.98),
                         SIMDE_FLOAT32_C(  813.95), SIMDE_FLOAT32_C( -881.68),
                         SIMDE_FLOAT32_C(  977.49), SIMDE_FLOAT32_C(  528.94),
                         SIMDE_FLOAT32_C(  994.01), SIMDE_FLOAT32_C(  529.37)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -205.02), SIMDE_FLOAT32_C(   -5.78),
                         SIMDE_FLOAT32_C(  763.76), SIMDE_FLOAT32_C( -249.81),
                         SIMDE_FLOAT32_C( 1384.56), SIMDE_FLOAT32_C(  611.88),
                         SIMDE_FLOAT32_C( 1704.15), SIMDE_FLOAT32_C(  669.52)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  160.16), SIMDE_FLOAT32_C(  875.39),
                         SIMDE_FLOAT32_C(  514.63), SIMDE_FLOAT32_C( -397.44),
                         SIMDE_FLOAT32_C(  299.15), SIMDE_FLOAT32_C( -674.71),
                         SIMDE_FLOAT32_C(  625.83), SIMDE_FLOAT32_C( -614.91)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -835.86), SIMDE_FLOAT32_C(  900.26),
                         SIMDE_FLOAT32_C(  485.80), SIMDE_FLOAT32_C( -508.14),
                         SIMDE_FLOAT32_C(  244.55), SIMDE_FLOAT32_C(  182.83),
                         SIMDE_FLOAT32_C(  -64.03), SIMDE_FLOAT32_C(    1.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -675.70), SIMDE_FLOAT32_C( 1775.65),
                         SIMDE_FLOAT32_C( 1000.43), SIMDE_FLOAT32_C( -905.58),
                         SIMDE_FLOAT32_C(  543.70), SIMDE_FLOAT32_C( -491.88),
                         SIMDE_FLOAT32_C(  561.80), SIMDE_FLOAT32_C( -613.60)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -699.57), SIMDE_FLOAT32_C(  489.63),
                         SIMDE_FLOAT32_C(  414.73), SIMDE_FLOAT32_C(  451.08),
                         SIMDE_FLOAT32_C( -926.15), SIMDE_FLOAT32_C( -146.45),
                         SIMDE_FLOAT32_C(  105.18), SIMDE_FLOAT32_C( -637.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -524.62), SIMDE_FLOAT32_C(   50.97),
                         SIMDE_FLOAT32_C(  -65.89), SIMDE_FLOAT32_C(  850.47),
                         SIMDE_FLOAT32_C(  952.97), SIMDE_FLOAT32_C( -408.81),
                         SIMDE_FLOAT32_C(  653.26), SIMDE_FLOAT32_C(  365.69)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-1224.19), SIMDE_FLOAT32_C(  540.60),
                         SIMDE_FLOAT32_C(  348.84), SIMDE_FLOAT32_C( 1301.55),
                         SIMDE_FLOAT32_C(   26.82), SIMDE_FLOAT32_C( -555.26),
                         SIMDE_FLOAT32_C(  758.44), SIMDE_FLOAT32_C( -272.19)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  185.82), SIMDE_FLOAT32_C(  -69.85),
                         SIMDE_FLOAT32_C( -529.83), SIMDE_FLOAT32_C(    7.18),
                         SIMDE_FLOAT32_C(  181.46), SIMDE_FLOAT32_C( -392.96),
                         SIMDE_FLOAT32_C( -825.54), SIMDE_FLOAT32_C(  -73.18)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -863.74), SIMDE_FLOAT32_C(  538.93),
                         SIMDE_FLOAT32_C(  867.32), SIMDE_FLOAT32_C( -263.67),
                         SIMDE_FLOAT32_C(   54.32), SIMDE_FLOAT32_C(  185.31),
                         SIMDE_FLOAT32_C( -761.42), SIMDE_FLOAT32_C( -272.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -677.92), SIMDE_FLOAT32_C(  469.08),
                         SIMDE_FLOAT32_C(  337.49), SIMDE_FLOAT32_C( -256.49),
                         SIMDE_FLOAT32_C(  235.78), SIMDE_FLOAT32_C( -207.65),
                         SIMDE_FLOAT32_C(-1586.96), SIMDE_FLOAT32_C( -345.41)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  693.17), SIMDE_FLOAT32_C( -668.89),
                         SIMDE_FLOAT32_C(  -84.19), SIMDE_FLOAT32_C( -965.81),
                         SIMDE_FLOAT32_C(   87.16), SIMDE_FLOAT32_C( -403.06),
                         SIMDE_FLOAT32_C(  609.16), SIMDE_FLOAT32_C( -596.97)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -8.20), SIMDE_FLOAT32_C(  127.25),
                         SIMDE_FLOAT32_C( -585.64), SIMDE_FLOAT32_C( -146.63),
                         SIMDE_FLOAT32_C(  610.52), SIMDE_FLOAT32_C(  318.25),
                         SIMDE_FLOAT32_C( -951.82), SIMDE_FLOAT32_C(   72.45)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  684.97), SIMDE_FLOAT32_C( -541.64),
                         SIMDE_FLOAT32_C( -669.83), SIMDE_FLOAT32_C(-1112.44),
                         SIMDE_FLOAT32_C(  697.68), SIMDE_FLOAT32_C(  -84.81),
                         SIMDE_FLOAT32_C( -342.66), SIMDE_FLOAT32_C( -524.52)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -894.89), SIMDE_FLOAT32_C(  538.71),
                         SIMDE_FLOAT32_C(  705.28), SIMDE_FLOAT32_C(  408.87),
                         SIMDE_FLOAT32_C(  595.54), SIMDE_FLOAT32_C(  916.74),
                         SIMDE_FLOAT32_C(  901.91), SIMDE_FLOAT32_C( -728.42)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -290.65), SIMDE_FLOAT32_C(  876.93),
                         SIMDE_FLOAT32_C(   99.14), SIMDE_FLOAT32_C(  948.23),
                         SIMDE_FLOAT32_C( -630.32), SIMDE_FLOAT32_C( -883.56),
                         SIMDE_FLOAT32_C(  844.54), SIMDE_FLOAT32_C(  507.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-1185.54), SIMDE_FLOAT32_C( 1415.64),
                         SIMDE_FLOAT32_C(  804.42), SIMDE_FLOAT32_C( 1357.10),
                         SIMDE_FLOAT32_C(  -34.78), SIMDE_FLOAT32_C(   33.18),
                         SIMDE_FLOAT32_C( 1746.45), SIMDE_FLOAT32_C( -221.32)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  126.73), SIMDE_FLOAT32_C( -250.52),
                         SIMDE_FLOAT32_C( -981.38), SIMDE_FLOAT32_C(  834.39),
                         SIMDE_FLOAT32_C(  -38.78), SIMDE_FLOAT32_C(  -35.08),
                         SIMDE_FLOAT32_C(  480.59), SIMDE_FLOAT32_C(  503.57)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -239.82), SIMDE_FLOAT32_C(   81.48),
                         SIMDE_FLOAT32_C( -961.01), SIMDE_FLOAT32_C( -408.34),
                         SIMDE_FLOAT32_C(  705.38), SIMDE_FLOAT32_C(   10.31),
                         SIMDE_FLOAT32_C(  562.97), SIMDE_FLOAT32_C(  952.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -113.09), SIMDE_FLOAT32_C( -169.04),
                         SIMDE_FLOAT32_C(-1942.39), SIMDE_FLOAT32_C(  426.05),
                         SIMDE_FLOAT32_C(  666.60), SIMDE_FLOAT32_C(  -24.77),
                         SIMDE_FLOAT32_C( 1043.56), SIMDE_FLOAT32_C( 1456.36)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_add_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_add_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  303.85), SIMDE_FLOAT64_C(  912.11),
                         SIMDE_FLOAT64_C( -650.18), SIMDE_FLOAT64_C(  473.98)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -109.04), SIMDE_FLOAT64_C( -576.86),
                         SIMDE_FLOAT64_C( -110.30), SIMDE_FLOAT64_C(  423.02)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  194.81), SIMDE_FLOAT64_C(  335.25),
                         SIMDE_FLOAT64_C( -760.48), SIMDE_FLOAT64_C(  897.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  979.21), SIMDE_FLOAT64_C(  275.57),
                         SIMDE_FLOAT64_C(  499.36), SIMDE_FLOAT64_C( -638.79)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  988.55), SIMDE_FLOAT64_C( -838.17),
                         SIMDE_FLOAT64_C( -141.00), SIMDE_FLOAT64_C( -264.15)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 1967.76), SIMDE_FLOAT64_C( -562.60),
                         SIMDE_FLOAT64_C(  358.36), SIMDE_FLOAT64_C( -902.94)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -601.88), SIMDE_FLOAT64_C(  830.35),
                         SIMDE_FLOAT64_C( -809.06), SIMDE_FLOAT64_C(  444.49)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -242.19), SIMDE_FLOAT64_C( -659.35),
                         SIMDE_FLOAT64_C(  783.96), SIMDE_FLOAT64_C( -941.55)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -844.07), SIMDE_FLOAT64_C(  171.00),
                         SIMDE_FLOAT64_C(  -25.10), SIMDE_FLOAT64_C( -497.06)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -183.86), SIMDE_FLOAT64_C( -913.99),
                         SIMDE_FLOAT64_C(  681.98), SIMDE_FLOAT64_C(  778.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -143.75), SIMDE_FLOAT64_C( -874.49),
                         SIMDE_FLOAT64_C(  158.94), SIMDE_FLOAT64_C(  168.19)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -327.61), SIMDE_FLOAT64_C(-1788.48),
                         SIMDE_FLOAT64_C(  840.92), SIMDE_FLOAT64_C(  946.49)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -46.65), SIMDE_FLOAT64_C( -996.47),
                         SIMDE_FLOAT64_C(  910.52), SIMDE_FLOAT64_C( -114.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  749.53), SIMDE_FLOAT64_C(  540.86),
                         SIMDE_FLOAT64_C(   64.91), SIMDE_FLOAT64_C( -347.42)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  702.88), SIMDE_FLOAT64_C( -455.61),
                         SIMDE_FLOAT64_C(  975.43), SIMDE_FLOAT64_C( -461.62)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -739.61), SIMDE_FLOAT64_C(  573.43),
                         SIMDE_FLOAT64_C(  552.79), SIMDE_FLOAT64_C( -374.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -947.01), SIMDE_FLOAT64_C(  120.02),
                         SIMDE_FLOAT64_C(  463.99), SIMDE_FLOAT64_C(   50.32)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1686.62), SIMDE_FLOAT64_C(  693.45),
                         SIMDE_FLOAT64_C( 1016.78), SIMDE_FLOAT64_C( -323.99)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -187.57), SIMDE_FLOAT64_C(  -62.04),
                         SIMDE_FLOAT64_C(  957.24), SIMDE_FLOAT64_C(  581.23)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  950.16), SIMDE_FLOAT64_C(  298.02),
                         SIMDE_FLOAT64_C(  203.94), SIMDE_FLOAT64_C( -826.89)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  762.59), SIMDE_FLOAT64_C(  235.98),
                         SIMDE_FLOAT64_C( 1161.18), SIMDE_FLOAT64_C( -245.66)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  612.20), SIMDE_FLOAT64_C(  556.68),
                         SIMDE_FLOAT64_C(  158.92), SIMDE_FLOAT64_C(  158.42)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   66.07), SIMDE_FLOAT64_C( -695.86),
                         SIMDE_FLOAT64_C(  940.17), SIMDE_FLOAT64_C(  935.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  678.27), SIMDE_FLOAT64_C( -139.18),
                         SIMDE_FLOAT64_C( 1099.09), SIMDE_FLOAT64_C( 1093.62)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_add_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_addsub_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -665.97), SIMDE_FLOAT32_C( -119.17),
                         SIMDE_FLOAT32_C(   98.44), SIMDE_FLOAT32_C( -870.79),
                         SIMDE_FLOAT32_C(  715.06), SIMDE_FLOAT32_C(  168.23),
                         SIMDE_FLOAT32_C(  291.85), SIMDE_FLOAT32_C(  803.77)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  437.26), SIMDE_FLOAT32_C(  621.28),
                         SIMDE_FLOAT32_C(  727.27), SIMDE_FLOAT32_C( -902.73),
                         SIMDE_FLOAT32_C( -279.74), SIMDE_FLOAT32_C(  960.47),
                         SIMDE_FLOAT32_C( -437.81), SIMDE_FLOAT32_C(  516.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -228.71), SIMDE_FLOAT32_C( -740.45),
                         SIMDE_FLOAT32_C(  825.71), SIMDE_FLOAT32_C(   31.94),
                         SIMDE_FLOAT32_C(  435.32), SIMDE_FLOAT32_C( -792.24),
                         SIMDE_FLOAT32_C( -145.96), SIMDE_FLOAT32_C(  287.46)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -441.72), SIMDE_FLOAT32_C(  881.45),
                         SIMDE_FLOAT32_C(  512.79), SIMDE_FLOAT32_C( -201.00),
                         SIMDE_FLOAT32_C(  709.10), SIMDE_FLOAT32_C(  130.51),
                         SIMDE_FLOAT32_C( -836.20), SIMDE_FLOAT32_C(  276.45)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -410.67), SIMDE_FLOAT32_C(  408.11),
                         SIMDE_FLOAT32_C( -371.59), SIMDE_FLOAT32_C( -135.76),
                         SIMDE_FLOAT32_C( -896.75), SIMDE_FLOAT32_C( -185.21),
                         SIMDE_FLOAT32_C( -154.35), SIMDE_FLOAT32_C( -995.14)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -852.39), SIMDE_FLOAT32_C(  473.34),
                         SIMDE_FLOAT32_C(  141.20), SIMDE_FLOAT32_C(  -65.24),
                         SIMDE_FLOAT32_C( -187.65), SIMDE_FLOAT32_C(  315.72),
                         SIMDE_FLOAT32_C( -990.55), SIMDE_FLOAT32_C( 1271.59)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  792.33), SIMDE_FLOAT32_C( -677.48),
                         SIMDE_FLOAT32_C(  -78.97), SIMDE_FLOAT32_C(  595.95),
                         SIMDE_FLOAT32_C(  441.86), SIMDE_FLOAT32_C(  221.91),
                         SIMDE_FLOAT32_C(  688.66), SIMDE_FLOAT32_C( -937.21)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  615.36), SIMDE_FLOAT32_C( -858.28),
                         SIMDE_FLOAT32_C(  102.87), SIMDE_FLOAT32_C( -380.97),
                         SIMDE_FLOAT32_C( -155.81), SIMDE_FLOAT32_C( -426.12),
                         SIMDE_FLOAT32_C( -862.23), SIMDE_FLOAT32_C( -891.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 1407.69), SIMDE_FLOAT32_C(  180.80),
                         SIMDE_FLOAT32_C(   23.90), SIMDE_FLOAT32_C(  976.92),
                         SIMDE_FLOAT32_C(  286.05), SIMDE_FLOAT32_C(  648.03),
                         SIMDE_FLOAT32_C( -173.57), SIMDE_FLOAT32_C(  -45.90)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -493.40), SIMDE_FLOAT32_C( -257.06),
                         SIMDE_FLOAT32_C( -968.46), SIMDE_FLOAT32_C(  634.36),
                         SIMDE_FLOAT32_C( -600.69), SIMDE_FLOAT32_C( -769.31),
                         SIMDE_FLOAT32_C(  230.22), SIMDE_FLOAT32_C( -863.68)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -678.13), SIMDE_FLOAT32_C(  166.99),
                         SIMDE_FLOAT32_C(  125.37), SIMDE_FLOAT32_C( -846.30),
                         SIMDE_FLOAT32_C(  414.00), SIMDE_FLOAT32_C( -144.57),
                         SIMDE_FLOAT32_C(  -43.08), SIMDE_FLOAT32_C(  287.75)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-1171.53), SIMDE_FLOAT32_C( -424.05),
                         SIMDE_FLOAT32_C( -843.09), SIMDE_FLOAT32_C( 1480.66),
                         SIMDE_FLOAT32_C( -186.69), SIMDE_FLOAT32_C( -624.74),
                         SIMDE_FLOAT32_C(  187.14), SIMDE_FLOAT32_C(-1151.43)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -449.73), SIMDE_FLOAT32_C( -350.27),
                         SIMDE_FLOAT32_C( -591.20), SIMDE_FLOAT32_C(  571.44),
                         SIMDE_FLOAT32_C(  787.95), SIMDE_FLOAT32_C(  514.78),
                         SIMDE_FLOAT32_C( -355.32), SIMDE_FLOAT32_C(  545.86)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  341.77), SIMDE_FLOAT32_C( -839.01),
                         SIMDE_FLOAT32_C(   -9.88), SIMDE_FLOAT32_C(  193.01),
                         SIMDE_FLOAT32_C(  871.45), SIMDE_FLOAT32_C( -840.06),
                         SIMDE_FLOAT32_C(  689.52), SIMDE_FLOAT32_C( -902.32)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -107.96), SIMDE_FLOAT32_C(  488.74),
                         SIMDE_FLOAT32_C( -601.08), SIMDE_FLOAT32_C(  378.43),
                         SIMDE_FLOAT32_C( 1659.40), SIMDE_FLOAT32_C( 1354.84),
                         SIMDE_FLOAT32_C(  334.20), SIMDE_FLOAT32_C( 1448.18)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -336.63), SIMDE_FLOAT32_C(  960.76),
                         SIMDE_FLOAT32_C(  657.64), SIMDE_FLOAT32_C( -548.45),
                         SIMDE_FLOAT32_C( -101.48), SIMDE_FLOAT32_C( -271.70),
                         SIMDE_FLOAT32_C(   23.46), SIMDE_FLOAT32_C(  562.46)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -564.95), SIMDE_FLOAT32_C( -418.72),
                         SIMDE_FLOAT32_C( -693.90), SIMDE_FLOAT32_C( -314.48),
                         SIMDE_FLOAT32_C( -760.76), SIMDE_FLOAT32_C(    7.61),
                         SIMDE_FLOAT32_C(  228.32), SIMDE_FLOAT32_C( -230.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -901.58), SIMDE_FLOAT32_C( 1379.48),
                         SIMDE_FLOAT32_C(  -36.26), SIMDE_FLOAT32_C( -233.97),
                         SIMDE_FLOAT32_C( -862.24), SIMDE_FLOAT32_C( -279.31),
                         SIMDE_FLOAT32_C(  251.78), SIMDE_FLOAT32_C(  792.77)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -451.91), SIMDE_FLOAT32_C( -184.14),
                         SIMDE_FLOAT32_C( -772.77), SIMDE_FLOAT32_C( -278.00),
                         SIMDE_FLOAT32_C( -640.89), SIMDE_FLOAT32_C(  -35.35),
                         SIMDE_FLOAT32_C( -518.18), SIMDE_FLOAT32_C( -851.69)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -152.24), SIMDE_FLOAT32_C(  636.58),
                         SIMDE_FLOAT32_C( -808.67), SIMDE_FLOAT32_C(  166.94),
                         SIMDE_FLOAT32_C( -359.45), SIMDE_FLOAT32_C( -888.48),
                         SIMDE_FLOAT32_C( -553.07), SIMDE_FLOAT32_C( -570.58)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -604.15), SIMDE_FLOAT32_C( -820.72),
                         SIMDE_FLOAT32_C(-1581.44), SIMDE_FLOAT32_C( -444.94),
                         SIMDE_FLOAT32_C(-1000.34), SIMDE_FLOAT32_C(  853.13),
                         SIMDE_FLOAT32_C(-1071.25), SIMDE_FLOAT32_C( -281.11)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -3.71), SIMDE_FLOAT32_C( -782.28),
                         SIMDE_FLOAT32_C(  533.36), SIMDE_FLOAT32_C(  848.42),
                         SIMDE_FLOAT32_C(  345.49), SIMDE_FLOAT32_C( -110.04),
                         SIMDE_FLOAT32_C( -550.91), SIMDE_FLOAT32_C(   -5.89)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  186.13), SIMDE_FLOAT32_C( -310.95),
                         SIMDE_FLOAT32_C(  742.56), SIMDE_FLOAT32_C( -943.39),
                         SIMDE_FLOAT32_C( -294.98), SIMDE_FLOAT32_C( -455.35),
                         SIMDE_FLOAT32_C(  262.46), SIMDE_FLOAT32_C(  299.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  182.42), SIMDE_FLOAT32_C( -471.33),
                         SIMDE_FLOAT32_C( 1275.92), SIMDE_FLOAT32_C( 1791.81),
                         SIMDE_FLOAT32_C(   50.51), SIMDE_FLOAT32_C(  345.31),
                         SIMDE_FLOAT32_C( -288.45), SIMDE_FLOAT32_C( -305.06)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_addsub_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_addsub_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  715.06), SIMDE_FLOAT64_C(  168.23),
                         SIMDE_FLOAT64_C(  291.85), SIMDE_FLOAT64_C(  803.77)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -279.74), SIMDE_FLOAT64_C(  960.47),
                         SIMDE_FLOAT64_C( -437.81), SIMDE_FLOAT64_C(  516.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  435.32), SIMDE_FLOAT64_C( -792.24),
                         SIMDE_FLOAT64_C( -145.96), SIMDE_FLOAT64_C(  287.46)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -665.97), SIMDE_FLOAT64_C( -119.17),
                         SIMDE_FLOAT64_C(   98.44), SIMDE_FLOAT64_C( -870.79)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  437.26), SIMDE_FLOAT64_C(  621.28),
                         SIMDE_FLOAT64_C(  727.27), SIMDE_FLOAT64_C( -902.73)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -228.71), SIMDE_FLOAT64_C( -740.45),
                         SIMDE_FLOAT64_C(  825.71), SIMDE_FLOAT64_C(   31.94)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  709.10), SIMDE_FLOAT64_C(  130.51),
                         SIMDE_FLOAT64_C( -836.20), SIMDE_FLOAT64_C(  276.45)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -896.75), SIMDE_FLOAT64_C( -185.21),
                         SIMDE_FLOAT64_C( -154.35), SIMDE_FLOAT64_C( -995.14)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -187.65), SIMDE_FLOAT64_C(  315.72),
                         SIMDE_FLOAT64_C( -990.55), SIMDE_FLOAT64_C( 1271.59)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -441.72), SIMDE_FLOAT64_C(  881.45),
                         SIMDE_FLOAT64_C(  512.79), SIMDE_FLOAT64_C( -201.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -410.67), SIMDE_FLOAT64_C(  408.11),
                         SIMDE_FLOAT64_C( -371.59), SIMDE_FLOAT64_C( -135.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -852.39), SIMDE_FLOAT64_C(  473.34),
                         SIMDE_FLOAT64_C(  141.20), SIMDE_FLOAT64_C(  -65.24)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  441.86), SIMDE_FLOAT64_C(  221.91),
                         SIMDE_FLOAT64_C(  688.66), SIMDE_FLOAT64_C( -937.21)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -155.81), SIMDE_FLOAT64_C( -426.12),
                         SIMDE_FLOAT64_C( -862.23), SIMDE_FLOAT64_C( -891.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  286.05), SIMDE_FLOAT64_C(  648.03),
                         SIMDE_FLOAT64_C( -173.57), SIMDE_FLOAT64_C(  -45.90)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  792.33), SIMDE_FLOAT64_C( -677.48),
                         SIMDE_FLOAT64_C(  -78.97), SIMDE_FLOAT64_C(  595.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  615.36), SIMDE_FLOAT64_C( -858.28),
                         SIMDE_FLOAT64_C(  102.87), SIMDE_FLOAT64_C( -380.97)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 1407.69), SIMDE_FLOAT64_C(  180.80),
                         SIMDE_FLOAT64_C(   23.90), SIMDE_FLOAT64_C(  976.92)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -600.69), SIMDE_FLOAT64_C( -769.31),
                         SIMDE_FLOAT64_C(  230.22), SIMDE_FLOAT64_C( -863.68)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  414.00), SIMDE_FLOAT64_C( -144.57),
                         SIMDE_FLOAT64_C(  -43.08), SIMDE_FLOAT64_C(  287.75)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -186.69), SIMDE_FLOAT64_C( -624.74),
                         SIMDE_FLOAT64_C(  187.14), SIMDE_FLOAT64_C(-1151.43)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -493.40), SIMDE_FLOAT64_C( -257.06),
                         SIMDE_FLOAT64_C( -968.46), SIMDE_FLOAT64_C(  634.36)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -678.13), SIMDE_FLOAT64_C(  166.99),
                         SIMDE_FLOAT64_C(  125.37), SIMDE_FLOAT64_C( -846.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1171.53), SIMDE_FLOAT64_C( -424.05),
                         SIMDE_FLOAT64_C( -843.09), SIMDE_FLOAT64_C( 1480.66)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_addsub_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_and_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -927.26), SIMDE_FLOAT32_C( -802.03),
                         SIMDE_FLOAT32_C( -266.41), SIMDE_FLOAT32_C(  -50.41),
                         SIMDE_FLOAT32_C( -309.19), SIMDE_FLOAT32_C( -707.19),
                         SIMDE_FLOAT32_C( -220.07), SIMDE_FLOAT32_C(  127.67)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -205.91), SIMDE_FLOAT32_C( -275.07),
                         SIMDE_FLOAT32_C(  -13.57), SIMDE_FLOAT32_C(  990.91),
                         SIMDE_FLOAT32_C( -167.84), SIMDE_FLOAT32_C(  346.85),
                         SIMDE_FLOAT32_C(  124.29), SIMDE_FLOAT32_C(  759.96)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -3.09), SIMDE_FLOAT32_C(   -2.13),
                         SIMDE_FLOAT32_C(   -8.07), SIMDE_FLOAT32_C(    3.03),
                         SIMDE_FLOAT32_C( -130.56), SIMDE_FLOAT32_C(    2.50),
                         SIMDE_FLOAT32_C(   54.02), SIMDE_FLOAT32_C(    2.96)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -39.85), SIMDE_FLOAT32_C(  325.28),
                         SIMDE_FLOAT32_C(  658.09), SIMDE_FLOAT32_C(  797.01),
                         SIMDE_FLOAT32_C( -512.38), SIMDE_FLOAT32_C( -352.93),
                         SIMDE_FLOAT32_C( -357.04), SIMDE_FLOAT32_C( -456.94)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -802.91), SIMDE_FLOAT32_C(  574.48),
                         SIMDE_FLOAT32_C( -277.42), SIMDE_FLOAT32_C(  470.68),
                         SIMDE_FLOAT32_C( -575.30), SIMDE_FLOAT32_C(  -85.17),
                         SIMDE_FLOAT32_C(  928.67), SIMDE_FLOAT32_C(  878.11)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -2.13), SIMDE_FLOAT32_C(    2.04),
                         SIMDE_FLOAT32_C(    2.01), SIMDE_FLOAT32_C(    3.05),
                         SIMDE_FLOAT32_C( -512.25), SIMDE_FLOAT32_C(  -80.17),
                         SIMDE_FLOAT32_C(    2.50), SIMDE_FLOAT32_C(    3.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  758.85), SIMDE_FLOAT32_C(  749.41),
                         SIMDE_FLOAT32_C(  129.33), SIMDE_FLOAT32_C( -389.28),
                         SIMDE_FLOAT32_C( -248.13), SIMDE_FLOAT32_C(  236.41),
                         SIMDE_FLOAT32_C(  416.63), SIMDE_FLOAT32_C( -413.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -615.54), SIMDE_FLOAT32_C(  496.18),
                         SIMDE_FLOAT32_C( -485.54), SIMDE_FLOAT32_C( -818.26),
                         SIMDE_FLOAT32_C( -139.14), SIMDE_FLOAT32_C(  955.99),
                         SIMDE_FLOAT32_C(  356.33), SIMDE_FLOAT32_C( -498.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  614.53), SIMDE_FLOAT32_C(    2.88),
                         SIMDE_FLOAT32_C(  128.27), SIMDE_FLOAT32_C(   -3.01),
                         SIMDE_FLOAT32_C( -136.13), SIMDE_FLOAT32_C(    3.69),
                         SIMDE_FLOAT32_C(  288.00), SIMDE_FLOAT32_C( -400.79)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -131.10), SIMDE_FLOAT32_C( -368.55),
                         SIMDE_FLOAT32_C(  657.24), SIMDE_FLOAT32_C(  939.62),
                         SIMDE_FLOAT32_C(  -50.98), SIMDE_FLOAT32_C(  313.56),
                         SIMDE_FLOAT32_C( -914.58), SIMDE_FLOAT32_C(  -29.59)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -195.92), SIMDE_FLOAT32_C( -475.65),
                         SIMDE_FLOAT32_C( -524.29), SIMDE_FLOAT32_C(  537.04),
                         SIMDE_FLOAT32_C( -280.43), SIMDE_FLOAT32_C(  379.54),
                         SIMDE_FLOAT32_C(  -38.50), SIMDE_FLOAT32_C( -188.05)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -131.04), SIMDE_FLOAT32_C( -336.52),
                         SIMDE_FLOAT32_C(  512.03), SIMDE_FLOAT32_C(  521.04),
                         SIMDE_FLOAT32_C(  -34.03), SIMDE_FLOAT32_C(  313.54),
                         SIMDE_FLOAT32_C(   -2.00), SIMDE_FLOAT32_C(  -10.75)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  159.88), SIMDE_FLOAT32_C( -559.41),
                         SIMDE_FLOAT32_C(  -99.24), SIMDE_FLOAT32_C( -420.50),
                         SIMDE_FLOAT32_C( -953.72), SIMDE_FLOAT32_C(  849.74),
                         SIMDE_FLOAT32_C(   80.27), SIMDE_FLOAT32_C(  -41.97)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  457.08), SIMDE_FLOAT32_C( -505.60),
                         SIMDE_FLOAT32_C( -390.51), SIMDE_FLOAT32_C( -524.68),
                         SIMDE_FLOAT32_C( -419.12), SIMDE_FLOAT32_C(  955.42),
                         SIMDE_FLOAT32_C(  180.08), SIMDE_FLOAT32_C(   33.67)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  132.50), SIMDE_FLOAT32_C(   -2.14),
                         SIMDE_FLOAT32_C(  -97.13), SIMDE_FLOAT32_C(   -2.03),
                         SIMDE_FLOAT32_C(   -3.00), SIMDE_FLOAT32_C(  785.16),
                         SIMDE_FLOAT32_C(   40.00), SIMDE_FLOAT32_C(   33.66)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  157.14), SIMDE_FLOAT32_C( -391.25),
                         SIMDE_FLOAT32_C( -362.22), SIMDE_FLOAT32_C( -137.98),
                         SIMDE_FLOAT32_C( -303.90), SIMDE_FLOAT32_C(  545.52),
                         SIMDE_FLOAT32_C( -383.06), SIMDE_FLOAT32_C(  973.73)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -973.80), SIMDE_FLOAT32_C(  457.53),
                         SIMDE_FLOAT32_C( -199.04), SIMDE_FLOAT32_C(  856.68),
                         SIMDE_FLOAT32_C( -830.67), SIMDE_FLOAT32_C( -121.42),
                         SIMDE_FLOAT32_C(  772.32), SIMDE_FLOAT32_C(  704.39)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    2.27), SIMDE_FLOAT32_C(  385.00),
                         SIMDE_FLOAT32_C( -133.03), SIMDE_FLOAT32_C(    2.00),
                         SIMDE_FLOAT32_C(   -2.12), SIMDE_FLOAT32_C(    2.00),
                         SIMDE_FLOAT32_C(    2.02), SIMDE_FLOAT32_C(  704.14)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  942.14), SIMDE_FLOAT32_C(  176.96),
                         SIMDE_FLOAT32_C(  525.37), SIMDE_FLOAT32_C(  924.18),
                         SIMDE_FLOAT32_C( -300.50), SIMDE_FLOAT32_C( -450.02),
                         SIMDE_FLOAT32_C(  708.11), SIMDE_FLOAT32_C(  742.76)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  647.68), SIMDE_FLOAT32_C(  632.57),
                         SIMDE_FLOAT32_C( -972.04), SIMDE_FLOAT32_C( -483.76),
                         SIMDE_FLOAT32_C(  274.26), SIMDE_FLOAT32_C(  570.79),
                         SIMDE_FLOAT32_C( -945.60), SIMDE_FLOAT32_C( -519.05)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  646.13), SIMDE_FLOAT32_C(    2.25),
                         SIMDE_FLOAT32_C(  524.04), SIMDE_FLOAT32_C(    3.52),
                         SIMDE_FLOAT32_C(  256.00), SIMDE_FLOAT32_C(    2.00),
                         SIMDE_FLOAT32_C(  640.09), SIMDE_FLOAT32_C(  518.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  361.93), SIMDE_FLOAT32_C( -223.38),
                         SIMDE_FLOAT32_C(  -51.19), SIMDE_FLOAT32_C( -300.56),
                         SIMDE_FLOAT32_C(  363.29), SIMDE_FLOAT32_C(  804.04),
                         SIMDE_FLOAT32_C(   99.54), SIMDE_FLOAT32_C( -622.58)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  446.79), SIMDE_FLOAT32_C(  300.89),
                         SIMDE_FLOAT32_C(  727.13), SIMDE_FLOAT32_C( -671.93),
                         SIMDE_FLOAT32_C(  708.76), SIMDE_FLOAT32_C( -834.24),
                         SIMDE_FLOAT32_C( -881.82), SIMDE_FLOAT32_C(  430.54)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  296.79), SIMDE_FLOAT32_C(  150.38),
                         SIMDE_FLOAT32_C(    2.07), SIMDE_FLOAT32_C(   -2.10),
                         SIMDE_FLOAT32_C(    2.77), SIMDE_FLOAT32_C(  768.03),
                         SIMDE_FLOAT32_C(    3.06), SIMDE_FLOAT32_C(    2.30)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_and_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_and_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -309.19), SIMDE_FLOAT64_C( -707.19),
                         SIMDE_FLOAT64_C( -220.07), SIMDE_FLOAT64_C(  127.67)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -167.84), SIMDE_FLOAT64_C(  346.85),
                         SIMDE_FLOAT64_C(  124.29), SIMDE_FLOAT64_C(  759.96)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -130.56), SIMDE_FLOAT64_C(    2.50),
                         SIMDE_FLOAT64_C(   54.02), SIMDE_FLOAT64_C(    2.96)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -927.26), SIMDE_FLOAT64_C( -802.03),
                         SIMDE_FLOAT64_C( -266.41), SIMDE_FLOAT64_C(  -50.41)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -205.91), SIMDE_FLOAT64_C( -275.07),
                         SIMDE_FLOAT64_C(  -13.57), SIMDE_FLOAT64_C(  990.91)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -3.09), SIMDE_FLOAT64_C(   -2.13),
                         SIMDE_FLOAT64_C(   -8.07), SIMDE_FLOAT64_C(    3.03)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -512.38), SIMDE_FLOAT64_C( -352.93),
                         SIMDE_FLOAT64_C( -357.04), SIMDE_FLOAT64_C( -456.94)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -575.30), SIMDE_FLOAT64_C(  -85.17),
                         SIMDE_FLOAT64_C(  928.67), SIMDE_FLOAT64_C(  878.11)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -512.25), SIMDE_FLOAT64_C(  -80.17),
                         SIMDE_FLOAT64_C(    2.50), SIMDE_FLOAT64_C(    3.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -39.85), SIMDE_FLOAT64_C(  325.28),
                         SIMDE_FLOAT64_C(  658.09), SIMDE_FLOAT64_C(  797.01)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -802.91), SIMDE_FLOAT64_C(  574.48),
                         SIMDE_FLOAT64_C( -277.42), SIMDE_FLOAT64_C(  470.68)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -2.13), SIMDE_FLOAT64_C(    2.04),
                         SIMDE_FLOAT64_C(    2.01), SIMDE_FLOAT64_C(    3.05)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -248.13), SIMDE_FLOAT64_C(  236.41),
                         SIMDE_FLOAT64_C(  416.63), SIMDE_FLOAT64_C( -413.79)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -139.14), SIMDE_FLOAT64_C(  955.99),
                         SIMDE_FLOAT64_C(  356.33), SIMDE_FLOAT64_C( -498.79)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -136.13), SIMDE_FLOAT64_C(    3.69),
                         SIMDE_FLOAT64_C(  288.00), SIMDE_FLOAT64_C( -400.79)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  758.85), SIMDE_FLOAT64_C(  749.41),
                         SIMDE_FLOAT64_C(  129.33), SIMDE_FLOAT64_C( -389.28)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -615.54), SIMDE_FLOAT64_C(  496.18),
                         SIMDE_FLOAT64_C( -485.54), SIMDE_FLOAT64_C( -818.26)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  614.53), SIMDE_FLOAT64_C(    2.88),
                         SIMDE_FLOAT64_C(  128.27), SIMDE_FLOAT64_C(   -3.01)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -50.98), SIMDE_FLOAT64_C(  313.56),
                         SIMDE_FLOAT64_C( -914.58), SIMDE_FLOAT64_C(  -29.59)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -280.43), SIMDE_FLOAT64_C(  379.54),
                         SIMDE_FLOAT64_C(  -38.50), SIMDE_FLOAT64_C( -188.05)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -34.03), SIMDE_FLOAT64_C(  313.54),
                         SIMDE_FLOAT64_C(   -2.00), SIMDE_FLOAT64_C(  -10.75)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -131.10), SIMDE_FLOAT64_C( -368.55),
                         SIMDE_FLOAT64_C(  657.24), SIMDE_FLOAT64_C(  939.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -195.92), SIMDE_FLOAT64_C( -475.65),
                         SIMDE_FLOAT64_C( -524.29), SIMDE_FLOAT64_C(  537.04)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -131.04), SIMDE_FLOAT64_C( -336.52),
                         SIMDE_FLOAT64_C(  512.03), SIMDE_FLOAT64_C(  521.04)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_and_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_blend_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   61.35), SIMDE_FLOAT32_C(  540.33),
                         SIMDE_FLOAT32_C( -888.48), SIMDE_FLOAT32_C(  570.09),
                         SIMDE_FLOAT32_C(  312.02), SIMDE_FLOAT32_C( -960.46),
                         SIMDE_FLOAT32_C( -440.55), SIMDE_FLOAT32_C( -796.55)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -286.42), SIMDE_FLOAT32_C( -835.51),
                         SIMDE_FLOAT32_C(  177.42), SIMDE_FLOAT32_C(  142.03),
                         SIMDE_FLOAT32_C(  501.36), SIMDE_FLOAT32_C( -894.74),
                         SIMDE_FLOAT32_C( -798.77), SIMDE_FLOAT32_C(  511.25)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   61.35), SIMDE_FLOAT32_C(  540.33),
                         SIMDE_FLOAT32_C( -888.48), SIMDE_FLOAT32_C(  570.09),
                         SIMDE_FLOAT32_C(  501.36), SIMDE_FLOAT32_C( -894.74),
                         SIMDE_FLOAT32_C( -440.55), SIMDE_FLOAT32_C(  511.25)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  783.21), SIMDE_FLOAT32_C(  251.09),
                         SIMDE_FLOAT32_C( -929.85), SIMDE_FLOAT32_C( -378.97),
                         SIMDE_FLOAT32_C(  496.83), SIMDE_FLOAT32_C( -643.84),
                         SIMDE_FLOAT32_C( -785.45), SIMDE_FLOAT32_C( -676.85)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  375.42), SIMDE_FLOAT32_C( -689.69),
                         SIMDE_FLOAT32_C(  240.54), SIMDE_FLOAT32_C( -955.13),
                         SIMDE_FLOAT32_C(   82.52), SIMDE_FLOAT32_C(  210.36),
                         SIMDE_FLOAT32_C(  621.75), SIMDE_FLOAT32_C( -780.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  783.21), SIMDE_FLOAT32_C(  251.09),
                         SIMDE_FLOAT32_C( -929.85), SIMDE_FLOAT32_C( -378.97),
                         SIMDE_FLOAT32_C(   82.52), SIMDE_FLOAT32_C(  210.36),
                         SIMDE_FLOAT32_C( -785.45), SIMDE_FLOAT32_C( -780.72)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -747.80), SIMDE_FLOAT32_C( -376.86),
                         SIMDE_FLOAT32_C(  238.38), SIMDE_FLOAT32_C( -668.84),
                         SIMDE_FLOAT32_C(  238.09), SIMDE_FLOAT32_C(  936.53),
                         SIMDE_FLOAT32_C( -693.41), SIMDE_FLOAT32_C( -381.56)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   83.85), SIMDE_FLOAT32_C(  559.24),
                         SIMDE_FLOAT32_C( -896.35), SIMDE_FLOAT32_C(  225.46),
                         SIMDE_FLOAT32_C( -243.15), SIMDE_FLOAT32_C( -714.74),
                         SIMDE_FLOAT32_C(  388.91), SIMDE_FLOAT32_C(  608.15)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -747.80), SIMDE_FLOAT32_C( -376.86),
                         SIMDE_FLOAT32_C(  238.38), SIMDE_FLOAT32_C( -668.84),
                         SIMDE_FLOAT32_C( -243.15), SIMDE_FLOAT32_C( -714.74),
                         SIMDE_FLOAT32_C( -693.41), SIMDE_FLOAT32_C(  608.15)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    1.67), SIMDE_FLOAT32_C( -361.23),
                         SIMDE_FLOAT32_C(  362.97), SIMDE_FLOAT32_C( -860.62),
                         SIMDE_FLOAT32_C(  518.00), SIMDE_FLOAT32_C(  985.53),
                         SIMDE_FLOAT32_C(  -40.74), SIMDE_FLOAT32_C(  246.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  236.67), SIMDE_FLOAT32_C( -133.38),
                         SIMDE_FLOAT32_C( -240.09), SIMDE_FLOAT32_C(  681.13),
                         SIMDE_FLOAT32_C( -437.53), SIMDE_FLOAT32_C(  645.53),
                         SIMDE_FLOAT32_C(  472.51), SIMDE_FLOAT32_C(   30.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    1.67), SIMDE_FLOAT32_C( -361.23),
                         SIMDE_FLOAT32_C(  362.97), SIMDE_FLOAT32_C( -860.62),
                         SIMDE_FLOAT32_C( -437.53), SIMDE_FLOAT32_C(  645.53),
                         SIMDE_FLOAT32_C(  -40.74), SIMDE_FLOAT32_C(   30.02)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -759.07), SIMDE_FLOAT32_C(  240.96),
                         SIMDE_FLOAT32_C( -743.41), SIMDE_FLOAT32_C( -766.95),
                         SIMDE_FLOAT32_C( -733.55), SIMDE_FLOAT32_C( -798.68),
                         SIMDE_FLOAT32_C( -189.75), SIMDE_FLOAT32_C( -424.58)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -396.91), SIMDE_FLOAT32_C(  509.13),
                         SIMDE_FLOAT32_C(  462.02), SIMDE_FLOAT32_C(  520.45),
                         SIMDE_FLOAT32_C(  948.24), SIMDE_FLOAT32_C(  730.18),
                         SIMDE_FLOAT32_C( -709.02), SIMDE_FLOAT32_C( -858.64)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -759.07), SIMDE_FLOAT32_C(  240.96),
                         SIMDE_FLOAT32_C( -743.41), SIMDE_FLOAT32_C( -766.95),
                         SIMDE_FLOAT32_C(  948.24), SIMDE_FLOAT32_C(  730.18),
                         SIMDE_FLOAT32_C( -189.75), SIMDE_FLOAT32_C( -858.64)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  624.31), SIMDE_FLOAT32_C(  375.12),
                         SIMDE_FLOAT32_C(  629.27), SIMDE_FLOAT32_C(  901.24),
                         SIMDE_FLOAT32_C( -896.96), SIMDE_FLOAT32_C( -769.47),
                         SIMDE_FLOAT32_C(  452.93), SIMDE_FLOAT32_C( -251.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -148.06), SIMDE_FLOAT32_C( -474.61),
                         SIMDE_FLOAT32_C( -146.01), SIMDE_FLOAT32_C( -955.67),
                         SIMDE_FLOAT32_C(  931.60), SIMDE_FLOAT32_C( -773.07),
                         SIMDE_FLOAT32_C(  626.99), SIMDE_FLOAT32_C(  431.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  624.31), SIMDE_FLOAT32_C(  375.12),
                         SIMDE_FLOAT32_C(  629.27), SIMDE_FLOAT32_C(  901.24),
                         SIMDE_FLOAT32_C(  931.60), SIMDE_FLOAT32_C( -773.07),
                         SIMDE_FLOAT32_C(  452.93), SIMDE_FLOAT32_C(  431.72)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -812.40), SIMDE_FLOAT32_C( -551.18),
                         SIMDE_FLOAT32_C(  389.71), SIMDE_FLOAT32_C(  667.74),
                         SIMDE_FLOAT32_C(   -2.37), SIMDE_FLOAT32_C( -129.53),
                         SIMDE_FLOAT32_C(  860.16), SIMDE_FLOAT32_C(  760.95)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -172.95), SIMDE_FLOAT32_C( -591.71),
                         SIMDE_FLOAT32_C( -137.29), SIMDE_FLOAT32_C( -689.63),
                         SIMDE_FLOAT32_C(  644.48), SIMDE_FLOAT32_C(  859.03),
                         SIMDE_FLOAT32_C( -963.16), SIMDE_FLOAT32_C( -158.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -812.40), SIMDE_FLOAT32_C( -551.18),
                         SIMDE_FLOAT32_C(  389.71), SIMDE_FLOAT32_C(  667.74),
                         SIMDE_FLOAT32_C(  644.48), SIMDE_FLOAT32_C(  859.03),
                         SIMDE_FLOAT32_C(  860.16), SIMDE_FLOAT32_C( -158.52)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   53.03), SIMDE_FLOAT32_C( -493.76),
                         SIMDE_FLOAT32_C(  623.37), SIMDE_FLOAT32_C(  296.00),
                         SIMDE_FLOAT32_C( -416.71), SIMDE_FLOAT32_C( -539.89),
                         SIMDE_FLOAT32_C(  210.88), SIMDE_FLOAT32_C(  585.18)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -34.37), SIMDE_FLOAT32_C( -267.21),
                         SIMDE_FLOAT32_C(  411.37), SIMDE_FLOAT32_C( -265.51),
                         SIMDE_FLOAT32_C(  345.42), SIMDE_FLOAT32_C(  252.46),
                         SIMDE_FLOAT32_C(  286.48), SIMDE_FLOAT32_C( -858.99)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   53.03), SIMDE_FLOAT32_C( -493.76),
                         SIMDE_FLOAT32_C(  623.37), SIMDE_FLOAT32_C(  296.00),
                         SIMDE_FLOAT32_C(  345.42), SIMDE_FLOAT32_C(  252.46),
                         SIMDE_FLOAT32_C(  210.88), SIMDE_FLOAT32_C( -858.99)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_blend_ps(test_vec[i].a, test_vec[i].b, 13);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_blend_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  983.61), SIMDE_FLOAT64_C(  -51.56),
                         SIMDE_FLOAT64_C(  561.13), SIMDE_FLOAT64_C( -977.17)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  311.03), SIMDE_FLOAT64_C( -876.87),
                         SIMDE_FLOAT64_C(   15.56), SIMDE_FLOAT64_C(  821.58)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  311.03), SIMDE_FLOAT64_C( -876.87),
                         SIMDE_FLOAT64_C(  561.13), SIMDE_FLOAT64_C(  821.58)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  486.15), SIMDE_FLOAT64_C( -809.80),
                         SIMDE_FLOAT64_C( -134.49), SIMDE_FLOAT64_C( -709.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -588.52), SIMDE_FLOAT64_C( -823.37),
                         SIMDE_FLOAT64_C( -436.62), SIMDE_FLOAT64_C( -938.83)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -588.52), SIMDE_FLOAT64_C( -823.37),
                         SIMDE_FLOAT64_C( -134.49), SIMDE_FLOAT64_C( -938.83)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   10.97), SIMDE_FLOAT64_C( -837.09),
                         SIMDE_FLOAT64_C( -238.93), SIMDE_FLOAT64_C( -927.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -150.59), SIMDE_FLOAT64_C(  428.13),
                         SIMDE_FLOAT64_C(  655.11), SIMDE_FLOAT64_C(  -28.81)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -150.59), SIMDE_FLOAT64_C(  428.13),
                         SIMDE_FLOAT64_C( -238.93), SIMDE_FLOAT64_C(  -28.81)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -691.52), SIMDE_FLOAT64_C( -756.72),
                         SIMDE_FLOAT64_C(   69.02), SIMDE_FLOAT64_C( -249.34)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -857.57), SIMDE_FLOAT64_C( -720.61),
                         SIMDE_FLOAT64_C(  529.12), SIMDE_FLOAT64_C(  813.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -857.57), SIMDE_FLOAT64_C( -720.61),
                         SIMDE_FLOAT64_C(   69.02), SIMDE_FLOAT64_C(  813.95)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  743.57), SIMDE_FLOAT64_C(  671.72),
                         SIMDE_FLOAT64_C(  747.66), SIMDE_FLOAT64_C(  592.11)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -559.29), SIMDE_FLOAT64_C(  529.63),
                         SIMDE_FLOAT64_C(  121.55), SIMDE_FLOAT64_C( -352.32)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -559.29), SIMDE_FLOAT64_C(  529.63),
                         SIMDE_FLOAT64_C(  747.66), SIMDE_FLOAT64_C( -352.32)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -466.05), SIMDE_FLOAT64_C( -621.64),
                         SIMDE_FLOAT64_C(  113.70), SIMDE_FLOAT64_C( -906.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -919.48), SIMDE_FLOAT64_C(  972.84),
                         SIMDE_FLOAT64_C(  378.79), SIMDE_FLOAT64_C( -196.68)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -919.48), SIMDE_FLOAT64_C(  972.84),
                         SIMDE_FLOAT64_C(  113.70), SIMDE_FLOAT64_C( -196.68)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -749.13), SIMDE_FLOAT64_C(   30.92),
                         SIMDE_FLOAT64_C(  753.62), SIMDE_FLOAT64_C( -864.28)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -997.13), SIMDE_FLOAT64_C(  675.64),
                         SIMDE_FLOAT64_C( -135.93), SIMDE_FLOAT64_C( -647.89)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -997.13), SIMDE_FLOAT64_C(  675.64),
                         SIMDE_FLOAT64_C(  753.62), SIMDE_FLOAT64_C( -647.89)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  757.64), SIMDE_FLOAT64_C(  119.62),
                         SIMDE_FLOAT64_C(  682.14), SIMDE_FLOAT64_C( -348.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  467.61), SIMDE_FLOAT64_C(  532.40),
                         SIMDE_FLOAT64_C(  959.59), SIMDE_FLOAT64_C( -392.58)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  467.61), SIMDE_FLOAT64_C(  532.40),
                         SIMDE_FLOAT64_C(  682.14), SIMDE_FLOAT64_C( -392.58)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_blend_pd(test_vec[i].a, test_vec[i].b, 13);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_blendv_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 mask;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -169.19), SIMDE_FLOAT32_C( -303.51),
                         SIMDE_FLOAT32_C(  280.62), SIMDE_FLOAT32_C(  971.56),
                         SIMDE_FLOAT32_C(  558.62), SIMDE_FLOAT32_C(  244.31),
                         SIMDE_FLOAT32_C( -482.20), SIMDE_FLOAT32_C(  526.92)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  779.01), SIMDE_FLOAT32_C( -628.61),
                         SIMDE_FLOAT32_C( -781.26), SIMDE_FLOAT32_C( -923.79),
                         SIMDE_FLOAT32_C( -624.75), SIMDE_FLOAT32_C( -481.19),
                         SIMDE_FLOAT32_C(  750.60), SIMDE_FLOAT32_C(  693.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  392.97), SIMDE_FLOAT32_C(  752.07),
                         SIMDE_FLOAT32_C(  -74.68), SIMDE_FLOAT32_C( -769.29),
                         SIMDE_FLOAT32_C(  600.30), SIMDE_FLOAT32_C( -577.83),
                         SIMDE_FLOAT32_C(  257.89), SIMDE_FLOAT32_C( -759.37)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -169.19), SIMDE_FLOAT32_C( -303.51),
                         SIMDE_FLOAT32_C( -781.26), SIMDE_FLOAT32_C( -923.79),
                         SIMDE_FLOAT32_C(  558.62), SIMDE_FLOAT32_C( -481.19),
                         SIMDE_FLOAT32_C( -482.20), SIMDE_FLOAT32_C(  693.30)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  436.77), SIMDE_FLOAT32_C(  265.17),
                         SIMDE_FLOAT32_C( -598.85), SIMDE_FLOAT32_C( -424.56),
                         SIMDE_FLOAT32_C(  -24.79), SIMDE_FLOAT32_C( -558.99),
                         SIMDE_FLOAT32_C( -299.03), SIMDE_FLOAT32_C( -367.92)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  434.09), SIMDE_FLOAT32_C(   46.59),
                         SIMDE_FLOAT32_C(   85.98), SIMDE_FLOAT32_C( -164.97),
                         SIMDE_FLOAT32_C(   72.68), SIMDE_FLOAT32_C( -140.26),
                         SIMDE_FLOAT32_C(  458.69), SIMDE_FLOAT32_C(  804.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  696.57), SIMDE_FLOAT32_C(  799.50),
                         SIMDE_FLOAT32_C(  216.00), SIMDE_FLOAT32_C(  812.94),
                         SIMDE_FLOAT32_C(  321.91), SIMDE_FLOAT32_C(  497.67),
                         SIMDE_FLOAT32_C( -321.87), SIMDE_FLOAT32_C(  -96.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  436.77), SIMDE_FLOAT32_C(  265.17),
                         SIMDE_FLOAT32_C( -598.85), SIMDE_FLOAT32_C( -424.56),
                         SIMDE_FLOAT32_C(  -24.79), SIMDE_FLOAT32_C( -558.99),
                         SIMDE_FLOAT32_C(  458.69), SIMDE_FLOAT32_C(  804.02)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  593.15), SIMDE_FLOAT32_C(  822.85),
                         SIMDE_FLOAT32_C( -843.43), SIMDE_FLOAT32_C( -486.43),
                         SIMDE_FLOAT32_C(  259.42), SIMDE_FLOAT32_C( -708.30),
                         SIMDE_FLOAT32_C( -398.61), SIMDE_FLOAT32_C(  689.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -402.96), SIMDE_FLOAT32_C(  346.21),
                         SIMDE_FLOAT32_C( -865.06), SIMDE_FLOAT32_C(  330.41),
                         SIMDE_FLOAT32_C(  355.72), SIMDE_FLOAT32_C( -380.53),
                         SIMDE_FLOAT32_C(  702.28), SIMDE_FLOAT32_C(    6.18)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -441.80), SIMDE_FLOAT32_C(  453.07),
                         SIMDE_FLOAT32_C( -312.81), SIMDE_FLOAT32_C(  655.80),
                         SIMDE_FLOAT32_C( -443.61), SIMDE_FLOAT32_C( -292.20),
                         SIMDE_FLOAT32_C( -429.77), SIMDE_FLOAT32_C(  815.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -402.96), SIMDE_FLOAT32_C(  822.85),
                         SIMDE_FLOAT32_C( -865.06), SIMDE_FLOAT32_C( -486.43),
                         SIMDE_FLOAT32_C(  355.72), SIMDE_FLOAT32_C( -380.53),
                         SIMDE_FLOAT32_C(  702.28), SIMDE_FLOAT32_C(  689.88)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  627.12), SIMDE_FLOAT32_C( -903.61),
                         SIMDE_FLOAT32_C(  802.66), SIMDE_FLOAT32_C(  393.79),
                         SIMDE_FLOAT32_C( -634.24), SIMDE_FLOAT32_C(  782.19),
                         SIMDE_FLOAT32_C(  964.94), SIMDE_FLOAT32_C( -554.43)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -249.23), SIMDE_FLOAT32_C( -358.11),
                         SIMDE_FLOAT32_C(   69.71), SIMDE_FLOAT32_C(  774.95),
                         SIMDE_FLOAT32_C( -447.84), SIMDE_FLOAT32_C( -947.94),
                         SIMDE_FLOAT32_C( -908.85), SIMDE_FLOAT32_C(  -21.47)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  241.23), SIMDE_FLOAT32_C(   27.04),
                         SIMDE_FLOAT32_C(  341.47), SIMDE_FLOAT32_C(  482.33),
                         SIMDE_FLOAT32_C(  411.77), SIMDE_FLOAT32_C( -282.69),
                         SIMDE_FLOAT32_C(  915.57), SIMDE_FLOAT32_C( -213.96)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  627.12), SIMDE_FLOAT32_C( -903.61),
                         SIMDE_FLOAT32_C(  802.66), SIMDE_FLOAT32_C(  393.79),
                         SIMDE_FLOAT32_C( -634.24), SIMDE_FLOAT32_C( -947.94),
                         SIMDE_FLOAT32_C(  964.94), SIMDE_FLOAT32_C(  -21.47)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  365.56), SIMDE_FLOAT32_C(  297.70),
                         SIMDE_FLOAT32_C( -723.56), SIMDE_FLOAT32_C(  -52.07),
                         SIMDE_FLOAT32_C(  692.93), SIMDE_FLOAT32_C( -882.05),
                         SIMDE_FLOAT32_C( -424.36), SIMDE_FLOAT32_C( -366.57)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  744.52), SIMDE_FLOAT32_C(  387.36),
                         SIMDE_FLOAT32_C( -311.40), SIMDE_FLOAT32_C( -280.68),
                         SIMDE_FLOAT32_C(  556.91), SIMDE_FLOAT32_C(  703.77),
                         SIMDE_FLOAT32_C( -828.92), SIMDE_FLOAT32_C(  893.13)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -152.86), SIMDE_FLOAT32_C(  793.25),
                         SIMDE_FLOAT32_C(  667.69), SIMDE_FLOAT32_C(  940.95),
                         SIMDE_FLOAT32_C( -273.21), SIMDE_FLOAT32_C(  148.61),
                         SIMDE_FLOAT32_C(  420.18), SIMDE_FLOAT32_C(    4.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  744.52), SIMDE_FLOAT32_C(  297.70),
                         SIMDE_FLOAT32_C( -723.56), SIMDE_FLOAT32_C(  -52.07),
                         SIMDE_FLOAT32_C(  556.91), SIMDE_FLOAT32_C( -882.05),
                         SIMDE_FLOAT32_C( -424.36), SIMDE_FLOAT32_C( -366.57)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  806.04), SIMDE_FLOAT32_C(  998.56),
                         SIMDE_FLOAT32_C(  954.81), SIMDE_FLOAT32_C( -105.93),
                         SIMDE_FLOAT32_C(  810.39), SIMDE_FLOAT32_C( -451.40),
                         SIMDE_FLOAT32_C( -991.41), SIMDE_FLOAT32_C(   24.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   69.57), SIMDE_FLOAT32_C(  -71.31),
                         SIMDE_FLOAT32_C( -379.77), SIMDE_FLOAT32_C( -507.58),
                         SIMDE_FLOAT32_C( -931.37), SIMDE_FLOAT32_C( -271.48),
                         SIMDE_FLOAT32_C(  709.92), SIMDE_FLOAT32_C( -442.85)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -608.56), SIMDE_FLOAT32_C( -319.60),
                         SIMDE_FLOAT32_C( -930.98), SIMDE_FLOAT32_C( -628.59),
                         SIMDE_FLOAT32_C(  898.10), SIMDE_FLOAT32_C( -782.18),
                         SIMDE_FLOAT32_C( -846.42), SIMDE_FLOAT32_C(  513.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   69.57), SIMDE_FLOAT32_C(  -71.31),
                         SIMDE_FLOAT32_C( -379.77), SIMDE_FLOAT32_C( -507.58),
                         SIMDE_FLOAT32_C(  810.39), SIMDE_FLOAT32_C( -271.48),
                         SIMDE_FLOAT32_C(  709.92), SIMDE_FLOAT32_C(   24.70)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -598.65), SIMDE_FLOAT32_C( -864.46),
                         SIMDE_FLOAT32_C( -182.16), SIMDE_FLOAT32_C(  855.39),
                         SIMDE_FLOAT32_C( -689.66), SIMDE_FLOAT32_C(  116.31),
                         SIMDE_FLOAT32_C( -552.00), SIMDE_FLOAT32_C(  962.19)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    2.01), SIMDE_FLOAT32_C(  601.06),
                         SIMDE_FLOAT32_C(  276.21), SIMDE_FLOAT32_C( -129.29),
                         SIMDE_FLOAT32_C( -199.59), SIMDE_FLOAT32_C( -345.44),
                         SIMDE_FLOAT32_C( -185.67), SIMDE_FLOAT32_C(  900.58)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  857.48), SIMDE_FLOAT32_C( -480.62),
                         SIMDE_FLOAT32_C( -406.99), SIMDE_FLOAT32_C( -422.80),
                         SIMDE_FLOAT32_C(    1.49), SIMDE_FLOAT32_C(  102.14),
                         SIMDE_FLOAT32_C(  113.98), SIMDE_FLOAT32_C( -405.64)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -598.65), SIMDE_FLOAT32_C(  601.06),
                         SIMDE_FLOAT32_C(  276.21), SIMDE_FLOAT32_C( -129.29),
                         SIMDE_FLOAT32_C( -689.66), SIMDE_FLOAT32_C(  116.31),
                         SIMDE_FLOAT32_C( -552.00), SIMDE_FLOAT32_C(  900.58)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  890.83), SIMDE_FLOAT32_C(  201.56),
                         SIMDE_FLOAT32_C(  104.24), SIMDE_FLOAT32_C(  496.38),
                         SIMDE_FLOAT32_C(  607.57), SIMDE_FLOAT32_C(  285.01),
                         SIMDE_FLOAT32_C(  501.29), SIMDE_FLOAT32_C( -590.78)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -643.60), SIMDE_FLOAT32_C(  256.83),
                         SIMDE_FLOAT32_C(  140.60), SIMDE_FLOAT32_C(  204.90),
                         SIMDE_FLOAT32_C(  371.07), SIMDE_FLOAT32_C( -744.00),
                         SIMDE_FLOAT32_C(  751.14), SIMDE_FLOAT32_C(  233.26)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -384.25), SIMDE_FLOAT32_C( -588.66),
                         SIMDE_FLOAT32_C( -531.19), SIMDE_FLOAT32_C( -520.11),
                         SIMDE_FLOAT32_C(  648.35), SIMDE_FLOAT32_C( -584.03),
                         SIMDE_FLOAT32_C(  700.38), SIMDE_FLOAT32_C(   21.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -643.60), SIMDE_FLOAT32_C(  256.83),
                         SIMDE_FLOAT32_C(  140.60), SIMDE_FLOAT32_C(  204.90),
                         SIMDE_FLOAT32_C(  607.57), SIMDE_FLOAT32_C( -744.00),
                         SIMDE_FLOAT32_C(  501.29), SIMDE_FLOAT32_C( -590.78)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_blendv_ps(test_vec[i].a, test_vec[i].b, test_vec[i].mask);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_blendv_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d mask;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -587.29), SIMDE_FLOAT64_C(  745.99),
                         SIMDE_FLOAT64_C(  660.01), SIMDE_FLOAT64_C(  -72.44)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  307.98), SIMDE_FLOAT64_C(  879.25),
                         SIMDE_FLOAT64_C(  340.44), SIMDE_FLOAT64_C( -338.42)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -599.03), SIMDE_FLOAT64_C(  269.37),
                         SIMDE_FLOAT64_C( -940.99), SIMDE_FLOAT64_C( -383.55)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  307.98), SIMDE_FLOAT64_C(  745.99),
                         SIMDE_FLOAT64_C(  340.44), SIMDE_FLOAT64_C( -338.42)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -369.37), SIMDE_FLOAT64_C(  888.66),
                         SIMDE_FLOAT64_C( -159.55), SIMDE_FLOAT64_C( -869.53)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  649.46), SIMDE_FLOAT64_C(  886.19),
                         SIMDE_FLOAT64_C(  926.89), SIMDE_FLOAT64_C( -697.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -515.74), SIMDE_FLOAT64_C( -918.64),
                         SIMDE_FLOAT64_C(  131.75), SIMDE_FLOAT64_C(  581.75)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  649.46), SIMDE_FLOAT64_C(  886.19),
                         SIMDE_FLOAT64_C( -159.55), SIMDE_FLOAT64_C( -869.53)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -900.47), SIMDE_FLOAT64_C(  409.14),
                         SIMDE_FLOAT64_C( -799.12), SIMDE_FLOAT64_C( -260.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -10.16), SIMDE_FLOAT64_C(  623.74),
                         SIMDE_FLOAT64_C( -915.24), SIMDE_FLOAT64_C( -491.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  804.78), SIMDE_FLOAT64_C( -317.20),
                         SIMDE_FLOAT64_C( -335.85), SIMDE_FLOAT64_C( -779.77)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -900.47), SIMDE_FLOAT64_C(  623.74),
                         SIMDE_FLOAT64_C( -915.24), SIMDE_FLOAT64_C( -491.31)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -87.84), SIMDE_FLOAT64_C(  244.36),
                         SIMDE_FLOAT64_C(  -17.33), SIMDE_FLOAT64_C(  496.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  176.35), SIMDE_FLOAT64_C(  303.26),
                         SIMDE_FLOAT64_C( -414.16), SIMDE_FLOAT64_C(  -98.44)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -385.65), SIMDE_FLOAT64_C( -192.42),
                         SIMDE_FLOAT64_C(  392.65), SIMDE_FLOAT64_C( -902.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  176.35), SIMDE_FLOAT64_C(  303.26),
                         SIMDE_FLOAT64_C(  -17.33), SIMDE_FLOAT64_C(  -98.44)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -793.35), SIMDE_FLOAT64_C(    6.53),
                         SIMDE_FLOAT64_C(  858.41), SIMDE_FLOAT64_C(  175.72)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  376.10), SIMDE_FLOAT64_C( -410.32),
                         SIMDE_FLOAT64_C(  -49.60), SIMDE_FLOAT64_C( -434.06)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -290.24), SIMDE_FLOAT64_C(  223.04),
                         SIMDE_FLOAT64_C(  738.63), SIMDE_FLOAT64_C( -193.43)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  376.10), SIMDE_FLOAT64_C(    6.53),
                         SIMDE_FLOAT64_C(  858.41), SIMDE_FLOAT64_C( -434.06)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -894.04), SIMDE_FLOAT64_C( -968.20),
                         SIMDE_FLOAT64_C(  146.09), SIMDE_FLOAT64_C( -741.36)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -570.76), SIMDE_FLOAT64_C( -340.64),
                         SIMDE_FLOAT64_C(  593.54), SIMDE_FLOAT64_C( -684.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  155.79), SIMDE_FLOAT64_C(  975.56),
                         SIMDE_FLOAT64_C(  939.33), SIMDE_FLOAT64_C(  615.78)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -894.04), SIMDE_FLOAT64_C( -968.20),
                         SIMDE_FLOAT64_C(  146.09), SIMDE_FLOAT64_C( -741.36)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -512.44), SIMDE_FLOAT64_C(  657.99),
                         SIMDE_FLOAT64_C(  888.55), SIMDE_FLOAT64_C(  863.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  344.43), SIMDE_FLOAT64_C(  994.17),
                         SIMDE_FLOAT64_C( -142.41), SIMDE_FLOAT64_C( -388.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -738.41), SIMDE_FLOAT64_C(  935.62),
                         SIMDE_FLOAT64_C( -743.51), SIMDE_FLOAT64_C(  -41.25)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  344.43), SIMDE_FLOAT64_C(  657.99),
                         SIMDE_FLOAT64_C( -142.41), SIMDE_FLOAT64_C( -388.31)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -178.00), SIMDE_FLOAT64_C( -981.39),
                         SIMDE_FLOAT64_C( -631.33), SIMDE_FLOAT64_C(  518.52)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  592.14), SIMDE_FLOAT64_C(  -27.22),
                         SIMDE_FLOAT64_C(  736.38), SIMDE_FLOAT64_C(  579.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  893.09), SIMDE_FLOAT64_C(  120.96),
                         SIMDE_FLOAT64_C(  910.10), SIMDE_FLOAT64_C( -128.61)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -178.00), SIMDE_FLOAT64_C( -981.39),
                         SIMDE_FLOAT64_C( -631.33), SIMDE_FLOAT64_C(  579.20)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_blendv_pd(test_vec[i].a, test_vec[i].b, test_vec[i].mask);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_broadcast_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -513.14), SIMDE_FLOAT64_C( -996.03)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -513.14), SIMDE_FLOAT64_C( -996.03),
                         SIMDE_FLOAT64_C( -513.14), SIMDE_FLOAT64_C( -996.03)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -857.31), SIMDE_FLOAT64_C(  353.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -857.31), SIMDE_FLOAT64_C(  353.95),
                         SIMDE_FLOAT64_C( -857.31), SIMDE_FLOAT64_C(  353.95)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -899.34), SIMDE_FLOAT64_C(  232.82)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -899.34), SIMDE_FLOAT64_C(  232.82),
                         SIMDE_FLOAT64_C( -899.34), SIMDE_FLOAT64_C(  232.82)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  382.07), SIMDE_FLOAT64_C(  111.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  382.07), SIMDE_FLOAT64_C(  111.12),
                         SIMDE_FLOAT64_C(  382.07), SIMDE_FLOAT64_C(  111.12)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -172.90), SIMDE_FLOAT64_C(  651.78)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -172.90), SIMDE_FLOAT64_C(  651.78),
                         SIMDE_FLOAT64_C( -172.90), SIMDE_FLOAT64_C(  651.78)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  181.43), SIMDE_FLOAT64_C( -457.14)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  181.43), SIMDE_FLOAT64_C( -457.14),
                         SIMDE_FLOAT64_C(  181.43), SIMDE_FLOAT64_C( -457.14)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -742.24), SIMDE_FLOAT64_C(  215.84)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -742.24), SIMDE_FLOAT64_C(  215.84),
                         SIMDE_FLOAT64_C( -742.24), SIMDE_FLOAT64_C(  215.84)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -536.84), SIMDE_FLOAT64_C(  334.73)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -536.84), SIMDE_FLOAT64_C(  334.73),
                         SIMDE_FLOAT64_C( -536.84), SIMDE_FLOAT64_C(  334.73)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_broadcast_pd(&(test_vec[i].a));
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_broadcast_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -120.60), SIMDE_FLOAT32_C( -932.90), SIMDE_FLOAT32_C( -860.11), SIMDE_FLOAT32_C(  350.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -120.60), SIMDE_FLOAT32_C( -932.90),
                         SIMDE_FLOAT32_C( -860.11), SIMDE_FLOAT32_C(  350.60),
                         SIMDE_FLOAT32_C( -120.60), SIMDE_FLOAT32_C( -932.90),
                         SIMDE_FLOAT32_C( -860.11), SIMDE_FLOAT32_C(  350.60)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  391.01), SIMDE_FLOAT32_C( -590.54), SIMDE_FLOAT32_C(  324.31), SIMDE_FLOAT32_C( -643.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  391.01), SIMDE_FLOAT32_C( -590.54),
                         SIMDE_FLOAT32_C(  324.31), SIMDE_FLOAT32_C( -643.80),
                         SIMDE_FLOAT32_C(  391.01), SIMDE_FLOAT32_C( -590.54),
                         SIMDE_FLOAT32_C(  324.31), SIMDE_FLOAT32_C( -643.80)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -491.12), SIMDE_FLOAT32_C( -967.66), SIMDE_FLOAT32_C(  104.85), SIMDE_FLOAT32_C(  671.42)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -491.12), SIMDE_FLOAT32_C( -967.66),
                         SIMDE_FLOAT32_C(  104.85), SIMDE_FLOAT32_C(  671.42),
                         SIMDE_FLOAT32_C( -491.12), SIMDE_FLOAT32_C( -967.66),
                         SIMDE_FLOAT32_C(  104.85), SIMDE_FLOAT32_C(  671.42)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -32.73), SIMDE_FLOAT32_C( -190.09), SIMDE_FLOAT32_C( -799.15), SIMDE_FLOAT32_C(  623.57)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -32.73), SIMDE_FLOAT32_C( -190.09),
                         SIMDE_FLOAT32_C( -799.15), SIMDE_FLOAT32_C(  623.57),
                         SIMDE_FLOAT32_C(  -32.73), SIMDE_FLOAT32_C( -190.09),
                         SIMDE_FLOAT32_C( -799.15), SIMDE_FLOAT32_C(  623.57)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  125.40), SIMDE_FLOAT32_C( -581.68), SIMDE_FLOAT32_C(   -8.66), SIMDE_FLOAT32_C(  -28.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  125.40), SIMDE_FLOAT32_C( -581.68),
                         SIMDE_FLOAT32_C(   -8.66), SIMDE_FLOAT32_C(  -28.30),
                         SIMDE_FLOAT32_C(  125.40), SIMDE_FLOAT32_C( -581.68),
                         SIMDE_FLOAT32_C(   -8.66), SIMDE_FLOAT32_C(  -28.30)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  419.56), SIMDE_FLOAT32_C(   29.31), SIMDE_FLOAT32_C(  547.18), SIMDE_FLOAT32_C(  390.29)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  419.56), SIMDE_FLOAT32_C(   29.31),
                         SIMDE_FLOAT32_C(  547.18), SIMDE_FLOAT32_C(  390.29),
                         SIMDE_FLOAT32_C(  419.56), SIMDE_FLOAT32_C(   29.31),
                         SIMDE_FLOAT32_C(  547.18), SIMDE_FLOAT32_C(  390.29)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -994.03), SIMDE_FLOAT32_C(   56.64), SIMDE_FLOAT32_C(   34.15), SIMDE_FLOAT32_C( -848.34)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -994.03), SIMDE_FLOAT32_C(   56.64),
                         SIMDE_FLOAT32_C(   34.15), SIMDE_FLOAT32_C( -848.34),
                         SIMDE_FLOAT32_C( -994.03), SIMDE_FLOAT32_C(   56.64),
                         SIMDE_FLOAT32_C(   34.15), SIMDE_FLOAT32_C( -848.34)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  124.11), SIMDE_FLOAT32_C( -417.13), SIMDE_FLOAT32_C(  650.71), SIMDE_FLOAT32_C(   49.59)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  124.11), SIMDE_FLOAT32_C( -417.13),
                         SIMDE_FLOAT32_C(  650.71), SIMDE_FLOAT32_C(   49.59),
                         SIMDE_FLOAT32_C(  124.11), SIMDE_FLOAT32_C( -417.13),
                         SIMDE_FLOAT32_C(  650.71), SIMDE_FLOAT32_C(   49.59)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_broadcast_ps(&(test_vec[i].a));
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_broadcast_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64 a;
    simde__m256d r;
  } test_vec[8] = {
    { SIMDE_FLOAT64_C(  800.84),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  800.84), SIMDE_FLOAT64_C(  800.84),
                         SIMDE_FLOAT64_C(  800.84), SIMDE_FLOAT64_C(  800.84)) },
    { SIMDE_FLOAT64_C(  700.06),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  700.06), SIMDE_FLOAT64_C(  700.06),
                         SIMDE_FLOAT64_C(  700.06), SIMDE_FLOAT64_C(  700.06)) },
    { SIMDE_FLOAT64_C( -801.66),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -801.66), SIMDE_FLOAT64_C( -801.66),
                         SIMDE_FLOAT64_C( -801.66), SIMDE_FLOAT64_C( -801.66)) },
    { SIMDE_FLOAT64_C( -941.38),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -941.38), SIMDE_FLOAT64_C( -941.38),
                         SIMDE_FLOAT64_C( -941.38), SIMDE_FLOAT64_C( -941.38)) },
    { SIMDE_FLOAT64_C( -346.77),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -346.77), SIMDE_FLOAT64_C( -346.77),
                         SIMDE_FLOAT64_C( -346.77), SIMDE_FLOAT64_C( -346.77)) },
    { SIMDE_FLOAT64_C( -833.73),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -833.73), SIMDE_FLOAT64_C( -833.73),
                         SIMDE_FLOAT64_C( -833.73), SIMDE_FLOAT64_C( -833.73)) },
    { SIMDE_FLOAT64_C(  315.88),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  315.88), SIMDE_FLOAT64_C(  315.88),
                         SIMDE_FLOAT64_C(  315.88), SIMDE_FLOAT64_C(  315.88)) },
    { SIMDE_FLOAT64_C( -868.73),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -868.73), SIMDE_FLOAT64_C( -868.73),
                         SIMDE_FLOAT64_C( -868.73), SIMDE_FLOAT64_C( -868.73)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_broadcast_sd(&(test_vec[i].a));
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_broadcast_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32 a;
    simde__m128 r;
  } test_vec[8] = {
    { SIMDE_FLOAT32_C(  137.82),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  137.82), SIMDE_FLOAT32_C(  137.82), SIMDE_FLOAT32_C(  137.82), SIMDE_FLOAT32_C(  137.82)) },
    { SIMDE_FLOAT32_C( -118.58),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -118.58), SIMDE_FLOAT32_C( -118.58), SIMDE_FLOAT32_C( -118.58), SIMDE_FLOAT32_C( -118.58)) },
    { SIMDE_FLOAT32_C(  963.02),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  963.02), SIMDE_FLOAT32_C(  963.02), SIMDE_FLOAT32_C(  963.02), SIMDE_FLOAT32_C(  963.02)) },
    { SIMDE_FLOAT32_C(  515.85),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  515.85), SIMDE_FLOAT32_C(  515.85), SIMDE_FLOAT32_C(  515.85), SIMDE_FLOAT32_C(  515.85)) },
    { SIMDE_FLOAT32_C(  110.78),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  110.78), SIMDE_FLOAT32_C(  110.78), SIMDE_FLOAT32_C(  110.78), SIMDE_FLOAT32_C(  110.78)) },
    { SIMDE_FLOAT32_C( -190.98),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -190.98), SIMDE_FLOAT32_C( -190.98), SIMDE_FLOAT32_C( -190.98), SIMDE_FLOAT32_C( -190.98)) },
    { SIMDE_FLOAT32_C( -429.63),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -429.63), SIMDE_FLOAT32_C( -429.63), SIMDE_FLOAT32_C( -429.63), SIMDE_FLOAT32_C( -429.63)) },
    { SIMDE_FLOAT32_C( -924.63),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -924.63), SIMDE_FLOAT32_C( -924.63), SIMDE_FLOAT32_C( -924.63), SIMDE_FLOAT32_C( -924.63)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_broadcast_ss(&(test_vec[i].a));
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_broadcast_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32 a;
    simde__m256 r;
  } test_vec[8] = {
    { SIMDE_FLOAT32_C( -970.00),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -970.00), SIMDE_FLOAT32_C( -970.00),
                         SIMDE_FLOAT32_C( -970.00), SIMDE_FLOAT32_C( -970.00),
                         SIMDE_FLOAT32_C( -970.00), SIMDE_FLOAT32_C( -970.00),
                         SIMDE_FLOAT32_C( -970.00), SIMDE_FLOAT32_C( -970.00)) },
    { SIMDE_FLOAT32_C(  425.08),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  425.08), SIMDE_FLOAT32_C(  425.08),
                         SIMDE_FLOAT32_C(  425.08), SIMDE_FLOAT32_C(  425.08),
                         SIMDE_FLOAT32_C(  425.08), SIMDE_FLOAT32_C(  425.08),
                         SIMDE_FLOAT32_C(  425.08), SIMDE_FLOAT32_C(  425.08)) },
    { SIMDE_FLOAT32_C(  814.32),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  814.32), SIMDE_FLOAT32_C(  814.32),
                         SIMDE_FLOAT32_C(  814.32), SIMDE_FLOAT32_C(  814.32),
                         SIMDE_FLOAT32_C(  814.32), SIMDE_FLOAT32_C(  814.32),
                         SIMDE_FLOAT32_C(  814.32), SIMDE_FLOAT32_C(  814.32)) },
    { SIMDE_FLOAT32_C(  309.83),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  309.83), SIMDE_FLOAT32_C(  309.83),
                         SIMDE_FLOAT32_C(  309.83), SIMDE_FLOAT32_C(  309.83),
                         SIMDE_FLOAT32_C(  309.83), SIMDE_FLOAT32_C(  309.83),
                         SIMDE_FLOAT32_C(  309.83), SIMDE_FLOAT32_C(  309.83)) },
    { SIMDE_FLOAT32_C( -410.17),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -410.17), SIMDE_FLOAT32_C( -410.17),
                         SIMDE_FLOAT32_C( -410.17), SIMDE_FLOAT32_C( -410.17),
                         SIMDE_FLOAT32_C( -410.17), SIMDE_FLOAT32_C( -410.17),
                         SIMDE_FLOAT32_C( -410.17), SIMDE_FLOAT32_C( -410.17)) },
    { SIMDE_FLOAT32_C( -592.37),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -592.37), SIMDE_FLOAT32_C( -592.37),
                         SIMDE_FLOAT32_C( -592.37), SIMDE_FLOAT32_C( -592.37),
                         SIMDE_FLOAT32_C( -592.37), SIMDE_FLOAT32_C( -592.37),
                         SIMDE_FLOAT32_C( -592.37), SIMDE_FLOAT32_C( -592.37)) },
    { SIMDE_FLOAT32_C(  297.30),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  297.30), SIMDE_FLOAT32_C(  297.30),
                         SIMDE_FLOAT32_C(  297.30), SIMDE_FLOAT32_C(  297.30),
                         SIMDE_FLOAT32_C(  297.30), SIMDE_FLOAT32_C(  297.30),
                         SIMDE_FLOAT32_C(  297.30), SIMDE_FLOAT32_C(  297.30)) },
    { SIMDE_FLOAT32_C( -549.85),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -549.85), SIMDE_FLOAT32_C( -549.85),
                         SIMDE_FLOAT32_C( -549.85), SIMDE_FLOAT32_C( -549.85),
                         SIMDE_FLOAT32_C( -549.85), SIMDE_FLOAT32_C( -549.85),
                         SIMDE_FLOAT32_C( -549.85), SIMDE_FLOAT32_C( -549.85)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_broadcast_ss(&(test_vec[i].a));
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_castpd128_pd256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -698.37), SIMDE_FLOAT64_C(  516.77)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -698.37), SIMDE_FLOAT64_C(  516.77)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -509.42), SIMDE_FLOAT64_C( -285.35)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -509.42), SIMDE_FLOAT64_C( -285.35)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -919.57), SIMDE_FLOAT64_C(  938.94)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -919.57), SIMDE_FLOAT64_C(  938.94)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   39.71), SIMDE_FLOAT64_C(  227.66)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(   39.71), SIMDE_FLOAT64_C(  227.66)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  548.32), SIMDE_FLOAT64_C( -120.08)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  548.32), SIMDE_FLOAT64_C( -120.08)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -962.85), SIMDE_FLOAT64_C(  234.42)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -962.85), SIMDE_FLOAT64_C(  234.42)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -939.16), SIMDE_FLOAT64_C( -985.25)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -939.16), SIMDE_FLOAT64_C( -985.25)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  302.61), SIMDE_FLOAT64_C(  350.72)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  302.61), SIMDE_FLOAT64_C(  350.72)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_castpd128_pd256(test_vec[i].a);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_castpd256_pd128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -956.85), SIMDE_FLOAT64_C(  625.41),
                         SIMDE_FLOAT64_C(  728.85), SIMDE_FLOAT64_C(  239.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  728.85), SIMDE_FLOAT64_C(  239.74)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -642.31), SIMDE_FLOAT64_C( -953.04),
                         SIMDE_FLOAT64_C( -288.66), SIMDE_FLOAT64_C(  999.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -288.66), SIMDE_FLOAT64_C(  999.01)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -330.74), SIMDE_FLOAT64_C(  875.72),
                         SIMDE_FLOAT64_C( -137.28), SIMDE_FLOAT64_C( -787.08)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -137.28), SIMDE_FLOAT64_C( -787.08)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -616.04), SIMDE_FLOAT64_C( -762.33),
                         SIMDE_FLOAT64_C(  806.25), SIMDE_FLOAT64_C( -621.65)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  806.25), SIMDE_FLOAT64_C( -621.65)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -28.93), SIMDE_FLOAT64_C(  468.91),
                         SIMDE_FLOAT64_C(  242.39), SIMDE_FLOAT64_C(   -4.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  242.39), SIMDE_FLOAT64_C(   -4.32)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -635.10), SIMDE_FLOAT64_C( -479.80),
                         SIMDE_FLOAT64_C(  479.34), SIMDE_FLOAT64_C(  994.78)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  479.34), SIMDE_FLOAT64_C(  994.78)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  839.27), SIMDE_FLOAT64_C( -846.55),
                         SIMDE_FLOAT64_C( -287.23), SIMDE_FLOAT64_C(  498.33)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -287.23), SIMDE_FLOAT64_C(  498.33)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -68.67), SIMDE_FLOAT64_C(  956.25),
                         SIMDE_FLOAT64_C(  462.89), SIMDE_FLOAT64_C( -555.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  462.89), SIMDE_FLOAT64_C( -555.47)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm256_castpd256_pd128(test_vec[i].a);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_ceil_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -242.41), SIMDE_FLOAT64_C( -377.59),
                         SIMDE_FLOAT64_C(  787.73), SIMDE_FLOAT64_C(  903.22)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -242.00), SIMDE_FLOAT64_C( -377.00),
                         SIMDE_FLOAT64_C(  788.00), SIMDE_FLOAT64_C(  904.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -851.63), SIMDE_FLOAT64_C( -168.29),
                         SIMDE_FLOAT64_C(  -47.72), SIMDE_FLOAT64_C( -227.89)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -851.00), SIMDE_FLOAT64_C( -168.00),
                         SIMDE_FLOAT64_C(  -47.00), SIMDE_FLOAT64_C( -227.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  922.71), SIMDE_FLOAT64_C( -494.40),
                         SIMDE_FLOAT64_C( -263.96), SIMDE_FLOAT64_C( -353.64)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  923.00), SIMDE_FLOAT64_C( -494.00),
                         SIMDE_FLOAT64_C( -263.00), SIMDE_FLOAT64_C( -353.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -611.84), SIMDE_FLOAT64_C(  512.63),
                         SIMDE_FLOAT64_C( -238.35), SIMDE_FLOAT64_C( -170.16)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -611.00), SIMDE_FLOAT64_C(  513.00),
                         SIMDE_FLOAT64_C( -238.00), SIMDE_FLOAT64_C( -170.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  816.43), SIMDE_FLOAT64_C(  815.17),
                         SIMDE_FLOAT64_C(  214.52), SIMDE_FLOAT64_C( -660.09)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  817.00), SIMDE_FLOAT64_C(  816.00),
                         SIMDE_FLOAT64_C(  215.00), SIMDE_FLOAT64_C( -660.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  434.90), SIMDE_FLOAT64_C(   54.02),
                         SIMDE_FLOAT64_C( -447.58), SIMDE_FLOAT64_C(  766.46)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  435.00), SIMDE_FLOAT64_C(   55.00),
                         SIMDE_FLOAT64_C( -447.00), SIMDE_FLOAT64_C(  767.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  372.78), SIMDE_FLOAT64_C( -135.62),
                         SIMDE_FLOAT64_C(  715.18), SIMDE_FLOAT64_C( -737.69)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  373.00), SIMDE_FLOAT64_C( -135.00),
                         SIMDE_FLOAT64_C(  716.00), SIMDE_FLOAT64_C( -737.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  491.75), SIMDE_FLOAT64_C(  481.14),
                         SIMDE_FLOAT64_C(  571.31), SIMDE_FLOAT64_C(  426.99)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  492.00), SIMDE_FLOAT64_C(  482.00),
                         SIMDE_FLOAT64_C(  572.00), SIMDE_FLOAT64_C(  427.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_ceil_pd(test_vec[i].a);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_ceil_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  719.50), SIMDE_FLOAT32_C(  423.42),
                         SIMDE_FLOAT32_C( -325.80), SIMDE_FLOAT32_C(   -7.65),
                         SIMDE_FLOAT32_C(  549.35), SIMDE_FLOAT32_C(   88.23),
                         SIMDE_FLOAT32_C(  442.11), SIMDE_FLOAT32_C(  103.18)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  720.00), SIMDE_FLOAT32_C(  424.00),
                         SIMDE_FLOAT32_C( -325.00), SIMDE_FLOAT32_C(   -7.00),
                         SIMDE_FLOAT32_C(  550.00), SIMDE_FLOAT32_C(   89.00),
                         SIMDE_FLOAT32_C(  443.00), SIMDE_FLOAT32_C(  104.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  295.26), SIMDE_FLOAT32_C(  174.52),
                         SIMDE_FLOAT32_C(  976.35), SIMDE_FLOAT32_C( -556.97),
                         SIMDE_FLOAT32_C( -188.36), SIMDE_FLOAT32_C( -888.83),
                         SIMDE_FLOAT32_C(  -89.34), SIMDE_FLOAT32_C(  743.04)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  296.00), SIMDE_FLOAT32_C(  175.00),
                         SIMDE_FLOAT32_C(  977.00), SIMDE_FLOAT32_C( -556.00),
                         SIMDE_FLOAT32_C( -188.00), SIMDE_FLOAT32_C( -888.00),
                         SIMDE_FLOAT32_C(  -89.00), SIMDE_FLOAT32_C(  744.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -846.44), SIMDE_FLOAT32_C(  768.02),
                         SIMDE_FLOAT32_C(  217.87), SIMDE_FLOAT32_C(  724.14),
                         SIMDE_FLOAT32_C( -751.28), SIMDE_FLOAT32_C(  377.99),
                         SIMDE_FLOAT32_C( -892.77), SIMDE_FLOAT32_C( -779.41)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -846.00), SIMDE_FLOAT32_C(  769.00),
                         SIMDE_FLOAT32_C(  218.00), SIMDE_FLOAT32_C(  725.00),
                         SIMDE_FLOAT32_C( -751.00), SIMDE_FLOAT32_C(  378.00),
                         SIMDE_FLOAT32_C( -892.00), SIMDE_FLOAT32_C( -779.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -291.21), SIMDE_FLOAT32_C( -433.62),
                         SIMDE_FLOAT32_C(  331.96), SIMDE_FLOAT32_C(   13.15),
                         SIMDE_FLOAT32_C(   -6.69), SIMDE_FLOAT32_C( -467.28),
                         SIMDE_FLOAT32_C( -722.45), SIMDE_FLOAT32_C( -121.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -291.00), SIMDE_FLOAT32_C( -433.00),
                         SIMDE_FLOAT32_C(  332.00), SIMDE_FLOAT32_C(   14.00),
                         SIMDE_FLOAT32_C(   -6.00), SIMDE_FLOAT32_C( -467.00),
                         SIMDE_FLOAT32_C( -722.00), SIMDE_FLOAT32_C( -121.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  337.66), SIMDE_FLOAT32_C(  332.63),
                         SIMDE_FLOAT32_C(  164.76), SIMDE_FLOAT32_C(  401.70),
                         SIMDE_FLOAT32_C( -359.22), SIMDE_FLOAT32_C( -704.77),
                         SIMDE_FLOAT32_C(  780.49), SIMDE_FLOAT32_C( -605.11)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  338.00), SIMDE_FLOAT32_C(  333.00),
                         SIMDE_FLOAT32_C(  165.00), SIMDE_FLOAT32_C(  402.00),
                         SIMDE_FLOAT32_C( -359.00), SIMDE_FLOAT32_C( -704.00),
                         SIMDE_FLOAT32_C(  781.00), SIMDE_FLOAT32_C( -605.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -670.88), SIMDE_FLOAT32_C(  812.79),
                         SIMDE_FLOAT32_C( -668.93), SIMDE_FLOAT32_C(  476.98),
                         SIMDE_FLOAT32_C(  590.12), SIMDE_FLOAT32_C(    1.22),
                         SIMDE_FLOAT32_C( -683.68), SIMDE_FLOAT32_C( -789.77)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -670.00), SIMDE_FLOAT32_C(  813.00),
                         SIMDE_FLOAT32_C( -668.00), SIMDE_FLOAT32_C(  477.00),
                         SIMDE_FLOAT32_C(  591.00), SIMDE_FLOAT32_C(    2.00),
                         SIMDE_FLOAT32_C( -683.00), SIMDE_FLOAT32_C( -789.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -872.42), SIMDE_FLOAT32_C(  -77.05),
                         SIMDE_FLOAT32_C( -381.51), SIMDE_FLOAT32_C( -862.58),
                         SIMDE_FLOAT32_C( -846.15), SIMDE_FLOAT32_C( -734.49),
                         SIMDE_FLOAT32_C(  -50.68), SIMDE_FLOAT32_C(  512.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -872.00), SIMDE_FLOAT32_C(  -77.00),
                         SIMDE_FLOAT32_C( -381.00), SIMDE_FLOAT32_C( -862.00),
                         SIMDE_FLOAT32_C( -846.00), SIMDE_FLOAT32_C( -734.00),
                         SIMDE_FLOAT32_C(  -50.00), SIMDE_FLOAT32_C(  513.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -195.22), SIMDE_FLOAT32_C(  -18.78),
                         SIMDE_FLOAT32_C(  479.49), SIMDE_FLOAT32_C(  552.41),
                         SIMDE_FLOAT32_C(  445.93), SIMDE_FLOAT32_C(  -70.46),
                         SIMDE_FLOAT32_C( -477.54), SIMDE_FLOAT32_C(  557.19)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -195.00), SIMDE_FLOAT32_C(  -18.00),
                         SIMDE_FLOAT32_C(  480.00), SIMDE_FLOAT32_C(  553.00),
                         SIMDE_FLOAT32_C(  446.00), SIMDE_FLOAT32_C(  -70.00),
                         SIMDE_FLOAT32_C( -477.00), SIMDE_FLOAT32_C(  558.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_ceil_ps(test_vec[i].a);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtepi32_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1957018358), INT32_C( 1074174472), INT32_C(  124397699), INT32_C( 1881644266)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(1957018358.00), SIMDE_FLOAT64_C(1074174472.00),
                         SIMDE_FLOAT64_C(124397699.00), SIMDE_FLOAT64_C(1881644266.00)) },
    { simde_mm_set_epi32(INT32_C( 2070107316), INT32_C( 1618653378), INT32_C( 1002292861), INT32_C( 2002977375)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(2070107316.00), SIMDE_FLOAT64_C(1618653378.00),
                         SIMDE_FLOAT64_C(1002292861.00), SIMDE_FLOAT64_C(2002977375.00)) },
    { simde_mm_set_epi32(INT32_C( 2031655643), INT32_C( 1380169755), INT32_C( 1722613954), INT32_C(  223100421)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(2031655643.00), SIMDE_FLOAT64_C(1380169755.00),
                         SIMDE_FLOAT64_C(1722613954.00), SIMDE_FLOAT64_C(223100421.00)) },
    { simde_mm_set_epi32(INT32_C(-1894427767), INT32_C(-1633274427), INT32_C(-2058387969), INT32_C(-1311515394)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1894427767.00), SIMDE_FLOAT64_C(-1633274427.00),
                         SIMDE_FLOAT64_C(-2058387969.00), SIMDE_FLOAT64_C(-1311515394.00)) },
    { simde_mm_set_epi32(INT32_C(-1443374135), INT32_C( 1382394218), INT32_C( 1459905767), INT32_C( -756048058)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1443374135.00), SIMDE_FLOAT64_C(1382394218.00),
                         SIMDE_FLOAT64_C(1459905767.00), SIMDE_FLOAT64_C(-756048058.00)) },
    { simde_mm_set_epi32(INT32_C( -781596301), INT32_C( 1840524706), INT32_C( 1502138952), INT32_C(-2118210723)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-781596301.00), SIMDE_FLOAT64_C(1840524706.00),
                         SIMDE_FLOAT64_C(1502138952.00), SIMDE_FLOAT64_C(-2118210723.00)) },
    { simde_mm_set_epi32(INT32_C(   52250967), INT32_C( 1988701031), INT32_C( 1592626424), INT32_C(-1778387557)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(52250967.00), SIMDE_FLOAT64_C(1988701031.00),
                         SIMDE_FLOAT64_C(1592626424.00), SIMDE_FLOAT64_C(-1778387557.00)) },
    { simde_mm_set_epi32(INT32_C(   30979646), INT32_C(  769206580), INT32_C(-2128276240), INT32_C( 1445709709)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(30979646.00), SIMDE_FLOAT64_C(769206580.00),
                         SIMDE_FLOAT64_C(-2128276240.00), SIMDE_FLOAT64_C(1445709709.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_cvtepi32_pd(test_vec[i].a);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtepi32_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(      -6033), INT32_C(      15813), INT32_C(      12979), INT32_C(     -31712),
                            INT32_C(      18002), INT32_C(      -6019), INT32_C(     -26810), INT32_C(      14091)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-6033.00), SIMDE_FLOAT32_C(15813.00),
                         SIMDE_FLOAT32_C(12979.00), SIMDE_FLOAT32_C(-31712.00),
                         SIMDE_FLOAT32_C(18002.00), SIMDE_FLOAT32_C(-6019.00),
                         SIMDE_FLOAT32_C(-26810.00), SIMDE_FLOAT32_C(14091.00)) },
    { simde_mm256_set_epi32(INT32_C(       6359), INT32_C(       7786), INT32_C(      21856), INT32_C(     -20706),
                            INT32_C(     -20652), INT32_C(      21040), INT32_C(      -8561), INT32_C(     -12779)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 6359.00), SIMDE_FLOAT32_C( 7786.00),
                         SIMDE_FLOAT32_C(21856.00), SIMDE_FLOAT32_C(-20706.00),
                         SIMDE_FLOAT32_C(-20652.00), SIMDE_FLOAT32_C(21040.00),
                         SIMDE_FLOAT32_C(-8561.00), SIMDE_FLOAT32_C(-12779.00)) },
    { simde_mm256_set_epi32(INT32_C(     -28477), INT32_C(     -21667), INT32_C(     -16892), INT32_C(     -16024),
                            INT32_C(     -11576), INT32_C(        602), INT32_C(      23902), INT32_C(      17547)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-28477.00), SIMDE_FLOAT32_C(-21667.00),
                         SIMDE_FLOAT32_C(-16892.00), SIMDE_FLOAT32_C(-16024.00),
                         SIMDE_FLOAT32_C(-11576.00), SIMDE_FLOAT32_C(  602.00),
                         SIMDE_FLOAT32_C(23902.00), SIMDE_FLOAT32_C(17547.00)) },
    { simde_mm256_set_epi32(INT32_C(       8732), INT32_C(      13948), INT32_C(       7489), INT32_C(      25724),
                            INT32_C(      24561), INT32_C(      11189), INT32_C(      24773), INT32_C(      -8467)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 8732.00), SIMDE_FLOAT32_C(13948.00),
                         SIMDE_FLOAT32_C( 7489.00), SIMDE_FLOAT32_C(25724.00),
                         SIMDE_FLOAT32_C(24561.00), SIMDE_FLOAT32_C(11189.00),
                         SIMDE_FLOAT32_C(24773.00), SIMDE_FLOAT32_C(-8467.00)) },
    { simde_mm256_set_epi32(INT32_C(     -31943), INT32_C(      26870), INT32_C(     -22515), INT32_C(       3030),
                            INT32_C(      24358), INT32_C(      31924), INT32_C(      30771), INT32_C(       4777)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-31943.00), SIMDE_FLOAT32_C(26870.00),
                         SIMDE_FLOAT32_C(-22515.00), SIMDE_FLOAT32_C( 3030.00),
                         SIMDE_FLOAT32_C(24358.00), SIMDE_FLOAT32_C(31924.00),
                         SIMDE_FLOAT32_C(30771.00), SIMDE_FLOAT32_C( 4777.00)) },
    { simde_mm256_set_epi32(INT32_C(      -1809), INT32_C(     -14404), INT32_C(     -32286), INT32_C(      25399),
                            INT32_C(      29260), INT32_C(     -23412), INT32_C(      12480), INT32_C(     -23461)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-1809.00), SIMDE_FLOAT32_C(-14404.00),
                         SIMDE_FLOAT32_C(-32286.00), SIMDE_FLOAT32_C(25399.00),
                         SIMDE_FLOAT32_C(29260.00), SIMDE_FLOAT32_C(-23412.00),
                         SIMDE_FLOAT32_C(12480.00), SIMDE_FLOAT32_C(-23461.00)) },
    { simde_mm256_set_epi32(INT32_C(      -2274), INT32_C(      23698), INT32_C(       4976), INT32_C(      13398),
                            INT32_C(      -8046), INT32_C(     -16937), INT32_C(      19340), INT32_C(      -6656)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-2274.00), SIMDE_FLOAT32_C(23698.00),
                         SIMDE_FLOAT32_C( 4976.00), SIMDE_FLOAT32_C(13398.00),
                         SIMDE_FLOAT32_C(-8046.00), SIMDE_FLOAT32_C(-16937.00),
                         SIMDE_FLOAT32_C(19340.00), SIMDE_FLOAT32_C(-6656.00)) },
    { simde_mm256_set_epi32(INT32_C(     -29605), INT32_C(       8888), INT32_C(      -8347), INT32_C(      -8890),
                            INT32_C(      -8372), INT32_C(       7334), INT32_C(      14947), INT32_C(      -5546)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-29605.00), SIMDE_FLOAT32_C( 8888.00),
                         SIMDE_FLOAT32_C(-8347.00), SIMDE_FLOAT32_C(-8890.00),
                         SIMDE_FLOAT32_C(-8372.00), SIMDE_FLOAT32_C( 7334.00),
                         SIMDE_FLOAT32_C(14947.00), SIMDE_FLOAT32_C(-5546.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_cvtepi32_ps(test_vec[i].a);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  675.83), SIMDE_FLOAT32_C(  732.26),
                         SIMDE_FLOAT32_C(   -4.57), SIMDE_FLOAT32_C( -168.80),
                         SIMDE_FLOAT32_C( -520.00), SIMDE_FLOAT32_C( -692.17),
                         SIMDE_FLOAT32_C(  934.56), SIMDE_FLOAT32_C(  631.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -378.09), SIMDE_FLOAT32_C( -656.19),
                         SIMDE_FLOAT32_C( -265.99), SIMDE_FLOAT32_C( -457.08),
                         SIMDE_FLOAT32_C( -481.51), SIMDE_FLOAT32_C(  732.73),
                         SIMDE_FLOAT32_C(  321.36), SIMDE_FLOAT32_C( -269.65)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -1.79), SIMDE_FLOAT32_C(   -1.12),
                         SIMDE_FLOAT32_C(    0.02), SIMDE_FLOAT32_C(    0.37),
                         SIMDE_FLOAT32_C(    1.08), SIMDE_FLOAT32_C(   -0.94),
                         SIMDE_FLOAT32_C(    2.91), SIMDE_FLOAT32_C(   -2.34)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  118.79), SIMDE_FLOAT32_C(  887.62),
                         SIMDE_FLOAT32_C(  493.85), SIMDE_FLOAT32_C( -554.19),
                         SIMDE_FLOAT32_C(  954.00), SIMDE_FLOAT32_C( -438.20),
                         SIMDE_FLOAT32_C(  457.40), SIMDE_FLOAT32_C( -597.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  136.05), SIMDE_FLOAT32_C( -648.50),
                         SIMDE_FLOAT32_C(  975.99), SIMDE_FLOAT32_C(  125.14),
                         SIMDE_FLOAT32_C(  391.49), SIMDE_FLOAT32_C( -989.28),
                         SIMDE_FLOAT32_C( -980.53), SIMDE_FLOAT32_C(  107.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.87), SIMDE_FLOAT32_C(   -1.37),
                         SIMDE_FLOAT32_C(    0.51), SIMDE_FLOAT32_C(   -4.43),
                         SIMDE_FLOAT32_C(    2.44), SIMDE_FLOAT32_C(    0.44),
                         SIMDE_FLOAT32_C(   -0.47), SIMDE_FLOAT32_C(   -5.57)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  788.25), SIMDE_FLOAT32_C( -786.20),
                         SIMDE_FLOAT32_C( -386.26), SIMDE_FLOAT32_C( -761.33),
                         SIMDE_FLOAT32_C(  307.75), SIMDE_FLOAT32_C(  863.78),
                         SIMDE_FLOAT32_C(  634.25), SIMDE_FLOAT32_C(  687.96)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  593.79), SIMDE_FLOAT32_C( -856.02),
                         SIMDE_FLOAT32_C(  504.54), SIMDE_FLOAT32_C(  553.51),
                         SIMDE_FLOAT32_C(  287.73), SIMDE_FLOAT32_C( -351.53),
                         SIMDE_FLOAT32_C( -572.54), SIMDE_FLOAT32_C(  264.37)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    1.33), SIMDE_FLOAT32_C(    0.92),
                         SIMDE_FLOAT32_C(   -0.77), SIMDE_FLOAT32_C(   -1.38),
                         SIMDE_FLOAT32_C(    1.07), SIMDE_FLOAT32_C(   -2.46),
                         SIMDE_FLOAT32_C(   -1.11), SIMDE_FLOAT32_C(    2.60)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  139.28), SIMDE_FLOAT32_C(  906.17),
                         SIMDE_FLOAT32_C(  486.23), SIMDE_FLOAT32_C(  556.78),
                         SIMDE_FLOAT32_C( -178.50), SIMDE_FLOAT32_C( -222.99),
                         SIMDE_FLOAT32_C(  642.44), SIMDE_FLOAT32_C(  839.86)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -272.29), SIMDE_FLOAT32_C( -752.32),
                         SIMDE_FLOAT32_C( -335.75), SIMDE_FLOAT32_C( -704.13),
                         SIMDE_FLOAT32_C(  526.15), SIMDE_FLOAT32_C( -407.90),
                         SIMDE_FLOAT32_C(  -13.13), SIMDE_FLOAT32_C( -893.18)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.51), SIMDE_FLOAT32_C(   -1.20),
                         SIMDE_FLOAT32_C(   -1.45), SIMDE_FLOAT32_C(   -0.79),
                         SIMDE_FLOAT32_C(   -0.34), SIMDE_FLOAT32_C(    0.55),
                         SIMDE_FLOAT32_C(  -48.93), SIMDE_FLOAT32_C(   -0.94)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -332.01), SIMDE_FLOAT32_C( -279.46),
                         SIMDE_FLOAT32_C(  360.69), SIMDE_FLOAT32_C( -121.43),
                         SIMDE_FLOAT32_C(  819.79), SIMDE_FLOAT32_C(  512.44),
                         SIMDE_FLOAT32_C( -185.75), SIMDE_FLOAT32_C(  503.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  621.10), SIMDE_FLOAT32_C(  514.79),
                         SIMDE_FLOAT32_C( -672.95), SIMDE_FLOAT32_C(  -62.01),
                         SIMDE_FLOAT32_C( -155.11), SIMDE_FLOAT32_C(  518.20),
                         SIMDE_FLOAT32_C( -704.10), SIMDE_FLOAT32_C( -249.95)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.53), SIMDE_FLOAT32_C(   -0.54),
                         SIMDE_FLOAT32_C(   -0.54), SIMDE_FLOAT32_C(    1.96),
                         SIMDE_FLOAT32_C(   -5.29), SIMDE_FLOAT32_C(    0.99),
                         SIMDE_FLOAT32_C(    0.26), SIMDE_FLOAT32_C(   -2.01)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -784.88), SIMDE_FLOAT32_C( -855.22),
                         SIMDE_FLOAT32_C( -347.04), SIMDE_FLOAT32_C( -241.02),
                         SIMDE_FLOAT32_C(  748.57), SIMDE_FLOAT32_C( -179.02),
                         SIMDE_FLOAT32_C( -995.77), SIMDE_FLOAT32_C( -927.09)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  868.43), SIMDE_FLOAT32_C(    9.90),
                         SIMDE_FLOAT32_C( -308.85), SIMDE_FLOAT32_C( -944.06),
                         SIMDE_FLOAT32_C( -323.62), SIMDE_FLOAT32_C(  739.02),
                         SIMDE_FLOAT32_C(  -61.38), SIMDE_FLOAT32_C(  426.14)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.90), SIMDE_FLOAT32_C(  -86.39),
                         SIMDE_FLOAT32_C(    1.12), SIMDE_FLOAT32_C(    0.26),
                         SIMDE_FLOAT32_C(   -2.31), SIMDE_FLOAT32_C(   -0.24),
                         SIMDE_FLOAT32_C(   16.22), SIMDE_FLOAT32_C(   -2.18)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  307.07), SIMDE_FLOAT32_C(  591.05),
                         SIMDE_FLOAT32_C( -630.36), SIMDE_FLOAT32_C(  826.28),
                         SIMDE_FLOAT32_C( -436.93), SIMDE_FLOAT32_C(  982.53),
                         SIMDE_FLOAT32_C( -808.08), SIMDE_FLOAT32_C(  630.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -339.08), SIMDE_FLOAT32_C( -235.71),
                         SIMDE_FLOAT32_C( -196.92), SIMDE_FLOAT32_C(   27.62),
                         SIMDE_FLOAT32_C( -443.69), SIMDE_FLOAT32_C(  242.35),
                         SIMDE_FLOAT32_C(  774.01), SIMDE_FLOAT32_C(  833.91)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.91), SIMDE_FLOAT32_C(   -2.51),
                         SIMDE_FLOAT32_C(    3.20), SIMDE_FLOAT32_C(   29.92),
                         SIMDE_FLOAT32_C(    0.98), SIMDE_FLOAT32_C(    4.05),
                         SIMDE_FLOAT32_C(   -1.04), SIMDE_FLOAT32_C(    0.76)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -830.19), SIMDE_FLOAT32_C( -620.56),
                         SIMDE_FLOAT32_C( -306.38), SIMDE_FLOAT32_C( -602.04),
                         SIMDE_FLOAT32_C(  183.46), SIMDE_FLOAT32_C(  824.79),
                         SIMDE_FLOAT32_C( -492.06), SIMDE_FLOAT32_C( -609.65)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -335.15), SIMDE_FLOAT32_C( -390.73),
                         SIMDE_FLOAT32_C(  951.40), SIMDE_FLOAT32_C(  398.19),
                         SIMDE_FLOAT32_C(  181.71), SIMDE_FLOAT32_C( -932.03),
                         SIMDE_FLOAT32_C(  887.77), SIMDE_FLOAT32_C(  257.75)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    2.48), SIMDE_FLOAT32_C(    1.59),
                         SIMDE_FLOAT32_C(   -0.32), SIMDE_FLOAT32_C(   -1.51),
                         SIMDE_FLOAT32_C(    1.01), SIMDE_FLOAT32_C(   -0.88),
                         SIMDE_FLOAT32_C(   -0.55), SIMDE_FLOAT32_C(   -2.37)) }
  };
  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_div_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   42.76), SIMDE_FLOAT64_C(  925.42),
                         SIMDE_FLOAT64_C(  624.80), SIMDE_FLOAT64_C(  413.87)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -621.50), SIMDE_FLOAT64_C( -651.30),
                         SIMDE_FLOAT64_C( -233.59), SIMDE_FLOAT64_C( -713.35)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.07), SIMDE_FLOAT64_C(   -1.42),
                         SIMDE_FLOAT64_C(   -2.67), SIMDE_FLOAT64_C(   -0.58)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  275.93), SIMDE_FLOAT64_C(  360.88),
                         SIMDE_FLOAT64_C(   -7.47), SIMDE_FLOAT64_C( -347.34)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  479.86), SIMDE_FLOAT64_C(  205.26),
                         SIMDE_FLOAT64_C(  174.68), SIMDE_FLOAT64_C(  363.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.58), SIMDE_FLOAT64_C(    1.76),
                         SIMDE_FLOAT64_C(   -0.04), SIMDE_FLOAT64_C(   -0.96)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  977.82), SIMDE_FLOAT64_C(  875.25),
                         SIMDE_FLOAT64_C(  775.86), SIMDE_FLOAT64_C(  314.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -748.72), SIMDE_FLOAT64_C(  258.24),
                         SIMDE_FLOAT64_C( -578.49), SIMDE_FLOAT64_C( -708.35)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -1.31), SIMDE_FLOAT64_C(    3.39),
                         SIMDE_FLOAT64_C(   -1.34), SIMDE_FLOAT64_C(   -0.44)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  617.56), SIMDE_FLOAT64_C( -254.21),
                         SIMDE_FLOAT64_C( -890.06), SIMDE_FLOAT64_C( -996.38)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -247.08), SIMDE_FLOAT64_C(  661.94),
                         SIMDE_FLOAT64_C( -120.93), SIMDE_FLOAT64_C( -574.61)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -2.50), SIMDE_FLOAT64_C(   -0.38),
                         SIMDE_FLOAT64_C(    7.36), SIMDE_FLOAT64_C(    1.73)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -932.29), SIMDE_FLOAT64_C( -263.62),
                         SIMDE_FLOAT64_C( -571.69), SIMDE_FLOAT64_C(  -83.26)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  395.02), SIMDE_FLOAT64_C(  290.85),
                         SIMDE_FLOAT64_C( -853.00), SIMDE_FLOAT64_C(  928.61)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -2.36), SIMDE_FLOAT64_C(   -0.91),
                         SIMDE_FLOAT64_C(    0.67), SIMDE_FLOAT64_C(   -0.09)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -109.60), SIMDE_FLOAT64_C( -812.14),
                         SIMDE_FLOAT64_C( -474.36), SIMDE_FLOAT64_C( -732.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -982.62), SIMDE_FLOAT64_C( -995.34),
                         SIMDE_FLOAT64_C(  -51.94), SIMDE_FLOAT64_C(  973.17)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.11), SIMDE_FLOAT64_C(    0.82),
                         SIMDE_FLOAT64_C(    9.13), SIMDE_FLOAT64_C(   -0.75)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -826.31), SIMDE_FLOAT64_C( -333.99),
                         SIMDE_FLOAT64_C( -238.49), SIMDE_FLOAT64_C( -706.13)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  929.44), SIMDE_FLOAT64_C(  493.44),
                         SIMDE_FLOAT64_C( -539.23), SIMDE_FLOAT64_C( -683.88)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.89), SIMDE_FLOAT64_C(   -0.68),
                         SIMDE_FLOAT64_C(    0.44), SIMDE_FLOAT64_C(    1.03)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  419.98), SIMDE_FLOAT64_C(  -51.88),
                         SIMDE_FLOAT64_C( -580.15), SIMDE_FLOAT64_C( -198.88)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  246.03), SIMDE_FLOAT64_C( -149.94),
                         SIMDE_FLOAT64_C( -107.67), SIMDE_FLOAT64_C(  875.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    1.71), SIMDE_FLOAT64_C(    0.35),
                         SIMDE_FLOAT64_C(    5.39), SIMDE_FLOAT64_C(   -0.23)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_div_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_floor_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  520.72), SIMDE_FLOAT32_C(  834.16),
                         SIMDE_FLOAT32_C( -945.36), SIMDE_FLOAT32_C( -135.41),
                         SIMDE_FLOAT32_C(  289.19), SIMDE_FLOAT32_C(  462.54),
                         SIMDE_FLOAT32_C( -937.67), SIMDE_FLOAT32_C(  706.09)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  520.00), SIMDE_FLOAT32_C(  834.00),
                         SIMDE_FLOAT32_C( -946.00), SIMDE_FLOAT32_C( -136.00),
                         SIMDE_FLOAT32_C(  289.00), SIMDE_FLOAT32_C(  462.00),
                         SIMDE_FLOAT32_C( -938.00), SIMDE_FLOAT32_C(  706.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -9.00), SIMDE_FLOAT32_C(  401.24),
                         SIMDE_FLOAT32_C(  899.70), SIMDE_FLOAT32_C( -258.03),
                         SIMDE_FLOAT32_C( -634.92), SIMDE_FLOAT32_C( -438.26),
                         SIMDE_FLOAT32_C(  433.94), SIMDE_FLOAT32_C( -170.51)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -9.00), SIMDE_FLOAT32_C(  401.00),
                         SIMDE_FLOAT32_C(  899.00), SIMDE_FLOAT32_C( -259.00),
                         SIMDE_FLOAT32_C( -635.00), SIMDE_FLOAT32_C( -439.00),
                         SIMDE_FLOAT32_C(  433.00), SIMDE_FLOAT32_C( -171.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -908.95), SIMDE_FLOAT32_C( -376.33),
                         SIMDE_FLOAT32_C( -639.88), SIMDE_FLOAT32_C(   40.45),
                         SIMDE_FLOAT32_C( -431.46), SIMDE_FLOAT32_C( -404.49),
                         SIMDE_FLOAT32_C( -411.60), SIMDE_FLOAT32_C(  531.65)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -909.00), SIMDE_FLOAT32_C( -377.00),
                         SIMDE_FLOAT32_C( -640.00), SIMDE_FLOAT32_C(   40.00),
                         SIMDE_FLOAT32_C( -432.00), SIMDE_FLOAT32_C( -405.00),
                         SIMDE_FLOAT32_C( -412.00), SIMDE_FLOAT32_C(  531.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -394.79), SIMDE_FLOAT32_C( -654.48),
                         SIMDE_FLOAT32_C(  223.95), SIMDE_FLOAT32_C( -557.45),
                         SIMDE_FLOAT32_C(  908.61), SIMDE_FLOAT32_C( -493.34),
                         SIMDE_FLOAT32_C(  466.68), SIMDE_FLOAT32_C( -301.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -395.00), SIMDE_FLOAT32_C( -655.00),
                         SIMDE_FLOAT32_C(  223.00), SIMDE_FLOAT32_C( -558.00),
                         SIMDE_FLOAT32_C(  908.00), SIMDE_FLOAT32_C( -494.00),
                         SIMDE_FLOAT32_C(  466.00), SIMDE_FLOAT32_C( -302.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -5.40), SIMDE_FLOAT32_C(  828.84),
                         SIMDE_FLOAT32_C(  468.99), SIMDE_FLOAT32_C(  665.66),
                         SIMDE_FLOAT32_C( -648.14), SIMDE_FLOAT32_C( -841.90),
                         SIMDE_FLOAT32_C( -380.33), SIMDE_FLOAT32_C(  740.32)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -6.00), SIMDE_FLOAT32_C(  828.00),
                         SIMDE_FLOAT32_C(  468.00), SIMDE_FLOAT32_C(  665.00),
                         SIMDE_FLOAT32_C( -649.00), SIMDE_FLOAT32_C( -842.00),
                         SIMDE_FLOAT32_C( -381.00), SIMDE_FLOAT32_C(  740.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -752.16), SIMDE_FLOAT32_C( -655.98),
                         SIMDE_FLOAT32_C(  902.13), SIMDE_FLOAT32_C(  972.30),
                         SIMDE_FLOAT32_C( -497.57), SIMDE_FLOAT32_C( -530.16),
                         SIMDE_FLOAT32_C( -966.55), SIMDE_FLOAT32_C(  570.95)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -753.00), SIMDE_FLOAT32_C( -656.00),
                         SIMDE_FLOAT32_C(  902.00), SIMDE_FLOAT32_C(  972.00),
                         SIMDE_FLOAT32_C( -498.00), SIMDE_FLOAT32_C( -531.00),
                         SIMDE_FLOAT32_C( -967.00), SIMDE_FLOAT32_C(  570.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  723.18), SIMDE_FLOAT32_C(  202.51),
                         SIMDE_FLOAT32_C(  -41.39), SIMDE_FLOAT32_C( -372.98),
                         SIMDE_FLOAT32_C(  697.91), SIMDE_FLOAT32_C( -303.11),
                         SIMDE_FLOAT32_C( -180.07), SIMDE_FLOAT32_C(  941.44)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  723.00), SIMDE_FLOAT32_C(  202.00),
                         SIMDE_FLOAT32_C(  -42.00), SIMDE_FLOAT32_C( -373.00),
                         SIMDE_FLOAT32_C(  697.00), SIMDE_FLOAT32_C( -304.00),
                         SIMDE_FLOAT32_C( -181.00), SIMDE_FLOAT32_C(  941.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  995.24), SIMDE_FLOAT32_C(   68.12),
                         SIMDE_FLOAT32_C(  284.41), SIMDE_FLOAT32_C(  723.96),
                         SIMDE_FLOAT32_C( -373.95), SIMDE_FLOAT32_C(   15.43),
                         SIMDE_FLOAT32_C( -498.85), SIMDE_FLOAT32_C(  581.12)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  995.00), SIMDE_FLOAT32_C(   68.00),
                         SIMDE_FLOAT32_C(  284.00), SIMDE_FLOAT32_C(  723.00),
                         SIMDE_FLOAT32_C( -374.00), SIMDE_FLOAT32_C(   15.00),
                         SIMDE_FLOAT32_C( -499.00), SIMDE_FLOAT32_C(  581.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_floor_ps(test_vec[i].a);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_floor_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -86.60), SIMDE_FLOAT64_C(  -29.62),
                         SIMDE_FLOAT64_C(  880.65), SIMDE_FLOAT64_C(  474.01)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -87.00), SIMDE_FLOAT64_C(  -30.00),
                         SIMDE_FLOAT64_C(  880.00), SIMDE_FLOAT64_C(  474.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  335.44), SIMDE_FLOAT64_C(   87.17),
                         SIMDE_FLOAT64_C(  264.70), SIMDE_FLOAT64_C(  435.92)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  335.00), SIMDE_FLOAT64_C(   87.00),
                         SIMDE_FLOAT64_C(  264.00), SIMDE_FLOAT64_C(  435.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  657.73), SIMDE_FLOAT64_C( -255.01),
                         SIMDE_FLOAT64_C( -236.61), SIMDE_FLOAT64_C(  198.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  657.00), SIMDE_FLOAT64_C( -256.00),
                         SIMDE_FLOAT64_C( -237.00), SIMDE_FLOAT64_C(  198.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -459.75), SIMDE_FLOAT64_C(  234.86),
                         SIMDE_FLOAT64_C( -517.66), SIMDE_FLOAT64_C( -561.05)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -460.00), SIMDE_FLOAT64_C(  234.00),
                         SIMDE_FLOAT64_C( -518.00), SIMDE_FLOAT64_C( -562.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -815.90), SIMDE_FLOAT64_C( -973.26),
                         SIMDE_FLOAT64_C( -704.97), SIMDE_FLOAT64_C(  629.57)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -816.00), SIMDE_FLOAT64_C( -974.00),
                         SIMDE_FLOAT64_C( -705.00), SIMDE_FLOAT64_C(  629.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -147.09), SIMDE_FLOAT64_C( -283.85),
                         SIMDE_FLOAT64_C(   91.60), SIMDE_FLOAT64_C( -808.32)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -148.00), SIMDE_FLOAT64_C( -284.00),
                         SIMDE_FLOAT64_C(   91.00), SIMDE_FLOAT64_C( -809.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  346.15), SIMDE_FLOAT64_C( -862.92),
                         SIMDE_FLOAT64_C( -616.19), SIMDE_FLOAT64_C( -434.01)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  346.00), SIMDE_FLOAT64_C( -863.00),
                         SIMDE_FLOAT64_C( -617.00), SIMDE_FLOAT64_C( -435.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -593.06), SIMDE_FLOAT64_C( -286.08),
                         SIMDE_FLOAT64_C(  351.32), SIMDE_FLOAT64_C(  -29.06)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -594.00), SIMDE_FLOAT64_C( -287.00),
                         SIMDE_FLOAT64_C(  351.00), SIMDE_FLOAT64_C(  -30.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_floor_pd(test_vec[i].a);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_hadd_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -626.68), SIMDE_FLOAT32_C( -596.09),
                         SIMDE_FLOAT32_C( -988.19), SIMDE_FLOAT32_C(  961.65),
                         SIMDE_FLOAT32_C(  518.43), SIMDE_FLOAT32_C(  334.09),
                         SIMDE_FLOAT32_C(  212.95), SIMDE_FLOAT32_C( -488.35)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -361.77), SIMDE_FLOAT32_C(  121.01),
                         SIMDE_FLOAT32_C( -252.45), SIMDE_FLOAT32_C(  920.40),
                         SIMDE_FLOAT32_C( -660.15), SIMDE_FLOAT32_C( -869.23),
                         SIMDE_FLOAT32_C(  372.46), SIMDE_FLOAT32_C(  408.66)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -240.76), SIMDE_FLOAT32_C(  667.95),
                         SIMDE_FLOAT32_C(-1222.77), SIMDE_FLOAT32_C(  -26.54),
                         SIMDE_FLOAT32_C(-1529.38), SIMDE_FLOAT32_C(  781.12),
                         SIMDE_FLOAT32_C(  852.52), SIMDE_FLOAT32_C( -275.40)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  781.58), SIMDE_FLOAT32_C(  111.71),
                         SIMDE_FLOAT32_C( -214.03), SIMDE_FLOAT32_C( -280.14),
                         SIMDE_FLOAT32_C(  285.11), SIMDE_FLOAT32_C( -159.71),
                         SIMDE_FLOAT32_C(  737.74), SIMDE_FLOAT32_C(  159.06)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -542.95), SIMDE_FLOAT32_C(  311.99),
                         SIMDE_FLOAT32_C( -695.66), SIMDE_FLOAT32_C( -563.82),
                         SIMDE_FLOAT32_C( -378.07), SIMDE_FLOAT32_C(  160.57),
                         SIMDE_FLOAT32_C(  591.32), SIMDE_FLOAT32_C(  -15.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -230.96), SIMDE_FLOAT32_C(-1259.48),
                         SIMDE_FLOAT32_C(  893.29), SIMDE_FLOAT32_C( -494.17),
                         SIMDE_FLOAT32_C( -217.50), SIMDE_FLOAT32_C(  575.44),
                         SIMDE_FLOAT32_C(  125.40), SIMDE_FLOAT32_C(  896.80)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -397.87), SIMDE_FLOAT32_C(  582.70),
                         SIMDE_FLOAT32_C(  728.77), SIMDE_FLOAT32_C(  563.76),
                         SIMDE_FLOAT32_C( -874.44), SIMDE_FLOAT32_C( -323.73),
                         SIMDE_FLOAT32_C(  191.14), SIMDE_FLOAT32_C( -425.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  398.85), SIMDE_FLOAT32_C(  435.48),
                         SIMDE_FLOAT32_C( -736.85), SIMDE_FLOAT32_C( -251.61),
                         SIMDE_FLOAT32_C(  363.70), SIMDE_FLOAT32_C( -850.74),
                         SIMDE_FLOAT32_C(  513.62), SIMDE_FLOAT32_C(  893.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  834.33), SIMDE_FLOAT32_C( -988.46),
                         SIMDE_FLOAT32_C(  184.83), SIMDE_FLOAT32_C( 1292.53),
                         SIMDE_FLOAT32_C( -487.04), SIMDE_FLOAT32_C( 1406.85),
                         SIMDE_FLOAT32_C(-1198.17), SIMDE_FLOAT32_C( -234.16)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -659.61), SIMDE_FLOAT32_C( -996.22),
                         SIMDE_FLOAT32_C(  426.97), SIMDE_FLOAT32_C(   60.91),
                         SIMDE_FLOAT32_C(  175.17), SIMDE_FLOAT32_C(  226.61),
                         SIMDE_FLOAT32_C(  234.99), SIMDE_FLOAT32_C(  755.38)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -152.71), SIMDE_FLOAT32_C(  857.34),
                         SIMDE_FLOAT32_C(  403.84), SIMDE_FLOAT32_C( -862.22),
                         SIMDE_FLOAT32_C(  782.97), SIMDE_FLOAT32_C(  437.87),
                         SIMDE_FLOAT32_C(  825.47), SIMDE_FLOAT32_C(  915.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  704.63), SIMDE_FLOAT32_C( -458.38),
                         SIMDE_FLOAT32_C(-1655.83), SIMDE_FLOAT32_C(  487.88),
                         SIMDE_FLOAT32_C( 1220.84), SIMDE_FLOAT32_C( 1740.75),
                         SIMDE_FLOAT32_C(  401.78), SIMDE_FLOAT32_C(  990.37)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -564.13), SIMDE_FLOAT32_C( -973.32),
                         SIMDE_FLOAT32_C(  233.13), SIMDE_FLOAT32_C(  504.79),
                         SIMDE_FLOAT32_C(  857.55), SIMDE_FLOAT32_C(  275.11),
                         SIMDE_FLOAT32_C(  643.61), SIMDE_FLOAT32_C(  -70.12)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -709.38), SIMDE_FLOAT32_C(  310.06),
                         SIMDE_FLOAT32_C( -793.34), SIMDE_FLOAT32_C( -947.00),
                         SIMDE_FLOAT32_C( -974.52), SIMDE_FLOAT32_C(  878.25),
                         SIMDE_FLOAT32_C( -856.10), SIMDE_FLOAT32_C(  529.04)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -399.32), SIMDE_FLOAT32_C(-1740.34),
                         SIMDE_FLOAT32_C(-1537.45), SIMDE_FLOAT32_C(  737.92),
                         SIMDE_FLOAT32_C(  -96.27), SIMDE_FLOAT32_C( -327.06),
                         SIMDE_FLOAT32_C( 1132.66), SIMDE_FLOAT32_C(  573.49)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  733.99), SIMDE_FLOAT32_C( -737.47),
                         SIMDE_FLOAT32_C( -603.71), SIMDE_FLOAT32_C(  863.52),
                         SIMDE_FLOAT32_C( -639.50), SIMDE_FLOAT32_C(  474.16),
                         SIMDE_FLOAT32_C(  816.39), SIMDE_FLOAT32_C(   75.56)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  412.95), SIMDE_FLOAT32_C(  396.26),
                         SIMDE_FLOAT32_C(  519.43), SIMDE_FLOAT32_C( -413.53),
                         SIMDE_FLOAT32_C( -676.69), SIMDE_FLOAT32_C( -335.15),
                         SIMDE_FLOAT32_C(  961.37), SIMDE_FLOAT32_C(  820.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  809.21), SIMDE_FLOAT32_C(  105.90),
                         SIMDE_FLOAT32_C(   -3.48), SIMDE_FLOAT32_C(  259.81),
                         SIMDE_FLOAT32_C(-1011.84), SIMDE_FLOAT32_C( 1781.47),
                         SIMDE_FLOAT32_C( -165.34), SIMDE_FLOAT32_C(  891.95)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -149.16), SIMDE_FLOAT32_C( -430.29),
                         SIMDE_FLOAT32_C( -817.18), SIMDE_FLOAT32_C(  272.68),
                         SIMDE_FLOAT32_C( -899.55), SIMDE_FLOAT32_C( -654.95),
                         SIMDE_FLOAT32_C(  148.93), SIMDE_FLOAT32_C(  957.05)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -940.60), SIMDE_FLOAT32_C(  528.45),
                         SIMDE_FLOAT32_C(  574.67), SIMDE_FLOAT32_C(  993.90),
                         SIMDE_FLOAT32_C( -532.80), SIMDE_FLOAT32_C( -214.29),
                         SIMDE_FLOAT32_C( -506.86), SIMDE_FLOAT32_C(  389.73)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -412.15), SIMDE_FLOAT32_C( 1568.57),
                         SIMDE_FLOAT32_C( -579.45), SIMDE_FLOAT32_C( -544.50),
                         SIMDE_FLOAT32_C( -747.09), SIMDE_FLOAT32_C( -117.13),
                         SIMDE_FLOAT32_C(-1554.50), SIMDE_FLOAT32_C( 1105.98)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -426.98), SIMDE_FLOAT32_C(  653.68),
                         SIMDE_FLOAT32_C(  854.01), SIMDE_FLOAT32_C( -871.75),
                         SIMDE_FLOAT32_C(   60.41), SIMDE_FLOAT32_C(  197.76),
                         SIMDE_FLOAT32_C( -611.16), SIMDE_FLOAT32_C(  848.76)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  243.99), SIMDE_FLOAT32_C( -967.54),
                         SIMDE_FLOAT32_C(  893.59), SIMDE_FLOAT32_C( -630.65),
                         SIMDE_FLOAT32_C( -132.65), SIMDE_FLOAT32_C( -434.90),
                         SIMDE_FLOAT32_C( -516.97), SIMDE_FLOAT32_C(  151.24)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -723.55), SIMDE_FLOAT32_C(  262.94),
                         SIMDE_FLOAT32_C(  226.70), SIMDE_FLOAT32_C(  -17.74),
                         SIMDE_FLOAT32_C( -567.55), SIMDE_FLOAT32_C( -365.73),
                         SIMDE_FLOAT32_C(  258.17), SIMDE_FLOAT32_C(  237.60)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_hadd_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_hadd_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -436.68), SIMDE_FLOAT64_C(  480.99),
                         SIMDE_FLOAT64_C( -278.34), SIMDE_FLOAT64_C(  588.89)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  130.14), SIMDE_FLOAT64_C( -927.67),
                         SIMDE_FLOAT64_C( -646.84), SIMDE_FLOAT64_C(  150.94)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -797.53), SIMDE_FLOAT64_C(   44.31),
                         SIMDE_FLOAT64_C( -495.90), SIMDE_FLOAT64_C(  310.55)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -433.18), SIMDE_FLOAT64_C(  708.48),
                         SIMDE_FLOAT64_C(  534.86), SIMDE_FLOAT64_C( -929.94)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  826.52), SIMDE_FLOAT64_C(   36.50),
                         SIMDE_FLOAT64_C(  561.99), SIMDE_FLOAT64_C( -293.03)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  863.02), SIMDE_FLOAT64_C(  275.30),
                         SIMDE_FLOAT64_C(  268.96), SIMDE_FLOAT64_C( -395.08)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  255.04), SIMDE_FLOAT64_C( -637.84),
                         SIMDE_FLOAT64_C( -513.11), SIMDE_FLOAT64_C( -599.83)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -910.36), SIMDE_FLOAT64_C( -799.15),
                         SIMDE_FLOAT64_C( -982.23), SIMDE_FLOAT64_C( -206.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1709.51), SIMDE_FLOAT64_C( -382.80),
                         SIMDE_FLOAT64_C(-1189.18), SIMDE_FLOAT64_C(-1112.94)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  149.87), SIMDE_FLOAT64_C(  274.56),
                         SIMDE_FLOAT64_C(  400.10), SIMDE_FLOAT64_C(  410.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  883.42), SIMDE_FLOAT64_C(   46.03),
                         SIMDE_FLOAT64_C( -600.38), SIMDE_FLOAT64_C(  131.34)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  929.45), SIMDE_FLOAT64_C(  424.43),
                         SIMDE_FLOAT64_C( -469.04), SIMDE_FLOAT64_C(  810.50)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -461.17), SIMDE_FLOAT64_C( -757.61),
                         SIMDE_FLOAT64_C( -114.45), SIMDE_FLOAT64_C(  853.48)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  397.09), SIMDE_FLOAT64_C( -444.66),
                         SIMDE_FLOAT64_C( -909.26), SIMDE_FLOAT64_C(  102.16)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -47.57), SIMDE_FLOAT64_C(-1218.78),
                         SIMDE_FLOAT64_C( -807.10), SIMDE_FLOAT64_C(  739.03)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -703.10), SIMDE_FLOAT64_C( -547.05),
                         SIMDE_FLOAT64_C( -158.62), SIMDE_FLOAT64_C( -256.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  137.64), SIMDE_FLOAT64_C( -342.68),
                         SIMDE_FLOAT64_C(  619.75), SIMDE_FLOAT64_C(  498.04)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -205.04), SIMDE_FLOAT64_C(-1250.15),
                         SIMDE_FLOAT64_C( 1117.79), SIMDE_FLOAT64_C( -415.32)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -818.29), SIMDE_FLOAT64_C(  196.32),
                         SIMDE_FLOAT64_C( -434.03), SIMDE_FLOAT64_C(   36.18)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -181.91), SIMDE_FLOAT64_C(  587.12),
                         SIMDE_FLOAT64_C( -318.37), SIMDE_FLOAT64_C(  -24.13)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  405.21), SIMDE_FLOAT64_C( -621.97),
                         SIMDE_FLOAT64_C( -342.50), SIMDE_FLOAT64_C( -397.85)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  129.06), SIMDE_FLOAT64_C( -240.83),
                         SIMDE_FLOAT64_C( -486.28), SIMDE_FLOAT64_C(  630.75)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  679.75), SIMDE_FLOAT64_C(  -37.94),
                         SIMDE_FLOAT64_C(  761.33), SIMDE_FLOAT64_C( -837.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  641.81), SIMDE_FLOAT64_C( -111.77),
                         SIMDE_FLOAT64_C(  -76.41), SIMDE_FLOAT64_C(  144.47)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_hadd_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_hsub_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -183.85), SIMDE_FLOAT32_C(  905.07),
                         SIMDE_FLOAT32_C( -962.47), SIMDE_FLOAT32_C(  739.25),
                         SIMDE_FLOAT32_C(   13.54), SIMDE_FLOAT32_C( -172.40),
                         SIMDE_FLOAT32_C(  456.21), SIMDE_FLOAT32_C(  164.33)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  959.87), SIMDE_FLOAT32_C(  500.02),
                         SIMDE_FLOAT32_C( -991.36), SIMDE_FLOAT32_C(  373.08),
                         SIMDE_FLOAT32_C( -962.56), SIMDE_FLOAT32_C( -502.91),
                         SIMDE_FLOAT32_C( -108.93), SIMDE_FLOAT32_C(  403.37)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -459.85), SIMDE_FLOAT32_C( 1364.44),
                         SIMDE_FLOAT32_C( 1088.92), SIMDE_FLOAT32_C( 1701.72),
                         SIMDE_FLOAT32_C(  459.65), SIMDE_FLOAT32_C(  512.30),
                         SIMDE_FLOAT32_C( -185.94), SIMDE_FLOAT32_C( -291.88)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  716.55), SIMDE_FLOAT32_C( -798.82),
                         SIMDE_FLOAT32_C(  -17.12), SIMDE_FLOAT32_C(  981.07),
                         SIMDE_FLOAT32_C( -241.05), SIMDE_FLOAT32_C(  266.35),
                         SIMDE_FLOAT32_C(  140.17), SIMDE_FLOAT32_C(  285.86)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  835.80), SIMDE_FLOAT32_C(  802.76),
                         SIMDE_FLOAT32_C( -745.28), SIMDE_FLOAT32_C( -228.38),
                         SIMDE_FLOAT32_C(  -44.09), SIMDE_FLOAT32_C(  991.15),
                         SIMDE_FLOAT32_C(  461.60), SIMDE_FLOAT32_C(   89.29)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -33.04), SIMDE_FLOAT32_C(  516.90),
                         SIMDE_FLOAT32_C(-1515.37), SIMDE_FLOAT32_C(  998.19),
                         SIMDE_FLOAT32_C( 1035.24), SIMDE_FLOAT32_C( -372.31),
                         SIMDE_FLOAT32_C(  507.40), SIMDE_FLOAT32_C(  145.69)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -323.55), SIMDE_FLOAT32_C( -835.05),
                         SIMDE_FLOAT32_C( -869.80), SIMDE_FLOAT32_C( -771.34),
                         SIMDE_FLOAT32_C( -342.71), SIMDE_FLOAT32_C(  374.92),
                         SIMDE_FLOAT32_C( -998.95), SIMDE_FLOAT32_C(   85.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -235.37), SIMDE_FLOAT32_C( -740.75),
                         SIMDE_FLOAT32_C(  568.96), SIMDE_FLOAT32_C(  984.74),
                         SIMDE_FLOAT32_C(  344.48), SIMDE_FLOAT32_C( -384.09),
                         SIMDE_FLOAT32_C( -746.69), SIMDE_FLOAT32_C(  666.35)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -505.38), SIMDE_FLOAT32_C(  415.78),
                         SIMDE_FLOAT32_C( -511.50), SIMDE_FLOAT32_C(   98.46),
                         SIMDE_FLOAT32_C( -728.57), SIMDE_FLOAT32_C( 1413.04),
                         SIMDE_FLOAT32_C(  717.63), SIMDE_FLOAT32_C( 1084.26)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  685.93), SIMDE_FLOAT32_C(  492.23),
                         SIMDE_FLOAT32_C(  668.17), SIMDE_FLOAT32_C( -421.85),
                         SIMDE_FLOAT32_C(  -93.75), SIMDE_FLOAT32_C( -819.96),
                         SIMDE_FLOAT32_C( -246.22), SIMDE_FLOAT32_C( -823.51)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  304.04), SIMDE_FLOAT32_C( -843.07),
                         SIMDE_FLOAT32_C( -204.07), SIMDE_FLOAT32_C( -879.53),
                         SIMDE_FLOAT32_C(  -83.04), SIMDE_FLOAT32_C( -516.58),
                         SIMDE_FLOAT32_C(  600.96), SIMDE_FLOAT32_C(   84.13)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-1147.11), SIMDE_FLOAT32_C( -675.46),
                         SIMDE_FLOAT32_C( -193.70), SIMDE_FLOAT32_C(-1090.02),
                         SIMDE_FLOAT32_C( -433.54), SIMDE_FLOAT32_C( -516.83),
                         SIMDE_FLOAT32_C( -726.21), SIMDE_FLOAT32_C( -577.29)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  492.05), SIMDE_FLOAT32_C( -121.48),
                         SIMDE_FLOAT32_C(  197.17), SIMDE_FLOAT32_C(  108.83),
                         SIMDE_FLOAT32_C( -910.74), SIMDE_FLOAT32_C( -610.63),
                         SIMDE_FLOAT32_C( -510.98), SIMDE_FLOAT32_C(  996.81)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -210.55), SIMDE_FLOAT32_C(  321.75),
                         SIMDE_FLOAT32_C( -949.93), SIMDE_FLOAT32_C(  547.84),
                         SIMDE_FLOAT32_C(  133.08), SIMDE_FLOAT32_C( -303.40),
                         SIMDE_FLOAT32_C(   47.44), SIMDE_FLOAT32_C( -236.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  532.30), SIMDE_FLOAT32_C( 1497.77),
                         SIMDE_FLOAT32_C( -613.53), SIMDE_FLOAT32_C(  -88.34),
                         SIMDE_FLOAT32_C( -436.48), SIMDE_FLOAT32_C( -283.94),
                         SIMDE_FLOAT32_C(  300.11), SIMDE_FLOAT32_C( 1507.79)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.77), SIMDE_FLOAT32_C( -920.82),
                         SIMDE_FLOAT32_C( -807.55), SIMDE_FLOAT32_C(  138.87),
                         SIMDE_FLOAT32_C(   34.09), SIMDE_FLOAT32_C( -826.98),
                         SIMDE_FLOAT32_C( -567.48), SIMDE_FLOAT32_C(  943.56)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -46.97), SIMDE_FLOAT32_C(  474.05),
                         SIMDE_FLOAT32_C(  -64.19), SIMDE_FLOAT32_C( -945.80),
                         SIMDE_FLOAT32_C( -873.08), SIMDE_FLOAT32_C( -569.02),
                         SIMDE_FLOAT32_C( -630.19), SIMDE_FLOAT32_C( -681.68)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  521.02), SIMDE_FLOAT32_C( -881.61),
                         SIMDE_FLOAT32_C(-1125.59), SIMDE_FLOAT32_C(  946.42),
                         SIMDE_FLOAT32_C(  304.06), SIMDE_FLOAT32_C(  -51.49),
                         SIMDE_FLOAT32_C( -861.07), SIMDE_FLOAT32_C( 1511.04)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  470.38), SIMDE_FLOAT32_C( -693.79),
                         SIMDE_FLOAT32_C( -843.14), SIMDE_FLOAT32_C( -640.08),
                         SIMDE_FLOAT32_C(  950.30), SIMDE_FLOAT32_C(  582.04),
                         SIMDE_FLOAT32_C( -585.94), SIMDE_FLOAT32_C(  175.69)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   45.69), SIMDE_FLOAT32_C(   38.77),
                         SIMDE_FLOAT32_C(  194.04), SIMDE_FLOAT32_C(  410.12),
                         SIMDE_FLOAT32_C(  -28.08), SIMDE_FLOAT32_C( -596.23),
                         SIMDE_FLOAT32_C(  -38.68), SIMDE_FLOAT32_C( -731.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -6.92), SIMDE_FLOAT32_C(  216.08),
                         SIMDE_FLOAT32_C(-1164.17), SIMDE_FLOAT32_C(  203.06),
                         SIMDE_FLOAT32_C( -568.15), SIMDE_FLOAT32_C( -692.49),
                         SIMDE_FLOAT32_C( -368.26), SIMDE_FLOAT32_C(  761.63)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -171.77), SIMDE_FLOAT32_C( -878.69),
                         SIMDE_FLOAT32_C( -337.47), SIMDE_FLOAT32_C( -864.26),
                         SIMDE_FLOAT32_C(  976.73), SIMDE_FLOAT32_C(  253.08),
                         SIMDE_FLOAT32_C(  134.24), SIMDE_FLOAT32_C( -737.89)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  167.53), SIMDE_FLOAT32_C( -453.33),
                         SIMDE_FLOAT32_C(   11.70), SIMDE_FLOAT32_C(  471.07),
                         SIMDE_FLOAT32_C( -269.64), SIMDE_FLOAT32_C(  547.27),
                         SIMDE_FLOAT32_C( -313.69), SIMDE_FLOAT32_C( -333.24)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -620.86), SIMDE_FLOAT32_C(  459.37),
                         SIMDE_FLOAT32_C( -706.92), SIMDE_FLOAT32_C( -526.79),
                         SIMDE_FLOAT32_C(  816.91), SIMDE_FLOAT32_C(  -19.55),
                         SIMDE_FLOAT32_C( -723.65), SIMDE_FLOAT32_C( -872.13)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_hsub_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_hsub_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -762.69), SIMDE_FLOAT64_C(  237.58),
                         SIMDE_FLOAT64_C(  832.53), SIMDE_FLOAT64_C(  -18.37)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  974.95), SIMDE_FLOAT64_C(  -69.86),
                         SIMDE_FLOAT64_C(   78.29), SIMDE_FLOAT64_C( -156.35)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1044.81), SIMDE_FLOAT64_C( 1000.27),
                         SIMDE_FLOAT64_C( -234.64), SIMDE_FLOAT64_C( -850.90)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  220.65), SIMDE_FLOAT64_C( -139.75),
                         SIMDE_FLOAT64_C( -707.34), SIMDE_FLOAT64_C( -798.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  397.80), SIMDE_FLOAT64_C( -497.83),
                         SIMDE_FLOAT64_C(  717.31), SIMDE_FLOAT64_C( -807.72)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -895.63), SIMDE_FLOAT64_C( -360.40),
                         SIMDE_FLOAT64_C(-1525.03), SIMDE_FLOAT64_C(  -91.42)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  105.63), SIMDE_FLOAT64_C(  306.00),
                         SIMDE_FLOAT64_C(  281.00), SIMDE_FLOAT64_C(  310.89)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -325.57), SIMDE_FLOAT64_C(  534.52),
                         SIMDE_FLOAT64_C(  987.26), SIMDE_FLOAT64_C(  787.06)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  860.09), SIMDE_FLOAT64_C(  200.37),
                         SIMDE_FLOAT64_C( -200.20), SIMDE_FLOAT64_C(   29.89)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  967.71), SIMDE_FLOAT64_C( -641.51),
                         SIMDE_FLOAT64_C( -759.32), SIMDE_FLOAT64_C(  -97.44)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  348.76), SIMDE_FLOAT64_C( -255.68),
                         SIMDE_FLOAT64_C(  982.70), SIMDE_FLOAT64_C(  155.49)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -604.44), SIMDE_FLOAT64_C(-1609.22),
                         SIMDE_FLOAT64_C( -827.21), SIMDE_FLOAT64_C(  661.88)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  679.95), SIMDE_FLOAT64_C( -269.56),
                         SIMDE_FLOAT64_C( -481.42), SIMDE_FLOAT64_C(  919.16)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -2.64), SIMDE_FLOAT64_C(  468.75),
                         SIMDE_FLOAT64_C(  -36.44), SIMDE_FLOAT64_C(  441.73)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  471.39), SIMDE_FLOAT64_C( -949.51),
                         SIMDE_FLOAT64_C(  478.17), SIMDE_FLOAT64_C( 1400.58)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -496.34), SIMDE_FLOAT64_C(  144.53),
                         SIMDE_FLOAT64_C(   -0.78), SIMDE_FLOAT64_C(  -49.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  551.16), SIMDE_FLOAT64_C(    1.32),
                         SIMDE_FLOAT64_C( -388.16), SIMDE_FLOAT64_C(  219.25)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -549.84), SIMDE_FLOAT64_C(  640.87),
                         SIMDE_FLOAT64_C(  607.41), SIMDE_FLOAT64_C(  -48.92)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -33.11), SIMDE_FLOAT64_C( -186.08),
                         SIMDE_FLOAT64_C(  701.92), SIMDE_FLOAT64_C(   14.26)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   92.65), SIMDE_FLOAT64_C( -100.54),
                         SIMDE_FLOAT64_C( -271.34), SIMDE_FLOAT64_C(  -61.14)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -193.19), SIMDE_FLOAT64_C( -152.97),
                         SIMDE_FLOAT64_C(  210.20), SIMDE_FLOAT64_C( -687.66)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  116.05), SIMDE_FLOAT64_C( -582.94),
                         SIMDE_FLOAT64_C(   -9.93), SIMDE_FLOAT64_C( -395.51)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  109.95), SIMDE_FLOAT64_C( -493.57),
                         SIMDE_FLOAT64_C(  927.71), SIMDE_FLOAT64_C(   40.21)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -603.52), SIMDE_FLOAT64_C( -698.99),
                         SIMDE_FLOAT64_C( -887.50), SIMDE_FLOAT64_C( -385.58)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_hsub_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  TEST_FUNC(mm256_set_epi8),
  TEST_FUNC(mm256_set_epi16),
  TEST_FUNC(mm256_set_epi32),
  TEST_FUNC(mm256_set_epi64x),
  TEST_FUNC(mm256_set_ps),
  TEST_FUNC(mm256_set_pd),
  TEST_FUNC(mm256_set_m128),
  TEST_FUNC(mm256_set_m128i),
  TEST_FUNC(mm256_set_m128d),
  TEST_FUNC(mm256_set1_epi8),
  TEST_FUNC(mm256_set1_epi16),
  TEST_FUNC(mm256_set1_epi32),
  TEST_FUNC(mm256_set1_epi64x),
  TEST_FUNC(mm256_set1_ps),
  TEST_FUNC(mm256_set1_pd),

  TEST_FUNC(mm256_add_ps),
  TEST_FUNC(mm256_add_pd),

  TEST_FUNC(mm256_addsub_ps),
  TEST_FUNC(mm256_addsub_pd),

  TEST_FUNC(mm256_and_ps),
  TEST_FUNC(mm256_and_pd),

  TEST_FUNC(mm256_blend_ps),
  TEST_FUNC(mm256_blend_pd),
  TEST_FUNC(mm256_blendv_ps),
  TEST_FUNC(mm256_blendv_pd),

  TEST_FUNC(mm256_broadcast_pd),
  TEST_FUNC(mm256_broadcast_ps),
  TEST_FUNC(mm256_broadcast_sd),
  TEST_FUNC(mm_broadcast_ss),
  TEST_FUNC(mm256_broadcast_ss),

  TEST_FUNC(mm256_castpd128_pd256),
  TEST_FUNC(mm256_castpd256_pd128),

  TEST_FUNC(mm256_ceil_ps),
  TEST_FUNC(mm256_ceil_pd),

  TEST_FUNC(mm256_cvtepi32_pd),
  TEST_FUNC(mm256_cvtepi32_ps),

  TEST_FUNC(mm256_div_pd),
  TEST_FUNC(mm256_div_ps),

  TEST_FUNC(mm256_floor_ps),
  TEST_FUNC(mm256_floor_pd),

  TEST_FUNC(mm256_hadd_ps),
  TEST_FUNC(mm256_hadd_pd),
  TEST_FUNC(mm256_hsub_ps),
  TEST_FUNC(mm256_hsub_pd),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

#if defined(SIMDE_NO_NATIVE)
#  define simde_avx_test_suite simde_avx_emul_test_suite
#endif

MunitSuite simde_avx_test_suite = {
  (char*) "/avx",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
