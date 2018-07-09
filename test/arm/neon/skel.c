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

#include <test/arm/arm-internal.h>
#include <simde/arm/neon.h>

static MunitResult
test_simde_xxx_s8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int8x8_t a;
    simde_int8x8_t b;
    simde_int8x8_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_int8x8_t a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_xxx_s8(a, b);

    printf("    { simde_x_vload_s8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                       INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")),\n",
           a.i8[0], a.i8[1], a.i8[2], a.i8[3], a.i8[4], a.i8[5], a.i8[6], a.i8[7]);
    printf("      simde_x_vload_s8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                       INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")),\n",
           b.i8[0], b.i8[1], b.i8[2], b.i8[3], b.i8[4], b.i8[5], b.i8[6], b.i8[7]);
    printf("      simde_x_vload_s8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                       INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")) },\n",
           r.i8[0], r.i8[1], r.i8[2], r.i8[3], r.i8[4], r.i8[5], r.i8[6], r.i8[7]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x8_t r = simde_xxx_s8(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int8x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxx_s16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int16x4_t a;
    simde_int16x4_t b;
    simde_int16x4_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_int16x4_t a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_xxx_s16(a, b);

    printf("    { simde_x_vload_s16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
           a.i16[0], a.i16[1], a.i16[2], a.i16[3]);
    printf("      simde_x_vload_s16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
           b.i16[0], b.i16[1], b.i16[2], b.i16[3]);
    printf("      simde_x_vload_s16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")) },\n",
           r.i16[0], r.i16[1], r.i16[2], r.i16[3]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x4_t r = simde_xxx_s16(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int16x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxx_s32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int32x2_t a;
    simde_int32x2_t b;
    simde_int32x2_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_int32x2_t a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_xxx_s32(a, b);

    printf("    { simde_x_vload_s32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
           a.i32[0], a.i32[1]);
    printf("      simde_x_vload_s32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
           b.i32[0], b.i32[1]);
    printf("      simde_x_vload_s32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")) },\n",
           r.i32[0], r.i32[1]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x2_t r = simde_xxx_s32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int32x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxx_s64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int64x1_t a;
    simde_int64x1_t b;
    simde_int64x1_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_int64x1_t a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_xxx_s64(a, b);

    printf("    { simde_x_vload_s64(INT64_C(%20" PRId64 ")),\n", a.i64[0]);
    printf("      simde_x_vload_s64(INT64_C(%20" PRId64 ")),\n", b.i64[0]);
    printf("      simde_x_vload_s64(INT64_C(%20" PRId64 ")) },\n", r.i64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x1_t r = simde_xxx_s64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int64x1(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxx_u8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint8x8_t a;
    simde_uint8x8_t b;
    simde_uint8x8_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_uint8x8_t a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_xxx_u8(a, b);

    printf("    { simde_x_vload_u8(UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                       UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 ")),\n",
           a.u8[0], a.u8[1], a.u8[2], a.u8[3], a.u8[4], a.u8[5], a.u8[6], a.u8[7]);
    printf("      simde_x_vload_u8(UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                       UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 ")),\n",
           b.u8[0], b.u8[1], b.u8[2], b.u8[3], b.u8[4], b.u8[5], b.u8[6], b.u8[7]);
    printf("      simde_x_vload_u8(UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                       UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 ")) },\n",
           r.u8[0], r.u8[1], r.u8[2], r.u8[3], r.u8[4], r.u8[5], r.u8[6], r.u8[7]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x8_t r = simde_xxx_u8(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint8x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxx_u16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint16x4_t a;
    simde_uint16x4_t b;
    simde_uint16x4_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_uint16x4_t a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_xxx_u16(a, b);

    printf("    { simde_x_vload_u16(UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 ")),\n",
           a.u16[0], a.u16[1], a.u16[2], a.u16[3]);
    printf("      simde_x_vload_u16(UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 ")),\n",
           b.u16[0], b.u16[1], b.u16[2], b.u16[3]);
    printf("      simde_x_vload_u16(UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 ")) },\n",
           r.u16[0], r.u16[1], r.u16[2], r.u16[3]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x4_t r = simde_xxx_u16(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint16x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxx_u32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint32x2_t a;
    simde_uint32x2_t b;
    simde_uint32x2_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_uint32x2_t a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_xxx_u32(a, b);

    printf("    { simde_x_vload_u32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")),\n",
           a.u32[0], a.u32[1]);
    printf("      simde_x_vload_u32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")),\n",
           b.u32[0], b.u32[1]);
    printf("      simde_x_vload_u32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")) },\n",
           r.u32[0], r.u32[1]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x2_t r = simde_xxx_u32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint32x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxx_u64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint64x1_t a;
    simde_uint64x1_t b;
    simde_uint64x1_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_uint64x1_t a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_xxx_u64(a, b);

    printf("    { simde_x_vload_u64(UINT64_C(%19" PRIu64 ")),\n", a.u64[0]);
    printf("      simde_x_vload_u64(UINT64_C(%19" PRIu64 ")),\n", b.u64[0]);
    printf("      simde_x_vload_u64(UINT64_C(%19" PRIu64 ")) },\n", r.u64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x1_t r = simde_xxx_u64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint64x1(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxx_f32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32x2_t a;
    simde_float32x2_t b;
    simde_float32x2_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_float32x2_t a, b, r;

    a = simde_neon_random_float32x2();
    b = simde_neon_random_float32x2();

    r = simde_xxx_f32(a, b);

    printf("    { simde_x_vload_f32(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
           8, a.f32[0], 8, a.f32[1]);
    printf("      simde_x_vload_f32(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
           8, b.f32[0], 8, b.f32[1]);
    printf("      simde_x_vload_f32(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)) },\n",
           8, r.f32[0], 8, r.f32[1]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x2_t r = simde_xxx_f32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_float32x2_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxx_f64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64x1_t a;
    simde_float64x1_t b;
    simde_float64x1_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_float64x1_t a, b, r;

    a = simde_neon_random_float64x1();
    b = simde_neon_random_float64x1();

    r = simde_xxx_f64(a, b);

    printf("    { simde_x_vload_f64(SIMDE_FLOAT64_C(%*.2f)),\n", 8, a.f64[0]);
    printf("      simde_x_vload_f64(SIMDE_FLOAT64_C(%*.2f)),\n", 8, b.f64[0]);
    printf("      simde_x_vload_f64(SIMDE_FLOAT64_C(%*.2f)) },\n", 8, r.f64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x1_t r = simde_xxx_f64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_float64x1_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxxq_s8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int8x16_t a;
    simde_int8x16_t b;
    simde_int8x16_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_int8x16_t a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_xxxq_s8(a, b);

    printf("    { simde_x_vloadq_s8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")),\n",
	   a.i8[ 0], a.i8[ 1], a.i8[ 2], a.i8[ 3], a.i8[ 4], a.i8[ 5], a.i8[ 6], a.i8[ 7],
           a.i8[ 8], a.i8[ 9], a.i8[10], a.i8[11], a.i8[12], a.i8[13], a.i8[14], a.i8[15]);
    printf("      simde_x_vloadq_s8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")),\n",
	   b.i8[ 0], b.i8[ 1], b.i8[ 2], b.i8[ 3], b.i8[ 4], b.i8[ 5], b.i8[ 6], b.i8[ 7],
           b.i8[ 8], b.i8[ 9], b.i8[10], b.i8[11], b.i8[12], b.i8[13], b.i8[14], b.i8[15]);
    printf("      simde_x_vloadq_s8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")) },\n",
	   r.i8[ 0], r.i8[ 1], r.i8[ 2], r.i8[ 3], r.i8[ 4], r.i8[ 5], r.i8[ 6], r.i8[ 7],
           r.i8[ 8], r.i8[ 9], r.i8[10], r.i8[11], r.i8[12], r.i8[13], r.i8[14], r.i8[15]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x16_t r = simde_xxxq_s8(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int8x16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxxq_s16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int16x8_t a;
    simde_int16x8_t b;
    simde_int16x8_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_int16x8_t a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_xxxq_s16(a, b);

    printf("    { simde_x_vloadq_s16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	   "                         INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
           a.i16[0], a.i16[1], a.i16[2], a.i16[3], a.i16[4], a.i16[5], a.i16[6], a.i16[7]);
    printf("      simde_x_vloadq_s16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	   "                         INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
           b.i16[0], b.i16[1], b.i16[2], b.i16[3], b.i16[4], b.i16[5], b.i16[6], b.i16[7]);
    printf("      simde_x_vloadq_s16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	   "                         INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")) },\n",
           r.i16[0], r.i16[1], r.i16[2], r.i16[3], r.i16[4], r.i16[5], r.i16[6], r.i16[7]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x8_t r = simde_xxxq_s16(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int16x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxxq_s32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int32x4_t a;
    simde_int32x4_t b;
    simde_int32x4_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_int32x4_t a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_xxxq_s32(a, b);

    printf("    { simde_x_vloadq_s32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
	   "                         INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
           a.i32[0], a.i32[1], a.i32[2], a.i32[3]);
    printf("      simde_x_vloadq_s32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
	   "                         INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
           b.i32[0], b.i32[1], b.i32[2], b.i32[3]);
    printf("      simde_x_vloadq_s32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
	   "                         INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")) },\n",
           r.i32[0], r.i32[1], r.i32[2], r.i32[3]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x4_t r = simde_xxxq_s32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxxq_s64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int64x2_t a;
    simde_int64x2_t b;
    simde_int64x2_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_int64x2_t a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_xxxq_s64(a, b);

    printf("    { simde_x_vloadq_s64(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")),\n", a.i64[0], a.i64[1]);
    printf("      simde_x_vloadq_s64(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")),\n", b.i64[0], b.i64[1]);
    printf("      simde_x_vloadq_s64(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")) },\n", r.i64[0], r.i64[1]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x2_t r = simde_xxxq_s64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int64x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxxq_u8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint8x16_t a;
    simde_uint8x16_t b;
    simde_uint8x16_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_uint8x16_t a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_xxxq_u8(a, b);

    printf("    { simde_x_vloadq_u8(UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                        UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                        UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                        UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 ") ),\n",
           a.u8[0], a.u8[1], a.u8[ 2], a.u8[ 3], a.u8[ 4], a.u8[ 5], a.u8[ 6], a.u8[ 7],
           a.u8[8], a.u8[9], a.u8[10], a.u8[11], a.u8[12], a.u8[13], a.u8[14], a.u8[15]);
    printf("      simde_x_vloadq_u8(UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                        UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                        UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                        UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 ") ),\n",
           b.u8[0], b.u8[1], b.u8[ 2], b.u8[ 3], b.u8[ 4], b.u8[ 5], b.u8[ 6], b.u8[ 7],
           b.u8[8], b.u8[9], b.u8[10], b.u8[11], b.u8[12], b.u8[13], b.u8[14], b.u8[15]);
    printf("      simde_x_vloadq_u8(UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                        UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                        UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                        UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 ") ) },\n",
           r.u8[0], r.u8[1], r.u8[ 2], r.u8[ 3], r.u8[ 4], r.u8[ 5], r.u8[ 6], r.u8[ 7],
           r.u8[8], r.u8[9], r.u8[10], r.u8[11], r.u8[12], r.u8[13], r.u8[14], r.u8[15]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x16_t r = simde_xxxq_u8(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint8x16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxxq_u16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint16x8_t a;
    simde_uint16x8_t b;
    simde_uint16x8_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_uint16x8_t a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_xxxq_u16(a, b);

    printf("    { simde_x_vloadq_u16(UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "),\n"
           "                         UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 ")),\n",
           a.u16[0], a.u16[1], a.u16[2], a.u16[3], a.u16[4], a.u16[5], a.u16[6], a.u16[7]);
    printf("      simde_x_vloadq_u16(UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "),\n"
           "                         UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 ")),\n",
           b.u16[0], b.u16[1], b.u16[2], b.u16[3], b.u16[4], b.u16[5], b.u16[6], b.u16[7]);
    printf("      simde_x_vloadq_u16(UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "),\n"
           "                         UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 ")) },\n",
           r.u16[0], r.u16[1], r.u16[2], r.u16[3], r.u16[4], r.u16[5], r.u16[6], r.u16[7]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x8_t r = simde_xxxq_u16(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint16x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxxq_u32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint32x4_t a;
    simde_uint32x4_t b;
    simde_uint32x4_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_uint32x4_t a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_xxxq_u32(a, b);

    printf("    { simde_x_vloadq_u32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                         UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")),\n",
           a.u32[0], a.u32[1], a.u32[2], a.u32[3]);
    printf("      simde_x_vloadq_u32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                         UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")),\n",
           b.u32[0], b.u32[1], b.u32[2], b.u32[3]);
    printf("      simde_x_vloadq_u32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                         UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")) },\n",
           r.u32[0], r.u32[1], r.u32[2], r.u32[3]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x4_t r = simde_xxxq_u32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxxq_u64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint64x2_t a;
    simde_uint64x2_t b;
    simde_uint64x2_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_uint64x2_t a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_xxxq_u64(a, b);

    printf("    { simde_x_vloadq_u64(UINT64_C(%19" PRIu64 "), UINT64_C(%19" PRIu64 ")),\n",
           a.u64[0], a.u64[1]);
    printf("      simde_x_vloadq_u64(UINT64_C(%19" PRIu64 "), UINT64_C(%19" PRIu64 ")),\n",
           b.u64[0], b.u64[1]);
    printf("      simde_x_vloadq_u64(UINT64_C(%19" PRIu64 "), UINT64_C(%19" PRIu64 ")) },\n",
           r.u64[0], r.u64[1]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x2_t r = simde_xxxq_u64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint64x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxxq_f32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32x4_t a;
    simde_float32x4_t b;
    simde_float32x4_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_float32x4_t a, b, r;

    a = simde_neon_random_float32x4();
    b = simde_neon_random_float32x4();

    r = simde_xxxq_f32(a, b);

    printf("    { simde_x_vloadq_f32(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
           8, a.f32[0], 8, a.f32[1], 8, a.f32[2], 8, a.f32[3]);
    printf("      simde_x_vloadq_f32(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
           8, b.f32[0], 8, b.f32[1], 8, b.f32[2], 8, b.f32[3]);
    printf("      simde_x_vloadq_f32(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)) },\n",
           8, r.f32[0], 8, r.f32[1], 8, r.f32[2], 8, r.f32[3]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x4_t r = simde_xxxq_f32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_float32x4_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_xxxq_f64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64x2_t a;
    simde_float64x2_t b;
    simde_float64x2_t r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_float64x2_t a, b, r;

    a = simde_neon_random_float64x2();
    b = simde_neon_random_float64x2();

    r = simde_xxxq_f64(a, b);

    printf("    { simde_x_vloadq_f64(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n",
           8, a.f64[0], 8, a.f64[1]);
    printf("      simde_x_vloadq_f64(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n",
           8, b.f64[0], 8, b.f64[1]);
    printf("      simde_x_vloadq_f64(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)) },\n",
           8, r.f64[0], 8, r.f64[1]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x2_t r = simde_xxxq_f64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_float64x2_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitTest xxx_tests[] = {
  TEST_FUNC2(xxx, s8),
  TEST_FUNC2(xxx, s16),
  TEST_FUNC2(xxx, s32),
  TEST_FUNC2(xxx, s64),
  TEST_FUNC2(xxx, u8),
  TEST_FUNC2(xxx, u16),
  TEST_FUNC2(xxx, u32),
  TEST_FUNC2(xxx, u64),
  TEST_FUNC2(xxx, f32),
  TEST_FUNC2(xxx, f64),
  TEST_FUNC3(xxx, q, s8),
  TEST_FUNC3(xxx, q, s16),
  TEST_FUNC3(xxx, q, s32),
  TEST_FUNC3(xxx, q, s64),
  TEST_FUNC3(xxx, q, u8),
  TEST_FUNC3(xxx, q, u16),
  TEST_FUNC3(xxx, q, u32),
  TEST_FUNC3(xxx, q, u64),
  TEST_FUNC3(xxx, q, f32),
  TEST_FUNC3(xxx, q, f64),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite NEON_TEST_SUITE(xxx) = {
  (char*) "/xxx",
  xxx_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
