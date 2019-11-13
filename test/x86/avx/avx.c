/* Copyright (c) 2018, 2019 Evan Nemerson <evan@nemerson.com>
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

#include "../x86-internal.h"
#include "../../../simde/x86/avx.h"

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

#define SIMDE_TEST_ALL_SET_DOUBLE (((union { uint64_t u; double b; }) { ~UINT64_C(0x0) }).b)

static MunitResult
test_simde_mm_cmp_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[] = {
    /* 0 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -529.39), SIMDE_FLOAT64_C(  120.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -464.46), SIMDE_FLOAT64_C(  787.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  952.78), SIMDE_FLOAT64_C( -168.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -565.68), SIMDE_FLOAT64_C( -927.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  154.75), SIMDE_FLOAT64_C(  421.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  154.75), SIMDE_FLOAT64_C(  421.91)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  824.22), SIMDE_FLOAT64_C(  893.34)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -441.87), SIMDE_FLOAT64_C(  716.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 1 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  696.22), SIMDE_FLOAT64_C( -762.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  919.14), SIMDE_FLOAT64_C(  193.81)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  633.35), SIMDE_FLOAT64_C(  108.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -781.31), SIMDE_FLOAT64_C( -480.81)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -959.59), SIMDE_FLOAT64_C(  537.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -959.59), SIMDE_FLOAT64_C(  537.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -264.04), SIMDE_FLOAT64_C(  375.43)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -794.42), SIMDE_FLOAT64_C(  595.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 2 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  867.95), SIMDE_FLOAT64_C(  922.57)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  898.26), SIMDE_FLOAT64_C(  935.85)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  202.85), SIMDE_FLOAT64_C(  -31.08)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -774.78), SIMDE_FLOAT64_C( -447.16)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -73.41), SIMDE_FLOAT64_C( -449.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -73.41), SIMDE_FLOAT64_C( -449.20)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  566.15), SIMDE_FLOAT64_C(   58.04)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  933.00), SIMDE_FLOAT64_C(  506.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 3 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -556.30), SIMDE_FLOAT64_C( -294.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  925.83), SIMDE_FLOAT64_C(  574.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  845.95), SIMDE_FLOAT64_C( -455.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  819.95), SIMDE_FLOAT64_C( -999.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  836.45), SIMDE_FLOAT64_C(   52.64)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  836.45), SIMDE_FLOAT64_C(   52.64)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  885.07), SIMDE_FLOAT64_C(  301.93)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  439.24), SIMDE_FLOAT64_C( -579.89)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    /* 4 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -870.88), SIMDE_FLOAT64_C(  245.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -24.26), SIMDE_FLOAT64_C(  522.18)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  197.35), SIMDE_FLOAT64_C(  431.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -239.79), SIMDE_FLOAT64_C( -923.26)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -817.59), SIMDE_FLOAT64_C(  878.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -817.59), SIMDE_FLOAT64_C(  878.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  732.05), SIMDE_FLOAT64_C(  358.02)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  376.41), SIMDE_FLOAT64_C( -150.39)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    /* 5 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -752.97), SIMDE_FLOAT64_C(  -94.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  129.56), SIMDE_FLOAT64_C(  291.14)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -694.60), SIMDE_FLOAT64_C(  283.15)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -744.59), SIMDE_FLOAT64_C( -281.74)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -245.17), SIMDE_FLOAT64_C(  713.29)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -245.17), SIMDE_FLOAT64_C(  713.29)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  800.54), SIMDE_FLOAT64_C(  336.83)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -984.20), SIMDE_FLOAT64_C(  916.79)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    /* 6 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  418.56), SIMDE_FLOAT64_C(  721.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  588.80), SIMDE_FLOAT64_C(  954.29)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -876.64), SIMDE_FLOAT64_C(  774.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -978.38), SIMDE_FLOAT64_C( -374.92)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  421.63), SIMDE_FLOAT64_C(  686.94)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  421.63), SIMDE_FLOAT64_C(  686.94)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  562.25), SIMDE_FLOAT64_C(  712.76)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -34.73), SIMDE_FLOAT64_C(   32.85)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    /* 7 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -970.08), SIMDE_FLOAT64_C(  342.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -564.35), SIMDE_FLOAT64_C(  715.16)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   74.04), SIMDE_FLOAT64_C(  782.97)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -252.40), SIMDE_FLOAT64_C( -653.45)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -820.35), SIMDE_FLOAT64_C(  846.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -820.35), SIMDE_FLOAT64_C(  846.68)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  262.97), SIMDE_FLOAT64_C( -220.11)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  652.85), SIMDE_FLOAT64_C(  169.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 8 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   61.55), SIMDE_FLOAT64_C( -860.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  131.29), SIMDE_FLOAT64_C( -493.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  793.95), SIMDE_FLOAT64_C(  172.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -232.93), SIMDE_FLOAT64_C(  -38.95)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  900.57), SIMDE_FLOAT64_C(  468.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  900.57), SIMDE_FLOAT64_C(  468.19)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -955.72), SIMDE_FLOAT64_C( -966.92)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  955.81), SIMDE_FLOAT64_C(  521.19)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    /* 9 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  295.38), SIMDE_FLOAT64_C( -590.44)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  311.26), SIMDE_FLOAT64_C(  337.73)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -88.55), SIMDE_FLOAT64_C( -176.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -876.40), SIMDE_FLOAT64_C( -707.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  723.57), SIMDE_FLOAT64_C(  487.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  723.57), SIMDE_FLOAT64_C(  487.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -138.67), SIMDE_FLOAT64_C( -722.72)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  469.74), SIMDE_FLOAT64_C( -238.12)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    /* 10 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -964.03), SIMDE_FLOAT64_C( -655.88)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  882.48), SIMDE_FLOAT64_C( -632.34)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -490.96), SIMDE_FLOAT64_C( -663.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -923.12), SIMDE_FLOAT64_C( -723.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -820.28), SIMDE_FLOAT64_C(  245.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -820.28), SIMDE_FLOAT64_C(  245.58)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -45.30), SIMDE_FLOAT64_C( -758.31)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -336.62), SIMDE_FLOAT64_C(  364.29)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    /* 11 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -362.47), SIMDE_FLOAT64_C( -433.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   48.67), SIMDE_FLOAT64_C(  358.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -861.52), SIMDE_FLOAT64_C(  340.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -862.78), SIMDE_FLOAT64_C(  207.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -51.45), SIMDE_FLOAT64_C( -796.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -51.45), SIMDE_FLOAT64_C( -796.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  402.78), SIMDE_FLOAT64_C( -860.46)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  908.56), SIMDE_FLOAT64_C(  -80.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 12 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -144.07), SIMDE_FLOAT64_C(  314.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -99.92), SIMDE_FLOAT64_C(  650.58)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -107.66), SIMDE_FLOAT64_C(  861.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -934.47), SIMDE_FLOAT64_C( -412.02)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -526.73), SIMDE_FLOAT64_C(  343.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -526.73), SIMDE_FLOAT64_C(  343.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -938.85), SIMDE_FLOAT64_C(  543.93)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  129.05), SIMDE_FLOAT64_C( -765.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 13 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   61.28), SIMDE_FLOAT64_C( -648.14)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   99.59), SIMDE_FLOAT64_C( -325.86)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  939.35), SIMDE_FLOAT64_C( -697.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  734.09), SIMDE_FLOAT64_C( -772.91)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  218.18), SIMDE_FLOAT64_C(  171.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  218.18), SIMDE_FLOAT64_C(  171.79)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  886.78), SIMDE_FLOAT64_C(  528.38)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  952.68), SIMDE_FLOAT64_C(  182.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 14 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -948.92), SIMDE_FLOAT64_C(  488.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  567.68), SIMDE_FLOAT64_C(  834.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -912.43), SIMDE_FLOAT64_C( -847.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -926.68), SIMDE_FLOAT64_C( -927.41)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -280.98), SIMDE_FLOAT64_C( -321.44)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -280.98), SIMDE_FLOAT64_C( -321.44)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  508.36), SIMDE_FLOAT64_C( -377.93)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  632.00), SIMDE_FLOAT64_C(  236.33)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 15 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -534.25), SIMDE_FLOAT64_C(  462.64)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -400.74), SIMDE_FLOAT64_C(  786.60)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   22.21), SIMDE_FLOAT64_C(    3.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -806.06), SIMDE_FLOAT64_C( -774.50)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -135.43), SIMDE_FLOAT64_C(    5.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -135.43), SIMDE_FLOAT64_C(    5.39)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -328.86), SIMDE_FLOAT64_C(   -1.43)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -578.68), SIMDE_FLOAT64_C( -504.59)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    /* 16 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -183.81), SIMDE_FLOAT64_C(  940.71)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  116.32), SIMDE_FLOAT64_C(  968.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  162.80), SIMDE_FLOAT64_C(  230.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   42.45), SIMDE_FLOAT64_C( -802.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  372.34), SIMDE_FLOAT64_C(  537.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  372.34), SIMDE_FLOAT64_C(  537.19)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -170.70), SIMDE_FLOAT64_C(   78.35)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -787.71), SIMDE_FLOAT64_C( -624.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 17 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  571.06), SIMDE_FLOAT64_C( -858.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  935.34), SIMDE_FLOAT64_C(  933.83)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   66.28), SIMDE_FLOAT64_C(   64.16)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -291.80), SIMDE_FLOAT64_C(  -28.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -336.17), SIMDE_FLOAT64_C( -225.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -336.17), SIMDE_FLOAT64_C( -225.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -780.19), SIMDE_FLOAT64_C(  709.48)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -626.75), SIMDE_FLOAT64_C( -830.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 18 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -366.69), SIMDE_FLOAT64_C(  668.86)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  797.88), SIMDE_FLOAT64_C(  703.26)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  789.39), SIMDE_FLOAT64_C(  864.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -300.63), SIMDE_FLOAT64_C( -736.94)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   83.76), SIMDE_FLOAT64_C( -578.41)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   83.76), SIMDE_FLOAT64_C( -578.41)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   92.61), SIMDE_FLOAT64_C(  780.89)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  133.54), SIMDE_FLOAT64_C(  148.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 19 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -871.45), SIMDE_FLOAT64_C(  -75.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  790.19), SIMDE_FLOAT64_C(  387.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -715.95), SIMDE_FLOAT64_C( -242.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -870.55), SIMDE_FLOAT64_C( -419.34)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -163.63), SIMDE_FLOAT64_C(  323.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -163.63), SIMDE_FLOAT64_C(  323.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -855.58), SIMDE_FLOAT64_C(  821.79)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -759.48), SIMDE_FLOAT64_C( -410.97)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    /* 20 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  608.05), SIMDE_FLOAT64_C(  305.86)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  786.81), SIMDE_FLOAT64_C(  485.46)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -332.74), SIMDE_FLOAT64_C( -240.33)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -490.37), SIMDE_FLOAT64_C( -482.95)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  959.57), SIMDE_FLOAT64_C( -245.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  959.57), SIMDE_FLOAT64_C( -245.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  471.52), SIMDE_FLOAT64_C( -254.36)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  805.34), SIMDE_FLOAT64_C(   47.10)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    /* 21 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -883.05), SIMDE_FLOAT64_C( -685.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  437.76), SIMDE_FLOAT64_C( -261.16)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   25.17), SIMDE_FLOAT64_C( -978.34)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -316.84), SIMDE_FLOAT64_C( -988.59)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -278.35), SIMDE_FLOAT64_C(  800.33)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -278.35), SIMDE_FLOAT64_C(  800.33)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  504.01), SIMDE_FLOAT64_C( -993.03)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -482.47), SIMDE_FLOAT64_C( -682.33)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    /* 22 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -947.05), SIMDE_FLOAT64_C(  497.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -479.84), SIMDE_FLOAT64_C(  771.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -957.22), SIMDE_FLOAT64_C( -498.17)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -996.36), SIMDE_FLOAT64_C( -893.25)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -196.35), SIMDE_FLOAT64_C(   70.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -196.35), SIMDE_FLOAT64_C(   70.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -895.00), SIMDE_FLOAT64_C( -516.24)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -605.59), SIMDE_FLOAT64_C(   95.56)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    /* 23 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -277.10), SIMDE_FLOAT64_C(  593.77)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -225.52), SIMDE_FLOAT64_C(  955.22)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  210.46), SIMDE_FLOAT64_C( -668.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.93), SIMDE_FLOAT64_C( -776.93)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  268.81), SIMDE_FLOAT64_C(   42.66)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  268.81), SIMDE_FLOAT64_C(   42.66)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.56), SIMDE_FLOAT64_C( -371.19)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -744.56), SIMDE_FLOAT64_C( -864.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 24 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  175.90), SIMDE_FLOAT64_C(  695.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  929.95), SIMDE_FLOAT64_C(  903.96)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -218.17), SIMDE_FLOAT64_C( -840.49)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -226.66), SIMDE_FLOAT64_C( -928.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  395.44), SIMDE_FLOAT64_C(  139.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  395.44), SIMDE_FLOAT64_C(  139.62)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -61.05), SIMDE_FLOAT64_C(  478.18)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -577.95), SIMDE_FLOAT64_C( -574.53)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    /* 25 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  416.40), SIMDE_FLOAT64_C( -526.24)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  660.03), SIMDE_FLOAT64_C(  -28.91)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -774.73), SIMDE_FLOAT64_C(  566.48)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -917.37), SIMDE_FLOAT64_C( -880.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.48), SIMDE_FLOAT64_C( -440.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.48), SIMDE_FLOAT64_C( -440.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -568.05), SIMDE_FLOAT64_C( -288.94)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  864.36), SIMDE_FLOAT64_C(  525.81)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    /* 26 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -542.28), SIMDE_FLOAT64_C(  892.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -306.92), SIMDE_FLOAT64_C(  949.05)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  412.57), SIMDE_FLOAT64_C(  620.17)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   59.07), SIMDE_FLOAT64_C(  108.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -427.72), SIMDE_FLOAT64_C(  114.96)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -427.72), SIMDE_FLOAT64_C(  114.96)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  946.11), SIMDE_FLOAT64_C(   48.04)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  318.10), SIMDE_FLOAT64_C( -874.65)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    /* 27 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  143.93), SIMDE_FLOAT64_C(  507.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  234.55), SIMDE_FLOAT64_C(  992.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  929.86), SIMDE_FLOAT64_C(  964.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -205.11), SIMDE_FLOAT64_C(  847.14)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -693.95), SIMDE_FLOAT64_C(  407.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -693.95), SIMDE_FLOAT64_C(  407.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -669.92), SIMDE_FLOAT64_C( -839.60)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  788.01), SIMDE_FLOAT64_C( -470.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 28 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  979.33), SIMDE_FLOAT64_C( -879.66)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  997.49), SIMDE_FLOAT64_C(  973.15)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -307.60), SIMDE_FLOAT64_C(  589.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -312.27), SIMDE_FLOAT64_C( -323.93)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -607.36), SIMDE_FLOAT64_C(  554.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -607.36), SIMDE_FLOAT64_C(  554.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  121.31), SIMDE_FLOAT64_C( -306.77)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -196.08), SIMDE_FLOAT64_C( -442.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 29 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  205.23), SIMDE_FLOAT64_C(  463.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  891.83), SIMDE_FLOAT64_C(  478.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   83.52), SIMDE_FLOAT64_C( -712.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -494.14), SIMDE_FLOAT64_C( -713.70)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -225.77), SIMDE_FLOAT64_C(  -14.65)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -225.77), SIMDE_FLOAT64_C(  -14.65)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  277.42), SIMDE_FLOAT64_C( -194.72)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  401.09), SIMDE_FLOAT64_C( -152.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 30 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -392.42), SIMDE_FLOAT64_C(  780.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -149.10), SIMDE_FLOAT64_C(  880.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -834.34), SIMDE_FLOAT64_C(  188.96)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -969.00), SIMDE_FLOAT64_C( -426.74)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  862.72), SIMDE_FLOAT64_C(  212.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  862.72), SIMDE_FLOAT64_C(  212.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   70.37), SIMDE_FLOAT64_C(  306.92)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  111.27), SIMDE_FLOAT64_C(  341.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 31 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -438.67), SIMDE_FLOAT64_C(  106.33)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   49.90), SIMDE_FLOAT64_C(  670.54)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -363.04), SIMDE_FLOAT64_C(  742.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -538.59), SIMDE_FLOAT64_C(  410.25)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  183.16), SIMDE_FLOAT64_C( -831.08)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  183.16), SIMDE_FLOAT64_C( -831.08)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  429.68), SIMDE_FLOAT64_C(   -7.96)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  700.81), SIMDE_FLOAT64_C( -641.71)),
      simde_mm_set_pd(SIMDE_TEST_ALL_SET_DOUBLE, SIMDE_TEST_ALL_SET_DOUBLE) },
  };

  for (size_t i = 0 ; i < 1 ; i++) {
    size_t p = (0 * 5) + i;
    simde__m128d r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 0);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (1 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 1);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (2 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 2);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (3 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 3);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (4 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 4);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (5 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 5);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (6 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 6);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (7 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 7);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (8 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 8);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (9 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 9);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (10 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 10);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (11 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 11);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (12 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 12);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (13 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 13);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (14 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 14);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (15 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 15);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (16 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 16);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (17 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 17);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (18 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 18);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (19 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 19);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (20 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 20);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (21 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 21);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (22 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 22);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (23 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 23);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (24 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 24);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (25 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 25);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (26 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 26);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (27 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 27);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (28 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 28);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (29 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 29);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (30 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 30);
    simde_assert_m128_u64(r, ==, test_vec[p].r);

    p = (31 * 5) + i;
    r = simde_mm_cmp_pd(test_vec[p].a, test_vec[p].b, 31);
    simde_assert_m128_u64(r, ==, test_vec[p].r);
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
test_simde_mm256_cvtpd_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  823.92), SIMDE_FLOAT64_C( -252.31),
                         SIMDE_FLOAT64_C(  311.42), SIMDE_FLOAT64_C(  639.08)),
      simde_mm_set_epi32(INT32_C( 824), INT32_C(-252), INT32_C( 311), INT32_C( 639)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  311.89), SIMDE_FLOAT64_C( -507.25),
                         SIMDE_FLOAT64_C(  748.64), SIMDE_FLOAT64_C( -488.86)),
      simde_mm_set_epi32(INT32_C( 312), INT32_C(-507), INT32_C( 749), INT32_C(-489)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  478.57), SIMDE_FLOAT64_C( -328.29),
                         SIMDE_FLOAT64_C( -289.22), SIMDE_FLOAT64_C( -586.95)),
      simde_mm_set_epi32(INT32_C( 479), INT32_C(-328), INT32_C(-289), INT32_C(-587)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  341.08), SIMDE_FLOAT64_C(  432.49),
                         SIMDE_FLOAT64_C(  835.07), SIMDE_FLOAT64_C( -889.53)),
      simde_mm_set_epi32(INT32_C( 341), INT32_C( 432), INT32_C( 835), INT32_C(-890)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -811.21), SIMDE_FLOAT64_C( -487.29),
                         SIMDE_FLOAT64_C(  852.90), SIMDE_FLOAT64_C(  970.07)),
      simde_mm_set_epi32(INT32_C(-811), INT32_C(-487), INT32_C( 853), INT32_C( 970)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  456.79), SIMDE_FLOAT64_C( -836.64),
                         SIMDE_FLOAT64_C( -396.53), SIMDE_FLOAT64_C(  788.69)),
      simde_mm_set_epi32(INT32_C( 457), INT32_C(-837), INT32_C(-397), INT32_C( 789)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  538.31), SIMDE_FLOAT64_C(  630.62),
                         SIMDE_FLOAT64_C( -811.65), SIMDE_FLOAT64_C( -175.08)),
      simde_mm_set_epi32(INT32_C( 538), INT32_C( 631), INT32_C(-812), INT32_C(-175)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -53.87), SIMDE_FLOAT64_C(  -83.11),
                         SIMDE_FLOAT64_C( -288.58), SIMDE_FLOAT64_C( -287.98)),
      simde_mm_set_epi32(INT32_C( -54), INT32_C( -83), INT32_C(-289), INT32_C(-288)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm256_cvtpd_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtpd_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  375.90), SIMDE_FLOAT64_C( -889.76),
                         SIMDE_FLOAT64_C( -974.31), SIMDE_FLOAT64_C(  373.58)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  375.90), SIMDE_FLOAT32_C( -889.76), SIMDE_FLOAT32_C( -974.31), SIMDE_FLOAT32_C(  373.58)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   84.47), SIMDE_FLOAT64_C(  744.53),
                         SIMDE_FLOAT64_C(  -27.43), SIMDE_FLOAT64_C(  -51.38)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   84.47), SIMDE_FLOAT32_C(  744.53), SIMDE_FLOAT32_C(  -27.43), SIMDE_FLOAT32_C(  -51.38)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   66.02), SIMDE_FLOAT64_C( -438.12),
                         SIMDE_FLOAT64_C(  408.44), SIMDE_FLOAT64_C(  197.54)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   66.02), SIMDE_FLOAT32_C( -438.12), SIMDE_FLOAT32_C(  408.44), SIMDE_FLOAT32_C(  197.54)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   80.23), SIMDE_FLOAT64_C(  910.03),
                         SIMDE_FLOAT64_C(  928.38), SIMDE_FLOAT64_C(  305.66)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   80.23), SIMDE_FLOAT32_C(  910.03), SIMDE_FLOAT32_C(  928.38), SIMDE_FLOAT32_C(  305.66)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -511.50), SIMDE_FLOAT64_C( -503.26),
                         SIMDE_FLOAT64_C( -164.88), SIMDE_FLOAT64_C(  -10.16)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -511.50), SIMDE_FLOAT32_C( -503.26), SIMDE_FLOAT32_C( -164.88), SIMDE_FLOAT32_C(  -10.16)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   99.85), SIMDE_FLOAT64_C( -538.53),
                         SIMDE_FLOAT64_C(   17.38), SIMDE_FLOAT64_C( -161.67)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   99.85), SIMDE_FLOAT32_C( -538.53), SIMDE_FLOAT32_C(   17.38), SIMDE_FLOAT32_C( -161.67)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  891.01), SIMDE_FLOAT64_C(  865.63),
                         SIMDE_FLOAT64_C(  -39.82), SIMDE_FLOAT64_C( -446.03)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  891.01), SIMDE_FLOAT32_C(  865.63), SIMDE_FLOAT32_C(  -39.82), SIMDE_FLOAT32_C( -446.03)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  394.04), SIMDE_FLOAT64_C(  238.42),
                         SIMDE_FLOAT64_C(  746.10), SIMDE_FLOAT64_C(   -8.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  394.04), SIMDE_FLOAT32_C(  238.42), SIMDE_FLOAT32_C(  746.10), SIMDE_FLOAT32_C(   -8.70)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm256_cvtpd_ps(test_vec[i].a);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtps_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  598.58), SIMDE_FLOAT32_C(  571.41),
                         SIMDE_FLOAT32_C( -242.37), SIMDE_FLOAT32_C( -717.41),
                         SIMDE_FLOAT32_C(  374.26), SIMDE_FLOAT32_C( -165.53),
                         SIMDE_FLOAT32_C( -357.04), SIMDE_FLOAT32_C( -622.88)),
      simde_mm256_set_epi32(INT32_C( 599), INT32_C( 571), INT32_C(-242), INT32_C(-717),
                            INT32_C( 374), INT32_C(-166), INT32_C(-357), INT32_C(-623)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  257.81), SIMDE_FLOAT32_C( -837.70),
                         SIMDE_FLOAT32_C(  261.48), SIMDE_FLOAT32_C(  542.96),
                         SIMDE_FLOAT32_C(  769.60), SIMDE_FLOAT32_C( -711.96),
                         SIMDE_FLOAT32_C( -326.97), SIMDE_FLOAT32_C( -113.31)),
      simde_mm256_set_epi32(INT32_C( 258), INT32_C(-838), INT32_C( 261), INT32_C( 543),
                            INT32_C( 770), INT32_C(-712), INT32_C(-327), INT32_C(-113)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -569.57), SIMDE_FLOAT32_C(  423.37),
                         SIMDE_FLOAT32_C(  -24.31), SIMDE_FLOAT32_C(  934.89),
                         SIMDE_FLOAT32_C(  421.98), SIMDE_FLOAT32_C(  514.39),
                         SIMDE_FLOAT32_C(  548.83), SIMDE_FLOAT32_C(  419.70)),
      simde_mm256_set_epi32(INT32_C(-570), INT32_C( 423), INT32_C( -24), INT32_C( 935),
                            INT32_C( 422), INT32_C( 514), INT32_C( 549), INT32_C( 420)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -391.60), SIMDE_FLOAT32_C( -565.59),
                         SIMDE_FLOAT32_C(  -30.37), SIMDE_FLOAT32_C( -335.58),
                         SIMDE_FLOAT32_C(  613.59), SIMDE_FLOAT32_C( -997.50),
                         SIMDE_FLOAT32_C( -875.20), SIMDE_FLOAT32_C(   61.16)),
      simde_mm256_set_epi32(INT32_C(-392), INT32_C(-566), INT32_C( -30), INT32_C(-336),
                            INT32_C( 614), INT32_C(-998), INT32_C(-875), INT32_C(  61)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -166.04), SIMDE_FLOAT32_C( -427.79),
                         SIMDE_FLOAT32_C(  609.54), SIMDE_FLOAT32_C( -532.28),
                         SIMDE_FLOAT32_C( -681.53), SIMDE_FLOAT32_C(  504.43),
                         SIMDE_FLOAT32_C( -888.34), SIMDE_FLOAT32_C(  403.18)),
      simde_mm256_set_epi32(INT32_C(-166), INT32_C(-428), INT32_C( 610), INT32_C(-532),
                            INT32_C(-682), INT32_C( 504), INT32_C(-888), INT32_C( 403)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  216.04), SIMDE_FLOAT32_C( -927.91),
                         SIMDE_FLOAT32_C(  780.38), SIMDE_FLOAT32_C(  765.71),
                         SIMDE_FLOAT32_C( -447.72), SIMDE_FLOAT32_C(  -65.81),
                         SIMDE_FLOAT32_C(  716.35), SIMDE_FLOAT32_C(  608.15)),
      simde_mm256_set_epi32(INT32_C( 216), INT32_C(-928), INT32_C( 780), INT32_C( 766),
                            INT32_C(-448), INT32_C( -66), INT32_C( 716), INT32_C( 608)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  971.27), SIMDE_FLOAT32_C( -611.58),
                         SIMDE_FLOAT32_C( -361.36), SIMDE_FLOAT32_C( -851.00),
                         SIMDE_FLOAT32_C(  839.99), SIMDE_FLOAT32_C(  207.87),
                         SIMDE_FLOAT32_C( -947.82), SIMDE_FLOAT32_C( -403.90)),
      simde_mm256_set_epi32(INT32_C( 971), INT32_C(-612), INT32_C(-361), INT32_C(-851),
                            INT32_C( 840), INT32_C( 208), INT32_C(-948), INT32_C(-404)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -507.54), SIMDE_FLOAT32_C(  581.68),
                         SIMDE_FLOAT32_C( -590.23), SIMDE_FLOAT32_C(  417.30),
                         SIMDE_FLOAT32_C(  -87.52), SIMDE_FLOAT32_C( -865.50),
                         SIMDE_FLOAT32_C(  940.51), SIMDE_FLOAT32_C(  910.77)),
      simde_mm256_set_epi32(INT32_C(-508), INT32_C( 582), INT32_C(-590), INT32_C( 417),
                            INT32_C( -88), INT32_C(-866), INT32_C( 941), INT32_C( 911)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cvtps_epi32(test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtps_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  846.20), SIMDE_FLOAT32_C(  685.37), SIMDE_FLOAT32_C(  660.41), SIMDE_FLOAT32_C( -309.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  846.20), SIMDE_FLOAT64_C(  685.37),
                         SIMDE_FLOAT64_C(  660.41), SIMDE_FLOAT64_C( -309.12)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  900.54), SIMDE_FLOAT32_C(  555.77), SIMDE_FLOAT32_C( -412.48), SIMDE_FLOAT32_C( -684.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  900.54), SIMDE_FLOAT64_C(  555.77),
                         SIMDE_FLOAT64_C( -412.48), SIMDE_FLOAT64_C( -684.76)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -530.00), SIMDE_FLOAT32_C(  516.66), SIMDE_FLOAT32_C(  969.93), SIMDE_FLOAT32_C( -956.57)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -530.00), SIMDE_FLOAT64_C(  516.66),
                         SIMDE_FLOAT64_C(  969.93), SIMDE_FLOAT64_C( -956.57)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  876.84), SIMDE_FLOAT32_C(  972.29), SIMDE_FLOAT32_C(  715.44), SIMDE_FLOAT32_C(  -66.38)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  876.84), SIMDE_FLOAT64_C(  972.29),
                         SIMDE_FLOAT64_C(  715.44), SIMDE_FLOAT64_C(  -66.38)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -684.20), SIMDE_FLOAT32_C( -317.33), SIMDE_FLOAT32_C(   88.04), SIMDE_FLOAT32_C(  992.34)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -684.20), SIMDE_FLOAT64_C( -317.33),
                         SIMDE_FLOAT64_C(   88.04), SIMDE_FLOAT64_C(  992.34)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  481.41), SIMDE_FLOAT32_C( -117.39), SIMDE_FLOAT32_C(  583.52), SIMDE_FLOAT32_C(  373.09)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  481.41), SIMDE_FLOAT64_C( -117.39),
                         SIMDE_FLOAT64_C(  583.52), SIMDE_FLOAT64_C(  373.09)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  798.14), SIMDE_FLOAT32_C(  486.93), SIMDE_FLOAT32_C( -832.59), SIMDE_FLOAT32_C(  796.43)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  798.14), SIMDE_FLOAT64_C(  486.93),
                         SIMDE_FLOAT64_C( -832.59), SIMDE_FLOAT64_C(  796.43)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   75.03), SIMDE_FLOAT32_C(  634.86), SIMDE_FLOAT32_C(  319.54), SIMDE_FLOAT32_C( -801.15)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   75.03), SIMDE_FLOAT64_C(  634.86),
                         SIMDE_FLOAT64_C(  319.54), SIMDE_FLOAT64_C( -801.15)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_cvtps_pd(test_vec[i].a);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvttpd_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -175.82), SIMDE_FLOAT64_C(  -91.19),
                         SIMDE_FLOAT64_C( -855.64), SIMDE_FLOAT64_C(-1000.00)),
      simde_mm_set_epi32(INT32_C(-175), INT32_C( -91), INT32_C(-855), INT32_C(-1000)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  296.54), SIMDE_FLOAT64_C(  312.22),
                         SIMDE_FLOAT64_C( -648.31), SIMDE_FLOAT64_C(  586.65)),
      simde_mm_set_epi32(INT32_C( 296), INT32_C( 312), INT32_C(-648), INT32_C( 586)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  502.08), SIMDE_FLOAT64_C( -904.00),
                         SIMDE_FLOAT64_C(  802.10), SIMDE_FLOAT64_C(  616.09)),
      simde_mm_set_epi32(INT32_C( 502), INT32_C(-904), INT32_C( 802), INT32_C( 616)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  808.28), SIMDE_FLOAT64_C( -212.29),
                         SIMDE_FLOAT64_C(   75.93), SIMDE_FLOAT64_C( -979.81)),
      simde_mm_set_epi32(INT32_C( 808), INT32_C(-212), INT32_C(  75), INT32_C(-979)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -426.54), SIMDE_FLOAT64_C(  577.52),
                         SIMDE_FLOAT64_C(  966.87), SIMDE_FLOAT64_C(  162.81)),
      simde_mm_set_epi32(INT32_C(-426), INT32_C( 577), INT32_C( 966), INT32_C( 162)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -50.83), SIMDE_FLOAT64_C(  928.40),
                         SIMDE_FLOAT64_C(  392.36), SIMDE_FLOAT64_C(  469.60)),
      simde_mm_set_epi32(INT32_C( -50), INT32_C( 928), INT32_C( 392), INT32_C( 469)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  701.55), SIMDE_FLOAT64_C( -334.03),
                         SIMDE_FLOAT64_C(  803.63), SIMDE_FLOAT64_C(  -68.22)),
      simde_mm_set_epi32(INT32_C( 701), INT32_C(-334), INT32_C( 803), INT32_C( -68)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -168.66), SIMDE_FLOAT64_C( -164.87),
                         SIMDE_FLOAT64_C(  824.77), SIMDE_FLOAT64_C( -834.37)),
      simde_mm_set_epi32(INT32_C(-168), INT32_C(-164), INT32_C( 824), INT32_C(-834)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm256_cvttpd_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvttps_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -135.75), SIMDE_FLOAT32_C(  534.39),
                         SIMDE_FLOAT32_C(  -81.93), SIMDE_FLOAT32_C( -234.94),
                         SIMDE_FLOAT32_C( -390.94), SIMDE_FLOAT32_C( -625.05),
                         SIMDE_FLOAT32_C(  991.22), SIMDE_FLOAT32_C(  326.76)),
      simde_mm256_set_epi32(INT32_C(-135), INT32_C( 534), INT32_C( -81), INT32_C(-234),
                            INT32_C(-390), INT32_C(-625), INT32_C( 991), INT32_C( 326)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  864.35), SIMDE_FLOAT32_C(  855.52),
                         SIMDE_FLOAT32_C( -619.15), SIMDE_FLOAT32_C( -985.70),
                         SIMDE_FLOAT32_C( -511.44), SIMDE_FLOAT32_C(  327.81),
                         SIMDE_FLOAT32_C(   88.57), SIMDE_FLOAT32_C(  775.15)),
      simde_mm256_set_epi32(INT32_C( 864), INT32_C( 855), INT32_C(-619), INT32_C(-985),
                            INT32_C(-511), INT32_C( 327), INT32_C(  88), INT32_C( 775)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  464.19), SIMDE_FLOAT32_C( -184.66),
                         SIMDE_FLOAT32_C(  626.41), SIMDE_FLOAT32_C(  -54.43),
                         SIMDE_FLOAT32_C(  810.20), SIMDE_FLOAT32_C(  906.68),
                         SIMDE_FLOAT32_C(  -63.04), SIMDE_FLOAT32_C( -182.48)),
      simde_mm256_set_epi32(INT32_C( 464), INT32_C(-184), INT32_C( 626), INT32_C( -54),
                            INT32_C( 810), INT32_C( 906), INT32_C( -63), INT32_C(-182)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  127.49), SIMDE_FLOAT32_C( -473.91),
                         SIMDE_FLOAT32_C( -171.73), SIMDE_FLOAT32_C( -903.89),
                         SIMDE_FLOAT32_C(   73.85), SIMDE_FLOAT32_C( -545.98),
                         SIMDE_FLOAT32_C( -240.40), SIMDE_FLOAT32_C(  286.08)),
      simde_mm256_set_epi32(INT32_C( 127), INT32_C(-473), INT32_C(-171), INT32_C(-903),
                            INT32_C(  73), INT32_C(-545), INT32_C(-240), INT32_C( 286)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -184.43), SIMDE_FLOAT32_C(  171.84),
                         SIMDE_FLOAT32_C( -693.45), SIMDE_FLOAT32_C( -961.18),
                         SIMDE_FLOAT32_C( -527.37), SIMDE_FLOAT32_C(  565.38),
                         SIMDE_FLOAT32_C(  865.23), SIMDE_FLOAT32_C(  998.03)),
      simde_mm256_set_epi32(INT32_C(-184), INT32_C( 171), INT32_C(-693), INT32_C(-961),
                            INT32_C(-527), INT32_C( 565), INT32_C( 865), INT32_C( 998)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  417.68), SIMDE_FLOAT32_C(  795.88),
                         SIMDE_FLOAT32_C( -307.52), SIMDE_FLOAT32_C(   75.71),
                         SIMDE_FLOAT32_C( -179.42), SIMDE_FLOAT32_C( -352.61),
                         SIMDE_FLOAT32_C( -314.52), SIMDE_FLOAT32_C(  250.68)),
      simde_mm256_set_epi32(INT32_C( 417), INT32_C( 795), INT32_C(-307), INT32_C(  75),
                            INT32_C(-179), INT32_C(-352), INT32_C(-314), INT32_C( 250)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   89.37), SIMDE_FLOAT32_C( -634.21),
                         SIMDE_FLOAT32_C(  115.63), SIMDE_FLOAT32_C(  878.23),
                         SIMDE_FLOAT32_C( -321.46), SIMDE_FLOAT32_C(  524.08),
                         SIMDE_FLOAT32_C(  597.19), SIMDE_FLOAT32_C(  940.58)),
      simde_mm256_set_epi32(INT32_C(  89), INT32_C(-634), INT32_C( 115), INT32_C( 878),
                            INT32_C(-321), INT32_C( 524), INT32_C( 597), INT32_C( 940)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -643.91), SIMDE_FLOAT32_C(  102.13),
                         SIMDE_FLOAT32_C(  800.40), SIMDE_FLOAT32_C( -587.08),
                         SIMDE_FLOAT32_C( -734.61), SIMDE_FLOAT32_C(  772.26),
                         SIMDE_FLOAT32_C( -256.23), SIMDE_FLOAT32_C( -452.64)),
      simde_mm256_set_epi32(INT32_C(-643), INT32_C( 102), INT32_C( 800), INT32_C(-587),
                            INT32_C(-734), INT32_C( 772), INT32_C(-256), INT32_C(-452)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cvttps_epi32(test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
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
test_simde_mm256_extractf128_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m128d ra;
    simde__m128d rb;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  115.05), SIMDE_FLOAT64_C(  580.50),
                         SIMDE_FLOAT64_C(  784.61), SIMDE_FLOAT64_C(    6.02)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -748.60), SIMDE_FLOAT64_C(  328.25),
                         SIMDE_FLOAT64_C( -515.20), SIMDE_FLOAT64_C(  761.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  784.61), SIMDE_FLOAT64_C(    6.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -748.60), SIMDE_FLOAT64_C(  328.25)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -201.97), SIMDE_FLOAT64_C(  -32.82),
                         SIMDE_FLOAT64_C(  698.56), SIMDE_FLOAT64_C( -504.23)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -706.22), SIMDE_FLOAT64_C(  296.17),
                         SIMDE_FLOAT64_C(  289.51), SIMDE_FLOAT64_C( -515.71)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  698.56), SIMDE_FLOAT64_C( -504.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -706.22), SIMDE_FLOAT64_C(  296.17)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  708.15), SIMDE_FLOAT64_C( -171.50),
                         SIMDE_FLOAT64_C(  534.26), SIMDE_FLOAT64_C( -815.83)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -29.20), SIMDE_FLOAT64_C( -861.78),
                         SIMDE_FLOAT64_C(   -7.26), SIMDE_FLOAT64_C(  861.75)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  534.26), SIMDE_FLOAT64_C( -815.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.20), SIMDE_FLOAT64_C( -861.78)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  186.47), SIMDE_FLOAT64_C(  690.51),
                         SIMDE_FLOAT64_C( -956.51), SIMDE_FLOAT64_C(  679.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  790.70), SIMDE_FLOAT64_C(  327.68),
                         SIMDE_FLOAT64_C(  -42.45), SIMDE_FLOAT64_C(  443.64)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -956.51), SIMDE_FLOAT64_C(  679.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  790.70), SIMDE_FLOAT64_C(  327.68)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -320.95), SIMDE_FLOAT64_C(  190.95),
                         SIMDE_FLOAT64_C( -667.22), SIMDE_FLOAT64_C( -985.92)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -263.54), SIMDE_FLOAT64_C(  946.34),
                         SIMDE_FLOAT64_C(  395.23), SIMDE_FLOAT64_C(  318.77)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -667.22), SIMDE_FLOAT64_C( -985.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -263.54), SIMDE_FLOAT64_C(  946.34)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  258.92), SIMDE_FLOAT64_C( -434.64),
                         SIMDE_FLOAT64_C(  431.03), SIMDE_FLOAT64_C( -543.52)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   13.27), SIMDE_FLOAT64_C( -706.44),
                         SIMDE_FLOAT64_C(   14.64), SIMDE_FLOAT64_C( -663.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  431.03), SIMDE_FLOAT64_C( -543.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   13.27), SIMDE_FLOAT64_C( -706.44)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -867.30), SIMDE_FLOAT64_C(  693.24),
                         SIMDE_FLOAT64_C( -963.86), SIMDE_FLOAT64_C(   73.79)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -726.99), SIMDE_FLOAT64_C(  691.78),
                         SIMDE_FLOAT64_C(  411.83), SIMDE_FLOAT64_C(  204.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -963.86), SIMDE_FLOAT64_C(   73.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -726.99), SIMDE_FLOAT64_C(  691.78)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -771.52), SIMDE_FLOAT64_C( -673.29),
                         SIMDE_FLOAT64_C( -291.52), SIMDE_FLOAT64_C( -321.79)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  979.05), SIMDE_FLOAT64_C(  161.61),
                         SIMDE_FLOAT64_C(  682.54), SIMDE_FLOAT64_C(   63.94)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -291.52), SIMDE_FLOAT64_C( -321.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  979.05), SIMDE_FLOAT64_C(  161.61)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d ra = simde_mm256_extractf128_pd(test_vec[i].a, 0);
    simde__m128d rb = simde_mm256_extractf128_pd(test_vec[i].b, 1);
    simde_assert_m128d_f64_equal(ra, test_vec[i].ra, 1);
    simde_assert_m128d_f64_equal(rb, test_vec[i].rb, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_extractf128_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m128 ra;
    simde__m128 rb;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -982.78), SIMDE_FLOAT32_C(  936.88),
                         SIMDE_FLOAT32_C(  412.85), SIMDE_FLOAT32_C( -941.25),
                         SIMDE_FLOAT32_C(  131.34), SIMDE_FLOAT32_C(  565.12),
                         SIMDE_FLOAT32_C( -716.42), SIMDE_FLOAT32_C( -825.93)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  850.34), SIMDE_FLOAT32_C( -992.50),
                         SIMDE_FLOAT32_C(  927.06), SIMDE_FLOAT32_C( -523.74),
                         SIMDE_FLOAT32_C( -670.83), SIMDE_FLOAT32_C(  805.14),
                         SIMDE_FLOAT32_C( -177.24), SIMDE_FLOAT32_C( -739.27)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  131.34), SIMDE_FLOAT32_C(  565.12), SIMDE_FLOAT32_C( -716.42), SIMDE_FLOAT32_C( -825.93)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -982.78), SIMDE_FLOAT32_C(  936.88), SIMDE_FLOAT32_C(  412.85), SIMDE_FLOAT32_C( -941.25)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -70.97), SIMDE_FLOAT32_C( -281.18),
                         SIMDE_FLOAT32_C(  775.52), SIMDE_FLOAT32_C( -398.03),
                         SIMDE_FLOAT32_C(  484.85), SIMDE_FLOAT32_C( -518.53),
                         SIMDE_FLOAT32_C( -204.80), SIMDE_FLOAT32_C( -550.46)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -638.16), SIMDE_FLOAT32_C(   -1.38),
                         SIMDE_FLOAT32_C( -998.42), SIMDE_FLOAT32_C(   63.00),
                         SIMDE_FLOAT32_C(  880.69), SIMDE_FLOAT32_C(  119.17),
                         SIMDE_FLOAT32_C(   35.15), SIMDE_FLOAT32_C( -586.49)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  484.85), SIMDE_FLOAT32_C( -518.53), SIMDE_FLOAT32_C( -204.80), SIMDE_FLOAT32_C( -550.46)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -70.97), SIMDE_FLOAT32_C( -281.18), SIMDE_FLOAT32_C(  775.52), SIMDE_FLOAT32_C( -398.03)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  899.55), SIMDE_FLOAT32_C(  996.09),
                         SIMDE_FLOAT32_C( -135.99), SIMDE_FLOAT32_C(  141.51),
                         SIMDE_FLOAT32_C(  -55.54), SIMDE_FLOAT32_C(  357.72),
                         SIMDE_FLOAT32_C( -706.21), SIMDE_FLOAT32_C(  310.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  434.09), SIMDE_FLOAT32_C(  834.83),
                         SIMDE_FLOAT32_C( -713.54), SIMDE_FLOAT32_C( -262.36),
                         SIMDE_FLOAT32_C(  332.23), SIMDE_FLOAT32_C(  176.07),
                         SIMDE_FLOAT32_C( -753.38), SIMDE_FLOAT32_C( -978.05)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -55.54), SIMDE_FLOAT32_C(  357.72), SIMDE_FLOAT32_C( -706.21), SIMDE_FLOAT32_C(  310.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  899.55), SIMDE_FLOAT32_C(  996.09), SIMDE_FLOAT32_C( -135.99), SIMDE_FLOAT32_C(  141.51)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  683.50), SIMDE_FLOAT32_C( -416.59),
                         SIMDE_FLOAT32_C(  629.11), SIMDE_FLOAT32_C(  891.79),
                         SIMDE_FLOAT32_C( -173.40), SIMDE_FLOAT32_C( -666.21),
                         SIMDE_FLOAT32_C( -628.67), SIMDE_FLOAT32_C(  605.77)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -779.97), SIMDE_FLOAT32_C(  302.06),
                         SIMDE_FLOAT32_C(  734.68), SIMDE_FLOAT32_C( -886.16),
                         SIMDE_FLOAT32_C(  707.40), SIMDE_FLOAT32_C(  833.35),
                         SIMDE_FLOAT32_C(  963.40), SIMDE_FLOAT32_C(  412.83)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -173.40), SIMDE_FLOAT32_C( -666.21), SIMDE_FLOAT32_C( -628.67), SIMDE_FLOAT32_C(  605.77)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  683.50), SIMDE_FLOAT32_C( -416.59), SIMDE_FLOAT32_C(  629.11), SIMDE_FLOAT32_C(  891.79)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -802.04), SIMDE_FLOAT32_C(  699.58),
                         SIMDE_FLOAT32_C(  450.94), SIMDE_FLOAT32_C( -386.39),
                         SIMDE_FLOAT32_C(  494.04), SIMDE_FLOAT32_C(  940.54),
                         SIMDE_FLOAT32_C( -934.60), SIMDE_FLOAT32_C( -970.12)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  648.13), SIMDE_FLOAT32_C(  946.05),
                         SIMDE_FLOAT32_C(  808.22), SIMDE_FLOAT32_C(  517.90),
                         SIMDE_FLOAT32_C( -691.53), SIMDE_FLOAT32_C(  525.44),
                         SIMDE_FLOAT32_C( -474.29), SIMDE_FLOAT32_C( -454.31)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  494.04), SIMDE_FLOAT32_C(  940.54), SIMDE_FLOAT32_C( -934.60), SIMDE_FLOAT32_C( -970.12)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -802.04), SIMDE_FLOAT32_C(  699.58), SIMDE_FLOAT32_C(  450.94), SIMDE_FLOAT32_C( -386.39)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -543.05), SIMDE_FLOAT32_C(  -31.72),
                         SIMDE_FLOAT32_C( -407.93), SIMDE_FLOAT32_C(  926.97),
                         SIMDE_FLOAT32_C(  179.76), SIMDE_FLOAT32_C(  712.03),
                         SIMDE_FLOAT32_C(  463.85), SIMDE_FLOAT32_C( -838.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  673.45), SIMDE_FLOAT32_C(  368.84),
                         SIMDE_FLOAT32_C(  678.61), SIMDE_FLOAT32_C(  857.34),
                         SIMDE_FLOAT32_C( -482.39), SIMDE_FLOAT32_C(  -94.31),
                         SIMDE_FLOAT32_C(  471.32), SIMDE_FLOAT32_C(  173.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  179.76), SIMDE_FLOAT32_C(  712.03), SIMDE_FLOAT32_C(  463.85), SIMDE_FLOAT32_C( -838.23)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -543.05), SIMDE_FLOAT32_C(  -31.72), SIMDE_FLOAT32_C( -407.93), SIMDE_FLOAT32_C(  926.97)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -929.66), SIMDE_FLOAT32_C( -223.82),
                         SIMDE_FLOAT32_C(  340.48), SIMDE_FLOAT32_C(  717.03),
                         SIMDE_FLOAT32_C(  895.13), SIMDE_FLOAT32_C(  964.64),
                         SIMDE_FLOAT32_C( -654.82), SIMDE_FLOAT32_C(   74.87)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  665.16), SIMDE_FLOAT32_C(  209.26),
                         SIMDE_FLOAT32_C(  133.64), SIMDE_FLOAT32_C(  -42.02),
                         SIMDE_FLOAT32_C( -424.16), SIMDE_FLOAT32_C( -122.50),
                         SIMDE_FLOAT32_C( -788.87), SIMDE_FLOAT32_C( -239.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  895.13), SIMDE_FLOAT32_C(  964.64), SIMDE_FLOAT32_C( -654.82), SIMDE_FLOAT32_C(   74.87)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -929.66), SIMDE_FLOAT32_C( -223.82), SIMDE_FLOAT32_C(  340.48), SIMDE_FLOAT32_C(  717.03)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  406.90), SIMDE_FLOAT32_C( -672.60),
                         SIMDE_FLOAT32_C(  803.83), SIMDE_FLOAT32_C( -409.89),
                         SIMDE_FLOAT32_C(  549.46), SIMDE_FLOAT32_C(  773.35),
                         SIMDE_FLOAT32_C( -173.87), SIMDE_FLOAT32_C(  365.19)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  381.05), SIMDE_FLOAT32_C( -236.95),
                         SIMDE_FLOAT32_C( -568.89), SIMDE_FLOAT32_C(  375.92),
                         SIMDE_FLOAT32_C(  259.53), SIMDE_FLOAT32_C( -247.84),
                         SIMDE_FLOAT32_C(  166.06), SIMDE_FLOAT32_C( -963.74)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  549.46), SIMDE_FLOAT32_C(  773.35), SIMDE_FLOAT32_C( -173.87), SIMDE_FLOAT32_C(  365.19)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  406.90), SIMDE_FLOAT32_C( -672.60), SIMDE_FLOAT32_C(  803.83), SIMDE_FLOAT32_C( -409.89)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 ra = simde_mm256_extractf128_ps(test_vec[i].a, 0);
    simde__m128 rb = simde_mm256_extractf128_ps(test_vec[i].a, 1);
    simde_assert_m128_f32_equal(ra, test_vec[i].ra, 1);
    simde_assert_m128_f32_equal(rb, test_vec[i].rb, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_extractf128_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m128i ra;
    simde__m128i rb;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( 1229394801), INT32_C(  992221618), INT32_C(-1388107406), INT32_C(  780445625),
                            INT32_C( 1795700153), INT32_C( -297324271), INT32_C( 1549329146), INT32_C( -534963225)),
      simde_mm256_set_epi32(INT32_C( -867719772), INT32_C(-1804212438), INT32_C( 1849818353), INT32_C(  405560893),
                            INT32_C( 1351338386), INT32_C( -886724662), INT32_C( 1197680760), INT32_C( 1003042592)),
      simde_mm_set_epi32(INT32_C( 1795700153), INT32_C( -297324271), INT32_C( 1549329146), INT32_C( -534963225)),
      simde_mm_set_epi32(INT32_C( 1229394801), INT32_C(  992221618), INT32_C(-1388107406), INT32_C(  780445625)) },
    { simde_mm256_set_epi32(INT32_C( 1839397279), INT32_C( -585358334), INT32_C(  779178160), INT32_C( -362976984),
                            INT32_C(-1015866216), INT32_C( -556342867), INT32_C( -766379029), INT32_C( -130781639)),
      simde_mm256_set_epi32(INT32_C( 2021215895), INT32_C( -422044488), INT32_C(-1385706777), INT32_C(   22702781),
                            INT32_C( 1076807274), INT32_C(-1923875401), INT32_C( -554846936), INT32_C(-1008226174)),
      simde_mm_set_epi32(INT32_C(-1015866216), INT32_C( -556342867), INT32_C( -766379029), INT32_C( -130781639)),
      simde_mm_set_epi32(INT32_C( 1839397279), INT32_C( -585358334), INT32_C(  779178160), INT32_C( -362976984)) },
    { simde_mm256_set_epi32(INT32_C(   23865749), INT32_C( -908972624), INT32_C(-1642418179), INT32_C(  111689864),
                            INT32_C( -835154412), INT32_C( -431540196), INT32_C( -161564683), INT32_C(  204589457)),
      simde_mm256_set_epi32(INT32_C( 2088662618), INT32_C(-1671363325), INT32_C( -997695043), INT32_C( -809764814),
                            INT32_C( 2092581708), INT32_C(-1073689737), INT32_C(-1556963227), INT32_C( -641330488)),
      simde_mm_set_epi32(INT32_C( -835154412), INT32_C( -431540196), INT32_C( -161564683), INT32_C(  204589457)),
      simde_mm_set_epi32(INT32_C(   23865749), INT32_C( -908972624), INT32_C(-1642418179), INT32_C(  111689864)) },
    { simde_mm256_set_epi32(INT32_C( 1727711569), INT32_C(-1915329589), INT32_C( -979233658), INT32_C( -409203179),
                            INT32_C( 1343207861), INT32_C(-1541174422), INT32_C(-2097250480), INT32_C(-1382492089)),
      simde_mm256_set_epi32(INT32_C(  -42175512), INT32_C(-2146588690), INT32_C(-1902868938), INT32_C( 1919945739),
                            INT32_C(  410749235), INT32_C(-1828962645), INT32_C(  525862553), INT32_C( -282512400)),
      simde_mm_set_epi32(INT32_C( 1343207861), INT32_C(-1541174422), INT32_C(-2097250480), INT32_C(-1382492089)),
      simde_mm_set_epi32(INT32_C( 1727711569), INT32_C(-1915329589), INT32_C( -979233658), INT32_C( -409203179)) },
    { simde_mm256_set_epi32(INT32_C(  377369527), INT32_C( 1159197718), INT32_C(  288677560), INT32_C(  828517622),
                            INT32_C( 1815109517), INT32_C( 1103735854), INT32_C( 1342116414), INT32_C( 1750949195)),
      simde_mm256_set_epi32(INT32_C( 1481955155), INT32_C( -119794855), INT32_C(-2109995042), INT32_C(  582656481),
                            INT32_C( 1178951500), INT32_C(  762286037), INT32_C(  628377158), INT32_C( -188026020)),
      simde_mm_set_epi32(INT32_C( 1815109517), INT32_C( 1103735854), INT32_C( 1342116414), INT32_C( 1750949195)),
      simde_mm_set_epi32(INT32_C(  377369527), INT32_C( 1159197718), INT32_C(  288677560), INT32_C(  828517622)) },
    { simde_mm256_set_epi32(INT32_C(-1996051424), INT32_C( -314294760), INT32_C( -770521150), INT32_C(  508113145),
                            INT32_C( -677093043), INT32_C( -527636644), INT32_C( 1238565466), INT32_C(-1592387355)),
      simde_mm256_set_epi32(INT32_C(-1510707643), INT32_C( 1988531398), INT32_C(-1182276921), INT32_C(  363503044),
                            INT32_C( 2086268932), INT32_C( -428647595), INT32_C( 1685321543), INT32_C( 1979089365)),
      simde_mm_set_epi32(INT32_C( -677093043), INT32_C( -527636644), INT32_C( 1238565466), INT32_C(-1592387355)),
      simde_mm_set_epi32(INT32_C(-1996051424), INT32_C( -314294760), INT32_C( -770521150), INT32_C(  508113145)) },
    { simde_mm256_set_epi32(INT32_C(    4593159), INT32_C( 1779671737), INT32_C( -569674634), INT32_C( -184254965),
                            INT32_C( -665786654), INT32_C(  663766301), INT32_C(-1237697897), INT32_C( -260948936)),
      simde_mm256_set_epi32(INT32_C( -575114102), INT32_C( -399786699), INT32_C(-1468780124), INT32_C( 2032090700),
                            INT32_C(  723386747), INT32_C(-1766232746), INT32_C(   73837413), INT32_C(  496540408)),
      simde_mm_set_epi32(INT32_C( -665786654), INT32_C(  663766301), INT32_C(-1237697897), INT32_C( -260948936)),
      simde_mm_set_epi32(INT32_C(    4593159), INT32_C( 1779671737), INT32_C( -569674634), INT32_C( -184254965)) },
    { simde_mm256_set_epi32(INT32_C( -328197013), INT32_C( 1036318270), INT32_C(-1930293157), INT32_C( 1948339432),
                            INT32_C( 1903716614), INT32_C(-1951673698), INT32_C(-1858071379), INT32_C( 2070124471)),
      simde_mm256_set_epi32(INT32_C(-1815372819), INT32_C( -102535612), INT32_C(  115383384), INT32_C( 1004544095),
                            INT32_C( 1506420054), INT32_C(-1014523798), INT32_C(-1776388104), INT32_C( 1550371104)),
      simde_mm_set_epi32(INT32_C( 1903716614), INT32_C(-1951673698), INT32_C(-1858071379), INT32_C( 2070124471)),
      simde_mm_set_epi32(INT32_C( -328197013), INT32_C( 1036318270), INT32_C(-1930293157), INT32_C( 1948339432)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i ra = simde_mm256_extractf128_si256(test_vec[i].a, 0);
    simde__m128i rb = simde_mm256_extractf128_si256(test_vec[i].a, 1);
    simde_assert_m128i_i32(ra, ==, test_vec[i].ra);
    simde_assert_m128i_i32(rb, ==, test_vec[i].rb);
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

static MunitResult
test_simde_mm256_dp_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -505.73), SIMDE_FLOAT32_C(   -137.42),
                         SIMDE_FLOAT32_C(     17.33), SIMDE_FLOAT32_C(    756.92),
                         SIMDE_FLOAT32_C(   -935.43), SIMDE_FLOAT32_C(    966.58),
                         SIMDE_FLOAT32_C(   -542.20), SIMDE_FLOAT32_C(   -986.95)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -727.11), SIMDE_FLOAT32_C(     41.36),
                         SIMDE_FLOAT32_C(   -966.84), SIMDE_FLOAT32_C(    -80.50),
                         SIMDE_FLOAT32_C(    623.90), SIMDE_FLOAT32_C(   -996.55),
                         SIMDE_FLOAT32_C(   -173.15), SIMDE_FLOAT32_C(   -230.46)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -16755.34), SIMDE_FLOAT32_C( -16755.34),
                         SIMDE_FLOAT32_C( -16755.34), SIMDE_FLOAT32_C( -16755.34),
                         SIMDE_FLOAT32_C(  93881.93), SIMDE_FLOAT32_C(  93881.93),
                         SIMDE_FLOAT32_C(  93881.93), SIMDE_FLOAT32_C(  93881.93)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    203.19), SIMDE_FLOAT32_C(   -301.86),
                         SIMDE_FLOAT32_C(   -510.29), SIMDE_FLOAT32_C(   -548.13),
                         SIMDE_FLOAT32_C(    769.15), SIMDE_FLOAT32_C(    758.71),
                         SIMDE_FLOAT32_C(    788.95), SIMDE_FLOAT32_C(   -308.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -93.30), SIMDE_FLOAT32_C(   -209.30),
                         SIMDE_FLOAT32_C(    125.32), SIMDE_FLOAT32_C(   -995.11),
                         SIMDE_FLOAT32_C(    443.92), SIMDE_FLOAT32_C(     15.16),
                         SIMDE_FLOAT32_C(    480.88), SIMDE_FLOAT32_C(   -179.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -63949.54), SIMDE_FLOAT32_C( -63949.54),
                         SIMDE_FLOAT32_C( -63949.54), SIMDE_FLOAT32_C( -63949.54),
                         SIMDE_FLOAT32_C( 379390.28), SIMDE_FLOAT32_C( 379390.28),
                         SIMDE_FLOAT32_C( 379390.28), SIMDE_FLOAT32_C( 379390.28)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -642.96), SIMDE_FLOAT32_C(    460.10),
                         SIMDE_FLOAT32_C(    365.68), SIMDE_FLOAT32_C(    149.19),
                         SIMDE_FLOAT32_C(   -863.16), SIMDE_FLOAT32_C(    539.13),
                         SIMDE_FLOAT32_C(    -10.06), SIMDE_FLOAT32_C(   -915.55)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -102.23), SIMDE_FLOAT32_C(     63.93),
                         SIMDE_FLOAT32_C(    220.16), SIMDE_FLOAT32_C(    -95.11),
                         SIMDE_FLOAT32_C(    920.74), SIMDE_FLOAT32_C(   -798.64),
                         SIMDE_FLOAT32_C(    549.26), SIMDE_FLOAT32_C(    150.46)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  80508.11), SIMDE_FLOAT32_C(  80508.11),
                         SIMDE_FLOAT32_C(  80508.11), SIMDE_FLOAT32_C(  80508.11),
                         SIMDE_FLOAT32_C(  -5525.56), SIMDE_FLOAT32_C(  -5525.56),
                         SIMDE_FLOAT32_C(  -5525.56), SIMDE_FLOAT32_C(  -5525.56)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -135.78), SIMDE_FLOAT32_C(   -796.33),
                         SIMDE_FLOAT32_C(   -449.54), SIMDE_FLOAT32_C(   -938.34),
                         SIMDE_FLOAT32_C(    393.31), SIMDE_FLOAT32_C(   -848.57),
                         SIMDE_FLOAT32_C(   -577.93), SIMDE_FLOAT32_C(   -905.86)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     36.84), SIMDE_FLOAT32_C(    187.09),
                         SIMDE_FLOAT32_C(   -980.80), SIMDE_FLOAT32_C(   -813.89),
                         SIMDE_FLOAT32_C(   -648.02), SIMDE_FLOAT32_C(     86.79),
                         SIMDE_FLOAT32_C(    527.03), SIMDE_FLOAT32_C(   -592.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 440908.84), SIMDE_FLOAT32_C( 440908.84),
                         SIMDE_FLOAT32_C( 440908.84), SIMDE_FLOAT32_C( 440908.84),
                         SIMDE_FLOAT32_C(-304586.47), SIMDE_FLOAT32_C(-304586.47),
                         SIMDE_FLOAT32_C(-304586.47), SIMDE_FLOAT32_C(-304586.47)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     74.94), SIMDE_FLOAT32_C(    503.91),
                         SIMDE_FLOAT32_C(   -375.34), SIMDE_FLOAT32_C(   -743.13),
                         SIMDE_FLOAT32_C(    569.57), SIMDE_FLOAT32_C(    343.31),
                         SIMDE_FLOAT32_C(    -63.75), SIMDE_FLOAT32_C(   -543.95)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -655.40), SIMDE_FLOAT32_C(   -172.92),
                         SIMDE_FLOAT32_C(    342.45), SIMDE_FLOAT32_C(    357.80),
                         SIMDE_FLOAT32_C(    265.80), SIMDE_FLOAT32_C(   -306.65),
                         SIMDE_FLOAT32_C(      8.98), SIMDE_FLOAT32_C(    608.49)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-128535.19), SIMDE_FLOAT32_C(-128535.19),
                         SIMDE_FLOAT32_C(-128535.19), SIMDE_FLOAT32_C(-128535.19),
                         SIMDE_FLOAT32_C(   -572.47), SIMDE_FLOAT32_C(   -572.47),
                         SIMDE_FLOAT32_C(   -572.47), SIMDE_FLOAT32_C(   -572.47)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    691.92), SIMDE_FLOAT32_C(   -222.27),
                         SIMDE_FLOAT32_C(   -447.07), SIMDE_FLOAT32_C(    147.51),
                         SIMDE_FLOAT32_C(    537.10), SIMDE_FLOAT32_C(    171.81),
                         SIMDE_FLOAT32_C(    347.32), SIMDE_FLOAT32_C(   -960.39)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    144.97), SIMDE_FLOAT32_C(   -282.53),
                         SIMDE_FLOAT32_C(    612.87), SIMDE_FLOAT32_C(   -406.95),
                         SIMDE_FLOAT32_C(   -724.51), SIMDE_FLOAT32_C(   -908.13),
                         SIMDE_FLOAT32_C(    448.37), SIMDE_FLOAT32_C(   -713.68)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-273995.78), SIMDE_FLOAT32_C(-273995.78),
                         SIMDE_FLOAT32_C(-273995.78), SIMDE_FLOAT32_C(-273995.78),
                         SIMDE_FLOAT32_C( 155727.88), SIMDE_FLOAT32_C( 155727.88),
                         SIMDE_FLOAT32_C( 155727.88), SIMDE_FLOAT32_C( 155727.88)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -208.78), SIMDE_FLOAT32_C(    929.10),
                         SIMDE_FLOAT32_C(   -272.86), SIMDE_FLOAT32_C(     86.66),
                         SIMDE_FLOAT32_C(   -744.06), SIMDE_FLOAT32_C(   -881.86),
                         SIMDE_FLOAT32_C(   -663.16), SIMDE_FLOAT32_C(    193.59)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -31.12), SIMDE_FLOAT32_C(   -303.48),
                         SIMDE_FLOAT32_C(   -758.68), SIMDE_FLOAT32_C(    -57.97),
                         SIMDE_FLOAT32_C(    -16.19), SIMDE_FLOAT32_C(    187.47),
                         SIMDE_FLOAT32_C(     13.98), SIMDE_FLOAT32_C(    577.97)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 207013.41), SIMDE_FLOAT32_C( 207013.41),
                         SIMDE_FLOAT32_C( 207013.41), SIMDE_FLOAT32_C( 207013.41),
                         SIMDE_FLOAT32_C(  -9270.98), SIMDE_FLOAT32_C(  -9270.98),
                         SIMDE_FLOAT32_C(  -9270.98), SIMDE_FLOAT32_C(  -9270.98)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    696.37), SIMDE_FLOAT32_C(    300.52),
                         SIMDE_FLOAT32_C(   -476.62), SIMDE_FLOAT32_C(    523.01),
                         SIMDE_FLOAT32_C(   -147.94), SIMDE_FLOAT32_C(   -993.31),
                         SIMDE_FLOAT32_C(    910.70), SIMDE_FLOAT32_C(   -650.05)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -298.13), SIMDE_FLOAT32_C(   -528.10),
                         SIMDE_FLOAT32_C(    371.86), SIMDE_FLOAT32_C(    -93.70),
                         SIMDE_FLOAT32_C(   -396.01), SIMDE_FLOAT32_C(   -319.70),
                         SIMDE_FLOAT32_C(   -350.31), SIMDE_FLOAT32_C(   -580.49)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-177235.91), SIMDE_FLOAT32_C(-177235.91),
                         SIMDE_FLOAT32_C(-177235.91), SIMDE_FLOAT32_C(-177235.91),
                         SIMDE_FLOAT32_C(-319027.31), SIMDE_FLOAT32_C(-319027.31),
                         SIMDE_FLOAT32_C(-319027.31), SIMDE_FLOAT32_C(-319027.31)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_dp_ps(test_vec[i].a, test_vec[i].b, 47);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_extract_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    int index;
    int32_t r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(   61055605), INT32_C(-1479980196), INT32_C(  -40353000), INT32_C(  172193063),
                            INT32_C(-1832323957), INT32_C(-1023924186), INT32_C( 1098350152), INT32_C( -919676442)),
      7, 61055605 },
    { simde_mm256_set_epi32(INT32_C( -331986513), INT32_C( 1808772555), INT32_C(   62879239), INT32_C(-1256375997),
                            INT32_C( 1185364794), INT32_C(   41090316), INT32_C(-1301790433), INT32_C(  815074909)),
      6, 1808772555 },
    { simde_mm256_set_epi32(INT32_C( 1654842341), INT32_C(  822291601), INT32_C(  897283487), INT32_C( 1778004523),
                            INT32_C(  130713148), INT32_C(  593162219), INT32_C(  985045955), INT32_C( 1592640798)),
      2, 593162219 },
    { simde_mm256_set_epi32(INT32_C( 1977612347), INT32_C( 1688995860), INT32_C( 1567504622), INT32_C(-2097944074),
                            INT32_C( 1761578069), INT32_C( 1929871764), INT32_C(  643853729), INT32_C( -207039555)),
      7, 1977612347 },
    { simde_mm256_set_epi32(INT32_C( 1948890649), INT32_C( -290842752), INT32_C(  -93675973), INT32_C( -498158071),
                            INT32_C( 1727601867), INT32_C(-1565364260), INT32_C( 2070242745), INT32_C( -909139096)),
      7, 1948890649 },
    { simde_mm256_set_epi32(INT32_C( -989272351), INT32_C(  989013364), INT32_C( -315262958), INT32_C(-1688278261),
                            INT32_C( 1299191383), INT32_C( 1962891034), INT32_C( -954577324), INT32_C(-1384850409)),
      5, -315262958 },
    { simde_mm256_set_epi32(INT32_C(-1122046157), INT32_C( 1213653197), INT32_C(  196144718), INT32_C( 1282318771),
                            INT32_C( 1290295538), INT32_C(-1451059232), INT32_C(-1717456343), INT32_C(-1181875370)),
      4, 1282318771 },
    { simde_mm256_set_epi32(INT32_C(  515370311), INT32_C(  607844900), INT32_C( 1915199718), INT32_C(  666752092),
                            INT32_C( -850042230), INT32_C(-1240024389), INT32_C(-1368273592), INT32_C(  598588907)),
      0, 598588907 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = simde_mm256_extract_epi32(test_vec[i].a, test_vec[i].index);
    simde_assert_int32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_extract_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    int index;
    int64_t r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C(-2655458780135953860), INT64_C( 7954001598227933468),
                             INT64_C( 6770172759215157955), INT64_C(-8789602045030953920)),
      0, INT64_C(-8789602045030953920) },
    { simde_mm256_set_epi64x(INT64_C( -341781105405719052), INT64_C( 1294723965810870930),
                             INT64_C(-7888937635288268931), INT64_C(-4698155264251724352)),
      0, INT64_C(-4698155264251724352) },
    { simde_mm256_set_epi64x(INT64_C(-7957372259058736569), INT64_C(-7725637084510287230),
                             INT64_C( 4381709987427875437), INT64_C(-5364794812878077922)),
      1, INT64_C(4381709987427875437) },
    { simde_mm256_set_epi64x(INT64_C(-1691906904044168671), INT64_C( 7979235859736616531),
                             INT64_C(-1551127775684753479), INT64_C(-8694197489457512342)),
      1, INT64_C(-1551127775684753479) },
    { simde_mm256_set_epi64x(INT64_C(-8013598668008262239), INT64_C(-7829356937064844865),
                             INT64_C( 3816644295329899007), INT64_C(-1889179524977096898)),
      0, INT64_C(-1889179524977096898) },
    { simde_mm256_set_epi64x(INT64_C(-6845066309341759464), INT64_C(-3677118362217746881),
                             INT64_C(-2648482972009088737), INT64_C(-5947057873479186806)),
      0, INT64_C(-5947057873479186806) },
    { simde_mm256_set_epi64x(INT64_C(-8833499439049351259), INT64_C( 2776454266808406221),
                             INT64_C( 5411746887543744165), INT64_C( 1887683724855089971)),
      2, INT64_C(2776454266808406221) },
    { simde_mm256_set_epi64x(INT64_C(-9127827259600585155), INT64_C( 1842464135422352111),
                             INT64_C(-6413752599297872422), INT64_C(-2564923405179519764)),
      0, INT64_C(-2564923405179519764) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int64_t r = simde_mm256_extract_epi64(test_vec[i].a, test_vec[i].index);
    munit_assert_int64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_insert_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    int8_t val;
    int index;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C( -99), INT8_C(  88), INT8_C( -53), INT8_C( -18),
                           INT8_C( -85), INT8_C( 102), INT8_C(  50), INT8_C(  10),
                           INT8_C(-108), INT8_C(  40), INT8_C( -44), INT8_C( -23),
                           INT8_C( -49), INT8_C(-113), INT8_C( 125), INT8_C(  94),
                           INT8_C( -76), INT8_C( 115), INT8_C(  86), INT8_C( -75),
                           INT8_C(  92), INT8_C( -22), INT8_C(-110), INT8_C(  52),
                           INT8_C( -21), INT8_C(  20), INT8_C(  57), INT8_C( -68),
                           INT8_C( 106), INT8_C( -13), INT8_C(-126), INT8_C(  87)),
      INT8_C( -19), 22,
      simde_mm256_set_epi8(INT8_C( -99), INT8_C(  88), INT8_C( -53), INT8_C( -18),
                           INT8_C( -85), INT8_C( 102), INT8_C(  50), INT8_C(  10),
                           INT8_C(-108), INT8_C( -19), INT8_C( -44), INT8_C( -23),
                           INT8_C( -49), INT8_C(-113), INT8_C( 125), INT8_C(  94),
                           INT8_C( -76), INT8_C( 115), INT8_C(  86), INT8_C( -75),
                           INT8_C(  92), INT8_C( -22), INT8_C(-110), INT8_C(  52),
                           INT8_C( -21), INT8_C(  20), INT8_C(  57), INT8_C( -68),
                           INT8_C( 106), INT8_C( -13), INT8_C(-126), INT8_C(  87)) },
    { simde_mm256_set_epi8(INT8_C(  78), INT8_C( -90), INT8_C(-106), INT8_C(  36),
                           INT8_C(-123), INT8_C(  40), INT8_C( 113), INT8_C( -58),
                           INT8_C(  81), INT8_C(  45), INT8_C( -68), INT8_C(  22),
                           INT8_C(   9), INT8_C( -55), INT8_C(  35), INT8_C(  -7),
                           INT8_C(  27), INT8_C(-122), INT8_C(  74), INT8_C(  26),
                           INT8_C( -48), INT8_C(  62), INT8_C(-119), INT8_C(  41),
                           INT8_C( -22), INT8_C( 103), INT8_C( -79), INT8_C(  94),
                           INT8_C( 125), INT8_C(  46), INT8_C( -13), INT8_C(-119)),
      INT8_C(  23), 4,
      simde_mm256_set_epi8(INT8_C(  78), INT8_C( -90), INT8_C(-106), INT8_C(  36),
                           INT8_C(-123), INT8_C(  40), INT8_C( 113), INT8_C( -58),
                           INT8_C(  81), INT8_C(  45), INT8_C( -68), INT8_C(  22),
                           INT8_C(   9), INT8_C( -55), INT8_C(  35), INT8_C(  -7),
                           INT8_C(  27), INT8_C(-122), INT8_C(  74), INT8_C(  26),
                           INT8_C( -48), INT8_C(  62), INT8_C(-119), INT8_C(  41),
                           INT8_C( -22), INT8_C( 103), INT8_C( -79), INT8_C(  23),
                           INT8_C( 125), INT8_C(  46), INT8_C( -13), INT8_C(-119)) },
    { simde_mm256_set_epi8(INT8_C( -49), INT8_C(  90), INT8_C( -40), INT8_C(  21),
                           INT8_C(-122), INT8_C( -53), INT8_C( -42), INT8_C(-126),
                           INT8_C( -50), INT8_C( -79), INT8_C( -22), INT8_C( -64),
                           INT8_C(  59), INT8_C( -32), INT8_C( -49), INT8_C(-126),
                           INT8_C(  26), INT8_C(  17), INT8_C( 120), INT8_C( -33),
                           INT8_C( -45), INT8_C(  77), INT8_C(  92), INT8_C( -67),
                           INT8_C( -26), INT8_C(  76), INT8_C( -85), INT8_C( -29),
                           INT8_C( -55), INT8_C(  38), INT8_C( -17), INT8_C(  47)),
      INT8_C(  29), 21,
      simde_mm256_set_epi8(INT8_C( -49), INT8_C(  90), INT8_C( -40), INT8_C(  21),
                           INT8_C(-122), INT8_C( -53), INT8_C( -42), INT8_C(-126),
                           INT8_C( -50), INT8_C( -79), INT8_C(  29), INT8_C( -64),
                           INT8_C(  59), INT8_C( -32), INT8_C( -49), INT8_C(-126),
                           INT8_C(  26), INT8_C(  17), INT8_C( 120), INT8_C( -33),
                           INT8_C( -45), INT8_C(  77), INT8_C(  92), INT8_C( -67),
                           INT8_C( -26), INT8_C(  76), INT8_C( -85), INT8_C( -29),
                           INT8_C( -55), INT8_C(  38), INT8_C( -17), INT8_C(  47)) },
    { simde_mm256_set_epi8(INT8_C(  -1), INT8_C( -43), INT8_C(  55), INT8_C(-102),
                           INT8_C(-109), INT8_C( -47), INT8_C( -35), INT8_C(  -7),
                           INT8_C( 113), INT8_C(  27), INT8_C(-115), INT8_C( -40),
                           INT8_C(  23), INT8_C(  41), INT8_C( -17), INT8_C(  22),
                           INT8_C( -53), INT8_C( -39), INT8_C( -64), INT8_C( 109),
                           INT8_C(-105), INT8_C( -39), INT8_C( 101), INT8_C(  44),
                           INT8_C( -77), INT8_C( -52), INT8_C( 106), INT8_C(  43),
                           INT8_C(-122), INT8_C( -98), INT8_C( 110), INT8_C(   0)),
      INT8_C(  24), 16,
      simde_mm256_set_epi8(INT8_C(  -1), INT8_C( -43), INT8_C(  55), INT8_C(-102),
                           INT8_C(-109), INT8_C( -47), INT8_C( -35), INT8_C(  -7),
                           INT8_C( 113), INT8_C(  27), INT8_C(-115), INT8_C( -40),
                           INT8_C(  23), INT8_C(  41), INT8_C( -17), INT8_C(  24),
                           INT8_C( -53), INT8_C( -39), INT8_C( -64), INT8_C( 109),
                           INT8_C(-105), INT8_C( -39), INT8_C( 101), INT8_C(  44),
                           INT8_C( -77), INT8_C( -52), INT8_C( 106), INT8_C(  43),
                           INT8_C(-122), INT8_C( -98), INT8_C( 110), INT8_C(   0)) },
    { simde_mm256_set_epi8(INT8_C(  43), INT8_C(   2), INT8_C( -77), INT8_C( -32),
                           INT8_C( -10), INT8_C( 119), INT8_C(  68), INT8_C( 115),
                           INT8_C(  37), INT8_C(  32), INT8_C( -57), INT8_C( -21),
                           INT8_C( 123), INT8_C(  50), INT8_C( -49), INT8_C(  61),
                           INT8_C( -43), INT8_C(   1), INT8_C(  57), INT8_C( -24),
                           INT8_C(   9), INT8_C( -29), INT8_C( -30), INT8_C( -40),
                           INT8_C( -59), INT8_C(-119), INT8_C(  62), INT8_C( 123),
                           INT8_C(  24), INT8_C(  49), INT8_C(   6), INT8_C( 120)),
      INT8_C( -54), 27,
      simde_mm256_set_epi8(INT8_C(  43), INT8_C(   2), INT8_C( -77), INT8_C( -32),
                           INT8_C( -54), INT8_C( 119), INT8_C(  68), INT8_C( 115),
                           INT8_C(  37), INT8_C(  32), INT8_C( -57), INT8_C( -21),
                           INT8_C( 123), INT8_C(  50), INT8_C( -49), INT8_C(  61),
                           INT8_C( -43), INT8_C(   1), INT8_C(  57), INT8_C( -24),
                           INT8_C(   9), INT8_C( -29), INT8_C( -30), INT8_C( -40),
                           INT8_C( -59), INT8_C(-119), INT8_C(  62), INT8_C( 123),
                           INT8_C(  24), INT8_C(  49), INT8_C(   6), INT8_C( 120)) },
    { simde_mm256_set_epi8(INT8_C(  39), INT8_C(  26), INT8_C(   2), INT8_C(-108),
                           INT8_C( -15), INT8_C( -19), INT8_C(  48), INT8_C( -57),
                           INT8_C(-109), INT8_C( -38), INT8_C(  34), INT8_C(  41),
                           INT8_C( 118), INT8_C(  69), INT8_C(  71), INT8_C(  -3),
                           INT8_C(  86), INT8_C(  31), INT8_C( -72), INT8_C(  74),
                           INT8_C(  77), INT8_C( -71), INT8_C(   1), INT8_C(  29),
                           INT8_C( -69), INT8_C(  73), INT8_C( 120), INT8_C( -49),
                           INT8_C( -72), INT8_C(  66), INT8_C(  55), INT8_C(  84)),
      INT8_C(  69), 22,
      simde_mm256_set_epi8(INT8_C(  39), INT8_C(  26), INT8_C(   2), INT8_C(-108),
                           INT8_C( -15), INT8_C( -19), INT8_C(  48), INT8_C( -57),
                           INT8_C(-109), INT8_C(  69), INT8_C(  34), INT8_C(  41),
                           INT8_C( 118), INT8_C(  69), INT8_C(  71), INT8_C(  -3),
                           INT8_C(  86), INT8_C(  31), INT8_C( -72), INT8_C(  74),
                           INT8_C(  77), INT8_C( -71), INT8_C(   1), INT8_C(  29),
                           INT8_C( -69), INT8_C(  73), INT8_C( 120), INT8_C( -49),
                           INT8_C( -72), INT8_C(  66), INT8_C(  55), INT8_C(  84)) },
    { simde_mm256_set_epi8(INT8_C(  88), INT8_C( 121), INT8_C(   7), INT8_C(  26),
                           INT8_C( 122), INT8_C( -93), INT8_C(   0), INT8_C(-128),
                           INT8_C(  49), INT8_C( -69), INT8_C( -97), INT8_C( -98),
                           INT8_C( -90), INT8_C(  84), INT8_C(-116), INT8_C( -64),
                           INT8_C( -34), INT8_C( 114), INT8_C( -75), INT8_C(  88),
                           INT8_C( 112), INT8_C(-125), INT8_C(  -2), INT8_C(  38),
                           INT8_C(  -5), INT8_C( 101), INT8_C( 121), INT8_C( -41),
                           INT8_C( -40), INT8_C( 104), INT8_C(  31), INT8_C( -53)),
      INT8_C( -89), 31,
      simde_mm256_set_epi8(INT8_C( -89), INT8_C( 121), INT8_C(   7), INT8_C(  26),
                           INT8_C( 122), INT8_C( -93), INT8_C(   0), INT8_C(-128),
                           INT8_C(  49), INT8_C( -69), INT8_C( -97), INT8_C( -98),
                           INT8_C( -90), INT8_C(  84), INT8_C(-116), INT8_C( -64),
                           INT8_C( -34), INT8_C( 114), INT8_C( -75), INT8_C(  88),
                           INT8_C( 112), INT8_C(-125), INT8_C(  -2), INT8_C(  38),
                           INT8_C(  -5), INT8_C( 101), INT8_C( 121), INT8_C( -41),
                           INT8_C( -40), INT8_C( 104), INT8_C(  31), INT8_C( -53)) },
    { simde_mm256_set_epi8(INT8_C(  95), INT8_C( -62), INT8_C(-102), INT8_C(  67),
                           INT8_C( -50), INT8_C(  21), INT8_C(  43), INT8_C( 115),
                           INT8_C(  29), INT8_C( 117), INT8_C( -30), INT8_C(-121),
                           INT8_C( -32), INT8_C( -87), INT8_C( -71), INT8_C(  45),
                           INT8_C(  61), INT8_C( -33), INT8_C( -73), INT8_C( -82),
                           INT8_C( 119), INT8_C( -42), INT8_C(  82), INT8_C( -52),
                           INT8_C( -79), INT8_C(  30), INT8_C(  24), INT8_C(  46),
                           INT8_C( 122), INT8_C( -37), INT8_C(  78), INT8_C(  21)),
      INT8_C( -20), 11,
      simde_mm256_set_epi8(INT8_C(  95), INT8_C( -62), INT8_C(-102), INT8_C(  67),
                           INT8_C( -50), INT8_C(  21), INT8_C(  43), INT8_C( 115),
                           INT8_C(  29), INT8_C( 117), INT8_C( -30), INT8_C(-121),
                           INT8_C( -32), INT8_C( -87), INT8_C( -71), INT8_C(  45),
                           INT8_C(  61), INT8_C( -33), INT8_C( -73), INT8_C( -82),
                           INT8_C( -20), INT8_C( -42), INT8_C(  82), INT8_C( -52),
                           INT8_C( -79), INT8_C(  30), INT8_C(  24), INT8_C(  46),
                           INT8_C( 122), INT8_C( -37), INT8_C(  78), INT8_C(  21)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_insert_epi8(test_vec[i].a, test_vec[i].val, test_vec[i].index);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_insert_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    int16_t val;
    int index;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi16(INT16_C( 20486), INT16_C(-32218), INT16_C( 27722), INT16_C(-32250),
                            INT16_C(-13849), INT16_C(-29212), INT16_C( 18892), INT16_C( -4268),
                            INT16_C( 20631), INT16_C( 20817), INT16_C( -8287), INT16_C(-28655),
                            INT16_C(-24480), INT16_C( 14404), INT16_C(-10728), INT16_C( 31357)),
      INT16_C(   393), 10,
      simde_mm256_set_epi16(INT16_C( 20486), INT16_C(-32218), INT16_C( 27722), INT16_C(-32250),
                            INT16_C(-13849), INT16_C(   393), INT16_C( 18892), INT16_C( -4268),
                            INT16_C( 20631), INT16_C( 20817), INT16_C( -8287), INT16_C(-28655),
                            INT16_C(-24480), INT16_C( 14404), INT16_C(-10728), INT16_C( 31357)) },
    { simde_mm256_set_epi16(INT16_C( -7241), INT16_C( 17545), INT16_C(-11900), INT16_C( 26551),
                            INT16_C( 25040), INT16_C(-15452), INT16_C(-23035), INT16_C(-10888),
                            INT16_C( -2690), INT16_C(-11622), INT16_C(-25207), INT16_C(  -910),
                            INT16_C( 23386), INT16_C( 19569), INT16_C(-22484), INT16_C( -3183)),
      INT16_C( 15303), 1,
      simde_mm256_set_epi16(INT16_C( -7241), INT16_C( 17545), INT16_C(-11900), INT16_C( 26551),
                            INT16_C( 25040), INT16_C(-15452), INT16_C(-23035), INT16_C(-10888),
                            INT16_C( -2690), INT16_C(-11622), INT16_C(-25207), INT16_C(  -910),
                            INT16_C( 23386), INT16_C( 19569), INT16_C( 15303), INT16_C( -3183)) },
    { simde_mm256_set_epi16(INT16_C(  8980), INT16_C(-17780), INT16_C( -7270), INT16_C(  6361),
                            INT16_C( -9198), INT16_C( 20082), INT16_C( -8780), INT16_C(-21516),
                            INT16_C(  4300), INT16_C( -8486), INT16_C( 31727), INT16_C( -9964),
                            INT16_C( 11935), INT16_C( -4936), INT16_C(-14068), INT16_C( -1207)),
      INT16_C(  9595), 4,
      simde_mm256_set_epi16(INT16_C(  8980), INT16_C(-17780), INT16_C( -7270), INT16_C(  6361),
                            INT16_C( -9198), INT16_C( 20082), INT16_C( -8780), INT16_C(-21516),
                            INT16_C(  4300), INT16_C( -8486), INT16_C( 31727), INT16_C(  9595),
                            INT16_C( 11935), INT16_C( -4936), INT16_C(-14068), INT16_C( -1207)) },
    { simde_mm256_set_epi16(INT16_C(-25936), INT16_C(-25097), INT16_C(-29673), INT16_C(-22779),
                            INT16_C(  7631), INT16_C( 13109), INT16_C( 21900), INT16_C(-20331),
                            INT16_C( -9869), INT16_C( -8244), INT16_C(-26290), INT16_C(-13177),
                            INT16_C( -5452), INT16_C(-22530), INT16_C( -4819), INT16_C( 31495)),
      INT16_C(  1004), 9,
      simde_mm256_set_epi16(INT16_C(-25936), INT16_C(-25097), INT16_C(-29673), INT16_C(-22779),
                            INT16_C(  7631), INT16_C( 13109), INT16_C(  1004), INT16_C(-20331),
                            INT16_C( -9869), INT16_C( -8244), INT16_C(-26290), INT16_C(-13177),
                            INT16_C( -5452), INT16_C(-22530), INT16_C( -4819), INT16_C( 31495)) },
    { simde_mm256_set_epi16(INT16_C(-23585), INT16_C(-24934), INT16_C(-10114), INT16_C(-30846),
                            INT16_C( -2989), INT16_C(-15793), INT16_C(-14728), INT16_C( -5248),
                            INT16_C( -7838), INT16_C( 20555), INT16_C( 26687), INT16_C( 17188),
                            INT16_C(-13813), INT16_C( 23977), INT16_C(-13527), INT16_C( 28012)),
      INT16_C( 18917), 2,
      simde_mm256_set_epi16(INT16_C(-23585), INT16_C(-24934), INT16_C(-10114), INT16_C(-30846),
                            INT16_C( -2989), INT16_C(-15793), INT16_C(-14728), INT16_C( -5248),
                            INT16_C( -7838), INT16_C( 20555), INT16_C( 26687), INT16_C( 17188),
                            INT16_C(-13813), INT16_C( 18917), INT16_C(-13527), INT16_C( 28012)) },
    { simde_mm256_set_epi16(INT16_C( -8770), INT16_C(-16888), INT16_C( 31408), INT16_C(  7020),
                            INT16_C( 19765), INT16_C( 30860), INT16_C( 26536), INT16_C(-26695),
                            INT16_C(-30807), INT16_C( 31709), INT16_C(-30131), INT16_C(  6126),
                            INT16_C(  -740), INT16_C( 11618), INT16_C(  -159), INT16_C( 17197)),
      INT16_C(-15871), 14,
      simde_mm256_set_epi16(INT16_C( -8770), INT16_C(-15871), INT16_C( 31408), INT16_C(  7020),
                            INT16_C( 19765), INT16_C( 30860), INT16_C( 26536), INT16_C(-26695),
                            INT16_C(-30807), INT16_C( 31709), INT16_C(-30131), INT16_C(  6126),
                            INT16_C(  -740), INT16_C( 11618), INT16_C(  -159), INT16_C( 17197)) },
    { simde_mm256_set_epi16(INT16_C( 10636), INT16_C( -3675), INT16_C(-21123), INT16_C( 17568),
                            INT16_C( 30853), INT16_C(  -132), INT16_C(-13082), INT16_C(-23850),
                            INT16_C( 28532), INT16_C( 22681), INT16_C(-15615), INT16_C( 23367),
                            INT16_C( 32616), INT16_C( 10786), INT16_C( 28123), INT16_C(  1581)),
      INT16_C( 17194), 2,
      simde_mm256_set_epi16(INT16_C( 10636), INT16_C( -3675), INT16_C(-21123), INT16_C( 17568),
                            INT16_C( 30853), INT16_C(  -132), INT16_C(-13082), INT16_C(-23850),
                            INT16_C( 28532), INT16_C( 22681), INT16_C(-15615), INT16_C( 23367),
                            INT16_C( 32616), INT16_C( 17194), INT16_C( 28123), INT16_C(  1581)) },
    { simde_mm256_set_epi16(INT16_C( 12664), INT16_C(  3110), INT16_C(-12323), INT16_C( -4889),
                            INT16_C(-25547), INT16_C(-10437), INT16_C(-13096), INT16_C(-16121),
                            INT16_C(-10087), INT16_C( 14418), INT16_C( 15791), INT16_C(  8782),
                            INT16_C( 25173), INT16_C(  3196), INT16_C( 16373), INT16_C(  8170)),
      INT16_C(  8771), 3,
      simde_mm256_set_epi16(INT16_C( 12664), INT16_C(  3110), INT16_C(-12323), INT16_C( -4889),
                            INT16_C(-25547), INT16_C(-10437), INT16_C(-13096), INT16_C(-16121),
                            INT16_C(-10087), INT16_C( 14418), INT16_C( 15791), INT16_C(  8782),
                            INT16_C(  8771), INT16_C(  3196), INT16_C( 16373), INT16_C(  8170)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_insert_epi16(test_vec[i].a, test_vec[i].val, test_vec[i].index);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_insert_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    int32_t val;
    int index;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( -794776694), INT32_C( -595980557), INT32_C(-1594553165), INT32_C(  546007350),
                            INT32_C( 1217738208), INT32_C(  563146926), INT32_C(  486713543), INT32_C(  772349766)),
      INT32_C( -142897390), 5,
      simde_mm256_set_epi32(INT32_C( -794776694), INT32_C( -595980557), INT32_C( -142897390), INT32_C(  546007350),
                            INT32_C( 1217738208), INT32_C(  563146926), INT32_C(  486713543), INT32_C(  772349766)) },
    { simde_mm256_set_epi32(INT32_C(  514330470), INT32_C(  878239636), INT32_C( -522502647), INT32_C( -947857233),
                            INT32_C(-1280790836), INT32_C(-2077457216), INT32_C( 1766829164), INT32_C( 1496710537)),
      INT32_C( -192517007), 7,
      simde_mm256_set_epi32(INT32_C( -192517007), INT32_C(  878239636), INT32_C( -522502647), INT32_C( -947857233),
                            INT32_C(-1280790836), INT32_C(-2077457216), INT32_C( 1766829164), INT32_C( 1496710537)) },
    { simde_mm256_set_epi32(INT32_C( -241496134), INT32_C( -728969225), INT32_C( 1670700106), INT32_C( 1009735903),
                            INT32_C(-1569132879), INT32_C( 1168657039), INT32_C( -800629398), INT32_C( 1395621879)),
      INT32_C( -324968920), 6,
      simde_mm256_set_epi32(INT32_C( -241496134), INT32_C( -324968920), INT32_C( 1670700106), INT32_C( 1009735903),
                            INT32_C(-1569132879), INT32_C( 1168657039), INT32_C( -800629398), INT32_C( 1395621879)) },
    { simde_mm256_set_epi32(INT32_C(  -73333189), INT32_C(-2091906257), INT32_C(-1022569606), INT32_C(   31907443),
                            INT32_C(-1871948623), INT32_C( -716582299), INT32_C( 1638917630), INT32_C( -952988925)),
      INT32_C( -827158739), 5,
      simde_mm256_set_epi32(INT32_C(  -73333189), INT32_C(-2091906257), INT32_C( -827158739), INT32_C(   31907443),
                            INT32_C(-1871948623), INT32_C( -716582299), INT32_C( 1638917630), INT32_C( -952988925)) },
    { simde_mm256_set_epi32(INT32_C( 1867074490), INT32_C(-2015142002), INT32_C( 1807174960), INT32_C(-2132128215),
                            INT32_C(-2023270528), INT32_C( 1999614223), INT32_C(  810339192), INT32_C(   34873431)),
      INT32_C( 1288048417), 2,
      simde_mm256_set_epi32(INT32_C( 1867074490), INT32_C(-2015142002), INT32_C( 1807174960), INT32_C(-2132128215),
                            INT32_C(-2023270528), INT32_C( 1288048417), INT32_C(  810339192), INT32_C(   34873431)) },
    { simde_mm256_set_epi32(INT32_C( -801082561), INT32_C( -639513940), INT32_C( -229402781), INT32_C(  630096686),
                            INT32_C(-2069410220), INT32_C(-1572129165), INT32_C(  830359576), INT32_C( 1671501242)),
      INT32_C(  518930919), 2,
      simde_mm256_set_epi32(INT32_C( -801082561), INT32_C( -639513940), INT32_C( -229402781), INT32_C(  630096686),
                            INT32_C(-2069410220), INT32_C(  518930919), INT32_C(  830359576), INT32_C( 1671501242)) },
    { simde_mm256_set_epi32(INT32_C(-2084192374), INT32_C(  827105053), INT32_C(-1267247697), INT32_C( -329400252),
                            INT32_C(  574788202), INT32_C( -946647754), INT32_C(-1536637789), INT32_C( -522595720)),
      INT32_C(-1771622283), 0,
      simde_mm256_set_epi32(INT32_C(-2084192374), INT32_C(  827105053), INT32_C(-1267247697), INT32_C( -329400252),
                            INT32_C(  574788202), INT32_C( -946647754), INT32_C(-1536637789), INT32_C(-1771622283)) },
    { simde_mm256_set_epi32(INT32_C( -303299309), INT32_C( 1037552837), INT32_C(  235762285), INT32_C(-1173875757),
                            INT32_C(-1855174495), INT32_C(-1958954726), INT32_C( 1573942546), INT32_C( 1061048615)),
      INT32_C(-1809400498), 5,
      simde_mm256_set_epi32(INT32_C( -303299309), INT32_C( 1037552837), INT32_C(-1809400498), INT32_C(-1173875757),
                            INT32_C(-1855174495), INT32_C(-1958954726), INT32_C( 1573942546), INT32_C( 1061048615)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_insert_epi32(test_vec[i].a, test_vec[i].val, test_vec[i].index);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_insert_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    int64_t val;
    int index;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C(-4133106280234092490), INT64_C( 6391729968243045872),
                             INT64_C(  706579550387858698), INT64_C(-8094816971798215413)),
      INT64_C( 1361481579719255375), 1,
      simde_mm256_set_epi64x(INT64_C(-4133106280234092490), INT64_C( 6391729968243045872),
                             INT64_C( 1361481579719255375), INT64_C(-8094816971798215413)) },
    { simde_mm256_set_epi64x(INT64_C(-8867437639424933758), INT64_C(-7036537223594140679),
                             INT64_C(-5358710875727875484), INT64_C(-6579269737984092013)),
      INT64_C( -126322782266607095), 2,
      simde_mm256_set_epi64x(INT64_C(-8867437639424933758), INT64_C( -126322782266607095),
                             INT64_C(-5358710875727875484), INT64_C(-6579269737984092013)) },
    { simde_mm256_set_epi64x(INT64_C(-7734678004140859883), INT64_C(-5582204680470306162),
                             INT64_C( 2044782098971575482), INT64_C(-8188499254719149159)),
      INT64_C(-3278368141131404913), 2,
      simde_mm256_set_epi64x(INT64_C(-7734678004140859883), INT64_C(-3278368141131404913),
                             INT64_C( 2044782098971575482), INT64_C(-8188499254719149159)) },
    { simde_mm256_set_epi64x(INT64_C(-3640877478924402746), INT64_C(  938391798482300340),
                             INT64_C( -909178123939548037), INT64_C( 7297452342371937113)),
      INT64_C( 1438113784174363415), 1,
      simde_mm256_set_epi64x(INT64_C(-3640877478924402746), INT64_C(  938391798482300340),
                             INT64_C( 1438113784174363415), INT64_C( 7297452342371937113)) },
    { simde_mm256_set_epi64x(INT64_C(-1152105029838182042), INT64_C( 7892262547659267546),
                             INT64_C( 4360439452681479110), INT64_C(  981978176053929152)),
      INT64_C( 1286379124931981636), 0,
      simde_mm256_set_epi64x(INT64_C(-1152105029838182042), INT64_C( 7892262547659267546),
                             INT64_C( 4360439452681479110), INT64_C( 1286379124931981636)) },
    { simde_mm256_set_epi64x(INT64_C( 1093678232940922918), INT64_C(  967020122528653444),
                             INT64_C(-7373331086455297145), INT64_C( 1529441791029094026)),
      INT64_C( 8641473307934905812), 1,
      simde_mm256_set_epi64x(INT64_C( 1093678232940922918), INT64_C(  967020122528653444),
                             INT64_C( 8641473307934905812), INT64_C( 1529441791029094026)) },
    { simde_mm256_set_epi64x(INT64_C(-2258751460500637869), INT64_C( 6563092370622491241),
                             INT64_C( 6402152630995329451), INT64_C(-9189113835618004127)),
      INT64_C(-8979985299286344880), 1,
      simde_mm256_set_epi64x(INT64_C(-2258751460500637869), INT64_C( 6563092370622491241),
                             INT64_C(-8979985299286344880), INT64_C(-9189113835618004127)) },
    { simde_mm256_set_epi64x(INT64_C( 3948552162617719541), INT64_C( 5037957059424157080),
                             INT64_C( 6625523276490478238), INT64_C( 1891428553313230937)),
      INT64_C(-4032996300484233102), 2,
      simde_mm256_set_epi64x(INT64_C( 3948552162617719541), INT64_C(-4032996300484233102),
                             INT64_C( 6625523276490478238), INT64_C( 1891428553313230937)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_insert_epi64(test_vec[i].a, test_vec[i].val, test_vec[i].index);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_insertf128_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m128 b;
    simde__m256 ra;
    simde__m256 rb;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   57.86), SIMDE_FLOAT32_C(  900.49),
                         SIMDE_FLOAT32_C(  678.15), SIMDE_FLOAT32_C( -551.43),
                         SIMDE_FLOAT32_C(  431.88), SIMDE_FLOAT32_C( -426.33),
                         SIMDE_FLOAT32_C( -705.72), SIMDE_FLOAT32_C(  809.23)),
      simde_mm_set_ps   (SIMDE_FLOAT32_C( -625.43), SIMDE_FLOAT32_C( -829.28),
                         SIMDE_FLOAT32_C(  -42.04), SIMDE_FLOAT32_C( -643.64)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   57.86), SIMDE_FLOAT32_C(  900.49),
                         SIMDE_FLOAT32_C(  678.15), SIMDE_FLOAT32_C( -551.43),
                         SIMDE_FLOAT32_C( -625.43), SIMDE_FLOAT32_C( -829.28),
                         SIMDE_FLOAT32_C(  -42.04), SIMDE_FLOAT32_C( -643.64)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -625.43), SIMDE_FLOAT32_C( -829.28),
                         SIMDE_FLOAT32_C(  -42.04), SIMDE_FLOAT32_C( -643.64),
                         SIMDE_FLOAT32_C(  431.88), SIMDE_FLOAT32_C( -426.33),
                         SIMDE_FLOAT32_C( -705.72), SIMDE_FLOAT32_C(  809.23)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -837.79), SIMDE_FLOAT32_C(  338.83),
                         SIMDE_FLOAT32_C(  296.45), SIMDE_FLOAT32_C(  172.80),
                         SIMDE_FLOAT32_C(  220.09), SIMDE_FLOAT32_C(  171.14),
                         SIMDE_FLOAT32_C(  492.30), SIMDE_FLOAT32_C( -224.75)),
      simde_mm_set_ps   (SIMDE_FLOAT32_C( -479.01), SIMDE_FLOAT32_C(  686.13),
                         SIMDE_FLOAT32_C( -518.69), SIMDE_FLOAT32_C( -606.38)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -837.79), SIMDE_FLOAT32_C(  338.83),
                         SIMDE_FLOAT32_C(  296.45), SIMDE_FLOAT32_C(  172.80),
                         SIMDE_FLOAT32_C( -479.01), SIMDE_FLOAT32_C(  686.13),
                         SIMDE_FLOAT32_C( -518.69), SIMDE_FLOAT32_C( -606.38)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -479.01), SIMDE_FLOAT32_C(  686.13),
                         SIMDE_FLOAT32_C( -518.69), SIMDE_FLOAT32_C( -606.38),
                         SIMDE_FLOAT32_C(  220.09), SIMDE_FLOAT32_C(  171.14),
                         SIMDE_FLOAT32_C(  492.30), SIMDE_FLOAT32_C( -224.75)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -665.08), SIMDE_FLOAT32_C( -599.25),
                         SIMDE_FLOAT32_C( -107.42), SIMDE_FLOAT32_C( -565.87),
                         SIMDE_FLOAT32_C( -588.15), SIMDE_FLOAT32_C(  906.13),
                         SIMDE_FLOAT32_C(  481.87), SIMDE_FLOAT32_C(  540.93)),
      simde_mm_set_ps   (SIMDE_FLOAT32_C(  308.44), SIMDE_FLOAT32_C( -387.39),
                         SIMDE_FLOAT32_C(  312.59), SIMDE_FLOAT32_C( -811.76)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -665.08), SIMDE_FLOAT32_C( -599.25),
                         SIMDE_FLOAT32_C( -107.42), SIMDE_FLOAT32_C( -565.87),
                         SIMDE_FLOAT32_C(  308.44), SIMDE_FLOAT32_C( -387.39),
                         SIMDE_FLOAT32_C(  312.59), SIMDE_FLOAT32_C( -811.76)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  308.44), SIMDE_FLOAT32_C( -387.39),
                         SIMDE_FLOAT32_C(  312.59), SIMDE_FLOAT32_C( -811.76),
                         SIMDE_FLOAT32_C( -588.15), SIMDE_FLOAT32_C(  906.13),
                         SIMDE_FLOAT32_C(  481.87), SIMDE_FLOAT32_C(  540.93)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -499.97), SIMDE_FLOAT32_C( -474.63),
                         SIMDE_FLOAT32_C( -449.49), SIMDE_FLOAT32_C(  941.31),
                         SIMDE_FLOAT32_C( -102.84), SIMDE_FLOAT32_C( -165.66),
                         SIMDE_FLOAT32_C( -680.74), SIMDE_FLOAT32_C(   98.73)),
      simde_mm_set_ps   (SIMDE_FLOAT32_C( -600.34), SIMDE_FLOAT32_C(  321.05),
                         SIMDE_FLOAT32_C(  438.78), SIMDE_FLOAT32_C(  -70.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -499.97), SIMDE_FLOAT32_C( -474.63),
                         SIMDE_FLOAT32_C( -449.49), SIMDE_FLOAT32_C(  941.31),
                         SIMDE_FLOAT32_C( -600.34), SIMDE_FLOAT32_C(  321.05),
                         SIMDE_FLOAT32_C(  438.78), SIMDE_FLOAT32_C(  -70.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -600.34), SIMDE_FLOAT32_C(  321.05),
                         SIMDE_FLOAT32_C(  438.78), SIMDE_FLOAT32_C(  -70.17),
                         SIMDE_FLOAT32_C( -102.84), SIMDE_FLOAT32_C( -165.66),
                         SIMDE_FLOAT32_C( -680.74), SIMDE_FLOAT32_C(   98.73)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -402.57), SIMDE_FLOAT32_C( -372.27),
                         SIMDE_FLOAT32_C( -839.54), SIMDE_FLOAT32_C(  507.35),
                         SIMDE_FLOAT32_C( -596.72), SIMDE_FLOAT32_C(  333.88),
                         SIMDE_FLOAT32_C( -839.21), SIMDE_FLOAT32_C( -624.72)),
      simde_mm_set_ps   (SIMDE_FLOAT32_C( -109.04), SIMDE_FLOAT32_C( -997.63),
                         SIMDE_FLOAT32_C(  959.39), SIMDE_FLOAT32_C( -856.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -402.57), SIMDE_FLOAT32_C( -372.27),
                         SIMDE_FLOAT32_C( -839.54), SIMDE_FLOAT32_C(  507.35),
                         SIMDE_FLOAT32_C( -109.04), SIMDE_FLOAT32_C( -997.63),
                         SIMDE_FLOAT32_C(  959.39), SIMDE_FLOAT32_C( -856.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -109.04), SIMDE_FLOAT32_C( -997.63),
                         SIMDE_FLOAT32_C(  959.39), SIMDE_FLOAT32_C( -856.10),
                         SIMDE_FLOAT32_C( -596.72), SIMDE_FLOAT32_C(  333.88),
                         SIMDE_FLOAT32_C( -839.21), SIMDE_FLOAT32_C( -624.72)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -148.40), SIMDE_FLOAT32_C( -137.24),
                         SIMDE_FLOAT32_C(  665.88), SIMDE_FLOAT32_C( -239.38),
                         SIMDE_FLOAT32_C(  864.82), SIMDE_FLOAT32_C(  415.07),
                         SIMDE_FLOAT32_C(  223.96), SIMDE_FLOAT32_C(  144.96)),
      simde_mm_set_ps   (SIMDE_FLOAT32_C(  -29.35), SIMDE_FLOAT32_C( -415.61),
                         SIMDE_FLOAT32_C(  231.08), SIMDE_FLOAT32_C( -375.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -148.40), SIMDE_FLOAT32_C( -137.24),
                         SIMDE_FLOAT32_C(  665.88), SIMDE_FLOAT32_C( -239.38),
                         SIMDE_FLOAT32_C(  -29.35), SIMDE_FLOAT32_C( -415.61),
                         SIMDE_FLOAT32_C(  231.08), SIMDE_FLOAT32_C( -375.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -29.35), SIMDE_FLOAT32_C( -415.61),
                         SIMDE_FLOAT32_C(  231.08), SIMDE_FLOAT32_C( -375.28),
                         SIMDE_FLOAT32_C(  864.82), SIMDE_FLOAT32_C(  415.07),
                         SIMDE_FLOAT32_C(  223.96), SIMDE_FLOAT32_C(  144.96)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  384.21), SIMDE_FLOAT32_C( -172.99),
                         SIMDE_FLOAT32_C( -651.42), SIMDE_FLOAT32_C(  104.60),
                         SIMDE_FLOAT32_C( -412.61), SIMDE_FLOAT32_C( -685.74),
                         SIMDE_FLOAT32_C(  349.45), SIMDE_FLOAT32_C(  431.71)),
      simde_mm_set_ps   (SIMDE_FLOAT32_C(  810.19), SIMDE_FLOAT32_C(   94.73),
                         SIMDE_FLOAT32_C(  542.66), SIMDE_FLOAT32_C(  824.78)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  384.21), SIMDE_FLOAT32_C( -172.99),
                         SIMDE_FLOAT32_C( -651.42), SIMDE_FLOAT32_C(  104.60),
                         SIMDE_FLOAT32_C(  810.19), SIMDE_FLOAT32_C(   94.73),
                         SIMDE_FLOAT32_C(  542.66), SIMDE_FLOAT32_C(  824.78)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  810.19), SIMDE_FLOAT32_C(   94.73),
                         SIMDE_FLOAT32_C(  542.66), SIMDE_FLOAT32_C(  824.78),
                         SIMDE_FLOAT32_C( -412.61), SIMDE_FLOAT32_C( -685.74),
                         SIMDE_FLOAT32_C(  349.45), SIMDE_FLOAT32_C(  431.71)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  117.02), SIMDE_FLOAT32_C(  874.06),
                         SIMDE_FLOAT32_C( -896.71), SIMDE_FLOAT32_C(  927.83),
                         SIMDE_FLOAT32_C( -471.09), SIMDE_FLOAT32_C(  907.26),
                         SIMDE_FLOAT32_C(  774.08), SIMDE_FLOAT32_C(  141.60)),
      simde_mm_set_ps   (SIMDE_FLOAT32_C(   69.32), SIMDE_FLOAT32_C(  645.62),
                         SIMDE_FLOAT32_C(  860.89), SIMDE_FLOAT32_C(  694.26)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  117.02), SIMDE_FLOAT32_C(  874.06),
                         SIMDE_FLOAT32_C( -896.71), SIMDE_FLOAT32_C(  927.83),
                         SIMDE_FLOAT32_C(   69.32), SIMDE_FLOAT32_C(  645.62),
                         SIMDE_FLOAT32_C(  860.89), SIMDE_FLOAT32_C(  694.26)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   69.32), SIMDE_FLOAT32_C(  645.62),
                         SIMDE_FLOAT32_C(  860.89), SIMDE_FLOAT32_C(  694.26),
                         SIMDE_FLOAT32_C( -471.09), SIMDE_FLOAT32_C(  907.26),
                         SIMDE_FLOAT32_C(  774.08), SIMDE_FLOAT32_C(  141.60)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 ra = simde_mm256_insertf128_ps(test_vec[i].a, test_vec[i].b, 0);
    simde__m256 rb = simde_mm256_insertf128_ps(test_vec[i].a, test_vec[i].b, 1);
    simde_assert_m256_f32_equal(ra, test_vec[i].ra, 1);
    simde_assert_m256_f32_equal(rb, test_vec[i].rb, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_insertf128_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m128d b;
    simde__m256d ra;
    simde__m256d rb;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  500.07), SIMDE_FLOAT64_C(   24.20),
                         SIMDE_FLOAT64_C( -264.31), SIMDE_FLOAT64_C(  584.01)),
      simde_mm_set_pd   (SIMDE_FLOAT64_C(  431.47), SIMDE_FLOAT64_C(  318.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  500.07), SIMDE_FLOAT64_C(   24.20),
                         SIMDE_FLOAT64_C(  431.47), SIMDE_FLOAT64_C(  318.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  431.47), SIMDE_FLOAT64_C(  318.12),
                         SIMDE_FLOAT64_C( -264.31), SIMDE_FLOAT64_C(  584.01)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  669.13), SIMDE_FLOAT64_C( -378.72),
                         SIMDE_FLOAT64_C( -204.56), SIMDE_FLOAT64_C(  289.88)),
      simde_mm_set_pd   (SIMDE_FLOAT64_C(  609.30), SIMDE_FLOAT64_C(  491.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  669.13), SIMDE_FLOAT64_C( -378.72),
                         SIMDE_FLOAT64_C(  609.30), SIMDE_FLOAT64_C(  491.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  609.30), SIMDE_FLOAT64_C(  491.95),
                         SIMDE_FLOAT64_C( -204.56), SIMDE_FLOAT64_C(  289.88)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -439.47), SIMDE_FLOAT64_C(  501.94),
                         SIMDE_FLOAT64_C( -311.14), SIMDE_FLOAT64_C( -486.50)),
      simde_mm_set_pd   (SIMDE_FLOAT64_C(  460.51), SIMDE_FLOAT64_C(  800.13)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -439.47), SIMDE_FLOAT64_C(  501.94),
                         SIMDE_FLOAT64_C(  460.51), SIMDE_FLOAT64_C(  800.13)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  460.51), SIMDE_FLOAT64_C(  800.13),
                         SIMDE_FLOAT64_C( -311.14), SIMDE_FLOAT64_C( -486.50)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -828.83), SIMDE_FLOAT64_C(  892.34),
                         SIMDE_FLOAT64_C(  849.35), SIMDE_FLOAT64_C(   71.26)),
      simde_mm_set_pd   (SIMDE_FLOAT64_C(  690.69), SIMDE_FLOAT64_C( -666.59)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -828.83), SIMDE_FLOAT64_C(  892.34),
                         SIMDE_FLOAT64_C(  690.69), SIMDE_FLOAT64_C( -666.59)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  690.69), SIMDE_FLOAT64_C( -666.59),
                         SIMDE_FLOAT64_C(  849.35), SIMDE_FLOAT64_C(   71.26)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -393.25), SIMDE_FLOAT64_C( -143.78),
                         SIMDE_FLOAT64_C(  452.34), SIMDE_FLOAT64_C(  313.17)),
      simde_mm_set_pd   (SIMDE_FLOAT64_C(    2.43), SIMDE_FLOAT64_C( -405.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -393.25), SIMDE_FLOAT64_C( -143.78),
                         SIMDE_FLOAT64_C(    2.43), SIMDE_FLOAT64_C( -405.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    2.43), SIMDE_FLOAT64_C( -405.20),
                         SIMDE_FLOAT64_C(  452.34), SIMDE_FLOAT64_C(  313.17)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -19.72), SIMDE_FLOAT64_C( -282.65),
                         SIMDE_FLOAT64_C( -261.63), SIMDE_FLOAT64_C( -641.13)),
      simde_mm_set_pd   (SIMDE_FLOAT64_C(  818.65), SIMDE_FLOAT64_C( -240.18)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -19.72), SIMDE_FLOAT64_C( -282.65),
                         SIMDE_FLOAT64_C(  818.65), SIMDE_FLOAT64_C( -240.18)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  818.65), SIMDE_FLOAT64_C( -240.18),
                         SIMDE_FLOAT64_C( -261.63), SIMDE_FLOAT64_C( -641.13)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  809.87), SIMDE_FLOAT64_C(  692.31),
                         SIMDE_FLOAT64_C(  848.43), SIMDE_FLOAT64_C( -514.36)),
      simde_mm_set_pd   (SIMDE_FLOAT64_C( -330.16), SIMDE_FLOAT64_C(  670.26)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  809.87), SIMDE_FLOAT64_C(  692.31),
                         SIMDE_FLOAT64_C( -330.16), SIMDE_FLOAT64_C(  670.26)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -330.16), SIMDE_FLOAT64_C(  670.26),
                         SIMDE_FLOAT64_C(  848.43), SIMDE_FLOAT64_C( -514.36)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -917.99), SIMDE_FLOAT64_C(  637.33),
                         SIMDE_FLOAT64_C(  143.49), SIMDE_FLOAT64_C(  390.85)),
      simde_mm_set_pd   (SIMDE_FLOAT64_C( -606.83), SIMDE_FLOAT64_C(  948.25)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -917.99), SIMDE_FLOAT64_C(  637.33),
                         SIMDE_FLOAT64_C( -606.83), SIMDE_FLOAT64_C(  948.25)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -606.83), SIMDE_FLOAT64_C(  948.25),
                         SIMDE_FLOAT64_C(  143.49), SIMDE_FLOAT64_C(  390.85)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d ra = simde_mm256_insertf128_pd(test_vec[i].a, test_vec[i].b, 0);
    simde__m256d rb = simde_mm256_insertf128_pd(test_vec[i].a, test_vec[i].b, 1);
    simde_assert_m256d_f64_equal(ra, test_vec[i].ra, 1);
    simde_assert_m256d_f64_equal(rb, test_vec[i].rb, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_insertf128_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m128i b;
    simde__m256i ra;
    simde__m256i rb;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( 1732788931), INT32_C( -493919285), INT32_C( -171391193), INT32_C( 1397412103),
                            INT32_C( -356536147), INT32_C(-1692932708), INT32_C(-1699348696), INT32_C( -647395099)),
      simde_mm_set_epi32   (INT32_C(-1522680411), INT32_C(-1731979321), INT32_C( 1240335413), INT32_C(  201854332)),
      simde_mm256_set_epi32(INT32_C( 1732788931), INT32_C( -493919285), INT32_C( -171391193), INT32_C( 1397412103),
                            INT32_C(-1522680411), INT32_C(-1731979321), INT32_C( 1240335413), INT32_C(  201854332)),
      simde_mm256_set_epi32(INT32_C(-1522680411), INT32_C(-1731979321), INT32_C( 1240335413), INT32_C(  201854332),
                            INT32_C( -356536147), INT32_C(-1692932708), INT32_C(-1699348696), INT32_C( -647395099)) },
    { simde_mm256_set_epi32(INT32_C(-1444875329), INT32_C( 1610023191), INT32_C( -708588022), INT32_C( -172947680),
                            INT32_C(  545675582), INT32_C( 1925063203), INT32_C(  200249152), INT32_C(  925361522)),
      simde_mm_set_epi32   (INT32_C( -719778838), INT32_C( -908663617), INT32_C(-1043096582), INT32_C( 2027106265)),
      simde_mm256_set_epi32(INT32_C(-1444875329), INT32_C( 1610023191), INT32_C( -708588022), INT32_C( -172947680),
                            INT32_C( -719778838), INT32_C( -908663617), INT32_C(-1043096582), INT32_C( 2027106265)),
      simde_mm256_set_epi32(INT32_C( -719778838), INT32_C( -908663617), INT32_C(-1043096582), INT32_C( 2027106265),
                            INT32_C(  545675582), INT32_C( 1925063203), INT32_C(  200249152), INT32_C(  925361522)) },
    { simde_mm256_set_epi32(INT32_C(  819255641), INT32_C(  758383634), INT32_C( -712717178), INT32_C( 1831898363),
                            INT32_C( -652589148), INT32_C(  437505059), INT32_C(-1426201125), INT32_C(  915542579)),
      simde_mm_set_epi32   (INT32_C( 1102980249), INT32_C( 1568821342), INT32_C( 1031497605), INT32_C( 1535564672)),
      simde_mm256_set_epi32(INT32_C(  819255641), INT32_C(  758383634), INT32_C( -712717178), INT32_C( 1831898363),
                            INT32_C( 1102980249), INT32_C( 1568821342), INT32_C( 1031497605), INT32_C( 1535564672)),
      simde_mm256_set_epi32(INT32_C( 1102980249), INT32_C( 1568821342), INT32_C( 1031497605), INT32_C( 1535564672),
                            INT32_C( -652589148), INT32_C(  437505059), INT32_C(-1426201125), INT32_C(  915542579)) },
    { simde_mm256_set_epi32(INT32_C(-1576300711), INT32_C(  804080573), INT32_C(-1947930635), INT32_C( -773073118),
                            INT32_C( -708044343), INT32_C( 1025803241), INT32_C(-1542400953), INT32_C( 1513652867)),
      simde_mm_set_epi32   (INT32_C( -630903986), INT32_C( 1210274072), INT32_C(-1479627472), INT32_C( 1540958491)),
      simde_mm256_set_epi32(INT32_C(-1576300711), INT32_C(  804080573), INT32_C(-1947930635), INT32_C( -773073118),
                            INT32_C( -630903986), INT32_C( 1210274072), INT32_C(-1479627472), INT32_C( 1540958491)),
      simde_mm256_set_epi32(INT32_C( -630903986), INT32_C( 1210274072), INT32_C(-1479627472), INT32_C( 1540958491),
                            INT32_C( -708044343), INT32_C( 1025803241), INT32_C(-1542400953), INT32_C( 1513652867)) },
    { simde_mm256_set_epi32(INT32_C(-1474400259), INT32_C( 1988182849), INT32_C(-1345043070), INT32_C(-2043590369),
                            INT32_C( -792511350), INT32_C(-1919476039), INT32_C( -711077027), INT32_C(-1924737697)),
      simde_mm_set_epi32   (INT32_C(-1229154872), INT32_C( 1506932355), INT32_C(  529233496), INT32_C(  900061932)),
      simde_mm256_set_epi32(INT32_C(-1474400259), INT32_C( 1988182849), INT32_C(-1345043070), INT32_C(-2043590369),
                            INT32_C(-1229154872), INT32_C( 1506932355), INT32_C(  529233496), INT32_C(  900061932)),
      simde_mm256_set_epi32(INT32_C(-1229154872), INT32_C( 1506932355), INT32_C(  529233496), INT32_C(  900061932),
                            INT32_C( -792511350), INT32_C(-1919476039), INT32_C( -711077027), INT32_C(-1924737697)) },
    { simde_mm256_set_epi32(INT32_C( 1011012252), INT32_C(-1383487313), INT32_C( -799281089), INT32_C(-1421799289),
                            INT32_C(-1020863292), INT32_C( -870274327), INT32_C(  767506840), INT32_C(  905532467)),
      simde_mm_set_epi32   (INT32_C(  535053718), INT32_C( 1571414305), INT32_C(  327456521), INT32_C(  562021450)),
      simde_mm256_set_epi32(INT32_C( 1011012252), INT32_C(-1383487313), INT32_C( -799281089), INT32_C(-1421799289),
                            INT32_C(  535053718), INT32_C( 1571414305), INT32_C(  327456521), INT32_C(  562021450)),
      simde_mm256_set_epi32(INT32_C(  535053718), INT32_C( 1571414305), INT32_C(  327456521), INT32_C(  562021450),
                            INT32_C(-1020863292), INT32_C( -870274327), INT32_C(  767506840), INT32_C(  905532467)) },
    { simde_mm256_set_epi32(INT32_C(-1892816233), INT32_C( -258025342), INT32_C(-1474147149), INT32_C(  200557748),
                            INT32_C(  863187861), INT32_C( 1974870245), INT32_C( 1114174400), INT32_C( -122006961)),
      simde_mm_set_epi32   (INT32_C( 1960728456), INT32_C(-1615388317), INT32_C(  728614642), INT32_C(  181559353)),
      simde_mm256_set_epi32(INT32_C(-1892816233), INT32_C( -258025342), INT32_C(-1474147149), INT32_C(  200557748),
                            INT32_C( 1960728456), INT32_C(-1615388317), INT32_C(  728614642), INT32_C(  181559353)),
      simde_mm256_set_epi32(INT32_C( 1960728456), INT32_C(-1615388317), INT32_C(  728614642), INT32_C(  181559353),
                            INT32_C(  863187861), INT32_C( 1974870245), INT32_C( 1114174400), INT32_C( -122006961)) },
    { simde_mm256_set_epi32(INT32_C( -172940012), INT32_C(-1274554211), INT32_C( -855665209), INT32_C(  935611457),
                            INT32_C( -592164168), INT32_C(  945068232), INT32_C(  755470781), INT32_C(-1762512447)),
      simde_mm_set_epi32   (INT32_C(-1172491108), INT32_C(-1413112125), INT32_C(   65588240), INT32_C(-1859214337)),
      simde_mm256_set_epi32(INT32_C( -172940012), INT32_C(-1274554211), INT32_C( -855665209), INT32_C(  935611457),
                            INT32_C(-1172491108), INT32_C(-1413112125), INT32_C(   65588240), INT32_C(-1859214337)),
      simde_mm256_set_epi32(INT32_C(-1172491108), INT32_C(-1413112125), INT32_C(   65588240), INT32_C(-1859214337),
                            INT32_C( -592164168), INT32_C(  945068232), INT32_C(  755470781), INT32_C(-1762512447)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i ra = simde_mm256_insertf128_si256(test_vec[i].a, test_vec[i].b, 0);
    simde__m256i rb = simde_mm256_insertf128_si256(test_vec[i].a, test_vec[i].b, 1);
    simde_assert_m256i_i32(ra, ==, test_vec[i].ra);
    simde_assert_m256i_i32(rb, ==, test_vec[i].rb);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_lddqu_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( -208613396), INT32_C(  972060947), INT32_C( 1079690819), INT32_C(-1629141358),
                            INT32_C( -291568998), INT32_C( -706346303), INT32_C( 1782265269), INT32_C(  663843445)),
      simde_mm256_set_epi32(INT32_C( -208613396), INT32_C(  972060947), INT32_C( 1079690819), INT32_C(-1629141358),
                            INT32_C( -291568998), INT32_C( -706346303), INT32_C( 1782265269), INT32_C(  663843445)) },
    { simde_mm256_set_epi32(INT32_C( -542385526), INT32_C(-1915647746), INT32_C(  251129882), INT32_C(  290247368),
                            INT32_C(  363399145), INT32_C(  688121978), INT32_C(  600807845), INT32_C( 1456401224)),
      simde_mm256_set_epi32(INT32_C( -542385526), INT32_C(-1915647746), INT32_C(  251129882), INT32_C(  290247368),
                            INT32_C(  363399145), INT32_C(  688121978), INT32_C(  600807845), INT32_C( 1456401224)) },
    { simde_mm256_set_epi32(INT32_C(  862880243), INT32_C(  961555167), INT32_C( -704902562), INT32_C(-2017515450),
                            INT32_C(-1906482322), INT32_C(-1699379933), INT32_C( 1894527886), INT32_C( 2049947519)),
      simde_mm256_set_epi32(INT32_C(  862880243), INT32_C(  961555167), INT32_C( -704902562), INT32_C(-2017515450),
                            INT32_C(-1906482322), INT32_C(-1699379933), INT32_C( 1894527886), INT32_C( 2049947519)) },
    { simde_mm256_set_epi32(INT32_C( 1564827830), INT32_C( -831950379), INT32_C(  815117120), INT32_C( -372364589),
                            INT32_C(-1095370522), INT32_C( 1608512554), INT32_C( 1210942744), INT32_C(  816264608)),
      simde_mm256_set_epi32(INT32_C( 1564827830), INT32_C( -831950379), INT32_C(  815117120), INT32_C( -372364589),
                            INT32_C(-1095370522), INT32_C( 1608512554), INT32_C( 1210942744), INT32_C(  816264608)) },
    { simde_mm256_set_epi32(INT32_C( 1014835213), INT32_C(  419509758), INT32_C( -940172407), INT32_C( 2075423717),
                            INT32_C( -958302313), INT32_C( 2056263130), INT32_C( -179845947), INT32_C( -487391602)),
      simde_mm256_set_epi32(INT32_C( 1014835213), INT32_C(  419509758), INT32_C( -940172407), INT32_C( 2075423717),
                            INT32_C( -958302313), INT32_C( 2056263130), INT32_C( -179845947), INT32_C( -487391602)) },
    { simde_mm256_set_epi32(INT32_C(  750230136), INT32_C(  830844077), INT32_C( 1366738463), INT32_C( 1719449608),
                            INT32_C(  953227083), INT32_C( -624601508), INT32_C( -983006206), INT32_C( 1138640848)),
      simde_mm256_set_epi32(INT32_C(  750230136), INT32_C(  830844077), INT32_C( 1366738463), INT32_C( 1719449608),
                            INT32_C(  953227083), INT32_C( -624601508), INT32_C( -983006206), INT32_C( 1138640848)) },
    { simde_mm256_set_epi32(INT32_C(-2045061394), INT32_C( -759814821), INT32_C( 1064937743), INT32_C(-1124388611),
                            INT32_C( -168818003), INT32_C( -757055903), INT32_C(-1606176919), INT32_C(  254467933)),
      simde_mm256_set_epi32(INT32_C(-2045061394), INT32_C( -759814821), INT32_C( 1064937743), INT32_C(-1124388611),
                            INT32_C( -168818003), INT32_C( -757055903), INT32_C(-1606176919), INT32_C(  254467933)) },
    { simde_mm256_set_epi32(INT32_C(-1387663431), INT32_C( 2083885974), INT32_C(  524830617), INT32_C( 1548734942),
                            INT32_C( 1378860315), INT32_C(-1149727640), INT32_C( 1373643603), INT32_C(  772353923)),
      simde_mm256_set_epi32(INT32_C(-1387663431), INT32_C( 2083885974), INT32_C(  524830617), INT32_C( 1548734942),
                            INT32_C( 1378860315), INT32_C(-1149727640), INT32_C( 1373643603), INT32_C(  772353923)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_lddqu_si256(&(test_vec[i].a));
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_load_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  461.56), SIMDE_FLOAT64_C(  635.23),
                         SIMDE_FLOAT64_C( -438.71), SIMDE_FLOAT64_C(  235.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  461.56), SIMDE_FLOAT64_C(  635.23),
                         SIMDE_FLOAT64_C( -438.71), SIMDE_FLOAT64_C(  235.76)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   96.53), SIMDE_FLOAT64_C( -742.88),
                         SIMDE_FLOAT64_C( -135.09), SIMDE_FLOAT64_C( -963.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   96.53), SIMDE_FLOAT64_C( -742.88),
                         SIMDE_FLOAT64_C( -135.09), SIMDE_FLOAT64_C( -963.10)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  599.28), SIMDE_FLOAT64_C( -624.99),
                         SIMDE_FLOAT64_C(  689.15), SIMDE_FLOAT64_C( -793.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  599.28), SIMDE_FLOAT64_C( -624.99),
                         SIMDE_FLOAT64_C(  689.15), SIMDE_FLOAT64_C( -793.31)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -987.98), SIMDE_FLOAT64_C(  566.07),
                         SIMDE_FLOAT64_C( -868.52), SIMDE_FLOAT64_C( -607.38)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -987.98), SIMDE_FLOAT64_C(  566.07),
                         SIMDE_FLOAT64_C( -868.52), SIMDE_FLOAT64_C( -607.38)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -700.73), SIMDE_FLOAT64_C( -564.20),
                         SIMDE_FLOAT64_C(  977.88), SIMDE_FLOAT64_C(  153.72)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -700.73), SIMDE_FLOAT64_C( -564.20),
                         SIMDE_FLOAT64_C(  977.88), SIMDE_FLOAT64_C(  153.72)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  594.14), SIMDE_FLOAT64_C( -272.29),
                         SIMDE_FLOAT64_C( -345.35), SIMDE_FLOAT64_C(  372.07)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  594.14), SIMDE_FLOAT64_C( -272.29),
                         SIMDE_FLOAT64_C( -345.35), SIMDE_FLOAT64_C(  372.07)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -338.44), SIMDE_FLOAT64_C( -675.98),
                         SIMDE_FLOAT64_C( -666.60), SIMDE_FLOAT64_C(  489.29)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -338.44), SIMDE_FLOAT64_C( -675.98),
                         SIMDE_FLOAT64_C( -666.60), SIMDE_FLOAT64_C(  489.29)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -432.94), SIMDE_FLOAT64_C( -166.81),
                         SIMDE_FLOAT64_C(  596.98), SIMDE_FLOAT64_C(  183.92)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -432.94), SIMDE_FLOAT64_C( -166.81),
                         SIMDE_FLOAT64_C(  596.98), SIMDE_FLOAT64_C(  183.92)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_load_pd((double*) &(test_vec[i].a));
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_load_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -952.80), SIMDE_FLOAT32_C(  686.70),
                         SIMDE_FLOAT32_C(  818.29), SIMDE_FLOAT32_C( -601.06),
                         SIMDE_FLOAT32_C( -260.54), SIMDE_FLOAT32_C( -393.74),
                         SIMDE_FLOAT32_C(  357.88), SIMDE_FLOAT32_C(  396.93)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -952.80), SIMDE_FLOAT32_C(  686.70),
                         SIMDE_FLOAT32_C(  818.29), SIMDE_FLOAT32_C( -601.06),
                         SIMDE_FLOAT32_C( -260.54), SIMDE_FLOAT32_C( -393.74),
                         SIMDE_FLOAT32_C(  357.88), SIMDE_FLOAT32_C(  396.93)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -205.19), SIMDE_FLOAT32_C(  156.84),
                         SIMDE_FLOAT32_C( -222.09), SIMDE_FLOAT32_C(  908.97),
                         SIMDE_FLOAT32_C( -591.86), SIMDE_FLOAT32_C( -230.59),
                         SIMDE_FLOAT32_C(  434.60), SIMDE_FLOAT32_C(  107.82)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -205.19), SIMDE_FLOAT32_C(  156.84),
                         SIMDE_FLOAT32_C( -222.09), SIMDE_FLOAT32_C(  908.97),
                         SIMDE_FLOAT32_C( -591.86), SIMDE_FLOAT32_C( -230.59),
                         SIMDE_FLOAT32_C(  434.60), SIMDE_FLOAT32_C(  107.82)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  123.60), SIMDE_FLOAT32_C( -110.90),
                         SIMDE_FLOAT32_C(  522.49), SIMDE_FLOAT32_C( -101.00),
                         SIMDE_FLOAT32_C( -366.35), SIMDE_FLOAT32_C(  774.17),
                         SIMDE_FLOAT32_C(  -65.28), SIMDE_FLOAT32_C(   -2.76)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  123.60), SIMDE_FLOAT32_C( -110.90),
                         SIMDE_FLOAT32_C(  522.49), SIMDE_FLOAT32_C( -101.00),
                         SIMDE_FLOAT32_C( -366.35), SIMDE_FLOAT32_C(  774.17),
                         SIMDE_FLOAT32_C(  -65.28), SIMDE_FLOAT32_C(   -2.76)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -52.68), SIMDE_FLOAT32_C( -169.65),
                         SIMDE_FLOAT32_C(  151.56), SIMDE_FLOAT32_C(  -29.81),
                         SIMDE_FLOAT32_C(  692.17), SIMDE_FLOAT32_C(  452.50),
                         SIMDE_FLOAT32_C( -924.09), SIMDE_FLOAT32_C(  574.83)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -52.68), SIMDE_FLOAT32_C( -169.65),
                         SIMDE_FLOAT32_C(  151.56), SIMDE_FLOAT32_C(  -29.81),
                         SIMDE_FLOAT32_C(  692.17), SIMDE_FLOAT32_C(  452.50),
                         SIMDE_FLOAT32_C( -924.09), SIMDE_FLOAT32_C(  574.83)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   42.45), SIMDE_FLOAT32_C( -931.86),
                         SIMDE_FLOAT32_C( -794.38), SIMDE_FLOAT32_C(  186.88),
                         SIMDE_FLOAT32_C(  527.15), SIMDE_FLOAT32_C(  668.50),
                         SIMDE_FLOAT32_C(  596.48), SIMDE_FLOAT32_C(  -76.77)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   42.45), SIMDE_FLOAT32_C( -931.86),
                         SIMDE_FLOAT32_C( -794.38), SIMDE_FLOAT32_C(  186.88),
                         SIMDE_FLOAT32_C(  527.15), SIMDE_FLOAT32_C(  668.50),
                         SIMDE_FLOAT32_C(  596.48), SIMDE_FLOAT32_C(  -76.77)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   46.04), SIMDE_FLOAT32_C(  307.12),
                         SIMDE_FLOAT32_C( -650.55), SIMDE_FLOAT32_C(  716.39),
                         SIMDE_FLOAT32_C( -622.25), SIMDE_FLOAT32_C( -493.53),
                         SIMDE_FLOAT32_C(  -13.43), SIMDE_FLOAT32_C( -585.13)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   46.04), SIMDE_FLOAT32_C(  307.12),
                         SIMDE_FLOAT32_C( -650.55), SIMDE_FLOAT32_C(  716.39),
                         SIMDE_FLOAT32_C( -622.25), SIMDE_FLOAT32_C( -493.53),
                         SIMDE_FLOAT32_C(  -13.43), SIMDE_FLOAT32_C( -585.13)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  928.00), SIMDE_FLOAT32_C( -654.49),
                         SIMDE_FLOAT32_C( -937.13), SIMDE_FLOAT32_C( -665.80),
                         SIMDE_FLOAT32_C( -783.53), SIMDE_FLOAT32_C(  495.35),
                         SIMDE_FLOAT32_C( -911.12), SIMDE_FLOAT32_C(  756.06)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  928.00), SIMDE_FLOAT32_C( -654.49),
                         SIMDE_FLOAT32_C( -937.13), SIMDE_FLOAT32_C( -665.80),
                         SIMDE_FLOAT32_C( -783.53), SIMDE_FLOAT32_C(  495.35),
                         SIMDE_FLOAT32_C( -911.12), SIMDE_FLOAT32_C(  756.06)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  359.98), SIMDE_FLOAT32_C(  -43.89),
                         SIMDE_FLOAT32_C(  761.79), SIMDE_FLOAT32_C(  681.73),
                         SIMDE_FLOAT32_C( -560.66), SIMDE_FLOAT32_C(  149.79),
                         SIMDE_FLOAT32_C( -419.99), SIMDE_FLOAT32_C(  662.22)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  359.98), SIMDE_FLOAT32_C(  -43.89),
                         SIMDE_FLOAT32_C(  761.79), SIMDE_FLOAT32_C(  681.73),
                         SIMDE_FLOAT32_C( -560.66), SIMDE_FLOAT32_C(  149.79),
                         SIMDE_FLOAT32_C( -419.99), SIMDE_FLOAT32_C(  662.22)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_load_ps((float*) &(test_vec[i].a));
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_load_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(   93433077), INT32_C(  912488615), INT32_C( -849505573), INT32_C( -538760324),
                            INT32_C(  576018808), INT32_C(  306399285), INT32_C(  761465198), INT32_C(   67322681)),
      simde_mm256_set_epi32(INT32_C(   93433077), INT32_C(  912488615), INT32_C( -849505573), INT32_C( -538760324),
                            INT32_C(  576018808), INT32_C(  306399285), INT32_C(  761465198), INT32_C(   67322681)) },
    { simde_mm256_set_epi32(INT32_C( 1661040700), INT32_C(-1506281364), INT32_C(  769308925), INT32_C( -545741767),
                            INT32_C(-1609914843), INT32_C(-1728610320), INT32_C( 1438363911), INT32_C(-1495474004)),
      simde_mm256_set_epi32(INT32_C( 1661040700), INT32_C(-1506281364), INT32_C(  769308925), INT32_C( -545741767),
                            INT32_C(-1609914843), INT32_C(-1728610320), INT32_C( 1438363911), INT32_C(-1495474004)) },
    { simde_mm256_set_epi32(INT32_C( -403469250), INT32_C( 1422195130), INT32_C( 1240509512), INT32_C(-1325093027),
                            INT32_C( 1112848703), INT32_C(  757887555), INT32_C( -808479029), INT32_C( 1524821649)),
      simde_mm256_set_epi32(INT32_C( -403469250), INT32_C( 1422195130), INT32_C( 1240509512), INT32_C(-1325093027),
                            INT32_C( 1112848703), INT32_C(  757887555), INT32_C( -808479029), INT32_C( 1524821649)) },
    { simde_mm256_set_epi32(INT32_C(  419753251), INT32_C( 1133371811), INT32_C( 1920523876), INT32_C( 1566543302),
                            INT32_C( 1608176387), INT32_C(  174748447), INT32_C(-1944132629), INT32_C(-1618941327)),
      simde_mm256_set_epi32(INT32_C(  419753251), INT32_C( 1133371811), INT32_C( 1920523876), INT32_C( 1566543302),
                            INT32_C( 1608176387), INT32_C(  174748447), INT32_C(-1944132629), INT32_C(-1618941327)) },
    { simde_mm256_set_epi32(INT32_C(  133578927), INT32_C(  -89176331), INT32_C(  533976318), INT32_C(  686005880),
                            INT32_C( 1680867737), INT32_C( -633287306), INT32_C( -911734776), INT32_C( 1028891739)),
      simde_mm256_set_epi32(INT32_C(  133578927), INT32_C(  -89176331), INT32_C(  533976318), INT32_C(  686005880),
                            INT32_C( 1680867737), INT32_C( -633287306), INT32_C( -911734776), INT32_C( 1028891739)) },
    { simde_mm256_set_epi32(INT32_C( 1968343895), INT32_C( 1991193919), INT32_C(-1412421123), INT32_C(-1413471204),
                            INT32_C( 1571538617), INT32_C(  392630938), INT32_C(   44925707), INT32_C(-1288122501)),
      simde_mm256_set_epi32(INT32_C( 1968343895), INT32_C( 1991193919), INT32_C(-1412421123), INT32_C(-1413471204),
                            INT32_C( 1571538617), INT32_C(  392630938), INT32_C(   44925707), INT32_C(-1288122501)) },
    { simde_mm256_set_epi32(INT32_C(  932954327), INT32_C(  884951875), INT32_C(-1145840174), INT32_C( 2040117874),
                            INT32_C(   39201359), INT32_C( -102892947), INT32_C(  740751736), INT32_C( 1598969461)),
      simde_mm256_set_epi32(INT32_C(  932954327), INT32_C(  884951875), INT32_C(-1145840174), INT32_C( 2040117874),
                            INT32_C(   39201359), INT32_C( -102892947), INT32_C(  740751736), INT32_C( 1598969461)) },
    { simde_mm256_set_epi32(INT32_C( -471731507), INT32_C( 1955207001), INT32_C(-1681640586), INT32_C( -304295513),
                            INT32_C( 1688427496), INT32_C(-1852849481), INT32_C( -533311004), INT32_C(  263226824)),
      simde_mm256_set_epi32(INT32_C( -471731507), INT32_C( 1955207001), INT32_C(-1681640586), INT32_C( -304295513),
                            INT32_C( 1688427496), INT32_C(-1852849481), INT32_C( -533311004), INT32_C(  263226824)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_load_si256(&(test_vec[i].a));
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_loadu_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  461.56), SIMDE_FLOAT64_C(  635.23),
                         SIMDE_FLOAT64_C( -438.71), SIMDE_FLOAT64_C(  235.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  461.56), SIMDE_FLOAT64_C(  635.23),
                         SIMDE_FLOAT64_C( -438.71), SIMDE_FLOAT64_C(  235.76)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   96.53), SIMDE_FLOAT64_C( -742.88),
                         SIMDE_FLOAT64_C( -135.09), SIMDE_FLOAT64_C( -963.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   96.53), SIMDE_FLOAT64_C( -742.88),
                         SIMDE_FLOAT64_C( -135.09), SIMDE_FLOAT64_C( -963.10)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  599.28), SIMDE_FLOAT64_C( -624.99),
                         SIMDE_FLOAT64_C(  689.15), SIMDE_FLOAT64_C( -793.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  599.28), SIMDE_FLOAT64_C( -624.99),
                         SIMDE_FLOAT64_C(  689.15), SIMDE_FLOAT64_C( -793.31)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -987.98), SIMDE_FLOAT64_C(  566.07),
                         SIMDE_FLOAT64_C( -868.52), SIMDE_FLOAT64_C( -607.38)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -987.98), SIMDE_FLOAT64_C(  566.07),
                         SIMDE_FLOAT64_C( -868.52), SIMDE_FLOAT64_C( -607.38)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -700.73), SIMDE_FLOAT64_C( -564.20),
                         SIMDE_FLOAT64_C(  977.88), SIMDE_FLOAT64_C(  153.72)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -700.73), SIMDE_FLOAT64_C( -564.20),
                         SIMDE_FLOAT64_C(  977.88), SIMDE_FLOAT64_C(  153.72)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  594.14), SIMDE_FLOAT64_C( -272.29),
                         SIMDE_FLOAT64_C( -345.35), SIMDE_FLOAT64_C(  372.07)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  594.14), SIMDE_FLOAT64_C( -272.29),
                         SIMDE_FLOAT64_C( -345.35), SIMDE_FLOAT64_C(  372.07)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -338.44), SIMDE_FLOAT64_C( -675.98),
                         SIMDE_FLOAT64_C( -666.60), SIMDE_FLOAT64_C(  489.29)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -338.44), SIMDE_FLOAT64_C( -675.98),
                         SIMDE_FLOAT64_C( -666.60), SIMDE_FLOAT64_C(  489.29)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -432.94), SIMDE_FLOAT64_C( -166.81),
                         SIMDE_FLOAT64_C(  596.98), SIMDE_FLOAT64_C(  183.92)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -432.94), SIMDE_FLOAT64_C( -166.81),
                         SIMDE_FLOAT64_C(  596.98), SIMDE_FLOAT64_C(  183.92)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_loadu_pd((double*) &(test_vec[i].a));
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_loadu_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -952.80), SIMDE_FLOAT32_C(  686.70),
                         SIMDE_FLOAT32_C(  818.29), SIMDE_FLOAT32_C( -601.06),
                         SIMDE_FLOAT32_C( -260.54), SIMDE_FLOAT32_C( -393.74),
                         SIMDE_FLOAT32_C(  357.88), SIMDE_FLOAT32_C(  396.93)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -952.80), SIMDE_FLOAT32_C(  686.70),
                         SIMDE_FLOAT32_C(  818.29), SIMDE_FLOAT32_C( -601.06),
                         SIMDE_FLOAT32_C( -260.54), SIMDE_FLOAT32_C( -393.74),
                         SIMDE_FLOAT32_C(  357.88), SIMDE_FLOAT32_C(  396.93)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -205.19), SIMDE_FLOAT32_C(  156.84),
                         SIMDE_FLOAT32_C( -222.09), SIMDE_FLOAT32_C(  908.97),
                         SIMDE_FLOAT32_C( -591.86), SIMDE_FLOAT32_C( -230.59),
                         SIMDE_FLOAT32_C(  434.60), SIMDE_FLOAT32_C(  107.82)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -205.19), SIMDE_FLOAT32_C(  156.84),
                         SIMDE_FLOAT32_C( -222.09), SIMDE_FLOAT32_C(  908.97),
                         SIMDE_FLOAT32_C( -591.86), SIMDE_FLOAT32_C( -230.59),
                         SIMDE_FLOAT32_C(  434.60), SIMDE_FLOAT32_C(  107.82)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  123.60), SIMDE_FLOAT32_C( -110.90),
                         SIMDE_FLOAT32_C(  522.49), SIMDE_FLOAT32_C( -101.00),
                         SIMDE_FLOAT32_C( -366.35), SIMDE_FLOAT32_C(  774.17),
                         SIMDE_FLOAT32_C(  -65.28), SIMDE_FLOAT32_C(   -2.76)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  123.60), SIMDE_FLOAT32_C( -110.90),
                         SIMDE_FLOAT32_C(  522.49), SIMDE_FLOAT32_C( -101.00),
                         SIMDE_FLOAT32_C( -366.35), SIMDE_FLOAT32_C(  774.17),
                         SIMDE_FLOAT32_C(  -65.28), SIMDE_FLOAT32_C(   -2.76)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -52.68), SIMDE_FLOAT32_C( -169.65),
                         SIMDE_FLOAT32_C(  151.56), SIMDE_FLOAT32_C(  -29.81),
                         SIMDE_FLOAT32_C(  692.17), SIMDE_FLOAT32_C(  452.50),
                         SIMDE_FLOAT32_C( -924.09), SIMDE_FLOAT32_C(  574.83)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -52.68), SIMDE_FLOAT32_C( -169.65),
                         SIMDE_FLOAT32_C(  151.56), SIMDE_FLOAT32_C(  -29.81),
                         SIMDE_FLOAT32_C(  692.17), SIMDE_FLOAT32_C(  452.50),
                         SIMDE_FLOAT32_C( -924.09), SIMDE_FLOAT32_C(  574.83)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   42.45), SIMDE_FLOAT32_C( -931.86),
                         SIMDE_FLOAT32_C( -794.38), SIMDE_FLOAT32_C(  186.88),
                         SIMDE_FLOAT32_C(  527.15), SIMDE_FLOAT32_C(  668.50),
                         SIMDE_FLOAT32_C(  596.48), SIMDE_FLOAT32_C(  -76.77)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   42.45), SIMDE_FLOAT32_C( -931.86),
                         SIMDE_FLOAT32_C( -794.38), SIMDE_FLOAT32_C(  186.88),
                         SIMDE_FLOAT32_C(  527.15), SIMDE_FLOAT32_C(  668.50),
                         SIMDE_FLOAT32_C(  596.48), SIMDE_FLOAT32_C(  -76.77)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   46.04), SIMDE_FLOAT32_C(  307.12),
                         SIMDE_FLOAT32_C( -650.55), SIMDE_FLOAT32_C(  716.39),
                         SIMDE_FLOAT32_C( -622.25), SIMDE_FLOAT32_C( -493.53),
                         SIMDE_FLOAT32_C(  -13.43), SIMDE_FLOAT32_C( -585.13)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   46.04), SIMDE_FLOAT32_C(  307.12),
                         SIMDE_FLOAT32_C( -650.55), SIMDE_FLOAT32_C(  716.39),
                         SIMDE_FLOAT32_C( -622.25), SIMDE_FLOAT32_C( -493.53),
                         SIMDE_FLOAT32_C(  -13.43), SIMDE_FLOAT32_C( -585.13)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  928.00), SIMDE_FLOAT32_C( -654.49),
                         SIMDE_FLOAT32_C( -937.13), SIMDE_FLOAT32_C( -665.80),
                         SIMDE_FLOAT32_C( -783.53), SIMDE_FLOAT32_C(  495.35),
                         SIMDE_FLOAT32_C( -911.12), SIMDE_FLOAT32_C(  756.06)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  928.00), SIMDE_FLOAT32_C( -654.49),
                         SIMDE_FLOAT32_C( -937.13), SIMDE_FLOAT32_C( -665.80),
                         SIMDE_FLOAT32_C( -783.53), SIMDE_FLOAT32_C(  495.35),
                         SIMDE_FLOAT32_C( -911.12), SIMDE_FLOAT32_C(  756.06)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  359.98), SIMDE_FLOAT32_C(  -43.89),
                         SIMDE_FLOAT32_C(  761.79), SIMDE_FLOAT32_C(  681.73),
                         SIMDE_FLOAT32_C( -560.66), SIMDE_FLOAT32_C(  149.79),
                         SIMDE_FLOAT32_C( -419.99), SIMDE_FLOAT32_C(  662.22)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  359.98), SIMDE_FLOAT32_C(  -43.89),
                         SIMDE_FLOAT32_C(  761.79), SIMDE_FLOAT32_C(  681.73),
                         SIMDE_FLOAT32_C( -560.66), SIMDE_FLOAT32_C(  149.79),
                         SIMDE_FLOAT32_C( -419.99), SIMDE_FLOAT32_C(  662.22)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_loadu_ps((float*) &(test_vec[i].a));
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_loadu_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(   93433077), INT32_C(  912488615), INT32_C( -849505573), INT32_C( -538760324),
                            INT32_C(  576018808), INT32_C(  306399285), INT32_C(  761465198), INT32_C(   67322681)),
      simde_mm256_set_epi32(INT32_C(   93433077), INT32_C(  912488615), INT32_C( -849505573), INT32_C( -538760324),
                            INT32_C(  576018808), INT32_C(  306399285), INT32_C(  761465198), INT32_C(   67322681)) },
    { simde_mm256_set_epi32(INT32_C( 1661040700), INT32_C(-1506281364), INT32_C(  769308925), INT32_C( -545741767),
                            INT32_C(-1609914843), INT32_C(-1728610320), INT32_C( 1438363911), INT32_C(-1495474004)),
      simde_mm256_set_epi32(INT32_C( 1661040700), INT32_C(-1506281364), INT32_C(  769308925), INT32_C( -545741767),
                            INT32_C(-1609914843), INT32_C(-1728610320), INT32_C( 1438363911), INT32_C(-1495474004)) },
    { simde_mm256_set_epi32(INT32_C( -403469250), INT32_C( 1422195130), INT32_C( 1240509512), INT32_C(-1325093027),
                            INT32_C( 1112848703), INT32_C(  757887555), INT32_C( -808479029), INT32_C( 1524821649)),
      simde_mm256_set_epi32(INT32_C( -403469250), INT32_C( 1422195130), INT32_C( 1240509512), INT32_C(-1325093027),
                            INT32_C( 1112848703), INT32_C(  757887555), INT32_C( -808479029), INT32_C( 1524821649)) },
    { simde_mm256_set_epi32(INT32_C(  419753251), INT32_C( 1133371811), INT32_C( 1920523876), INT32_C( 1566543302),
                            INT32_C( 1608176387), INT32_C(  174748447), INT32_C(-1944132629), INT32_C(-1618941327)),
      simde_mm256_set_epi32(INT32_C(  419753251), INT32_C( 1133371811), INT32_C( 1920523876), INT32_C( 1566543302),
                            INT32_C( 1608176387), INT32_C(  174748447), INT32_C(-1944132629), INT32_C(-1618941327)) },
    { simde_mm256_set_epi32(INT32_C(  133578927), INT32_C(  -89176331), INT32_C(  533976318), INT32_C(  686005880),
                            INT32_C( 1680867737), INT32_C( -633287306), INT32_C( -911734776), INT32_C( 1028891739)),
      simde_mm256_set_epi32(INT32_C(  133578927), INT32_C(  -89176331), INT32_C(  533976318), INT32_C(  686005880),
                            INT32_C( 1680867737), INT32_C( -633287306), INT32_C( -911734776), INT32_C( 1028891739)) },
    { simde_mm256_set_epi32(INT32_C( 1968343895), INT32_C( 1991193919), INT32_C(-1412421123), INT32_C(-1413471204),
                            INT32_C( 1571538617), INT32_C(  392630938), INT32_C(   44925707), INT32_C(-1288122501)),
      simde_mm256_set_epi32(INT32_C( 1968343895), INT32_C( 1991193919), INT32_C(-1412421123), INT32_C(-1413471204),
                            INT32_C( 1571538617), INT32_C(  392630938), INT32_C(   44925707), INT32_C(-1288122501)) },
    { simde_mm256_set_epi32(INT32_C(  932954327), INT32_C(  884951875), INT32_C(-1145840174), INT32_C( 2040117874),
                            INT32_C(   39201359), INT32_C( -102892947), INT32_C(  740751736), INT32_C( 1598969461)),
      simde_mm256_set_epi32(INT32_C(  932954327), INT32_C(  884951875), INT32_C(-1145840174), INT32_C( 2040117874),
                            INT32_C(   39201359), INT32_C( -102892947), INT32_C(  740751736), INT32_C( 1598969461)) },
    { simde_mm256_set_epi32(INT32_C( -471731507), INT32_C( 1955207001), INT32_C(-1681640586), INT32_C( -304295513),
                            INT32_C( 1688427496), INT32_C(-1852849481), INT32_C( -533311004), INT32_C(  263226824)),
      simde_mm256_set_epi32(INT32_C( -471731507), INT32_C( 1955207001), INT32_C(-1681640586), INT32_C( -304295513),
                            INT32_C( 1688427496), INT32_C(-1852849481), INT32_C( -533311004), INT32_C(  263226824)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_loadu_si256(&(test_vec[i].a));
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_loadu2_m128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  320.96), SIMDE_FLOAT32_C(  659.07), SIMDE_FLOAT32_C(  972.57), SIMDE_FLOAT32_C(  377.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  937.88), SIMDE_FLOAT32_C(  218.23), SIMDE_FLOAT32_C(  515.68), SIMDE_FLOAT32_C(  329.92)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  320.96), SIMDE_FLOAT32_C(  659.07),
                         SIMDE_FLOAT32_C(  972.57), SIMDE_FLOAT32_C(  377.20),
                         SIMDE_FLOAT32_C(  937.88), SIMDE_FLOAT32_C(  218.23),
                         SIMDE_FLOAT32_C(  515.68), SIMDE_FLOAT32_C(  329.92)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -943.66), SIMDE_FLOAT32_C( -391.47), SIMDE_FLOAT32_C( -426.68), SIMDE_FLOAT32_C(  276.94)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  828.33), SIMDE_FLOAT32_C(  156.03), SIMDE_FLOAT32_C(  814.29), SIMDE_FLOAT32_C(  934.05)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -943.66), SIMDE_FLOAT32_C( -391.47),
                         SIMDE_FLOAT32_C( -426.68), SIMDE_FLOAT32_C(  276.94),
                         SIMDE_FLOAT32_C(  828.33), SIMDE_FLOAT32_C(  156.03),
                         SIMDE_FLOAT32_C(  814.29), SIMDE_FLOAT32_C(  934.05)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -450.81), SIMDE_FLOAT32_C(  408.09), SIMDE_FLOAT32_C( -107.21), SIMDE_FLOAT32_C( -222.72)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  943.76), SIMDE_FLOAT32_C(  562.90), SIMDE_FLOAT32_C(   87.25), SIMDE_FLOAT32_C(  650.08)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -450.81), SIMDE_FLOAT32_C(  408.09),
                         SIMDE_FLOAT32_C( -107.21), SIMDE_FLOAT32_C( -222.72),
                         SIMDE_FLOAT32_C(  943.76), SIMDE_FLOAT32_C(  562.90),
                         SIMDE_FLOAT32_C(   87.25), SIMDE_FLOAT32_C(  650.08)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  892.90), SIMDE_FLOAT32_C( -624.07), SIMDE_FLOAT32_C(   92.46), SIMDE_FLOAT32_C( -978.68)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  879.22), SIMDE_FLOAT32_C(  505.82), SIMDE_FLOAT32_C(  539.12), SIMDE_FLOAT32_C( -705.39)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  892.90), SIMDE_FLOAT32_C( -624.07),
                         SIMDE_FLOAT32_C(   92.46), SIMDE_FLOAT32_C( -978.68),
                         SIMDE_FLOAT32_C(  879.22), SIMDE_FLOAT32_C(  505.82),
                         SIMDE_FLOAT32_C(  539.12), SIMDE_FLOAT32_C( -705.39)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -452.17), SIMDE_FLOAT32_C( -870.72), SIMDE_FLOAT32_C(  804.70), SIMDE_FLOAT32_C(  579.66)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  129.37), SIMDE_FLOAT32_C(  -90.44), SIMDE_FLOAT32_C(  789.84), SIMDE_FLOAT32_C(  444.15)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -452.17), SIMDE_FLOAT32_C( -870.72),
                         SIMDE_FLOAT32_C(  804.70), SIMDE_FLOAT32_C(  579.66),
                         SIMDE_FLOAT32_C(  129.37), SIMDE_FLOAT32_C(  -90.44),
                         SIMDE_FLOAT32_C(  789.84), SIMDE_FLOAT32_C(  444.15)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  929.65), SIMDE_FLOAT32_C(  725.76), SIMDE_FLOAT32_C( -862.45), SIMDE_FLOAT32_C(   73.85)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  312.64), SIMDE_FLOAT32_C(  179.93), SIMDE_FLOAT32_C( -299.41), SIMDE_FLOAT32_C( -777.93)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  929.65), SIMDE_FLOAT32_C(  725.76),
                         SIMDE_FLOAT32_C( -862.45), SIMDE_FLOAT32_C(   73.85),
                         SIMDE_FLOAT32_C(  312.64), SIMDE_FLOAT32_C(  179.93),
                         SIMDE_FLOAT32_C( -299.41), SIMDE_FLOAT32_C( -777.93)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  749.93), SIMDE_FLOAT32_C( -503.03), SIMDE_FLOAT32_C(  312.75), SIMDE_FLOAT32_C(  785.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  925.76), SIMDE_FLOAT32_C(  616.12), SIMDE_FLOAT32_C(  230.43), SIMDE_FLOAT32_C(   -6.87)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  749.93), SIMDE_FLOAT32_C( -503.03),
                         SIMDE_FLOAT32_C(  312.75), SIMDE_FLOAT32_C(  785.60),
                         SIMDE_FLOAT32_C(  925.76), SIMDE_FLOAT32_C(  616.12),
                         SIMDE_FLOAT32_C(  230.43), SIMDE_FLOAT32_C(   -6.87)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  530.07), SIMDE_FLOAT32_C(  -65.75), SIMDE_FLOAT32_C(  995.75), SIMDE_FLOAT32_C( -849.91)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   81.96), SIMDE_FLOAT32_C(  -72.70), SIMDE_FLOAT32_C( -308.42), SIMDE_FLOAT32_C(  200.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  530.07), SIMDE_FLOAT32_C(  -65.75),
                         SIMDE_FLOAT32_C(  995.75), SIMDE_FLOAT32_C( -849.91),
                         SIMDE_FLOAT32_C(   81.96), SIMDE_FLOAT32_C(  -72.70),
                         SIMDE_FLOAT32_C( -308.42), SIMDE_FLOAT32_C(  200.36)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_loadu2_m128((float*) &(test_vec[i].a), (float*) &(test_vec[i].b));
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_loadu2_m128d(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  603.56), SIMDE_FLOAT64_C( -454.41)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -429.48), SIMDE_FLOAT64_C(  310.19)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  603.56), SIMDE_FLOAT64_C( -454.41),
                         SIMDE_FLOAT64_C( -429.48), SIMDE_FLOAT64_C(  310.19)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  864.32), SIMDE_FLOAT64_C( -366.07)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -121.89), SIMDE_FLOAT64_C( -768.23)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  864.32), SIMDE_FLOAT64_C( -366.07),
                         SIMDE_FLOAT64_C( -121.89), SIMDE_FLOAT64_C( -768.23)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  527.64), SIMDE_FLOAT64_C(   56.93)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -130.71), SIMDE_FLOAT64_C(  614.72)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  527.64), SIMDE_FLOAT64_C(   56.93),
                         SIMDE_FLOAT64_C( -130.71), SIMDE_FLOAT64_C(  614.72)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   14.74), SIMDE_FLOAT64_C(  175.43)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -235.98), SIMDE_FLOAT64_C( -177.19)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   14.74), SIMDE_FLOAT64_C(  175.43),
                         SIMDE_FLOAT64_C( -235.98), SIMDE_FLOAT64_C( -177.19)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  615.82), SIMDE_FLOAT64_C( -698.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   80.82), SIMDE_FLOAT64_C( -983.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  615.82), SIMDE_FLOAT64_C( -698.02),
                         SIMDE_FLOAT64_C(   80.82), SIMDE_FLOAT64_C( -983.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  971.33), SIMDE_FLOAT64_C( -439.16)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  488.24), SIMDE_FLOAT64_C(  538.39)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  971.33), SIMDE_FLOAT64_C( -439.16),
                         SIMDE_FLOAT64_C(  488.24), SIMDE_FLOAT64_C(  538.39)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -775.75), SIMDE_FLOAT64_C( -182.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  529.92), SIMDE_FLOAT64_C(  517.43)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -775.75), SIMDE_FLOAT64_C( -182.61),
                         SIMDE_FLOAT64_C(  529.92), SIMDE_FLOAT64_C(  517.43)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -130.29), SIMDE_FLOAT64_C(  550.66)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  248.09), SIMDE_FLOAT64_C(  821.35)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -130.29), SIMDE_FLOAT64_C(  550.66),
                         SIMDE_FLOAT64_C(  248.09), SIMDE_FLOAT64_C(  821.35)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_loadu2_m128d((double*) &(test_vec[i].a), (double*) &(test_vec[i].b));
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_loadu2_m128i(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  354008351), INT32_C( 1710178598), INT32_C( 1223789711), INT32_C(-1500329554)),
      simde_mm_set_epi32(INT32_C(-1388022686), INT32_C( -390861004), INT32_C( -560834160), INT32_C( 1618430517)),
      simde_mm256_set_epi32(INT32_C(  354008351), INT32_C( 1710178598), INT32_C( 1223789711), INT32_C(-1500329554),
                            INT32_C(-1388022686), INT32_C( -390861004), INT32_C( -560834160), INT32_C( 1618430517)) },
    { simde_mm_set_epi32(INT32_C(-2097010594), INT32_C(-1953861975), INT32_C( 1525655088), INT32_C(-1479248872)),
      simde_mm_set_epi32(INT32_C( -212387035), INT32_C( -783086135), INT32_C( -464607138), INT32_C( -807907186)),
      simde_mm256_set_epi32(INT32_C(-2097010594), INT32_C(-1953861975), INT32_C( 1525655088), INT32_C(-1479248872),
                            INT32_C( -212387035), INT32_C( -783086135), INT32_C( -464607138), INT32_C( -807907186)) },
    { simde_mm_set_epi32(INT32_C( 1556453306), INT32_C( -628648157), INT32_C(-1070645220), INT32_C( 1816365112)),
      simde_mm_set_epi32(INT32_C( -449670221), INT32_C(  758539132), INT32_C(  894912628), INT32_C( 2013246533)),
      simde_mm256_set_epi32(INT32_C( 1556453306), INT32_C( -628648157), INT32_C(-1070645220), INT32_C( 1816365112),
                            INT32_C( -449670221), INT32_C(  758539132), INT32_C(  894912628), INT32_C( 2013246533)) },
    { simde_mm_set_epi32(INT32_C(  973055118), INT32_C(  267011876), INT32_C( -970751985), INT32_C( -790620326)),
      simde_mm_set_epi32(INT32_C(-1774701032), INT32_C(  110651775), INT32_C(-2029162765), INT32_C( -644927818)),
      simde_mm256_set_epi32(INT32_C(  973055118), INT32_C(  267011876), INT32_C( -970751985), INT32_C( -790620326),
                            INT32_C(-1774701032), INT32_C(  110651775), INT32_C(-2029162765), INT32_C( -644927818)) },
    { simde_mm_set_epi32(INT32_C( 1343331807), INT32_C( -752743183), INT32_C( -212726727), INT32_C(  673547091)),
      simde_mm_set_epi32(INT32_C(  510472604), INT32_C(   30606375), INT32_C(-1460649586), INT32_C( -783315263)),
      simde_mm256_set_epi32(INT32_C( 1343331807), INT32_C( -752743183), INT32_C( -212726727), INT32_C(  673547091),
                            INT32_C(  510472604), INT32_C(   30606375), INT32_C(-1460649586), INT32_C( -783315263)) },
    { simde_mm_set_epi32(INT32_C( 1773008222), INT32_C( -172973908), INT32_C( -578745695), INT32_C( 1088863920)),
      simde_mm_set_epi32(INT32_C(-2064848056), INT32_C(  207858402), INT32_C(-1299831865), INT32_C(-1364624980)),
      simde_mm256_set_epi32(INT32_C( 1773008222), INT32_C( -172973908), INT32_C( -578745695), INT32_C( 1088863920),
                            INT32_C(-2064848056), INT32_C(  207858402), INT32_C(-1299831865), INT32_C(-1364624980)) },
    { simde_mm_set_epi32(INT32_C( -608977283), INT32_C(-1563798803), INT32_C(-1827655569), INT32_C( -382597224)),
      simde_mm_set_epi32(INT32_C(-1788804177), INT32_C(-1217503299), INT32_C(   57159833), INT32_C(  -53652220)),
      simde_mm256_set_epi32(INT32_C( -608977283), INT32_C(-1563798803), INT32_C(-1827655569), INT32_C( -382597224),
                            INT32_C(-1788804177), INT32_C(-1217503299), INT32_C(   57159833), INT32_C(  -53652220)) },
    { simde_mm_set_epi32(INT32_C( 2096190829), INT32_C(  255970451), INT32_C( 2016421031), INT32_C( -950647181)),
      simde_mm_set_epi32(INT32_C( -133085873), INT32_C(-1605552420), INT32_C( -147782601), INT32_C( -870212282)),
      simde_mm256_set_epi32(INT32_C( 2096190829), INT32_C(  255970451), INT32_C( 2016421031), INT32_C( -950647181),
                            INT32_C( -133085873), INT32_C(-1605552420), INT32_C( -147782601), INT32_C( -870212282)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_loadu2_m128i(&(test_vec[i].a), &(test_vec[i].b));
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_maskload_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128i mask;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -869.07), SIMDE_FLOAT64_C( -591.08)),
      simde_mm_set_epi64x(INT64_C(-4656940344630529687), INT64_C(4066151916241821774)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -869.07), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  562.04), SIMDE_FLOAT64_C(  685.29)),
      simde_mm_set_epi64x(INT64_C(-6569577205444773046), INT64_C(2918445148843299397)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  562.04), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  280.16), SIMDE_FLOAT64_C( -447.82)),
      simde_mm_set_epi64x(INT64_C(-9083772134411729116), INT64_C(-3507727887218884246)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  280.16), SIMDE_FLOAT64_C( -447.82)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  101.98), SIMDE_FLOAT64_C(  678.90)),
      simde_mm_set_epi64x(INT64_C(5053198455305737737), INT64_C(-366772722796788166)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  678.90)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  493.56), SIMDE_FLOAT64_C(  702.42)),
      simde_mm_set_epi64x(INT64_C(-8132835132130799425), INT64_C(6721857388801979943)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  493.56), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  450.87), SIMDE_FLOAT64_C( -305.21)),
      simde_mm_set_epi64x(INT64_C(-2966707152922402179), INT64_C(4918710390050837578)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  450.87), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -525.88), SIMDE_FLOAT64_C( -418.81)),
      simde_mm_set_epi64x(INT64_C(6936128414192720034), INT64_C(4382638642696047377)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  807.93), SIMDE_FLOAT64_C( -641.71)),
      simde_mm_set_epi64x(INT64_C(2989204552058115818), INT64_C(-6975420056835782983)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -641.71)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_maskload_pd((double*) &(test_vec[i].a), test_vec[i].mask);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_maskload_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256i mask;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  998.58), SIMDE_FLOAT64_C(  453.40),
                         SIMDE_FLOAT64_C( -974.33), SIMDE_FLOAT64_C( -886.23)),
      simde_mm256_set_epi64x(INT64_C( 8805653739036980375), INT64_C( 2399376934534417157),
                             INT64_C( 6546187137622507168), INT64_C(-2273018221893387885)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -886.23)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -681.17), SIMDE_FLOAT64_C( -528.17),
                         SIMDE_FLOAT64_C(  895.50), SIMDE_FLOAT64_C(  223.12)),
      simde_mm256_set_epi64x(INT64_C( 7293008844963971585), INT64_C(-1136370201413106824),
                             INT64_C(-7528522330218381930), INT64_C(-1969469625465759468)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -528.17),
                         SIMDE_FLOAT64_C(  895.50), SIMDE_FLOAT64_C(  223.12)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -844.30), SIMDE_FLOAT64_C(  451.22),
                         SIMDE_FLOAT64_C(  106.37), SIMDE_FLOAT64_C(  455.17)),
      simde_mm256_set_epi64x(INT64_C(-7353806629340057995), INT64_C( 4939270147261873906),
                             INT64_C(-5499323801240251091), INT64_C(-7544547969100393732)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -844.30), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  106.37), SIMDE_FLOAT64_C(  455.17)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -702.27), SIMDE_FLOAT64_C(  958.34),
                         SIMDE_FLOAT64_C(  124.46), SIMDE_FLOAT64_C( -924.11)),
      simde_mm256_set_epi64x(INT64_C(  226955271346515562), INT64_C( 4879635330183243750),
                             INT64_C(-1728742208821169865), INT64_C(-3657794116646034749)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  124.46), SIMDE_FLOAT64_C( -924.11)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  850.84), SIMDE_FLOAT64_C(  756.59),
                         SIMDE_FLOAT64_C( -309.25), SIMDE_FLOAT64_C( -592.72)),
      simde_mm256_set_epi64x(INT64_C(-1823342756301920709), INT64_C( 1560661890365696098),
                             INT64_C( 5546635832651410568), INT64_C(-8781765740568726309)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  850.84), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -592.72)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -606.83), SIMDE_FLOAT64_C(  336.84),
                         SIMDE_FLOAT64_C( -947.37), SIMDE_FLOAT64_C(  772.54)),
      simde_mm256_set_epi64x(INT64_C( 3797309541153329542), INT64_C( 7374629747919594897),
                             INT64_C(  -37141041474566228), INT64_C(-2657461092240792671)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -947.37), SIMDE_FLOAT64_C(  772.54)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  436.36), SIMDE_FLOAT64_C( -215.95),
                         SIMDE_FLOAT64_C( -560.04), SIMDE_FLOAT64_C( -193.30)),
      simde_mm256_set_epi64x(INT64_C( 3286601641881841808), INT64_C(-2411223573337484362),
                             INT64_C(-3230833694297996662), INT64_C( 2091629286858077757)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -215.95),
                         SIMDE_FLOAT64_C( -560.04), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  846.27), SIMDE_FLOAT64_C( -364.82),
                         SIMDE_FLOAT64_C( -530.42), SIMDE_FLOAT64_C(  419.62)),
      simde_mm256_set_epi64x(INT64_C(-2256278840318443538), INT64_C( 6499299535430665585),
                             INT64_C( 1607500318271218280), INT64_C( 6715379162779325050)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  846.27), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_maskload_pd((double*) &(test_vec[i].a), test_vec[i].mask);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_maskload_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128i mask;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  311.80), SIMDE_FLOAT32_C( -618.01), SIMDE_FLOAT32_C(   -5.14), SIMDE_FLOAT32_C(   34.63)),
      simde_mm_set_epi32(INT32_C(  674479798), INT32_C( 1961776311), INT32_C(  -52523803), INT32_C(   90431183)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(   -5.14), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  887.99), SIMDE_FLOAT32_C( -359.94), SIMDE_FLOAT32_C( -725.95), SIMDE_FLOAT32_C( -443.04)),
      simde_mm_set_epi32(INT32_C(  555433715), INT32_C( 1278719026), INT32_C(-2146918925), INT32_C( -230564549)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C( -725.95), SIMDE_FLOAT32_C( -443.04)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -267.72), SIMDE_FLOAT32_C( -162.10), SIMDE_FLOAT32_C( -798.12), SIMDE_FLOAT32_C(  112.08)),
      simde_mm_set_epi32(INT32_C( -820767063), INT32_C(-1140827870), INT32_C(  188332002), INT32_C(-1100794796)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -267.72), SIMDE_FLOAT32_C( -162.10), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  112.08)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  317.62), SIMDE_FLOAT32_C( -762.45), SIMDE_FLOAT32_C( -539.98), SIMDE_FLOAT32_C(  132.08)),
      simde_mm_set_epi32(INT32_C(-1748342522), INT32_C( 1008342819), INT32_C(-1926222705), INT32_C(-1475654940)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  317.62), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C( -539.98), SIMDE_FLOAT32_C(  132.08)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -191.85), SIMDE_FLOAT32_C(  390.49), SIMDE_FLOAT32_C( -412.66), SIMDE_FLOAT32_C(  493.52)),
      simde_mm_set_epi32(INT32_C(  869247873), INT32_C(  532225925), INT32_C(   67644453), INT32_C( -754286454)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  493.52)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  255.66), SIMDE_FLOAT32_C(  956.17), SIMDE_FLOAT32_C(  414.83), SIMDE_FLOAT32_C( -190.55)),
      simde_mm_set_epi32(INT32_C(  343260864), INT32_C( 1002494048), INT32_C( 1434736226), INT32_C(  622702548)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -110.33), SIMDE_FLOAT32_C(  923.24), SIMDE_FLOAT32_C( -872.61), SIMDE_FLOAT32_C( -822.02)),
      simde_mm_set_epi32(INT32_C( 1293196809), INT32_C(  -50598112), INT32_C(  674674628), INT32_C( -921350619)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  923.24), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C( -822.02)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  717.10), SIMDE_FLOAT32_C( -183.60), SIMDE_FLOAT32_C( -950.19), SIMDE_FLOAT32_C(  -83.28)),
      simde_mm_set_epi32(INT32_C(-1512952272), INT32_C( 1209799869), INT32_C(  847871438), INT32_C(-1330307361)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  717.10), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  -83.28)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_maskload_ps((float*) &(test_vec[i].a), test_vec[i].mask);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_maskload_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256i mask;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -752.91), SIMDE_FLOAT32_C(  779.11),
                         SIMDE_FLOAT32_C( -999.71), SIMDE_FLOAT32_C(  573.29),
                         SIMDE_FLOAT32_C( -705.63), SIMDE_FLOAT32_C( -423.09),
                         SIMDE_FLOAT32_C(  377.10), SIMDE_FLOAT32_C( -796.23)),
      simde_mm256_set_epi32(INT32_C( 1925552740), INT32_C( -536836283), INT32_C( -650710589), INT32_C(  985555010),
                            INT32_C( -836749119), INT32_C( -853340630), INT32_C( -297951364), INT32_C( -383112932)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  779.11),
                         SIMDE_FLOAT32_C( -999.71), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -705.63), SIMDE_FLOAT32_C( -423.09),
                         SIMDE_FLOAT32_C(  377.10), SIMDE_FLOAT32_C( -796.23)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  127.90), SIMDE_FLOAT32_C(  118.00),
                         SIMDE_FLOAT32_C( -746.01), SIMDE_FLOAT32_C(  957.25),
                         SIMDE_FLOAT32_C(  537.70), SIMDE_FLOAT32_C( -644.71),
                         SIMDE_FLOAT32_C( -499.66), SIMDE_FLOAT32_C( -153.26)),
      simde_mm256_set_epi32(INT32_C(-1786317259), INT32_C(  115208988), INT32_C( -962058757), INT32_C( -463424553),
                            INT32_C( 1429007767), INT32_C(  177684894), INT32_C( -888643816), INT32_C(-1479129179)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  127.90), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -746.01), SIMDE_FLOAT32_C(  957.25),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -499.66), SIMDE_FLOAT32_C( -153.26)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  467.02), SIMDE_FLOAT32_C(  495.73),
                         SIMDE_FLOAT32_C( -615.79), SIMDE_FLOAT32_C(   39.27),
                         SIMDE_FLOAT32_C( -182.60), SIMDE_FLOAT32_C( -293.50),
                         SIMDE_FLOAT32_C(  895.64), SIMDE_FLOAT32_C(  846.67)),
      simde_mm256_set_epi32(INT32_C( 1083150060), INT32_C( 1373222022), INT32_C( -376879014), INT32_C(-1832162307),
                            INT32_C( 1450882878), INT32_C(   38335444), INT32_C(  -87516796), INT32_C(   93420291)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -615.79), SIMDE_FLOAT32_C(   39.27),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(  895.64), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -938.30), SIMDE_FLOAT32_C( -246.18),
                         SIMDE_FLOAT32_C( -164.44), SIMDE_FLOAT32_C( -416.87),
                         SIMDE_FLOAT32_C( -257.57), SIMDE_FLOAT32_C(  877.34),
                         SIMDE_FLOAT32_C( -648.88), SIMDE_FLOAT32_C( -874.11)),
      simde_mm256_set_epi32(INT32_C(  920172214), INT32_C(  943699584), INT32_C(-2010506890), INT32_C( 2130526840),
                            INT32_C(-2000446411), INT32_C( 1303998621), INT32_C(  382477477), INT32_C( 1890164515)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -164.44), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -257.57), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  388.19), SIMDE_FLOAT32_C( -629.96),
                         SIMDE_FLOAT32_C(  -29.11), SIMDE_FLOAT32_C(   81.90),
                         SIMDE_FLOAT32_C(   37.28), SIMDE_FLOAT32_C(  454.65),
                         SIMDE_FLOAT32_C(  953.85), SIMDE_FLOAT32_C(  835.35)),
      simde_mm256_set_epi32(INT32_C( 1515921474), INT32_C(   14029640), INT32_C( -663410697), INT32_C(  984882279),
                            INT32_C( 1984839672), INT32_C( -817621191), INT32_C(   10575660), INT32_C(   48702656)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(  -29.11), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  454.65),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  731.59), SIMDE_FLOAT32_C(  652.19),
                         SIMDE_FLOAT32_C( -336.04), SIMDE_FLOAT32_C(  557.80),
                         SIMDE_FLOAT32_C(  245.00), SIMDE_FLOAT32_C( -907.76),
                         SIMDE_FLOAT32_C( -793.65), SIMDE_FLOAT32_C( -448.27)),
      simde_mm256_set_epi32(INT32_C(  651567854), INT32_C( 1910174842), INT32_C(-1045560123), INT32_C(-1582689813),
                            INT32_C( 2033355854), INT32_C( -589914606), INT32_C( 2046255959), INT32_C(  228315114)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -336.04), SIMDE_FLOAT32_C(  557.80),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C( -907.76),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  168.44), SIMDE_FLOAT32_C(  486.54),
                         SIMDE_FLOAT32_C(  970.34), SIMDE_FLOAT32_C(  832.27),
                         SIMDE_FLOAT32_C(  125.30), SIMDE_FLOAT32_C(  800.47),
                         SIMDE_FLOAT32_C(  145.42), SIMDE_FLOAT32_C(  342.54)),
      simde_mm256_set_epi32(INT32_C(-1958884333), INT32_C( 1832273155), INT32_C(  850368156), INT32_C(-1960191348),
                            INT32_C( -337636084), INT32_C(-1352546968), INT32_C(-1280973450), INT32_C(  291086356)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  168.44), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(  832.27),
                         SIMDE_FLOAT32_C(  125.30), SIMDE_FLOAT32_C(  800.47),
                         SIMDE_FLOAT32_C(  145.42), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -841.40), SIMDE_FLOAT32_C( -400.22),
                         SIMDE_FLOAT32_C(  837.14), SIMDE_FLOAT32_C(  453.62),
                         SIMDE_FLOAT32_C( -357.05), SIMDE_FLOAT32_C(  400.49),
                         SIMDE_FLOAT32_C(  230.39), SIMDE_FLOAT32_C( -694.30)),
      simde_mm256_set_epi32(INT32_C( -810841400), INT32_C( -471092299), INT32_C(  741877078), INT32_C( 1728996194),
                            INT32_C( -390585903), INT32_C( -423751754), INT32_C(-1649889111), INT32_C(  530215398)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -841.40), SIMDE_FLOAT32_C( -400.22),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -357.05), SIMDE_FLOAT32_C(  400.49),
                         SIMDE_FLOAT32_C(  230.39), SIMDE_FLOAT32_C(    0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_maskload_ps((float*) &(test_vec[i].a), test_vec[i].mask);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_maskstore_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128i mask;
    double ri[2];
    double ro[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  291.40), SIMDE_FLOAT64_C( -747.46)),
      simde_mm_set_epi64x(INT64_C( -901196363302656956), INT64_C(  423467829629286510)),
      { SIMDE_FLOAT64_C( -279.11), SIMDE_FLOAT64_C( -707.31) },
      { SIMDE_FLOAT64_C( -279.11), SIMDE_FLOAT64_C(  291.40) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   36.11), SIMDE_FLOAT64_C( -279.03)),
      simde_mm_set_epi64x(INT64_C(-5374148835716618800), INT64_C( 4687824648494664977)),
      { SIMDE_FLOAT64_C( -513.32), SIMDE_FLOAT64_C(  997.01) },
      { SIMDE_FLOAT64_C( -513.32), SIMDE_FLOAT64_C(   36.11) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  252.18), SIMDE_FLOAT64_C( -396.70)),
      simde_mm_set_epi64x(INT64_C(-2340838553401196290), INT64_C(-8255671198755410933)),
      { SIMDE_FLOAT64_C( -313.87), SIMDE_FLOAT64_C(  648.77) },
      { SIMDE_FLOAT64_C( -396.70), SIMDE_FLOAT64_C(  252.18) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -154.32), SIMDE_FLOAT64_C(  707.71)),
      simde_mm_set_epi64x(INT64_C( -336577207510206055), INT64_C(-8731515008786621717)),
      { SIMDE_FLOAT64_C( -956.34), SIMDE_FLOAT64_C(  661.79) },
      { SIMDE_FLOAT64_C(  707.71), SIMDE_FLOAT64_C( -154.32) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -482.35), SIMDE_FLOAT64_C(  870.14)),
      simde_mm_set_epi64x(INT64_C(-6428326320006280400), INT64_C( 2370968363897859860)),
      { SIMDE_FLOAT64_C(  -88.00), SIMDE_FLOAT64_C( -393.63) },
      { SIMDE_FLOAT64_C(  -88.00), SIMDE_FLOAT64_C( -482.35) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -798.76), SIMDE_FLOAT64_C(  378.53)),
      simde_mm_set_epi64x(INT64_C( 2158346412704669322), INT64_C(-1741710562990070947)),
      { SIMDE_FLOAT64_C( -459.19), SIMDE_FLOAT64_C( -261.60) },
      { SIMDE_FLOAT64_C(  378.53), SIMDE_FLOAT64_C( -261.60) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   47.39), SIMDE_FLOAT64_C(  457.82)),
      simde_mm_set_epi64x(INT64_C( 3118706775454689373), INT64_C(-4723277293636004112)),
      { SIMDE_FLOAT64_C( -206.48), SIMDE_FLOAT64_C(  663.61) },
      { SIMDE_FLOAT64_C(  457.82), SIMDE_FLOAT64_C(  663.61) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -497.78), SIMDE_FLOAT64_C(  -27.40)),
      simde_mm_set_epi64x(INT64_C(-5481981628135809029), INT64_C(-7037919562781567894)),
      { SIMDE_FLOAT64_C(   54.28), SIMDE_FLOAT64_C(  -36.05) },
      { SIMDE_FLOAT64_C(  -27.40), SIMDE_FLOAT64_C( -497.78) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    double r[2] = { test_vec[i].ri[0], test_vec[i].ri[1], };
    memcpy(r, test_vec[i].ri, sizeof(r));
    simde_mm_maskstore_pd(r, test_vec[i].mask, test_vec[i].a);
    simde_assert_m128d_f64_equal(*((simde__m128d*) r), *((simde__m128d*) test_vec[i].ro), 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_maskstore_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256i mask;
    simde_float64 ri[4];
    simde_float64 ro[4];
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  256.10), SIMDE_FLOAT64_C(  343.75),
                         SIMDE_FLOAT64_C( -441.90), SIMDE_FLOAT64_C(  609.80)),
      simde_mm256_set_epi64x(INT64_C( 4260458650207424972), INT64_C( 7445494124920454187),
                             INT64_C( 3286955945790099662), INT64_C(-7285974739268381254)),
      { SIMDE_FLOAT64_C( -289.65), SIMDE_FLOAT64_C(  426.76),
        SIMDE_FLOAT64_C(   -9.11), SIMDE_FLOAT64_C( -274.93) },
      { SIMDE_FLOAT64_C(  609.80), SIMDE_FLOAT64_C(  426.76),
        SIMDE_FLOAT64_C(   -9.11), SIMDE_FLOAT64_C( -274.93) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  571.67), SIMDE_FLOAT64_C(  518.20),
                         SIMDE_FLOAT64_C(  -98.22), SIMDE_FLOAT64_C( -751.94)),
      simde_mm256_set_epi64x(INT64_C( 1638253588391173148), INT64_C( 1793291230565330203),
                             INT64_C(-9111784699029565866), INT64_C( -227326109536357972)),
      { SIMDE_FLOAT64_C( -486.54), SIMDE_FLOAT64_C(  729.14),
        SIMDE_FLOAT64_C( -705.07), SIMDE_FLOAT64_C( -433.33) },
      { SIMDE_FLOAT64_C( -751.94), SIMDE_FLOAT64_C(  -98.22),
        SIMDE_FLOAT64_C( -705.07), SIMDE_FLOAT64_C( -433.33) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  102.13), SIMDE_FLOAT64_C( -818.78),
                         SIMDE_FLOAT64_C( -736.90), SIMDE_FLOAT64_C( -616.20)),
      simde_mm256_set_epi64x(INT64_C(-2892759574131760065), INT64_C(-3440936018861750870),
                             INT64_C( -525494054977382250), INT64_C(-2782562282709585632)),
      { SIMDE_FLOAT64_C( -465.13), SIMDE_FLOAT64_C(  232.40),
        SIMDE_FLOAT64_C( -478.53), SIMDE_FLOAT64_C(  -53.86) },
      { SIMDE_FLOAT64_C( -616.20), SIMDE_FLOAT64_C( -736.90),
        SIMDE_FLOAT64_C( -818.78), SIMDE_FLOAT64_C(  102.13) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  748.35), SIMDE_FLOAT64_C(  412.39),
                         SIMDE_FLOAT64_C(  180.73), SIMDE_FLOAT64_C( -772.53)),
      simde_mm256_set_epi64x(INT64_C(-7252528024816875961), INT64_C( 3768666429054031776),
                             INT64_C(-5502653220660844988), INT64_C( 6869378166726947276)),
      { SIMDE_FLOAT64_C( -276.66), SIMDE_FLOAT64_C( -248.39),
        SIMDE_FLOAT64_C( -589.21), SIMDE_FLOAT64_C(  826.33) },
      { SIMDE_FLOAT64_C( -276.66), SIMDE_FLOAT64_C(  180.73),
        SIMDE_FLOAT64_C( -589.21), SIMDE_FLOAT64_C(  748.35) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  837.77), SIMDE_FLOAT64_C(  582.83),
                         SIMDE_FLOAT64_C(  901.95), SIMDE_FLOAT64_C(  440.28)),
      simde_mm256_set_epi64x(INT64_C( 7132263712774217761), INT64_C( 7513359651930322343),
                             INT64_C( 7271276353319921669), INT64_C(-6353645951073475265)),
      { SIMDE_FLOAT64_C(  194.29), SIMDE_FLOAT64_C( -702.43),
        SIMDE_FLOAT64_C(  663.08), SIMDE_FLOAT64_C( -837.37) },
      { SIMDE_FLOAT64_C(  440.28), SIMDE_FLOAT64_C( -702.43),
        SIMDE_FLOAT64_C(  663.08), SIMDE_FLOAT64_C( -837.37) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -476.01), SIMDE_FLOAT64_C(  964.03),
                         SIMDE_FLOAT64_C( -620.01), SIMDE_FLOAT64_C( -190.51)),
      simde_mm256_set_epi64x(INT64_C(-6904573933630117437), INT64_C( 8435505992452950995),
                             INT64_C(-2030909113789010322), INT64_C(-3516031824252737762)),
      { SIMDE_FLOAT64_C(  412.73), SIMDE_FLOAT64_C( -375.82),
        SIMDE_FLOAT64_C(  493.97), SIMDE_FLOAT64_C( -325.91) },
      { SIMDE_FLOAT64_C( -190.51), SIMDE_FLOAT64_C( -620.01),
        SIMDE_FLOAT64_C(  493.97), SIMDE_FLOAT64_C( -476.01) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  109.41), SIMDE_FLOAT64_C( -105.03),
                         SIMDE_FLOAT64_C(  942.38), SIMDE_FLOAT64_C(  492.62)),
      simde_mm256_set_epi64x(INT64_C(-4507038716603653937), INT64_C(-5597740526711762453),
                             INT64_C(-4892847490676269188), INT64_C(-2050275303632712946)),
      { SIMDE_FLOAT64_C(  999.52), SIMDE_FLOAT64_C(   91.29),
        SIMDE_FLOAT64_C( -389.17), SIMDE_FLOAT64_C( -828.90) },
      { SIMDE_FLOAT64_C(  492.62), SIMDE_FLOAT64_C(  942.38),
        SIMDE_FLOAT64_C( -105.03), SIMDE_FLOAT64_C(  109.41) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -984.18), SIMDE_FLOAT64_C(  526.23),
                         SIMDE_FLOAT64_C(  210.69), SIMDE_FLOAT64_C( -960.42)),
      simde_mm256_set_epi64x(INT64_C(-2327918596051776606), INT64_C(-6284034566091225578),
                             INT64_C( 5326594562181579270), INT64_C( 7458656096830697285)),
      { SIMDE_FLOAT64_C(  719.28), SIMDE_FLOAT64_C( -272.00),
        SIMDE_FLOAT64_C( -305.09), SIMDE_FLOAT64_C(  995.54) },
      { SIMDE_FLOAT64_C(  719.28), SIMDE_FLOAT64_C( -272.00),
        SIMDE_FLOAT64_C(  526.23), SIMDE_FLOAT64_C( -984.18) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64 r[4];
    memcpy(r, test_vec[i].ri, sizeof(r));
    simde_mm256_maskstore_pd(r, test_vec[i].mask, test_vec[i].a);
    simde_assert_m256d_f64_equal(r, test_vec[i].ro, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_maskstore_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128i mask;
    simde_float32 ri[4];
    simde_float32 ro[4];
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  674.56), SIMDE_FLOAT32_C( -800.90), SIMDE_FLOAT32_C( -515.11), SIMDE_FLOAT32_C(  918.12)),
      simde_mm_set_epi32(INT32_C( 1108579007), INT32_C( 1980053353), INT32_C( 1803323457), INT32_C( -407836103)),
      { SIMDE_FLOAT32_C( -619.39), SIMDE_FLOAT32_C( -235.61), SIMDE_FLOAT32_C( -100.19), SIMDE_FLOAT32_C(  132.85) },
      { SIMDE_FLOAT32_C(  918.12), SIMDE_FLOAT32_C( -235.61), SIMDE_FLOAT32_C( -100.19), SIMDE_FLOAT32_C(  132.85) } },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -921.95), SIMDE_FLOAT32_C( -150.48), SIMDE_FLOAT32_C(  -68.61), SIMDE_FLOAT32_C(  516.22)),
      simde_mm_set_epi32(INT32_C(  992186029), INT32_C( 1116343160), INT32_C(  312629428), INT32_C( -102955009)),
      { SIMDE_FLOAT32_C(  590.22), SIMDE_FLOAT32_C(   90.53), SIMDE_FLOAT32_C(  -38.56), SIMDE_FLOAT32_C(  730.28) },
      { SIMDE_FLOAT32_C(  516.22), SIMDE_FLOAT32_C(   90.53), SIMDE_FLOAT32_C(  -38.56), SIMDE_FLOAT32_C(  730.28) } },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -641.93), SIMDE_FLOAT32_C(  207.52), SIMDE_FLOAT32_C( -794.64), SIMDE_FLOAT32_C(  604.13)),
      simde_mm_set_epi32(INT32_C( -917957115), INT32_C( 1866845223), INT32_C(  844085971), INT32_C( -482023893)),
      { SIMDE_FLOAT32_C( -925.57), SIMDE_FLOAT32_C(    8.11), SIMDE_FLOAT32_C( -375.92), SIMDE_FLOAT32_C( -370.15) },
      { SIMDE_FLOAT32_C(  604.13), SIMDE_FLOAT32_C(    8.11), SIMDE_FLOAT32_C( -375.92), SIMDE_FLOAT32_C( -641.93) } },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  805.10), SIMDE_FLOAT32_C( -153.46), SIMDE_FLOAT32_C(  308.00), SIMDE_FLOAT32_C( -159.40)),
      simde_mm_set_epi32(INT32_C( -582979650), INT32_C( 2118735836), INT32_C( -687047741), INT32_C( -848367450)),
      { SIMDE_FLOAT32_C(  678.23), SIMDE_FLOAT32_C(  517.86), SIMDE_FLOAT32_C(  930.59), SIMDE_FLOAT32_C( -376.44) },
      { SIMDE_FLOAT32_C( -159.40), SIMDE_FLOAT32_C(  308.00), SIMDE_FLOAT32_C(  930.59), SIMDE_FLOAT32_C(  805.10) } },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  286.93), SIMDE_FLOAT32_C( -263.99), SIMDE_FLOAT32_C( -966.59), SIMDE_FLOAT32_C( -652.85)),
      simde_mm_set_epi32(INT32_C( -773117066), INT32_C(-1995762340), INT32_C(-1086112436), INT32_C(  352565673)),
      { SIMDE_FLOAT32_C( -243.02), SIMDE_FLOAT32_C(  -10.35), SIMDE_FLOAT32_C( -930.64), SIMDE_FLOAT32_C( -942.71) },
      { SIMDE_FLOAT32_C( -243.02), SIMDE_FLOAT32_C( -966.59), SIMDE_FLOAT32_C( -263.99), SIMDE_FLOAT32_C(  286.93) } },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  695.71), SIMDE_FLOAT32_C(  544.01), SIMDE_FLOAT32_C( -155.11), SIMDE_FLOAT32_C(  773.52)),
      simde_mm_set_epi32(INT32_C( 2130523937), INT32_C(  959365319), INT32_C(  -87305215), INT32_C(  336137071)),
      { SIMDE_FLOAT32_C(  331.75), SIMDE_FLOAT32_C(  641.50), SIMDE_FLOAT32_C( -114.90), SIMDE_FLOAT32_C(  582.07) },
      { SIMDE_FLOAT32_C(  331.75), SIMDE_FLOAT32_C( -155.11), SIMDE_FLOAT32_C( -114.90), SIMDE_FLOAT32_C(  582.07) } },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -51.27), SIMDE_FLOAT32_C(  493.10), SIMDE_FLOAT32_C( -182.48), SIMDE_FLOAT32_C( -902.32)),
      simde_mm_set_epi32(INT32_C( -776181519), INT32_C(-1636897440), INT32_C( -492655883), INT32_C(-1758902344)),
      { SIMDE_FLOAT32_C(  -81.09), SIMDE_FLOAT32_C( -980.86), SIMDE_FLOAT32_C( -619.01), SIMDE_FLOAT32_C( -490.33) },
      { SIMDE_FLOAT32_C( -902.32), SIMDE_FLOAT32_C( -182.48), SIMDE_FLOAT32_C(  493.10), SIMDE_FLOAT32_C(  -51.27) } },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  432.35), SIMDE_FLOAT32_C(  341.26), SIMDE_FLOAT32_C(  183.18), SIMDE_FLOAT32_C( -136.49)),
      simde_mm_set_epi32(INT32_C( 1637126517), INT32_C(-1887081950), INT32_C( 1956680612), INT32_C( 1224753500)),
      { SIMDE_FLOAT32_C( -471.44), SIMDE_FLOAT32_C(  241.66), SIMDE_FLOAT32_C(  -19.61), SIMDE_FLOAT32_C( -311.97) },
      { SIMDE_FLOAT32_C( -471.44), SIMDE_FLOAT32_C(  241.66), SIMDE_FLOAT32_C(  341.26), SIMDE_FLOAT32_C( -311.97) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32 r[4];
    memcpy(r, test_vec[i].ri, sizeof(r));
    simde_mm_maskstore_ps(r, test_vec[i].mask, test_vec[i].a);
    simde_assert_m128_f32_equal(r, test_vec[i].ro, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_maskstore_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256i mask;
    simde_float32 ri[8];
    simde_float32 ro[8];
  } test_vec[8] = {
   { simde_mm256_set_ps(SIMDE_FLOAT32_C( -840.97), SIMDE_FLOAT32_C( -667.62),
                         SIMDE_FLOAT32_C(   62.32), SIMDE_FLOAT32_C(   77.23),
                         SIMDE_FLOAT32_C(  612.86), SIMDE_FLOAT32_C(  912.45),
                         SIMDE_FLOAT32_C(  778.71), SIMDE_FLOAT32_C( -109.21)),
      simde_mm256_set_epi64x(INT64_C( 9072214393288156198), INT64_C(-8060084542862295221),
                             INT64_C( -555395488243285532), INT64_C( 5158767021173771711)),
      { SIMDE_FLOAT32_C( -737.39), SIMDE_FLOAT32_C(  519.36),
        SIMDE_FLOAT32_C(  707.42), SIMDE_FLOAT32_C( -825.90),
        SIMDE_FLOAT32_C( -158.04), SIMDE_FLOAT32_C( -179.54),
        SIMDE_FLOAT32_C(  553.92), SIMDE_FLOAT32_C(  949.34) },
      { SIMDE_FLOAT32_C( -737.39), SIMDE_FLOAT32_C(  519.36),
        SIMDE_FLOAT32_C(  912.45), SIMDE_FLOAT32_C(  612.86),
        SIMDE_FLOAT32_C(   77.23), SIMDE_FLOAT32_C(   62.32),
        SIMDE_FLOAT32_C( -667.62), SIMDE_FLOAT32_C(  949.34) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   87.95), SIMDE_FLOAT32_C(  657.90),
                         SIMDE_FLOAT32_C(  181.08), SIMDE_FLOAT32_C( -841.79),
                         SIMDE_FLOAT32_C( -859.56), SIMDE_FLOAT32_C( -285.12),
                         SIMDE_FLOAT32_C(  579.30), SIMDE_FLOAT32_C(  987.72)),
      simde_mm256_set_epi64x(INT64_C( 8746381795822312225), INT64_C( 3232898507485144417),
                             INT64_C(-4231873738582571613), INT64_C( 3657438512222861200)),
      { SIMDE_FLOAT32_C(  335.65), SIMDE_FLOAT32_C( -396.02),
        SIMDE_FLOAT32_C( -819.96), SIMDE_FLOAT32_C(  455.49),
        SIMDE_FLOAT32_C(  836.78), SIMDE_FLOAT32_C(  -21.77),
        SIMDE_FLOAT32_C( -671.22), SIMDE_FLOAT32_C(  138.98) },
      { SIMDE_FLOAT32_C(  987.72), SIMDE_FLOAT32_C( -396.02),
        SIMDE_FLOAT32_C( -285.12), SIMDE_FLOAT32_C( -859.56),
        SIMDE_FLOAT32_C(  836.78), SIMDE_FLOAT32_C(  -21.77),
        SIMDE_FLOAT32_C( -671.22), SIMDE_FLOAT32_C(  138.98) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -403.21), SIMDE_FLOAT32_C(  521.70),
                         SIMDE_FLOAT32_C(  216.79), SIMDE_FLOAT32_C( -659.54),
                         SIMDE_FLOAT32_C( -900.47), SIMDE_FLOAT32_C(  448.90),
                         SIMDE_FLOAT32_C(  576.62), SIMDE_FLOAT32_C( -932.82)),
      simde_mm256_set_epi64x(INT64_C(-1891132600922232034), INT64_C( 2277661503294388734),
                             INT64_C(-3895958037598173639), INT64_C( 8886413299048876820)),
      { SIMDE_FLOAT32_C( -530.25), SIMDE_FLOAT32_C( -239.58),
        SIMDE_FLOAT32_C( -160.16), SIMDE_FLOAT32_C(  785.77),
        SIMDE_FLOAT32_C(   95.94), SIMDE_FLOAT32_C( -653.02),
        SIMDE_FLOAT32_C(  539.98), SIMDE_FLOAT32_C(  289.02) },
      { SIMDE_FLOAT32_C( -530.25), SIMDE_FLOAT32_C( -239.58),
        SIMDE_FLOAT32_C( -160.16), SIMDE_FLOAT32_C( -900.47),
        SIMDE_FLOAT32_C( -659.54), SIMDE_FLOAT32_C( -653.02),
        SIMDE_FLOAT32_C(  539.98), SIMDE_FLOAT32_C( -403.21) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  524.42), SIMDE_FLOAT32_C( -505.92),
                         SIMDE_FLOAT32_C( -482.89), SIMDE_FLOAT32_C(  224.53),
                         SIMDE_FLOAT32_C( -140.37), SIMDE_FLOAT32_C(  813.97),
                         SIMDE_FLOAT32_C(  408.03), SIMDE_FLOAT32_C(  311.73)),
      simde_mm256_set_epi64x(INT64_C( 4216721159168672116), INT64_C( 5790291547478630298),
                             INT64_C( 4301453374901740391), INT64_C( 8386771969285475915)),
      { SIMDE_FLOAT32_C(  913.79), SIMDE_FLOAT32_C(  302.79),
        SIMDE_FLOAT32_C( -895.26), SIMDE_FLOAT32_C(  987.08),
        SIMDE_FLOAT32_C(  868.65), SIMDE_FLOAT32_C( -707.44),
        SIMDE_FLOAT32_C( -212.82), SIMDE_FLOAT32_C( -968.51) },
      { SIMDE_FLOAT32_C(  311.73), SIMDE_FLOAT32_C(  302.79),
        SIMDE_FLOAT32_C(  813.97), SIMDE_FLOAT32_C(  987.08),
        SIMDE_FLOAT32_C(  224.53), SIMDE_FLOAT32_C( -707.44),
        SIMDE_FLOAT32_C( -505.92), SIMDE_FLOAT32_C( -968.51) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  299.75), SIMDE_FLOAT32_C(  709.21),
                         SIMDE_FLOAT32_C( -727.53), SIMDE_FLOAT32_C( -155.39),
                         SIMDE_FLOAT32_C(  364.27), SIMDE_FLOAT32_C( -736.45),
                         SIMDE_FLOAT32_C(  715.75), SIMDE_FLOAT32_C(  791.90)),
      simde_mm256_set_epi64x(INT64_C( 1606305372695184450), INT64_C( 4622551524021465392),
                             INT64_C(-8780896172102094055), INT64_C( 2174190935919163940)),
      { SIMDE_FLOAT32_C( -322.87), SIMDE_FLOAT32_C(  632.94),
        SIMDE_FLOAT32_C( -936.19), SIMDE_FLOAT32_C(  589.23),
        SIMDE_FLOAT32_C(  512.31), SIMDE_FLOAT32_C(  540.57),
        SIMDE_FLOAT32_C( -515.65), SIMDE_FLOAT32_C(   -5.92) },
      { SIMDE_FLOAT32_C( -322.87), SIMDE_FLOAT32_C(  632.94),
        SIMDE_FLOAT32_C( -936.19), SIMDE_FLOAT32_C(  364.27),
        SIMDE_FLOAT32_C( -155.39), SIMDE_FLOAT32_C(  540.57),
        SIMDE_FLOAT32_C(  709.21), SIMDE_FLOAT32_C(   -5.92) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  723.54), SIMDE_FLOAT32_C( -457.53),
                         SIMDE_FLOAT32_C(   -1.65), SIMDE_FLOAT32_C( -674.86),
                         SIMDE_FLOAT32_C( -812.21), SIMDE_FLOAT32_C(  378.16),
                         SIMDE_FLOAT32_C(  -82.16), SIMDE_FLOAT32_C( -548.42)),
      simde_mm256_set_epi64x(INT64_C( -616435447695200909), INT64_C( 6852812389335600665),
                             INT64_C(-7342600923051374002), INT64_C( 3876261701530645696)),
      { SIMDE_FLOAT32_C( -433.77), SIMDE_FLOAT32_C( -375.49),
        SIMDE_FLOAT32_C( -445.70), SIMDE_FLOAT32_C( -589.22),
        SIMDE_FLOAT32_C( -736.41), SIMDE_FLOAT32_C( -896.76),
        SIMDE_FLOAT32_C( -675.40), SIMDE_FLOAT32_C(  481.53) },
      { SIMDE_FLOAT32_C( -548.42), SIMDE_FLOAT32_C( -375.49),
        SIMDE_FLOAT32_C(  378.16), SIMDE_FLOAT32_C( -812.21),
        SIMDE_FLOAT32_C( -736.41), SIMDE_FLOAT32_C( -896.76),
        SIMDE_FLOAT32_C( -457.53), SIMDE_FLOAT32_C(  723.54) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -785.55), SIMDE_FLOAT32_C( -256.70),
                         SIMDE_FLOAT32_C(  127.87), SIMDE_FLOAT32_C( -190.27),
                         SIMDE_FLOAT32_C( -258.76), SIMDE_FLOAT32_C( -158.88),
                         SIMDE_FLOAT32_C(  878.41), SIMDE_FLOAT32_C( -464.91)),
      simde_mm256_set_epi64x(INT64_C(-8429494741451862298), INT64_C(-5719079744080869823),
                             INT64_C(-5398854853129310758), INT64_C( 1027012433924339585)),
      { SIMDE_FLOAT32_C( -104.16), SIMDE_FLOAT32_C( -833.72),
        SIMDE_FLOAT32_C(  235.08), SIMDE_FLOAT32_C( -538.95),
        SIMDE_FLOAT32_C( -928.73), SIMDE_FLOAT32_C(  567.95),
        SIMDE_FLOAT32_C( -285.10), SIMDE_FLOAT32_C( -704.58) },
      { SIMDE_FLOAT32_C( -104.16), SIMDE_FLOAT32_C( -833.72),
        SIMDE_FLOAT32_C( -158.88), SIMDE_FLOAT32_C( -258.76),
        SIMDE_FLOAT32_C( -928.73), SIMDE_FLOAT32_C(  127.87),
        SIMDE_FLOAT32_C( -256.70), SIMDE_FLOAT32_C( -785.55) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  781.16), SIMDE_FLOAT32_C(  161.31),
                         SIMDE_FLOAT32_C( -254.52), SIMDE_FLOAT32_C(  -11.48),
                         SIMDE_FLOAT32_C( -985.13), SIMDE_FLOAT32_C(  363.04),
                         SIMDE_FLOAT32_C( -749.38), SIMDE_FLOAT32_C( -928.63)),
      simde_mm256_set_epi64x(INT64_C( 2001558216207868998), INT64_C( 5373398186203329258),
                             INT64_C( 7491864056048818001), INT64_C( -646461826983018838)),
      { SIMDE_FLOAT32_C(  746.08), SIMDE_FLOAT32_C( -164.33),
        SIMDE_FLOAT32_C(  587.12), SIMDE_FLOAT32_C(  483.48),
        SIMDE_FLOAT32_C(  710.41), SIMDE_FLOAT32_C(  111.42),
        SIMDE_FLOAT32_C( -246.50), SIMDE_FLOAT32_C(  162.36) },
      { SIMDE_FLOAT32_C( -928.63), SIMDE_FLOAT32_C( -749.38),
        SIMDE_FLOAT32_C(  587.12), SIMDE_FLOAT32_C(  483.48),
        SIMDE_FLOAT32_C(  710.41), SIMDE_FLOAT32_C(  111.42),
        SIMDE_FLOAT32_C(  161.31), SIMDE_FLOAT32_C(  162.36) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32 r[8];
    memcpy(r, test_vec[i].ri, sizeof(r));
    simde_mm256_maskstore_ps(r, test_vec[i].mask, test_vec[i].a);
    simde_assert_m256_f32_equal(r, test_vec[i].ro, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_min_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  620.32), SIMDE_FLOAT32_C( -596.35),
                         SIMDE_FLOAT32_C(  174.72), SIMDE_FLOAT32_C(  165.53),
                         SIMDE_FLOAT32_C(  242.92), SIMDE_FLOAT32_C(  330.00),
                         SIMDE_FLOAT32_C( -436.53), SIMDE_FLOAT32_C( -259.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  137.36), SIMDE_FLOAT32_C(  -49.88),
                         SIMDE_FLOAT32_C(  846.67), SIMDE_FLOAT32_C(  642.07),
                         SIMDE_FLOAT32_C(  353.31), SIMDE_FLOAT32_C( -696.33),
                         SIMDE_FLOAT32_C( -153.51), SIMDE_FLOAT32_C( -347.51)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  137.36), SIMDE_FLOAT32_C( -596.35),
                         SIMDE_FLOAT32_C(  174.72), SIMDE_FLOAT32_C(  165.53),
                         SIMDE_FLOAT32_C(  242.92), SIMDE_FLOAT32_C( -696.33),
                         SIMDE_FLOAT32_C( -436.53), SIMDE_FLOAT32_C( -347.51)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  938.63), SIMDE_FLOAT32_C(  244.19),
                         SIMDE_FLOAT32_C(  355.24), SIMDE_FLOAT32_C(  261.35),
                         SIMDE_FLOAT32_C(  679.42), SIMDE_FLOAT32_C(  -31.35),
                         SIMDE_FLOAT32_C(  138.77), SIMDE_FLOAT32_C( -717.66)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -563.43), SIMDE_FLOAT32_C(  586.11),
                         SIMDE_FLOAT32_C( -131.07), SIMDE_FLOAT32_C(  850.65),
                         SIMDE_FLOAT32_C(  165.14), SIMDE_FLOAT32_C( -413.67),
                         SIMDE_FLOAT32_C( -290.54), SIMDE_FLOAT32_C(  984.51)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -563.43), SIMDE_FLOAT32_C(  244.19),
                         SIMDE_FLOAT32_C( -131.07), SIMDE_FLOAT32_C(  261.35),
                         SIMDE_FLOAT32_C(  165.14), SIMDE_FLOAT32_C( -413.67),
                         SIMDE_FLOAT32_C( -290.54), SIMDE_FLOAT32_C( -717.66)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -838.48), SIMDE_FLOAT32_C(  344.61),
                         SIMDE_FLOAT32_C( -913.53), SIMDE_FLOAT32_C(  858.23),
                         SIMDE_FLOAT32_C( -347.90), SIMDE_FLOAT32_C( -707.87),
                         SIMDE_FLOAT32_C( -634.91), SIMDE_FLOAT32_C( -919.82)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -180.34), SIMDE_FLOAT32_C( -789.22),
                         SIMDE_FLOAT32_C(  607.01), SIMDE_FLOAT32_C(  440.98),
                         SIMDE_FLOAT32_C(  432.59), SIMDE_FLOAT32_C( -196.73),
                         SIMDE_FLOAT32_C(  380.83), SIMDE_FLOAT32_C(  796.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -838.48), SIMDE_FLOAT32_C( -789.22),
                         SIMDE_FLOAT32_C( -913.53), SIMDE_FLOAT32_C(  440.98),
                         SIMDE_FLOAT32_C( -347.90), SIMDE_FLOAT32_C( -707.87),
                         SIMDE_FLOAT32_C( -634.91), SIMDE_FLOAT32_C( -919.82)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -210.35), SIMDE_FLOAT32_C( -870.90),
                         SIMDE_FLOAT32_C(  992.08), SIMDE_FLOAT32_C( -822.82),
                         SIMDE_FLOAT32_C( -209.97), SIMDE_FLOAT32_C( -436.22),
                         SIMDE_FLOAT32_C(  481.44), SIMDE_FLOAT32_C(  169.09)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -860.96), SIMDE_FLOAT32_C(  972.39),
                         SIMDE_FLOAT32_C(  830.57), SIMDE_FLOAT32_C(  -23.76),
                         SIMDE_FLOAT32_C(  311.19), SIMDE_FLOAT32_C(  554.15),
                         SIMDE_FLOAT32_C(    0.80), SIMDE_FLOAT32_C( -247.41)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -860.96), SIMDE_FLOAT32_C( -870.90),
                         SIMDE_FLOAT32_C(  830.57), SIMDE_FLOAT32_C( -822.82),
                         SIMDE_FLOAT32_C( -209.97), SIMDE_FLOAT32_C( -436.22),
                         SIMDE_FLOAT32_C(    0.80), SIMDE_FLOAT32_C( -247.41)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -158.36), SIMDE_FLOAT32_C( -758.94),
                         SIMDE_FLOAT32_C(  618.04), SIMDE_FLOAT32_C(  976.02),
                         SIMDE_FLOAT32_C( -953.60), SIMDE_FLOAT32_C(  866.14),
                         SIMDE_FLOAT32_C(  565.22), SIMDE_FLOAT32_C(  554.29)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -8.54), SIMDE_FLOAT32_C( -896.75),
                         SIMDE_FLOAT32_C(  630.48), SIMDE_FLOAT32_C(   27.00),
                         SIMDE_FLOAT32_C(  865.05), SIMDE_FLOAT32_C( -640.13),
                         SIMDE_FLOAT32_C( -969.96), SIMDE_FLOAT32_C( -427.62)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -158.36), SIMDE_FLOAT32_C( -896.75),
                         SIMDE_FLOAT32_C(  618.04), SIMDE_FLOAT32_C(   27.00),
                         SIMDE_FLOAT32_C( -953.60), SIMDE_FLOAT32_C( -640.13),
                         SIMDE_FLOAT32_C( -969.96), SIMDE_FLOAT32_C( -427.62)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -601.54), SIMDE_FLOAT32_C( -545.11),
                         SIMDE_FLOAT32_C( -568.66), SIMDE_FLOAT32_C(  393.12),
                         SIMDE_FLOAT32_C( -656.85), SIMDE_FLOAT32_C(  612.23),
                         SIMDE_FLOAT32_C(  417.91), SIMDE_FLOAT32_C( -206.48)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -56.90), SIMDE_FLOAT32_C( -986.18),
                         SIMDE_FLOAT32_C(  948.05), SIMDE_FLOAT32_C(  -52.08),
                         SIMDE_FLOAT32_C( -838.46), SIMDE_FLOAT32_C( -751.49),
                         SIMDE_FLOAT32_C(  775.89), SIMDE_FLOAT32_C(  940.13)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -601.54), SIMDE_FLOAT32_C( -986.18),
                         SIMDE_FLOAT32_C( -568.66), SIMDE_FLOAT32_C(  -52.08),
                         SIMDE_FLOAT32_C( -838.46), SIMDE_FLOAT32_C( -751.49),
                         SIMDE_FLOAT32_C(  417.91), SIMDE_FLOAT32_C( -206.48)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  459.26), SIMDE_FLOAT32_C( -447.11),
                         SIMDE_FLOAT32_C(  826.76), SIMDE_FLOAT32_C( -107.61),
                         SIMDE_FLOAT32_C( -521.03), SIMDE_FLOAT32_C(  -33.76),
                         SIMDE_FLOAT32_C(  315.53), SIMDE_FLOAT32_C( -222.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -136.58), SIMDE_FLOAT32_C(   50.72),
                         SIMDE_FLOAT32_C(  921.42), SIMDE_FLOAT32_C(  664.07),
                         SIMDE_FLOAT32_C(  743.00), SIMDE_FLOAT32_C( -236.39),
                         SIMDE_FLOAT32_C(  981.20), SIMDE_FLOAT32_C(  280.47)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -136.58), SIMDE_FLOAT32_C( -447.11),
                         SIMDE_FLOAT32_C(  826.76), SIMDE_FLOAT32_C( -107.61),
                         SIMDE_FLOAT32_C( -521.03), SIMDE_FLOAT32_C( -236.39),
                         SIMDE_FLOAT32_C(  315.53), SIMDE_FLOAT32_C( -222.31)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  356.76), SIMDE_FLOAT32_C( -389.22),
                         SIMDE_FLOAT32_C( -477.96), SIMDE_FLOAT32_C(   -3.77),
                         SIMDE_FLOAT32_C( -645.03), SIMDE_FLOAT32_C( -766.89),
                         SIMDE_FLOAT32_C(  755.76), SIMDE_FLOAT32_C(  244.51)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  823.25), SIMDE_FLOAT32_C(  384.14),
                         SIMDE_FLOAT32_C(  475.61), SIMDE_FLOAT32_C( -650.92),
                         SIMDE_FLOAT32_C( -913.35), SIMDE_FLOAT32_C( -290.77),
                         SIMDE_FLOAT32_C(  213.82), SIMDE_FLOAT32_C( -350.01)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  356.76), SIMDE_FLOAT32_C( -389.22),
                         SIMDE_FLOAT32_C( -477.96), SIMDE_FLOAT32_C( -650.92),
                         SIMDE_FLOAT32_C( -913.35), SIMDE_FLOAT32_C( -766.89),
                         SIMDE_FLOAT32_C(  213.82), SIMDE_FLOAT32_C( -350.01)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_min_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_min_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  207.41), SIMDE_FLOAT64_C(  328.63),
                         SIMDE_FLOAT64_C( -694.69), SIMDE_FLOAT64_C(  687.63)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   89.05), SIMDE_FLOAT64_C(  448.86),
                         SIMDE_FLOAT64_C(   19.12), SIMDE_FLOAT64_C( -158.19)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   89.05), SIMDE_FLOAT64_C(  328.63),
                         SIMDE_FLOAT64_C( -694.69), SIMDE_FLOAT64_C( -158.19)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  809.97), SIMDE_FLOAT64_C( -437.57),
                         SIMDE_FLOAT64_C( -994.98), SIMDE_FLOAT64_C( -594.51)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  949.89), SIMDE_FLOAT64_C( -515.80),
                         SIMDE_FLOAT64_C( -545.90), SIMDE_FLOAT64_C(  794.78)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  809.97), SIMDE_FLOAT64_C( -515.80),
                         SIMDE_FLOAT64_C( -994.98), SIMDE_FLOAT64_C( -594.51)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -509.90), SIMDE_FLOAT64_C( -421.15),
                         SIMDE_FLOAT64_C( -539.85), SIMDE_FLOAT64_C( -245.38)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -30.48), SIMDE_FLOAT64_C( -451.08),
                         SIMDE_FLOAT64_C(  -92.82), SIMDE_FLOAT64_C( -896.69)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -509.90), SIMDE_FLOAT64_C( -451.08),
                         SIMDE_FLOAT64_C( -539.85), SIMDE_FLOAT64_C( -896.69)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  362.92), SIMDE_FLOAT64_C(  618.37),
                         SIMDE_FLOAT64_C( -874.81), SIMDE_FLOAT64_C(  119.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  479.87), SIMDE_FLOAT64_C(  161.56),
                         SIMDE_FLOAT64_C(  162.67), SIMDE_FLOAT64_C( -967.58)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  362.92), SIMDE_FLOAT64_C(  161.56),
                         SIMDE_FLOAT64_C( -874.81), SIMDE_FLOAT64_C( -967.58)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -124.73), SIMDE_FLOAT64_C(  204.12),
                         SIMDE_FLOAT64_C( -546.39), SIMDE_FLOAT64_C(  -78.22)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  120.00), SIMDE_FLOAT64_C(  851.26),
                         SIMDE_FLOAT64_C(  153.83), SIMDE_FLOAT64_C(  393.14)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -124.73), SIMDE_FLOAT64_C(  204.12),
                         SIMDE_FLOAT64_C( -546.39), SIMDE_FLOAT64_C(  -78.22)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -812.91), SIMDE_FLOAT64_C(  797.50),
                         SIMDE_FLOAT64_C(  285.31), SIMDE_FLOAT64_C(  340.33)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -48.34), SIMDE_FLOAT64_C( -906.19),
                         SIMDE_FLOAT64_C(  314.61), SIMDE_FLOAT64_C(  602.47)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -812.91), SIMDE_FLOAT64_C( -906.19),
                         SIMDE_FLOAT64_C(  285.31), SIMDE_FLOAT64_C(  340.33)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  376.08), SIMDE_FLOAT64_C(  847.57),
                         SIMDE_FLOAT64_C(  979.10), SIMDE_FLOAT64_C( -602.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  307.85), SIMDE_FLOAT64_C(  571.44),
                         SIMDE_FLOAT64_C( -621.81), SIMDE_FLOAT64_C(  -12.29)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  307.85), SIMDE_FLOAT64_C(  571.44),
                         SIMDE_FLOAT64_C( -621.81), SIMDE_FLOAT64_C( -602.74)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -682.10), SIMDE_FLOAT64_C(  349.84),
                         SIMDE_FLOAT64_C( -943.34), SIMDE_FLOAT64_C(  341.61)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -89.49), SIMDE_FLOAT64_C( -236.51),
                         SIMDE_FLOAT64_C(  632.28), SIMDE_FLOAT64_C( -535.13)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -682.10), SIMDE_FLOAT64_C( -236.51),
                         SIMDE_FLOAT64_C( -943.34), SIMDE_FLOAT64_C( -535.13)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_min_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_max_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  449.92), SIMDE_FLOAT32_C(   34.28),
                         SIMDE_FLOAT32_C(  -25.78), SIMDE_FLOAT32_C(  210.08),
                         SIMDE_FLOAT32_C(  389.04), SIMDE_FLOAT32_C( -871.84),
                         SIMDE_FLOAT32_C( -259.15), SIMDE_FLOAT32_C( -935.03)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -540.89), SIMDE_FLOAT32_C(  480.33),
                         SIMDE_FLOAT32_C(   35.20), SIMDE_FLOAT32_C(  243.72),
                         SIMDE_FLOAT32_C(  827.03), SIMDE_FLOAT32_C(  -35.53),
                         SIMDE_FLOAT32_C( -369.50), SIMDE_FLOAT32_C( -834.21)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  449.92), SIMDE_FLOAT32_C(  480.33),
                         SIMDE_FLOAT32_C(   35.20), SIMDE_FLOAT32_C(  243.72),
                         SIMDE_FLOAT32_C(  827.03), SIMDE_FLOAT32_C(  -35.53),
                         SIMDE_FLOAT32_C( -259.15), SIMDE_FLOAT32_C( -834.21)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  489.45), SIMDE_FLOAT32_C( -170.78),
                         SIMDE_FLOAT32_C(  183.48), SIMDE_FLOAT32_C(  307.64),
                         SIMDE_FLOAT32_C( -977.66), SIMDE_FLOAT32_C(  745.18),
                         SIMDE_FLOAT32_C(  561.96), SIMDE_FLOAT32_C( -868.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -220.92), SIMDE_FLOAT32_C(  742.39),
                         SIMDE_FLOAT32_C(  682.97), SIMDE_FLOAT32_C(  319.92),
                         SIMDE_FLOAT32_C(  734.45), SIMDE_FLOAT32_C( -490.69),
                         SIMDE_FLOAT32_C( -753.68), SIMDE_FLOAT32_C( -110.63)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  489.45), SIMDE_FLOAT32_C(  742.39),
                         SIMDE_FLOAT32_C(  682.97), SIMDE_FLOAT32_C(  319.92),
                         SIMDE_FLOAT32_C(  734.45), SIMDE_FLOAT32_C(  745.18),
                         SIMDE_FLOAT32_C(  561.96), SIMDE_FLOAT32_C( -110.63)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -934.39), SIMDE_FLOAT32_C( -436.28),
                         SIMDE_FLOAT32_C(  572.10), SIMDE_FLOAT32_C( -111.64),
                         SIMDE_FLOAT32_C(  551.18), SIMDE_FLOAT32_C(  829.61),
                         SIMDE_FLOAT32_C( -107.94), SIMDE_FLOAT32_C( -864.62)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  797.77), SIMDE_FLOAT32_C(  207.18),
                         SIMDE_FLOAT32_C( -690.52), SIMDE_FLOAT32_C(  861.15),
                         SIMDE_FLOAT32_C(  110.08), SIMDE_FLOAT32_C(   67.85),
                         SIMDE_FLOAT32_C( -389.66), SIMDE_FLOAT32_C(  867.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  797.77), SIMDE_FLOAT32_C(  207.18),
                         SIMDE_FLOAT32_C(  572.10), SIMDE_FLOAT32_C(  861.15),
                         SIMDE_FLOAT32_C(  551.18), SIMDE_FLOAT32_C(  829.61),
                         SIMDE_FLOAT32_C( -107.94), SIMDE_FLOAT32_C(  867.20)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  481.13), SIMDE_FLOAT32_C(  -53.37),
                         SIMDE_FLOAT32_C(   -0.04), SIMDE_FLOAT32_C(  614.09),
                         SIMDE_FLOAT32_C(  596.94), SIMDE_FLOAT32_C(  349.18),
                         SIMDE_FLOAT32_C(   53.36), SIMDE_FLOAT32_C(  244.43)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -253.17), SIMDE_FLOAT32_C( -107.20),
                         SIMDE_FLOAT32_C( -893.53), SIMDE_FLOAT32_C(  608.05),
                         SIMDE_FLOAT32_C(  292.67), SIMDE_FLOAT32_C(  529.08),
                         SIMDE_FLOAT32_C(  170.70), SIMDE_FLOAT32_C( -778.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  481.13), SIMDE_FLOAT32_C(  -53.37),
                         SIMDE_FLOAT32_C(   -0.04), SIMDE_FLOAT32_C(  614.09),
                         SIMDE_FLOAT32_C(  596.94), SIMDE_FLOAT32_C(  529.08),
                         SIMDE_FLOAT32_C(  170.70), SIMDE_FLOAT32_C(  244.43)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -125.79), SIMDE_FLOAT32_C( -776.79),
                         SIMDE_FLOAT32_C( -268.99), SIMDE_FLOAT32_C(  991.82),
                         SIMDE_FLOAT32_C(  880.36), SIMDE_FLOAT32_C( -906.06),
                         SIMDE_FLOAT32_C( -550.03), SIMDE_FLOAT32_C(  415.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  733.77), SIMDE_FLOAT32_C( -207.30),
                         SIMDE_FLOAT32_C( -944.02), SIMDE_FLOAT32_C( -591.97),
                         SIMDE_FLOAT32_C( -584.21), SIMDE_FLOAT32_C(  271.28),
                         SIMDE_FLOAT32_C( -845.79), SIMDE_FLOAT32_C( -155.27)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  733.77), SIMDE_FLOAT32_C( -207.30),
                         SIMDE_FLOAT32_C( -268.99), SIMDE_FLOAT32_C(  991.82),
                         SIMDE_FLOAT32_C(  880.36), SIMDE_FLOAT32_C(  271.28),
                         SIMDE_FLOAT32_C( -550.03), SIMDE_FLOAT32_C(  415.17)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -136.67), SIMDE_FLOAT32_C(  221.00),
                         SIMDE_FLOAT32_C( -864.98), SIMDE_FLOAT32_C(  290.97),
                         SIMDE_FLOAT32_C( -704.76), SIMDE_FLOAT32_C( -867.43),
                         SIMDE_FLOAT32_C( -323.83), SIMDE_FLOAT32_C(   74.81)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -127.03), SIMDE_FLOAT32_C(  135.62),
                         SIMDE_FLOAT32_C( -308.59), SIMDE_FLOAT32_C( -352.70),
                         SIMDE_FLOAT32_C(  883.68), SIMDE_FLOAT32_C(  134.86),
                         SIMDE_FLOAT32_C( -894.89), SIMDE_FLOAT32_C( -737.05)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -127.03), SIMDE_FLOAT32_C(  221.00),
                         SIMDE_FLOAT32_C( -308.59), SIMDE_FLOAT32_C(  290.97),
                         SIMDE_FLOAT32_C(  883.68), SIMDE_FLOAT32_C(  134.86),
                         SIMDE_FLOAT32_C( -323.83), SIMDE_FLOAT32_C(   74.81)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  780.81), SIMDE_FLOAT32_C(  -76.69),
                         SIMDE_FLOAT32_C( -213.47), SIMDE_FLOAT32_C(  296.05),
                         SIMDE_FLOAT32_C(  129.81), SIMDE_FLOAT32_C(   95.07),
                         SIMDE_FLOAT32_C( -493.97), SIMDE_FLOAT32_C( -309.39)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  224.91), SIMDE_FLOAT32_C(  545.10),
                         SIMDE_FLOAT32_C( -928.25), SIMDE_FLOAT32_C(  373.14),
                         SIMDE_FLOAT32_C( -710.01), SIMDE_FLOAT32_C(  166.25),
                         SIMDE_FLOAT32_C(  729.82), SIMDE_FLOAT32_C(  996.22)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  780.81), SIMDE_FLOAT32_C(  545.10),
                         SIMDE_FLOAT32_C( -213.47), SIMDE_FLOAT32_C(  373.14),
                         SIMDE_FLOAT32_C(  129.81), SIMDE_FLOAT32_C(  166.25),
                         SIMDE_FLOAT32_C(  729.82), SIMDE_FLOAT32_C(  996.22)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -153.19), SIMDE_FLOAT32_C( -809.42),
                         SIMDE_FLOAT32_C(  665.06), SIMDE_FLOAT32_C(  966.51),
                         SIMDE_FLOAT32_C(  515.00), SIMDE_FLOAT32_C(  239.45),
                         SIMDE_FLOAT32_C(  878.48), SIMDE_FLOAT32_C(   83.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -855.75), SIMDE_FLOAT32_C( -288.00),
                         SIMDE_FLOAT32_C(  118.38), SIMDE_FLOAT32_C(  373.81),
                         SIMDE_FLOAT32_C( -507.54), SIMDE_FLOAT32_C( -677.13),
                         SIMDE_FLOAT32_C( -680.61), SIMDE_FLOAT32_C(  934.18)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -153.19), SIMDE_FLOAT32_C( -288.00),
                         SIMDE_FLOAT32_C(  665.06), SIMDE_FLOAT32_C(  966.51),
                         SIMDE_FLOAT32_C(  515.00), SIMDE_FLOAT32_C(  239.45),
                         SIMDE_FLOAT32_C(  878.48), SIMDE_FLOAT32_C(  934.18)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_max_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_max_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -66.36), SIMDE_FLOAT64_C( -982.48),
                         SIMDE_FLOAT64_C( -994.10), SIMDE_FLOAT64_C(  656.44)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   58.12), SIMDE_FLOAT64_C(  730.28),
                         SIMDE_FLOAT64_C(  705.46), SIMDE_FLOAT64_C(  138.28)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   58.12), SIMDE_FLOAT64_C(  730.28),
                         SIMDE_FLOAT64_C(  705.46), SIMDE_FLOAT64_C(  656.44)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  965.09), SIMDE_FLOAT64_C( -956.81),
                         SIMDE_FLOAT64_C(  -84.17), SIMDE_FLOAT64_C(   -0.28)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -943.91), SIMDE_FLOAT64_C( -849.45),
                         SIMDE_FLOAT64_C(  747.06), SIMDE_FLOAT64_C(  297.16)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  965.09), SIMDE_FLOAT64_C( -849.45),
                         SIMDE_FLOAT64_C(  747.06), SIMDE_FLOAT64_C(  297.16)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -285.40), SIMDE_FLOAT64_C(   20.32),
                         SIMDE_FLOAT64_C( -517.57), SIMDE_FLOAT64_C(  747.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -634.35), SIMDE_FLOAT64_C( -655.50),
                         SIMDE_FLOAT64_C(  321.54), SIMDE_FLOAT64_C( -151.46)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -285.40), SIMDE_FLOAT64_C(   20.32),
                         SIMDE_FLOAT64_C(  321.54), SIMDE_FLOAT64_C(  747.40)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  766.49), SIMDE_FLOAT64_C( -821.02),
                         SIMDE_FLOAT64_C(  800.18), SIMDE_FLOAT64_C(  -78.19)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -744.41), SIMDE_FLOAT64_C(  250.49),
                         SIMDE_FLOAT64_C(   16.63), SIMDE_FLOAT64_C(  223.92)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  766.49), SIMDE_FLOAT64_C(  250.49),
                         SIMDE_FLOAT64_C(  800.18), SIMDE_FLOAT64_C(  223.92)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  297.61), SIMDE_FLOAT64_C(   -1.23),
                         SIMDE_FLOAT64_C( -644.62), SIMDE_FLOAT64_C(  -37.89)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -152.08), SIMDE_FLOAT64_C(  667.58),
                         SIMDE_FLOAT64_C(  737.38), SIMDE_FLOAT64_C(  221.17)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  297.61), SIMDE_FLOAT64_C(  667.58),
                         SIMDE_FLOAT64_C(  737.38), SIMDE_FLOAT64_C(  221.17)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  804.47), SIMDE_FLOAT64_C( -363.06),
                         SIMDE_FLOAT64_C( -130.47), SIMDE_FLOAT64_C( -257.67)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -448.43), SIMDE_FLOAT64_C(   52.56),
                         SIMDE_FLOAT64_C( -688.52), SIMDE_FLOAT64_C(  690.05)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  804.47), SIMDE_FLOAT64_C(   52.56),
                         SIMDE_FLOAT64_C( -130.47), SIMDE_FLOAT64_C(  690.05)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   20.48), SIMDE_FLOAT64_C(  404.58),
                         SIMDE_FLOAT64_C( -885.87), SIMDE_FLOAT64_C(  607.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -402.92), SIMDE_FLOAT64_C(  777.55),
                         SIMDE_FLOAT64_C( -392.90), SIMDE_FLOAT64_C(  385.67)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   20.48), SIMDE_FLOAT64_C(  777.55),
                         SIMDE_FLOAT64_C( -392.90), SIMDE_FLOAT64_C(  607.60)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -612.46), SIMDE_FLOAT64_C( -353.94),
                         SIMDE_FLOAT64_C( -723.01), SIMDE_FLOAT64_C( -705.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -638.30), SIMDE_FLOAT64_C(   67.95),
                         SIMDE_FLOAT64_C(  537.38), SIMDE_FLOAT64_C( -280.17)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -612.46), SIMDE_FLOAT64_C(   67.95),
                         SIMDE_FLOAT64_C(  537.38), SIMDE_FLOAT64_C( -280.17)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_max_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_movedup_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -848.53), SIMDE_FLOAT64_C( -411.84),
                         SIMDE_FLOAT64_C( -162.95), SIMDE_FLOAT64_C(  899.65)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -411.84), SIMDE_FLOAT64_C( -411.84),
                         SIMDE_FLOAT64_C(  899.65), SIMDE_FLOAT64_C(  899.65)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -411.40), SIMDE_FLOAT64_C( -713.22),
                         SIMDE_FLOAT64_C( -868.77), SIMDE_FLOAT64_C( -109.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -713.22), SIMDE_FLOAT64_C( -713.22),
                         SIMDE_FLOAT64_C( -109.40), SIMDE_FLOAT64_C( -109.40)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -430.65), SIMDE_FLOAT64_C(  350.42),
                         SIMDE_FLOAT64_C( -891.94), SIMDE_FLOAT64_C( -973.52)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  350.42), SIMDE_FLOAT64_C(  350.42),
                         SIMDE_FLOAT64_C( -973.52), SIMDE_FLOAT64_C( -973.52)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -988.20), SIMDE_FLOAT64_C( -840.45),
                         SIMDE_FLOAT64_C(  979.48), SIMDE_FLOAT64_C( -644.54)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -840.45), SIMDE_FLOAT64_C( -840.45),
                         SIMDE_FLOAT64_C( -644.54), SIMDE_FLOAT64_C( -644.54)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  459.82), SIMDE_FLOAT64_C(  645.18),
                         SIMDE_FLOAT64_C( -152.73), SIMDE_FLOAT64_C(  150.29)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  645.18), SIMDE_FLOAT64_C(  645.18),
                         SIMDE_FLOAT64_C(  150.29), SIMDE_FLOAT64_C(  150.29)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -902.52), SIMDE_FLOAT64_C(   -5.45),
                         SIMDE_FLOAT64_C( -958.89), SIMDE_FLOAT64_C( -924.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -5.45), SIMDE_FLOAT64_C(   -5.45),
                         SIMDE_FLOAT64_C( -924.74), SIMDE_FLOAT64_C( -924.74)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -582.37), SIMDE_FLOAT64_C(  163.98),
                         SIMDE_FLOAT64_C( -479.86), SIMDE_FLOAT64_C(  420.17)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  163.98), SIMDE_FLOAT64_C(  163.98),
                         SIMDE_FLOAT64_C(  420.17), SIMDE_FLOAT64_C(  420.17)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -319.68), SIMDE_FLOAT64_C(  791.82),
                         SIMDE_FLOAT64_C(  388.17), SIMDE_FLOAT64_C(  537.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  791.82), SIMDE_FLOAT64_C(  791.82),
                         SIMDE_FLOAT64_C(  537.00), SIMDE_FLOAT64_C(  537.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_movedup_pd(test_vec[i].a);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_movehdup_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  948.05), SIMDE_FLOAT32_C( -208.59),
                         SIMDE_FLOAT32_C( -422.71), SIMDE_FLOAT32_C( -254.03),
                         SIMDE_FLOAT32_C(    4.80), SIMDE_FLOAT32_C( -671.71),
                         SIMDE_FLOAT32_C(  685.42), SIMDE_FLOAT32_C( -954.51)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  948.05), SIMDE_FLOAT32_C(  948.05),
                         SIMDE_FLOAT32_C( -422.71), SIMDE_FLOAT32_C( -422.71),
                         SIMDE_FLOAT32_C(    4.80), SIMDE_FLOAT32_C(    4.80),
                         SIMDE_FLOAT32_C(  685.42), SIMDE_FLOAT32_C(  685.42)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  569.22), SIMDE_FLOAT32_C(  232.90),
                         SIMDE_FLOAT32_C(  835.45), SIMDE_FLOAT32_C(   10.13),
                         SIMDE_FLOAT32_C(   30.06), SIMDE_FLOAT32_C(  598.20),
                         SIMDE_FLOAT32_C(  376.16), SIMDE_FLOAT32_C( -918.63)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  569.22), SIMDE_FLOAT32_C(  569.22),
                         SIMDE_FLOAT32_C(  835.45), SIMDE_FLOAT32_C(  835.45),
                         SIMDE_FLOAT32_C(   30.06), SIMDE_FLOAT32_C(   30.06),
                         SIMDE_FLOAT32_C(  376.16), SIMDE_FLOAT32_C(  376.16)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   97.81), SIMDE_FLOAT32_C(  286.59),
                         SIMDE_FLOAT32_C( -299.41), SIMDE_FLOAT32_C(  944.38),
                         SIMDE_FLOAT32_C( -367.92), SIMDE_FLOAT32_C(  626.43),
                         SIMDE_FLOAT32_C(  889.36), SIMDE_FLOAT32_C(  776.89)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   97.81), SIMDE_FLOAT32_C(   97.81),
                         SIMDE_FLOAT32_C( -299.41), SIMDE_FLOAT32_C( -299.41),
                         SIMDE_FLOAT32_C( -367.92), SIMDE_FLOAT32_C( -367.92),
                         SIMDE_FLOAT32_C(  889.36), SIMDE_FLOAT32_C(  889.36)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -67.83), SIMDE_FLOAT32_C( -435.86),
                         SIMDE_FLOAT32_C( -637.27), SIMDE_FLOAT32_C(  -95.13),
                         SIMDE_FLOAT32_C(  698.01), SIMDE_FLOAT32_C(   55.48),
                         SIMDE_FLOAT32_C(    1.28), SIMDE_FLOAT32_C( -243.13)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -67.83), SIMDE_FLOAT32_C(  -67.83),
                         SIMDE_FLOAT32_C( -637.27), SIMDE_FLOAT32_C( -637.27),
                         SIMDE_FLOAT32_C(  698.01), SIMDE_FLOAT32_C(  698.01),
                         SIMDE_FLOAT32_C(    1.28), SIMDE_FLOAT32_C(    1.28)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -266.47), SIMDE_FLOAT32_C(  784.83),
                         SIMDE_FLOAT32_C( -470.70), SIMDE_FLOAT32_C(  865.28),
                         SIMDE_FLOAT32_C(  393.60), SIMDE_FLOAT32_C( -743.40),
                         SIMDE_FLOAT32_C(  858.48), SIMDE_FLOAT32_C(  507.86)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -266.47), SIMDE_FLOAT32_C( -266.47),
                         SIMDE_FLOAT32_C( -470.70), SIMDE_FLOAT32_C( -470.70),
                         SIMDE_FLOAT32_C(  393.60), SIMDE_FLOAT32_C(  393.60),
                         SIMDE_FLOAT32_C(  858.48), SIMDE_FLOAT32_C(  858.48)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  270.84), SIMDE_FLOAT32_C(   46.20),
                         SIMDE_FLOAT32_C( -185.53), SIMDE_FLOAT32_C(  211.61),
                         SIMDE_FLOAT32_C(  -20.87), SIMDE_FLOAT32_C( -661.06),
                         SIMDE_FLOAT32_C(  209.04), SIMDE_FLOAT32_C(  920.86)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  270.84), SIMDE_FLOAT32_C(  270.84),
                         SIMDE_FLOAT32_C( -185.53), SIMDE_FLOAT32_C( -185.53),
                         SIMDE_FLOAT32_C(  -20.87), SIMDE_FLOAT32_C(  -20.87),
                         SIMDE_FLOAT32_C(  209.04), SIMDE_FLOAT32_C(  209.04)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -751.76), SIMDE_FLOAT32_C( -655.85),
                         SIMDE_FLOAT32_C(  179.21), SIMDE_FLOAT32_C(  373.36),
                         SIMDE_FLOAT32_C(    1.62), SIMDE_FLOAT32_C( -981.05),
                         SIMDE_FLOAT32_C(  802.72), SIMDE_FLOAT32_C(  -49.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -751.76), SIMDE_FLOAT32_C( -751.76),
                         SIMDE_FLOAT32_C(  179.21), SIMDE_FLOAT32_C(  179.21),
                         SIMDE_FLOAT32_C(    1.62), SIMDE_FLOAT32_C(    1.62),
                         SIMDE_FLOAT32_C(  802.72), SIMDE_FLOAT32_C(  802.72)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   44.57), SIMDE_FLOAT32_C( -391.28),
                         SIMDE_FLOAT32_C(  614.40), SIMDE_FLOAT32_C( -901.50),
                         SIMDE_FLOAT32_C(  577.45), SIMDE_FLOAT32_C( -465.25),
                         SIMDE_FLOAT32_C( -148.70), SIMDE_FLOAT32_C( -714.68)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   44.57), SIMDE_FLOAT32_C(   44.57),
                         SIMDE_FLOAT32_C(  614.40), SIMDE_FLOAT32_C(  614.40),
                         SIMDE_FLOAT32_C(  577.45), SIMDE_FLOAT32_C(  577.45),
                         SIMDE_FLOAT32_C( -148.70), SIMDE_FLOAT32_C( -148.70)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_movehdup_ps(test_vec[i].a);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_moveldup_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  366.49), SIMDE_FLOAT32_C(  -15.43),
                         SIMDE_FLOAT32_C( -732.71), SIMDE_FLOAT32_C(  312.44),
                         SIMDE_FLOAT32_C( -535.64), SIMDE_FLOAT32_C(  -24.14),
                         SIMDE_FLOAT32_C( -881.62), SIMDE_FLOAT32_C(  419.86)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -15.43), SIMDE_FLOAT32_C(  -15.43),
                         SIMDE_FLOAT32_C(  312.44), SIMDE_FLOAT32_C(  312.44),
                         SIMDE_FLOAT32_C(  -24.14), SIMDE_FLOAT32_C(  -24.14),
                         SIMDE_FLOAT32_C(  419.86), SIMDE_FLOAT32_C(  419.86)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -625.40), SIMDE_FLOAT32_C( -523.97),
                         SIMDE_FLOAT32_C(  296.91), SIMDE_FLOAT32_C(  228.72),
                         SIMDE_FLOAT32_C(  553.44), SIMDE_FLOAT32_C(  -88.10),
                         SIMDE_FLOAT32_C( -240.30), SIMDE_FLOAT32_C(  437.29)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -523.97), SIMDE_FLOAT32_C( -523.97),
                         SIMDE_FLOAT32_C(  228.72), SIMDE_FLOAT32_C(  228.72),
                         SIMDE_FLOAT32_C(  -88.10), SIMDE_FLOAT32_C(  -88.10),
                         SIMDE_FLOAT32_C(  437.29), SIMDE_FLOAT32_C(  437.29)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -54.17), SIMDE_FLOAT32_C( -444.25),
                         SIMDE_FLOAT32_C( -384.50), SIMDE_FLOAT32_C(  781.57),
                         SIMDE_FLOAT32_C(  607.05), SIMDE_FLOAT32_C( -295.21),
                         SIMDE_FLOAT32_C(  101.75), SIMDE_FLOAT32_C( -941.55)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -444.25), SIMDE_FLOAT32_C( -444.25),
                         SIMDE_FLOAT32_C(  781.57), SIMDE_FLOAT32_C(  781.57),
                         SIMDE_FLOAT32_C( -295.21), SIMDE_FLOAT32_C( -295.21),
                         SIMDE_FLOAT32_C( -941.55), SIMDE_FLOAT32_C( -941.55)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -41.58), SIMDE_FLOAT32_C( -957.94),
                         SIMDE_FLOAT32_C(  871.50), SIMDE_FLOAT32_C( -839.89),
                         SIMDE_FLOAT32_C(  692.80), SIMDE_FLOAT32_C( -417.15),
                         SIMDE_FLOAT32_C( -850.22), SIMDE_FLOAT32_C(  594.16)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -957.94), SIMDE_FLOAT32_C( -957.94),
                         SIMDE_FLOAT32_C( -839.89), SIMDE_FLOAT32_C( -839.89),
                         SIMDE_FLOAT32_C( -417.15), SIMDE_FLOAT32_C( -417.15),
                         SIMDE_FLOAT32_C(  594.16), SIMDE_FLOAT32_C(  594.16)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -319.28), SIMDE_FLOAT32_C( -229.51),
                         SIMDE_FLOAT32_C( -581.14), SIMDE_FLOAT32_C(   81.57),
                         SIMDE_FLOAT32_C(  774.33), SIMDE_FLOAT32_C( -621.69),
                         SIMDE_FLOAT32_C( -447.13), SIMDE_FLOAT32_C(  334.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -229.51), SIMDE_FLOAT32_C( -229.51),
                         SIMDE_FLOAT32_C(   81.57), SIMDE_FLOAT32_C(   81.57),
                         SIMDE_FLOAT32_C( -621.69), SIMDE_FLOAT32_C( -621.69),
                         SIMDE_FLOAT32_C(  334.88), SIMDE_FLOAT32_C(  334.88)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  288.60), SIMDE_FLOAT32_C(  139.33),
                         SIMDE_FLOAT32_C(  951.18), SIMDE_FLOAT32_C( -924.84),
                         SIMDE_FLOAT32_C( -320.35), SIMDE_FLOAT32_C( -998.89),
                         SIMDE_FLOAT32_C(  164.55), SIMDE_FLOAT32_C(  991.73)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  139.33), SIMDE_FLOAT32_C(  139.33),
                         SIMDE_FLOAT32_C( -924.84), SIMDE_FLOAT32_C( -924.84),
                         SIMDE_FLOAT32_C( -998.89), SIMDE_FLOAT32_C( -998.89),
                         SIMDE_FLOAT32_C(  991.73), SIMDE_FLOAT32_C(  991.73)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -671.27), SIMDE_FLOAT32_C(   35.52),
                         SIMDE_FLOAT32_C(  780.53), SIMDE_FLOAT32_C(  -58.65),
                         SIMDE_FLOAT32_C(  227.27), SIMDE_FLOAT32_C( -621.99),
                         SIMDE_FLOAT32_C( -182.62), SIMDE_FLOAT32_C(  448.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   35.52), SIMDE_FLOAT32_C(   35.52),
                         SIMDE_FLOAT32_C(  -58.65), SIMDE_FLOAT32_C(  -58.65),
                         SIMDE_FLOAT32_C( -621.99), SIMDE_FLOAT32_C( -621.99),
                         SIMDE_FLOAT32_C(  448.36), SIMDE_FLOAT32_C(  448.36)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -984.41), SIMDE_FLOAT32_C( -968.89),
                         SIMDE_FLOAT32_C( -986.96), SIMDE_FLOAT32_C( -760.49),
                         SIMDE_FLOAT32_C(  908.37), SIMDE_FLOAT32_C(   35.57),
                         SIMDE_FLOAT32_C( -144.09), SIMDE_FLOAT32_C( -735.38)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -968.89), SIMDE_FLOAT32_C( -968.89),
                         SIMDE_FLOAT32_C( -760.49), SIMDE_FLOAT32_C( -760.49),
                         SIMDE_FLOAT32_C(   35.57), SIMDE_FLOAT32_C(   35.57),
                         SIMDE_FLOAT32_C( -735.38), SIMDE_FLOAT32_C( -735.38)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_moveldup_ps(test_vec[i].a);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_movemask_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    int r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(-1882468747), INT32_C(  687119108), INT32_C(  990615051), INT32_C(-1253009356),
                            INT32_C( -617641993), INT32_C(-1788847115), INT32_C( 1286496634), INT32_C( -717001088)),
      157 },
    { simde_mm256_set_epi32(INT32_C(-1989003409), INT32_C(-1421574364), INT32_C( -382909714), INT32_C( 1867671217),
                            INT32_C( -487294761), INT32_C( -454003817), INT32_C(  -33445130), INT32_C( -757457478)),
      239 },
    { simde_mm256_set_epi32(INT32_C(   75750543), INT32_C( -792015200), INT32_C( -456366441), INT32_C( 1395825015),
                            INT32_C( 1090607410), INT32_C( -644107645), INT32_C( 2024077315), INT32_C( 1442543377)),
      100 },
    { simde_mm256_set_epi32(INT32_C(   64842844), INT32_C(-1499432736), INT32_C( -849672143), INT32_C(  808386603),
                            INT32_C( 1431766696), INT32_C(  778893676), INT32_C(   -4359592), INT32_C( -465691700)),
      99 },
    { simde_mm256_set_epi32(INT32_C(-1142593030), INT32_C( 1697913004), INT32_C(-1241903623), INT32_C( 1420498198),
                            INT32_C( 1725730120), INT32_C( 1757719770), INT32_C( 1834101516), INT32_C(-1076410946)),
      161 },
    { simde_mm256_set_epi32(INT32_C( -247458634), INT32_C(  497266182), INT32_C(  668953611), INT32_C( -198408792),
                            INT32_C(  443042962), INT32_C(  174399567), INT32_C( 1910223665), INT32_C( 1408104689)),
      144 },
    { simde_mm256_set_epi32(INT32_C( 1266303831), INT32_C(-1981624404), INT32_C( 1894718767), INT32_C( 1471458198),
                            INT32_C(-1698669031), INT32_C(-1514661026), INT32_C(-1880466849), INT32_C(-1226909311)),
      79 },
    { simde_mm256_set_epi32(INT32_C( 1314135938), INT32_C( 1476193225), INT32_C( 1478701126), INT32_C( 1097128360),
                            INT32_C( -681267332), INT32_C( -854863432), INT32_C(-1814679036), INT32_C( 2077413591)),
      14 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm256_movemask_ps(*((simde__m256*) &(test_vec[i].a)));
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_movemask_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    int r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C(-3476114617639449125), INT64_C( 4174348817044283167),
                             INT64_C( 2372823762134739460), INT64_C( 2922754125044459603)),
      8 },
    { simde_mm256_set_epi64x(INT64_C( 2977848152908728188), INT64_C(-9001314161736319662),
                             INT64_C(  316358866512427816), INT64_C(  122734419977663898)),
      4 },
    { simde_mm256_set_epi64x(INT64_C( 1458362257601867464), INT64_C(-2204086314119824728),
                             INT64_C( 4226262178485377739), INT64_C( 3412235452127467527)),
      4 },
    { simde_mm256_set_epi64x(INT64_C(-3206742534496437425), INT64_C( 4783689227782243759),
                             INT64_C(-2969411634419391796), INT64_C( 6490543198836487087)),
      10 },
    { simde_mm256_set_epi64x(INT64_C( 5617129527752259343), INT64_C( 8836429733868806831),
                             INT64_C(-3648376369890579220), INT64_C( 2974368927295586543)),
      2 },
    { simde_mm256_set_epi64x(INT64_C(-7634385432411504297), INT64_C( 7257505416389479780),
                             INT64_C( 7838438756599446984), INT64_C( 8814240438147347165)),
      8 },
    { simde_mm256_set_epi64x(INT64_C( 9071444056306285548), INT64_C( 8310979399473657009),
                             INT64_C(-1777863912628705993), INT64_C( 4472167403670196676)),
      2 },
    { simde_mm256_set_epi64x(INT64_C(-6555517372143397251), INT64_C( 2575855241209659630),
                             INT64_C(-8431720993701553511), INT64_C( -874276281105343662)),
      11 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm256_movemask_pd(* ((simde__m256d*) &(test_vec[i].a)));
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_mul_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -65.11), SIMDE_FLOAT32_C(  729.63),
                         SIMDE_FLOAT32_C(  579.86), SIMDE_FLOAT32_C(  759.34),
                         SIMDE_FLOAT32_C(  638.63), SIMDE_FLOAT32_C(  366.71),
                         SIMDE_FLOAT32_C( -251.89), SIMDE_FLOAT32_C( -327.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -853.75), SIMDE_FLOAT32_C(  306.50),
                         SIMDE_FLOAT32_C( -694.30), SIMDE_FLOAT32_C(   62.03),
                         SIMDE_FLOAT32_C( -332.43), SIMDE_FLOAT32_C( -617.58),
                         SIMDE_FLOAT32_C( -841.05), SIMDE_FLOAT32_C( -990.91)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(55587.66), SIMDE_FLOAT32_C(223631.59),
                         SIMDE_FLOAT32_C(-402596.78), SIMDE_FLOAT32_C(47101.86),
                         SIMDE_FLOAT32_C(-212299.77), SIMDE_FLOAT32_C(-226472.77),
                         SIMDE_FLOAT32_C(211852.08), SIMDE_FLOAT32_C(324721.22)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -540.24), SIMDE_FLOAT32_C(  599.92),
                         SIMDE_FLOAT32_C(  946.63), SIMDE_FLOAT32_C(  269.39),
                         SIMDE_FLOAT32_C(  990.71), SIMDE_FLOAT32_C(  736.78),
                         SIMDE_FLOAT32_C(  735.17), SIMDE_FLOAT32_C( -839.81)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -471.86), SIMDE_FLOAT32_C(  231.47),
                         SIMDE_FLOAT32_C(  368.19), SIMDE_FLOAT32_C( -199.69),
                         SIMDE_FLOAT32_C( -781.21), SIMDE_FLOAT32_C( -576.81),
                         SIMDE_FLOAT32_C( -351.44), SIMDE_FLOAT32_C(  650.57)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(254917.64), SIMDE_FLOAT32_C(138863.48),
                         SIMDE_FLOAT32_C(348539.72), SIMDE_FLOAT32_C(-53794.49),
                         SIMDE_FLOAT32_C(-773952.62), SIMDE_FLOAT32_C(-424982.09),
                         SIMDE_FLOAT32_C(-258368.14), SIMDE_FLOAT32_C(-546355.19)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  174.33), SIMDE_FLOAT32_C( -261.00),
                         SIMDE_FLOAT32_C(  947.71), SIMDE_FLOAT32_C(  -39.38),
                         SIMDE_FLOAT32_C( -142.31), SIMDE_FLOAT32_C( -753.91),
                         SIMDE_FLOAT32_C( -304.55), SIMDE_FLOAT32_C(  197.06)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -894.79), SIMDE_FLOAT32_C(  298.89),
                         SIMDE_FLOAT32_C(  413.08), SIMDE_FLOAT32_C(   45.44),
                         SIMDE_FLOAT32_C( -362.24), SIMDE_FLOAT32_C(  247.39),
                         SIMDE_FLOAT32_C( -836.15), SIMDE_FLOAT32_C(  250.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-155988.73), SIMDE_FLOAT32_C(-78010.30),
                         SIMDE_FLOAT32_C(391480.03), SIMDE_FLOAT32_C(-1789.43),
                         SIMDE_FLOAT32_C(51550.37), SIMDE_FLOAT32_C(-186509.78),
                         SIMDE_FLOAT32_C(254649.48), SIMDE_FLOAT32_C(49367.47)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -108.81), SIMDE_FLOAT32_C( -144.46),
                         SIMDE_FLOAT32_C( -926.46), SIMDE_FLOAT32_C(  -87.02),
                         SIMDE_FLOAT32_C( -701.58), SIMDE_FLOAT32_C(  412.02),
                         SIMDE_FLOAT32_C( -404.71), SIMDE_FLOAT32_C( -140.12)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -502.46), SIMDE_FLOAT32_C( -741.60),
                         SIMDE_FLOAT32_C(  261.69), SIMDE_FLOAT32_C( -236.88),
                         SIMDE_FLOAT32_C(  805.45), SIMDE_FLOAT32_C(  663.49),
                         SIMDE_FLOAT32_C(  804.65), SIMDE_FLOAT32_C( -231.08)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(54672.67), SIMDE_FLOAT32_C(107131.54),
                         SIMDE_FLOAT32_C(-242445.33), SIMDE_FLOAT32_C(20613.30),
                         SIMDE_FLOAT32_C(-565087.62), SIMDE_FLOAT32_C(273371.12),
                         SIMDE_FLOAT32_C(-325649.91), SIMDE_FLOAT32_C(32378.93)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  274.12), SIMDE_FLOAT32_C(  417.28),
                         SIMDE_FLOAT32_C(  626.47), SIMDE_FLOAT32_C(  541.42),
                         SIMDE_FLOAT32_C( -351.86), SIMDE_FLOAT32_C(  144.88),
                         SIMDE_FLOAT32_C( -692.65), SIMDE_FLOAT32_C(  994.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -588.84), SIMDE_FLOAT32_C(  440.91),
                         SIMDE_FLOAT32_C( -668.35), SIMDE_FLOAT32_C(  950.11),
                         SIMDE_FLOAT32_C(   38.08), SIMDE_FLOAT32_C( -877.72),
                         SIMDE_FLOAT32_C(  389.76), SIMDE_FLOAT32_C(  702.21)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-161412.83), SIMDE_FLOAT32_C(183982.92),
                         SIMDE_FLOAT32_C(-418701.19), SIMDE_FLOAT32_C(514408.53),
                         SIMDE_FLOAT32_C(-13398.83), SIMDE_FLOAT32_C(-127164.07),
                         SIMDE_FLOAT32_C(-269967.28), SIMDE_FLOAT32_C(698361.94)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -72.46), SIMDE_FLOAT32_C( -957.98),
                         SIMDE_FLOAT32_C(  872.62), SIMDE_FLOAT32_C( -600.00),
                         SIMDE_FLOAT32_C(  937.99), SIMDE_FLOAT32_C( -698.26),
                         SIMDE_FLOAT32_C(  895.96), SIMDE_FLOAT32_C( -799.53)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -864.38), SIMDE_FLOAT32_C( -416.69),
                         SIMDE_FLOAT32_C(  894.78), SIMDE_FLOAT32_C(  968.43),
                         SIMDE_FLOAT32_C(  609.48), SIMDE_FLOAT32_C(  317.20),
                         SIMDE_FLOAT32_C(  767.37), SIMDE_FLOAT32_C(  -51.68)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(62632.97), SIMDE_FLOAT32_C(399180.69),
                         SIMDE_FLOAT32_C(780802.94), SIMDE_FLOAT32_C(-581058.00),
                         SIMDE_FLOAT32_C(571686.12), SIMDE_FLOAT32_C(-221488.08),
                         SIMDE_FLOAT32_C(687532.81), SIMDE_FLOAT32_C(41319.71)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -131.07), SIMDE_FLOAT32_C( -294.47),
                         SIMDE_FLOAT32_C( -916.92), SIMDE_FLOAT32_C(  146.62),
                         SIMDE_FLOAT32_C(  597.05), SIMDE_FLOAT32_C(   75.62),
                         SIMDE_FLOAT32_C(  636.06), SIMDE_FLOAT32_C(  363.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  427.08), SIMDE_FLOAT32_C( -105.65),
                         SIMDE_FLOAT32_C(   98.05), SIMDE_FLOAT32_C(  398.71),
                         SIMDE_FLOAT32_C( -883.53), SIMDE_FLOAT32_C( -434.31),
                         SIMDE_FLOAT32_C(  638.77), SIMDE_FLOAT32_C( -453.78)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-55977.38), SIMDE_FLOAT32_C(31110.76),
                         SIMDE_FLOAT32_C(-89904.01), SIMDE_FLOAT32_C(58458.86),
                         SIMDE_FLOAT32_C(-527511.56), SIMDE_FLOAT32_C(-32842.52),
                         SIMDE_FLOAT32_C(406296.06), SIMDE_FLOAT32_C(-164826.52)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  401.83), SIMDE_FLOAT32_C( -101.21),
                         SIMDE_FLOAT32_C( -199.00), SIMDE_FLOAT32_C(  823.62),
                         SIMDE_FLOAT32_C( -930.84), SIMDE_FLOAT32_C( -154.42),
                         SIMDE_FLOAT32_C(  958.59), SIMDE_FLOAT32_C(  853.69)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -449.55), SIMDE_FLOAT32_C(  354.78),
                         SIMDE_FLOAT32_C( -131.96), SIMDE_FLOAT32_C( -519.93),
                         SIMDE_FLOAT32_C(  699.65), SIMDE_FLOAT32_C(  781.77),
                         SIMDE_FLOAT32_C( -157.96), SIMDE_FLOAT32_C( -793.47)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-180642.67), SIMDE_FLOAT32_C(-35907.29),
                         SIMDE_FLOAT32_C(26260.04), SIMDE_FLOAT32_C(-428224.75),
                         SIMDE_FLOAT32_C(-651262.25), SIMDE_FLOAT32_C(-120720.92),
                         SIMDE_FLOAT32_C(-151418.89), SIMDE_FLOAT32_C(-677377.38)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_mul_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_mul_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -216.07), SIMDE_FLOAT64_C(   -759.70),
                         SIMDE_FLOAT64_C(   -257.81), SIMDE_FLOAT64_C(    916.82)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -279.71), SIMDE_FLOAT64_C(    654.36),
                         SIMDE_FLOAT64_C(   -699.07), SIMDE_FLOAT64_C(    772.15)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  60436.94), SIMDE_FLOAT64_C(-497117.29),
                         SIMDE_FLOAT64_C( 180227.24), SIMDE_FLOAT64_C( 707922.56)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -576.02), SIMDE_FLOAT64_C(   -915.91),
                         SIMDE_FLOAT64_C(    616.42), SIMDE_FLOAT64_C(    692.53)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    285.52), SIMDE_FLOAT64_C(   -538.61),
                         SIMDE_FLOAT64_C(    604.61), SIMDE_FLOAT64_C(   -220.38)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-164465.23), SIMDE_FLOAT64_C( 493318.29),
                         SIMDE_FLOAT64_C( 372693.70), SIMDE_FLOAT64_C(-152619.76)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -378.41), SIMDE_FLOAT64_C(   -782.44),
                         SIMDE_FLOAT64_C(   -858.38), SIMDE_FLOAT64_C(   -932.65)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    782.91), SIMDE_FLOAT64_C(    352.73),
                         SIMDE_FLOAT64_C(    705.00), SIMDE_FLOAT64_C(    -78.46)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-296260.97), SIMDE_FLOAT64_C(-275990.06),
                         SIMDE_FLOAT64_C(-605157.90), SIMDE_FLOAT64_C(  73175.72)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -936.48), SIMDE_FLOAT64_C(    274.43),
                         SIMDE_FLOAT64_C(    341.69), SIMDE_FLOAT64_C(    588.43)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -915.35), SIMDE_FLOAT64_C(    625.98),
                         SIMDE_FLOAT64_C(    -66.28), SIMDE_FLOAT64_C(   -474.34)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 857206.97), SIMDE_FLOAT64_C( 171787.69),
                         SIMDE_FLOAT64_C( -22647.21), SIMDE_FLOAT64_C(-279115.89)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    371.75), SIMDE_FLOAT64_C(   -392.05),
                         SIMDE_FLOAT64_C(   -730.60), SIMDE_FLOAT64_C(    399.39)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -409.43), SIMDE_FLOAT64_C(    920.37),
                         SIMDE_FLOAT64_C(    -56.28), SIMDE_FLOAT64_C(   -779.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-152205.60), SIMDE_FLOAT64_C(-360831.06),
                         SIMDE_FLOAT64_C(  41118.17), SIMDE_FLOAT64_C(-311248.62)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(     -0.10), SIMDE_FLOAT64_C(    955.19),
                         SIMDE_FLOAT64_C(    162.40), SIMDE_FLOAT64_C(   -236.01)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -741.60), SIMDE_FLOAT64_C(    194.99),
                         SIMDE_FLOAT64_C(    845.16), SIMDE_FLOAT64_C(    363.39)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(     74.16), SIMDE_FLOAT64_C( 186252.50),
                         SIMDE_FLOAT64_C( 137253.98), SIMDE_FLOAT64_C( -85763.67)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(     18.23), SIMDE_FLOAT64_C(    296.33),
                         SIMDE_FLOAT64_C(    628.43), SIMDE_FLOAT64_C(   -660.29)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    -24.23), SIMDE_FLOAT64_C(    573.95),
                         SIMDE_FLOAT64_C(    350.37), SIMDE_FLOAT64_C(   -979.36)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -441.71), SIMDE_FLOAT64_C( 170078.60),
                         SIMDE_FLOAT64_C( 220183.02), SIMDE_FLOAT64_C( 646661.61)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(     14.47), SIMDE_FLOAT64_C(    780.26),
                         SIMDE_FLOAT64_C(   -875.01), SIMDE_FLOAT64_C(    609.14)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    690.47), SIMDE_FLOAT64_C(   -614.79),
                         SIMDE_FLOAT64_C(    626.96), SIMDE_FLOAT64_C(   -369.27)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   9991.10), SIMDE_FLOAT64_C(-479696.05),
                         SIMDE_FLOAT64_C(-548596.27), SIMDE_FLOAT64_C(-224937.13)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_mul_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_or_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -856.34), SIMDE_FLOAT32_C(   -251.54),
                         SIMDE_FLOAT32_C(    873.84), SIMDE_FLOAT32_C(    282.56),
                         SIMDE_FLOAT32_C(   -701.43), SIMDE_FLOAT32_C(    881.08),
                         SIMDE_FLOAT32_C(    949.17), SIMDE_FLOAT32_C(    -70.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     13.03), SIMDE_FLOAT32_C(   -213.71),
                         SIMDE_FLOAT32_C(   -960.05), SIMDE_FLOAT32_C(     76.97),
                         SIMDE_FLOAT32_C(    529.10), SIMDE_FLOAT32_C(   -768.23),
                         SIMDE_FLOAT32_C(    808.48), SIMDE_FLOAT32_C(   -237.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -3431.99), SIMDE_FLOAT32_C(   -255.75),
                         SIMDE_FLOAT32_C(  -1001.87), SIMDE_FLOAT32_C(    315.93),
                         SIMDE_FLOAT32_C(   -701.50), SIMDE_FLOAT32_C(   -881.25),
                         SIMDE_FLOAT32_C(    957.48), SIMDE_FLOAT32_C(   -474.81)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    222.49), SIMDE_FLOAT32_C(    898.11),
                         SIMDE_FLOAT32_C(   -986.95), SIMDE_FLOAT32_C(   -624.89),
                         SIMDE_FLOAT32_C(   -780.02), SIMDE_FLOAT32_C(    920.74),
                         SIMDE_FLOAT32_C(    815.92), SIMDE_FLOAT32_C(    550.68)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -274.50), SIMDE_FLOAT32_C(    377.51),
                         SIMDE_FLOAT32_C(    595.96), SIMDE_FLOAT32_C(    513.30),
                         SIMDE_FLOAT32_C(    235.21), SIMDE_FLOAT32_C(    -45.95),
                         SIMDE_FLOAT32_C(    722.85), SIMDE_FLOAT32_C(    781.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -446.98), SIMDE_FLOAT32_C( 129422.58),
                         SIMDE_FLOAT32_C(   -987.97), SIMDE_FLOAT32_C(   -625.94),
                         SIMDE_FLOAT32_C( -60213.79), SIMDE_FLOAT32_C( -15867.97),
                         SIMDE_FLOAT32_C(   1023.98), SIMDE_FLOAT32_C(    815.93)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -789.64), SIMDE_FLOAT32_C(    957.16),
                         SIMDE_FLOAT32_C(   -431.62), SIMDE_FLOAT32_C(    527.46),
                         SIMDE_FLOAT32_C(   -345.54), SIMDE_FLOAT32_C(   -528.90),
                         SIMDE_FLOAT32_C(   -257.76), SIMDE_FLOAT32_C(    194.98)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    966.68), SIMDE_FLOAT32_C(    513.70),
                         SIMDE_FLOAT32_C(    151.32), SIMDE_FLOAT32_C(   -424.41),
                         SIMDE_FLOAT32_C(   -411.73), SIMDE_FLOAT32_C(    846.41),
                         SIMDE_FLOAT32_C(    151.87), SIMDE_FLOAT32_C(   -542.65)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -983.69), SIMDE_FLOAT32_C(    957.73),
                         SIMDE_FLOAT32_C(   -431.75), SIMDE_FLOAT32_C(-110586.96),
                         SIMDE_FLOAT32_C(   -475.73), SIMDE_FLOAT32_C(   -862.93),
                         SIMDE_FLOAT32_C(   -304.00), SIMDE_FLOAT32_C( -51195.98)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -998.71), SIMDE_FLOAT32_C(   -667.81),
                         SIMDE_FLOAT32_C(     67.10), SIMDE_FLOAT32_C(   -760.87),
                         SIMDE_FLOAT32_C(   -217.54), SIMDE_FLOAT32_C(    503.65),
                         SIMDE_FLOAT32_C(    247.04), SIMDE_FLOAT32_C(    844.19)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    661.94), SIMDE_FLOAT32_C(   -209.04),
                         SIMDE_FLOAT32_C(    -75.64), SIMDE_FLOAT32_C(   -274.76),
                         SIMDE_FLOAT32_C(   -442.04), SIMDE_FLOAT32_C(   -562.29),
                         SIMDE_FLOAT32_C(   -151.20), SIMDE_FLOAT32_C(    897.08)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -1015.96), SIMDE_FLOAT32_C( -63484.00),
                         SIMDE_FLOAT32_C(    -75.73), SIMDE_FLOAT32_C( -98031.86),
                         SIMDE_FLOAT32_C(   -443.12), SIMDE_FLOAT32_C(-130983.49),
                         SIMDE_FLOAT32_C(   -247.23), SIMDE_FLOAT32_C(    973.21)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    413.34), SIMDE_FLOAT32_C(    969.02),
                         SIMDE_FLOAT32_C(   -337.47), SIMDE_FLOAT32_C(   -324.75),
                         SIMDE_FLOAT32_C(   -193.88), SIMDE_FLOAT32_C(   -534.97),
                         SIMDE_FLOAT32_C(    873.51), SIMDE_FLOAT32_C(   -141.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -783.17), SIMDE_FLOAT32_C(    718.95),
                         SIMDE_FLOAT32_C(    707.27), SIMDE_FLOAT32_C(   -573.61),
                         SIMDE_FLOAT32_C(   -268.73), SIMDE_FLOAT32_C(    245.35),
                         SIMDE_FLOAT32_C(    309.36), SIMDE_FLOAT32_C(   -248.32)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-106455.79), SIMDE_FLOAT32_C(    975.97),
                         SIMDE_FLOAT32_C( -94714.82), SIMDE_FLOAT32_C( -89806.08),
                         SIMDE_FLOAT32_C(   -399.98), SIMDE_FLOAT32_C( -62975.62),
                         SIMDE_FLOAT32_C( 112093.41), SIMDE_FLOAT32_C(   -253.95)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -788.80), SIMDE_FLOAT32_C(   -153.54),
                         SIMDE_FLOAT32_C(    281.95), SIMDE_FLOAT32_C(    256.34),
                         SIMDE_FLOAT32_C(   -635.81), SIMDE_FLOAT32_C(   -147.12),
                         SIMDE_FLOAT32_C(   -744.53), SIMDE_FLOAT32_C(    799.41)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(      2.25), SIMDE_FLOAT32_C(    -53.24),
                         SIMDE_FLOAT32_C(    690.38), SIMDE_FLOAT32_C(    776.59),
                         SIMDE_FLOAT32_C(   -713.17), SIMDE_FLOAT32_C(   -856.98),
                         SIMDE_FLOAT32_C(   -302.74), SIMDE_FLOAT32_C(    409.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -852.80), SIMDE_FLOAT32_C(   -222.00),
                         SIMDE_FLOAT32_C(  88563.70), SIMDE_FLOAT32_C(  99423.55),
                         SIMDE_FLOAT32_C(   -763.94), SIMDE_FLOAT32_C( -55102.72),
                         SIMDE_FLOAT32_C( -98047.97), SIMDE_FLOAT32_C( 106487.99)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -404.76), SIMDE_FLOAT32_C(   -875.24),
                         SIMDE_FLOAT32_C(    822.92), SIMDE_FLOAT32_C(    409.42),
                         SIMDE_FLOAT32_C(    144.27), SIMDE_FLOAT32_C(    260.67),
                         SIMDE_FLOAT32_C(    383.19), SIMDE_FLOAT32_C(    173.56)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -913.39), SIMDE_FLOAT32_C(   -747.11),
                         SIMDE_FLOAT32_C(    262.13), SIMDE_FLOAT32_C(    535.89),
                         SIMDE_FLOAT32_C(   -513.17), SIMDE_FLOAT32_C(    945.43),
                         SIMDE_FLOAT32_C(    473.23), SIMDE_FLOAT32_C(    594.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-122099.98), SIMDE_FLOAT32_C(  -1003.24),
                         SIMDE_FLOAT32_C( 106357.79), SIMDE_FLOAT32_C( 105467.93),
                         SIMDE_FLOAT32_C( -36944.00), SIMDE_FLOAT32_C( 122047.55),
                         SIMDE_FLOAT32_C(    511.23), SIMDE_FLOAT32_C(  48543.87)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    255.64), SIMDE_FLOAT32_C(    352.54),
                         SIMDE_FLOAT32_C(    905.17), SIMDE_FLOAT32_C(    -97.04),
                         SIMDE_FLOAT32_C(    635.19), SIMDE_FLOAT32_C(   -653.37),
                         SIMDE_FLOAT32_C(    871.87), SIMDE_FLOAT32_C(   -471.42)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -534.86), SIMDE_FLOAT32_C(     20.68),
                         SIMDE_FLOAT32_C(    963.33), SIMDE_FLOAT32_C(   -431.12),
                         SIMDE_FLOAT32_C(    199.08), SIMDE_FLOAT32_C(    684.85),
                         SIMDE_FLOAT32_C(   -893.07), SIMDE_FLOAT32_C(   -817.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -65463.87), SIMDE_FLOAT32_C(    362.92),
                         SIMDE_FLOAT32_C(    971.50), SIMDE_FLOAT32_C(   -431.25),
                         SIMDE_FLOAT32_C(  57308.48), SIMDE_FLOAT32_C(   -685.87),
                         SIMDE_FLOAT32_C(   -895.87), SIMDE_FLOAT32_C(-122879.96)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_or_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_or_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[10] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -749.97), SIMDE_FLOAT64_C(    552.38),
                         SIMDE_FLOAT64_C(   -988.63), SIMDE_FLOAT64_C(    297.73)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    629.11), SIMDE_FLOAT64_C(    -50.38),
                         SIMDE_FLOAT64_C(    172.77), SIMDE_FLOAT64_C(    886.21)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -765.99), SIMDE_FLOAT64_C( -13031.34),
                         SIMDE_FLOAT64_C( -65517.37), SIMDE_FLOAT64_C( 113594.88)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    352.41), SIMDE_FLOAT64_C(    951.15),
                         SIMDE_FLOAT64_C(   -545.01), SIMDE_FLOAT64_C(   -446.23)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -465.63), SIMDE_FLOAT64_C(   -877.18),
                         SIMDE_FLOAT64_C(   -373.85), SIMDE_FLOAT64_C(    233.07)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -497.91), SIMDE_FLOAT64_C(  -1023.18),
                         SIMDE_FLOAT64_C( -95705.87), SIMDE_FLOAT64_C(   -510.23)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    902.57), SIMDE_FLOAT64_C(     -4.90),
                         SIMDE_FLOAT64_C(   -482.16), SIMDE_FLOAT64_C(   -715.39)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    399.18), SIMDE_FLOAT64_C(    905.02),
                         SIMDE_FLOAT64_C(    -71.87), SIMDE_FLOAT64_C(    880.03)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 118638.96), SIMDE_FLOAT64_C(  -2038.43),
                         SIMDE_FLOAT64_C(   -511.48), SIMDE_FLOAT64_C(  -1019.41)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    419.67), SIMDE_FLOAT64_C(    255.48),
                         SIMDE_FLOAT64_C(     -1.01), SIMDE_FLOAT64_C(   -549.02)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    603.93), SIMDE_FLOAT64_C(   -234.00),
                         SIMDE_FLOAT64_C(    215.77), SIMDE_FLOAT64_C(   -307.55)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 110591.56), SIMDE_FLOAT64_C(   -255.48),
                         SIMDE_FLOAT64_C(      -NAN), SIMDE_FLOAT64_C( -78734.81)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    551.36), SIMDE_FLOAT64_C(     69.71),
                         SIMDE_FLOAT64_C(    781.27), SIMDE_FLOAT64_C(    236.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    631.98), SIMDE_FLOAT64_C(    991.18),
                         SIMDE_FLOAT64_C(     73.59), SIMDE_FLOAT64_C(    439.81)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    632.00), SIMDE_FLOAT64_C(  32757.76),
                         SIMDE_FLOAT64_C(  27071.67), SIMDE_FLOAT64_C(    511.87)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    -68.23), SIMDE_FLOAT64_C(   -127.06),
                         SIMDE_FLOAT64_C(   -588.36), SIMDE_FLOAT64_C(    -86.01)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -530.51), SIMDE_FLOAT64_C(    695.00),
                         SIMDE_FLOAT64_C(   -293.00), SIMDE_FLOAT64_C(   -446.36)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -18042.95), SIMDE_FLOAT64_C( -32751.36),
                         SIMDE_FLOAT64_C( -75566.08), SIMDE_FLOAT64_C(   -510.37)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -635.77), SIMDE_FLOAT64_C(    797.50),
                         SIMDE_FLOAT64_C(    -78.02), SIMDE_FLOAT64_C(   -343.97)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    764.42), SIMDE_FLOAT64_C(    779.42),
                         SIMDE_FLOAT64_C(    298.40), SIMDE_FLOAT64_C(    -93.49)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -767.94), SIMDE_FLOAT64_C(    799.92),
                         SIMDE_FLOAT64_C(   -314.46), SIMDE_FLOAT64_C(   -375.99)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    989.81), SIMDE_FLOAT64_C(    815.74),
                         SIMDE_FLOAT64_C(     -7.28), SIMDE_FLOAT64_C(    -18.98)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    635.70), SIMDE_FLOAT64_C(    681.36),
                         SIMDE_FLOAT64_C(    492.60), SIMDE_FLOAT64_C(   -591.68)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   1024.00), SIMDE_FLOAT64_C(    943.99),
                         SIMDE_FLOAT64_C(   -509.98), SIMDE_FLOAT64_C(  -4863.94)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -501.96), SIMDE_FLOAT64_C(   -333.26),
                         SIMDE_FLOAT64_C(    543.64), SIMDE_FLOAT64_C(    179.97)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    409.60), SIMDE_FLOAT64_C(     98.49),
                         SIMDE_FLOAT64_C(   -370.88), SIMDE_FLOAT64_C(   -810.16)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -509.99), SIMDE_FLOAT64_C(   -461.97),
                         SIMDE_FLOAT64_C( -98289.94), SIMDE_FLOAT64_C( -64506.49)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -107.11), SIMDE_FLOAT64_C(   -409.28),
                         SIMDE_FLOAT64_C(    656.78), SIMDE_FLOAT64_C(   -826.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -961.17), SIMDE_FLOAT64_C(   -674.29),
                         SIMDE_FLOAT64_C(    864.67), SIMDE_FLOAT64_C(   -130.54)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -31549.47), SIMDE_FLOAT64_C(-121191.75),
                         SIMDE_FLOAT64_C(   1008.94), SIMDE_FLOAT64_C( -52911.49)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_or_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_permute_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    struct {
      simde__m256 a;
      simde__m256 r;
    } p[8];
  } test_vec[1] = {
    {
      {
        { simde_mm256_set_ps(SIMDE_FLOAT32_C( -139.04), SIMDE_FLOAT32_C( -911.51),
                             SIMDE_FLOAT32_C(  580.20), SIMDE_FLOAT32_C(  982.03),
                             SIMDE_FLOAT32_C( -878.62), SIMDE_FLOAT32_C( -797.57),
                             SIMDE_FLOAT32_C( -426.64), SIMDE_FLOAT32_C( -818.52)),
          simde_mm256_set_ps(SIMDE_FLOAT32_C(  982.03), SIMDE_FLOAT32_C(  982.03),
                             SIMDE_FLOAT32_C(  982.03), SIMDE_FLOAT32_C(  982.03),
                             SIMDE_FLOAT32_C( -818.52), SIMDE_FLOAT32_C( -818.52),
                             SIMDE_FLOAT32_C( -818.52), SIMDE_FLOAT32_C( -818.52)) },
        { simde_mm256_set_ps(SIMDE_FLOAT32_C( -946.18), SIMDE_FLOAT32_C(  580.43),
                             SIMDE_FLOAT32_C(  276.12), SIMDE_FLOAT32_C(  862.54),
                             SIMDE_FLOAT32_C(  664.35), SIMDE_FLOAT32_C(  162.22),
                             SIMDE_FLOAT32_C(  234.37), SIMDE_FLOAT32_C(  188.86)),
          simde_mm256_set_ps(SIMDE_FLOAT32_C(  862.54), SIMDE_FLOAT32_C(  862.54),
                             SIMDE_FLOAT32_C(  862.54), SIMDE_FLOAT32_C(  276.12),
                             SIMDE_FLOAT32_C(  188.86), SIMDE_FLOAT32_C(  188.86),
                             SIMDE_FLOAT32_C(  188.86), SIMDE_FLOAT32_C(  234.37)) },
        { simde_mm256_set_ps(SIMDE_FLOAT32_C( -799.19), SIMDE_FLOAT32_C( -835.77),
                             SIMDE_FLOAT32_C( -716.61), SIMDE_FLOAT32_C(  614.58),
                             SIMDE_FLOAT32_C(  366.48), SIMDE_FLOAT32_C(  294.53),
                             SIMDE_FLOAT32_C( -368.14), SIMDE_FLOAT32_C(  638.90)),
          simde_mm256_set_ps(SIMDE_FLOAT32_C(  614.58), SIMDE_FLOAT32_C(  614.58),
                             SIMDE_FLOAT32_C(  614.58), SIMDE_FLOAT32_C( -835.77),
                             SIMDE_FLOAT32_C(  638.90), SIMDE_FLOAT32_C(  638.90),
                             SIMDE_FLOAT32_C(  638.90), SIMDE_FLOAT32_C(  294.53)) },
        { simde_mm256_set_ps(SIMDE_FLOAT32_C(  141.00), SIMDE_FLOAT32_C( -110.45),
                             SIMDE_FLOAT32_C( -302.60), SIMDE_FLOAT32_C( -332.94),
                             SIMDE_FLOAT32_C(  188.73), SIMDE_FLOAT32_C(  551.54),
                             SIMDE_FLOAT32_C( -580.84), SIMDE_FLOAT32_C(  854.95)),
          simde_mm256_set_ps(SIMDE_FLOAT32_C( -332.94), SIMDE_FLOAT32_C( -332.94),
                             SIMDE_FLOAT32_C( -332.94), SIMDE_FLOAT32_C(  141.00),
                             SIMDE_FLOAT32_C(  854.95), SIMDE_FLOAT32_C(  854.95),
                             SIMDE_FLOAT32_C(  854.95), SIMDE_FLOAT32_C(  188.73)) },
        { simde_mm256_set_ps(SIMDE_FLOAT32_C(  655.95), SIMDE_FLOAT32_C( -740.30),
                             SIMDE_FLOAT32_C( -946.00), SIMDE_FLOAT32_C( -434.04),
                             SIMDE_FLOAT32_C(   67.66), SIMDE_FLOAT32_C(  990.02),
                             SIMDE_FLOAT32_C(  889.36), SIMDE_FLOAT32_C(  470.48)),
          simde_mm256_set_ps(SIMDE_FLOAT32_C( -434.04), SIMDE_FLOAT32_C( -434.04),
                             SIMDE_FLOAT32_C( -946.00), SIMDE_FLOAT32_C( -434.04),
                             SIMDE_FLOAT32_C(  470.48), SIMDE_FLOAT32_C(  470.48),
                             SIMDE_FLOAT32_C(  889.36), SIMDE_FLOAT32_C(  470.48)) },
        { simde_mm256_set_ps(SIMDE_FLOAT32_C(  184.64), SIMDE_FLOAT32_C(  689.89),
                             SIMDE_FLOAT32_C(   66.41), SIMDE_FLOAT32_C(  657.41),
                             SIMDE_FLOAT32_C( -642.74), SIMDE_FLOAT32_C(  674.83),
                             SIMDE_FLOAT32_C( -458.59), SIMDE_FLOAT32_C( -735.59)),
          simde_mm256_set_ps(SIMDE_FLOAT32_C(  657.41), SIMDE_FLOAT32_C(  657.41),
                             SIMDE_FLOAT32_C(   66.41), SIMDE_FLOAT32_C(   66.41),
                             SIMDE_FLOAT32_C( -735.59), SIMDE_FLOAT32_C( -735.59),
                             SIMDE_FLOAT32_C( -458.59), SIMDE_FLOAT32_C( -458.59)) },
        { simde_mm256_set_ps(SIMDE_FLOAT32_C( -810.48), SIMDE_FLOAT32_C( -796.84),
                             SIMDE_FLOAT32_C(  173.69), SIMDE_FLOAT32_C(  -58.65),
                             SIMDE_FLOAT32_C( -873.61), SIMDE_FLOAT32_C( -813.18),
                             SIMDE_FLOAT32_C( -876.21), SIMDE_FLOAT32_C( -105.85)),
          simde_mm256_set_ps(SIMDE_FLOAT32_C(  -58.65), SIMDE_FLOAT32_C(  -58.65),
                             SIMDE_FLOAT32_C(  173.69), SIMDE_FLOAT32_C( -796.84),
                             SIMDE_FLOAT32_C( -105.85), SIMDE_FLOAT32_C( -105.85),
                             SIMDE_FLOAT32_C( -876.21), SIMDE_FLOAT32_C( -813.18)) },
        { simde_mm256_set_ps(SIMDE_FLOAT32_C( -653.04), SIMDE_FLOAT32_C( -205.53),
                             SIMDE_FLOAT32_C(  -47.21), SIMDE_FLOAT32_C( -850.03),
                             SIMDE_FLOAT32_C( -120.73), SIMDE_FLOAT32_C( -663.03),
                             SIMDE_FLOAT32_C(  803.42), SIMDE_FLOAT32_C(  391.07)),
          simde_mm256_set_ps(SIMDE_FLOAT32_C( -850.03), SIMDE_FLOAT32_C( -850.03),
                             SIMDE_FLOAT32_C(  -47.21), SIMDE_FLOAT32_C( -653.04),
                             SIMDE_FLOAT32_C(  391.07), SIMDE_FLOAT32_C(  391.07),
                             SIMDE_FLOAT32_C(  803.42), SIMDE_FLOAT32_C( -120.73)) },
      },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r;

    r = simde_mm256_permute_ps(test_vec[i].p[0].a, 0);
    simde_assert_m256_f32_equal(r, test_vec[i].p[0].r, 1);

    r = simde_mm256_permute_ps(test_vec[i].p[1].a, 1);
    simde_assert_m256_f32_equal(r, test_vec[i].p[1].r, 1);

    r = simde_mm256_permute_ps(test_vec[i].p[2].a, 2);
    simde_assert_m256_f32_equal(r, test_vec[i].p[2].r, 1);

    r = simde_mm256_permute_ps(test_vec[i].p[3].a, 3);
    simde_assert_m256_f32_equal(r, test_vec[i].p[3].r, 1);

    r = simde_mm256_permute_ps(test_vec[i].p[4].a, 4);
    simde_assert_m256_f32_equal(r, test_vec[i].p[4].r, 1);

    r = simde_mm256_permute_ps(test_vec[i].p[5].a, 5);
    simde_assert_m256_f32_equal(r, test_vec[i].p[5].r, 1);

    r = simde_mm256_permute_ps(test_vec[i].p[6].a, 6);
    simde_assert_m256_f32_equal(r, test_vec[i].p[6].r, 1);

    r = simde_mm256_permute_ps(test_vec[i].p[7].a, 7);
    simde_assert_m256_f32_equal(r, test_vec[i].p[7].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_permute_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    struct {
      simde__m128d a;
      simde__m128d r;
    } p[4];
  } test_vec[8] = {
    {
      {
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -586.66), SIMDE_FLOAT64_C(  759.07)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  759.07), SIMDE_FLOAT64_C(  759.07)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  312.86), SIMDE_FLOAT64_C(  489.25)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  489.25), SIMDE_FLOAT64_C(  312.86)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  510.93), SIMDE_FLOAT64_C( -731.36)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  510.93), SIMDE_FLOAT64_C( -731.36)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  211.69), SIMDE_FLOAT64_C(  302.00)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  211.69), SIMDE_FLOAT64_C(  211.69)) },
      },
    },
    {
      {
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  878.46), SIMDE_FLOAT64_C(  679.15)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  679.15), SIMDE_FLOAT64_C(  679.15)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -990.20), SIMDE_FLOAT64_C( -630.61)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -630.61), SIMDE_FLOAT64_C( -990.20)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  471.54), SIMDE_FLOAT64_C( -307.27)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  471.54), SIMDE_FLOAT64_C( -307.27)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  625.19), SIMDE_FLOAT64_C(  623.51)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  625.19), SIMDE_FLOAT64_C(  625.19)) },
      },
    },
    {
      {
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  637.56), SIMDE_FLOAT64_C(  480.86)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  480.86), SIMDE_FLOAT64_C(  480.86)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -358.97), SIMDE_FLOAT64_C( -958.25)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -958.25), SIMDE_FLOAT64_C( -358.97)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  867.67), SIMDE_FLOAT64_C(  -39.52)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  867.67), SIMDE_FLOAT64_C(  -39.52)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  596.21), SIMDE_FLOAT64_C(  558.65)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  596.21), SIMDE_FLOAT64_C(  596.21)) },
      },
    },
    {
      {
        { simde_mm_set_pd(SIMDE_FLOAT64_C(   32.94), SIMDE_FLOAT64_C( -306.71)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -306.71), SIMDE_FLOAT64_C( -306.71)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  881.79), SIMDE_FLOAT64_C(  737.35)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  737.35), SIMDE_FLOAT64_C(  881.79)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  857.28), SIMDE_FLOAT64_C(  640.79)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  857.28), SIMDE_FLOAT64_C(  640.79)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  529.31), SIMDE_FLOAT64_C(  660.42)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  529.31), SIMDE_FLOAT64_C(  529.31)) },
      },
    },
    {
      {
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -645.32), SIMDE_FLOAT64_C( -500.25)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -500.25), SIMDE_FLOAT64_C( -500.25)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -862.75), SIMDE_FLOAT64_C( -773.36)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -773.36), SIMDE_FLOAT64_C( -862.75)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  795.76), SIMDE_FLOAT64_C(  320.59)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  795.76), SIMDE_FLOAT64_C(  320.59)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -749.80), SIMDE_FLOAT64_C(  899.97)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -749.80), SIMDE_FLOAT64_C( -749.80)) },
      },
    },
    {
      {
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  711.35), SIMDE_FLOAT64_C(  304.45)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  304.45), SIMDE_FLOAT64_C(  304.45)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  -92.64), SIMDE_FLOAT64_C(   45.68)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(   45.68), SIMDE_FLOAT64_C(  -92.64)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  261.59), SIMDE_FLOAT64_C(  207.13)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  261.59), SIMDE_FLOAT64_C(  207.13)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -540.32), SIMDE_FLOAT64_C(  -11.20)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -540.32), SIMDE_FLOAT64_C( -540.32)) },
      },
    },
    {
      {
        { simde_mm_set_pd(SIMDE_FLOAT64_C(   11.20), SIMDE_FLOAT64_C(  175.87)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  175.87), SIMDE_FLOAT64_C(  175.87)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  274.15), SIMDE_FLOAT64_C(  152.30)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  152.30), SIMDE_FLOAT64_C(  274.15)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  673.19), SIMDE_FLOAT64_C(  979.94)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  673.19), SIMDE_FLOAT64_C(  979.94)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(   36.65), SIMDE_FLOAT64_C( -391.85)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(   36.65), SIMDE_FLOAT64_C(   36.65)) },
      },
    },
    {
      {
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -950.12), SIMDE_FLOAT64_C( -979.88)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -979.88), SIMDE_FLOAT64_C( -979.88)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  910.59), SIMDE_FLOAT64_C(  380.41)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  380.41), SIMDE_FLOAT64_C(  910.59)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -731.74), SIMDE_FLOAT64_C(  314.11)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -731.74), SIMDE_FLOAT64_C(  314.11)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -794.00), SIMDE_FLOAT64_C( -659.77)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -794.00), SIMDE_FLOAT64_C( -794.00)) },
      },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r;

    r = simde_mm_permute_pd(test_vec[i].p[0].a, 0);
    simde_assert_m128d_f64_equal(r, test_vec[i].p[0].r, 1);

    r = simde_mm_permute_pd(test_vec[i].p[1].a, 1);
    simde_assert_m128d_f64_equal(r, test_vec[i].p[1].r, 1);

    r = simde_mm_permute_pd(test_vec[i].p[2].a, 2);
    simde_assert_m128d_f64_equal(r, test_vec[i].p[2].r, 1);

    r = simde_mm_permute_pd(test_vec[i].p[3].a, 3);
    simde_assert_m128d_f64_equal(r, test_vec[i].p[3].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_permute_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    struct {
      simde__m128 a;
      simde__m128 r;
    } p[256];
  } test_vec[1] = {
    {
      {
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -670.73), SIMDE_FLOAT32_C(  982.76), SIMDE_FLOAT32_C(  -52.44), SIMDE_FLOAT32_C( -261.37)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -261.37), SIMDE_FLOAT32_C( -261.37), SIMDE_FLOAT32_C( -261.37), SIMDE_FLOAT32_C( -261.37)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  523.60), SIMDE_FLOAT32_C(  950.62), SIMDE_FLOAT32_C(  696.12), SIMDE_FLOAT32_C( -792.16)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -792.16), SIMDE_FLOAT32_C( -792.16), SIMDE_FLOAT32_C( -792.16), SIMDE_FLOAT32_C(  696.12)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(   56.27), SIMDE_FLOAT32_C(  300.34), SIMDE_FLOAT32_C( -482.76), SIMDE_FLOAT32_C( -471.33)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -471.33), SIMDE_FLOAT32_C( -471.33), SIMDE_FLOAT32_C( -471.33), SIMDE_FLOAT32_C(  300.34)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  638.39), SIMDE_FLOAT32_C( -877.63), SIMDE_FLOAT32_C( -594.24), SIMDE_FLOAT32_C(  886.61)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  886.61), SIMDE_FLOAT32_C(  886.61), SIMDE_FLOAT32_C(  886.61), SIMDE_FLOAT32_C(  638.39)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -842.05), SIMDE_FLOAT32_C(  731.36), SIMDE_FLOAT32_C(  880.68), SIMDE_FLOAT32_C( -218.07)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -218.07), SIMDE_FLOAT32_C( -218.07), SIMDE_FLOAT32_C(  880.68), SIMDE_FLOAT32_C( -218.07)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -852.17), SIMDE_FLOAT32_C(    9.24), SIMDE_FLOAT32_C(  134.24), SIMDE_FLOAT32_C(  876.46)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  876.46), SIMDE_FLOAT32_C(  876.46), SIMDE_FLOAT32_C(  134.24), SIMDE_FLOAT32_C(  134.24)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -948.50), SIMDE_FLOAT32_C( -338.31), SIMDE_FLOAT32_C( -882.02), SIMDE_FLOAT32_C( -621.13)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -621.13), SIMDE_FLOAT32_C( -621.13), SIMDE_FLOAT32_C( -882.02), SIMDE_FLOAT32_C( -338.31)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  686.03), SIMDE_FLOAT32_C( -933.82), SIMDE_FLOAT32_C( -444.55), SIMDE_FLOAT32_C(  923.11)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  923.11), SIMDE_FLOAT32_C(  923.11), SIMDE_FLOAT32_C( -444.55), SIMDE_FLOAT32_C(  686.03)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  594.47), SIMDE_FLOAT32_C(   48.28), SIMDE_FLOAT32_C(  121.57), SIMDE_FLOAT32_C(  562.11)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  562.11), SIMDE_FLOAT32_C(  562.11), SIMDE_FLOAT32_C(   48.28), SIMDE_FLOAT32_C(  562.11)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  889.73), SIMDE_FLOAT32_C( -278.33), SIMDE_FLOAT32_C( -374.28), SIMDE_FLOAT32_C(  556.56)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  556.56), SIMDE_FLOAT32_C(  556.56), SIMDE_FLOAT32_C( -278.33), SIMDE_FLOAT32_C( -374.28)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -373.76), SIMDE_FLOAT32_C( -476.30), SIMDE_FLOAT32_C(  567.81), SIMDE_FLOAT32_C(  108.53)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  108.53), SIMDE_FLOAT32_C(  108.53), SIMDE_FLOAT32_C( -476.30), SIMDE_FLOAT32_C( -476.30)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -651.04), SIMDE_FLOAT32_C( -341.02), SIMDE_FLOAT32_C( -145.70), SIMDE_FLOAT32_C(  881.66)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  881.66), SIMDE_FLOAT32_C(  881.66), SIMDE_FLOAT32_C( -341.02), SIMDE_FLOAT32_C( -651.04)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(   51.28), SIMDE_FLOAT32_C(    9.96), SIMDE_FLOAT32_C(  200.56), SIMDE_FLOAT32_C( -857.80)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -857.80), SIMDE_FLOAT32_C( -857.80), SIMDE_FLOAT32_C(   51.28), SIMDE_FLOAT32_C( -857.80)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -873.93), SIMDE_FLOAT32_C(  290.78), SIMDE_FLOAT32_C( -219.88), SIMDE_FLOAT32_C( -453.47)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -453.47), SIMDE_FLOAT32_C( -453.47), SIMDE_FLOAT32_C( -873.93), SIMDE_FLOAT32_C( -219.88)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(   48.88), SIMDE_FLOAT32_C(  -88.66), SIMDE_FLOAT32_C( -661.28), SIMDE_FLOAT32_C(  627.05)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  627.05), SIMDE_FLOAT32_C(  627.05), SIMDE_FLOAT32_C(   48.88), SIMDE_FLOAT32_C(  -88.66)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -922.80), SIMDE_FLOAT32_C(  887.80), SIMDE_FLOAT32_C(  374.26), SIMDE_FLOAT32_C(  491.34)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  491.34), SIMDE_FLOAT32_C(  491.34), SIMDE_FLOAT32_C( -922.80), SIMDE_FLOAT32_C( -922.80)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -671.08), SIMDE_FLOAT32_C( -106.41), SIMDE_FLOAT32_C( -595.80), SIMDE_FLOAT32_C(  -40.41)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  -40.41), SIMDE_FLOAT32_C( -595.80), SIMDE_FLOAT32_C(  -40.41), SIMDE_FLOAT32_C(  -40.41)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  698.03), SIMDE_FLOAT32_C( -461.17), SIMDE_FLOAT32_C(  -38.27), SIMDE_FLOAT32_C(  853.51)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  853.51), SIMDE_FLOAT32_C(  -38.27), SIMDE_FLOAT32_C(  853.51), SIMDE_FLOAT32_C(  -38.27)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -565.58), SIMDE_FLOAT32_C(  391.09), SIMDE_FLOAT32_C( -326.97), SIMDE_FLOAT32_C( -674.80)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -674.80), SIMDE_FLOAT32_C( -326.97), SIMDE_FLOAT32_C( -674.80), SIMDE_FLOAT32_C(  391.09)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -392.51), SIMDE_FLOAT32_C(  968.71), SIMDE_FLOAT32_C( -843.92), SIMDE_FLOAT32_C(  318.74)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  318.74), SIMDE_FLOAT32_C( -843.92), SIMDE_FLOAT32_C(  318.74), SIMDE_FLOAT32_C( -392.51)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  404.46), SIMDE_FLOAT32_C(  801.15), SIMDE_FLOAT32_C( -819.14), SIMDE_FLOAT32_C(  690.57)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  690.57), SIMDE_FLOAT32_C( -819.14), SIMDE_FLOAT32_C( -819.14), SIMDE_FLOAT32_C(  690.57)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  479.03), SIMDE_FLOAT32_C(  503.89), SIMDE_FLOAT32_C(  752.88), SIMDE_FLOAT32_C(  -98.54)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  -98.54), SIMDE_FLOAT32_C(  752.88), SIMDE_FLOAT32_C(  752.88), SIMDE_FLOAT32_C(  752.88)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -327.94), SIMDE_FLOAT32_C( -117.29), SIMDE_FLOAT32_C(  626.95), SIMDE_FLOAT32_C( -690.64)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -690.64), SIMDE_FLOAT32_C(  626.95), SIMDE_FLOAT32_C(  626.95), SIMDE_FLOAT32_C( -117.29)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -655.08), SIMDE_FLOAT32_C(  787.15), SIMDE_FLOAT32_C( -816.54), SIMDE_FLOAT32_C(  -33.14)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  -33.14), SIMDE_FLOAT32_C( -816.54), SIMDE_FLOAT32_C( -816.54), SIMDE_FLOAT32_C( -655.08)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  547.28), SIMDE_FLOAT32_C( -306.09), SIMDE_FLOAT32_C(  103.62), SIMDE_FLOAT32_C( -271.00)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -271.00), SIMDE_FLOAT32_C(  103.62), SIMDE_FLOAT32_C( -306.09), SIMDE_FLOAT32_C( -271.00)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -545.68), SIMDE_FLOAT32_C( -597.67), SIMDE_FLOAT32_C(  508.70), SIMDE_FLOAT32_C(  926.11)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  926.11), SIMDE_FLOAT32_C(  508.70), SIMDE_FLOAT32_C( -597.67), SIMDE_FLOAT32_C(  508.70)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -425.20), SIMDE_FLOAT32_C( -880.63), SIMDE_FLOAT32_C(  308.27), SIMDE_FLOAT32_C( -587.43)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -587.43), SIMDE_FLOAT32_C(  308.27), SIMDE_FLOAT32_C( -880.63), SIMDE_FLOAT32_C( -880.63)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -224.05), SIMDE_FLOAT32_C( -369.78), SIMDE_FLOAT32_C(  -99.34), SIMDE_FLOAT32_C(  170.50)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  170.50), SIMDE_FLOAT32_C(  -99.34), SIMDE_FLOAT32_C( -369.78), SIMDE_FLOAT32_C( -224.05)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  264.86), SIMDE_FLOAT32_C(  816.56), SIMDE_FLOAT32_C( -941.64), SIMDE_FLOAT32_C( -851.73)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -851.73), SIMDE_FLOAT32_C( -941.64), SIMDE_FLOAT32_C(  264.86), SIMDE_FLOAT32_C( -851.73)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -279.10), SIMDE_FLOAT32_C( -427.92), SIMDE_FLOAT32_C(  570.65), SIMDE_FLOAT32_C( -107.53)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -107.53), SIMDE_FLOAT32_C(  570.65), SIMDE_FLOAT32_C( -279.10), SIMDE_FLOAT32_C(  570.65)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -127.02), SIMDE_FLOAT32_C( -264.13), SIMDE_FLOAT32_C( -428.21), SIMDE_FLOAT32_C( -184.44)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -184.44), SIMDE_FLOAT32_C( -428.21), SIMDE_FLOAT32_C( -127.02), SIMDE_FLOAT32_C( -264.13)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -182.44), SIMDE_FLOAT32_C( -240.91), SIMDE_FLOAT32_C( -912.69), SIMDE_FLOAT32_C(  580.20)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  580.20), SIMDE_FLOAT32_C( -912.69), SIMDE_FLOAT32_C( -182.44), SIMDE_FLOAT32_C( -182.44)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  632.48), SIMDE_FLOAT32_C(  588.23), SIMDE_FLOAT32_C( -262.83), SIMDE_FLOAT32_C( -919.34)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -919.34), SIMDE_FLOAT32_C(  588.23), SIMDE_FLOAT32_C( -919.34), SIMDE_FLOAT32_C( -919.34)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  830.18), SIMDE_FLOAT32_C(  542.80), SIMDE_FLOAT32_C( -551.51), SIMDE_FLOAT32_C( -827.73)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -827.73), SIMDE_FLOAT32_C(  542.80), SIMDE_FLOAT32_C( -827.73), SIMDE_FLOAT32_C( -551.51)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  819.58), SIMDE_FLOAT32_C( -763.72), SIMDE_FLOAT32_C(  702.18), SIMDE_FLOAT32_C(  261.04)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  261.04), SIMDE_FLOAT32_C( -763.72), SIMDE_FLOAT32_C(  261.04), SIMDE_FLOAT32_C( -763.72)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -440.21), SIMDE_FLOAT32_C( -342.25), SIMDE_FLOAT32_C(    5.96), SIMDE_FLOAT32_C(  919.61)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  919.61), SIMDE_FLOAT32_C( -342.25), SIMDE_FLOAT32_C(  919.61), SIMDE_FLOAT32_C( -440.21)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -832.71), SIMDE_FLOAT32_C( -416.87), SIMDE_FLOAT32_C(  760.26), SIMDE_FLOAT32_C(   80.99)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(   80.99), SIMDE_FLOAT32_C( -416.87), SIMDE_FLOAT32_C(  760.26), SIMDE_FLOAT32_C(   80.99)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -684.76), SIMDE_FLOAT32_C(  -25.28), SIMDE_FLOAT32_C(  476.65), SIMDE_FLOAT32_C(  243.62)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  243.62), SIMDE_FLOAT32_C(  -25.28), SIMDE_FLOAT32_C(  476.65), SIMDE_FLOAT32_C(  476.65)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -803.52), SIMDE_FLOAT32_C(  465.28), SIMDE_FLOAT32_C(  542.51), SIMDE_FLOAT32_C(  722.68)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  722.68), SIMDE_FLOAT32_C(  465.28), SIMDE_FLOAT32_C(  542.51), SIMDE_FLOAT32_C(  465.28)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(   87.12), SIMDE_FLOAT32_C( -380.21), SIMDE_FLOAT32_C( -480.44), SIMDE_FLOAT32_C(  545.37)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  545.37), SIMDE_FLOAT32_C( -380.21), SIMDE_FLOAT32_C( -480.44), SIMDE_FLOAT32_C(   87.12)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -141.36), SIMDE_FLOAT32_C( -242.44), SIMDE_FLOAT32_C( -638.09), SIMDE_FLOAT32_C( -867.41)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -867.41), SIMDE_FLOAT32_C( -242.44), SIMDE_FLOAT32_C( -242.44), SIMDE_FLOAT32_C( -867.41)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  219.79), SIMDE_FLOAT32_C( -659.77), SIMDE_FLOAT32_C(  352.07), SIMDE_FLOAT32_C(  106.13)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  106.13), SIMDE_FLOAT32_C( -659.77), SIMDE_FLOAT32_C( -659.77), SIMDE_FLOAT32_C(  352.07)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -251.49), SIMDE_FLOAT32_C( -932.39), SIMDE_FLOAT32_C(  744.93), SIMDE_FLOAT32_C(  900.97)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  900.97), SIMDE_FLOAT32_C( -932.39), SIMDE_FLOAT32_C( -932.39), SIMDE_FLOAT32_C( -932.39)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  431.98), SIMDE_FLOAT32_C(  993.85), SIMDE_FLOAT32_C( -958.76), SIMDE_FLOAT32_C(  855.25)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  855.25), SIMDE_FLOAT32_C(  993.85), SIMDE_FLOAT32_C(  993.85), SIMDE_FLOAT32_C(  431.98)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -588.34), SIMDE_FLOAT32_C(  588.12), SIMDE_FLOAT32_C(  -75.55), SIMDE_FLOAT32_C( -372.67)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -372.67), SIMDE_FLOAT32_C(  588.12), SIMDE_FLOAT32_C( -588.34), SIMDE_FLOAT32_C( -372.67)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(   54.72), SIMDE_FLOAT32_C(  673.12), SIMDE_FLOAT32_C( -137.05), SIMDE_FLOAT32_C(  941.45)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  941.45), SIMDE_FLOAT32_C(  673.12), SIMDE_FLOAT32_C(   54.72), SIMDE_FLOAT32_C( -137.05)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -412.95), SIMDE_FLOAT32_C(  -52.99), SIMDE_FLOAT32_C(  967.59), SIMDE_FLOAT32_C( -912.89)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -912.89), SIMDE_FLOAT32_C(  -52.99), SIMDE_FLOAT32_C( -412.95), SIMDE_FLOAT32_C(  -52.99)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -317.23), SIMDE_FLOAT32_C( -204.98), SIMDE_FLOAT32_C(  201.85), SIMDE_FLOAT32_C(   62.03)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(   62.03), SIMDE_FLOAT32_C( -204.98), SIMDE_FLOAT32_C( -317.23), SIMDE_FLOAT32_C( -317.23)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -628.19), SIMDE_FLOAT32_C(  512.44), SIMDE_FLOAT32_C(   95.95), SIMDE_FLOAT32_C( -839.98)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -839.98), SIMDE_FLOAT32_C( -628.19), SIMDE_FLOAT32_C( -839.98), SIMDE_FLOAT32_C( -839.98)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -686.72), SIMDE_FLOAT32_C( -893.68), SIMDE_FLOAT32_C(  239.95), SIMDE_FLOAT32_C(  570.56)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  570.56), SIMDE_FLOAT32_C( -686.72), SIMDE_FLOAT32_C(  570.56), SIMDE_FLOAT32_C(  239.95)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -173.29), SIMDE_FLOAT32_C(  265.72), SIMDE_FLOAT32_C(  553.63), SIMDE_FLOAT32_C(  559.06)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  559.06), SIMDE_FLOAT32_C( -173.29), SIMDE_FLOAT32_C(  559.06), SIMDE_FLOAT32_C(  265.72)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -403.56), SIMDE_FLOAT32_C(  700.91), SIMDE_FLOAT32_C( -583.37), SIMDE_FLOAT32_C(  -25.08)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  -25.08), SIMDE_FLOAT32_C( -403.56), SIMDE_FLOAT32_C(  -25.08), SIMDE_FLOAT32_C( -403.56)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -373.18), SIMDE_FLOAT32_C(  313.23), SIMDE_FLOAT32_C(  560.38), SIMDE_FLOAT32_C(  513.58)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  513.58), SIMDE_FLOAT32_C( -373.18), SIMDE_FLOAT32_C(  560.38), SIMDE_FLOAT32_C(  513.58)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -796.47), SIMDE_FLOAT32_C( -443.81), SIMDE_FLOAT32_C( -714.51), SIMDE_FLOAT32_C( -698.06)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -698.06), SIMDE_FLOAT32_C( -796.47), SIMDE_FLOAT32_C( -714.51), SIMDE_FLOAT32_C( -714.51)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(   71.28), SIMDE_FLOAT32_C( -858.30), SIMDE_FLOAT32_C(  354.31), SIMDE_FLOAT32_C( -854.87)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -854.87), SIMDE_FLOAT32_C(   71.28), SIMDE_FLOAT32_C(  354.31), SIMDE_FLOAT32_C( -858.30)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -467.43), SIMDE_FLOAT32_C( -224.93), SIMDE_FLOAT32_C( -851.33), SIMDE_FLOAT32_C(   45.73)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(   45.73), SIMDE_FLOAT32_C( -467.43), SIMDE_FLOAT32_C( -851.33), SIMDE_FLOAT32_C( -467.43)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  -38.42), SIMDE_FLOAT32_C( -516.03), SIMDE_FLOAT32_C( -255.68), SIMDE_FLOAT32_C(  -45.92)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  -45.92), SIMDE_FLOAT32_C(  -38.42), SIMDE_FLOAT32_C( -516.03), SIMDE_FLOAT32_C(  -45.92)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -528.82), SIMDE_FLOAT32_C( -262.27), SIMDE_FLOAT32_C( -581.75), SIMDE_FLOAT32_C(  890.78)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  890.78), SIMDE_FLOAT32_C( -528.82), SIMDE_FLOAT32_C( -262.27), SIMDE_FLOAT32_C( -581.75)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(   47.79), SIMDE_FLOAT32_C(   64.24), SIMDE_FLOAT32_C(  756.42), SIMDE_FLOAT32_C( -198.35)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -198.35), SIMDE_FLOAT32_C(   47.79), SIMDE_FLOAT32_C(   64.24), SIMDE_FLOAT32_C(   64.24)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  -27.67), SIMDE_FLOAT32_C(  610.85), SIMDE_FLOAT32_C(  573.20), SIMDE_FLOAT32_C(  458.89)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  458.89), SIMDE_FLOAT32_C(  -27.67), SIMDE_FLOAT32_C(  610.85), SIMDE_FLOAT32_C(  -27.67)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -571.89), SIMDE_FLOAT32_C(  655.82), SIMDE_FLOAT32_C( -740.91), SIMDE_FLOAT32_C(  668.79)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  668.79), SIMDE_FLOAT32_C( -571.89), SIMDE_FLOAT32_C( -571.89), SIMDE_FLOAT32_C(  668.79)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -662.74), SIMDE_FLOAT32_C(  294.02), SIMDE_FLOAT32_C( -247.72), SIMDE_FLOAT32_C(  549.64)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  549.64), SIMDE_FLOAT32_C( -662.74), SIMDE_FLOAT32_C( -662.74), SIMDE_FLOAT32_C( -247.72)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  913.92), SIMDE_FLOAT32_C(  595.91), SIMDE_FLOAT32_C( -607.07), SIMDE_FLOAT32_C(  946.58)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  946.58), SIMDE_FLOAT32_C(  913.92), SIMDE_FLOAT32_C(  913.92), SIMDE_FLOAT32_C(  595.91)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  526.81), SIMDE_FLOAT32_C( -623.63), SIMDE_FLOAT32_C(  641.56), SIMDE_FLOAT32_C(  411.60)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  411.60), SIMDE_FLOAT32_C(  526.81), SIMDE_FLOAT32_C(  526.81), SIMDE_FLOAT32_C(  526.81)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  201.64), SIMDE_FLOAT32_C( -678.17), SIMDE_FLOAT32_C(  678.85), SIMDE_FLOAT32_C(  842.84)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  678.85), SIMDE_FLOAT32_C(  842.84), SIMDE_FLOAT32_C(  842.84), SIMDE_FLOAT32_C(  842.84)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -699.25), SIMDE_FLOAT32_C( -660.13), SIMDE_FLOAT32_C(  997.42), SIMDE_FLOAT32_C(  466.13)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  997.42), SIMDE_FLOAT32_C(  466.13), SIMDE_FLOAT32_C(  466.13), SIMDE_FLOAT32_C(  997.42)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -755.71), SIMDE_FLOAT32_C( -240.45), SIMDE_FLOAT32_C( -868.64), SIMDE_FLOAT32_C( -526.98)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -868.64), SIMDE_FLOAT32_C( -526.98), SIMDE_FLOAT32_C( -526.98), SIMDE_FLOAT32_C( -240.45)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  118.23), SIMDE_FLOAT32_C(  430.71), SIMDE_FLOAT32_C( -655.25), SIMDE_FLOAT32_C(  691.06)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -655.25), SIMDE_FLOAT32_C(  691.06), SIMDE_FLOAT32_C(  691.06), SIMDE_FLOAT32_C(  118.23)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  769.95), SIMDE_FLOAT32_C( -965.48), SIMDE_FLOAT32_C(  679.30), SIMDE_FLOAT32_C( -472.09)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  679.30), SIMDE_FLOAT32_C( -472.09), SIMDE_FLOAT32_C(  679.30), SIMDE_FLOAT32_C( -472.09)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  326.56), SIMDE_FLOAT32_C( -920.79), SIMDE_FLOAT32_C( -713.26), SIMDE_FLOAT32_C(  731.27)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -713.26), SIMDE_FLOAT32_C(  731.27), SIMDE_FLOAT32_C( -713.26), SIMDE_FLOAT32_C( -713.26)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  687.92), SIMDE_FLOAT32_C(  446.71), SIMDE_FLOAT32_C( -122.32), SIMDE_FLOAT32_C( -970.51)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -122.32), SIMDE_FLOAT32_C( -970.51), SIMDE_FLOAT32_C( -122.32), SIMDE_FLOAT32_C(  446.71)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  899.32), SIMDE_FLOAT32_C(  542.48), SIMDE_FLOAT32_C( -483.93), SIMDE_FLOAT32_C( -414.42)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -483.93), SIMDE_FLOAT32_C( -414.42), SIMDE_FLOAT32_C( -483.93), SIMDE_FLOAT32_C(  899.32)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -846.70), SIMDE_FLOAT32_C( -437.12), SIMDE_FLOAT32_C( -610.81), SIMDE_FLOAT32_C( -113.29)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -610.81), SIMDE_FLOAT32_C( -113.29), SIMDE_FLOAT32_C( -437.12), SIMDE_FLOAT32_C( -113.29)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -784.25), SIMDE_FLOAT32_C(  135.12), SIMDE_FLOAT32_C( -110.06), SIMDE_FLOAT32_C(  307.12)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -110.06), SIMDE_FLOAT32_C(  307.12), SIMDE_FLOAT32_C(  135.12), SIMDE_FLOAT32_C( -110.06)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(   61.66), SIMDE_FLOAT32_C(  639.23), SIMDE_FLOAT32_C( -885.40), SIMDE_FLOAT32_C(  629.86)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -885.40), SIMDE_FLOAT32_C(  629.86), SIMDE_FLOAT32_C(  639.23), SIMDE_FLOAT32_C(  639.23)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  750.01), SIMDE_FLOAT32_C(  196.93), SIMDE_FLOAT32_C( -121.64), SIMDE_FLOAT32_C( -699.41)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -121.64), SIMDE_FLOAT32_C( -699.41), SIMDE_FLOAT32_C(  196.93), SIMDE_FLOAT32_C(  750.01)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -638.91), SIMDE_FLOAT32_C( -469.10), SIMDE_FLOAT32_C( -940.40), SIMDE_FLOAT32_C(    9.99)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -940.40), SIMDE_FLOAT32_C(    9.99), SIMDE_FLOAT32_C( -638.91), SIMDE_FLOAT32_C(    9.99)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  928.63), SIMDE_FLOAT32_C(  309.39), SIMDE_FLOAT32_C( -127.18), SIMDE_FLOAT32_C(  -99.51)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -127.18), SIMDE_FLOAT32_C(  -99.51), SIMDE_FLOAT32_C(  928.63), SIMDE_FLOAT32_C( -127.18)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -831.04), SIMDE_FLOAT32_C( -251.25), SIMDE_FLOAT32_C( -266.02), SIMDE_FLOAT32_C( -207.85)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -266.02), SIMDE_FLOAT32_C( -207.85), SIMDE_FLOAT32_C( -831.04), SIMDE_FLOAT32_C( -251.25)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  999.23), SIMDE_FLOAT32_C( -496.23), SIMDE_FLOAT32_C( -947.77), SIMDE_FLOAT32_C( -545.85)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -947.77), SIMDE_FLOAT32_C( -545.85), SIMDE_FLOAT32_C(  999.23), SIMDE_FLOAT32_C(  999.23)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(   47.96), SIMDE_FLOAT32_C(    2.82), SIMDE_FLOAT32_C(  202.79), SIMDE_FLOAT32_C(  564.74)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  202.79), SIMDE_FLOAT32_C(  202.79), SIMDE_FLOAT32_C(  564.74), SIMDE_FLOAT32_C(  564.74)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  797.25), SIMDE_FLOAT32_C(  259.68), SIMDE_FLOAT32_C(   52.32), SIMDE_FLOAT32_C( -762.85)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(   52.32), SIMDE_FLOAT32_C(   52.32), SIMDE_FLOAT32_C( -762.85), SIMDE_FLOAT32_C(   52.32)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -113.44), SIMDE_FLOAT32_C( -994.88), SIMDE_FLOAT32_C(  440.07), SIMDE_FLOAT32_C( -428.31)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  440.07), SIMDE_FLOAT32_C(  440.07), SIMDE_FLOAT32_C( -428.31), SIMDE_FLOAT32_C( -994.88)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -795.97), SIMDE_FLOAT32_C(  668.43), SIMDE_FLOAT32_C(  759.65), SIMDE_FLOAT32_C( -792.05)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  759.65), SIMDE_FLOAT32_C(  759.65), SIMDE_FLOAT32_C( -792.05), SIMDE_FLOAT32_C( -795.97)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -357.44), SIMDE_FLOAT32_C(   81.95), SIMDE_FLOAT32_C(  548.34), SIMDE_FLOAT32_C( -724.84)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  548.34), SIMDE_FLOAT32_C(  548.34), SIMDE_FLOAT32_C(  548.34), SIMDE_FLOAT32_C( -724.84)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  197.07), SIMDE_FLOAT32_C(   17.46), SIMDE_FLOAT32_C( -512.34), SIMDE_FLOAT32_C(  526.78)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -512.34), SIMDE_FLOAT32_C( -512.34), SIMDE_FLOAT32_C( -512.34), SIMDE_FLOAT32_C( -512.34)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  192.92), SIMDE_FLOAT32_C( -936.13), SIMDE_FLOAT32_C(  901.95), SIMDE_FLOAT32_C( -248.80)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  901.95), SIMDE_FLOAT32_C(  901.95), SIMDE_FLOAT32_C(  901.95), SIMDE_FLOAT32_C( -936.13)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -630.71), SIMDE_FLOAT32_C( -330.59), SIMDE_FLOAT32_C(   82.23), SIMDE_FLOAT32_C(  719.00)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(   82.23), SIMDE_FLOAT32_C(   82.23), SIMDE_FLOAT32_C(   82.23), SIMDE_FLOAT32_C( -630.71)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  925.42), SIMDE_FLOAT32_C(  329.90), SIMDE_FLOAT32_C(  186.04), SIMDE_FLOAT32_C( -720.55)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  186.04), SIMDE_FLOAT32_C(  186.04), SIMDE_FLOAT32_C(  329.90), SIMDE_FLOAT32_C( -720.55)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -442.05), SIMDE_FLOAT32_C(  536.90), SIMDE_FLOAT32_C( -334.86), SIMDE_FLOAT32_C(  688.45)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -334.86), SIMDE_FLOAT32_C( -334.86), SIMDE_FLOAT32_C(  536.90), SIMDE_FLOAT32_C( -334.86)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -378.68), SIMDE_FLOAT32_C( -430.68), SIMDE_FLOAT32_C( -645.59), SIMDE_FLOAT32_C( -118.19)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -645.59), SIMDE_FLOAT32_C( -645.59), SIMDE_FLOAT32_C( -430.68), SIMDE_FLOAT32_C( -430.68)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  523.87), SIMDE_FLOAT32_C(   79.59), SIMDE_FLOAT32_C( -143.56), SIMDE_FLOAT32_C(  863.12)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -143.56), SIMDE_FLOAT32_C( -143.56), SIMDE_FLOAT32_C(   79.59), SIMDE_FLOAT32_C(  523.87)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  998.76), SIMDE_FLOAT32_C(  710.90), SIMDE_FLOAT32_C( -465.90), SIMDE_FLOAT32_C(  917.49)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -465.90), SIMDE_FLOAT32_C( -465.90), SIMDE_FLOAT32_C(  998.76), SIMDE_FLOAT32_C(  917.49)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -914.30), SIMDE_FLOAT32_C(  -75.60), SIMDE_FLOAT32_C( -471.92), SIMDE_FLOAT32_C(  514.20)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -471.92), SIMDE_FLOAT32_C( -471.92), SIMDE_FLOAT32_C( -914.30), SIMDE_FLOAT32_C( -471.92)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -977.60), SIMDE_FLOAT32_C(  586.14), SIMDE_FLOAT32_C( -796.25), SIMDE_FLOAT32_C( -242.07)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -796.25), SIMDE_FLOAT32_C( -796.25), SIMDE_FLOAT32_C( -977.60), SIMDE_FLOAT32_C(  586.14)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -367.70), SIMDE_FLOAT32_C(  -51.47), SIMDE_FLOAT32_C(  888.89), SIMDE_FLOAT32_C( -484.53)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  888.89), SIMDE_FLOAT32_C(  888.89), SIMDE_FLOAT32_C( -367.70), SIMDE_FLOAT32_C( -367.70)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -497.66), SIMDE_FLOAT32_C(  568.81), SIMDE_FLOAT32_C(  261.51), SIMDE_FLOAT32_C(  409.74)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  261.51), SIMDE_FLOAT32_C(  568.81), SIMDE_FLOAT32_C(  409.74), SIMDE_FLOAT32_C(  409.74)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  860.94), SIMDE_FLOAT32_C( -736.50), SIMDE_FLOAT32_C( -526.79), SIMDE_FLOAT32_C(  -26.31)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -526.79), SIMDE_FLOAT32_C( -736.50), SIMDE_FLOAT32_C(  -26.31), SIMDE_FLOAT32_C( -526.79)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -348.77), SIMDE_FLOAT32_C(  412.23), SIMDE_FLOAT32_C(  503.74), SIMDE_FLOAT32_C(  154.98)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  503.74), SIMDE_FLOAT32_C(  412.23), SIMDE_FLOAT32_C(  154.98), SIMDE_FLOAT32_C(  412.23)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(   96.99), SIMDE_FLOAT32_C(  924.76), SIMDE_FLOAT32_C(  195.37), SIMDE_FLOAT32_C( -509.80)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  195.37), SIMDE_FLOAT32_C(  924.76), SIMDE_FLOAT32_C( -509.80), SIMDE_FLOAT32_C(   96.99)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -942.77), SIMDE_FLOAT32_C( -619.72), SIMDE_FLOAT32_C(  286.50), SIMDE_FLOAT32_C( -624.38)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  286.50), SIMDE_FLOAT32_C( -619.72), SIMDE_FLOAT32_C(  286.50), SIMDE_FLOAT32_C( -624.38)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  646.19), SIMDE_FLOAT32_C(  588.86), SIMDE_FLOAT32_C( -851.49), SIMDE_FLOAT32_C(  716.64)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -851.49), SIMDE_FLOAT32_C(  588.86), SIMDE_FLOAT32_C( -851.49), SIMDE_FLOAT32_C( -851.49)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  919.32), SIMDE_FLOAT32_C(  583.35), SIMDE_FLOAT32_C( -833.45), SIMDE_FLOAT32_C(  -19.86)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -833.45), SIMDE_FLOAT32_C(  583.35), SIMDE_FLOAT32_C( -833.45), SIMDE_FLOAT32_C(  583.35)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -657.38), SIMDE_FLOAT32_C(  907.92), SIMDE_FLOAT32_C(  393.16), SIMDE_FLOAT32_C( -507.79)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  393.16), SIMDE_FLOAT32_C(  907.92), SIMDE_FLOAT32_C(  393.16), SIMDE_FLOAT32_C( -657.38)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  913.71), SIMDE_FLOAT32_C(  199.15), SIMDE_FLOAT32_C( -400.92), SIMDE_FLOAT32_C(  -79.54)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -400.92), SIMDE_FLOAT32_C(  199.15), SIMDE_FLOAT32_C(  199.15), SIMDE_FLOAT32_C(  -79.54)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -246.42), SIMDE_FLOAT32_C( -272.80), SIMDE_FLOAT32_C(  414.30), SIMDE_FLOAT32_C(  975.91)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  414.30), SIMDE_FLOAT32_C( -272.80), SIMDE_FLOAT32_C( -272.80), SIMDE_FLOAT32_C(  414.30)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -434.43), SIMDE_FLOAT32_C( -492.17), SIMDE_FLOAT32_C(  587.13), SIMDE_FLOAT32_C(  -92.88)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  587.13), SIMDE_FLOAT32_C( -492.17), SIMDE_FLOAT32_C( -492.17), SIMDE_FLOAT32_C( -492.17)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  -27.25), SIMDE_FLOAT32_C( -358.12), SIMDE_FLOAT32_C( -352.82), SIMDE_FLOAT32_C(  446.91)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -352.82), SIMDE_FLOAT32_C( -358.12), SIMDE_FLOAT32_C( -358.12), SIMDE_FLOAT32_C(  -27.25)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  521.68), SIMDE_FLOAT32_C( -662.29), SIMDE_FLOAT32_C( -469.72), SIMDE_FLOAT32_C(  990.43)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -469.72), SIMDE_FLOAT32_C( -662.29), SIMDE_FLOAT32_C(  521.68), SIMDE_FLOAT32_C(  990.43)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -207.42), SIMDE_FLOAT32_C( -368.57), SIMDE_FLOAT32_C( -563.56), SIMDE_FLOAT32_C(  851.44)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -563.56), SIMDE_FLOAT32_C( -368.57), SIMDE_FLOAT32_C( -207.42), SIMDE_FLOAT32_C( -563.56)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -682.19), SIMDE_FLOAT32_C(  822.46), SIMDE_FLOAT32_C(  678.74), SIMDE_FLOAT32_C(  405.54)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  678.74), SIMDE_FLOAT32_C(  822.46), SIMDE_FLOAT32_C( -682.19), SIMDE_FLOAT32_C(  822.46)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  379.86), SIMDE_FLOAT32_C(  221.90), SIMDE_FLOAT32_C(  255.71), SIMDE_FLOAT32_C( -253.16)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  255.71), SIMDE_FLOAT32_C(  221.90), SIMDE_FLOAT32_C(  379.86), SIMDE_FLOAT32_C(  379.86)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -468.42), SIMDE_FLOAT32_C(  183.29), SIMDE_FLOAT32_C( -906.66), SIMDE_FLOAT32_C(  856.70)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -906.66), SIMDE_FLOAT32_C( -468.42), SIMDE_FLOAT32_C(  856.70), SIMDE_FLOAT32_C(  856.70)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(   63.27), SIMDE_FLOAT32_C( -666.06), SIMDE_FLOAT32_C( -407.35), SIMDE_FLOAT32_C(  276.11)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -407.35), SIMDE_FLOAT32_C(   63.27), SIMDE_FLOAT32_C(  276.11), SIMDE_FLOAT32_C( -407.35)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -957.66), SIMDE_FLOAT32_C(  -54.13), SIMDE_FLOAT32_C( -234.34), SIMDE_FLOAT32_C(  385.07)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -234.34), SIMDE_FLOAT32_C( -957.66), SIMDE_FLOAT32_C(  385.07), SIMDE_FLOAT32_C(  -54.13)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  138.95), SIMDE_FLOAT32_C(  169.28), SIMDE_FLOAT32_C( -765.90), SIMDE_FLOAT32_C(  659.90)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -765.90), SIMDE_FLOAT32_C(  138.95), SIMDE_FLOAT32_C(  659.90), SIMDE_FLOAT32_C(  138.95)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  237.96), SIMDE_FLOAT32_C( -753.52), SIMDE_FLOAT32_C(  701.82), SIMDE_FLOAT32_C(  369.95)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  701.82), SIMDE_FLOAT32_C(  237.96), SIMDE_FLOAT32_C(  701.82), SIMDE_FLOAT32_C(  369.95)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -341.41), SIMDE_FLOAT32_C( -753.67), SIMDE_FLOAT32_C( -791.26), SIMDE_FLOAT32_C( -867.78)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -791.26), SIMDE_FLOAT32_C( -341.41), SIMDE_FLOAT32_C( -791.26), SIMDE_FLOAT32_C( -791.26)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  -81.56), SIMDE_FLOAT32_C(  116.74), SIMDE_FLOAT32_C(  681.80), SIMDE_FLOAT32_C( -355.36)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  681.80), SIMDE_FLOAT32_C(  -81.56), SIMDE_FLOAT32_C(  681.80), SIMDE_FLOAT32_C(  116.74)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  290.55), SIMDE_FLOAT32_C( -846.20), SIMDE_FLOAT32_C(  744.86), SIMDE_FLOAT32_C( -984.85)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  744.86), SIMDE_FLOAT32_C(  290.55), SIMDE_FLOAT32_C(  744.86), SIMDE_FLOAT32_C(  290.55)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  156.02), SIMDE_FLOAT32_C( -578.39), SIMDE_FLOAT32_C(  122.79), SIMDE_FLOAT32_C(  432.77)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  122.79), SIMDE_FLOAT32_C(  156.02), SIMDE_FLOAT32_C( -578.39), SIMDE_FLOAT32_C(  432.77)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  623.05), SIMDE_FLOAT32_C( -860.44), SIMDE_FLOAT32_C( -584.30), SIMDE_FLOAT32_C(  977.33)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -584.30), SIMDE_FLOAT32_C(  623.05), SIMDE_FLOAT32_C( -860.44), SIMDE_FLOAT32_C( -584.30)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -759.65), SIMDE_FLOAT32_C(  118.08), SIMDE_FLOAT32_C(  237.95), SIMDE_FLOAT32_C( -510.27)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  237.95), SIMDE_FLOAT32_C( -759.65), SIMDE_FLOAT32_C(  118.08), SIMDE_FLOAT32_C(  118.08)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -589.86), SIMDE_FLOAT32_C(  441.39), SIMDE_FLOAT32_C(  536.13), SIMDE_FLOAT32_C(  406.32)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  536.13), SIMDE_FLOAT32_C( -589.86), SIMDE_FLOAT32_C(  441.39), SIMDE_FLOAT32_C( -589.86)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -821.01), SIMDE_FLOAT32_C( -190.34), SIMDE_FLOAT32_C(  250.72), SIMDE_FLOAT32_C(  430.77)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  250.72), SIMDE_FLOAT32_C( -821.01), SIMDE_FLOAT32_C( -821.01), SIMDE_FLOAT32_C(  430.77)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -794.40), SIMDE_FLOAT32_C( -905.41), SIMDE_FLOAT32_C( -600.00), SIMDE_FLOAT32_C(  537.05)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -600.00), SIMDE_FLOAT32_C( -794.40), SIMDE_FLOAT32_C( -794.40), SIMDE_FLOAT32_C( -600.00)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -929.50), SIMDE_FLOAT32_C(   34.12), SIMDE_FLOAT32_C(  463.32), SIMDE_FLOAT32_C(  201.56)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  463.32), SIMDE_FLOAT32_C( -929.50), SIMDE_FLOAT32_C( -929.50), SIMDE_FLOAT32_C(   34.12)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(   82.66), SIMDE_FLOAT32_C(  131.64), SIMDE_FLOAT32_C(  979.15), SIMDE_FLOAT32_C(  658.74)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  979.15), SIMDE_FLOAT32_C(   82.66), SIMDE_FLOAT32_C(   82.66), SIMDE_FLOAT32_C(   82.66)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -597.79), SIMDE_FLOAT32_C( -283.72), SIMDE_FLOAT32_C( -875.55), SIMDE_FLOAT32_C( -515.26)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -283.72), SIMDE_FLOAT32_C( -515.26), SIMDE_FLOAT32_C( -515.26), SIMDE_FLOAT32_C( -515.26)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  161.01), SIMDE_FLOAT32_C( -280.81), SIMDE_FLOAT32_C(  433.76), SIMDE_FLOAT32_C(  574.65)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -280.81), SIMDE_FLOAT32_C(  574.65), SIMDE_FLOAT32_C(  574.65), SIMDE_FLOAT32_C(  433.76)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -120.60), SIMDE_FLOAT32_C(  984.62), SIMDE_FLOAT32_C(  588.33), SIMDE_FLOAT32_C( -475.24)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  984.62), SIMDE_FLOAT32_C( -475.24), SIMDE_FLOAT32_C( -475.24), SIMDE_FLOAT32_C(  984.62)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -958.82), SIMDE_FLOAT32_C(  826.27), SIMDE_FLOAT32_C( -955.21), SIMDE_FLOAT32_C( -423.09)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  826.27), SIMDE_FLOAT32_C( -423.09), SIMDE_FLOAT32_C( -423.09), SIMDE_FLOAT32_C( -958.82)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -912.92), SIMDE_FLOAT32_C( -993.29), SIMDE_FLOAT32_C(  519.49), SIMDE_FLOAT32_C( -813.38)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -993.29), SIMDE_FLOAT32_C( -813.38), SIMDE_FLOAT32_C(  519.49), SIMDE_FLOAT32_C( -813.38)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  400.51), SIMDE_FLOAT32_C( -477.89), SIMDE_FLOAT32_C( -223.62), SIMDE_FLOAT32_C( -892.00)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -477.89), SIMDE_FLOAT32_C( -892.00), SIMDE_FLOAT32_C( -223.62), SIMDE_FLOAT32_C( -223.62)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -219.57), SIMDE_FLOAT32_C( -463.35), SIMDE_FLOAT32_C( -649.55), SIMDE_FLOAT32_C(  419.75)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -463.35), SIMDE_FLOAT32_C(  419.75), SIMDE_FLOAT32_C( -649.55), SIMDE_FLOAT32_C( -463.35)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  674.35), SIMDE_FLOAT32_C(  104.83), SIMDE_FLOAT32_C( -922.50), SIMDE_FLOAT32_C(  126.87)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  104.83), SIMDE_FLOAT32_C(  126.87), SIMDE_FLOAT32_C( -922.50), SIMDE_FLOAT32_C(  674.35)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -361.65), SIMDE_FLOAT32_C(  829.53), SIMDE_FLOAT32_C(  -30.69), SIMDE_FLOAT32_C(  227.81)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  829.53), SIMDE_FLOAT32_C(  227.81), SIMDE_FLOAT32_C(  829.53), SIMDE_FLOAT32_C(  227.81)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -832.30), SIMDE_FLOAT32_C(   51.62), SIMDE_FLOAT32_C( -928.61), SIMDE_FLOAT32_C( -243.53)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(   51.62), SIMDE_FLOAT32_C( -243.53), SIMDE_FLOAT32_C(   51.62), SIMDE_FLOAT32_C( -928.61)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -984.05), SIMDE_FLOAT32_C( -356.91), SIMDE_FLOAT32_C(  194.97), SIMDE_FLOAT32_C(  360.69)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -356.91), SIMDE_FLOAT32_C(  360.69), SIMDE_FLOAT32_C( -356.91), SIMDE_FLOAT32_C( -356.91)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -801.82), SIMDE_FLOAT32_C(  -91.27), SIMDE_FLOAT32_C( -932.88), SIMDE_FLOAT32_C( -684.29)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  -91.27), SIMDE_FLOAT32_C( -684.29), SIMDE_FLOAT32_C(  -91.27), SIMDE_FLOAT32_C( -801.82)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -988.23), SIMDE_FLOAT32_C(  639.77), SIMDE_FLOAT32_C(  980.28), SIMDE_FLOAT32_C( -155.78)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  639.77), SIMDE_FLOAT32_C( -155.78), SIMDE_FLOAT32_C( -988.23), SIMDE_FLOAT32_C( -155.78)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  777.22), SIMDE_FLOAT32_C(  390.78), SIMDE_FLOAT32_C( -991.33), SIMDE_FLOAT32_C( -336.72)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  390.78), SIMDE_FLOAT32_C( -336.72), SIMDE_FLOAT32_C(  777.22), SIMDE_FLOAT32_C( -991.33)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -328.81), SIMDE_FLOAT32_C( -300.01), SIMDE_FLOAT32_C( -117.64), SIMDE_FLOAT32_C( -897.11)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -300.01), SIMDE_FLOAT32_C( -897.11), SIMDE_FLOAT32_C( -328.81), SIMDE_FLOAT32_C( -300.01)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  685.73), SIMDE_FLOAT32_C(  596.12), SIMDE_FLOAT32_C(  419.02), SIMDE_FLOAT32_C(  916.79)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  596.12), SIMDE_FLOAT32_C(  916.79), SIMDE_FLOAT32_C(  685.73), SIMDE_FLOAT32_C(  685.73)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  796.65), SIMDE_FLOAT32_C(  880.95), SIMDE_FLOAT32_C(  971.66), SIMDE_FLOAT32_C( -484.20)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  880.95), SIMDE_FLOAT32_C(  971.66), SIMDE_FLOAT32_C( -484.20), SIMDE_FLOAT32_C( -484.20)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -278.90), SIMDE_FLOAT32_C(  589.79), SIMDE_FLOAT32_C( -455.51), SIMDE_FLOAT32_C( -179.81)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  589.79), SIMDE_FLOAT32_C( -455.51), SIMDE_FLOAT32_C( -179.81), SIMDE_FLOAT32_C( -455.51)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -431.09), SIMDE_FLOAT32_C(  687.64), SIMDE_FLOAT32_C(  547.23), SIMDE_FLOAT32_C(  875.54)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  687.64), SIMDE_FLOAT32_C(  547.23), SIMDE_FLOAT32_C(  875.54), SIMDE_FLOAT32_C(  687.64)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  -94.41), SIMDE_FLOAT32_C( -895.08), SIMDE_FLOAT32_C(  393.41), SIMDE_FLOAT32_C(  884.32)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -895.08), SIMDE_FLOAT32_C(  393.41), SIMDE_FLOAT32_C(  884.32), SIMDE_FLOAT32_C(  -94.41)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  443.28), SIMDE_FLOAT32_C( -532.78), SIMDE_FLOAT32_C(  901.08), SIMDE_FLOAT32_C(  361.64)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -532.78), SIMDE_FLOAT32_C(  901.08), SIMDE_FLOAT32_C(  901.08), SIMDE_FLOAT32_C(  361.64)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  529.64), SIMDE_FLOAT32_C( -198.34), SIMDE_FLOAT32_C( -627.88), SIMDE_FLOAT32_C(  855.30)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -198.34), SIMDE_FLOAT32_C( -627.88), SIMDE_FLOAT32_C( -627.88), SIMDE_FLOAT32_C( -627.88)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -177.99), SIMDE_FLOAT32_C(  923.65), SIMDE_FLOAT32_C(  547.66), SIMDE_FLOAT32_C(  425.65)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  923.65), SIMDE_FLOAT32_C(  547.66), SIMDE_FLOAT32_C(  547.66), SIMDE_FLOAT32_C(  923.65)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -390.98), SIMDE_FLOAT32_C(  372.02), SIMDE_FLOAT32_C( -363.20), SIMDE_FLOAT32_C( -381.77)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  372.02), SIMDE_FLOAT32_C( -363.20), SIMDE_FLOAT32_C( -363.20), SIMDE_FLOAT32_C( -390.98)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -832.84), SIMDE_FLOAT32_C(  816.10), SIMDE_FLOAT32_C( -323.60), SIMDE_FLOAT32_C( -812.16)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  816.10), SIMDE_FLOAT32_C( -323.60), SIMDE_FLOAT32_C(  816.10), SIMDE_FLOAT32_C( -812.16)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -654.62), SIMDE_FLOAT32_C( -780.25), SIMDE_FLOAT32_C(  836.42), SIMDE_FLOAT32_C( -115.55)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -780.25), SIMDE_FLOAT32_C(  836.42), SIMDE_FLOAT32_C( -780.25), SIMDE_FLOAT32_C(  836.42)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -678.64), SIMDE_FLOAT32_C(  306.11), SIMDE_FLOAT32_C(  840.86), SIMDE_FLOAT32_C(  511.67)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  306.11), SIMDE_FLOAT32_C(  840.86), SIMDE_FLOAT32_C(  306.11), SIMDE_FLOAT32_C(  306.11)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  529.91), SIMDE_FLOAT32_C( -986.05), SIMDE_FLOAT32_C( -396.01), SIMDE_FLOAT32_C(   84.06)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -986.05), SIMDE_FLOAT32_C( -396.01), SIMDE_FLOAT32_C( -986.05), SIMDE_FLOAT32_C(  529.91)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  583.87), SIMDE_FLOAT32_C( -798.29), SIMDE_FLOAT32_C(  -36.74), SIMDE_FLOAT32_C( -759.30)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -798.29), SIMDE_FLOAT32_C(  -36.74), SIMDE_FLOAT32_C(  583.87), SIMDE_FLOAT32_C( -759.30)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -888.99), SIMDE_FLOAT32_C( -125.32), SIMDE_FLOAT32_C(  718.04), SIMDE_FLOAT32_C(  980.08)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -125.32), SIMDE_FLOAT32_C(  718.04), SIMDE_FLOAT32_C( -888.99), SIMDE_FLOAT32_C(  718.04)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(   92.61), SIMDE_FLOAT32_C(  -37.83), SIMDE_FLOAT32_C(  786.53), SIMDE_FLOAT32_C( -271.98)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  -37.83), SIMDE_FLOAT32_C(  786.53), SIMDE_FLOAT32_C(   92.61), SIMDE_FLOAT32_C(  -37.83)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  -12.79), SIMDE_FLOAT32_C( -626.85), SIMDE_FLOAT32_C( -789.68), SIMDE_FLOAT32_C(  994.79)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -626.85), SIMDE_FLOAT32_C( -789.68), SIMDE_FLOAT32_C(  -12.79), SIMDE_FLOAT32_C(  -12.79)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  196.53), SIMDE_FLOAT32_C( -183.45), SIMDE_FLOAT32_C( -958.80), SIMDE_FLOAT32_C(  936.18)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -183.45), SIMDE_FLOAT32_C( -183.45), SIMDE_FLOAT32_C(  936.18), SIMDE_FLOAT32_C(  936.18)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -594.79), SIMDE_FLOAT32_C(  339.35), SIMDE_FLOAT32_C(  261.16), SIMDE_FLOAT32_C(  214.84)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  339.35), SIMDE_FLOAT32_C(  339.35), SIMDE_FLOAT32_C(  214.84), SIMDE_FLOAT32_C(  261.16)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -471.49), SIMDE_FLOAT32_C(  -57.54), SIMDE_FLOAT32_C(  124.66), SIMDE_FLOAT32_C(  338.07)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  -57.54), SIMDE_FLOAT32_C(  -57.54), SIMDE_FLOAT32_C(  338.07), SIMDE_FLOAT32_C(  -57.54)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  102.70), SIMDE_FLOAT32_C(  823.34), SIMDE_FLOAT32_C(  691.25), SIMDE_FLOAT32_C( -818.26)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  823.34), SIMDE_FLOAT32_C(  823.34), SIMDE_FLOAT32_C( -818.26), SIMDE_FLOAT32_C(  102.70)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  591.19), SIMDE_FLOAT32_C( -442.13), SIMDE_FLOAT32_C( -405.72), SIMDE_FLOAT32_C(  763.96)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -442.13), SIMDE_FLOAT32_C( -442.13), SIMDE_FLOAT32_C( -405.72), SIMDE_FLOAT32_C(  763.96)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -346.34), SIMDE_FLOAT32_C( -542.44), SIMDE_FLOAT32_C( -190.16), SIMDE_FLOAT32_C(  958.34)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -542.44), SIMDE_FLOAT32_C( -542.44), SIMDE_FLOAT32_C( -190.16), SIMDE_FLOAT32_C( -190.16)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -269.02), SIMDE_FLOAT32_C(  102.93), SIMDE_FLOAT32_C( -329.22), SIMDE_FLOAT32_C(  316.11)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  102.93), SIMDE_FLOAT32_C(  102.93), SIMDE_FLOAT32_C( -329.22), SIMDE_FLOAT32_C(  102.93)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  757.87), SIMDE_FLOAT32_C(  372.36), SIMDE_FLOAT32_C(    8.92), SIMDE_FLOAT32_C( -449.36)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  372.36), SIMDE_FLOAT32_C(  372.36), SIMDE_FLOAT32_C(    8.92), SIMDE_FLOAT32_C(  757.87)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -989.80), SIMDE_FLOAT32_C( -564.66), SIMDE_FLOAT32_C(  750.97), SIMDE_FLOAT32_C( -365.52)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -564.66), SIMDE_FLOAT32_C( -564.66), SIMDE_FLOAT32_C( -564.66), SIMDE_FLOAT32_C( -365.52)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  385.06), SIMDE_FLOAT32_C(  256.00), SIMDE_FLOAT32_C( -486.71), SIMDE_FLOAT32_C( -581.02)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  256.00), SIMDE_FLOAT32_C(  256.00), SIMDE_FLOAT32_C(  256.00), SIMDE_FLOAT32_C( -486.71)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  918.69), SIMDE_FLOAT32_C( -614.99), SIMDE_FLOAT32_C(  369.92), SIMDE_FLOAT32_C(  807.28)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -614.99), SIMDE_FLOAT32_C( -614.99), SIMDE_FLOAT32_C( -614.99), SIMDE_FLOAT32_C( -614.99)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  207.16), SIMDE_FLOAT32_C( -862.08), SIMDE_FLOAT32_C(  -64.71), SIMDE_FLOAT32_C( -617.71)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -862.08), SIMDE_FLOAT32_C( -862.08), SIMDE_FLOAT32_C( -862.08), SIMDE_FLOAT32_C(  207.16)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -430.66), SIMDE_FLOAT32_C(  604.46), SIMDE_FLOAT32_C( -166.72), SIMDE_FLOAT32_C(  563.18)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  604.46), SIMDE_FLOAT32_C(  604.46), SIMDE_FLOAT32_C( -430.66), SIMDE_FLOAT32_C(  563.18)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  440.09), SIMDE_FLOAT32_C( -733.60), SIMDE_FLOAT32_C(  723.39), SIMDE_FLOAT32_C(  324.08)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -733.60), SIMDE_FLOAT32_C( -733.60), SIMDE_FLOAT32_C(  440.09), SIMDE_FLOAT32_C(  723.39)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(   27.12), SIMDE_FLOAT32_C(   61.27), SIMDE_FLOAT32_C( -549.41), SIMDE_FLOAT32_C( -656.87)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(   61.27), SIMDE_FLOAT32_C(   61.27), SIMDE_FLOAT32_C(   27.12), SIMDE_FLOAT32_C(   61.27)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -117.29), SIMDE_FLOAT32_C( -681.66), SIMDE_FLOAT32_C(  318.62), SIMDE_FLOAT32_C(  389.46)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -681.66), SIMDE_FLOAT32_C( -681.66), SIMDE_FLOAT32_C( -117.29), SIMDE_FLOAT32_C( -117.29)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -238.56), SIMDE_FLOAT32_C(  372.78), SIMDE_FLOAT32_C(  526.75), SIMDE_FLOAT32_C( -125.64)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  372.78), SIMDE_FLOAT32_C( -238.56), SIMDE_FLOAT32_C( -125.64), SIMDE_FLOAT32_C( -125.64)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  210.07), SIMDE_FLOAT32_C( -289.95), SIMDE_FLOAT32_C(  500.34), SIMDE_FLOAT32_C(  849.05)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -289.95), SIMDE_FLOAT32_C(  210.07), SIMDE_FLOAT32_C(  849.05), SIMDE_FLOAT32_C(  500.34)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  -28.70), SIMDE_FLOAT32_C( -255.62), SIMDE_FLOAT32_C(  763.65), SIMDE_FLOAT32_C(   94.61)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -255.62), SIMDE_FLOAT32_C(  -28.70), SIMDE_FLOAT32_C(   94.61), SIMDE_FLOAT32_C( -255.62)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  725.84), SIMDE_FLOAT32_C(  594.62), SIMDE_FLOAT32_C( -365.96), SIMDE_FLOAT32_C( -854.19)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  594.62), SIMDE_FLOAT32_C(  725.84), SIMDE_FLOAT32_C( -854.19), SIMDE_FLOAT32_C(  725.84)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  783.28), SIMDE_FLOAT32_C( -603.30), SIMDE_FLOAT32_C( -803.69), SIMDE_FLOAT32_C( -448.36)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -603.30), SIMDE_FLOAT32_C(  783.28), SIMDE_FLOAT32_C( -803.69), SIMDE_FLOAT32_C( -448.36)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  406.77), SIMDE_FLOAT32_C(   82.36), SIMDE_FLOAT32_C( -765.67), SIMDE_FLOAT32_C(  235.70)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(   82.36), SIMDE_FLOAT32_C(  406.77), SIMDE_FLOAT32_C( -765.67), SIMDE_FLOAT32_C( -765.67)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -235.56), SIMDE_FLOAT32_C( -950.34), SIMDE_FLOAT32_C(  822.39), SIMDE_FLOAT32_C(  927.21)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -950.34), SIMDE_FLOAT32_C( -235.56), SIMDE_FLOAT32_C(  822.39), SIMDE_FLOAT32_C( -950.34)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  674.56), SIMDE_FLOAT32_C(  812.98), SIMDE_FLOAT32_C( -301.55), SIMDE_FLOAT32_C(  368.14)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  812.98), SIMDE_FLOAT32_C(  674.56), SIMDE_FLOAT32_C( -301.55), SIMDE_FLOAT32_C(  674.56)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -732.74), SIMDE_FLOAT32_C(  236.04), SIMDE_FLOAT32_C( -826.13), SIMDE_FLOAT32_C( -302.69)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  236.04), SIMDE_FLOAT32_C( -732.74), SIMDE_FLOAT32_C(  236.04), SIMDE_FLOAT32_C( -302.69)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -904.66), SIMDE_FLOAT32_C(  743.42), SIMDE_FLOAT32_C( -303.17), SIMDE_FLOAT32_C( -418.85)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  743.42), SIMDE_FLOAT32_C( -904.66), SIMDE_FLOAT32_C(  743.42), SIMDE_FLOAT32_C( -303.17)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -899.64), SIMDE_FLOAT32_C(  875.65), SIMDE_FLOAT32_C(  181.39), SIMDE_FLOAT32_C(  -99.21)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  875.65), SIMDE_FLOAT32_C( -899.64), SIMDE_FLOAT32_C(  875.65), SIMDE_FLOAT32_C(  875.65)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  326.49), SIMDE_FLOAT32_C(  250.21), SIMDE_FLOAT32_C(  214.85), SIMDE_FLOAT32_C( -108.01)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  250.21), SIMDE_FLOAT32_C(  326.49), SIMDE_FLOAT32_C(  250.21), SIMDE_FLOAT32_C(  326.49)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -484.49), SIMDE_FLOAT32_C(  983.76), SIMDE_FLOAT32_C(  607.97), SIMDE_FLOAT32_C( -348.70)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  983.76), SIMDE_FLOAT32_C( -484.49), SIMDE_FLOAT32_C( -484.49), SIMDE_FLOAT32_C( -348.70)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -805.17), SIMDE_FLOAT32_C( -967.96), SIMDE_FLOAT32_C( -415.79), SIMDE_FLOAT32_C( -535.45)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -967.96), SIMDE_FLOAT32_C( -805.17), SIMDE_FLOAT32_C( -805.17), SIMDE_FLOAT32_C( -415.79)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -493.15), SIMDE_FLOAT32_C(  867.60), SIMDE_FLOAT32_C( -516.42), SIMDE_FLOAT32_C(   -2.63)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  867.60), SIMDE_FLOAT32_C( -493.15), SIMDE_FLOAT32_C( -493.15), SIMDE_FLOAT32_C(  867.60)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -394.13), SIMDE_FLOAT32_C( -758.56), SIMDE_FLOAT32_C( -874.63), SIMDE_FLOAT32_C( -876.35)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -758.56), SIMDE_FLOAT32_C( -394.13), SIMDE_FLOAT32_C( -394.13), SIMDE_FLOAT32_C( -394.13)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  996.63), SIMDE_FLOAT32_C(  579.16), SIMDE_FLOAT32_C( -396.61), SIMDE_FLOAT32_C(  887.34)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  996.63), SIMDE_FLOAT32_C(  887.34), SIMDE_FLOAT32_C(  887.34), SIMDE_FLOAT32_C(  887.34)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -215.05), SIMDE_FLOAT32_C( -383.28), SIMDE_FLOAT32_C( -358.15), SIMDE_FLOAT32_C( -100.26)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -215.05), SIMDE_FLOAT32_C( -100.26), SIMDE_FLOAT32_C( -100.26), SIMDE_FLOAT32_C( -358.15)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  498.79), SIMDE_FLOAT32_C( -181.50), SIMDE_FLOAT32_C(  -54.70), SIMDE_FLOAT32_C( -518.72)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  498.79), SIMDE_FLOAT32_C( -518.72), SIMDE_FLOAT32_C( -518.72), SIMDE_FLOAT32_C( -181.50)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  -19.49), SIMDE_FLOAT32_C( -927.75), SIMDE_FLOAT32_C(  710.98), SIMDE_FLOAT32_C(  -58.71)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  -19.49), SIMDE_FLOAT32_C(  -58.71), SIMDE_FLOAT32_C(  -58.71), SIMDE_FLOAT32_C(  -19.49)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  723.93), SIMDE_FLOAT32_C(  -45.40), SIMDE_FLOAT32_C(  453.31), SIMDE_FLOAT32_C(  -41.73)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  723.93), SIMDE_FLOAT32_C(  -41.73), SIMDE_FLOAT32_C(  453.31), SIMDE_FLOAT32_C(  -41.73)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  561.59), SIMDE_FLOAT32_C(  660.98), SIMDE_FLOAT32_C( -173.98), SIMDE_FLOAT32_C(  557.68)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  561.59), SIMDE_FLOAT32_C(  557.68), SIMDE_FLOAT32_C( -173.98), SIMDE_FLOAT32_C( -173.98)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  953.14), SIMDE_FLOAT32_C(  873.10), SIMDE_FLOAT32_C( -165.91), SIMDE_FLOAT32_C(  -68.41)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  953.14), SIMDE_FLOAT32_C(  -68.41), SIMDE_FLOAT32_C( -165.91), SIMDE_FLOAT32_C(  873.10)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  962.15), SIMDE_FLOAT32_C(  676.26), SIMDE_FLOAT32_C( -374.75), SIMDE_FLOAT32_C(  384.02)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  962.15), SIMDE_FLOAT32_C(  384.02), SIMDE_FLOAT32_C( -374.75), SIMDE_FLOAT32_C(  962.15)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -601.38), SIMDE_FLOAT32_C(   92.89), SIMDE_FLOAT32_C(  170.78), SIMDE_FLOAT32_C( -620.70)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -601.38), SIMDE_FLOAT32_C( -620.70), SIMDE_FLOAT32_C(   92.89), SIMDE_FLOAT32_C( -620.70)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -805.51), SIMDE_FLOAT32_C( -417.04), SIMDE_FLOAT32_C(  490.99), SIMDE_FLOAT32_C( -512.47)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -805.51), SIMDE_FLOAT32_C( -512.47), SIMDE_FLOAT32_C( -417.04), SIMDE_FLOAT32_C(  490.99)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  -61.78), SIMDE_FLOAT32_C( -138.80), SIMDE_FLOAT32_C(  942.03), SIMDE_FLOAT32_C( -801.33)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  -61.78), SIMDE_FLOAT32_C( -801.33), SIMDE_FLOAT32_C( -138.80), SIMDE_FLOAT32_C( -138.80)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  699.85), SIMDE_FLOAT32_C(  -90.11), SIMDE_FLOAT32_C(  308.36), SIMDE_FLOAT32_C( -655.79)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  699.85), SIMDE_FLOAT32_C( -655.79), SIMDE_FLOAT32_C(  -90.11), SIMDE_FLOAT32_C(  699.85)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -481.55), SIMDE_FLOAT32_C(  132.34), SIMDE_FLOAT32_C(  861.95), SIMDE_FLOAT32_C(  462.26)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -481.55), SIMDE_FLOAT32_C(  462.26), SIMDE_FLOAT32_C( -481.55), SIMDE_FLOAT32_C(  462.26)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -945.14), SIMDE_FLOAT32_C( -138.14), SIMDE_FLOAT32_C(  868.02), SIMDE_FLOAT32_C(   -6.85)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -945.14), SIMDE_FLOAT32_C(   -6.85), SIMDE_FLOAT32_C( -945.14), SIMDE_FLOAT32_C(  868.02)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -570.43), SIMDE_FLOAT32_C(  704.73), SIMDE_FLOAT32_C(  765.30), SIMDE_FLOAT32_C(  363.14)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -570.43), SIMDE_FLOAT32_C(  363.14), SIMDE_FLOAT32_C( -570.43), SIMDE_FLOAT32_C(  704.73)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -316.13), SIMDE_FLOAT32_C( -993.42), SIMDE_FLOAT32_C( -681.39), SIMDE_FLOAT32_C( -671.72)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -316.13), SIMDE_FLOAT32_C( -671.72), SIMDE_FLOAT32_C( -316.13), SIMDE_FLOAT32_C( -316.13)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  314.84), SIMDE_FLOAT32_C( -819.20), SIMDE_FLOAT32_C( -570.13), SIMDE_FLOAT32_C(  131.80)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  314.84), SIMDE_FLOAT32_C( -570.13), SIMDE_FLOAT32_C(  131.80), SIMDE_FLOAT32_C(  131.80)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  454.38), SIMDE_FLOAT32_C(  907.25), SIMDE_FLOAT32_C(   81.37), SIMDE_FLOAT32_C(  795.02)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  454.38), SIMDE_FLOAT32_C(   81.37), SIMDE_FLOAT32_C(  795.02), SIMDE_FLOAT32_C(   81.37)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(   39.87), SIMDE_FLOAT32_C(  836.30), SIMDE_FLOAT32_C(  789.65), SIMDE_FLOAT32_C( -610.19)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(   39.87), SIMDE_FLOAT32_C(  789.65), SIMDE_FLOAT32_C( -610.19), SIMDE_FLOAT32_C(  836.30)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -481.86), SIMDE_FLOAT32_C( -460.62), SIMDE_FLOAT32_C( -786.81), SIMDE_FLOAT32_C( -875.13)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -481.86), SIMDE_FLOAT32_C( -786.81), SIMDE_FLOAT32_C( -875.13), SIMDE_FLOAT32_C( -481.86)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -899.49), SIMDE_FLOAT32_C( -538.75), SIMDE_FLOAT32_C( -204.06), SIMDE_FLOAT32_C(  714.62)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -899.49), SIMDE_FLOAT32_C( -204.06), SIMDE_FLOAT32_C( -204.06), SIMDE_FLOAT32_C(  714.62)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  866.02), SIMDE_FLOAT32_C(  -24.69), SIMDE_FLOAT32_C(  368.58), SIMDE_FLOAT32_C(  982.21)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  866.02), SIMDE_FLOAT32_C(  368.58), SIMDE_FLOAT32_C(  368.58), SIMDE_FLOAT32_C(  368.58)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -704.68), SIMDE_FLOAT32_C( -393.06), SIMDE_FLOAT32_C(  917.82), SIMDE_FLOAT32_C( -266.20)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -704.68), SIMDE_FLOAT32_C(  917.82), SIMDE_FLOAT32_C(  917.82), SIMDE_FLOAT32_C( -393.06)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -755.38), SIMDE_FLOAT32_C(  979.14), SIMDE_FLOAT32_C( -727.63), SIMDE_FLOAT32_C(   -5.13)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -755.38), SIMDE_FLOAT32_C( -727.63), SIMDE_FLOAT32_C( -727.63), SIMDE_FLOAT32_C( -755.38)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -860.81), SIMDE_FLOAT32_C(  688.80), SIMDE_FLOAT32_C(  711.16), SIMDE_FLOAT32_C( -977.00)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -860.81), SIMDE_FLOAT32_C(  711.16), SIMDE_FLOAT32_C(  688.80), SIMDE_FLOAT32_C( -977.00)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  889.51), SIMDE_FLOAT32_C(  893.93), SIMDE_FLOAT32_C( -836.21), SIMDE_FLOAT32_C( -656.76)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  889.51), SIMDE_FLOAT32_C( -836.21), SIMDE_FLOAT32_C(  893.93), SIMDE_FLOAT32_C( -836.21)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -926.57), SIMDE_FLOAT32_C( -999.83), SIMDE_FLOAT32_C(  990.17), SIMDE_FLOAT32_C(   31.34)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -926.57), SIMDE_FLOAT32_C(  990.17), SIMDE_FLOAT32_C( -999.83), SIMDE_FLOAT32_C( -999.83)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -217.80), SIMDE_FLOAT32_C(  346.78), SIMDE_FLOAT32_C(  742.45), SIMDE_FLOAT32_C( -330.69)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -217.80), SIMDE_FLOAT32_C(  742.45), SIMDE_FLOAT32_C(  346.78), SIMDE_FLOAT32_C( -217.80)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  951.30), SIMDE_FLOAT32_C(  643.52), SIMDE_FLOAT32_C( -545.08), SIMDE_FLOAT32_C(  -16.31)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  951.30), SIMDE_FLOAT32_C( -545.08), SIMDE_FLOAT32_C(  951.30), SIMDE_FLOAT32_C(  -16.31)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -172.63), SIMDE_FLOAT32_C( -201.73), SIMDE_FLOAT32_C(  682.75), SIMDE_FLOAT32_C(  917.39)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -172.63), SIMDE_FLOAT32_C(  682.75), SIMDE_FLOAT32_C( -172.63), SIMDE_FLOAT32_C(  682.75)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  375.71), SIMDE_FLOAT32_C( -604.54), SIMDE_FLOAT32_C(  473.59), SIMDE_FLOAT32_C( -812.43)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  375.71), SIMDE_FLOAT32_C(  473.59), SIMDE_FLOAT32_C(  375.71), SIMDE_FLOAT32_C( -604.54)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  404.19), SIMDE_FLOAT32_C(  421.93), SIMDE_FLOAT32_C( -109.74), SIMDE_FLOAT32_C(  979.62)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  404.19), SIMDE_FLOAT32_C( -109.74), SIMDE_FLOAT32_C(  404.19), SIMDE_FLOAT32_C(  404.19)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(   -9.51), SIMDE_FLOAT32_C(  320.85), SIMDE_FLOAT32_C(  551.37), SIMDE_FLOAT32_C( -524.69)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(   -9.51), SIMDE_FLOAT32_C(  320.85), SIMDE_FLOAT32_C( -524.69), SIMDE_FLOAT32_C( -524.69)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -265.68), SIMDE_FLOAT32_C( -223.06), SIMDE_FLOAT32_C(  287.31), SIMDE_FLOAT32_C(  730.73)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -265.68), SIMDE_FLOAT32_C( -223.06), SIMDE_FLOAT32_C(  730.73), SIMDE_FLOAT32_C(  287.31)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  706.20), SIMDE_FLOAT32_C( -329.19), SIMDE_FLOAT32_C(  979.88), SIMDE_FLOAT32_C( -522.02)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  706.20), SIMDE_FLOAT32_C( -329.19), SIMDE_FLOAT32_C( -522.02), SIMDE_FLOAT32_C( -329.19)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -962.08), SIMDE_FLOAT32_C(  111.64), SIMDE_FLOAT32_C(  371.10), SIMDE_FLOAT32_C(  702.39)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -962.08), SIMDE_FLOAT32_C(  111.64), SIMDE_FLOAT32_C(  702.39), SIMDE_FLOAT32_C( -962.08)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  702.98), SIMDE_FLOAT32_C(  257.14), SIMDE_FLOAT32_C( -535.16), SIMDE_FLOAT32_C(  685.04)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  702.98), SIMDE_FLOAT32_C(  257.14), SIMDE_FLOAT32_C( -535.16), SIMDE_FLOAT32_C(  685.04)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -113.46), SIMDE_FLOAT32_C(  477.77), SIMDE_FLOAT32_C(  273.91), SIMDE_FLOAT32_C(  752.11)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -113.46), SIMDE_FLOAT32_C(  477.77), SIMDE_FLOAT32_C(  273.91), SIMDE_FLOAT32_C(  273.91)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -356.23), SIMDE_FLOAT32_C( -632.01), SIMDE_FLOAT32_C( -871.42), SIMDE_FLOAT32_C(  780.30)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -356.23), SIMDE_FLOAT32_C( -632.01), SIMDE_FLOAT32_C( -871.42), SIMDE_FLOAT32_C( -632.01)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -472.28), SIMDE_FLOAT32_C( -560.56), SIMDE_FLOAT32_C( -218.52), SIMDE_FLOAT32_C( -803.86)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -472.28), SIMDE_FLOAT32_C( -560.56), SIMDE_FLOAT32_C( -218.52), SIMDE_FLOAT32_C( -472.28)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  592.05), SIMDE_FLOAT32_C(  232.25), SIMDE_FLOAT32_C(  475.73), SIMDE_FLOAT32_C( -434.99)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  592.05), SIMDE_FLOAT32_C(  232.25), SIMDE_FLOAT32_C(  232.25), SIMDE_FLOAT32_C( -434.99)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  315.20), SIMDE_FLOAT32_C( -129.42), SIMDE_FLOAT32_C( -821.99), SIMDE_FLOAT32_C(  927.34)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  315.20), SIMDE_FLOAT32_C( -129.42), SIMDE_FLOAT32_C( -129.42), SIMDE_FLOAT32_C( -821.99)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -553.95), SIMDE_FLOAT32_C( -619.72), SIMDE_FLOAT32_C(  568.11), SIMDE_FLOAT32_C( -797.12)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -553.95), SIMDE_FLOAT32_C( -619.72), SIMDE_FLOAT32_C( -619.72), SIMDE_FLOAT32_C( -619.72)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  812.31), SIMDE_FLOAT32_C(   17.79), SIMDE_FLOAT32_C(  126.94), SIMDE_FLOAT32_C( -867.58)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  812.31), SIMDE_FLOAT32_C(   17.79), SIMDE_FLOAT32_C(   17.79), SIMDE_FLOAT32_C(  812.31)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  232.37), SIMDE_FLOAT32_C(  -92.15), SIMDE_FLOAT32_C(  971.17), SIMDE_FLOAT32_C( -839.59)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  232.37), SIMDE_FLOAT32_C(  -92.15), SIMDE_FLOAT32_C(  232.37), SIMDE_FLOAT32_C( -839.59)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  997.75), SIMDE_FLOAT32_C(   95.89), SIMDE_FLOAT32_C(  348.67), SIMDE_FLOAT32_C(  475.83)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  997.75), SIMDE_FLOAT32_C(   95.89), SIMDE_FLOAT32_C(  997.75), SIMDE_FLOAT32_C(  348.67)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  221.51), SIMDE_FLOAT32_C(  311.37), SIMDE_FLOAT32_C(   71.62), SIMDE_FLOAT32_C(  301.39)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  221.51), SIMDE_FLOAT32_C(  311.37), SIMDE_FLOAT32_C(  221.51), SIMDE_FLOAT32_C(  311.37)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -747.80), SIMDE_FLOAT32_C( -805.96), SIMDE_FLOAT32_C(  908.27), SIMDE_FLOAT32_C(  472.56)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -747.80), SIMDE_FLOAT32_C( -805.96), SIMDE_FLOAT32_C( -747.80), SIMDE_FLOAT32_C( -747.80)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  437.35), SIMDE_FLOAT32_C( -737.70), SIMDE_FLOAT32_C(  155.10), SIMDE_FLOAT32_C(  321.68)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  437.35), SIMDE_FLOAT32_C(  437.35), SIMDE_FLOAT32_C(  321.68), SIMDE_FLOAT32_C(  321.68)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -133.46), SIMDE_FLOAT32_C( -714.68), SIMDE_FLOAT32_C(   55.41), SIMDE_FLOAT32_C( -926.71)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -133.46), SIMDE_FLOAT32_C( -133.46), SIMDE_FLOAT32_C( -926.71), SIMDE_FLOAT32_C(   55.41)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -812.91), SIMDE_FLOAT32_C(  510.47), SIMDE_FLOAT32_C(  800.40), SIMDE_FLOAT32_C(  217.56)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -812.91), SIMDE_FLOAT32_C( -812.91), SIMDE_FLOAT32_C(  217.56), SIMDE_FLOAT32_C(  510.47)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -284.97), SIMDE_FLOAT32_C(  652.12), SIMDE_FLOAT32_C(  834.31), SIMDE_FLOAT32_C(  571.81)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -284.97), SIMDE_FLOAT32_C( -284.97), SIMDE_FLOAT32_C(  571.81), SIMDE_FLOAT32_C( -284.97)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -825.59), SIMDE_FLOAT32_C(  953.50), SIMDE_FLOAT32_C( -232.76), SIMDE_FLOAT32_C( -445.55)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -825.59), SIMDE_FLOAT32_C( -825.59), SIMDE_FLOAT32_C( -232.76), SIMDE_FLOAT32_C( -445.55)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  -60.73), SIMDE_FLOAT32_C( -208.22), SIMDE_FLOAT32_C(  396.19), SIMDE_FLOAT32_C(  971.01)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  -60.73), SIMDE_FLOAT32_C(  -60.73), SIMDE_FLOAT32_C(  396.19), SIMDE_FLOAT32_C(  396.19)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -353.30), SIMDE_FLOAT32_C( -243.97), SIMDE_FLOAT32_C(   81.44), SIMDE_FLOAT32_C(   25.19)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -353.30), SIMDE_FLOAT32_C( -353.30), SIMDE_FLOAT32_C(   81.44), SIMDE_FLOAT32_C( -243.97)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -530.50), SIMDE_FLOAT32_C(  784.73), SIMDE_FLOAT32_C(  861.67), SIMDE_FLOAT32_C( -393.30)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -530.50), SIMDE_FLOAT32_C( -530.50), SIMDE_FLOAT32_C(  861.67), SIMDE_FLOAT32_C( -530.50)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -836.54), SIMDE_FLOAT32_C(  530.58), SIMDE_FLOAT32_C(  734.13), SIMDE_FLOAT32_C( -153.69)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -836.54), SIMDE_FLOAT32_C( -836.54), SIMDE_FLOAT32_C(  530.58), SIMDE_FLOAT32_C( -153.69)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  896.09), SIMDE_FLOAT32_C(  879.36), SIMDE_FLOAT32_C( -729.20), SIMDE_FLOAT32_C(  888.62)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(  896.09), SIMDE_FLOAT32_C(  896.09), SIMDE_FLOAT32_C(  879.36), SIMDE_FLOAT32_C( -729.20)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -516.39), SIMDE_FLOAT32_C(   11.39), SIMDE_FLOAT32_C( -470.70), SIMDE_FLOAT32_C(  347.30)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -516.39), SIMDE_FLOAT32_C( -516.39), SIMDE_FLOAT32_C(   11.39), SIMDE_FLOAT32_C(   11.39)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -707.64), SIMDE_FLOAT32_C(  575.89), SIMDE_FLOAT32_C(  823.35), SIMDE_FLOAT32_C( -160.23)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -707.64), SIMDE_FLOAT32_C( -707.64), SIMDE_FLOAT32_C(  575.89), SIMDE_FLOAT32_C( -707.64)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -325.65), SIMDE_FLOAT32_C(  933.15), SIMDE_FLOAT32_C( -902.46), SIMDE_FLOAT32_C( -599.01)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -325.65), SIMDE_FLOAT32_C( -325.65), SIMDE_FLOAT32_C( -325.65), SIMDE_FLOAT32_C( -599.01)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -367.38), SIMDE_FLOAT32_C(   -2.74), SIMDE_FLOAT32_C( -966.16), SIMDE_FLOAT32_C(  463.85)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -367.38), SIMDE_FLOAT32_C( -367.38), SIMDE_FLOAT32_C( -367.38), SIMDE_FLOAT32_C( -966.16)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C( -364.34), SIMDE_FLOAT32_C( -585.44), SIMDE_FLOAT32_C( -474.18), SIMDE_FLOAT32_C( -283.75)),
          simde_mm_set_ps(SIMDE_FLOAT32_C( -364.34), SIMDE_FLOAT32_C( -364.34), SIMDE_FLOAT32_C( -364.34), SIMDE_FLOAT32_C( -585.44)) },
        { simde_mm_set_ps(SIMDE_FLOAT32_C(  478.28), SIMDE_FLOAT32_C(  950.77), SIMDE_FLOAT32_C( -169.72), SIMDE_FLOAT32_C( -119.76)),
          simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
      },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r;

    r = simde_mm_permute_ps(test_vec[i].p[  0].a,   0);
    simde_assert_m128_f32_equal(r, test_vec[i].p[  0].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[  1].a,   1);
    simde_assert_m128_f32_equal(r, test_vec[i].p[  1].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[  2].a,   2);
    simde_assert_m128_f32_equal(r, test_vec[i].p[  2].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[  3].a,   3);
    simde_assert_m128_f32_equal(r, test_vec[i].p[  3].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[  4].a,   4);
    simde_assert_m128_f32_equal(r, test_vec[i].p[  4].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[  5].a,   5);
    simde_assert_m128_f32_equal(r, test_vec[i].p[  5].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[  6].a,   6);
    simde_assert_m128_f32_equal(r, test_vec[i].p[  6].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[  7].a,   7);
    simde_assert_m128_f32_equal(r, test_vec[i].p[  7].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[  8].a,   8);
    simde_assert_m128_f32_equal(r, test_vec[i].p[  8].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[  9].a,   9);
    simde_assert_m128_f32_equal(r, test_vec[i].p[  9].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 10].a,  10);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 10].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 11].a,  11);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 11].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 12].a,  12);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 12].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 13].a,  13);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 13].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 14].a,  14);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 14].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 15].a,  15);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 15].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 16].a,  16);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 16].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 17].a,  17);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 17].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 18].a,  18);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 18].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 19].a,  19);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 19].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 20].a,  20);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 20].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 21].a,  21);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 21].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 22].a,  22);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 22].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 23].a,  23);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 23].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 24].a,  24);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 24].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 25].a,  25);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 25].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 26].a,  26);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 26].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 27].a,  27);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 27].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 28].a,  28);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 28].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 29].a,  29);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 29].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 30].a,  30);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 30].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 31].a,  31);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 31].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 32].a,  32);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 32].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 33].a,  33);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 33].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 34].a,  34);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 34].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 35].a,  35);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 35].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 36].a,  36);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 36].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 37].a,  37);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 37].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 38].a,  38);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 38].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 39].a,  39);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 39].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 40].a,  40);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 40].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 41].a,  41);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 41].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 42].a,  42);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 42].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 43].a,  43);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 43].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 44].a,  44);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 44].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 45].a,  45);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 45].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 46].a,  46);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 46].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 47].a,  47);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 47].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 48].a,  48);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 48].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 49].a,  49);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 49].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 50].a,  50);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 50].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 51].a,  51);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 51].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 52].a,  52);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 52].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 53].a,  53);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 53].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 54].a,  54);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 54].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 55].a,  55);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 55].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 56].a,  56);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 56].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 57].a,  57);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 57].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 58].a,  58);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 58].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 59].a,  59);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 59].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 60].a,  60);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 60].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 61].a,  61);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 61].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 62].a,  62);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 62].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 63].a,  63);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 63].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 64].a,  64);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 64].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 65].a,  65);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 65].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 66].a,  66);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 66].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 67].a,  67);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 67].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 68].a,  68);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 68].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 69].a,  69);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 69].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 70].a,  70);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 70].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 71].a,  71);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 71].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 72].a,  72);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 72].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 73].a,  73);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 73].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 74].a,  74);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 74].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 75].a,  75);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 75].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 76].a,  76);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 76].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 77].a,  77);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 77].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 78].a,  78);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 78].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 79].a,  79);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 79].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 80].a,  80);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 80].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 81].a,  81);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 81].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 82].a,  82);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 82].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 83].a,  83);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 83].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 84].a,  84);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 84].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 85].a,  85);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 85].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 86].a,  86);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 86].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 87].a,  87);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 87].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 88].a,  88);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 88].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 89].a,  89);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 89].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 90].a,  90);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 90].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 91].a,  91);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 91].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 92].a,  92);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 92].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 93].a,  93);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 93].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 94].a,  94);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 94].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 95].a,  95);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 95].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 96].a,  96);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 96].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 97].a,  97);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 97].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 98].a,  98);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 98].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[ 99].a,  99);
    simde_assert_m128_f32_equal(r, test_vec[i].p[ 99].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[100].a, 100);
    simde_assert_m128_f32_equal(r, test_vec[i].p[100].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[101].a, 101);
    simde_assert_m128_f32_equal(r, test_vec[i].p[101].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[102].a, 102);
    simde_assert_m128_f32_equal(r, test_vec[i].p[102].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[103].a, 103);
    simde_assert_m128_f32_equal(r, test_vec[i].p[103].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[104].a, 104);
    simde_assert_m128_f32_equal(r, test_vec[i].p[104].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[105].a, 105);
    simde_assert_m128_f32_equal(r, test_vec[i].p[105].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[106].a, 106);
    simde_assert_m128_f32_equal(r, test_vec[i].p[106].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[107].a, 107);
    simde_assert_m128_f32_equal(r, test_vec[i].p[107].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[108].a, 108);
    simde_assert_m128_f32_equal(r, test_vec[i].p[108].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[109].a, 109);
    simde_assert_m128_f32_equal(r, test_vec[i].p[109].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[110].a, 110);
    simde_assert_m128_f32_equal(r, test_vec[i].p[110].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[111].a, 111);
    simde_assert_m128_f32_equal(r, test_vec[i].p[111].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[112].a, 112);
    simde_assert_m128_f32_equal(r, test_vec[i].p[112].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[113].a, 113);
    simde_assert_m128_f32_equal(r, test_vec[i].p[113].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[114].a, 114);
    simde_assert_m128_f32_equal(r, test_vec[i].p[114].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[115].a, 115);
    simde_assert_m128_f32_equal(r, test_vec[i].p[115].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[116].a, 116);
    simde_assert_m128_f32_equal(r, test_vec[i].p[116].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[117].a, 117);
    simde_assert_m128_f32_equal(r, test_vec[i].p[117].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[118].a, 118);
    simde_assert_m128_f32_equal(r, test_vec[i].p[118].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[119].a, 119);
    simde_assert_m128_f32_equal(r, test_vec[i].p[119].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[120].a, 120);
    simde_assert_m128_f32_equal(r, test_vec[i].p[120].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[121].a, 121);
    simde_assert_m128_f32_equal(r, test_vec[i].p[121].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[122].a, 122);
    simde_assert_m128_f32_equal(r, test_vec[i].p[122].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[123].a, 123);
    simde_assert_m128_f32_equal(r, test_vec[i].p[123].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[124].a, 124);
    simde_assert_m128_f32_equal(r, test_vec[i].p[124].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[125].a, 125);
    simde_assert_m128_f32_equal(r, test_vec[i].p[125].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[126].a, 126);
    simde_assert_m128_f32_equal(r, test_vec[i].p[126].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[127].a, 127);
    simde_assert_m128_f32_equal(r, test_vec[i].p[127].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[128].a, 128);
    simde_assert_m128_f32_equal(r, test_vec[i].p[128].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[129].a, 129);
    simde_assert_m128_f32_equal(r, test_vec[i].p[129].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[130].a, 130);
    simde_assert_m128_f32_equal(r, test_vec[i].p[130].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[131].a, 131);
    simde_assert_m128_f32_equal(r, test_vec[i].p[131].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[132].a, 132);
    simde_assert_m128_f32_equal(r, test_vec[i].p[132].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[133].a, 133);
    simde_assert_m128_f32_equal(r, test_vec[i].p[133].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[134].a, 134);
    simde_assert_m128_f32_equal(r, test_vec[i].p[134].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[135].a, 135);
    simde_assert_m128_f32_equal(r, test_vec[i].p[135].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[136].a, 136);
    simde_assert_m128_f32_equal(r, test_vec[i].p[136].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[137].a, 137);
    simde_assert_m128_f32_equal(r, test_vec[i].p[137].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[138].a, 138);
    simde_assert_m128_f32_equal(r, test_vec[i].p[138].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[139].a, 139);
    simde_assert_m128_f32_equal(r, test_vec[i].p[139].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[140].a, 140);
    simde_assert_m128_f32_equal(r, test_vec[i].p[140].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[141].a, 141);
    simde_assert_m128_f32_equal(r, test_vec[i].p[141].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[142].a, 142);
    simde_assert_m128_f32_equal(r, test_vec[i].p[142].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[143].a, 143);
    simde_assert_m128_f32_equal(r, test_vec[i].p[143].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[144].a, 144);
    simde_assert_m128_f32_equal(r, test_vec[i].p[144].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[145].a, 145);
    simde_assert_m128_f32_equal(r, test_vec[i].p[145].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[146].a, 146);
    simde_assert_m128_f32_equal(r, test_vec[i].p[146].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[147].a, 147);
    simde_assert_m128_f32_equal(r, test_vec[i].p[147].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[148].a, 148);
    simde_assert_m128_f32_equal(r, test_vec[i].p[148].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[149].a, 149);
    simde_assert_m128_f32_equal(r, test_vec[i].p[149].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[150].a, 150);
    simde_assert_m128_f32_equal(r, test_vec[i].p[150].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[151].a, 151);
    simde_assert_m128_f32_equal(r, test_vec[i].p[151].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[152].a, 152);
    simde_assert_m128_f32_equal(r, test_vec[i].p[152].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[153].a, 153);
    simde_assert_m128_f32_equal(r, test_vec[i].p[153].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[154].a, 154);
    simde_assert_m128_f32_equal(r, test_vec[i].p[154].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[155].a, 155);
    simde_assert_m128_f32_equal(r, test_vec[i].p[155].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[156].a, 156);
    simde_assert_m128_f32_equal(r, test_vec[i].p[156].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[157].a, 157);
    simde_assert_m128_f32_equal(r, test_vec[i].p[157].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[158].a, 158);
    simde_assert_m128_f32_equal(r, test_vec[i].p[158].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[159].a, 159);
    simde_assert_m128_f32_equal(r, test_vec[i].p[159].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[160].a, 160);
    simde_assert_m128_f32_equal(r, test_vec[i].p[160].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[161].a, 161);
    simde_assert_m128_f32_equal(r, test_vec[i].p[161].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[162].a, 162);
    simde_assert_m128_f32_equal(r, test_vec[i].p[162].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[163].a, 163);
    simde_assert_m128_f32_equal(r, test_vec[i].p[163].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[164].a, 164);
    simde_assert_m128_f32_equal(r, test_vec[i].p[164].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[165].a, 165);
    simde_assert_m128_f32_equal(r, test_vec[i].p[165].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[166].a, 166);
    simde_assert_m128_f32_equal(r, test_vec[i].p[166].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[167].a, 167);
    simde_assert_m128_f32_equal(r, test_vec[i].p[167].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[168].a, 168);
    simde_assert_m128_f32_equal(r, test_vec[i].p[168].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[169].a, 169);
    simde_assert_m128_f32_equal(r, test_vec[i].p[169].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[170].a, 170);
    simde_assert_m128_f32_equal(r, test_vec[i].p[170].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[171].a, 171);
    simde_assert_m128_f32_equal(r, test_vec[i].p[171].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[172].a, 172);
    simde_assert_m128_f32_equal(r, test_vec[i].p[172].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[173].a, 173);
    simde_assert_m128_f32_equal(r, test_vec[i].p[173].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[174].a, 174);
    simde_assert_m128_f32_equal(r, test_vec[i].p[174].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[175].a, 175);
    simde_assert_m128_f32_equal(r, test_vec[i].p[175].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[176].a, 176);
    simde_assert_m128_f32_equal(r, test_vec[i].p[176].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[177].a, 177);
    simde_assert_m128_f32_equal(r, test_vec[i].p[177].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[178].a, 178);
    simde_assert_m128_f32_equal(r, test_vec[i].p[178].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[179].a, 179);
    simde_assert_m128_f32_equal(r, test_vec[i].p[179].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[180].a, 180);
    simde_assert_m128_f32_equal(r, test_vec[i].p[180].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[181].a, 181);
    simde_assert_m128_f32_equal(r, test_vec[i].p[181].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[182].a, 182);
    simde_assert_m128_f32_equal(r, test_vec[i].p[182].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[183].a, 183);
    simde_assert_m128_f32_equal(r, test_vec[i].p[183].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[184].a, 184);
    simde_assert_m128_f32_equal(r, test_vec[i].p[184].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[185].a, 185);
    simde_assert_m128_f32_equal(r, test_vec[i].p[185].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[186].a, 186);
    simde_assert_m128_f32_equal(r, test_vec[i].p[186].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[187].a, 187);
    simde_assert_m128_f32_equal(r, test_vec[i].p[187].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[188].a, 188);
    simde_assert_m128_f32_equal(r, test_vec[i].p[188].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[189].a, 189);
    simde_assert_m128_f32_equal(r, test_vec[i].p[189].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[190].a, 190);
    simde_assert_m128_f32_equal(r, test_vec[i].p[190].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[191].a, 191);
    simde_assert_m128_f32_equal(r, test_vec[i].p[191].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[192].a, 192);
    simde_assert_m128_f32_equal(r, test_vec[i].p[192].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[193].a, 193);
    simde_assert_m128_f32_equal(r, test_vec[i].p[193].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[194].a, 194);
    simde_assert_m128_f32_equal(r, test_vec[i].p[194].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[195].a, 195);
    simde_assert_m128_f32_equal(r, test_vec[i].p[195].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[196].a, 196);
    simde_assert_m128_f32_equal(r, test_vec[i].p[196].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[197].a, 197);
    simde_assert_m128_f32_equal(r, test_vec[i].p[197].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[198].a, 198);
    simde_assert_m128_f32_equal(r, test_vec[i].p[198].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[199].a, 199);
    simde_assert_m128_f32_equal(r, test_vec[i].p[199].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[200].a, 200);
    simde_assert_m128_f32_equal(r, test_vec[i].p[200].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[201].a, 201);
    simde_assert_m128_f32_equal(r, test_vec[i].p[201].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[202].a, 202);
    simde_assert_m128_f32_equal(r, test_vec[i].p[202].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[203].a, 203);
    simde_assert_m128_f32_equal(r, test_vec[i].p[203].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[204].a, 204);
    simde_assert_m128_f32_equal(r, test_vec[i].p[204].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[205].a, 205);
    simde_assert_m128_f32_equal(r, test_vec[i].p[205].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[206].a, 206);
    simde_assert_m128_f32_equal(r, test_vec[i].p[206].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[207].a, 207);
    simde_assert_m128_f32_equal(r, test_vec[i].p[207].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[208].a, 208);
    simde_assert_m128_f32_equal(r, test_vec[i].p[208].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[209].a, 209);
    simde_assert_m128_f32_equal(r, test_vec[i].p[209].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[210].a, 210);
    simde_assert_m128_f32_equal(r, test_vec[i].p[210].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[211].a, 211);
    simde_assert_m128_f32_equal(r, test_vec[i].p[211].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[212].a, 212);
    simde_assert_m128_f32_equal(r, test_vec[i].p[212].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[213].a, 213);
    simde_assert_m128_f32_equal(r, test_vec[i].p[213].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[214].a, 214);
    simde_assert_m128_f32_equal(r, test_vec[i].p[214].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[215].a, 215);
    simde_assert_m128_f32_equal(r, test_vec[i].p[215].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[216].a, 216);
    simde_assert_m128_f32_equal(r, test_vec[i].p[216].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[217].a, 217);
    simde_assert_m128_f32_equal(r, test_vec[i].p[217].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[218].a, 218);
    simde_assert_m128_f32_equal(r, test_vec[i].p[218].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[219].a, 219);
    simde_assert_m128_f32_equal(r, test_vec[i].p[219].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[220].a, 220);
    simde_assert_m128_f32_equal(r, test_vec[i].p[220].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[221].a, 221);
    simde_assert_m128_f32_equal(r, test_vec[i].p[221].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[222].a, 222);
    simde_assert_m128_f32_equal(r, test_vec[i].p[222].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[223].a, 223);
    simde_assert_m128_f32_equal(r, test_vec[i].p[223].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[224].a, 224);
    simde_assert_m128_f32_equal(r, test_vec[i].p[224].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[225].a, 225);
    simde_assert_m128_f32_equal(r, test_vec[i].p[225].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[226].a, 226);
    simde_assert_m128_f32_equal(r, test_vec[i].p[226].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[227].a, 227);
    simde_assert_m128_f32_equal(r, test_vec[i].p[227].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[228].a, 228);
    simde_assert_m128_f32_equal(r, test_vec[i].p[228].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[229].a, 229);
    simde_assert_m128_f32_equal(r, test_vec[i].p[229].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[230].a, 230);
    simde_assert_m128_f32_equal(r, test_vec[i].p[230].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[231].a, 231);
    simde_assert_m128_f32_equal(r, test_vec[i].p[231].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[232].a, 232);
    simde_assert_m128_f32_equal(r, test_vec[i].p[232].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[233].a, 233);
    simde_assert_m128_f32_equal(r, test_vec[i].p[233].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[234].a, 234);
    simde_assert_m128_f32_equal(r, test_vec[i].p[234].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[235].a, 235);
    simde_assert_m128_f32_equal(r, test_vec[i].p[235].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[236].a, 236);
    simde_assert_m128_f32_equal(r, test_vec[i].p[236].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[237].a, 237);
    simde_assert_m128_f32_equal(r, test_vec[i].p[237].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[238].a, 238);
    simde_assert_m128_f32_equal(r, test_vec[i].p[238].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[239].a, 239);
    simde_assert_m128_f32_equal(r, test_vec[i].p[239].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[240].a, 240);
    simde_assert_m128_f32_equal(r, test_vec[i].p[240].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[241].a, 241);
    simde_assert_m128_f32_equal(r, test_vec[i].p[241].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[242].a, 242);
    simde_assert_m128_f32_equal(r, test_vec[i].p[242].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[243].a, 243);
    simde_assert_m128_f32_equal(r, test_vec[i].p[243].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[244].a, 244);
    simde_assert_m128_f32_equal(r, test_vec[i].p[244].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[245].a, 245);
    simde_assert_m128_f32_equal(r, test_vec[i].p[245].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[246].a, 246);
    simde_assert_m128_f32_equal(r, test_vec[i].p[246].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[247].a, 247);
    simde_assert_m128_f32_equal(r, test_vec[i].p[247].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[248].a, 248);
    simde_assert_m128_f32_equal(r, test_vec[i].p[248].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[249].a, 249);
    simde_assert_m128_f32_equal(r, test_vec[i].p[249].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[250].a, 250);
    simde_assert_m128_f32_equal(r, test_vec[i].p[250].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[251].a, 251);
    simde_assert_m128_f32_equal(r, test_vec[i].p[251].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[252].a, 252);
    simde_assert_m128_f32_equal(r, test_vec[i].p[252].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[253].a, 253);
    simde_assert_m128_f32_equal(r, test_vec[i].p[253].r, 1);

    r = simde_mm_permute_ps(test_vec[i].p[254].a, 254);
    simde_assert_m128_f32_equal(r, test_vec[i].p[254].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_permute_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a[4];
    simde__m256d r[4];
  } test_vec[8] = {
    { { simde_mm256_set_pd(SIMDE_FLOAT64_C( -307.33), SIMDE_FLOAT64_C( -277.83),
                           SIMDE_FLOAT64_C( -811.26), SIMDE_FLOAT64_C( -340.98)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  520.01), SIMDE_FLOAT64_C(   20.96),
                           SIMDE_FLOAT64_C( -217.27), SIMDE_FLOAT64_C(  475.98)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -236.99), SIMDE_FLOAT64_C( -515.97),
                           SIMDE_FLOAT64_C( -252.10), SIMDE_FLOAT64_C( -367.50)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -740.61), SIMDE_FLOAT64_C(  459.66),
                           SIMDE_FLOAT64_C(  780.67), SIMDE_FLOAT64_C( -928.66)) },
      { simde_mm256_set_pd(SIMDE_FLOAT64_C( -277.83), SIMDE_FLOAT64_C( -277.83),
                           SIMDE_FLOAT64_C( -340.98), SIMDE_FLOAT64_C( -340.98)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(   20.96), SIMDE_FLOAT64_C(   20.96),
                           SIMDE_FLOAT64_C(  475.98), SIMDE_FLOAT64_C( -217.27)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -515.97), SIMDE_FLOAT64_C( -515.97),
                           SIMDE_FLOAT64_C( -252.10), SIMDE_FLOAT64_C( -367.50)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  459.66), SIMDE_FLOAT64_C(  459.66),
                           SIMDE_FLOAT64_C(  780.67), SIMDE_FLOAT64_C(  780.67)) } },
    { { simde_mm256_set_pd(SIMDE_FLOAT64_C(  718.00), SIMDE_FLOAT64_C( -514.42),
                           SIMDE_FLOAT64_C( -222.91), SIMDE_FLOAT64_C( -665.22)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  431.31), SIMDE_FLOAT64_C( -787.13),
                           SIMDE_FLOAT64_C( -902.93), SIMDE_FLOAT64_C( -601.27)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -645.66), SIMDE_FLOAT64_C(  168.66),
                           SIMDE_FLOAT64_C(  823.10), SIMDE_FLOAT64_C(  348.53)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -855.11), SIMDE_FLOAT64_C(  343.83),
                           SIMDE_FLOAT64_C(  888.93), SIMDE_FLOAT64_C(   81.36)) },
      { simde_mm256_set_pd(SIMDE_FLOAT64_C( -514.42), SIMDE_FLOAT64_C( -514.42),
                           SIMDE_FLOAT64_C( -665.22), SIMDE_FLOAT64_C( -665.22)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -787.13), SIMDE_FLOAT64_C( -787.13),
                           SIMDE_FLOAT64_C( -601.27), SIMDE_FLOAT64_C( -902.93)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  168.66), SIMDE_FLOAT64_C(  168.66),
                           SIMDE_FLOAT64_C(  823.10), SIMDE_FLOAT64_C(  348.53)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  343.83), SIMDE_FLOAT64_C(  343.83),
                           SIMDE_FLOAT64_C(  888.93), SIMDE_FLOAT64_C(  888.93)) } },
    { { simde_mm256_set_pd(SIMDE_FLOAT64_C(  482.80), SIMDE_FLOAT64_C(  651.20),
                           SIMDE_FLOAT64_C( -299.11), SIMDE_FLOAT64_C(  660.92)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  562.16), SIMDE_FLOAT64_C( -407.46),
                           SIMDE_FLOAT64_C(  470.74), SIMDE_FLOAT64_C(  663.86)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -609.81), SIMDE_FLOAT64_C(  224.41),
                           SIMDE_FLOAT64_C(  638.76), SIMDE_FLOAT64_C(  609.66)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  950.61), SIMDE_FLOAT64_C( -221.62),
                           SIMDE_FLOAT64_C(  198.64), SIMDE_FLOAT64_C(  472.05)) },
      { simde_mm256_set_pd(SIMDE_FLOAT64_C(  651.20), SIMDE_FLOAT64_C(  651.20),
                           SIMDE_FLOAT64_C(  660.92), SIMDE_FLOAT64_C(  660.92)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -407.46), SIMDE_FLOAT64_C( -407.46),
                           SIMDE_FLOAT64_C(  663.86), SIMDE_FLOAT64_C(  470.74)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  224.41), SIMDE_FLOAT64_C(  224.41),
                           SIMDE_FLOAT64_C(  638.76), SIMDE_FLOAT64_C(  609.66)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -221.62), SIMDE_FLOAT64_C( -221.62),
                           SIMDE_FLOAT64_C(  198.64), SIMDE_FLOAT64_C(  198.64)) } },
    { { simde_mm256_set_pd(SIMDE_FLOAT64_C( -304.11), SIMDE_FLOAT64_C(  887.38),
                           SIMDE_FLOAT64_C(  -49.50), SIMDE_FLOAT64_C( -449.56)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -667.31), SIMDE_FLOAT64_C(  293.87),
                           SIMDE_FLOAT64_C( -667.79), SIMDE_FLOAT64_C(  371.99)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  895.41), SIMDE_FLOAT64_C(  116.14),
                           SIMDE_FLOAT64_C(   65.95), SIMDE_FLOAT64_C( -990.78)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -751.37), SIMDE_FLOAT64_C( -570.35),
                           SIMDE_FLOAT64_C(  -32.79), SIMDE_FLOAT64_C(  337.40)) },
      { simde_mm256_set_pd(SIMDE_FLOAT64_C(  887.38), SIMDE_FLOAT64_C(  887.38),
                           SIMDE_FLOAT64_C( -449.56), SIMDE_FLOAT64_C( -449.56)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  293.87), SIMDE_FLOAT64_C(  293.87),
                           SIMDE_FLOAT64_C(  371.99), SIMDE_FLOAT64_C( -667.79)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  116.14), SIMDE_FLOAT64_C(  116.14),
                           SIMDE_FLOAT64_C(   65.95), SIMDE_FLOAT64_C( -990.78)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -570.35), SIMDE_FLOAT64_C( -570.35),
                           SIMDE_FLOAT64_C(  -32.79), SIMDE_FLOAT64_C(  -32.79)) } },
    { { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -78.53), SIMDE_FLOAT64_C( -723.45),
                           SIMDE_FLOAT64_C( -594.84), SIMDE_FLOAT64_C( -504.83)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  599.38), SIMDE_FLOAT64_C( -102.58),
                           SIMDE_FLOAT64_C(  369.99), SIMDE_FLOAT64_C(  -58.86)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -705.85), SIMDE_FLOAT64_C( -561.88),
                           SIMDE_FLOAT64_C( -855.33), SIMDE_FLOAT64_C( -876.41)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  200.30), SIMDE_FLOAT64_C( -816.59),
                           SIMDE_FLOAT64_C(  495.88), SIMDE_FLOAT64_C(  -20.39)) },
      { simde_mm256_set_pd(SIMDE_FLOAT64_C( -723.45), SIMDE_FLOAT64_C( -723.45),
                           SIMDE_FLOAT64_C( -504.83), SIMDE_FLOAT64_C( -504.83)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -102.58), SIMDE_FLOAT64_C( -102.58),
                           SIMDE_FLOAT64_C(  -58.86), SIMDE_FLOAT64_C(  369.99)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -561.88), SIMDE_FLOAT64_C( -561.88),
                           SIMDE_FLOAT64_C( -855.33), SIMDE_FLOAT64_C( -876.41)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -816.59), SIMDE_FLOAT64_C( -816.59),
                           SIMDE_FLOAT64_C(  495.88), SIMDE_FLOAT64_C(  495.88)) } },
    { { simde_mm256_set_pd(SIMDE_FLOAT64_C( -459.43), SIMDE_FLOAT64_C(   35.05),
                           SIMDE_FLOAT64_C( -647.26), SIMDE_FLOAT64_C( -116.28)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  861.84), SIMDE_FLOAT64_C(   79.42),
                           SIMDE_FLOAT64_C(  -61.14), SIMDE_FLOAT64_C( -959.28)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -190.88), SIMDE_FLOAT64_C(   91.78),
                           SIMDE_FLOAT64_C(  624.59), SIMDE_FLOAT64_C( -875.05)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -757.98), SIMDE_FLOAT64_C( -777.95),
                           SIMDE_FLOAT64_C( -309.55), SIMDE_FLOAT64_C(  387.53)) },
      { simde_mm256_set_pd(SIMDE_FLOAT64_C(   35.05), SIMDE_FLOAT64_C(   35.05),
                           SIMDE_FLOAT64_C( -116.28), SIMDE_FLOAT64_C( -116.28)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(   79.42), SIMDE_FLOAT64_C(   79.42),
                           SIMDE_FLOAT64_C( -959.28), SIMDE_FLOAT64_C(  -61.14)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(   91.78), SIMDE_FLOAT64_C(   91.78),
                           SIMDE_FLOAT64_C(  624.59), SIMDE_FLOAT64_C( -875.05)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -777.95), SIMDE_FLOAT64_C( -777.95),
                           SIMDE_FLOAT64_C( -309.55), SIMDE_FLOAT64_C( -309.55)) } },
    { { simde_mm256_set_pd(SIMDE_FLOAT64_C( -297.45), SIMDE_FLOAT64_C( -420.28),
                           SIMDE_FLOAT64_C( -324.78), SIMDE_FLOAT64_C( -643.43)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  271.76), SIMDE_FLOAT64_C( -727.19),
                           SIMDE_FLOAT64_C(  659.23), SIMDE_FLOAT64_C(   91.29)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  751.73), SIMDE_FLOAT64_C(  366.97),
                           SIMDE_FLOAT64_C(  178.00), SIMDE_FLOAT64_C( -562.69)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  355.89), SIMDE_FLOAT64_C(  861.10),
                           SIMDE_FLOAT64_C(  814.16), SIMDE_FLOAT64_C(  218.35)) },
      { simde_mm256_set_pd(SIMDE_FLOAT64_C( -420.28), SIMDE_FLOAT64_C( -420.28),
                           SIMDE_FLOAT64_C( -643.43), SIMDE_FLOAT64_C( -643.43)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -727.19), SIMDE_FLOAT64_C( -727.19),
                           SIMDE_FLOAT64_C(   91.29), SIMDE_FLOAT64_C(  659.23)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  366.97), SIMDE_FLOAT64_C(  366.97),
                           SIMDE_FLOAT64_C(  178.00), SIMDE_FLOAT64_C( -562.69)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  861.10), SIMDE_FLOAT64_C(  861.10),
                           SIMDE_FLOAT64_C(  814.16), SIMDE_FLOAT64_C(  814.16)) } },
    { { simde_mm256_set_pd(SIMDE_FLOAT64_C( -344.58), SIMDE_FLOAT64_C( -961.29),
                           SIMDE_FLOAT64_C(  602.43), SIMDE_FLOAT64_C(  -99.06)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  915.17), SIMDE_FLOAT64_C(  886.67),
                           SIMDE_FLOAT64_C(  631.07), SIMDE_FLOAT64_C( -393.04)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  815.36), SIMDE_FLOAT64_C( -920.33),
                           SIMDE_FLOAT64_C( -701.98), SIMDE_FLOAT64_C(  230.05)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  408.01), SIMDE_FLOAT64_C( -369.61),
                           SIMDE_FLOAT64_C( -195.80), SIMDE_FLOAT64_C( -161.14)) },
      { simde_mm256_set_pd(SIMDE_FLOAT64_C( -961.29), SIMDE_FLOAT64_C( -961.29),
                           SIMDE_FLOAT64_C(  -99.06), SIMDE_FLOAT64_C(  -99.06)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  886.67), SIMDE_FLOAT64_C(  886.67),
                           SIMDE_FLOAT64_C( -393.04), SIMDE_FLOAT64_C(  631.07)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -920.33), SIMDE_FLOAT64_C( -920.33),
                           SIMDE_FLOAT64_C( -701.98), SIMDE_FLOAT64_C(  230.05)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -369.61), SIMDE_FLOAT64_C( -369.61),
                           SIMDE_FLOAT64_C( -195.80), SIMDE_FLOAT64_C( -195.80)) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r;

    r = simde_mm256_permute_pd(test_vec[i].a[0], 0);
    simde_assert_m256d_f64_equal(r, test_vec[i].r[0], 1);

    r = simde_mm256_permute_pd(test_vec[i].a[1], 1);
    simde_assert_m256d_f64_equal(r, test_vec[i].r[1], 1);

    r = simde_mm256_permute_pd(test_vec[i].a[2], 2);
    simde_assert_m256d_f64_equal(r, test_vec[i].r[2], 1);

    r = simde_mm256_permute_pd(test_vec[i].a[3], 3);
    simde_assert_m256d_f64_equal(r, test_vec[i].r[3], 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_rcp_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -908.92), SIMDE_FLOAT32_C( -201.59),
                         SIMDE_FLOAT32_C(    3.47), SIMDE_FLOAT32_C(  829.08),
                         SIMDE_FLOAT32_C(  -86.36), SIMDE_FLOAT32_C(  780.02),
                         SIMDE_FLOAT32_C(   13.29), SIMDE_FLOAT32_C(  492.53)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(   -0.00),
                         SIMDE_FLOAT32_C(    0.29), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(   -0.01), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.08), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  745.72), SIMDE_FLOAT32_C( -860.90),
                         SIMDE_FLOAT32_C(  647.35), SIMDE_FLOAT32_C( -932.06),
                         SIMDE_FLOAT32_C(  782.22), SIMDE_FLOAT32_C(  232.69),
                         SIMDE_FLOAT32_C(   88.27), SIMDE_FLOAT32_C( -882.29)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(   -0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(   -0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.01), SIMDE_FLOAT32_C(   -0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  750.74), SIMDE_FLOAT32_C(  -90.83),
                         SIMDE_FLOAT32_C(  949.51), SIMDE_FLOAT32_C(  177.31),
                         SIMDE_FLOAT32_C( -204.98), SIMDE_FLOAT32_C(  340.91),
                         SIMDE_FLOAT32_C(  -39.69), SIMDE_FLOAT32_C( -715.33)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(   -0.01),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.01),
                         SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(   -0.03), SIMDE_FLOAT32_C(   -0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -147.11), SIMDE_FLOAT32_C(  588.21),
                         SIMDE_FLOAT32_C(  521.36), SIMDE_FLOAT32_C( -659.55),
                         SIMDE_FLOAT32_C(  932.00), SIMDE_FLOAT32_C(  548.33),
                         SIMDE_FLOAT32_C(  639.13), SIMDE_FLOAT32_C( -316.06)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.01), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(   -0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(   -0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -794.81), SIMDE_FLOAT32_C(   88.08),
                         SIMDE_FLOAT32_C( -540.52), SIMDE_FLOAT32_C(   32.82),
                         SIMDE_FLOAT32_C( -921.78), SIMDE_FLOAT32_C( -970.13),
                         SIMDE_FLOAT32_C(  659.29), SIMDE_FLOAT32_C( -464.98)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.01),
                         SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.03),
                         SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(   -0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(   -0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -853.91), SIMDE_FLOAT32_C(  837.38),
                         SIMDE_FLOAT32_C( -478.03), SIMDE_FLOAT32_C(  330.06),
                         SIMDE_FLOAT32_C(  627.16), SIMDE_FLOAT32_C(  535.10),
                         SIMDE_FLOAT32_C( -787.00), SIMDE_FLOAT32_C(  376.04)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -244.65), SIMDE_FLOAT32_C(  415.43),
                         SIMDE_FLOAT32_C(  415.27), SIMDE_FLOAT32_C(  243.86),
                         SIMDE_FLOAT32_C(  475.16), SIMDE_FLOAT32_C(    0.53),
                         SIMDE_FLOAT32_C( -509.99), SIMDE_FLOAT32_C( -861.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    1.89),
                         SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(   -0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -819.61), SIMDE_FLOAT32_C( -441.38),
                         SIMDE_FLOAT32_C( -736.01), SIMDE_FLOAT32_C(  681.16),
                         SIMDE_FLOAT32_C( -798.05), SIMDE_FLOAT32_C(  561.39),
                         SIMDE_FLOAT32_C(  116.98), SIMDE_FLOAT32_C( -372.62)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(   -0.00),
                         SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.01), SIMDE_FLOAT32_C(   -0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_rcp_ps(test_vec[i].a);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_round_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 nearest;
    simde__m256 neg_inf;
    simde__m256 pos_inf;
    simde__m256 truncate;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -437.99), SIMDE_FLOAT32_C(  332.86),
                         SIMDE_FLOAT32_C(  531.55), SIMDE_FLOAT32_C(  188.24),
                         SIMDE_FLOAT32_C(  135.31), SIMDE_FLOAT32_C( -341.69),
                         SIMDE_FLOAT32_C( -995.08), SIMDE_FLOAT32_C(  -84.86)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -438.00), SIMDE_FLOAT32_C(  333.00),
                         SIMDE_FLOAT32_C(  532.00), SIMDE_FLOAT32_C(  188.00),
                         SIMDE_FLOAT32_C(  135.00), SIMDE_FLOAT32_C( -342.00),
                         SIMDE_FLOAT32_C( -995.00), SIMDE_FLOAT32_C(  -85.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -438.00), SIMDE_FLOAT32_C(  332.00),
                         SIMDE_FLOAT32_C(  531.00), SIMDE_FLOAT32_C(  188.00),
                         SIMDE_FLOAT32_C(  135.00), SIMDE_FLOAT32_C( -342.00),
                         SIMDE_FLOAT32_C( -996.00), SIMDE_FLOAT32_C(  -85.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -437.00), SIMDE_FLOAT32_C(  333.00),
                         SIMDE_FLOAT32_C(  532.00), SIMDE_FLOAT32_C(  189.00),
                         SIMDE_FLOAT32_C(  136.00), SIMDE_FLOAT32_C( -341.00),
                         SIMDE_FLOAT32_C( -995.00), SIMDE_FLOAT32_C(  -84.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -437.00), SIMDE_FLOAT32_C(  332.00),
                         SIMDE_FLOAT32_C(  531.00), SIMDE_FLOAT32_C(  188.00),
                         SIMDE_FLOAT32_C(  135.00), SIMDE_FLOAT32_C( -341.00),
                         SIMDE_FLOAT32_C( -995.00), SIMDE_FLOAT32_C(  -84.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.77), SIMDE_FLOAT32_C( -902.26),
                         SIMDE_FLOAT32_C(  960.96), SIMDE_FLOAT32_C(  885.00),
                         SIMDE_FLOAT32_C(  184.99), SIMDE_FLOAT32_C(  273.55),
                         SIMDE_FLOAT32_C( -508.74), SIMDE_FLOAT32_C(  304.51)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -272.00), SIMDE_FLOAT32_C( -902.00),
                         SIMDE_FLOAT32_C(  961.00), SIMDE_FLOAT32_C(  885.00),
                         SIMDE_FLOAT32_C(  185.00), SIMDE_FLOAT32_C(  274.00),
                         SIMDE_FLOAT32_C( -509.00), SIMDE_FLOAT32_C(  305.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -272.00), SIMDE_FLOAT32_C( -903.00),
                         SIMDE_FLOAT32_C(  960.00), SIMDE_FLOAT32_C(  885.00),
                         SIMDE_FLOAT32_C(  184.00), SIMDE_FLOAT32_C(  273.00),
                         SIMDE_FLOAT32_C( -509.00), SIMDE_FLOAT32_C(  304.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.00), SIMDE_FLOAT32_C( -902.00),
                         SIMDE_FLOAT32_C(  961.00), SIMDE_FLOAT32_C(  885.00),
                         SIMDE_FLOAT32_C(  185.00), SIMDE_FLOAT32_C(  274.00),
                         SIMDE_FLOAT32_C( -508.00), SIMDE_FLOAT32_C(  305.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.00), SIMDE_FLOAT32_C( -902.00),
                         SIMDE_FLOAT32_C(  960.00), SIMDE_FLOAT32_C(  885.00),
                         SIMDE_FLOAT32_C(  184.00), SIMDE_FLOAT32_C(  273.00),
                         SIMDE_FLOAT32_C( -508.00), SIMDE_FLOAT32_C(  304.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  970.76), SIMDE_FLOAT32_C( -833.91),
                         SIMDE_FLOAT32_C( -187.58), SIMDE_FLOAT32_C(   27.59),
                         SIMDE_FLOAT32_C(  181.38), SIMDE_FLOAT32_C( -399.46),
                         SIMDE_FLOAT32_C( -127.86), SIMDE_FLOAT32_C( -393.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  971.00), SIMDE_FLOAT32_C( -834.00),
                         SIMDE_FLOAT32_C( -188.00), SIMDE_FLOAT32_C(   28.00),
                         SIMDE_FLOAT32_C(  181.00), SIMDE_FLOAT32_C( -399.00),
                         SIMDE_FLOAT32_C( -128.00), SIMDE_FLOAT32_C( -393.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  970.00), SIMDE_FLOAT32_C( -834.00),
                         SIMDE_FLOAT32_C( -188.00), SIMDE_FLOAT32_C(   27.00),
                         SIMDE_FLOAT32_C(  181.00), SIMDE_FLOAT32_C( -400.00),
                         SIMDE_FLOAT32_C( -128.00), SIMDE_FLOAT32_C( -394.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  971.00), SIMDE_FLOAT32_C( -833.00),
                         SIMDE_FLOAT32_C( -187.00), SIMDE_FLOAT32_C(   28.00),
                         SIMDE_FLOAT32_C(  182.00), SIMDE_FLOAT32_C( -399.00),
                         SIMDE_FLOAT32_C( -127.00), SIMDE_FLOAT32_C( -393.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  970.00), SIMDE_FLOAT32_C( -833.00),
                         SIMDE_FLOAT32_C( -187.00), SIMDE_FLOAT32_C(   27.00),
                         SIMDE_FLOAT32_C(  181.00), SIMDE_FLOAT32_C( -399.00),
                         SIMDE_FLOAT32_C( -127.00), SIMDE_FLOAT32_C( -393.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  259.90), SIMDE_FLOAT32_C( -282.33),
                         SIMDE_FLOAT32_C(  766.19), SIMDE_FLOAT32_C(  948.74),
                         SIMDE_FLOAT32_C( -533.05), SIMDE_FLOAT32_C(  397.75),
                         SIMDE_FLOAT32_C(  998.83), SIMDE_FLOAT32_C( -841.13)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  260.00), SIMDE_FLOAT32_C( -282.00),
                         SIMDE_FLOAT32_C(  766.00), SIMDE_FLOAT32_C(  949.00),
                         SIMDE_FLOAT32_C( -533.00), SIMDE_FLOAT32_C(  398.00),
                         SIMDE_FLOAT32_C(  999.00), SIMDE_FLOAT32_C( -841.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  259.00), SIMDE_FLOAT32_C( -283.00),
                         SIMDE_FLOAT32_C(  766.00), SIMDE_FLOAT32_C(  948.00),
                         SIMDE_FLOAT32_C( -534.00), SIMDE_FLOAT32_C(  397.00),
                         SIMDE_FLOAT32_C(  998.00), SIMDE_FLOAT32_C( -842.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  260.00), SIMDE_FLOAT32_C( -282.00),
                         SIMDE_FLOAT32_C(  767.00), SIMDE_FLOAT32_C(  949.00),
                         SIMDE_FLOAT32_C( -533.00), SIMDE_FLOAT32_C(  398.00),
                         SIMDE_FLOAT32_C(  999.00), SIMDE_FLOAT32_C( -841.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  259.00), SIMDE_FLOAT32_C( -282.00),
                         SIMDE_FLOAT32_C(  766.00), SIMDE_FLOAT32_C(  948.00),
                         SIMDE_FLOAT32_C( -533.00), SIMDE_FLOAT32_C(  397.00),
                         SIMDE_FLOAT32_C(  998.00), SIMDE_FLOAT32_C( -841.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -178.69), SIMDE_FLOAT32_C(  880.71),
                         SIMDE_FLOAT32_C( -928.72), SIMDE_FLOAT32_C( -201.24),
                         SIMDE_FLOAT32_C(  -99.45), SIMDE_FLOAT32_C(  785.84),
                         SIMDE_FLOAT32_C(  542.02), SIMDE_FLOAT32_C(  -81.93)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -179.00), SIMDE_FLOAT32_C(  881.00),
                         SIMDE_FLOAT32_C( -929.00), SIMDE_FLOAT32_C( -201.00),
                         SIMDE_FLOAT32_C(  -99.00), SIMDE_FLOAT32_C(  786.00),
                         SIMDE_FLOAT32_C(  542.00), SIMDE_FLOAT32_C(  -82.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -179.00), SIMDE_FLOAT32_C(  880.00),
                         SIMDE_FLOAT32_C( -929.00), SIMDE_FLOAT32_C( -202.00),
                         SIMDE_FLOAT32_C( -100.00), SIMDE_FLOAT32_C(  785.00),
                         SIMDE_FLOAT32_C(  542.00), SIMDE_FLOAT32_C(  -82.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -178.00), SIMDE_FLOAT32_C(  881.00),
                         SIMDE_FLOAT32_C( -928.00), SIMDE_FLOAT32_C( -201.00),
                         SIMDE_FLOAT32_C(  -99.00), SIMDE_FLOAT32_C(  786.00),
                         SIMDE_FLOAT32_C(  543.00), SIMDE_FLOAT32_C(  -81.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -178.00), SIMDE_FLOAT32_C(  880.00),
                         SIMDE_FLOAT32_C( -928.00), SIMDE_FLOAT32_C( -201.00),
                         SIMDE_FLOAT32_C(  -99.00), SIMDE_FLOAT32_C(  785.00),
                         SIMDE_FLOAT32_C(  542.00), SIMDE_FLOAT32_C(  -81.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -937.16), SIMDE_FLOAT32_C(  854.52),
                         SIMDE_FLOAT32_C(  980.48), SIMDE_FLOAT32_C(  -86.24),
                         SIMDE_FLOAT32_C(  473.38), SIMDE_FLOAT32_C(  104.75),
                         SIMDE_FLOAT32_C(   14.33), SIMDE_FLOAT32_C(   91.35)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -937.00), SIMDE_FLOAT32_C(  855.00),
                         SIMDE_FLOAT32_C(  980.00), SIMDE_FLOAT32_C(  -86.00),
                         SIMDE_FLOAT32_C(  473.00), SIMDE_FLOAT32_C(  105.00),
                         SIMDE_FLOAT32_C(   14.00), SIMDE_FLOAT32_C(   91.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -938.00), SIMDE_FLOAT32_C(  854.00),
                         SIMDE_FLOAT32_C(  980.00), SIMDE_FLOAT32_C(  -87.00),
                         SIMDE_FLOAT32_C(  473.00), SIMDE_FLOAT32_C(  104.00),
                         SIMDE_FLOAT32_C(   14.00), SIMDE_FLOAT32_C(   91.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -937.00), SIMDE_FLOAT32_C(  855.00),
                         SIMDE_FLOAT32_C(  981.00), SIMDE_FLOAT32_C(  -86.00),
                         SIMDE_FLOAT32_C(  474.00), SIMDE_FLOAT32_C(  105.00),
                         SIMDE_FLOAT32_C(   15.00), SIMDE_FLOAT32_C(   92.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -937.00), SIMDE_FLOAT32_C(  854.00),
                         SIMDE_FLOAT32_C(  980.00), SIMDE_FLOAT32_C(  -86.00),
                         SIMDE_FLOAT32_C(  473.00), SIMDE_FLOAT32_C(  104.00),
                         SIMDE_FLOAT32_C(   14.00), SIMDE_FLOAT32_C(   91.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  529.30), SIMDE_FLOAT32_C(  148.64),
                         SIMDE_FLOAT32_C(  820.35), SIMDE_FLOAT32_C(  265.99),
                         SIMDE_FLOAT32_C(  701.82), SIMDE_FLOAT32_C(  479.73),
                         SIMDE_FLOAT32_C(  432.96), SIMDE_FLOAT32_C(  276.42)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  529.00), SIMDE_FLOAT32_C(  149.00),
                         SIMDE_FLOAT32_C(  820.00), SIMDE_FLOAT32_C(  266.00),
                         SIMDE_FLOAT32_C(  702.00), SIMDE_FLOAT32_C(  480.00),
                         SIMDE_FLOAT32_C(  433.00), SIMDE_FLOAT32_C(  276.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  529.00), SIMDE_FLOAT32_C(  148.00),
                         SIMDE_FLOAT32_C(  820.00), SIMDE_FLOAT32_C(  265.00),
                         SIMDE_FLOAT32_C(  701.00), SIMDE_FLOAT32_C(  479.00),
                         SIMDE_FLOAT32_C(  432.00), SIMDE_FLOAT32_C(  276.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  530.00), SIMDE_FLOAT32_C(  149.00),
                         SIMDE_FLOAT32_C(  821.00), SIMDE_FLOAT32_C(  266.00),
                         SIMDE_FLOAT32_C(  702.00), SIMDE_FLOAT32_C(  480.00),
                         SIMDE_FLOAT32_C(  433.00), SIMDE_FLOAT32_C(  277.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  529.00), SIMDE_FLOAT32_C(  148.00),
                         SIMDE_FLOAT32_C(  820.00), SIMDE_FLOAT32_C(  265.00),
                         SIMDE_FLOAT32_C(  701.00), SIMDE_FLOAT32_C(  479.00),
                         SIMDE_FLOAT32_C(  432.00), SIMDE_FLOAT32_C(  276.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -33.90), SIMDE_FLOAT32_C( -334.90),
                         SIMDE_FLOAT32_C( -399.58), SIMDE_FLOAT32_C(  824.28),
                         SIMDE_FLOAT32_C(  442.40), SIMDE_FLOAT32_C(  699.22),
                         SIMDE_FLOAT32_C( -143.02), SIMDE_FLOAT32_C( -465.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -34.00), SIMDE_FLOAT32_C( -335.00),
                         SIMDE_FLOAT32_C( -400.00), SIMDE_FLOAT32_C(  824.00),
                         SIMDE_FLOAT32_C(  442.00), SIMDE_FLOAT32_C(  699.00),
                         SIMDE_FLOAT32_C( -143.00), SIMDE_FLOAT32_C( -466.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -34.00), SIMDE_FLOAT32_C( -335.00),
                         SIMDE_FLOAT32_C( -400.00), SIMDE_FLOAT32_C(  824.00),
                         SIMDE_FLOAT32_C(  442.00), SIMDE_FLOAT32_C(  699.00),
                         SIMDE_FLOAT32_C( -144.00), SIMDE_FLOAT32_C( -466.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -33.00), SIMDE_FLOAT32_C( -334.00),
                         SIMDE_FLOAT32_C( -399.00), SIMDE_FLOAT32_C(  825.00),
                         SIMDE_FLOAT32_C(  443.00), SIMDE_FLOAT32_C(  700.00),
                         SIMDE_FLOAT32_C( -143.00), SIMDE_FLOAT32_C( -465.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -33.00), SIMDE_FLOAT32_C( -334.00),
                         SIMDE_FLOAT32_C( -399.00), SIMDE_FLOAT32_C(  824.00),
                         SIMDE_FLOAT32_C(  442.00), SIMDE_FLOAT32_C(  699.00),
                         SIMDE_FLOAT32_C( -143.00), SIMDE_FLOAT32_C( -465.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r;

    r = simde_mm256_round_ps(test_vec[i].a, SIMDE_MM_FROUND_TO_NEAREST_INT);
    simde_assert_m256_f32_equal(r, test_vec[i].nearest, 1);

    r = simde_mm256_round_ps(test_vec[i].a, SIMDE_MM_FROUND_TO_NEG_INF);
    simde_assert_m256_f32_equal(r, test_vec[i].neg_inf, 1);

    r = simde_mm256_round_ps(test_vec[i].a, SIMDE_MM_FROUND_TO_POS_INF);
    simde_assert_m256_f32_equal(r, test_vec[i].pos_inf, 1);

    r = simde_mm256_round_ps(test_vec[i].a, SIMDE_MM_FROUND_TO_ZERO);
    simde_assert_m256_f32_equal(r, test_vec[i].truncate, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_round_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d nearest;
    simde__m256d neg_inf;
    simde__m256d pos_inf;
    simde__m256d truncate;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  312.12), SIMDE_FLOAT64_C(  818.22),
                         SIMDE_FLOAT64_C(   62.47), SIMDE_FLOAT64_C(  918.37)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  312.00), SIMDE_FLOAT64_C(  818.00),
                         SIMDE_FLOAT64_C(   62.00), SIMDE_FLOAT64_C(  918.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  312.00), SIMDE_FLOAT64_C(  818.00),
                         SIMDE_FLOAT64_C(   62.00), SIMDE_FLOAT64_C(  918.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  313.00), SIMDE_FLOAT64_C(  819.00),
                         SIMDE_FLOAT64_C(   63.00), SIMDE_FLOAT64_C(  919.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  312.00), SIMDE_FLOAT64_C(  818.00),
                         SIMDE_FLOAT64_C(   62.00), SIMDE_FLOAT64_C(  918.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  651.78), SIMDE_FLOAT64_C( -771.04),
                         SIMDE_FLOAT64_C(  544.48), SIMDE_FLOAT64_C(  333.27)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  652.00), SIMDE_FLOAT64_C( -771.00),
                         SIMDE_FLOAT64_C(  544.00), SIMDE_FLOAT64_C(  333.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  651.00), SIMDE_FLOAT64_C( -772.00),
                         SIMDE_FLOAT64_C(  544.00), SIMDE_FLOAT64_C(  333.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  652.00), SIMDE_FLOAT64_C( -771.00),
                         SIMDE_FLOAT64_C(  545.00), SIMDE_FLOAT64_C(  334.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  651.00), SIMDE_FLOAT64_C( -771.00),
                         SIMDE_FLOAT64_C(  544.00), SIMDE_FLOAT64_C(  333.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -661.62), SIMDE_FLOAT64_C(  921.42),
                         SIMDE_FLOAT64_C(   23.03), SIMDE_FLOAT64_C(  143.14)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -662.00), SIMDE_FLOAT64_C(  921.00),
                         SIMDE_FLOAT64_C(   23.00), SIMDE_FLOAT64_C(  143.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -662.00), SIMDE_FLOAT64_C(  921.00),
                         SIMDE_FLOAT64_C(   23.00), SIMDE_FLOAT64_C(  143.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -661.00), SIMDE_FLOAT64_C(  922.00),
                         SIMDE_FLOAT64_C(   24.00), SIMDE_FLOAT64_C(  144.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -661.00), SIMDE_FLOAT64_C(  921.00),
                         SIMDE_FLOAT64_C(   23.00), SIMDE_FLOAT64_C(  143.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -70.00), SIMDE_FLOAT64_C( -189.29),
                         SIMDE_FLOAT64_C( -644.20), SIMDE_FLOAT64_C( -788.03)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -70.00), SIMDE_FLOAT64_C( -189.00),
                         SIMDE_FLOAT64_C( -644.00), SIMDE_FLOAT64_C( -788.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -70.00), SIMDE_FLOAT64_C( -190.00),
                         SIMDE_FLOAT64_C( -645.00), SIMDE_FLOAT64_C( -789.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -70.00), SIMDE_FLOAT64_C( -189.00),
                         SIMDE_FLOAT64_C( -644.00), SIMDE_FLOAT64_C( -788.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -70.00), SIMDE_FLOAT64_C( -189.00),
                         SIMDE_FLOAT64_C( -644.00), SIMDE_FLOAT64_C( -788.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -999.31), SIMDE_FLOAT64_C(  917.83),
                         SIMDE_FLOAT64_C( -173.85), SIMDE_FLOAT64_C( -622.25)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -999.00), SIMDE_FLOAT64_C(  918.00),
                         SIMDE_FLOAT64_C( -174.00), SIMDE_FLOAT64_C( -622.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1000.00), SIMDE_FLOAT64_C(  917.00),
                         SIMDE_FLOAT64_C( -174.00), SIMDE_FLOAT64_C( -623.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -999.00), SIMDE_FLOAT64_C(  918.00),
                         SIMDE_FLOAT64_C( -173.00), SIMDE_FLOAT64_C( -622.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -999.00), SIMDE_FLOAT64_C(  917.00),
                         SIMDE_FLOAT64_C( -173.00), SIMDE_FLOAT64_C( -622.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -905.08), SIMDE_FLOAT64_C(   96.40),
                         SIMDE_FLOAT64_C(  481.12), SIMDE_FLOAT64_C(  989.53)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -905.00), SIMDE_FLOAT64_C(   96.00),
                         SIMDE_FLOAT64_C(  481.00), SIMDE_FLOAT64_C(  990.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -906.00), SIMDE_FLOAT64_C(   96.00),
                         SIMDE_FLOAT64_C(  481.00), SIMDE_FLOAT64_C(  989.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -905.00), SIMDE_FLOAT64_C(   97.00),
                         SIMDE_FLOAT64_C(  482.00), SIMDE_FLOAT64_C(  990.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -905.00), SIMDE_FLOAT64_C(   96.00),
                         SIMDE_FLOAT64_C(  481.00), SIMDE_FLOAT64_C(  989.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  380.53), SIMDE_FLOAT64_C(  251.75),
                         SIMDE_FLOAT64_C( -843.75), SIMDE_FLOAT64_C( -890.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  381.00), SIMDE_FLOAT64_C(  252.00),
                         SIMDE_FLOAT64_C( -844.00), SIMDE_FLOAT64_C( -891.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  380.00), SIMDE_FLOAT64_C(  251.00),
                         SIMDE_FLOAT64_C( -844.00), SIMDE_FLOAT64_C( -891.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  381.00), SIMDE_FLOAT64_C(  252.00),
                         SIMDE_FLOAT64_C( -843.00), SIMDE_FLOAT64_C( -890.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  380.00), SIMDE_FLOAT64_C(  251.00),
                         SIMDE_FLOAT64_C( -843.00), SIMDE_FLOAT64_C( -890.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -382.52), SIMDE_FLOAT64_C( -590.14),
                         SIMDE_FLOAT64_C(    3.25), SIMDE_FLOAT64_C(  599.23)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -383.00), SIMDE_FLOAT64_C( -590.00),
                         SIMDE_FLOAT64_C(    3.00), SIMDE_FLOAT64_C(  599.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -383.00), SIMDE_FLOAT64_C( -591.00),
                         SIMDE_FLOAT64_C(    3.00), SIMDE_FLOAT64_C(  599.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -382.00), SIMDE_FLOAT64_C( -590.00),
                         SIMDE_FLOAT64_C(    4.00), SIMDE_FLOAT64_C(  600.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -382.00), SIMDE_FLOAT64_C( -590.00),
                         SIMDE_FLOAT64_C(    3.00), SIMDE_FLOAT64_C(  599.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r;

    r = simde_mm256_round_pd(test_vec[i].a, SIMDE_MM_FROUND_TO_NEAREST_INT);
    simde_assert_m256d_f64_equal(r, test_vec[i].nearest, 1);

    r = simde_mm256_round_pd(test_vec[i].a, SIMDE_MM_FROUND_TO_NEG_INF);
    simde_assert_m256d_f64_equal(r, test_vec[i].neg_inf, 1);

    r = simde_mm256_round_pd(test_vec[i].a, SIMDE_MM_FROUND_TO_POS_INF);
    simde_assert_m256d_f64_equal(r, test_vec[i].pos_inf, 1);

    r = simde_mm256_round_pd(test_vec[i].a, SIMDE_MM_FROUND_TO_ZERO);
    simde_assert_m256d_f64_equal(r, test_vec[i].truncate, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_rsqrt_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  376.34), SIMDE_FLOAT32_C(  781.09),
                         SIMDE_FLOAT32_C(  426.92), SIMDE_FLOAT32_C(  127.71),
                         SIMDE_FLOAT32_C(  308.06), SIMDE_FLOAT32_C(  169.26),
                         SIMDE_FLOAT32_C(  264.24), SIMDE_FLOAT32_C(   87.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.05), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.05), SIMDE_FLOAT32_C(    0.09),
                         SIMDE_FLOAT32_C(    0.06), SIMDE_FLOAT32_C(    0.08),
                         SIMDE_FLOAT32_C(    0.06), SIMDE_FLOAT32_C(    0.11)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  840.99), SIMDE_FLOAT32_C(  641.73),
                         SIMDE_FLOAT32_C(  425.88), SIMDE_FLOAT32_C(  794.85),
                         SIMDE_FLOAT32_C(  374.41), SIMDE_FLOAT32_C(  576.54),
                         SIMDE_FLOAT32_C(  840.83), SIMDE_FLOAT32_C(  886.63)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.03), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.05), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.05), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.03), SIMDE_FLOAT32_C(    0.03)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  314.85), SIMDE_FLOAT32_C(  671.43),
                         SIMDE_FLOAT32_C(  540.12), SIMDE_FLOAT32_C(  529.67),
                         SIMDE_FLOAT32_C(  498.35), SIMDE_FLOAT32_C(  224.61),
                         SIMDE_FLOAT32_C(  518.07), SIMDE_FLOAT32_C(  759.15)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.06), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.07),
                         SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.04)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  990.90), SIMDE_FLOAT32_C(  800.35),
                         SIMDE_FLOAT32_C(   95.53), SIMDE_FLOAT32_C(  852.74),
                         SIMDE_FLOAT32_C(  140.49), SIMDE_FLOAT32_C(  379.21),
                         SIMDE_FLOAT32_C(  930.80), SIMDE_FLOAT32_C(   70.01)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.03), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.10), SIMDE_FLOAT32_C(    0.03),
                         SIMDE_FLOAT32_C(    0.08), SIMDE_FLOAT32_C(    0.05),
                         SIMDE_FLOAT32_C(    0.03), SIMDE_FLOAT32_C(    0.12)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  251.14), SIMDE_FLOAT32_C(  612.05),
                         SIMDE_FLOAT32_C(   55.90), SIMDE_FLOAT32_C(  550.93),
                         SIMDE_FLOAT32_C(   71.18), SIMDE_FLOAT32_C(  968.41),
                         SIMDE_FLOAT32_C(   36.22), SIMDE_FLOAT32_C(  986.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.06), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.13), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.12), SIMDE_FLOAT32_C(    0.03),
                         SIMDE_FLOAT32_C(    0.17), SIMDE_FLOAT32_C(    0.03)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  657.13), SIMDE_FLOAT32_C(  431.08),
                         SIMDE_FLOAT32_C(  717.98), SIMDE_FLOAT32_C(   27.05),
                         SIMDE_FLOAT32_C(  195.42), SIMDE_FLOAT32_C(  859.20),
                         SIMDE_FLOAT32_C(  157.91), SIMDE_FLOAT32_C(  578.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.05),
                         SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.19),
                         SIMDE_FLOAT32_C(    0.07), SIMDE_FLOAT32_C(    0.03),
                         SIMDE_FLOAT32_C(    0.08), SIMDE_FLOAT32_C(    0.04)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  738.73), SIMDE_FLOAT32_C(  198.62),
                         SIMDE_FLOAT32_C(  544.16), SIMDE_FLOAT32_C(  379.62),
                         SIMDE_FLOAT32_C(  782.12), SIMDE_FLOAT32_C(   91.05),
                         SIMDE_FLOAT32_C(  650.65), SIMDE_FLOAT32_C(  315.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.07),
                         SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.05),
                         SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.10),
                         SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.06)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  788.79), SIMDE_FLOAT32_C(  929.94),
                         SIMDE_FLOAT32_C(   55.55), SIMDE_FLOAT32_C(  137.30),
                         SIMDE_FLOAT32_C(  612.48), SIMDE_FLOAT32_C(    6.47),
                         SIMDE_FLOAT32_C(  828.22), SIMDE_FLOAT32_C(  971.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.03),
                         SIMDE_FLOAT32_C(    0.13), SIMDE_FLOAT32_C(    0.09),
                         SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.39),
                         SIMDE_FLOAT32_C(    0.03), SIMDE_FLOAT32_C(    0.03)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_rsqrt_ps(test_vec[i].a);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int8_t a[32];
    simde__m256i r;
  } test_vec[8] = {
    { { INT8_C(  -4), INT8_C(  97), INT8_C( -85), INT8_C( -82),
        INT8_C(  42), INT8_C(  35), INT8_C(  11), INT8_C(  62),
        INT8_C( -47), INT8_C(  10), INT8_C(-127), INT8_C(  56),
        INT8_C(  44), INT8_C(  59), INT8_C( -13), INT8_C(  22),
        INT8_C( -14), INT8_C(  77), INT8_C( -49), INT8_C( -46),
        INT8_C(  53), INT8_C(-109), INT8_C(  30), INT8_C(  70),
        INT8_C(-110), INT8_C(  70), INT8_C(  95), INT8_C( -22),
        INT8_C(  89), INT8_C( -50), INT8_C( -28), INT8_C(-122) },
      simde_mm256_set_epi8(INT8_C(-122), INT8_C( -28), INT8_C( -50), INT8_C(  89),
                           INT8_C( -22), INT8_C(  95), INT8_C(  70), INT8_C(-110),
                           INT8_C(  70), INT8_C(  30), INT8_C(-109), INT8_C(  53),
                           INT8_C( -46), INT8_C( -49), INT8_C(  77), INT8_C( -14),
                           INT8_C(  22), INT8_C( -13), INT8_C(  59), INT8_C(  44),
                           INT8_C(  56), INT8_C(-127), INT8_C(  10), INT8_C( -47),
                           INT8_C(  62), INT8_C(  11), INT8_C(  35), INT8_C(  42),
                           INT8_C( -82), INT8_C( -85), INT8_C(  97), INT8_C(  -4)) },
    { { INT8_C( 127), INT8_C(  42), INT8_C( -70), INT8_C( -73),
        INT8_C( -56), INT8_C(-116), INT8_C( -43), INT8_C(  20),
        INT8_C(  -7), INT8_C(-120), INT8_C( -33), INT8_C(   3),
        INT8_C(  87), INT8_C(  58), INT8_C(  61), INT8_C( -32),
        INT8_C(  37), INT8_C(-114), INT8_C(  14), INT8_C(  80),
        INT8_C( -87), INT8_C(  43), INT8_C( -56), INT8_C(  51),
        INT8_C(  64), INT8_C(-107), INT8_C(  80), INT8_C(  59),
        INT8_C( -99), INT8_C( -49), INT8_C(  22), INT8_C( 109) },
      simde_mm256_set_epi8(INT8_C( 109), INT8_C(  22), INT8_C( -49), INT8_C( -99),
                           INT8_C(  59), INT8_C(  80), INT8_C(-107), INT8_C(  64),
                           INT8_C(  51), INT8_C( -56), INT8_C(  43), INT8_C( -87),
                           INT8_C(  80), INT8_C(  14), INT8_C(-114), INT8_C(  37),
                           INT8_C( -32), INT8_C(  61), INT8_C(  58), INT8_C(  87),
                           INT8_C(   3), INT8_C( -33), INT8_C(-120), INT8_C(  -7),
                           INT8_C(  20), INT8_C( -43), INT8_C(-116), INT8_C( -56),
                           INT8_C( -73), INT8_C( -70), INT8_C(  42), INT8_C( 127)) },
    { { INT8_C(  18), INT8_C( 106), INT8_C( -14), INT8_C( -63),
        INT8_C(  49), INT8_C(  26), INT8_C( 111), INT8_C( 121),
        INT8_C(-109), INT8_C(  19), INT8_C(  59), INT8_C( -42),
        INT8_C( -61), INT8_C(  44), INT8_C(  95), INT8_C(   0),
        INT8_C(  14), INT8_C(  62), INT8_C(  88), INT8_C(  98),
        INT8_C(  26), INT8_C(  58), INT8_C(  76), INT8_C( -18),
        INT8_C(-104), INT8_C(  -9), INT8_C( -67), INT8_C(  20),
        INT8_C( -43), INT8_C( -63), INT8_C(  30), INT8_C( 123) },
      simde_mm256_set_epi8(INT8_C( 123), INT8_C(  30), INT8_C( -63), INT8_C( -43),
                           INT8_C(  20), INT8_C( -67), INT8_C(  -9), INT8_C(-104),
                           INT8_C( -18), INT8_C(  76), INT8_C(  58), INT8_C(  26),
                           INT8_C(  98), INT8_C(  88), INT8_C(  62), INT8_C(  14),
                           INT8_C(   0), INT8_C(  95), INT8_C(  44), INT8_C( -61),
                           INT8_C( -42), INT8_C(  59), INT8_C(  19), INT8_C(-109),
                           INT8_C( 121), INT8_C( 111), INT8_C(  26), INT8_C(  49),
                           INT8_C( -63), INT8_C( -14), INT8_C( 106), INT8_C(  18)) },
    { { INT8_C(-122), INT8_C( 106), INT8_C( -25), INT8_C(  57),
        INT8_C(-110), INT8_C(  80), INT8_C(  35), INT8_C( -81),
        INT8_C(-111), INT8_C(   7), INT8_C(  90), INT8_C( -14),
        INT8_C(  64), INT8_C(  90), INT8_C( -51), INT8_C(  87),
        INT8_C(  49), INT8_C(  77), INT8_C( 127), INT8_C( -93),
        INT8_C( -57), INT8_C( 112), INT8_C( -74), INT8_C(  26),
        INT8_C(-113), INT8_C( -77), INT8_C( -29), INT8_C( -29),
        INT8_C( 117), INT8_C(  31), INT8_C(-100), INT8_C( -86) },
      simde_mm256_set_epi8(INT8_C( -86), INT8_C(-100), INT8_C(  31), INT8_C( 117),
                           INT8_C( -29), INT8_C( -29), INT8_C( -77), INT8_C(-113),
                           INT8_C(  26), INT8_C( -74), INT8_C( 112), INT8_C( -57),
                           INT8_C( -93), INT8_C( 127), INT8_C(  77), INT8_C(  49),
                           INT8_C(  87), INT8_C( -51), INT8_C(  90), INT8_C(  64),
                           INT8_C( -14), INT8_C(  90), INT8_C(   7), INT8_C(-111),
                           INT8_C( -81), INT8_C(  35), INT8_C(  80), INT8_C(-110),
                           INT8_C(  57), INT8_C( -25), INT8_C( 106), INT8_C(-122)) },
    { { INT8_C(  58), INT8_C(   6), INT8_C( 118), INT8_C(  36),
        INT8_C( 115), INT8_C( -15), INT8_C(  37), INT8_C( 119),
        INT8_C( -89), INT8_C( -10), INT8_C( -50), INT8_C(-119),
        INT8_C(   6), INT8_C( -77), INT8_C(  70), INT8_C( 117),
        INT8_C( -12), INT8_C( -22), INT8_C( 114), INT8_C( -39),
        INT8_C( 100), INT8_C( 122), INT8_C(-102), INT8_C( -55),
        INT8_C( 116), INT8_C( -23), INT8_C( -29), INT8_C( -57),
        INT8_C( -40), INT8_C(  41), INT8_C( 119), INT8_C( 121) },
      simde_mm256_set_epi8(INT8_C( 121), INT8_C( 119), INT8_C(  41), INT8_C( -40),
                           INT8_C( -57), INT8_C( -29), INT8_C( -23), INT8_C( 116),
                           INT8_C( -55), INT8_C(-102), INT8_C( 122), INT8_C( 100),
                           INT8_C( -39), INT8_C( 114), INT8_C( -22), INT8_C( -12),
                           INT8_C( 117), INT8_C(  70), INT8_C( -77), INT8_C(   6),
                           INT8_C(-119), INT8_C( -50), INT8_C( -10), INT8_C( -89),
                           INT8_C( 119), INT8_C(  37), INT8_C( -15), INT8_C( 115),
                           INT8_C(  36), INT8_C( 118), INT8_C(   6), INT8_C(  58)) },
    { { INT8_C(  47), INT8_C(  33), INT8_C( -28), INT8_C(-105),
        INT8_C(  -6), INT8_C( -69), INT8_C( 111), INT8_C( -17),
        INT8_C(  43), INT8_C(-123), INT8_C(  56), INT8_C( 119),
        INT8_C(  18), INT8_C(  -6), INT8_C( -96), INT8_C(-126),
        INT8_C( 113), INT8_C(-107), INT8_C(  83), INT8_C(  24),
        INT8_C( -84), INT8_C(-124), INT8_C( -72), INT8_C( -86),
        INT8_C(  80), INT8_C(  33), INT8_C(  -6), INT8_C( -30),
        INT8_C(  85), INT8_C( -74), INT8_C(  58), INT8_C( -88) },
      simde_mm256_set_epi8(INT8_C( -88), INT8_C(  58), INT8_C( -74), INT8_C(  85),
                           INT8_C( -30), INT8_C(  -6), INT8_C(  33), INT8_C(  80),
                           INT8_C( -86), INT8_C( -72), INT8_C(-124), INT8_C( -84),
                           INT8_C(  24), INT8_C(  83), INT8_C(-107), INT8_C( 113),
                           INT8_C(-126), INT8_C( -96), INT8_C(  -6), INT8_C(  18),
                           INT8_C( 119), INT8_C(  56), INT8_C(-123), INT8_C(  43),
                           INT8_C( -17), INT8_C( 111), INT8_C( -69), INT8_C(  -6),
                           INT8_C(-105), INT8_C( -28), INT8_C(  33), INT8_C(  47)) },
    { { INT8_C(  12), INT8_C(  93), INT8_C( -74), INT8_C( 117),
        INT8_C( -55), INT8_C( -56), INT8_C(   9), INT8_C( -48),
        INT8_C( 100), INT8_C(  -4), INT8_C( 101), INT8_C(  -1),
        INT8_C( -41), INT8_C( -98), INT8_C(-128), INT8_C( -73),
        INT8_C( -47), INT8_C(  35), INT8_C( -89), INT8_C( -36),
        INT8_C(-117), INT8_C( -95), INT8_C( -70), INT8_C( -94),
        INT8_C( -61), INT8_C( -88), INT8_C( -41), INT8_C( -56),
        INT8_C(  -5), INT8_C( -90), INT8_C( -61), INT8_C(  58) },
      simde_mm256_set_epi8(INT8_C(  58), INT8_C( -61), INT8_C( -90), INT8_C(  -5),
                           INT8_C( -56), INT8_C( -41), INT8_C( -88), INT8_C( -61),
                           INT8_C( -94), INT8_C( -70), INT8_C( -95), INT8_C(-117),
                           INT8_C( -36), INT8_C( -89), INT8_C(  35), INT8_C( -47),
                           INT8_C( -73), INT8_C(-128), INT8_C( -98), INT8_C( -41),
                           INT8_C(  -1), INT8_C( 101), INT8_C(  -4), INT8_C( 100),
                           INT8_C( -48), INT8_C(   9), INT8_C( -56), INT8_C( -55),
                           INT8_C( 117), INT8_C( -74), INT8_C(  93), INT8_C(  12)) },
    { { INT8_C( -62), INT8_C( 106), INT8_C(  33), INT8_C( -86),
        INT8_C(  50), INT8_C(  51), INT8_C(   1), INT8_C(  83),
        INT8_C( -24), INT8_C(  24), INT8_C( 119), INT8_C( -35),
        INT8_C(  55), INT8_C( 109), INT8_C( -56), INT8_C( -46),
        INT8_C( -64), INT8_C( 124), INT8_C(  -1), INT8_C( -71),
        INT8_C(  27), INT8_C( 108), INT8_C(-113), INT8_C( -86),
        INT8_C(  94), INT8_C(  46), INT8_C( -59), INT8_C( -32),
        INT8_C( -63), INT8_C( -39), INT8_C( -52), INT8_C( 101) },
      simde_mm256_set_epi8(INT8_C( 101), INT8_C( -52), INT8_C( -39), INT8_C( -63),
                           INT8_C( -32), INT8_C( -59), INT8_C(  46), INT8_C(  94),
                           INT8_C( -86), INT8_C(-113), INT8_C( 108), INT8_C(  27),
                           INT8_C( -71), INT8_C(  -1), INT8_C( 124), INT8_C( -64),
                           INT8_C( -46), INT8_C( -56), INT8_C( 109), INT8_C(  55),
                           INT8_C( -35), INT8_C( 119), INT8_C(  24), INT8_C( -24),
                           INT8_C(  83), INT8_C(   1), INT8_C(  51), INT8_C(  50),
                           INT8_C( -86), INT8_C(  33), INT8_C( 106), INT8_C( -62)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_setr_epi8(
        test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3],
        test_vec[i].a[ 4], test_vec[i].a[ 5], test_vec[i].a[ 6], test_vec[i].a[ 7],
        test_vec[i].a[ 8], test_vec[i].a[ 9], test_vec[i].a[10], test_vec[i].a[11],
        test_vec[i].a[12], test_vec[i].a[13], test_vec[i].a[14], test_vec[i].a[15],
        test_vec[i].a[16], test_vec[i].a[17], test_vec[i].a[18], test_vec[i].a[19],
        test_vec[i].a[20], test_vec[i].a[21], test_vec[i].a[22], test_vec[i].a[23],
        test_vec[i].a[24], test_vec[i].a[25], test_vec[i].a[26], test_vec[i].a[27],
        test_vec[i].a[28], test_vec[i].a[29], test_vec[i].a[30], test_vec[i].a[31]);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int16_t a[16];
    simde__m256i r;
  } test_vec[8] = {
    { { INT16_C(-20822), INT16_C(  4719), INT16_C( 13700), INT16_C( 26280),
        INT16_C( -8393), INT16_C( 13684), INT16_C(-27950), INT16_C(-18508),
        INT16_C( 32037), INT16_C(-24299), INT16_C(-21546), INT16_C(  1669),
        INT16_C(   957), INT16_C( 10001), INT16_C(-15549), INT16_C(-30917) },
      simde_mm256_set_epi16(INT16_C(-30917), INT16_C(-15549), INT16_C( 10001), INT16_C(   957),
                            INT16_C(  1669), INT16_C(-21546), INT16_C(-24299), INT16_C( 32037),
                            INT16_C(-18508), INT16_C(-27950), INT16_C( 13684), INT16_C( -8393),
                            INT16_C( 26280), INT16_C( 13700), INT16_C(  4719), INT16_C(-20822)) },
    { { INT16_C(-21993), INT16_C(-20656), INT16_C( 29326), INT16_C( 28940),
        INT16_C(-31152), INT16_C(-19248), INT16_C(-26052), INT16_C(-19065),
        INT16_C(-11006), INT16_C( -7550), INT16_C( 14017), INT16_C( 19342),
        INT16_C(-32339), INT16_C(  3580), INT16_C( 28313), INT16_C(-13882) },
      simde_mm256_set_epi16(INT16_C(-13882), INT16_C( 28313), INT16_C(  3580), INT16_C(-32339),
                            INT16_C( 19342), INT16_C( 14017), INT16_C( -7550), INT16_C(-11006),
                            INT16_C(-19065), INT16_C(-26052), INT16_C(-19248), INT16_C(-31152),
                            INT16_C( 28940), INT16_C( 29326), INT16_C(-20656), INT16_C(-21993)) },
    { { INT16_C( 10866), INT16_C(  9786), INT16_C(  3944), INT16_C(-19272),
        INT16_C(-30670), INT16_C( 14551), INT16_C(  8410), INT16_C( -6777),
        INT16_C(-16568), INT16_C(-18107), INT16_C(-20605), INT16_C( 22309),
        INT16_C(-22975), INT16_C( 30575), INT16_C( -4285), INT16_C( 10884) },
      simde_mm256_set_epi16(INT16_C( 10884), INT16_C( -4285), INT16_C( 30575), INT16_C(-22975),
                            INT16_C( 22309), INT16_C(-20605), INT16_C(-18107), INT16_C(-16568),
                            INT16_C( -6777), INT16_C(  8410), INT16_C( 14551), INT16_C(-30670),
                            INT16_C(-19272), INT16_C(  3944), INT16_C(  9786), INT16_C( 10866)) },
    { { INT16_C(  3382), INT16_C(-18461), INT16_C( 23033), INT16_C(-12757),
        INT16_C(  -812), INT16_C( 15509), INT16_C(-23059), INT16_C(  2475),
        INT16_C(-26254), INT16_C(-14528), INT16_C(-12769), INT16_C( -6867),
        INT16_C(-17924), INT16_C( 22705), INT16_C(-26548), INT16_C(-32025) },
      simde_mm256_set_epi16(INT16_C(-32025), INT16_C(-26548), INT16_C( 22705), INT16_C(-17924),
                            INT16_C( -6867), INT16_C(-12769), INT16_C(-14528), INT16_C(-26254),
                            INT16_C(  2475), INT16_C(-23059), INT16_C( 15509), INT16_C(  -812),
                            INT16_C(-12757), INT16_C( 23033), INT16_C(-18461), INT16_C(  3382)) },
    { { INT16_C(-16227), INT16_C( 12780), INT16_C( 24958), INT16_C( 10168),
        INT16_C(-24922), INT16_C(-26733), INT16_C(  3884), INT16_C(  8130),
        INT16_C(  -363), INT16_C( -2828), INT16_C( -7524), INT16_C( 28685),
        INT16_C( -7215), INT16_C(  7765), INT16_C( 25104), INT16_C(-23004) },
      simde_mm256_set_epi16(INT16_C(-23004), INT16_C( 25104), INT16_C(  7765), INT16_C( -7215),
                            INT16_C( 28685), INT16_C( -7524), INT16_C( -2828), INT16_C(  -363),
                            INT16_C(  8130), INT16_C(  3884), INT16_C(-26733), INT16_C(-24922),
                            INT16_C( 10168), INT16_C( 24958), INT16_C( 12780), INT16_C(-16227)) },
    { { INT16_C(-23604), INT16_C(-17002), INT16_C( -3804), INT16_C(-31486),
        INT16_C(-31316), INT16_C(  8603), INT16_C( 13936), INT16_C(-30323),
        INT16_C( 17911), INT16_C(-25284), INT16_C( 11323), INT16_C( -3450),
        INT16_C( -2379), INT16_C( -4748), INT16_C( -1701), INT16_C(-14575) },
      simde_mm256_set_epi16(INT16_C(-14575), INT16_C( -1701), INT16_C( -4748), INT16_C( -2379),
                            INT16_C( -3450), INT16_C( 11323), INT16_C(-25284), INT16_C( 17911),
                            INT16_C(-30323), INT16_C( 13936), INT16_C(  8603), INT16_C(-31316),
                            INT16_C(-31486), INT16_C( -3804), INT16_C(-17002), INT16_C(-23604)) },
    { { INT16_C(  2504), INT16_C(  3886), INT16_C( -8527), INT16_C( 15137),
        INT16_C( -2956), INT16_C(  3741), INT16_C(-30624), INT16_C(-26724),
        INT16_C(  6830), INT16_C( 31838), INT16_C( 31654), INT16_C(-13744),
        INT16_C( -1202), INT16_C( 10750), INT16_C(  5862), INT16_C(-29772) },
      simde_mm256_set_epi16(INT16_C(-29772), INT16_C(  5862), INT16_C( 10750), INT16_C( -1202),
                            INT16_C(-13744), INT16_C( 31654), INT16_C( 31838), INT16_C(  6830),
                            INT16_C(-26724), INT16_C(-30624), INT16_C(  3741), INT16_C( -2956),
                            INT16_C( 15137), INT16_C( -8527), INT16_C(  3886), INT16_C(  2504)) },
    { { INT16_C(  9166), INT16_C( 24566), INT16_C(-20956), INT16_C( 25846),
        INT16_C( -9797), INT16_C(-30693), INT16_C( 17134), INT16_C(-20898),
        INT16_C(-11673), INT16_C( -1066), INT16_C( 24186), INT16_C( 15486),
        INT16_C( -6894), INT16_C( -1878), INT16_C(-19558), INT16_C( 25792) },
      simde_mm256_set_epi16(INT16_C( 25792), INT16_C(-19558), INT16_C( -1878), INT16_C( -6894),
                            INT16_C( 15486), INT16_C( 24186), INT16_C( -1066), INT16_C(-11673),
                            INT16_C(-20898), INT16_C( 17134), INT16_C(-30693), INT16_C( -9797),
                            INT16_C( 25846), INT16_C(-20956), INT16_C( 24566), INT16_C(  9166)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_setr_epi16(
        test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3],
        test_vec[i].a[ 4], test_vec[i].a[ 5], test_vec[i].a[ 6], test_vec[i].a[ 7],
        test_vec[i].a[ 8], test_vec[i].a[ 9], test_vec[i].a[10], test_vec[i].a[11],
        test_vec[i].a[12], test_vec[i].a[13], test_vec[i].a[14], test_vec[i].a[15]);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t a[8];
    simde__m256i r;
  } test_vec[8] = {
    { { INT32_C(  932849909), INT32_C( -456580424), INT32_C(-1072840342), INT32_C(  187025165),
        INT32_C(  -54386372), INT32_C(-1527557226), INT32_C(  842765893), INT32_C(-1371730077) },
      simde_mm256_set_epi32(INT32_C(-1371730077), INT32_C(  842765893), INT32_C(-1527557226), INT32_C(  -54386372),
                            INT32_C(  187025165), INT32_C(-1072840342), INT32_C( -456580424), INT32_C(  932849909)) },
    { { INT32_C( 1893614455), INT32_C( 1294871072), INT32_C( 1552259151), INT32_C(  946045936),
        INT32_C(   -7047247), INT32_C(  177282155), INT32_C( -581856304), INT32_C(  673832922) },
      simde_mm256_set_epi32(INT32_C(  673832922), INT32_C( -581856304), INT32_C(  177282155), INT32_C(   -7047247),
                            INT32_C(  946045936), INT32_C( 1552259151), INT32_C( 1294871072), INT32_C( 1893614455)) },
    { { INT32_C(-1610219922), INT32_C(  -94583836), INT32_C( -424768577), INT32_C( -880788885),
        INT32_C(  602433069), INT32_C( -274391227), INT32_C( -328110003), INT32_C(  499660384) },
      simde_mm256_set_epi32(INT32_C(  499660384), INT32_C( -328110003), INT32_C( -274391227), INT32_C(  602433069),
                            INT32_C( -880788885), INT32_C( -424768577), INT32_C(  -94583836), INT32_C(-1610219922)) },
    { { INT32_C( 1302188877), INT32_C( -801832432), INT32_C( 1655080701), INT32_C(-1605614771),
        INT32_C( 1846614190), INT32_C( 1570676076), INT32_C(  -68393412), INT32_C( 1031272058) },
      simde_mm256_set_epi32(INT32_C( 1031272058), INT32_C(  -68393412), INT32_C( 1570676076), INT32_C( 1846614190),
                            INT32_C(-1605614771), INT32_C( 1655080701), INT32_C( -801832432), INT32_C( 1302188877)) },
    { { INT32_C(   25897078), INT32_C(-1241591361), INT32_C( -592602700), INT32_C( -348865550),
        INT32_C( 1694164628), INT32_C( -856795223), INT32_C( -997978026), INT32_C( 1280081679) },
      simde_mm256_set_epi32(INT32_C( 1280081679), INT32_C( -997978026), INT32_C( -856795223), INT32_C( 1694164628),
                            INT32_C( -348865550), INT32_C( -592602700), INT32_C(-1241591361), INT32_C(   25897078)) },
    { { INT32_C(  -87546396), INT32_C( 1852814507), INT32_C( -373825552), INT32_C( 1866208106),
        INT32_C(  910270627), INT32_C( 1550266609), INT32_C( 1485123950), INT32_C( -498285483) },
      simde_mm256_set_epi32(INT32_C( -498285483), INT32_C( 1485123950), INT32_C( 1550266609), INT32_C(  910270627),
                            INT32_C( 1866208106), INT32_C( -373825552), INT32_C( 1852814507), INT32_C(  -87546396)) },
    { { INT32_C( -786490570), INT32_C( -486650057), INT32_C(-1901610760), INT32_C(-1385527729),
        INT32_C( 1837621475), INT32_C(  362332872), INT32_C( 1409187239), INT32_C( -294514311) },
      simde_mm256_set_epi32(INT32_C( -294514311), INT32_C( 1409187239), INT32_C(  362332872), INT32_C( 1837621475),
                            INT32_C(-1385527729), INT32_C(-1901610760), INT32_C( -486650057), INT32_C( -786490570)) },
    { { INT32_C(-2037006285), INT32_C(-1237137601), INT32_C(-1490902854), INT32_C(-1337182966),
        INT32_C( -732587886), INT32_C(-1907285545), INT32_C(  165118547), INT32_C(-1097315632) },
      simde_mm256_set_epi32(INT32_C(-1097315632), INT32_C(  165118547), INT32_C(-1907285545), INT32_C( -732587886),
                            INT32_C(-1337182966), INT32_C(-1490902854), INT32_C(-1237137601), INT32_C(-2037006285)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_setr_epi32(
        test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3],
        test_vec[i].a[ 4], test_vec[i].a[ 5], test_vec[i].a[ 6], test_vec[i].a[ 7]);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int64_t a[4];
    simde__m256i r;
  } test_vec[8] = {
    { { INT64_C( 3013620110861784505), INT64_C(-9156069624919168580),
        INT64_C( 1343723656449999612), INT64_C(-3830101585267880776) },
      simde_mm256_set_epi64x(INT64_C(-3830101585267880776), INT64_C( 1343723656449999612),
                             INT64_C(-9156069624919168580), INT64_C( 3013620110861784505)) },
    { { INT64_C( -470898397325052178), INT64_C(-1684256644586675245),
        INT64_C(-8451403171467723697), INT64_C( 5467852576317781229) },
      simde_mm256_set_epi64x(INT64_C( 5467852576317781229), INT64_C(-8451403171467723697),
                             INT64_C(-1684256644586675245), INT64_C( -470898397325052178)) },
    { { INT64_C(-8481091302015892038), INT64_C(-5840489628108018840),
        INT64_C( 8103807582752765524), INT64_C( 9048592296921391543) },
      simde_mm256_set_epi64x(INT64_C( 9048592296921391543), INT64_C( 8103807582752765524),
                             INT64_C(-5840489628108018840), INT64_C(-8481091302015892038)) },
    { { INT64_C( 1422449841795305675), INT64_C( 2887994309822364165),
        INT64_C( 7807032920035636816), INT64_C(-3076736950419346689) },
      simde_mm256_set_epi64x(INT64_C(-3076736950419346689), INT64_C( 7807032920035636816),
                             INT64_C( 2887994309822364165), INT64_C( 1422449841795305675)) },
    { { INT64_C( 3070310353568185156), INT64_C(-8852504885484410210),
        INT64_C( 8605078790751557478), INT64_C(-3993303917440615301) },
      simde_mm256_set_epi64x(INT64_C(-3993303917440615301), INT64_C( 8605078790751557478),
                             INT64_C(-8852504885484410210), INT64_C( 3070310353568185156)) },
    { { INT64_C( 8628903781070638905), INT64_C( 7741876512722404057),
        INT64_C(-7211506260596057593), INT64_C( 4414889885954661792) },
      simde_mm256_set_epi64x(INT64_C( 4414889885954661792), INT64_C(-7211506260596057593),
                             INT64_C( 7741876512722404057), INT64_C( 8628903781070638905)) },
    { { INT64_C( 5522184073273144975), INT64_C(-7081867462548166489),
        INT64_C( 9175542926859973104), INT64_C( 1769179143810464101) },
      simde_mm256_set_epi64x(INT64_C( 1769179143810464101), INT64_C( 9175542926859973104),
                             INT64_C(-7081867462548166489), INT64_C( 5522184073273144975)) },
    { { INT64_C(-8500631716292798858), INT64_C( 4882720816332117442),
        INT64_C(  328133580565148934), INT64_C( 3537144852497440140) },
      simde_mm256_set_epi64x(INT64_C( 3537144852497440140), INT64_C(  328133580565148934),
                             INT64_C( 4882720816332117442), INT64_C(-8500631716292798858)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_setr_epi64(
        test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3]);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32 a[8];
    simde__m256 r;
  } test_vec[8] = {
    { { SIMDE_FLOAT32_C(  -98.84), SIMDE_FLOAT32_C(  882.16),
        SIMDE_FLOAT32_C(  306.69), SIMDE_FLOAT32_C( -539.67),
        SIMDE_FLOAT32_C( -947.14), SIMDE_FLOAT32_C( -871.17),
        SIMDE_FLOAT32_C(  -26.40), SIMDE_FLOAT32_C( -202.75) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -202.75), SIMDE_FLOAT32_C(  -26.40),
                         SIMDE_FLOAT32_C( -871.17), SIMDE_FLOAT32_C( -947.14),
                         SIMDE_FLOAT32_C( -539.67), SIMDE_FLOAT32_C(  306.69),
                         SIMDE_FLOAT32_C(  882.16), SIMDE_FLOAT32_C(  -98.84)) },
    { { SIMDE_FLOAT32_C(  499.74), SIMDE_FLOAT32_C( -810.04),
        SIMDE_FLOAT32_C(  499.26), SIMDE_FLOAT32_C( -519.32),
        SIMDE_FLOAT32_C(  852.97), SIMDE_FLOAT32_C(  119.58),
        SIMDE_FLOAT32_C(   88.58), SIMDE_FLOAT32_C(  364.48) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  364.48), SIMDE_FLOAT32_C(   88.58),
                         SIMDE_FLOAT32_C(  119.58), SIMDE_FLOAT32_C(  852.97),
                         SIMDE_FLOAT32_C( -519.32), SIMDE_FLOAT32_C(  499.26),
                         SIMDE_FLOAT32_C( -810.04), SIMDE_FLOAT32_C(  499.74)) },
    { { SIMDE_FLOAT32_C(  127.60), SIMDE_FLOAT32_C(  904.28),
        SIMDE_FLOAT32_C(  -45.75), SIMDE_FLOAT32_C( -900.72),
        SIMDE_FLOAT32_C(  277.91), SIMDE_FLOAT32_C( -221.10),
        SIMDE_FLOAT32_C(  935.26), SIMDE_FLOAT32_C( -125.20) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -125.20), SIMDE_FLOAT32_C(  935.26),
                         SIMDE_FLOAT32_C( -221.10), SIMDE_FLOAT32_C(  277.91),
                         SIMDE_FLOAT32_C( -900.72), SIMDE_FLOAT32_C(  -45.75),
                         SIMDE_FLOAT32_C(  904.28), SIMDE_FLOAT32_C(  127.60)) },
    { { SIMDE_FLOAT32_C( -252.48), SIMDE_FLOAT32_C( -889.53),
        SIMDE_FLOAT32_C(  628.46), SIMDE_FLOAT32_C(  326.01),
        SIMDE_FLOAT32_C(  211.05), SIMDE_FLOAT32_C( -703.39),
        SIMDE_FLOAT32_C( -581.63), SIMDE_FLOAT32_C( -367.12) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -367.12), SIMDE_FLOAT32_C( -581.63),
                         SIMDE_FLOAT32_C( -703.39), SIMDE_FLOAT32_C(  211.05),
                         SIMDE_FLOAT32_C(  326.01), SIMDE_FLOAT32_C(  628.46),
                         SIMDE_FLOAT32_C( -889.53), SIMDE_FLOAT32_C( -252.48)) },
    { { SIMDE_FLOAT32_C( -852.61), SIMDE_FLOAT32_C(  168.93),
        SIMDE_FLOAT32_C(  -51.67), SIMDE_FLOAT32_C( -699.78),
        SIMDE_FLOAT32_C( -215.36), SIMDE_FLOAT32_C(  505.82),
        SIMDE_FLOAT32_C(  -83.94), SIMDE_FLOAT32_C( -117.98) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -117.98), SIMDE_FLOAT32_C(  -83.94),
                         SIMDE_FLOAT32_C(  505.82), SIMDE_FLOAT32_C( -215.36),
                         SIMDE_FLOAT32_C( -699.78), SIMDE_FLOAT32_C(  -51.67),
                         SIMDE_FLOAT32_C(  168.93), SIMDE_FLOAT32_C( -852.61)) },
    { { SIMDE_FLOAT32_C(  422.80), SIMDE_FLOAT32_C(  684.40),
        SIMDE_FLOAT32_C(  497.91), SIMDE_FLOAT32_C( -511.24),
        SIMDE_FLOAT32_C(  504.14), SIMDE_FLOAT32_C(  871.91),
        SIMDE_FLOAT32_C(  175.65), SIMDE_FLOAT32_C( -754.38) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -754.38), SIMDE_FLOAT32_C(  175.65),
                         SIMDE_FLOAT32_C(  871.91), SIMDE_FLOAT32_C(  504.14),
                         SIMDE_FLOAT32_C( -511.24), SIMDE_FLOAT32_C(  497.91),
                         SIMDE_FLOAT32_C(  684.40), SIMDE_FLOAT32_C(  422.80)) },
    { { SIMDE_FLOAT32_C( -712.98), SIMDE_FLOAT32_C(   92.05),
        SIMDE_FLOAT32_C( -155.74), SIMDE_FLOAT32_C(  933.89),
        SIMDE_FLOAT32_C(  385.65), SIMDE_FLOAT32_C( -406.91),
        SIMDE_FLOAT32_C( -999.59), SIMDE_FLOAT32_C( -851.48) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -851.48), SIMDE_FLOAT32_C( -999.59),
                         SIMDE_FLOAT32_C( -406.91), SIMDE_FLOAT32_C(  385.65),
                         SIMDE_FLOAT32_C(  933.89), SIMDE_FLOAT32_C( -155.74),
                         SIMDE_FLOAT32_C(   92.05), SIMDE_FLOAT32_C( -712.98)) },
    { { SIMDE_FLOAT32_C( -182.06), SIMDE_FLOAT32_C( -447.19),
        SIMDE_FLOAT32_C( -170.21), SIMDE_FLOAT32_C( -504.91),
        SIMDE_FLOAT32_C(  448.84), SIMDE_FLOAT32_C( -232.24),
        SIMDE_FLOAT32_C( -688.18), SIMDE_FLOAT32_C( -405.72) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -405.72), SIMDE_FLOAT32_C( -688.18),
                         SIMDE_FLOAT32_C( -232.24), SIMDE_FLOAT32_C(  448.84),
                         SIMDE_FLOAT32_C( -504.91), SIMDE_FLOAT32_C( -170.21),
                         SIMDE_FLOAT32_C( -447.19), SIMDE_FLOAT32_C( -182.06)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_setr_ps(
        test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3],
        test_vec[i].a[ 4], test_vec[i].a[ 5], test_vec[i].a[ 6], test_vec[i].a[ 7]);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64 a[4];
    simde__m256d r;
  } test_vec[8] = {
    { { SIMDE_FLOAT64_C(  648.06), SIMDE_FLOAT64_C( -427.64),
        SIMDE_FLOAT64_C(  870.51), SIMDE_FLOAT64_C( -400.08) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -400.08), SIMDE_FLOAT64_C(  870.51),
                         SIMDE_FLOAT64_C( -427.64), SIMDE_FLOAT64_C(  648.06)) },
    { { SIMDE_FLOAT64_C(  631.12), SIMDE_FLOAT64_C(  452.84),
        SIMDE_FLOAT64_C(  521.67), SIMDE_FLOAT64_C(  516.74) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  516.74), SIMDE_FLOAT64_C(  521.67),
                         SIMDE_FLOAT64_C(  452.84), SIMDE_FLOAT64_C(  631.12)) },
    { { SIMDE_FLOAT64_C( -967.92), SIMDE_FLOAT64_C(   20.70),
        SIMDE_FLOAT64_C(  301.61), SIMDE_FLOAT64_C( -721.26) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -721.26), SIMDE_FLOAT64_C(  301.61),
                         SIMDE_FLOAT64_C(   20.70), SIMDE_FLOAT64_C( -967.92)) },
    { { SIMDE_FLOAT64_C(  324.87), SIMDE_FLOAT64_C( -688.66),
        SIMDE_FLOAT64_C( -942.28), SIMDE_FLOAT64_C( -476.77) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -476.77), SIMDE_FLOAT64_C( -942.28),
                         SIMDE_FLOAT64_C( -688.66), SIMDE_FLOAT64_C(  324.87)) },
    { { SIMDE_FLOAT64_C( -951.83), SIMDE_FLOAT64_C(   77.38),
        SIMDE_FLOAT64_C(   95.18), SIMDE_FLOAT64_C( -682.02) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -682.02), SIMDE_FLOAT64_C(   95.18),
                         SIMDE_FLOAT64_C(   77.38), SIMDE_FLOAT64_C( -951.83)) },
    { { SIMDE_FLOAT64_C( -650.77), SIMDE_FLOAT64_C( -285.31),
        SIMDE_FLOAT64_C(  662.58), SIMDE_FLOAT64_C(  693.61) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  693.61), SIMDE_FLOAT64_C(  662.58),
                         SIMDE_FLOAT64_C( -285.31), SIMDE_FLOAT64_C( -650.77)) },
    { { SIMDE_FLOAT64_C(  209.43), SIMDE_FLOAT64_C(  188.93),
        SIMDE_FLOAT64_C( -264.78), SIMDE_FLOAT64_C(  938.62) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  938.62), SIMDE_FLOAT64_C( -264.78),
                         SIMDE_FLOAT64_C(  188.93), SIMDE_FLOAT64_C(  209.43)) },
    { { SIMDE_FLOAT64_C(  887.57), SIMDE_FLOAT64_C(  787.01),
        SIMDE_FLOAT64_C( -658.13), SIMDE_FLOAT64_C(  241.09) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  241.09), SIMDE_FLOAT64_C( -658.13),
                         SIMDE_FLOAT64_C(  787.01), SIMDE_FLOAT64_C(  887.57)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_setr_pd(
        test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3]);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_m128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -682.25), SIMDE_FLOAT32_C( -899.79), SIMDE_FLOAT32_C( -478.94), SIMDE_FLOAT32_C(  364.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -650.11), SIMDE_FLOAT32_C( -192.16), SIMDE_FLOAT32_C(  808.30), SIMDE_FLOAT32_C(  519.14)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -650.11), SIMDE_FLOAT32_C( -192.16),
                         SIMDE_FLOAT32_C(  808.30), SIMDE_FLOAT32_C(  519.14),
                         SIMDE_FLOAT32_C( -682.25), SIMDE_FLOAT32_C( -899.79),
                         SIMDE_FLOAT32_C( -478.94), SIMDE_FLOAT32_C(  364.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   16.48), SIMDE_FLOAT32_C(  517.23), SIMDE_FLOAT32_C( -546.20), SIMDE_FLOAT32_C(  -61.05)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  715.06), SIMDE_FLOAT32_C( -476.50), SIMDE_FLOAT32_C( -479.17), SIMDE_FLOAT32_C( -869.09)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  715.06), SIMDE_FLOAT32_C( -476.50),
                         SIMDE_FLOAT32_C( -479.17), SIMDE_FLOAT32_C( -869.09),
                         SIMDE_FLOAT32_C(   16.48), SIMDE_FLOAT32_C(  517.23),
                         SIMDE_FLOAT32_C( -546.20), SIMDE_FLOAT32_C(  -61.05)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -779.37), SIMDE_FLOAT32_C(   30.06), SIMDE_FLOAT32_C( -690.77), SIMDE_FLOAT32_C(  921.96)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -173.53), SIMDE_FLOAT32_C(  887.42), SIMDE_FLOAT32_C(  309.36), SIMDE_FLOAT32_C(  929.48)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -173.53), SIMDE_FLOAT32_C(  887.42),
                         SIMDE_FLOAT32_C(  309.36), SIMDE_FLOAT32_C(  929.48),
                         SIMDE_FLOAT32_C( -779.37), SIMDE_FLOAT32_C(   30.06),
                         SIMDE_FLOAT32_C( -690.77), SIMDE_FLOAT32_C(  921.96)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  766.53), SIMDE_FLOAT32_C( -675.92), SIMDE_FLOAT32_C( -948.96), SIMDE_FLOAT32_C(  521.94)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  725.37), SIMDE_FLOAT32_C( -802.67), SIMDE_FLOAT32_C( -800.62), SIMDE_FLOAT32_C(  419.68)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  725.37), SIMDE_FLOAT32_C( -802.67),
                         SIMDE_FLOAT32_C( -800.62), SIMDE_FLOAT32_C(  419.68),
                         SIMDE_FLOAT32_C(  766.53), SIMDE_FLOAT32_C( -675.92),
                         SIMDE_FLOAT32_C( -948.96), SIMDE_FLOAT32_C(  521.94)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  133.15), SIMDE_FLOAT32_C(  853.30), SIMDE_FLOAT32_C(  295.19), SIMDE_FLOAT32_C( -233.49)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  973.48), SIMDE_FLOAT32_C(  235.18), SIMDE_FLOAT32_C(  111.09), SIMDE_FLOAT32_C( -515.37)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  973.48), SIMDE_FLOAT32_C(  235.18),
                         SIMDE_FLOAT32_C(  111.09), SIMDE_FLOAT32_C( -515.37),
                         SIMDE_FLOAT32_C(  133.15), SIMDE_FLOAT32_C(  853.30),
                         SIMDE_FLOAT32_C(  295.19), SIMDE_FLOAT32_C( -233.49)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -131.35), SIMDE_FLOAT32_C(  737.21), SIMDE_FLOAT32_C(  816.16), SIMDE_FLOAT32_C(  442.16)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -614.82), SIMDE_FLOAT32_C( -170.44), SIMDE_FLOAT32_C(  851.94), SIMDE_FLOAT32_C(  235.41)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -614.82), SIMDE_FLOAT32_C( -170.44),
                         SIMDE_FLOAT32_C(  851.94), SIMDE_FLOAT32_C(  235.41),
                         SIMDE_FLOAT32_C( -131.35), SIMDE_FLOAT32_C(  737.21),
                         SIMDE_FLOAT32_C(  816.16), SIMDE_FLOAT32_C(  442.16)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  291.38), SIMDE_FLOAT32_C( -442.22), SIMDE_FLOAT32_C(  756.36), SIMDE_FLOAT32_C( -768.65)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -266.91), SIMDE_FLOAT32_C( -275.67), SIMDE_FLOAT32_C( -687.10), SIMDE_FLOAT32_C(  236.32)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -266.91), SIMDE_FLOAT32_C( -275.67),
                         SIMDE_FLOAT32_C( -687.10), SIMDE_FLOAT32_C(  236.32),
                         SIMDE_FLOAT32_C(  291.38), SIMDE_FLOAT32_C( -442.22),
                         SIMDE_FLOAT32_C(  756.36), SIMDE_FLOAT32_C( -768.65)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  561.83), SIMDE_FLOAT32_C(  979.61), SIMDE_FLOAT32_C(   43.21), SIMDE_FLOAT32_C( -386.38)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -879.64), SIMDE_FLOAT32_C( -192.97), SIMDE_FLOAT32_C( -876.27), SIMDE_FLOAT32_C(  -36.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -879.64), SIMDE_FLOAT32_C( -192.97),
                         SIMDE_FLOAT32_C( -876.27), SIMDE_FLOAT32_C(  -36.00),
                         SIMDE_FLOAT32_C(  561.83), SIMDE_FLOAT32_C(  979.61),
                         SIMDE_FLOAT32_C(   43.21), SIMDE_FLOAT32_C( -386.38)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_setr_m128(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_m128d(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -456.75), SIMDE_FLOAT64_C( -671.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -831.34), SIMDE_FLOAT64_C(  280.05)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -831.34), SIMDE_FLOAT64_C(  280.05),
                         SIMDE_FLOAT64_C( -456.75), SIMDE_FLOAT64_C( -671.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  937.15), SIMDE_FLOAT64_C( -608.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -231.75), SIMDE_FLOAT64_C( -301.21)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -231.75), SIMDE_FLOAT64_C( -301.21),
                         SIMDE_FLOAT64_C(  937.15), SIMDE_FLOAT64_C( -608.20)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -418.68), SIMDE_FLOAT64_C( -219.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -262.95), SIMDE_FLOAT64_C( -857.27)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -262.95), SIMDE_FLOAT64_C( -857.27),
                         SIMDE_FLOAT64_C( -418.68), SIMDE_FLOAT64_C( -219.09)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  154.88), SIMDE_FLOAT64_C(   64.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  231.57), SIMDE_FLOAT64_C(  996.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  231.57), SIMDE_FLOAT64_C(  996.12),
                         SIMDE_FLOAT64_C(  154.88), SIMDE_FLOAT64_C(   64.12)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -46.48), SIMDE_FLOAT64_C( -511.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  951.46), SIMDE_FLOAT64_C(  771.21)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  951.46), SIMDE_FLOAT64_C(  771.21),
                         SIMDE_FLOAT64_C(  -46.48), SIMDE_FLOAT64_C( -511.22)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -492.75), SIMDE_FLOAT64_C( -725.08)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -545.59), SIMDE_FLOAT64_C( -960.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -545.59), SIMDE_FLOAT64_C( -960.12),
                         SIMDE_FLOAT64_C( -492.75), SIMDE_FLOAT64_C( -725.08)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -9.74), SIMDE_FLOAT64_C(  -44.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  854.62), SIMDE_FLOAT64_C( -942.41)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  854.62), SIMDE_FLOAT64_C( -942.41),
                         SIMDE_FLOAT64_C(   -9.74), SIMDE_FLOAT64_C(  -44.37)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  575.33), SIMDE_FLOAT64_C( -493.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   73.10), SIMDE_FLOAT64_C(   90.67)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   73.10), SIMDE_FLOAT64_C(   90.67),
                         SIMDE_FLOAT64_C(  575.33), SIMDE_FLOAT64_C( -493.55)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_setr_m128d(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_m128i(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1742712724), INT32_C( -314784100), INT32_C(  986737210), INT32_C( 1275380805)),
      simde_mm_set_epi32(INT32_C( -652328462), INT32_C(-1178876865), INT32_C(-2116026355), INT32_C(  283851183)),
      simde_mm256_set_epi32(INT32_C( -652328462), INT32_C(-1178876865), INT32_C(-2116026355), INT32_C(  283851183),
                            INT32_C(-1742712724), INT32_C( -314784100), INT32_C(  986737210), INT32_C( 1275380805)) },
    { simde_mm_set_epi32(INT32_C( 1950785462), INT32_C(-1647057227), INT32_C( 1610379205), INT32_C( -779524107)),
      simde_mm_set_epi32(INT32_C(  463748536), INT32_C( -797772071), INT32_C( 1736524491), INT32_C( 1281308863)),
      simde_mm256_set_epi32(INT32_C(  463748536), INT32_C( -797772071), INT32_C( 1736524491), INT32_C( 1281308863),
                            INT32_C( 1950785462), INT32_C(-1647057227), INT32_C( 1610379205), INT32_C( -779524107)) },
    { simde_mm_set_epi32(INT32_C(-2008212267), INT32_C(-2138916541), INT32_C(-1006728926), INT32_C(-1435438838)),
      simde_mm_set_epi32(INT32_C( -133349630), INT32_C(-1192564707), INT32_C(-2002224298), INT32_C(  917327905)),
      simde_mm256_set_epi32(INT32_C( -133349630), INT32_C(-1192564707), INT32_C(-2002224298), INT32_C(  917327905),
                            INT32_C(-2008212267), INT32_C(-2138916541), INT32_C(-1006728926), INT32_C(-1435438838)) },
    { simde_mm_set_epi32(INT32_C( -870567789), INT32_C(-1650884654), INT32_C(  516950890), INT32_C(-1478935293)),
      simde_mm_set_epi32(INT32_C(  346251173), INT32_C(   44036763), INT32_C( -453299917), INT32_C( 1313402969)),
      simde_mm256_set_epi32(INT32_C(  346251173), INT32_C(   44036763), INT32_C( -453299917), INT32_C( 1313402969),
                            INT32_C( -870567789), INT32_C(-1650884654), INT32_C(  516950890), INT32_C(-1478935293)) },
    { simde_mm_set_epi32(INT32_C( 1685745491), INT32_C(-1092039924), INT32_C( 1442866872), INT32_C(-1523614432)),
      simde_mm_set_epi32(INT32_C(  863519834), INT32_C(  230110187), INT32_C(  812017634), INT32_C( 1688191143)),
      simde_mm256_set_epi32(INT32_C(  863519834), INT32_C(  230110187), INT32_C(  812017634), INT32_C( 1688191143),
                            INT32_C( 1685745491), INT32_C(-1092039924), INT32_C( 1442866872), INT32_C(-1523614432)) },
    { simde_mm_set_epi32(INT32_C(  245453619), INT32_C( 1778016121), INT32_C(   58675090), INT32_C( 1219256368)),
      simde_mm_set_epi32(INT32_C( 1174470085), INT32_C( -388376691), INT32_C( -990477533), INT32_C( -476034642)),
      simde_mm256_set_epi32(INT32_C( 1174470085), INT32_C( -388376691), INT32_C( -990477533), INT32_C( -476034642),
                            INT32_C(  245453619), INT32_C( 1778016121), INT32_C(   58675090), INT32_C( 1219256368)) },
    { simde_mm_set_epi32(INT32_C(    4875253), INT32_C(-1938130041), INT32_C( -829985839), INT32_C( 1737785848)),
      simde_mm_set_epi32(INT32_C(  645358488), INT32_C(   69189244), INT32_C( 1744086784), INT32_C(  473310154)),
      simde_mm256_set_epi32(INT32_C(  645358488), INT32_C(   69189244), INT32_C( 1744086784), INT32_C(  473310154),
                            INT32_C(    4875253), INT32_C(-1938130041), INT32_C( -829985839), INT32_C( 1737785848)) },
    { simde_mm_set_epi32(INT32_C(  804470839), INT32_C(-1989324616), INT32_C( 2138294939), INT32_C(  -20370473)),
      simde_mm_set_epi32(INT32_C(  587534668), INT32_C(  665646160), INT32_C(-1572975914), INT32_C( 1262599280)),
      simde_mm256_set_epi32(INT32_C(  587534668), INT32_C(  665646160), INT32_C(-1572975914), INT32_C( 1262599280),
                            INT32_C(  804470839), INT32_C(-1989324616), INT32_C( 2138294939), INT32_C(  -20370473)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_setr_m128i(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_shuffle_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r1;
    simde__m256 r2;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -37.53), SIMDE_FLOAT32_C(  505.45),
                         SIMDE_FLOAT32_C( -772.05), SIMDE_FLOAT32_C( -524.38),
                         SIMDE_FLOAT32_C(   32.28), SIMDE_FLOAT32_C(  575.28),
                         SIMDE_FLOAT32_C(  459.50), SIMDE_FLOAT32_C( -869.92)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  190.31), SIMDE_FLOAT32_C( -827.59),
                         SIMDE_FLOAT32_C( -501.09), SIMDE_FLOAT32_C(  667.40),
                         SIMDE_FLOAT32_C( -205.26), SIMDE_FLOAT32_C(  908.59),
                         SIMDE_FLOAT32_C(  448.39), SIMDE_FLOAT32_C( -264.01)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -501.09), SIMDE_FLOAT32_C( -501.09),
                         SIMDE_FLOAT32_C( -772.05), SIMDE_FLOAT32_C( -772.05),
                         SIMDE_FLOAT32_C(  448.39), SIMDE_FLOAT32_C(  448.39),
                         SIMDE_FLOAT32_C(  459.50), SIMDE_FLOAT32_C(  459.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -827.59), SIMDE_FLOAT32_C( -827.59),
                         SIMDE_FLOAT32_C(  505.45), SIMDE_FLOAT32_C(  505.45),
                         SIMDE_FLOAT32_C(  908.59), SIMDE_FLOAT32_C(  908.59),
                         SIMDE_FLOAT32_C(  575.28), SIMDE_FLOAT32_C(  575.28)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -651.57), SIMDE_FLOAT32_C( -282.66),
                         SIMDE_FLOAT32_C( -530.16), SIMDE_FLOAT32_C( -552.16),
                         SIMDE_FLOAT32_C(  586.68), SIMDE_FLOAT32_C(  706.29),
                         SIMDE_FLOAT32_C(  537.21), SIMDE_FLOAT32_C( -450.04)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -642.32), SIMDE_FLOAT32_C( -725.64),
                         SIMDE_FLOAT32_C(  162.03), SIMDE_FLOAT32_C(  624.91),
                         SIMDE_FLOAT32_C(  415.33), SIMDE_FLOAT32_C(  -62.25),
                         SIMDE_FLOAT32_C(  445.83), SIMDE_FLOAT32_C( -888.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  162.03), SIMDE_FLOAT32_C(  162.03),
                         SIMDE_FLOAT32_C( -530.16), SIMDE_FLOAT32_C( -530.16),
                         SIMDE_FLOAT32_C(  445.83), SIMDE_FLOAT32_C(  445.83),
                         SIMDE_FLOAT32_C(  537.21), SIMDE_FLOAT32_C(  537.21)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -725.64), SIMDE_FLOAT32_C( -725.64),
                         SIMDE_FLOAT32_C( -282.66), SIMDE_FLOAT32_C( -282.66),
                         SIMDE_FLOAT32_C(  -62.25), SIMDE_FLOAT32_C(  -62.25),
                         SIMDE_FLOAT32_C(  706.29), SIMDE_FLOAT32_C(  706.29)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -586.61), SIMDE_FLOAT32_C( -444.58),
                         SIMDE_FLOAT32_C(  804.56), SIMDE_FLOAT32_C( -661.78),
                         SIMDE_FLOAT32_C( -398.96), SIMDE_FLOAT32_C(  555.99),
                         SIMDE_FLOAT32_C(  255.05), SIMDE_FLOAT32_C(  326.05)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   59.74), SIMDE_FLOAT32_C(  544.15),
                         SIMDE_FLOAT32_C(  414.09), SIMDE_FLOAT32_C(   11.73),
                         SIMDE_FLOAT32_C(  678.11), SIMDE_FLOAT32_C(  264.09),
                         SIMDE_FLOAT32_C(  492.67), SIMDE_FLOAT32_C( -690.47)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  414.09), SIMDE_FLOAT32_C(  414.09),
                         SIMDE_FLOAT32_C(  804.56), SIMDE_FLOAT32_C(  804.56),
                         SIMDE_FLOAT32_C(  492.67), SIMDE_FLOAT32_C(  492.67),
                         SIMDE_FLOAT32_C(  255.05), SIMDE_FLOAT32_C(  255.05)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  544.15), SIMDE_FLOAT32_C(  544.15),
                         SIMDE_FLOAT32_C( -444.58), SIMDE_FLOAT32_C( -444.58),
                         SIMDE_FLOAT32_C(  264.09), SIMDE_FLOAT32_C(  264.09),
                         SIMDE_FLOAT32_C(  555.99), SIMDE_FLOAT32_C(  555.99)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -738.46), SIMDE_FLOAT32_C(  931.97),
                         SIMDE_FLOAT32_C( -722.34), SIMDE_FLOAT32_C( -600.75),
                         SIMDE_FLOAT32_C( -215.41), SIMDE_FLOAT32_C( -472.40),
                         SIMDE_FLOAT32_C(  -60.64), SIMDE_FLOAT32_C(  120.78)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  773.86), SIMDE_FLOAT32_C( -298.57),
                         SIMDE_FLOAT32_C(  440.00), SIMDE_FLOAT32_C( -205.51),
                         SIMDE_FLOAT32_C( -237.18), SIMDE_FLOAT32_C( -760.22),
                         SIMDE_FLOAT32_C( -446.09), SIMDE_FLOAT32_C( -381.56)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  440.00), SIMDE_FLOAT32_C(  440.00),
                         SIMDE_FLOAT32_C( -722.34), SIMDE_FLOAT32_C( -722.34),
                         SIMDE_FLOAT32_C( -446.09), SIMDE_FLOAT32_C( -446.09),
                         SIMDE_FLOAT32_C(  -60.64), SIMDE_FLOAT32_C(  -60.64)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -298.57), SIMDE_FLOAT32_C( -298.57),
                         SIMDE_FLOAT32_C(  931.97), SIMDE_FLOAT32_C(  931.97),
                         SIMDE_FLOAT32_C( -760.22), SIMDE_FLOAT32_C( -760.22),
                         SIMDE_FLOAT32_C( -472.40), SIMDE_FLOAT32_C( -472.40)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -868.52), SIMDE_FLOAT32_C( -561.35),
                         SIMDE_FLOAT32_C( -571.37), SIMDE_FLOAT32_C(  511.95),
                         SIMDE_FLOAT32_C(  794.40), SIMDE_FLOAT32_C(  468.29),
                         SIMDE_FLOAT32_C(  949.07), SIMDE_FLOAT32_C(  504.01)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -600.88), SIMDE_FLOAT32_C( -128.06),
                         SIMDE_FLOAT32_C(   -3.70), SIMDE_FLOAT32_C( -620.63),
                         SIMDE_FLOAT32_C(  888.33), SIMDE_FLOAT32_C(  864.93),
                         SIMDE_FLOAT32_C( -548.30), SIMDE_FLOAT32_C(  693.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -3.70), SIMDE_FLOAT32_C(   -3.70),
                         SIMDE_FLOAT32_C( -571.37), SIMDE_FLOAT32_C( -571.37),
                         SIMDE_FLOAT32_C( -548.30), SIMDE_FLOAT32_C( -548.30),
                         SIMDE_FLOAT32_C(  949.07), SIMDE_FLOAT32_C(  949.07)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -128.06), SIMDE_FLOAT32_C( -128.06),
                         SIMDE_FLOAT32_C( -561.35), SIMDE_FLOAT32_C( -561.35),
                         SIMDE_FLOAT32_C(  864.93), SIMDE_FLOAT32_C(  864.93),
                         SIMDE_FLOAT32_C(  468.29), SIMDE_FLOAT32_C(  468.29)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -274.24), SIMDE_FLOAT32_C( -910.17),
                         SIMDE_FLOAT32_C(  548.80), SIMDE_FLOAT32_C( -838.00),
                         SIMDE_FLOAT32_C( -379.63), SIMDE_FLOAT32_C(  775.00),
                         SIMDE_FLOAT32_C( -238.61), SIMDE_FLOAT32_C( -278.26)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   28.03), SIMDE_FLOAT32_C( -206.70),
                         SIMDE_FLOAT32_C(  -80.05), SIMDE_FLOAT32_C(  380.68),
                         SIMDE_FLOAT32_C(  342.48), SIMDE_FLOAT32_C(  525.81),
                         SIMDE_FLOAT32_C( -202.62), SIMDE_FLOAT32_C(  412.48)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -80.05), SIMDE_FLOAT32_C(  -80.05),
                         SIMDE_FLOAT32_C(  548.80), SIMDE_FLOAT32_C(  548.80),
                         SIMDE_FLOAT32_C( -202.62), SIMDE_FLOAT32_C( -202.62),
                         SIMDE_FLOAT32_C( -238.61), SIMDE_FLOAT32_C( -238.61)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -206.70), SIMDE_FLOAT32_C( -206.70),
                         SIMDE_FLOAT32_C( -910.17), SIMDE_FLOAT32_C( -910.17),
                         SIMDE_FLOAT32_C(  525.81), SIMDE_FLOAT32_C(  525.81),
                         SIMDE_FLOAT32_C(  775.00), SIMDE_FLOAT32_C(  775.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  270.95), SIMDE_FLOAT32_C(  727.79),
                         SIMDE_FLOAT32_C(  361.48), SIMDE_FLOAT32_C(  843.29),
                         SIMDE_FLOAT32_C( -519.67), SIMDE_FLOAT32_C( -181.50),
                         SIMDE_FLOAT32_C( -112.74), SIMDE_FLOAT32_C(  545.62)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -132.55), SIMDE_FLOAT32_C( -718.86),
                         SIMDE_FLOAT32_C(  142.59), SIMDE_FLOAT32_C(  742.01),
                         SIMDE_FLOAT32_C(  593.39), SIMDE_FLOAT32_C(  515.42),
                         SIMDE_FLOAT32_C(  897.24), SIMDE_FLOAT32_C(  759.74)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  142.59), SIMDE_FLOAT32_C(  142.59),
                         SIMDE_FLOAT32_C(  361.48), SIMDE_FLOAT32_C(  361.48),
                         SIMDE_FLOAT32_C(  897.24), SIMDE_FLOAT32_C(  897.24),
                         SIMDE_FLOAT32_C( -112.74), SIMDE_FLOAT32_C( -112.74)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -718.86), SIMDE_FLOAT32_C( -718.86),
                         SIMDE_FLOAT32_C(  727.79), SIMDE_FLOAT32_C(  727.79),
                         SIMDE_FLOAT32_C(  515.42), SIMDE_FLOAT32_C(  515.42),
                         SIMDE_FLOAT32_C( -181.50), SIMDE_FLOAT32_C( -181.50)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -964.03), SIMDE_FLOAT32_C(  334.31),
                         SIMDE_FLOAT32_C( -520.63), SIMDE_FLOAT32_C(  -60.01),
                         SIMDE_FLOAT32_C(  788.31), SIMDE_FLOAT32_C( -532.00),
                         SIMDE_FLOAT32_C(  146.02), SIMDE_FLOAT32_C(  -45.94)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -225.66), SIMDE_FLOAT32_C( -255.31),
                         SIMDE_FLOAT32_C(  440.71), SIMDE_FLOAT32_C( -673.25),
                         SIMDE_FLOAT32_C( -649.50), SIMDE_FLOAT32_C( -704.29),
                         SIMDE_FLOAT32_C(  340.20), SIMDE_FLOAT32_C( -395.47)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  440.71), SIMDE_FLOAT32_C(  440.71),
                         SIMDE_FLOAT32_C( -520.63), SIMDE_FLOAT32_C( -520.63),
                         SIMDE_FLOAT32_C(  340.20), SIMDE_FLOAT32_C(  340.20),
                         SIMDE_FLOAT32_C(  146.02), SIMDE_FLOAT32_C(  146.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -255.31), SIMDE_FLOAT32_C( -255.31),
                         SIMDE_FLOAT32_C(  334.31), SIMDE_FLOAT32_C(  334.31),
                         SIMDE_FLOAT32_C( -704.29), SIMDE_FLOAT32_C( -704.29),
                         SIMDE_FLOAT32_C( -532.00), SIMDE_FLOAT32_C( -532.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r;
    
    r = simde_mm256_shuffle_ps(test_vec[i].a, test_vec[i].b, 0x55);
    simde_assert_m256_f32_equal(r, test_vec[i].r1, 1);
    
    r = simde_mm256_shuffle_ps(test_vec[i].a, test_vec[i].b, 0xaa);
    simde_assert_m256_f32_equal(r, test_vec[i].r2, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_shuffle_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r1;
    simde__m256d r2;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  934.66), SIMDE_FLOAT64_C( -881.67),
                         SIMDE_FLOAT64_C(  836.94), SIMDE_FLOAT64_C( -777.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -249.31), SIMDE_FLOAT64_C(  364.30),
                         SIMDE_FLOAT64_C( -553.11), SIMDE_FLOAT64_C( -269.32)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  364.30), SIMDE_FLOAT64_C(  934.66),
                         SIMDE_FLOAT64_C( -269.32), SIMDE_FLOAT64_C(  836.94)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -249.31), SIMDE_FLOAT64_C( -881.67),
                         SIMDE_FLOAT64_C( -553.11), SIMDE_FLOAT64_C( -777.20)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -570.38), SIMDE_FLOAT64_C(  768.57),
                         SIMDE_FLOAT64_C(  912.15), SIMDE_FLOAT64_C(  -23.81)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -107.98), SIMDE_FLOAT64_C( -226.33),
                         SIMDE_FLOAT64_C(  924.14), SIMDE_FLOAT64_C( -792.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -226.33), SIMDE_FLOAT64_C( -570.38),
                         SIMDE_FLOAT64_C( -792.70), SIMDE_FLOAT64_C(  912.15)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -107.98), SIMDE_FLOAT64_C(  768.57),
                         SIMDE_FLOAT64_C(  924.14), SIMDE_FLOAT64_C(  -23.81)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -307.34), SIMDE_FLOAT64_C(  256.70),
                         SIMDE_FLOAT64_C(  615.34), SIMDE_FLOAT64_C(  966.02)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   80.56), SIMDE_FLOAT64_C( -102.88),
                         SIMDE_FLOAT64_C(  558.25), SIMDE_FLOAT64_C(  907.54)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -102.88), SIMDE_FLOAT64_C( -307.34),
                         SIMDE_FLOAT64_C(  907.54), SIMDE_FLOAT64_C(  615.34)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   80.56), SIMDE_FLOAT64_C(  256.70),
                         SIMDE_FLOAT64_C(  558.25), SIMDE_FLOAT64_C(  966.02)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -428.91), SIMDE_FLOAT64_C( -946.94),
                         SIMDE_FLOAT64_C( -242.51), SIMDE_FLOAT64_C(  207.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  871.74), SIMDE_FLOAT64_C(  294.25),
                         SIMDE_FLOAT64_C(  -23.76), SIMDE_FLOAT64_C(  857.02)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  294.25), SIMDE_FLOAT64_C( -428.91),
                         SIMDE_FLOAT64_C(  857.02), SIMDE_FLOAT64_C( -242.51)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  871.74), SIMDE_FLOAT64_C( -946.94),
                         SIMDE_FLOAT64_C(  -23.76), SIMDE_FLOAT64_C(  207.30)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  684.37), SIMDE_FLOAT64_C(  -77.07),
                         SIMDE_FLOAT64_C( -492.40), SIMDE_FLOAT64_C( -711.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  911.18), SIMDE_FLOAT64_C( -875.79),
                         SIMDE_FLOAT64_C(  168.17), SIMDE_FLOAT64_C( -582.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -875.79), SIMDE_FLOAT64_C(  684.37),
                         SIMDE_FLOAT64_C( -582.90), SIMDE_FLOAT64_C( -492.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  911.18), SIMDE_FLOAT64_C(  -77.07),
                         SIMDE_FLOAT64_C(  168.17), SIMDE_FLOAT64_C( -711.90)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  844.28), SIMDE_FLOAT64_C( -547.02),
                         SIMDE_FLOAT64_C( -536.51), SIMDE_FLOAT64_C( -341.28)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -205.14), SIMDE_FLOAT64_C(   35.47),
                         SIMDE_FLOAT64_C(  536.74), SIMDE_FLOAT64_C(  843.54)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   35.47), SIMDE_FLOAT64_C(  844.28),
                         SIMDE_FLOAT64_C(  843.54), SIMDE_FLOAT64_C( -536.51)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -205.14), SIMDE_FLOAT64_C( -547.02),
                         SIMDE_FLOAT64_C(  536.74), SIMDE_FLOAT64_C( -341.28)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  597.24), SIMDE_FLOAT64_C(   73.58),
                         SIMDE_FLOAT64_C(  575.62), SIMDE_FLOAT64_C( -337.42)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  430.69), SIMDE_FLOAT64_C( -764.62),
                         SIMDE_FLOAT64_C(  152.29), SIMDE_FLOAT64_C(  529.08)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -764.62), SIMDE_FLOAT64_C(  597.24),
                         SIMDE_FLOAT64_C(  529.08), SIMDE_FLOAT64_C(  575.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  430.69), SIMDE_FLOAT64_C(   73.58),
                         SIMDE_FLOAT64_C(  152.29), SIMDE_FLOAT64_C( -337.42)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  276.59), SIMDE_FLOAT64_C(  918.52),
                         SIMDE_FLOAT64_C(  859.45), SIMDE_FLOAT64_C(   26.68)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -365.57), SIMDE_FLOAT64_C(  780.68),
                         SIMDE_FLOAT64_C(  333.70), SIMDE_FLOAT64_C( -391.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  780.68), SIMDE_FLOAT64_C(  276.59),
                         SIMDE_FLOAT64_C( -391.20), SIMDE_FLOAT64_C(  859.45)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -365.57), SIMDE_FLOAT64_C(  918.52),
                         SIMDE_FLOAT64_C(  333.70), SIMDE_FLOAT64_C(   26.68)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r;
    
    r = simde_mm256_shuffle_pd(test_vec[i].a, test_vec[i].b, 0x5);
    simde_assert_m256d_f64_equal(r, test_vec[i].r1, 1);
    
    r = simde_mm256_shuffle_pd(test_vec[i].a, test_vec[i].b, 0xa);
    simde_assert_m256d_f64_equal(r, test_vec[i].r2, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_sqrt_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   37.27), SIMDE_FLOAT32_C(  842.37),
                         SIMDE_FLOAT32_C(  821.35), SIMDE_FLOAT32_C(  882.42),
                         SIMDE_FLOAT32_C(  506.85), SIMDE_FLOAT32_C(  418.78),
                         SIMDE_FLOAT32_C(  759.20), SIMDE_FLOAT32_C(  903.29)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    6.10), SIMDE_FLOAT32_C(   29.02),
                         SIMDE_FLOAT32_C(   28.66), SIMDE_FLOAT32_C(   29.71),
                         SIMDE_FLOAT32_C(   22.51), SIMDE_FLOAT32_C(   20.46),
                         SIMDE_FLOAT32_C(   27.55), SIMDE_FLOAT32_C(   30.05)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  675.11), SIMDE_FLOAT32_C(  473.44),
                         SIMDE_FLOAT32_C(  936.76), SIMDE_FLOAT32_C(  315.53),
                         SIMDE_FLOAT32_C(  585.70), SIMDE_FLOAT32_C(  466.99),
                         SIMDE_FLOAT32_C(  876.99), SIMDE_FLOAT32_C(  421.09)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   25.98), SIMDE_FLOAT32_C(   21.76),
                         SIMDE_FLOAT32_C(   30.61), SIMDE_FLOAT32_C(   17.76),
                         SIMDE_FLOAT32_C(   24.20), SIMDE_FLOAT32_C(   21.61),
                         SIMDE_FLOAT32_C(   29.61), SIMDE_FLOAT32_C(   20.52)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  455.63), SIMDE_FLOAT32_C(  708.48),
                         SIMDE_FLOAT32_C(  426.65), SIMDE_FLOAT32_C(   16.24),
                         SIMDE_FLOAT32_C(  899.49), SIMDE_FLOAT32_C(  710.23),
                         SIMDE_FLOAT32_C(  195.07), SIMDE_FLOAT32_C(  877.55)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   21.35), SIMDE_FLOAT32_C(   26.62),
                         SIMDE_FLOAT32_C(   20.66), SIMDE_FLOAT32_C(    4.03),
                         SIMDE_FLOAT32_C(   29.99), SIMDE_FLOAT32_C(   26.65),
                         SIMDE_FLOAT32_C(   13.97), SIMDE_FLOAT32_C(   29.62)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  247.65), SIMDE_FLOAT32_C(  650.69),
                         SIMDE_FLOAT32_C(  691.01), SIMDE_FLOAT32_C(  931.91),
                         SIMDE_FLOAT32_C(  760.76), SIMDE_FLOAT32_C(  925.05),
                         SIMDE_FLOAT32_C(  438.39), SIMDE_FLOAT32_C(  204.75)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   15.74), SIMDE_FLOAT32_C(   25.51),
                         SIMDE_FLOAT32_C(   26.29), SIMDE_FLOAT32_C(   30.53),
                         SIMDE_FLOAT32_C(   27.58), SIMDE_FLOAT32_C(   30.41),
                         SIMDE_FLOAT32_C(   20.94), SIMDE_FLOAT32_C(   14.31)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  281.85), SIMDE_FLOAT32_C(  525.43),
                         SIMDE_FLOAT32_C(   50.88), SIMDE_FLOAT32_C(  685.15),
                         SIMDE_FLOAT32_C(  223.40), SIMDE_FLOAT32_C(  911.30),
                         SIMDE_FLOAT32_C(   97.50), SIMDE_FLOAT32_C(  436.55)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   16.79), SIMDE_FLOAT32_C(   22.92),
                         SIMDE_FLOAT32_C(    7.13), SIMDE_FLOAT32_C(   26.18),
                         SIMDE_FLOAT32_C(   14.95), SIMDE_FLOAT32_C(   30.19),
                         SIMDE_FLOAT32_C(    9.87), SIMDE_FLOAT32_C(   20.89)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  420.63), SIMDE_FLOAT32_C(  643.40),
                         SIMDE_FLOAT32_C(  474.44), SIMDE_FLOAT32_C(  474.06),
                         SIMDE_FLOAT32_C(  331.02), SIMDE_FLOAT32_C(  191.18),
                         SIMDE_FLOAT32_C(  614.70), SIMDE_FLOAT32_C(  135.59)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   20.51), SIMDE_FLOAT32_C(   25.37),
                         SIMDE_FLOAT32_C(   21.78), SIMDE_FLOAT32_C(   21.77),
                         SIMDE_FLOAT32_C(   18.19), SIMDE_FLOAT32_C(   13.83),
                         SIMDE_FLOAT32_C(   24.79), SIMDE_FLOAT32_C(   11.64)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  777.57), SIMDE_FLOAT32_C(  684.09),
                         SIMDE_FLOAT32_C(  183.20), SIMDE_FLOAT32_C(  761.60),
                         SIMDE_FLOAT32_C(  226.72), SIMDE_FLOAT32_C(  710.47),
                         SIMDE_FLOAT32_C(  853.48), SIMDE_FLOAT32_C(  115.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   27.88), SIMDE_FLOAT32_C(   26.16),
                         SIMDE_FLOAT32_C(   13.54), SIMDE_FLOAT32_C(   27.60),
                         SIMDE_FLOAT32_C(   15.06), SIMDE_FLOAT32_C(   26.65),
                         SIMDE_FLOAT32_C(   29.21), SIMDE_FLOAT32_C(   10.76)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  797.47), SIMDE_FLOAT32_C(  634.08),
                         SIMDE_FLOAT32_C(  881.12), SIMDE_FLOAT32_C(  697.30),
                         SIMDE_FLOAT32_C(  189.46), SIMDE_FLOAT32_C(   47.99),
                         SIMDE_FLOAT32_C(   85.88), SIMDE_FLOAT32_C(  938.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   28.24), SIMDE_FLOAT32_C(   25.18),
                         SIMDE_FLOAT32_C(   29.68), SIMDE_FLOAT32_C(   26.41),
                         SIMDE_FLOAT32_C(   13.76), SIMDE_FLOAT32_C(    6.93),
                         SIMDE_FLOAT32_C(    9.27), SIMDE_FLOAT32_C(   30.63)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_sqrt_ps(test_vec[i].a);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_sqrt_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  121.95), SIMDE_FLOAT64_C(  169.21),
                         SIMDE_FLOAT64_C(  224.34), SIMDE_FLOAT64_C(  661.75)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   11.04), SIMDE_FLOAT64_C(   13.01),
                         SIMDE_FLOAT64_C(   14.98), SIMDE_FLOAT64_C(   25.72)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   41.79), SIMDE_FLOAT64_C(   48.53),
                         SIMDE_FLOAT64_C(   17.25), SIMDE_FLOAT64_C(  585.21)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    6.46), SIMDE_FLOAT64_C(    6.97),
                         SIMDE_FLOAT64_C(    4.15), SIMDE_FLOAT64_C(   24.19)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  323.54), SIMDE_FLOAT64_C(   12.60),
                         SIMDE_FLOAT64_C(  916.80), SIMDE_FLOAT64_C(  392.02)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   17.99), SIMDE_FLOAT64_C(    3.55),
                         SIMDE_FLOAT64_C(   30.28), SIMDE_FLOAT64_C(   19.80)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  317.36), SIMDE_FLOAT64_C(  248.26),
                         SIMDE_FLOAT64_C(   48.91), SIMDE_FLOAT64_C(  291.13)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   17.81), SIMDE_FLOAT64_C(   15.76),
                         SIMDE_FLOAT64_C(    6.99), SIMDE_FLOAT64_C(   17.06)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  476.37), SIMDE_FLOAT64_C(  799.71),
                         SIMDE_FLOAT64_C(  234.23), SIMDE_FLOAT64_C(  908.93)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   21.83), SIMDE_FLOAT64_C(   28.28),
                         SIMDE_FLOAT64_C(   15.30), SIMDE_FLOAT64_C(   30.15)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  937.16), SIMDE_FLOAT64_C(  886.92),
                         SIMDE_FLOAT64_C(  703.77), SIMDE_FLOAT64_C(  383.22)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   30.61), SIMDE_FLOAT64_C(   29.78),
                         SIMDE_FLOAT64_C(   26.53), SIMDE_FLOAT64_C(   19.58)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   36.08), SIMDE_FLOAT64_C(  932.02),
                         SIMDE_FLOAT64_C(  592.55), SIMDE_FLOAT64_C(  593.01)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    6.01), SIMDE_FLOAT64_C(   30.53),
                         SIMDE_FLOAT64_C(   24.34), SIMDE_FLOAT64_C(   24.35)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  436.31), SIMDE_FLOAT64_C(  915.76),
                         SIMDE_FLOAT64_C(  575.57), SIMDE_FLOAT64_C(  268.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   20.89), SIMDE_FLOAT64_C(   30.26),
                         SIMDE_FLOAT64_C(   23.99), SIMDE_FLOAT64_C(   16.39)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_sqrt_pd(test_vec[i].a);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_store_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    SIMDE_ALIGN(32) simde_float32 r[8];
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  256.09), SIMDE_FLOAT32_C(  768.79),
                         SIMDE_FLOAT32_C(  201.90), SIMDE_FLOAT32_C(  339.33),
                         SIMDE_FLOAT32_C(  957.46), SIMDE_FLOAT32_C(  728.44),
                         SIMDE_FLOAT32_C(   73.67), SIMDE_FLOAT32_C(  440.11)),
      { SIMDE_FLOAT32_C(  440.11), SIMDE_FLOAT32_C(   73.67),
        SIMDE_FLOAT32_C(  728.44), SIMDE_FLOAT32_C(  957.46),
        SIMDE_FLOAT32_C(  339.33), SIMDE_FLOAT32_C(  201.90),
        SIMDE_FLOAT32_C(  768.79), SIMDE_FLOAT32_C(  256.09) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -72.04), SIMDE_FLOAT32_C( -425.25),
                         SIMDE_FLOAT32_C(  471.77), SIMDE_FLOAT32_C(  976.75),
                         SIMDE_FLOAT32_C( -510.20), SIMDE_FLOAT32_C(  696.54),
                         SIMDE_FLOAT32_C( -843.54), SIMDE_FLOAT32_C( -868.41)),
      { SIMDE_FLOAT32_C( -868.41), SIMDE_FLOAT32_C( -843.54),
        SIMDE_FLOAT32_C(  696.54), SIMDE_FLOAT32_C( -510.20),
        SIMDE_FLOAT32_C(  976.75), SIMDE_FLOAT32_C(  471.77),
        SIMDE_FLOAT32_C( -425.25), SIMDE_FLOAT32_C(  -72.04) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -304.23), SIMDE_FLOAT32_C(  477.48),
                         SIMDE_FLOAT32_C(  356.58), SIMDE_FLOAT32_C(  955.81),
                         SIMDE_FLOAT32_C(  999.99), SIMDE_FLOAT32_C(  487.33),
                         SIMDE_FLOAT32_C(  633.61), SIMDE_FLOAT32_C(  518.11)),
      { SIMDE_FLOAT32_C(  518.11), SIMDE_FLOAT32_C(  633.61),
        SIMDE_FLOAT32_C(  487.33), SIMDE_FLOAT32_C(  999.99),
        SIMDE_FLOAT32_C(  955.81), SIMDE_FLOAT32_C(  356.58),
        SIMDE_FLOAT32_C(  477.48), SIMDE_FLOAT32_C( -304.23) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   88.04), SIMDE_FLOAT32_C( -296.25),
                         SIMDE_FLOAT32_C(  948.33), SIMDE_FLOAT32_C( -584.17),
                         SIMDE_FLOAT32_C( -796.11), SIMDE_FLOAT32_C(  -38.84),
                         SIMDE_FLOAT32_C( -706.11), SIMDE_FLOAT32_C(  347.32)),
      { SIMDE_FLOAT32_C(  347.32), SIMDE_FLOAT32_C( -706.11),
        SIMDE_FLOAT32_C(  -38.84), SIMDE_FLOAT32_C( -796.11),
        SIMDE_FLOAT32_C( -584.17), SIMDE_FLOAT32_C(  948.33),
        SIMDE_FLOAT32_C( -296.25), SIMDE_FLOAT32_C(   88.04) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -143.76), SIMDE_FLOAT32_C(  504.36),
                         SIMDE_FLOAT32_C( -154.12), SIMDE_FLOAT32_C(  375.43),
                         SIMDE_FLOAT32_C( -307.18), SIMDE_FLOAT32_C(  256.93),
                         SIMDE_FLOAT32_C(   78.86), SIMDE_FLOAT32_C(  526.77)),
      { SIMDE_FLOAT32_C(  526.77), SIMDE_FLOAT32_C(   78.86),
        SIMDE_FLOAT32_C(  256.93), SIMDE_FLOAT32_C( -307.18),
        SIMDE_FLOAT32_C(  375.43), SIMDE_FLOAT32_C( -154.12),
        SIMDE_FLOAT32_C(  504.36), SIMDE_FLOAT32_C( -143.76) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  597.82), SIMDE_FLOAT32_C(  697.68),
                         SIMDE_FLOAT32_C( -285.13), SIMDE_FLOAT32_C(  354.51),
                         SIMDE_FLOAT32_C(   41.32), SIMDE_FLOAT32_C( -445.78),
                         SIMDE_FLOAT32_C( -483.17), SIMDE_FLOAT32_C( -727.28)),
      { SIMDE_FLOAT32_C( -727.28), SIMDE_FLOAT32_C( -483.17),
        SIMDE_FLOAT32_C( -445.78), SIMDE_FLOAT32_C(   41.32),
        SIMDE_FLOAT32_C(  354.51), SIMDE_FLOAT32_C( -285.13),
        SIMDE_FLOAT32_C(  697.68), SIMDE_FLOAT32_C(  597.82) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -441.93), SIMDE_FLOAT32_C( -382.04),
                         SIMDE_FLOAT32_C(  392.67), SIMDE_FLOAT32_C(  690.10),
                         SIMDE_FLOAT32_C(  -30.26), SIMDE_FLOAT32_C( -968.87),
                         SIMDE_FLOAT32_C( -246.46), SIMDE_FLOAT32_C(  625.73)),
      { SIMDE_FLOAT32_C(  625.73), SIMDE_FLOAT32_C( -246.46),
        SIMDE_FLOAT32_C( -968.87), SIMDE_FLOAT32_C(  -30.26),
        SIMDE_FLOAT32_C(  690.10), SIMDE_FLOAT32_C(  392.67),
        SIMDE_FLOAT32_C( -382.04), SIMDE_FLOAT32_C( -441.93) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  442.97), SIMDE_FLOAT32_C(  -20.37),
                         SIMDE_FLOAT32_C(  758.01), SIMDE_FLOAT32_C( -507.47),
                         SIMDE_FLOAT32_C(  529.68), SIMDE_FLOAT32_C( -598.71),
                         SIMDE_FLOAT32_C(  952.31), SIMDE_FLOAT32_C( -565.36)),
      { SIMDE_FLOAT32_C( -565.36), SIMDE_FLOAT32_C(  952.31),
        SIMDE_FLOAT32_C( -598.71), SIMDE_FLOAT32_C(  529.68),
        SIMDE_FLOAT32_C( -507.47), SIMDE_FLOAT32_C(  758.01),
        SIMDE_FLOAT32_C(  -20.37), SIMDE_FLOAT32_C(  442.97) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    SIMDE_ALIGN(32) simde_float32 r[8];
    simde_mm256_store_ps(r, test_vec[i].a);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_store_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    SIMDE_ALIGN(32) simde_float64 r[8];
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  771.84), SIMDE_FLOAT64_C(  578.19),
                         SIMDE_FLOAT64_C(  287.63), SIMDE_FLOAT64_C(  196.16)),
      { SIMDE_FLOAT64_C(  196.16), SIMDE_FLOAT64_C(  287.63),
        SIMDE_FLOAT64_C(  578.19), SIMDE_FLOAT64_C(  771.84) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -941.73), SIMDE_FLOAT64_C( -687.45),
                         SIMDE_FLOAT64_C( -865.09), SIMDE_FLOAT64_C(  586.03)),
      { SIMDE_FLOAT64_C(  586.03), SIMDE_FLOAT64_C( -865.09),
        SIMDE_FLOAT64_C( -687.45), SIMDE_FLOAT64_C( -941.73) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -342.90), SIMDE_FLOAT64_C( -658.61),
                         SIMDE_FLOAT64_C(  882.05), SIMDE_FLOAT64_C( -607.89)),
      { SIMDE_FLOAT64_C( -607.89), SIMDE_FLOAT64_C(  882.05),
        SIMDE_FLOAT64_C( -658.61), SIMDE_FLOAT64_C( -342.90) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -248.91), SIMDE_FLOAT64_C( -473.20),
                         SIMDE_FLOAT64_C(  170.76), SIMDE_FLOAT64_C( -407.02)),
      { SIMDE_FLOAT64_C( -407.02), SIMDE_FLOAT64_C(  170.76),
        SIMDE_FLOAT64_C( -473.20), SIMDE_FLOAT64_C( -248.91) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  181.69), SIMDE_FLOAT64_C(  697.67),
                         SIMDE_FLOAT64_C(  911.25), SIMDE_FLOAT64_C( -299.04)),
      { SIMDE_FLOAT64_C( -299.04), SIMDE_FLOAT64_C(  911.25),
        SIMDE_FLOAT64_C(  697.67), SIMDE_FLOAT64_C(  181.69) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -630.92), SIMDE_FLOAT64_C( -612.42),
                         SIMDE_FLOAT64_C(  645.34), SIMDE_FLOAT64_C( -379.90)),
      { SIMDE_FLOAT64_C( -379.90), SIMDE_FLOAT64_C(  645.34),
        SIMDE_FLOAT64_C( -612.42), SIMDE_FLOAT64_C( -630.92) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -339.32), SIMDE_FLOAT64_C(  404.98),
                         SIMDE_FLOAT64_C( -361.76), SIMDE_FLOAT64_C(  391.60)),
      { SIMDE_FLOAT64_C(  391.60), SIMDE_FLOAT64_C( -361.76),
        SIMDE_FLOAT64_C(  404.98), SIMDE_FLOAT64_C( -339.32) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  714.72), SIMDE_FLOAT64_C(  997.58),
                         SIMDE_FLOAT64_C(  807.47), SIMDE_FLOAT64_C(  948.80)),
      { SIMDE_FLOAT64_C(  948.80), SIMDE_FLOAT64_C(  807.47),
        SIMDE_FLOAT64_C(  997.58), SIMDE_FLOAT64_C(  714.72) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    SIMDE_ALIGN(32) simde_float64 r[8];
    simde_mm256_store_pd(r, test_vec[i].a);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_store_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( -495387953), INT32_C( 1389422093), INT32_C( 1549613541), INT32_C( 1621396930),
                            INT32_C(  431885981), INT32_C( -495493978), INT32_C(  957980176), INT32_C( -756622382)),
      simde_mm256_set_epi32(INT32_C( -495387953), INT32_C( 1389422093), INT32_C( 1549613541), INT32_C( 1621396930),
                            INT32_C(  431885981), INT32_C( -495493978), INT32_C(  957980176), INT32_C( -756622382)) },
    { simde_mm256_set_epi32(INT32_C(-1537563225), INT32_C( -111752931), INT32_C( 2068479386), INT32_C( 2004807479),
                            INT32_C( 2110162316), INT32_C( 1854708769), INT32_C(  -83811592), INT32_C( -892599604)),
      simde_mm256_set_epi32(INT32_C(-1537563225), INT32_C( -111752931), INT32_C( 2068479386), INT32_C( 2004807479),
                            INT32_C( 2110162316), INT32_C( 1854708769), INT32_C(  -83811592), INT32_C( -892599604)) },
    { simde_mm256_set_epi32(INT32_C( 1682126570), INT32_C(  340006289), INT32_C(  149083722), INT32_C( 1734045351),
                            INT32_C(-1572830580), INT32_C( 1824421914), INT32_C( 1423738129), INT32_C( -492096848)),
      simde_mm256_set_epi32(INT32_C( 1682126570), INT32_C(  340006289), INT32_C(  149083722), INT32_C( 1734045351),
                            INT32_C(-1572830580), INT32_C( 1824421914), INT32_C( 1423738129), INT32_C( -492096848)) },
    { simde_mm256_set_epi32(INT32_C(-2079347795), INT32_C( -336455233), INT32_C( -761216501), INT32_C( 1784601451),
                            INT32_C(  386854500), INT32_C(  177253765), INT32_C(  797476379), INT32_C( -848434210)),
      simde_mm256_set_epi32(INT32_C(-2079347795), INT32_C( -336455233), INT32_C( -761216501), INT32_C( 1784601451),
                            INT32_C(  386854500), INT32_C(  177253765), INT32_C(  797476379), INT32_C( -848434210)) },
    { simde_mm256_set_epi32(INT32_C(-1024397654), INT32_C(  273228891), INT32_C( -327343542), INT32_C(  941152347),
                            INT32_C(-1943801853), INT32_C( -571606335), INT32_C(-1600503753), INT32_C(    3657489)),
      simde_mm256_set_epi32(INT32_C(-1024397654), INT32_C(  273228891), INT32_C( -327343542), INT32_C(  941152347),
                            INT32_C(-1943801853), INT32_C( -571606335), INT32_C(-1600503753), INT32_C(    3657489)) },
    { simde_mm256_set_epi32(INT32_C(  392666418), INT32_C(-1141495552), INT32_C(-1265226558), INT32_C( -341769681),
                            INT32_C(  784056885), INT32_C(   -8791049), INT32_C( -255179514), INT32_C( 1505512077)),
      simde_mm256_set_epi32(INT32_C(  392666418), INT32_C(-1141495552), INT32_C(-1265226558), INT32_C( -341769681),
                            INT32_C(  784056885), INT32_C(   -8791049), INT32_C( -255179514), INT32_C( 1505512077)) },
    { simde_mm256_set_epi32(INT32_C(-2051731929), INT32_C( 1367430487), INT32_C( -142986568), INT32_C( 1381573702),
                            INT32_C( -856833247), INT32_C(  665026143), INT32_C( 1196790497), INT32_C( -507260176)),
      simde_mm256_set_epi32(INT32_C(-2051731929), INT32_C( 1367430487), INT32_C( -142986568), INT32_C( 1381573702),
                            INT32_C( -856833247), INT32_C(  665026143), INT32_C( 1196790497), INT32_C( -507260176)) },
    { simde_mm256_set_epi32(INT32_C( -878005657), INT32_C( -546637276), INT32_C(-1056155816), INT32_C(  259320365),
                            INT32_C(-1537222115), INT32_C(  895058753), INT32_C( -970999316), INT32_C(  224281618)),
      simde_mm256_set_epi32(INT32_C( -878005657), INT32_C( -546637276), INT32_C(-1056155816), INT32_C(  259320365),
                            INT32_C(-1537222115), INT32_C(  895058753), INT32_C( -970999316), INT32_C(  224281618)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r;
    simde_mm256_store_si256(&r, test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_storeu_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde_float32 r[8];
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  389.47), SIMDE_FLOAT32_C(  -23.53),
                         SIMDE_FLOAT32_C(  971.41), SIMDE_FLOAT32_C(  968.93),
                         SIMDE_FLOAT32_C(  388.52), SIMDE_FLOAT32_C(  400.32),
                         SIMDE_FLOAT32_C( -988.67), SIMDE_FLOAT32_C(  867.57)),
      { SIMDE_FLOAT32_C(  867.57), SIMDE_FLOAT32_C( -988.67),
        SIMDE_FLOAT32_C(  400.32), SIMDE_FLOAT32_C(  388.52),
        SIMDE_FLOAT32_C(  968.93), SIMDE_FLOAT32_C(  971.41),
        SIMDE_FLOAT32_C(  -23.53), SIMDE_FLOAT32_C(  389.47) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -904.63), SIMDE_FLOAT32_C(  373.49),
                         SIMDE_FLOAT32_C( -535.56), SIMDE_FLOAT32_C(  674.97),
                         SIMDE_FLOAT32_C( -321.09), SIMDE_FLOAT32_C( -666.72),
                         SIMDE_FLOAT32_C(  574.65), SIMDE_FLOAT32_C( -486.68)),
      { SIMDE_FLOAT32_C( -486.68), SIMDE_FLOAT32_C(  574.65),
        SIMDE_FLOAT32_C( -666.72), SIMDE_FLOAT32_C( -321.09),
        SIMDE_FLOAT32_C(  674.97), SIMDE_FLOAT32_C( -535.56),
        SIMDE_FLOAT32_C(  373.49), SIMDE_FLOAT32_C( -904.63) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  716.68), SIMDE_FLOAT32_C( -902.50),
                         SIMDE_FLOAT32_C(  689.19), SIMDE_FLOAT32_C(  562.96),
                         SIMDE_FLOAT32_C(  218.97), SIMDE_FLOAT32_C( -717.02),
                         SIMDE_FLOAT32_C(   50.08), SIMDE_FLOAT32_C(  473.03)),
      { SIMDE_FLOAT32_C(  473.03), SIMDE_FLOAT32_C(   50.08),
        SIMDE_FLOAT32_C( -717.02), SIMDE_FLOAT32_C(  218.97),
        SIMDE_FLOAT32_C(  562.96), SIMDE_FLOAT32_C(  689.19),
        SIMDE_FLOAT32_C( -902.50), SIMDE_FLOAT32_C(  716.68) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -748.65), SIMDE_FLOAT32_C( -546.25),
                         SIMDE_FLOAT32_C( -755.41), SIMDE_FLOAT32_C(  720.41),
                         SIMDE_FLOAT32_C(  469.62), SIMDE_FLOAT32_C( -529.37),
                         SIMDE_FLOAT32_C(   68.16), SIMDE_FLOAT32_C( -880.26)),
      { SIMDE_FLOAT32_C( -880.26), SIMDE_FLOAT32_C(   68.16),
        SIMDE_FLOAT32_C( -529.37), SIMDE_FLOAT32_C(  469.62),
        SIMDE_FLOAT32_C(  720.41), SIMDE_FLOAT32_C( -755.41),
        SIMDE_FLOAT32_C( -546.25), SIMDE_FLOAT32_C( -748.65) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -639.31), SIMDE_FLOAT32_C(  210.80),
                         SIMDE_FLOAT32_C( -481.50), SIMDE_FLOAT32_C( -773.33),
                         SIMDE_FLOAT32_C(  766.24), SIMDE_FLOAT32_C(  722.05),
                         SIMDE_FLOAT32_C(  569.99), SIMDE_FLOAT32_C(   78.20)),
      { SIMDE_FLOAT32_C(   78.20), SIMDE_FLOAT32_C(  569.99),
        SIMDE_FLOAT32_C(  722.05), SIMDE_FLOAT32_C(  766.24),
        SIMDE_FLOAT32_C( -773.33), SIMDE_FLOAT32_C( -481.50),
        SIMDE_FLOAT32_C(  210.80), SIMDE_FLOAT32_C( -639.31) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  219.96), SIMDE_FLOAT32_C( -967.95),
                         SIMDE_FLOAT32_C( -966.73), SIMDE_FLOAT32_C( -375.54),
                         SIMDE_FLOAT32_C( -872.08), SIMDE_FLOAT32_C( -211.68),
                         SIMDE_FLOAT32_C(  797.84), SIMDE_FLOAT32_C(  819.26)),
      { SIMDE_FLOAT32_C(  819.26), SIMDE_FLOAT32_C(  797.84),
        SIMDE_FLOAT32_C( -211.68), SIMDE_FLOAT32_C( -872.08),
        SIMDE_FLOAT32_C( -375.54), SIMDE_FLOAT32_C( -966.73),
        SIMDE_FLOAT32_C( -967.95), SIMDE_FLOAT32_C(  219.96) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  601.98), SIMDE_FLOAT32_C( -827.42),
                         SIMDE_FLOAT32_C(  747.06), SIMDE_FLOAT32_C( -914.70),
                         SIMDE_FLOAT32_C(  111.41), SIMDE_FLOAT32_C(  873.12),
                         SIMDE_FLOAT32_C(  763.60), SIMDE_FLOAT32_C(  161.15)),
      { SIMDE_FLOAT32_C(  161.15), SIMDE_FLOAT32_C(  763.60),
        SIMDE_FLOAT32_C(  873.12), SIMDE_FLOAT32_C(  111.41),
        SIMDE_FLOAT32_C( -914.70), SIMDE_FLOAT32_C(  747.06),
        SIMDE_FLOAT32_C( -827.42), SIMDE_FLOAT32_C(  601.98) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  800.45), SIMDE_FLOAT32_C(  526.22),
                         SIMDE_FLOAT32_C(  670.34), SIMDE_FLOAT32_C(  433.87),
                         SIMDE_FLOAT32_C(  651.08), SIMDE_FLOAT32_C( -532.01),
                         SIMDE_FLOAT32_C( -619.94), SIMDE_FLOAT32_C(   88.39)),
      { SIMDE_FLOAT32_C(   88.39), SIMDE_FLOAT32_C( -619.94),
        SIMDE_FLOAT32_C( -532.01), SIMDE_FLOAT32_C(  651.08),
        SIMDE_FLOAT32_C(  433.87), SIMDE_FLOAT32_C(  670.34),
        SIMDE_FLOAT32_C(  526.22), SIMDE_FLOAT32_C(  800.45) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32 r[8];
    simde_mm256_storeu_ps(r, test_vec[i].a);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_storeu_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde_float64 r[4];
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -416.91), SIMDE_FLOAT64_C( -266.91),
                         SIMDE_FLOAT64_C(  400.77), SIMDE_FLOAT64_C(  614.06)),
      { SIMDE_FLOAT64_C(  614.06), SIMDE_FLOAT64_C(  400.77),
        SIMDE_FLOAT64_C( -266.91), SIMDE_FLOAT64_C( -416.91) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -82.84), SIMDE_FLOAT64_C(  375.26),
                         SIMDE_FLOAT64_C( -316.62), SIMDE_FLOAT64_C(  608.04)),
      { SIMDE_FLOAT64_C(  608.04), SIMDE_FLOAT64_C( -316.62),
        SIMDE_FLOAT64_C(  375.26), SIMDE_FLOAT64_C(  -82.84) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  218.37), SIMDE_FLOAT64_C( -388.98),
                         SIMDE_FLOAT64_C( -164.15), SIMDE_FLOAT64_C(   66.39)),
      { SIMDE_FLOAT64_C(   66.39), SIMDE_FLOAT64_C( -164.15),
        SIMDE_FLOAT64_C( -388.98), SIMDE_FLOAT64_C(  218.37) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  414.66), SIMDE_FLOAT64_C(  373.86),
                         SIMDE_FLOAT64_C(  387.85), SIMDE_FLOAT64_C(  140.99)),
      { SIMDE_FLOAT64_C(  140.99), SIMDE_FLOAT64_C(  387.85),
        SIMDE_FLOAT64_C(  373.86), SIMDE_FLOAT64_C(  414.66) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  513.43), SIMDE_FLOAT64_C( -671.43),
                         SIMDE_FLOAT64_C( -383.59), SIMDE_FLOAT64_C(  476.58)),
      { SIMDE_FLOAT64_C(  476.58), SIMDE_FLOAT64_C( -383.59),
        SIMDE_FLOAT64_C( -671.43), SIMDE_FLOAT64_C(  513.43) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -620.74), SIMDE_FLOAT64_C(  593.91),
                         SIMDE_FLOAT64_C(  595.45), SIMDE_FLOAT64_C(  326.69)),
      { SIMDE_FLOAT64_C(  326.69), SIMDE_FLOAT64_C(  595.45),
        SIMDE_FLOAT64_C(  593.91), SIMDE_FLOAT64_C( -620.74) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  933.41), SIMDE_FLOAT64_C( -583.63),
                         SIMDE_FLOAT64_C(  451.59), SIMDE_FLOAT64_C(   17.38)),
      { SIMDE_FLOAT64_C(   17.38), SIMDE_FLOAT64_C(  451.59),
        SIMDE_FLOAT64_C( -583.63), SIMDE_FLOAT64_C(  933.41) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -951.90), SIMDE_FLOAT64_C(  -96.08),
                         SIMDE_FLOAT64_C( -475.76), SIMDE_FLOAT64_C( -920.22)),
      { SIMDE_FLOAT64_C( -920.22), SIMDE_FLOAT64_C( -475.76),
        SIMDE_FLOAT64_C(  -96.08), SIMDE_FLOAT64_C( -951.90) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64 r[4];
    simde_mm256_storeu_pd(r, test_vec[i].a);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_storeu_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(-1690076372), INT32_C(  273159718), INT32_C(  661600261), INT32_C( -431509063),
                            INT32_C(-1410315245), INT32_C(  938478074), INT32_C( -325173074), INT32_C( -955068873)),
      simde_mm256_set_epi32(INT32_C(-1690076372), INT32_C(  273159718), INT32_C(  661600261), INT32_C( -431509063),
                            INT32_C(-1410315245), INT32_C(  938478074), INT32_C( -325173074), INT32_C( -955068873)) },
    { simde_mm256_set_epi32(INT32_C( 1349804757), INT32_C( -716302605), INT32_C( -407964159), INT32_C( 1438548072),
                            INT32_C(-1765250498), INT32_C(-1398568590), INT32_C( -166142303), INT32_C(-1616708423)),
      simde_mm256_set_epi32(INT32_C( 1349804757), INT32_C( -716302605), INT32_C( -407964159), INT32_C( 1438548072),
                            INT32_C(-1765250498), INT32_C(-1398568590), INT32_C( -166142303), INT32_C(-1616708423)) },
    { simde_mm256_set_epi32(INT32_C( 1299583779), INT32_C( 1018639695), INT32_C(  378838390), INT32_C(  823542835),
                            INT32_C(  107040332), INT32_C( 1160607838), INT32_C(-1073772085), INT32_C(  550633253)),
      simde_mm256_set_epi32(INT32_C( 1299583779), INT32_C( 1018639695), INT32_C(  378838390), INT32_C(  823542835),
                            INT32_C(  107040332), INT32_C( 1160607838), INT32_C(-1073772085), INT32_C(  550633253)) },
    { simde_mm256_set_epi32(INT32_C(-2020164947), INT32_C( 1097566074), INT32_C(  838709016), INT32_C(-1310900036),
                            INT32_C(  205435207), INT32_C(-1570208834), INT32_C( -866634640), INT32_C(-1469292111)),
      simde_mm256_set_epi32(INT32_C(-2020164947), INT32_C( 1097566074), INT32_C(  838709016), INT32_C(-1310900036),
                            INT32_C(  205435207), INT32_C(-1570208834), INT32_C( -866634640), INT32_C(-1469292111)) },
    { simde_mm256_set_epi32(INT32_C( 1996197805), INT32_C(-1742000211), INT32_C( -252812234), INT32_C(  126353816),
                            INT32_C(-1209789142), INT32_C(-1818044476), INT32_C(-1843734346), INT32_C( 1208980142)),
      simde_mm256_set_epi32(INT32_C( 1996197805), INT32_C(-1742000211), INT32_C( -252812234), INT32_C(  126353816),
                            INT32_C(-1209789142), INT32_C(-1818044476), INT32_C(-1843734346), INT32_C( 1208980142)) },
    { simde_mm256_set_epi32(INT32_C(  264233747), INT32_C(   65047959), INT32_C(-2078914587), INT32_C(  -76956293),
                            INT32_C(-1404669906), INT32_C(-1580100987), INT32_C(-1585720935), INT32_C( -962400296)),
      simde_mm256_set_epi32(INT32_C(  264233747), INT32_C(   65047959), INT32_C(-2078914587), INT32_C(  -76956293),
                            INT32_C(-1404669906), INT32_C(-1580100987), INT32_C(-1585720935), INT32_C( -962400296)) },
    { simde_mm256_set_epi32(INT32_C(-2048043478), INT32_C( -746745729), INT32_C(  515423412), INT32_C(-1288873149),
                            INT32_C(  -50167373), INT32_C(  751152155), INT32_C(   63560258), INT32_C(  839041982)),
      simde_mm256_set_epi32(INT32_C(-2048043478), INT32_C( -746745729), INT32_C(  515423412), INT32_C(-1288873149),
                            INT32_C(  -50167373), INT32_C(  751152155), INT32_C(   63560258), INT32_C(  839041982)) },
    { simde_mm256_set_epi32(INT32_C(-1066512345), INT32_C(-1608586608), INT32_C( 2001494396), INT32_C(  667109925),
                            INT32_C(  134968304), INT32_C(  154885492), INT32_C(  204100449), INT32_C(-2103566856)),
      simde_mm256_set_epi32(INT32_C(-1066512345), INT32_C(-1608586608), INT32_C( 2001494396), INT32_C(  667109925),
                            INT32_C(  134968304), INT32_C(  154885492), INT32_C(  204100449), INT32_C(-2103566856)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r;
    simde_mm256_storeu_si256(&r, test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_storeu2_m128d(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde_float64 lo[2];
    simde_float64 hi[2];
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -194.98), SIMDE_FLOAT64_C(  916.70),
                         SIMDE_FLOAT64_C(  887.89), SIMDE_FLOAT64_C( -369.82)),
      { SIMDE_FLOAT64_C( -369.82), SIMDE_FLOAT64_C(  887.89) },
      { SIMDE_FLOAT64_C(  916.70), SIMDE_FLOAT64_C( -194.98) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -641.49), SIMDE_FLOAT64_C( -881.69),
                         SIMDE_FLOAT64_C(  627.53), SIMDE_FLOAT64_C(  575.62)),
      { SIMDE_FLOAT64_C(  575.62), SIMDE_FLOAT64_C(  627.53) },
      { SIMDE_FLOAT64_C( -881.69), SIMDE_FLOAT64_C( -641.49) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  518.30), SIMDE_FLOAT64_C( -433.95),
                         SIMDE_FLOAT64_C( -285.84), SIMDE_FLOAT64_C( -221.03)),
      { SIMDE_FLOAT64_C( -221.03), SIMDE_FLOAT64_C( -285.84) },
      { SIMDE_FLOAT64_C( -433.95), SIMDE_FLOAT64_C(  518.30) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -662.71), SIMDE_FLOAT64_C(  122.75),
                         SIMDE_FLOAT64_C( -172.81), SIMDE_FLOAT64_C(  852.48)),
      { SIMDE_FLOAT64_C(  852.48), SIMDE_FLOAT64_C( -172.81) },
      { SIMDE_FLOAT64_C(  122.75), SIMDE_FLOAT64_C( -662.71) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  223.39), SIMDE_FLOAT64_C(   81.02),
                         SIMDE_FLOAT64_C( -389.17), SIMDE_FLOAT64_C( -925.92)),
      { SIMDE_FLOAT64_C( -925.92), SIMDE_FLOAT64_C( -389.17) },
      { SIMDE_FLOAT64_C(   81.02), SIMDE_FLOAT64_C(  223.39) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -179.05), SIMDE_FLOAT64_C( -523.56),
                         SIMDE_FLOAT64_C( -888.14), SIMDE_FLOAT64_C( -890.71)),
      { SIMDE_FLOAT64_C( -890.71), SIMDE_FLOAT64_C( -888.14) },
      { SIMDE_FLOAT64_C( -523.56), SIMDE_FLOAT64_C( -179.05) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  495.30), SIMDE_FLOAT64_C(  776.16),
                         SIMDE_FLOAT64_C(  945.09), SIMDE_FLOAT64_C( -993.27)),
      { SIMDE_FLOAT64_C( -993.27), SIMDE_FLOAT64_C(  945.09) },
      { SIMDE_FLOAT64_C(  776.16), SIMDE_FLOAT64_C(  495.30) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -570.57), SIMDE_FLOAT64_C(  -54.05),
                         SIMDE_FLOAT64_C(   18.98), SIMDE_FLOAT64_C(  273.66)),
      { SIMDE_FLOAT64_C(  273.66), SIMDE_FLOAT64_C(   18.98) },
      { SIMDE_FLOAT64_C(  -54.05), SIMDE_FLOAT64_C( -570.57) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64 lo[2];
    simde_float64 hi[2];
    simde_mm256_storeu2_m128d(hi, lo, test_vec[i].a);
    simde_assert_m128d_f64_equal(lo, test_vec[i].lo, 1);
    simde_assert_m128d_f64_equal(hi, test_vec[i].hi, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_storeu2_m128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde_float32 lo[4];
    simde_float32 hi[4];
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  443.79), SIMDE_FLOAT32_C( -943.66),
                         SIMDE_FLOAT32_C( -617.03), SIMDE_FLOAT32_C(  623.90),
                         SIMDE_FLOAT32_C(  762.13), SIMDE_FLOAT32_C( -191.81),
                         SIMDE_FLOAT32_C( -640.60), SIMDE_FLOAT32_C( -234.64)),
      { SIMDE_FLOAT32_C( -234.64), SIMDE_FLOAT32_C( -640.60),
        SIMDE_FLOAT32_C( -191.81), SIMDE_FLOAT32_C(  762.13) },
      { SIMDE_FLOAT32_C(  623.90), SIMDE_FLOAT32_C( -617.03),
        SIMDE_FLOAT32_C( -943.66), SIMDE_FLOAT32_C(  443.79) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  182.89), SIMDE_FLOAT32_C(  873.05),
                         SIMDE_FLOAT32_C( -272.49), SIMDE_FLOAT32_C(  736.89),
                         SIMDE_FLOAT32_C(  847.09), SIMDE_FLOAT32_C( -558.86),
                         SIMDE_FLOAT32_C(  408.24), SIMDE_FLOAT32_C(  859.69)),
      { SIMDE_FLOAT32_C(  859.69), SIMDE_FLOAT32_C(  408.24),
        SIMDE_FLOAT32_C( -558.86), SIMDE_FLOAT32_C(  847.09) },
      { SIMDE_FLOAT32_C(  736.89), SIMDE_FLOAT32_C( -272.49),
        SIMDE_FLOAT32_C(  873.05), SIMDE_FLOAT32_C(  182.89) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -136.90), SIMDE_FLOAT32_C(  907.77),
                         SIMDE_FLOAT32_C(  406.39), SIMDE_FLOAT32_C( -278.95),
                         SIMDE_FLOAT32_C( -644.43), SIMDE_FLOAT32_C( -382.39),
                         SIMDE_FLOAT32_C( -628.10), SIMDE_FLOAT32_C(  477.81)),
      { SIMDE_FLOAT32_C(  477.81), SIMDE_FLOAT32_C( -628.10),
        SIMDE_FLOAT32_C( -382.39), SIMDE_FLOAT32_C( -644.43) },
      { SIMDE_FLOAT32_C( -278.95), SIMDE_FLOAT32_C(  406.39),
        SIMDE_FLOAT32_C(  907.77), SIMDE_FLOAT32_C( -136.90) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -403.18), SIMDE_FLOAT32_C( -297.11),
                         SIMDE_FLOAT32_C( -839.59), SIMDE_FLOAT32_C(  925.44),
                         SIMDE_FLOAT32_C(   -4.12), SIMDE_FLOAT32_C(  223.77),
                         SIMDE_FLOAT32_C(  124.27), SIMDE_FLOAT32_C( -589.05)),
      { SIMDE_FLOAT32_C( -589.05), SIMDE_FLOAT32_C(  124.27),
        SIMDE_FLOAT32_C(  223.77), SIMDE_FLOAT32_C(   -4.12) },
      { SIMDE_FLOAT32_C(  925.44), SIMDE_FLOAT32_C( -839.59),
        SIMDE_FLOAT32_C( -297.11), SIMDE_FLOAT32_C( -403.18) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  375.51), SIMDE_FLOAT32_C(  712.93),
                         SIMDE_FLOAT32_C(  259.42), SIMDE_FLOAT32_C(  -11.11),
                         SIMDE_FLOAT32_C( -941.70), SIMDE_FLOAT32_C(  747.97),
                         SIMDE_FLOAT32_C( -604.59), SIMDE_FLOAT32_C(  959.68)),
      { SIMDE_FLOAT32_C(  959.68), SIMDE_FLOAT32_C( -604.59),
        SIMDE_FLOAT32_C(  747.97), SIMDE_FLOAT32_C( -941.70) },
      { SIMDE_FLOAT32_C(  -11.11), SIMDE_FLOAT32_C(  259.42),
        SIMDE_FLOAT32_C(  712.93), SIMDE_FLOAT32_C(  375.51) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  836.60), SIMDE_FLOAT32_C(  294.15),
                         SIMDE_FLOAT32_C( -609.69), SIMDE_FLOAT32_C( -302.95),
                         SIMDE_FLOAT32_C(   53.57), SIMDE_FLOAT32_C(  -19.22),
                         SIMDE_FLOAT32_C( -957.62), SIMDE_FLOAT32_C(  661.17)),
      { SIMDE_FLOAT32_C(  661.17), SIMDE_FLOAT32_C( -957.62),
        SIMDE_FLOAT32_C(  -19.22), SIMDE_FLOAT32_C(   53.57) },
      { SIMDE_FLOAT32_C( -302.95), SIMDE_FLOAT32_C( -609.69),
        SIMDE_FLOAT32_C(  294.15), SIMDE_FLOAT32_C(  836.60) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -436.80), SIMDE_FLOAT32_C( -424.39),
                         SIMDE_FLOAT32_C(  570.24), SIMDE_FLOAT32_C( -821.65),
                         SIMDE_FLOAT32_C( -881.33), SIMDE_FLOAT32_C( -593.81),
                         SIMDE_FLOAT32_C( -486.59), SIMDE_FLOAT32_C(  962.05)),
      { SIMDE_FLOAT32_C(  962.05), SIMDE_FLOAT32_C( -486.59),
        SIMDE_FLOAT32_C( -593.81), SIMDE_FLOAT32_C( -881.33) },
      { SIMDE_FLOAT32_C( -821.65), SIMDE_FLOAT32_C(  570.24),
        SIMDE_FLOAT32_C( -424.39), SIMDE_FLOAT32_C( -436.80) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -876.51), SIMDE_FLOAT32_C(  339.14),
                         SIMDE_FLOAT32_C(  805.13), SIMDE_FLOAT32_C(  -98.57),
                         SIMDE_FLOAT32_C(  486.75), SIMDE_FLOAT32_C( -826.76),
                         SIMDE_FLOAT32_C( -802.86), SIMDE_FLOAT32_C(  864.61)),
      { SIMDE_FLOAT32_C(  864.61), SIMDE_FLOAT32_C( -802.86),
        SIMDE_FLOAT32_C( -826.76), SIMDE_FLOAT32_C(  486.75) },
      { SIMDE_FLOAT32_C(  -98.57), SIMDE_FLOAT32_C(  805.13),
        SIMDE_FLOAT32_C(  339.14), SIMDE_FLOAT32_C( -876.51) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32 lo[4];
    simde_float32 hi[4];
    simde_mm256_storeu2_m128(hi, lo, test_vec[i].a);
    simde_assert_m128_f32_equal(lo, test_vec[i].lo, 1);
    simde_assert_m128_f32_equal(hi, test_vec[i].hi, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_storeu2_m128i(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m128i lo;
    simde__m128i hi;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(  393618896), INT32_C(-2001591323), INT32_C(  571243540), INT32_C( -991131551),
                            INT32_C(-1628428871), INT32_C(-1785170070), INT32_C(-1344585991), INT32_C(  394549136)),
      simde_mm_set_epi32(INT32_C(-1628428871), INT32_C(-1785170070), INT32_C(-1344585991), INT32_C(  394549136)),
      simde_mm_set_epi32(INT32_C(  393618896), INT32_C(-2001591323), INT32_C(  571243540), INT32_C( -991131551)) },
    { simde_mm256_set_epi32(INT32_C(-1934140687), INT32_C(-1810421284), INT32_C( 1425686798), INT32_C( -866335309),
                            INT32_C(  -95249521), INT32_C( 1994067869), INT32_C( -221558182), INT32_C(-1252244061)),
      simde_mm_set_epi32(INT32_C(  -95249521), INT32_C( 1994067869), INT32_C( -221558182), INT32_C(-1252244061)),
      simde_mm_set_epi32(INT32_C(-1934140687), INT32_C(-1810421284), INT32_C( 1425686798), INT32_C( -866335309)) },
    { simde_mm256_set_epi32(INT32_C( -246697484), INT32_C(-1956819884), INT32_C(-1699719942), INT32_C( -979363348),
                            INT32_C( -887855577), INT32_C(-1489598373), INT32_C(  -35728240), INT32_C(-1964323946)),
      simde_mm_set_epi32(INT32_C( -887855577), INT32_C(-1489598373), INT32_C(  -35728240), INT32_C(-1964323946)),
      simde_mm_set_epi32(INT32_C( -246697484), INT32_C(-1956819884), INT32_C(-1699719942), INT32_C( -979363348)) },
    { simde_mm256_set_epi32(INT32_C( 1386381884), INT32_C(   37784267), INT32_C(-1684378143), INT32_C( -594239665),
                            INT32_C( 1400213774), INT32_C( -622529784), INT32_C(  401959227), INT32_C(  971273192)),
      simde_mm_set_epi32(INT32_C( 1400213774), INT32_C( -622529784), INT32_C(  401959227), INT32_C(  971273192)),
      simde_mm_set_epi32(INT32_C( 1386381884), INT32_C(   37784267), INT32_C(-1684378143), INT32_C( -594239665)) },
    { simde_mm256_set_epi32(INT32_C(-1612998305), INT32_C( 1288430921), INT32_C(-1609225142), INT32_C( -537331182),
                            INT32_C(-1310393347), INT32_C(-1547450104), INT32_C( 1731121387), INT32_C( 1158176208)),
      simde_mm_set_epi32(INT32_C(-1310393347), INT32_C(-1547450104), INT32_C( 1731121387), INT32_C( 1158176208)),
      simde_mm_set_epi32(INT32_C(-1612998305), INT32_C( 1288430921), INT32_C(-1609225142), INT32_C( -537331182)) },
    { simde_mm256_set_epi32(INT32_C(  853720407), INT32_C( 1963572434), INT32_C(-1461958617), INT32_C(    -948574),
                            INT32_C(  440127588), INT32_C( -575649939), INT32_C( -647922801), INT32_C( 1292269475)),
      simde_mm_set_epi32(INT32_C(  440127588), INT32_C( -575649939), INT32_C( -647922801), INT32_C( 1292269475)),
      simde_mm_set_epi32(INT32_C(  853720407), INT32_C( 1963572434), INT32_C(-1461958617), INT32_C(    -948574)) },
    { simde_mm256_set_epi32(INT32_C( 1035304658), INT32_C(-1477195307), INT32_C( 1255581892), INT32_C( -187826179),
                            INT32_C( -553614821), INT32_C(-1529210253), INT32_C(  524369675), INT32_C(-1409815299)),
      simde_mm_set_epi32(INT32_C( -553614821), INT32_C(-1529210253), INT32_C(  524369675), INT32_C(-1409815299)),
      simde_mm_set_epi32(INT32_C( 1035304658), INT32_C(-1477195307), INT32_C( 1255581892), INT32_C( -187826179)) },
    { simde_mm256_set_epi32(INT32_C(-1147733206), INT32_C(-1982126005), INT32_C( 1233979928), INT32_C(-1413154458),
                            INT32_C(   36276938), INT32_C(  -66222229), INT32_C(-1746900300), INT32_C(  533326126)),
      simde_mm_set_epi32(INT32_C(   36276938), INT32_C(  -66222229), INT32_C(-1746900300), INT32_C(  533326126)),
      simde_mm_set_epi32(INT32_C(-1147733206), INT32_C(-1982126005), INT32_C( 1233979928), INT32_C(-1413154458)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i lo, hi;
    simde_mm256_storeu2_m128i(&hi, &lo, test_vec[i].a);
    simde_assert_m128i_i32(lo, ==, test_vec[i].lo);
    simde_assert_m128i_i32(hi, ==, test_vec[i].hi);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_stream_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    SIMDE_ALIGN(32) simde_float32 r[8];
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  256.09), SIMDE_FLOAT32_C(  768.79),
                         SIMDE_FLOAT32_C(  201.90), SIMDE_FLOAT32_C(  339.33),
                         SIMDE_FLOAT32_C(  957.46), SIMDE_FLOAT32_C(  728.44),
                         SIMDE_FLOAT32_C(   73.67), SIMDE_FLOAT32_C(  440.11)),
      { SIMDE_FLOAT32_C(  440.11), SIMDE_FLOAT32_C(   73.67),
        SIMDE_FLOAT32_C(  728.44), SIMDE_FLOAT32_C(  957.46),
        SIMDE_FLOAT32_C(  339.33), SIMDE_FLOAT32_C(  201.90),
        SIMDE_FLOAT32_C(  768.79), SIMDE_FLOAT32_C(  256.09) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -72.04), SIMDE_FLOAT32_C( -425.25),
                         SIMDE_FLOAT32_C(  471.77), SIMDE_FLOAT32_C(  976.75),
                         SIMDE_FLOAT32_C( -510.20), SIMDE_FLOAT32_C(  696.54),
                         SIMDE_FLOAT32_C( -843.54), SIMDE_FLOAT32_C( -868.41)),
      { SIMDE_FLOAT32_C( -868.41), SIMDE_FLOAT32_C( -843.54),
        SIMDE_FLOAT32_C(  696.54), SIMDE_FLOAT32_C( -510.20),
        SIMDE_FLOAT32_C(  976.75), SIMDE_FLOAT32_C(  471.77),
        SIMDE_FLOAT32_C( -425.25), SIMDE_FLOAT32_C(  -72.04) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -304.23), SIMDE_FLOAT32_C(  477.48),
                         SIMDE_FLOAT32_C(  356.58), SIMDE_FLOAT32_C(  955.81),
                         SIMDE_FLOAT32_C(  999.99), SIMDE_FLOAT32_C(  487.33),
                         SIMDE_FLOAT32_C(  633.61), SIMDE_FLOAT32_C(  518.11)),
      { SIMDE_FLOAT32_C(  518.11), SIMDE_FLOAT32_C(  633.61),
        SIMDE_FLOAT32_C(  487.33), SIMDE_FLOAT32_C(  999.99),
        SIMDE_FLOAT32_C(  955.81), SIMDE_FLOAT32_C(  356.58),
        SIMDE_FLOAT32_C(  477.48), SIMDE_FLOAT32_C( -304.23) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   88.04), SIMDE_FLOAT32_C( -296.25),
                         SIMDE_FLOAT32_C(  948.33), SIMDE_FLOAT32_C( -584.17),
                         SIMDE_FLOAT32_C( -796.11), SIMDE_FLOAT32_C(  -38.84),
                         SIMDE_FLOAT32_C( -706.11), SIMDE_FLOAT32_C(  347.32)),
      { SIMDE_FLOAT32_C(  347.32), SIMDE_FLOAT32_C( -706.11),
        SIMDE_FLOAT32_C(  -38.84), SIMDE_FLOAT32_C( -796.11),
        SIMDE_FLOAT32_C( -584.17), SIMDE_FLOAT32_C(  948.33),
        SIMDE_FLOAT32_C( -296.25), SIMDE_FLOAT32_C(   88.04) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -143.76), SIMDE_FLOAT32_C(  504.36),
                         SIMDE_FLOAT32_C( -154.12), SIMDE_FLOAT32_C(  375.43),
                         SIMDE_FLOAT32_C( -307.18), SIMDE_FLOAT32_C(  256.93),
                         SIMDE_FLOAT32_C(   78.86), SIMDE_FLOAT32_C(  526.77)),
      { SIMDE_FLOAT32_C(  526.77), SIMDE_FLOAT32_C(   78.86),
        SIMDE_FLOAT32_C(  256.93), SIMDE_FLOAT32_C( -307.18),
        SIMDE_FLOAT32_C(  375.43), SIMDE_FLOAT32_C( -154.12),
        SIMDE_FLOAT32_C(  504.36), SIMDE_FLOAT32_C( -143.76) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  597.82), SIMDE_FLOAT32_C(  697.68),
                         SIMDE_FLOAT32_C( -285.13), SIMDE_FLOAT32_C(  354.51),
                         SIMDE_FLOAT32_C(   41.32), SIMDE_FLOAT32_C( -445.78),
                         SIMDE_FLOAT32_C( -483.17), SIMDE_FLOAT32_C( -727.28)),
      { SIMDE_FLOAT32_C( -727.28), SIMDE_FLOAT32_C( -483.17),
        SIMDE_FLOAT32_C( -445.78), SIMDE_FLOAT32_C(   41.32),
        SIMDE_FLOAT32_C(  354.51), SIMDE_FLOAT32_C( -285.13),
        SIMDE_FLOAT32_C(  697.68), SIMDE_FLOAT32_C(  597.82) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -441.93), SIMDE_FLOAT32_C( -382.04),
                         SIMDE_FLOAT32_C(  392.67), SIMDE_FLOAT32_C(  690.10),
                         SIMDE_FLOAT32_C(  -30.26), SIMDE_FLOAT32_C( -968.87),
                         SIMDE_FLOAT32_C( -246.46), SIMDE_FLOAT32_C(  625.73)),
      { SIMDE_FLOAT32_C(  625.73), SIMDE_FLOAT32_C( -246.46),
        SIMDE_FLOAT32_C( -968.87), SIMDE_FLOAT32_C(  -30.26),
        SIMDE_FLOAT32_C(  690.10), SIMDE_FLOAT32_C(  392.67),
        SIMDE_FLOAT32_C( -382.04), SIMDE_FLOAT32_C( -441.93) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  442.97), SIMDE_FLOAT32_C(  -20.37),
                         SIMDE_FLOAT32_C(  758.01), SIMDE_FLOAT32_C( -507.47),
                         SIMDE_FLOAT32_C(  529.68), SIMDE_FLOAT32_C( -598.71),
                         SIMDE_FLOAT32_C(  952.31), SIMDE_FLOAT32_C( -565.36)),
      { SIMDE_FLOAT32_C( -565.36), SIMDE_FLOAT32_C(  952.31),
        SIMDE_FLOAT32_C( -598.71), SIMDE_FLOAT32_C(  529.68),
        SIMDE_FLOAT32_C( -507.47), SIMDE_FLOAT32_C(  758.01),
        SIMDE_FLOAT32_C(  -20.37), SIMDE_FLOAT32_C(  442.97) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    SIMDE_ALIGN(32) simde_float32 r[8];
    simde_mm256_stream_ps(r, test_vec[i].a);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_stream_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    SIMDE_ALIGN(32) simde_float64 r[8];
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  771.84), SIMDE_FLOAT64_C(  578.19),
                         SIMDE_FLOAT64_C(  287.63), SIMDE_FLOAT64_C(  196.16)),
      { SIMDE_FLOAT64_C(  196.16), SIMDE_FLOAT64_C(  287.63),
        SIMDE_FLOAT64_C(  578.19), SIMDE_FLOAT64_C(  771.84) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -941.73), SIMDE_FLOAT64_C( -687.45),
                         SIMDE_FLOAT64_C( -865.09), SIMDE_FLOAT64_C(  586.03)),
      { SIMDE_FLOAT64_C(  586.03), SIMDE_FLOAT64_C( -865.09),
        SIMDE_FLOAT64_C( -687.45), SIMDE_FLOAT64_C( -941.73) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -342.90), SIMDE_FLOAT64_C( -658.61),
                         SIMDE_FLOAT64_C(  882.05), SIMDE_FLOAT64_C( -607.89)),
      { SIMDE_FLOAT64_C( -607.89), SIMDE_FLOAT64_C(  882.05),
        SIMDE_FLOAT64_C( -658.61), SIMDE_FLOAT64_C( -342.90) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -248.91), SIMDE_FLOAT64_C( -473.20),
                         SIMDE_FLOAT64_C(  170.76), SIMDE_FLOAT64_C( -407.02)),
      { SIMDE_FLOAT64_C( -407.02), SIMDE_FLOAT64_C(  170.76),
        SIMDE_FLOAT64_C( -473.20), SIMDE_FLOAT64_C( -248.91) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  181.69), SIMDE_FLOAT64_C(  697.67),
                         SIMDE_FLOAT64_C(  911.25), SIMDE_FLOAT64_C( -299.04)),
      { SIMDE_FLOAT64_C( -299.04), SIMDE_FLOAT64_C(  911.25),
        SIMDE_FLOAT64_C(  697.67), SIMDE_FLOAT64_C(  181.69) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -630.92), SIMDE_FLOAT64_C( -612.42),
                         SIMDE_FLOAT64_C(  645.34), SIMDE_FLOAT64_C( -379.90)),
      { SIMDE_FLOAT64_C( -379.90), SIMDE_FLOAT64_C(  645.34),
        SIMDE_FLOAT64_C( -612.42), SIMDE_FLOAT64_C( -630.92) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -339.32), SIMDE_FLOAT64_C(  404.98),
                         SIMDE_FLOAT64_C( -361.76), SIMDE_FLOAT64_C(  391.60)),
      { SIMDE_FLOAT64_C(  391.60), SIMDE_FLOAT64_C( -361.76),
        SIMDE_FLOAT64_C(  404.98), SIMDE_FLOAT64_C( -339.32) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  714.72), SIMDE_FLOAT64_C(  997.58),
                         SIMDE_FLOAT64_C(  807.47), SIMDE_FLOAT64_C(  948.80)),
      { SIMDE_FLOAT64_C(  948.80), SIMDE_FLOAT64_C(  807.47),
        SIMDE_FLOAT64_C(  997.58), SIMDE_FLOAT64_C(  714.72) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    SIMDE_ALIGN(32) simde_float64 r[8];
    simde_mm256_stream_pd(r, test_vec[i].a);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_stream_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( -495387953), INT32_C( 1389422093), INT32_C( 1549613541), INT32_C( 1621396930),
                            INT32_C(  431885981), INT32_C( -495493978), INT32_C(  957980176), INT32_C( -756622382)),
      simde_mm256_set_epi32(INT32_C( -495387953), INT32_C( 1389422093), INT32_C( 1549613541), INT32_C( 1621396930),
                            INT32_C(  431885981), INT32_C( -495493978), INT32_C(  957980176), INT32_C( -756622382)) },
    { simde_mm256_set_epi32(INT32_C(-1537563225), INT32_C( -111752931), INT32_C( 2068479386), INT32_C( 2004807479),
                            INT32_C( 2110162316), INT32_C( 1854708769), INT32_C(  -83811592), INT32_C( -892599604)),
      simde_mm256_set_epi32(INT32_C(-1537563225), INT32_C( -111752931), INT32_C( 2068479386), INT32_C( 2004807479),
                            INT32_C( 2110162316), INT32_C( 1854708769), INT32_C(  -83811592), INT32_C( -892599604)) },
    { simde_mm256_set_epi32(INT32_C( 1682126570), INT32_C(  340006289), INT32_C(  149083722), INT32_C( 1734045351),
                            INT32_C(-1572830580), INT32_C( 1824421914), INT32_C( 1423738129), INT32_C( -492096848)),
      simde_mm256_set_epi32(INT32_C( 1682126570), INT32_C(  340006289), INT32_C(  149083722), INT32_C( 1734045351),
                            INT32_C(-1572830580), INT32_C( 1824421914), INT32_C( 1423738129), INT32_C( -492096848)) },
    { simde_mm256_set_epi32(INT32_C(-2079347795), INT32_C( -336455233), INT32_C( -761216501), INT32_C( 1784601451),
                            INT32_C(  386854500), INT32_C(  177253765), INT32_C(  797476379), INT32_C( -848434210)),
      simde_mm256_set_epi32(INT32_C(-2079347795), INT32_C( -336455233), INT32_C( -761216501), INT32_C( 1784601451),
                            INT32_C(  386854500), INT32_C(  177253765), INT32_C(  797476379), INT32_C( -848434210)) },
    { simde_mm256_set_epi32(INT32_C(-1024397654), INT32_C(  273228891), INT32_C( -327343542), INT32_C(  941152347),
                            INT32_C(-1943801853), INT32_C( -571606335), INT32_C(-1600503753), INT32_C(    3657489)),
      simde_mm256_set_epi32(INT32_C(-1024397654), INT32_C(  273228891), INT32_C( -327343542), INT32_C(  941152347),
                            INT32_C(-1943801853), INT32_C( -571606335), INT32_C(-1600503753), INT32_C(    3657489)) },
    { simde_mm256_set_epi32(INT32_C(  392666418), INT32_C(-1141495552), INT32_C(-1265226558), INT32_C( -341769681),
                            INT32_C(  784056885), INT32_C(   -8791049), INT32_C( -255179514), INT32_C( 1505512077)),
      simde_mm256_set_epi32(INT32_C(  392666418), INT32_C(-1141495552), INT32_C(-1265226558), INT32_C( -341769681),
                            INT32_C(  784056885), INT32_C(   -8791049), INT32_C( -255179514), INT32_C( 1505512077)) },
    { simde_mm256_set_epi32(INT32_C(-2051731929), INT32_C( 1367430487), INT32_C( -142986568), INT32_C( 1381573702),
                            INT32_C( -856833247), INT32_C(  665026143), INT32_C( 1196790497), INT32_C( -507260176)),
      simde_mm256_set_epi32(INT32_C(-2051731929), INT32_C( 1367430487), INT32_C( -142986568), INT32_C( 1381573702),
                            INT32_C( -856833247), INT32_C(  665026143), INT32_C( 1196790497), INT32_C( -507260176)) },
    { simde_mm256_set_epi32(INT32_C( -878005657), INT32_C( -546637276), INT32_C(-1056155816), INT32_C(  259320365),
                            INT32_C(-1537222115), INT32_C(  895058753), INT32_C( -970999316), INT32_C(  224281618)),
      simde_mm256_set_epi32(INT32_C( -878005657), INT32_C( -546637276), INT32_C(-1056155816), INT32_C(  259320365),
                            INT32_C(-1537222115), INT32_C(  895058753), INT32_C( -970999316), INT32_C(  224281618)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r;
    simde_mm256_stream_si256(&r, test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_sub_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  895.54), SIMDE_FLOAT32_C( -418.39),
                         SIMDE_FLOAT32_C( -695.61), SIMDE_FLOAT32_C( -703.30),
                         SIMDE_FLOAT32_C( -607.73), SIMDE_FLOAT32_C(  485.65),
                         SIMDE_FLOAT32_C(  755.18), SIMDE_FLOAT32_C(   41.77)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -396.67), SIMDE_FLOAT32_C( -773.83),
                         SIMDE_FLOAT32_C( -672.24), SIMDE_FLOAT32_C(  931.02),
                         SIMDE_FLOAT32_C( -562.65), SIMDE_FLOAT32_C( -945.51),
                         SIMDE_FLOAT32_C(  938.88), SIMDE_FLOAT32_C(  508.62)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 1292.21), SIMDE_FLOAT32_C(  355.44),
                         SIMDE_FLOAT32_C(  -23.37), SIMDE_FLOAT32_C(-1634.32),
                         SIMDE_FLOAT32_C(  -45.08), SIMDE_FLOAT32_C( 1431.16),
                         SIMDE_FLOAT32_C( -183.70), SIMDE_FLOAT32_C( -466.85)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -470.99), SIMDE_FLOAT32_C( -584.82),
                         SIMDE_FLOAT32_C(  594.88), SIMDE_FLOAT32_C( -970.99),
                         SIMDE_FLOAT32_C(  -61.62), SIMDE_FLOAT32_C(    8.56),
                         SIMDE_FLOAT32_C( -149.02), SIMDE_FLOAT32_C(  992.11)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -290.52), SIMDE_FLOAT32_C(  724.83),
                         SIMDE_FLOAT32_C(  -46.66), SIMDE_FLOAT32_C( -959.87),
                         SIMDE_FLOAT32_C( -350.83), SIMDE_FLOAT32_C( -742.59),
                         SIMDE_FLOAT32_C( -154.10), SIMDE_FLOAT32_C(  297.07)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -180.47), SIMDE_FLOAT32_C(-1309.65),
                         SIMDE_FLOAT32_C(  641.54), SIMDE_FLOAT32_C(  -11.12),
                         SIMDE_FLOAT32_C(  289.21), SIMDE_FLOAT32_C(  751.15),
                         SIMDE_FLOAT32_C(    5.08), SIMDE_FLOAT32_C(  695.04)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -970.60), SIMDE_FLOAT32_C(  -80.01),
                         SIMDE_FLOAT32_C(  -52.72), SIMDE_FLOAT32_C(  126.54),
                         SIMDE_FLOAT32_C( -671.14), SIMDE_FLOAT32_C( -767.97),
                         SIMDE_FLOAT32_C( -218.43), SIMDE_FLOAT32_C(  532.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  605.24), SIMDE_FLOAT32_C(  -39.09),
                         SIMDE_FLOAT32_C(  863.80), SIMDE_FLOAT32_C( -150.76),
                         SIMDE_FLOAT32_C( -836.71), SIMDE_FLOAT32_C(  584.17),
                         SIMDE_FLOAT32_C(  207.01), SIMDE_FLOAT32_C(  321.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-1575.84), SIMDE_FLOAT32_C(  -40.92),
                         SIMDE_FLOAT32_C( -916.52), SIMDE_FLOAT32_C(  277.30),
                         SIMDE_FLOAT32_C(  165.57), SIMDE_FLOAT32_C(-1352.14),
                         SIMDE_FLOAT32_C( -425.44), SIMDE_FLOAT32_C(  210.68)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  342.27), SIMDE_FLOAT32_C( -662.10),
                         SIMDE_FLOAT32_C( -934.33), SIMDE_FLOAT32_C( -742.68),
                         SIMDE_FLOAT32_C( -973.49), SIMDE_FLOAT32_C(   11.46),
                         SIMDE_FLOAT32_C(  125.25), SIMDE_FLOAT32_C( -964.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  604.39), SIMDE_FLOAT32_C(  789.04),
                         SIMDE_FLOAT32_C( -177.72), SIMDE_FLOAT32_C(  -86.37),
                         SIMDE_FLOAT32_C( -125.89), SIMDE_FLOAT32_C(  264.15),
                         SIMDE_FLOAT32_C(  690.78), SIMDE_FLOAT32_C(  529.89)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -262.12), SIMDE_FLOAT32_C(-1451.14),
                         SIMDE_FLOAT32_C( -756.61), SIMDE_FLOAT32_C( -656.31),
                         SIMDE_FLOAT32_C( -847.60), SIMDE_FLOAT32_C( -252.69),
                         SIMDE_FLOAT32_C( -565.53), SIMDE_FLOAT32_C(-1494.25)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   25.31), SIMDE_FLOAT32_C(  539.95),
                         SIMDE_FLOAT32_C(  423.13), SIMDE_FLOAT32_C(  781.76),
                         SIMDE_FLOAT32_C(  417.34), SIMDE_FLOAT32_C(  842.38),
                         SIMDE_FLOAT32_C( -253.59), SIMDE_FLOAT32_C( -916.97)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  772.83), SIMDE_FLOAT32_C(  517.22),
                         SIMDE_FLOAT32_C(  908.12), SIMDE_FLOAT32_C( -320.25),
                         SIMDE_FLOAT32_C(  304.42), SIMDE_FLOAT32_C( -692.34),
                         SIMDE_FLOAT32_C( -714.07), SIMDE_FLOAT32_C( -793.24)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -747.52), SIMDE_FLOAT32_C(   22.73),
                         SIMDE_FLOAT32_C( -484.99), SIMDE_FLOAT32_C( 1102.01),
                         SIMDE_FLOAT32_C(  112.92), SIMDE_FLOAT32_C( 1534.72),
                         SIMDE_FLOAT32_C(  460.48), SIMDE_FLOAT32_C( -123.73)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  393.40), SIMDE_FLOAT32_C( -394.71),
                         SIMDE_FLOAT32_C(  -86.25), SIMDE_FLOAT32_C(  978.22),
                         SIMDE_FLOAT32_C(  983.88), SIMDE_FLOAT32_C(  704.75),
                         SIMDE_FLOAT32_C(  982.77), SIMDE_FLOAT32_C(  368.33)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -436.22), SIMDE_FLOAT32_C( -898.24),
                         SIMDE_FLOAT32_C( -332.96), SIMDE_FLOAT32_C(  552.30),
                         SIMDE_FLOAT32_C(  889.88), SIMDE_FLOAT32_C( -709.13),
                         SIMDE_FLOAT32_C( -308.74), SIMDE_FLOAT32_C(  240.99)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  829.62), SIMDE_FLOAT32_C(  503.53),
                         SIMDE_FLOAT32_C(  246.71), SIMDE_FLOAT32_C(  425.92),
                         SIMDE_FLOAT32_C(   94.00), SIMDE_FLOAT32_C( 1413.88),
                         SIMDE_FLOAT32_C( 1291.51), SIMDE_FLOAT32_C(  127.34)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  338.33), SIMDE_FLOAT32_C(  742.66),
                         SIMDE_FLOAT32_C( -662.36), SIMDE_FLOAT32_C(  193.25),
                         SIMDE_FLOAT32_C( -791.36), SIMDE_FLOAT32_C(  864.59),
                         SIMDE_FLOAT32_C( -234.67), SIMDE_FLOAT32_C( -697.85)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -154.56), SIMDE_FLOAT32_C(  577.30),
                         SIMDE_FLOAT32_C(  801.65), SIMDE_FLOAT32_C(  520.59),
                         SIMDE_FLOAT32_C( -742.87), SIMDE_FLOAT32_C( -868.99),
                         SIMDE_FLOAT32_C(   16.41), SIMDE_FLOAT32_C(  377.46)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  492.89), SIMDE_FLOAT32_C(  165.36),
                         SIMDE_FLOAT32_C(-1464.01), SIMDE_FLOAT32_C( -327.34),
                         SIMDE_FLOAT32_C(  -48.49), SIMDE_FLOAT32_C( 1733.58),
                         SIMDE_FLOAT32_C( -251.08), SIMDE_FLOAT32_C(-1075.31)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  301.89), SIMDE_FLOAT32_C(  110.31),
                         SIMDE_FLOAT32_C( -669.00), SIMDE_FLOAT32_C( -603.43),
                         SIMDE_FLOAT32_C(  552.74), SIMDE_FLOAT32_C(  111.39),
                         SIMDE_FLOAT32_C(  485.92), SIMDE_FLOAT32_C(   89.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  222.86), SIMDE_FLOAT32_C(  451.25),
                         SIMDE_FLOAT32_C(  422.47), SIMDE_FLOAT32_C( -182.63),
                         SIMDE_FLOAT32_C( -845.87), SIMDE_FLOAT32_C( -863.72),
                         SIMDE_FLOAT32_C( -400.45), SIMDE_FLOAT32_C(  543.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   79.03), SIMDE_FLOAT32_C( -340.94),
                         SIMDE_FLOAT32_C(-1091.47), SIMDE_FLOAT32_C( -420.80),
                         SIMDE_FLOAT32_C( 1398.61), SIMDE_FLOAT32_C(  975.11),
                         SIMDE_FLOAT32_C(  886.37), SIMDE_FLOAT32_C( -454.56)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_sub_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_sub_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -472.29), SIMDE_FLOAT64_C(  818.19),
                         SIMDE_FLOAT64_C( -310.33), SIMDE_FLOAT64_C( -307.48)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  349.11), SIMDE_FLOAT64_C(  984.47),
                         SIMDE_FLOAT64_C(  184.55), SIMDE_FLOAT64_C(  274.42)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -821.40), SIMDE_FLOAT64_C( -166.28),
                         SIMDE_FLOAT64_C( -494.88), SIMDE_FLOAT64_C( -581.90)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -992.33), SIMDE_FLOAT64_C( -503.60),
                         SIMDE_FLOAT64_C( -575.41), SIMDE_FLOAT64_C(  497.58)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  203.77), SIMDE_FLOAT64_C( -296.83),
                         SIMDE_FLOAT64_C( -970.76), SIMDE_FLOAT64_C(  837.97)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1196.10), SIMDE_FLOAT64_C( -206.77),
                         SIMDE_FLOAT64_C(  395.35), SIMDE_FLOAT64_C( -340.39)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  691.42), SIMDE_FLOAT64_C(  124.38),
                         SIMDE_FLOAT64_C( -117.46), SIMDE_FLOAT64_C(  -44.64)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  865.33), SIMDE_FLOAT64_C( -985.94),
                         SIMDE_FLOAT64_C( -427.40), SIMDE_FLOAT64_C(  247.61)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -173.91), SIMDE_FLOAT64_C( 1110.32),
                         SIMDE_FLOAT64_C(  309.94), SIMDE_FLOAT64_C( -292.25)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -811.54), SIMDE_FLOAT64_C( -682.27),
                         SIMDE_FLOAT64_C( -138.35), SIMDE_FLOAT64_C(  149.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -356.84), SIMDE_FLOAT64_C( -870.72),
                         SIMDE_FLOAT64_C(  278.05), SIMDE_FLOAT64_C(  725.66)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -454.70), SIMDE_FLOAT64_C(  188.45),
                         SIMDE_FLOAT64_C( -416.40), SIMDE_FLOAT64_C( -575.71)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -372.68), SIMDE_FLOAT64_C( -973.76),
                         SIMDE_FLOAT64_C( -655.95), SIMDE_FLOAT64_C(  -13.49)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  132.41), SIMDE_FLOAT64_C( -317.72),
                         SIMDE_FLOAT64_C(  685.31), SIMDE_FLOAT64_C( -205.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -505.09), SIMDE_FLOAT64_C( -656.04),
                         SIMDE_FLOAT64_C(-1341.26), SIMDE_FLOAT64_C(  192.41)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -904.59), SIMDE_FLOAT64_C(  450.57),
                         SIMDE_FLOAT64_C(  462.97), SIMDE_FLOAT64_C( -213.02)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  256.78), SIMDE_FLOAT64_C(  248.73),
                         SIMDE_FLOAT64_C( -329.49), SIMDE_FLOAT64_C(  126.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1161.37), SIMDE_FLOAT64_C(  201.84),
                         SIMDE_FLOAT64_C(  792.46), SIMDE_FLOAT64_C( -339.78)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  425.49), SIMDE_FLOAT64_C( -968.50),
                         SIMDE_FLOAT64_C( -130.01), SIMDE_FLOAT64_C(  908.84)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  529.10), SIMDE_FLOAT64_C(   40.66),
                         SIMDE_FLOAT64_C(  677.87), SIMDE_FLOAT64_C( -349.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -103.61), SIMDE_FLOAT64_C(-1009.16),
                         SIMDE_FLOAT64_C( -807.88), SIMDE_FLOAT64_C( 1258.04)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  385.72), SIMDE_FLOAT64_C(  135.17),
                         SIMDE_FLOAT64_C( -935.76), SIMDE_FLOAT64_C(  307.38)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  799.62), SIMDE_FLOAT64_C(  219.20),
                         SIMDE_FLOAT64_C(  812.15), SIMDE_FLOAT64_C(   33.47)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -413.90), SIMDE_FLOAT64_C(  -84.03),
                         SIMDE_FLOAT64_C(-1747.91), SIMDE_FLOAT64_C(  273.91)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_sub_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_unpackhi_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  807.72), SIMDE_FLOAT32_C(  100.14),
                         SIMDE_FLOAT32_C(  187.05), SIMDE_FLOAT32_C( -298.31),
                         SIMDE_FLOAT32_C(  -34.37), SIMDE_FLOAT32_C(  964.34),
                         SIMDE_FLOAT32_C(  191.73), SIMDE_FLOAT32_C(  188.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -734.87), SIMDE_FLOAT32_C( -828.29),
                         SIMDE_FLOAT32_C( -280.75), SIMDE_FLOAT32_C(  955.06),
                         SIMDE_FLOAT32_C(  436.60), SIMDE_FLOAT32_C( -584.60),
                         SIMDE_FLOAT32_C(  158.18), SIMDE_FLOAT32_C(   60.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -734.87), SIMDE_FLOAT32_C(  807.72),
                         SIMDE_FLOAT32_C( -828.29), SIMDE_FLOAT32_C(  100.14),
                         SIMDE_FLOAT32_C(  436.60), SIMDE_FLOAT32_C(  -34.37),
                         SIMDE_FLOAT32_C( -584.60), SIMDE_FLOAT32_C(  964.34)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -931.86), SIMDE_FLOAT32_C( -611.79),
                         SIMDE_FLOAT32_C( -274.19), SIMDE_FLOAT32_C( -226.15),
                         SIMDE_FLOAT32_C( -145.52), SIMDE_FLOAT32_C(  128.94),
                         SIMDE_FLOAT32_C( -102.01), SIMDE_FLOAT32_C( -500.66)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -438.58), SIMDE_FLOAT32_C( -771.61),
                         SIMDE_FLOAT32_C(  661.02), SIMDE_FLOAT32_C( -824.40),
                         SIMDE_FLOAT32_C(  837.69), SIMDE_FLOAT32_C(   62.03),
                         SIMDE_FLOAT32_C(  350.22), SIMDE_FLOAT32_C(  -94.71)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -438.58), SIMDE_FLOAT32_C( -931.86),
                         SIMDE_FLOAT32_C( -771.61), SIMDE_FLOAT32_C( -611.79),
                         SIMDE_FLOAT32_C(  837.69), SIMDE_FLOAT32_C( -145.52),
                         SIMDE_FLOAT32_C(   62.03), SIMDE_FLOAT32_C(  128.94)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -514.10), SIMDE_FLOAT32_C(  798.26),
                         SIMDE_FLOAT32_C(  453.29), SIMDE_FLOAT32_C( -723.59),
                         SIMDE_FLOAT32_C(  488.64), SIMDE_FLOAT32_C( -551.49),
                         SIMDE_FLOAT32_C( -160.63), SIMDE_FLOAT32_C(   78.66)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  525.47), SIMDE_FLOAT32_C( -613.64),
                         SIMDE_FLOAT32_C(  666.94), SIMDE_FLOAT32_C( -806.63),
                         SIMDE_FLOAT32_C(  409.97), SIMDE_FLOAT32_C(  221.24),
                         SIMDE_FLOAT32_C(  721.07), SIMDE_FLOAT32_C( -434.84)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  525.47), SIMDE_FLOAT32_C( -514.10),
                         SIMDE_FLOAT32_C( -613.64), SIMDE_FLOAT32_C(  798.26),
                         SIMDE_FLOAT32_C(  409.97), SIMDE_FLOAT32_C(  488.64),
                         SIMDE_FLOAT32_C(  221.24), SIMDE_FLOAT32_C( -551.49)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -951.19), SIMDE_FLOAT32_C(  -28.42),
                         SIMDE_FLOAT32_C(  106.10), SIMDE_FLOAT32_C( -926.30),
                         SIMDE_FLOAT32_C( -891.33), SIMDE_FLOAT32_C( -910.68),
                         SIMDE_FLOAT32_C(  859.23), SIMDE_FLOAT32_C( -534.18)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -774.25), SIMDE_FLOAT32_C( -509.69),
                         SIMDE_FLOAT32_C( -863.30), SIMDE_FLOAT32_C( -245.43),
                         SIMDE_FLOAT32_C( -949.52), SIMDE_FLOAT32_C( -135.53),
                         SIMDE_FLOAT32_C(  390.61), SIMDE_FLOAT32_C( -616.91)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -774.25), SIMDE_FLOAT32_C( -951.19),
                         SIMDE_FLOAT32_C( -509.69), SIMDE_FLOAT32_C(  -28.42),
                         SIMDE_FLOAT32_C( -949.52), SIMDE_FLOAT32_C( -891.33),
                         SIMDE_FLOAT32_C( -135.53), SIMDE_FLOAT32_C( -910.68)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  854.52), SIMDE_FLOAT32_C( -781.40),
                         SIMDE_FLOAT32_C(  848.96), SIMDE_FLOAT32_C(  755.16),
                         SIMDE_FLOAT32_C(  991.03), SIMDE_FLOAT32_C( -213.85),
                         SIMDE_FLOAT32_C(  907.55), SIMDE_FLOAT32_C( -711.16)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  456.01), SIMDE_FLOAT32_C( -206.18),
                         SIMDE_FLOAT32_C( -786.69), SIMDE_FLOAT32_C(  940.75),
                         SIMDE_FLOAT32_C( -664.64), SIMDE_FLOAT32_C( -614.97),
                         SIMDE_FLOAT32_C(  524.63), SIMDE_FLOAT32_C(  291.78)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  456.01), SIMDE_FLOAT32_C(  854.52),
                         SIMDE_FLOAT32_C( -206.18), SIMDE_FLOAT32_C( -781.40),
                         SIMDE_FLOAT32_C( -664.64), SIMDE_FLOAT32_C(  991.03),
                         SIMDE_FLOAT32_C( -614.97), SIMDE_FLOAT32_C( -213.85)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -51.56), SIMDE_FLOAT32_C(  716.82),
                         SIMDE_FLOAT32_C(  820.37), SIMDE_FLOAT32_C( -556.55),
                         SIMDE_FLOAT32_C( -748.23), SIMDE_FLOAT32_C( -191.87),
                         SIMDE_FLOAT32_C(  886.02), SIMDE_FLOAT32_C( -964.97)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  942.40), SIMDE_FLOAT32_C( -388.17),
                         SIMDE_FLOAT32_C(  620.64), SIMDE_FLOAT32_C(  768.35),
                         SIMDE_FLOAT32_C( -196.91), SIMDE_FLOAT32_C( -771.49),
                         SIMDE_FLOAT32_C( -618.58), SIMDE_FLOAT32_C( -887.04)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  942.40), SIMDE_FLOAT32_C(  -51.56),
                         SIMDE_FLOAT32_C( -388.17), SIMDE_FLOAT32_C(  716.82),
                         SIMDE_FLOAT32_C( -196.91), SIMDE_FLOAT32_C( -748.23),
                         SIMDE_FLOAT32_C( -771.49), SIMDE_FLOAT32_C( -191.87)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  934.86), SIMDE_FLOAT32_C( -147.82),
                         SIMDE_FLOAT32_C(  984.99), SIMDE_FLOAT32_C(  944.15),
                         SIMDE_FLOAT32_C(  882.67), SIMDE_FLOAT32_C(  370.21),
                         SIMDE_FLOAT32_C(  981.44), SIMDE_FLOAT32_C( -856.37)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   80.89), SIMDE_FLOAT32_C(  -20.18),
                         SIMDE_FLOAT32_C( -561.60), SIMDE_FLOAT32_C(  599.04),
                         SIMDE_FLOAT32_C( -556.62), SIMDE_FLOAT32_C( -514.91),
                         SIMDE_FLOAT32_C( -240.53), SIMDE_FLOAT32_C( -421.29)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   80.89), SIMDE_FLOAT32_C(  934.86),
                         SIMDE_FLOAT32_C(  -20.18), SIMDE_FLOAT32_C( -147.82),
                         SIMDE_FLOAT32_C( -556.62), SIMDE_FLOAT32_C(  882.67),
                         SIMDE_FLOAT32_C( -514.91), SIMDE_FLOAT32_C(  370.21)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -445.93), SIMDE_FLOAT32_C(  998.84),
                         SIMDE_FLOAT32_C( -975.41), SIMDE_FLOAT32_C(  762.47),
                         SIMDE_FLOAT32_C(  829.30), SIMDE_FLOAT32_C( -324.70),
                         SIMDE_FLOAT32_C(  745.09), SIMDE_FLOAT32_C(   12.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  177.17), SIMDE_FLOAT32_C(  871.02),
                         SIMDE_FLOAT32_C(  263.38), SIMDE_FLOAT32_C( -284.12),
                         SIMDE_FLOAT32_C( -407.86), SIMDE_FLOAT32_C( -554.15),
                         SIMDE_FLOAT32_C(   -7.26), SIMDE_FLOAT32_C( -655.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  177.17), SIMDE_FLOAT32_C( -445.93),
                         SIMDE_FLOAT32_C(  871.02), SIMDE_FLOAT32_C(  998.84),
                         SIMDE_FLOAT32_C( -407.86), SIMDE_FLOAT32_C(  829.30),
                         SIMDE_FLOAT32_C( -554.15), SIMDE_FLOAT32_C( -324.70)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_unpackhi_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_unpackhi_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  474.20), SIMDE_FLOAT64_C(  -84.92),
                         SIMDE_FLOAT64_C(  521.98), SIMDE_FLOAT64_C( -506.09)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  547.06), SIMDE_FLOAT64_C( -105.08),
                         SIMDE_FLOAT64_C(  810.31), SIMDE_FLOAT64_C(  175.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  547.06), SIMDE_FLOAT64_C(  474.20),
                         SIMDE_FLOAT64_C(  810.31), SIMDE_FLOAT64_C(  521.98)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -738.63), SIMDE_FLOAT64_C( -207.02),
                         SIMDE_FLOAT64_C(  624.23), SIMDE_FLOAT64_C( -787.13)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -734.37), SIMDE_FLOAT64_C(   16.93),
                         SIMDE_FLOAT64_C( -235.12), SIMDE_FLOAT64_C(  261.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -734.37), SIMDE_FLOAT64_C( -738.63),
                         SIMDE_FLOAT64_C( -235.12), SIMDE_FLOAT64_C(  624.23)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  713.19), SIMDE_FLOAT64_C(  906.18),
                         SIMDE_FLOAT64_C( -969.47), SIMDE_FLOAT64_C( -953.69)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  182.58), SIMDE_FLOAT64_C(  575.97),
                         SIMDE_FLOAT64_C(  870.00), SIMDE_FLOAT64_C(  681.86)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  182.58), SIMDE_FLOAT64_C(  713.19),
                         SIMDE_FLOAT64_C(  870.00), SIMDE_FLOAT64_C( -969.47)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -478.99), SIMDE_FLOAT64_C( -198.61),
                         SIMDE_FLOAT64_C( -506.78), SIMDE_FLOAT64_C( -744.29)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -105.58), SIMDE_FLOAT64_C( -594.58),
                         SIMDE_FLOAT64_C( -326.65), SIMDE_FLOAT64_C(  744.36)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -105.58), SIMDE_FLOAT64_C( -478.99),
                         SIMDE_FLOAT64_C( -326.65), SIMDE_FLOAT64_C( -506.78)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  456.60), SIMDE_FLOAT64_C( -346.15),
                         SIMDE_FLOAT64_C(  230.97), SIMDE_FLOAT64_C(  246.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -895.16), SIMDE_FLOAT64_C(  675.27),
                         SIMDE_FLOAT64_C( -175.34), SIMDE_FLOAT64_C( -350.18)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -895.16), SIMDE_FLOAT64_C(  456.60),
                         SIMDE_FLOAT64_C( -175.34), SIMDE_FLOAT64_C(  230.97)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  517.62), SIMDE_FLOAT64_C( -985.29),
                         SIMDE_FLOAT64_C( -720.18), SIMDE_FLOAT64_C(   52.87)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  519.19), SIMDE_FLOAT64_C(  -56.82),
                         SIMDE_FLOAT64_C(  611.63), SIMDE_FLOAT64_C(  463.94)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  519.19), SIMDE_FLOAT64_C(  517.62),
                         SIMDE_FLOAT64_C(  611.63), SIMDE_FLOAT64_C( -720.18)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -839.87), SIMDE_FLOAT64_C(  -23.85),
                         SIMDE_FLOAT64_C(  777.18), SIMDE_FLOAT64_C(  867.39)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -606.42), SIMDE_FLOAT64_C(  503.57),
                         SIMDE_FLOAT64_C(  891.19), SIMDE_FLOAT64_C(  137.98)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -606.42), SIMDE_FLOAT64_C( -839.87),
                         SIMDE_FLOAT64_C(  891.19), SIMDE_FLOAT64_C(  777.18)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -362.78), SIMDE_FLOAT64_C( -942.23),
                         SIMDE_FLOAT64_C(  577.23), SIMDE_FLOAT64_C(  747.66)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -987.53), SIMDE_FLOAT64_C(  145.74),
                         SIMDE_FLOAT64_C(  948.38), SIMDE_FLOAT64_C( -772.85)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -987.53), SIMDE_FLOAT64_C( -362.78),
                         SIMDE_FLOAT64_C(  948.38), SIMDE_FLOAT64_C(  577.23)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_unpackhi_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_unpacklo_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  476.45), SIMDE_FLOAT32_C(  703.11),
                         SIMDE_FLOAT32_C(  221.80), SIMDE_FLOAT32_C( -361.45),
                         SIMDE_FLOAT32_C(  645.73), SIMDE_FLOAT32_C(  420.76),
                         SIMDE_FLOAT32_C(  -23.12), SIMDE_FLOAT32_C(   96.33)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -773.95), SIMDE_FLOAT32_C(  586.39),
                         SIMDE_FLOAT32_C(  118.66), SIMDE_FLOAT32_C(    5.14),
                         SIMDE_FLOAT32_C(    9.63), SIMDE_FLOAT32_C(  896.46),
                         SIMDE_FLOAT32_C(  121.67), SIMDE_FLOAT32_C( -134.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  118.66), SIMDE_FLOAT32_C(  221.80),
                         SIMDE_FLOAT32_C(    5.14), SIMDE_FLOAT32_C( -361.45),
                         SIMDE_FLOAT32_C(  121.67), SIMDE_FLOAT32_C(  -23.12),
                         SIMDE_FLOAT32_C( -134.20), SIMDE_FLOAT32_C(   96.33)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -605.12), SIMDE_FLOAT32_C(  481.83),
                         SIMDE_FLOAT32_C(  757.82), SIMDE_FLOAT32_C( -782.53),
                         SIMDE_FLOAT32_C(  546.60), SIMDE_FLOAT32_C( -405.06),
                         SIMDE_FLOAT32_C( -413.20), SIMDE_FLOAT32_C( -645.12)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -646.85), SIMDE_FLOAT32_C( -619.64),
                         SIMDE_FLOAT32_C(    4.92), SIMDE_FLOAT32_C(  816.93),
                         SIMDE_FLOAT32_C( -509.30), SIMDE_FLOAT32_C(  435.06),
                         SIMDE_FLOAT32_C(  -11.96), SIMDE_FLOAT32_C( -147.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    4.92), SIMDE_FLOAT32_C(  757.82),
                         SIMDE_FLOAT32_C(  816.93), SIMDE_FLOAT32_C( -782.53),
                         SIMDE_FLOAT32_C(  -11.96), SIMDE_FLOAT32_C( -413.20),
                         SIMDE_FLOAT32_C( -147.23), SIMDE_FLOAT32_C( -645.12)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  850.74), SIMDE_FLOAT32_C(  -85.68),
                         SIMDE_FLOAT32_C( -210.45), SIMDE_FLOAT32_C(  -73.45),
                         SIMDE_FLOAT32_C(  532.06), SIMDE_FLOAT32_C(  709.20),
                         SIMDE_FLOAT32_C(  882.78), SIMDE_FLOAT32_C( -768.32)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -922.57), SIMDE_FLOAT32_C(   42.72),
                         SIMDE_FLOAT32_C(  514.25), SIMDE_FLOAT32_C( -144.83),
                         SIMDE_FLOAT32_C(  -74.58), SIMDE_FLOAT32_C( -573.39),
                         SIMDE_FLOAT32_C( -176.90), SIMDE_FLOAT32_C( -171.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  514.25), SIMDE_FLOAT32_C( -210.45),
                         SIMDE_FLOAT32_C( -144.83), SIMDE_FLOAT32_C(  -73.45),
                         SIMDE_FLOAT32_C( -176.90), SIMDE_FLOAT32_C(  882.78),
                         SIMDE_FLOAT32_C( -171.10), SIMDE_FLOAT32_C( -768.32)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -573.82), SIMDE_FLOAT32_C(  486.51),
                         SIMDE_FLOAT32_C(  332.79), SIMDE_FLOAT32_C( -446.48),
                         SIMDE_FLOAT32_C(  110.94), SIMDE_FLOAT32_C(  515.10),
                         SIMDE_FLOAT32_C(  513.81), SIMDE_FLOAT32_C( -806.87)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  206.71), SIMDE_FLOAT32_C( -250.67),
                         SIMDE_FLOAT32_C(  127.20), SIMDE_FLOAT32_C(  -93.11),
                         SIMDE_FLOAT32_C( -774.94), SIMDE_FLOAT32_C( -230.88),
                         SIMDE_FLOAT32_C(  631.35), SIMDE_FLOAT32_C(  231.15)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  127.20), SIMDE_FLOAT32_C(  332.79),
                         SIMDE_FLOAT32_C(  -93.11), SIMDE_FLOAT32_C( -446.48),
                         SIMDE_FLOAT32_C(  631.35), SIMDE_FLOAT32_C(  513.81),
                         SIMDE_FLOAT32_C(  231.15), SIMDE_FLOAT32_C( -806.87)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  149.45), SIMDE_FLOAT32_C(  726.97),
                         SIMDE_FLOAT32_C(  -55.39), SIMDE_FLOAT32_C(  -82.15),
                         SIMDE_FLOAT32_C(  549.77), SIMDE_FLOAT32_C(  954.11),
                         SIMDE_FLOAT32_C(  -93.98), SIMDE_FLOAT32_C( -820.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  456.52), SIMDE_FLOAT32_C( -978.21),
                         SIMDE_FLOAT32_C(  560.56), SIMDE_FLOAT32_C(  178.87),
                         SIMDE_FLOAT32_C(  916.04), SIMDE_FLOAT32_C( -801.57),
                         SIMDE_FLOAT32_C( -369.99), SIMDE_FLOAT32_C(   24.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  560.56), SIMDE_FLOAT32_C(  -55.39),
                         SIMDE_FLOAT32_C(  178.87), SIMDE_FLOAT32_C(  -82.15),
                         SIMDE_FLOAT32_C( -369.99), SIMDE_FLOAT32_C(  -93.98),
                         SIMDE_FLOAT32_C(   24.70), SIMDE_FLOAT32_C( -820.28)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  683.93), SIMDE_FLOAT32_C( -442.40),
                         SIMDE_FLOAT32_C( -321.81), SIMDE_FLOAT32_C(  -47.02),
                         SIMDE_FLOAT32_C( -854.54), SIMDE_FLOAT32_C(  -65.39),
                         SIMDE_FLOAT32_C( -879.02), SIMDE_FLOAT32_C( -144.43)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -204.43), SIMDE_FLOAT32_C(  186.43),
                         SIMDE_FLOAT32_C( -537.46), SIMDE_FLOAT32_C( -851.25),
                         SIMDE_FLOAT32_C( -312.32), SIMDE_FLOAT32_C( -630.06),
                         SIMDE_FLOAT32_C( -737.72), SIMDE_FLOAT32_C(  475.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -537.46), SIMDE_FLOAT32_C( -321.81),
                         SIMDE_FLOAT32_C( -851.25), SIMDE_FLOAT32_C(  -47.02),
                         SIMDE_FLOAT32_C( -737.72), SIMDE_FLOAT32_C( -879.02),
                         SIMDE_FLOAT32_C(  475.72), SIMDE_FLOAT32_C( -144.43)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -948.98), SIMDE_FLOAT32_C(  497.67),
                         SIMDE_FLOAT32_C(  650.06), SIMDE_FLOAT32_C(  741.02),
                         SIMDE_FLOAT32_C( -984.88), SIMDE_FLOAT32_C( -952.48),
                         SIMDE_FLOAT32_C( -355.06), SIMDE_FLOAT32_C(  845.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  984.39), SIMDE_FLOAT32_C( -147.65),
                         SIMDE_FLOAT32_C( -608.72), SIMDE_FLOAT32_C(  798.45),
                         SIMDE_FLOAT32_C( -191.22), SIMDE_FLOAT32_C( -819.43),
                         SIMDE_FLOAT32_C(  651.13), SIMDE_FLOAT32_C(  878.58)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -608.72), SIMDE_FLOAT32_C(  650.06),
                         SIMDE_FLOAT32_C(  798.45), SIMDE_FLOAT32_C(  741.02),
                         SIMDE_FLOAT32_C(  651.13), SIMDE_FLOAT32_C( -355.06),
                         SIMDE_FLOAT32_C(  878.58), SIMDE_FLOAT32_C(  845.88)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  860.59), SIMDE_FLOAT32_C(  -10.76),
                         SIMDE_FLOAT32_C( -198.30), SIMDE_FLOAT32_C(   77.85),
                         SIMDE_FLOAT32_C(  -62.31), SIMDE_FLOAT32_C(   -4.21),
                         SIMDE_FLOAT32_C(  365.71), SIMDE_FLOAT32_C(  937.33)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -309.45), SIMDE_FLOAT32_C(  297.29),
                         SIMDE_FLOAT32_C(  986.26), SIMDE_FLOAT32_C( -531.67),
                         SIMDE_FLOAT32_C(  648.25), SIMDE_FLOAT32_C( -225.86),
                         SIMDE_FLOAT32_C( -897.83), SIMDE_FLOAT32_C(  816.08)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  986.26), SIMDE_FLOAT32_C( -198.30),
                         SIMDE_FLOAT32_C( -531.67), SIMDE_FLOAT32_C(   77.85),
                         SIMDE_FLOAT32_C( -897.83), SIMDE_FLOAT32_C(  365.71),
                         SIMDE_FLOAT32_C(  816.08), SIMDE_FLOAT32_C(  937.33)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_unpacklo_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_unpacklo_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -600.90), SIMDE_FLOAT64_C( -534.18),
                         SIMDE_FLOAT64_C( -294.96), SIMDE_FLOAT64_C(  194.68)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  653.08), SIMDE_FLOAT64_C( -555.28),
                         SIMDE_FLOAT64_C(  745.15), SIMDE_FLOAT64_C( -216.67)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -555.28), SIMDE_FLOAT64_C( -534.18),
                         SIMDE_FLOAT64_C( -216.67), SIMDE_FLOAT64_C(  194.68)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  421.87), SIMDE_FLOAT64_C(  397.23),
                         SIMDE_FLOAT64_C(  303.53), SIMDE_FLOAT64_C(  285.42)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -720.94), SIMDE_FLOAT64_C( -472.31),
                         SIMDE_FLOAT64_C(  488.28), SIMDE_FLOAT64_C( -308.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -472.31), SIMDE_FLOAT64_C(  397.23),
                         SIMDE_FLOAT64_C( -308.40), SIMDE_FLOAT64_C(  285.42)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -109.61), SIMDE_FLOAT64_C(  180.86),
                         SIMDE_FLOAT64_C(  399.64), SIMDE_FLOAT64_C(  594.61)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -866.29), SIMDE_FLOAT64_C(  935.36),
                         SIMDE_FLOAT64_C(  680.83), SIMDE_FLOAT64_C(  371.83)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  935.36), SIMDE_FLOAT64_C(  180.86),
                         SIMDE_FLOAT64_C(  371.83), SIMDE_FLOAT64_C(  594.61)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   90.32), SIMDE_FLOAT64_C(  277.68),
                         SIMDE_FLOAT64_C(  879.43), SIMDE_FLOAT64_C( -100.14)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  615.95), SIMDE_FLOAT64_C( -913.08),
                         SIMDE_FLOAT64_C(  109.38), SIMDE_FLOAT64_C(  735.81)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -913.08), SIMDE_FLOAT64_C(  277.68),
                         SIMDE_FLOAT64_C(  735.81), SIMDE_FLOAT64_C( -100.14)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  932.30), SIMDE_FLOAT64_C(  361.71),
                         SIMDE_FLOAT64_C( -106.90), SIMDE_FLOAT64_C( -236.07)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -388.60), SIMDE_FLOAT64_C( -254.78),
                         SIMDE_FLOAT64_C(   -8.15), SIMDE_FLOAT64_C( -517.38)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -254.78), SIMDE_FLOAT64_C(  361.71),
                         SIMDE_FLOAT64_C( -517.38), SIMDE_FLOAT64_C( -236.07)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  420.24), SIMDE_FLOAT64_C(  915.08),
                         SIMDE_FLOAT64_C( -310.09), SIMDE_FLOAT64_C(  924.29)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -6.45), SIMDE_FLOAT64_C(  943.38),
                         SIMDE_FLOAT64_C( -842.17), SIMDE_FLOAT64_C(  303.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  943.38), SIMDE_FLOAT64_C(  915.08),
                         SIMDE_FLOAT64_C(  303.10), SIMDE_FLOAT64_C(  924.29)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  198.81), SIMDE_FLOAT64_C(  823.67),
                         SIMDE_FLOAT64_C(   21.23), SIMDE_FLOAT64_C(  275.37)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -789.28), SIMDE_FLOAT64_C(  222.39),
                         SIMDE_FLOAT64_C( -125.82), SIMDE_FLOAT64_C( -521.52)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  222.39), SIMDE_FLOAT64_C(  823.67),
                         SIMDE_FLOAT64_C( -521.52), SIMDE_FLOAT64_C(  275.37)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   71.55), SIMDE_FLOAT64_C( -915.84),
                         SIMDE_FLOAT64_C( -246.51), SIMDE_FLOAT64_C( -206.93)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -663.61), SIMDE_FLOAT64_C(  763.05),
                         SIMDE_FLOAT64_C( -365.16), SIMDE_FLOAT64_C( -475.21)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  763.05), SIMDE_FLOAT64_C( -915.84),
                         SIMDE_FLOAT64_C( -475.21), SIMDE_FLOAT64_C( -206.93)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_unpacklo_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_zextps128_ps256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m256 r;
  } test_vec[8] = {
    {    simde_mm_set_ps(SIMDE_FLOAT32_C( -312.77), SIMDE_FLOAT32_C(  594.20),
                         SIMDE_FLOAT32_C( -325.59), SIMDE_FLOAT32_C( -490.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -312.77), SIMDE_FLOAT32_C(  594.20),
                         SIMDE_FLOAT32_C( -325.59), SIMDE_FLOAT32_C( -490.02)) },
    {    simde_mm_set_ps(SIMDE_FLOAT32_C( -164.79), SIMDE_FLOAT32_C( -934.42),
                         SIMDE_FLOAT32_C(  921.14), SIMDE_FLOAT32_C(   62.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -164.79), SIMDE_FLOAT32_C( -934.42),
                         SIMDE_FLOAT32_C(  921.14), SIMDE_FLOAT32_C(   62.10)) },
    {    simde_mm_set_ps(SIMDE_FLOAT32_C( -517.66), SIMDE_FLOAT32_C(  967.01),
                         SIMDE_FLOAT32_C(  846.07), SIMDE_FLOAT32_C(  311.22)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -517.66), SIMDE_FLOAT32_C(  967.01),
                         SIMDE_FLOAT32_C(  846.07), SIMDE_FLOAT32_C(  311.22)) },
    {    simde_mm_set_ps(SIMDE_FLOAT32_C(  258.19), SIMDE_FLOAT32_C(    3.23),
                         SIMDE_FLOAT32_C( -975.57), SIMDE_FLOAT32_C(  -36.42)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(  258.19), SIMDE_FLOAT32_C(    3.23),
                         SIMDE_FLOAT32_C( -975.57), SIMDE_FLOAT32_C(  -36.42)) },
    {    simde_mm_set_ps(SIMDE_FLOAT32_C( -435.42), SIMDE_FLOAT32_C(  892.30),
                         SIMDE_FLOAT32_C( -907.17), SIMDE_FLOAT32_C( -773.85)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -435.42), SIMDE_FLOAT32_C(  892.30),
                         SIMDE_FLOAT32_C( -907.17), SIMDE_FLOAT32_C( -773.85)) },
    {    simde_mm_set_ps(SIMDE_FLOAT32_C(  555.74), SIMDE_FLOAT32_C( -152.72),
                         SIMDE_FLOAT32_C(  264.72), SIMDE_FLOAT32_C(  888.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(  555.74), SIMDE_FLOAT32_C( -152.72),
                         SIMDE_FLOAT32_C(  264.72), SIMDE_FLOAT32_C(  888.72)) },
    {    simde_mm_set_ps(SIMDE_FLOAT32_C( -118.52), SIMDE_FLOAT32_C( -258.55),
                         SIMDE_FLOAT32_C(  -89.99), SIMDE_FLOAT32_C(  -84.84)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -118.52), SIMDE_FLOAT32_C( -258.55),
                         SIMDE_FLOAT32_C(  -89.99), SIMDE_FLOAT32_C(  -84.84)) },
    {    simde_mm_set_ps(SIMDE_FLOAT32_C(  270.43), SIMDE_FLOAT32_C( -194.76),
                         SIMDE_FLOAT32_C( -351.14), SIMDE_FLOAT32_C(  335.42)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(  270.43), SIMDE_FLOAT32_C( -194.76),
                         SIMDE_FLOAT32_C( -351.14), SIMDE_FLOAT32_C(  335.42)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_zextps128_ps256(test_vec[i].a);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_zextpd128_pd256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  376.29), SIMDE_FLOAT64_C( -625.09)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  376.29), SIMDE_FLOAT64_C( -625.09)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -371.24), SIMDE_FLOAT64_C( -550.26)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -371.24), SIMDE_FLOAT64_C( -550.26)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -354.92), SIMDE_FLOAT64_C( -801.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -354.92), SIMDE_FLOAT64_C( -801.74)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -686.18), SIMDE_FLOAT64_C(  492.11)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -686.18), SIMDE_FLOAT64_C(  492.11)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -504.19), SIMDE_FLOAT64_C( -186.92)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -504.19), SIMDE_FLOAT64_C( -186.92)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  116.22), SIMDE_FLOAT64_C(  481.86)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  116.22), SIMDE_FLOAT64_C(  481.86)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  436.67), SIMDE_FLOAT64_C(  524.04)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  436.67), SIMDE_FLOAT64_C(  524.04)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -466.66), SIMDE_FLOAT64_C(  855.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -466.66), SIMDE_FLOAT64_C(  855.76)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_zextpd128_pd256(test_vec[i].a);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_zextsi128_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1643962878), INT32_C(-2136224029), INT32_C( -862547967), INT32_C( 1563544589)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(-1643962878), INT32_C(-2136224029), INT32_C( -862547967), INT32_C( 1563544589)) },
    { simde_mm_set_epi32(INT32_C(  222615505), INT32_C(-1697983622), INT32_C(-1628394379), INT32_C( 1723107736)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(  222615505), INT32_C(-1697983622), INT32_C(-1628394379), INT32_C( 1723107736)) },
    { simde_mm_set_epi32(INT32_C(  317003320), INT32_C(  266477895), INT32_C(-2056377610), INT32_C( -882756593)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(  317003320), INT32_C(  266477895), INT32_C(-2056377610), INT32_C( -882756593)) },
    { simde_mm_set_epi32(INT32_C( 1329871120), INT32_C( 1486902655), INT32_C(   47452678), INT32_C( 1284761395)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1329871120), INT32_C( 1486902655), INT32_C(   47452678), INT32_C( 1284761395)) },
    { simde_mm_set_epi32(INT32_C( 1382110307), INT32_C( 1399602482), INT32_C(-2085222328), INT32_C( -378818432)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1382110307), INT32_C( 1399602482), INT32_C(-2085222328), INT32_C( -378818432)) },
    { simde_mm_set_epi32(INT32_C(  181961329), INT32_C(  805996393), INT32_C( 1252840330), INT32_C( -381034184)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(  181961329), INT32_C(  805996393), INT32_C( 1252840330), INT32_C( -381034184)) },
    { simde_mm_set_epi32(INT32_C(-1859226353), INT32_C( -981205803), INT32_C( -178937485), INT32_C(-1391112590)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(-1859226353), INT32_C( -981205803), INT32_C( -178937485), INT32_C(-1391112590)) },
    { simde_mm_set_epi32(INT32_C( -625262837), INT32_C(-1636493607), INT32_C( -899223790), INT32_C(-2123458109)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( -625262837), INT32_C(-1636493607), INT32_C( -899223790), INT32_C(-2123458109)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_zextsi128_si256(test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
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

  TEST_FUNC(mm_cmp_pd),

  TEST_FUNC(mm256_cvtepi32_pd),
  TEST_FUNC(mm256_cvtepi32_ps),
  TEST_FUNC(mm256_cvtpd_epi32),
  TEST_FUNC(mm256_cvtpd_ps),
  TEST_FUNC(mm256_cvtps_epi32),
  TEST_FUNC(mm256_cvtps_pd),
  TEST_FUNC(mm256_cvttpd_epi32),
  TEST_FUNC(mm256_cvttps_epi32),

  TEST_FUNC(mm256_div_pd),
  TEST_FUNC(mm256_div_ps),

  TEST_FUNC(mm256_dp_ps),

  TEST_FUNC(mm256_extract_epi32),
  TEST_FUNC(mm256_extract_epi64),
  TEST_FUNC(mm256_extractf128_pd),
  TEST_FUNC(mm256_extractf128_ps),
  TEST_FUNC(mm256_extractf128_si256),

  TEST_FUNC(mm256_floor_ps),
  TEST_FUNC(mm256_floor_pd),

  TEST_FUNC(mm256_hadd_ps),
  TEST_FUNC(mm256_hadd_pd),
  TEST_FUNC(mm256_hsub_ps),
  TEST_FUNC(mm256_hsub_pd),

  TEST_FUNC(mm256_insert_epi8),
  TEST_FUNC(mm256_insert_epi16),
  TEST_FUNC(mm256_insert_epi32),
  TEST_FUNC(mm256_insert_epi64),
  TEST_FUNC(mm256_insertf128_pd),
  TEST_FUNC(mm256_insertf128_ps),
  TEST_FUNC(mm256_insertf128_si256),

  TEST_FUNC(mm256_lddqu_si256),
  TEST_FUNC(mm256_load_pd),
  TEST_FUNC(mm256_load_ps),
  TEST_FUNC(mm256_load_si256),
  TEST_FUNC(mm256_loadu_pd),
  TEST_FUNC(mm256_loadu_ps),
  TEST_FUNC(mm256_loadu_si256),
  TEST_FUNC(mm256_loadu2_m128),
  TEST_FUNC(mm256_loadu2_m128d),
  TEST_FUNC(mm256_loadu2_m128i),

  TEST_FUNC(mm_maskload_pd),
  TEST_FUNC(mm256_maskload_pd),
  TEST_FUNC(mm_maskload_ps),
  TEST_FUNC(mm256_maskload_ps),

  TEST_FUNC(mm_maskstore_pd),
  TEST_FUNC(mm256_maskstore_pd),
  TEST_FUNC(mm_maskstore_ps),
  TEST_FUNC(mm256_maskstore_ps),

  TEST_FUNC(mm256_min_ps),
  TEST_FUNC(mm256_min_pd),
  TEST_FUNC(mm256_max_ps),
  TEST_FUNC(mm256_max_pd),

  TEST_FUNC(mm256_movedup_pd),
  TEST_FUNC(mm256_movehdup_ps),
  TEST_FUNC(mm256_moveldup_ps),

  TEST_FUNC(mm256_movemask_ps),
  TEST_FUNC(mm256_movemask_pd),

  TEST_FUNC(mm256_mul_ps),
  TEST_FUNC(mm256_mul_pd),

  TEST_FUNC(mm256_or_ps),
  TEST_FUNC(mm256_or_pd),

  TEST_FUNC(mm256_permute_ps),
  TEST_FUNC(mm256_permute_pd),
  TEST_FUNC(mm_permute_ps),
  TEST_FUNC(mm_permute_pd),

  TEST_FUNC(mm256_rcp_ps),

  TEST_FUNC(mm256_round_ps),
  TEST_FUNC(mm256_round_pd),

  TEST_FUNC(mm256_rsqrt_ps),

  TEST_FUNC(mm256_setr_epi8),
  TEST_FUNC(mm256_setr_epi16),
  TEST_FUNC(mm256_setr_epi32),
  TEST_FUNC(mm256_setr_epi64),
  TEST_FUNC(mm256_setr_ps),
  TEST_FUNC(mm256_setr_pd),
  TEST_FUNC(mm256_setr_m128),
  TEST_FUNC(mm256_setr_m128d),
  TEST_FUNC(mm256_setr_m128i),

  TEST_FUNC(mm256_shuffle_ps),
  TEST_FUNC(mm256_shuffle_pd),

  TEST_FUNC(mm256_sqrt_ps),
  TEST_FUNC(mm256_sqrt_pd),

  TEST_FUNC(mm256_store_ps),
  TEST_FUNC(mm256_store_pd),
  TEST_FUNC(mm256_store_si256),
  TEST_FUNC(mm256_storeu_ps),
  TEST_FUNC(mm256_storeu_pd),
  TEST_FUNC(mm256_storeu_si256),
  TEST_FUNC(mm256_storeu2_m128),
  TEST_FUNC(mm256_storeu2_m128d),
  TEST_FUNC(mm256_storeu2_m128i),
  TEST_FUNC(mm256_stream_ps),
  TEST_FUNC(mm256_stream_pd),
  TEST_FUNC(mm256_stream_si256),

  TEST_FUNC(mm256_sub_ps),
  TEST_FUNC(mm256_sub_pd),

  TEST_FUNC(mm256_unpackhi_ps),
  TEST_FUNC(mm256_unpackhi_pd),
  TEST_FUNC(mm256_unpacklo_ps),
  TEST_FUNC(mm256_unpacklo_pd),

  TEST_FUNC(mm256_zextps128_ps256),
  TEST_FUNC(mm256_zextpd128_pd256),
  TEST_FUNC(mm256_zextsi128_si256),

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
